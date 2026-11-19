#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4722d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004722d0);
    // 004722d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004722d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004722d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004722d3  8b15ecff5000           -mov edx, dword ptr [0x50ffec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308396) /* 0x50ffec */);
    // 004722d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004722da  8b0d58125100           -mov ecx, dword ptr [0x511258]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5313112) /* 0x511258 */);
    // 004722e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004722e1  68f0c04c00             -push 0x4cc0f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030128 /*0x4cc0f0*/;
    cpu.esp -= 4;
    // 004722e6  6864035400             -push 0x540364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5505892 /*0x540364*/;
    cpu.esp -= 4;
    // 004722eb  e881260100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004722f0  b864035400             -mov eax, 0x540364
    cpu.eax = 5505892 /*0x540364*/;
    // 004722f5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004722f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472300);
    // 00472300  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472310);
    // 00472310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472313  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472314  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472316  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047231d  756c                   -jne 0x47238b
    if (!cpu.flags.zf)
    {
        goto L_0x0047238b;
    }
    // 0047231f  6683b94c01000000       +cmp word ptr [ecx + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00472327  7667                   -jbe 0x472390
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00472390;
    }
    // 00472329  81b95c01000000800000   +cmp dword ptr [ecx + 0x15c], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472333  0f8c0e010000           -jl 0x472447
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472447;
    }
L_0x00472339:
    // 00472339  8b15d4ff5000           -mov edx, dword ptr [0x50ffd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308372) /* 0x50ffd4 */);
    // 0047233f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00472346  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472348  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047234b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047234d  8b9160010000           -mov edx, dword ptr [ecx + 0x160]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */);
    // 00472353  3b148518fb5000         +cmp edx, dword ptr [eax*4 + 0x50fb18]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5307160) /* 0x50fb18 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047235a  0f8fbe010000           -jg 0x47251e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047251e;
    }
    // 00472360  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472367  7e15                   -jle 0x47237e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047237e;
    }
L_0x00472369:
    // 00472369  8ba978050000           -mov ebp, dword ptr [ecx + 0x578]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
    // 0047236f  4d                     -dec ebp
    (cpu.ebp)--;
    // 00472370  89a978050000           -mov dword ptr [ecx + 0x578], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = cpu.ebp;
    // 00472376  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472378  0f8eb6010000           -jle 0x472534
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472534;
    }
L_0x0047237e:
    // 0047237e  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472385  0f8eba010000           -jle 0x472545
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472545;
    }
L_0x0047238b:
    // 0047238b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047238c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047238d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047238e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047238f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472390:
    // 00472390  8b99a8000000           -mov ebx, dword ptr [ecx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00472396  69d3e6000000           -imul edx, ebx, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 0047239c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047239e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004723a1  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004723a4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004723a6  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004723a9  6991ac000000e6000000   -imul edx, dword ptr [ecx + 0xac], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 004723b3  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 004723b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004723bb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004723be  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004723c1  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004723c3  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004723c6  6991b0000000e6000000   -imul edx, dword ptr [ecx + 0xb0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 004723d0  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 004723d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004723d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004723db  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004723de  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004723e0  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004723e3  6991e8000000e6000000   -imul edx, dword ptr [ecx + 0xe8], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 004723ed  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 004723f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004723f5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004723f8  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004723fb  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004723fd  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00472400  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00472406  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0047240c  69d0e6000000           -imul edx, eax, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00472412  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472414  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472417  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047241a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047241c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0047241f  6991f0000000e6000000   -imul edx, dword ptr [ecx + 0xf0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00472429  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 0047242f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472431  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472434  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00472437  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472439  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047243c  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00472442  e9f2feffff             -jmp 0x472339
    goto L_0x00472339;
L_0x00472447:
    // 00472447  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0047244d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00472450  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472452  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00472455  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472457  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472459  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047245c  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047245f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472461  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00472464  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0047246a  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00472470  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00472473  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472475  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00472478  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047247a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047247c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047247f  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00472482  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472484  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00472487  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0047248d  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00472493  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00472496  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472498  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047249b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047249d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047249f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004724a2  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004724a5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004724a7  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004724aa  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 004724b0  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 004724b6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004724b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004724bb  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004724be  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004724c0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004724c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004724c5  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004724c8  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004724ca  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004724cd  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 004724d3  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 004724d9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004724dc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004724de  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004724e1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004724e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004724e5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004724e8  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004724eb  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004724ed  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004724f0  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 004724f6  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 004724fc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004724ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472501  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00472504  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472506  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472508  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047250b  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047250e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472510  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00472513  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00472519  e91bfeffff             -jmp 0x472339
    goto L_0x00472339;
L_0x0047251e:
    // 0047251e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472520  e88b00feff             -call 0x4525b0
    cpu.esp -= 4;
    sub_4525b0(app, cpu);
    if (cpu.terminate) return;
    // 00472525  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 0047252f  e935feffff             -jmp 0x472369
    goto L_0x00472369;
L_0x00472534:
    // 00472534  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472536  e835010000             -call 0x472670
    cpu.esp -= 4;
    sub_472670(app, cpu);
    if (cpu.terminate) return;
    // 0047253b  c7817805000000000000   -mov dword ptr [ecx + 0x578], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 0 /*0x0*/;
L_0x00472545:
    // 00472545  8b9984010000           -mov ebx, dword ptr [ecx + 0x184]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(388) /* 0x184 */);
    // 0047254b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047254d  7412                   -je 0x472561
    if (cpu.flags.zf)
    {
        goto L_0x00472561;
    }
    // 0047254f  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472552  740d                   -je 0x472561
    if (cpu.flags.zf)
    {
        goto L_0x00472561;
    }
    // 00472554  83b97c01000000         +cmp dword ptr [ecx + 0x17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(380) /* 0x17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047255b  0f842afeffff           -je 0x47238b
    if (cpu.flags.zf)
    {
        goto L_0x0047238b;
    }
L_0x00472561:
    // 00472561  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 0047256b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047256c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047256d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047256e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047256f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_472570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472570);
    // 00472570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472571  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472573  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047257a  7402                   -je 0x47257e
    if (cpu.flags.zf)
    {
        goto L_0x0047257e;
    }
    // 0047257c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047257d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047257e:
    // 0047257e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047257f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472580  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00472586  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0047258c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047258e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472591  c1e810                 +shr eax, 0x10
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
    // 00472594  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472596  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00472598  8b91c8000000           -mov edx, dword ptr [ecx + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 0047259e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004725a4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004725a6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004725a9  c1e810                 +shr eax, 0x10
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
    // 004725ac  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004725ae  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 004725b4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004725b6  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 004725bc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004725be  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004725c1  c1e810                 +shr eax, 0x10
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
    // 004725c4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004725c6  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 004725cc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004725ce  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 004725d4  8999b0020000           -mov dword ptr [ecx + 0x2b0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(688) /* 0x2b0 */) = cpu.ebx;
    // 004725da  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004725dc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004725df  c1e810                 +shr eax, 0x10
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
    // 004725e2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004725e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004725e6  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 004725ec  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 004725f2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004725f4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004725f7  c1e810                 +shr eax, 0x10
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
    // 004725fa  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004725fc  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00472602  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472604  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0047260a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047260c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047260f  c1e810                 +shr eax, 0x10
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
    // 00472612  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472614  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0047261a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047261c  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00472622  8999b4020000           -mov dword ptr [ecx + 0x2b4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */) = cpu.ebx;
    // 00472628  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047262a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047262d  c1e810                 +shr eax, 0x10
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
    // 00472630  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472632  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00472634  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0047263a  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00472640  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472642  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472645  c1e810                 +shr eax, 0x10
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
    // 00472648  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047264a  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 00472650  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472652  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00472658  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047265a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047265d  c1e810                 +shr eax, 0x10
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
    // 00472660  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472662  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472664  8999b8020000           -mov dword ptr [ecx + 0x2b8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.ebx;
    // 0047266a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047266b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047266c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047266d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_472670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472670);
    // 00472670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472672  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472673  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472674  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472675  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472677  c780a800000000000000   -mov dword ptr [eax + 0xa8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 0 /*0x0*/;
    // 00472681  c780ac00000000000000   -mov dword ptr [eax + 0xac], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 0047268b  c780b000000000000000   -mov dword ptr [eax + 0xb0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = 0 /*0x0*/;
    // 00472695  8db83c010000           -lea edi, [eax + 0x13c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(316) /* 0x13c */);
    // 0047269b  c780e800000000000000   -mov dword ptr [eax + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 004726a5  8db024010000           -lea esi, [eax + 0x124]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 004726ab  c780ec00000000000000   -mov dword ptr [eax + 0xec], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 004726b5  059c000000             -add eax, 0x9c
    (cpu.eax) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 004726ba  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004726bc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004726be  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004726c5  e836edfeff             -call 0x461400
    cpu.esp -= 4;
    sub_461400(app, cpu);
    if (cpu.terminate) return;
    // 004726ca  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004726cc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004726ce  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 004726d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004726d6  e8a5eafeff             -call 0x461180
    cpu.esp -= 4;
    sub_461180(app, cpu);
    if (cpu.terminate) return;
    // 004726db  89815c010000           -mov dword ptr [ecx + 0x15c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = cpu.eax;
    // 004726e1  8b91a0000000           -mov edx, dword ptr [ecx + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 004726e7  c7815c01000000000000   -mov dword ptr [ecx + 0x15c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 004726f1  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004726f3  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 004726f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_472700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472700);
    // 00472700  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472710);
    // 00472710  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472711  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00472716  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472718  a3cc2e5400             -mov dword ptr [0x542ecc], eax
    app->getMemory<x86::reg32>(x86::reg32(5517004) /* 0x542ecc */) = cpu.eax;
    // 0047271d  8915c42e5400           -mov dword ptr [0x542ec4], edx
    app->getMemory<x86::reg32>(x86::reg32(5516996) /* 0x542ec4 */) = cpu.edx;
    // 00472723  8915c82e5400           -mov dword ptr [0x542ec8], edx
    app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */) = cpu.edx;
    // 00472729  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047272a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472730);
    // 00472730  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472731  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00472736  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472738  a3cc2e5400             -mov dword ptr [0x542ecc], eax
    app->getMemory<x86::reg32>(x86::reg32(5517004) /* 0x542ecc */) = cpu.eax;
    // 0047273d  8915c42e5400           -mov dword ptr [0x542ec4], edx
    app->getMemory<x86::reg32>(x86::reg32(5516996) /* 0x542ec4 */) = cpu.edx;
    // 00472743  8915c82e5400           -mov dword ptr [0x542ec8], edx
    app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */) = cpu.edx;
    // 00472749  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047274a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472750);
    // 00472750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472756  81ece0030000           -sub esp, 0x3e0
    (cpu.esp) -= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 0047275c  898424d4030000         -mov dword ptr [esp + 0x3d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */) = cpu.eax;
    // 00472763  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00472768  a1c82e5400             -mov eax, dword ptr [0x542ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 0047276d  e8ae8afbff             -call 0x42b220
    cpu.esp -= 4;
    sub_42b220(app, cpu);
    if (cpu.terminate) return;
    // 00472772  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472774  8b1dc82e5400           -mov ebx, dword ptr [0x542ec8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 0047277a  899424d8030000         -mov dword ptr [esp + 0x3d8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(984) /* 0x3d8 */) = cpu.edx;
    // 00472781  899424d0030000         -mov dword ptr [esp + 0x3d0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */) = cpu.edx;
    // 00472788  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047278a  7e5e                   -jle 0x4727ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004727ea;
    }
    // 0047278c  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 00472793  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00472796  898424c0030000         -mov dword ptr [esp + 0x3c0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(960) /* 0x3c0 */) = cpu.eax;
    // 0047279d  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 004727a4  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004727a7  898424c8030000         -mov dword ptr [esp + 0x3c8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(968) /* 0x3c8 */) = cpu.eax;
    // 004727ae  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 004727b5  bfa4035400             -mov edi, 0x5403a4
    cpu.edi = 5505956 /*0x5403a4*/;
    // 004727ba  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004727bd  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004727bf  898424cc030000         -mov dword ptr [esp + 0x3cc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(972) /* 0x3cc */) = cpu.eax;
L_0x004727c6:
    // 004727c6  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004727c8  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004727ca  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004727cc  754c                   -jne 0x47281a
    if (!cpu.flags.zf)
    {
        goto L_0x0047281a;
    }
L_0x004727ce:
    // 004727ce  8bb424d8030000         -mov esi, dword ptr [esp + 0x3d8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(984) /* 0x3d8 */);
    // 004727d5  8b15c82e5400           -mov edx, dword ptr [0x542ec8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 004727db  46                     -inc esi
    (cpu.esi)++;
    // 004727dc  83c75c                 -add edi, 0x5c
    (cpu.edi) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004727df  89b424d8030000         -mov dword ptr [esp + 0x3d8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(984) /* 0x3d8 */) = cpu.esi;
    // 004727e6  39d6                   +cmp esi, edx
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
    // 004727e8  7cdc                   -jl 0x4727c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004727c6;
    }
L_0x004727ea:
    // 004727ea  8b8c24d0030000         -mov ecx, dword ptr [esp + 0x3d0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */);
    // 004727f1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004727f3  7418                   -je 0x47280d
    if (cpu.flags.zf)
    {
        goto L_0x0047280d;
    }
    // 004727f5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004727f7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004727f9  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004727fc  83f901                 +cmp ecx, 1
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
    // 004727ff  0f8f97000000           -jg 0x47289c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047289c;
    }
L_0x00472805:
    // 00472805  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00472807  0f8529010000           -jne 0x472936
    if (!cpu.flags.zf)
    {
        goto L_0x00472936;
    }
L_0x0047280d:
    // 0047280d  81c4e0030000           -add esp, 0x3e0
    (cpu.esp) += x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00472813  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472814  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472815  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472816  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472817  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472818  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472819  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047281a:
    // 0047281a  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 0047281f  8d4f10                 -lea ecx, [edi + 0x10]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00472822  8b9424cc030000         -mov edx, dword ptr [esp + 0x3cc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(972) /* 0x3cc */);
    // 00472829  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047282b  e840cbffff             -call 0x46f370
    cpu.esp -= 4;
    sub_46f370(app, cpu);
    if (cpu.terminate) return;
    // 00472830  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472832  749a                   -je 0x4727ce
    if (cpu.flags.zf)
    {
        goto L_0x004727ce;
    }
    // 00472834  8d4728                 -lea eax, [edi + 0x28]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00472837  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047283c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047283d  8b9424c4030000         -mov edx, dword ptr [esp + 0x3c4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(964) /* 0x3c4 */);
    // 00472844  8b8424cc030000         -mov eax, dword ptr [esp + 0x3cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(972) /* 0x3cc */);
    // 0047284b  e860c10000             -call 0x47e9b0
    cpu.esp -= 4;
    sub_47e9b0(app, cpu);
    if (cpu.terminate) return;
    // 00472850  8a17                   -mov dl, byte ptr [edi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi);
    // 00472852  80fa04                 +cmp dl, 4
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
    // 00472855  7429                   -je 0x472880
    if (cpu.flags.zf)
    {
        goto L_0x00472880;
    }
    // 00472857  80fa05                 +cmp dl, 5
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047285a  7424                   -je 0x472880
    if (cpu.flags.zf)
    {
        goto L_0x00472880;
    }
    // 0047285c  817f3000000100         +cmp dword ptr [edi + 0x30], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472863  7c2e                   -jl 0x472893
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472893;
    }
L_0x00472865:
    // 00472865  8b9424d0030000         -mov edx, dword ptr [esp + 0x3d0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */);
    // 0047286c  83c508                 +add ebp, 8
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047286f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00472870  89742cfc               -mov dword ptr [esp + ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ebp * 1) = cpu.esi;
    // 00472874  899424d0030000         -mov dword ptr [esp + 0x3d0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(976) /* 0x3d0 */) = cpu.edx;
    // 0047287b  e94effffff             -jmp 0x4727ce
    goto L_0x004727ce;
L_0x00472880:
    // 00472880  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 00472887  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00472889  e896f8fbff             -call 0x432124
    cpu.esp -= 4;
    sub_432124(app, cpu);
    if (cpu.terminate) return;
    // 0047288e  e93bffffff             -jmp 0x4727ce
    goto L_0x004727ce;
L_0x00472893:
    // 00472893  c7473000000100         -mov dword ptr [edi + 0x30], 0x10000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = 65536 /*0x10000*/;
    // 0047289a  ebc9                   -jmp 0x472865
    goto L_0x00472865;
L_0x0047289c:
    // 0047289c  8d4708                 -lea eax, [edi + 8]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047289f  898424dc030000         -mov dword ptr [esp + 0x3dc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */) = cpu.eax;
    // 004728a6  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004728ad  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 004728b2  898424c4030000         -mov dword ptr [esp + 0x3c4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(964) /* 0x3c4 */) = cpu.eax;
L_0x004728b9:
    // 004728b9  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004728bc  8b542c04               -mov edx, dword ptr [esp + ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 004728c0  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004728c3  3b4230                 +cmp eax, dword ptr [edx + 0x30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004728c6  7e2f                   -jle 0x4728f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004728f7;
    }
    // 004728c8  893c2c                 -mov dword ptr [esp + ebp], edi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebp * 1) = cpu.edi;
    // 004728cb  8bbc24dc030000         -mov edi, dword ptr [esp + 0x3dc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */);
L_0x004728d2:
    // 004728d2  8b8c24dc030000         -mov ecx, dword ptr [esp + 0x3dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */);
    // 004728d9  8b9c24c4030000         -mov ebx, dword ptr [esp + 0x3c4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(964) /* 0x3c4 */);
    // 004728e0  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004728e3  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004728e6  898c24dc030000         -mov dword ptr [esp + 0x3dc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */) = cpu.ecx;
    // 004728ed  39dd                   +cmp ebp, ebx
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
    // 004728ef  0f8d10ffffff           -jge 0x472805
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472805;
    }
    // 004728f5  ebc2                   -jmp 0x4728b9
    goto L_0x004728b9;
L_0x004728f7:
    // 004728f7  833f00                 +cmp dword ptr [edi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004728fa  742a                   -je 0x472926
    if (cpu.flags.zf)
    {
        goto L_0x00472926;
    }
    // 004728fc  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004728fe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00472900:
    // 00472900  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00472902  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00472905  8b5c3404               -mov ebx, dword ptr [esp + esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 00472909  8b4930                 -mov ecx, dword ptr [ecx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0047290c  3b4b30                 +cmp ecx, dword ptr [ebx + 0x30]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047290f  7d08                   -jge 0x472919
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472919;
    }
    // 00472911  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00472913  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472915  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472917  75e7                   -jne 0x472900
    if (!cpu.flags.zf)
    {
        goto L_0x00472900;
    }
L_0x00472919:
    // 00472919  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047291b  89042c                 -mov dword ptr [esp + ebp], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebp * 1) = cpu.eax;
    // 0047291e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00472920  01e8                   +add eax, ebp
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
    // 00472922  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00472924  ebac                   -jmp 0x4728d2
    goto L_0x004728d2;
L_0x00472926:
    // 00472926  8b8424dc030000         -mov eax, dword ptr [esp + 0x3dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(988) /* 0x3dc */);
    // 0047292d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047292f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00472931  89142c                 -mov dword ptr [esp + ebp], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebp * 1) = cpu.edx;
    // 00472934  eb9c                   -jmp 0x4728d2
    goto L_0x004728d2;
L_0x00472936:
    // 00472936  8b8424d4030000         -mov eax, dword ptr [esp + 0x3d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(980) /* 0x3d4 */);
    // 0047293d  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00472940  e8dff7fbff             -call 0x432124
    cpu.esp -= 4;
    sub_432124(app, cpu);
    if (cpu.terminate) return;
    // 00472945  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00472947  e9b9feffff             -jmp 0x472805
    goto L_0x00472805;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_472950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472950);
    // 00472950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472955  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472956  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00472959  8b2dc82e5400           -mov ebp, dword ptr [0x542ec8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 0047295f  8b15cc2e5400           -mov edx, dword ptr [0x542ecc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517004) /* 0x542ecc */);
    // 00472965  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047296a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047296c  83f803                 +cmp eax, 3
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
    // 0047296f  0f8ea4000000           -jle 0x472a19
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472a19;
    }
    // 00472975  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047297a  a3cc2e5400             -mov dword ptr [0x542ecc], eax
    app->getMemory<x86::reg32>(x86::reg32(5517004) /* 0x542ecc */) = cpu.eax;
    // 0047297f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472981  0f85a2000000           -jne 0x472a29
    if (!cpu.flags.zf)
    {
        goto L_0x00472a29;
    }
L_0x00472987:
    // 00472987  8b2dc82e5400           -mov ebp, dword ptr [0x542ec8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 0047298d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047298f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472991  7e6b                   -jle 0x4729fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004729fe;
    }
    // 00472993  baa4035400             -mov edx, 0x5403a4
    cpu.edx = 5505956 /*0x5403a4*/;
L_0x00472998:
    // 00472998  8a6202                 -mov ah, byte ptr [edx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047299b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047299d  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047299f  0f840a010000           -je 0x472aaf
    if (cpu.flags.zf)
    {
        goto L_0x00472aaf;
    }
    // 004729a5  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004729a8  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004729ab  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004729ae  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004729b0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004729b2  897210                 -mov dword ptr [edx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004729b5  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004729b9  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004729bc  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004729bf  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004729c1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004729c3  897214                 -mov dword ptr [edx + 0x14], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004729c6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004729ca  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004729cd  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004729d0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004729d2:
    // 004729d2  01c6                   +add esi, eax
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
    // 004729d4  892dc82e5400           -mov dword ptr [0x542ec8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */) = cpu.ebp;
    // 004729da  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004729dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004729df  e84c020000             -call 0x472c30
    cpu.esp -= 4;
    sub_472c30(app, cpu);
    if (cpu.terminate) return;
    // 004729e4  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004729e7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004729e8  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004729eb  7503                   -jne 0x4729f0
    if (!cpu.flags.zf)
    {
        goto L_0x004729f0;
    }
    // 004729ed  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x004729f0:
    // 004729f0  8b2dc82e5400           -mov ebp, dword ptr [0x542ec8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 004729f6  43                     -inc ebx
    (cpu.ebx)++;
    // 004729f7  83c25c                 -add edx, 0x5c
    (cpu.edx) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 004729fa  39eb                   +cmp ebx, ebp
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
    // 004729fc  7c9a                   -jl 0x472998
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472998;
    }
L_0x004729fe:
    // 004729fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472a00  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472a02  7e15                   -jle 0x472a19
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472a19;
    }
L_0x00472a04:
    // 00472a04  6bf05c                 -imul esi, eax, 0x5c
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(92 /*0x5c*/)));
    // 00472a07  80bea403540000         +cmp byte ptr [esi + 0x5403a4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5505956) /* 0x5403a4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00472a0e  0f84bc000000           -je 0x472ad0
    if (cpu.flags.zf)
    {
        goto L_0x00472ad0;
    }
L_0x00472a14:
    // 00472a14  40                     -inc eax
    (cpu.eax)++;
    // 00472a15  39e8                   +cmp eax, ebp
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
    // 00472a17  7ceb                   -jl 0x472a04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472a04;
    }
L_0x00472a19:
    // 00472a19  892dc82e5400           -mov dword ptr [0x542ec8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */) = cpu.ebp;
    // 00472a1f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00472a22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a25  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a27  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472a29:
    // 00472a29  8b0dc42e5400           -mov ecx, dword ptr [0x542ec4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5516996) /* 0x542ec4 */);
    // 00472a2f  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00472a32  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00472a34  890dc42e5400           -mov dword ptr [0x542ec4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5516996) /* 0x542ec4 */) = cpu.ecx;
    // 00472a3a  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00472a40  c0e507                 +shl ch, 7
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
    // 00472a43  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472a45  00ed                   +add ch, ch
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
    // 00472a47  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00472a49  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472a4b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00472a50  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472a52  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 00472a59  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a5b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a5d  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 00472a62  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472a64  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472a67  c1e810                 +shr eax, 0x10
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
    // 00472a6a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472a6c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00472a6f  a1c42e5400             -mov eax, dword ptr [0x542ec4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516996) /* 0x542ec4 */);
    // 00472a74  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472a76  c0e407                 +shl ah, 7
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
    // 00472a79  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472a7b  00e4                   +add ah, ah
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
    // 00472a7d  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00472a7f  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472a81  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00472a86  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472a88  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 00472a8f  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a91  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a93  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 00472a98  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00472a9c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472a9e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472aa1  c1e810                 +shr eax, 0x10
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
    // 00472aa4  11d0                   +adc eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472aa6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00472aaa  e9d8feffff             -jmp 0x472987
    goto L_0x00472987;
L_0x00472aaf:
    // 00472aaf  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00472ab2  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00472ab5  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472ab7  897210                 -mov dword ptr [edx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00472aba  8b7a14                 -mov edi, dword ptr [edx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00472abd  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00472ac0  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00472ac3  01c7                   +add edi, eax
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
    // 00472ac5  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00472ac8  897a14                 -mov dword ptr [edx + 0x14], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 00472acb  e902ffffff             -jmp 0x4729d2
    goto L_0x004729d2;
L_0x00472ad0:
    // 00472ad0  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00472ad3  6bda5c                 +imul ebx, edx, 0x5c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(92 /*0x5c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00472ad6  b917000000             -mov ecx, 0x17
    cpu.ecx = 23 /*0x17*/;
    // 00472adb  8dbea4035400           -lea edi, [esi + 0x5403a4]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(5505956) /* 0x5403a4 */);
    // 00472ae1  8db3a4035400           -lea esi, [ebx + 0x5403a4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(5505956) /* 0x5403a4 */);
    // 00472ae7  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00472ae8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00472aea  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472aec  e923ffffff             -jmp 0x472a14
    goto L_0x00472a14;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472b24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472b24);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00472b24  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472b25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472b26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472b27  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472b28  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00472b2b  8b2dc82e5400           -mov ebp, dword ptr [0x542ec8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 00472b31  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472b33  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00472b37  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00472b3b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472b3d  83fd78                 +cmp ebp, 0x78
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472b40  0f85b3000000           -jne 0x472bf9
    if (!cpu.flags.zf)
    {
        goto L_0x00472bf9;
    }
    // 00472b46  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00472b4b  8b0da8035400           -mov ecx, dword ptr [0x5403a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5505960) /* 0x5403a8 */);
    // 00472b51  39c5                   +cmp ebp, eax
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
    // 00472b53  7e1b                   -jle 0x472b70
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472b70;
    }
    // 00472b55  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
L_0x00472b5a:
    // 00472b5a  8bbaa8035400           -mov edi, dword ptr [edx + 0x5403a8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505960) /* 0x5403a8 */);
    // 00472b60  39f9                   +cmp ecx, edi
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
    // 00472b62  7e04                   -jle 0x472b68
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472b68;
    }
    // 00472b64  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00472b66  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00472b68:
    // 00472b68  40                     -inc eax
    (cpu.eax)++;
    // 00472b69  83c25c                 -add edx, 0x5c
    (cpu.edx) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00472b6c  39e8                   +cmp eax, ebp
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
    // 00472b6e  7cea                   -jl 0x472b5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472b5a;
    }
L_0x00472b70:
    // 00472b70  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00472b77  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472b79  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00472b7c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472b7e  baa4035400             -mov edx, 0x5403a4
    cpu.edx = 5505956 /*0x5403a4*/;
    // 00472b83  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00472b86  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472b88  8d7a10                 -lea edi, [edx + 0x10]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00472b8b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472b8c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472b8d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472b8e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00472b92  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00472b99  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00472b9b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00472b9f  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00472ba2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472ba4  7513                   -jne 0x472bb9
    if (!cpu.flags.zf)
    {
        goto L_0x00472bb9;
    }
    // 00472ba6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00472ba8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472baa  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00472bae  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00472bb1  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00472bb5  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x00472bb9:
    // 00472bb9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00472bbd  48                     -dec eax
    (cpu.eax)--;
    // 00472bbe  892dc82e5400           -mov dword ptr [0x542ec8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */) = cpu.ebp;
    // 00472bc4  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472bc7  7719                   -ja 0x472be2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00472be2;
    }
    // 00472bc9  ff2485002b4700         -jmp dword ptr [eax*4 + 0x472b00]
    cpu.ip = app->getMemory<x86::reg32>(4664064 + cpu.eax * 4); goto dynamic_jump;
  case 0x00472bd0:
    // 00472bd0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472bd2  e8b9000000             -call 0x472c90
    cpu.esp -= 4;
    sub_472c90(app, cpu);
    if (cpu.terminate) return;
    // 00472bd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472bd9  c6420201               -mov byte ptr [edx + 2], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 1 /*0x1*/;
L_0x00472bdd:
    // 00472bdd  e88e000000             -call 0x472c70
    cpu.esp -= 4;
    sub_472c70(app, cpu);
    if (cpu.terminate) return;
L_0x00472be2:
    // 00472be2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472be4  e8cbf4fbff             -call 0x4320b4
    cpu.esp -= 4;
    sub_4320b4(app, cpu);
    if (cpu.terminate) return;
    // 00472be9  8b2dc82e5400           -mov ebp, dword ptr [0x542ec8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5517000) /* 0x542ec8 */);
    // 00472bef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472bf1  83c414                 +add esp, 0x14
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
    // 00472bf4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472bf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472bf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472bf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472bf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472bf9:
    // 00472bf9  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00472bfb  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00472bfc  e96fffffff             -jmp 0x472b70
    goto L_0x00472b70;
  case 0x00472c01:
    // 00472c01  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00472c05  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00472c07  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00472c0a  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00472c0d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00472c11  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00472c14  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00472c17  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00472c1a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00472c1e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00472c21  c1f805                 +sar eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00472c24  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00472c27  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472c29  c6420200               -mov byte ptr [edx + 2], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00472c2d  ebae                   -jmp 0x472bdd
    goto L_0x00472bdd;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_472c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472c30);
    // 00472c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472c32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472c33  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00472c36  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 00472c39  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00472c3c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00472c3f  83fbfd                 +cmp ebx, -3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472c42  7c09                   -jl 0x472c4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472c4d;
    }
    // 00472c44  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472c47  7f0e                   -jg 0x472c57
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00472c57;
    }
    // 00472c49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472c4d:
    // 00472c4d  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00472c50  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00472c53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472c57:
    // 00472c57  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472c58  8d7bff                 -lea edi, [ebx - 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00472c5b  89780c                 -mov dword ptr [eax + 0xc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00472c5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472c70);
    // 00472c70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472c71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472c73  e86c380100             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 00472c78  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00472c7b  e864380100             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 00472c80  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00472c83  83e83f                 -sub eax, 0x3f
    (cpu.eax) -= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00472c86  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00472c89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472c8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472c90);
    // 00472c90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472c91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472c93  e84c380100             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 00472c98  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 00472c9d  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00472ca0  e83f380100             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 00472ca5  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 00472caa  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00472cad  e832380100             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 00472cb2  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 00472cb7  05ff070000             -add eax, 0x7ff
    (cpu.eax) += x86::reg32(x86::sreg32(2047 /*0x7ff*/));
    // 00472cbc  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00472cbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472cc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472cd0);
    // 00472cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472cd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472cd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472cd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472cd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472cd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472cd6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472cd9  8b15f4ec5300           -mov edx, dword ptr [0x53ecf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */);
    // 00472cdf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472ce1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00472ce3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00472ce5  0f8565000000           -jne 0x472d50
    if (!cpu.flags.zf)
    {
        goto L_0x00472d50;
    }
    // 00472ceb  833d10fc500000         +cmp dword ptr [0x50fc10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472cf2  7e4d                   -jle 0x472d41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472d41;
    }
    // 00472cf4  8b1510fc5000           -mov edx, dword ptr [0x50fc10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 00472cfa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472cfc  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472cfe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472d00  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00472d03:
    // 00472d03  8b91d8fa5000           -mov edx, dword ptr [ecx + 0x50fad8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472d09  8bba1c020000           -mov edi, dword ptr [edx + 0x21c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(540) /* 0x21c */);
    // 00472d0f  833f24                 +cmp dword ptr [edi], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472d12  745b                   -je 0x472d6f
    if (cpu.flags.zf)
    {
        goto L_0x00472d6f;
    }
    // 00472d14  83ba8002000002         +cmp dword ptr [edx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472d1b  753d                   -jne 0x472d5a
    if (!cpu.flags.zf)
    {
        goto L_0x00472d5a;
    }
    // 00472d1d  8b9224020000           -mov edx, dword ptr [edx + 0x224]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */);
    // 00472d23  8b2d18ed5300           -mov ebp, dword ptr [0x53ed18]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00472d29  81c240010000           -add edx, 0x140
    (cpu.edx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00472d2f  39ea                   +cmp edx, ebp
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
    // 00472d31  7d27                   -jge 0x472d5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472d5a;
    }
L_0x00472d33:
    // 00472d33  43                     -inc ebx
    (cpu.ebx)++;
L_0x00472d34:
    // 00472d34  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00472d37  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00472d3a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472d3d  39f8                   +cmp eax, edi
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
    // 00472d3f  7cc2                   -jl 0x472d03
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472d03;
    }
L_0x00472d41:
    // 00472d41  a110fc5000             -mov eax, dword ptr [0x50fc10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 00472d46  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00472d48  39c3                   +cmp ebx, eax
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
    // 00472d4a  7504                   -jne 0x472d50
    if (!cpu.flags.zf)
    {
        goto L_0x00472d50;
    }
    // 00472d4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472d4e  7f22                   -jg 0x472d72
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00472d72;
    }
L_0x00472d50:
    // 00472d50  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472d53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472d5a:
    // 00472d5a  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472d61  75d1                   -jne 0x472d34
    if (!cpu.flags.zf)
    {
        goto L_0x00472d34;
    }
    // 00472d63  6683b8b811510000       +cmp word ptr [eax + 0x5111b8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5312952) /* 0x5111b8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00472d6b  75c6                   -jne 0x472d33
    if (!cpu.flags.zf)
    {
        goto L_0x00472d33;
    }
    // 00472d6d  ebc5                   -jmp 0x472d34
    goto L_0x00472d34;
L_0x00472d6f:
    // 00472d6f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00472d70  ebc2                   -jmp 0x472d34
    goto L_0x00472d34;
L_0x00472d72:
    // 00472d72  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00472d77  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00472d7c  892df4ec5300           -mov dword ptr [0x53ecf4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.ebp;
    // 00472d82  e819000000             -call 0x472da0
    cpu.esp -= 4;
    sub_472da0(app, cpu);
    if (cpu.terminate) return;
    // 00472d87  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472d8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472da0);
    // 00472da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472da1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472da2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472da4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472da5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472da6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472da9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00472dab  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472db0  8b0d10fc5000           -mov ecx, dword ptr [0x50fc10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 00472db6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00472db8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00472dbb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472dbd  0f8e7b000000           -jle 0x472e3e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472e3e;
    }
    // 00472dc3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00472dc5:
    // 00472dc5  8b1570f65000           -mov edx, dword ptr [0x50f670]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5305968) /* 0x50f670 */);
    // 00472dcb  0faf15ccff5000         -imul edx, dword ptr [0x50ffcc]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308364) /* 0x50ffcc */))));
    // 00472dd2  8b99d8fa5000           -mov ebx, dword ptr [ecx + 0x50fad8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472dd8  8b831c020000           -mov eax, dword ptr [ebx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(540) /* 0x21c */);
    // 00472dde  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472de1  0f85ec000000           -jne 0x472ed3
    if (!cpu.flags.zf)
    {
        goto L_0x00472ed3;
    }
    // 00472de7  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00472ded  39ea                   +cmp edx, ebp
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
    // 00472def  7e16                   -jle 0x472e07
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472e07;
    }
    // 00472df1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472df3  0f85c0000000           -jne 0x472eb9
    if (!cpu.flags.zf)
    {
        goto L_0x00472eb9;
    }
    // 00472df9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00472dfb:
    // 00472dfb  8b91d8fa5000           -mov edx, dword ptr [ecx + 0x50fad8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472e01  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
L_0x00472e07:
    // 00472e07  8b81d8fa5000           -mov eax, dword ptr [ecx + 0x50fad8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472e0d  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00472e13:
    // 00472e13  83ff01                 +cmp edi, 1
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
    // 00472e16  7518                   -jne 0x472e30
    if (!cpu.flags.zf)
    {
        goto L_0x00472e30;
    }
    // 00472e18  3b3dc8ff5000           +cmp edi, dword ptr [0x50ffc8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308360) /* 0x50ffc8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e1e  0f8418010000           -je 0x472f3c
    if (cpu.flags.zf)
    {
        goto L_0x00472f3c;
    }
    // 00472e24  8b81d8fa5000           -mov eax, dword ptr [ecx + 0x50fad8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
L_0x00472e2a:
    // 00472e2a  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00472e30:
    // 00472e30  8b1d10fc5000           -mov ebx, dword ptr [0x50fc10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 00472e36  46                     -inc esi
    (cpu.esi)++;
    // 00472e37  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472e3a  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e3c  7c87                   -jl 0x472dc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472dc5;
    }
L_0x00472e3e:
    // 00472e3e  8b2d00fc5000           -mov ebp, dword ptr [0x50fc00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5307392) /* 0x50fc00 */);
    // 00472e44  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00472e46  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472e48  7e65                   -jle 0x472eaf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472eaf;
    }
    // 00472e4a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00472e4c:
    // 00472e4c  8b9918fa5000           -mov ebx, dword ptr [ecx + 0x50fa18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5306904) /* 0x50fa18 */);
    // 00472e52  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e59  7435                   -je 0x472e90
    if (cpu.flags.zf)
    {
        goto L_0x00472e90;
    }
    // 00472e5b  83bb2002000000         +cmp dword ptr [ebx + 0x220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e62  0f85f8000000           -jne 0x472f60
    if (!cpu.flags.zf)
    {
        goto L_0x00472f60;
    }
    // 00472e68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00472e6a:
    // 00472e6a  8b9118fa5000           -mov edx, dword ptr [ecx + 0x50fa18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5306904) /* 0x50fa18 */);
    // 00472e70  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 00472e76  833c2400               +cmp dword ptr [esp], 0
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
    // 00472e7a  0f840d010000           -je 0x472f8d
    if (cpu.flags.zf)
    {
        goto L_0x00472f8d;
    }
    // 00472e80  8b8118fa5000           -mov eax, dword ptr [ecx + 0x50fa18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5306904) /* 0x50fa18 */);
    // 00472e86  c7808002000002000000   -mov dword ptr [eax + 0x280], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
L_0x00472e90:
    // 00472e90  83ff01                 +cmp edi, 1
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
    // 00472e93  750c                   -jne 0x472ea1
    if (!cpu.flags.zf)
    {
        goto L_0x00472ea1;
    }
    // 00472e95  8b8118fa5000           -mov eax, dword ptr [ecx + 0x50fa18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5306904) /* 0x50fa18 */);
    // 00472e9b  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00472ea1:
    // 00472ea1  8b2d00fc5000           -mov ebp, dword ptr [0x50fc00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5307392) /* 0x50fc00 */);
    // 00472ea7  46                     -inc esi
    (cpu.esi)++;
    // 00472ea8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472eab  39ee                   +cmp esi, ebp
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
    // 00472ead  7c9d                   -jl 0x472e4c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472e4c;
    }
L_0x00472eaf:
    // 00472eaf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472eb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eb5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472eb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472eb9:
    // 00472eb9  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00472ebf  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00472ec4  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00472ec7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472ec9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472ecc  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472ece  e928ffffff             -jmp 0x472dfb
    goto L_0x00472dfb;
L_0x00472ed3:
    // 00472ed3  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472eda  0f8433ffffff           -je 0x472e13
    if (cpu.flags.zf)
    {
        goto L_0x00472e13;
    }
    // 00472ee0  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00472ee6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00472ee8  7531                   -jne 0x472f1b
    if (!cpu.flags.zf)
    {
        goto L_0x00472f1b;
    }
    // 00472eea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00472eec:
    // 00472eec  8b91d8fa5000           -mov edx, dword ptr [ecx + 0x50fad8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472ef2  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 00472ef8  833dc8ff500001         +cmp dword ptr [0x50ffc8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308360) /* 0x50ffc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472eff  7431                   -je 0x472f32
    if (cpu.flags.zf)
    {
        goto L_0x00472f32;
    }
L_0x00472f01:
    // 00472f01  8b81d8fa5000           -mov eax, dword ptr [ecx + 0x50fad8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472f07  c7808002000001000000   -mov dword ptr [eax + 0x280], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
L_0x00472f11:
    // 00472f11  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00472f13  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00472f16  e9f8feffff             -jmp 0x472e13
    goto L_0x00472e13;
L_0x00472f1b:
    // 00472f1b  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00472f21  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00472f26  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00472f29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472f2b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472f2e  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472f30  ebba                   -jmp 0x472eec
    goto L_0x00472eec;
L_0x00472f32:
    // 00472f32  3b35dcff5000           +cmp esi, dword ptr [0x50ffdc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f38  75d7                   -jne 0x472f11
    if (!cpu.flags.zf)
    {
        goto L_0x00472f11;
    }
    // 00472f3a  ebc5                   -jmp 0x472f01
    goto L_0x00472f01;
L_0x00472f3c:
    // 00472f3c  8b81d8fa5000           -mov eax, dword ptr [ecx + 0x50fad8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00472f42  83b88002000002         +cmp dword ptr [eax + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f49  0f84e1feffff           -je 0x472e30
    if (cpu.flags.zf)
    {
        goto L_0x00472e30;
    }
    // 00472f4f  3b35dcff5000           +cmp esi, dword ptr [0x50ffdc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f55  0f85d5feffff           -jne 0x472e30
    if (!cpu.flags.zf)
    {
        goto L_0x00472e30;
    }
    // 00472f5b  e9cafeffff             -jmp 0x472e2a
    goto L_0x00472e2a;
L_0x00472f60:
    // 00472f60  8b1570f65000           -mov edx, dword ptr [0x50f670]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5305968) /* 0x50f670 */);
    // 00472f66  0faf15ccff5000         -imul edx, dword ptr [0x50ffcc]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308364) /* 0x50ffcc */))));
    // 00472f6d  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00472f73  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00472f78  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00472f7b  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00472f81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472f83  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472f86  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472f88  e9ddfeffff             -jmp 0x472e6a
    goto L_0x00472e6a;
L_0x00472f8d:
    // 00472f8d  8b8118fa5000           -mov eax, dword ptr [ecx + 0x50fa18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5306904) /* 0x50fa18 */);
    // 00472f93  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
    // 00472f99  e9f2feffff             -jmp 0x472e90
    goto L_0x00472e90;
}

/* align: skip 0x00 0x00 */
void Application::sub_472fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00472fa0);
    // 00472fa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472fa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472fa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472fa4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472fa5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472fa6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00472fa9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00472fab  8b9030020000           -mov edx, dword ptr [eax + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 00472fb1  83fa08                 +cmp edx, 8
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
    // 00472fb4  7d73                   -jge 0x473029
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473029;
    }
    // 00472fb6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00472fbd  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00472fc0  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00472fc6  3b8258020000           +cmp eax, dword ptr [edx + 0x258]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472fcc  7e5b                   -jle 0x473029
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473029;
    }
    // 00472fce  f685f401000008         +test byte ptr [ebp + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 00472fd5  0f8494020000           -je 0x47326f
    if (cpu.flags.zf)
    {
        goto L_0x0047326f;
    }
    // 00472fdb  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00472fe1  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00472fe3  83fb0f                 +cmp ebx, 0xf
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
    // 00472fe6  0f8d83020000           -jge 0x47326f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047326f;
    }
    // 00472fec  833dd8ff500002         +cmp dword ptr [0x50ffd8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472ff3  0f8c2c020000           -jl 0x473225
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473225;
    }
    // 00472ff9  6985e801000099190000   -imul eax, dword ptr [ebp + 0x1e8], 0x1999
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */))) * x86::sreg64(x86::sreg32(6553 /*0x1999*/)));
    // 00473003  8b149d903d4d00         -mov edx, dword ptr [ebx*4 + 0x4d3d90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5062032) /* 0x4d3d90 */ + cpu.ebx * 4);
    // 0047300a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047300c  8b9db8020000           -mov ebx, dword ptr [ebp + 0x2b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00473012  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473014  39da                   +cmp edx, ebx
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
    // 00473016  0f8d02020000           -jge 0x47321e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047321e;
    }
L_0x0047301c:
    // 0047301c  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00473022  89849558020000         -mov dword ptr [ebp + edx*4 + 0x258], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(600) /* 0x258 */ + cpu.edx * 4) = cpu.eax;
L_0x00473029:
    // 00473029  8bb5f8010000           -mov esi, dword ptr [ebp + 0x1f8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 0047302f  3bb530020000           +cmp esi, dword ptr [ebp + 0x230]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473035  0f8491000000           -je 0x4730cc
    if (cpu.flags.zf)
    {
        goto L_0x004730cc;
    }
    // 0047303b  83bd8002000002         +cmp dword ptr [ebp + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473042  0f8484000000           -je 0x4730cc
    if (cpu.flags.zf)
    {
        goto L_0x004730cc;
    }
    // 00473048  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047304d  8b9534020000           -mov edx, dword ptr [ebp + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 00473053  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473055  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473057  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0047305d  89948538020000         -mov dword ptr [ebp + eax*4 + 0x238], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(568) /* 0x238 */ + cpu.eax * 4) = cpu.edx;
    // 00473064  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00473069  898534020000           -mov dword ptr [ebp + 0x234], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 0047306f  8b85f8010000           -mov eax, dword ptr [ebp + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 00473075  8b0dccff5000           -mov ecx, dword ptr [0x50ffcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5308364) /* 0x50ffcc */);
    // 0047307b  898530020000           -mov dword ptr [ebp + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 00473081  39c8                   +cmp eax, ecx
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
    // 00473083  7547                   -jne 0x4730cc
    if (!cpu.flags.zf)
    {
        goto L_0x004730cc;
    }
    // 00473085  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0047308b  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047308e  743c                   -je 0x4730cc
    if (cpu.flags.zf)
    {
        goto L_0x004730cc;
    }
    // 00473090  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00473096  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047309b  42                     -inc edx
    (cpu.edx)++;
    // 0047309c  898524020000           -mov dword ptr [ebp + 0x224], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 004730a2  a170f65000             -mov eax, dword ptr [0x50f670]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5305968) /* 0x50f670 */);
    // 004730a7  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004730aa  8bb534020000           -mov esi, dword ptr [ebp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 004730b0  c7858002000002000000   -mov dword ptr [ebp + 0x280], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
    // 004730ba  81ee00020000           -sub esi, 0x200
    (cpu.esi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004730c0  89b534020000           -mov dword ptr [ebp + 0x234], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.esi;
    // 004730c6  899520020000           -mov dword ptr [ebp + 0x220], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.edx;
L_0x004730cc:
    // 004730cc  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004730cf  3bbd28020000           +cmp edi, dword ptr [ebp + 0x228]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004730d5  7455                   -je 0x47312c
    if (cpu.flags.zf)
    {
        goto L_0x0047312c;
    }
    // 004730d7  8b8580020000           -mov eax, dword ptr [ebp + 0x280]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
    // 004730dd  89bd28020000           -mov dword ptr [ebp + 0x228], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */) = cpu.edi;
    // 004730e3  83f802                 +cmp eax, 2
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
    // 004730e6  7444                   -je 0x47312c
    if (cpu.flags.zf)
    {
        goto L_0x0047312c;
    }
    // 004730e8  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 004730ed  8b15f8ff5000           -mov edx, dword ptr [0x50fff8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308408) /* 0x50fff8 */);
    // 004730f3  898524020000           -mov dword ptr [ebp + 0x224], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 004730f9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004730fb  0f848b010000           -je 0x47328c
    if (cpu.flags.zf)
    {
        goto L_0x0047328c;
    }
    // 00473101  8b1570f65000           -mov edx, dword ptr [0x50f670]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5305968) /* 0x50f670 */);
    // 00473107  2b9528020000           -sub edx, dword ptr [ebp + 0x228]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
L_0x0047310d:
    // 0047310d  8b9dfc010000           -mov ebx, dword ptr [ebp + 0x1fc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(508) /* 0x1fc */);
    // 00473113  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00473119  8b3570f65000           -mov esi, dword ptr [0x50f670]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5305968) /* 0x50f670 */);
    // 0047311f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473121  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00473124  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473126  898520020000           -mov dword ptr [ebp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x0047312c:
    // 0047312c  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00473132  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473135  0f84d9000000           -je 0x473214
    if (cpu.flags.zf)
    {
        goto L_0x00473214;
    }
    // 0047313b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047313d  8b1514fc5000           -mov edx, dword ptr [0x50fc14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */);
    // 00473143  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00473147  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473149  0f8ec5000000           -jle 0x473214
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473214;
    }
    // 0047314f  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00473152  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00473155:
    // 00473155  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473159  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047315c  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 00473162  8bb0d42e5400           -mov esi, dword ptr [eax + 0x542ed4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517012) /* 0x542ed4 */);
    // 00473168  39f2                   +cmp edx, esi
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
    // 0047316a  0f8e27010000           -jle 0x473297
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473297;
    }
L_0x00473170:
    // 00473170  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473173  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473177  39d8                   +cmp eax, ebx
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
    // 00473179  7c3f                   -jl 0x4731ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004731ba;
    }
    // 0047317b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047317d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00473180  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
L_0x00473183:
    // 00473183  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473186  8bb0e02e5400           -mov esi, dword ptr [eax + 0x542ee0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517024) /* 0x542ee0 */);
    // 0047318c  8b90e42e5400           -mov edx, dword ptr [eax + 0x542ee4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517028) /* 0x542ee4 */);
    // 00473192  89b0f02e5400           -mov dword ptr [eax + 0x542ef0], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517040) /* 0x542ef0 */) = cpu.esi;
    // 00473198  8990f42e5400           -mov dword ptr [eax + 0x542ef4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517044) /* 0x542ef4 */) = cpu.edx;
    // 0047319e  8b98e82e5400           -mov ebx, dword ptr [eax + 0x542ee8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517032) /* 0x542ee8 */);
    // 004731a4  8b88ec2e5400           -mov ecx, dword ptr [eax + 0x542eec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517036) /* 0x542eec */);
    // 004731aa  8998f82e5400           -mov dword ptr [eax + 0x542ef8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517048) /* 0x542ef8 */) = cpu.ebx;
    // 004731b0  8988fc2e5400           -mov dword ptr [eax + 0x542efc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517052) /* 0x542efc */) = cpu.ecx;
    // 004731b6  39f8                   +cmp eax, edi
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
    // 004731b8  7dc9                   -jge 0x473183
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473183;
    }
L_0x004731ba:
    // 004731ba  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004731be  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 004731c4  8b8d24020000           -mov ecx, dword ptr [ebp + 0x224]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */);
    // 004731ca  8bb5e8010000           -mov esi, dword ptr [ebp + 0x1e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */);
    // 004731d0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004731d3  8b9df4010000           -mov ebx, dword ptr [ebp + 0x1f4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(500) /* 0x1f4 */);
    // 004731d9  89b0d02e5400           -mov dword ptr [eax + 0x542ed0], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517008) /* 0x542ed0 */) = cpu.esi;
    // 004731df  8990d42e5400           -mov dword ptr [eax + 0x542ed4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517012) /* 0x542ed4 */) = cpu.edx;
    // 004731e5  83e304                 -and ebx, 4
    cpu.ebx &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004731e8  8988d82e5400           -mov dword ptr [eax + 0x542ed8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517016) /* 0x542ed8 */) = cpu.ecx;
    // 004731ee  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 004731f3  8998dc2e5400           -mov dword ptr [eax + 0x542edc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517020) /* 0x542edc */) = cpu.ebx;
    // 004731f9  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x004731fd:
    // 004731fd  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473201  41                     -inc ecx
    (cpu.ecx)++;
    // 00473202  8b1d14fc5000           -mov ebx, dword ptr [0x50fc14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */);
    // 00473208  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047320c  39d9                   +cmp ecx, ebx
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
    // 0047320e  0f8c41ffffff           -jl 0x473155
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473155;
    }
L_0x00473214:
    // 00473214  83c408                 +add esp, 8
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
    // 00473217  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473218  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473219  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047321a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047321b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047321c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047321d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047321e:
    // 0047321e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00473220  e9f7fdffff             -jmp 0x47301c
    goto L_0x0047301c;
L_0x00473225:
    // 00473225  e8f56b0200             -call 0x499e1f
    cpu.esp -= 4;
    sub_499e1f(app, cpu);
    if (cpu.terminate) return;
    // 0047322a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047322c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047322f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473231  8b149d903d4d00         -mov edx, dword ptr [ebx*4 + 0x4d3d90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5062032) /* 0x4d3d90 */ + cpu.ebx * 4);
    // 00473238  8bbdb8020000           -mov edi, dword ptr [ebp + 0x2b8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0047323e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00473240  39fa                   +cmp edx, edi
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
    // 00473242  7d24                   -jge 0x473268
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473268;
    }
    // 00473244  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0047324a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047324c  e8ce6b0200             -call 0x499e1f
    cpu.esp -= 4;
    sub_499e1f(app, cpu);
    if (cpu.terminate) return;
    // 00473251  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473253  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473256  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473258  8b148d903d4d00         -mov edx, dword ptr [ecx*4 + 0x4d3d90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5062032) /* 0x4d3d90 */ + cpu.ecx * 4);
    // 0047325f  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00473261  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473263  e9b4fdffff             -jmp 0x47301c
    goto L_0x0047301c;
L_0x00473268:
    // 00473268  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047326a  e9adfdffff             -jmp 0x47301c
    goto L_0x0047301c;
L_0x0047326f:
    // 0047326f  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00473275  c1e002                 +shl eax, 2
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
    // 00473278  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0047327b  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00473281  898258020000           -mov dword ptr [edx + 0x258], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */) = cpu.eax;
    // 00473287  e99dfdffff             -jmp 0x473029
    goto L_0x00473029;
L_0x0047328c:
    // 0047328c  8b9528020000           -mov edx, dword ptr [ebp + 0x228]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */);
    // 00473292  e976feffff             -jmp 0x47310d
    goto L_0x0047310d;
L_0x00473297:
    // 00473297  0f8560ffffff           -jne 0x4731fd
    if (!cpu.flags.zf)
    {
        goto L_0x004731fd;
    }
    // 0047329d  8b88d82e5400           -mov ecx, dword ptr [eax + 0x542ed8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517016) /* 0x542ed8 */);
    // 004732a3  3b8d24020000           +cmp ecx, dword ptr [ebp + 0x224]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004732a9  0f8fc1feffff           -jg 0x473170
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00473170;
    }
    // 004732af  e949ffffff             -jmp 0x4731fd
    goto L_0x004731fd;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4732c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004732c0);
    // 004732c0  83f801                 +cmp eax, 1
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
    // 004732c3  7e11                   -jle 0x4732d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004732d6;
    }
    // 004732c5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004732c8  8b80b02e5400           -mov eax, dword ptr [eax + 0x542eb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5516976) /* 0x542eb0 */);
    // 004732ce  8b048518f95000         -mov eax, dword ptr [eax*4 + 0x50f918]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5306648) /* 0x50f918 */ + cpu.eax * 4);
    // 004732d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004732d6:
    // 004732d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004732d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4732e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004732e0);
    // 004732e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004732e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004732e2  8b0d14fc5000           -mov ecx, dword ptr [0x50fc14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */);
    // 004732e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004732ea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004732ec  7e16                   -jle 0x473304
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473304;
    }
    // 004732ee  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004732f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004732f3:
    // 004732f3  83b8d02e5400ff         +cmp dword ptr [eax + 0x542ed0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517008) /* 0x542ed0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004732fa  7401                   -je 0x4732fd
    if (cpu.flags.zf)
    {
        goto L_0x004732fd;
    }
    // 004732fc  42                     -inc edx
    (cpu.edx)++;
L_0x004732fd:
    // 004732fd  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473300  39c8                   +cmp eax, ecx
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
    // 00473302  7cef                   -jl 0x4732f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004732f3;
    }
L_0x00473304:
    // 00473304  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473306  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473307  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473308  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473310);
    // 00473310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473314  8b3514fc5000           -mov esi, dword ptr [0x50fc14]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */);
    // 0047331a  8b98e8010000           -mov ebx, dword ptr [eax + 0x1e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 00473320  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473322  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473324  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00473326  7e15                   -jle 0x47333d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047333d;
    }
    // 00473328  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047332a:
    // 0047332a  3b9ad02e5400           +cmp ebx, dword ptr [edx + 0x542ed0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5517008) /* 0x542ed0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473330  7503                   -jne 0x473335
    if (!cpu.flags.zf)
    {
        goto L_0x00473335;
    }
    // 00473332  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00473335:
    // 00473335  40                     -inc eax
    (cpu.eax)++;
    // 00473336  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473339  39f0                   +cmp eax, esi
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
    // 0047333b  7ced                   -jl 0x47332a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047332a;
    }
L_0x0047333d:
    // 0047333d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047333f  893514fc5000           -mov dword ptr [0x50fc14], esi
    app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */) = cpu.esi;
    // 00473345  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473346  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473347  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473348  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473350);
    // 00473350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473352  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473353  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00473358  b96179feff             -mov ecx, 0xfffe7961
    cpu.ecx = 4294867297 /*0xfffe7961*/;
    // 0047335d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047335f:
    // 0047335f  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473362  8988c42e5400           -mov dword ptr [eax + 0x542ec4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5516996) /* 0x542ec4 */) = cpu.ecx;
    // 00473368  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047336a  8990c02e5400           -mov dword ptr [eax + 0x542ec0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5516992) /* 0x542ec0 */) = cpu.edx;
    // 00473370  8998c82e5400           -mov dword ptr [eax + 0x542ec8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517000) /* 0x542ec8 */) = cpu.ebx;
    // 00473376  8998cc2e5400           -mov dword ptr [eax + 0x542ecc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5517004) /* 0x542ecc */) = cpu.ebx;
    // 0047337c  3dc0000000             +cmp eax, 0xc0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473381  75dc                   -jne 0x47335f
    if (!cpu.flags.zf)
    {
        goto L_0x0047335f;
    }
    // 00473383  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473390);
    // 00473390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473394  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473395  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473396  8b2d10fc5000           -mov ebp, dword ptr [0x50fc10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 0047339c  bf63000000             -mov edi, 0x63
    cpu.edi = 99 /*0x63*/;
    // 004733a1  8b0d14fc5000           -mov ecx, dword ptr [0x50fc14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */);
    // 004733a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004733a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004733ab  7e54                   -jle 0x473401
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473401;
    }
    // 004733ad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004733af  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004733b1:
    // 004733b1  8b8398fa5000           -mov eax, dword ptr [ebx + 0x50fa98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5307032) /* 0x50fa98 */);
    // 004733b7  e854ffffff             -call 0x473310
    cpu.esp -= 4;
    sub_473310(app, cpu);
    if (cpu.terminate) return;
    // 004733bc  8bb398fa5000           -mov esi, dword ptr [ebx + 0x50fa98]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5307032) /* 0x50fa98 */);
    // 004733c2  898678020000           -mov dword ptr [esi + 0x278], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(632) /* 0x278 */) = cpu.eax;
    // 004733c8  83b9dc2e540000         +cmp dword ptr [ecx + 0x542edc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5517020) /* 0x542edc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004733cf  741f                   -je 0x4733f0
    if (cpu.flags.zf)
    {
        goto L_0x004733f0;
    }
    // 004733d1  83ff63                 +cmp edi, 0x63
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004733d4  751a                   -jne 0x4733f0
    if (!cpu.flags.zf)
    {
        goto L_0x004733f0;
    }
    // 004733d6  8b81d02e5400           -mov eax, dword ptr [ecx + 0x542ed0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5517008) /* 0x542ed0 */);
    // 004733dc  8b048598fa5000         -mov eax, dword ptr [eax*4 + 0x50fa98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307032) /* 0x50fa98 */ + cpu.eax * 4);
    // 004733e3  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 004733e9  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004733ec  7402                   -je 0x4733f0
    if (cpu.flags.zf)
    {
        goto L_0x004733f0;
    }
    // 004733ee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x004733f0:
    // 004733f0  8b3514fc5000           -mov esi, dword ptr [0x50fc14]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5307412) /* 0x50fc14 */);
    // 004733f6  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004733f9  42                     -inc edx
    (cpu.edx)++;
    // 004733fa  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004733fd  39f2                   +cmp edx, esi
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
    // 004733ff  7cb0                   -jl 0x4733b1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004733b1;
    }
L_0x00473401:
    // 00473401  a1e0ff5000             -mov eax, dword ptr [0x50ffe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308384) /* 0x50ffe0 */);
    // 00473406  8b2d10fc5000           -mov ebp, dword ptr [0x50fc10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 0047340c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047340e  744b                   -je 0x47345b
    if (cpu.flags.zf)
    {
        goto L_0x0047345b;
    }
    // 00473410  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00473412  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00473414  7e45                   -jle 0x47345b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047345b;
    }
    // 00473416  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00473419  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047341b:
    // 0047341b  8b83d8fa5000           -mov eax, dword ptr [ebx + 0x50fad8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5307096) /* 0x50fad8 */);
    // 00473421  8b901c020000           -mov edx, dword ptr [eax + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 00473427  833a24                 +cmp dword ptr [edx], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047342a  741d                   -je 0x473449
    if (cpu.flags.zf)
    {
        goto L_0x00473449;
    }
    // 0047342c  8b9020020000           -mov edx, dword ptr [eax + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00473432  8b8fd42e5400           -mov ecx, dword ptr [edi + 0x542ed4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5517012) /* 0x542ed4 */);
    // 00473438  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047343a  6b15d4ff500074         -imul edx, dword ptr [0x50ffd4], 0x74
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308372) /* 0x50ffd4 */))) * x86::sreg64(x86::sreg32(116 /*0x74*/)));
    // 00473441  3b8a6cfb5000           +cmp ecx, dword ptr [edx + 0x50fb6c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307244) /* 0x50fb6c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473447  7d1f                   -jge 0x473468
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473468;
    }
L_0x00473449:
    // 00473449  c7801802000000000100   -mov dword ptr [eax + 0x218], 0x10000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = 65536 /*0x10000*/;
L_0x00473453:
    // 00473453  46                     -inc esi
    (cpu.esi)++;
    // 00473454  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473457  39ee                   +cmp esi, ebp
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
    // 00473459  7cc0                   -jl 0x47341b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047341b;
    }
L_0x0047345b:
    // 0047345b  892d10fc5000           -mov dword ptr [0x50fc10], ebp
    app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */) = cpu.ebp;
    // 00473461  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473462  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473463  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473464  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473465  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473466  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473467  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473468:
    // 00473468  3b8a70fb5000           +cmp ecx, dword ptr [edx + 0x50fb70]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307248) /* 0x50fb70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047346e  7d0e                   -jge 0x47347e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047347e;
    }
    // 00473470  8b927cfb5000           -mov edx, dword ptr [edx + 0x50fb7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307260) /* 0x50fb7c */);
    // 00473476  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 0047347c  ebd5                   -jmp 0x473453
    goto L_0x00473453;
L_0x0047347e:
    // 0047347e  3b8a74fb5000           +cmp ecx, dword ptr [edx + 0x50fb74]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307252) /* 0x50fb74 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473484  7d0e                   -jge 0x473494
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473494;
    }
    // 00473486  8b9280fb5000           -mov edx, dword ptr [edx + 0x50fb80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307264) /* 0x50fb80 */);
    // 0047348c  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00473492  ebbf                   -jmp 0x473453
    goto L_0x00473453;
L_0x00473494:
    // 00473494  3b8a78fb5000           +cmp ecx, dword ptr [edx + 0x50fb78]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307256) /* 0x50fb78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047349a  7d0e                   -jge 0x4734aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004734aa;
    }
    // 0047349c  8b9284fb5000           -mov edx, dword ptr [edx + 0x50fb84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307268) /* 0x50fb84 */);
    // 004734a2  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 004734a8  eba9                   -jmp 0x473453
    goto L_0x00473453;
L_0x004734aa:
    // 004734aa  8b9288fb5000           -mov edx, dword ptr [edx + 0x50fb88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307272) /* 0x50fb88 */);
    // 004734b0  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 004734b6  eb9b                   -jmp 0x473453
    goto L_0x00473453;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 04000000080000000a0000000c00000010000000400000001800000000000000 */
void Application::sub_4734e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004734e0);
    // 004734e0  0305d0344700           -add eax, dword ptr [0x4734d0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4666576) /* 0x4734d0 */)));
    // 004734e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4734f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004734f0);
    // 004734f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004734f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004734f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004734f3  8b0dcc344700           -mov ecx, dword ptr [0x4734cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4666572) /* 0x4734cc */);
    // 004734f9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004734fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004734fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004734ff  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473502  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473504  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00473506  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 0047350a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047350b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047350c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047350d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_473510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473510);
    // 00473510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473513  8b0dc8344700           -mov ecx, dword ptr [0x4734c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4666568) /* 0x4734c8 */);
    // 00473519  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047351b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047351d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047351f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473522  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473524  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00473526  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 0047352a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047352d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_473530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473530);
    // 00473530  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473531  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473532  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473533  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473534  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473535  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473538  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047353a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047353c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047353e  a1c4344700             -mov eax, dword ptr [0x4734c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4666564) /* 0x4734c4 */);
    // 00473543  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00473546  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473548  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047354b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047354d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047354f  0fbf3c46               -movsx edi, word ptr [esi + eax*2]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 00473553  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00473555  7427                   -je 0x47357e
    if (cpu.flags.zf)
    {
        goto L_0x0047357e;
    }
    // 00473557  a1d4344700             -mov eax, dword ptr [0x4734d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4666580) /* 0x4734d4 */);
    // 0047355c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047355e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00473560  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473562  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473564  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00473566  7e16                   -jle 0x47357e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047357e;
    }
L_0x00473568:
    // 00473568  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047356a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047356c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047356e  668b5904               -mov bx, word ptr [ecx + 4]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00473572  39eb                   +cmp ebx, ebp
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
    // 00473574  7414                   -je 0x47358a
    if (cpu.flags.zf)
    {
        goto L_0x0047358a;
    }
    // 00473576  40                     -inc eax
    (cpu.eax)++;
    // 00473577  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047357a  39f8                   +cmp eax, edi
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
    // 0047357c  7cea                   -jl 0x473568
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473568;
    }
L_0x0047357e:
    // 0047357e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473581  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473584  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473585  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473586  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473587  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473588  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047358a:
    // 0047358a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047358d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473590  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473593  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473594  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473595  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473596  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473597  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473598  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4735a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004735a0);
    // 004735a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004735a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004735a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004735a4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004735a6  668b480a               -mov cx, word ptr [eax + 0xa]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 004735aa  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004735b1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004735b3  8b0dd8344700           -mov ecx, dword ptr [0x4734d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4666584) /* 0x4734d8 */);
    // 004735b9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004735bb  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004735bd  668b5204               -mov dx, word ptr [edx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004735c1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004735c3  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004735c9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004735d0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004735d2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004735d4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004735d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4735e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004735e0);
    // 004735e0  0305d8344700           -add eax, dword ptr [0x4734d8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4666584) /* 0x4734d8 */)));
    // 004735e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4735f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004735f0);
    // 004735f0  0305d4344700           -add eax, dword ptr [0x4734d4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4666580) /* 0x4734d4 */)));
    // 004735f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473600);
    // 00473600  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473601  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473603  3b05ac2f5400           +cmp eax, dword ptr [0x542fac]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473609  730b                   -jae 0x473616
    if (!cpu.flags.cf)
    {
        goto L_0x00473616;
    }
    // 0047360b  a1a8744d00             -mov eax, dword ptr [0x4d74a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076136) /* 0x4d74a8 */);
    // 00473610  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 00473614  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473615  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473616:
    // 00473616  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473617  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473618  bb08010000             -mov ebx, 0x108
    cpu.ebx = 264 /*0x108*/;
    // 0047361d  ba04c14c00             -mov edx, 0x4cc104
    cpu.edx = 5030148 /*0x4cc104*/;
    // 00473622  b864c14c00             -mov eax, 0x4cc164
    cpu.eax = 5030244 /*0x4cc164*/;
    // 00473627  e827680200             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 0047362c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047362d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047362e  a1a8744d00             -mov eax, dword ptr [0x4d74a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076136) /* 0x4d74a8 */);
    // 00473633  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 00473637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473638  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473640);
    // 00473640  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473641  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473642  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473644  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00473646  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473648  668b4104               -mov ax, word ptr [ecx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047364c  39c2                   +cmp edx, eax
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
    // 0047364e  7d0b                   -jge 0x47365b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047365b;
    }
    // 00473650  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00473653  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00473656  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00473658  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473659  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047365a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047365b:
    // 0047365b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047365c  bbf7000000             -mov ebx, 0xf7
    cpu.ebx = 247 /*0xf7*/;
    // 00473661  ba04c14c00             -mov edx, 0x4cc104
    cpu.edx = 5030148 /*0x4cc104*/;
    // 00473666  b840c14c00             -mov eax, 0x4cc140
    cpu.eax = 5030208 /*0x4cc140*/;
    // 0047366b  e8e3670200             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 00473670  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473671  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00473674  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00473677  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00473679  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047367a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047367b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473680);
    // 00473680  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473681  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473683  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473686  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473688  8b15a4744d00           -mov edx, dword ptr [0x4d74a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076132) /* 0x4d74a4 */);
    // 0047368e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473691  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473693  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473694  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4736a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004736a0);
    // 004736a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004736a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004736a2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004736a9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004736ab  8b35a4744d00           -mov esi, dword ptr [0x4d74a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076132) /* 0x4d74a4 */);
    // 004736b1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004736b4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004736b6  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004736b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736b9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4736c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004736c0);
    // 004736c0  3b05b02f5400           +cmp eax, dword ptr [0x542fb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004736c6  7506                   -jne 0x4736ce
    if (!cpu.flags.zf)
    {
        goto L_0x004736ce;
    }
    // 004736c8  a19c2f5400             -mov eax, dword ptr [0x542f9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517212) /* 0x542f9c */);
    // 004736cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004736ce:
    // 004736ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004736cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004736d0  bb94000000             -mov ebx, 0x94
    cpu.ebx = 148 /*0x94*/;
    // 004736d5  ba04c14c00             -mov edx, 0x4cc104
    cpu.edx = 5030148 /*0x4cc104*/;
    // 004736da  b824c14c00             -mov eax, 0x4cc124
    cpu.eax = 5030180 /*0x4cc124*/;
    // 004736df  e86f670200             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 004736e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736e6  a19c2f5400             -mov eax, dword ptr [0x542f9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517212) /* 0x542f9c */);
    // 004736eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4736f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004736f0);
    // 004736f0  3b05b02f5400           +cmp eax, dword ptr [0x542fb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004736f6  7506                   -jne 0x4736fe
    if (!cpu.flags.zf)
    {
        goto L_0x004736fe;
    }
    // 004736f8  a1982f5400             -mov eax, dword ptr [0x542f98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517208) /* 0x542f98 */);
    // 004736fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004736fe:
    // 004736fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004736ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473700  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00473705  ba04c14c00             -mov edx, 0x4cc104
    cpu.edx = 5030148 /*0x4cc104*/;
    // 0047370a  b824c14c00             -mov eax, 0x4cc124
    cpu.eax = 5030180 /*0x4cc124*/;
    // 0047370f  e83f670200             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 00473714  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473715  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473716  a1982f5400             -mov eax, dword ptr [0x542f98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517208) /* 0x542f98 */);
    // 0047371b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473720);
    // 00473720  3b05b02f5400           +cmp eax, dword ptr [0x542fb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473726  7506                   -jne 0x47372e
    if (!cpu.flags.zf)
    {
        goto L_0x0047372e;
    }
    // 00473728  a1a82f5400             -mov eax, dword ptr [0x542fa8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517224) /* 0x542fa8 */);
    // 0047372d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047372e:
    // 0047372e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047372f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473730  bb76000000             -mov ebx, 0x76
    cpu.ebx = 118 /*0x76*/;
    // 00473735  ba04c14c00             -mov edx, 0x4cc104
    cpu.edx = 5030148 /*0x4cc104*/;
    // 0047373a  b824c14c00             -mov eax, 0x4cc124
    cpu.eax = 5030180 /*0x4cc124*/;
    // 0047373f  e80f670200             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 00473744  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473745  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473746  a1a82f5400             -mov eax, dword ptr [0x542fa8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517224) /* 0x542fa8 */);
    // 0047374b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473750);
    // 00473750  3b05b02f5400           +cmp eax, dword ptr [0x542fb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473756  7506                   -jne 0x47375e
    if (!cpu.flags.zf)
    {
        goto L_0x0047375e;
    }
    // 00473758  a1ac2f5400             -mov eax, dword ptr [0x542fac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */);
    // 0047375d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047375e:
    // 0047375e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047375f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473760  bb67000000             -mov ebx, 0x67
    cpu.ebx = 103 /*0x67*/;
    // 00473765  ba04c14c00             -mov edx, 0x4cc104
    cpu.edx = 5030148 /*0x4cc104*/;
    // 0047376a  b824c14c00             -mov eax, 0x4cc124
    cpu.eax = 5030180 /*0x4cc124*/;
    // 0047376f  e8df660200             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 00473774  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473775  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473776  a1ac2f5400             -mov eax, dword ptr [0x542fac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */);
    // 0047377b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473780);
    // 00473780  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473781  8b15b02f5400           -mov edx, dword ptr [0x542fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 00473787  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473789  7502                   -jne 0x47378d
    if (!cpu.flags.zf)
    {
        goto L_0x0047378d;
    }
    // 0047378b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047378c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047378d:
    // 0047378d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047378f  e82ca70000             -call 0x47dec0
    cpu.esp -= 4;
    sub_47dec0(app, cpu);
    if (cpu.terminate) return;
    // 00473794  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473795  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4737a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004737a0);
    // 004737a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004737a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4737b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004737b0);
    // 004737b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004737b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004737b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004737b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004737b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004737b5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004737b8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004737ba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004737bc:
    // 004737bc  8b9a00305400           -mov ebx, dword ptr [edx + 0x543000]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5517312) /* 0x543000 */);
    // 004737c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004737c3  8bb2fc2f5400           -mov esi, dword ptr [edx + 0x542ffc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5517308) /* 0x542ffc */);
    // 004737c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004737ca  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004737cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004737ce  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 004737d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004737d1  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004737d5  e8c6aaffff             -call 0x46e2a0
    cpu.esp -= 4;
    sub_46e2a0(app, cpu);
    if (cpu.terminate) return;
    // 004737da  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004737dc  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004737de  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004737e1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004737e2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004737e3  81fa00010000           +cmp edx, 0x100
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
    // 004737e9  75d1                   -jne 0x4737bc
    if (!cpu.flags.zf)
    {
        goto L_0x004737bc;
    }
    // 004737eb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004737ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473800);
    // 00473800  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473803  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473806  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00473808:
    // 00473808  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047380a  e841abffff             -call 0x46e350
    cpu.esp -= 4;
    sub_46e350(app, cpu);
    if (cpu.terminate) return;
    // 0047380f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473811  8dbafc2f5400           -lea edi, [edx + 0x542ffc]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(5517308) /* 0x542ffc */);
    // 00473817  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047381a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047381b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047381c  81fa00010000           +cmp edx, 0x100
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
    // 00473822  75e4                   -jne 0x473808
    if (!cpu.flags.zf)
    {
        goto L_0x00473808;
    }
    // 00473824  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473827  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473828  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473829  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047382a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473830);
    // 00473830  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473831  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473832  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473833  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473834  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00473837  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00473839  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047383b  895c2464               -mov dword ptr [esp + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 0047383f  83b8bc00000000         +cmp dword ptr [eax + 0xbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473846  0f85b4000000           -jne 0x473900
    if (!cpu.flags.zf)
    {
        goto L_0x00473900;
    }
L_0x0047384c:
    // 0047384c  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047384f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473851  747b                   -je 0x4738ce
    if (cpu.flags.zf)
    {
        goto L_0x004738ce;
    }
    // 00473853  8d5e50                 -lea ebx, [esi + 0x50]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00473856  8d5150                 -lea edx, [ecx + 0x50]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00473859  8d4620                 -lea eax, [esi + 0x20]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047385c  e84f5f0200             -call 0x4997b0
    cpu.esp -= 4;
    sub_4997b0(app, cpu);
    if (cpu.terminate) return;
    // 00473861  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00473864  8b9e80000000           -mov ebx, dword ptr [esi + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0047386a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047386c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00473870  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00473873  8bae84000000           -mov ebp, dword ptr [esi + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00473879  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047387b  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047387f  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00473882  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00473888  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047388a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0047388e  8d5c2430               -lea ebx, [esp + 0x30]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00473892  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00473895  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00473899  83c250                 -add edx, 0x50
    (cpu.edx) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0047389c  e8efb20000             -call 0x47eb90
    cpu.esp -= 4;
    sub_47eb90(app, cpu);
    if (cpu.terminate) return;
    // 004738a1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004738a4  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004738a8  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004738ab  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004738ad  895674                 -mov dword ptr [esi + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004738b0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004738b3  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004738b7  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 004738ba  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004738bc  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004738bf  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004738c2  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004738c6  8b407c                 -mov eax, dword ptr [eax + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    // 004738c9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004738cb  89567c                 -mov dword ptr [esi + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.edx;
L_0x004738ce:
    // 004738ce  833e01                 +cmp dword ptr [esi], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004738d1  7544                   -jne 0x473917
    if (!cpu.flags.zf)
    {
        goto L_0x00473917;
    }
    // 004738d3  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004738d6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004738d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004738da  7e1c                   -jle 0x4738f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004738f8;
    }
    // 004738dc  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004738de:
    // 004738de  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004738e2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004738e4  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004738e7  e844ffffff             -call 0x473830
    cpu.esp -= 4;
    sub_473830(app, cpu);
    if (cpu.terminate) return;
    // 004738ec  45                     -inc ebp
    (cpu.ebp)++;
    // 004738ed  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004738f0  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004738f3  39c5                   +cmp ebp, eax
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
    // 004738f5  7ce7                   -jl 0x4738de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004738de;
    }
    // 004738f7  90                     -nop 
    ;
L_0x004738f8:
    // 004738f8  83c470                 +add esp, 0x70
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
    // 004738fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004738ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473900:
    // 00473900  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00473906  8b80c0000000           -mov eax, dword ptr [eax + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 0047390c  ff96bc000000           -call dword ptr [esi + 0xbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00473912  e935ffffff             -jmp 0x47384c
    goto L_0x0047384c;
L_0x00473917:
    // 00473917  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0047391d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047391f  74d7                   -je 0x4738f8
    if (cpu.flags.zf)
    {
        goto L_0x004738f8;
    }
    // 00473921  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00473923  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 00473927  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00473929  7ecd                   -jle 0x4738f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004738f8;
    }
    // 0047392b  8d4650                 -lea eax, [esi + 0x50]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 0047392e  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00473932  8d4744                 -lea eax, [edi + 0x44]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 00473935  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00473937  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0047393b:
    // 0047393b  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00473941  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473944  740f                   -je 0x473955
    if (cpu.flags.zf)
    {
        goto L_0x00473955;
    }
    // 00473946  833da4704d0000         +cmp dword ptr [0x4d70a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5075108) /* 0x4d70a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047394d  741e                   -je 0x47396d
    if (cpu.flags.zf)
    {
        goto L_0x0047396d;
    }
    // 0047394f  80782000               +cmp byte ptr [eax + 0x20], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00473953  7518                   -jne 0x47396d
    if (!cpu.flags.zf)
    {
        goto L_0x0047396d;
    }
L_0x00473955:
    // 00473955  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00473959  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047395c  41                     -inc ecx
    (cpu.ecx)++;
    // 0047395d  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00473963  894c246c               -mov dword ptr [esp + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 00473967  39d9                   +cmp ecx, ebx
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
    // 00473969  7d8d                   -jge 0x4738f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004738f8;
    }
    // 0047396b  ebce                   -jmp 0x47393b
    goto L_0x0047393b;
L_0x0047396d:
    // 0047396d  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00473973  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00473976  81fb00000200           +cmp ebx, 0x20000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047397c  0f85af000000           -jne 0x473a31
    if (!cpu.flags.zf)
    {
        goto L_0x00473a31;
    }
L_0x00473982:
    // 00473982  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 00473985  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00473988  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047398a  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0047398e  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00473991  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00473994  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473996  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0047399a  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 0047399d  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004739a0  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004739a4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004739a6  8d5c2454               -lea ebx, [esp + 0x54]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004739aa  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004739ae  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004739b2  e8d9b10000             -call 0x47eb90
    cpu.esp -= 4;
    sub_47eb90(app, cpu);
    if (cpu.terminate) return;
    // 004739b7  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004739b9  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004739bd  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004739c1  e8ea5d0200             -call 0x4997b0
    cpu.esp -= 4;
    sub_4997b0(app, cpu);
    if (cpu.terminate) return;
    // 004739c6  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 004739cc  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004739cf  8b159c704d00           -mov edx, dword ptr [0x4d709c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5075100) /* 0x4d709c */);
    // 004739d5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004739d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004739da  740c                   -je 0x4739e8
    if (cpu.flags.zf)
    {
        goto L_0x004739e8;
    }
    // 004739dc  83f805                 +cmp eax, 5
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
    // 004739df  7d07                   -jge 0x4739e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004739e8;
    }
    // 004739e1  8b0485d8135100         -mov eax, dword ptr [eax*4 + 0x5113d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313496) /* 0x5113d8 */ + cpu.eax * 4);
L_0x004739e8:
    // 004739e8  8b5674                 -mov edx, dword ptr [esi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 004739eb  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004739ee  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004739f0  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004739f4  8b5678                 -mov edx, dword ptr [esi + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004739f7  2b570c                 -sub edx, dword ptr [edi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004739fa  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004739fe  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00473a02  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473a03  8b567c                 -mov edx, dword ptr [esi + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00473a06  8b4f10                 -mov ecx, dword ptr [edi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00473a09  8b5c246c               -mov ebx, dword ptr [esp + 0x6c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00473a0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473a0e  29ca                   +sub edx, ecx
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
    // 00473a10  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00473a14  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00473a18  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00473a1c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473a1d  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473a21  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00473a27  e814a70000             -call 0x47e140
    cpu.esp -= 4;
    sub_47e140(app, cpu);
    if (cpu.terminate) return;
    // 00473a2c  e924ffffff             -jmp 0x473955
    goto L_0x00473955;
L_0x00473a31:
    // 00473a31  8b15f42f5400           -mov edx, dword ptr [0x542ff4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517300) /* 0x542ff4 */);
    // 00473a37  39da                   +cmp edx, ebx
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
    // 00473a39  0f8e43ffffff           -jle 0x473982
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473982;
    }
    // 00473a3f  3b5028                 +cmp edx, dword ptr [eax + 0x28]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473a42  0f8d3affffff           -jge 0x473982
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473982;
    }
    // 00473a48  8b15f82f5400           -mov edx, dword ptr [0x542ff8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517304) /* 0x542ff8 */);
    // 00473a4e  3b502c                 +cmp edx, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473a51  0f8e2bffffff           -jle 0x473982
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473982;
    }
    // 00473a57  3b5030                 +cmp edx, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473a5a  0f8cf5feffff           -jl 0x473955
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473955;
    }
    // 00473a60  e91dffffff             -jmp 0x473982
    goto L_0x00473982;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473a70);
    // 00473a70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473a72  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473a75  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00473a77  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00473a79  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 00473a7e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00473a80  e81ba9ffff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 00473a85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473a87  7508                   -jne 0x473a91
    if (!cpu.flags.zf)
    {
        goto L_0x00473a91;
    }
L_0x00473a89:
    // 00473a89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473a8b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473a8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473a90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473a91:
    // 00473a91  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00473a94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473a95  8d5138                 -lea edx, [ecx + 0x38]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 00473a98  8d4144                 -lea eax, [ecx + 0x44]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 00473a9b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00473a9d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00473aa2  e899000000             -call 0x473b40
    cpu.esp -= 4;
    sub_473b40(app, cpu);
    if (cpu.terminate) return;
    // 00473aa7  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 00473aac  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473ab0  e8eba8ffff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 00473ab5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473ab7  74d0                   -je 0x473a89
    if (cpu.flags.zf)
    {
        goto L_0x00473a89;
    }
    // 00473ab9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473abd  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00473ac3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473ac7  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 00473ace  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473ad2  8b1510ed4f00           -mov edx, dword ptr [0x4fed10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5238032) /* 0x4fed10 */);
    // 00473ad8  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00473adb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473adf  c74020ffffff8f         -mov dword ptr [eax + 0x20], 0x8fffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2415919103 /*0x8fffffff*/;
    // 00473ae6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473aea  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 00473af0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473af4  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 00473afa  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473afe  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473b01  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00473b04  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473b08  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00473b0b  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00473b0e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473b11  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473b15  0590000000             -add eax, 0x90
    (cpu.eax) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 00473b1a  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00473b1d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473b20  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473b24  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473b27  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00473b2a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473b2e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473b40);
    // 00473b40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473b41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473b42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473b43  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00473b46  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00473b4a  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00473b4e  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00473b52  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00473b56  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00473b59  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00473b5d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00473b61:
    // 00473b61  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00473b65  4a                     -dec edx
    (cpu.edx)--;
    // 00473b66  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00473b6a  83faff                 +cmp edx, -1
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
    // 00473b6d  7509                   -jne 0x473b78
    if (!cpu.flags.zf)
    {
        goto L_0x00473b78;
    }
    // 00473b6f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00473b72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b75  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00473b78:
    // 00473b78  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00473b7a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00473b7e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00473b82  e8b15e0200             -call 0x499a38
    cpu.esp -= 4;
    sub_499a38(app, cpu);
    if (cpu.terminate) return;
    // 00473b87  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473b8b  81c300200000           -add ebx, 0x2000
    (cpu.ebx) += x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 00473b91  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00473b95  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00473b99  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00473b9c  0330                   -add esi, dword ptr [eax]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 00473b9e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00473ba2  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00473ba5  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00473ba8  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00473bab  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00473baf  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00473bb3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473bb7  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00473bba  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473bbc  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00473bc0  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 00473bc3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473bc7  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00473bca  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473bce  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00473bd4  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00473bd7  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473bdb  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473bdf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473be1  7508                   -jne 0x473beb
    if (!cpu.flags.zf)
    {
        goto L_0x00473beb;
    }
    // 00473be3  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x00473beb:
    // 00473beb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473bef  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00473bf3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473bf7  db442428               -fild dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 00473bfb  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00473bff  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00473c03  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00473c05  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00473c07  c1eb0f                 -shr ebx, 0xf
    cpu.ebx >>= 15 /*0xf*/ % 32;
    // 00473c0a  81e1000080ff           -and ecx, 0xff800000
    cpu.ecx &= x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
    // 00473c10  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00473c16  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 00473c18  8b1c9db4f74e00         -mov ebx, dword ptr [ebx*4 + 0x4ef7b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5175220) /* 0x4ef7b4 */ + cpu.ebx * 4);
    // 00473c1f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473c21  891de4fb4e00           -mov dword ptr [0x4efbe4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5176292) /* 0x4efbe4 */) = cpu.ebx;
    // 00473c27  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 00473c2d  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 00473c33  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 00473c39  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00473c3b  d808                   -fmul dword ptr [eax]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax));
    // 00473c3d  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 00473c43  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00473c45  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00473c47  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473c4b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00473c4d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00473c4f  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00473c52  d905b0304d00           -fld dword ptr [0x4d30b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058736) /* 0x4d30b0 */)));
    // 00473c58  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 00473c5a  d905b4304d00           -fld dword ptr [0x4d30b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058740) /* 0x4d30b4 */)));
    // 00473c60  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 00473c62  d905cc304d00           -fld dword ptr [0x4d30cc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058764) /* 0x4d30cc */)));
    // 00473c68  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 00473c6a  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 00473c6d  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 00473c6f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00473c71  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00473c73  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00473c75  d905bc304d00           -fld dword ptr [0x4d30bc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058748) /* 0x4d30bc */)));
    // 00473c7b  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00473c7d  d905b8304d00           -fld dword ptr [0x4d30b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058744) /* 0x4d30b8 */)));
    // 00473c83  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00473c85  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00473c88  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00473c8b  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00473c8d  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00473c90  8b0dd4fb4e00           -mov ecx, dword ptr [0x4efbd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176276) /* 0x4efbd4 */);
    // 00473c96  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 00473c9b  7558                   -jne 0x473cf5
    if (!cpu.flags.zf)
    {
        goto L_0x00473cf5;
    }
    // 00473c9d  39c8                   +cmp eax, ecx
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
    // 00473c9f  7d54                   -jge 0x473cf5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473cf5;
    }
    // 00473ca1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00473ca4  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 00473ca9  8b0de0fb4e00           -mov ecx, dword ptr [0x4efbe0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176288) /* 0x4efbe0 */);
    // 00473caf  8b15dcfb4e00           -mov edx, dword ptr [0x4efbdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176284) /* 0x4efbdc */);
    // 00473cb5  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 00473cba  750d                   -jne 0x473cc9
    if (!cpu.flags.zf)
    {
        goto L_0x00473cc9;
    }
    // 00473cbc  39c8                   +cmp eax, ecx
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
    // 00473cbe  7c09                   -jl 0x473cc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473cc9;
    }
    // 00473cc0  39d0                   +cmp eax, edx
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
    // 00473cc2  7e09                   -jle 0x473ccd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473ccd;
    }
    // 00473cc4  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 00473cc7  eb04                   -jmp 0x473ccd
    goto L_0x00473ccd;
L_0x00473cc9:
    // 00473cc9  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473ccc  90                     -nop 
    ;
L_0x00473ccd:
    // 00473ccd  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00473ccf  90                     -nop 
    ;
    // 00473cd0  8b0dd8fb4e00           -mov ecx, dword ptr [0x4efbd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176280) /* 0x4efbd8 */);
    // 00473cd6  8b15e8fb4e00           -mov edx, dword ptr [0x4efbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176296) /* 0x4efbe8 */);
    // 00473cdc  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 00473ce1  750d                   -jne 0x473cf0
    if (!cpu.flags.zf)
    {
        goto L_0x00473cf0;
    }
    // 00473ce3  39c8                   +cmp eax, ecx
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
    // 00473ce5  7c09                   -jl 0x473cf0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473cf0;
    }
    // 00473ce7  39d0                   +cmp eax, edx
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
    // 00473ce9  7e0f                   -jle 0x473cfa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473cfa;
    }
    // 00473ceb  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 00473cee  eb0a                   -jmp 0x473cfa
    goto L_0x00473cfa;
L_0x00473cf0:
    // 00473cf0  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 00473cf3  eb05                   -jmp 0x473cfa
    goto L_0x00473cfa;
L_0x00473cf5:
    // 00473cf5  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00473cfa:
    // 00473cfa  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 00473cfc  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00473d01  7c24                   -jl 0x473d27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473d27;
    }
    // 00473d03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00473d05:
    // 00473d05  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473d09  6689450e               -mov word ptr [ebp + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00473d0d  83c530                 -add ebp, 0x30
    (cpu.ebp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00473d10  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00473d14  83c730                 -add edi, 0x30
    (cpu.edi) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00473d17  83c00c                 +add eax, 0xc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00473d1a  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00473d1e  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00473d22  e93afeffff             -jmp 0x473b61
    goto L_0x00473b61;
L_0x00473d27:
    // 00473d27  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473d2c  ebd7                   -jmp 0x473d05
    goto L_0x00473d05;
}

/* align: skip 0x00 0x00 */
void Application::sub_473d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473d30);
    // 00473d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473d31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473d32  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473d35  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00473d37  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00473d3c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00473d3e  e85da6ffff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 00473d43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473d45  7506                   -jne 0x473d4d
    if (!cpu.flags.zf)
    {
        goto L_0x00473d4d;
    }
    // 00473d47  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473d4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473d4d:
    // 00473d4d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473d50  c740041a000000         -mov dword ptr [eax + 4], 0x1a
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 26 /*0x1a*/;
    // 00473d57  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473d5a  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00473d60  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473d63  885808                 -mov byte ptr [eax + 8], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 00473d66  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00473d69  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473d6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_473d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473d70);
    // 00473d70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473d71  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473d73  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00473d78  e893000000             -call 0x473e10
    cpu.esp -= 4;
    sub_473e10(app, cpu);
    if (cpu.terminate) return;
    // 00473d7d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00473d80  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 00473d86  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00473d8c  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 00473d92  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00473d95  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 00473d99  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 00473d9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_473da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473da0);
    // 00473da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473da1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473da3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00473da8  e863000000             -call 0x473e10
    cpu.esp -= 4;
    sub_473e10(app, cpu);
    if (cpu.terminate) return;
    // 00473dad  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00473db0  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 00473db6  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00473dbc  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 00473dc2  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00473dc5  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 00473dc9  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 00473dcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_473dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473dd0);
    // 00473dd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473dd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473dd2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473dd4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00473dd6  8b808c000000           -mov eax, dword ptr [eax + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 00473ddc  89948190000000         -mov dword ptr [ecx + eax*4 + 0x90], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */ + cpu.eax * 4) = cpu.edx;
    // 00473de3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00473de5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473de7  e84489ffff             -call 0x46c730
    cpu.esp -= 4;
    sub_46c730(app, cpu);
    if (cpu.terminate) return;
    // 00473dec  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00473def  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00473df2  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00473df5  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00473df8  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00473dfb  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00473dfe  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00473e00  884620                 -mov byte ptr [esi + 0x20], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.al;
    // 00473e03  ff818c000000           -inc dword ptr [ecx + 0x8c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */))++;
    // 00473e09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473e10);
    // 00473e10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473e13  b8b8c14c00             -mov eax, 0x4cc1b8
    cpu.eax = 5030328 /*0x4cc1b8*/;
    // 00473e18  e813000000             -call 0x473e30
    cpu.esp -= 4;
    sub_473e30(app, cpu);
    if (cpu.terminate) return;
    // 00473e1d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00473e24  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00473e26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473e30);
    // 00473e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473e31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e32  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 00473e37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473e39  e8f2000000             -call 0x473f30
    cpu.esp -= 4;
    sub_473f30(app, cpu);
    if (cpu.terminate) return;
    // 00473e3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473e40  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00473e43  c740e400000000         -mov dword ptr [eax - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00473e4a  c740e800000000         -mov dword ptr [eax - 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-24) /* -0x18 */) = 0 /*0x0*/;
    // 00473e51  c7406c00000000         -mov dword ptr [eax + 0x6c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 0 /*0x0*/;
    // 00473e58  c7809c00000000000000   -mov dword ptr [eax + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 00473e62  c780a000000000000000   -mov dword ptr [eax + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 00473e6c  c780a400000000000000   -mov dword ptr [eax + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 00473e76  e89593feff             -call 0x45d210
    cpu.esp -= 4;
    sub_45d210(app, cpu);
    if (cpu.terminate) return;
    // 00473e7b  8d4250                 -lea eax, [edx + 0x50]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 00473e7e  e88d93feff             -call 0x45d210
    cpu.esp -= 4;
    sub_45d210(app, cpu);
    if (cpu.terminate) return;
    // 00473e83  c7424400000000         -mov dword ptr [edx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00473e8a  c7424800000000         -mov dword ptr [edx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00473e91  c7424c00000000         -mov dword ptr [edx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 00473e98  c7828000000000000000   -mov dword ptr [edx + 0x80], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 00473ea2  c7828400000000000000   -mov dword ptr [edx + 0x84], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 00473eac  c7828800000000000000   -mov dword ptr [edx + 0x88], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 00473eb6  c7427400000000         -mov dword ptr [edx + 0x74], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 00473ebd  c7427800000000         -mov dword ptr [edx + 0x78], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00473ec4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473ec6  c7427c00000000         -mov dword ptr [edx + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 00473ecd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ece  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ecf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_473ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473ed0);
    // 00473ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473ed1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473ed2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473ed3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473ed4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473ed5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473ed6  8b15ac744d00           -mov edx, dword ptr [0x4d74ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076140) /* 0x4d74ac */);
    // 00473edc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473ede  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473ee0  7e22                   -jle 0x473f04
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473f04;
    }
    // 00473ee2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00473ee4:
    // 00473ee4  8bbab42f5400           -mov edi, dword ptr [edx + 0x542fb4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5517236) /* 0x542fb4 */);
    // 00473eea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00473eec  752b                   -jne 0x473f19
    if (!cpu.flags.zf)
    {
        goto L_0x00473f19;
    }
L_0x00473eee:
    // 00473eee  8b35ac744d00           -mov esi, dword ptr [0x4d74ac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076140) /* 0x4d74ac */);
    // 00473ef4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473ef7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473ef9  41                     -inc ecx
    (cpu.ecx)++;
    // 00473efa  899ab02f5400           -mov dword ptr [edx + 0x542fb0], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5517232) /* 0x542fb0 */) = cpu.ebx;
    // 00473f00  39f1                   +cmp ecx, esi
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
    // 00473f02  7ce0                   -jl 0x473ee4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473ee4;
    }
L_0x00473f04:
    // 00473f04  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00473f06  892dac744d00           -mov dword ptr [0x4d74ac], ebp
    app->getMemory<x86::reg32>(x86::reg32(5076140) /* 0x4d74ac */) = cpu.ebp;
    // 00473f0c  892db0744d00           -mov dword ptr [0x4d74b0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5076144) /* 0x4d74b0 */) = cpu.ebp;
    // 00473f12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473f19:
    // 00473f19  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00473f1b  e84cee0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00473f20  ebcc                   -jmp 0x473eee
    goto L_0x00473eee;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473f30);
    // 00473f30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473f31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473f32  8b0db0744d00           -mov ecx, dword ptr [0x4d74b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076144) /* 0x4d74b0 */);
    // 00473f38  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473f3a  7442                   -je 0x473f7e
    if (cpu.flags.zf)
    {
        goto L_0x00473f7e;
    }
    // 00473f3c  a1ac744d00             -mov eax, dword ptr [0x4d74ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076140) /* 0x4d74ac */);
    // 00473f41  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00473f48  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00473f4f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473f51  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473f54  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00473f56  8b93b02f5400           -mov edx, dword ptr [ebx + 0x542fb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5517232) /* 0x542fb0 */);
    // 00473f5c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473f5f  41                     -inc ecx
    (cpu.ecx)++;
    // 00473f60  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00473f63  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00473f68  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00473f6a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473f6c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473f6f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473f71  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00473f73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00473f75  890db0744d00           -mov dword ptr [0x4d74b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076144) /* 0x4d74b0 */) = cpu.ecx;
    // 00473f7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473f7e:
    // 00473f7e  ba8cc14c00             -mov edx, 0x4cc18c
    cpu.edx = 5030284 /*0x4cc18c*/;
    // 00473f83  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00473f88  b8b0c14c00             -mov eax, 0x4cc1b0
    cpu.eax = 5030320 /*0x4cc1b0*/;
    // 00473f8d  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 00473f93  891df88f4d00           -mov dword ptr [0x4d8ff8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ebx;
    // 00473f99  bad0070000             -mov edx, 0x7d0
    cpu.edx = 2000 /*0x7d0*/;
    // 00473f9e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473fa0  e863e90000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00473fa5  8b15ac744d00           -mov edx, dword ptr [0x4d74ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076140) /* 0x4d74ac */);
    // 00473fab  8b0db0744d00           -mov ecx, dword ptr [0x4d74b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076144) /* 0x4d74b0 */);
    // 00473fb1  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00473fb4  41                     -inc ecx
    (cpu.ecx)++;
    // 00473fb5  890495b42f5400         -mov dword ptr [edx*4 + 0x542fb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5517236) /* 0x542fb4 */ + cpu.edx * 4) = cpu.eax;
    // 00473fbc  8935ac744d00           -mov dword ptr [0x4d74ac], esi
    app->getMemory<x86::reg32>(x86::reg32(5076140) /* 0x4d74ac */) = cpu.esi;
    // 00473fc2  8b04b5b02f5400         -mov eax, dword ptr [esi*4 + 0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */ + cpu.esi * 4);
    // 00473fc9  890db0744d00           -mov dword ptr [0x4d74b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076144) /* 0x4d74b0 */) = cpu.ecx;
    // 00473fcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473fd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473fe0);
    // 00473fe0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00473ff0);
    // 00473ff0  e90b000000             -jmp 0x474000
    return sub_474000(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474000);
    // 00474000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474002  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474004  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474005  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0047400a  8b1518ed5300           -mov edx, dword ptr [0x53ed18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00474010  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474012  8915fc365400           -mov dword ptr [0x5436fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5519100) /* 0x5436fc */) = cpu.edx;
    // 00474018  891500375400           -mov dword ptr [0x543700], edx
    app->getMemory<x86::reg32>(x86::reg32(5519104) /* 0x543700 */) = cpu.edx;
    // 0047401e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00474020:
    // 00474020  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00474022  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00474024  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
L_0x00474027:
    // 00474027  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047402a  8990f8335400           -mov dword ptr [eax + 0x5433f8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5518328) /* 0x5433f8 */) = cpu.edx;
    // 00474030  89b8f8355400           -mov dword ptr [eax + 0x5435f8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5518840) /* 0x5435f8 */) = cpu.edi;
    // 00474036  8990f8345400           -mov dword ptr [eax + 0x5434f8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5518584) /* 0x5434f8 */) = cpu.edx;
    // 0047403c  39c8                   +cmp eax, ecx
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
    // 0047403e  75e7                   -jne 0x474027
    if (!cpu.flags.zf)
    {
        goto L_0x00474027;
    }
    // 00474040  43                     -inc ebx
    (cpu.ebx)++;
    // 00474041  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474044  83fb10                 +cmp ebx, 0x10
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
    // 00474047  7cd7                   -jl 0x474020
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474020;
    }
    // 00474049  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047404a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047404b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047404c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047404d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047404e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_474050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474050);
    // 00474050  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474051  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474052  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474053  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474056  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00474058  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047405a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047405c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047405e  83e70f                 -and edi, 0xf
    cpu.edi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00474061  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474063  751d                   -jne 0x474082
    if (!cpu.flags.zf)
    {
        goto L_0x00474082;
    }
    // 00474065  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00474067  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 0047406e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00474071  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474073  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00474078  2b81fc335400           -sub eax, dword ptr [ecx + 0x5433fc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5518332) /* 0x5433fc */)));
    // 0047407e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474080  7e50                   -jle 0x4740d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004740d2;
    }
L_0x00474082:
    // 00474082  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00474084  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0047408b  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0047408e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474090  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00474095  8981fc335400           -mov dword ptr [ecx + 0x5433fc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5518332) /* 0x5433fc */) = cpu.eax;
    // 0047409b  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004740a2  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004740a4  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004740a8  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004740af  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004740b6  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004740b8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004740bb  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004740be  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004740c1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004740c5  83bbfc35540000         +cmp dword ptr [ebx + 0x5435fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5518844) /* 0x5435fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004740cc  7524                   -jne 0x4740f2
    if (!cpu.flags.zf)
    {
        goto L_0x004740f2;
    }
    // 004740ce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004740d0  7407                   -je 0x4740d9
    if (cpu.flags.zf)
    {
        goto L_0x004740d9;
    }
L_0x004740d2:
    // 004740d2  83c40c                 +add esp, 0xc
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
    // 004740d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004740d9:
    // 004740d9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004740dc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004740e1  8dbffc305400           -lea edi, [edi + 0x5430fc]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5517564) /* 0x5430fc */);
    // 004740e7  8993fc355400           -mov dword ptr [ebx + 0x5435fc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5518844) /* 0x5435fc */) = cpu.edx;
    // 004740ed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740ee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740ef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740f0  ebe0                   -jmp 0x4740d2
    goto L_0x004740d2;
L_0x004740f2:
    // 004740f2  05fc305400             -add eax, 0x5430fc
    (cpu.eax) += x86::reg32(x86::sreg32(5517564 /*0x5430fc*/));
    // 004740f7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004740f9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004740fd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004740ff  7435                   -je 0x474136
    if (cpu.flags.zf)
    {
        goto L_0x00474136;
    }
    // 00474101  bb33330000             -mov ebx, 0x3333
    cpu.ebx = 13107 /*0x3333*/;
    // 00474106  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00474108  e863b2ffff             -call 0x46f370
    cpu.esp -= 4;
    sub_46f370(app, cpu);
    if (cpu.terminate) return;
    // 0047410d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047410f  7512                   -jne 0x474123
    if (!cpu.flags.zf)
    {
        goto L_0x00474123;
    }
    // 00474111  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474112  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474116  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00474118  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047411a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047411c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047411e  e85d000000             -call 0x474180
    cpu.esp -= 4;
    sub_474180(app, cpu);
    if (cpu.terminate) return;
L_0x00474123:
    // 00474123  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00474126  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474128  8984affc355400         -mov dword ptr [edi + ebp*4 + 0x5435fc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5518844) /* 0x5435fc */ + cpu.ebp * 4) = cpu.eax;
    // 0047412f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474132  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474133  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474134  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474135  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474136:
    // 00474136  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0047413b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047413d  e82eb2ffff             -call 0x46f370
    cpu.esp -= 4;
    sub_46f370(app, cpu);
    if (cpu.terminate) return;
    // 00474142  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474144  758c                   -jne 0x4740d2
    if (!cpu.flags.zf)
    {
        goto L_0x004740d2;
    }
    // 00474146  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474147  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047414b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047414d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047414f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474151  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00474153  e828000000             -call 0x474180
    cpu.esp -= 4;
    sub_474180(app, cpu);
    if (cpu.terminate) return;
    // 00474158  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047415c  c780fc35540001000000   -mov dword ptr [eax + 0x5435fc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5518844) /* 0x5435fc */) = 1 /*0x1*/;
    // 00474166  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00474169  8dbffc305400           -lea edi, [edi + 0x5430fc]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5517564) /* 0x5430fc */);
    // 0047416f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474170  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474171  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474172  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474175  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474176  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474177  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474180);
    // 00474180  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474181  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474182  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474183  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00474186  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00474188  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047418c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047418e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00474190  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00474194  bb00000e00             -mov ebx, 0xe0000
    cpu.ebx = 917504 /*0xe0000*/;
    // 00474199  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047419b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047419d  e8ceb1ffff             -call 0x46f370
    cpu.esp -= 4;
    sub_46f370(app, cpu);
    if (cpu.terminate) return;
    // 004741a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004741a4  0f857e000000           -jne 0x474228
    if (!cpu.flags.zf)
    {
        goto L_0x00474228;
    }
    // 004741aa  83f903                 +cmp ecx, 3
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
    // 004741ad  7d5c                   -jge 0x47420b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047420b;
    }
    // 004741af  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004741b1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004741b3  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004741b5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004741b8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004741bb  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004741bf  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004741c1  41                     -inc ecx
    (cpu.ecx)++;
    // 004741c2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004741c4  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004741c6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004741ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004741cb  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004741ce  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004741d2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004741d4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004741d6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004741d8  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004741dc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004741e0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004741e2  e899ffffff             -call 0x474180
    cpu.esp -= 4;
    sub_474180(app, cpu);
    if (cpu.terminate) return;
    // 004741e7  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004741eb  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004741ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004741f0  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004741f4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004741f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004741f7  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004741fb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004741fd  e87effffff             -call 0x474180
    cpu.esp -= 4;
    sub_474180(app, cpu);
    if (cpu.terminate) return;
    // 00474202  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00474205  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474206  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474207  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474208  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0047420b:
    // 0047420b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047420f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00474213  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00474215  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474216  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00474218  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047421a  e891990000             -call 0x47dbb0
    cpu.esp -= 4;
    sub_47dbb0(app, cpu);
    if (cpu.terminate) return;
    // 0047421f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00474222  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474223  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474224  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474225  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00474228:
    // 00474228  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047422c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047422e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00474230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474231  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00474233  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474237  e874990000             -call 0x47dbb0
    cpu.esp -= 4;
    sub_47dbb0(app, cpu);
    if (cpu.terminate) return;
    // 0047423c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047423f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474240  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474241  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474242  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474250);
    // 00474250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474252  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00474254  8b15fc365400           -mov edx, dword ptr [0x5436fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5519100) /* 0x5436fc */);
    // 0047425a  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047425f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474261  83f804                 +cmp eax, 4
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
    // 00474264  7f03                   -jg 0x474269
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00474269;
    }
    // 00474266  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474267  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474268  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474269:
    // 00474269  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047426a  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047426f  a3fc365400             -mov dword ptr [0x5436fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5519100) /* 0x5436fc */) = cpu.eax;
    // 00474274  e86b220100             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 00474279  a807                   +test al, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 7 /*0x7*/));
    // 0047427b  7415                   -je 0x474292
    if (cpu.flags.zf)
    {
        goto L_0x00474292;
    }
    // 0047427d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00474282  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474284  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474286  e899e8ffff             -call 0x472b24
    cpu.esp -= 4;
    sub_472b24(app, cpu);
    if (cpu.terminate) return;
    // 0047428b  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
L_0x00474292:
    // 00474292  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00474297  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474299  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047429b  e884e8ffff             -call 0x472b24
    cpu.esp -= 4;
    sub_472b24(app, cpu);
    if (cpu.terminate) return;
    // 004742a0  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
    // 004742a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4742b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004742b0);
    // 004742b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004742b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004742b2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004742b4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004742b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004742b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004742ba  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004742be  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004742c1  83f908                 +cmp ecx, 8
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
    // 004742c4  751e                   -jne 0x4742e4
    if (!cpu.flags.zf)
    {
        goto L_0x004742e4;
    }
L_0x004742c6:
    // 004742c6  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004742c9  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004742cc  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004742ce  8b3518ed5300           -mov esi, dword ptr [0x53ed18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 004742d4  2bb7fc345400           -sub esi, dword ptr [edi + 0x5434fc]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5518588) /* 0x5434fc */)));
    // 004742da  83fe02                 +cmp esi, 2
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
    // 004742dd  7f28                   -jg 0x474307
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00474307;
    }
L_0x004742df:
    // 004742df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742e1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004742e4:
    // 004742e4  83f907                 +cmp ecx, 7
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
    // 004742e7  74dd                   -je 0x4742c6
    if (cpu.flags.zf)
    {
        goto L_0x004742c6;
    }
    // 004742e9  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004742ec  74d8                   -je 0x4742c6
    if (cpu.flags.zf)
    {
        goto L_0x004742c6;
    }
    // 004742ee  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004742f1  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004742f4  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004742f6  8b3518ed5300           -mov esi, dword ptr [0x53ed18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 004742fc  2bb7fc345400           -sub esi, dword ptr [edi + 0x5434fc]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5518588) /* 0x5434fc */)));
    // 00474302  83fe05                 +cmp esi, 5
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
    // 00474305  7ed8                   -jle 0x4742df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004742df;
    }
L_0x00474307:
    // 00474307  8b3518ed5300           -mov esi, dword ptr [0x53ed18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0047430d  89b7fc345400           -mov dword ptr [edi + 0x5434fc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5518588) /* 0x5434fc */) = cpu.esi;
    // 00474313  e80ce8ffff             -call 0x472b24
    cpu.esp -= 4;
    sub_472b24(app, cpu);
    if (cpu.terminate) return;
    // 00474318  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474319  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047431a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_474320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474320);
    // 00474320  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474321  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00474323  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474326  7515                   -jne 0x47433d
    if (!cpu.flags.zf)
    {
        goto L_0x0047433d;
    }
    // 00474328  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047432b  e8981a0100             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 00474330  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474332  7402                   -je 0x474336
    if (cpu.flags.zf)
    {
        goto L_0x00474336;
    }
    // 00474334  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474335  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474336:
    // 00474336  e8aa190200             -call 0x495ce5
    cpu.esp -= 4;
    sub_495ce5(app, cpu);
    if (cpu.terminate) return;
    // 0047433b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047433c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047433d:
    // 0047433d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047433e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047433f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474340  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00474342  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00474344  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00474347  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474348  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047434a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047434d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047434f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00474351  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00474354  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00474356  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474357  015d08                 -add dword ptr [ebp + 8], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047435a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047435b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047435c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047435d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047435e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_474360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474360);
    // 00474360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474362  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00474365  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474367  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047436a  7414                   -je 0x474380
    if (cpu.flags.zf)
    {
        goto L_0x00474380;
    }
    // 0047436c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047436f  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00474371  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00474374  ff4208                 -inc dword ptr [edx + 8]
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */))++;
L_0x00474377:
    // 00474377  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0047437a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047437d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047437e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047437f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474380:
    // 00474380  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00474385  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00474388  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047438a  e8391a0100             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 0047438f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474391  75e4                   -jne 0x474377
    if (!cpu.flags.zf)
    {
        goto L_0x00474377;
    }
    // 00474393  e84d190200             -call 0x495ce5
    cpu.esp -= 4;
    sub_495ce5(app, cpu);
    if (cpu.terminate) return;
    // 00474398  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0047439b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047439e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047439f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4743b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004743b0);
    // 004743b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004743b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004743b2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004743b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004743b7  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004743ba  7415                   -je 0x4743d1
    if (cpu.flags.zf)
    {
        goto L_0x004743d1;
    }
    // 004743bc  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004743bf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004743c1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004743c4  83420804               -add dword ptr [edx + 8], 4
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004743c8:
    // 004743c8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004743cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004743ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004743d1:
    // 004743d1  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004743d6  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004743d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004743db  e8e8190100             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 004743e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004743e2  75e4                   -jne 0x4743c8
    if (!cpu.flags.zf)
    {
        goto L_0x004743c8;
    }
    // 004743e4  e8fc180200             -call 0x495ce5
    cpu.esp -= 4;
    sub_495ce5(app, cpu);
    if (cpu.terminate) return;
    // 004743e9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004743ec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004743ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474400);
    // 00474400  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474401  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474403  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474405  741c                   -je 0x474423
    if (cpu.flags.zf)
    {
        goto L_0x00474423;
    }
    // 00474407  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474408  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047440b  750e                   -jne 0x47441b
    if (!cpu.flags.zf)
    {
        goto L_0x0047441b;
    }
    // 0047440d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00474410  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474412  7407                   -je 0x47441b
    if (cpu.flags.zf)
    {
        goto L_0x0047441b;
    }
    // 00474414  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474416  e8a5190100             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
L_0x0047441b:
    // 0047441b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047441d  e84ae90000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00474422  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00474423:
    // 00474423  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474424  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474430);
    // 00474430  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474431  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474432  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474433  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474434  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474437  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00474439  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047443b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047443f  bac8c14c00             -mov edx, 0x4cc1c8
    cpu.edx = 5030344 /*0x4cc1c8*/;
    // 00474444  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00474449  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0047444e  b8e8c14c00             -mov eax, 0x4cc1e8
    cpu.eax = 5030376 /*0x4cc1e8*/;
    // 00474453  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 00474459  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0047445f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00474464  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00474469  e8c6e40000             -call 0x482934
    cpu.esp -= 4;
    sub_482934(app, cpu);
    if (cpu.terminate) return;
    // 0047446e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00474470  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474472  7533                   -jne 0x4744a7
    if (!cpu.flags.zf)
    {
        goto L_0x004744a7;
    }
    // 00474474  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00474479  7422                   -je 0x47449d
    if (cpu.flags.zf)
    {
        goto L_0x0047449d;
    }
    // 0047447b  bdc8c14c00             -mov ebp, 0x4cc1c8
    cpu.ebp = 5030344 /*0x4cc1c8*/;
    // 00474480  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00474485  68f4c14c00             -push 0x4cc1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030388 /*0x4cc1f4*/;
    cpu.esp -= 4;
    // 0047448a  892df48f4d00           -mov dword ptr [0x4d8ff4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebp;
    // 00474490  a3f88f4d00             -mov dword ptr [0x4d8ff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.eax;
    // 00474495  e8c6e00000             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 0047449a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047449d:
    // 0047449d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047449f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004744a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004744a7:
    // 004744a7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004744a9  7543                   -jne 0x4744ee
    if (!cpu.flags.zf)
    {
        goto L_0x004744ee;
    }
    // 004744ab  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004744ad  753f                   -jne 0x4744ee
    if (!cpu.flags.zf)
    {
        goto L_0x004744ee;
    }
L_0x004744af:
    // 004744af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004744b1  7407                   -je 0x4744ba
    if (cpu.flags.zf)
    {
        goto L_0x004744ba;
    }
    // 004744b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004744b5  e8b2e80000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x004744ba:
    // 004744ba  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004744bf  74dc                   -je 0x47449d
    if (cpu.flags.zf)
    {
        goto L_0x0047449d;
    }
    // 004744c1  bbc8c14c00             -mov ebx, 0x4cc1c8
    cpu.ebx = 5030344 /*0x4cc1c8*/;
    // 004744c6  be18000000             -mov esi, 0x18
    cpu.esi = 24 /*0x18*/;
    // 004744cb  6814c24c00             -push 0x4cc214
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030420 /*0x4cc214*/;
    cpu.esp -= 4;
    // 004744d0  891df48f4d00           -mov dword ptr [0x4d8ff4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebx;
    // 004744d6  8935f88f4d00           -mov dword ptr [0x4d8ff8], esi
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.esi;
    // 004744dc  e87fe00000             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 004744e1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004744e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004744e6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004744e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004744ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004744ee:
    // 004744ee  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004744f0  7404                   -je 0x4744f6
    if (cpu.flags.zf)
    {
        goto L_0x004744f6;
    }
    // 004744f2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004744f4  75b9                   -jne 0x4744af
    if (!cpu.flags.zf)
    {
        goto L_0x004744af;
    }
L_0x004744f6:
    // 004744f6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004744f8  7417                   -je 0x474511
    if (cpu.flags.zf)
    {
        goto L_0x00474511;
    }
    // 004744fa  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00474501  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 00474504  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x00474507:
    // 00474507  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00474509  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047450c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047450d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047450e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047450f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474510  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474511:
    // 00474511  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474515  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474519  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047451b  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047451e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00474522  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00474525  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474526  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00474529  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047452b  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047452e  e8a5150100             -call 0x485ad8
    cpu.esp -= 4;
    sub_485ad8(app, cpu);
    if (cpu.terminate) return;
    // 00474533  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 00474537  75ce                   -jne 0x474507
    if (!cpu.flags.zf)
    {
        goto L_0x00474507;
    }
    // 00474539  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047453b  e82ce80000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00474540  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474542  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474545  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474546  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474547  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474548  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474549  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 09000000000000000b000000020000000d000000040000000e000000050000000c000000030000000f0000000600000010000000070000001100000008000000 */
void Application::sub_474590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474590);
    // 00474590  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4745a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004745a0);
    // 004745a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004745a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004745a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004745a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004745a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004745a5  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004745ab  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004745ad  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004745af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004745b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004745b2:
    // 004745b2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004745b4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004745b6  3c00                   +cmp al, 0
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
    // 004745b8  7410                   -je 0x4745ca
    if (cpu.flags.zf)
    {
        goto L_0x004745ca;
    }
    // 004745ba  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004745bd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004745c0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004745c3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004745c6  3c00                   +cmp al, 0
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
    // 004745c8  75e8                   -jne 0x4745b2
    if (!cpu.flags.zf)
    {
        goto L_0x004745b2;
    }
L_0x004745ca:
    // 004745ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745cb  befcc34c00             -mov esi, 0x4cc3fc
    cpu.esi = 5030908 /*0x4cc3fc*/;
    // 004745d0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004745d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004745d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004745d5  2bc9                   +sub ecx, ecx
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
    // 004745d7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004745d8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004745da  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004745dc  4f                     -dec edi
    (cpu.edi)--;
L_0x004745dd:
    // 004745dd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004745df  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004745e1  3c00                   +cmp al, 0
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
    // 004745e3  7410                   -je 0x4745f5
    if (cpu.flags.zf)
    {
        goto L_0x004745f5;
    }
    // 004745e5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004745e8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004745eb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004745ee  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004745f1  3c00                   +cmp al, 0
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
    // 004745f3  75e8                   -jne 0x4745dd
    if (!cpu.flags.zf)
    {
        goto L_0x004745dd;
    }
L_0x004745f5:
    // 004745f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745f6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004745f8  e8c30d0100             -call 0x4853c0
    cpu.esp -= 4;
    sub_4853c0(app, cpu);
    if (cpu.terminate) return;
    // 004745fd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004745ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00474601  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474603  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047460a  e8c5f10000             -call 0x4837d4
    cpu.esp -= 4;
    sub_4837d4(app, cpu);
    if (cpu.terminate) return;
    // 0047460f  83f807                 +cmp eax, 7
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
    // 00474612  742f                   -je 0x474643
    if (cpu.flags.zf)
    {
        goto L_0x00474643;
    }
L_0x00474614:
    // 00474614  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0047461b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047461d  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00474624  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047462b  8999e8915000           -mov dword ptr [ecx + 0x5091e8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5280232) /* 0x5091e8 */) = cpu.ebx;
    // 00474631  8981e0915000           -mov dword ptr [ecx + 0x5091e0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5280224) /* 0x5091e0 */) = cpu.eax;
    // 00474637  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047463d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047463e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047463f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474640  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474641  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474642  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474643:
    // 00474643  ba0cc34c00             -mov edx, 0x4cc30c
    cpu.edx = 5030668 /*0x4cc30c*/;
    // 00474648  bb10030000             -mov ebx, 0x310
    cpu.ebx = 784 /*0x310*/;
    // 0047464d  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00474654  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 0047465a  891df88f4d00           -mov dword ptr [0x4d8ff8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ebx;
    // 00474660  e86bef0000             -call 0x4835d0
    cpu.esp -= 4;
    sub_4835d0(app, cpu);
    if (cpu.terminate) return;
    // 00474665  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474667  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00474669  b804c44c00             -mov eax, 0x4cc404
    cpu.eax = 5030916 /*0x4cc404*/;
    // 0047466e  e895e20000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00474673  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047467a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047467c  e807f00000             -call 0x483688
    cpu.esp -= 4;
    sub_483688(app, cpu);
    if (cpu.terminate) return;
    // 00474681  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474683  e8e4e60000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00474688  eb8a                   -jmp 0x474614
    goto L_0x00474614;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474690);
    // 00474690  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474691  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00474696  e8d9010100             -call 0x484874
    cpu.esp -= 4;
    sub_484874(app, cpu);
    if (cpu.terminate) return;
    // 0047469b  8b15e8915000           -mov edx, dword ptr [0x5091e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5280232) /* 0x5091e8 */);
    // 004746a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004746a3  7502                   -jne 0x4746a7
    if (!cpu.flags.zf)
    {
        goto L_0x004746a7;
    }
    // 004746a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004746a7:
    // 004746a7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004746a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004746aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004746ac  e8bbe60000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004746b1  890de8915000           -mov dword ptr [0x5091e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5280232) /* 0x5091e8 */) = cpu.ecx;
    // 004746b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4746c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004746c0);
    // 004746c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004746c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004746c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004746c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004746c5:
    // 004746c5  8b8ae8915000           -mov ecx, dword ptr [edx + 0x5091e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5280232) /* 0x5091e8 */);
    // 004746cb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004746cd  750c                   -jne 0x4746db
    if (!cpu.flags.zf)
    {
        goto L_0x004746db;
    }
    // 004746cf  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004746d2  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004746d5  75ee                   -jne 0x4746c5
    if (!cpu.flags.zf)
    {
        goto L_0x004746c5;
    }
    // 004746d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004746db:
    // 004746db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004746dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004746df  e888e60000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004746e4  899ae8915000           -mov dword ptr [edx + 0x5091e8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5280232) /* 0x5091e8 */) = cpu.ebx;
    // 004746ea  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004746ed  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004746f0  75d3                   -jne 0x4746c5
    if (!cpu.flags.zf)
    {
        goto L_0x004746c5;
    }
    // 004746f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004746f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474700);
    // 00474700  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474707  7509                   -jne 0x474712
    if (!cpu.flags.zf)
    {
        goto L_0x00474712;
    }
    // 00474709  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474710  7501                   -jne 0x474713
    if (!cpu.flags.zf)
    {
        goto L_0x00474713;
    }
L_0x00474712:
    // 00474712  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474713:
    // 00474713  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474714  e8b7c10100             -call 0x4908d0
    cpu.esp -= 4;
    sub_4908d0(app, cpu);
    if (cpu.terminate) return;
    // 00474719  a1c4744d00             -mov eax, dword ptr [0x4d74c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */);
    // 0047471e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474720  e8c7a10100             -call 0x48e8ec
    cpu.esp -= 4;
    sub_48e8ec(app, cpu);
    if (cpu.terminate) return;
    // 00474725  890dc4744d00           -mov dword ptr [0x4d74c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */) = cpu.ecx;
    // 0047472b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047472c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_474730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474730);
    // 00474730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474731  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474738  7509                   -jne 0x474743
    if (!cpu.flags.zf)
    {
        goto L_0x00474743;
    }
    // 0047473a  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474741  7502                   -jne 0x474745
    if (!cpu.flags.zf)
    {
        goto L_0x00474745;
    }
L_0x00474743:
    // 00474743  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474744  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474745:
    // 00474745  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474747  e824350100             -call 0x487c70
    cpu.esp -= 4;
    sub_487c70(app, cpu);
    if (cpu.terminate) return;
    // 0047474c  e81bc30100             -call 0x490a6c
    cpu.esp -= 4;
    sub_490a6c(app, cpu);
    if (cpu.terminate) return;
    // 00474751  803dc0744d0000         +cmp byte ptr [0x4d74c0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076160) /* 0x4d74c0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474758  7422                   -je 0x47477c
    if (cpu.flags.zf)
    {
        goto L_0x0047477c;
    }
    // 0047475a  e871c10100             -call 0x4908d0
    cpu.esp -= 4;
    sub_4908d0(app, cpu);
    if (cpu.terminate) return;
L_0x0047475f:
    // 0047475f  8b0d10375400           -mov ecx, dword ptr [0x543710]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5519120) /* 0x543710 */);
    // 00474765  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474767  74da                   -je 0x474743
    if (cpu.flags.zf)
    {
        goto L_0x00474743;
    }
    // 00474769  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047476a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047476c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047476e  e8f9e50000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00474773  891d10375400           -mov dword ptr [0x543710], ebx
    app->getMemory<x86::reg32>(x86::reg32(5519120) /* 0x543710 */) = cpu.ebx;
    // 00474779  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047477a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047477b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047477c:
    // 0047477c  e8db470200             -call 0x498f5c
    cpu.esp -= 4;
    sub_498f5c(app, cpu);
    if (cpu.terminate) return;
    // 00474781  ebdc                   -jmp 0x47475f
    goto L_0x0047475f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474790);
    // 00474790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474791  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474792  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474799  7509                   -jne 0x4747a4
    if (!cpu.flags.zf)
    {
        goto L_0x004747a4;
    }
    // 0047479b  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004747a2  7503                   -jne 0x4747a7
    if (!cpu.flags.zf)
    {
        goto L_0x004747a7;
    }
L_0x004747a4:
    // 004747a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004747a7:
    // 004747a7  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004747ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004747ae  e85d010100             -call 0x484910
    cpu.esp -= 4;
    sub_484910(app, cpu);
    if (cpu.terminate) return;
L_0x004747b3:
    // 004747b3  e8a8660200             -call 0x49ae60
    cpu.esp -= 4;
    sub_49ae60(app, cpu);
    if (cpu.terminate) return;
    // 004747b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004747ba  7e09                   -jle 0x4747c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004747c5;
    }
    // 004747bc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004747be  e85ddb0000             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004747c3  ebee                   -jmp 0x4747b3
    goto L_0x004747b3;
L_0x004747c5:
    // 004747c5  e8a2c20100             -call 0x490a6c
    cpu.esp -= 4;
    sub_490a6c(app, cpu);
    if (cpu.terminate) return;
    // 004747ca  803dc0744d0000         +cmp byte ptr [0x4d74c0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076160) /* 0x4d74c0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004747d1  7423                   -je 0x4747f6
    if (cpu.flags.zf)
    {
        goto L_0x004747f6;
    }
    // 004747d3  e8f8c00100             -call 0x4908d0
    cpu.esp -= 4;
    sub_4908d0(app, cpu);
    if (cpu.terminate) return;
L_0x004747d8:
    // 004747d8  8b0d10375400           -mov ecx, dword ptr [0x543710]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5519120) /* 0x543710 */);
    // 004747de  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004747e0  74c2                   -je 0x4747a4
    if (cpu.flags.zf)
    {
        goto L_0x004747a4;
    }
    // 004747e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004747e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004747e5  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004747e7  e880e50000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004747ec  891d10375400           -mov dword ptr [0x543710], ebx
    app->getMemory<x86::reg32>(x86::reg32(5519120) /* 0x543710 */) = cpu.ebx;
    // 004747f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004747f6:
    // 004747f6  e861470200             -call 0x498f5c
    cpu.esp -= 4;
    sub_498f5c(app, cpu);
    if (cpu.terminate) return;
    // 004747fb  ebdb                   -jmp 0x4747d8
    goto L_0x004747d8;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_474800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474800);
    // 00474800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474801  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474802  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00474808  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047480a  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047480d  7502                   -jne 0x474811
    if (!cpu.flags.zf)
    {
        goto L_0x00474811;
    }
    // 0047480f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474811:
    // 00474811  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474818  0f85d5000000           -jne 0x4748f3
    if (!cpu.flags.zf)
    {
        goto L_0x004748f3;
    }
    // 0047481e  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474825  0f84c8000000           -je 0x4748f3
    if (cpu.flags.zf)
    {
        goto L_0x004748f3;
    }
    // 0047482b  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047482e  0f8fbf000000           -jg 0x4748f3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004748f3;
    }
    // 00474834  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474836  0f85c0000000           -jne 0x4748fc
    if (!cpu.flags.zf)
    {
        goto L_0x004748fc;
    }
    // 0047483c  a354384d00             -mov dword ptr [0x4d3854], eax
    app->getMemory<x86::reg32>(x86::reg32(5060692) /* 0x4d3854 */) = cpu.eax;
L_0x00474841:
    // 00474841  833d24384d0001         +cmp dword ptr [0x4d3824], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060644) /* 0x4d3824 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474848  7511                   -jne 0x47485b
    if (!cpu.flags.zf)
    {
        goto L_0x0047485b;
    }
    // 0047484a  83f809                 +cmp eax, 9
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
    // 0047484d  7d0c                   -jge 0x47485b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047485b;
    }
    // 0047484f  803d0f0d510000         +cmp byte ptr [0x510d0f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311759) /* 0x510d0f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474856  7403                   -je 0x47485b
    if (cpu.flags.zf)
    {
        goto L_0x0047485b;
    }
    // 00474858  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x0047485b:
    // 0047485b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047485c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047485d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047485e  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474861  0f84a4000000           -je 0x47490b
    if (cpu.flags.zf)
    {
        goto L_0x0047490b;
    }
    // 00474867  8b148574754d00         -mov edx, dword ptr [eax*4 + 0x4d7574]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076340) /* 0x4d7574 */ + cpu.eax * 4);
    // 0047486e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047486f  8b0d70125100           -mov ecx, dword ptr [0x511270]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474875  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474876  6854c34c00             -push 0x4cc354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030740 /*0x4cc354*/;
    cpu.esp -= 4;
    // 0047487b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047487f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474880  e8ec000100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474885  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00474888:
    // 00474888  bed8c34c00             -mov esi, 0x4cc3d8
    cpu.esi = 5030872 /*0x4cc3d8*/;
    // 0047488d  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474891  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474892  2bc9                   +sub ecx, ecx
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
    // 00474894  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474895  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00474897  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474899  4f                     -dec edi
    (cpu.edi)--;
L_0x0047489a:
    // 0047489a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047489c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047489e  3c00                   +cmp al, 0
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
    // 004748a0  7410                   -je 0x4748b2
    if (cpu.flags.zf)
    {
        goto L_0x004748b2;
    }
    // 004748a2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004748a5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004748a8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004748ab  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004748ae  3c00                   +cmp al, 0
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
    // 004748b0  75e8                   -jne 0x47489a
    if (!cpu.flags.zf)
    {
        goto L_0x0047489a;
    }
L_0x004748b2:
    // 004748b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748b3  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004748ba  e831ef0000             -call 0x4837f0
    cpu.esp -= 4;
    sub_4837f0(app, cpu);
    if (cpu.terminate) return;
    // 004748bf  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004748c1  8d94240c010000         -lea edx, [esp + 0x10c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004748c8  88842414010000         -mov byte ptr [esp + 0x114], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.al;
    // 004748cf  a1c4744d00             -mov eax, dword ptr [0x4d74c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */);
    // 004748d4  e837bf0100             -call 0x490810
    cpu.esp -= 4;
    sub_490810(app, cpu);
    if (cpu.terminate) return;
    // 004748d9  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004748dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004748df  e848c00100             -call 0x49092c
    cpu.esp -= 4;
    sub_49092c(app, cpu);
    if (cpu.terminate) return;
    // 004748e4  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004748e9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004748eb  e820000100             -call 0x484910
    cpu.esp -= 4;
    sub_484910(app, cpu);
    if (cpu.terminate) return;
    // 004748f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004748f3:
    // 004748f3  81c410010000           +add esp, 0x110
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(272 /*0x110*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004748f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004748fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004748fc:
    // 004748fc  c70554384d0001000000   -mov dword ptr [0x4d3854], 1
    app->getMemory<x86::reg32>(x86::reg32(5060692) /* 0x4d3854 */) = 1 /*0x1*/;
    // 00474906  e936ffffff             -jmp 0x474841
    goto L_0x00474841;
L_0x0047490b:
    // 0047490b  803dc6754d0000         +cmp byte ptr [0x4d75c6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076422) /* 0x4d75c6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474912  742d                   -je 0x474941
    if (cpu.flags.zf)
    {
        goto L_0x00474941;
    }
    // 00474914  a170125100             -mov eax, dword ptr [0x511270]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474919  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047491a  685cc34c00             -push 0x4cc35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030748 /*0x4cc35c*/;
    cpu.esp -= 4;
L_0x0047491f:
    // 0047491f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474923  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474924  e848000100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474929  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047492c  803dc6754d0000         +cmp byte ptr [0x4d75c6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076422) /* 0x4d75c6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474933  751a                   -jne 0x47494f
    if (!cpu.flags.zf)
    {
        goto L_0x0047494f;
    }
    // 00474935  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00474937  a2c6754d00             -mov byte ptr [0x4d75c6], al
    app->getMemory<x86::reg8>(x86::reg32(5076422) /* 0x4d75c6 */) = cpu.al;
    // 0047493c  e947ffffff             -jmp 0x474888
    goto L_0x00474888;
L_0x00474941:
    // 00474941  8b2d70125100           -mov ebp, dword ptr [0x511270]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474947  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474948  6864c34c00             -push 0x4cc364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030756 /*0x4cc364*/;
    cpu.esp -= 4;
    // 0047494d  ebd0                   -jmp 0x47491f
    goto L_0x0047491f;
L_0x0047494f:
    // 0047494f  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00474951  a2c6754d00             -mov byte ptr [0x4d75c6], al
    app->getMemory<x86::reg8>(x86::reg32(5076422) /* 0x4d75c6 */) = cpu.al;
    // 00474956  e92dffffff             -jmp 0x474888
    goto L_0x00474888;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474960);
    // 00474960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474962  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474963  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474964  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474965  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0047496b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047496d  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 00474974  bbdc050000             -mov ebx, 0x5dc
    cpu.ebx = 1500 /*0x5dc*/;
    // 00474979  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047497c  7502                   -jne 0x474980
    if (!cpu.flags.zf)
    {
        goto L_0x00474980;
    }
    // 0047497e  31c5                   -xor ebp, eax
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474980:
    // 00474980  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00474982  8a159c0c5100           -mov dl, byte ptr [0x510c9c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
    // 00474988  8825c0744d00           -mov byte ptr [0x4d74c0], ah
    app->getMemory<x86::reg8>(x86::reg32(5076160) /* 0x4d74c0 */) = cpu.ah;
    // 0047498e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00474990  7543                   -jne 0x4749d5
    if (!cpu.flags.zf)
    {
        goto L_0x004749d5;
    }
    // 00474992  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474999  743a                   -je 0x4749d5
    if (cpu.flags.zf)
    {
        goto L_0x004749d5;
    }
    // 0047499b  83fd13                 +cmp ebp, 0x13
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047499e  7f35                   -jg 0x4749d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004749d5;
    }
    // 004749a0  803d0f0d510000         +cmp byte ptr [0x510d0f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311759) /* 0x510d0f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004749a7  7538                   -jne 0x4749e1
    if (!cpu.flags.zf)
    {
        goto L_0x004749e1;
    }
    // 004749a9  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004749ac  7d33                   -jge 0x4749e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004749e1;
    }
    // 004749ae  803d100d510000         +cmp byte ptr [0x510d10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311760) /* 0x510d10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004749b5  7609                   -jbe 0x4749c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004749c0;
    }
    // 004749b7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004749b9  e8c2010000             -call 0x474b80
    cpu.esp -= 4;
    sub_474b80(app, cpu);
    if (cpu.terminate) return;
    // 004749be  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004749c0:
    // 004749c0  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004749c7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004749c9  e832feffff             -call 0x474800
    cpu.esp -= 4;
    sub_474800(app, cpu);
    if (cpu.terminate) return;
    // 004749ce  c605c0744d0001         -mov byte ptr [0x4d74c0], 1
    app->getMemory<x86::reg8>(x86::reg32(5076160) /* 0x4d74c0 */) = 1 /*0x1*/;
L_0x004749d5:
    // 004749d5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004749db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004749e1:
    // 004749e1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004749e3  0f852f010000           -jne 0x474b18
    if (!cpu.flags.zf)
    {
        goto L_0x00474b18;
    }
    // 004749e9  892d54384d00           -mov dword ptr [0x4d3854], ebp
    app->getMemory<x86::reg32>(x86::reg32(5060692) /* 0x4d3854 */) = cpu.ebp;
L_0x004749ef:
    // 004749ef  833d24384d0001         +cmp dword ptr [0x4d3824], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060644) /* 0x4d3824 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004749f6  7508                   -jne 0x474a00
    if (!cpu.flags.zf)
    {
        goto L_0x00474a00;
    }
    // 004749f8  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004749fb  7d03                   -jge 0x474a00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474a00;
    }
    // 004749fd  83c509                 -add ebp, 9
    (cpu.ebp) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00474a00:
    // 00474a00  83fd12                 +cmp ebp, 0x12
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474a03  0f841e010000           -je 0x474b27
    if (cpu.flags.zf)
    {
        goto L_0x00474b27;
    }
    // 00474a09  8b0cad74754d00         -mov ecx, dword ptr [ebp*4 + 0x4d7574]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076340) /* 0x4d7574 */ + cpu.ebp * 4);
    // 00474a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474a11  8b3570125100           -mov esi, dword ptr [0x511270]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474a17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474a18  6854c34c00             -push 0x4cc354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030740 /*0x4cc354*/;
    cpu.esp -= 4;
    // 00474a1d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474a21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a22  e84aff0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474a27  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00474a2a:
    // 00474a2a  be8cc34c00             -mov esi, 0x4cc38c
    cpu.esi = 5030796 /*0x4cc38c*/;
    // 00474a2f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00474a31  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00474a36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474a37  2bc9                   +sub ecx, ecx
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
    // 00474a39  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474a3a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00474a3c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474a3e  4f                     -dec edi
    (cpu.edi)--;
L_0x00474a3f:
    // 00474a3f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00474a41  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00474a43  3c00                   +cmp al, 0
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
    // 00474a45  7410                   -je 0x474a57
    if (cpu.flags.zf)
    {
        goto L_0x00474a57;
    }
    // 00474a47  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00474a4a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474a4d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00474a50  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474a53  3c00                   +cmp al, 0
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
    // 00474a55  75e8                   -jne 0x474a3f
    if (!cpu.flags.zf)
    {
        goto L_0x00474a3f;
    }
L_0x00474a57:
    // 00474a57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474a58  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474a5a  e851090100             -call 0x4853b0
    cpu.esp -= 4;
    sub_4853b0(app, cpu);
    if (cpu.terminate) return;
    // 00474a5f  a310375400             -mov dword ptr [0x543710], eax
    app->getMemory<x86::reg32>(x86::reg32(5519120) /* 0x543710 */) = cpu.eax;
    // 00474a64  e8db420200             -call 0x498d44
    cpu.esp -= 4;
    sub_498d44(app, cpu);
    if (cpu.terminate) return;
    // 00474a69  8b3d54125100           -mov edi, dword ptr [0x511254]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5313108) /* 0x511254 */);
    // 00474a6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474a70  68d0c34c00             -push 0x4cc3d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030864 /*0x4cc3d0*/;
    cpu.esp -= 4;
    // 00474a75  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474a79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a7a  bea8c34c00             -mov esi, 0x4cc3a8
    cpu.esi = 5030824 /*0x4cc3a8*/;
    // 00474a7f  e8edfe0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474a84  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474a87  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00474a89  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00474a8b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474a8c  2bc9                   +sub ecx, ecx
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
    // 00474a8e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474a8f  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00474a91  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474a93  4f                     -dec edi
    (cpu.edi)--;
L_0x00474a94:
    // 00474a94  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00474a96  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00474a98  3c00                   +cmp al, 0
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
    // 00474a9a  7410                   -je 0x474aac
    if (cpu.flags.zf)
    {
        goto L_0x00474aac;
    }
    // 00474a9c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00474a9f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474aa2  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00474aa5  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474aa8  3c00                   +cmp al, 0
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
    // 00474aaa  75e8                   -jne 0x474a94
    if (!cpu.flags.zf)
    {
        goto L_0x00474a94;
    }
L_0x00474aac:
    // 00474aac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474aad  a1c4744d00             -mov eax, dword ptr [0x4d74c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */);
    // 00474ab2  e829430200             -call 0x498de0
    cpu.esp -= 4;
    sub_498de0(app, cpu);
    if (cpu.terminate) return;
    // 00474ab7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00474abc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474abe  e84dfe0000             -call 0x484910
    cpu.esp -= 4;
    sub_484910(app, cpu);
    if (cpu.terminate) return;
    // 00474ac3  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00474aca  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00474acf  e83cfe0000             -call 0x484910
    cpu.esp -= 4;
    sub_484910(app, cpu);
    if (cpu.terminate) return;
    // 00474ad4  833df8ff500000         +cmp dword ptr [0x50fff8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308408) /* 0x50fff8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474adb  0f84f4feffff           -je 0x4749d5
    if (cpu.flags.zf)
    {
        goto L_0x004749d5;
    }
    // 00474ae1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00474ae3  0f84ecfeffff           -je 0x4749d5
    if (cpu.flags.zf)
    {
        goto L_0x004749d5;
    }
    // 00474ae9  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474aec  0f84e3feffff           -je 0x4749d5
    if (cpu.flags.zf)
    {
        goto L_0x004749d5;
    }
    // 00474af2  8a04add4744d00         -mov al, byte ptr [ebp*4 + 0x4d74d4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5076180) /* 0x4d74d4 */ + cpu.ebp * 4);
    // 00474af9  a220384d00             -mov byte ptr [0x4d3820], al
    app->getMemory<x86::reg8>(x86::reg32(5060640) /* 0x4d3820 */) = cpu.al;
    // 00474afe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474b00  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474b02  a020384d00             -mov al, byte ptr [0x4d3820]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5060640) /* 0x4d3820 */);
    // 00474b07  e8c8430200             -call 0x498ed4
    cpu.esp -= 4;
    sub_498ed4(app, cpu);
    if (cpu.terminate) return;
    // 00474b0c  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00474b12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474b18:
    // 00474b18  c70554384d0001000000   -mov dword ptr [0x4d3854], 1
    app->getMemory<x86::reg32>(x86::reg32(5060692) /* 0x4d3854 */) = 1 /*0x1*/;
    // 00474b22  e9c8feffff             -jmp 0x4749ef
    goto L_0x004749ef;
L_0x00474b27:
    // 00474b27  803dc5754d0000         +cmp byte ptr [0x4d75c5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076421) /* 0x4d75c5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474b2e  742e                   -je 0x474b5e
    if (cpu.flags.zf)
    {
        goto L_0x00474b5e;
    }
    // 00474b30  8b1570125100           -mov edx, dword ptr [0x511270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474b36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474b37  685cc34c00             -push 0x4cc35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030748 /*0x4cc35c*/;
    cpu.esp -= 4;
L_0x00474b3c:
    // 00474b3c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474b40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474b41  e82bfe0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474b46  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474b49  803dc5754d0000         +cmp byte ptr [0x4d75c5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076421) /* 0x4d75c5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474b50  7519                   -jne 0x474b6b
    if (!cpu.flags.zf)
    {
        goto L_0x00474b6b;
    }
    // 00474b52  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00474b54  a2c5754d00             -mov byte ptr [0x4d75c5], al
    app->getMemory<x86::reg8>(x86::reg32(5076421) /* 0x4d75c5 */) = cpu.al;
    // 00474b59  e9ccfeffff             -jmp 0x474a2a
    goto L_0x00474a2a;
L_0x00474b5e:
    // 00474b5e  a170125100             -mov eax, dword ptr [0x511270]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474b63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474b64  6864c34c00             -push 0x4cc364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030756 /*0x4cc364*/;
    cpu.esp -= 4;
    // 00474b69  ebd1                   -jmp 0x474b3c
    goto L_0x00474b3c;
L_0x00474b6b:
    // 00474b6b  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00474b6d  a2c5754d00             -mov byte ptr [0x4d75c5], al
    app->getMemory<x86::reg8>(x86::reg32(5076421) /* 0x4d75c5 */) = cpu.al;
    // 00474b72  e9b3feffff             -jmp 0x474a2a
    goto L_0x00474a2a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474b80);
    // 00474b80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474b81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474b82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474b83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474b84  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474b87  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00474b8c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00474b8e  be50454700             -mov esi, 0x474550
    cpu.esi = 4670800 /*0x474550*/;
    // 00474b93  8a150f0d5100           -mov dl, byte ptr [0x510d0f]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5311759) /* 0x510d0f */);
    // 00474b99  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474b9b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00474b9d  7513                   -jne 0x474bb2
    if (!cpu.flags.zf)
    {
        goto L_0x00474bb2;
    }
    // 00474b9f  8a35100d5100           -mov dh, byte ptr [0x510d10]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5311760) /* 0x510d10 */);
    // 00474ba5  80fe11                 +cmp dh, 0x11
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474ba8  7410                   -je 0x474bba
    if (cpu.flags.zf)
    {
        goto L_0x00474bba;
    }
    // 00474baa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474bac  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 00474bae  8b4484fc               -mov eax, dword ptr [esp + eax*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
L_0x00474bb2:
    // 00474bb2  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474bb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bb6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474bba:
    // 00474bba  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474bbb  8a1d50925000           -mov bl, byte ptr [0x509250]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5280336) /* 0x509250 */);
    // 00474bc1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474bc3  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 00474bc5  8a9265384d00           -mov dl, byte ptr [edx + 0x4d3865]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5060709) /* 0x4d3865 */);
    // 00474bcb  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00474bd1  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00474bd6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474bd8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474bdb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474bdd  fec3                   -inc bl
    (cpu.bl)++;
    // 00474bdf  881d50925000           -mov byte ptr [0x509250], bl
    app->getMemory<x86::reg8>(x86::reg32(5280336) /* 0x509250 */) = cpu.bl;
    // 00474be5  8b449404               -mov eax, dword ptr [esp + edx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 00474be9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bea  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474bed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bf0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474bf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474c00);
    // 00474c00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474c01  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474c02  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00474c08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00474c0a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00474c0c  c7842400010000dc050000 -mov dword ptr [esp + 0x100], 0x5dc
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = 1500 /*0x5dc*/;
    // 00474c17  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c1a  7502                   -jne 0x474c1e
    if (!cpu.flags.zf)
    {
        goto L_0x00474c1e;
    }
    // 00474c1c  31c3                   -xor ebx, eax
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474c1e:
    // 00474c1e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00474c20  8a159c0c5100           -mov dl, byte ptr [0x510c9c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
    // 00474c26  8825c0744d00           -mov byte ptr [0x4d74c0], ah
    app->getMemory<x86::reg8>(x86::reg32(5076160) /* 0x4d74c0 */) = cpu.ah;
    // 00474c2c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00474c2e  0f854d010000           -jne 0x474d81
    if (!cpu.flags.zf)
    {
        goto L_0x00474d81;
    }
    // 00474c34  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c3b  0f8440010000           -je 0x474d81
    if (cpu.flags.zf)
    {
        goto L_0x00474d81;
    }
    // 00474c41  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c44  0f8f37010000           -jg 0x474d81
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00474d81;
    }
    // 00474c4a  803d0f0d510000         +cmp byte ptr [0x510d0f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311759) /* 0x510d0f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474c51  7509                   -jne 0x474c5c
    if (!cpu.flags.zf)
    {
        goto L_0x00474c5c;
    }
    // 00474c53  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c56  0f8c2e010000           -jl 0x474d8a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00474d8a;
    }
L_0x00474c5c:
    // 00474c5c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00474c5e  0f853f010000           -jne 0x474da3
    if (!cpu.flags.zf)
    {
        goto L_0x00474da3;
    }
    // 00474c64  891d54384d00           -mov dword ptr [0x4d3854], ebx
    app->getMemory<x86::reg32>(x86::reg32(5060692) /* 0x4d3854 */) = cpu.ebx;
L_0x00474c6a:
    // 00474c6a  833d24384d0001         +cmp dword ptr [0x4d3824], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060644) /* 0x4d3824 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c71  7508                   -jne 0x474c7b
    if (!cpu.flags.zf)
    {
        goto L_0x00474c7b;
    }
    // 00474c73  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c76  7d03                   -jge 0x474c7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474c7b;
    }
    // 00474c78  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00474c7b:
    // 00474c7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474c7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474c7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474c7e  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474c81  0f842b010000           -je 0x474db2
    if (cpu.flags.zf)
    {
        goto L_0x00474db2;
    }
    // 00474c87  8b349d74754d00         -mov esi, dword ptr [ebx*4 + 0x4d7574]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076340) /* 0x4d7574 */ + cpu.ebx * 4);
    // 00474c8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474c8f  8b3d70125100           -mov edi, dword ptr [0x511270]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474c95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474c96  6854c34c00             -push 0x4cc354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030740 /*0x4cc354*/;
    cpu.esp -= 4;
    // 00474c9b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00474c9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474ca0  e8ccfc0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474ca5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00474ca8:
    // 00474ca8  be8cc34c00             -mov esi, 0x4cc38c
    cpu.esi = 5030796 /*0x4cc38c*/;
    // 00474cad  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474cb1  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00474cb6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474cb7  2bc9                   +sub ecx, ecx
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
    // 00474cb9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474cba  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00474cbc  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474cbe  4f                     -dec edi
    (cpu.edi)--;
L_0x00474cbf:
    // 00474cbf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00474cc1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00474cc3  3c00                   +cmp al, 0
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
    // 00474cc5  7410                   -je 0x474cd7
    if (cpu.flags.zf)
    {
        goto L_0x00474cd7;
    }
    // 00474cc7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00474cca  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474ccd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00474cd0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474cd3  3c00                   +cmp al, 0
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
    // 00474cd5  75e8                   -jne 0x474cbf
    if (!cpu.flags.zf)
    {
        goto L_0x00474cbf;
    }
L_0x00474cd7:
    // 00474cd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474cd8  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474cdc  e8cf060100             -call 0x4853b0
    cpu.esp -= 4;
    sub_4853b0(app, cpu);
    if (cpu.terminate) return;
    // 00474ce1  a310375400             -mov dword ptr [0x543710], eax
    app->getMemory<x86::reg32>(x86::reg32(5519120) /* 0x543710 */) = cpu.eax;
    // 00474ce6  e859400200             -call 0x498d44
    cpu.esp -= 4;
    sub_498d44(app, cpu);
    if (cpu.terminate) return;
    // 00474ceb  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474cee  0f8412010000           -je 0x474e06
    if (cpu.flags.zf)
    {
        goto L_0x00474e06;
    }
    // 00474cf4  8b0c9d24754d00         -mov ecx, dword ptr [ebx*4 + 0x4d7524]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076260) /* 0x4d7524 */ + cpu.ebx * 4);
    // 00474cfb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474cfc  8b1d70125100           -mov ebx, dword ptr [0x511270]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474d02  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474d03  6854c34c00             -push 0x4cc354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030740 /*0x4cc354*/;
    cpu.esp -= 4;
    // 00474d08  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00474d0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474d0d  e85ffc0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474d12  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00474d15:
    // 00474d15  bea8c34c00             -mov esi, 0x4cc3a8
    cpu.esi = 5030824 /*0x4cc3a8*/;
    // 00474d1a  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474d1e  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00474d25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474d26  2bc9                   +sub ecx, ecx
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
    // 00474d28  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00474d29  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00474d2b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00474d2d  4f                     -dec edi
    (cpu.edi)--;
L_0x00474d2e:
    // 00474d2e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00474d30  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00474d32  3c00                   +cmp al, 0
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
    // 00474d34  7410                   -je 0x474d46
    if (cpu.flags.zf)
    {
        goto L_0x00474d46;
    }
    // 00474d36  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00474d39  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474d3c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00474d3f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00474d42  3c00                   +cmp al, 0
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
    // 00474d44  75e8                   -jne 0x474d2e
    if (!cpu.flags.zf)
    {
        goto L_0x00474d2e;
    }
L_0x00474d46:
    // 00474d46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474d49  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474d4d  e8ce3c0200             -call 0x498a20
    cpu.esp -= 4;
    sub_498a20(app, cpu);
    if (cpu.terminate) return;
    // 00474d52  a1c4744d00             -mov eax, dword ptr [0x4d74c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */);
    // 00474d57  e884400200             -call 0x498de0
    cpu.esp -= 4;
    sub_498de0(app, cpu);
    if (cpu.terminate) return;
    // 00474d5c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00474d61  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474d63  e8a8fb0000             -call 0x484910
    cpu.esp -= 4;
    sub_484910(app, cpu);
    if (cpu.terminate) return;
    // 00474d68  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 00474d6d  e8ae3c0200             -call 0x498a20
    cpu.esp -= 4;
    sub_498a20(app, cpu);
    if (cpu.terminate) return;
    // 00474d72  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474d74  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00474d79  e892fb0000             -call 0x484910
    cpu.esp -= 4;
    sub_484910(app, cpu);
    if (cpu.terminate) return;
    // 00474d7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00474d81:
    // 00474d81  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00474d87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474d89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474d8a:
    // 00474d8a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474d8c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00474d8e  e86dfaffff             -call 0x474800
    cpu.esp -= 4;
    sub_474800(app, cpu);
    if (cpu.terminate) return;
    // 00474d93  c605c0744d0001         -mov byte ptr [0x4d74c0], 1
    app->getMemory<x86::reg8>(x86::reg32(5076160) /* 0x4d74c0 */) = 1 /*0x1*/;
    // 00474d9a  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00474da0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474da1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474da2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474da3:
    // 00474da3  c70554384d0001000000   -mov dword ptr [0x4d3854], 1
    app->getMemory<x86::reg32>(x86::reg32(5060692) /* 0x4d3854 */) = 1 /*0x1*/;
    // 00474dad  e9b8feffff             -jmp 0x474c6a
    goto L_0x00474c6a;
L_0x00474db2:
    // 00474db2  803dc4754d0000         +cmp byte ptr [0x4d75c4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076420) /* 0x4d75c4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474db9  7529                   -jne 0x474de4
    if (!cpu.flags.zf)
    {
        goto L_0x00474de4;
    }
    // 00474dbb  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00474dbd:
    // 00474dbd  a2c4754d00             -mov byte ptr [0x4d75c4], al
    app->getMemory<x86::reg8>(x86::reg32(5076420) /* 0x4d75c4 */) = cpu.al;
    // 00474dc2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00474dc4  7422                   -je 0x474de8
    if (cpu.flags.zf)
    {
        goto L_0x00474de8;
    }
    // 00474dc6  8b0d70125100           -mov ecx, dword ptr [0x511270]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474dcc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474dcd  685cc34c00             -push 0x4cc35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030748 /*0x4cc35c*/;
    cpu.esp -= 4;
    // 00474dd2  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474dd6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474dd7  e895fb0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474ddc  83c40c                 +add esp, 0xc
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
    // 00474ddf  e9c4feffff             -jmp 0x474ca8
    goto L_0x00474ca8;
L_0x00474de4:
    // 00474de4  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00474de6  ebd5                   -jmp 0x474dbd
    goto L_0x00474dbd;
L_0x00474de8:
    // 00474de8  8b1570125100           -mov edx, dword ptr [0x511270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474dee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474def  6864c34c00             -push 0x4cc364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030756 /*0x4cc364*/;
    cpu.esp -= 4;
    // 00474df4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474df8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474df9  e873fb0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474dfe  83c40c                 +add esp, 0xc
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
    // 00474e01  e9a2feffff             -jmp 0x474ca8
    goto L_0x00474ca8;
L_0x00474e06:
    // 00474e06  803dc4754d0000         +cmp byte ptr [0x4d75c4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5076420) /* 0x4d75c4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474e0d  741e                   -je 0x474e2d
    if (cpu.flags.zf)
    {
        goto L_0x00474e2d;
    }
    // 00474e0f  8b1570125100           -mov edx, dword ptr [0x511270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474e15  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474e16  685cc34c00             -push 0x4cc35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030748 /*0x4cc35c*/;
    cpu.esp -= 4;
    // 00474e1b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474e1f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474e20  e84cfb0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474e25  83c40c                 +add esp, 0xc
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
    // 00474e28  e9e8feffff             -jmp 0x474d15
    goto L_0x00474d15;
L_0x00474e2d:
    // 00474e2d  a170125100             -mov eax, dword ptr [0x511270]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474e32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474e33  6864c34c00             -push 0x4cc364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030756 /*0x4cc364*/;
    cpu.esp -= 4;
    // 00474e38  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474e3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474e3d  e82ffb0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474e42  83c40c                 +add esp, 0xc
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
    // 00474e45  e9cbfeffff             -jmp 0x474d15
    goto L_0x00474d15;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474e50);
    // 00474e50  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474e57  7509                   -jne 0x474e62
    if (!cpu.flags.zf)
    {
        goto L_0x00474e62;
    }
    // 00474e59  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474e60  7501                   -jne 0x474e63
    if (!cpu.flags.zf)
    {
        goto L_0x00474e63;
    }
L_0x00474e62:
    // 00474e62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474e63:
    // 00474e63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474e64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474e65  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 00474e6a  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 00474e6d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474e6f  e8e4970100             -call 0x48e658
    cpu.esp -= 4;
    sub_48e658(app, cpu);
    if (cpu.terminate) return;
    // 00474e74  a3c4744d00             -mov dword ptr [0x4d74c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */) = cpu.eax;
    // 00474e79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_474e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474e80);
    // 00474e80  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474e87  7509                   -jne 0x474e92
    if (!cpu.flags.zf)
    {
        goto L_0x00474e92;
    }
    // 00474e89  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474e90  7501                   -jne 0x474e93
    if (!cpu.flags.zf)
    {
        goto L_0x00474e93;
    }
L_0x00474e92:
    // 00474e92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474e93:
    // 00474e93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474e94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474e95  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 00474e9a  b800b00400             -mov eax, 0x4b000
    cpu.eax = 307200 /*0x4b000*/;
    // 00474e9f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474ea1  e8b2970100             -call 0x48e658
    cpu.esp -= 4;
    sub_48e658(app, cpu);
    if (cpu.terminate) return;
    // 00474ea6  a3c4744d00             -mov dword ptr [0x4d74c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5076164) /* 0x4d74c4 */) = cpu.eax;
    // 00474eab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474eac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474ead  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_474eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00474eb0);
    // 00474eb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474eb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474eb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474eb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474eb4  81ec20010000           -sub esp, 0x120
    (cpu.esp) -= x86::reg32(x86::sreg32(288 /*0x120*/));
    // 00474eba  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00474ebc  be00000800             -mov esi, 0x80000
    cpu.esi = 524288 /*0x80000*/;
    // 00474ec1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00474ec3  8a250f0d5100           -mov ah, byte ptr [0x510d0f]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5311759) /* 0x510d0f */);
    // 00474ec9  89bc241c010000         -mov dword ptr [esp + 0x11c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */) = cpu.edi;
    // 00474ed0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00474ed2  0f845b010000           -je 0x475033
    if (cpu.flags.zf)
    {
        goto L_0x00475033;
    }
    // 00474ed8  803d9c0c510000         +cmp byte ptr [0x510c9c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5311644) /* 0x510c9c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474edf  0f854e010000           -jne 0x475033
    if (!cpu.flags.zf)
    {
        goto L_0x00475033;
    }
    // 00474ee5  833d24384d0001         +cmp dword ptr [0x4d3824], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060644) /* 0x4d3824 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474eec  7508                   -jne 0x474ef6
    if (!cpu.flags.zf)
    {
        goto L_0x00474ef6;
    }
    // 00474eee  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474ef1  7d03                   -jge 0x474ef6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474ef6;
    }
    // 00474ef3  83c109                 -add ecx, 9
    (cpu.ecx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00474ef6:
    // 00474ef6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474ef7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474ef8  bd0cc34c00             -mov ebp, 0x4cc30c
    cpu.ebp = 5030668 /*0x4cc30c*/;
    // 00474efd  b85a010000             -mov eax, 0x15a
    cpu.eax = 346 /*0x15a*/;
    // 00474f02  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00474f04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474f06  a3f88f4d00             -mov dword ptr [0x4d8ff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.eax;
    // 00474f0b  b828c34c00             -mov eax, 0x4cc328
    cpu.eax = 5030696 /*0x4cc328*/;
    // 00474f10  892df48f4d00           -mov dword ptr [0x4d8ff4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebp;
    // 00474f16  e8edd90000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 00474f1b  8b148d24754d00         -mov edx, dword ptr [ecx*4 + 0x4d7524]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076260) /* 0x4d7524 */ + cpu.ecx * 4);
    // 00474f22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474f23  8b0d70125100           -mov ecx, dword ptr [0x511270]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5313136) /* 0x511270 */);
    // 00474f29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474f2a  6830c34c00             -push 0x4cc330
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030704 /*0x4cc330*/;
    cpu.esp -= 4;
    // 00474f2f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00474f31  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00474f35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474f36  e836fa0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474f3b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474f3e  8b1d54125100           -mov ebx, dword ptr [0x511254]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5313108) /* 0x511254 */);
    // 00474f44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474f45  68e4c24c00             -push 0x4cc2e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030628 /*0x4cc2e4*/;
    cpu.esp -= 4;
    // 00474f4a  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00474f51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474f52  e81afa0000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00474f57  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474f5a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474f5e  e88d430200             -call 0x4992f0
    cpu.esp -= 4;
    sub_4992f0(app, cpu);
    if (cpu.terminate) return;
    // 00474f63  89842420010000         -mov dword ptr [esp + 0x120], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.eax;
    // 00474f6a  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00474f71  e86a1a0100             -call 0x4869e0
    cpu.esp -= 4;
    sub_4869e0(app, cpu);
    if (cpu.terminate) return;
    // 00474f76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474f78  0f85c0000000           -jne 0x47503e
    if (!cpu.flags.zf)
    {
        goto L_0x0047503e;
    }
L_0x00474f7e:
    // 00474f7e  8d8c2418010000         -lea ecx, [esp + 0x118]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 00474f85  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00474f8c  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00474f93  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474f97  e8880c0100             -call 0x485c24
    cpu.esp -= 4;
    sub_485c24(app, cpu);
    if (cpu.terminate) return;
    // 00474f9c  8d8c241c010000         -lea ecx, [esp + 0x11c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00474fa3  8d9c240c010000         -lea ebx, [esp + 0x10c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00474faa  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00474fb1  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00474fb8  e8770c0100             -call 0x485c34
    cpu.esp -= 4;
    sub_485c34(app, cpu);
    if (cpu.terminate) return;
L_0x00474fbd:
    // 00474fbd  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00474fc4  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00474fc6  39f0                   +cmp eax, esi
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
    // 00474fc8  7d0d                   -jge 0x474fd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474fd7;
    }
    // 00474fca  c784242401000001000000 -mov dword ptr [esp + 0x124], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = 1 /*0x1*/;
    // 00474fd5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00474fd7:
    // 00474fd7  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00474fde  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00474fe0  e8f30d0100             -call 0x485dd8
    cpu.esp -= 4;
    sub_485dd8(app, cpu);
    if (cpu.terminate) return;
    // 00474fe5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00474fe7  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00474fee  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00474ff0  e8d30d0100             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 00474ff5  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00474ffc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00474ffe  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00475000  e8cb0d0100             -call 0x485dd0
    cpu.esp -= 4;
    sub_485dd0(app, cpu);
    if (cpu.terminate) return;
    // 00475005  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0047500c  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047500e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475010  74ab                   -je 0x474fbd
    if (cpu.flags.zf)
    {
        goto L_0x00474fbd;
    }
    // 00475012  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00475019  e8a20d0100             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 0047501e  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00475025  e8960d0100             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 0047502a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047502c  e83bdd0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 00475031  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475032  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00475033:
    // 00475033  81c420010000           +add esp, 0x120
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00475039  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047503a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047503b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047503c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047503d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047503e:
    // 0047503e  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00475040  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00475047  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475048  2eff1560454c00         -call dword ptr cs:[0x4c4560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998496) /* 0x4c4560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047504f  e92affffff             -jmp 0x474f7e
    goto L_0x00474f7e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475060);
    // 00475060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475062  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475063  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475064  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0047506a  8b1554125100           -mov edx, dword ptr [0x511254]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313108) /* 0x511254 */);
    // 00475070  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475071  68e4c24c00             -push 0x4cc2e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030628 /*0x4cc2e4*/;
    cpu.esp -= 4;
    // 00475076  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047507a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047507b  e8f1f80000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00475080  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475083  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475085  be0000f000             -mov esi, 0xf00000
    cpu.esi = 15728640 /*0xf00000*/;
    // 0047508a  e851190100             -call 0x4869e0
    cpu.esp -= 4;
    sub_4869e0(app, cpu);
    if (cpu.terminate) return;
    // 0047508f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475091  7545                   -jne 0x4750d8
    if (!cpu.flags.zf)
    {
        goto L_0x004750d8;
    }
L_0x00475093:
    // 00475093  8d8c2484000000         -lea ecx, [esp + 0x84]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0047509a  8d9c2488000000         -lea ebx, [esp + 0x88]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 004750a1  8d942480000000         -lea edx, [esp + 0x80]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004750a8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004750aa  e8850b0100             -call 0x485c34
    cpu.esp -= 4;
    sub_485c34(app, cpu);
    if (cpu.terminate) return;
    // 004750af  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004750b6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004750b8  e8432efeff             -call 0x457f00
    cpu.esp -= 4;
    sub_457f00(app, cpu);
    if (cpu.terminate) return;
    // 004750bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004750bf  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004750c6  e8f50c0100             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 004750cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004750cd  81c48c000000           +add esp, 0x8c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004750d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004750d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004750d8:
    // 004750d8  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004750da  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004750de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004750df  2eff1560454c00         -call dword ptr cs:[0x4c4560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998496) /* 0x4c4560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004750e6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004750e8  e8310d0100             -call 0x485e1e
    cpu.esp -= 4;
    sub_485e1e(app, cpu);
    if (cpu.terminate) return;
    // 004750ed  eba4                   -jmp 0x475093
    goto L_0x00475093;
}

/* align: skip 0x00 */
void Application::sub_4750f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004750f0);
    // 004750f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004750f1  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004750f7  8b1554125100           -mov edx, dword ptr [0x511254]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313108) /* 0x511254 */);
    // 004750fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004750fe  68e4c24c00             -push 0x4cc2e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030628 /*0x4cc2e4*/;
    cpu.esp -= 4;
    // 00475103  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475107  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475108  e864f80000             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0047510d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475110  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475112  e8c9180100             -call 0x4869e0
    cpu.esp -= 4;
    sub_4869e0(app, cpu);
    if (cpu.terminate) return;
    // 00475117  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475119  7508                   -jne 0x475123
    if (!cpu.flags.zf)
    {
        goto L_0x00475123;
    }
    // 0047511b  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00475121  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475122  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475123:
    // 00475123  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475124  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00475126  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047512a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047512b  2eff1560454c00         -call dword ptr cs:[0x4c4560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998496) /* 0x4c4560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475132  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475136  e8e30c0100             -call 0x485e1e
    cpu.esp -= 4;
    sub_485e1e(app, cpu);
    if (cpu.terminate) return;
    // 0047513b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047513c  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00475142  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475143  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475150);
    // 00475150  833d38384d0000         +cmp dword ptr [0x4d3838], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060664) /* 0x4d3838 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475157  0f85635b0200           -jne 0x49acc0
    if (!cpu.flags.zf)
    {
        return sub_49acc0(app, cpu);
    }
    // 0047515d  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475164  0f85565b0200           -jne 0x49acc0
    if (!cpu.flags.zf)
    {
        return sub_49acc0(app, cpu);
    }
    // 0047516a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475170);
    // 00475170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475172  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475173  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475174  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00475176  8b3d38384d00           -mov edi, dword ptr [0x4d3838]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5060664) /* 0x4d3838 */);
    // 0047517c  8935cc744d00           -mov dword ptr [0x4d74cc], esi
    app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */) = cpu.esi;
    // 00475182  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00475184  7445                   -je 0x4751cb
    if (cpu.flags.zf)
    {
        goto L_0x004751cb;
    }
L_0x00475186:
    // 00475186  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475188  7558                   -jne 0x4751e2
    if (!cpu.flags.zf)
    {
        goto L_0x004751e2;
    }
    // 0047518a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047518c  7554                   -jne 0x4751e2
    if (!cpu.flags.zf)
    {
        goto L_0x004751e2;
    }
    // 0047518e  81e308080000           -and ebx, 0x808
    cpu.ebx &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 00475194  81fb08080000           +cmp ebx, 0x808
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047519a  743d                   -je 0x4751d9
    if (cpu.flags.zf)
    {
        goto L_0x004751d9;
    }
L_0x0047519c:
    // 0047519c  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004751a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004751a3:
    // 004751a3  e8c85a0200             -call 0x49ac70
    cpu.esp -= 4;
    sub_49ac70(app, cpu);
    if (cpu.terminate) return;
    // 004751a8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004751aa:
    // 004751aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004751ac  0f8d9b000000           -jge 0x47524d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047524d;
    }
    // 004751b2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004751b4  890d3c384d00           -mov dword ptr [0x4d383c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */) = cpu.ecx;
    // 004751ba  890d58384d00           -mov dword ptr [0x4d3858], ecx
    app->getMemory<x86::reg32>(x86::reg32(5060696) /* 0x4d3858 */) = cpu.ecx;
    // 004751c0  890d38384d00           -mov dword ptr [0x4d3838], ecx
    app->getMemory<x86::reg32>(x86::reg32(5060664) /* 0x4d3838 */) = cpu.ecx;
    // 004751c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004751cb:
    // 004751cb  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004751d2  75b2                   -jne 0x475186
    if (!cpu.flags.zf)
    {
        goto L_0x00475186;
    }
    // 004751d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004751d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004751d9:
    // 004751d9  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004751de  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004751e0  ebc1                   -jmp 0x4751a3
    goto L_0x004751a3;
L_0x004751e2:
    // 004751e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004751e4  751c                   -jne 0x475202
    if (!cpu.flags.zf)
    {
        goto L_0x00475202;
    }
    // 004751e6  83fa01                 +cmp edx, 1
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
    // 004751e9  7517                   -jne 0x475202
    if (!cpu.flags.zf)
    {
        goto L_0x00475202;
    }
    // 004751eb  81e304080000           -and ebx, 0x804
    cpu.ebx &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 004751f1  81fb04080000           +cmp ebx, 0x804
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004751f7  75a3                   -jne 0x47519c
    if (!cpu.flags.zf)
    {
        goto L_0x0047519c;
    }
    // 004751f9  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004751fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475200  eba1                   -jmp 0x4751a3
    goto L_0x004751a3;
L_0x00475202:
    // 00475202  83f801                 +cmp eax, 1
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
    // 00475205  751b                   -jne 0x475222
    if (!cpu.flags.zf)
    {
        goto L_0x00475222;
    }
    // 00475207  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475209  7517                   -jne 0x475222
    if (!cpu.flags.zf)
    {
        goto L_0x00475222;
    }
    // 0047520b  81e302080000           -and ebx, 0x802
    cpu.ebx &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00475211  81fb02080000           +cmp ebx, 0x802
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475217  7583                   -jne 0x47519c
    if (!cpu.flags.zf)
    {
        goto L_0x0047519c;
    }
    // 00475219  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047521e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475220  eb81                   -jmp 0x4751a3
    goto L_0x004751a3;
L_0x00475222:
    // 00475222  83f801                 +cmp eax, 1
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
    // 00475225  7583                   -jne 0x4751aa
    if (!cpu.flags.zf)
    {
        goto L_0x004751aa;
    }
    // 00475227  39c2                   +cmp edx, eax
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
    // 00475229  0f857bffffff           -jne 0x4751aa
    if (!cpu.flags.zf)
    {
        goto L_0x004751aa;
    }
    // 0047522f  81e301080000           -and ebx, 0x801
    cpu.ebx &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00475235  81fb01080000           +cmp ebx, 0x801
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047523b  0f855bffffff           -jne 0x47519c
    if (!cpu.flags.zf)
    {
        goto L_0x0047519c;
    }
    // 00475241  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00475246  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475248  e956ffffff             -jmp 0x4751a3
    goto L_0x004751a3;
L_0x0047524d:
    // 0047524d  e8eeb3fcff             -call 0x440640
    cpu.esp -= 4;
    sub_440640(app, cpu);
    if (cpu.terminate) return;
    // 00475252  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00475257  e8501a0100             -call 0x486cac
    cpu.esp -= 4;
    sub_486cac(app, cpu);
    if (cpu.terminate) return;
    // 0047525c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047525e  a3d0744d00             -mov dword ptr [0x4d74d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5076176) /* 0x4d74d0 */) = cpu.eax;
    // 00475263  a3cc744d00             -mov dword ptr [0x4d74cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */) = cpu.eax;
    // 00475268  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475269  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047526a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047526b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047526c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_475270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475270);
    // 00475270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475271  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475272  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475273  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475274  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475275  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475277  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00475279:
    // 00475279  8982e0915000           -mov dword ptr [edx + 0x5091e0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5280224) /* 0x5091e0 */) = cpu.eax;
    // 0047527f  40                     -inc eax
    (cpu.eax)++;
    // 00475280  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475283  83f809                 +cmp eax, 9
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
    // 00475286  7cf1                   -jl 0x475279
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475279;
    }
    // 00475288  0fb63d0e0d5100         -movzx edi, byte ptr [0x510d0e]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5311758) /* 0x510d0e */));
    // 0047528f  8b3538384d00           -mov esi, dword ptr [0x4d3838]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5060664) /* 0x4d3838 */);
    // 00475295  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475297  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475299  8a1dcf0b5100           -mov bl, byte ptr [0x510bcf]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5311439) /* 0x510bcf */);
    // 0047529f  8915cc744d00           -mov dword ptr [0x4d74cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */) = cpu.edx;
    // 004752a5  8a15110d5100           -mov dl, byte ptr [0x510d11]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5311761) /* 0x510d11 */);
    // 004752ab  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004752ad  7509                   -jne 0x4752b8
    if (!cpu.flags.zf)
    {
        goto L_0x004752b8;
    }
    // 004752af  833d3c384d0000         +cmp dword ptr [0x4d383c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004752b6  7458                   -je 0x475310
    if (cpu.flags.zf)
    {
        goto L_0x00475310;
    }
L_0x004752b8:
    // 004752b8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004752bd  e8ea190100             -call 0x486cac
    cpu.esp -= 4;
    sub_486cac(app, cpu);
    if (cpu.terminate) return;
    // 004752c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004752c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004752c6  7557                   -jne 0x47531f
    if (!cpu.flags.zf)
    {
        goto L_0x0047531f;
    }
    // 004752c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004752ca  7553                   -jne 0x47531f
    if (!cpu.flags.zf)
    {
        goto L_0x0047531f;
    }
    // 004752cc  81e608080000           -and esi, 0x808
    cpu.esi &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 004752d2  81fe08080000           +cmp esi, 0x808
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004752d8  743c                   -je 0x475316
    if (cpu.flags.zf)
    {
        goto L_0x00475316;
    }
L_0x004752da:
    // 004752da  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004752df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004752e1:
    // 004752e1  e88a590200             -call 0x49ac70
    cpu.esp -= 4;
    sub_49ac70(app, cpu);
    if (cpu.terminate) return;
    // 004752e6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004752e8:
    // 004752e8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004752ea  0f8c8a000000           -jl 0x47537a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047537a;
    }
    // 004752f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004752f2  0f849c000000           -je 0x475394
    if (cpu.flags.zf)
    {
        goto L_0x00475394;
    }
    // 004752f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004752fa:
    // 004752fa  e8091a0100             -call 0x486d08
    cpu.esp -= 4;
    sub_486d08(app, cpu);
    if (cpu.terminate) return;
    // 004752ff  e83cb3fcff             -call 0x440640
    cpu.esp -= 4;
    sub_440640(app, cpu);
    if (cpu.terminate) return;
    // 00475304  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00475306  a3d0744d00             -mov dword ptr [0x4d74d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5076176) /* 0x4d74d0 */) = cpu.eax;
    // 0047530b  a3cc744d00             -mov dword ptr [0x4d74cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */) = cpu.eax;
L_0x00475310:
    // 00475310  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475311  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475312  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475314  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475316:
    // 00475316  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047531b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047531d  ebc2                   -jmp 0x4752e1
    goto L_0x004752e1;
L_0x0047531f:
    // 0047531f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475321  7518                   -jne 0x47533b
    if (!cpu.flags.zf)
    {
        goto L_0x0047533b;
    }
    // 00475323  83fb01                 +cmp ebx, 1
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
    // 00475326  7513                   -jne 0x47533b
    if (!cpu.flags.zf)
    {
        goto L_0x0047533b;
    }
    // 00475328  2504080000             -and eax, 0x804
    cpu.eax &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 0047532d  3d04080000             +cmp eax, 0x804
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475332  75a6                   -jne 0x4752da
    if (!cpu.flags.zf)
    {
        goto L_0x004752da;
    }
    // 00475334  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00475339  eba6                   -jmp 0x4752e1
    goto L_0x004752e1;
L_0x0047533b:
    // 0047533b  83fa01                 +cmp edx, 1
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
    // 0047533e  7517                   -jne 0x475357
    if (!cpu.flags.zf)
    {
        goto L_0x00475357;
    }
    // 00475340  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475342  7513                   -jne 0x475357
    if (!cpu.flags.zf)
    {
        goto L_0x00475357;
    }
    // 00475344  2502080000             -and eax, 0x802
    cpu.eax &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00475349  3d02080000             +cmp eax, 0x802
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047534e  758a                   -jne 0x4752da
    if (!cpu.flags.zf)
    {
        goto L_0x004752da;
    }
    // 00475350  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00475355  eb8a                   -jmp 0x4752e1
    goto L_0x004752e1;
L_0x00475357:
    // 00475357  83fa01                 +cmp edx, 1
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
    // 0047535a  758c                   -jne 0x4752e8
    if (!cpu.flags.zf)
    {
        goto L_0x004752e8;
    }
    // 0047535c  39d3                   +cmp ebx, edx
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
    // 0047535e  7588                   -jne 0x4752e8
    if (!cpu.flags.zf)
    {
        goto L_0x004752e8;
    }
    // 00475360  2501080000             -and eax, 0x801
    cpu.eax &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00475365  3d01080000             +cmp eax, 0x801
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047536a  0f856affffff           -jne 0x4752da
    if (!cpu.flags.zf)
    {
        goto L_0x004752da;
    }
    // 00475370  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00475375  e967ffffff             -jmp 0x4752e1
    goto L_0x004752e1;
L_0x0047537a:
    // 0047537a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047537c  890d3c384d00           -mov dword ptr [0x4d383c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5060668) /* 0x4d383c */) = cpu.ecx;
    // 00475382  890d58384d00           -mov dword ptr [0x4d3858], ecx
    app->getMemory<x86::reg32>(x86::reg32(5060696) /* 0x4d3858 */) = cpu.ecx;
    // 00475388  890d38384d00           -mov dword ptr [0x4d3838], ecx
    app->getMemory<x86::reg32>(x86::reg32(5060664) /* 0x4d3838 */) = cpu.ecx;
    // 0047538e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047538f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475390  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475391  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475392  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475393  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475394:
    // 00475394  b8ceffffff             -mov eax, 0xffffffce
    cpu.eax = 4294967246 /*0xffffffce*/;
    // 00475399  e95cffffff             -jmp 0x4752fa
    goto L_0x004752fa;
}

/* align: skip 0x00 0x00 */
void Application::sub_4753a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004753a0);
    // 004753a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004753a1  8b15c8754d00           -mov edx, dword ptr [0x4d75c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 004753a7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004753a9  7502                   -jne 0x4753ad
    if (!cpu.flags.zf)
    {
        goto L_0x004753ad;
    }
    // 004753ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004753ad:
    // 004753ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004753ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004753b0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004753b2  e8b5d90000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004753b7  890dc8754d00           -mov dword ptr [0x4d75c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */) = cpu.ecx;
    // 004753bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4753c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004753c0);
    // 004753c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004753c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004753c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004753c4  8b0dc8754d00           -mov ecx, dword ptr [0x4d75c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 004753ca  8915cc754d00           -mov dword ptr [0x4d75cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */) = cpu.edx;
    // 004753d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004753d2  7403                   -je 0x4753d7
    if (cpu.flags.zf)
    {
        goto L_0x004753d7;
    }
    // 004753d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004753d7:
    // 004753d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004753d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004753d9  bb28c44c00             -mov ebx, 0x4cc428
    cpu.ebx = 5030952 /*0x4cc428*/;
    // 004753de  beec020000             -mov esi, 0x2ec
    cpu.esi = 748 /*0x2ec*/;
    // 004753e3  ba20480100             -mov edx, 0x14820
    cpu.edx = 84000 /*0x14820*/;
    // 004753e8  b844c44c00             -mov eax, 0x4cc444
    cpu.eax = 5030980 /*0x4cc444*/;
    // 004753ed  891df48f4d00           -mov dword ptr [0x4d8ff4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebx;
    // 004753f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004753f5  8935f88f4d00           -mov dword ptr [0x4d8ff8], esi
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.esi;
    // 004753fb  e820d50000             -call 0x482920
    cpu.esp -= 4;
    sub_482920(app, cpu);
    if (cpu.terminate) return;
    // 00475400  a3c8754d00             -mov dword ptr [0x4d75c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */) = cpu.eax;
    // 00475405  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475406  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475407  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475408  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475409  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475410);
    // 00475410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475412  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475413  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475414  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475415  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00475418  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 0047541c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047541e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00475420  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00475423  8b048558f95000         -mov eax, dword ptr [eax*4 + 0x50f958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5306712) /* 0x50f958 */ + cpu.eax * 4);
    // 0047542a  898210060000           -mov dword ptr [edx + 0x610], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1552) /* 0x610 */) = cpu.eax;
    // 00475430  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00475434  898288000000           -mov dword ptr [edx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0047543a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047543c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047543f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00475446  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00475448  8b9e1c020000           -mov ebx, dword ptr [esi + 0x21c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(540) /* 0x21c */);
    // 0047544e  8b048598f75000         -mov eax, dword ptr [eax*4 + 0x50f798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5306264) /* 0x50f798 */ + cpu.eax * 4);
    // 00475455  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475457  898614060000           -mov dword ptr [esi + 0x614], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 0047545d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047545f  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00475462  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475464  e837040000             -call 0x4758a0
    cpu.esp -= 4;
    sub_4758a0(app, cpu);
    if (cpu.terminate) return;
    // 00475469  a1cc754d00             -mov eax, dword ptr [0x4d75cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */);
    // 0047546e  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00475472  898618060000           -mov dword ptr [esi + 0x618], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00475478  894c2450               -mov dword ptr [esp + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 0047547c  898284000000           -mov dword ptr [edx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00475482  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00475487  89861c060000           -mov dword ptr [esi + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 0047548d  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00475491  8915d4754d00           -mov dword ptr [0x4d75d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5076436) /* 0x4d75d4 */) = cpu.edx;
    // 00475497  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
L_0x0047549b:
    // 0047549b  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0047549f  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004754a2  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004754a6  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004754a9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004754ac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004754ae  7533                   -jne 0x4754e3
    if (!cpu.flags.zf)
    {
        goto L_0x004754e3;
    }
L_0x004754b0:
    // 004754b0  8b7c2450               -mov edi, dword ptr [esp + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004754b4  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004754b8  47                     -inc edi
    (cpu.edi)++;
    // 004754b9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004754bc  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 004754c0  895c2454               -mov dword ptr [esp + 0x54], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.ebx;
    // 004754c4  83ff20                 +cmp edi, 0x20
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
    // 004754c7  7cd2                   -jl 0x47549b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047549b;
    }
    // 004754c9  e842800000             -call 0x47d510
    cpu.esp -= 4;
    sub_47d510(app, cpu);
    if (cpu.terminate) return;
    // 004754ce  a31c804d00             -mov dword ptr [0x4d801c], eax
    app->getMemory<x86::reg32>(x86::reg32(5079068) /* 0x4d801c */) = cpu.eax;
    // 004754d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004754d5  a3d4754d00             -mov dword ptr [0x4d75d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5076436) /* 0x4d75d4 */) = cpu.eax;
    // 004754da  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004754dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004754de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004754df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004754e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004754e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004754e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004754e3:
    // 004754e3  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004754e7  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004754eb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004754ed  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 004754f1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004754f3  897c244c               -mov dword ptr [esp + 0x4c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edi;
    // 004754f7  897c2460               -mov dword ptr [esp + 0x60], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edi;
L_0x004754fb:
    // 004754fb  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004754ff  03442458               -add eax, dword ptr [esp + 0x58]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
    // 00475503  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475506  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047550a  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 0047550d  7da1                   -jge 0x4754b0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004754b0;
    }
    // 0047550f  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00475513  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00475516  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00475518  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047551a  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 0047551d  0f843b010000           -je 0x47565e
    if (cpu.flags.zf)
    {
        goto L_0x0047565e;
    }
    // 00475523  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00475525  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047552a  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0047552d  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
L_0x00475531:
    // 00475531  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475533  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00475537  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0047553b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047553d  0f8e02010000           -jle 0x475645
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475645;
    }
    // 00475543  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00475547  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00475549  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
L_0x0047554d:
    // 0047554d  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00475550  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00475553  8a440708               -mov al, byte ptr [edi + eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 00475557  88442438               -mov byte ptr [esp + 0x38], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 0047555b  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047555e  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00475561  8a440709               -mov al, byte ptr [edi + eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */ + cpu.eax * 1);
    // 00475565  88442439               -mov byte ptr [esp + 0x39], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 00475569  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047556c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047556f  8a44070a               -mov al, byte ptr [edi + eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */ + cpu.eax * 1);
    // 00475573  8844243a               -mov byte ptr [esp + 0x3a], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(58) /* 0x3a */) = cpu.al;
    // 00475577  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047557a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047557d  8a44070b               -mov al, byte ptr [edi + eax + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */ + cpu.eax * 1);
    // 00475581  8a5c2439               -mov bl, byte ptr [esp + 0x39]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(57) /* 0x39 */);
    // 00475585  8844243b               -mov byte ptr [esp + 0x3b], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(59) /* 0x3b */) = cpu.al;
    // 00475589  8a442448               -mov al, byte ptr [esp + 0x48]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047558d  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0047558f  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 00475591  8874243c               -mov byte ptr [esp + 0x3c], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.dh;
    // 00475595  885c2439               -mov byte ptr [esp + 0x39], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(57) /* 0x39 */) = cpu.bl;
    // 00475599  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047559c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047559f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004755a1  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004755a3  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004755a6  0f84ec000000           -je 0x475698
    if (cpu.flags.zf)
    {
        goto L_0x00475698;
    }
    // 004755ac  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 004755af  0f84b6000000           -je 0x47566b
    if (cpu.flags.zf)
    {
        goto L_0x0047566b;
    }
    // 004755b5  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004755b7  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004755bb  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 004755c1  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 004755c7  e804e2fbff             -call 0x4337d0
    cpu.esp -= 4;
    sub_4337d0(app, cpu);
    if (cpu.terminate) return;
    // 004755cc  6b1dcc754d001c         -imul ebx, dword ptr [0x4d75cc], 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004755d3  a1c8754d00             -mov eax, dword ptr [0x4d75c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 004755d8  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x004755dd:
    // 004755dd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004755df  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004755e1:
    // 004755e1  e82ee0fbff             -call 0x433614
    cpu.esp -= 4;
    sub_433614(app, cpu);
    if (cpu.terminate) return;
    // 004755e6  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004755ea  66a1cc754d00           -mov ax, word ptr [0x4d75cc]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5076428) /* 0x4d75cc */);
    // 004755f0  668b9a84000000         -mov bx, word ptr [edx + 0x84]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 004755f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004755f9  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 004755fd  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00475601  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475603  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475606  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475608  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047560c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047560f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475611  66895002               -mov word ptr [eax + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00475615  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00475619  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047561c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047561f  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00475623  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475625  42                     -inc edx
    (cpu.edx)++;
    // 00475626  c6400100               -mov byte ptr [eax + 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 0047562a  a1cc754d00             -mov eax, dword ptr [0x4d75cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */);
    // 0047562f  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 00475633  40                     -inc eax
    (cpu.eax)++;
    // 00475634  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00475638  a3cc754d00             -mov dword ptr [0x4d75cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */) = cpu.eax;
    // 0047563d  39ca                   +cmp edx, ecx
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
    // 0047563f  0f8c08ffffff           -jl 0x47554d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047554d;
    }
L_0x00475645:
    // 00475645  8b7c2460               -mov edi, dword ptr [esp + 0x60]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00475649  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047564d  47                     -inc edi
    (cpu.edi)++;
    // 0047564e  83c30c                 +add ebx, 0xc
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00475651  897c2460               -mov dword ptr [esp + 0x60], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edi;
    // 00475655  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00475659  e99dfeffff             -jmp 0x4754fb
    goto L_0x004754fb;
L_0x0047565e:
    // 0047565e  c744246401000000       -mov dword ptr [esp + 0x64], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = 1 /*0x1*/;
    // 00475666  e9c6feffff             -jmp 0x475531
    goto L_0x00475531;
L_0x0047566b:
    // 0047566b  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0047566d  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00475671  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00475677  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 0047567d  e84ee1fbff             -call 0x4337d0
    cpu.esp -= 4;
    sub_4337d0(app, cpu);
    if (cpu.terminate) return;
    // 00475682  6b1dcc754d001c         +imul ebx, dword ptr [0x4d75cc], 0x1c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00475689  a1c8754d00             -mov eax, dword ptr [0x4d75c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 0047568e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00475693  e945ffffff             -jmp 0x4755dd
    goto L_0x004755dd;
L_0x00475698:
    // 00475698  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0047569a  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047569e  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 004756a4  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 004756aa  e821e1fbff             -call 0x4337d0
    cpu.esp -= 4;
    sub_4337d0(app, cpu);
    if (cpu.terminate) return;
    // 004756af  8d5c241c               -lea ebx, [esp + 0x1c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004756b3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004756b8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004756ba  e855dffbff             -call 0x433614
    cpu.esp -= 4;
    sub_433614(app, cpu);
    if (cpu.terminate) return;
    // 004756bf  6b1dcc754d001c         -imul ebx, dword ptr [0x4d75cc], 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004756c6  a1c8754d00             -mov eax, dword ptr [0x4d75c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 004756cb  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004756d0  01c3                   +add ebx, eax
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
    // 004756d2  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004756d6  e906ffffff             -jmp 0x4755e1
    goto L_0x004755e1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4756e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004756e0);
    // 004756e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004756e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004756e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004756e3  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004756e6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004756ea  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004756ee  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004756f0  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004756f2  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004756f5  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004756fc  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 00475703  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475705  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475709  8b848698f75000         -mov eax, dword ptr [esi + eax*4 + 0x50f798]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5306264) /* 0x50f798 */ + cpu.eax * 4);
    // 00475710  898314060000           -mov dword ptr [ebx + 0x614], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00475716  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047571a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047571c  e87f010000             -call 0x4758a0
    cpu.esp -= 4;
    sub_4758a0(app, cpu);
    if (cpu.terminate) return;
    // 00475721  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475725  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00475727  a1cc754d00             -mov eax, dword ptr [0x4d75cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */);
    // 0047572c  89861c060000           -mov dword ptr [esi + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 00475732  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475734  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 0047573a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047573e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00475742  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00475746:
    // 00475746  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047574a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047574d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475751  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00475754  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00475757  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475759  7534                   -jne 0x47578f
    if (!cpu.flags.zf)
    {
        goto L_0x0047578f;
    }
L_0x0047575b:
    // 0047575b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047575f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475763  42                     -inc edx
    (cpu.edx)++;
    // 00475764  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475767  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047576b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047576f  83fa20                 +cmp edx, 0x20
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
    // 00475772  7cd2                   -jl 0x475746
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00475746;
    }
    // 00475774  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475778  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047577c  8b801c060000           -mov eax, dword ptr [eax + 0x61c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1564) /* 0x61c */);
    // 00475782  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00475788  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047578b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047578c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047578d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047578e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047578f:
    // 0047578f  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475793  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00475795  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00475799  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0047579c  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x004757a0:
    // 004757a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004757a4  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004757a8  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004757ab  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004757af  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004757b2  7da7                   -jge 0x47575b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047575b;
    }
    // 004757b4  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004757b7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004757ba  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004757bc  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004757be  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 004757c1  0f84c5000000           -je 0x47588c
    if (cpu.flags.zf)
    {
        goto L_0x0047588c;
    }
    // 004757c7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004757c9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004757ce  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 004757d1  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004757d5:
    // 004757d5  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004757d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004757db  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004757dd  0f8e92000000           -jle 0x475875
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00475875;
    }
    // 004757e3  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004757e6  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004757ea:
    // 004757ea  6b15cc754d001c         -imul edx, dword ptr [0x4d75cc], 0x1c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004757f1  a1c8754d00             -mov eax, dword ptr [0x4d75c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 004757f6  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004757f9  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004757fd  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00475800  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475804  8b5b18                 -mov ebx, dword ptr [ebx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00475807  8b9214060000           -mov edx, dword ptr [edx + 0x614]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1556) /* 0x614 */);
    // 0047580d  668b5c1e02             -mov bx, word ptr [esi + ebx + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.ebx * 1);
    // 00475812  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00475818  039d84000000           -add ebx, dword ptr [ebp + 0x84]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(132) /* 0x84 */)));
    // 0047581e  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00475820  6bdb1c                 -imul ebx, ebx, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00475823  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00475825  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475829  e882dffbff             -call 0x4337b0
    cpu.esp -= 4;
    sub_4337b0(app, cpu);
    if (cpu.terminate) return;
    // 0047582e  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475832  66a1cc754d00           -mov ax, word ptr [0x4d75cc]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5076428) /* 0x4d75cc */);
    // 00475838  668b9a18060000         -mov bx, word ptr [edx + 0x618]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(1560) /* 0x618 */);
    // 0047583f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475841  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00475844  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475846  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00475849  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047584b  6689540602             -mov word ptr [esi + eax + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = cpu.dx;
    // 00475850  8b15cc754d00           -mov edx, dword ptr [0x4d75cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */);
    // 00475856  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00475859  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047585d  42                     -inc edx
    (cpu.edx)++;
    // 0047585e  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00475861  41                     -inc ecx
    (cpu.ecx)++;
    // 00475862  8915cc754d00           -mov dword ptr [0x4d75cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5076428) /* 0x4d75cc */) = cpu.edx;
    // 00475868  c644060100             -mov byte ptr [esi + eax + 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 0047586d  39d9                   +cmp ecx, ebx
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
    // 0047586f  0f8c75ffffff           -jl 0x4757ea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004757ea;
    }
L_0x00475875:
    // 00475875  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475879  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0047587c  45                     -inc ebp
    (cpu.ebp)++;
    // 0047587d  83c60c                 +add esi, 0xc
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
    // 00475880  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00475884  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00475887  e914ffffff             -jmp 0x4757a0
    goto L_0x004757a0;
L_0x0047588c:
    // 0047588c  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00475894  e93cffffff             -jmp 0x4757d5
    goto L_0x004757d5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4758a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004758a0);
    // 004758a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004758a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004758a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004758a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004758a4  81ec10030000           -sub esp, 0x310
    (cpu.esp) -= x86::reg32(x86::sreg32(784 /*0x310*/));
    // 004758aa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004758ac  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004758ae  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004758b0  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004758b3  8b048558f95000         -mov eax, dword ptr [eax*4 + 0x50f958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5306712) /* 0x50f958 */ + cpu.eax * 4);
    // 004758ba  8b0dd0754d00           -mov ecx, dword ptr [0x4d75d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076432) /* 0x4d75d0 */);
    // 004758c0  898610060000           -mov dword ptr [esi + 0x610], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */) = cpu.eax;
    // 004758c6  83f940                 +cmp ecx, 0x40
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004758c9  7c08                   -jl 0x4758d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004758d3;
    }
    // 004758cb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004758cd  891dd0754d00           -mov dword ptr [0x4d75d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5076432) /* 0x4d75d0 */) = cpu.ebx;
L_0x004758d3:
    // 004758d3  8b2dd0754d00           -mov ebp, dword ptr [0x4d75d0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5076432) /* 0x4d75d0 */);
    // 004758d9  a1d0754d00             -mov eax, dword ptr [0x4d75d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076432) /* 0x4d75d0 */);
    // 004758de  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004758e0  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 004758e3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004758e5  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004758e8  898614060000           -mov dword ptr [esi + 0x614], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 004758ee  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004758f5  81c514375400           -add ebp, 0x543714
    (cpu.ebp) += x86::reg32(x86::sreg32(5519124 /*0x543714*/));
    // 004758fb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004758fd  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00475900  892d1c804d00           -mov dword ptr [0x4d801c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5079068) /* 0x4d801c */) = cpu.ebp;
    // 00475906  899c8298f75000         -mov dword ptr [edx + eax*4 + 0x50f798], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5306264) /* 0x50f798 */ + cpu.eax * 4) = cpu.ebx;
    // 0047590d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047590f  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 00475914  42                     -inc edx
    (cpu.edx)++;
    // 00475915  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 0047591b  8915d0754d00           -mov dword ptr [0x4d75d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5076432) /* 0x4d75d0 */) = cpu.edx;
    // 00475921  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00475923  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00475925  e8067d0000             -call 0x47d630
    cpu.esp -= 4;
    sub_47d630(app, cpu);
    if (cpu.terminate) return;
    // 0047592a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047592f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00475931  e80a10feff             -call 0x456940
    cpu.esp -= 4;
    sub_456940(app, cpu);
    if (cpu.terminate) return;
    // 00475936  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0047593d  8d8c240c030000         -lea ecx, [esp + 0x30c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00475944  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475945  8b861c020000           -mov eax, dword ptr [esi + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(540) /* 0x21c */);
    // 0047594b  8d9c240c030000         -lea ebx, [esp + 0x30c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00475952  8d942408030000         -lea edx, [esp + 0x308]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 00475959  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047595c  e81f12feff             -call 0x456b80
    cpu.esp -= 4;
    sub_456b80(app, cpu);
    if (cpu.terminate) return;
    // 00475961  8b8c2404030000         -mov ecx, dword ptr [esp + 0x304]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00475968  8b2d1c804d00           -mov ebp, dword ptr [0x4d801c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5079068) /* 0x4d801c */);
    // 0047596e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475970  0f8496000000           -je 0x475a0c
    if (cpu.flags.zf)
    {
        goto L_0x00475a0c;
    }
L_0x00475976:
    // 00475976  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00475978  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
L_0x0047597a:
    // 0047597a  8a3c34                 -mov bh, byte ptr [esp + esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1);
    // 0047597d  38f8                   +cmp al, bh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047597f  7507                   -jne 0x475988
    if (!cpu.flags.zf)
    {
        goto L_0x00475988;
    }
    // 00475981  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 00475983  fec1                   -inc cl
    (cpu.cl)++;
    // 00475985  880c34                 -mov byte ptr [esp + esi], cl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.cl;
L_0x00475988:
    // 00475988  8a6c3401               -mov ch, byte ptr [esp + esi + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1);
    // 0047598c  38e8                   +cmp al, ch
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047598e  7508                   -jne 0x475998
    if (!cpu.flags.zf)
    {
        goto L_0x00475998;
    }
    // 00475990  88ec                   -mov ah, ch
    cpu.ah = cpu.ch;
    // 00475992  fec4                   -inc ah
    (cpu.ah)++;
    // 00475994  88643401               -mov byte ptr [esp + esi + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1) = cpu.ah;
L_0x00475998:
    // 00475998  8a543402               -mov dl, byte ptr [esp + esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1);
    // 0047599c  38d0                   +cmp al, dl
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
    // 0047599e  7508                   -jne 0x4759a8
    if (!cpu.flags.zf)
    {
        goto L_0x004759a8;
    }
    // 004759a0  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004759a2  fec6                   -inc dh
    (cpu.dh)++;
    // 004759a4  88743402               -mov byte ptr [esp + esi + 2], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.dh;
L_0x004759a8:
    // 004759a8  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004759ab  81fefd020000           +cmp esi, 0x2fd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(765 /*0x2fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004759b1  7cc7                   -jl 0x47597a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047597a;
    }
L_0x004759b3:
    // 004759b3  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004759b5  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 004759b8  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004759ba  885c3401               -mov byte ptr [esp + esi + 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1) = cpu.bl;
    // 004759be  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004759c0  885c3402               -mov byte ptr [esp + esi + 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.bl;
    // 004759c4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004759c6:
    // 004759c6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004759c8  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004759cf  c6440203ff             -mov byte ptr [edx + eax + 3], 0xff
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */ + cpu.eax * 1) = 255 /*0xff*/;
    // 004759d4  8d1476                 -lea edx, [esi + esi*2]
    cpu.edx = x86::reg32(cpu.esi + cpu.esi * 2);
L_0x004759d7:
    // 004759d7  8d0c28                 -lea ecx, [eax + ebp]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004759da  8a1c14                 -mov bl, byte ptr [esp + edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 004759dd  885902                 -mov byte ptr [ecx + 2], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004759e0  8a5c1401               -mov bl, byte ptr [esp + edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 004759e4  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004759e7  885901                 -mov byte ptr [ecx + 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004759ea  46                     -inc esi
    (cpu.esi)++;
    // 004759eb  8a5c14ff               -mov bl, byte ptr [esp + edx - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1);
    // 004759ef  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004759f2  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 004759f4  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004759f9  0f8d69000000           -jge 0x475a68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00475a68;
    }
    // 004759ff  3dfc030000             +cmp eax, 0x3fc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1020 /*0x3fc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a04  75c0                   -jne 0x4759c6
    if (!cpu.flags.zf)
    {
        goto L_0x004759c6;
    }
    // 00475a06  887c0703               -mov byte ptr [edi + eax + 3], bh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */ + cpu.eax * 1) = cpu.bh;
    // 00475a0a  ebcb                   -jmp 0x4759d7
    goto L_0x004759d7;
L_0x00475a0c:
    // 00475a0c  83bc240803000000       +cmp dword ptr [esp + 0x308], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a14  0f855cffffff           -jne 0x475976
    if (!cpu.flags.zf)
    {
        goto L_0x00475976;
    }
    // 00475a1a  8bb4240c030000         -mov esi, dword ptr [esp + 0x30c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 00475a21  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00475a23  0f854dffffff           -jne 0x475976
    if (!cpu.flags.zf)
    {
        goto L_0x00475976;
    }
    // 00475a29  83bc240003000000       +cmp dword ptr [esp + 0x300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a31  0f853fffffff           -jne 0x475976
    if (!cpu.flags.zf)
    {
        goto L_0x00475976;
    }
    // 00475a37  b050                   -mov al, 0x50
    cpu.al = 80 /*0x50*/;
    // 00475a39  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
L_0x00475a3b:
    // 00475a3b  3a0434                 +cmp al, byte ptr [esp + esi]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475a3e  7603                   -jbe 0x475a43
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475a43;
    }
    // 00475a40  882434                 -mov byte ptr [esp + esi], ah
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.ah;
L_0x00475a43:
    // 00475a43  3a443401               +cmp al, byte ptr [esp + esi + 1]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475a47  7604                   -jbe 0x475a4d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475a4d;
    }
    // 00475a49  88643401               -mov byte ptr [esp + esi + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.esi * 1) = cpu.ah;
L_0x00475a4d:
    // 00475a4d  3a443402               +cmp al, byte ptr [esp + esi + 2]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475a51  7604                   -jbe 0x475a57
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475a57;
    }
    // 00475a53  88643402               -mov byte ptr [esp + esi + 2], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.esi * 1) = cpu.ah;
L_0x00475a57:
    // 00475a57  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00475a5a  81fefd020000           +cmp esi, 0x2fd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(765 /*0x2fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a60  0f8d4dffffff           -jge 0x4759b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004759b3;
    }
    // 00475a66  ebd3                   -jmp 0x475a3b
    goto L_0x00475a3b;
L_0x00475a68:
    // 00475a68  892d1c804d00           -mov dword ptr [0x4d801c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5079068) /* 0x4d801c */) = cpu.ebp;
    // 00475a6e  81c410030000           -add esp, 0x310
    (cpu.esp) += x86::reg32(x86::sreg32(784 /*0x310*/));
    // 00475a74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475a78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: ffffffff0000000000000000ffffffff010000000000000000000000010000000000000000000000ffffffff0000000000000000ffffffff010000000000000000000000010000000000000000000000 */
void Application::sub_475ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475ad0);
    // 00475ad0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475ad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475ad2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475ad5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475ad7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475ad9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475adb  e87088ffff             -call 0x46e350
    cpu.esp -= 4;
    sub_46e350(app, cpu);
    if (cpu.terminate) return;
    // 00475ae0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475ae2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475ae3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475ae4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475ae6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00475ae9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475aea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475aeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_475af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475af0);
    // 00475af0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475af1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475af2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475af5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00475af7  8a25e8525500           -mov ah, byte ptr [0x5552e8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5591784) /* 0x5552e8 */);
    // 00475afd  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00475aff  754b                   -jne 0x475b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00475b4c;
    }
    // 00475b01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475b02  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475b03  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00475b08  bedc525500             -mov esi, 0x5552dc
    cpu.esi = 5591772 /*0x5552dc*/;
    // 00475b0d  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475b11  a2e4525500             -mov byte ptr [0x5552e4], al
    app->getMemory<x86::reg8>(x86::reg32(5591780) /* 0x5552e4 */) = cpu.al;
    // 00475b16  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475b18  891de0525500           -mov dword ptr [0x5552e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5591776) /* 0x5552e0 */) = cpu.ebx;
    // 00475b1e  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00475b22  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00475b26  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475b2a  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 00475b2c  890ddc525500           -mov dword ptr [0x5552dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5591772) /* 0x5552dc */) = cpu.ecx;
    // 00475b32  fec3                   -inc bl
    (cpu.bl)++;
    // 00475b34  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475b35  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475b36  881de8525500           -mov byte ptr [0x5552e8], bl
    app->getMemory<x86::reg8>(x86::reg32(5591784) /* 0x5552e8 */) = cpu.bl;
    // 00475b3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b3e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475b40  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475b42  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475b43  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475b44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475b46  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475b49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475b4c:
    // 00475b4c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475b4e  e8fd87ffff             -call 0x46e350
    cpu.esp -= 4;
    sub_46e350(app, cpu);
    if (cpu.terminate) return;
    // 00475b53  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00475b55  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00475b57  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475b58  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00475b59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475b5b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475b5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475b70);
    // 00475b70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475b71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475b73  e8383cfdff             -call 0x4497b0
    cpu.esp -= 4;
    sub_4497b0(app, cpu);
    if (cpu.terminate) return;
    // 00475b78  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00475b7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475b7c  e8ef3ffdff             -call 0x449b70
    cpu.esp -= 4;
    sub_449b70(app, cpu);
    if (cpu.terminate) return;
    // 00475b81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475b83  7517                   -jne 0x475b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00475b9c;
    }
    // 00475b85  80bade02000000         +cmp byte ptr [edx + 0x2de], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(734) /* 0x2de */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475b8c  750e                   -jne 0x475b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00475b9c;
    }
    // 00475b8e  a12cfe5000             -mov eax, dword ptr [0x50fe2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307948) /* 0x50fe2c */);
    // 00475b93  8b048588764d00         -mov eax, dword ptr [eax*4 + 0x4d7688]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076616) /* 0x4d7688 */ + cpu.eax * 4);
    // 00475b9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475b9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475b9c:
    // 00475b9c  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 00475ba1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475ba2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475bb0);
    // 00475bb0  a12cfe5000             -mov eax, dword ptr [0x50fe2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307948) /* 0x50fe2c */);
    // 00475bb5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00475bb8  0528764d00             -add eax, 0x4d7628
    (cpu.eax) += x86::reg32(x86::sreg32(5076520 /*0x4d7628*/));
    // 00475bbd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_475bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475bc0);
    // 00475bc0  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00475bc6  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00475bcc  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00475bd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475be0);
    // 00475be0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475be1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475be3  8915d0525500           -mov dword ptr [0x5552d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5591760) /* 0x5552d0 */) = cpu.edx;
    // 00475be9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475bea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475bf0);
    // 00475bf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475c00);
    // 00475c00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475c10);
    // 00475c10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475c20);
    // 00475c20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475c30);
    // 00475c30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00475c50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475c52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00475c60);
    // 00475c60  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00475c65  0f8555000000           -jne 0x475cc0
    if (!cpu.flags.zf)
    {
        goto L_0x00475cc0;
    }
    // 00475c6b  f6053857550020         +test byte ptr [0x555738], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5592888) /* 0x555738 */) & 32 /*0x20*/));
    // 00475c72  7546                   -jne 0x475cba
    if (!cpu.flags.zf)
    {
        goto L_0x00475cba;
    }
L_0x00475c74:
    // 00475c74  83f84b                 +cmp eax, 0x4b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(75 /*0x4b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c77  7509                   -jne 0x475c82
    if (!cpu.flags.zf)
    {
        goto L_0x00475c82;
    }
    // 00475c79  f6053857550004         +test byte ptr [0x555738], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5592888) /* 0x555738 */) & 4 /*0x4*/));
    // 00475c80  7538                   -jne 0x475cba
    if (!cpu.flags.zf)
    {
        goto L_0x00475cba;
    }
L_0x00475c82:
    // 00475c82  83f84d                 +cmp eax, 0x4d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(77 /*0x4d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c85  7509                   -jne 0x475c90
    if (!cpu.flags.zf)
    {
        goto L_0x00475c90;
    }
    // 00475c87  f6053857550008         +test byte ptr [0x555738], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5592888) /* 0x555738 */) & 8 /*0x8*/));
    // 00475c8e  752a                   -jne 0x475cba
    if (!cpu.flags.zf)
    {
        goto L_0x00475cba;
    }
L_0x00475c90:
    // 00475c90  83f848                 +cmp eax, 0x48
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c93  7509                   -jne 0x475c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00475c9e;
    }
    // 00475c95  f6053857550001         +test byte ptr [0x555738], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5592888) /* 0x555738 */) & 1 /*0x1*/));
    // 00475c9c  751c                   -jne 0x475cba
    if (!cpu.flags.zf)
    {
        goto L_0x00475cba;
    }
L_0x00475c9e:
    // 00475c9e  83f850                 +cmp eax, 0x50
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
    // 00475ca1  7509                   -jne 0x475cac
    if (!cpu.flags.zf)
    {
        goto L_0x00475cac;
    }
    // 00475ca3  f6053857550002         +test byte ptr [0x555738], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5592888) /* 0x555738 */) & 2 /*0x2*/));
    // 00475caa  750e                   -jne 0x475cba
    if (!cpu.flags.zf)
    {
        goto L_0x00475cba;
    }
L_0x00475cac:
    // 00475cac  83f81c                 +cmp eax, 0x1c
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
    // 00475caf  751a                   -jne 0x475ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00475ccb;
    }
    // 00475cb1  f6053857550010         +test byte ptr [0x555738], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5592888) /* 0x555738 */) & 16 /*0x10*/));
    // 00475cb8  7411                   -je 0x475ccb
    if (cpu.flags.zf)
    {
        goto L_0x00475ccb;
    }
L_0x00475cba:
    // 00475cba  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00475cbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475cc0:
    // 00475cc0  80b810914d0000         +cmp byte ptr [eax + 0x4d9110], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5083408) /* 0x4d9110 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475cc7  74ab                   -je 0x475c74
    if (cpu.flags.zf)
    {
        goto L_0x00475c74;
    }
    // 00475cc9  ebef                   -jmp 0x475cba
    goto L_0x00475cba;
L_0x00475ccb:
    // 00475ccb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475ccd  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
