#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c760  803dce11510003         +cmp byte ptr [0x5111ce], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c767  0f8594000000           -jne 0x47c801
    if (!cpu.flags.zf)
    {
        goto L_0x0047c801;
    }
    // 0047c76d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c76e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c76f  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047c777  7456                   -je 0x47c7cf
    if (cpu.flags.zf)
    {
        goto L_0x0047c7cf;
    }
    // 0047c779  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047c77b:
    // 0047c77b  83ba800e510000         +cmp dword ptr [edx + 0x510e80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5312128) /* 0x510e80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c782  740c                   -je 0x47c790
    if (cpu.flags.zf)
    {
        goto L_0x0047c790;
    }
    // 0047c784  b8700e5100             -mov eax, 0x510e70
    cpu.eax = 5312112 /*0x510e70*/;
    // 0047c789  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c78b  e840020000             -call 0x47c9d0
    cpu.esp -= 4;
    sub_47c9d0(app, cpu);
    if (cpu.terminate) return;
L_0x0047c790:
    // 0047c790  83c268                 -add edx, 0x68
    (cpu.edx) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0047c793  81fad8020000           +cmp edx, 0x2d8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(728 /*0x2d8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c799  75e0                   -jne 0x47c77b
    if (!cpu.flags.zf)
    {
        goto L_0x0047c77b;
    }
    // 0047c79b  833df47f4d0000         +cmp dword ptr [0x4d7ff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c7a2  742b                   -je 0x47c7cf
    if (cpu.flags.zf)
    {
        goto L_0x0047c7cf;
    }
    // 0047c7a4  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047c7aa  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047c7b1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c7b3  8b15e47f4d00           -mov edx, dword ptr [0x4d7fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047c7b9  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c7be  740f                   -je 0x47c7cf
    if (cpu.flags.zf)
    {
        goto L_0x0047c7cf;
    }
    // 0047c7c0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047c7c5  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047c7ca  e8f5eb0100             -call 0x49b3c4
    cpu.esp -= 4;
    sub_49b3c4(app, cpu);
    if (cpu.terminate) return;
L_0x0047c7cf:
    // 0047c7cf  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047c7d5  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047c7dc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c7de  a1e47f4d00             -mov eax, dword ptr [0x4d7fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047c7e3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047c7e6  807c020f00             +cmp byte ptr [edx + eax + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c7eb  740a                   -je 0x47c7f7
    if (cpu.flags.zf)
    {
        goto L_0x0047c7f7;
    }
    // 0047c7ed  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047c7f2  e8e5eb0100             -call 0x49b3dc
    cpu.esp -= 4;
    sub_49b3dc(app, cpu);
    if (cpu.terminate) return;
L_0x0047c7f7:
    // 0047c7f7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c7f9  8935f47f4d00           -mov dword ptr [0x4d7ff4], esi
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = cpu.esi;
    // 0047c7ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c800  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c801:
    // 0047c801  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c810  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c811  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047c819  7442                   -je 0x47c85d
    if (cpu.flags.zf)
    {
        goto L_0x0047c85d;
    }
    // 0047c81b  66833dca11510000       +cmp word ptr [0x5111ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047c823  7538                   -jne 0x47c85d
    if (!cpu.flags.zf)
    {
        goto L_0x0047c85d;
    }
    // 0047c825  833df47f4d0000         +cmp dword ptr [0x4d7ff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c82c  742f                   -je 0x47c85d
    if (cpu.flags.zf)
    {
        goto L_0x0047c85d;
    }
    // 0047c82e  803dce11510003         +cmp byte ptr [0x5111ce], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c835  7526                   -jne 0x47c85d
    if (!cpu.flags.zf)
    {
        goto L_0x0047c85d;
    }
    // 0047c837  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047c83d  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047c844  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c846  8b15e47f4d00           -mov edx, dword ptr [0x4d7fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047c84c  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c851  750c                   -jne 0x47c85f
    if (!cpu.flags.zf)
    {
        goto L_0x0047c85f;
    }
    // 0047c853  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c854  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c856  890df47f4d00           -mov dword ptr [0x4d7ff4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = cpu.ecx;
    // 0047c85c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c85d:
    // 0047c85d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c85e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c85f:
    // 0047c85f  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047c864  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c866  e859eb0100             -call 0x49b3c4
    cpu.esp -= 4;
    sub_49b3c4(app, cpu);
    if (cpu.terminate) return;
    // 0047c86b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c86c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c86e  890df47f4d00           -mov dword ptr [0x4d7ff4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = cpu.ecx;
    // 0047c874  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c875  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c876  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c880  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047c888  7444                   -je 0x47c8ce
    if (cpu.flags.zf)
    {
        goto L_0x0047c8ce;
    }
    // 0047c88a  66833dca11510000       +cmp word ptr [0x5111ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047c892  753a                   -jne 0x47c8ce
    if (!cpu.flags.zf)
    {
        goto L_0x0047c8ce;
    }
    // 0047c894  833df47f4d0000         +cmp dword ptr [0x4d7ff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c89b  7531                   -jne 0x47c8ce
    if (!cpu.flags.zf)
    {
        goto L_0x0047c8ce;
    }
    // 0047c89d  803dce11510003         +cmp byte ptr [0x5111ce], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c8a4  7528                   -jne 0x47c8ce
    if (!cpu.flags.zf)
    {
        goto L_0x0047c8ce;
    }
    // 0047c8a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c8a7  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047c8ad  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047c8b4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c8b6  8b15e47f4d00           -mov edx, dword ptr [0x4d7fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047c8bc  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c8c1  750c                   -jne 0x47c8cf
    if (!cpu.flags.zf)
    {
        goto L_0x0047c8cf;
    }
    // 0047c8c3  c705f47f4d0001000000   -mov dword ptr [0x4d7ff4], 1
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = 1 /*0x1*/;
    // 0047c8cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c8ce:
    // 0047c8ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c8cf:
    // 0047c8cf  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047c8d4  e8f7ea0100             -call 0x49b3d0
    cpu.esp -= 4;
    sub_49b3d0(app, cpu);
    if (cpu.terminate) return;
    // 0047c8d9  c705f47f4d0001000000   -mov dword ptr [0x4d7ff4], 1
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = 1 /*0x1*/;
    // 0047c8e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c8e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c8f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c8f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c8f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c8f3  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0047c8f8  bfb8115100             -mov edi, 0x5111b8
    cpu.edi = 5312952 /*0x5111b8*/;
    // 0047c8fd  8d7202                 -lea esi, [edx + 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047c900  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c901  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c903  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047c906  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047c908  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047c90a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047c90d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047c90f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c910  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c911  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c913  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c920  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c921  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c924  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c926  833df47f4d0000         +cmp dword ptr [0x4d7ff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c92d  7509                   -jne 0x47c938
    if (!cpu.flags.zf)
    {
        goto L_0x0047c938;
    }
    // 0047c92f  83f807                 +cmp eax, 7
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
    // 0047c932  7f04                   -jg 0x47c938
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047c938;
    }
    // 0047c934  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c936  7d05                   -jge 0x47c93d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047c93d;
    }
L_0x0047c938:
    // 0047c938  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c93b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c93c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c93d:
    // 0047c93d  a1f87f4d00             -mov eax, dword ptr [0x4d7ff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079032) /* 0x4d7ff8 */);
    // 0047c942  e871ba0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0047c947  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0047c94a  6683b8b811510000       +cmp word ptr [eax + 0x5111b8], 0
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
    // 0047c952  7563                   -jne 0x47c9b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047c9b7;
    }
    // 0047c954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c955  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c956  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c957  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c958  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047c95d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0047c962  beb8115100             -mov esi, 0x5111b8
    cpu.esi = 5312952 /*0x5111b8*/;
    // 0047c967  8d7c2412               -lea edi, [esp + 0x12]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(18) /* 0x12 */);
    // 0047c96b  668998b8115100         -mov word ptr [eax + 0x5111b8], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5312952) /* 0x5111b8 */) = cpu.bx;
    // 0047c972  a1f87f4d00             -mov eax, dword ptr [0x4d7ff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079032) /* 0x4d7ff8 */);
    // 0047c977  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047c97b  e850ba0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0047c980  b409                   -mov ah, 9
    cpu.ah = 9 /*0x9*/;
    // 0047c982  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 0047c987  88642410               -mov byte ptr [esp + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 0047c98b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c98c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c98e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047c991  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047c993  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047c995  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047c998  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047c99a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c99b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047c9a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c9a2  66890d94115100         -mov word ptr [0x511194], cx
    app->getMemory<x86::reg16>(x86::reg32(5312916) /* 0x511194 */) = cpu.cx;
    // 0047c9a9  e8c25bfeff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 0047c9ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b2  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c9b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c9b7:
    // 0047c9b7  a1f87f4d00             -mov eax, dword ptr [0x4d7ff8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079032) /* 0x4d7ff8 */);
    // 0047c9bc  e80fba0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0047c9c1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c9c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c9d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c9d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c9d3  83781000               +cmp dword ptr [eax + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c9d7  7502                   -jne 0x47c9db
    if (!cpu.flags.zf)
    {
        goto L_0x0047c9db;
    }
    // 0047c9d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c9db:
    // 0047c9db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c9dc  e897bd0000             -call 0x488778
    cpu.esp -= 4;
    sub_488778(app, cpu);
    if (cpu.terminate) return;
    // 0047c9e1  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047c9e6  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047c9e9  e822ea0100             -call 0x49b410
    cpu.esp -= 4;
    sub_49b410(app, cpu);
    if (cpu.terminate) return;
    // 0047c9ee  8b1d40085600           -mov ebx, dword ptr [0x560840]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5638208) /* 0x560840 */);
    // 0047c9f4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047c9f9  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047c9fa  66891594115100         -mov word ptr [0x511194], dx
    app->getMemory<x86::reg16>(x86::reg32(5312916) /* 0x511194 */) = cpu.dx;
    // 0047ca01  891d40085600           -mov dword ptr [0x560840], ebx
    app->getMemory<x86::reg32>(x86::reg32(5638208) /* 0x560840 */) = cpu.ebx;
    // 0047ca07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ca10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ca10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ca11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ca12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ca13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ca14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ca15  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047ca1a  3b1d34005100           +cmp ebx, dword ptr [0x510034]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ca20  0f8d74000000           -jge 0x47ca9a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ca9a;
    }
    // 0047ca26  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0047ca2b  bd74cc4c00             -mov ebp, 0x4ccc74
    cpu.ebp = 5033076 /*0x4ccc74*/;
    // 0047ca30  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0047ca35:
    // 0047ca35  6683bab811510002       +cmp word ptr [edx + 0x5111b8], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312952) /* 0x5111b8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047ca3d  754a                   -jne 0x47ca89
    if (!cpu.flags.zf)
    {
        goto L_0x0047ca89;
    }
    // 0047ca3f  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ca46  7458                   -je 0x47caa0
    if (cpu.flags.zf)
    {
        goto L_0x0047caa0;
    }
L_0x0047ca48:
    // 0047ca48  c705f88f4d00da020000   -mov dword ptr [0x4d8ff8], 0x2da
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = 730 /*0x2da*/;
    // 0047ca52  a1c6115100             -mov eax, dword ptr [0x5111c6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5312966) /* 0x5111c6 */);
    // 0047ca57  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047ca5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ca5b  8b35dcff5000           -mov esi, dword ptr [0x50ffdc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
    // 0047ca61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ca62  6838cd4c00             -push 0x4ccd38
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033272 /*0x4ccd38*/;
    cpu.esp -= 4;
    // 0047ca67  892df48f4d00           -mov dword ptr [0x4d8ff4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebp;
    // 0047ca6d  e8ee5a0000             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 0047ca72  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0047ca75:
    // 0047ca75  8b81500e5100           -mov eax, dword ptr [ecx + 0x510e50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5312080) /* 0x510e50 */);
    // 0047ca7b  e850ffffff             -call 0x47c9d0
    cpu.esp -= 4;
    sub_47c9d0(app, cpu);
    if (cpu.terminate) return;
    // 0047ca80  66c782b81151000100     -mov word ptr [edx + 0x5111b8], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312952) /* 0x5111b8 */) = 1 /*0x1*/;
L_0x0047ca89:
    // 0047ca89  8b3534005100           -mov esi, dword ptr [0x510034]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 0047ca8f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047ca92  43                     -inc ebx
    (cpu.ebx)++;
    // 0047ca93  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ca96  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ca98  7c9b                   -jl 0x47ca35
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ca35;
    }
L_0x0047ca9a:
    // 0047ca9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ca9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047caa0:
    // 0047caa0  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047caa8  749e                   -je 0x47ca48
    if (cpu.flags.zf)
    {
        goto L_0x0047ca48;
    }
    // 0047caaa  ebc9                   -jmp 0x47ca75
    goto L_0x0047ca75;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_47cab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cab0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cab1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cab2  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047cab5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cab7  8a25ce115100           -mov ah, byte ptr [0x5111ce]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
    // 0047cabd  6689542420             -mov word ptr [esp + 0x20], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 0047cac2  80fc03                 +cmp ah, 3
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cac5  0f85e7000000           -jne 0x47cbb2
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbb2;
    }
    // 0047cacb  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cad3  0f84e1000000           -je 0x47cbba
    if (cpu.flags.zf)
    {
        goto L_0x0047cbba;
    }
    // 0047cad9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cada  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cadb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cadc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cadd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047cadf:
    // 0047cadf  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0047cae2  6bc068                 -imul eax, eax, 0x68
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(104 /*0x68*/)));
    // 0047cae5  8b98740e5100           -mov ebx, dword ptr [eax + 0x510e74]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5312116) /* 0x510e74 */);
    // 0047caeb  39d9                   +cmp ecx, ebx
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
    // 0047caed  751c                   -jne 0x47cb0b
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb0b;
    }
    // 0047caef  3b98800e5100           +cmp ebx, dword ptr [eax + 0x510e80]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5312128) /* 0x510e80 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047caf5  7414                   -je 0x47cb0b
    if (cpu.flags.zf)
    {
        goto L_0x0047cb0b;
    }
    // 0047caf7  05700e5100             -add eax, 0x510e70
    (cpu.eax) += x86::reg32(x86::sreg32(5312112 /*0x510e70*/));
    // 0047cafc  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047cb01  e8cafeffff             -call 0x47c9d0
    cpu.esp -= 4;
    sub_47c9d0(app, cpu);
    if (cpu.terminate) return;
    // 0047cb06  6689742430             -mov word ptr [esp + 0x30], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.si;
L_0x0047cb0b:
    // 0047cb0b  42                     -inc edx
    (cpu.edx)++;
    // 0047cb0c  6683fa07               +cmp dx, 7
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(7 /*0x7*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cb10  7ccd                   -jl 0x47cadf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cadf;
    }
    // 0047cb12  bd74cc4c00             -mov ebp, 0x4ccc74
    cpu.ebp = 5033076 /*0x4ccc74*/;
L_0x0047cb17:
    // 0047cb17  e884f6ffff             -call 0x47c1a0
    cpu.esp -= 4;
    sub_47c1a0(app, cpu);
    if (cpu.terminate) return;
    // 0047cb1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cb1e  0f85f9000000           -jne 0x47cc1d
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc1d;
    }
    // 0047cb24  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047cb28  e873f5ffff             -call 0x47c0a0
    cpu.esp -= 4;
    sub_47c0a0(app, cpu);
    if (cpu.terminate) return;
    // 0047cb2d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047cb2f:
    // 0047cb2f  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0047cb32  6bc868                 -imul ecx, eax, 0x68
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(104 /*0x68*/)));
    // 0047cb35  83b9740e510000         +cmp dword ptr [ecx + 0x510e74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5312116) /* 0x510e74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cb3c  0f857f000000           -jne 0x47cbc1
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbc1;
    }
    // 0047cb42  bf48115100             -mov edi, 0x511148
    cpu.edi = 5312840 /*0x511148*/;
    // 0047cb47  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0047cb4a  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047cb4e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047cb50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047cb51:
    // 0047cb51  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047cb53  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047cb55  3c00                   +cmp al, 0
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
    // 0047cb57  7410                   -je 0x47cb69
    if (cpu.flags.zf)
    {
        goto L_0x0047cb69;
    }
    // 0047cb59  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047cb5c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cb5f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047cb62  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cb65  3c00                   +cmp al, 0
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
    // 0047cb67  75e8                   -jne 0x47cb51
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb51;
    }
L_0x0047cb69:
    // 0047cb69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047cb6a:
    // 0047cb6a  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0047cb6f  b96c065600             -mov ecx, 0x56066c
    cpu.ecx = 5637740 /*0x56066c*/;
    // 0047cb74  0580020000             -add eax, 0x280
    (cpu.eax) += x86::reg32(x86::sreg32(640 /*0x280*/));
    // 0047cb79  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0047cb7c  a3d87f4d00             -mov dword ptr [0x4d7fd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5079000) /* 0x4d7fd8 */) = cpu.eax;
    // 0047cb81  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 0047cb85  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0047cb8a  e821fbffff             -call 0x47c6b0
    cpu.esp -= 4;
    sub_47c6b0(app, cpu);
    if (cpu.terminate) return;
    // 0047cb8f  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0047cb94  e883e80100             -call 0x49b41c
    cpu.esp -= 4;
    sub_49b41c(app, cpu);
    if (cpu.terminate) return;
    // 0047cb99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cb9b  7557                   -jne 0x47cbf4
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbf4;
    }
    // 0047cb9d  ff0d40085600           +dec dword ptr [0x560840]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5638208) /* 0x560840 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047cba3  c705d87f4d00ffffff0f   -mov dword ptr [0x4d7fd8], 0xfffffff
    app->getMemory<x86::reg32>(x86::reg32(5079000) /* 0x4d7fd8 */) = 268435455 /*0xfffffff*/;
    // 0047cbad  e965ffffff             -jmp 0x47cb17
    goto L_0x0047cb17;
L_0x0047cbb2:
    // 0047cbb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047cbb4:
    // 0047cbb4  83c424                 +add esp, 0x24
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cbb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cbba:
    // 0047cbba  e8d154feff             -call 0x462090
    cpu.esp -= 4;
    sub_462090(app, cpu);
    if (cpu.terminate) return;
    // 0047cbbf  ebf3                   -jmp 0x47cbb4
    goto L_0x0047cbb4;
L_0x0047cbc1:
    // 0047cbc1  6683fa07               +cmp dx, 7
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(7 /*0x7*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cbc5  751d                   -jne 0x47cbe4
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbe4;
    }
    // 0047cbc7  b8af020000             -mov eax, 0x2af
    cpu.eax = 687 /*0x2af*/;
    // 0047cbcc  688ccc4c00             -push 0x4ccc8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033100 /*0x4ccc8c*/;
    cpu.esp -= 4;
    // 0047cbd1  892df48f4d00           -mov dword ptr [0x4d8ff4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebp;
    // 0047cbd7  a3f88f4d00             -mov dword ptr [0x4d8ff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.eax;
    // 0047cbdc  e87f590000             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 0047cbe1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047cbe4:
    // 0047cbe4  42                     -inc edx
    (cpu.edx)++;
    // 0047cbe5  6683fa08               +cmp dx, 8
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cbe9  0f8c40ffffff           -jl 0x47cb2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cb2f;
    }
    // 0047cbef  e976ffffff             -jmp 0x47cb6a
    goto L_0x0047cb6a;
L_0x0047cbf4:
    // 0047cbf4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047cbf9  668b1d1e125100         -mov bx, word ptr [0x51121e]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5313054) /* 0x51121e */);
    // 0047cc00  01d3                   +add ebx, edx
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
    // 0047cc02  6689542430             -mov word ptr [esp + 0x30], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 0047cc07  66891d1e125100         -mov word ptr [0x51121e], bx
    app->getMemory<x86::reg16>(x86::reg32(5313054) /* 0x51121e */) = cpu.bx;
    // 0047cc0e  c705d87f4d00ffffff0f   -mov dword ptr [0x4d7fd8], 0xfffffff
    app->getMemory<x86::reg32>(x86::reg32(5079000) /* 0x4d7fd8 */) = 268435455 /*0xfffffff*/;
    // 0047cc18  e9fafeffff             -jmp 0x47cb17
    goto L_0x0047cb17;
L_0x0047cc1d:
    // 0047cc1d  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047cc21  66a194115100           -mov ax, word ptr [0x511194]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5312916) /* 0x511194 */);
    // 0047cc27  6609c7                 +or di, ax
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.ax))));
    // 0047cc2a  66897c2430             -mov word ptr [esp + 0x30], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 0047cc2f  7405                   -je 0x47cc36
    if (cpu.flags.zf)
    {
        goto L_0x0047cc36;
    }
    // 0047cc31  e82a55feff             -call 0x462160
    cpu.esp -= 4;
    sub_462160(app, cpu);
    if (cpu.terminate) return;
L_0x0047cc36:
    // 0047cc36  8b44242e               -mov eax, dword ptr [esp + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
    // 0047cc3a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047cc3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc41  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047cc44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cc50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cc51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cc52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cc53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cc54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cc55  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047cc58  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047cc5a  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047cc5e  be6dc04700             -mov esi, 0x47c06d
    cpu.esi = 4702317 /*0x47c06d*/;
    // 0047cc63  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cc64  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cc65  66a5                   -movsw word ptr es:[edi], word ptr [esi]
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
        cpu.esi -= 2;
    }
    else
    {
        cpu.edi += 2;
        cpu.esi += 2;
    }
    // 0047cc67  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0047cc6c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047cc6e  be77c04700             -mov esi, 0x47c077
    cpu.esi = 4702327 /*0x47c077*/;
    // 0047cc73  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cc75  8b0de07f4d00           -mov ecx, dword ptr [0x4d7fe0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */);
    // 0047cc7b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047cc7d  7444                   -je 0x47ccc3
    if (cpu.flags.zf)
    {
        goto L_0x0047ccc3;
    }
L_0x0047cc7f:
    // 0047cc7f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047cc84  bb27000000             -mov ebx, 0x27
    cpu.ebx = 39 /*0x27*/;
    // 0047cc89  ba0b030000             -mov edx, 0x30b
    cpu.edx = 779 /*0x30b*/;
    // 0047cc8e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047cc90  e8cb57f8ff             -call 0x402460
    cpu.esp -= 4;
    sub_402460(app, cpu);
    if (cpu.terminate) return;
    // 0047cc95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cc97  0f8479000000           -je 0x47cd16
    if (cpu.flags.zf)
    {
        goto L_0x0047cd16;
    }
    // 0047cc9d  b988065600             -mov ecx, 0x560688
    cpu.ecx = 5637768 /*0x560688*/;
    // 0047cca2  bb06040000             -mov ebx, 0x406
    cpu.ebx = 1030 /*0x406*/;
    // 0047cca7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047cca9  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047ccae  e899e70100             -call 0x49b44c
    cpu.esp -= 4;
    sub_49b44c(app, cpu);
    if (cpu.terminate) return;
    // 0047ccb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ccb5  7568                   -jne 0x47cd1f
    if (!cpu.flags.zf)
    {
        goto L_0x0047cd1f;
    }
    // 0047ccb7  b8ff020000             -mov eax, 0x2ff
    cpu.eax = 767 /*0x2ff*/;
    // 0047ccbc  e80f60f8ff             -call 0x402cd0
    cpu.esp -= 4;
    sub_402cd0(app, cpu);
    if (cpu.terminate) return;
    // 0047ccc1  ebbc                   -jmp 0x47cc7f
    goto L_0x0047cc7f;
L_0x0047ccc3:
    // 0047ccc3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ccc4  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ccc8  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047ccce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cccf  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047ccd6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ccd8  a1e47f4d00             -mov eax, dword ptr [0x4d7fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047ccdd  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047cce0  bbfc7f4d00             -mov ebx, 0x4d7ffc
    cpu.ebx = 5079036 /*0x4d7ffc*/;
    // 0047cce5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047cce7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cce8  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047cceb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cced  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047ccf2  e80de50100             -call 0x49b204
    cpu.esp -= 4;
    sub_49b204(app, cpu);
    if (cpu.terminate) return;
    // 0047ccf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ccf9  740f                   -je 0x47cd0a
    if (cpu.flags.zf)
    {
        goto L_0x0047cd0a;
    }
    // 0047ccfb  c705e07f4d0001000000   -mov dword ptr [0x4d7fe0], 1
    app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */) = 1 /*0x1*/;
    // 0047cd05  e975ffffff             -jmp 0x47cc7f
    goto L_0x0047cc7f;
L_0x0047cd0a:
    // 0047cd0a  b8ff020000             -mov eax, 0x2ff
    cpu.eax = 767 /*0x2ff*/;
    // 0047cd0f  e8bc5ff8ff             -call 0x402cd0
    cpu.esp -= 4;
    sub_402cd0(app, cpu);
    if (cpu.terminate) return;
    // 0047cd14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047cd16:
    // 0047cd16  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047cd19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cd1f:
    // 0047cd1f  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0047cd24  be88065600             -mov esi, 0x560688
    cpu.esi = 5637768 /*0x560688*/;
    // 0047cd29  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047cd2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cd2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047cd2e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047cd31  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047cd33  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047cd35  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047cd38  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047cd3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd3b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047cd40  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047cd43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cd50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cd51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cd52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cd53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cd54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cd55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cd58  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047cd5a  a06cc04700             -mov al, byte ptr [0x47c06c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4702316) /* 0x47c06c */);
    // 0047cd5f  bafeffffff             -mov edx, 0xfffffffe
    cpu.edx = 4294967294 /*0xfffffffe*/;
    // 0047cd64  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0047cd67  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047cd6c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cd6e  e8bd57feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
    // 0047cd73  66891520125100         -mov word ptr [0x511220], dx
    app->getMemory<x86::reg16>(x86::reg32(5313056) /* 0x511220 */) = cpu.dx;
    // 0047cd7a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047cd7c  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 0047cd7e  8825d4115100           -mov byte ptr [0x5111d4], ah
    app->getMemory<x86::reg8>(x86::reg32(5312980) /* 0x5111d4 */) = cpu.ah;
    // 0047cd84  b800030000             -mov eax, 0x300
    cpu.eax = 768 /*0x300*/;
    // 0047cd89  8815ce115100           -mov byte ptr [0x5111ce], dl
    app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */) = cpu.dl;
    // 0047cd8f  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0047cd94  66891dc8115100         -mov word ptr [0x5111c8], bx
    app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */) = cpu.bx;
    // 0047cd9b  e83056f8ff             -call 0x4023d0
    cpu.esp -= 4;
    sub_4023d0(app, cpu);
    if (cpu.terminate) return;
    // 0047cda0  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047cda6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cda8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047cdaa  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047cdb1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047cdb3  8b15e47f4d00           -mov edx, dword ptr [0x4d7fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047cdb9  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047cdbe  7424                   -je 0x47cde4
    if (cpu.flags.zf)
    {
        goto L_0x0047cde4;
    }
    // 0047cdc0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047cdc2  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047cdc7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047cdc9  e8c6e50100             -call 0x49b394
    cpu.esp -= 4;
    sub_49b394(app, cpu);
    if (cpu.terminate) return;
    // 0047cdce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cdd0  0f8e7e000000           -jle 0x47ce54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ce54;
    }
    // 0047cdd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047cdd8:
    // 0047cdd8  3b1510075600           +cmp edx, dword ptr [0x560710]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5637904) /* 0x560710 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cdde  0f84a0000000           -je 0x47ce84
    if (cpu.flags.zf)
    {
        goto L_0x0047ce84;
    }
L_0x0047cde4:
    // 0047cde4  e8b755feff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 0047cde9  b888065600             -mov eax, 0x560688
    cpu.eax = 5637768 /*0x560688*/;
    // 0047cdee  b96c065600             -mov ecx, 0x56066c
    cpu.ecx = 5637740 /*0x56066c*/;
    // 0047cdf3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cdf5  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0047cdfa  e8b1f8ffff             -call 0x47c6b0
    cpu.esp -= 4;
    sub_47c6b0(app, cpu);
    if (cpu.terminate) return;
    // 0047cdff  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0047ce04  e813e60100             -call 0x49b41c
    cpu.esp -= 4;
    sub_49b41c(app, cpu);
    if (cpu.terminate) return;
    // 0047ce09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ce0b  0f85e3000000           -jne 0x47cef4
    if (!cpu.flags.zf)
    {
        goto L_0x0047cef4;
    }
    // 0047ce11  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0047ce16  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ce18  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047ce1d  e81e55f8ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0047ce22  66890dca115100         -mov word ptr [0x5111ca], cx
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.cx;
    // 0047ce29  e832f9ffff             -call 0x47c760
    cpu.esp -= 4;
    sub_47c760(app, cpu);
    if (cpu.terminate) return;
    // 0047ce2e  e8f1b80000             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
    // 0047ce33  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047ce35  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ce37  668935ca115100         -mov word ptr [0x5111ca], si
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.si;
L_0x0047ce3e:
    // 0047ce3e  e8bd8af8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047ce43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ce45  0f847b000000           -je 0x47cec6
    if (cpu.flags.zf)
    {
        goto L_0x0047cec6;
    }
    // 0047ce4b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ce4d  e8ce540000             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0047ce52  ebea                   -jmp 0x47ce3e
    goto L_0x0047ce3e;
L_0x0047ce54:
    // 0047ce54  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0047ce59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ce5b  e8e054f8ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
L_0x0047ce60:
    // 0047ce60  e80c4a0000             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0047ce65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ce67  7509                   -jne 0x47ce72
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce72;
    }
    // 0047ce69  e8928af8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047ce6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ce70  74ee                   -je 0x47ce60
    if (cpu.flags.zf)
    {
        goto L_0x0047ce60;
    }
L_0x0047ce72:
    // 0047ce72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ce74  e8b756feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
L_0x0047ce79:
    // 0047ce79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ce7b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ce7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ce84:
    // 0047ce84  e8e754feff             -call 0x462370
    cpu.esp -= 4;
    sub_462370(app, cpu);
    if (cpu.terminate) return;
    // 0047ce89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ce8b  0f8447ffffff           -je 0x47cdd8
    if (cpu.flags.zf)
    {
        goto L_0x0047cdd8;
    }
    // 0047ce91  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0047ce96  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ce98  e8a354f8ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0047ce9d  e8bef8ffff             -call 0x47c760
    cpu.esp -= 4;
    sub_47c760(app, cpu);
    if (cpu.terminate) return;
L_0x0047cea2:
    // 0047cea2  e8ca490000             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0047cea7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cea9  75c7                   -jne 0x47ce72
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce72;
    }
    // 0047ceab  e8508af8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047ceb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ceb2  74ee                   -je 0x47cea2
    if (cpu.flags.zf)
    {
        goto L_0x0047cea2;
    }
    // 0047ceb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ceb6  e87556feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
    // 0047cebb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cebd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cec0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cec5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cec6:
    // 0047cec6  e8a6490000             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0047cecb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cecd  7509                   -jne 0x47ced8
    if (!cpu.flags.zf)
    {
        goto L_0x0047ced8;
    }
    // 0047cecf  e82c8af8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047ced4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ced6  74ee                   -je 0x47cec6
    if (cpu.flags.zf)
    {
        goto L_0x0047cec6;
    }
L_0x0047ced8:
    // 0047ced8  e8032bfaff             -call 0x41f9e0
    cpu.esp -= 4;
    sub_41f9e0(app, cpu);
    if (cpu.terminate) return;
    // 0047cedd  e86e1bf9ff             -call 0x40ea50
    cpu.esp -= 4;
    sub_40ea50(app, cpu);
    if (cpu.terminate) return;
    // 0047cee2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cee4  e84756feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
    // 0047cee9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ceeb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ceee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cef0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cef1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cef2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cef3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cef4:
    // 0047cef4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047cef6:
    // 0047cef6  663b1594115100         +cmp dx, word ptr [0x511194]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(5312916) /* 0x511194 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cefd  7554                   -jne 0x47cf53
    if (!cpu.flags.zf)
    {
        goto L_0x0047cf53;
    }
    // 0047ceff  e86c54feff             -call 0x462370
    cpu.esp -= 4;
    sub_462370(app, cpu);
    if (cpu.terminate) return;
    // 0047cf04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cf06  74ee                   -je 0x47cef6
    if (cpu.flags.zf)
    {
        goto L_0x0047cef6;
    }
    // 0047cf08  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0047cf0d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047cf0f  e82c54f8ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0047cf14  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047cf19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cf1b  66a3ca115100           -mov word ptr [0x5111ca], ax
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.ax;
    // 0047cf21  e8feb70000             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
    // 0047cf26  66891dca115100         -mov word ptr [0x5111ca], bx
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.bx;
    // 0047cf2d  e80e54feff             -call 0x462340
    cpu.esp -= 4;
    sub_462340(app, cpu);
    if (cpu.terminate) return;
L_0x0047cf32:
    // 0047cf32  e83a490000             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0047cf37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cf39  0f853affffff           -jne 0x47ce79
    if (!cpu.flags.zf)
    {
        goto L_0x0047ce79;
    }
    // 0047cf3f  e8bc89f8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047cf44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cf46  74ea                   -je 0x47cf32
    if (cpu.flags.zf)
    {
        goto L_0x0047cf32;
    }
    // 0047cf48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cf4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cf4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf4f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cf53:
    // 0047cf53  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047cf55  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cf57  e8e453f8ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0047cf5c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047cf61  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cf64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cf71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cf72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cf73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cf74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cf75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cf76  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047cf79  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cf7b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cf80  bfd5115100             -mov edi, 0x5111d5
    cpu.edi = 5312981 /*0x5111d5*/;
    // 0047cf85  a06bc04700             -mov al, byte ptr [0x47c06b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4702315) /* 0x47c06b */);
    // 0047cf8a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047cf8c  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0047cf90  e80bf3ffff             -call 0x47c2a0
    cpu.esp -= 4;
    sub_47c2a0(app, cpu);
    if (cpu.terminate) return;
    // 0047cf95  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047cf9a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047cf9c  e88f55feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
    // 0047cfa1  b403                   -mov ah, 3
    cpu.ah = 3 /*0x3*/;
    // 0047cfa3  8815d4115100           -mov byte ptr [0x5111d4], dl
    app->getMemory<x86::reg8>(x86::reg32(5312980) /* 0x5111d4 */) = cpu.dl;
    // 0047cfa9  66891d1e125100         -mov word ptr [0x51121e], bx
    app->getMemory<x86::reg16>(x86::reg32(5313054) /* 0x51121e */) = cpu.bx;
    // 0047cfb0  66893522125100         -mov word ptr [0x511222], si
    app->getMemory<x86::reg16>(x86::reg32(5313058) /* 0x511222 */) = cpu.si;
    // 0047cfb7  8825ce115100           -mov byte ptr [0x5111ce], ah
    app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */) = cpu.ah;
    // 0047cfbd  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0047cfbf  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047cfc1  66891520125100         -mov word ptr [0x511220], dx
    app->getMemory<x86::reg16>(x86::reg32(5313056) /* 0x511220 */) = cpu.dx;
    // 0047cfc8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047cfc9:
    // 0047cfc9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047cfcb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047cfcd  3c00                   +cmp al, 0
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
    // 0047cfcf  7410                   -je 0x47cfe1
    if (cpu.flags.zf)
    {
        goto L_0x0047cfe1;
    }
    // 0047cfd1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047cfd4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cfd7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047cfda  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047cfdd  3c00                   +cmp al, 0
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
    // 0047cfdf  75e8                   -jne 0x47cfc9
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfc9;
    }
L_0x0047cfe1:
    // 0047cfe1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfe2  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 0047cfe7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047cfe9:
    // 0047cfe9  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0047cfec  40                     -inc eax
    (cpu.eax)++;
    // 0047cfed  66893c5522125100       -mov word ptr [edx*2 + 0x511222], di
    app->getMemory<x86::reg16>(x86::reg32(5313058) /* 0x511222 */ + cpu.edx * 2) = cpu.di;
    // 0047cff5  663d0800               +cmp ax, 8
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047cff9  7cee                   -jl 0x47cfe9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cfe9;
    }
    // 0047cffb  e8c0f1ffff             -call 0x47c1c0
    cpu.esp -= 4;
    sub_47c1c0(app, cpu);
    if (cpu.terminate) return;
    // 0047d000  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047d005  bf18075600             -mov edi, 0x560718
    cpu.edi = 5637912 /*0x560718*/;
    // 0047d00a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047d00c  891548075600           -mov dword ptr [0x560748], edx
    app->getMemory<x86::reg32>(x86::reg32(5637960) /* 0x560748 */) = cpu.edx;
    // 0047d012  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047d013:
    // 0047d013  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d015  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047d017  3c00                   +cmp al, 0
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
    // 0047d019  7410                   -je 0x47d02b
    if (cpu.flags.zf)
    {
        goto L_0x0047d02b;
    }
    // 0047d01b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047d01e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d021  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047d024  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d027  3c00                   +cmp al, 0
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
    // 0047d029  75e8                   -jne 0x47d013
    if (!cpu.flags.zf)
    {
        goto L_0x0047d013;
    }
L_0x0047d02b:
    // 0047d02b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d02c  833de07f4d0000         +cmp dword ptr [0x4d7fe0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d033  0f85aa000000           -jne 0x47d0e3
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0e3;
    }
    // 0047d039  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047d03f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047d046  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047d048  8b15e47f4d00           -mov edx, dword ptr [0x4d7fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d04e  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d053  0f8474000000           -je 0x47d0cd
    if (cpu.flags.zf)
    {
        goto L_0x0047d0cd;
    }
    // 0047d059  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d05b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047d05d:
    // 0047d05d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d05e  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d062  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d063  8b0ddc7f4d00           -mov ecx, dword ptr [0x4d7fdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047d069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d06a  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0047d071  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d073  8b0de47f4d00           -mov ecx, dword ptr [0x4d7fe4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d079  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047d07c  bbfc7f4d00             -mov ebx, 0x4d7ffc
    cpu.ebx = 5079036 /*0x4d7ffc*/;
    // 0047d081  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047d083  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047d088  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d08b  e874e10100             -call 0x49b204
    cpu.esp -= 4;
    sub_49b204(app, cpu);
    if (cpu.terminate) return;
    // 0047d090  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d092  7545                   -jne 0x47d0d9
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0d9;
    }
    // 0047d094  b8ff020000             -mov eax, 0x2ff
    cpu.eax = 767 /*0x2ff*/;
    // 0047d099  e8325cf8ff             -call 0x402cd0
    cpu.esp -= 4;
    sub_402cd0(app, cpu);
    if (cpu.terminate) return;
    // 0047d09e  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0047d0a3  e8af470000             -call 0x481857
    cpu.esp -= 4;
    sub_481857(app, cpu);
    if (cpu.terminate) return;
L_0x0047d0a8:
    // 0047d0a8  e8c4470000             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0047d0ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0af  7509                   -jne 0x47d0ba
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0ba;
    }
    // 0047d0b1  e84a88f8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047d0b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0b8  74ee                   -je 0x47d0a8
    if (cpu.flags.zf)
    {
        goto L_0x0047d0a8;
    }
L_0x0047d0ba:
    // 0047d0ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d0bc  e86f54feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
    // 0047d0c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d0c3  83c410                 +add esp, 0x10
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
    // 0047d0c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d0cd:
    // 0047d0cd  b806040000             -mov eax, 0x406
    cpu.eax = 1030 /*0x406*/;
    // 0047d0d2  bac0c24700             -mov edx, 0x47c2c0
    cpu.edx = 4702912 /*0x47c2c0*/;
    // 0047d0d7  eb84                   -jmp 0x47d05d
    goto L_0x0047d05d;
L_0x0047d0d9:
    // 0047d0d9  c705e07f4d0001000000   -mov dword ptr [0x4d7fe0], 1
    app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */) = 1 /*0x1*/;
L_0x0047d0e3:
    // 0047d0e3  e8b852feff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 0047d0e8  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047d0ee  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047d0f5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047d0f7  a1e47f4d00             -mov eax, dword ptr [0x4d7fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d0fc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047d0ff  807c020f00             +cmp byte ptr [edx + eax + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d104  7514                   -jne 0x47d11a
    if (!cpu.flags.zf)
    {
        goto L_0x0047d11a;
    }
    // 0047d106  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047d10b  a3f47f4d00             -mov dword ptr [0x4d7ff4], eax
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = cpu.eax;
    // 0047d110  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d113  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d114  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d115  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d116  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d117  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d118  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d119  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d11a:
    // 0047d11a  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 0047d11f  b930c34700             -mov ecx, 0x47c330
    cpu.ecx = 4703024 /*0x47c330*/;
    // 0047d124  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d128  ba18075600             -mov edx, 0x560718
    cpu.edx = 5637912 /*0x560718*/;
    // 0047d12d  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047d132  893d048a4d00           -mov dword ptr [0x4d8a04], edi
    app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */) = cpu.edi;
    // 0047d138  e86fe20100             -call 0x49b3ac
    cpu.esp -= 4;
    sub_49b3ac(app, cpu);
    if (cpu.terminate) return;
    // 0047d13d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d13f  754f                   -jne 0x47d190
    if (!cpu.flags.zf)
    {
        goto L_0x0047d190;
    }
    // 0047d141  a3048a4d00             -mov dword ptr [0x4d8a04], eax
    app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */) = cpu.eax;
    // 0047d146  b8ff020000             -mov eax, 0x2ff
    cpu.eax = 767 /*0x2ff*/;
    // 0047d14b  e8805bf8ff             -call 0x402cd0
    cpu.esp -= 4;
    sub_402cd0(app, cpu);
    if (cpu.terminate) return;
    // 0047d150  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0047d155  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d157  e8fb460000             -call 0x481857
    cpu.esp -= 4;
    sub_481857(app, cpu);
    if (cpu.terminate) return;
    // 0047d15c  e8c3b50000             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
L_0x0047d161:
    // 0047d161  e80b470000             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0047d166  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d168  7509                   -jne 0x47d173
    if (!cpu.flags.zf)
    {
        goto L_0x0047d173;
    }
    // 0047d16a  e89187f8ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 0047d16f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d171  74ee                   -je 0x47d161
    if (cpu.flags.zf)
    {
        goto L_0x0047d161;
    }
L_0x0047d173:
    // 0047d173  e86828faff             -call 0x41f9e0
    cpu.esp -= 4;
    sub_41f9e0(app, cpu);
    if (cpu.terminate) return;
    // 0047d178  e8d318f9ff             -call 0x40ea50
    cpu.esp -= 4;
    sub_40ea50(app, cpu);
    if (cpu.terminate) return;
    // 0047d17d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d17f  e8ac53feff             -call 0x462530
    cpu.esp -= 4;
    sub_462530(app, cpu);
    if (cpu.terminate) return;
    // 0047d184  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d186  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d189  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d18a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d18b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d18c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d18d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d18e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d18f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d190:
    // 0047d190  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d192  892d048a4d00           -mov dword ptr [0x4d8a04], ebp
    app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */) = cpu.ebp;
    // 0047d198  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047d19d  a3f47f4d00             -mov dword ptr [0x4d7ff4], eax
    app->getMemory<x86::reg32>(x86::reg32(5079028) /* 0x4d7ff4 */) = cpu.eax;
    // 0047d1a2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d1a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_47d1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d1b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d1b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d1b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d1b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d1b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d1b5  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0047d1b8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047d1ba  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047d1be  a06ac04700             -mov al, byte ptr [0x47c06a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4702314) /* 0x47c06a */);
    // 0047d1c3  be60c04700             -mov esi, 0x47c060
    cpu.esi = 4702304 /*0x47c060*/;
    // 0047d1c8  8b0de07f4d00           -mov ecx, dword ptr [0x4d7fe0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */);
    // 0047d1ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d1d0  88442464               -mov byte ptr [esp + 0x64], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.al;
    // 0047d1d4  66891dec7f4d00         -mov word ptr [0x4d7fec], bx
    app->getMemory<x86::reg16>(x86::reg32(5079020) /* 0x4d7fec */) = cpu.bx;
    // 0047d1db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d1dc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d1dd  66a5                   -movsw word ptr es:[edi], word ptr [esi]
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
        cpu.esi -= 2;
    }
    else
    {
        cpu.edi += 2;
        cpu.esi += 2;
    }
    // 0047d1df  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d1e1  7547                   -jne 0x47d22a
    if (!cpu.flags.zf)
    {
        goto L_0x0047d22a;
    }
    // 0047d1e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d1e4  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047d1e8  8b15dc7f4d00           -mov edx, dword ptr [0x4d7fdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047d1ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d1ef  bbfc7f4d00             -mov ebx, 0x4d7ffc
    cpu.ebx = 5079036 /*0x4d7ffc*/;
    // 0047d1f4  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047d1fb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d1fc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047d1fe  8b0de47f4d00           -mov ecx, dword ptr [0x4d7fe4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d204  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047d207  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d209  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047d20b  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047d210  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d213  e8ecdf0100             -call 0x49b204
    cpu.esp -= 4;
    sub_49b204(app, cpu);
    if (cpu.terminate) return;
    // 0047d218  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d21a  0f8472010000           -je 0x47d392
    if (cpu.flags.zf)
    {
        goto L_0x0047d392;
    }
    // 0047d220  c705e07f4d0001000000   -mov dword ptr [0x4d7fe0], 1
    app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */) = 1 /*0x1*/;
L_0x0047d22a:
    // 0047d22a  bec4005600             -mov esi, 0x5600c4
    cpu.esi = 5636292 /*0x5600c4*/;
    // 0047d22f  8d4c2464               -lea ecx, [esp + 0x64]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0047d233  ba60c34700             -mov edx, 0x47c360
    cpu.edx = 4703072 /*0x47c360*/;
    // 0047d238  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047d23d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047d23f  8935f07f4d00           -mov dword ptr [0x4d7ff0], esi
    app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */) = cpu.esi;
    // 0047d245  e83ee10100             -call 0x49b388
    cpu.esp -= 4;
    sub_49b388(app, cpu);
    if (cpu.terminate) return;
    // 0047d24a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d24c  0f8440010000           -je 0x47d392
    if (cpu.flags.zf)
    {
        goto L_0x0047d392;
    }
    // 0047d252  66833dec7f4d0001       +cmp word ptr [0x4d7fec], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5079020) /* 0x4d7fec */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047d25a  0f8e32010000           -jle 0x47d392
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d392;
    }
    // 0047d260  a1ea7f4d00             -mov eax, dword ptr [0x4d7fea]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079018) /* 0x4d7fea */);
    // 0047d265  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d267  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d26a  897c245c               -mov dword ptr [esp + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 0047d26e  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0047d272  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d274  0f8e18010000           -jle 0x47d392
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d392;
    }
    // 0047d27a  897c2458               -mov dword ptr [esp + 0x58], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edi;
L_0x0047d27e:
    // 0047d27e  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0047d282  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047d286  8b35f07f4d00           -mov esi, dword ptr [0x4d7ff0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */);
    // 0047d28c  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047d290  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047d292  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047d296  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047d298  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047d299:
    // 0047d299  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d29b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047d29d  3c00                   +cmp al, 0
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
    // 0047d29f  7410                   -je 0x47d2b1
    if (cpu.flags.zf)
    {
        goto L_0x0047d2b1;
    }
    // 0047d2a1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047d2a4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d2a7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047d2aa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d2ad  3c00                   +cmp al, 0
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
    // 0047d2af  75e8                   -jne 0x47d299
    if (!cpu.flags.zf)
    {
        goto L_0x0047d299;
    }
L_0x0047d2b1:
    // 0047d2b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d2b2  39d5                   +cmp ebp, edx
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
    // 0047d2b4  7d4e                   -jge 0x47d304
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d304;
    }
    // 0047d2b6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047d2b8  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
L_0x0047d2bb:
    // 0047d2bb  8b15f07f4d00           -mov edx, dword ptr [0x4d7ff0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */);
    // 0047d2c1  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047d2c5  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d2c7  e8c4480000             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 0047d2cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d2ce  7e28                   -jle 0x47d2f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d2f8;
    }
    // 0047d2d0  8b35f07f4d00           -mov esi, dword ptr [0x4d7ff0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */);
    // 0047d2d6  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047d2da  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d2dc  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047d2de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047d2df:
    // 0047d2df  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d2e1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047d2e3  3c00                   +cmp al, 0
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
    // 0047d2e5  7410                   -je 0x47d2f7
    if (cpu.flags.zf)
    {
        goto L_0x0047d2f7;
    }
    // 0047d2e7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047d2ea  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d2ed  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047d2f0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d2f3  3c00                   +cmp al, 0
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
    // 0047d2f5  75e8                   -jne 0x47d2df
    if (!cpu.flags.zf)
    {
        goto L_0x0047d2df;
    }
L_0x0047d2f7:
    // 0047d2f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d2f8:
    // 0047d2f8  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047d2fc  41                     -inc ecx
    (cpu.ecx)++;
    // 0047d2fd  83c340                 -add ebx, 0x40
    (cpu.ebx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047d300  39f1                   +cmp ecx, esi
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
    // 0047d302  7cb7                   -jl 0x47d2bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d2bb;
    }
L_0x0047d304:
    // 0047d304  3b6c245c               +cmp ebp, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d308  7468                   -je 0x47d372
    if (cpu.flags.zf)
    {
        goto L_0x0047d372;
    }
    // 0047d30a  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047d30e  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0047d313  8b35f07f4d00           -mov esi, dword ptr [0x4d7ff0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */);
    // 0047d319  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047d31b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047d31d  c1e506                 -shl ebp, 6
    cpu.ebp <<= 6 /*0x6*/ % 32;
    // 0047d320  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d321  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d323  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047d326  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d328  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047d32a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047d32d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047d32f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d330  a1f07f4d00             -mov eax, dword ptr [0x4d7ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */);
    // 0047d335  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047d339  8d3428                 -lea esi, [eax + ebp]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0047d33c  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0047d341  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047d343  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d344  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d346  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047d349  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d34b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047d34d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047d350  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047d352  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d353  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0047d358  8b3df07f4d00           -mov edi, dword ptr [0x4d7ff0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5079024) /* 0x4d7ff0 */);
    // 0047d35e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047d360  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d362  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d363  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d365  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047d368  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d36a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047d36c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047d36f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047d371  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d372:
    // 0047d372  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047d376  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0047d37a  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047d37e  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047d381  42                     -inc edx
    (cpu.edx)++;
    // 0047d382  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0047d386  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 0047d38a  39ca                   +cmp edx, ecx
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
    // 0047d38c  0f8cecfeffff           -jl 0x47d27e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d27e;
    }
L_0x0047d392:
    // 0047d392  beec7f4d00             -mov esi, 0x4d7fec
    cpu.esi = 5079020 /*0x4d7fec*/;
    // 0047d397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d399  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0047d39c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d39d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d39e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d39f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d3a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d3a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d3b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d3b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d3b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d3b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d3b4  8b35dc7f4d00           -mov esi, dword ptr [0x4d7fdc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047d3ba  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d3bc  833df87f4d0000         +cmp dword ptr [0x4d7ff8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079032) /* 0x4d7ff8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d3c3  0f849d000000           -je 0x47d466
    if (cpu.flags.zf)
    {
        goto L_0x0047d466;
    }
L_0x0047d3c9:
    // 0047d3c9  833de07f4d0000         +cmp dword ptr [0x4d7fe0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d3d0  7412                   -je 0x47d3e4
    if (cpu.flags.zf)
    {
        goto L_0x0047d3e4;
    }
    // 0047d3d2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047d3d4  b86c065600             -mov eax, 0x56066c
    cpu.eax = 5637740 /*0x56066c*/;
    // 0047d3d9  893de07f4d00           -mov dword ptr [0x4d7fe0], edi
    app->getMemory<x86::reg32>(x86::reg32(5079008) /* 0x4d7fe0 */) = cpu.edi;
    // 0047d3df  e868df0100             -call 0x49b34c
    cpu.esp -= 4;
    sub_49b34c(app, cpu);
    if (cpu.terminate) return;
L_0x0047d3e4:
    // 0047d3e4  833de47f4d0000         +cmp dword ptr [0x4d7fe4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d3eb  7520                   -jne 0x47d40d
    if (!cpu.flags.zf)
    {
        goto L_0x0047d40d;
    }
    // 0047d3ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d3ee  b81ccb4c00             -mov eax, 0x4ccb1c
    cpu.eax = 5032732 /*0x4ccb1c*/;
    // 0047d3f3  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0047d3f8  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0047d3fd  e842e80100             -call 0x49bc44
    cpu.esp -= 4;
    sub_49bc44(app, cpu);
    if (cpu.terminate) return;
    // 0047d402  b880250000             -mov eax, 0x2580
    cpu.eax = 9600 /*0x2580*/;
    // 0047d407  e884f1ffff             -call 0x47c590
    cpu.esp -= 4;
    sub_47c590(app, cpu);
    if (cpu.terminate) return;
    // 0047d40c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047d40d:
    // 0047d40d  a1e47f4d00             -mov eax, dword ptr [0x4d7fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d412  8b35dc7f4d00           -mov esi, dword ptr [0x4d7fdc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */);
    // 0047d418  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d41a  743f                   -je 0x47d45b
    if (cpu.flags.zf)
    {
        goto L_0x0047d45b;
    }
    // 0047d41c  8b1544085600           -mov edx, dword ptr [0x560844]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5638212) /* 0x560844 */);
    // 0047d422  46                     -inc esi
    (cpu.esi)++;
    // 0047d423  39d6                   +cmp esi, edx
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
    // 0047d425  7c02                   -jl 0x47d429
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d429;
    }
    // 0047d427  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047d429:
    // 0047d429  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d42b  741a                   -je 0x47d447
    if (cpu.flags.zf)
    {
        goto L_0x0047d447;
    }
    // 0047d42d  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0047d434  8b15e47f4d00           -mov edx, dword ptr [0x4d7fe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d43a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047d43c  8a44820f               -mov al, byte ptr [edx + eax*4 + 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
    // 0047d440  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d445  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0047d447:
    // 0047d447  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0047d44e  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0047d451  a1e47f4d00             -mov eax, dword ptr [0x4d7fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5079012) /* 0x4d7fe4 */);
    // 0047d456  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047d459  01d0                   +add eax, edx
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
L_0x0047d45b:
    // 0047d45b  8935dc7f4d00           -mov dword ptr [0x4d7fdc], esi
    app->getMemory<x86::reg32>(x86::reg32(5079004) /* 0x4d7fdc */) = cpu.esi;
    // 0047d461  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d462  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d463  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d465  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d466:
    // 0047d466  e8fdae0000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0047d46b  a3f87f4d00             -mov dword ptr [0x4d7ff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5079032) /* 0x4d7ff8 */) = cpu.eax;
    // 0047d470  e954ffffff             -jmp 0x47d3c9
    goto L_0x0047d3c9;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d480  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d481  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d482  b9a0d44700             -mov ecx, 0x47d4a0
    cpu.ecx = 4707488 /*0x47d4a0*/;
    // 0047d487  bac0d44700             -mov edx, 0x47d4c0
    cpu.edx = 4707520 /*0x47d4c0*/;
    // 0047d48c  890d30904d00           -mov dword ptr [0x4d9030], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083184) /* 0x4d9030 */) = cpu.ecx;
    // 0047d492  89152c904d00           -mov dword ptr [0x4d902c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083180) /* 0x4d902c */) = cpu.edx;
    // 0047d498  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d499  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d49a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d4a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d4a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d4a3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d4a5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d4a7  7502                   -jne 0x47d4ab
    if (!cpu.flags.zf)
    {
        goto L_0x0047d4ab;
    }
    // 0047d4a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d4ab:
    // 0047d4ab  e8685d0000             -call 0x483218
    cpu.esp -= 4;
    sub_483218(app, cpu);
    if (cpu.terminate) return;
    // 0047d4b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d4b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d4c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d4d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d4d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d4d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d4d3  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0047d4d8  b9c8d04c00             -mov ecx, 0x4cd0c8
    cpu.ecx = 5034184 /*0x4cd0c8*/;
    // 0047d4dd  bb5a020000             -mov ebx, 0x25a
    cpu.ebx = 602 /*0x25a*/;
    // 0047d4e2  b81cd24c00             -mov eax, 0x4cd21c
    cpu.eax = 5034524 /*0x4cd21c*/;
    // 0047d4e7  8915b00e5600           -mov dword ptr [0x560eb0], edx
    app->getMemory<x86::reg32>(x86::reg32(5639856) /* 0x560eb0 */) = cpu.edx;
    // 0047d4ed  891df88f4d00           -mov dword ptr [0x4d8ff8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ebx;
    // 0047d4f3  ba00e00200             -mov edx, 0x2e000
    cpu.edx = 188416 /*0x2e000*/;
    // 0047d4f8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d4fa  890df48f4d00           -mov dword ptr [0x4d8ff4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ecx;
    // 0047d500  e803540000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0047d505  a3b40e5600             -mov dword ptr [0x560eb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5639860) /* 0x560eb4 */) = cpu.eax;
    // 0047d50a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d50b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d50c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d50d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_47d510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d510  b8a8085600             -mov eax, 0x5608a8
    cpu.eax = 5638312 /*0x5608a8*/;
    // 0047d515  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d521  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d522  8b35b80e5600           -mov esi, dword ptr [0x560eb8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5639864) /* 0x560eb8 */);
    // 0047d528  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d52a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047d52d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d52f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047d532  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0047d535  0548085600             -add eax, 0x560848
    (cpu.eax) += x86::reg32(x86::sreg32(5638216 /*0x560848*/));
    // 0047d53a  81f9ff000000           +cmp ecx, 0xff
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
    // 0047d540  7e07                   -jle 0x47d549
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d549;
    }
    // 0047d542  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0047d547  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047d549:
    // 0047d549  83e301                 -and ebx, 1
    cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047d54c  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047d553  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047d555  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047d558  8935b80e5600           -mov dword ptr [0x560eb8], esi
    app->getMemory<x86::reg32>(x86::reg32(5639864) /* 0x560eb8 */) = cpu.esi;
    // 0047d55e  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047d560  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d561  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d562  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d570  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d571  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047d573:
    // 0047d573  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d576  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d578  899040085600           -mov dword ptr [eax + 0x560840], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5638208) /* 0x560840 */) = cpu.edx;
    // 0047d57e  83f860                 +cmp eax, 0x60
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d581  75f0                   -jne 0x47d573
    if (!cpu.flags.zf)
    {
        goto L_0x0047d573;
    }
    // 0047d583  8915b80e5600           -mov dword ptr [0x560eb8], edx
    app->getMemory<x86::reg32>(x86::reg32(5639864) /* 0x560eb8 */) = cpu.edx;
    // 0047d589  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d58a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d590  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d591  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0047d596  b8a8085600             -mov eax, 0x5608a8
    cpu.eax = 5638312 /*0x5608a8*/;
    // 0047d59b  e8ecae0000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0047d5a0  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0047d5a5  b8a80b5600             -mov eax, 0x560ba8
    cpu.eax = 5639080 /*0x560ba8*/;
    // 0047d5aa  e8ddae0000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0047d5af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d5b1  8915a80e5600           -mov dword ptr [0x560ea8], edx
    app->getMemory<x86::reg32>(x86::reg32(5639848) /* 0x560ea8 */) = cpu.edx;
    // 0047d5b7  8915ac0e5600           -mov dword ptr [0x560eac], edx
    app->getMemory<x86::reg32>(x86::reg32(5639852) /* 0x560eac */) = cpu.edx;
    // 0047d5bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d5be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47d5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d5c0  a1b40e5600             -mov eax, dword ptr [0x560eb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639860) /* 0x560eb4 */);
    // 0047d5c5  e9a2570000             -jmp 0x482d6c
    return sub_482d6c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d5d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d5d2  e8d995fdff             -call 0x456bb0
    cpu.esp -= 4;
    sub_456bb0(app, cpu);
    if (cpu.terminate) return;
    // 0047d5d7  e8b4ffffff             -call 0x47d590
    cpu.esp -= 4;
    sub_47d590(app, cpu);
    if (cpu.terminate) return;
    // 0047d5dc  e8effeffff             -call 0x47d4d0
    cpu.esp -= 4;
    sub_47d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d5e1  e88affffff             -call 0x47d570
    cpu.esp -= 4;
    sub_47d570(app, cpu);
    if (cpu.terminate) return;
    // 0047d5e6  ba1a000000             -mov edx, 0x1a
    cpu.edx = 26 /*0x1a*/;
    // 0047d5eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d5ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d5ef  e82cffffff             -call 0x47d520
    cpu.esp -= 4;
    sub_47d520(app, cpu);
    if (cpu.terminate) return;
    // 0047d5f4  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 0047d5f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047d5fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d600  e81bffffff             -call 0x47d520
    cpu.esp -= 4;
    sub_47d520(app, cpu);
    if (cpu.terminate) return;
    // 0047d605  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047d60a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0047d60f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047d614  e807ffffff             -call 0x47d520
    cpu.esp -= 4;
    sub_47d520(app, cpu);
    if (cpu.terminate) return;
    // 0047d619  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047d61e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d620  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d622  e8f9feffff             -call 0x47d520
    cpu.esp -= 4;
    sub_47d520(app, cpu);
    if (cpu.terminate) return;
    // 0047d627  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d628  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d629  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d632  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d633  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d635  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d637  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047d639  e822be0100             -call 0x499460
    cpu.esp -= 4;
    sub_499460(app, cpu);
    if (cpu.terminate) return;
    // 0047d63e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0047d640:
    // 0047d640  49                     -dec ecx
    (cpu.ecx)--;
    // 0047d641  83f9ff                 +cmp ecx, -1
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
    // 0047d644  750a                   -jne 0x47d650
    if (!cpu.flags.zf)
    {
        goto L_0x0047d650;
    }
    // 0047d646  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d648  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d64a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d650:
    // 0047d650  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d652  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d654  e80bbe0100             -call 0x499464
    cpu.esp -= 4;
    sub_499464(app, cpu);
    if (cpu.terminate) return;
    // 0047d659  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047d65b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d661  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d663  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d666  755a                   -jne 0x47d6c2
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6c2;
    }
L_0x0047d668:
    // 0047d668  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047d66a  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047d66d  8dbd00030000           -lea edi, [ebp + 0x300]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0047d673:
    // 0047d673  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d675  40                     -inc eax
    (cpu.eax)++;
    // 0047d676  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047d678  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d67a  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0047d67c  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047d67e  40                     -inc eax
    (cpu.eax)++;
    // 0047d67f  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0047d682  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d684  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d687  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047d689  40                     -inc eax
    (cpu.eax)++;
    // 0047d68a  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0047d68d  39fa                   +cmp edx, edi
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
    // 0047d68f  75e2                   -jne 0x47d673
    if (!cpu.flags.zf)
    {
        goto L_0x0047d673;
    }
    // 0047d691  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d693  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d698  83f822                 +cmp eax, 0x22
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d69b  7517                   -jne 0x47d6b4
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6b4;
    }
    // 0047d69d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047d69f  8d9500030000           -lea edx, [ebp + 0x300]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0047d6a5:
    // 0047d6a5  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047d6a7  40                     -inc eax
    (cpu.eax)++;
    // 0047d6a8  c0e302                 -shl bl, 2
    cpu.bl <<= 2 /*0x2*/ % 32;
    // 0047d6ab  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0047d6ae  39d0                   +cmp eax, edx
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
    // 0047d6b0  75f3                   -jne 0x47d6a5
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6a5;
    }
    // 0047d6b2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047d6b4:
    // 0047d6b4  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047d6b7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047d6ba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d6bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d6c2:
    // 0047d6c2  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d6c5  74a1                   -je 0x47d668
    if (cpu.flags.zf)
    {
        goto L_0x0047d668;
    }
    // 0047d6c7  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d6ca  0f8570ffffff           -jne 0x47d640
    if (!cpu.flags.zf)
    {
        goto L_0x0047d640;
    }
    // 0047d6d0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047d6d2  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d6d5  8dbd00030000           -lea edi, [ebp + 0x300]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0047d6db:
    // 0047d6db  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d6dd  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047d6df  40                     -inc eax
    (cpu.eax)++;
    // 0047d6e0  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0047d6e3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d6e5  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047d6e7  40                     -inc eax
    (cpu.eax)++;
    // 0047d6e8  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0047d6eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d6ed  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0047d6f0  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047d6f2  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047d6f5  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0047d6f8  39fa                   +cmp edx, edi
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
    // 0047d6fa  75df                   -jne 0x47d6db
    if (!cpu.flags.zf)
    {
        goto L_0x0047d6db;
    }
    // 0047d6fc  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047d6ff  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047d702  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d704  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d705  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d706  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d707  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d708  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d710  a1cc0e5600             -mov eax, dword ptr [0x560ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639884) /* 0x560ecc */);
    // 0047d715  e952560000             -jmp 0x482d6c
    return sub_482d6c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d720  a1cc0e5600             -mov eax, dword ptr [0x560ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639884) /* 0x560ecc */);
    // 0047d725  e842560000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0047d72a  e901000000             -jmp 0x47d730
    return sub_47d730(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_47d730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d731  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d732  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d733  ba98d24c00             -mov edx, 0x4cd298
    cpu.edx = 5034648 /*0x4cd298*/;
    // 0047d738  b91b010000             -mov ecx, 0x11b
    cpu.ecx = 283 /*0x11b*/;
    // 0047d73d  b8b8d24c00             -mov eax, 0x4cd2b8
    cpu.eax = 5034680 /*0x4cd2b8*/;
    // 0047d742  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d744  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 0047d74a  ba00680000             -mov edx, 0x6800
    cpu.edx = 26624 /*0x6800*/;
    // 0047d74f  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0047d755  e8ae510000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0047d75a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d75c  a3cc0e5600             -mov dword ptr [0x560ecc], eax
    app->getMemory<x86::reg32>(x86::reg32(5639884) /* 0x560ecc */) = cpu.eax;
    // 0047d761  891dd00e5600           -mov dword ptr [0x560ed0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5639888) /* 0x560ed0 */) = cpu.ebx;
    // 0047d767  891dc80e5600           -mov dword ptr [0x560ec8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */) = cpu.ebx;
    // 0047d76d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047d770  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d771  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d772  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d773  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d784  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d786  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047d789  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047d78b  a1d00e5600             -mov eax, dword ptr [0x560ed0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639888) /* 0x560ed0 */);
    // 0047d790  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d792  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0047d796  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0047d79a  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0047d79e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047d7a0  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047d7a4  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0047d7a7  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0047d7ae  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0047d7b2  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d7b4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047d7b6  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0047d7b9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047d7bc  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047d7be  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047d7c2  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
L_0x0047d7c5:
    // 0047d7c5  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047d7c9  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047d7ca  81efa0010000           -sub edi, 0x1a0
    (cpu.edi) -= x86::reg32(x86::sreg32(416 /*0x1a0*/));
    // 0047d7d0  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0047d7d4  81ff60feffff           +cmp edi, 0xfffffe60
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966880 /*0xfffffe60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d7da  753a                   -jne 0x47d816
    if (!cpu.flags.zf)
    {
        goto L_0x0047d816;
    }
    // 0047d7dc  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047d7e0  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047d7e4  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047d7e8  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047d7ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d7ee  7406                   -je 0x47d7f6
    if (cpu.flags.zf)
    {
        goto L_0x0047d7f6;
    }
    // 0047d7f0  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x0047d7f6:
    // 0047d7f6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047d7f8  6800000600             -push 0x60000
    app->getMemory<x86::reg32>(cpu.esp-4) = 393216 /*0x60000*/;
    cpu.esp -= 4;
    // 0047d7fd  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d801  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d802  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d806  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d807  e8741fffff             -call 0x46f780
    cpu.esp -= 4;
    sub_46f780(app, cpu);
    if (cpu.terminate) return;
    // 0047d80c  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047d80f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d810  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d811  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d812  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d813  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d814  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d815  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d816:
    // 0047d816  8b35cc0e5600           -mov esi, dword ptr [0x560ecc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5639884) /* 0x560ecc */);
    // 0047d81c  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 0047d821  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047d823  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047d827  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d829  e8421bffff             -call 0x46f370
    cpu.esp -= 4;
    sub_46f370(app, cpu);
    if (cpu.terminate) return;
    // 0047d82e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d830  7493                   -je 0x47d7c5
    if (cpu.flags.zf)
    {
        goto L_0x0047d7c5;
    }
    // 0047d832  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047d835  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047d838  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047d83b  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0047d83f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047d841  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d843  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047d846  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047d849  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047d84c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d84e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047d852  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047d855  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047d858  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047d85c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d85e  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d862  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047d866  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d868  e823130000             -call 0x47eb90
    cpu.esp -= 4;
    sub_47eb90(app, cpu);
    if (cpu.terminate) return;
    // 0047d86d  6b54243c30             -imul edx, dword ptr [esp + 0x3c], 0x30
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */))) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047d872  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d876  e8250bffff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0047d87b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d87d  0f8442ffffff           -je 0x47d7c5
    if (cpu.flags.zf)
    {
        goto L_0x0047d7c5;
    }
    // 0047d883  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d887  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047d88b  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047d88f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d890  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047d893  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047d897  e8f4000000             -call 0x47d990
    cpu.esp -= 4;
    sub_47d990(app, cpu);
    if (cpu.terminate) return;
    // 0047d89c  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047d89f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0047d8a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d8a6  81c690010000           -add esi, 0x190
    (cpu.esi) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0047d8ac  e86fd9faff             -call 0x42b220
    cpu.esp -= 4;
    sub_42b220(app, cpu);
    if (cpu.terminate) return;
L_0x0047d8b1:
    // 0047d8b1  49                     -dec ecx
    (cpu.ecx)--;
    // 0047d8b2  83f9ff                 +cmp ecx, -1
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
    // 0047d8b5  0f840affffff           -je 0x47d7c5
    if (cpu.flags.zf)
    {
        goto L_0x0047d7c5;
    }
    // 0047d8bb  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0047d8c0  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d8c4  e8d70affff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0047d8c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d8cb  7510                   -jne 0x47d8dd
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8dd;
    }
    // 0047d8cd  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d8d1  05c0000000             +add eax, 0xc0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d8d6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d8d7  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047d8db  ebd4                   -jmp 0x47d8b1
    goto L_0x0047d8b1;
L_0x0047d8dd:
    // 0047d8dd  837c243400             +cmp dword ptr [esp + 0x34], 0
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
    // 0047d8e2  0f8593000000           -jne 0x47d97b
    if (!cpu.flags.zf)
    {
        goto L_0x0047d97b;
    }
    // 0047d8e8  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d8ec  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x0047d8f0:
    // 0047d8f0  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d8f4  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0047d8f8  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 0047d8ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d901  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047d903  8b1485e0ea4f00         -mov edx, dword ptr [eax*4 + 0x4feae0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5237472) /* 0x4feae0 */ + cpu.eax * 4);
    // 0047d90a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d90e  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047d911  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d915  c74020ffffff8f         -mov dword ptr [eax + 0x20], 0x8fffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2415919103 /*0x8fffffff*/;
    // 0047d91c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d920  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 0047d926  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d92a  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0047d930  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d934  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d938  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047d93b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047d93e  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d942  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d946  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047d949  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d94d  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d951  81c290000000           -add edx, 0x90
    (cpu.edx) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 0047d957  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047d95a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d95e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d962  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047d965  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047d968  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047d96c  05c0000000             +add eax, 0xc0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d971  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d972  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047d976  e936ffffff             -jmp 0x47d8b1
    goto L_0x0047d8b1;
L_0x0047d97b:
    // 0047d97b  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047d97f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d983  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0047d985  e966ffffff             -jmp 0x47d8f0
    goto L_0x0047d8f0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d990  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d991  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d992  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d993  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047d996  8b6c2448               -mov ebp, dword ptr [esp + 0x48]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047d99a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047d99e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047d9a2  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047d9a6  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047d9a9  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0047d9ad  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0047d9b1:
    // 0047d9b1  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047d9b5  4a                     -dec edx
    (cpu.edx)--;
    // 0047d9b6  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047d9ba  83faff                 +cmp edx, -1
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
    // 0047d9bd  7509                   -jne 0x47d9c8
    if (!cpu.flags.zf)
    {
        goto L_0x0047d9c8;
    }
    // 0047d9bf  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047d9c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9c5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d9c8:
    // 0047d9c8  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047d9cc  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0047d9cf  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047d9d2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047d9d6  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047d9da  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047d9dc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d9df  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047d9e2  0500180000             -add eax, 0x1800
    (cpu.eax) += x86::reg32(x86::sreg32(6144 /*0x1800*/));
    // 0047d9e7  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047d9eb  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047d9ef  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047d9f2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d9f5  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047d9f7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047d9fa  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047d9fe  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047da02  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047da06  e82dc00100             -call 0x499a38
    cpu.esp -= 4;
    sub_499a38(app, cpu);
    if (cpu.terminate) return;
    // 0047da0b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047da0f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047da12  0318                   -add ebx, dword ptr [eax]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0047da14  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047da18  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047da1b  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047da1f  037004                 -add esi, dword ptr [eax + 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0047da22  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047da26  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047da2a  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047da2e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047da31  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047da33  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0047da37  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 0047da3a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047da3e  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047da41  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047da45  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047da4b  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047da4e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047da52  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047da56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047da58  7508                   -jne 0x47da62
    if (!cpu.flags.zf)
    {
        goto L_0x0047da62;
    }
    // 0047da5a  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0047da62:
    // 0047da62  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047da66  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0047da6a  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047da6e  db442434               -fild dword ptr [esp + 0x34]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 0047da72  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047da76  d95c2420               -fstp dword ptr [esp + 0x20]
    app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047da7a  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047da7c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047da7e  c1eb0f                 -shr ebx, 0xf
    cpu.ebx >>= 15 /*0xf*/ % 32;
    // 0047da81  81e1000080ff           -and ecx, 0xff800000
    cpu.ecx &= x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
    // 0047da87  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047da8d  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0047da8f  8b1c9db4f74e00         -mov ebx, dword ptr [ebx*4 + 0x4ef7b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5175220) /* 0x4ef7b4 */ + cpu.ebx * 4);
    // 0047da96  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047da98  891de4fb4e00           -mov dword ptr [0x4efbe4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5176292) /* 0x4efbe4 */) = cpu.ebx;
    // 0047da9e  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 0047daa4  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 0047daaa  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 0047dab0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0047dab2  d808                   -fmul dword ptr [eax]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax));
    // 0047dab4  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 0047daba  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047dabc  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047dabe  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047dac2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047dac4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047dac6  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047dac9  d905b0304d00           -fld dword ptr [0x4d30b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058736) /* 0x4d30b0 */)));
    // 0047dacf  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047dad1  d905b4304d00           -fld dword ptr [0x4d30b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058740) /* 0x4d30b4 */)));
    // 0047dad7  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047dad9  d905cc304d00           -fld dword ptr [0x4d30cc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058764) /* 0x4d30cc */)));
    // 0047dadf  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047dae1  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 0047dae4  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 0047dae6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047dae8  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047daea  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047daec  d905bc304d00           -fld dword ptr [0x4d30bc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058748) /* 0x4d30bc */)));
    // 0047daf2  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047daf4  d905b8304d00           -fld dword ptr [0x4d30b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058744) /* 0x4d30b8 */)));
    // 0047dafa  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047dafc  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047daff  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047db02  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047db04  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047db07  8b0dd4fb4e00           -mov ecx, dword ptr [0x4efbd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176276) /* 0x4efbd4 */);
    // 0047db0d  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047db12  7558                   -jne 0x47db6c
    if (!cpu.flags.zf)
    {
        goto L_0x0047db6c;
    }
    // 0047db14  39c8                   +cmp eax, ecx
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
    // 0047db16  7d54                   -jge 0x47db6c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047db6c;
    }
    // 0047db18  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047db1b  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0047db20  8b0de0fb4e00           -mov ecx, dword ptr [0x4efbe0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176288) /* 0x4efbe0 */);
    // 0047db26  8b15dcfb4e00           -mov edx, dword ptr [0x4efbdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176284) /* 0x4efbdc */);
    // 0047db2c  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047db31  750d                   -jne 0x47db40
    if (!cpu.flags.zf)
    {
        goto L_0x0047db40;
    }
    // 0047db33  39c8                   +cmp eax, ecx
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
    // 0047db35  7c09                   -jl 0x47db40
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047db40;
    }
    // 0047db37  39d0                   +cmp eax, edx
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
    // 0047db39  7e09                   -jle 0x47db44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047db44;
    }
    // 0047db3b  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0047db3e  eb04                   -jmp 0x47db44
    goto L_0x0047db44;
L_0x0047db40:
    // 0047db40  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047db43  90                     -nop 
    ;
L_0x0047db44:
    // 0047db44  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047db46  90                     -nop 
    ;
    // 0047db47  8b0dd8fb4e00           -mov ecx, dword ptr [0x4efbd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176280) /* 0x4efbd8 */);
    // 0047db4d  8b15e8fb4e00           -mov edx, dword ptr [0x4efbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176296) /* 0x4efbe8 */);
    // 0047db53  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047db58  750d                   -jne 0x47db67
    if (!cpu.flags.zf)
    {
        goto L_0x0047db67;
    }
    // 0047db5a  39c8                   +cmp eax, ecx
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
    // 0047db5c  7c09                   -jl 0x47db67
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047db67;
    }
    // 0047db5e  39d0                   +cmp eax, edx
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
    // 0047db60  7e0f                   -jle 0x47db71
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047db71;
    }
    // 0047db62  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0047db65  eb0a                   -jmp 0x47db71
    goto L_0x0047db71;
L_0x0047db67:
    // 0047db67  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047db6a  eb05                   -jmp 0x47db71
    goto L_0x0047db71;
L_0x0047db6c:
    // 0047db6c  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0047db71:
    // 0047db71  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0047db73  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0047db78  7c24                   -jl 0x47db9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047db9e;
    }
    // 0047db7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047db7c:
    // 0047db7c  83c530                 -add ebp, 0x30
    (cpu.ebp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047db7f  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047db83  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047db87  668945de               -mov word ptr [ebp - 0x22], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-34) /* -0x22 */) = cpu.ax;
    // 0047db8b  83c330                 -add ebx, 0x30
    (cpu.ebx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047db8e  83c606                 +add esi, 6
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047db91  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0047db95  89742430               -mov dword ptr [esp + 0x30], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.esi;
    // 0047db99  e913feffff             -jmp 0x47d9b1
    goto L_0x0047d9b1;
L_0x0047db9e:
    // 0047db9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047dba3  ebd7                   -jmp 0x47db7c
    goto L_0x0047db7c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47dbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dbb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dbb1  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0047dbb6  0f84b7000000           -je 0x47dc73
    if (cpu.flags.zf)
    {
        goto L_0x0047dc73;
    }
    // 0047dbbc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dbbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dbbe  a1c80e5600             -mov eax, dword ptr [0x560ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */);
    // 0047dbc3  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 0047dbca  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dbcc  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047dbcf  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047dbd1  a1cc0e5600             -mov eax, dword ptr [0x560ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639884) /* 0x560ecc */);
    // 0047dbd6  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0047dbd9  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047dbdb  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047dbde  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dbe0  83fe10                 +cmp esi, 0x10
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
    // 0047dbe3  0f858e000000           -jne 0x47dc77
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc77;
    }
L_0x0047dbe9:
    // 0047dbe9  8b15d00e5600           -mov edx, dword ptr [0x560ed0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5639888) /* 0x560ed0 */);
    // 0047dbef  83fa40                 +cmp edx, 0x40
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
    // 0047dbf2  0f8d07010000           -jge 0x47dcff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047dcff;
    }
    // 0047dbf8  8915c80e5600           -mov dword ptr [0x560ec8], edx
    app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */) = cpu.edx;
    // 0047dbfe  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047dc01  a3d00e5600             -mov dword ptr [0x560ed0], eax
    app->getMemory<x86::reg32>(x86::reg32(5639888) /* 0x560ed0 */) = cpu.eax;
L_0x0047dc06:
    // 0047dc06  a1c80e5600             -mov eax, dword ptr [0x560ec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */);
    // 0047dc0b  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 0047dc12  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dc14  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047dc17  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047dc19  a1cc0e5600             -mov eax, dword ptr [0x560ecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639884) /* 0x560ecc */);
    // 0047dc1e  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0047dc21  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047dc23  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x0047dc2a:
    // 0047dc2a  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047dc2c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047dc2e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047dc2f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047dc30  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0047dc31:
    // 0047dc31  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047dc34  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047dc3b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dc3d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047dc40  8d5510                 -lea edx, [ebp + 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047dc43  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047dc45  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047dc47  e8f4000000             -call 0x47dd40
    cpu.esp -= 4;
    sub_47dd40(app, cpu);
    if (cpu.terminate) return;
    // 0047dc4c  837c241002             +cmp dword ptr [esp + 0x10], 2
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
    // 0047dc51  0f85ce000000           -jne 0x47dd25
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd25;
    }
    // 0047dc57  e888880000             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 0047dc5c  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0047dc5e  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047dc61  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047dc64  80c202                 -add dl, 2
    (cpu.dl) += x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0047dc67  88942890010000         -mov byte ptr [eax + ebp + 0x190], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(400) /* 0x190 */ + cpu.ebp * 1) = cpu.dl;
    // 0047dc6e  ff450c                 -inc dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))++;
    // 0047dc71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dc73:
    // 0047dc73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc74  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047dc77:
    // 0047dc77  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047dc79  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047dc7c  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047dc7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc80  7e0c                   -jle 0x47dc8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dc8e;
    }
    // 0047dc82  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc87  7c13                   -jl 0x47dc9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dc9c;
    }
    // 0047dc89  e95bffffff             -jmp 0x47dbe9
    goto L_0x0047dbe9;
L_0x0047dc8e:
    // 0047dc8e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0047dc90  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc95  7c05                   -jl 0x47dc9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dc9c;
    }
    // 0047dc97  e94dffffff             -jmp 0x47dbe9
    goto L_0x0047dbe9;
L_0x0047dc9c:
    // 0047dc9c  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047dc9f  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047dca2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047dca4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dca6  7e0c                   -jle 0x47dcb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dcb4;
    }
    // 0047dca8  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dcad  7c13                   -jl 0x47dcc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dcc2;
    }
    // 0047dcaf  e935ffffff             -jmp 0x47dbe9
    goto L_0x0047dbe9;
L_0x0047dcb4:
    // 0047dcb4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0047dcb6  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dcbb  7c05                   -jl 0x47dcc2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dcc2;
    }
    // 0047dcbd  e927ffffff             -jmp 0x47dbe9
    goto L_0x0047dbe9;
L_0x0047dcc2:
    // 0047dcc2  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047dcc5  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047dcc8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047dcca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dccc  7e0c                   -jle 0x47dcda
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047dcda;
    }
    // 0047dcce  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dcd3  7c13                   -jl 0x47dce8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dce8;
    }
    // 0047dcd5  e90fffffff             -jmp 0x47dbe9
    goto L_0x0047dbe9;
L_0x0047dcda:
    // 0047dcda  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0047dcdc  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dce1  7c05                   -jl 0x47dce8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dce8;
    }
    // 0047dce3  e901ffffff             -jmp 0x47dbe9
    goto L_0x0047dbe9;
L_0x0047dce8:
    // 0047dce8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047dcea  0f85f9feffff           -jne 0x47dbe9
    if (!cpu.flags.zf)
    {
        goto L_0x0047dbe9;
    }
    // 0047dcf0  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dcf4  0f8430ffffff           -je 0x47dc2a
    if (cpu.flags.zf)
    {
        goto L_0x0047dc2a;
    }
    // 0047dcfa  e932ffffff             -jmp 0x47dc31
    goto L_0x0047dc31;
L_0x0047dcff:
    // 0047dcff  8b35c80e5600           -mov esi, dword ptr [0x560ec8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */);
    // 0047dd05  83fe3f                 +cmp esi, 0x3f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dd08  7d0e                   -jge 0x47dd18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047dd18;
    }
    // 0047dd0a  8d6e01                 -lea ebp, [esi + 1]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047dd0d  892dc80e5600           -mov dword ptr [0x560ec8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */) = cpu.ebp;
    // 0047dd13  e9eefeffff             -jmp 0x47dc06
    goto L_0x0047dc06;
L_0x0047dd18:
    // 0047dd18  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047dd1a  893dc80e5600           -mov dword ptr [0x560ec8], edi
    app->getMemory<x86::reg32>(x86::reg32(5639880) /* 0x560ec8 */) = cpu.edi;
    // 0047dd20  e9e1feffff             -jmp 0x47dc06
    goto L_0x0047dc06;
L_0x0047dd25:
    // 0047dd25  e8ba870000             -call 0x4864e4
    cpu.esp -= 4;
    sub_4864e4(app, cpu);
    if (cpu.terminate) return;
    // 0047dd2a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047dd2d  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047dd2f  88842a90010000         -mov byte ptr [edx + ebp + 0x190], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(400) /* 0x190 */ + cpu.ebp * 1) = cpu.al;
    // 0047dd36  ff450c                 -inc dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))++;
    // 0047dd39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd3c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_47dd40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dd40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dd41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dd42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dd43  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047dd46  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047dd48  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047dd4a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047dd4c  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047dd4e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047dd50  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047dd53  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dd55  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047dd58  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dd5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047dd5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dd5e  e8eda90100             -call 0x498750
    cpu.esp -= 4;
    sub_498750(app, cpu);
    if (cpu.terminate) return;
    // 0047dd63  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047dd67  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0047dd6d  c0e507                 +shl ch, 7
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
    // 0047dd70  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047dd72  00ed                   +add ch, ch
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
    // 0047dd74  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0047dd76  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047dd78  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047dd7d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047dd7f  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 0047dd86  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dd88  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dd8a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047dd8c  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0047dd91  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0047dd93  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047dd95  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047dd98  c1e810                 +shr eax, 0x10
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
    // 0047dd9b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047dd9d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047dd9f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047dda2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047dda6  c0e407                 +shl ah, 7
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
    // 0047dda9  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047ddab  00e4                   +add ah, ah
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
    // 0047ddad  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0047ddaf  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ddb1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047ddb6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ddb8  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 0047ddbf  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ddc1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ddc3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ddc5  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0047ddca  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ddcd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047ddcf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047ddd2  c1e810                 +shr eax, 0x10
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
    // 0047ddd5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047ddd7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047ddd9  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047dddb  2b17                   -sub edx, dword ptr [edi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 0047dddd  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047dde0  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 0047dde3  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047dde6  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0047dde9  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047ddec  66895602               -mov word ptr [esi + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 0047ddf0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047ddf2  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047ddf5  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047ddf8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ddfa  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ddfc  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047ddff  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0047de03  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047de06  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047de08  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de0a  2b17                   -sub edx, dword ptr [edi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 0047de0c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de0f  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0047de13  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047de16  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0047de19  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de1c  66895608               -mov word ptr [esi + 8], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.dx;
    // 0047de20  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047de23  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047de26  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047de28  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047de2a  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de2d  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0047de31  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047de34  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047de37  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0047de39  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de3b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047de3d  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de40  6689560c               -mov word ptr [esi + 0xc], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 0047de44  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047de47  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0047de4a  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de4d  6689560e               -mov word ptr [esi + 0xe], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0047de51  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047de54  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047de57  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047de59  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047de5b  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de5e  66895610               -mov word ptr [esi + 0x10], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0047de62  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047de65  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047de68  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0047de6a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de6c  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047de6e  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de71  66895612               -mov word ptr [esi + 0x12], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 0047de75  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047de78  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0047de7b  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047de7e  66895614               -mov word ptr [esi + 0x14], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.dx;
    // 0047de82  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047de85  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047de88  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047de8a  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047de8c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0047de8f  66894616               -mov word ptr [esi + 0x16], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */) = cpu.ax;
    // 0047de93  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047de96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047de97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047de98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047de99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47dea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dea0  a1a0744d00             -mov eax, dword ptr [0x4d74a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076128) /* 0x4d74a0 */);
    // 0047dea5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047dea8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047deaa  8b15d80e5600           -mov edx, dword ptr [0x560ed8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5639896) /* 0x560ed8 */);
    // 0047deb0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047deb2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047deb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47dec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dec0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dec1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dec2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dec3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dec4  3b05b02f5400           +cmp eax, dword ptr [0x542fb0]
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
    // 0047deca  7416                   -je 0x47dee2
    if (cpu.flags.zf)
    {
        goto L_0x0047dee2;
    }
    // 0047decc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047decd  bba3000000             -mov ebx, 0xa3
    cpu.ebx = 163 /*0xa3*/;
    // 0047ded2  bac4d24c00             -mov edx, 0x4cd2c4
    cpu.edx = 5034692 /*0x4cd2c4*/;
    // 0047ded7  b838d34c00             -mov eax, 0x4cd338
    cpu.eax = 5034808 /*0x4cd338*/;
    // 0047dedc  e872bf0100             -call 0x499e53
    cpu.esp -= 4;
    sub_499e53(app, cpu);
    if (cpu.terminate) return;
    // 0047dee1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dee2:
    // 0047dee2  a1b02f5400             -mov eax, dword ptr [0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047dee7  e8a4a1fdff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 0047deec  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047deee  8b35a0744d00           -mov esi, dword ptr [0x4d74a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076128) /* 0x4d74a0 */);
    // 0047def4  890d20894d00           -mov dword ptr [0x4d8920], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081376) /* 0x4d8920 */) = cpu.ecx;
    // 0047defa  890db02f5400           -mov dword ptr [0x542fb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */) = cpu.ecx;
    // 0047df00  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047df02  740d                   -je 0x47df11
    if (cpu.flags.zf)
    {
        goto L_0x0047df11;
    }
    // 0047df04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047df06  e8614e0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0047df0b  890da0744d00           -mov dword ptr [0x4d74a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076128) /* 0x4d74a0 */) = cpu.ecx;
L_0x0047df11:
    // 0047df11  8b2da4744d00           -mov ebp, dword ptr [0x4d74a4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5076132) /* 0x4d74a4 */);
    // 0047df17  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047df19  740e                   -je 0x47df29
    if (cpu.flags.zf)
    {
        goto L_0x0047df29;
    }
    // 0047df1b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047df1d  e84a4e0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0047df22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047df24  a3a4744d00             -mov dword ptr [0x4d74a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5076132) /* 0x4d74a4 */) = cpu.eax;
L_0x0047df29:
    // 0047df29  8b15a8744d00           -mov edx, dword ptr [0x4d74a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076136) /* 0x4d74a8 */);
    // 0047df2f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047df31  7505                   -jne 0x47df38
    if (!cpu.flags.zf)
    {
        goto L_0x0047df38;
    }
    // 0047df33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047df38:
    // 0047df38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047df3a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047df3c  e82b4e0000             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0047df41  890da8744d00           -mov dword ptr [0x4d74a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076136) /* 0x4d74a8 */) = cpu.ecx;
    // 0047df47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_47df50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047df50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047df51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047df52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047df53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047df54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047df55  b9b02f5400             -mov ecx, 0x542fb0
    cpu.ecx = 5517232 /*0x542fb0*/;
    // 0047df5a  bb00080000             -mov ebx, 0x800
    cpu.ebx = 2048 /*0x800*/;
    // 0047df5f  ba01080000             -mov edx, 0x801
    cpu.edx = 2049 /*0x801*/;
    // 0047df64  e807abfdff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 0047df69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047df6b  7523                   -jne 0x47df90
    if (!cpu.flags.zf)
    {
        goto L_0x0047df90;
    }
    // 0047df6d  bac4d24c00             -mov edx, 0x4cd2c4
    cpu.edx = 5034692 /*0x4cd2c4*/;
    // 0047df72  b971000000             -mov ecx, 0x71
    cpu.ecx = 113 /*0x71*/;
    // 0047df77  68e0d24c00             -push 0x4cd2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034720 /*0x4cd2e0*/;
    cpu.esp -= 4;
    // 0047df7c  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 0047df82  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0047df88  e8d3450000             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 0047df8d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0047df90:
    // 0047df90  a1b02f5400             -mov eax, dword ptr [0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047df95  ba902f5400             -mov edx, 0x542f90
    cpu.edx = 5517200 /*0x542f90*/;
    // 0047df9a  e831a0fdff             -call 0x457fd0
    cpu.esp -= 4;
    sub_457fd0(app, cpu);
    if (cpu.terminate) return;
    // 0047df9f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dfa1  a3d80e5600             -mov dword ptr [0x560ed8], eax
    app->getMemory<x86::reg32>(x86::reg32(5639896) /* 0x560ed8 */) = cpu.eax;
    // 0047dfa6  891dd40e5600           -mov dword ptr [0x560ed4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5639892) /* 0x560ed4 */) = cpu.ebx;
    // 0047dfac  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0047dfb1  a1b02f5400             -mov eax, dword ptr [0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047dfb6  e855010000             -call 0x47e110
    cpu.esp -= 4;
    sub_47e110(app, cpu);
    if (cpu.terminate) return;
    // 0047dfbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dfbd  0f8426010000           -je 0x47e0e9
    if (cpu.flags.zf)
    {
        goto L_0x0047e0e9;
    }
    // 0047dfc3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0047dfc8  ba0cd34c00             -mov edx, 0x4cd30c
    cpu.edx = 5034764 /*0x4cd30c*/;
    // 0047dfcd  b8902f5400             -mov eax, 0x542f90
    cpu.eax = 5517200 /*0x542f90*/;
    // 0047dfd2  e8a0970100             -call 0x497777
    cpu.esp -= 4;
    sub_497777(app, cpu);
    if (cpu.terminate) return;
    // 0047dfd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dfd9  0f850a010000           -jne 0x47e0e9
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0e9;
    }
    // 0047dfdf  833d942f540016         +cmp dword ptr [0x542f94], 0x16
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5517204) /* 0x542f94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dfe6  0f85fd000000           -jne 0x47e0e9
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0e9;
    }
    // 0047dfec  bfc4d24c00             -mov edi, 0x4cd2c4
    cpu.edi = 5034692 /*0x4cd2c4*/;
    // 0047dff1  bd82000000             -mov ebp, 0x82
    cpu.ebp = 130 /*0x82*/;
    // 0047dff6  b814d34c00             -mov eax, 0x4cd314
    cpu.eax = 5034772 /*0x4cd314*/;
    // 0047dffb  8b15a82f5400           -mov edx, dword ptr [0x542fa8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517224) /* 0x542fa8 */);
    // 0047e001  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e003  893df48f4d00           -mov dword ptr [0x4d8ff4], edi
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edi;
    // 0047e009  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e00c  892df88f4d00           -mov dword ptr [0x4d8ff8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ebp;
    // 0047e012  e8f1480000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0047e017  8b1da82f5400           -mov ebx, dword ptr [0x542fa8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5517224) /* 0x542fa8 */);
    // 0047e01d  8b0db02f5400           -mov ecx, dword ptr [0x542fb0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047e023  a3a0744d00             -mov dword ptr [0x4d74a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5076128) /* 0x4d74a0 */) = cpu.eax;
    // 0047e028  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e02a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047e02d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e02f  e8dc000000             -call 0x47e110
    cpu.esp -= 4;
    sub_47e110(app, cpu);
    if (cpu.terminate) return;
    // 0047e034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e036  0f84ad000000           -je 0x47e0e9
    if (cpu.flags.zf)
    {
        goto L_0x0047e0e9;
    }
    // 0047e03c  c705f88f4d0087000000   -mov dword ptr [0x4d8ff8], 0x87
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = 135 /*0x87*/;
    // 0047e046  8b15ac2f5400           -mov edx, dword ptr [0x542fac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */);
    // 0047e04c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047e053  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e055  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0047e05c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e05e  b820d34c00             -mov eax, 0x4cd320
    cpu.eax = 5034784 /*0x4cd320*/;
    // 0047e063  893df48f4d00           -mov dword ptr [0x4d8ff4], edi
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edi;
    // 0047e069  e89a480000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0047e06e  8b1dac2f5400           -mov ebx, dword ptr [0x542fac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */);
    // 0047e074  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e076  a3a4744d00             -mov dword ptr [0x4d74a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5076132) /* 0x4d74a4 */) = cpu.eax;
    // 0047e07b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047e082  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e084  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0047e08b  a1b02f5400             -mov eax, dword ptr [0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047e090  e87b000000             -call 0x47e110
    cpu.esp -= 4;
    sub_47e110(app, cpu);
    if (cpu.terminate) return;
    // 0047e095  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e097  7450                   -je 0x47e0e9
    if (cpu.flags.zf)
    {
        goto L_0x0047e0e9;
    }
    // 0047e099  bb8c000000             -mov ebx, 0x8c
    cpu.ebx = 140 /*0x8c*/;
    // 0047e09e  b82cd34c00             -mov eax, 0x4cd32c
    cpu.eax = 5034796 /*0x4cd32c*/;
    // 0047e0a3  8b15ac2f5400           -mov edx, dword ptr [0x542fac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */);
    // 0047e0a9  891df88f4d00           -mov dword ptr [0x4d8ff8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ebx;
    // 0047e0af  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047e0b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e0b3  893df48f4d00           -mov dword ptr [0x4d8ff4], edi
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edi;
    // 0047e0b9  e84a480000             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0047e0be  8b1dac2f5400           -mov ebx, dword ptr [0x542fac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5517228) /* 0x542fac */);
    // 0047e0c4  8b0db02f5400           -mov ecx, dword ptr [0x542fb0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047e0ca  a3a8744d00             -mov dword ptr [0x4d74a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5076136) /* 0x4d74a8 */) = cpu.eax;
    // 0047e0cf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e0d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e0d3  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e0d5  e836000000             -call 0x47e110
    cpu.esp -= 4;
    sub_47e110(app, cpu);
    if (cpu.terminate) return;
    // 0047e0da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e0dc  740b                   -je 0x47e0e9
    if (cpu.flags.zf)
    {
        goto L_0x0047e0e9;
    }
    // 0047e0de  a1b02f5400             -mov eax, dword ptr [0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047e0e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e0e9:
    // 0047e0e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e0ea  a1b02f5400             -mov eax, dword ptr [0x542fb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */);
    // 0047e0ef  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e0f1  e89a9ffdff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 0047e0f6  8935b02f5400           -mov dword ptr [0x542fb0], esi
    app->getMemory<x86::reg32>(x86::reg32(5517232) /* 0x542fb0 */) = cpu.esi;
    // 0047e0fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e0fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e100  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e101  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e102  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e103  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e104  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e110  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e111  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e112  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047e114  a1d80e5600             -mov eax, dword ptr [0x560ed8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639896) /* 0x560ed8 */);
    // 0047e119  0305d40e5600           -add eax, dword ptr [0x560ed4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5639892) /* 0x560ed4 */)));
    // 0047e11f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047e121  e8dab90000             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 0047e126  8b35d40e5600           -mov esi, dword ptr [0x560ed4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5639892) /* 0x560ed4 */);
    // 0047e12c  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e12e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e130  8935d40e5600           -mov dword ptr [0x560ed4], esi
    app->getMemory<x86::reg32>(x86::reg32(5639892) /* 0x560ed4 */) = cpu.esi;
    // 0047e136  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e137  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e138  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e140  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e141  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e142  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e143  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e146  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047e14a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047e14c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047e14e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047e150  833d54734d0000         +cmp dword ptr [0x4d7354], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5075796) /* 0x4d7354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e157  0f842e020000           -je 0x47e38b
    if (cpu.flags.zf)
    {
        goto L_0x0047e38b;
    }
    // 0047e15d  80782000               +cmp byte ptr [eax + 0x20], 0
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
    // 0047e161  0f8424020000           -je 0x47e38b
    if (cpu.flags.zf)
    {
        goto L_0x0047e38b;
    }
    // 0047e167  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 0047e16b  0f841a020000           -je 0x47e38b
    if (cpu.flags.zf)
    {
        goto L_0x0047e38b;
    }
    // 0047e171  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0047e176:
    // 0047e176  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e17a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047e17c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047e183  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e185  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e187  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e18b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047e18e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047e192  e80902ffff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0047e197  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e199  0f845e030000           -je 0x47e4fd
    if (cpu.flags.zf)
    {
        goto L_0x0047e4fd;
    }
    // 0047e19f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e1a1  742f                   -je 0x47e1d2
    if (cpu.flags.zf)
    {
        goto L_0x0047e1d2;
    }
    // 0047e1a3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e1a7  80782002               +cmp byte ptr [eax + 0x20], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e1ab  0f85e1010000           -jne 0x47e392
    if (!cpu.flags.zf)
    {
        goto L_0x0047e392;
    }
    // 0047e1b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047e1b6:
    // 0047e1b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e1b7  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e1bb  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e1bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e1c0  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047e1c3  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047e1c6  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e1c8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e1c9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e1cb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047e1cd  e84e030000             -call 0x47e520
    cpu.esp -= 4;
    sub_47e520(app, cpu);
    if (cpu.terminate) return;
L_0x0047e1d2:
    // 0047e1d2  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e1d6  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e1da  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047e1de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e1df  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e1e3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047e1e5  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047e1e7  8b4914                 -mov ecx, dword ptr [ecx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047e1ea  e8b1050000             -call 0x47e7a0
    cpu.esp -= 4;
    sub_47e7a0(app, cpu);
    if (cpu.terminate) return;
    // 0047e1ef  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e1f3  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047e1f6  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047e1fd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e1ff  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e203  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e206  e89501ffff             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0047e20b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e20d  0f84ea020000           -je 0x47e4fd
    if (cpu.flags.zf)
    {
        goto L_0x0047e4fd;
    }
    // 0047e213  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e217  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e219  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047e21c  e8ffcffaff             -call 0x42b220
    cpu.esp -= 4;
    sub_42b220(app, cpu);
    if (cpu.terminate) return;
    // 0047e221  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e225  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e227  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047e22a  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0047e22e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e230  0f8e16010000           -jle 0x47e34c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e34c;
    }
    // 0047e236  be24000000             -mov esi, 0x24
    cpu.esi = 36 /*0x24*/;
    // 0047e23b  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047e23f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047e241:
    // 0047e241  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e245  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e249  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e24d  8b5b18                 -mov ebx, dword ptr [ebx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0047e250  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e252  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e256  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047e258  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e25a  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047e25c  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0047e25e  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 0047e260  0fb76b02               -movzx ebp, word ptr [ebx + 2]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */));
    // 0047e264  8d5304                 -lea edx, [ebx + 4]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047e267  036c243c               -add ebp, dword ptr [esp + 0x3c]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 0047e26b  8a5b01                 -mov bl, byte ptr [ebx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0047e26e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e274  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e276  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047e27a  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e27e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e280  0f84cd010000           -je 0x47e453
    if (cpu.flags.zf)
    {
        goto L_0x0047e453;
    }
    // 0047e286  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0047e28d  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0047e290  0f843d010000           -je 0x47e3d3
    if (cpu.flags.zf)
    {
        goto L_0x0047e3d3;
    }
    // 0047e296  c740041f000000         -mov dword ptr [eax + 4], 0x1f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 31 /*0x1f*/;
    // 0047e29d  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0047e2a0  0f84f3000000           -je 0x47e399
    if (cpu.flags.zf)
    {
        goto L_0x0047e399;
    }
    // 0047e2a6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047e2a8:
    // 0047e2a8  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e2ab  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e2ae  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e2b2  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e2b4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e2b6  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047e2b9  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047e2bc  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e2bf  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e2c3  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e2c5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e2c7  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0047e2ca  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047e2cc  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e2cf  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e2d3  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e2d5  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e2d8  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
L_0x0047e2da:
    // 0047e2da  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e2e0  6bd230                 -imul edx, edx, 0x30
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e2e3  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e2e7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047e2e9  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047e2ec  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0047e2ef  0f84f3010000           -je 0x47e4e8
    if (cpu.flags.zf)
    {
        goto L_0x0047e4e8;
    }
    // 0047e2f5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0047e2fa:
    // 0047e2fa  6b4c24141c             -imul ecx, dword ptr [esp + 0x14], 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0047e2ff  6689500a               -mov word ptr [eax + 0xa], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0047e303  8b15c8754d00           -mov edx, dword ptr [0x4d75c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076424) /* 0x4d75c8 */);
    // 0047e309  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e30b  833a00                 +cmp dword ptr [edx], 0
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
    // 0047e30e  0f84de010000           -je 0x47e4f2
    if (cpu.flags.zf)
    {
        goto L_0x0047e4f2;
    }
L_0x0047e314:
    // 0047e314  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047e317  8b15fa0e5600           -mov edx, dword ptr [0x560efa]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5639930) /* 0x560efa */);
    // 0047e31d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047e320  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0047e323  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e327  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047e32b  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e32f  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e332  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e335  83c524                 -add ebp, 0x24
    (cpu.ebp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e338  40                     -inc eax
    (cpu.eax)++;
    // 0047e339  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047e33c  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0047e340  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047e344  39c8                   +cmp eax, ecx
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
    // 0047e346  0f8cf5feffff           -jl 0x47e241
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e241;
    }
L_0x0047e34c:
    // 0047e34c  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047e350  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e354  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e358  8904d5fc2f5400         -mov dword ptr [edx*8 + 0x542ffc], eax
    app->getMemory<x86::reg32>(x86::reg32(5517308) /* 0x542ffc */ + cpu.edx * 8) = cpu.eax;
    // 0047e35f  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047e362  49                     -dec ecx
    (cpu.ecx)--;
    // 0047e363  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0047e36a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e36c  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e370  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e373  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e375  8904d500305400         -mov dword ptr [edx*8 + 0x543000], eax
    app->getMemory<x86::reg32>(x86::reg32(5517312) /* 0x543000 */ + cpu.edx * 8) = cpu.eax;
    // 0047e37c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047e382  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e385  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e386  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e387  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e388  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047e38b:
    // 0047e38b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047e38d  e9e4fdffff             -jmp 0x47e176
    goto L_0x0047e176;
L_0x0047e392:
    // 0047e392  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e394  e91dfeffff             -jmp 0x47e1b6
    goto L_0x0047e1b6;
L_0x0047e399:
    // 0047e399  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e39b  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047e39d  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e3a0  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e3a4  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3a6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3a8  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047e3ab  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047e3ae  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e3b1  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e3b5  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3b7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3b9  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0047e3bc  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e3bf  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e3c2  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e3c6  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e3c8  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e3cb  8a5202                 -mov dl, byte ptr [edx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e3ce  e907ffffff             -jmp 0x47e2da
    goto L_0x0047e2da;
L_0x0047e3d3:
    // 0047e3d3  c7400420000000         -mov dword ptr [eax + 4], 0x20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 32 /*0x20*/;
    // 0047e3da  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0047e3dd  743a                   -je 0x47e419
    if (cpu.flags.zf)
    {
        goto L_0x0047e419;
    }
    // 0047e3df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3e1  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047e3e3  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e3e6  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e3ea  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3ee  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047e3f1  8a5a03                 -mov bl, byte ptr [edx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0047e3f4  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e3f7  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e3fb  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3ff  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0047e402  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e405  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e408  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e40c  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e40e  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e411  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047e414  e9c1feffff             -jmp 0x47e2da
    goto L_0x0047e2da;
L_0x0047e419:
    // 0047e419  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047e41b:
    // 0047e41b  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047e41d  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e420  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e424  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e426  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e428  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047e42b  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047e42e  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e431  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e435  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e437  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e439  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0047e43c  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e43f  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e442  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e446  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e448  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e44b  8a5203                 -mov dl, byte ptr [edx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0047e44e  e987feffff             -jmp 0x47e2da
    goto L_0x0047e2da;
L_0x0047e453:
    // 0047e453  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0047e456  7448                   -je 0x47e4a0
    if (cpu.flags.zf)
    {
        goto L_0x0047e4a0;
    }
    // 0047e458  c740040c000000         -mov dword ptr [eax + 4], 0xc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
    // 0047e45f  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0047e462  0f8540feffff           -jne 0x47e2a8
    if (!cpu.flags.zf)
    {
        goto L_0x0047e2a8;
    }
    // 0047e468  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047e46a  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e46d  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e471  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e473  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e475  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047e478  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047e47b  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e47e  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e482  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e484  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e486  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0047e489  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e48c  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e48f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e493  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e495  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e498  8a5202                 -mov dl, byte ptr [edx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e49b  e93afeffff             -jmp 0x47e2da
    goto L_0x0047e2da;
L_0x0047e4a0:
    // 0047e4a0  c7400408000000         -mov dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0047e4a7  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0047e4aa  0f846bffffff           -je 0x47e41b
    if (cpu.flags.zf)
    {
        goto L_0x0047e41b;
    }
    // 0047e4b0  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047e4b2  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e4b5  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e4b9  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e4bb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e4bd  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047e4c0  8a5a03                 -mov bl, byte ptr [edx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0047e4c3  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e4c6  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e4ca  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e4cc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e4ce  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0047e4d1  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0047e4d4  6bdb30                 -imul ebx, ebx, 0x30
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(48 /*0x30*/)));
    // 0047e4d7  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e4db  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e4dd  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0047e4e0  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047e4e3  e9f2fdffff             -jmp 0x47e2da
    goto L_0x0047e2da;
L_0x0047e4e8:
    // 0047e4e8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047e4ed  e908feffff             -jmp 0x47e2fa
    goto L_0x0047e2fa;
L_0x0047e4f2:
    // 0047e4f2  8b1510ed4f00           -mov edx, dword ptr [0x4fed10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5238032) /* 0x4fed10 */);
    // 0047e4f8  e917feffff             -jmp 0x47e314
    goto L_0x0047e314;
L_0x0047e4fd:
    // 0047e4fd  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047e4ff  e84cfefeff             -call 0x46e350
    cpu.esp -= 4;
    sub_46e350(app, cpu);
    if (cpu.terminate) return;
    // 0047e504  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047e508  8d3cf5fc2f5400         -lea edi, [esi*8 + 0x542ffc]
    cpu.edi = x86::reg32(x86::reg32(5517308) /* 0x542ffc */ + cpu.esi * 8);
    // 0047e50f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047e511  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047e512  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047e513  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047e516  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e517  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e518  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e519  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_47e520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e520  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e521  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e522  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e523  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047e526  8b7c2440               -mov edi, dword ptr [esp + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047e52a  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047e52e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047e530  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047e534  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047e536  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047e53a  a158734d00             -mov eax, dword ptr [0x4d7358]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5075800) /* 0x4d7358 */);
    // 0047e53f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047e542  8b1ddc0e5600           -mov ebx, dword ptr [0x560edc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5639900) /* 0x560edc */);
    // 0047e548  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e54d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e54f  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0047e551  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e557  39d8                   +cmp eax, ebx
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
    // 0047e559  0f8d7b000000           -jge 0x47e5da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e5da;
    }
L_0x0047e55f:
    // 0047e55f  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0047e562  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047e566  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047e568  7467                   -je 0x47e5d1
    if (cpu.flags.zf)
    {
        goto L_0x0047e5d1;
    }
    // 0047e56a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e56c  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e570  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0047e574  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e576  7e59                   -jle 0x47e5d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e5d1;
    }
L_0x0047e578:
    // 0047e578  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047e57b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047e57d  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047e580  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e582  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e584  7558                   -jne 0x47e5de
    if (!cpu.flags.zf)
    {
        goto L_0x0047e5de;
    }
    // 0047e586  8b1ddc0e5600           -mov ebx, dword ptr [0x560edc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5639900) /* 0x560edc */);
    // 0047e58c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047e590  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0047e593  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e595  a1dc0e5600             -mov eax, dword ptr [0x560edc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639900) /* 0x560edc */);
    // 0047e59a  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e59d  c7412800000000         -mov dword ptr [ecx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0047e5a4  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5a6  a1dc0e5600             -mov eax, dword ptr [0x560edc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639900) /* 0x560edc */);
    // 0047e5ab  c7412c00000000         -mov dword ptr [ecx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
L_0x0047e5b2:
    // 0047e5b2  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5b4  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0047e5b7  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047e5bb  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e5bf  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047e5c2  83c706                 -add edi, 6
    (cpu.edi) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0047e5c5  40                     -inc eax
    (cpu.eax)++;
    // 0047e5c6  83c130                 -add ecx, 0x30
    (cpu.ecx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047e5c9  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047e5cd  39d0                   +cmp eax, edx
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
    // 0047e5cf  7ca7                   -jl 0x47e578
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e578;
    }
L_0x0047e5d1:
    // 0047e5d1  83c430                 +add esp, 0x30
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
    // 0047e5d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5d7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047e5da:
    // 0047e5da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047e5dc  eb81                   -jmp 0x47e55f
    goto L_0x0047e55f;
L_0x0047e5de:
    // 0047e5de  0fbf07                 -movsx eax, word ptr [edi]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edi)));
    // 0047e5e1  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047e5e4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e5e7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5e9  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047e5ed  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0047e5ef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047e5f2  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047e5f5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e5f8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e5fa  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047e5fe  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0047e601  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047e604  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047e607  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e60a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e60c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e610  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047e614  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e616  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e618  e81bb40100             -call 0x499a38
    cpu.esp -= 4;
    sub_499a38(app, cpu);
    if (cpu.terminate) return;
    // 0047e61d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e621  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e623  0f85bb000000           -jne 0x47e6e4
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6e4;
    }
    // 0047e629  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 0047e62e  0f85b0000000           -jne 0x47e6e4
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6e4;
    }
    // 0047e634  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 0047e639  0f85a5000000           -jne 0x47e6e4
    if (!cpu.flags.zf)
    {
        goto L_0x0047e6e4;
    }
    // 0047e63f  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 0047e644  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047e648  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x0047e64c:
    // 0047e64c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e650  e89bda0100             -call 0x49c0f0
    cpu.esp -= 4;
    sub_49c0f0(app, cpu);
    if (cpu.terminate) return;
    // 0047e655  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e657  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e65a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0047e65c  e88fda0100             -call 0x49c0f0
    cpu.esp -= 4;
    sub_49c0f0(app, cpu);
    if (cpu.terminate) return;
    // 0047e661  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e663  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047e667  c1e309                 -shl ebx, 9
    cpu.ebx <<= 9 /*0x9*/ % 32;
    // 0047e66a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e66c  0f8592000000           -jne 0x47e704
    if (!cpu.flags.zf)
    {
        goto L_0x0047e704;
    }
    // 0047e672  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e676  81fa00800000           +cmp edx, 0x8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e67c  0f8f79000000           -jg 0x47e6fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047e6fb;
    }
L_0x0047e682:
    // 0047e682  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047e684:
    // 0047e684  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0047e688  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0047e68c  d90554d34c00           -fld dword ptr [0x4cd354]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5034836) /* 0x4cd354 */)));
    // 0047e692  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0047e696  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0047e698  db442428               -fild dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 0047e69c  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047e69e  d9592c                 -fstp dword ptr [ecx + 0x2c]
    app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e6a1  d95928                 -fstp dword ptr [ecx + 0x28]
    app->getMemory<float>(cpu.ecx + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e6a4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e6a8  0500000100             -add eax, 0x10000
    (cpu.eax) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0047e6ad  8b1ddc0e5600           -mov ebx, dword ptr [0x560edc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5639900) /* 0x560edc */);
    // 0047e6b3  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047e6b5  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0047e6b8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047e6bb  3dff000000             +cmp eax, 0xff
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
    // 0047e6c0  7d04                   -jge 0x47e6c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e6c6;
    }
    // 0047e6c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e6c4  7c4f                   -jl 0x47e715
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e715;
    }
L_0x0047e6c6:
    // 0047e6c6  3dff000000             +cmp eax, 0xff
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
    // 0047e6cb  7d4c                   -jge 0x47e719
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e719;
    }
L_0x0047e6cd:
    // 0047e6cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e6cf  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047e6d3  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0047e6d6  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e6d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e6da  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0047e6dd  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047e6df  e9cefeffff             -jmp 0x47e5b2
    goto L_0x0047e5b2;
L_0x0047e6e4:
    // 0047e6e4  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e6e8  e833e6fdff             -call 0x45cd20
    cpu.esp -= 4;
    sub_45cd20(app, cpu);
    if (cpu.terminate) return;
    // 0047e6ed  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e6f1  e8aae7fdff             -call 0x45cea0
    cpu.esp -= 4;
    sub_45cea0(app, cpu);
    if (cpu.terminate) return;
    // 0047e6f6  e951ffffff             -jmp 0x47e64c
    goto L_0x0047e64c;
L_0x0047e6fb:
    // 0047e6fb  8d84120000ffff         -lea eax, [edx + edx - 0x10000]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-65536) /* -0x10000 */ + cpu.edx * 1);
    // 0047e702  eb80                   -jmp 0x47e684
    goto L_0x0047e684;
L_0x0047e704:
    // 0047e704  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e708  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e70a  0f8f74ffffff           -jg 0x47e684
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047e684;
    }
    // 0047e710  e96dffffff             -jmp 0x47e682
    goto L_0x0047e682;
L_0x0047e715:
    // 0047e715  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e717  ebb4                   -jmp 0x47e6cd
    goto L_0x0047e6cd;
L_0x0047e719:
    // 0047e719  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0047e71e  ebad                   -jmp 0x47e6cd
    goto L_0x0047e6cd;
}

/* align: skip  */
void Application::sub_47e720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e722  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e723  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e725  30e5                   -xor ch, ah
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047e727  66c1f804               -sar ax, 4
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (4 /*0x4*/ % 32));
    // 0047e72b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e72d  30e6                   -xor dh, ah
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047e72f  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0047e733  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e735  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047e737  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0047e73a  80e307                 -and bl, 7
    cpu.bl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0047e73d  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0047e741  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e743  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e745  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047e747  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0047e74b  80e307                 -and bl, 7
    cpu.bl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0047e74e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047e750  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e752  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0047e754  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e756  66c1ea02               -shr dx, 2
    cpu.dx >>= 2 /*0x2*/ % 32;
    // 0047e75a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e75c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047e75e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047e761  c1e307                 -shl ebx, 7
    cpu.ebx <<= 7 /*0x7*/ % 32;
    // 0047e764  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e766  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e768  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0047e76b  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e76d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e76f  c1e00d                 -shl eax, 0xd
    cpu.eax <<= 13 /*0xd*/ % 32;
    // 0047e772  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0047e775  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e777  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e779  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e77b  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 0047e77e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e780  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047e783  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047e786  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047e788  83c032                 -add eax, 0x32
    (cpu.eax) += x86::reg32(x86::sreg32(50 /*0x32*/));
    // 0047e78b  66890dfc0e5600         -mov word ptr [0x560efc], cx
    app->getMemory<x86::reg16>(x86::reg32(5639932) /* 0x560efc */) = cpu.cx;
    // 0047e792  a3dc0e5600             -mov dword ptr [0x560edc], eax
    app->getMemory<x86::reg32>(x86::reg32(5639900) /* 0x560edc */) = cpu.eax;
    // 0047e797  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e798  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e799  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e79a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e7a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e7a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e7a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e7a3  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047e7a6  8b6c2448               -mov ebp, dword ptr [esp + 0x48]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047e7aa  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047e7ae  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047e7b2  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0047e7b6  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e7b9  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0047e7bd  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0047e7c1:
    // 0047e7c1  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047e7c5  4a                     -dec edx
    (cpu.edx)--;
    // 0047e7c6  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0047e7ca  83faff                 +cmp edx, -1
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
    // 0047e7cd  7509                   -jne 0x47e7d8
    if (!cpu.flags.zf)
    {
        goto L_0x0047e7d8;
    }
    // 0047e7cf  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047e7d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e7d5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047e7d8:
    // 0047e7d8  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047e7dc  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0047e7df  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e7e2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047e7e5  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047e7e9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e7eb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047e7ee  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e7f1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e7f5  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047e7f9  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047e7fc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047e7ff  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e803  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e806  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047e80a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047e80e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047e810  e823b20100             -call 0x499a38
    cpu.esp -= 4;
    sub_499a38(app, cpu);
    if (cpu.terminate) return;
    // 0047e815  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e819  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e81d  0318                   -add ebx, dword ptr [eax]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0047e81f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e823  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047e827  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047e82b  037004                 -add esi, dword ptr [eax + 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0047e82e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e832  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0047e836  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047e83a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047e83d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e83f  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0047e843  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 0047e846  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047e84a  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e84d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047e851  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047e857  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047e85a  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047e85e  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047e862  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e864  7508                   -jne 0x47e86e
    if (!cpu.flags.zf)
    {
        goto L_0x0047e86e;
    }
    // 0047e866  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x0047e86e:
    // 0047e86e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047e872  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047e876  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0047e87a  83c530                 -add ebp, 0x30
    (cpu.ebp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047e87d  db442434               -fild dword ptr [esp + 0x34]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 0047e881  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e885  d95c241c               -fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e889  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e88b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047e88d  c1eb0f                 -shr ebx, 0xf
    cpu.ebx >>= 15 /*0xf*/ % 32;
    // 0047e890  81e1000080ff           -and ecx, 0xff800000
    cpu.ecx &= x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
    // 0047e896  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047e89c  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0047e89e  8b1c9db4f74e00         -mov ebx, dword ptr [ebx*4 + 0x4ef7b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5175220) /* 0x4ef7b4 */ + cpu.ebx * 4);
    // 0047e8a5  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e8a7  891de4fb4e00           -mov dword ptr [0x4efbe4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5176292) /* 0x4efbe4 */) = cpu.ebx;
    // 0047e8ad  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 0047e8b3  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 0047e8b9  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 0047e8bf  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0047e8c1  d808                   -fmul dword ptr [eax]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax));
    // 0047e8c3  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 0047e8c9  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047e8cb  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e8cd  8d4c2420               -lea ecx, [esp + 0x20]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047e8d1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e8d5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047e8d7  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047e8da  d905b0304d00           -fld dword ptr [0x4d30b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058736) /* 0x4d30b0 */)));
    // 0047e8e0  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047e8e2  d905b4304d00           -fld dword ptr [0x4d30b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058740) /* 0x4d30b4 */)));
    // 0047e8e8  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047e8ea  d905cc304d00           -fld dword ptr [0x4d30cc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058764) /* 0x4d30cc */)));
    // 0047e8f0  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047e8f2  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 0047e8f5  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 0047e8f7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047e8f9  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047e8fb  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047e8fd  d905bc304d00           -fld dword ptr [0x4d30bc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058748) /* 0x4d30bc */)));
    // 0047e903  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047e905  d905b8304d00           -fld dword ptr [0x4d30b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058744) /* 0x4d30b8 */)));
    // 0047e90b  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047e90d  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e910  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e913  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047e915  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047e918  8b0dd4fb4e00           -mov ecx, dword ptr [0x4efbd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176276) /* 0x4efbd4 */);
    // 0047e91e  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047e923  7558                   -jne 0x47e97d
    if (!cpu.flags.zf)
    {
        goto L_0x0047e97d;
    }
    // 0047e925  39c8                   +cmp eax, ecx
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
    // 0047e927  7d54                   -jge 0x47e97d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e97d;
    }
    // 0047e929  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047e92c  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0047e931  8b0de0fb4e00           -mov ecx, dword ptr [0x4efbe0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176288) /* 0x4efbe0 */);
    // 0047e937  8b15dcfb4e00           -mov edx, dword ptr [0x4efbdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176284) /* 0x4efbdc */);
    // 0047e93d  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047e942  750d                   -jne 0x47e951
    if (!cpu.flags.zf)
    {
        goto L_0x0047e951;
    }
    // 0047e944  39c8                   +cmp eax, ecx
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
    // 0047e946  7c09                   -jl 0x47e951
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e951;
    }
    // 0047e948  39d0                   +cmp eax, edx
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
    // 0047e94a  7e09                   -jle 0x47e955
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e955;
    }
    // 0047e94c  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0047e94f  eb04                   -jmp 0x47e955
    goto L_0x0047e955;
L_0x0047e951:
    // 0047e951  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e954  90                     -nop 
    ;
L_0x0047e955:
    // 0047e955  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047e957  90                     -nop 
    ;
    // 0047e958  8b0dd8fb4e00           -mov ecx, dword ptr [0x4efbd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176280) /* 0x4efbd8 */);
    // 0047e95e  8b15e8fb4e00           -mov edx, dword ptr [0x4efbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176296) /* 0x4efbe8 */);
    // 0047e964  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047e969  750d                   -jne 0x47e978
    if (!cpu.flags.zf)
    {
        goto L_0x0047e978;
    }
    // 0047e96b  39c8                   +cmp eax, ecx
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
    // 0047e96d  7c09                   -jl 0x47e978
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e978;
    }
    // 0047e96f  39d0                   +cmp eax, edx
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
    // 0047e971  7e0f                   -jle 0x47e982
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e982;
    }
    // 0047e973  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0047e976  eb0a                   -jmp 0x47e982
    goto L_0x0047e982;
L_0x0047e978:
    // 0047e978  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047e97b  eb05                   -jmp 0x47e982
    goto L_0x0047e982;
L_0x0047e97d:
    // 0047e97d  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0047e982:
    // 0047e982  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0047e984  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047e988  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047e98c  668b45f4               -mov ax, word ptr [ebp - 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047e990  83c130                 -add ecx, 0x30
    (cpu.ecx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047e993  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047e995  83c306                 -add ebx, 6
    (cpu.ebx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0047e998  2410                   +and al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0047e99a  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0047e99e  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0047e9a2  668945de               -mov word ptr [ebp - 0x22], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-34) /* -0x22 */) = cpu.ax;
    // 0047e9a6  e916feffff             -jmp 0x47e7c1
    goto L_0x0047e7c1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e9b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e9b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e9b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e9b3  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0047e9b6  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047e9ba  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047e9be  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0047e9c2  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047e9c6  8d4510                 -lea eax, [ebp + 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047e9c9  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0047e9cd  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0047e9d1:
    // 0047e9d1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047e9d5  4a                     -dec edx
    (cpu.edx)--;
    // 0047e9d6  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047e9da  83faff                 +cmp edx, -1
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
    // 0047e9dd  7509                   -jne 0x47e9e8
    if (!cpu.flags.zf)
    {
        goto L_0x0047e9e8;
    }
    // 0047e9df  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0047e9e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e9e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e9e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e9e5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047e9e8:
    // 0047e9e8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e9ea  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e9ee  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047e9f2  e841b00100             -call 0x499a38
    cpu.esp -= 4;
    sub_499a38(app, cpu);
    if (cpu.terminate) return;
    // 0047e9f7  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047e9fb  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e9fe  0318                   -add ebx, dword ptr [eax]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0047ea00  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047ea04  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047ea07  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ea0b  037004                 -add esi, dword ptr [eax + 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 0047ea0e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047ea12  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047ea16  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ea1a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ea1d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ea1f  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0047ea23  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 0047ea26  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ea2a  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047ea2d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ea31  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047ea37  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047ea3a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ea3e  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047ea42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ea44  7508                   -jne 0x47ea4e
    if (!cpu.flags.zf)
    {
        goto L_0x0047ea4e;
    }
    // 0047ea46  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0047ea4e:
    // 0047ea4e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ea52  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ea56  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047ea5a  83c530                 -add ebp, 0x30
    (cpu.ebp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047ea5d  db442428               -fild dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 0047ea61  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ea65  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ea69  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ea6b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047ea6d  c1eb0f                 -shr ebx, 0xf
    cpu.ebx >>= 15 /*0xf*/ % 32;
    // 0047ea70  81e1000080ff           -and ecx, 0xff800000
    cpu.ecx &= x86::reg32(x86::sreg32(4286578688 /*0xff800000*/));
    // 0047ea76  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047ea7c  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 0047ea7e  8b1c9db4f74e00         -mov ebx, dword ptr [ebx*4 + 0x4ef7b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5175220) /* 0x4ef7b4 */ + cpu.ebx * 4);
    // 0047ea85  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ea87  891de4fb4e00           -mov dword ptr [0x4efbe4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5176292) /* 0x4efbe4 */) = cpu.ebx;
    // 0047ea8d  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 0047ea93  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 0047ea99  d80de4fb4e00           -fmul dword ptr [0x4efbe4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5176292) /* 0x4efbe4 */));
    // 0047ea9f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0047eaa1  d808                   -fmul dword ptr [eax]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax));
    // 0047eaa3  d82dc8304d00           -fsubr dword ptr [0x4d30c8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(x86::reg32(5058760) /* 0x4d30c8 */)) - cpu.fpu.st(0);
    // 0047eaa9  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047eaab  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047eaad  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047eab1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047eab3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047eab5  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047eab8  d905b0304d00           -fld dword ptr [0x4d30b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058736) /* 0x4d30b0 */)));
    // 0047eabe  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047eac0  d905b4304d00           -fld dword ptr [0x4d30b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058740) /* 0x4d30b4 */)));
    // 0047eac6  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047eac8  d905cc304d00           -fld dword ptr [0x4d30cc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058764) /* 0x4d30cc */)));
    // 0047eace  d809                   -fmul dword ptr [ecx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx));
    // 0047ead0  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 0047ead3  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 0047ead5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047ead7  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047ead9  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047eadb  d905bc304d00           -fld dword ptr [0x4d30bc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058748) /* 0x4d30bc */)));
    // 0047eae1  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047eae3  d905b8304d00           -fld dword ptr [0x4d30b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5058744) /* 0x4d30b8 */)));
    // 0047eae9  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047eaeb  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047eaee  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047eaf1  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047eaf3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047eaf6  8b0dd4fb4e00           -mov ecx, dword ptr [0x4efbd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176276) /* 0x4efbd4 */);
    // 0047eafc  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047eb01  7558                   -jne 0x47eb5b
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb5b;
    }
    // 0047eb03  39c8                   +cmp eax, ecx
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
    // 0047eb05  7d54                   -jge 0x47eb5b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047eb5b;
    }
    // 0047eb07  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047eb0a  bb00000000             -mov ebx, 0
    cpu.ebx = 0 /*0x0*/;
    // 0047eb0f  8b0de0fb4e00           -mov ecx, dword ptr [0x4efbe0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176288) /* 0x4efbe0 */);
    // 0047eb15  8b15dcfb4e00           -mov edx, dword ptr [0x4efbdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176284) /* 0x4efbdc */);
    // 0047eb1b  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047eb20  750d                   -jne 0x47eb2f
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb2f;
    }
    // 0047eb22  39c8                   +cmp eax, ecx
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
    // 0047eb24  7c09                   -jl 0x47eb2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eb2f;
    }
    // 0047eb26  39d0                   +cmp eax, edx
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
    // 0047eb28  7e09                   -jle 0x47eb33
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047eb33;
    }
    // 0047eb2a  83cb04                 +or ebx, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/))));
    // 0047eb2d  eb04                   -jmp 0x47eb33
    goto L_0x0047eb33;
L_0x0047eb2f:
    // 0047eb2f  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047eb32  90                     -nop 
    ;
L_0x0047eb33:
    // 0047eb33  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047eb35  90                     -nop 
    ;
    // 0047eb36  8b0dd8fb4e00           -mov ecx, dword ptr [0x4efbd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5176280) /* 0x4efbd8 */);
    // 0047eb3c  8b15e8fb4e00           -mov edx, dword ptr [0x4efbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5176296) /* 0x4efbe8 */);
    // 0047eb42  a900000080             +test eax, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483648 /*0x80000000*/));
    // 0047eb47  750d                   -jne 0x47eb56
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb56;
    }
    // 0047eb49  39c8                   +cmp eax, ecx
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
    // 0047eb4b  7c09                   -jl 0x47eb56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eb56;
    }
    // 0047eb4d  39d0                   +cmp eax, edx
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
    // 0047eb4f  7e0f                   -jle 0x47eb60
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047eb60;
    }
    // 0047eb51  83cb02                 +or ebx, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0047eb54  eb0a                   -jmp 0x47eb60
    goto L_0x0047eb60;
L_0x0047eb56:
    // 0047eb56  83cb01                 +or ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 0047eb59  eb05                   -jmp 0x47eb60
    goto L_0x0047eb60;
L_0x0047eb5b:
    // 0047eb5b  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0047eb60:
    // 0047eb60  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 0047eb62  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047eb66  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047eb6a  668b45f4               -mov ax, word ptr [ebp - 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0047eb6e  83c130                 -add ecx, 0x30
    (cpu.ecx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047eb71  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047eb73  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047eb76  2410                   +and al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0047eb78  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0047eb7c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047eb80  668945de               -mov word ptr [ebp - 0x22], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-34) /* -0x22 */) = cpu.ax;
    // 0047eb84  e948feffff             -jmp 0x47e9d1
    goto L_0x0047e9d1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47eb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eb90  e9a3ae0100             -jmp 0x499a38
    return sub_499a38(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47eba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eba2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eba3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047eba5  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047eba8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ebaa  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ebac  83fa01                 +cmp edx, 1
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
    // 0047ebaf  741f                   -je 0x47ebd0
    if (cpu.flags.zf)
    {
        goto L_0x0047ebd0;
    }
    // 0047ebb1  833dd8ff500001         +cmp dword ptr [0x50ffd8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ebb8  743a                   -je 0x47ebf4
    if (cpu.flags.zf)
    {
        goto L_0x0047ebf4;
    }
    // 0047ebba  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047ebbd  e8aeaffcff             -call 0x449b70
    cpu.esp -= 4;
    sub_449b70(app, cpu);
    if (cpu.terminate) return;
    // 0047ebc2  83f805                 +cmp eax, 5
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
    // 0047ebc5  7575                   -jne 0x47ec3c
    if (!cpu.flags.zf)
    {
        goto L_0x0047ec3c;
    }
L_0x0047ebc7:
    // 0047ebc7  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047ebca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ebd0:
    // 0047ebd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ebd1  8b506c                 -mov edx, dword ptr [eax + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 0047ebd4  83c228                 -add edx, 0x28
    (cpu.edx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047ebd7  8b4068                 -mov eax, dword ptr [eax + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0047ebda  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ebdb  05e6010000             +add eax, 0x1e6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(486 /*0x1e6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ebe0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ebe1  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0047ebe3  b946000000             -mov ecx, 0x46
    cpu.ecx = 70 /*0x46*/;
    // 0047ebe8  bb96000000             -mov ebx, 0x96
    cpu.ebx = 150 /*0x96*/;
    // 0047ebed  e84e010000             -call 0x47ed40
    cpu.esp -= 4;
    sub_47ed40(app, cpu);
    if (cpu.terminate) return;
    // 0047ebf2  ebd3                   -jmp 0x47ebc7
    goto L_0x0047ebc7;
L_0x0047ebf4:
    // 0047ebf4  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ebf8  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ebfc  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ec00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec01  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ec05  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047ec08  e8839bfaff             -call 0x428790
    cpu.esp -= 4;
    sub_428790(app, cpu);
    if (cpu.terminate) return;
    // 0047ec0d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ec0f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ec13  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ec17  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ec1b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ec1f  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ec23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ec24  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047ec26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec27  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047ec29  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ec2b  29d0                   +sub eax, edx
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
    // 0047ec2d  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0047ec2f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ec31  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ec35  e806010000             -call 0x47ed40
    cpu.esp -= 4;
    sub_47ed40(app, cpu);
    if (cpu.terminate) return;
    // 0047ec3a  eb8b                   -jmp 0x47ebc7
    goto L_0x0047ebc7;
L_0x0047ec3c:
    // 0047ec3c  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ec40  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ec44  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ec48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec49  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ec4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ec4f  e83c9bfaff             -call 0x428790
    cpu.esp -= 4;
    sub_428790(app, cpu);
    if (cpu.terminate) return;
    // 0047ec54  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047ec57  e814affcff             -call 0x449b70
    cpu.esp -= 4;
    sub_449b70(app, cpu);
    if (cpu.terminate) return;
    // 0047ec5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ec5e  7514                   -jne 0x47ec74
    if (!cpu.flags.zf)
    {
        goto L_0x0047ec74;
    }
    // 0047ec60  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ec64  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ec66  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0047ec6b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ec6e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047ec70  29442414               -sub dword ptr [esp + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047ec74:
    // 0047ec74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ec75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ec77  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ec7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ec7c  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ec80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ec81  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ec85  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047ec89  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0047ec8b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ec8d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ec8f  e8ac000000             -call 0x47ed40
    cpu.esp -= 4;
    sub_47ed40(app, cpu);
    if (cpu.terminate) return;
    // 0047ec94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec95  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047ec98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_47eca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eca2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eca3  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047eca6  833dd8ff500001         +cmp dword ptr [0x50ffd8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ecad  754f                   -jne 0x47ecfe
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecfe;
    }
    // 0047ecaf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ecb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ecb1  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ecb5  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ecb9  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ecbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ecbe  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047ecc1  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ecc5  e8c69afaff             -call 0x428790
    cpu.esp -= 4;
    sub_428790(app, cpu);
    if (cpu.terminate) return;
    // 0047ecca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eccc  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ecd0  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ecd4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ecd8  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ecdc  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ece0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ece1  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047ece3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ece5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ece6  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ece8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ecea  6a78                   -push 0x78
    app->getMemory<x86::reg32>(cpu.esp-4) = 120 /*0x78*/;
    cpu.esp -= 4;
    // 0047ecec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ecee  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ecf0  e84b000000             -call 0x47ed40
    cpu.esp -= 4;
    sub_47ed40(app, cpu);
    if (cpu.terminate) return;
    // 0047ecf5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecf7  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047ecfa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecfb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecfc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecfd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ecfe:
    // 0047ecfe  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ed02  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ed06  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ed0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ed0b  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ed0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ed11  e87a9afaff             -call 0x428790
    cpu.esp -= 4;
    sub_428790(app, cpu);
    if (cpu.terminate) return;
    // 0047ed16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ed18  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ed1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ed1d  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ed21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ed22  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047ed26  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047ed2a  6a78                   -push 0x78
    app->getMemory<x86::reg32>(cpu.esp-4) = 120 /*0x78*/;
    cpu.esp -= 4;
    // 0047ed2c  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ed30  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047ed34  e807000000             -call 0x47ed40
    cpu.esp -= 4;
    sub_47ed40(app, cpu);
    if (cpu.terminate) return;
    // 0047ed39  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047ed3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ed40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ed41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ed42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ed43  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047ed46  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ed4a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047ed4e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047ed50  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047ed54  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047ed56  e8b5d30100             -call 0x49c110
    cpu.esp -= 4;
    sub_49c110(app, cpu);
    if (cpu.terminate) return;
    // 0047ed5b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ed5d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ed5f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ed62  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ed64  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047ed66  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ed68  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ed6b  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047ed6d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ed70  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0047ed73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ed75  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ed78  c1e204                 +shl edx, 4
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
    // 0047ed7b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047ed7d  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047ed80  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047ed83  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ed85  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ed87  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0047ed8b  e8e4d40100             -call 0x49c274
    cpu.esp -= 4;
    sub_49c274(app, cpu);
    if (cpu.terminate) return;
    // 0047ed90  68ad55033b             -push 0x3b0355ad
    app->getMemory<x86::reg32>(cpu.esp-4) = 990074285 /*0x3b0355ad*/;
    cpu.esp -= 4;
    // 0047ed95  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0047ed99  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047ed9e  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047eda2  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047eda6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047edaa  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0047edae  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0047edb2  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047edb6  d8442410               -fadd dword ptr [esp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0047edba  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047edbd  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047edc1  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047edc5  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047edc8  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 0047edcc  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047edd0  d95c2418               -fstp dword ptr [esp + 0x18]
    app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047edd4  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047edd8  d9442418               -fld dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0047eddc  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 0047ede0  d95c2424               -fstp dword ptr [esp + 0x24]
    app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ede4  d8442424               -fadd dword ptr [esp + 0x24]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */));
    // 0047ede8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047edeb  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047edee  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0047edf2  ff74242c               -push dword ptr [esp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 0047edf6  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047edfa  e85131fbff             -call 0x431f50
    cpu.esp -= 4;
    sub_431f50(app, cpu);
    if (cpu.terminate) return;
    // 0047edff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ee00  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ee04  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0047ee08  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047ee0c  ff742414               -push dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0047ee10  db442424               -fild dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 0047ee14  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ee17  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 0047ee1b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ee1e  db442428               -fild dword ptr [esp + 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */))));
    // 0047ee22  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ee25  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 0047ee29  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ee2c  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0047ee30  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ee33  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047ee37  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0047ee3b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ee3e  db442430               -fild dword ptr [esp + 0x30]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 0047ee42  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ee45  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ee48  e8d32ffbff             -call 0x431e20
    cpu.esp -= 4;
    sub_431e20(app, cpu);
    if (cpu.terminate) return;
    // 0047ee4d  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047ee50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee53  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ee60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ee60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ee61  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ee63  891524894d00           -mov dword ptr [0x4d8924], edx
    app->getMemory<x86::reg32>(x86::reg32(5081380) /* 0x4d8924 */) = cpu.edx;
    // 0047ee69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ee70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ee70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ee71  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ee73  891524894d00           -mov dword ptr [0x4d8924], edx
    app->getMemory<x86::reg32>(x86::reg32(5081380) /* 0x4d8924 */) = cpu.edx;
    // 0047ee79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ee80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ee80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ee81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ee82  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047ee87  8b1d44894d00           -mov ebx, dword ptr [0x4d8944]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081412) /* 0x4d8944 */);
    // 0047ee8d  a348894d00             -mov dword ptr [0x4d8948], eax
    app->getMemory<x86::reg32>(x86::reg32(5081416) /* 0x4d8948 */) = cpu.eax;
    // 0047ee92  89154c894d00           -mov dword ptr [0x4d894c], edx
    app->getMemory<x86::reg32>(x86::reg32(5081420) /* 0x4d894c */) = cpu.edx;
    // 0047ee98  890d40894d00           -mov dword ptr [0x4d8940], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081408) /* 0x4d8940 */) = cpu.ecx;
    // 0047ee9e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047eea0  7403                   -je 0x47eea5
    if (cpu.flags.zf)
    {
        goto L_0x0047eea5;
    }
    // 0047eea2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eea3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eea4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047eea5:
    // 0047eea5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eea6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eea7  6800f94700             -push 0x47f900
    app->getMemory<x86::reg32>(cpu.esp-4) = 4716800 /*0x47f900*/;
    cpu.esp -= 4;
    // 0047eeac  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047eeae  2eff1504444c00         -call dword ptr cs:[0x4c4404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998148) /* 0x4c4404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eeb5  a344894d00             -mov dword ptr [0x4d8944], eax
    app->getMemory<x86::reg32>(x86::reg32(5081412) /* 0x4d8944 */) = cpu.eax;
    // 0047eeba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eebb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eebc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_47eec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eec0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eec1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eec2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047eec4  8a252d1b5600           -mov ah, byte ptr [0x561b2d]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 0047eeca  891540894d00           -mov dword ptr [0x4d8940], edx
    app->getMemory<x86::reg32>(x86::reg32(5081408) /* 0x4d8940 */) = cpu.edx;
    // 0047eed0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047eed2  740a                   -je 0x47eede
    if (cpu.flags.zf)
    {
        goto L_0x0047eede;
    }
    // 0047eed4  8b0d44894d00           -mov ecx, dword ptr [0x4d8944]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081412) /* 0x4d8944 */);
    // 0047eeda  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047eedc  7503                   -jne 0x47eee1
    if (!cpu.flags.zf)
    {
        goto L_0x0047eee1;
    }
L_0x0047eede:
    // 0047eede  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eedf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eee0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047eee1:
    // 0047eee1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eee2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eee3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047eee5  2eff1518444c00         -call dword ptr cs:[0x4c4418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998168) /* 0x4c4418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eeec  893544894d00           -mov dword ptr [0x4d8944], esi
    app->getMemory<x86::reg32>(x86::reg32(5081412) /* 0x4d8944 */) = cpu.esi;
    // 0047eef2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eef3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eef4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eef5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ef00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ef01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ef02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ef03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ef04  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ef06  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047ef08  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047ef0a  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ef11  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047ef13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ef15  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ef18  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ef1a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047ef1c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ef1e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ef20  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ef27  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ef29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ef2b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ef2e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ef30  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047ef32  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047ef34  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047ef36  e805000000             -call 0x47ef40
    cpu.esp -= 4;
    sub_47ef40(app, cpu);
    if (cpu.terminate) return;
    // 0047ef3b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ef40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ef41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ef42  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047ef45  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ef47  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047ef4b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047ef4f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ef51  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 0047ef53  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047ef57  8b15241b5600           -mov edx, dword ptr [0x561b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047ef5d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ef5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ef60  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047ef64  2eff15d0434c00         -call dword ptr cs:[0x4c43d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998096) /* 0x4c43d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ef6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ef6c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ef70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ef71  2eff1588434c00         -call dword ptr cs:[0x4c4388]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998024) /* 0x4c4388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ef78  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ef7c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ef80  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0047ef82  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ef84  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ef88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ef89  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ef8d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ef8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ef90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ef91  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ef92  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ef94  8b2d241b5600           -mov ebp, dword ptr [0x561b24]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047ef9a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ef9b  2eff1500444c00         -call dword ptr cs:[0x4c4400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998144) /* 0x4c4400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047efa2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047efa4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efa5  a1241b5600             -mov eax, dword ptr [0x561b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047efaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efab  2eff15bc434c00         -call dword ptr cs:[0x4c43bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998076) /* 0x4c43bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047efb2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047efb4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efb5  8b15241b5600           -mov edx, dword ptr [0x561b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047efbb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047efbc  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047efc3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047efc7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efc8  8b0d241b5600           -mov ecx, dword ptr [0x561b24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047efce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047efcf  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047efd6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047efda  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047efdd  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047efdf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047efe3  a3e4165600             -mov dword ptr [0x5616e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */) = cpu.eax;
    // 0047efe8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047efec  891d341b5600           -mov dword ptr [0x561b34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */) = cpu.ebx;
    // 0047eff2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047eff4  8935381b5600           -mov dword ptr [0x561b38], esi
    app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */) = cpu.esi;
    // 0047effa  a3e8165600             -mov dword ptr [0x5616e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */) = cpu.eax;
    // 0047efff  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f002  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f003  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f004  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f010  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f011  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f012  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f013  833d241b560000         +cmp dword ptr [0x561b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f01a  7504                   -jne 0x47f020
    if (!cpu.flags.zf)
    {
        goto L_0x0047f020;
    }
    // 0047f01c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f01d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f01e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f01f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f020:
    // 0047f020  6890d64c00             -push 0x4cd690
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035664 /*0x4cd690*/;
    cpu.esp -= 4;
    // 0047f025  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047f027  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f02c  e8bfaf0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f031  8b0d38894d00           -mov ecx, dword ptr [0x4d8938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081400) /* 0x4d8938 */);
    // 0047f037  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f03a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f03c  740e                   -je 0x47f04c
    if (cpu.flags.zf)
    {
        goto L_0x0047f04c;
    }
    // 0047f03e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f040  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f042  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f043  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f045  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f04c:
    // 0047f04c  8b353c894d00           -mov esi, dword ptr [0x4d893c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5081404) /* 0x4d893c */);
    // 0047f052  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f054  740e                   -je 0x47f064
    if (cpu.flags.zf)
    {
        goto L_0x0047f064;
    }
    // 0047f056  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f058  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f05a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f05b  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 0047f05d  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f064:
    // 0047f064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f065  68a8d64c00             -push 0x4cd6a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035688 /*0x4cd6a8*/;
    cpu.esp -= 4;
    // 0047f06a  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0047f06c  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f071  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f073  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f075  e876af0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f07a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f07d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f07f  b866040000             -mov eax, 0x466
    cpu.eax = 1126 /*0x466*/;
    // 0047f084  e8c7150000             -call 0x480650
    cpu.esp -= 4;
    sub_480650(app, cpu);
    if (cpu.terminate) return;
    // 0047f089  833d241b560000         +cmp dword ptr [0x561b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f090  741a                   -je 0x47f0ac
    if (cpu.flags.zf)
    {
        goto L_0x0047f0ac;
    }
    // 0047f092  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047f094:
    // 0047f094  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f096  e8718f0000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0047f09b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f09d  e87e320000             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0047f0a2  3b15241b5600           +cmp edx, dword ptr [0x561b24]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f0a8  75ea                   -jne 0x47f094
    if (!cpu.flags.zf)
    {
        goto L_0x0047f094;
    }
    // 0047f0aa  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047f0ac:
    // 0047f0ac  68ccd64c00             -push 0x4cd6cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035724 /*0x4cd6cc*/;
    cpu.esp -= 4;
    // 0047f0b1  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0047f0b3  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f0b8  e833af0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f0bd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f0c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f0d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f0d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f0d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f0d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f0d4  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047f0d7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047f0d9  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0047f0dd  833d54894d0000         +cmp dword ptr [0x4d8954], 0
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
    // 0047f0e4  750a                   -jne 0x47f0f0
    if (!cpu.flags.zf)
    {
        goto L_0x0047f0f0;
    }
    // 0047f0e6  e87d920000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0047f0eb  a354894d00             -mov dword ptr [0x4d8954], eax
    app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */) = cpu.eax;
L_0x0047f0f0:
    // 0047f0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f0f1  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047f0f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f0f6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f0f7  6814d64c00             -push 0x4cd614
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035540 /*0x4cd614*/;
    cpu.esp -= 4;
    // 0047f0fc  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047f0fe  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f103  e8e8ae0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f108  8a25b0135600           -mov ah, byte ptr [0x5613b0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5641136) /* 0x5613b0 */);
    // 0047f10e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047f111  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047f113  0f85c2020000           -jne 0x47f3db
    if (!cpu.flags.zf)
    {
        goto L_0x0047f3db;
    }
    // 0047f119  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f11b  2eff15dc444c00         -call dword ptr cs:[0x4c44dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998364) /* 0x4c44dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f122  8b3d60894d00           -mov edi, dword ptr [0x4d8960]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */);
    // 0047f128  a3401b5600             -mov dword ptr [0x561b40], eax
    app->getMemory<x86::reg32>(x86::reg32(5643072) /* 0x561b40 */) = cpu.eax;
    // 0047f12d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f12f  750c                   -jne 0x47f13d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f13d;
    }
    // 0047f131  a10cea5600             -mov eax, dword ptr [0x56ea0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696012) /* 0x56ea0c */);
    // 0047f136  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047f138  a360894d00             -mov dword ptr [0x4d8960], eax
    app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */) = cpu.eax;
L_0x0047f13d:
    // 0047f13d  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0047f142  ba00fa4700             -mov edx, 0x47fa00
    cpu.edx = 4717056 /*0x47fa00*/;
    // 0047f147  8b3d64894d00           -mov edi, dword ptr [0x4d8964]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081444) /* 0x4d8964 */);
    // 0047f14d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f14f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047f152  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047f156  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f157  a1401b5600             -mov eax, dword ptr [0x561b40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643072) /* 0x561b40 */);
    // 0047f15c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047f160  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f161  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0047f165  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047f169  2eff15d4434c00         -call dword ptr cs:[0x4c43d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998100) /* 0x4c43d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f170  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047f172  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f174  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047f178  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047f17c  2eff1580434c00         -call dword ptr cs:[0x4c4380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998016) /* 0x4c4380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f183  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047f187  a160894d00             -mov eax, dword ptr [0x4d8960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */);
    // 0047f18c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047f190  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047f194  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047f196  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f197  2eff15e8434c00         -call dword ptr cs:[0x4c43e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998120) /* 0x4c43e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f19e  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0047f1a1  0f84ff010000           -je 0x47f3a6
    if (cpu.flags.zf)
    {
        goto L_0x0047f3a6;
    }
    // 0047f1a7  e8bc910000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0047f1ac  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0047f1b1  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0047f1b3  68b0014800             -push 0x4801b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4719024 /*0x4801b0*/;
    cpu.esp -= 4;
    // 0047f1b8  a398135600             -mov dword ptr [0x561398], eax
    app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */) = cpu.eax;
    // 0047f1bd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047f1bf  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 0047f1c1  890da0135600           -mov dword ptr [0x5613a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5641120) /* 0x5613a0 */) = cpu.ecx;
    // 0047f1c7  893594135600           -mov dword ptr [0x561394], esi
    app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */) = cpu.esi;
    // 0047f1cd  89359c135600           -mov dword ptr [0x56139c], esi
    app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */) = cpu.esi;
    // 0047f1d3  8815b0135600           -mov byte ptr [0x5613b0], dl
    app->getMemory<x86::reg8>(x86::reg32(5641136) /* 0x5613b0 */) = cpu.dl;
    // 0047f1d9  e802150000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f1de  6830014800             -push 0x480130
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718896 /*0x480130*/;
    cpu.esp -= 4;
    // 0047f1e3  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 0047f1e5  e8f6140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f1ea  68d0004800             -push 0x4800d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718800 /*0x4800d0*/;
    cpu.esp -= 4;
    // 0047f1ef  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0047f1f1  e8ea140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f1f6  68b0fe4700             -push 0x47feb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718256 /*0x47feb0*/;
    cpu.esp -= 4;
    // 0047f1fb  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0047f1fd  e8de140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f202  68b0fe4700             -push 0x47feb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718256 /*0x47feb0*/;
    cpu.esp -= 4;
    // 0047f207  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0047f209  e8d2140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f20e  6890004800             -push 0x480090
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718736 /*0x480090*/;
    cpu.esp -= 4;
    // 0047f213  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047f215  e8c6140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f21a  6820004800             -push 0x480020
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718624 /*0x480020*/;
    cpu.esp -= 4;
    // 0047f21f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f221  e8ba140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f226  6850fb4700             -push 0x47fb50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717392 /*0x47fb50*/;
    cpu.esp -= 4;
    // 0047f22b  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0047f22d  e8ae140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f232  6810fb4700             -push 0x47fb10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717328 /*0x47fb10*/;
    cpu.esp -= 4;
    // 0047f237  6885000000             -push 0x85
    app->getMemory<x86::reg32>(cpu.esp-4) = 133 /*0x85*/;
    cpu.esp -= 4;
    // 0047f23c  e89f140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f241  6830ff4700             -push 0x47ff30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718384 /*0x47ff30*/;
    cpu.esp -= 4;
    // 0047f246  6a1a                   -push 0x1a
    app->getMemory<x86::reg32>(cpu.esp-4) = 26 /*0x1a*/;
    cpu.esp -= 4;
    // 0047f248  e893140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f24d  68e0ff4700             -push 0x47ffe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718560 /*0x47ffe0*/;
    cpu.esp -= 4;
    // 0047f252  6812010000             -push 0x112
    app->getMemory<x86::reg32>(cpu.esp-4) = 274 /*0x112*/;
    cpu.esp -= 4;
    // 0047f257  e884140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f25c  6850004800             -push 0x480050
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718672 /*0x480050*/;
    cpu.esp -= 4;
    // 0047f261  6866040000             -push 0x466
    app->getMemory<x86::reg32>(cpu.esp-4) = 1126 /*0x466*/;
    cpu.esp -= 4;
    // 0047f266  e875140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f26b  6840fe4700             -push 0x47fe40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4718144 /*0x47fe40*/;
    cpu.esp -= 4;
    // 0047f270  6802010000             -push 0x102
    app->getMemory<x86::reg32>(cpu.esp-4) = 258 /*0x102*/;
    cpu.esp -= 4;
    // 0047f275  e866140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f27a  6820fd4700             -push 0x47fd20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717856 /*0x47fd20*/;
    cpu.esp -= 4;
    // 0047f27f  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0047f284  e857140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f289  6820fd4700             -push 0x47fd20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717856 /*0x47fd20*/;
    cpu.esp -= 4;
    // 0047f28e  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0047f293  e848140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f298  68d0fc4700             -push 0x47fcd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717776 /*0x47fcd0*/;
    cpu.esp -= 4;
    // 0047f29d  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 0047f2a2  e839140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f2a7  68d0fc4700             -push 0x47fcd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717776 /*0x47fcd0*/;
    cpu.esp -= 4;
    // 0047f2ac  6805010000             -push 0x105
    app->getMemory<x86::reg32>(cpu.esp-4) = 261 /*0x105*/;
    cpu.esp -= 4;
    // 0047f2b1  e82a140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f2b6  6860fc4700             -push 0x47fc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717664 /*0x47fc60*/;
    cpu.esp -= 4;
    // 0047f2bb  6801020000             -push 0x201
    app->getMemory<x86::reg32>(cpu.esp-4) = 513 /*0x201*/;
    cpu.esp -= 4;
    // 0047f2c0  e81b140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f2c5  6860fc4700             -push 0x47fc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717664 /*0x47fc60*/;
    cpu.esp -= 4;
    // 0047f2ca  6807020000             -push 0x207
    app->getMemory<x86::reg32>(cpu.esp-4) = 519 /*0x207*/;
    cpu.esp -= 4;
    // 0047f2cf  e80c140000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f2d4  6860fc4700             -push 0x47fc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717664 /*0x47fc60*/;
    cpu.esp -= 4;
    // 0047f2d9  6804020000             -push 0x204
    app->getMemory<x86::reg32>(cpu.esp-4) = 516 /*0x204*/;
    cpu.esp -= 4;
    // 0047f2de  e8fd130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f2e3  6860fc4700             -push 0x47fc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717664 /*0x47fc60*/;
    cpu.esp -= 4;
    // 0047f2e8  6803020000             -push 0x203
    app->getMemory<x86::reg32>(cpu.esp-4) = 515 /*0x203*/;
    cpu.esp -= 4;
    // 0047f2ed  e8ee130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f2f2  6860fc4700             -push 0x47fc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717664 /*0x47fc60*/;
    cpu.esp -= 4;
    // 0047f2f7  6809020000             -push 0x209
    app->getMemory<x86::reg32>(cpu.esp-4) = 521 /*0x209*/;
    cpu.esp -= 4;
    // 0047f2fc  e8df130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f301  6860fc4700             -push 0x47fc60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717664 /*0x47fc60*/;
    cpu.esp -= 4;
    // 0047f306  6806020000             -push 0x206
    app->getMemory<x86::reg32>(cpu.esp-4) = 518 /*0x206*/;
    cpu.esp -= 4;
    // 0047f30b  e8d0130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f310  68f0fb4700             -push 0x47fbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717552 /*0x47fbf0*/;
    cpu.esp -= 4;
    // 0047f315  6802020000             -push 0x202
    app->getMemory<x86::reg32>(cpu.esp-4) = 514 /*0x202*/;
    cpu.esp -= 4;
    // 0047f31a  e8c1130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f31f  68f0fb4700             -push 0x47fbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717552 /*0x47fbf0*/;
    cpu.esp -= 4;
    // 0047f324  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 0047f329  e8b2130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f32e  68f0fb4700             -push 0x47fbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717552 /*0x47fbf0*/;
    cpu.esp -= 4;
    // 0047f333  6805020000             -push 0x205
    app->getMemory<x86::reg32>(cpu.esp-4) = 517 /*0x205*/;
    cpu.esp -= 4;
    // 0047f338  e8a3130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f33d  68f0fb4700             -push 0x47fbf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4717552 /*0x47fbf0*/;
    cpu.esp -= 4;
    // 0047f342  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0047f347  e894130000             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
L_0x0047f34c:
    // 0047f34c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047f351  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0047f356  881d2d1b5600           -mov byte ptr [0x561b2d], bl
    app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */) = cpu.bl;
    // 0047f35c  a3441b5600             -mov dword ptr [0x561b44], eax
    app->getMemory<x86::reg32>(x86::reg32(5643076) /* 0x561b44 */) = cpu.eax;
    // 0047f361  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047f365  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f367  a3e8165600             -mov dword ptr [0x5616e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */) = cpu.eax;
    // 0047f36c  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047f370  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047f375  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f376  b8f0f44700             -mov eax, 0x47f4f0
    cpu.eax = 4715760 /*0x47f4f0*/;
    // 0047f37b  892de4165600           -mov dword ptr [0x5616e4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */) = cpu.ebp;
    // 0047f381  e8ca8b0000             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 0047f386  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f388  7449                   -je 0x47f3d3
    if (cpu.flags.zf)
    {
        goto L_0x0047f3d3;
    }
    // 0047f38a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047f38c:
    // 0047f38c  8b1d30894d00           -mov ebx, dword ptr [0x4d8930]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */);
    // 0047f392  39da                   +cmp edx, ebx
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
    // 0047f394  7571                   -jne 0x47f407
    if (!cpu.flags.zf)
    {
        goto L_0x0047f407;
    }
    // 0047f396  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f398  e8832f0000             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0047f39d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f39f  e8688c0000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0047f3a4  ebe6                   -jmp 0x47f38c
    goto L_0x0047f38c;
L_0x0047f3a6:
    // 0047f3a6  ba38d64c00             -mov edx, 0x4cd638
    cpu.edx = 5035576 /*0x4cd638*/;
    // 0047f3ab  b950030000             -mov ecx, 0x350
    cpu.ecx = 848 /*0x350*/;
    // 0047f3b0  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 0047f3b6  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0047f3bc  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f3c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f3c4  6858d64c00             -push 0x4cd658
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035608 /*0x4cd658*/;
    cpu.esp -= 4;
    // 0047f3c9  e892310000             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 0047f3ce  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047f3d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047f3d3:
    // 0047f3d3  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047f3d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3db:
    // 0047f3db  833d241b560000         +cmp dword ptr [0x561b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f3e2  0f8464ffffff           -je 0x47f34c
    if (cpu.flags.zf)
    {
        goto L_0x0047f34c;
    }
    // 0047f3e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f3ea  a02d1b5600             -mov al, byte ptr [0x561b2d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 0047f3ef  39c3                   +cmp ebx, eax
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
    // 0047f3f1  0f8455ffffff           -je 0x47f34c
    if (cpu.flags.zf)
    {
        goto L_0x0047f34c;
    }
    // 0047f3f7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047f3f9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047f3fb  e800fbffff             -call 0x47ef00
    cpu.esp -= 4;
    sub_47ef00(app, cpu);
    if (cpu.terminate) return;
    // 0047f400  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047f405  ebcc                   -jmp 0x47f3d3
    goto L_0x0047f3d3;
L_0x0047f407:
    // 0047f407  833d241b560000         +cmp dword ptr [0x561b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f40e  7405                   -je 0x47f415
    if (cpu.flags.zf)
    {
        goto L_0x0047f415;
    }
    // 0047f410  e8fbfbffff             -call 0x47f010
    cpu.esp -= 4;
    sub_47f010(app, cpu);
    if (cpu.terminate) return;
L_0x0047f415:
    // 0047f415  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047f419  8b1530894d00           -mov edx, dword ptr [0x4d8930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */);
    // 0047f41f  e86c8e0000             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0047f424  833d30894d0000         +cmp dword ptr [0x4d8930], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f42b  741b                   -je 0x47f448
    if (cpu.flags.zf)
    {
        goto L_0x0047f448;
    }
    // 0047f42d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047f42f:
    // 0047f42f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f431  e8d68b0000             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0047f436  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f438  e8e32e0000             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0047f43d  3b1530894d00           +cmp edx, dword ptr [0x4d8930]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f443  75ea                   -jne 0x47f42f
    if (!cpu.flags.zf)
    {
        goto L_0x0047f42f;
    }
    // 0047f445  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0047f448:
    // 0047f448  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047f44c  bf80135600             -mov edi, 0x561380
    cpu.edi = 5641088 /*0x561380*/;
    // 0047f451  8a352d1b5600           -mov dh, byte ptr [0x561b2d]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 0047f457  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047f458  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047f459  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047f45a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047f45b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047f45c  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0047f45e  7461                   -je 0x47f4c1
    if (cpu.flags.zf)
    {
        goto L_0x0047f4c1;
    }
    // 0047f460  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f462  6838894d00             -push 0x4d8938
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081400 /*0x4d8938*/;
    cpu.esp -= 4;
    // 0047f467  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f469  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047f46b  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f472  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f474  683c894d00             -push 0x4d893c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081404 /*0x4d893c*/;
    cpu.esp -= 4;
    // 0047f479  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f47b  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 0047f47d  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f484  833d38894d0000         +cmp dword ptr [0x4d8938], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081400) /* 0x4d8938 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f48b  740f                   -je 0x47f49c
    if (cpu.flags.zf)
    {
        goto L_0x0047f49c;
    }
    // 0047f48d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f48f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f491  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f493  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f495  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f49c:
    // 0047f49c  833d3c894d0000         +cmp dword ptr [0x4d893c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081404) /* 0x4d893c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f4a3  740f                   -je 0x47f4b4
    if (cpu.flags.zf)
    {
        goto L_0x0047f4b4;
    }
    // 0047f4a5  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f4a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f4a9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f4ab  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 0047f4ad  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f4b4:
    // 0047f4b4  a1241b5600             -mov eax, dword ptr [0x561b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047f4b9  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047f4bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f4c1:
    // 0047f4c1  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047f4c5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047f4c7  e834faffff             -call 0x47ef00
    cpu.esp -= 4;
    sub_47ef00(app, cpu);
    if (cpu.terminate) return;
    // 0047f4cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f4ce  891538894d00           -mov dword ptr [0x4d8938], edx
    app->getMemory<x86::reg32>(x86::reg32(5081400) /* 0x4d8938 */) = cpu.edx;
    // 0047f4d4  89153c894d00           -mov dword ptr [0x4d893c], edx
    app->getMemory<x86::reg32>(x86::reg32(5081404) /* 0x4d893c */) = cpu.edx;
    // 0047f4da  a1241b5600             -mov eax, dword ptr [0x561b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047f4df  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047f4e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f4f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f4f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f4f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f4f5  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0047f4f8  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0047f4fd  e8fe010000             -call 0x47f700
    cpu.esp -= 4;
    sub_47f700(app, cpu);
    if (cpu.terminate) return;
    // 0047f502  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f504  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f506  e8718d0000             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 0047f50b  a330894d00             -mov dword ptr [0x4d8930], eax
    app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */) = cpu.eax;
    // 0047f510  e8b78d0000             -call 0x4882cc
    cpu.esp -= 4;
    sub_4882cc(app, cpu);
    if (cpu.terminate) return;
    // 0047f515  a130894d00             -mov eax, dword ptr [0x4d8930]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */);
    // 0047f51a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f51c  e8378e0000             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0047f521  8a252d1b5600           -mov ah, byte ptr [0x561b2d]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 0047f527  891d241b5600           -mov dword ptr [0x561b24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */) = cpu.ebx;
    // 0047f52d  891534894d00           -mov dword ptr [0x4d8934], edx
    app->getMemory<x86::reg32>(x86::reg32(5081396) /* 0x4d8934 */) = cpu.edx;
    // 0047f533  891530894d00           -mov dword ptr [0x4d8930], edx
    app->getMemory<x86::reg32>(x86::reg32(5081392) /* 0x4d8930 */) = cpu.edx;
    // 0047f539  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047f53b  0f845a010000           -je 0x47f69b
    if (cpu.flags.zf)
    {
        goto L_0x0047f69b;
    }
    // 0047f541  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f542  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f544  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f54b  891d341b5600           -mov dword ptr [0x561b34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */) = cpu.ebx;
    // 0047f551  891d381b5600           -mov dword ptr [0x561b38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */) = cpu.ebx;
L_0x0047f557:
    // 0047f557  6874d54c00             -push 0x4cd574
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035380 /*0x4cd574*/;
    cpu.esp -= 4;
    // 0047f55c  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0047f55e  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f563  e888aa0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f568  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f56b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f56c  2eff15f0434c00         -call dword ptr cs:[0x4c43f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998128) /* 0x4c43f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f573  3b35241b5600           +cmp esi, dword ptr [0x561b24]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f579  0f85ff000000           -jne 0x47f67e
    if (!cpu.flags.zf)
    {
        goto L_0x0047f67e;
    }
L_0x0047f57f:
    // 0047f57f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f581  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f583  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f585  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f589  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f58a  2eff15c8434c00         -call dword ptr cs:[0x4c43c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998088) /* 0x4c43c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f591  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f593  0f8433010000           -je 0x47f6cc
    if (cpu.flags.zf)
    {
        goto L_0x0047f6cc;
    }
    // 0047f599  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0047f59e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f59f  6894d54c00             -push 0x4cd594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035412 /*0x4cd594*/;
    cpu.esp -= 4;
    // 0047f5a4  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0047f5a6  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f5ab  e840aa0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f5b0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f5b3  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0047f5b8  e8fb8d0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0047f5bd  833da813560000         +cmp dword ptr [0x5613a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641128) /* 0x5613a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f5c4  751b                   -jne 0x47f5e1
    if (!cpu.flags.zf)
    {
        goto L_0x0047f5e1;
    }
    // 0047f5c6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f5ca  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f5ce  e81d0c0000             -call 0x4801f0
    cpu.esp -= 4;
    sub_4801f0(app, cpu);
    if (cpu.terminate) return;
    // 0047f5d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f5d5  750a                   -jne 0x47f5e1
    if (!cpu.flags.zf)
    {
        goto L_0x0047f5e1;
    }
    // 0047f5d7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047f5d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5da  2eff1514444c00         -call dword ptr cs:[0x4c4414]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998164) /* 0x4c4414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f5e1:
    // 0047f5e1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047f5e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5e4  2eff15ac434c00         -call dword ptr cs:[0x4c43ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998060) /* 0x4c43ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f5eb  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0047f5f0  e8db8d0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0047f5f5  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0047f5fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5fb  68a4d54c00             -push 0x4cd5a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035428 /*0x4cd5a4*/;
    cpu.esp -= 4;
    // 0047f600  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0047f602  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f607  e8e4a90100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f60c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0047f60f:
    // 0047f60f  833d34894d0000         +cmp dword ptr [0x4d8934], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081396) /* 0x4d8934 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f616  745a                   -je 0x47f672
    if (cpu.flags.zf)
    {
        goto L_0x0047f672;
    }
    // 0047f618  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f61a  8b3dd0165600           -mov edi, dword ptr [0x5616d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5641936) /* 0x5616d0 */);
    // 0047f620  891d34894d00           -mov dword ptr [0x4d8934], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081396) /* 0x4d8934 */) = cpu.ebx;
    // 0047f626  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f628  7427                   -je 0x47f651
    if (cpu.flags.zf)
    {
        goto L_0x0047f651;
    }
    // 0047f62a  833de016560000         +cmp dword ptr [0x5616e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f631  741e                   -je 0x47f651
    if (cpu.flags.zf)
    {
        goto L_0x0047f651;
    }
    // 0047f633  68ccd54c00             -push 0x4cd5cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035468 /*0x4cd5cc*/;
    cpu.esp -= 4;
    // 0047f638  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f63a  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f63f  e8aca90100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f644  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f647  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0047f64c  e853d20000             -call 0x48c8a4
    cpu.esp -= 4;
    sub_48c8a4(app, cpu);
    if (cpu.terminate) return;
L_0x0047f651:
    // 0047f651  68e8d54c00             -push 0x4cd5e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035496 /*0x4cd5e8*/;
    cpu.esp -= 4;
    // 0047f656  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f658  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f65d  e88ea90100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f662  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f665  a1241b5600             -mov eax, dword ptr [0x561b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0047f66a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f66b  2eff15a8434c00         -call dword ptr cs:[0x4c43a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998056) /* 0x4c43a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f672:
    // 0047f672  3b35241b5600           +cmp esi, dword ptr [0x561b24]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f678  0f8401ffffff           -je 0x47f57f
    if (cpu.flags.zf)
    {
        goto L_0x0047f57f;
    }
L_0x0047f67e:
    // 0047f67e  68f8d54c00             -push 0x4cd5f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035512 /*0x4cd5f8*/;
    cpu.esp -= 4;
    // 0047f683  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f685  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f68a  e861a90100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f68f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f692  83c42c                 +add esp, 0x2c
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
    // 0047f695  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f696  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f697  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f698  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f699  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f69a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f69b:
    // 0047f69b  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047f69f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f6a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f6a1  2eff15bc434c00         -call dword ptr cs:[0x4c43bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998076) /* 0x4c43bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f6a8  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047f6ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f6ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f6ae  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f6b5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047f6b9  a3341b5600             -mov dword ptr [0x561b34], eax
    app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */) = cpu.eax;
    // 0047f6be  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047f6c2  a3381b5600             -mov dword ptr [0x561b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */) = cpu.eax;
    // 0047f6c7  e98bfeffff             -jmp 0x47f557
    goto L_0x0047f557;
L_0x0047f6cc:
    // 0047f6cc  68b4d54c00             -push 0x4cd5b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035444 /*0x4cd5b4*/;
    cpu.esp -= 4;
    // 0047f6d1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f6d3  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f6d8  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0047f6dd  e80ea90100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f6e2  83c40c                 +add esp, 0xc
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
    // 0047f6e5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047f6ea  b810064800             -mov eax, 0x480610
    cpu.eax = 4720144 /*0x480610*/;
    // 0047f6ef  e84c2b0000             -call 0x482240
    cpu.esp -= 4;
    sub_482240(app, cpu);
    if (cpu.terminate) return;
    // 0047f6f4  e916ffffff             -jmp 0x47f60f
    goto L_0x0047f60f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f702  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f703  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f704  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f705  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f706  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f709  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f70b  8aa05d040000           -mov ah, byte ptr [eax + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
    // 0047f711  8b3550894d00           -mov esi, dword ptr [0x4d8950]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5081424) /* 0x4d8950 */);
    // 0047f717  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047f719  0f8520010000           -jne 0x47f83f
    if (!cpu.flags.zf)
    {
        goto L_0x0047f83f;
    }
    // 0047f71f  8a15a4894d00           -mov dl, byte ptr [0x4d89a4]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 0047f725  81ce0000ca00           -or esi, 0xca0000
    cpu.esi |= x86::reg32(x86::sreg32(13238272 /*0xca0000*/));
    // 0047f72b  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 0047f72e  0f8445010000           -je 0x47f879
    if (cpu.flags.zf)
    {
        goto L_0x0047f879;
    }
    // 0047f734  81ce00000500           -or esi, 0x50000
    cpu.esi |= x86::reg32(x86::sreg32(327680 /*0x50000*/));
L_0x0047f73a:
    // 0047f73a  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f741  0f843d010000           -je 0x47f884
    if (cpu.flags.zf)
    {
        goto L_0x0047f884;
    }
    // 0047f747  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 0047f74d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047f751  8b8364040000           -mov eax, dword ptr [ebx + 0x464]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 0047f757  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0047f75a:
    // 0047f75a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f75e  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0047f761  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f763  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047f767  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f76a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047f76d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f76f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047f771  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f772  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047f776  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f77a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f77b  2eff1588434c00         -call dword ptr cs:[0x4c4388]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998024) /* 0x4c4388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f782  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f785  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0047f78b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f78f  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 0047f795  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f799  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f79c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f7a0  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f7a2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f7a4  b900000400             -mov ecx, 0x40000
    cpu.ecx = 262144 /*0x40000*/;
L_0x0047f7a9:
    // 0047f7a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f7aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7ab  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 0047f7b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f7b2  8bab64040000           -mov ebp, dword ptr [ebx + 0x464]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 0047f7b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f7b9  6828d54c00             -push 0x4cd528
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035304 /*0x4cd528*/;
    cpu.esp -= 4;
    // 0047f7be  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0047f7c0  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f7c5  e826a80100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f7ca  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047f7cd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f7cf  a1401b5600             -mov eax, dword ptr [0x561b40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643072) /* 0x561b40 */);
    // 0047f7d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f7d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f7d7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f7d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f7da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7db  8b9368040000           -mov edx, dword ptr [ebx + 0x468]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 0047f7e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f7e2  8bbb64040000           -mov edi, dword ptr [ebx + 0x464]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 0047f7e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f7e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f7ea  8b2d60894d00           -mov ebp, dword ptr [0x4d8960]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5081440) /* 0x4d8960 */);
    // 0047f7f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f7f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f7f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f7f3  2eff15a0434c00         -call dword ptr cs:[0x4c43a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998048) /* 0x4c43a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f7fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f7fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f7fe  7409                   -je 0x47f809
    if (cpu.flags.zf)
    {
        goto L_0x0047f809;
    }
    // 0047f800  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f802  2eff1508444c00         -call dword ptr cs:[0x4c4408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998152) /* 0x4c4408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f809:
    // 0047f809  ff1508155600           -call dword ptr [0x561508]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641480) /* 0x561508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f80f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f811  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047f813  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f815  ff1538155600           -call dword ptr [0x561538]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641528) /* 0x561538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f81b  6858d54c00             -push 0x4cd558
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035352 /*0x4cd558*/;
    cpu.esp -= 4;
    // 0047f820  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0047f822  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047f827  e8c4a70100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047f82c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f82f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f831  7562                   -jne 0x47f895
    if (!cpu.flags.zf)
    {
        goto L_0x0047f895;
    }
L_0x0047f833:
    // 0047f833  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f835  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f838  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f839  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f83a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f83b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f83c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f83d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f83e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f83f:
    // 0047f83f  c7836404000000000000   -mov dword ptr [ebx + 0x464], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = 0 /*0x0*/;
    // 0047f849  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f84b  c7836804000000000000   -mov dword ptr [ebx + 0x468], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = 0 /*0x0*/;
    // 0047f855  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f85c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047f85e  81ce00000080           +or esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 0047f864  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047f866  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f86d  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0047f872  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f874  e930ffffff             -jmp 0x47f7a9
    goto L_0x0047f7a9;
L_0x0047f879:
    // 0047f879  81ce00008000           +or esi, 0x800000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(8388608 /*0x800000*/))));
    // 0047f87f  e9b6feffff             -jmp 0x47f73a
    goto L_0x0047f73a;
L_0x0047f884:
    // 0047f884  b900e0ffff             -mov ecx, 0xffffe000
    cpu.ecx = 4294959104 /*0xffffe000*/;
    // 0047f889  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047f88c  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047f890  e9c5feffff             -jmp 0x47f75a
    goto L_0x0047f75a;
L_0x0047f895:
    // 0047f895  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f897  2eff15f4434c00         -call dword ptr cs:[0x4c43f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998132) /* 0x4c43f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f89e  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
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
    // 0047f8a5  7409                   -je 0x47f8b0
    if (cpu.flags.zf)
    {
        goto L_0x0047f8b0;
    }
    // 0047f8a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f8a9  2eff1508444c00         -call dword ptr cs:[0x4c4408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998152) /* 0x4c4408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f8b0:
    // 0047f8b0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f8b2  8b0d5c894d00           -mov ecx, dword ptr [0x4d895c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081436) /* 0x4d895c */);
    // 0047f8b8  89150c914d00           -mov dword ptr [0x4d910c], edx
    app->getMemory<x86::reg32>(x86::reg32(5083404) /* 0x4d910c */) = cpu.edx;
    // 0047f8be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f8c0  0f856dffffff           -jne 0x47f833
    if (!cpu.flags.zf)
    {
        goto L_0x0047f833;
    }
    // 0047f8c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f8c8  e8a3d20100             -call 0x49cb70
    cpu.esp -= 4;
    sub_49cb70(app, cpu);
    if (cpu.terminate) return;
    // 0047f8cd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047f8d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f8d4  e897d20100             -call 0x49cb70
    cpu.esp -= 4;
    sub_49cb70(app, cpu);
    if (cpu.terminate) return;
    // 0047f8d9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047f8de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f8e0  e88bd20100             -call 0x49cb70
    cpu.esp -= 4;
    sub_49cb70(app, cpu);
    if (cpu.terminate) return;
    // 0047f8e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f8e7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f8ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f901  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f902  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f903  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f904  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047f908  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047f90c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f90e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047f910  754b                   -jne 0x47f95d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f95d;
    }
    // 0047f912  833d40894d0000         +cmp dword ptr [0x4d8940], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081408) /* 0x4d8940 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f919  7442                   -je 0x47f95d
    if (cpu.flags.zf)
    {
        goto L_0x0047f95d;
    }
    // 0047f91b  833d441b560000         +cmp dword ptr [0x561b44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643076) /* 0x561b44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f922  7439                   -je 0x47f95d
    if (cpu.flags.zf)
    {
        goto L_0x0047f95d;
    }
    // 0047f924  833d48894d0000         +cmp dword ptr [0x4d8948], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081416) /* 0x4d8948 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f92b  744f                   -je 0x47f97c
    if (cpu.flags.zf)
    {
        goto L_0x0047f97c;
    }
    // 0047f92d  f644241f20             +test byte ptr [esp + 0x1f], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */) & 32 /*0x20*/));
    // 0047f932  7448                   -je 0x47f97c
    if (cpu.flags.zf)
    {
        goto L_0x0047f97c;
    }
    // 0047f934  bd38000000             -mov ebp, 0x38
    cpu.ebp = 56 /*0x38*/;
    // 0047f939  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f93c  7530                   -jne 0x47f96e
    if (!cpu.flags.zf)
    {
        goto L_0x0047f96e;
    }
    // 0047f93e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047f943  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
L_0x0047f948:
    // 0047f948  833d4c894d0000         +cmp dword ptr [0x4d894c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081420) /* 0x4d894c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f94f  740c                   -je 0x47f95d
    if (cpu.flags.zf)
    {
        goto L_0x0047f95d;
    }
    // 0047f951  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047f953  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047f955  ff154c894d00           -call dword ptr [0x4d894c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5081420) /* 0x4d894c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f95b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0047f95d:
    // 0047f95d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f95f  0f846b000000           -je 0x47f9d0
    if (cpu.flags.zf)
    {
        goto L_0x0047f9d0;
    }
    // 0047f965  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f967  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f968  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f969  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f96a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f96b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047f96e:
    // 0047f96e  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f971  7536                   -jne 0x47f9a9
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9a9;
    }
    // 0047f973  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047f978  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047f97a  ebcc                   -jmp 0x47f948
    goto L_0x0047f948;
L_0x0047f97c:
    // 0047f97c  83fe5b                 +cmp esi, 0x5b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f97f  750b                   -jne 0x47f98c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f98c;
    }
L_0x0047f981:
    // 0047f981  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047f986  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047f988  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0047f98a  ebbc                   -jmp 0x47f948
    goto L_0x0047f948;
L_0x0047f98c:
    // 0047f98c  83fe5c                 +cmp esi, 0x5c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f98f  74f0                   -je 0x47f981
    if (cpu.flags.zf)
    {
        goto L_0x0047f981;
    }
    // 0047f991  83fe5d                 +cmp esi, 0x5d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f994  74eb                   -je 0x47f981
    if (cpu.flags.zf)
    {
        goto L_0x0047f981;
    }
    // 0047f996  83fe2c                 +cmp esi, 0x2c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f999  74e6                   -je 0x47f981
    if (cpu.flags.zf)
    {
        goto L_0x0047f981;
    }
    // 0047f99b  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047f99d  2eff15b8434c00         -call dword ptr cs:[0x4c43b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998072) /* 0x4c43b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f9a4  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0047f9a7  7c11                   -jl 0x47f9ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f9ba;
    }
L_0x0047f9a9:
    // 0047f9a9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f9ab  759b                   -jne 0x47f948
    if (!cpu.flags.zf)
    {
        goto L_0x0047f948;
    }
    // 0047f9ad  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f9af  741f                   -je 0x47f9d0
    if (cpu.flags.zf)
    {
        goto L_0x0047f9d0;
    }
    // 0047f9b1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f9b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9b7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047f9ba:
    // 0047f9ba  bd1d000000             -mov ebp, 0x1d
    cpu.ebp = 29 /*0x1d*/;
    // 0047f9bf  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f9c2  75e5                   -jne 0x47f9a9
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9a9;
    }
    // 0047f9c4  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047f9c9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047f9cb  e978ffffff             -jmp 0x47f948
    goto L_0x0047f948;
L_0x0047f9d0:
    // 0047f9d0  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047f9d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f9d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f9d6  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047f9da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f9db  8b3d44894d00           -mov edi, dword ptr [0x4d8944]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081412) /* 0x4d8944 */);
    // 0047f9e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f9e2  2eff1590434c00         -call dword ptr cs:[0x4c4390]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998032) /* 0x4c4390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f9e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f9eb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f9ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f9f1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fa00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fa00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fa04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0047fa06  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047fa09  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047fa0c  b9d0165600             -mov ecx, 0x5616d0
    cpu.ecx = 5641936 /*0x5616d0*/;
    // 0047fa11  6840084800             -push 0x480840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4720704 /*0x480840*/;
    cpu.esp -= 4;
    // 0047fa16  ba800f5600             -mov edx, 0x560f80
    cpu.edx = 5640064 /*0x560f80*/;
    // 0047fa1b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047fa1e  8b1d2c894d00           -mov ebx, dword ptr [0x4d892c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */);
    // 0047fa24  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 0047fa27  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047fa29  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047fa2c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0047fa31  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0047fa34  e8cdc80100             -call 0x49c306
    cpu.esp -= 4;
    sub_49c306(app, cpu);
    if (cpu.terminate) return;
    // 0047fa39  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047fa3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fa3d  0f8486000000           -je 0x47fac9
    if (cpu.flags.zf)
    {
        goto L_0x0047fac9;
    }
    // 0047fa43  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
L_0x0047fa48:
    // 0047fa48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa49  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047fa4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa4d  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047fa50  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047fa53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fa54  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fa56  0f8477000000           -je 0x47fad3
    if (cpu.flags.zf)
    {
        goto L_0x0047fad3;
    }
    // 0047fa5c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047fa61:
    // 0047fa61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa63  6808d54c00             -push 0x4cd508
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035272 /*0x4cd508*/;
    cpu.esp -= 4;
    // 0047fa68  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fa6a  746b                   -je 0x47fad7
    if (cpu.flags.zf)
    {
        goto L_0x0047fad7;
    }
    // 0047fa6c  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x0047fa71:
    // 0047fa71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa72  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fa77  e874a50100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fa7c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0047fa7f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fa81  741a                   -je 0x47fa9d
    if (cpu.flags.zf)
    {
        goto L_0x0047fa9d;
    }
    // 0047fa83  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047fa86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa87  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047fa8a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa8b  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047fa8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa90  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047fa93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fa94  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0047fa97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fa98  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fa9b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047fa9d:
    // 0047fa9d  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0047faa2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047faa4  7438                   -je 0x47fade
    if (cpu.flags.zf)
    {
        goto L_0x0047fade;
    }
    // 0047faa6  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0047faab:
    // 0047faab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047faac  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fab1  e83aa50100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fab6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fab9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047fabb  7428                   -je 0x47fae5
    if (cpu.flags.zf)
    {
        goto L_0x0047fae5;
    }
    // 0047fabd  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0047fac0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0047fac2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0047fac9:
    // 0047fac9  b83b000000             -mov eax, 0x3b
    cpu.eax = 59 /*0x3b*/;
    // 0047face  e975ffffff             -jmp 0x47fa48
    goto L_0x0047fa48;
L_0x0047fad3:
    // 0047fad3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047fad5  eb8a                   -jmp 0x47fa61
    goto L_0x0047fa61;
L_0x0047fad7:
    // 0047fad7  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047fadc  eb93                   -jmp 0x47fa71
    goto L_0x0047fa71;
L_0x0047fade:
    // 0047fade  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047fae3  ebc6                   -jmp 0x47faab
    goto L_0x0047faab;
L_0x0047fae5:
    // 0047fae5  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047fae8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fae9  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047faec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047faed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047faee  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047faf1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047faf2  2eff15a4434c00         -call dword ptr cs:[0x4c43a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998052) /* 0x4c43a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047faf9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0047fafb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fafc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fafd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fafe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047faff  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fb10  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fb14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fb16  741d                   -je 0x47fb35
    if (cpu.flags.zf)
    {
        goto L_0x0047fb35;
    }
    // 0047fb18  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fb1c  3b9054040000           +cmp edx, dword ptr [eax + 0x454]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fb22  7511                   -jne 0x47fb35
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb35;
    }
    // 0047fb24  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb2b  7408                   -je 0x47fb35
    if (cpu.flags.zf)
    {
        goto L_0x0047fb35;
    }
    // 0047fb2d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047fb32  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fb35:
    // 0047fb35  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0047fb3a  e879880000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0047fb3f  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0047fb44  e887880000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0047fb49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fb4b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_47fb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fb50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fb51  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047fb54  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047fb58  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fb5a  7409                   -je 0x47fb65
    if (cpu.flags.zf)
    {
        goto L_0x0047fb65;
    }
    // 0047fb5c  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fb63  750c                   -jne 0x47fb71
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb71;
    }
L_0x0047fb65:
    // 0047fb65  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047fb6a  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047fb6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb6e  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fb71:
    // 0047fb71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fb72  68fcd44c00             -push 0x4cd4fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035260 /*0x4cd4fc*/;
    cpu.esp -= 4;
    // 0047fb77  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fb79  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fb7e  e86da40100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fb83  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fb86  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0047fb8b  e828880000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0047fb90  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fb94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fb95  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047fb9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fb9c  2eff158c434c00         -call dword ptr cs:[0x4c438c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998028) /* 0x4c438c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fba3  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fba7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fba8  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047fbae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fbaf  2eff15b0434c00         -call dword ptr cs:[0x4c43b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998064) /* 0x4c43b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fbb6  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0047fbbb  e810880000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0047fbc0  833dec8f4d0000         +cmp dword ptr [0x4d8fec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fbc7  7406                   -je 0x47fbcf
    if (cpu.flags.zf)
    {
        goto L_0x0047fbcf;
    }
    // 0047fbc9  ff15ec8f4d00           -call dword ptr [0x4d8fec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047fbcf:
    // 0047fbcf  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0047fbd3  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0047fbd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fbda  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047fbdf  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047fbe2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fbe3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fbf0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fbf4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047fbf8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0047fbfd  7505                   -jne 0x47fc04
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc04;
    }
    // 0047fbff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fc01  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fc04:
    // 0047fc04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fc05  68f0d44c00             -push 0x4cd4f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035248 /*0x4cd4f0*/;
    cpu.esp -= 4;
    // 0047fc0a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fc0c  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fc11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc13  e8d8a30100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fc18  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fc1b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0047fc1e  7405                   -je 0x47fc25
    if (cpu.flags.zf)
    {
        goto L_0x0047fc25;
    }
    // 0047fc20  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0047fc25:
    // 0047fc25  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0047fc28  7403                   -je 0x47fc2d
    if (cpu.flags.zf)
    {
        goto L_0x0047fc2d;
    }
    // 0047fc2a  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0047fc2d:
    // 0047fc2d  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 0047fc30  7403                   -je 0x47fc35
    if (cpu.flags.zf)
    {
        goto L_0x0047fc35;
    }
    // 0047fc32  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0047fc35:
    // 0047fc35  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fc37  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fc39  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047fc3c  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0047fc3f  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fc45  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fc4b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047fc4d  e892cc0100             -call 0x49c8e4
    cpu.esp -= 4;
    sub_49c8e4(app, cpu);
    if (cpu.terminate) return;
    // 0047fc52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fc55  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fc60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fc60  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fc64  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047fc68  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0047fc6d  7505                   -jne 0x47fc74
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc74;
    }
    // 0047fc6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fc71  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fc74:
    // 0047fc74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fc75  68e4d44c00             -push 0x4cd4e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035236 /*0x4cd4e4*/;
    cpu.esp -= 4;
    // 0047fc7a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fc7c  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fc81  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc83  e868a30100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fc88  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fc8b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0047fc8e  7405                   -je 0x47fc95
    if (cpu.flags.zf)
    {
        goto L_0x0047fc95;
    }
    // 0047fc90  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0047fc95:
    // 0047fc95  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0047fc98  7403                   -je 0x47fc9d
    if (cpu.flags.zf)
    {
        goto L_0x0047fc9d;
    }
    // 0047fc9a  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0047fc9d:
    // 0047fc9d  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 0047fca0  7403                   -je 0x47fca5
    if (cpu.flags.zf)
    {
        goto L_0x0047fca5;
    }
    // 0047fca2  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0047fca5:
    // 0047fca5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fca7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fca9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047fcac  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0047fcaf  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fcb5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047fcba  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fcc0  e81fcc0100             -call 0x49c8e4
    cpu.esp -= 4;
    sub_49c8e4(app, cpu);
    if (cpu.terminate) return;
    // 0047fcc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fcc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fcc8  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fcd0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0047fcd5  743a                   -je 0x47fd11
    if (cpu.flags.zf)
    {
        goto L_0x0047fd11;
    }
    // 0047fcd7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047fcdb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047fcde  8b0d5c894d00           -mov ecx, dword ptr [0x4d895c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081436) /* 0x4d895c */);
    // 0047fce4  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047fce7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fce9  740a                   -je 0x47fcf5
    if (cpu.flags.zf)
    {
        goto L_0x0047fcf5;
    }
    // 0047fceb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fced  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0047fcf0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x0047fcf5:
    // 0047fcf5  68d8d44c00             -push 0x4cd4d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035224 /*0x4cd4d8*/;
    cpu.esp -= 4;
    // 0047fcfa  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fcfc  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047fcfe  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fd03  889010914d00           -mov byte ptr [eax + 0x4d9110], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5083408) /* 0x4d9110 */) = cpu.dl;
    // 0047fd09  e8e2a20100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fd0e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0047fd11:
    // 0047fd11  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fd13  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fd20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fd21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fd22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fd23  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047fd27  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 0047fd2c  0f84b1000000           -je 0x47fde3
    if (cpu.flags.zf)
    {
        goto L_0x0047fde3;
    }
    // 0047fd32  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047fd34  8b0da0135600           -mov ecx, dword ptr [0x5613a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641120) /* 0x5613a0 */);
    // 0047fd3a  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fd40  39ce                   +cmp esi, ecx
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
    // 0047fd42  7e02                   -jle 0x47fd46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047fd46;
    }
    // 0047fd44  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0047fd46:
    // 0047fd46  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047fd48  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047fd4b  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047fd4e  8b1d5c894d00           -mov ebx, dword ptr [0x4d895c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081436) /* 0x4d895c */);
    // 0047fd54  a3ac135600             -mov dword ptr [0x5613ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5641132) /* 0x5613ac */) = cpu.eax;
    // 0047fd59  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fd5b  740e                   -je 0x47fd6b
    if (cpu.flags.zf)
    {
        goto L_0x0047fd6b;
    }
    // 0047fd5d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fd5f  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0047fd61  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047fd66  a3ac135600             -mov dword ptr [0x5613ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5641132) /* 0x5613ac */) = cpu.eax;
L_0x0047fd6b:
    // 0047fd6b  a1ac135600             -mov eax, dword ptr [0x5613ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641132) /* 0x5613ac */);
    // 0047fd70  c68010914d0001         -mov byte ptr [eax + 0x4d9110], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5083408) /* 0x4d9110 */) = 1 /*0x1*/;
    // 0047fd77  833d08914d0000         +cmp dword ptr [0x4d9108], 0
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
    // 0047fd7e  7424                   -je 0x47fda4
    if (cpu.flags.zf)
    {
        goto L_0x0047fda4;
    }
    // 0047fd80  3b0558894d00           +cmp eax, dword ptr [0x4d8958]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5081432) /* 0x4d8958 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fd86  751c                   -jne 0x47fda4
    if (!cpu.flags.zf)
    {
        goto L_0x0047fda4;
    }
    // 0047fd88  803d48914d0000         +cmp byte ptr [0x4d9148], 0
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
    // 0047fd8f  7413                   -je 0x47fda4
    if (cpu.flags.zf)
    {
        goto L_0x0047fda4;
    }
    // 0047fd91  6884d44c00             -push 0x4cd484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035140 /*0x4cd484*/;
    cpu.esp -= 4;
    // 0047fd96  2eff1528454c00         -call dword ptr cs:[0x4c4528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998440) /* 0x4c4528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fd9d  2eff1540444c00         -call dword ptr cs:[0x4c4440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998208) /* 0x4c4440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047fda4:
    // 0047fda4  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0047fda7  8b1da8135600           -mov ebx, dword ptr [0x5613a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641128) /* 0x5613a8 */);
    // 0047fdad  83e701                 -and edi, 1
    cpu.edi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047fdb0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fdb2  743a                   -je 0x47fdee
    if (cpu.flags.zf)
    {
        goto L_0x0047fdee;
    }
    // 0047fdb4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047fdb6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0047fdb8:
    // 0047fdb8  4e                     -dec esi
    (cpu.esi)--;
    // 0047fdb9  83feff                 +cmp esi, -1
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
    // 0047fdbc  7411                   -je 0x47fdcf
    if (cpu.flags.zf)
    {
        goto L_0x0047fdcf;
    }
    // 0047fdbe  8b15ac135600           -mov edx, dword ptr [0x5613ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641132) /* 0x5613ac */);
    // 0047fdc4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047fdc6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047fdc8  e883070000             -call 0x480550
    cpu.esp -= 4;
    sub_480550(app, cpu);
    if (cpu.terminate) return;
    // 0047fdcd  ebe9                   -jmp 0x47fdb8
    goto L_0x0047fdb8;
L_0x0047fdcf:
    // 0047fdcf  6894d44c00             -push 0x4cd494
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035156 /*0x4cd494*/;
    cpu.esp -= 4;
L_0x0047fdd4:
    // 0047fdd4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fdd6  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fddb  e810a20100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fde0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0047fde3:
    // 0047fde3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047fde8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fde9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdeb  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fdee:
    // 0047fdee  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047fdf2  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047fdf6  e8f5030000             -call 0x4801f0
    cpu.esp -= 4;
    sub_4801f0(app, cpu);
    if (cpu.terminate) return;
    // 0047fdfb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fdfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fdff  7417                   -je 0x47fe18
    if (cpu.flags.zf)
    {
        goto L_0x0047fe18;
    }
L_0x0047fe01:
    // 0047fe01  4e                     -dec esi
    (cpu.esi)--;
    // 0047fe02  83feff                 +cmp esi, -1
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
    // 0047fe05  742d                   -je 0x47fe34
    if (cpu.flags.zf)
    {
        goto L_0x0047fe34;
    }
    // 0047fe07  8b15ac135600           -mov edx, dword ptr [0x5613ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641132) /* 0x5613ac */);
    // 0047fe0d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047fe0f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fe11  e83a070000             -call 0x480550
    cpu.esp -= 4;
    sub_480550(app, cpu);
    if (cpu.terminate) return;
    // 0047fe16  ebe9                   -jmp 0x47fe01
    goto L_0x0047fe01;
L_0x0047fe18:
    // 0047fe18  68c4d44c00             -push 0x4cd4c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035204 /*0x4cd4c4*/;
    cpu.esp -= 4;
    // 0047fe1d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fe1f  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fe24  e8c7a10100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fe29  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fe2c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047fe2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe31  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fe34:
    // 0047fe34  68a8d44c00             -push 0x4cd4a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035176 /*0x4cd4a8*/;
    cpu.esp -= 4;
    // 0047fe39  eb99                   -jmp 0x47fdd4
    goto L_0x0047fdd4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fe40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fe40  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fe41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fe42  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047fe46  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047fe4a  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fe4f  744f                   -je 0x47fea0
    if (cpu.flags.zf)
    {
        goto L_0x0047fea0;
    }
    // 0047fe51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fe52  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fe53  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047fe55  8b1da0135600           -mov ebx, dword ptr [0x5613a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641120) /* 0x5613a0 */);
    // 0047fe5b  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fe61  39d9                   +cmp ecx, ebx
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
    // 0047fe63  7f21                   -jg 0x47fe86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047fe86;
    }
L_0x0047fe65:
    // 0047fe65  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047fe67  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 0047fe6a  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0047fe6d  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047fe70  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x0047fe73:
    // 0047fe73  49                     -dec ecx
    (cpu.ecx)--;
    // 0047fe74  83f9ff                 +cmp ecx, -1
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
    // 0047fe77  7411                   -je 0x47fe8a
    if (cpu.flags.zf)
    {
        goto L_0x0047fe8a;
    }
    // 0047fe79  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047fe7b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047fe7d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047fe7f  e8cc060000             -call 0x480550
    cpu.esp -= 4;
    sub_480550(app, cpu);
    if (cpu.terminate) return;
    // 0047fe84  ebed                   -jmp 0x47fe73
    goto L_0x0047fe73;
L_0x0047fe86:
    // 0047fe86  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047fe88  ebdb                   -jmp 0x47fe65
    goto L_0x0047fe65;
L_0x0047fe8a:
    // 0047fe8a  6878d44c00             -push 0x4cd478
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035128 /*0x4cd478*/;
    cpu.esp -= 4;
    // 0047fe8f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fe91  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fe96  e855a10100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fe9b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fe9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047fea0:
    // 0047fea0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047fea5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fea6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fea7  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47feb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047feb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047feb1  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047feb4  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047feb8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047feba  7509                   -jne 0x47fec5
    if (!cpu.flags.zf)
    {
        goto L_0x0047fec5;
    }
L_0x0047febc:
    // 0047febc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047febe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047fec1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fec2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047fec5:
    // 0047fec5  6868d44c00             -push 0x4cd468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035112 /*0x4cd468*/;
    cpu.esp -= 4;
    // 0047feca  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047fecc  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047fed1  e81aa10100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047fed6  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 0047fedc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047fedf  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047fee1  75d9                   -jne 0x47febc
    if (!cpu.flags.zf)
    {
        goto L_0x0047febc;
    }
    // 0047fee3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047fee5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fee6  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047feec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047feed  2eff15bc434c00         -call dword ptr cs:[0x4c43bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998076) /* 0x4c43bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fef4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047fef6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fef7  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047fefd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fefe  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ff05  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ff08  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0047ff0e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ff12  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 0047ff18  833dec8f4d0000         +cmp dword ptr [0x4d8fec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff1f  749b                   -je 0x47febc
    if (cpu.flags.zf)
    {
        goto L_0x0047febc;
    }
    // 0047ff21  ff15ec8f4d00           -call dword ptr [0x4d8fec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ff27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ff29  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047ff2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff2d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_47ff30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ff30  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ff34  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ff38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ff39  683cd44c00             -push 0x4cd43c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035068 /*0x4cd43c*/;
    cpu.esp -= 4;
    // 0047ff3e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047ff40  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047ff45  e8a6a00100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047ff4a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047ff4d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ff4f  7409                   -je 0x47ff5a
    if (cpu.flags.zf)
    {
        goto L_0x0047ff5a;
    }
    // 0047ff51  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff58  750f                   -jne 0x47ff69
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff69;
    }
L_0x0047ff5a:
    // 0047ff5a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ff5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ff60  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047ff66  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047ff69:
    // 0047ff69  6850d44c00             -push 0x4cd450
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035088 /*0x4cd450*/;
    cpu.esp -= 4;
    // 0047ff6e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047ff70  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0047ff75  e876a00100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0047ff7a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ff7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ff7f  6838894d00             -push 0x4d8938
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081400 /*0x4d8938*/;
    cpu.esp -= 4;
    // 0047ff84  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ff86  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 0047ff88  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ff8f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ff91  683c894d00             -push 0x4d893c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081404 /*0x4d893c*/;
    cpu.esp -= 4;
    // 0047ff96  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ff98  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 0047ff9a  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ffa1  833d38894d0000         +cmp dword ptr [0x4d8938], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081400) /* 0x4d8938 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffa8  740f                   -je 0x47ffb9
    if (cpu.flags.zf)
    {
        goto L_0x0047ffb9;
    }
    // 0047ffaa  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047ffac  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ffae  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ffb0  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047ffb2  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047ffb9:
    // 0047ffb9  833d3c894d0000         +cmp dword ptr [0x4d893c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081404) /* 0x4d893c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffc0  7498                   -je 0x47ff5a
    if (cpu.flags.zf)
    {
        goto L_0x0047ff5a;
    }
    // 0047ffc2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047ffc4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ffc6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ffc8  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 0047ffca  2eff1510444c00         -call dword ptr cs:[0x4c4410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998160) /* 0x4c4410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ffd1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047ffd5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ffd7  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047ffdd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_47ffe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ffe0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ffe4  3d60f00000             +cmp eax, 0xf060
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61536 /*0xf060*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffe9  7424                   -je 0x48000f
    if (cpu.flags.zf)
    {
        goto L_0x0048000f;
    }
    // 0047ffeb  3d20f00000             +cmp eax, 0xf020
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61472 /*0xf020*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fff0  741d                   -je 0x48000f
    if (cpu.flags.zf)
    {
        goto L_0x0048000f;
    }
    // 0047fff2  3d30f00000             +cmp eax, 0xf030
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61488 /*0xf030*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fff7  7416                   -je 0x48000f
    if (cpu.flags.zf)
    {
        goto L_0x0048000f;
    }
    // 0047fff9  3d20f10000             +cmp eax, 0xf120
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61728 /*0xf120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fffe  740f                   -je 0x48000f
    if (cpu.flags.zf)
    {
        goto L_0x0048000f;
    }
    // 00480000  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480004  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480006  8a825d040000           -mov al, byte ptr [edx + 0x45d]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
    // 0048000c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0048000f:
    // 0048000f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480011  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480020  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480024  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480026  7505                   -jne 0x48002d
    if (!cpu.flags.zf)
    {
        goto L_0x0048002d;
    }
    // 00480028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048002a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0048002d:
    // 0048002d  6828d44c00             -push 0x4cd428
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035048 /*0x4cd428*/;
    cpu.esp -= 4;
    // 00480032  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00480034  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 00480039  c7805404000000000000   -mov dword ptr [eax + 0x454], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */) = 0 /*0x0*/;
    // 00480043  e8a89f0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 00480048  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048004b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048004d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_480050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480050  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00480055  7508                   -jne 0x48005f
    if (!cpu.flags.zf)
    {
        goto L_0x0048005f;
    }
    // 00480057  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048005c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0048005f:
    // 0048005f  6818d44c00             -push 0x4cd418
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035032 /*0x4cd418*/;
    cpu.esp -= 4;
    // 00480064  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00480066  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0048006b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00480070  e87b9f0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 00480075  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480078  890d34894d00           -mov dword ptr [0x4d8934], ecx
    app->getMemory<x86::reg32>(x86::reg32(5081396) /* 0x4d8934 */) = cpu.ecx;
    // 0048007e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480083  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480090  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00480095  7508                   -jne 0x48009f
    if (!cpu.flags.zf)
    {
        goto L_0x0048009f;
    }
    // 00480097  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048009c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0048009f:
    // 0048009f  680cd44c00             -push 0x4cd40c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035020 /*0x4cd40c*/;
    cpu.esp -= 4;
    // 004800a4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004800a6  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 004800ab  e8409f0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 004800b0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004800b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004800b5  2eff15e0434c00         -call dword ptr cs:[0x4c43e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998112) /* 0x4c43e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004800bc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004800c1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4800d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004800d0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004800d4  3b15241b5600           +cmp edx, dword ptr [0x561b24]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004800da  7405                   -je 0x4800e1
    if (cpu.flags.zf)
    {
        goto L_0x004800e1;
    }
    // 004800dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004800de  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004800e1:
    // 004800e1  68fcd34c00             -push 0x4cd3fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035004 /*0x4cd3fc*/;
    cpu.esp -= 4;
    // 004800e6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004800e8  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 004800ed  e8fe9e0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 004800f2  8b0da4135600           -mov ecx, dword ptr [0x5613a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641124) /* 0x5613a4 */);
    // 004800f8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004800fb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004800fd  7408                   -je 0x480107
    if (cpu.flags.zf)
    {
        goto L_0x00480107;
    }
    // 004800ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480101  ff15a4135600           -call dword ptr [0x5613a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641124) /* 0x5613a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00480107:
    // 00480107  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480109  2eff1508444c00         -call dword ptr cs:[0x4c4408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998152) /* 0x4c4408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480110  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 00480115  b810914d00             -mov eax, 0x4d9110
    cpu.eax = 5083408 /*0x4d9110*/;
    // 0048011a  e86d830000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048011f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480121  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480130  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480134  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480136  7465                   -je 0x48019d
    if (cpu.flags.zf)
    {
        goto L_0x0048019d;
    }
    // 00480138  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048013c  3b0d241b5600           +cmp ecx, dword ptr [0x561b24]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480142  7559                   -jne 0x48019d
    if (!cpu.flags.zf)
    {
        goto L_0x0048019d;
    }
    // 00480144  833da413560000         +cmp dword ptr [0x5613a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641124) /* 0x5613a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048014b  7555                   -jne 0x4801a2
    if (!cpu.flags.zf)
    {
        goto L_0x004801a2;
    }
L_0x0048014d:
    // 0048014d  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480154  7409                   -je 0x48015f
    if (cpu.flags.zf)
    {
        goto L_0x0048015f;
    }
    // 00480156  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480158  2eff1508444c00         -call dword ptr cs:[0x4c4408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998152) /* 0x4c4408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048015f:
    // 0048015f  833d441b560000         +cmp dword ptr [0x561b44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643076) /* 0x561b44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480166  7521                   -jne 0x480189
    if (!cpu.flags.zf)
    {
        goto L_0x00480189;
    }
    // 00480168  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480169  68dcd34c00             -push 0x4cd3dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034972 /*0x4cd3dc*/;
    cpu.esp -= 4;
    // 0048016e  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00480170  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 00480175  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048017a  e8719e0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0048017f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480182  893d441b5600           -mov dword ptr [0x561b44], edi
    app->getMemory<x86::reg32>(x86::reg32(5643076) /* 0x561b44 */) = cpu.edi;
    // 00480188  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480189:
    // 00480189  68ecd34c00             -push 0x4cd3ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034988 /*0x4cd3ec*/;
    cpu.esp -= 4;
    // 0048018e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00480190  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 00480195  e8569e0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0048019a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0048019d:
    // 0048019d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048019f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004801a2:
    // 004801a2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004801a7  ff15a4135600           -call dword ptr [0x5613a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641124) /* 0x5613a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004801ad  eb9e                   -jmp 0x48014d
    goto L_0x0048014d;
}

/* align: skip 0x00 */
void Application::sub_4801b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004801b0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004801b4  a3441b5600             -mov dword ptr [0x561b44], eax
    app->getMemory<x86::reg32>(x86::reg32(5643076) /* 0x561b44 */) = cpu.eax;
    // 004801b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004801bb  741f                   -je 0x4801dc
    if (cpu.flags.zf)
    {
        goto L_0x004801dc;
    }
    // 004801bd  b8b4d34c00             -mov eax, 0x4cd3b4
    cpu.eax = 5034932 /*0x4cd3b4*/;
L_0x004801c2:
    // 004801c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004801c3  68c8d34c00             -push 0x4cd3c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034952 /*0x4cd3c8*/;
    cpu.esp -= 4;
    // 004801c8  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004801ca  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 004801cf  e81c9e0100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 004801d4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004801d7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004801d9  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004801dc:
    // 004801dc  b8bcd34c00             -mov eax, 0x4cd3bc
    cpu.eax = 5034940 /*0x4cd3bc*/;
    // 004801e1  ebdf                   -jmp 0x4801c2
    goto L_0x004801c2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4801f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004801f0  3d04010000             +cmp eax, 0x104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004801f5  752d                   -jne 0x480224
    if (!cpu.flags.zf)
    {
        goto L_0x00480224;
    }
L_0x004801f7:
    // 004801f7  83fa65                 +cmp edx, 0x65
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004801fa  7334                   -jae 0x480230
    if (!cpu.flags.cf)
    {
        goto L_0x00480230;
    }
    // 004801fc  83fa28                 +cmp edx, 0x28
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
    // 004801ff  0f83c9000000           -jae 0x4802ce
    if (!cpu.flags.cf)
    {
        goto L_0x004802ce;
    }
    // 00480205  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480208  0f8311010000           -jae 0x48031f
    if (!cpu.flags.cf)
    {
        goto L_0x0048031f;
    }
    // 0048020e  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480211  0f8319010000           -jae 0x480330
    if (!cpu.flags.cf)
    {
        goto L_0x00480330;
    }
    // 00480217  83fa21                 +cmp edx, 0x21
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048021a  750f                   -jne 0x48022b
    if (!cpu.flags.zf)
    {
        goto L_0x0048022b;
    }
    // 0048021c  ba00490000             -mov edx, 0x4900
    cpu.edx = 18688 /*0x4900*/;
    // 00480221  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480223  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480224:
    // 00480224  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480229  74cc                   -je 0x4801f7
    if (cpu.flags.zf)
    {
        goto L_0x004801f7;
    }
L_0x0048022b:
    // 0048022b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048022d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048022f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480230:
    // 00480230  0f864c010000           -jbe 0x480382
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480382;
    }
    // 00480236  83fa73                 +cmp edx, 0x73
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480239  731c                   -jae 0x480257
    if (!cpu.flags.cf)
    {
        goto L_0x00480257;
    }
    // 0048023b  83fa69                 +cmp edx, 0x69
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048023e  7364                   -jae 0x4802a4
    if (!cpu.flags.cf)
    {
        goto L_0x004802a4;
    }
    // 00480240  83fa67                 +cmp edx, 0x67
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480243  0f8241010000           -jb 0x48038a
    if (cpu.flags.cf)
    {
        goto L_0x0048038a;
    }
    // 00480249  0f8743010000           -ja 0x480392
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480392;
    }
    // 0048024f  ba51000000             -mov edx, 0x51
    cpu.edx = 81 /*0x51*/;
    // 00480254  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480256  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480257:
    // 00480257  0f864d010000           -jbe 0x4803aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004803aa;
    }
    // 0048025d  83fa77                 +cmp edx, 0x77
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480260  7317                   -jae 0x480279
    if (!cpu.flags.cf)
    {
        goto L_0x00480279;
    }
    // 00480262  83fa75                 +cmp edx, 0x75
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480265  0f8247010000           -jb 0x4803b2
    if (cpu.flags.cf)
    {
        goto L_0x004803b2;
    }
    // 0048026b  0f8749010000           -ja 0x4803ba
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004803ba;
    }
    // 00480271  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 00480276  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480278  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480279:
    // 00480279  0f8643010000           -jbe 0x4803c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004803c2;
    }
    // 0048027f  83fa79                 +cmp edx, 0x79
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480282  0f8242010000           -jb 0x4803ca
    if (cpu.flags.cf)
    {
        goto L_0x004803ca;
    }
    // 00480288  0f8644010000           -jbe 0x4803d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004803d2;
    }
    // 0048028e  83fa7a                 +cmp edx, 0x7a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480291  0f8643010000           -jbe 0x4803da
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004803da;
    }
    // 00480297  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048029a  758f                   -jne 0x48022b
    if (!cpu.flags.zf)
    {
        goto L_0x0048022b;
    }
    // 0048029c  ba00880000             -mov edx, 0x8800
    cpu.edx = 34816 /*0x8800*/;
    // 004802a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004802a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004802a4:
    // 004802a4  0f86f0000000           -jbe 0x48039a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048039a;
    }
    // 004802aa  83fa71                 +cmp edx, 0x71
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(113 /*0x71*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004802ad  7311                   -jae 0x4802c0
    if (!cpu.flags.cf)
    {
        goto L_0x004802c0;
    }
    // 004802af  83fa70                 +cmp edx, 0x70
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004802b2  0f8573ffffff           -jne 0x48022b
    if (!cpu.flags.zf)
    {
        goto L_0x0048022b;
    }
    // 004802b8  ba003b0000             -mov edx, 0x3b00
    cpu.edx = 15104 /*0x3b00*/;
    // 004802bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004802bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004802c0:
    // 004802c0  0f87dc000000           -ja 0x4803a2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004803a2;
    }
    // 004802c6  ba003c0000             -mov edx, 0x3c00
    cpu.edx = 15360 /*0x3c00*/;
    // 004802cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004802cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004802ce:
    // 004802ce  0f8686000000           -jbe 0x48035a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048035a;
    }
    // 004802d4  83fa61                 +cmp edx, 0x61
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004802d7  7316                   -jae 0x4802ef
    if (!cpu.flags.cf)
    {
        goto L_0x004802ef;
    }
    // 004802d9  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004802dc  732e                   -jae 0x48030c
    if (!cpu.flags.cf)
    {
        goto L_0x0048030c;
    }
    // 004802de  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004802e1  0f8544ffffff           -jne 0x48022b
    if (!cpu.flags.zf)
    {
        goto L_0x0048022b;
    }
    // 004802e7  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 004802ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004802ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004802ef:
    // 004802ef  0f8675000000           -jbe 0x48036a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048036a;
    }
    // 004802f5  83fa63                 +cmp edx, 0x63
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004802f8  0f8274000000           -jb 0x480372
    if (cpu.flags.cf)
    {
        goto L_0x00480372;
    }
    // 004802fe  0f8776000000           -ja 0x48037a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048037a;
    }
    // 00480304  ba47000000             -mov edx, 0x47
    cpu.edx = 71 /*0x47*/;
    // 00480309  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048030b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048030c:
    // 0048030c  7654                   -jbe 0x480362
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480362;
    }
    // 0048030e  83fa60                 +cmp edx, 0x60
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480311  0f8514ffffff           -jne 0x48022b
    if (!cpu.flags.zf)
    {
        goto L_0x0048022b;
    }
    // 00480317  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 0048031c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048031e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048031f:
    // 0048031f  7621                   -jbe 0x480342
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480342;
    }
    // 00480321  83fa26                 +cmp edx, 0x26
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480324  7224                   -jb 0x48034a
    if (cpu.flags.cf)
    {
        goto L_0x0048034a;
    }
    // 00480326  772a                   -ja 0x480352
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480352;
    }
    // 00480328  ba00480000             -mov edx, 0x4800
    cpu.edx = 18432 /*0x4800*/;
    // 0048032d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048032f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480330:
    // 00480330  7708                   -ja 0x48033a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048033a;
    }
    // 00480332  ba00510000             -mov edx, 0x5100
    cpu.edx = 20736 /*0x5100*/;
    // 00480337  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480339  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048033a:
    // 0048033a  ba004f0000             -mov edx, 0x4f00
    cpu.edx = 20224 /*0x4f00*/;
    // 0048033f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480341  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480342:
    // 00480342  ba00470000             -mov edx, 0x4700
    cpu.edx = 18176 /*0x4700*/;
    // 00480347  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480349  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048034a:
    // 0048034a  ba004b0000             -mov edx, 0x4b00
    cpu.edx = 19200 /*0x4b00*/;
    // 0048034f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480351  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480352:
    // 00480352  ba004d0000             -mov edx, 0x4d00
    cpu.edx = 19712 /*0x4d00*/;
    // 00480357  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480359  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048035a:
    // 0048035a  ba00500000             -mov edx, 0x5000
    cpu.edx = 20480 /*0x5000*/;
    // 0048035f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480361  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480362:
    // 00480362  ba00530000             -mov edx, 0x5300
    cpu.edx = 21248 /*0x5300*/;
    // 00480367  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480369  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048036a:
    // 0048036a  ba5a000000             -mov edx, 0x5a
    cpu.edx = 90 /*0x5a*/;
    // 0048036f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480371  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480372:
    // 00480372  ba58000000             -mov edx, 0x58
    cpu.edx = 88 /*0x58*/;
    // 00480377  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480379  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048037a:
    // 0048037a  ba41000000             -mov edx, 0x41
    cpu.edx = 65 /*0x41*/;
    // 0048037f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480381  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480382:
    // 00480382  ba004c0000             -mov edx, 0x4c00
    cpu.edx = 19456 /*0x4c00*/;
    // 00480387  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048038a:
    // 0048038a  ba44000000             -mov edx, 0x44
    cpu.edx = 68 /*0x44*/;
    // 0048038f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480391  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480392:
    // 00480392  ba57000000             -mov edx, 0x57
    cpu.edx = 87 /*0x57*/;
    // 00480397  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480399  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048039a:
    // 0048039a  ba45000000             -mov edx, 0x45
    cpu.edx = 69 /*0x45*/;
    // 0048039f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803a2:
    // 004803a2  ba003d0000             -mov edx, 0x3d00
    cpu.edx = 15616 /*0x3d00*/;
    // 004803a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803aa:
    // 004803aa  ba003e0000             -mov edx, 0x3e00
    cpu.edx = 15872 /*0x3e00*/;
    // 004803af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803b2:
    // 004803b2  ba003f0000             -mov edx, 0x3f00
    cpu.edx = 16128 /*0x3f00*/;
    // 004803b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803ba:
    // 004803ba  ba00410000             -mov edx, 0x4100
    cpu.edx = 16640 /*0x4100*/;
    // 004803bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803c2:
    // 004803c2  ba00420000             -mov edx, 0x4200
    cpu.edx = 16896 /*0x4200*/;
    // 004803c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803ca:
    // 004803ca  ba00430000             -mov edx, 0x4300
    cpu.edx = 17152 /*0x4300*/;
    // 004803cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803d2:
    // 004803d2  ba00440000             -mov edx, 0x4400
    cpu.edx = 17408 /*0x4400*/;
    // 004803d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803da:
    // 004803da  ba00870000             -mov edx, 0x8700
    cpu.edx = 34560 /*0x8700*/;
    // 004803df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004803e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4803f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004803f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004803f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004803f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004803f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004803f4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004803f7  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 004803fd  a198135600             -mov eax, dword ptr [0x561398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */);
    // 00480402  e8b17f0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00480407  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480409  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 0048040f  8b159c135600           -mov edx, dword ptr [0x56139c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */);
    // 00480415  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480417  39d6                   +cmp esi, edx
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
    // 00480419  7455                   -je 0x480470
    if (cpu.flags.zf)
    {
        goto L_0x00480470;
    }
L_0x0048041b:
    // 0048041b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048041d  7551                   -jne 0x480470
    if (!cpu.flags.zf)
    {
        goto L_0x00480470;
    }
    // 0048041f  893594135600           -mov dword ptr [0x561394], esi
    app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */) = cpu.esi;
    // 00480425  8b04b5000f5600         -mov eax, dword ptr [esi*4 + 0x560f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639936) /* 0x560f00 */ + cpu.esi * 4);
    // 0048042c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048042e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480430  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480433  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00480436  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0048043a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048043c  750e                   -jne 0x48044c
    if (!cpu.flags.zf)
    {
        goto L_0x0048044c;
    }
    // 0048043e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480440  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480442  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00480445  e8a64d0000             -call 0x4851f0
    cpu.esp -= 4;
    sub_4851f0(app, cpu);
    if (cpu.terminate) return;
    // 0048044a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048044c:
    // 0048044c  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 00480452  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480454  7512                   -jne 0x480468
    if (!cpu.flags.zf)
    {
        goto L_0x00480468;
    }
    // 00480456  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480459  8b35a0135600           -mov esi, dword ptr [0x5613a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641120) /* 0x5613a0 */);
    // 0048045f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480461  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480464  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480466  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00480468:
    // 00480468  3b359c135600           +cmp esi, dword ptr [0x56139c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048046e  75ab                   -jne 0x48041b
    if (!cpu.flags.zf)
    {
        goto L_0x0048041b;
    }
L_0x00480470:
    // 00480470  a198135600             -mov eax, dword ptr [0x561398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */);
    // 00480475  893594135600           -mov dword ptr [0x561394], esi
    app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */) = cpu.esi;
    // 0048047b  e8507f0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00480480  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480482  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480485  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 0048048b  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048048d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480490  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480491  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480492  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480493  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480494  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4804a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004804a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004804a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004804a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004804a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004804a5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004804a8  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 004804ae  a198135600             -mov eax, dword ptr [0x561398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */);
    // 004804b3  e8007f0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004804b8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004804ba  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 004804c0  8b159c135600           -mov edx, dword ptr [0x56139c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */);
    // 004804c6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004804c8  39d6                   +cmp esi, edx
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
    // 004804ca  7453                   -je 0x48051f
    if (cpu.flags.zf)
    {
        goto L_0x0048051f;
    }
L_0x004804cc:
    // 004804cc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004804ce  754f                   -jne 0x48051f
    if (!cpu.flags.zf)
    {
        goto L_0x0048051f;
    }
    // 004804d0  893594135600           -mov dword ptr [0x561394], esi
    app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */) = cpu.esi;
    // 004804d6  8b04b5000f5600         -mov eax, dword ptr [esi*4 + 0x560f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5639936) /* 0x560f00 */ + cpu.esi * 4);
    // 004804dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004804df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004804e1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004804e4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004804e7  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004804eb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004804ed  750e                   -jne 0x4804fd
    if (!cpu.flags.zf)
    {
        goto L_0x004804fd;
    }
    // 004804ef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004804f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004804f3  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004804f6  e8f54c0000             -call 0x4851f0
    cpu.esp -= 4;
    sub_4851f0(app, cpu);
    if (cpu.terminate) return;
    // 004804fb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004804fd:
    // 004804fd  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 00480503  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480506  8b35a0135600           -mov esi, dword ptr [0x5613a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641120) /* 0x5613a0 */);
    // 0048050c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048050e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480511  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480513  8b3d9c135600           -mov edi, dword ptr [0x56139c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */);
    // 00480519  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048051b  39fa                   +cmp edx, edi
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
    // 0048051d  75ad                   -jne 0x4804cc
    if (!cpu.flags.zf)
    {
        goto L_0x004804cc;
    }
L_0x0048051f:
    // 0048051f  a198135600             -mov eax, dword ptr [0x561398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */);
    // 00480524  893594135600           -mov dword ptr [0x561394], esi
    app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */) = cpu.esi;
    // 0048052a  e8a17e0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048052f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480531  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480534  8b3594135600           -mov esi, dword ptr [0x561394]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 0048053a  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048053c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048053f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480540  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480541  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480542  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480543  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480544  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480552  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480554  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00480556  a198135600             -mov eax, dword ptr [0x561398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */);
    // 0048055b  8b159c135600           -mov edx, dword ptr [0x56139c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */);
    // 00480561  e8527e0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00480566  66893495020f5600       -mov word ptr [edx*4 + 0x560f02], si
    app->getMemory<x86::reg16>(x86::reg32(5639938) /* 0x560f02 */ + cpu.edx * 4) = cpu.si;
    // 0048056e  880c95010f5600         -mov byte ptr [edx*4 + 0x560f01], cl
    app->getMemory<x86::reg8>(x86::reg32(5639937) /* 0x560f01 */ + cpu.edx * 4) = cpu.cl;
    // 00480575  881c95000f5600         -mov byte ptr [edx*4 + 0x560f00], bl
    app->getMemory<x86::reg8>(x86::reg32(5639936) /* 0x560f00 */ + cpu.edx * 4) = cpu.bl;
    // 0048057c  8b159c135600           -mov edx, dword ptr [0x56139c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */);
    // 00480582  42                     -inc edx
    (cpu.edx)++;
    // 00480583  8b0da0135600           -mov ecx, dword ptr [0x5613a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5641120) /* 0x5613a0 */);
    // 00480589  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048058b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048058e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480590  a194135600             -mov eax, dword ptr [0x561394]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 00480595  89159c135600           -mov dword ptr [0x56139c], edx
    app->getMemory<x86::reg32>(x86::reg32(5641116) /* 0x56139c */) = cpu.edx;
    // 0048059b  39d0                   +cmp eax, edx
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
    // 0048059d  7514                   -jne 0x4805b3
    if (!cpu.flags.zf)
    {
        goto L_0x004805b3;
    }
    // 0048059f  8b1594135600           -mov edx, dword ptr [0x561394]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */);
    // 004805a5  42                     -inc edx
    (cpu.edx)++;
    // 004805a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004805a8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004805ab  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004805ad  891594135600           -mov dword ptr [0x561394], edx
    app->getMemory<x86::reg32>(x86::reg32(5641108) /* 0x561394 */) = cpu.edx;
L_0x004805b3:
    // 004805b3  a198135600             -mov eax, dword ptr [0x561398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641112) /* 0x561398 */);
    // 004805b8  e8137e0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004805bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4805c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004805c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004805c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004805c2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004805c5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004805c7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004805ca  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004805cc  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004805d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004805d1  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 004805d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004805d8  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004805df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004805e1  7420                   -je 0x480603
    if (cpu.flags.zf)
    {
        goto L_0x00480603;
    }
    // 004805e3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004805e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004805e8  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004805ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x004805ed:
    // 004805ed  2eff15f8434c00         -call dword ptr cs:[0x4c43f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998136) /* 0x4c43f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004805f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004805f6  2eff15f4434c00         -call dword ptr cs:[0x4c43f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998132) /* 0x4c43f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004805fd  83c408                 +add esp, 8
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
    // 00480600  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480601  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480602  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480603:
    // 00480603  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480604  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480605  ebe6                   -jmp 0x4805ed
    goto L_0x004805ed;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480610  6898d34c00             -push 0x4cd398
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034904 /*0x4cd398*/;
    cpu.esp -= 4;
    // 00480615  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480617  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 0048061c  e8cf990100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 00480621  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480624  e803030000             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 00480629  b810064800             -mov eax, 0x480610
    cpu.eax = 4720144 /*0x480610*/;
    // 0048062e  e8a11c0000             -call 0x4822d4
    cpu.esp -= 4;
    sub_4822d4(app, cpu);
    if (cpu.terminate) return;
    // 00480633  e8ad560100             -call 0x495ce5
    cpu.esp -= 4;
    sub_495ce5(app, cpu);
    if (cpu.terminate) return;
    // 00480638  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048063a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480640  a3a4135600             -mov dword ptr [0x5613a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5641124) /* 0x5613a4 */) = cpu.eax;
    // 00480645  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480651  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480652  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480653  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480655  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00480657  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480658  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480659  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048065a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048065b  6858d34c00             -push 0x4cd358
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034840 /*0x4cd358*/;
    cpu.esp -= 4;
    // 00480660  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00480662  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 00480667  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480669  e882990100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 0048066e  8b2d241b5600           -mov ebp, dword ptr [0x561b24]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 00480674  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00480677  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00480679  7456                   -je 0x4806d1
    if (cpu.flags.zf)
    {
        goto L_0x004806d1;
    }
    // 0048067b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048067d  7545                   -jne 0x4806c4
    if (!cpu.flags.zf)
    {
        goto L_0x004806c4;
    }
    // 0048067f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480680  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480681  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480682  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480683  2eff15dc434c00         -call dword ptr cs:[0x4c43dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998108) /* 0x4c43dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048068a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048068c  7509                   -jne 0x480697
    if (!cpu.flags.zf)
    {
        goto L_0x00480697;
    }
    // 0048068e  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00480695:
    // 00480695  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00480697:
    // 00480697  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00480699  741c                   -je 0x4806b7
    if (cpu.flags.zf)
    {
        goto L_0x004806b7;
    }
    // 0048069b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048069d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004806a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806a3  6880d34c00             -push 0x4cd380
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034880 /*0x4cd380*/;
    cpu.esp -= 4;
    // 004806a8  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004806aa  6828894d00             -push 0x4d8928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5081384 /*0x4d8928*/;
    cpu.esp -= 4;
    // 004806af  e83c990100             -call 0x499ff0
    cpu.esp -= 4;
    sub_499ff0(app, cpu);
    if (cpu.terminate) return;
    // 004806b4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004806b7:
    // 004806b7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004806b9  7516                   -jne 0x4806d1
    if (!cpu.flags.zf)
    {
        goto L_0x004806d1;
    }
    // 004806bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004806c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004806c4:
    // 004806c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004806c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004806c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004806c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004806c8  2eff15ec434c00         -call dword ptr cs:[0x4c43ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998124) /* 0x4c43ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004806cf  ebc4                   -jmp 0x480695
    goto L_0x00480695;
L_0x004806d1:
    // 004806d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004806d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4806e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004806e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004806e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004806e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004806e3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004806e6  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004806ea  8b1554894d00           -mov edx, dword ptr [0x4d8954]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 004806f0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004806f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004806f4  750a                   -jne 0x480700
    if (!cpu.flags.zf)
    {
        goto L_0x00480700;
    }
    // 004806f6  e86d7c0000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 004806fb  a354894d00             -mov dword ptr [0x4d8954], eax
    app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */) = cpu.eax;
L_0x00480700:
    // 00480700  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00480705  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 0048070a  ba800f5600             -mov edx, 0x560f80
    cpu.edx = 5640064 /*0x560f80*/;
    // 0048070f  e8a47c0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00480714  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00480718  6840084800             -push 0x480840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4720704 /*0x480840*/;
    cpu.esp -= 4;
    // 0048071d  8b1d2c894d00           -mov ebx, dword ptr [0x4d892c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */);
    // 00480723  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00480727  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048072b  e8d6bb0100             -call 0x49c306
    cpu.esp -= 4;
    sub_49c306(app, cpu);
    if (cpu.terminate) return;
    // 00480730  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480732  7449                   -je 0x48077d
    if (cpu.flags.zf)
    {
        goto L_0x0048077d;
    }
    // 00480734  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480736  7540                   -jne 0x480778
    if (!cpu.flags.zf)
    {
        goto L_0x00480778;
    }
    // 00480738  b940084800             -mov ecx, 0x480840
    cpu.ecx = 4720704 /*0x480840*/;
    // 0048073d  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00480742  8b152c894d00           -mov edx, dword ptr [0x4d892c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */);
    // 00480748  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 0048074e  b8800f5600             -mov eax, 0x560f80
    cpu.eax = 5640064 /*0x560f80*/;
    // 00480753  e894bc0100             -call 0x49c3ec
    cpu.esp -= 4;
    sub_49c3ec(app, cpu);
    if (cpu.terminate) return;
    // 00480758  ff0d2c894d00           -dec dword ptr [0x4d892c]
    (app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */))--;
L_0x0048075e:
    // 0048075e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00480763:
    // 00480763  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 00480768  e8637c0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048076d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048076f  83c408                 +add esp, 8
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
    // 00480772  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480773  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480774  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480775  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00480778:
    // 00480778  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048077b  ebe1                   -jmp 0x48075e
    goto L_0x0048075e;
L_0x0048077d:
    // 0048077d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048077f  74e2                   -je 0x480763
    if (cpu.flags.zf)
    {
        goto L_0x00480763;
    }
    // 00480781  8b0d2c894d00           -mov ecx, dword ptr [0x4d892c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */);
    // 00480787  81f980000000           +cmp ecx, 0x80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048078d  73d4                   -jae 0x480763
    if (!cpu.flags.cf)
    {
        goto L_0x00480763;
    }
    // 0048078f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00480793  b8800f5600             -mov eax, 0x560f80
    cpu.eax = 5640064 /*0x560f80*/;
    // 00480798  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0048079b  893ccd840f5600         -mov dword ptr [ecx*8 + 0x560f84], edi
    app->getMemory<x86::reg32>(x86::reg32(5640068) /* 0x560f84 */ + cpu.ecx * 8) = cpu.edi;
    // 004807a2  891d2c894d00           -mov dword ptr [0x4d892c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */) = cpu.ebx;
    // 004807a8  8914cd800f5600         -mov dword ptr [ecx*8 + 0x560f80], edx
    app->getMemory<x86::reg32>(x86::reg32(5640064) /* 0x560f80 */ + cpu.ecx * 8) = cpu.edx;
    // 004807af  b940084800             -mov ecx, 0x480840
    cpu.ecx = 4720704 /*0x480840*/;
    // 004807b4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004807b6  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004807bb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004807c0  e827bc0100             -call 0x49c3ec
    cpu.esp -= 4;
    sub_49c3ec(app, cpu);
    if (cpu.terminate) return;
    // 004807c5  eb9c                   -jmp 0x480763
    goto L_0x00480763;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4807d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004807d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004807d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004807d2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004807d5  8b1554894d00           -mov edx, dword ptr [0x4d8954]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 004807db  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004807dd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004807df  750a                   -jne 0x4807eb
    if (!cpu.flags.zf)
    {
        goto L_0x004807eb;
    }
    // 004807e1  e8827b0000             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 004807e6  a354894d00             -mov dword ptr [0x4d8954], eax
    app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */) = cpu.eax;
L_0x004807eb:
    // 004807eb  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004807f0  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 004807f5  ba800f5600             -mov edx, 0x560f80
    cpu.edx = 5640064 /*0x560f80*/;
    // 004807fa  e8b97b0000             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004807ff  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00480803  6840084800             -push 0x480840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4720704 /*0x480840*/;
    cpu.esp -= 4;
    // 00480808  8b1d2c894d00           -mov ebx, dword ptr [0x4d892c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081388) /* 0x4d892c */);
    // 0048080e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00480812  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480816  e8ebba0100             -call 0x49c306
    cpu.esp -= 4;
    sub_49c306(app, cpu);
    if (cpu.terminate) return;
    // 0048081b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048081d  7403                   -je 0x480822
    if (cpu.flags.zf)
    {
        goto L_0x00480822;
    }
    // 0048081f  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00480822:
    // 00480822  a154894d00             -mov eax, dword ptr [0x4d8954]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081428) /* 0x4d8954 */);
    // 00480827  e8a47b0000             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048082c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048082e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00480831  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480832  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480833  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480841  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00480843  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00480845  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480847  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480848  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480852  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480855  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480858  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048085a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048085c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048085e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00480860  7e0c                   -jle 0x48086e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048086e;
    }
L_0x00480862:
    // 00480862  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00480864  ff154cb54d00           -call dword ptr [0x4db54c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092684) /* 0x4db54c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048086a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048086c  7508                   -jne 0x480876
    if (!cpu.flags.zf)
    {
        goto L_0x00480876;
    }
L_0x0048086e:
    // 0048086e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480870  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480873  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480874  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480875  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480876:
    // 00480876  e819430000             -call 0x484b94
    cpu.esp -= 4;
    sub_484b94(app, cpu);
    if (cpu.terminate) return;
    // 0048087b  42                     -inc edx
    (cpu.edx)++;
    // 0048087c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048087e  7408                   -je 0x480888
    if (cpu.flags.zf)
    {
        goto L_0x00480888;
    }
    // 00480880  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00480883  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00480886  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00480888:
    // 00480888  39da                   +cmp edx, ebx
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
    // 0048088a  7cd6                   -jl 0x480862
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480862;
    }
    // 0048088c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048088e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480891  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480892  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480893  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480894(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480894  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480895  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048089a  e8b1ffffff             -call 0x480850
    cpu.esp -= 4;
    sub_480850(app, cpu);
    if (cpu.terminate) return;
    // 0048089f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4808b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004808b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004808b1  8b35a0894d00           -mov esi, dword ptr [0x4d89a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 004808b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004808b8  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004808ba  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004808bc  e8cfcc0000             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 004808c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004808c3  7402                   -je 0x4808c7
    if (cpu.flags.zf)
    {
        goto L_0x004808c7;
    }
    // 004808c5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004808c7:
    // 004808c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4808cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004808cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004808cd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004808cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004808d1  8b1da0894d00           -mov ebx, dword ptr [0x4d89a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 004808d7  e8b4cc0000             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 004808dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004808de  7402                   -je 0x4808e2
    if (cpu.flags.zf)
    {
        goto L_0x004808e2;
    }
    // 004808e0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004808e2:
    // 004808e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4808e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004808e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004808e5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004808e7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004808e9  8b1da0894d00           -mov ebx, dword ptr [0x4d89a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 004808ef  e89ccc0000             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 004808f4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004808f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480900  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480904  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480905  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048090a  b894904d00             -mov eax, 0x4d9094
    cpu.eax = 5083284 /*0x4d9094*/;
    // 0048090f  e828000000             -call 0x48093c
    cpu.esp -= 4;
    sub_48093c(app, cpu);
    if (cpu.terminate) return;
    // 00480914  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480915  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480918(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480918  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480919  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048091e  b8cc904d00             -mov eax, 0x4d90cc
    cpu.eax = 5083340 /*0x4d90cc*/;
    // 00480923  e814000000             -call 0x48093c
    cpu.esp -= 4;
    sub_48093c(app, cpu);
    if (cpu.terminate) return;
    // 00480928  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480929  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48092c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048092c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048092d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00480932  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480934  e803000000             -call 0x48093c
    cpu.esp -= 4;
    sub_48093c(app, cpu);
    if (cpu.terminate) return;
    // 00480939  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048093a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48093c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048093c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048093d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048093e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048093f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480940  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480941  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480943  8b1568b54d00           -mov edx, dword ptr [0x4db568]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092712) /* 0x4db568 */);
    // 00480949  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0048094e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480950  7540                   -jne 0x480992
    if (!cpu.flags.zf)
    {
        goto L_0x00480992;
    }
    // 00480952  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480954  7444                   -je 0x48099a
    if (cpu.flags.zf)
    {
        goto L_0x0048099a;
    }
    // 00480956  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480958  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048095b  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 00480960  e8e3c10000             -call 0x48cb48
    cpu.esp -= 4;
    sub_48cb48(app, cpu);
    if (cpu.terminate) return;
L_0x00480965:
    // 00480965  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00480967:
    // 00480967  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480969  7461                   -je 0x4809cc
    if (cpu.flags.zf)
    {
        goto L_0x004809cc;
    }
    // 0048096b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048096d  7537                   -jne 0x4809a6
    if (!cpu.flags.zf)
    {
        goto L_0x004809a6;
    }
    // 0048096f  833d008a4d0000         +cmp dword ptr [0x4d8a00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081600) /* 0x4d8a00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480976  7435                   -je 0x4809ad
    if (cpu.flags.zf)
    {
        goto L_0x004809ad;
    }
L_0x00480978:
    // 00480978  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0048097d  8b35008a4d00           -mov esi, dword ptr [0x4d8a00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5081600) /* 0x4d8a00 */);
L_0x00480983:
    // 00480983  bf5c904d00             -mov edi, 0x4d905c
    cpu.edi = 5083228 /*0x4d905c*/;
    // 00480988  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048098a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048098c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048098d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048098e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048098f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480990  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480991  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480992:
    // 00480992  ff1568b54d00           -call dword ptr [0x4db568]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092712) /* 0x4db568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480998  ebcb                   -jmp 0x480965
    goto L_0x00480965;
L_0x0048099a:
    // 0048099a  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 0048099f  e8f8c20000             -call 0x48cc9c
    cpu.esp -= 4;
    sub_48cc9c(app, cpu);
    if (cpu.terminate) return;
    // 004809a4  ebc1                   -jmp 0x480967
    goto L_0x00480967;
L_0x004809a6:
    // 004809a6  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004809ab  ebd6                   -jmp 0x480983
    goto L_0x00480983;
L_0x004809ad:
    // 004809ad  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004809b2  8b0d048a4d00           -mov ecx, dword ptr [0x4d8a04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 004809b8  8b1da0894d00           -mov ebx, dword ptr [0x4d89a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 004809be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004809c0  e89bcd0000             -call 0x48d760
    cpu.esp -= 4;
    sub_48d760(app, cpu);
    if (cpu.terminate) return;
    // 004809c5  a3008a4d00             -mov dword ptr [0x4d8a00], eax
    app->getMemory<x86::reg32>(x86::reg32(5081600) /* 0x4d8a00 */) = cpu.eax;
    // 004809ca  ebac                   -jmp 0x480978
    goto L_0x00480978;
L_0x004809cc:
    // 004809cc  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004809d1  b85c904d00             -mov eax, 0x4d905c
    cpu.eax = 5083228 /*0x4d905c*/;
    // 004809d6  e8b17a0000             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 004809db  a0b0904d00             -mov al, byte ptr [0x4d90b0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083312) /* 0x4d90b0 */);
    // 004809e0  a278904d00             -mov byte ptr [0x4d9078], al
    app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */) = cpu.al;
    // 004809e5  a0b1904d00             -mov al, byte ptr [0x4d90b1]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083313) /* 0x4d90b1 */);
    // 004809ea  a279904d00             -mov byte ptr [0x4d9079], al
    app->getMemory<x86::reg8>(x86::reg32(5083257) /* 0x4d9079 */) = cpu.al;
    // 004809ef  a0b2904d00             -mov al, byte ptr [0x4d90b2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083314) /* 0x4d90b2 */);
    // 004809f4  a27a904d00             -mov byte ptr [0x4d907a], al
    app->getMemory<x86::reg8>(x86::reg32(5083258) /* 0x4d907a */) = cpu.al;
    // 004809f9  a1c4904d00             -mov eax, dword ptr [0x4d90c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083332) /* 0x4d90c4 */);
    // 004809fe  a38c904d00             -mov dword ptr [0x4d908c], eax
    app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */) = cpu.eax;
    // 00480a03  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00480a05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480a0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a0d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480a0f  e828ffffff             -call 0x48093c
    cpu.esp -= 4;
    sub_48093c(app, cpu);
    if (cpu.terminate) return;
    // 00480a14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a19  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00480a1e  e819ffffff             -call 0x48093c
    cpu.esp -= 4;
    sub_48093c(app, cpu);
    if (cpu.terminate) return;
    // 00480a23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480a28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a28  b894904d00             -mov eax, 0x4d9094
    cpu.eax = 5083284 /*0x4d9094*/;
    // 00480a2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a30  b8cc904d00             -mov eax, 0x4d90cc
    cpu.eax = 5083340 /*0x4d90cc*/;
    // 00480a35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480a41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480a42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480a43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480a44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480a45  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00480a48  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480a4a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480a4c  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00480a4f  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480a55  baa0ea5600             -mov edx, 0x56eaa0
    cpu.edx = 5696160 /*0x56eaa0*/;
    // 00480a5a  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00480a5e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480a60  bb9f860100             -mov ebx, 0x1869f
    cpu.ebx = 99999 /*0x1869f*/;
    // 00480a65  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 00480a68  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480a6d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00480a73  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480a76  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00480a7a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480a7c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480a7e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x00480a82:
    // 00480a82  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480a85  0fb672fe               -movzx esi, byte ptr [edx - 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */));
    // 00480a89  0fb67afd               -movzx edi, byte ptr [edx - 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */));
    // 00480a8d  8a88808a4d00           -mov cl, byte ptr [eax + 0x4d8a80]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5081728) /* 0x4d8a80 */);
    // 00480a93  0fb66afc               -movzx ebp, byte ptr [edx - 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */));
    // 00480a97  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00480a99  742b                   -je 0x480ac6
    if (cpu.flags.zf)
    {
        goto L_0x00480ac6;
    }
    // 00480a9b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480a9f  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00480aa1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00480aa3  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00480aa6  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480aaa  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00480aac  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00480aaf  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00480ab2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00480ab5  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00480ab7  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00480aba  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00480abc  39d9                   +cmp ecx, ebx
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
    // 00480abe  7d06                   -jge 0x480ac6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480ac6;
    }
    // 00480ac0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00480ac2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00480ac6:
    // 00480ac6  40                     -inc eax
    (cpu.eax)++;
    // 00480ac7  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480acc  7cb4                   -jl 0x480a82
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480a82;
    }
    // 00480ace  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00480ad2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00480ad5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480adc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480add  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480ade  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480ae0  8a2578904d00           -mov ah, byte ptr [0x4d9078]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 00480ae6  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480ae9  761c                   -jbe 0x480b07
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480b07;
    }
    // 00480aeb  80fc0f                 +cmp ah, 0xf
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480aee  745e                   -je 0x480b4e
    if (cpu.flags.zf)
    {
        goto L_0x00480b4e;
    }
    // 00480af0  80fc10                 +cmp ah, 0x10
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
    // 00480af3  0f8483000000           -je 0x480b7c
    if (cpu.flags.zf)
    {
        goto L_0x00480b7c;
    }
    // 00480af9  80fc18                 +cmp ah, 0x18
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480afc  0f829f000000           -jb 0x480ba1
    if (cpu.flags.cf)
    {
        goto L_0x00480ba1;
    }
    // 00480b02  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480b07:
    // 00480b07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480b08  8b0d7c8a4d00           -mov ecx, dword ptr [0x4d8a7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */);
    // 00480b0e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480b10  7427                   -je 0x480b39
    if (cpu.flags.zf)
    {
        goto L_0x00480b39;
    }
    // 00480b12  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b14  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00480b1a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00480b1d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480b1f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00480b22  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00480b28  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00480b2b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00480b2e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00480b30  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480b32  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00480b34  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 00480b37  eb0f                   -jmp 0x480b48
    goto L_0x00480b48;
L_0x00480b39:
    // 00480b39  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00480b3b  8d05a0ea5600           -lea eax, [0x56eaa0]
    cpu.eax = x86::reg32(x86::reg32(5696160) /* 0x56eaa0 */);
    // 00480b41  e8fafeffff             -call 0x480a40
    cpu.esp -= 4;
    sub_480a40(app, cpu);
    if (cpu.terminate) return;
    // 00480b46  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00480b48:
    // 00480b48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b49  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480b4e:
    // 00480b4e  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00480b50  7425                   -je 0x480b77
    if (cpu.flags.zf)
    {
        goto L_0x00480b77;
    }
    // 00480b52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b54  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00480b5a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00480b5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480b5f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00480b62  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00480b68  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00480b6b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00480b6e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480b70  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00480b77:
    // 00480b77  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480b7c:
    // 00480b7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b7e  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00480b84  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00480b87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480b89  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00480b8c  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00480b92  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00480b95  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00480b98  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480b9a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480b9c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480b9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480ba1:
    // 00480ba1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480ba3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480ba5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ba6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ba7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480bb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480bb4  8b0d74904d00           -mov ecx, dword ptr [0x4d9074]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 00480bba  8b156c904d00           -mov edx, dword ptr [0x4d906c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 00480bc0  8b1d68904d00           -mov ebx, dword ptr [0x4d9068]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 00480bc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480bc7  a170904d00             -mov eax, dword ptr [0x4d9070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 00480bcc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00480bce  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480bd0  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00480bd2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480bd4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480bd6  e8b55e0000             -call 0x486a90
    cpu.esp -= 4;
    sub_486a90(app, cpu);
    if (cpu.terminate) return;
    // 00480bdb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
