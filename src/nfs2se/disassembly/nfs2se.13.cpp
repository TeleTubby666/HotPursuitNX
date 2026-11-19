#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_469c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469c20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469c21  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00469c23  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469c27  3c20                   +cmp al, 0x20
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
    // 00469c29  7538                   -jne 0x469c63
    if (!cpu.flags.zf)
    {
        goto L_0x00469c63;
    }
    // 00469c2b  b02d                   -mov al, 0x2d
    cpu.al = 45 /*0x2d*/;
L_0x00469c2d:
    // 00469c2d  2c2d                   -sub al, 0x2d
    (cpu.al) -= x86::reg8(x86::sreg8(45 /*0x2d*/));
    // 00469c2f  3c0e                   +cmp al, 0xe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469c31  7740                   -ja 0x469c73
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00469c73;
    }
    // 00469c33  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469c36  754d                   -jne 0x469c85
    if (!cpu.flags.zf)
    {
        goto L_0x00469c85;
    }
    // 00469c38  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00469c3d  8b8077904c00           -mov eax, dword ptr [eax + 0x4c9077]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017719) /* 0x4c9077 */);
    // 00469c43  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00469c46  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x00469c49:
    // 00469c49  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00469c4b  c7021d000000           -mov dword ptr [edx], 0x1d
    app->getMemory<x86::reg32>(cpu.edx) = 29 /*0x1d*/;
    // 00469c51  833900                 +cmp dword ptr [ecx], 0
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
    // 00469c54  0f8cc9000000           -jl 0x469d23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469d23;
    }
    // 00469c5a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00469c5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469c60  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00469c63:
    // 00469c63  3c2c                   +cmp al, 0x2c
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469c65  7504                   -jne 0x469c6b
    if (!cpu.flags.zf)
    {
        goto L_0x00469c6b;
    }
    // 00469c67  b02e                   -mov al, 0x2e
    cpu.al = 46 /*0x2e*/;
    // 00469c69  ebc2                   -jmp 0x469c2d
    goto L_0x00469c2d;
L_0x00469c6b:
    // 00469c6b  3c27                   +cmp al, 0x27
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(39 /*0x27*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00469c6d  75be                   -jne 0x469c2d
    if (!cpu.flags.zf)
    {
        goto L_0x00469c2d;
    }
    // 00469c6f  b03b                   -mov al, 0x3b
    cpu.al = 59 /*0x3b*/;
    // 00469c71  ebba                   -jmp 0x469c2d
    goto L_0x00469c2d;
L_0x00469c73:
    // 00469c73  c70181ffffff           -mov dword ptr [ecx], 0xffffff81
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967169 /*0xffffff81*/;
    // 00469c79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00469c7b  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00469c81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469c82  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00469c85:
    // 00469c85  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469c88  750a                   -jne 0x469c94
    if (!cpu.flags.zf)
    {
        goto L_0x00469c94;
    }
    // 00469c8a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00469c8f  83c029                 +add eax, 0x29
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00469c92  ebb5                   -jmp 0x469c49
    goto L_0x00469c49;
L_0x00469c94:
    // 00469c94  833c9d7cf34d0000       +cmp dword ptr [ebx*4 + 0x4df37c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108604) /* 0x4df37c */ + cpu.ebx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469c9c  742c                   -je 0x469cca
    if (cpu.flags.zf)
    {
        goto L_0x00469cca;
    }
    // 00469c9e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00469ca3  8b9877904c00           -mov ebx, dword ptr [eax + 0x4c9077]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017719) /* 0x4c9077 */);
    // 00469ca9  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00469cac  83c316                 -add ebx, 0x16
    (cpu.ebx) += x86::reg32(x86::sreg32(22 /*0x16*/));
    // 00469caf  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00469cb1  8b8086904c00           -mov eax, dword ptr [eax + 0x4c9086]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017734) /* 0x4c9086 */);
    // 00469cb7  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00469cba  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00469cbc  833900                 +cmp dword ptr [ecx], 0
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
    // 00469cbf  7c62                   -jl 0x469d23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469d23;
    }
    // 00469cc1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00469cc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469cc7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00469cca:
    // 00469cca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00469ccc  752c                   -jne 0x469cfa
    if (!cpu.flags.zf)
    {
        goto L_0x00469cfa;
    }
    // 00469cce  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00469cd3  8b9877904c00           -mov ebx, dword ptr [eax + 0x4c9077]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017719) /* 0x4c9077 */);
    // 00469cd9  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00469cdc  83c30b                 -add ebx, 0xb
    (cpu.ebx) += x86::reg32(x86::sreg32(11 /*0xb*/));
    // 00469cdf  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00469ce1  8b8086904c00           -mov eax, dword ptr [eax + 0x4c9086]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017734) /* 0x4c9086 */);
    // 00469ce7  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00469cea  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00469cec  833900                 +cmp dword ptr [ecx], 0
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
    // 00469cef  7c32                   -jl 0x469d23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469d23;
    }
    // 00469cf1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00469cf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469cf7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00469cfa:
    // 00469cfa  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00469cff  8b9877904c00           -mov ebx, dword ptr [eax + 0x4c9077]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017719) /* 0x4c9077 */);
    // 00469d05  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00469d08  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00469d0a  8b8086904c00           -mov eax, dword ptr [eax + 0x4c9086]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5017734) /* 0x4c9086 */);
    // 00469d10  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00469d13  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00469d15  833900                 +cmp dword ptr [ecx], 0
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
    // 00469d18  7c09                   -jl 0x469d23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469d23;
    }
    // 00469d1a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00469d1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d20  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00469d23:
    // 00469d23  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00469d25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d26  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_469d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469d32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469d33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469d34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00469d36  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00469d38  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00469d3a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00469d3c  83f8ff                 +cmp eax, -1
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
    // 00469d3f  755c                   -jne 0x469d9d
    if (!cpu.flags.zf)
    {
        goto L_0x00469d9d;
    }
    // 00469d41  833db0f34d0000         +cmp dword ptr [0x4df3b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469d48  744f                   -je 0x469d99
    if (cpu.flags.zf)
    {
        goto L_0x00469d99;
    }
    // 00469d4a  833db4f34d0000         +cmp dword ptr [0x4df3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108660) /* 0x4df3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469d51  7446                   -je 0x469d99
    if (cpu.flags.zf)
    {
        goto L_0x00469d99;
    }
    // 00469d53  a1bcf34d00             -mov eax, dword ptr [0x4df3bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 00469d58  bb95000000             -mov ebx, 0x95
    cpu.ebx = 149 /*0x95*/;
    // 00469d5d  83f805                 +cmp eax, 5
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
    // 00469d60  7526                   -jne 0x469d88
    if (!cpu.flags.zf)
    {
        goto L_0x00469d88;
    }
    // 00469d62  bf31000000             -mov edi, 0x31
    cpu.edi = 49 /*0x31*/;
    // 00469d67  beef010000             -mov esi, 0x1ef
    cpu.esi = 495 /*0x1ef*/;
L_0x00469d6c:
    // 00469d6c  a1a8885100             -mov eax, dword ptr [0x5188a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343400) /* 0x5188a8 */);
L_0x00469d71:
    // 00469d71  893d30c74c00           -mov dword ptr [0x4cc730], edi
    app->getMemory<x86::reg32>(x86::reg32(5031728) /* 0x4cc730 */) = cpu.edi;
    // 00469d77  89352cc74c00           -mov dword ptr [0x4cc72c], esi
    app->getMemory<x86::reg32>(x86::reg32(5031724) /* 0x4cc72c */) = cpu.esi;
    // 00469d7d  891d38c74c00           -mov dword ptr [0x4cc738], ebx
    app->getMemory<x86::reg32>(x86::reg32(5031736) /* 0x4cc738 */) = cpu.ebx;
    // 00469d83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469d87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469d88:
    // 00469d88  83f809                 +cmp eax, 9
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
    // 00469d8b  75df                   -jne 0x469d6c
    if (!cpu.flags.zf)
    {
        goto L_0x00469d6c;
    }
    // 00469d8d  bf3e000000             -mov edi, 0x3e
    cpu.edi = 62 /*0x3e*/;
    // 00469d92  bef8010000             -mov esi, 0x1f8
    cpu.esi = 504 /*0x1f8*/;
    // 00469d97  ebd3                   -jmp 0x469d6c
    goto L_0x00469d6c;
L_0x00469d99:
    // 00469d99  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00469d9b  ebd4                   -jmp 0x469d71
    goto L_0x00469d71;
L_0x00469d9d:
    // 00469d9d  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469da0  7527                   -jne 0x469dc9
    if (!cpu.flags.zf)
    {
        goto L_0x00469dc9;
    }
    // 00469da2  833dbcf34d0000         +cmp dword ptr [0x4df3bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469da9  75ee                   -jne 0x469d99
    if (!cpu.flags.zf)
    {
        goto L_0x00469d99;
    }
    // 00469dab  833db0f34d0000         +cmp dword ptr [0x4df3b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469db2  74e5                   -je 0x469d99
    if (cpu.flags.zf)
    {
        goto L_0x00469d99;
    }
    // 00469db4  833db4f34d0000         +cmp dword ptr [0x4df3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108660) /* 0x4df3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469dbb  74dc                   -je 0x469d99
    if (cpu.flags.zf)
    {
        goto L_0x00469d99;
    }
    // 00469dbd  bb95000000             -mov ebx, 0x95
    cpu.ebx = 149 /*0x95*/;
    // 00469dc2  a1b8885100             -mov eax, dword ptr [0x5188b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343416) /* 0x5188b8 */);
    // 00469dc7  eba8                   -jmp 0x469d71
    goto L_0x00469d71;
L_0x00469dc9:
    // 00469dc9  83f8fd                 +cmp eax, -3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469dcc  7538                   -jne 0x469e06
    if (!cpu.flags.zf)
    {
        goto L_0x00469e06;
    }
    // 00469dce  a1b0f34d00             -mov eax, dword ptr [0x4df3b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
    // 00469dd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00469dd5  749a                   -je 0x469d71
    if (cpu.flags.zf)
    {
        goto L_0x00469d71;
    }
    // 00469dd7  8b1570f34d00           -mov edx, dword ptr [0x4df370]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
    // 00469ddd  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 00469de2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469de4  7414                   -je 0x469dfa
    if (cpu.flags.zf)
    {
        goto L_0x00469dfa;
    }
    // 00469de6  8b0d40f34d00           -mov ecx, dword ptr [0x4df340]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
    // 00469dec  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 00469df1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00469df3  7505                   -jne 0x469dfa
    if (!cpu.flags.zf)
    {
        goto L_0x00469dfa;
    }
    // 00469df5  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
L_0x00469dfa:
    // 00469dfa  8b048558885100         -mov eax, dword ptr [eax*4 + 0x518858]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343320) /* 0x518858 */ + cpu.eax * 4);
    // 00469e01  e96bffffff             -jmp 0x469d71
    goto L_0x00469d71;
L_0x00469e06:
    // 00469e06  833d34f34d0000         +cmp dword ptr [0x4df334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e0d  743c                   -je 0x469e4b
    if (cpu.flags.zf)
    {
        goto L_0x00469e4b;
    }
    // 00469e0f  833d70f34d0000         +cmp dword ptr [0x4df370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e16  7403                   -je 0x469e1b
    if (cpu.flags.zf)
    {
        goto L_0x00469e1b;
    }
    // 00469e18  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
L_0x00469e1b:
    // 00469e1b  833d40f34d0000         +cmp dword ptr [0x4df340], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e22  7403                   -je 0x469e27
    if (cpu.flags.zf)
    {
        goto L_0x00469e27;
    }
    // 00469e24  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
L_0x00469e27:
    // 00469e27  833d74f34d0000         +cmp dword ptr [0x4df374], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108596) /* 0x4df374 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e2e  7403                   -je 0x469e33
    if (cpu.flags.zf)
    {
        goto L_0x00469e33;
    }
    // 00469e30  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x00469e33:
    // 00469e33  833d44f34d0000         +cmp dword ptr [0x4df344], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108548) /* 0x4df344 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x00469e3a:
    // 00469e3a  7403                   -je 0x469e3f
    if (cpu.flags.zf)
    {
        goto L_0x00469e3f;
    }
    // 00469e3c  83c00f                 +add eax, 0xf
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00469e3f:
    // 00469e3f  8b0485845f5100         -mov eax, dword ptr [eax*4 + 0x515f84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332868) /* 0x515f84 */ + cpu.eax * 4);
    // 00469e46  e926ffffff             -jmp 0x469d71
    goto L_0x00469d71;
L_0x00469e4b:
    // 00469e4b  833db0f34d0000         +cmp dword ptr [0x4df3b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e52  742d                   -je 0x469e81
    if (cpu.flags.zf)
    {
        goto L_0x00469e81;
    }
    // 00469e54  833dbcf34d00ff         +cmp dword ptr [0x4df3bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e5b  7e24                   -jle 0x469e81
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00469e81;
    }
    // 00469e5d  833db4f34d0000         +cmp dword ptr [0x4df3b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108660) /* 0x4df3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e64  7403                   -je 0x469e69
    if (cpu.flags.zf)
    {
        goto L_0x00469e69;
    }
    // 00469e66  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00469e69:
    // 00469e69  833d70f34d0000         +cmp dword ptr [0x4df370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e70  7403                   -je 0x469e75
    if (cpu.flags.zf)
    {
        goto L_0x00469e75;
    }
    // 00469e72  83c005                 +add eax, 5
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00469e75:
    // 00469e75  8b048558885100         -mov eax, dword ptr [eax*4 + 0x518858]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343320) /* 0x518858 */ + cpu.eax * 4);
    // 00469e7c  e9f0feffff             -jmp 0x469d71
    goto L_0x00469d71;
L_0x00469e81:
    // 00469e81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469e83  7525                   -jne 0x469eaa
    if (!cpu.flags.zf)
    {
        goto L_0x00469eaa;
    }
    // 00469e85  833d70f34d0000         +cmp dword ptr [0x4df370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469e8c  74b1                   -je 0x469e3f
    if (cpu.flags.zf)
    {
        goto L_0x00469e3f;
    }
    // 00469e8e  8b1540f34d00           -mov edx, dword ptr [0x4df340]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
    // 00469e94  83c019                 -add eax, 0x19
    (cpu.eax) += x86::reg32(x86::sreg32(25 /*0x19*/));
    // 00469e97  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469e99  74a4                   -je 0x469e3f
    if (cpu.flags.zf)
    {
        goto L_0x00469e3f;
    }
    // 00469e9b  83e80a                 +sub eax, 0xa
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00469e9e  8b0485845f5100         -mov eax, dword ptr [eax*4 + 0x515f84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332868) /* 0x515f84 */ + cpu.eax * 4);
    // 00469ea5  e9c7feffff             -jmp 0x469d71
    goto L_0x00469d71;
L_0x00469eaa:
    // 00469eaa  83fa01                 +cmp edx, 1
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
    // 00469ead  7519                   -jne 0x469ec8
    if (!cpu.flags.zf)
    {
        goto L_0x00469ec8;
    }
    // 00469eaf  8b1570f34d00           -mov edx, dword ptr [0x4df370]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108592) /* 0x4df370 */);
    // 00469eb5  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00469eb8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469eba  7483                   -je 0x469e3f
    if (cpu.flags.zf)
    {
        goto L_0x00469e3f;
    }
    // 00469ebc  833d40f34d0000         +cmp dword ptr [0x4df340], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469ec3  e972ffffff             -jmp 0x469e3a
    goto L_0x00469e3a;
L_0x00469ec8:
    // 00469ec8  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469ecb  0f856effffff           -jne 0x469e3f
    if (!cpu.flags.zf)
    {
        goto L_0x00469e3f;
    }
    // 00469ed1  83c00a                 +add eax, 0xa
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00469ed4  8b0485845f5100         -mov eax, dword ptr [eax*4 + 0x515f84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5332868) /* 0x515f84 */ + cpu.eax * 4);
    // 00469edb  e991feffff             -jmp 0x469d71
    goto L_0x00469d71;
}

/* align: skip  */
void Application::sub_469ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469ee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469ee1  a138605100             -mov eax, dword ptr [0x516038]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5333048) /* 0x516038 */);
    // 00469ee6  e8a1070100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00469eeb  a1c0885100             -mov eax, dword ptr [0x5188c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343424) /* 0x5188c0 */);
    // 00469ef0  e897070100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00469ef5  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 00469efa  e88d070100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00469eff  a150885100             -mov eax, dword ptr [0x518850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */);
    // 00469f04  e883070100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00469f09  8b1554885100           -mov edx, dword ptr [0x518854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343316) /* 0x518854 */);
    // 00469f0f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00469f11  7502                   -jne 0x469f15
    if (!cpu.flags.zf)
    {
        goto L_0x00469f15;
    }
    // 00469f13  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469f14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00469f15:
    // 00469f15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00469f17  e870070100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00469f1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00469f1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_469f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469f20  c70554b7510001000000   -mov dword ptr [0x51b754], 1
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = 1 /*0x1*/;
    // 00469f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_469f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00469f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00469f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00469f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00469f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00469f34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469f35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00469f36  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 00469f3c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00469f3e  e81d0a0000             -call 0x46a960
    cpu.esp -= 4;
    sub_46a960(app, cpu);
    if (cpu.terminate) return;
    // 00469f43  833d34f34d0000         +cmp dword ptr [0x4df334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108532) /* 0x4df334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469f4a  0f8479020000           -je 0x46a1c9
    if (cpu.flags.zf)
    {
        goto L_0x0046a1c9;
    }
    // 00469f50  833d34f54d0002         +cmp dword ptr [0x4df534], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469f57  0f8ce7010000           -jl 0x46a144
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a144;
    }
    // 00469f5d  b8b8db4b00             -mov eax, 0x4bdbb8
    cpu.eax = 4971448 /*0x4bdbb8*/;
L_0x00469f62:
    // 00469f62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469f63  68c0db4b00             -push 0x4bdbc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971456 /*0x4bdbc0*/;
    cpu.esp -= 4;
    // 00469f68  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00469f6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469f6d  e86f200100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00469f72  a1b48f4c00             -mov eax, dword ptr [0x4c8fb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 00469f77  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00469f7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00469f7c  0f85cc010000           -jne 0x46a14e
    if (!cpu.flags.zf)
    {
        goto L_0x0046a14e;
    }
L_0x00469f82:
    // 00469f82  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00469f84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00469f86:
    // 00469f86  a150885100             -mov eax, dword ptr [0x518850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */);
    // 00469f8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00469f8d  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00469f90  e8b7400200             -call 0x48e04c
    cpu.esp -= 4;
    sub_48e04c(app, cpu);
    if (cpu.terminate) return;
    // 00469f95  41                     -inc ecx
    (cpu.ecx)++;
    // 00469f96  8983805f5100           -mov dword ptr [ebx + 0x515f80], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5332864) /* 0x515f80 */) = cpu.eax;
    // 00469f9c  83f92d                 +cmp ecx, 0x2d
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00469f9f  7ce5                   -jl 0x469f86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469f86;
    }
    // 00469fa1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00469fa3  893d54885100           -mov dword ptr [0x518854], edi
    app->getMemory<x86::reg32>(x86::reg32(5343316) /* 0x518854 */) = cpu.edi;
    // 00469fa9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00469fac:
    // 00469fac  be804c5100             -mov esi, 0x514c80
    cpu.esi = 5328000 /*0x514c80*/;
    // 00469fb1  bf05000000             -mov edi, 5
    cpu.edi = 5 /*0x5*/;
    // 00469fb6  83c63c                 -add esi, 0x3c
    (cpu.esi) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00469fb9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00469fbb:
    // 00469fbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00469fbc  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00469fc3  684cdc4b00             -push 0x4bdc4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971596 /*0x4bdc4c*/;
    cpu.esp -= 4;
    // 00469fc8  8d942404010000         -lea edx, [esp + 0x104]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00469fcf  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00469fd1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00469fd2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00469fd4  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00469fd7  e805200100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00469fdc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00469fdf  a1c0885100             -mov eax, dword ptr [0x5188c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343424) /* 0x5188c0 */);
    // 00469fe4  47                     -inc edi
    (cpu.edi)++;
    // 00469fe5  e876b20000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00469fea  83ff08                 +cmp edi, 8
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
    // 00469fed  7ccc                   -jl 0x469fbb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00469fbb;
    }
    // 00469fef  bd70485100             -mov ebp, 0x514870
    cpu.ebp = 5326960 /*0x514870*/;
    // 00469ff4  bf70485100             -mov edi, 0x514870
    cpu.edi = 5326960 /*0x514870*/;
    // 00469ff9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00469ffb  81c5c0000000           -add ebp, 0xc0
    (cpu.ebp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
L_0x0046a001:
    // 0046a001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a002  6854dc4b00             -push 0x4bdc54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971604 /*0x4bdc54*/;
    cpu.esp -= 4;
    // 0046a007  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a00e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a00f  8d942408010000         -lea edx, [esp + 0x108]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a016  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a018  e8c41f0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a01d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a020  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a022  a138605100             -mov eax, dword ptr [0x516038]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5333048) /* 0x516038 */);
    // 0046a027  e834b20000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a02c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a02d  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a030  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a037  685cdc4b00             -push 0x4bdc5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971612 /*0x4bdc5c*/;
    cpu.esp -= 4;
    // 0046a03c  8d942404010000         -lea edx, [esp + 0x104]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a043  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a045  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a046  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a048  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a04b  e8911f0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a050  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a053  a138605100             -mov eax, dword ptr [0x516038]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5333048) /* 0x516038 */);
    // 0046a058  46                     -inc esi
    (cpu.esi)++;
    // 0046a059  e802b20000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a05e  83fe10                 +cmp esi, 0x10
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
    // 0046a061  7c9e                   -jl 0x46a001
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a001;
    }
    // 0046a063  bf804c5100             -mov edi, 0x514c80
    cpu.edi = 5328000 /*0x514c80*/;
    // 0046a068  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a06a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0046a06c:
    // 0046a06c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a06d  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a074  684cdc4b00             -push 0x4bdc4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971596 /*0x4bdc4c*/;
    cpu.esp -= 4;
    // 0046a079  8d942404010000         -lea edx, [esp + 0x104]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a080  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a082  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a083  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046a085  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a088  e8541f0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a08d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a090  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a095  46                     -inc esi
    (cpu.esi)++;
    // 0046a096  e8c5b10000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a09b  83fe05                 +cmp esi, 5
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
    // 0046a09e  7ccc                   -jl 0x46a06c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a06c;
    }
    // 0046a0a0  bea0435100             -mov esi, 0x5143a0
    cpu.esi = 5325728 /*0x5143a0*/;
    // 0046a0a5  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046a0a7  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 0046a0ac  892d805f5100           -mov dword ptr [0x515f80], ebp
    app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */) = cpu.ebp;
L_0x0046a0b2:
    // 0046a0b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a0b3  6864dc4b00             -push 0x4bdc64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971620 /*0x4bdc64*/;
    cpu.esp -= 4;
    // 0046a0b8  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a0bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a0c0  e81c1f0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a0c5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a0c8  8d9424fc000000         -lea edx, [esp + 0xfc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a0cf  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a0d4  e87fe80000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046a0d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046a0db  0f84df030000           -je 0x46a4c0
    if (cpu.flags.zf)
    {
        goto L_0x0046a4c0;
    }
    // 0046a0e1  b8d83e5100             -mov eax, 0x513ed8
    cpu.eax = 5324504 /*0x513ed8*/;
    // 0046a0e6  8d9424fc000000         -lea edx, [esp + 0xfc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a0ed  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046a0ef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a0f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046a0f3  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0046a0f5  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a0fa  e861b10000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a0ff  8b85d83e5100           -mov eax, dword ptr [ebp + 0x513ed8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5324504) /* 0x513ed8 */);
    // 0046a105  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046a108  8b15805f5100           -mov edx, dword ptr [0x515f80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */);
    // 0046a10e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046a111  39d0                   +cmp eax, edx
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
    // 0046a113  7e05                   -jle 0x46a11a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a11a;
    }
    // 0046a115  a3805f5100             -mov dword ptr [0x515f80], eax
    app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */) = cpu.eax;
L_0x0046a11a:
    // 0046a11a  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0046a11d:
    // 0046a11d  47                     -inc edi
    (cpu.edi)++;
    // 0046a11e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a121  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a127  0f8e82030000           -jle 0x46a4af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a4af;
    }
L_0x0046a12d:
    // 0046a12d  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a133  0f8f8e030000           -jg 0x46a4c7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046a4c7;
    }
    // 0046a139  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0046a13f  83c604                 +add esi, 4
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
    // 0046a142  ebe9                   -jmp 0x46a12d
    goto L_0x0046a12d;
L_0x0046a144:
    // 0046a144  b8bcdb4b00             -mov eax, 0x4bdbbc
    cpu.eax = 4971452 /*0x4bdbbc*/;
    // 0046a149  e914feffff             -jmp 0x469f62
    goto L_0x00469f62;
L_0x0046a14e:
    // 0046a14e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046a150  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046a157  8d8c2408010000         -lea ecx, [esp + 0x108]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a15e  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a162  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a163  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a165  a1b48f4c00             -mov eax, dword ptr [0x4c8fb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a16a  e83d3b0200             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0046a16f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046a171  0f840bfeffff           -je 0x469f82
    if (cpu.flags.zf)
    {
        goto L_0x00469f82;
    }
    // 0046a177  baccdb4b00             -mov edx, 0x4bdbcc
    cpu.edx = 4971468 /*0x4bdbcc*/;
    // 0046a17c  b9ea020000             -mov ecx, 0x2ea
    cpu.ecx = 746 /*0x2ea*/;
    // 0046a181  b8e4db4b00             -mov eax, 0x4bdbe4
    cpu.eax = 4971492 /*0x4bdbe4*/;
    // 0046a186  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a188  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046a18e  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a195  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046a19b  e888000100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046a1a0  8b9c2404010000         -mov ebx, dword ptr [esp + 0x104]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a1a7  8b0db48f4c00           -mov ecx, dword ptr [0x4c8fb4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a1ad  a350885100             -mov dword ptr [0x518850], eax
    app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */) = cpu.eax;
    // 0046a1b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a1b4  01d9                   +add ecx, ebx
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
    // 0046a1b6  8b9c2408010000         -mov ebx, dword ptr [esp + 0x108]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a1bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046a1bf  e83c740100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046a1c4  e9b9fdffff             -jmp 0x469f82
    goto L_0x00469f82;
L_0x0046a1c9:
    // 0046a1c9  83feff                 +cmp esi, -1
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
    // 0046a1cc  0f8e0b020000           -jle 0x46a3dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a3dd;
    }
    // 0046a1d2  833d34f54d0002         +cmp dword ptr [0x4df534], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a1d9  0f8c86000000           -jl 0x46a265
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a265;
    }
    // 0046a1df  b8b8db4b00             -mov eax, 0x4bdbb8
    cpu.eax = 4971448 /*0x4bdbb8*/;
L_0x0046a1e4:
    // 0046a1e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a1e5  6808dc4b00             -push 0x4bdc08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971528 /*0x4bdc08*/;
    cpu.esp -= 4;
    // 0046a1ea  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a1ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a1ef  e8ed1d0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a1f4  8b15b48f4c00           -mov edx, dword ptr [0x4c8fb4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a1fa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a1fd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046a1ff  756e                   -jne 0x46a26f
    if (!cpu.flags.zf)
    {
        goto L_0x0046a26f;
    }
L_0x0046a201:
    // 0046a201  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a203  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046a205:
    // 0046a205  a150885100             -mov eax, dword ptr [0x518850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */);
    // 0046a20a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046a20c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a20f  e8383e0200             -call 0x48e04c
    cpu.esp -= 4;
    sub_48e04c(app, cpu);
    if (cpu.terminate) return;
    // 0046a214  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a215  8983805f5100           -mov dword ptr [ebx + 0x515f80], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5332864) /* 0x515f80 */) = cpu.eax;
    // 0046a21b  83f91e                 +cmp ecx, 0x1e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a21e  7ce5                   -jl 0x46a205
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a205;
    }
    // 0046a220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a221  6820dc4b00             -push 0x4bdc20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971552 /*0x4bdc20*/;
    cpu.esp -= 4;
    // 0046a226  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a22a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a22b  e8b11d0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a230  8b3db48f4c00           -mov edi, dword ptr [0x4c8fb4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a236  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a239  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046a23b  0f85a6000000           -jne 0x46a2e7
    if (!cpu.flags.zf)
    {
        goto L_0x0046a2e7;
    }
L_0x0046a241:
    // 0046a241  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a243  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046a245:
    // 0046a245  a154885100             -mov eax, dword ptr [0x518854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343316) /* 0x518854 */);
    // 0046a24a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046a24c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a24f  e8f83d0200             -call 0x48e04c
    cpu.esp -= 4;
    sub_48e04c(app, cpu);
    if (cpu.terminate) return;
    // 0046a254  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a255  898654885100           -mov dword ptr [esi + 0x518854], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5343316) /* 0x518854 */) = cpu.eax;
    // 0046a25b  83f919                 +cmp ecx, 0x19
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a25e  7ce5                   -jl 0x46a245
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a245;
    }
    // 0046a260  e947fdffff             -jmp 0x469fac
    goto L_0x00469fac;
L_0x0046a265:
    // 0046a265  b8bcdb4b00             -mov eax, 0x4bdbbc
    cpu.eax = 4971452 /*0x4bdbbc*/;
    // 0046a26a  e975ffffff             -jmp 0x46a1e4
    goto L_0x0046a1e4;
L_0x0046a26f:
    // 0046a26f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046a271  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046a278  8d8c2408010000         -lea ecx, [esp + 0x108]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a27f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a281  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a282  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046a284  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a288  e81f3a0200             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0046a28d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046a28f  0f846cffffff           -je 0x46a201
    if (cpu.flags.zf)
    {
        goto L_0x0046a201;
    }
    // 0046a295  b9ccdb4b00             -mov ecx, 0x4bdbcc
    cpu.ecx = 4971468 /*0x4bdbcc*/;
    // 0046a29a  bb0d030000             -mov ebx, 0x30d
    cpu.ebx = 781 /*0x30d*/;
    // 0046a29f  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a2a6  b814dc4b00             -mov eax, 0x4bdc14
    cpu.eax = 4971540 /*0x4bdc14*/;
    // 0046a2ab  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 0046a2b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a2b3  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 0046a2b9  e86aff0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046a2be  8bbc2404010000         -mov edi, dword ptr [esp + 0x104]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a2c5  8b9c2408010000         -mov ebx, dword ptr [esp + 0x108]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a2cc  8b0db48f4c00           -mov ecx, dword ptr [0x4c8fb4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a2d2  a350885100             -mov dword ptr [0x518850], eax
    app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */) = cpu.eax;
    // 0046a2d7  01f9                   +add ecx, edi
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
    // 0046a2d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a2db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046a2dd  e81e730100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046a2e2  e91affffff             -jmp 0x46a201
    goto L_0x0046a201;
L_0x0046a2e7:
    // 0046a2e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046a2e9  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046a2f0  8d8c2408010000         -lea ecx, [esp + 0x108]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a2f7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a2fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a2fc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a2fe  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046a300  e8a7390200             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0046a305  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046a307  7452                   -je 0x46a35b
    if (cpu.flags.zf)
    {
        goto L_0x0046a35b;
    }
    // 0046a309  b9ccdb4b00             -mov ecx, 0x4bdbcc
    cpu.ecx = 4971468 /*0x4bdbcc*/;
    // 0046a30e  bb28030000             -mov ebx, 0x328
    cpu.ebx = 808 /*0x328*/;
    // 0046a313  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a31a  b82cdc4b00             -mov eax, 0x4bdc2c
    cpu.eax = 4971564 /*0x4bdc2c*/;
    // 0046a31f  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 0046a325  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a327  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 0046a32d  e8f6fe0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046a332  8bb42404010000         -mov esi, dword ptr [esp + 0x104]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a339  8b9c2408010000         -mov ebx, dword ptr [esp + 0x108]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a340  8b0db48f4c00           -mov ecx, dword ptr [0x4c8fb4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a346  a354885100             -mov dword ptr [0x518854], eax
    app->getMemory<x86::reg32>(x86::reg32(5343316) /* 0x518854 */) = cpu.eax;
    // 0046a34b  01f1                   +add ecx, esi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a34d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a34f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046a351  e8aa720100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046a356  e9e6feffff             -jmp 0x46a241
    goto L_0x0046a241;
L_0x0046a35b:
    // 0046a35b  6834dc4b00             -push 0x4bdc34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971572 /*0x4bdc34*/;
    cpu.esp -= 4;
    // 0046a360  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a364  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a365  e8771c0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a36a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046a36d  8d8c2404010000         -lea ecx, [esp + 0x104]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a374  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046a376  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046a378  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046a37f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a381  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a382  a1b48f4c00             -mov eax, dword ptr [0x4c8fb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a387  bdccdb4b00             -mov ebp, 0x4bdbcc
    cpu.ebp = 4971468 /*0x4bdbcc*/;
    // 0046a38c  e81b390200             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0046a391  b82f030000             -mov eax, 0x32f
    cpu.eax = 815 /*0x32f*/;
    // 0046a396  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a39d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a39f  a37ca64c00             -mov dword ptr [0x4ca67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.eax;
    // 0046a3a4  b82cdc4b00             -mov eax, 0x4bdc2c
    cpu.eax = 4971564 /*0x4bdc2c*/;
    // 0046a3a9  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 0046a3af  e874fe0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046a3b4  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a3bb  8b9c2408010000         -mov ebx, dword ptr [esp + 0x108]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a3c2  8b0db48f4c00           -mov ecx, dword ptr [0x4c8fb4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a3c8  a354885100             -mov dword ptr [0x518854], eax
    app->getMemory<x86::reg32>(x86::reg32(5343316) /* 0x518854 */) = cpu.eax;
    // 0046a3cd  01d1                   +add ecx, edx
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
    // 0046a3cf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a3d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046a3d3  e828720100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046a3d8  e964feffff             -jmp 0x46a241
    goto L_0x0046a241;
L_0x0046a3dd:
    // 0046a3dd  833d34f54d0002         +cmp dword ptr [0x4df534], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a3e4  7c4e                   -jl 0x46a434
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a434;
    }
    // 0046a3e6  b8b8db4b00             -mov eax, 0x4bdbb8
    cpu.eax = 4971448 /*0x4bdbb8*/;
L_0x0046a3eb:
    // 0046a3eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a3ec  6808dc4b00             -push 0x4bdc08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971528 /*0x4bdc08*/;
    cpu.esp -= 4;
    // 0046a3f1  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a3f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a3f6  e8e61b0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a3fb  8b1db48f4c00           -mov ebx, dword ptr [0x4c8fb4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a401  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a404  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046a406  7533                   -jne 0x46a43b
    if (!cpu.flags.zf)
    {
        goto L_0x0046a43b;
    }
L_0x0046a408:
    // 0046a408  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a40a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046a40c:
    // 0046a40c  a150885100             -mov eax, dword ptr [0x518850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */);
    // 0046a411  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046a413  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a416  e8313c0200             -call 0x48e04c
    cpu.esp -= 4;
    sub_48e04c(app, cpu);
    if (cpu.terminate) return;
    // 0046a41b  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a41c  8983805f5100           -mov dword ptr [ebx + 0x515f80], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5332864) /* 0x515f80 */) = cpu.eax;
    // 0046a422  83f91e                 +cmp ecx, 0x1e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a425  7ce5                   -jl 0x46a40c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a40c;
    }
    // 0046a427  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0046a429  893554885100           -mov dword ptr [0x518854], esi
    app->getMemory<x86::reg32>(x86::reg32(5343316) /* 0x518854 */) = cpu.esi;
    // 0046a42f  e978fbffff             -jmp 0x469fac
    goto L_0x00469fac;
L_0x0046a434:
    // 0046a434  b8bcdb4b00             -mov eax, 0x4bdbbc
    cpu.eax = 4971452 /*0x4bdbbc*/;
    // 0046a439  ebb0                   -jmp 0x46a3eb
    goto L_0x0046a3eb;
L_0x0046a43b:
    // 0046a43b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046a43d  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046a444  8d8c2408010000         -lea ecx, [esp + 0x108]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a44b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046a44f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a450  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046a452  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a454  e853380200             -call 0x48dcac
    cpu.esp -= 4;
    sub_48dcac(app, cpu);
    if (cpu.terminate) return;
    // 0046a459  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046a45b  74ab                   -je 0x46a408
    if (cpu.flags.zf)
    {
        goto L_0x0046a408;
    }
    // 0046a45d  beccdb4b00             -mov esi, 0x4bdbcc
    cpu.esi = 4971468 /*0x4bdbcc*/;
    // 0046a462  bf5a030000             -mov edi, 0x35a
    cpu.edi = 858 /*0x35a*/;
    // 0046a467  8b942408010000         -mov edx, dword ptr [esp + 0x108]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a46e  b840dc4b00             -mov eax, 0x4bdc40
    cpu.eax = 4971584 /*0x4bdc40*/;
    // 0046a473  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a475  893578a64c00           -mov dword ptr [0x4ca678], esi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.esi;
    // 0046a47b  893d7ca64c00           -mov dword ptr [0x4ca67c], edi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edi;
    // 0046a481  e8a2fd0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046a486  8bac2404010000         -mov ebp, dword ptr [esp + 0x104]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a48d  8b9c2408010000         -mov ebx, dword ptr [esp + 0x108]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a494  8b0db48f4c00           -mov ecx, dword ptr [0x4c8fb4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a49a  a350885100             -mov dword ptr [0x518850], eax
    app->getMemory<x86::reg32>(x86::reg32(5343312) /* 0x518850 */) = cpu.eax;
    // 0046a49f  01e9                   +add ecx, ebp
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046a4a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a4a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046a4a5  e856710100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046a4aa  e959ffffff             -jmp 0x46a408
    goto L_0x0046a408;
L_0x0046a4af:
    // 0046a4af  81fdb0040000           +cmp ebp, 0x4b0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1200 /*0x4b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a4b5  0f8cf7fbffff           -jl 0x46a0b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a0b2;
    }
    // 0046a4bb  e96dfcffff             -jmp 0x46a12d
    goto L_0x0046a12d;
L_0x0046a4c0:
    // 0046a4c0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0046a4c2  e956fcffff             -jmp 0x46a11d
    goto L_0x0046a11d;
L_0x0046a4c7:
    // 0046a4c7  8b0d805f5100           -mov ecx, dword ptr [0x515f80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */);
    // 0046a4cd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046a4cf  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046a4d1  83e902                 -sub ecx, 2
    (cpu.ecx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046a4d4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a4d6  890d805f5100           -mov dword ptr [0x515f80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5332864) /* 0x515f80 */) = cpu.ecx;
L_0x0046a4dc:
    // 0046a4dc  8d8424fc000000         -lea eax, [esp + 0xfc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a4e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a4e4  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a4eb  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a4ed  686cdc4b00             -push 0x4bdc6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971628 /*0x4bdc6c*/;
    cpu.esp -= 4;
    // 0046a4f2  46                     -inc esi
    (cpu.esi)++;
    // 0046a4f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a4f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a4f6  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a4f9  81c1f0495100           -add ecx, 0x5149f0
    (cpu.ecx) += x86::reg32(x86::sreg32(5327344 /*0x5149f0*/));
    // 0046a4ff  e8dd1a0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a504  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a507  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a50c  47                     -inc edi
    (cpu.edi)++;
    // 0046a50d  e84ead0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a512  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a515  7cc5                   -jl 0x46a4dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a4dc;
    }
    // 0046a517  b9f0495100             -mov ecx, 0x5149f0
    cpu.ecx = 5327344 /*0x5149f0*/;
    // 0046a51c  ba74dc4b00             -mov edx, 0x4bdc74
    cpu.edx = 4971636 /*0x4bdc74*/;
    // 0046a521  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046a528  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a52a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046a52c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a52e  46                     -inc esi
    (cpu.esi)++;
    // 0046a52f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046a532  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0046a539  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046a53b  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a540  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a542  e819ad0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a547  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
L_0x0046a54a:
    // 0046a54a  8d8424fc000000         -lea eax, [esp + 0xfc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a551  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a552  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a559  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a55b  687cdc4b00             -push 0x4bdc7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971644 /*0x4bdc7c*/;
    cpu.esp -= 4;
    // 0046a560  46                     -inc esi
    (cpu.esi)++;
    // 0046a561  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a563  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a564  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a567  81c1f0495100           -add ecx, 0x5149f0
    (cpu.ecx) += x86::reg32(x86::sreg32(5327344 /*0x5149f0*/));
    // 0046a56d  e86f1a0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a572  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a575  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a57a  47                     -inc edi
    (cpu.edi)++;
    // 0046a57b  e8e0ac0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a580  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a583  7cc5                   -jl 0x46a54a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a54a;
    }
    // 0046a585  b9f0495100             -mov ecx, 0x5149f0
    cpu.ecx = 5327344 /*0x5149f0*/;
    // 0046a58a  ba84dc4b00             -mov edx, 0x4bdc84
    cpu.edx = 4971652 /*0x4bdc84*/;
    // 0046a58f  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046a596  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a598  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046a59a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a59c  46                     -inc esi
    (cpu.esi)++;
    // 0046a59d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046a5a0  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0046a5a7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046a5a9  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a5ae  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a5b0  e8abac0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a5b5  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
L_0x0046a5b8:
    // 0046a5b8  8d8424fc000000         -lea eax, [esp + 0xfc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a5bf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a5c0  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a5c7  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a5c9  688cdc4b00             -push 0x4bdc8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971660 /*0x4bdc8c*/;
    cpu.esp -= 4;
    // 0046a5ce  46                     -inc esi
    (cpu.esi)++;
    // 0046a5cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a5d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a5d2  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a5d5  81c1f0495100           -add ecx, 0x5149f0
    (cpu.ecx) += x86::reg32(x86::sreg32(5327344 /*0x5149f0*/));
    // 0046a5db  e8011a0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a5e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a5e3  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a5e8  47                     -inc edi
    (cpu.edi)++;
    // 0046a5e9  e872ac0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a5ee  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a5f1  7cc5                   -jl 0x46a5b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a5b8;
    }
    // 0046a5f3  b9f0495100             -mov ecx, 0x5149f0
    cpu.ecx = 5327344 /*0x5149f0*/;
    // 0046a5f8  ba94dc4b00             -mov edx, 0x4bdc94
    cpu.edx = 4971668 /*0x4bdc94*/;
    // 0046a5fd  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046a604  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a606  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046a608  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a60a  46                     -inc esi
    (cpu.esi)++;
    // 0046a60b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046a60e  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0046a615  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046a617  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a61c  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a61e  e83dac0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a623  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
L_0x0046a626:
    // 0046a626  8d8424fc000000         -lea eax, [esp + 0xfc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a62d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a62e  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a635  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a637  689cdc4b00             -push 0x4bdc9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971676 /*0x4bdc9c*/;
    cpu.esp -= 4;
    // 0046a63c  46                     -inc esi
    (cpu.esi)++;
    // 0046a63d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a63f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a640  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a643  81c1f0495100           -add ecx, 0x5149f0
    (cpu.ecx) += x86::reg32(x86::sreg32(5327344 /*0x5149f0*/));
    // 0046a649  e893190100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a64e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a651  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a656  47                     -inc edi
    (cpu.edi)++;
    // 0046a657  e804ac0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a65c  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046a65f  7cc5                   -jl 0x46a626
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a626;
    }
    // 0046a661  b9f0495100             -mov ecx, 0x5149f0
    cpu.ecx = 5327344 /*0x5149f0*/;
    // 0046a666  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046a66d  baa4dc4b00             -mov edx, 0x4bdca4
    cpu.edx = 4971684 /*0x4bdca4*/;
    // 0046a672  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a674  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046a679  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046a67c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a67e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046a680  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a685  46                     -inc esi
    (cpu.esi)++;
    // 0046a686  e8d5ab0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a68b  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046a692  b9f0495100             -mov ecx, 0x5149f0
    cpu.ecx = 5327344 /*0x5149f0*/;
    // 0046a697  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a699  baacdc4b00             -mov edx, 0x4bdcac
    cpu.edx = 4971692 /*0x4bdcac*/;
    // 0046a69e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046a6a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a6a3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046a6a5  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a6aa  46                     -inc esi
    (cpu.esi)++;
    // 0046a6ab  e8b0ab0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a6b0  b9f0495100             -mov ecx, 0x5149f0
    cpu.ecx = 5327344 /*0x5149f0*/;
    // 0046a6b5  bab4dc4b00             -mov edx, 0x4bdcb4
    cpu.edx = 4971700 /*0x4bdcb4*/;
    // 0046a6ba  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046a6c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a6c3  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a6c5  46                     -inc esi
    (cpu.esi)++;
    // 0046a6c6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046a6c9  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0046a6d0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046a6d2  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a6d7  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046a6d9  e882ab0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a6de  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
L_0x0046a6e1:
    // 0046a6e1  8d8424fc000000         -lea eax, [esp + 0xfc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(252) /* 0xfc */);
    // 0046a6e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046a6e9  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046a6f0  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a6f2  68bcdc4b00             -push 0x4bdcbc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971708 /*0x4bdcbc*/;
    cpu.esp -= 4;
    // 0046a6f7  46                     -inc esi
    (cpu.esi)++;
    // 0046a6f8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a6fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a6fb  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a6fe  81c1f0495100           -add ecx, 0x5149f0
    (cpu.ecx) += x86::reg32(x86::sreg32(5327344 /*0x5149f0*/));
    // 0046a704  e8d8180100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a709  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a70c  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a711  47                     -inc edi
    (cpu.edi)++;
    // 0046a712  e849ab0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a717  83ff06                 +cmp edi, 6
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
    // 0046a71a  7ec5                   -jle 0x46a6e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046a6e1;
    }
    // 0046a71c  bee83d5100             -mov esi, 0x513de8
    cpu.esi = 5324264 /*0x513de8*/;
    // 0046a721  bf16904c00             -mov edi, 0x4c9016
    cpu.edi = 5017622 /*0x4c9016*/;
    // 0046a726  8daef0000000           -lea ebp, [esi + 0xf0]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(240) /* 0xf0 */);
L_0x0046a72c:
    // 0046a72c  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a731  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046a733  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046a735  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a737  e824ab0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a73c  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a73f  83c705                 -add edi, 5
    (cpu.edi) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0046a742  39ee                   +cmp esi, ebp
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
    // 0046a744  75e6                   -jne 0x46a72c
    if (!cpu.flags.zf)
    {
        goto L_0x0046a72c;
    }
    // 0046a746  bec45d5100             -mov esi, 0x515dc4
    cpu.esi = 5332420 /*0x515dc4*/;
    // 0046a74b  bfbc8f4c00             -mov edi, 0x4c8fbc
    cpu.edi = 5017532 /*0x4c8fbc*/;
    // 0046a750  8d6e78                 -lea ebp, [esi + 0x78]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(120) /* 0x78 */);
L_0x0046a753:
    // 0046a753  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a758  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046a75a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046a75c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a75e  e8fdaa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a763  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a766  83c705                 -add edi, 5
    (cpu.edi) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0046a769  39ee                   +cmp esi, ebp
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
    // 0046a76b  75e6                   -jne 0x46a753
    if (!cpu.flags.zf)
    {
        goto L_0x0046a753;
    }
    // 0046a76d  bfc45d5100             -mov edi, 0x515dc4
    cpu.edi = 5332420 /*0x515dc4*/;
    // 0046a772  beee8f4c00             -mov esi, 0x4c8fee
    cpu.esi = 5017582 /*0x4c8fee*/;
    // 0046a777  83c778                 -add edi, 0x78
    (cpu.edi) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0046a77a  8d6e28                 -lea ebp, [esi + 0x28]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x0046a77d:
    // 0046a77d  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a782  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a784  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046a786  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a788  e8d3aa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a78d  83c605                 -add esi, 5
    (cpu.esi) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0046a790  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a793  39ee                   +cmp esi, ebp
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
    // 0046a795  75e6                   -jne 0x46a77d
    if (!cpu.flags.zf)
    {
        goto L_0x0046a77d;
    }
    // 0046a797  bfc45d5100             -mov edi, 0x515dc4
    cpu.edi = 5332420 /*0x515dc4*/;
    // 0046a79c  bdc45d5100             -mov ebp, 0x515dc4
    cpu.ebp = 5332420 /*0x515dc4*/;
    // 0046a7a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046a7a3  81c744010000           -add edi, 0x144
    (cpu.edi) += x86::reg32(x86::sreg32(324 /*0x144*/));
    // 0046a7a9  81c5d8000000           -add ebp, 0xd8
    (cpu.ebp) += x86::reg32(x86::sreg32(216 /*0xd8*/));
L_0x0046a7af:
    // 0046a7af  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046a7b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a7b3  68c4dc4b00             -push 0x4bdcc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971716 /*0x4bdcc4*/;
    cpu.esp -= 4;
    // 0046a7b8  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a7bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a7c0  8d942408010000         -lea edx, [esp + 0x108]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046a7c7  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046a7c9  e813180100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a7ce  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a7d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a7d3  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a7d8  e883aa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a7dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a7de  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a7e1  68ccdc4b00             -push 0x4bdccc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971724 /*0x4bdccc*/;
    cpu.esp -= 4;
    // 0046a7e6  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a7ed  8d942404010000         -lea edx, [esp + 0x104]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0046a7f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a7f5  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046a7f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a7f9  e8e3170100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a7fe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a801  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a806  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a809  e852aa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a80e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046a810  83fe09                 +cmp esi, 9
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
    // 0046a813  7c9a                   -jl 0x46a7af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a7af;
    }
    // 0046a815  b9745f5100             -mov ecx, 0x515f74
    cpu.ecx = 5332852 /*0x515f74*/;
    // 0046a81a  bad4dc4b00             -mov edx, 0x4bdcd4
    cpu.edx = 4971732 /*0x4bdcd4*/;
    // 0046a81f  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046a824  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a826  e835aa0000             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 0046a82b  81c40c010000           -add esp, 0x10c
    (cpu.esp) += x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 0046a831  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a832  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a833  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a834  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a835  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a836  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a837  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46a840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a840  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a841  8b15b48f4c00           -mov edx, dword ptr [0x4c8fb4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */);
    // 0046a847  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046a849  7502                   -jne 0x46a84d
    if (!cpu.flags.zf)
    {
        goto L_0x0046a84d;
    }
    // 0046a84b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a84c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046a84d:
    // 0046a84d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a84e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046a850  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a852  e835fe0000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046a857  890db48f4c00           -mov dword ptr [0x4c8fb4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */) = cpu.ecx;
    // 0046a85d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a85e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a85f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46a860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a860  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a861  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0046a867  8b15bc074e00           -mov edx, dword ptr [0x4e07bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113788) /* 0x4e07bc */);
    // 0046a86d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a86e  68a8db4b00             -push 0x4bdba8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971432 /*0x4bdba8*/;
    cpu.esp -= 4;
    // 0046a873  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a877  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a878  e864170100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a87d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a880  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a882  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046a884  e8e71f0100             -call 0x47c870
    cpu.esp -= 4;
    sub_47c870(app, cpu);
    if (cpu.terminate) return;
    // 0046a889  a3b48f4c00             -mov dword ptr [0x4c8fb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5017524) /* 0x4c8fb4 */) = cpu.eax;
    // 0046a88e  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0046a894  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a895  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46a8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a8a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046a8a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a8a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a8a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a8a4  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046a8aa  8b1554f54d00           -mov edx, dword ptr [0x4df554]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109076) /* 0x4df554 */);
    // 0046a8b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a8b1  8b0dbc074e00           -mov ecx, dword ptr [0x4e07bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113788) /* 0x4e07bc */);
    // 0046a8b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a8b8  687cdb4b00             -push 0x4bdb7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971388 /*0x4bdb7c*/;
    cpu.esp -= 4;
    // 0046a8bd  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046a8c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a8c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a8c4  e818170100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a8c9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046a8cc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046a8ce  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0046a8d3  e8881f0100             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 0046a8d8  a3c0885100             -mov dword ptr [0x5188c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5343424) /* 0x5188c0 */) = cpu.eax;
    // 0046a8dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a8df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046a8e1  e8daa50000             -call 0x474ec0
    cpu.esp -= 4;
    sub_474ec0(app, cpu);
    if (cpu.terminate) return;
    // 0046a8e6  8b1dbc074e00           -mov ebx, dword ptr [0x4e07bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113788) /* 0x4e07bc */);
    // 0046a8ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046a8ed  688cdb4b00             -push 0x4bdb8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971404 /*0x4bdb8c*/;
    cpu.esp -= 4;
    // 0046a8f2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a8f6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a8f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a8f9  e8e3160100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a8fe  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a901  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046a903  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046a905  e8561f0100             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 0046a90a  a338605100             -mov dword ptr [0x516038], eax
    app->getMemory<x86::reg32>(x86::reg32(5333048) /* 0x516038 */) = cpu.eax;
    // 0046a90f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a911  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046a916  e8a5a50000             -call 0x474ec0
    cpu.esp -= 4;
    sub_474ec0(app, cpu);
    if (cpu.terminate) return;
    // 0046a91b  8b35bc074e00           -mov esi, dword ptr [0x4e07bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5113788) /* 0x4e07bc */);
    // 0046a921  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a922  689cdb4b00             -push 0x4bdb9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971420 /*0x4bdb9c*/;
    cpu.esp -= 4;
    // 0046a927  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046a92b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046a92c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a92e  e8ae160100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046a933  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046a936  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046a938  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0046a93d  e81e1f0100             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 0046a942  a3ccf34d00             -mov dword ptr [0x4df3cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */) = cpu.eax;
    // 0046a947  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046a949  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046a94b  e870a50000             -call 0x474ec0
    cpu.esp -= 4;
    sub_474ec0(app, cpu);
    if (cpu.terminate) return;
    // 0046a950  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046a956  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a957  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a958  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a959  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a95a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46a960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a961  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a962  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a963  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046a964  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0046a969  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a96b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046a96d  8915c4885100           -mov dword ptr [0x5188c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5343428) /* 0x5188c4 */) = cpu.edx;
    // 0046a973  8915c8885100           -mov dword ptr [0x5188c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5343432) /* 0x5188c8 */) = cpu.edx;
    // 0046a979  8915bc885100           -mov dword ptr [0x5188bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.edx;
    // 0046a97f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x0046a981:
    // 0046a981  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046a983  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046a985  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
L_0x0046a988:
    // 0046a988  40                     -inc eax
    (cpu.eax)++;
    // 0046a989  8898373c5100           -mov byte ptr [eax + 0x513c37], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5323831) /* 0x513c37 */) = cpu.bl;
    // 0046a98f  8898273c5100           -mov byte ptr [eax + 0x513c27], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5323815) /* 0x513c27 */) = cpu.bl;
    // 0046a995  39d0                   +cmp eax, edx
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
    // 0046a997  75ef                   -jne 0x46a988
    if (!cpu.flags.zf)
    {
        goto L_0x0046a988;
    }
    // 0046a999  41                     -inc ecx
    (cpu.ecx)++;
    // 0046a99a  83c620                 -add esi, 0x20
    (cpu.esi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046a99d  83f90e                 +cmp ecx, 0xe
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
    // 0046a9a0  7cdf                   -jl 0x46a981
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046a981;
    }
    // 0046a9a2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a9a4  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0046a9a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a9aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a9ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046a9ac:
    // 0046a9ac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046a9af  899090435100           -mov dword ptr [eax + 0x514390], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5325712) /* 0x514390 */) = cpu.edx;
    // 0046a9b5  899084435100           -mov dword ptr [eax + 0x514384], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5325700) /* 0x514384 */) = cpu.edx;
    // 0046a9bb  83f80c                 +cmp eax, 0xc
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
    // 0046a9be  75ec                   -jne 0x46a9ac
    if (!cpu.flags.zf)
    {
        goto L_0x0046a9ac;
    }
    // 0046a9c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046a9c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46a9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046a9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046a9d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046a9d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046a9d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046a9d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046a9d5  b820475100             -mov eax, 0x514720
    cpu.eax = 5326624 /*0x514720*/;
    // 0046a9da  b93e010000             -mov ecx, 0x13e
    cpu.ecx = 318 /*0x13e*/;
    // 0046a9df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046a9e1  be45000000             -mov esi, 0x45
    cpu.esi = 69 /*0x45*/;
    // 0046a9e6  e885010000             -call 0x46ab70
    cpu.esp -= 4;
    sub_46ab70(app, cpu);
    if (cpu.terminate) return;
    // 0046a9eb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046a9f0  b890475100             -mov eax, 0x514790
    cpu.eax = 5326736 /*0x514790*/;
    // 0046a9f5  bd35010000             -mov ebp, 0x135
    cpu.ebp = 309 /*0x135*/;
    // 0046a9fa  e871010000             -call 0x46ab70
    cpu.esp -= 4;
    sub_46ab70(app, cpu);
    if (cpu.terminate) return;
    // 0046a9ff  baf1000000             -mov edx, 0xf1
    cpu.edx = 241 /*0xf1*/;
    // 0046aa04  b800485100             -mov eax, 0x514800
    cpu.eax = 5326848 /*0x514800*/;
    // 0046aa09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046aa0b  e860010000             -call 0x46ab70
    cpu.esp -= 4;
    sub_46ab70(app, cpu);
    if (cpu.terminate) return;
    // 0046aa10  ba14020000             -mov edx, 0x214
    cpu.edx = 532 /*0x214*/;
    // 0046aa15  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046aa1a  890d4c475100           -mov dword ptr [0x51474c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326668) /* 0x51474c */) = cpu.ecx;
    // 0046aa20  891db8475100           -mov dword ptr [0x5147b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5326776) /* 0x5147b8 */) = cpu.ebx;
    // 0046aa26  8935bc475100           -mov dword ptr [0x5147bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5326780) /* 0x5147bc */) = cpu.esi;
    // 0046aa2c  891d28485100           -mov dword ptr [0x514828], ebx
    app->getMemory<x86::reg32>(x86::reg32(5326888) /* 0x514828 */) = cpu.ebx;
    // 0046aa32  891548475100           -mov dword ptr [0x514748], edx
    app->getMemory<x86::reg32>(x86::reg32(5326664) /* 0x514748 */) = cpu.edx;
    // 0046aa38  ba6cdb4b00             -mov edx, 0x4bdb6c
    cpu.edx = 4971372 /*0x4bdb6c*/;
    // 0046aa3d  892d2c485100           -mov dword ptr [0x51482c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5326892) /* 0x51482c */) = cpu.ebp;
    // 0046aa43  e81cdf0000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 0046aa48  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046aa4a  e8a5620200             -call 0x490cf4
    cpu.esp -= 4;
    sub_490cf4(app, cpu);
    if (cpu.terminate) return;
    // 0046aa4f  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046aa52  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046aa54  c1e114                 -shl ecx, 0x14
    cpu.ecx <<= 20 /*0x14*/ % 32;
    // 0046aa57  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046aa5a  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 0046aa5d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046aa60  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046aa62  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046aa65  891d80475100           -mov dword ptr [0x514780], ebx
    app->getMemory<x86::reg32>(x86::reg32(5326720) /* 0x514780 */) = cpu.ebx;
    // 0046aa6b  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046aa6e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046aa70  891d84475100           -mov dword ptr [0x514784], ebx
    app->getMemory<x86::reg32>(x86::reg32(5326724) /* 0x514784 */) = cpu.ebx;
    // 0046aa76  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046aa79  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046aa7c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046aa7e  a37c475100             -mov dword ptr [0x51477c], eax
    app->getMemory<x86::reg32>(x86::reg32(5326716) /* 0x51477c */) = cpu.eax;
    // 0046aa83  a180475100             -mov eax, dword ptr [0x514780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5326720) /* 0x514780 */);
    // 0046aa88  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046aa8a  a3f0475100             -mov dword ptr [0x5147f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5326832) /* 0x5147f0 */) = cpu.eax;
    // 0046aa8f  a184475100             -mov eax, dword ptr [0x514784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5326724) /* 0x514784 */);
    // 0046aa94  890d78475100           -mov dword ptr [0x514778], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326712) /* 0x514778 */) = cpu.ecx;
    // 0046aa9a  8d9010ffffff           -lea edx, [eax - 0xf0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-240) /* -0xf0 */);
    // 0046aaa0  890de8475100           -mov dword ptr [0x5147e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326824) /* 0x5147e8 */) = cpu.ecx;
    // 0046aaa6  8915f4475100           -mov dword ptr [0x5147f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5326836) /* 0x5147f4 */) = cpu.edx;
    // 0046aaac  a364485100             -mov dword ptr [0x514864], eax
    app->getMemory<x86::reg32>(x86::reg32(5326948) /* 0x514864 */) = cpu.eax;
    // 0046aab1  8b157c475100           -mov edx, dword ptr [0x51477c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5326716) /* 0x51477c */);
    // 0046aab7  a1e8475100             -mov eax, dword ptr [0x5147e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5326824) /* 0x5147e8 */);
    // 0046aabc  8d8a10ffffff           -lea ecx, [edx - 0xf0]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-240) /* -0xf0 */);
    // 0046aac2  a358485100             -mov dword ptr [0x514858], eax
    app->getMemory<x86::reg32>(x86::reg32(5326936) /* 0x514858 */) = cpu.eax;
    // 0046aac7  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046aacc  890dec475100           -mov dword ptr [0x5147ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326828) /* 0x5147ec */) = cpu.ecx;
    // 0046aad2  89155c485100           -mov dword ptr [0x51485c], edx
    app->getMemory<x86::reg32>(x86::reg32(5326940) /* 0x51485c */) = cpu.edx;
    // 0046aad8  8b0df0475100           -mov ecx, dword ptr [0x5147f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5326832) /* 0x5147f0 */);
    // 0046aade  ba74db4b00             -mov edx, 0x4bdb74
    cpu.edx = 4971380 /*0x4bdb74*/;
    // 0046aae3  890d60485100           -mov dword ptr [0x514860], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326944) /* 0x514860 */) = cpu.ecx;
    // 0046aae9  e876de0000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 0046aaee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046aaf0  e8ff610200             -call 0x490cf4
    cpu.esp -= 4;
    sub_490cf4(app, cpu);
    if (cpu.terminate) return;
    // 0046aaf5  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046aaf8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046aafa  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 0046aafd  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ab00  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046ab03  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046ab06  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0046ab09  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046ab0c  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ab0e  bbd4010000             -mov ebx, 0x1d4
    cpu.ebx = 468 /*0x1d4*/;
    // 0046ab13  890d68475100           -mov dword ptr [0x514768], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326696) /* 0x514768 */) = cpu.ecx;
    // 0046ab19  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ab1b  b940010000             -mov ecx, 0x140
    cpu.ecx = 320 /*0x140*/;
    // 0046ab20  a36c475100             -mov dword ptr [0x51476c], eax
    app->getMemory<x86::reg32>(x86::reg32(5326700) /* 0x51476c */) = cpu.eax;
    // 0046ab25  891d8c475100           -mov dword ptr [0x51478c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5326732) /* 0x51478c */) = cpu.ebx;
    // 0046ab2b  891dfc475100           -mov dword ptr [0x5147fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5326844) /* 0x5147fc */) = cpu.ebx;
    // 0046ab31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ab33  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0046ab38  890d88475100           -mov dword ptr [0x514788], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326728) /* 0x514788 */) = cpu.ecx;
    // 0046ab3e  890df8475100           -mov dword ptr [0x5147f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326840) /* 0x5147f8 */) = cpu.ecx;
    // 0046ab44  890d68485100           -mov dword ptr [0x514868], ecx
    app->getMemory<x86::reg32>(x86::reg32(5326952) /* 0x514868 */) = cpu.ecx;
    // 0046ab4a  8915bc885100           -mov dword ptr [0x5188bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5343420) /* 0x5188bc */) = cpu.edx;
    // 0046ab50  a3d8475100             -mov dword ptr [0x5147d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5326808) /* 0x5147d8 */) = cpu.eax;
    // 0046ab55  a348485100             -mov dword ptr [0x514848], eax
    app->getMemory<x86::reg32>(x86::reg32(5326920) /* 0x514848 */) = cpu.eax;
    // 0046ab5a  b84c020000             -mov eax, 0x24c
    cpu.eax = 588 /*0x24c*/;
    // 0046ab5f  8915c4885100           -mov dword ptr [0x5188c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5343428) /* 0x5188c4 */) = cpu.edx;
    // 0046ab65  a36c485100             -mov dword ptr [0x51486c], eax
    app->getMemory<x86::reg32>(x86::reg32(5326956) /* 0x51486c */) = cpu.eax;
    // 0046ab6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ab6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46ab70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ab70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ab71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ab72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ab73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ab74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ab75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ab77  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046ab79  ba64db4b00             -mov edx, 0x4bdb64
    cpu.edx = 4971364 /*0x4bdb64*/;
    // 0046ab7e  a1ccf34d00             -mov eax, dword ptr [0x4df3cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108684) /* 0x4df3cc */);
    // 0046ab83  e8dcdd0000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 0046ab88  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046ab8a  e865610200             -call 0x490cf4
    cpu.esp -= 4;
    sub_490cf4(app, cpu);
    if (cpu.terminate) return;
    // 0046ab8f  8b7a0c                 -mov edi, dword ptr [edx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ab92  c1e714                 -shl edi, 0x14
    cpu.edi <<= 20 /*0x14*/ % 32;
    // 0046ab95  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0046ab97  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 0046ab9a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046ab9c  897118                 -mov dword ptr [ecx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0046ab9f  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046aba2  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0046aba5  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046aba8  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046abab  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046abad  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046abaf  89711c                 -mov dword ptr [ecx + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0046abb2  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046abb5  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0046abb8  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046abbb  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046abbe  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046abc0  897920                 -mov dword ptr [ecx + 0x20], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0046abc3  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046abc6  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0046abc9  8b680c                 -mov ebp, dword ptr [eax + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046abcc  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046abcf  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046abd1  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046abd3  897124                 -mov dword ptr [ecx + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0046abd6  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046abd9  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0046abdc  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046abdf  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046abe2  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046abe4  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0046abe6  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046abe9  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0046abec  8b7814                 -mov edi, dword ptr [eax + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046abef  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046abf2  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046abf4  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046abf6  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0046abf9  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046abfc  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0046abff  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046ac02  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac05  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ac07  897940                 -mov dword ptr [ecx + 0x40], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.edi;
    // 0046ac0a  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac0d  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0046ac10  8b681c                 -mov ebp, dword ptr [eax + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046ac13  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac16  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ac18  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ac1a  897144                 -mov dword ptr [ecx + 0x44], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.esi;
    // 0046ac1d  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac20  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0046ac23  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046ac26  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac29  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ac2b  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0046ac2e  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac31  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0046ac34  8b7824                 -mov edi, dword ptr [eax + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0046ac37  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac3a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046ac3c  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ac3e  897114                 -mov dword ptr [ecx + 0x14], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0046ac41  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac44  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0046ac47  8b7828                 -mov edi, dword ptr [eax + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0046ac4a  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac4d  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ac4f  897938                 -mov dword ptr [ecx + 0x38], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0046ac52  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac55  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0046ac58  8b682c                 -mov ebp, dword ptr [eax + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0046ac5b  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac5e  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ac60  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ac62  89713c                 -mov dword ptr [ecx + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0046ac65  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac68  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0046ac6b  8b7830                 -mov edi, dword ptr [eax + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 0046ac6e  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046ac71  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ac73  897908                 -mov dword ptr [ecx + 8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046ac76  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ac79  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046ac7c  8b7034                 -mov esi, dword ptr [eax + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0046ac7f  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046ac82  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ac84  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ac86  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046ac89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ac8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46ac90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ac90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ac91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ac92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ac93  8b35b08f4c00           -mov esi, dword ptr [0x4c8fb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */);
    // 0046ac99  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046ac9b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046ac9d  83fe77                 +cmp esi, 0x77
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046aca0  7c50                   -jl 0x46acf2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046acf2;
    }
    // 0046aca2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046aca4:
    // 0046aca4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046aca6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046aca9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046acab  bae04c5100             -mov edx, 0x514ce0
    cpu.edx = 5328096 /*0x514ce0*/;
    // 0046acb0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046acb3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046acb5  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046acbc  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046acbe  891485e04c5100         -mov dword ptr [eax*4 + 0x514ce0], edx
    app->getMemory<x86::reg32>(x86::reg32(5328096) /* 0x514ce0 */ + cpu.eax * 4) = cpu.edx;
    // 0046acc5  893c85e44c5100         -mov dword ptr [eax*4 + 0x514ce4], edi
    app->getMemory<x86::reg32>(x86::reg32(5328100) /* 0x514ce4 */ + cpu.eax * 4) = cpu.edi;
    // 0046accc  892c85004d5100         -mov dword ptr [eax*4 + 0x514d00], ebp
    app->getMemory<x86::reg32>(x86::reg32(5328128) /* 0x514d00 */ + cpu.eax * 4) = cpu.ebp;
    // 0046acd3  891c85e84c5100         -mov dword ptr [eax*4 + 0x514ce8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5328104) /* 0x514ce8 */ + cpu.eax * 4) = cpu.ebx;
    // 0046acda  890c85ec4c5100         -mov dword ptr [eax*4 + 0x514cec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5328108) /* 0x514cec */ + cpu.eax * 4) = cpu.ecx;
    // 0046ace1  83fe77                 +cmp esi, 0x77
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ace4  7c11                   -jl 0x46acf7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046acf7;
    }
    // 0046ace6  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0046ace8  8935b08f4c00           -mov dword ptr [0x4c8fb0], esi
    app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */) = cpu.esi;
    // 0046acee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acf1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046acf2:
    // 0046acf2  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046acf5  ebad                   -jmp 0x46aca4
    goto L_0x0046aca4;
L_0x0046acf7:
    // 0046acf7  46                     -inc esi
    (cpu.esi)++;
    // 0046acf8  8935b08f4c00           -mov dword ptr [0x4c8fb0], esi
    app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */) = cpu.esi;
    // 0046acfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ad10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ad10  a1dc9d5100             -mov eax, dword ptr [0x519ddc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5348828) /* 0x519ddc */);
    // 0046ad15  e972f90000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ad20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ad20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ad21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ad22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ad23  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046ad26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ad27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ad28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ad29  baf8dc4b00             -mov edx, 0x4bdcf8
    cpu.edx = 4971768 /*0x4bdcf8*/;
    // 0046ad2e  b9d4000000             -mov ecx, 0xd4
    cpu.ecx = 212 /*0xd4*/;
    // 0046ad33  b818dd4b00             -mov eax, 0x4bdd18
    cpu.eax = 4971800 /*0x4bdd18*/;
    // 0046ad38  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ad3a  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046ad40  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0046ad45  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046ad4b  e8d8f40000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046ad50  a3dc9d5100             -mov dword ptr [0x519ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5348828) /* 0x519ddc */) = cpu.eax;
    // 0046ad55  e836250000             -call 0x46d290
    cpu.esp -= 4;
    sub_46d290(app, cpu);
    if (cpu.terminate) return;
    // 0046ad5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ad5c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046ad60  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0046ad64  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0046ad68  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x0046ad6a:
    // 0046ad6a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ad6e  8b3ddc9d5100           -mov edi, dword ptr [0x519ddc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5348828) /* 0x519ddc */);
    // 0046ad74  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ad76  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046ad7a  80b8cc88510000         +cmp byte ptr [eax + 0x5188cc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5343436) /* 0x5188cc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ad81  7558                   -jne 0x46addb
    if (!cpu.flags.zf)
    {
        goto L_0x0046addb;
    }
L_0x0046ad83:
    // 0046ad83  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046ad87  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ad8b  83c503                 -add ebp, 3
    (cpu.ebp) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046ad8e  43                     -inc ebx
    (cpu.ebx)++;
    // 0046ad8f  81c100010000           -add ecx, 0x100
    (cpu.ecx) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046ad95  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0046ad99  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0046ad9d  81fb00010000           +cmp ebx, 0x100
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
    // 0046ada3  7cc5                   -jl 0x46ad6a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ad6a;
    }
    // 0046ada5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ada7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ada9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046adaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046adab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046adac:
    // 0046adac  8b0ddc9d5100           -mov ecx, dword ptr [0x519ddc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5348828) /* 0x519ddc */);
    // 0046adb2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046adb5  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046adb7  81c200010000           -add edx, 0x100
    (cpu.edx) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046adbd  8988c8895100           -mov dword ptr [eax + 0x5189c8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5343688) /* 0x5189c8 */) = cpu.ecx;
    // 0046adc3  3d00040000             +cmp eax, 0x400
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
    // 0046adc8  75e2                   -jne 0x46adac
    if (!cpu.flags.zf)
    {
        goto L_0x0046adac;
    }
    // 0046adca  b8cc895100             -mov eax, 0x5189cc
    cpu.eax = 5343692 /*0x5189cc*/;
    // 0046adcf  e808640200             -call 0x4911dc
    cpu.esp -= 4;
    sub_4911dc(app, cpu);
    if (cpu.terminate) return;
    // 0046add4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046add7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046add8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046add9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046adda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046addb:
    // 0046addb  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0046addd  88742418               -mov byte ptr [esp + 0x18], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.dh;
    // 0046ade1  88742424               -mov byte ptr [esp + 0x24], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.dh;
    // 0046ade5  88742420               -mov byte ptr [esp + 0x20], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.dh;
    // 0046ade9  3dff000000             +cmp eax, 0xff
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
    // 0046adee  0f858c000000           -jne 0x46ae80
    if (!cpu.flags.zf)
    {
        goto L_0x0046ae80;
    }
L_0x0046adf4:
    // 0046adf4  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046adf8  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0046adfa  81c700010000           -add edi, 0x100
    (cpu.edi) += x86::reg32(x86::sreg32(256 /*0x100*/));
L_0x0046ae00:
    // 0046ae00  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046ae02  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ae04  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0046ae06  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae08  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ae0c  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046ae0f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ae11  8a7902                 -mov bh, byte ptr [ecx + 2]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046ae14  3dff000000             +cmp eax, 0xff
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
    // 0046ae19  7e05                   -jle 0x46ae20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ae20;
    }
    // 0046ae1b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0046ae20:
    // 0046ae20  8844241c               -mov byte ptr [esp + 0x1c], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 0046ae24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ae26  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae28  8a542418               -mov dl, byte ptr [esp + 0x18]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ae2c  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0046ae2e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ae30  3dff000000             +cmp eax, 0xff
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
    // 0046ae35  7e05                   -jle 0x46ae3c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ae3c;
    }
    // 0046ae37  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0046ae3c:
    // 0046ae3c  88fb                   -mov bl, bh
    cpu.bl = cpu.bh;
    // 0046ae3e  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0046ae40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae42  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046ae48  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046ae4c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ae4e  3dff000000             +cmp eax, 0xff
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
    // 0046ae53  7e05                   -jle 0x46ae5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ae5a;
    }
    // 0046ae55  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0046ae5a:
    // 0046ae5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ae5c  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0046ae5e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046ae64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae66  46                     -inc esi
    (cpu.esi)++;
    // 0046ae67  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046ae6b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046ae6e  e82d2d0000             -call 0x46dba0
    cpu.esp -= 4;
    sub_46dba0(app, cpu);
    if (cpu.terminate) return;
    // 0046ae73  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046ae76  39fe                   +cmp esi, edi
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
    // 0046ae78  0f8405ffffff           -je 0x46ad83
    if (cpu.flags.zf)
    {
        goto L_0x0046ad83;
    }
    // 0046ae7e  eb80                   -jmp 0x46ae00
    goto L_0x0046ae00;
L_0x0046ae80:
    // 0046ae80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae82  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0046ae85  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046ae88  88442424               -mov byte ptr [esp + 0x24], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
    // 0046ae8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae8e  8a4501                 -mov al, byte ptr [ebp + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0046ae91  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046ae94  88442418               -mov byte ptr [esp + 0x18], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.al;
    // 0046ae98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae9a  8a4502                 -mov al, byte ptr [ebp + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0046ae9d  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0046aea0  88442420               -mov byte ptr [esp + 0x20], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
    // 0046aea4  e94bffffff             -jmp 0x46adf4
    goto L_0x0046adf4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46aeb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046aeb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046aeb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046aeb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046aeb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046aeb5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046aeb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046aeb9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046aebb  7e17                   -jle 0x46aed4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046aed4;
    }
    // 0046aebd  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0046aebf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0046aec1:
    // 0046aec1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046aec3  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046aec5  42                     -inc edx
    (cpu.edx)++;
    // 0046aec6  40                     -inc eax
    (cpu.eax)++;
    // 0046aec7  8899cc885100           -mov byte ptr [ecx + 0x5188cc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5343436) /* 0x5188cc */) = cpu.bl;
    // 0046aecd  39f0                   +cmp eax, esi
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
    // 0046aecf  7cf0                   -jl 0x46aec1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046aec1;
    }
    // 0046aed1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0046aed4:
    // 0046aed4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aed5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aed6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aed7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46aee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046aee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046aee1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046aee3:
    // 0046aee3  40                     -inc eax
    (cpu.eax)++;
    // 0046aee4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0046aee6  8890cb885100           -mov byte ptr [eax + 0x5188cb], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5343435) /* 0x5188cb */) = cpu.dl;
    // 0046aeec  3d00010000             +cmp eax, 0x100
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
    // 0046aef1  7cf0                   -jl 0x46aee3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046aee3;
    }
    // 0046aef3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046aef4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46af00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046af00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046af01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046af02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046af03  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0046af09  e882230000             -call 0x46d290
    cpu.esp -= 4;
    sub_46d290(app, cpu);
    if (cpu.terminate) return;
    // 0046af0e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046af10  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046af14  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046af16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046af18  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046af1a  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 0046af1f  e81c020000             -call 0x46b140
    cpu.esp -= 4;
    sub_46b140(app, cpu);
    if (cpu.terminate) return;
    // 0046af24  ba3cc84c00             -mov edx, 0x4cc83c
    cpu.edx = 5031996 /*0x4cc83c*/;
    // 0046af29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046af2b  e8302c0000             -call 0x46db60
    cpu.esp -= 4;
    sub_46db60(app, cpu);
    if (cpu.terminate) return;
    // 0046af30  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0046af36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46af40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046af40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046af41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046af42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046af43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046af44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046af45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046af46  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 0046af4c  e83f230000             -call 0x46d290
    cpu.esp -= 4;
    sub_46d290(app, cpu);
    if (cpu.terminate) return;
    // 0046af51  bfcc8d5100             -mov edi, 0x518dcc
    cpu.edi = 5344716 /*0x518dcc*/;
    // 0046af56  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046af58  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046af5a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046af5c  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
L_0x0046af63:
    // 0046af63  bb00001000             -mov ebx, 0x100000
    cpu.ebx = 1048576 /*0x100000*/;
    // 0046af68  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046af6a  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046af6b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046af6d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046af6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046af71  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0046af75  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046af78  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046af7a  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046af7d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046af7f  833dd89d510000         +cmp dword ptr [0x519dd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5348824) /* 0x519dd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046af86  7566                   -jne 0x46afee
    if (!cpu.flags.zf)
    {
        goto L_0x0046afee;
    }
    // 0046af88  8b1dd49d5100           -mov ebx, dword ptr [0x519dd4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5348820) /* 0x519dd4 */);
    // 0046af8e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046af8f  8b15d09d5100           -mov edx, dword ptr [0x519dd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5348816) /* 0x519dd0 */);
    // 0046af95  8b0dcc9d5100           -mov ecx, dword ptr [0x519dcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5348812) /* 0x519dcc */);
    // 0046af9b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046af9c  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046afa0  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046afa2  e899010000             -call 0x46b140
    cpu.esp -= 4;
    sub_46b140(app, cpu);
    if (cpu.terminate) return;
L_0x0046afa7:
    // 0046afa7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046afa9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046afab  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0046afb2  e8a92b0000             -call 0x46db60
    cpu.esp -= 4;
    sub_46db60(app, cpu);
    if (cpu.terminate) return;
    // 0046afb7  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0046afba  c681cb8e5100ff         -mov byte ptr [ecx + 0x518ecb], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5344971) /* 0x518ecb */) = 255 /*0xff*/;
    // 0046afc1  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0046afc8  81c500000100           -add ebp, 0x10000
    (cpu.ebp) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0046afce  40                     -inc eax
    (cpu.eax)++;
    // 0046afcf  81c700010000           -add edi, 0x100
    (cpu.edi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046afd5  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 0046afdc  83f810                 +cmp eax, 0x10
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
    // 0046afdf  7c82                   -jl 0x46af63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046af63;
    }
    // 0046afe1  81c404030000           +add esp, 0x304
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(772 /*0x304*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046afe7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afe8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afe9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046afee:
    // 0046afee  8b0dd49d5100           -mov ecx, dword ptr [0x519dd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5348820) /* 0x519dd4 */);
    // 0046aff4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046aff5  8b1dd09d5100           -mov ebx, dword ptr [0x519dd0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5348816) /* 0x519dd0 */);
    // 0046affb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046affd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046affe  8b0dcc9d5100           -mov ecx, dword ptr [0x519dcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5348812) /* 0x519dcc */);
    // 0046b004  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b008  e833000000             -call 0x46b040
    cpu.esp -= 4;
    sub_46b040(app, cpu);
    if (cpu.terminate) return;
    // 0046b00d  eb98                   -jmp 0x46afa7
    goto L_0x0046afa7;
}

/* align: skip 0x00 */
void Application::sub_46b010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b010  8915cc9d5100           -mov dword ptr [0x519dcc], edx
    app->getMemory<x86::reg32>(x86::reg32(5348812) /* 0x519dcc */) = cpu.edx;
    // 0046b016  891dd09d5100           -mov dword ptr [0x519dd0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5348816) /* 0x519dd0 */) = cpu.ebx;
    // 0046b01c  890dd49d5100           -mov dword ptr [0x519dd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5348820) /* 0x519dd4 */) = cpu.ecx;
    // 0046b022  a3d89d5100             -mov dword ptr [0x519dd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5348824) /* 0x519dd8 */) = cpu.eax;
    // 0046b027  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b030  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046b033  05cc8d5100             -add eax, 0x518dcc
    (cpu.eax) += x86::reg32(x86::sreg32(5344716 /*0x518dcc*/));
    // 0046b038  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b040  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b041  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b042  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b043  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046b046  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046b048  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046b04a  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0046b04e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046b050  81c2fd020000           -add edx, 0x2fd
    (cpu.edx) += x86::reg32(x86::sreg32(765 /*0x2fd*/));
    // 0046b056  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x0046b05a:
    // 0046b05a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b05c  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0046b05f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046b063  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b065  8a4501                 -mov al, byte ptr [ebp + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0046b068  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046b06c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b06e  8a4502                 -mov al, byte ptr [ebp + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0046b071  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046b075  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b079  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0046b07b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b07c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b080  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046b084  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b085  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b089  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b08d  e8ceb7fdff             -call 0x446860
    cpu.esp -= 4;
    sub_446860(app, cpu);
    if (cpu.terminate) return;
    // 0046b092  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046b096  2b0424                 -sub eax, dword ptr [esp]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0046b099  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b09b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046b09d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046b0a0  c1e810                 +shr eax, 0x10
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
    // 0046b0a3  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046b0a5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b0a8  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b0ac  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b0ae  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046b0b2  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046b0b6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b0b8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b0ba  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046b0bc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046b0bf  c1e810                 +shr eax, 0x10
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
    // 0046b0c2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046b0c4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b0c8  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b0cc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b0ce  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046b0d2  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0046b0d6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b0d8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b0da  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046b0dc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046b0df  c1e810                 +shr eax, 0x10
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
    // 0046b0e2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046b0e4  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b0e8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b0ea  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046b0ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b0ef  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046b0f3  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046b0f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b0f8  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046b0fc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046b100  e803b5fdff             -call 0x446608
    cpu.esp -= 4;
    sub_446608(app, cpu);
    if (cpu.terminate) return;
    // 0046b105  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b109  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0046b10b  46                     -inc esi
    (cpu.esi)++;
    // 0046b10c  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046b110  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0046b112  46                     -inc esi
    (cpu.esi)++;
    // 0046b113  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046b117  83c503                 -add ebp, 3
    (cpu.ebp) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b11a  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 0046b11c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046b120  46                     -inc esi
    (cpu.esi)++;
    // 0046b121  39c5                   +cmp ebp, eax
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
    // 0046b123  0f8531ffffff           -jne 0x46b05a
    if (!cpu.flags.zf)
    {
        goto L_0x0046b05a;
    }
    // 0046b129  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046b12c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b12d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b12e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b12f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b140  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b141  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b142  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b143  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b146  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b148  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0046b14b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046b14d  81c200030000           -add edx, 0x300
    (cpu.edx) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0046b153  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0046b157:
    // 0046b157  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b15a  0fb639                 -movzx edi, byte ptr [ecx]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0046b15d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046b15f  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046b161  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046b163  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046b166  c1e810                 +shr eax, 0x10
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
    // 0046b169  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046b16b  8d2c07                 -lea ebp, [edi + eax]
    cpu.ebp = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0046b16e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046b172  0fb67901               -movzx edi, byte ptr [ecx + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 0046b176  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046b178  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046b17a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046b17c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046b17f  c1e810                 +shr eax, 0x10
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
    // 0046b182  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046b184  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b186  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b18a  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046b18e  0fb67902               -movzx edi, byte ptr [ecx + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */));
    // 0046b192  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046b194  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046b196  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046b198  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046b19b  c1e810                 +shr eax, 0x10
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
    // 0046b19e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046b1a0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b1a2  81fdff000000           +cmp ebp, 0xff
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b1a8  7e47                   -jle 0x46b1f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b1f1;
    }
    // 0046b1aa  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0046b1af:
    // 0046b1af  43                     -inc ebx
    (cpu.ebx)++;
    // 0046b1b0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b1b4  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046b1b7  81faff000000           +cmp edx, 0xff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b1bd  7e36                   -jle 0x46b1f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b1f5;
    }
    // 0046b1bf  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0046b1c4:
    // 0046b1c4  43                     -inc ebx
    (cpu.ebx)++;
    // 0046b1c5  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046b1c8  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b1ce  7e29                   -jle 0x46b1f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b1f9;
    }
    // 0046b1d0  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0046b1d5:
    // 0046b1d5  43                     -inc ebx
    (cpu.ebx)++;
    // 0046b1d6  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b1da  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b1dd  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046b1e0  39f9                   +cmp ecx, edi
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
    // 0046b1e2  0f856fffffff           -jne 0x46b157
    if (!cpu.flags.zf)
    {
        goto L_0x0046b157;
    }
    // 0046b1e8  83c40c                 +add esp, 0xc
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
    // 0046b1eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1ee  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0046b1f1:
    // 0046b1f1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046b1f3  ebba                   -jmp 0x46b1af
    goto L_0x0046b1af;
L_0x0046b1f5:
    // 0046b1f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b1f7  ebcb                   -jmp 0x46b1c4
    goto L_0x0046b1c4;
L_0x0046b1f9:
    // 0046b1f9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046b1fb  ebd8                   -jmp 0x46b1d5
    goto L_0x0046b1d5;
}

/* align: skip 0x00 0x00 0x00 */
/* data blob: 20dd4b0028dd4b0030dd4b0038dd4b0040dd4b0048dd4b0050dd4b0058dd4b0060dd4b0068dd4b0070dd4b0078dd4b0080dd4b0084dd4b0088dd4b008cdd4b0090dd4b0094dd4b0098dd4b009cdd4b00a0dd4b00a4dd4b00a8dd4b00acdd4b00b4dd4b00b8dd4b00bcdd4b00c0dd4b00c4dd4b00c8dd4b00ccdd4b00d0dd4b00d4dd4b00d8dd4b00dcdd4b00e0dd4b00e4dd4b00ecdd4b00f4dd4b00fcdd4b0004de4b000cde4b000000000000000000 */
void Application::sub_46b2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b2b0  e817f60000             -call 0x47a8cc
    cpu.esp -= 4;
    sub_47a8cc(app, cpu);
    if (cpu.terminate) return;
    // 0046b2b5  a3dc944c00             -mov dword ptr [0x4c94dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5018844) /* 0x4c94dc */) = cpu.eax;
    // 0046b2ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b2c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b2c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b2c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b2c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b2c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b2c5  81ec18010000           -sub esp, 0x118
    (cpu.esp) -= x86::reg32(x86::sreg32(280 /*0x118*/));
    // 0046b2cb  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0046b2d0  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046b2d7  be90b24600             -mov esi, 0x46b290
    cpu.esi = 4633232 /*0x46b290*/;
    // 0046b2dc  8b153cf54d00           -mov edx, dword ptr [0x4df53c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 0046b2e2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046b2e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b2e5  8b0db8074e00           -mov ecx, dword ptr [0x4e07b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113784) /* 0x4e07b8 */);
    // 0046b2eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b2ec  68e0de4b00             -push 0x4bdee0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972256 /*0x4bdee0*/;
    cpu.esp -= 4;
    // 0046b2f1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b2f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b2f6  8b1d54f54d00           -mov ebx, dword ptr [0x4df554]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5109076) /* 0x4df554 */);
    // 0046b2fc  e8e00c0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046b301  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b304  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b306  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046b308  e86b260100             -call 0x47d978
    cpu.esp -= 4;
    sub_47d978(app, cpu);
    if (cpu.terminate) return;
    // 0046b30d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046b30f  e8e0cb0000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 0046b314  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b316  e8d5ce0000             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0046b31b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b31d  8b949c00010000         -mov edx, dword ptr [esp + ebx*4 + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */ + cpu.ebx * 4);
    // 0046b324  e82fd60000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046b329  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046b32c  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046b32f  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0046b332  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046b335  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0046b338  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046b33b  e8c0e00000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
    // 0046b340  e8d7cb0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0046b345  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046b347  750c                   -jne 0x46b355
    if (!cpu.flags.zf)
    {
        goto L_0x0046b355;
    }
    // 0046b349  81c418010000           -add esp, 0x118
    (cpu.esp) += x86::reg32(x86::sreg32(280 /*0x118*/));
    // 0046b34f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b350  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b351  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b352  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b353  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b354  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b355:
    // 0046b355  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b357  e830f30000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046b35c  81c418010000           -add esp, 0x118
    (cpu.esp) += x86::reg32(x86::sreg32(280 /*0x118*/));
    // 0046b362  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b363  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b364  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b365  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b366  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b367  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b372  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b373  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b374  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b375  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b376  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0046b37c  89842400010000         -mov dword ptr [esp + 0x100], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0046b383  83f801                 +cmp eax, 1
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
    // 0046b386  750d                   -jne 0x46b395
    if (!cpu.flags.zf)
    {
        goto L_0x0046b395;
    }
    // 0046b388  833dd8944c0000         +cmp dword ptr [0x4c94d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018840) /* 0x4c94d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b38f  0f8492000000           -je 0x46b427
    if (cpu.flags.zf)
    {
        goto L_0x0046b427;
    }
L_0x0046b395:
    // 0046b395  ba7cde4b00             -mov edx, 0x4bde7c
    cpu.edx = 4972156 /*0x4bde7c*/;
    // 0046b39a  a1d8944c00             -mov eax, dword ptr [0x4c94d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018840) /* 0x4c94d8 */);
    // 0046b39f  e8b4d50000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046b3a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b3a6  e849cb0000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 0046b3ab  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046b3b2  48                     -dec eax
    (cpu.eax)--;
    // 0046b3b3  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046b3ba  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b3bc  bfb4010000             -mov edi, 0x1b4
    cpu.edi = 436 /*0x1b4*/;
    // 0046b3c1  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0046b3c4  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b3c6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046b3c8  83ef28                 -sub edi, 0x28
    (cpu.edi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0046b3cb:
    // 0046b3cb  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0046b3d0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046b3d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046b3d4  83e905                 -sub ecx, 5
    (cpu.ecx) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 0046b3d7  e824e00000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
    // 0046b3dc  39f9                   +cmp ecx, edi
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
    // 0046b3de  75eb                   -jne 0x46b3cb
    if (!cpu.flags.zf)
    {
        goto L_0x0046b3cb;
    }
    // 0046b3e0  8bb42400010000         -mov esi, dword ptr [esp + 0x100]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046b3e7  e830cb0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0046b3ec  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b3ef  7519                   -jne 0x46b40a
    if (!cpu.flags.zf)
    {
        goto L_0x0046b40a;
    }
    // 0046b3f1  8b3dd8944c00           -mov edi, dword ptr [0x4c94d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5018840) /* 0x4c94d8 */);
    // 0046b3f7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046b3f9  740f                   -je 0x46b40a
    if (cpu.flags.zf)
    {
        goto L_0x0046b40a;
    }
    // 0046b3fb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046b3fd  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046b3ff  e888f20000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046b404  892dd8944c00           -mov dword ptr [0x4c94d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5018840) /* 0x4c94d8 */) = cpu.ebp;
L_0x0046b40a:
    // 0046b40a  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046b411  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b413  7e05                   -jle 0x46b41a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b41a;
    }
    // 0046b415  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b418  7c3c                   -jl 0x46b456
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b456;
    }
L_0x0046b41a:
    // 0046b41a  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0046b420  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b423  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b424  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b425  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b426  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b427:
    // 0046b427  8b1db8074e00           -mov ebx, dword ptr [0x4e07b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113784) /* 0x4e07b8 */);
    // 0046b42d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b42e  68d4de4b00             -push 0x4bded4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972244 /*0x4bded4*/;
    cpu.esp -= 4;
    // 0046b433  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b437  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b438  e8a40b0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046b43d  83c40c                 +add esp, 0xc
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
    // 0046b440  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 0046b445  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046b447  e838250100             -call 0x47d984
    cpu.esp -= 4;
    sub_47d984(app, cpu);
    if (cpu.terminate) return;
    // 0046b44c  a3d8944c00             -mov dword ptr [0x4c94d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5018840) /* 0x4c94d8 */) = cpu.eax;
    // 0046b451  e93fffffff             -jmp 0x46b395
    goto L_0x0046b395;
L_0x0046b456:
    // 0046b456  8a842400010000         -mov al, byte ptr [esp + 0x100]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046b45d  0404                   -add al, 4
    (cpu.al) += x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0046b45f  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0046b462  b800140000             -mov eax, 0x1400
    cpu.eax = 5120 /*0x1400*/;
    // 0046b467  e8245cfeff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 0046b46c  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0046b472  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b473  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b474  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b475  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b477  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b478  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b485  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b486  81ecb8010000           -sub esp, 0x1b8
    (cpu.esp) -= x86::reg32(x86::sreg32(440 /*0x1b8*/));
    // 0046b48c  898424b0010000         -mov dword ptr [esp + 0x1b0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(432) /* 0x1b0 */) = cpu.eax;
    // 0046b493  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0046b498  8dbc2494010000         -lea edi, [esp + 0x194]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 0046b49f  be00b24600             -mov esi, 0x46b200
    cpu.esi = 4633088 /*0x46b200*/;
    // 0046b4a4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046b4a6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0046b4ab  8dbc2470010000         -lea edi, [esp + 0x170]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0046b4b2  be30b24600             -mov esi, 0x46b230
    cpu.esi = 4633136 /*0x46b230*/;
    // 0046b4b7  8b9424b0010000         -mov edx, dword ptr [esp + 0x1b0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
    // 0046b4be  a154f54d00             -mov eax, dword ptr [0x4df554]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109076) /* 0x4df554 */);
    // 0046b4c3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046b4c5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b4c7  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 0046b4cc  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046b4d3  be54b24600             -mov esi, 0x46b254
    cpu.esi = 4633172 /*0x46b254*/;
    // 0046b4d8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046b4da  898424ac010000         -mov dword ptr [esp + 0x1ac], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */) = cpu.eax;
    // 0046b4e1  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046b4e3  a13cf54d00             -mov eax, dword ptr [0x4df53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 0046b4e8  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0046b4ed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b4ef  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0046b4f2  7421                   -je 0x46b515
    if (cpu.flags.zf)
    {
        goto L_0x0046b515;
    }
L_0x0046b4f4:
    // 0046b4f4  833d34f54d0000         +cmp dword ptr [0x4df534], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b4fb  7422                   -je 0x46b51f
    if (cpu.flags.zf)
    {
        goto L_0x0046b51f;
    }
    // 0046b4fd  6683bc24b001000000     +cmp word ptr [esp + 0x1b0], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b506  7e17                   -jle 0x46b51f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b51f;
    }
L_0x0046b508:
    // 0046b508  81c4b8010000           -add esp, 0x1b8
    (cpu.esp) += x86::reg32(x86::sreg32(440 /*0x1b8*/));
    // 0046b50e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b50f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b511  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b512  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b513  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b514  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b515:
    // 0046b515  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046b517  8915d4944c00           -mov dword ptr [0x4c94d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5018836) /* 0x4c94d4 */) = cpu.edx;
    // 0046b51d  ebd5                   -jmp 0x46b4f4
    goto L_0x0046b4f4;
L_0x0046b51f:
    // 0046b51f  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b528  7d23                   -jge 0x46b54d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b54d;
    }
    // 0046b52a  833d28f54d0004         +cmp dword ptr [0x4df528], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b531  751a                   -jne 0x46b54d
    if (!cpu.flags.zf)
    {
        goto L_0x0046b54d;
    }
    // 0046b533  8b152cf54d00           -mov edx, dword ptr [0x4df52c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0046b539  66833c55ba024e0024     +cmp word ptr [edx*2 + 0x4e02ba], 0x24
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5112506) /* 0x4e02ba */ + cpu.edx * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(36 /*0x24*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b542  7509                   -jne 0x46b54d
    if (!cpu.flags.zf)
    {
        goto L_0x0046b54d;
    }
    // 0046b544  833d34f54d0000         +cmp dword ptr [0x4df534], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b54b  74bb                   -je 0x46b508
    if (cpu.flags.zf)
    {
        goto L_0x0046b508;
    }
L_0x0046b54d:
    // 0046b54d  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b554  7528                   -jne 0x46b57e
    if (!cpu.flags.zf)
    {
        goto L_0x0046b57e;
    }
    // 0046b556  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b55f  7d1d                   -jge 0x46b57e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b57e;
    }
    // 0046b561  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b563  8a15dd004e00           -mov dl, byte ptr [0x4e00dd]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046b569  8b3d90f54d00           -mov edi, dword ptr [0x4df590]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109136) /* 0x4df590 */);
    // 0046b56f  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b572  39fa                   +cmp edx, edi
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
    // 0046b574  7e92                   -jle 0x46b508
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b508;
    }
    // 0046b576  3b15d0f54d00           +cmp edx, dword ptr [0x4df5d0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109200) /* 0x4df5d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b57c  7e8a                   -jle 0x46b508
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b508;
    }
L_0x0046b57e:
    // 0046b57e  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b585  7d24                   -jge 0x46b5ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b5ab;
    }
    // 0046b587  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b590  7d19                   -jge 0x46b5ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b5ab;
    }
    // 0046b592  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b594  8a15dd004e00           -mov dl, byte ptr [0x4e00dd]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046b59a  8b3d90f54d00           -mov edi, dword ptr [0x4df590]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109136) /* 0x4df590 */);
    // 0046b5a0  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b5a3  39fa                   +cmp edx, edi
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
    // 0046b5a5  0f8e5dffffff           -jle 0x46b508
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b508;
    }
L_0x0046b5ab:
    // 0046b5ab  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b5b4  7d0d                   -jge 0x46b5c3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b5c3;
    }
    // 0046b5b6  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046b5bd  0f8545ffffff           -jne 0x46b508
    if (!cpu.flags.zf)
    {
        goto L_0x0046b508;
    }
L_0x0046b5c3:
    // 0046b5c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b5c5  0f8c7f010000           -jl 0x46b74a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b74a;
    }
    // 0046b5cb  83f808                 +cmp eax, 8
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
    // 0046b5ce  0f8f76010000           -jg 0x46b74a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046b74a;
    }
L_0x0046b5d4:
    // 0046b5d4  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
L_0x0046b5db:
    // 0046b5db  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046b5dd  0f856e010000           -jne 0x46b751
    if (!cpu.flags.zf)
    {
        goto L_0x0046b751;
    }
L_0x0046b5e3:
    // 0046b5e3  8b2d28f54d00           -mov ebp, dword ptr [0x4df528]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0046b5e9  43                     -inc ebx
    (cpu.ebx)++;
    // 0046b5ea  83fd01                 +cmp ebp, 1
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
    // 0046b5ed  0f851c020000           -jne 0x46b80f
    if (!cpu.flags.zf)
    {
        goto L_0x0046b80f;
    }
    // 0046b5f3  a118f54d00             -mov eax, dword ptr [0x4df518]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109016) /* 0x4df518 */);
    // 0046b5f8  83f802                 +cmp eax, 2
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
    // 0046b5fb  0f850e020000           -jne 0x46b80f
    if (!cpu.flags.zf)
    {
        goto L_0x0046b80f;
    }
    // 0046b601  3b0584f54d00           +cmp eax, dword ptr [0x4df584]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b607  0f8e02020000           -jle 0x46b80f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b80f;
    }
    // 0046b60d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b60f  e8ecbff9ff             -call 0x407600
    cpu.esp -= 4;
    sub_407600(app, cpu);
    if (cpu.terminate) return;
    // 0046b614  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0046b617  0f84e5010000           -je 0x46b802
    if (cpu.flags.zf)
    {
        goto L_0x0046b802;
    }
L_0x0046b61d:
    // 0046b61d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b61f  8a0ddf004e00           -mov cl, byte ptr [0x4e00df]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5112031) /* 0x4e00df */);
L_0x0046b625:
    // 0046b625  6683f903               +cmp cx, 3
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b629  0f857e020000           -jne 0x46b8ad
    if (!cpu.flags.zf)
    {
        goto L_0x0046b8ad;
    }
L_0x0046b62f:
    // 0046b62f  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
L_0x0046b634:
    // 0046b634  6683f90c               +cmp cx, 0xc
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(12 /*0xc*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b638  0f8d7e020000           -jge 0x46b8bc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b8bc;
    }
    // 0046b63e  a0b4874d00             -mov al, byte ptr [0x4d87b4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5081012) /* 0x4d87b4 */);
    // 0046b643  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b645  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0046b647  888424b4010000         -mov byte ptr [esp + 0x1b4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(436) /* 0x1b4 */) = cpu.al;
    // 0046b64e  8a92a94f4c00           -mov dl, byte ptr [edx + 0x4c4fa9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5001129) /* 0x4c4fa9 */);
    // 0046b654  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046b65a  0fbfee                 -movsx ebp, si
    cpu.ebp = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0046b65d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b65f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046b662  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046b664  8a8424b4010000         -mov al, byte ptr [esp + 0x1b4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(436) /* 0x1b4 */);
    // 0046b66b  fec0                   -inc al
    (cpu.al)++;
    // 0046b66d  42                     -inc edx
    (cpu.edx)++;
    // 0046b66e  a2b4874d00             -mov byte ptr [0x4d87b4], al
    app->getMemory<x86::reg8>(x86::reg32(5081012) /* 0x4d87b4 */) = cpu.al;
L_0x0046b673:
    // 0046b673  6683f903               +cmp cx, 3
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b677  0f8549020000           -jne 0x46b8c6
    if (!cpu.flags.zf)
    {
        goto L_0x0046b8c6;
    }
L_0x0046b67d:
    // 0046b67d  6683fa07               +cmp dx, 7
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
    // 0046b681  0f8e49020000           -jle 0x46b8d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b8d0;
    }
    // 0046b687  c70578a64c0014de4b00   -mov dword ptr [0x4ca678], 0x4bde14
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = 4972052 /*0x4bde14*/;
    // 0046b691  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046b694  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b695  0fbfc1                 -movsx eax, cx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.cx));
    // 0046b698  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b699  bd99000000             -mov ebp, 0x99
    cpu.ebp = 153 /*0x99*/;
L_0x0046b69e:
    // 0046b69e  6830de4b00             -push 0x4bde30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972080 /*0x4bde30*/;
    cpu.esp -= 4;
    // 0046b6a3  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 0046b6a9  e8d2e70000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0046b6ae  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0046b6b1:
    // 0046b6b1  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b6ba  0f845e020000           -je 0x46b91e
    if (cpu.flags.zf)
    {
        goto L_0x0046b91e;
    }
    // 0046b6c0  0fb62ddd004e00         -movzx ebp, byte ptr [0x4e00dd]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */));
    // 0046b6c7  0fbfc1                 -movsx eax, cx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.cx));
    // 0046b6ca  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b6cd  39e8                   +cmp eax, ebp
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
    // 0046b6cf  0f8d49020000           -jge 0x46b91e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b91e;
    }
    // 0046b6d5  833d34f54d0000         +cmp dword ptr [0x4df534], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b6dc  0f853c020000           -jne 0x46b91e
    if (!cpu.flags.zf)
    {
        goto L_0x0046b91e;
    }
    // 0046b6e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046b6e5  6683fa01               +cmp dx, 1
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b6e9  0f840d020000           -je 0x46b8fc
    if (cpu.flags.zf)
    {
        goto L_0x0046b8fc;
    }
    // 0046b6ef  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046b6f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b6f3  8bac0404010000         -mov ebp, dword ptr [esp + eax + 0x104]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */ + cpu.eax * 1);
    // 0046b6fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b6fb  6854de4b00             -push 0x4bde54
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972116 /*0x4bde54*/;
    cpu.esp -= 4;
    // 0046b700  8d842448010000         -lea eax, [esp + 0x148]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 0046b707  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b708  e8d4080100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046b70d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0046b710:
    // 0046b710  8d84243c010000         -lea eax, [esp + 0x13c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 0046b717  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b718  a1f0074e00             -mov eax, dword ptr [0x4e07f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113840) /* 0x4e07f0 */);
    // 0046b71d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b71e  6860de4b00             -push 0x4bde60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972128 /*0x4bde60*/;
    cpu.esp -= 4;
L_0x0046b723:
    // 0046b723  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b727  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b728  e8b4080100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046b72d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b730  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046b732  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b734  e83f220100             -call 0x47d978
    cpu.esp -= 4;
    sub_47d978(app, cpu);
    if (cpu.terminate) return;
    // 0046b739  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046b73b  6683fb14               +cmp bx, 0x14
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20 /*0x14*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b73f  0f8fc3fdffff           -jg 0x46b508
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046b508;
    }
    // 0046b745  e991feffff             -jmp 0x46b5db
    goto L_0x0046b5db;
L_0x0046b74a:
    // 0046b74a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046b74c  e983feffff             -jmp 0x46b5d4
    goto L_0x0046b5d4;
L_0x0046b751:
    // 0046b751  0f848cfeffff           -je 0x46b5e3
    if (cpu.flags.zf)
    {
        goto L_0x0046b5e3;
    }
    // 0046b757  e898c70000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 0046b75c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b75e  ba7cde4b00             -mov edx, 0x4bde7c
    cpu.edx = 4972156 /*0x4bde7c*/;
    // 0046b763  e888ca0000             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0046b768  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046b76a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b76c  e8e7d10000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046b771  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b773  e888dc0000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
    // 0046b778  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b781  0f85b0010000           -jne 0x46b937
    if (!cpu.flags.zf)
    {
        goto L_0x0046b937;
    }
L_0x0046b787:
    // 0046b787  8b9424ac010000         -mov edx, dword ptr [esp + 0x1ac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 0046b78e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046b790  8b949494010000         -mov edx, dword ptr [esp + edx*4 + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */ + cpu.edx * 4);
    // 0046b797  e8bcd10000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046b79c  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046b79f  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046b7a2  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0046b7a5  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046b7a8  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0046b7ab  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046b7ae  e84ddc0000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
L_0x0046b7b3:
    // 0046b7b3  e864c70000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0046b7b8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046b7ba  7407                   -je 0x46b7c3
    if (cpu.flags.zf)
    {
        goto L_0x0046b7c3;
    }
    // 0046b7bc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046b7be  e8c9ee0000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0046b7c3:
    // 0046b7c3  8b8c24b0010000         -mov ecx, dword ptr [esp + 0x1b0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
    // 0046b7ca  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0046b7cd  0f858b010000           -jne 0x46b95e
    if (!cpu.flags.zf)
    {
        goto L_0x0046b95e;
    }
L_0x0046b7d3:
    // 0046b7d3  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046b7da  0f8528fdffff           -jne 0x46b508
    if (!cpu.flags.zf)
    {
        goto L_0x0046b508;
    }
    // 0046b7e0  a13cf54d00             -mov eax, dword ptr [0x4df53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 0046b7e5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046b7ea  e8b17bffff             -call 0x4633a0
    cpu.esp -= 4;
    sub_4633a0(app, cpu);
    if (cpu.terminate) return;
    // 0046b7ef  890dd4944c00           -mov dword ptr [0x4c94d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5018836) /* 0x4c94d4 */) = cpu.ecx;
    // 0046b7f5  81c4b8010000           -add esp, 0x1b8
    (cpu.esp) += x86::reg32(x86::sreg32(440 /*0x1b8*/));
    // 0046b7fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b800  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b801  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b802:
    // 0046b802  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046b804  8a0dfa004e00           -mov cl, byte ptr [0x4e00fa]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5112058) /* 0x4e00fa */);
    // 0046b80a  e916feffff             -jmp 0x46b625
    goto L_0x0046b625;
L_0x0046b80f:
    // 0046b80f  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b816  7542                   -jne 0x46b85a
    if (!cpu.flags.zf)
    {
        goto L_0x0046b85a;
    }
    // 0046b818  6683bc24b001000001     +cmp word ptr [esp + 0x1b0], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b821  7537                   -jne 0x46b85a
    if (!cpu.flags.zf)
    {
        goto L_0x0046b85a;
    }
    // 0046b823  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b825  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b827  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b829  8a0dfa004e00           -mov cl, byte ptr [0x4e00fa]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5112058) /* 0x4e00fa */);
    // 0046b82f  a0dd004e00             -mov al, byte ptr [0x4e00dd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046b834  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0046b836  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b839  39c2                   +cmp edx, eax
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
    // 0046b83b  0f8ce4fdffff           -jl 0x46b625
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b625;
    }
    // 0046b841  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b843  8a15df004e00           -mov dl, byte ptr [0x4e00df]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112031) /* 0x4e00df */);
    // 0046b849  39c2                   +cmp edx, eax
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
    // 0046b84b  0f8dd4fdffff           -jge 0x46b625
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b625;
    }
    // 0046b851  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046b853  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046b855  e9cbfdffff             -jmp 0x46b625
    goto L_0x0046b625;
L_0x0046b85a:
    // 0046b85a  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b861  0f85b6fdffff           -jne 0x46b61d
    if (!cpu.flags.zf)
    {
        goto L_0x0046b61d;
    }
    // 0046b867  6683bc24b001000000     +cmp word ptr [esp + 0x1b0], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b870  0f85a7fdffff           -jne 0x46b61d
    if (!cpu.flags.zf)
    {
        goto L_0x0046b61d;
    }
    // 0046b876  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b878  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b87a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b87c  8a0ddf004e00           -mov cl, byte ptr [0x4e00df]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5112031) /* 0x4e00df */);
    // 0046b882  a0dd004e00             -mov al, byte ptr [0x4e00dd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046b887  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0046b889  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b88c  39c2                   +cmp edx, eax
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
    // 0046b88e  0f8c91fdffff           -jl 0x46b625
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b625;
    }
    // 0046b894  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b896  8a15fa004e00           -mov dl, byte ptr [0x4e00fa]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112058) /* 0x4e00fa */);
    // 0046b89c  39c2                   +cmp edx, eax
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
    // 0046b89e  0f8d81fdffff           -jge 0x46b625
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b625;
    }
    // 0046b8a4  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046b8a6  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046b8a8  e978fdffff             -jmp 0x46b625
    goto L_0x0046b625;
L_0x0046b8ad:
    // 0046b8ad  6683f905               +cmp cx, 5
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b8b1  0f8478fdffff           -je 0x46b62f
    if (cpu.flags.zf)
    {
        goto L_0x0046b62f;
    }
    // 0046b8b7  e978fdffff             -jmp 0x46b634
    goto L_0x0046b634;
L_0x0046b8bc:
    // 0046b8bc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046b8c1  e9adfdffff             -jmp 0x46b673
    goto L_0x0046b673;
L_0x0046b8c6:
    // 0046b8c6  6683f905               +cmp cx, 5
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b8ca  0f84adfdffff           -je 0x46b67d
    if (cpu.flags.zf)
    {
        goto L_0x0046b67d;
    }
L_0x0046b8d0:
    // 0046b8d0  6683fa01               +cmp dx, 1
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b8d4  7c0a                   -jl 0x46b8e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b8e0;
    }
    // 0046b8d6  6683fa08               +cmp dx, 8
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
    // 0046b8da  0f8ed1fdffff           -jle 0x46b6b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b6b1;
    }
L_0x0046b8e0:
    // 0046b8e0  c70578a64c0014de4b00   -mov dword ptr [0x4ca678], 0x4bde14
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = 4972052 /*0x4bde14*/;
    // 0046b8ea  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046b8ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b8ee  0fbfc1                 -movsx eax, cx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.cx));
    // 0046b8f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b8f2  bd9d000000             -mov ebp, 0x9d
    cpu.ebp = 157 /*0x9d*/;
    // 0046b8f7  e9a2fdffff             -jmp 0x46b69e
    goto L_0x0046b69e;
L_0x0046b8fc:
    // 0046b8fc  8b940400010000         -mov edx, dword ptr [esp + eax + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */ + cpu.eax * 1);
    // 0046b903  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b904  685cde4b00             -push 0x4bde5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972124 /*0x4bde5c*/;
    cpu.esp -= 4;
    // 0046b909  8d842444010000         -lea eax, [esp + 0x144]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 0046b910  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b911  e8cb060100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046b916  83c40c                 +add esp, 0xc
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
    // 0046b919  e9f2fdffff             -jmp 0x46b710
    goto L_0x0046b710;
L_0x0046b91e:
    // 0046b91e  8b943c70010000         -mov edx, dword ptr [esp + edi + 0x170]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */ + cpu.edi * 1);
    // 0046b925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b926  8b2db8074e00           -mov ebp, dword ptr [0x4e07b8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113784) /* 0x4e07b8 */);
    // 0046b92c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b92d  686cde4b00             -push 0x4bde6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972140 /*0x4bde6c*/;
    cpu.esp -= 4;
    // 0046b932  e9ecfdffff             -jmp 0x46b723
    goto L_0x0046b723;
L_0x0046b937:
    // 0046b937  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b939  a0dd004e00             -mov al, byte ptr [0x4e00dd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046b93e  0fbfd1                 -movsx edx, cx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.cx));
    // 0046b941  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b944  39c2                   +cmp edx, eax
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
    // 0046b946  0f8d3bfeffff           -jge 0x46b787
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b787;
    }
    // 0046b94c  833d34f54d0000         +cmp dword ptr [0x4df534], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b953  0f852efeffff           -jne 0x46b787
    if (!cpu.flags.zf)
    {
        goto L_0x0046b787;
    }
    // 0046b959  e955feffff             -jmp 0x46b7b3
    goto L_0x0046b7b3;
L_0x0046b95e:
    // 0046b95e  833dd4944c0000         +cmp dword ptr [0x4c94d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018836) /* 0x4c94d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b965  750a                   -jne 0x46b971
    if (!cpu.flags.zf)
    {
        goto L_0x0046b971;
    }
    // 0046b967  6683f902               +cmp cx, 2
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b96b  0f8462feffff           -je 0x46b7d3
    if (cpu.flags.zf)
    {
        goto L_0x0046b7d3;
    }
L_0x0046b971:
    // 0046b971  833d34f54d0000         +cmp dword ptr [0x4df534], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b978  0f8555feffff           -jne 0x46b7d3
    if (!cpu.flags.zf)
    {
        goto L_0x0046b7d3;
    }
    // 0046b97e  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b987  751d                   -jne 0x46b9a6
    if (!cpu.flags.zf)
    {
        goto L_0x0046b9a6;
    }
    // 0046b989  833d28f54d0004         +cmp dword ptr [0x4df528], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b990  7514                   -jne 0x46b9a6
    if (!cpu.flags.zf)
    {
        goto L_0x0046b9a6;
    }
    // 0046b992  a12cf54d00             -mov eax, dword ptr [0x4df52c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0046b997  66833c45ba024e0024     +cmp word ptr [eax*2 + 0x4e02ba], 0x24
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5112506) /* 0x4e02ba */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(36 /*0x24*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b9a0  0f842dfeffff           -je 0x46b7d3
    if (cpu.flags.zf)
    {
        goto L_0x0046b7d3;
    }
L_0x0046b9a6:
    // 0046b9a6  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b9af  752d                   -jne 0x46b9de
    if (!cpu.flags.zf)
    {
        goto L_0x0046b9de;
    }
    // 0046b9b1  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b9b8  7524                   -jne 0x46b9de
    if (!cpu.flags.zf)
    {
        goto L_0x0046b9de;
    }
    // 0046b9ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b9bc  a0dd004e00             -mov al, byte ptr [0x4e00dd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046b9c1  8b3d90f54d00           -mov edi, dword ptr [0x4df590]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109136) /* 0x4df590 */);
    // 0046b9c7  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b9ca  39f8                   +cmp eax, edi
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
    // 0046b9cc  0f8e01feffff           -jle 0x46b7d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b7d3;
    }
    // 0046b9d2  3b05d0f54d00           +cmp eax, dword ptr [0x4df5d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109200) /* 0x4df5d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b9d8  0f8ef5fdffff           -jle 0x46b7d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b7d3;
    }
L_0x0046b9de:
    // 0046b9de  6683bc24b001000002     +cmp word ptr [esp + 0x1b0], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(432) /* 0x1b0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b9e7  0f851bfbffff           -jne 0x46b508
    if (!cpu.flags.zf)
    {
        goto L_0x0046b508;
    }
    // 0046b9ed  833d28f54d0001         +cmp dword ptr [0x4df528], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b9f4  0f8d0efbffff           -jge 0x46b508
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b508;
    }
    // 0046b9fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b9fc  a0dd004e00             -mov al, byte ptr [0x4e00dd]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5112029) /* 0x4e00dd */);
    // 0046ba01  8b1590f54d00           -mov edx, dword ptr [0x4df590]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109136) /* 0x4df590 */);
    // 0046ba07  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046ba0a  39d0                   +cmp eax, edx
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
    // 0046ba0c  0f8ec1fdffff           -jle 0x46b7d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b7d3;
    }
    // 0046ba12  81c4b8010000           -add esp, 0x1b8
    (cpu.esp) += x86::reg32(x86::sreg32(440 /*0x1b8*/));
    // 0046ba18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
/* data blob: 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 */
void Application::sub_46ba60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ba60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ba61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ba62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ba63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ba64  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046ba66  8b1568a45100           -mov edx, dword ptr [0x51a468]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5350504) /* 0x51a468 */);
    // 0046ba6c  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046ba73  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ba75  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046ba78  be74a45100             -mov esi, 0x51a474
    cpu.esi = 5350516 /*0x51a474*/;
    // 0046ba7d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ba7f  b91d000000             -mov ecx, 0x1d
    cpu.ecx = 29 /*0x1d*/;
    // 0046ba84  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ba86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ba87  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ba89  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ba8c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ba8e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ba90  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ba93  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ba95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba96  8b1568a45100           -mov edx, dword ptr [0x51a468]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5350504) /* 0x51a468 */);
    // 0046ba9c  42                     -inc edx
    (cpu.edx)++;
    // 0046ba9d  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0046baa2  891568a45100           -mov dword ptr [0x51a468], edx
    app->getMemory<x86::reg32>(x86::reg32(5350504) /* 0x51a468 */) = cpu.edx;
    // 0046baa8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046baaa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046baad  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046baaf  ff0d70a45100           -dec dword ptr [0x51a470]
    (app->getMemory<x86::reg32>(x86::reg32(5350512) /* 0x51a470 */))--;
    // 0046bab5  891568a45100           -mov dword ptr [0x51a468], edx
    app->getMemory<x86::reg32>(x86::reg32(5350504) /* 0x51a468 */) = cpu.edx;
    // 0046babb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046babc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046babd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046babe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046babf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46bac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bac3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bac4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046bac6  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046bac8  8b156ca45100           -mov edx, dword ptr [0x51a46c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5350508) /* 0x51a46c */);
    // 0046bace  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046bad5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bad7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bada  bf74a45100             -mov edi, 0x51a474
    cpu.edi = 5350516 /*0x51a474*/;
    // 0046badf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046bae1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bae3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046bae4:
    // 0046bae4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046bae6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046bae8  3c00                   +cmp al, 0
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
    // 0046baea  7410                   -je 0x46bafc
    if (cpu.flags.zf)
    {
        goto L_0x0046bafc;
    }
    // 0046baec  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046baef  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046baf2  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046baf5  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046baf8  3c00                   +cmp al, 0
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
    // 0046bafa  75e8                   -jne 0x46bae4
    if (!cpu.flags.zf)
    {
        goto L_0x0046bae4;
    }
L_0x0046bafc:
    // 0046bafc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bafd  8b156ca45100           -mov edx, dword ptr [0x51a46c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5350508) /* 0x51a46c */);
    // 0046bb03  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046bb0a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bb0c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bb0f  bf74a45100             -mov edi, 0x51a474
    cpu.edi = 5350516 /*0x51a474*/;
    // 0046bb14  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046bb16  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0046bb1b  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bb1d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046bb1f  83c709                 -add edi, 9
    (cpu.edi) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0046bb22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bb23  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046bb25  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046bb28  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046bb2a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046bb2c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046bb2f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046bb31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb32  8b156ca45100           -mov edx, dword ptr [0x51a46c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5350508) /* 0x51a46c */);
    // 0046bb38  42                     -inc edx
    (cpu.edx)++;
    // 0046bb39  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0046bb3e  89156ca45100           -mov dword ptr [0x51a46c], edx
    app->getMemory<x86::reg32>(x86::reg32(5350508) /* 0x51a46c */) = cpu.edx;
    // 0046bb44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046bb46  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046bb49  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046bb4b  ff0570a45100           -inc dword ptr [0x51a470]
    (app->getMemory<x86::reg32>(x86::reg32(5350512) /* 0x51a470 */))++;
    // 0046bb51  89156ca45100           -mov dword ptr [0x51a46c], edx
    app->getMemory<x86::reg32>(x86::reg32(5350508) /* 0x51a46c */) = cpu.edx;
    // 0046bb57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46bb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bb60  833d70a4510000         +cmp dword ptr [0x51a470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350512) /* 0x51a470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bb67  7403                   -je 0x46bb6c
    if (cpu.flags.zf)
    {
        goto L_0x0046bb6c;
    }
    // 0046bb69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bb6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bb6c:
    // 0046bb6c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bb71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bb80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bb81  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bb83  891568a45100           -mov dword ptr [0x51a468], edx
    app->getMemory<x86::reg32>(x86::reg32(5350504) /* 0x51a468 */) = cpu.edx;
    // 0046bb89  89156ca45100           -mov dword ptr [0x51a46c], edx
    app->getMemory<x86::reg32>(x86::reg32(5350508) /* 0x51a46c */) = cpu.edx;
    // 0046bb8f  891570a45100           -mov dword ptr [0x51a470], edx
    app->getMemory<x86::reg32>(x86::reg32(5350512) /* 0x51a470 */) = cpu.edx;
    // 0046bb95  89155ca55100           -mov dword ptr [0x51a55c], edx
    app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */) = cpu.edx;
    // 0046bb9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46bba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bba2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bba3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bba4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bba5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046bba7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bba9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0046bbab:
    // 0046bbab  8b91e0a25100           -mov edx, dword ptr [ecx + 0x51a2e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5350112) /* 0x51a2e0 */);
    // 0046bbb1  39d7                   +cmp edi, edx
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
    // 0046bbb3  755f                   -jne 0x46bc14
    if (!cpu.flags.zf)
    {
        goto L_0x0046bc14;
    }
L_0x0046bbb5:
    // 0046bbb5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046bbb8  83f91c                 +cmp ecx, 0x1c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bbbb  7cee                   -jl 0x46bbab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046bbab;
    }
    // 0046bbbd  8b1de0a25100           -mov ebx, dword ptr [0x51a2e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5350112) /* 0x51a2e0 */);
    // 0046bbc3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bbc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bbc7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046bbc9  7412                   -je 0x46bbdd
    if (cpu.flags.zf)
    {
        goto L_0x0046bbdd;
    }
L_0x0046bbcb:
    // 0046bbcb  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046bbce  40                     -inc eax
    (cpu.eax)++;
    // 0046bbcf  83f91c                 +cmp ecx, 0x1c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bbd2  7d52                   -jge 0x46bc26
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046bc26;
    }
    // 0046bbd4  83b9e0a2510000         +cmp dword ptr [ecx + 0x51a2e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5350112) /* 0x51a2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bbdb  75ee                   -jne 0x46bbcb
    if (!cpu.flags.zf)
    {
        goto L_0x0046bbcb;
    }
L_0x0046bbdd:
    // 0046bbdd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bbdf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bbe2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bbe4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bbe7  05fca25100             -add eax, 0x51a2fc
    (cpu.eax) += x86::reg32(x86::sreg32(5350140 /*0x51a2fc*/));
    // 0046bbec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046bbee  8981e0a25100           -mov dword ptr [ecx + 0x51a2e0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5350112) /* 0x51a2e0 */) = cpu.eax;
    // 0046bbf4  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0046bbf9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bbfa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046bbfc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046bbff  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046bc01  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046bc03  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046bc06  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046bc08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc09  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bc0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bc14:
    // 0046bc14  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046bc19  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046bc1b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046bc1d  e84e630100             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 0046bc22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bc24  748f                   -je 0x46bbb5
    if (cpu.flags.zf)
    {
        goto L_0x0046bbb5;
    }
L_0x0046bc26:
    // 0046bc26  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bc28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46bc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bc30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bc31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bc32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bc33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bc34  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046bc36  8b0de8944c00           -mov ecx, dword ptr [0x4c94e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bc3c  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046bc43  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bc45  8b0df0944c00           -mov ecx, dword ptr [0x4c94f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046bc4b  807c810f00             +cmp byte ptr [ecx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046bc50  7514                   -jne 0x46bc66
    if (!cpu.flags.zf)
    {
        goto L_0x0046bc66;
    }
    // 0046bc52  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046bc54:
    // 0046bc54  8b91e0a25100           -mov edx, dword ptr [ecx + 0x51a2e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5350112) /* 0x51a2e0 */);
    // 0046bc5a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046bc5c  750d                   -jne 0x46bc6b
    if (!cpu.flags.zf)
    {
        goto L_0x0046bc6b;
    }
L_0x0046bc5e:
    // 0046bc5e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046bc61  83f91c                 +cmp ecx, 0x1c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bc64  75ee                   -jne 0x46bc54
    if (!cpu.flags.zf)
    {
        goto L_0x0046bc54;
    }
L_0x0046bc66:
    // 0046bc66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bc6b:
    // 0046bc6b  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046bc70  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046bc72  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046bc74  e8f7620100             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 0046bc79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bc7b  74e1                   -je 0x46bc5e
    if (cpu.flags.zf)
    {
        goto L_0x0046bc5e;
    }
    // 0046bc7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bc7f  8999e0a25100           -mov dword ptr [ecx + 0x51a2e0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5350112) /* 0x51a2e0 */) = cpu.ebx;
    // 0046bc85  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046bc88  83f91c                 +cmp ecx, 0x1c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bc8b  75c7                   -jne 0x46bc54
    if (!cpu.flags.zf)
    {
        goto L_0x0046bc54;
    }
    // 0046bc8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bca0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bca1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046bca3:
    // 0046bca3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046bca6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bca8  8990dca25100           -mov dword ptr [eax + 0x51a2dc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5350108) /* 0x51a2dc */) = cpu.edx;
    // 0046bcae  83f81c                 +cmp eax, 0x1c
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
    // 0046bcb1  75f0                   -jne 0x46bca3
    if (!cpu.flags.zf)
    {
        goto L_0x0046bca3;
    }
    // 0046bcb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bcb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bcc0  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bcc3  833de0944c0000         +cmp dword ptr [0x4c94e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018848) /* 0x4c94e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bcca  7509                   -jne 0x46bcd5
    if (!cpu.flags.zf)
    {
        goto L_0x0046bcd5;
    }
    // 0046bccc  833d5ca5510007         +cmp dword ptr [0x51a55c], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bcd3  7c06                   -jl 0x46bcdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046bcdb;
    }
L_0x0046bcd5:
    // 0046bcd5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bcd7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bcda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bcdb:
    // 0046bcdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046bcdd  e8befeffff             -call 0x46bba0
    cpu.esp -= 4;
    sub_46bba0(app, cpu);
    if (cpu.terminate) return;
    // 0046bce2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bce4  7509                   -jne 0x46bcef
    if (!cpu.flags.zf)
    {
        goto L_0x0046bcef;
    }
    // 0046bce6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bceb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bcee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bcef:
    // 0046bcef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bcf0  8b355ca55100           -mov esi, dword ptr [0x51a55c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */);
    // 0046bcf6  46                     -inc esi
    (cpu.esi)++;
    // 0046bcf7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bcf8  68b4e24b00             -push 0x4be2b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4973236 /*0x4be2b4*/;
    cpu.esp -= 4;
    // 0046bcfd  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046bd01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046bd02  89355ca55100           -mov dword ptr [0x51a55c], esi
    app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */) = cpu.esi;
    // 0046bd08  e8d4020100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046bd0d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bd10  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046bd14  e8a7fdffff             -call 0x46bac0
    cpu.esp -= 4;
    sub_46bac0(app, cpu);
    if (cpu.terminate) return;
    // 0046bd19  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bd1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd1f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bd22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bd30  833de0944c0000         +cmp dword ptr [0x4c94e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018848) /* 0x4c94e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bd37  750b                   -jne 0x46bd44
    if (!cpu.flags.zf)
    {
        goto L_0x0046bd44;
    }
    // 0046bd39  8b1d5ca55100           -mov ebx, dword ptr [0x51a55c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */);
    // 0046bd3f  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bd42  7c03                   -jl 0x46bd47
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046bd47;
    }
L_0x0046bd44:
    // 0046bd44  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bd46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bd47:
    // 0046bd47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bd48  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0046bd4b  8d4248                 -lea eax, [edx + 0x48]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0046bd4e  89355ca55100           -mov dword ptr [0x51a55c], esi
    app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */) = cpu.esi;
    // 0046bd54  e867fdffff             -call 0x46bac0
    cpu.esp -= 4;
    sub_46bac0(app, cpu);
    if (cpu.terminate) return;
    // 0046bd59  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bd5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46bd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bd60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bd61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bd62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046bd63  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046bd66  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046bd6a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046bd6d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046bd6f  66833df8944c0014       +cmp word ptr [0x4c94f8], 0x14
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5018872) /* 0x4c94f8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20 /*0x14*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046bd77  0f8dc9000000           -jge 0x46be46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046be46;
    }
    // 0046bd7d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046bd7f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046bd81:
    // 0046bd81  a1f6944c00             -mov eax, dword ptr [0x4c94f6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018870) /* 0x4c94f6 */);
    // 0046bd86  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046bd89  39c6                   +cmp esi, eax
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
    // 0046bd8b  0f8c86000000           -jl 0x46be17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046be17;
    }
    // 0046bd91  8b3dfc944c00           -mov edi, dword ptr [0x4c94fc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046bd97  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046bd9a  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0046bd9d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bd9f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046bda2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046bda3:
    // 0046bda3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046bda5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046bda7  3c00                   +cmp al, 0
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
    // 0046bda9  7410                   -je 0x46bdbb
    if (cpu.flags.zf)
    {
        goto L_0x0046bdbb;
    }
    // 0046bdab  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046bdae  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046bdb1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046bdb4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046bdb7  3c00                   +cmp al, 0
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
    // 0046bdb9  75e8                   -jne 0x46bda3
    if (!cpu.flags.zf)
    {
        goto L_0x0046bda3;
    }
L_0x0046bdbb:
    // 0046bdbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bdbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046bdbe:
    // 0046bdbe  8b3df6944c00           -mov edi, dword ptr [0x4c94f6]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5018870) /* 0x4c94f6 */);
    // 0046bdc4  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0046bdc7  8b1dfc944c00           -mov ebx, dword ptr [0x4c94fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046bdcd  c1e706                 -shl edi, 6
    cpu.edi <<= 6 /*0x6*/ % 32;
    // 0046bdd0  40                     -inc eax
    (cpu.eax)++;
    // 0046bdd1  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046bdd3  8b7a20                 -mov edi, dword ptr [edx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0046bdd6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046bdd9  897c8318               -mov dword ptr [ebx + eax*4 + 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */ + cpu.eax * 4) = cpu.edi;
    // 0046bddd  83f804                 +cmp eax, 4
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
    // 0046bde0  7cdc                   -jl 0x46bdbe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046bdbe;
    }
    // 0046bde2  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0046bde7  8d7b2c                 -lea edi, [ebx + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */);
    // 0046bdea  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0046bdec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bded  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046bdef  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046bdf2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046bdf4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046bdf6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046bdf9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046bdfb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bdfc  668b1df8944c00         -mov bx, word ptr [0x4c94f8]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5018872) /* 0x4c94f8 */);
    // 0046be03  43                     -inc ebx
    (cpu.ebx)++;
    // 0046be04  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046be09  66891df8944c00         -mov word ptr [0x4c94f8], bx
    app->getMemory<x86::reg16>(x86::reg32(5018872) /* 0x4c94f8 */) = cpu.bx;
    // 0046be10  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046be13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046be17:
    // 0046be17  8b1dfc944c00           -mov ebx, dword ptr [0x4c94fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046be1d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046be21  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046be23  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046be25  83c32c                 -add ebx, 0x2c
    (cpu.ebx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046be28  e843610100             -call 0x481f70
    cpu.esp -= 4;
    sub_481f70(app, cpu);
    if (cpu.terminate) return;
    // 0046be2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046be2f  7509                   -jne 0x46be3a
    if (!cpu.flags.zf)
    {
        goto L_0x0046be3a;
    }
    // 0046be31  46                     -inc esi
    (cpu.esi)++;
    // 0046be32  83c740                 +add edi, 0x40
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046be35  e947ffffff             -jmp 0x46bd81
    goto L_0x0046bd81;
L_0x0046be3a:
    // 0046be3a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046be3f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046be42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046be46:
    // 0046be46  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046be48  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046be4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46be50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046be51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046be52  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046be54  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046be56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046be58  e8e3dd0000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0046be5d  833df0944c0000         +cmp dword ptr [0x4c94f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046be64  7409                   -je 0x46be6f
    if (cpu.flags.zf)
    {
        goto L_0x0046be6f;
    }
    // 0046be66  833de8944c000a         +cmp dword ptr [0x4c94e8], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046be6d  7c05                   -jl 0x46be74
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046be74;
    }
L_0x0046be6f:
    // 0046be6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046be71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046be74:
    // 0046be74  ba34e24b00             -mov edx, 0x4be234
    cpu.edx = 4973108 /*0x4be234*/;
    // 0046be79  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046be7b  e847520200             -call 0x4910c7
    cpu.esp -= 4;
    sub_4910c7(app, cpu);
    if (cpu.terminate) return;
    // 0046be80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046be82  0f84e0000000           -je 0x46bf68
    if (cpu.flags.zf)
    {
        goto L_0x0046bf68;
    }
    // 0046be88  baecde4b00             -mov edx, 0x4bdeec
    cpu.edx = 4972268 /*0x4bdeec*/;
    // 0046be8d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046be8f  e833520200             -call 0x4910c7
    cpu.esp -= 4;
    sub_4910c7(app, cpu);
    if (cpu.terminate) return;
    // 0046be94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046be96  0f8493000000           -je 0x46bf2f
    if (cpu.flags.zf)
    {
        goto L_0x0046bf2f;
    }
    // 0046be9c  8b35e8944c00           -mov esi, dword ptr [0x4c94e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bea2  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046bea9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046beab  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046beb1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046beb4  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0046beb9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046bebb  ba40e24b00             -mov edx, 0x4be240
    cpu.edx = 4973120 /*0x4be240*/;
L_0x0046bec0:
    // 0046bec0  e8f7000100             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
L_0x0046bec5:
    // 0046bec5  a1e8944c00             -mov eax, dword ptr [0x4c94e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046beca  8d34c500000000         -lea esi, [eax*8]
    cpu.esi = x86::reg32(cpu.eax * 8);
    // 0046bed1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bed3  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046bed8  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046bedb  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046bedd  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046bee2  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046bee5  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0046bee7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046bee9  c640fe00               -mov byte ptr [eax - 2], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-2) /* -0x2 */) = 0 /*0x0*/;
    // 0046beed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046beee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046bef0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046bef3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046bef5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046bef7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046befa  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046befc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046befd  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bf03  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046bf0a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bf0c  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046bf11  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046bf14  8b1de8944c00           -mov ebx, dword ptr [0x4c94e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bf1a  c644020f01             -mov byte ptr [edx + eax + 0xf], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 1) = 1 /*0x1*/;
    // 0046bf1f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bf24  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bf26  891de8944c00           -mov dword ptr [0x4c94e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */) = cpu.ebx;
    // 0046bf2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bf2f:
    // 0046bf2f  ba14e24b00             -mov edx, 0x4be214
    cpu.edx = 4973076 /*0x4be214*/;
    // 0046bf34  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046bf36  e88c510200             -call 0x4910c7
    cpu.esp -= 4;
    sub_4910c7(app, cpu);
    if (cpu.terminate) return;
    // 0046bf3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bf3d  7486                   -je 0x46bec5
    if (cpu.flags.zf)
    {
        goto L_0x0046bec5;
    }
    // 0046bf3f  8b35e8944c00           -mov esi, dword ptr [0x4c94e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bf45  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046bf4c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046bf4e  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046bf54  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bf57  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0046bf5c  01d0                   +add eax, edx
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
    // 0046bf5e  ba50e24b00             -mov edx, 0x4be250
    cpu.edx = 4973136 /*0x4be250*/;
    // 0046bf63  e958ffffff             -jmp 0x46bec0
    goto L_0x0046bec0;
L_0x0046bf68:
    // 0046bf68  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bf6e  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046bf75  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046bf77  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046bf7c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046bf7f  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0046bf84  01d0                   +add eax, edx
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
    // 0046bf86  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046bf88  e933ffffff             -jmp 0x46bec0
    goto L_0x0046bec0;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46bf90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bf90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bf91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bf92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bf93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046bf94  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046bf96  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046bf98  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046bf9a  ba50e04b00             -mov edx, 0x4be050
    cpu.edx = 4972624 /*0x4be050*/;
    // 0046bf9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bfa1  bb31040000             -mov ebx, 0x431
    cpu.ebx = 1073 /*0x431*/;
    // 0046bfa6  e895dc0000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0046bfab  b808e24b00             -mov eax, 0x4be208
    cpu.eax = 4973064 /*0x4be208*/;
    // 0046bfb0  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046bfb6  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 0046bfbc  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046bfc1  ba68010000             -mov edx, 0x168
    cpu.edx = 360 /*0x168*/;
    // 0046bfc6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046bfc8  e85be20000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046bfcd  a3f0944c00             -mov dword ptr [0x4c94f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */) = cpu.eax;
    // 0046bfd2  892d60a55100           -mov dword ptr [0x51a560], ebp
    app->getMemory<x86::reg32>(x86::reg32(5350752) /* 0x51a560 */) = cpu.ebp;
    // 0046bfd8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046bfda  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046bfdc  b850be4600             -mov eax, 0x46be50
    cpu.eax = 4636240 /*0x46be50*/;
    // 0046bfe1  892de8944c00           -mov dword ptr [0x4c94e8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */) = cpu.ebp;
    // 0046bfe7  e8c05c0100             -call 0x481cac
    cpu.esp -= 4;
    sub_481cac(app, cpu);
    if (cpu.terminate) return;
    // 0046bfec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046bfee  742e                   -je 0x46c01e
    if (cpu.flags.zf)
    {
        goto L_0x0046c01e;
    }
    // 0046bff0  833df4944c0000         +cmp dword ptr [0x4c94f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018868) /* 0x4c94f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bff7  752a                   -jne 0x46c023
    if (!cpu.flags.zf)
    {
        goto L_0x0046c023;
    }
L_0x0046bff9:
    // 0046bff9  a1e8944c00             -mov eax, dword ptr [0x4c94e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046bffe  a360a55100             -mov dword ptr [0x51a560], eax
    app->getMemory<x86::reg32>(x86::reg32(5350752) /* 0x51a560 */) = cpu.eax;
    // 0046c003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c005  7512                   -jne 0x46c019
    if (!cpu.flags.zf)
    {
        goto L_0x0046c019;
    }
    // 0046c007  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c00c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046c00e  e879e60000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046c013  8935f0944c00           -mov dword ptr [0x4c94f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */) = cpu.esi;
L_0x0046c019:
    // 0046c019  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
L_0x0046c01e:
    // 0046c01e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c01f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c020  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c022  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c023:
    // 0046c023  8b0de8944c00           -mov ecx, dword ptr [0x4c94e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c029  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046c030  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0046c035  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c037  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c03c  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046c03f  ba14e24b00             -mov edx, 0x4be214
    cpu.edx = 4973076 /*0x4be214*/;
    // 0046c044  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c046  e871ff0000             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0046c04b  8b0de8944c00           -mov ecx, dword ptr [0x4c94e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c051  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046c058  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c05a  8b3df0944c00           -mov edi, dword ptr [0x4c94f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c060  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046c063  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c065  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046c068  be18954c00             -mov esi, 0x4c9518
    cpu.esi = 5018904 /*0x4c9518*/;
    // 0046c06d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046c072  c647fe00               -mov byte ptr [edi - 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */) = 0 /*0x0*/;
    // 0046c076  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c077  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c079  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046c07c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c07e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046c080  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046c083  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046c085  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c086  8b0de8944c00           -mov ecx, dword ptr [0x4c94e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c08c  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046c093  01c8                   +add eax, ecx
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
    // 0046c095  8b0df0944c00           -mov ecx, dword ptr [0x4c94f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c09b  c644810f00             -mov byte ptr [ecx + eax*4 + 0xf], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */ + cpu.eax * 4) = 0 /*0x0*/;
    // 0046c0a0  ff05e8944c00           +inc dword ptr [0x4c94e8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046c0a6  e94effffff             -jmp 0x46bff9
    goto L_0x0046bff9;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c0b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c0b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c0b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c0b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c0b4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c0b6  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046c0b9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046c0c0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c0c2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046c0c5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c0c7  bbc0034e00             -mov ebx, 0x4e03c0
    cpu.ebx = 5112768 /*0x4e03c0*/;
    // 0046c0cc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046c0cf  8b1520a44c00           -mov edx, dword ptr [0x4ca420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 0046c0d5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c0d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046c0d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046c0dc  c1e202                 +shl edx, 2
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
    // 0046c0df  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046c0e1  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046c0e4  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 0046c0e9  894324                 -mov dword ptr [ebx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0046c0ec  890d50af4c00           -mov dword ptr [0x4caf50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5025616) /* 0x4caf50 */) = cpu.ecx;
    // 0046c0f2  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046c0f5  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0046c0fa  89432c                 -mov dword ptr [ebx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c0fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046c0ff  8d7b30                 -lea edi, [ebx + 0x30]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0046c102  e86956feff             -call 0x451770
    cpu.esp -= 4;
    sub_451770(app, cpu);
    if (cpu.terminate) return;
    // 0046c107  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c108  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c10a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046c10d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c10f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046c111  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046c114  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046c116  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c117  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046c119  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c11a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c11b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c11c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c11d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46c120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c120  803d7e074e0003         +cmp byte ptr [0x4e077e], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046c127  0f8594000000           -jne 0x46c1c1
    if (!cpu.flags.zf)
    {
        goto L_0x0046c1c1;
    }
    // 0046c12d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c12e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c12f  66833d78074e0000       +cmp word ptr [0x4e0778], 0
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
    // 0046c137  7456                   -je 0x46c18f
    if (cpu.flags.zf)
    {
        goto L_0x0046c18f;
    }
    // 0046c139  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046c13b:
    // 0046c13b  83bad0034e0000         +cmp dword ptr [edx + 0x4e03d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5112784) /* 0x4e03d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c142  740c                   -je 0x46c150
    if (cpu.flags.zf)
    {
        goto L_0x0046c150;
    }
    // 0046c144  b8c0034e00             -mov eax, 0x4e03c0
    cpu.eax = 5112768 /*0x4e03c0*/;
    // 0046c149  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c14b  e850020000             -call 0x46c3a0
    cpu.esp -= 4;
    sub_46c3a0(app, cpu);
    if (cpu.terminate) return;
L_0x0046c150:
    // 0046c150  83c268                 -add edx, 0x68
    (cpu.edx) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0046c153  81fad8020000           +cmp edx, 0x2d8
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
    // 0046c159  75e0                   -jne 0x46c13b
    if (!cpu.flags.zf)
    {
        goto L_0x0046c13b;
    }
    // 0046c15b  833d00954c0000         +cmp dword ptr [0x4c9500], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c162  742b                   -je 0x46c18f
    if (cpu.flags.zf)
    {
        goto L_0x0046c18f;
    }
    // 0046c164  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c16a  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046c171  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c173  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c179  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
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
    // 0046c17e  740f                   -je 0x46c18f
    if (cpu.flags.zf)
    {
        goto L_0x0046c18f;
    }
    // 0046c180  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046c185  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c18a  e8655d0100             -call 0x481ef4
    cpu.esp -= 4;
    sub_481ef4(app, cpu);
    if (cpu.terminate) return;
L_0x0046c18f:
    // 0046c18f  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c195  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046c19c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c19e  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c1a3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046c1a6  807c020f00             +cmp byte ptr [edx + eax + 0xf], 0
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
    // 0046c1ab  740a                   -je 0x46c1b7
    if (cpu.flags.zf)
    {
        goto L_0x0046c1b7;
    }
    // 0046c1ad  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c1b2  e8555d0100             -call 0x481f0c
    cpu.esp -= 4;
    sub_481f0c(app, cpu);
    if (cpu.terminate) return;
L_0x0046c1b7:
    // 0046c1b7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046c1b9  893500954c00           -mov dword ptr [0x4c9500], esi
    app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */) = cpu.esi;
    // 0046c1bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c1c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046c1c1:
    // 0046c1c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c1d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c1d1  66833d78074e0000       +cmp word ptr [0x4e0778], 0
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
    // 0046c1d9  7442                   -je 0x46c21d
    if (cpu.flags.zf)
    {
        goto L_0x0046c21d;
    }
    // 0046c1db  66833d7a074e0000       +cmp word ptr [0x4e077a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046c1e3  7538                   -jne 0x46c21d
    if (!cpu.flags.zf)
    {
        goto L_0x0046c21d;
    }
    // 0046c1e5  833d00954c0000         +cmp dword ptr [0x4c9500], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c1ec  742f                   -je 0x46c21d
    if (cpu.flags.zf)
    {
        goto L_0x0046c21d;
    }
    // 0046c1ee  803d7e074e0003         +cmp byte ptr [0x4e077e], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046c1f5  7526                   -jne 0x46c21d
    if (!cpu.flags.zf)
    {
        goto L_0x0046c21d;
    }
    // 0046c1f7  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c1fd  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046c204  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c206  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c20c  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
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
    // 0046c211  750c                   -jne 0x46c21f
    if (!cpu.flags.zf)
    {
        goto L_0x0046c21f;
    }
    // 0046c213  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c214  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c216  890d00954c00           -mov dword ptr [0x4c9500], ecx
    app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */) = cpu.ecx;
    // 0046c21c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046c21d:
    // 0046c21d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c21e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c21f:
    // 0046c21f  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c224  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c226  e8c95c0100             -call 0x481ef4
    cpu.esp -= 4;
    sub_481ef4(app, cpu);
    if (cpu.terminate) return;
    // 0046c22b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c22c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c22e  890d00954c00           -mov dword ptr [0x4c9500], ecx
    app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */) = cpu.ecx;
    // 0046c234  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c235  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c236  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c240  66833d78074e0000       +cmp word ptr [0x4e0778], 0
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
    // 0046c248  7444                   -je 0x46c28e
    if (cpu.flags.zf)
    {
        goto L_0x0046c28e;
    }
    // 0046c24a  66833d7a074e0000       +cmp word ptr [0x4e077a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046c252  753a                   -jne 0x46c28e
    if (!cpu.flags.zf)
    {
        goto L_0x0046c28e;
    }
    // 0046c254  833d00954c0000         +cmp dword ptr [0x4c9500], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c25b  7531                   -jne 0x46c28e
    if (!cpu.flags.zf)
    {
        goto L_0x0046c28e;
    }
    // 0046c25d  803d7e074e0003         +cmp byte ptr [0x4e077e], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046c264  7528                   -jne 0x46c28e
    if (!cpu.flags.zf)
    {
        goto L_0x0046c28e;
    }
    // 0046c266  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c267  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c26d  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046c274  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c276  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c27c  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
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
    // 0046c281  750c                   -jne 0x46c28f
    if (!cpu.flags.zf)
    {
        goto L_0x0046c28f;
    }
    // 0046c283  c70500954c0001000000   -mov dword ptr [0x4c9500], 1
    app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */) = 1 /*0x1*/;
    // 0046c28d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046c28e:
    // 0046c28e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c28f:
    // 0046c28f  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c294  e8675c0100             -call 0x481f00
    cpu.esp -= 4;
    sub_481f00(app, cpu);
    if (cpu.terminate) return;
    // 0046c299  c70500954c0001000000   -mov dword ptr [0x4c9500], 1
    app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */) = 1 /*0x1*/;
    // 0046c2a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c2b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c2b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c2b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c2b3  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046c2b8  bf68074e00             -mov edi, 0x4e0768
    cpu.edi = 5113704 /*0x4e0768*/;
    // 0046c2bd  8d7202                 -lea esi, [edx + 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046c2c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c2c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c2c3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046c2c6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c2c8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046c2ca  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046c2cd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046c2cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c2e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c2e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c2e2  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046c2e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c2e7  833d00954c0000         +cmp dword ptr [0x4c9500], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c2ee  7509                   -jne 0x46c2f9
    if (!cpu.flags.zf)
    {
        goto L_0x0046c2f9;
    }
    // 0046c2f0  83f807                 +cmp eax, 7
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
    // 0046c2f3  7f04                   -jg 0x46c2f9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046c2f9;
    }
    // 0046c2f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c2f7  7d06                   -jge 0x46c2ff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046c2ff;
    }
L_0x0046c2f9:
    // 0046c2f9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046c2fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c2fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c2ff:
    // 0046c2ff  a104954c00             -mov eax, dword ptr [0x4c9504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018884) /* 0x4c9504 */);
    // 0046c304  8d3c12                 -lea edi, [edx + edx]
    cpu.edi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0046c307  e8bc480100             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0046c30c  6683bf68074e0000       +cmp word ptr [edi + 0x4e0768], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(5113704) /* 0x4e0768 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046c314  7571                   -jne 0x46c387
    if (!cpu.flags.zf)
    {
        goto L_0x0046c387;
    }
    // 0046c316  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c317  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c318  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c319  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0046c31e  be68074e00             -mov esi, 0x4e0768
    cpu.esi = 5113704 /*0x4e0768*/;
    // 0046c323  8b0495a0034e00         -mov eax, dword ptr [edx*4 + 0x4e03a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5112736) /* 0x4e03a0 */ + cpu.edx * 4);
    // 0046c32a  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 0046c32f  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0046c332  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c336  e8f5f8ffff             -call 0x46bc30
    cpu.esp -= 4;
    sub_46bc30(app, cpu);
    if (cpu.terminate) return;
    // 0046c33b  a104954c00             -mov eax, dword ptr [0x4c9504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018884) /* 0x4c9504 */);
    // 0046c340  66898f68074e00         -mov word ptr [edi + 0x4e0768], cx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(5113704) /* 0x4e0768 */) = cpu.cx;
    // 0046c347  e894480100             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0046c34c  b409                   -mov ah, 9
    cpu.ah = 9 /*0x9*/;
    // 0046c34e  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046c353  8d7c240e               -lea edi, [esp + 0xe]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0046c357  8864240c               -mov byte ptr [esp + 0xc], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 0046c35b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c35c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c35e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046c361  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c363  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046c365  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046c368  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046c36a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c36b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046c370  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c372  66893544074e00         -mov word ptr [0x4e0744], si
    app->getMemory<x86::reg16>(x86::reg32(5113668) /* 0x4e0744 */) = cpu.si;
    // 0046c379  e85254feff             -call 0x4517d0
    cpu.esp -= 4;
    sub_4517d0(app, cpu);
    if (cpu.terminate) return;
    // 0046c37e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c37f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c380  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c381  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046c384  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c385  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c386  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c387:
    // 0046c387  a104954c00             -mov eax, dword ptr [0x4c9504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018884) /* 0x4c9504 */);
    // 0046c38c  e84f480100             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0046c391  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046c394  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c395  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c396  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c3a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c3a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c3a3  83781000               +cmp dword ptr [eax + 0x10], 0
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
    // 0046c3a7  7502                   -jne 0x46c3ab
    if (!cpu.flags.zf)
    {
        goto L_0x0046c3ab;
    }
    // 0046c3a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c3ab:
    // 0046c3ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c3ac  e8d74b0100             -call 0x480f88
    cpu.esp -= 4;
    sub_480f88(app, cpu);
    if (cpu.terminate) return;
    // 0046c3b1  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c3b6  83c230                 -add edx, 0x30
    (cpu.edx) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0046c3b9  e8825b0100             -call 0x481f40
    cpu.esp -= 4;
    sub_481f40(app, cpu);
    if (cpu.terminate) return;
    // 0046c3be  8b1d5ca55100           -mov ebx, dword ptr [0x51a55c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */);
    // 0046c3c4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046c3c9  4b                     -dec ebx
    (cpu.ebx)--;
    // 0046c3ca  66891544074e00         -mov word ptr [0x4e0744], dx
    app->getMemory<x86::reg16>(x86::reg32(5113668) /* 0x4e0744 */) = cpu.dx;
    // 0046c3d1  891d5ca55100           -mov dword ptr [0x51a55c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */) = cpu.ebx;
    // 0046c3d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c3e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c3e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c3e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c3e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c3e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c3e5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046c3ea  3b1d84f54d00           +cmp ebx, dword ptr [0x4df584]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c3f0  0f8d74000000           -jge 0x46c46a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046c46a;
    }
    // 0046c3f6  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0046c3fb  bd50e04b00             -mov ebp, 0x4be050
    cpu.ebp = 4972624 /*0x4be050*/;
    // 0046c400  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x0046c405:
    // 0046c405  6683ba68074e0002       +cmp word ptr [edx + 0x4e0768], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113704) /* 0x4e0768 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046c40d  754a                   -jne 0x46c459
    if (!cpu.flags.zf)
    {
        goto L_0x0046c459;
    }
    // 0046c40f  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c416  7458                   -je 0x46c470
    if (cpu.flags.zf)
    {
        goto L_0x0046c470;
    }
L_0x0046c418:
    // 0046c418  c7057ca64c00e6020000   -mov dword ptr [0x4ca67c], 0x2e6
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = 742 /*0x2e6*/;
    // 0046c422  a176074e00             -mov eax, dword ptr [0x4e0776]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113718) /* 0x4e0776 */);
    // 0046c427  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046c42a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c42b  8b352cf54d00           -mov esi, dword ptr [0x4df52c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
    // 0046c431  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c432  6814e14b00             -push 0x4be114
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972820 /*0x4be114*/;
    cpu.esp -= 4;
    // 0046c437  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 0046c43d  e83eda0000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0046c442  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0046c445:
    // 0046c445  8b81a0034e00           -mov eax, dword ptr [ecx + 0x4e03a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5112736) /* 0x4e03a0 */);
    // 0046c44b  e850ffffff             -call 0x46c3a0
    cpu.esp -= 4;
    sub_46c3a0(app, cpu);
    if (cpu.terminate) return;
    // 0046c450  66c78268074e000100     -mov word ptr [edx + 0x4e0768], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5113704) /* 0x4e0768 */) = 1 /*0x1*/;
L_0x0046c459:
    // 0046c459  8b3584f54d00           -mov esi, dword ptr [0x4df584]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 0046c45f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c462  43                     -inc ebx
    (cpu.ebx)++;
    // 0046c463  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c466  39f3                   +cmp ebx, esi
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
    // 0046c468  7c9b                   -jl 0x46c405
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c405;
    }
L_0x0046c46a:
    // 0046c46a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c46f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c470:
    // 0046c470  66833d78074e0000       +cmp word ptr [0x4e0778], 0
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
    // 0046c478  749e                   -je 0x46c418
    if (cpu.flags.zf)
    {
        goto L_0x0046c418;
    }
    // 0046c47a  ebc9                   -jmp 0x46c445
    goto L_0x0046c445;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46c480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c480  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c481  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c482  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046c485  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c487  8a257e074e00           -mov ah, byte ptr [0x4e077e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */);
    // 0046c48d  6689542420             -mov word ptr [esp + 0x20], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 0046c492  80fc03                 +cmp ah, 3
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
    // 0046c495  0f85e7000000           -jne 0x46c582
    if (!cpu.flags.zf)
    {
        goto L_0x0046c582;
    }
    // 0046c49b  66833d78074e0000       +cmp word ptr [0x4e0778], 0
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
    // 0046c4a3  0f84e1000000           -je 0x46c58a
    if (cpu.flags.zf)
    {
        goto L_0x0046c58a;
    }
    // 0046c4a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c4aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c4ab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c4ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c4ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046c4af:
    // 0046c4af  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046c4b2  6bc068                 -imul eax, eax, 0x68
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(104 /*0x68*/)));
    // 0046c4b5  8b98c4034e00           -mov ebx, dword ptr [eax + 0x4e03c4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5112772) /* 0x4e03c4 */);
    // 0046c4bb  39d9                   +cmp ecx, ebx
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
    // 0046c4bd  751c                   -jne 0x46c4db
    if (!cpu.flags.zf)
    {
        goto L_0x0046c4db;
    }
    // 0046c4bf  3b98d0034e00           +cmp ebx, dword ptr [eax + 0x4e03d0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5112784) /* 0x4e03d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c4c5  7414                   -je 0x46c4db
    if (cpu.flags.zf)
    {
        goto L_0x0046c4db;
    }
    // 0046c4c7  05c0034e00             -add eax, 0x4e03c0
    (cpu.eax) += x86::reg32(x86::sreg32(5112768 /*0x4e03c0*/));
    // 0046c4cc  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046c4d1  e8cafeffff             -call 0x46c3a0
    cpu.esp -= 4;
    sub_46c3a0(app, cpu);
    if (cpu.terminate) return;
    // 0046c4d6  6689742430             -mov word ptr [esp + 0x30], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.si;
L_0x0046c4db:
    // 0046c4db  42                     -inc edx
    (cpu.edx)++;
    // 0046c4dc  6683fa07               +cmp dx, 7
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
    // 0046c4e0  7ccd                   -jl 0x46c4af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c4af;
    }
    // 0046c4e2  bd50e04b00             -mov ebp, 0x4be050
    cpu.ebp = 4972624 /*0x4be050*/;
L_0x0046c4e7:
    // 0046c4e7  e874f6ffff             -call 0x46bb60
    cpu.esp -= 4;
    sub_46bb60(app, cpu);
    if (cpu.terminate) return;
    // 0046c4ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c4ee  0f85f9000000           -jne 0x46c5ed
    if (!cpu.flags.zf)
    {
        goto L_0x0046c5ed;
    }
    // 0046c4f4  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c4f8  e863f5ffff             -call 0x46ba60
    cpu.esp -= 4;
    sub_46ba60(app, cpu);
    if (cpu.terminate) return;
    // 0046c4fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046c4ff:
    // 0046c4ff  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046c502  6bc868                 -imul ecx, eax, 0x68
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(104 /*0x68*/)));
    // 0046c505  83b9c4034e0000         +cmp dword ptr [ecx + 0x4e03c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5112772) /* 0x4e03c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c50c  0f857f000000           -jne 0x46c591
    if (!cpu.flags.zf)
    {
        goto L_0x0046c591;
    }
    // 0046c512  bf98064e00             -mov edi, 0x4e0698
    cpu.edi = 5113496 /*0x4e0698*/;
    // 0046c517  8d04c0                 -lea eax, [eax + eax*8]
    cpu.eax = x86::reg32(cpu.eax + cpu.eax * 8);
    // 0046c51a  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c51e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c520  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046c521:
    // 0046c521  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046c523  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046c525  3c00                   +cmp al, 0
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
    // 0046c527  7410                   -je 0x46c539
    if (cpu.flags.zf)
    {
        goto L_0x0046c539;
    }
    // 0046c529  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046c52c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c52f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046c532  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c535  3c00                   +cmp al, 0
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
    // 0046c537  75e8                   -jne 0x46c521
    if (!cpu.flags.zf)
    {
        goto L_0x0046c521;
    }
L_0x0046c539:
    // 0046c539  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046c53a:
    // 0046c53a  a164d25100             -mov eax, dword ptr [0x51d264]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5362276) /* 0x51d264 */);
    // 0046c53f  b988a35100             -mov ecx, 0x51a388
    cpu.ecx = 5350280 /*0x51a388*/;
    // 0046c544  0580020000             -add eax, 0x280
    (cpu.eax) += x86::reg32(x86::sreg32(640 /*0x280*/));
    // 0046c549  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0046c54c  a3e4944c00             -mov dword ptr [0x4c94e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5018852) /* 0x4c94e4 */) = cpu.eax;
    // 0046c551  8d442419               -lea eax, [esp + 0x19]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 0046c555  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0046c55a  e851fbffff             -call 0x46c0b0
    cpu.esp -= 4;
    sub_46c0b0(app, cpu);
    if (cpu.terminate) return;
    // 0046c55f  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046c564  e8e3590100             -call 0x481f4c
    cpu.esp -= 4;
    sub_481f4c(app, cpu);
    if (cpu.terminate) return;
    // 0046c569  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c56b  7557                   -jne 0x46c5c4
    if (!cpu.flags.zf)
    {
        goto L_0x0046c5c4;
    }
    // 0046c56d  ff0d5ca55100           +dec dword ptr [0x51a55c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5350748) /* 0x51a55c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046c573  c705e4944c00ffffff0f   -mov dword ptr [0x4c94e4], 0xfffffff
    app->getMemory<x86::reg32>(x86::reg32(5018852) /* 0x4c94e4 */) = 268435455 /*0xfffffff*/;
    // 0046c57d  e965ffffff             -jmp 0x46c4e7
    goto L_0x0046c4e7;
L_0x0046c582:
    // 0046c582  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046c584:
    // 0046c584  83c424                 +add esp, 0x24
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
    // 0046c587  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c588  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c58a:
    // 0046c58a  e8514dfeff             -call 0x4512e0
    cpu.esp -= 4;
    sub_4512e0(app, cpu);
    if (cpu.terminate) return;
    // 0046c58f  ebf3                   -jmp 0x46c584
    goto L_0x0046c584;
L_0x0046c591:
    // 0046c591  6683fa07               +cmp dx, 7
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
    // 0046c595  751d                   -jne 0x46c5b4
    if (!cpu.flags.zf)
    {
        goto L_0x0046c5b4;
    }
    // 0046c597  b8bb020000             -mov eax, 0x2bb
    cpu.eax = 699 /*0x2bb*/;
    // 0046c59c  6868e04b00             -push 0x4be068
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972648 /*0x4be068*/;
    cpu.esp -= 4;
    // 0046c5a1  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 0046c5a7  a37ca64c00             -mov dword ptr [0x4ca67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.eax;
    // 0046c5ac  e8cfd80000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0046c5b1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046c5b4:
    // 0046c5b4  42                     -inc edx
    (cpu.edx)++;
    // 0046c5b5  6683fa08               +cmp dx, 8
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
    // 0046c5b9  0f8c40ffffff           -jl 0x46c4ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c4ff;
    }
    // 0046c5bf  e976ffffff             -jmp 0x46c53a
    goto L_0x0046c53a;
L_0x0046c5c4:
    // 0046c5c4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046c5c9  668b1d2a074e00         -mov bx, word ptr [0x4e072a]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5113642) /* 0x4e072a */);
    // 0046c5d0  01d3                   +add ebx, edx
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
    // 0046c5d2  6689542430             -mov word ptr [esp + 0x30], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 0046c5d7  66891d2a074e00         -mov word ptr [0x4e072a], bx
    app->getMemory<x86::reg16>(x86::reg32(5113642) /* 0x4e072a */) = cpu.bx;
    // 0046c5de  c705e4944c00ffffff0f   -mov dword ptr [0x4c94e4], 0xfffffff
    app->getMemory<x86::reg32>(x86::reg32(5018852) /* 0x4c94e4 */) = 268435455 /*0xfffffff*/;
    // 0046c5e8  e9fafeffff             -jmp 0x46c4e7
    goto L_0x0046c4e7;
L_0x0046c5ed:
    // 0046c5ed  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046c5f1  66a144074e00           -mov ax, word ptr [0x4e0744]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5113668) /* 0x4e0744 */);
    // 0046c5f7  6609c7                 +or di, ax
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.ax))));
    // 0046c5fa  66897c2430             -mov word ptr [esp + 0x30], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 0046c5ff  7405                   -je 0x46c606
    if (cpu.flags.zf)
    {
        goto L_0x0046c606;
    }
    // 0046c601  e8aa4dfeff             -call 0x4513b0
    cpu.esp -= 4;
    sub_4513b0(app, cpu);
    if (cpu.terminate) return;
L_0x0046c606:
    // 0046c606  8b44242e               -mov eax, dword ptr [esp + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(46) /* 0x2e */);
    // 0046c60a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046c60d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c60e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c60f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c610  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c611  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046c614  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c615  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c616  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c624  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c625  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046c628  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046c62a  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046c62e  be2dba4600             -mov esi, 0x46ba2d
    cpu.esi = 4635181 /*0x46ba2d*/;
    // 0046c633  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c634  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c635  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0046c637  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0046c63c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046c63e  be37ba4600             -mov esi, 0x46ba37
    cpu.esi = 4635191 /*0x46ba37*/;
    // 0046c643  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c645  8b0dec944c00           -mov ecx, dword ptr [0x4c94ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */);
    // 0046c64b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c64d  7444                   -je 0x46c693
    if (cpu.flags.zf)
    {
        goto L_0x0046c693;
    }
L_0x0046c64f:
    // 0046c64f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046c654  bb27000000             -mov ebx, 0x27
    cpu.ebx = 39 /*0x27*/;
    // 0046c659  ba0f030000             -mov edx, 0x30f
    cpu.edx = 783 /*0x30f*/;
    // 0046c65e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046c660  e8eb5df9ff             -call 0x402450
    cpu.esp -= 4;
    sub_402450(app, cpu);
    if (cpu.terminate) return;
    // 0046c665  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c667  0f8479000000           -je 0x46c6e6
    if (cpu.flags.zf)
    {
        goto L_0x0046c6e6;
    }
    // 0046c66d  b9a4a35100             -mov ecx, 0x51a3a4
    cpu.ecx = 5350308 /*0x51a3a4*/;
    // 0046c672  bb06040000             -mov ebx, 0x406
    cpu.ebx = 1030 /*0x406*/;
    // 0046c677  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046c679  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c67e  e8f9580100             -call 0x481f7c
    cpu.esp -= 4;
    sub_481f7c(app, cpu);
    if (cpu.terminate) return;
    // 0046c683  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c685  7568                   -jne 0x46c6ef
    if (!cpu.flags.zf)
    {
        goto L_0x0046c6ef;
    }
    // 0046c687  b803030000             -mov eax, 0x303
    cpu.eax = 771 /*0x303*/;
    // 0046c68c  e80f66f9ff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 0046c691  ebbc                   -jmp 0x46c64f
    goto L_0x0046c64f;
L_0x0046c693:
    // 0046c693  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c694  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046c698  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c69e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c69f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046c6a6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c6a8  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c6ad  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046c6b0  bb08954c00             -mov ebx, 0x4c9508
    cpu.ebx = 5018888 /*0x4c9508*/;
    // 0046c6b5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c6b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c6b8  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046c6bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c6bd  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c6c2  e86d560100             -call 0x481d34
    cpu.esp -= 4;
    sub_481d34(app, cpu);
    if (cpu.terminate) return;
    // 0046c6c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c6c9  740f                   -je 0x46c6da
    if (cpu.flags.zf)
    {
        goto L_0x0046c6da;
    }
    // 0046c6cb  c705ec944c0001000000   -mov dword ptr [0x4c94ec], 1
    app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */) = 1 /*0x1*/;
    // 0046c6d5  e975ffffff             -jmp 0x46c64f
    goto L_0x0046c64f;
L_0x0046c6da:
    // 0046c6da  b803030000             -mov eax, 0x303
    cpu.eax = 771 /*0x303*/;
    // 0046c6df  e8bc65f9ff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 0046c6e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046c6e6:
    // 0046c6e6  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046c6e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c6ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c6ef:
    // 0046c6ef  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0046c6f4  bea4a35100             -mov esi, 0x51a3a4
    cpu.esi = 5350308 /*0x51a3a4*/;
    // 0046c6f9  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046c6fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c6fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c6fe  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046c701  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046c703  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046c705  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046c708  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046c70a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c70b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046c710  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046c713  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c716  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c717  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c718  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c722  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c723  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c724  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c725  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c728  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046c72a  a02cba4600             -mov al, byte ptr [0x46ba2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4635180) /* 0x46ba2c */);
    // 0046c72f  bafeffffff             -mov edx, 0xfffffffe
    cpu.edx = 4294967294 /*0xfffffffe*/;
    // 0046c734  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0046c737  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046c73c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c73e  e84d50feff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 0046c743  6689152c074e00         -mov word ptr [0x4e072c], dx
    app->getMemory<x86::reg16>(x86::reg32(5113644) /* 0x4e072c */) = cpu.dx;
    // 0046c74a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046c74c  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 0046c74e  8825e0064e00           -mov byte ptr [0x4e06e0], ah
    app->getMemory<x86::reg8>(x86::reg32(5113568) /* 0x4e06e0 */) = cpu.ah;
    // 0046c754  b804030000             -mov eax, 0x304
    cpu.eax = 772 /*0x304*/;
    // 0046c759  88157e074e00           -mov byte ptr [0x4e077e], dl
    app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */) = cpu.dl;
    // 0046c75f  ba07030000             -mov edx, 0x307
    cpu.edx = 775 /*0x307*/;
    // 0046c764  66891d78074e00         -mov word ptr [0x4e0778], bx
    app->getMemory<x86::reg16>(x86::reg32(5113720) /* 0x4e0778 */) = cpu.bx;
    // 0046c76b  e8405cf9ff             -call 0x4023b0
    cpu.esp -= 4;
    sub_4023b0(app, cpu);
    if (cpu.terminate) return;
    // 0046c770  8b1de8944c00           -mov ebx, dword ptr [0x4c94e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046c776  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c778  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c77a  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0046c781  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c783  8b1df0944c00           -mov ebx, dword ptr [0x4c94f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046c789  807c830f00             +cmp byte ptr [ebx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046c78e  7424                   -je 0x46c7b4
    if (cpu.flags.zf)
    {
        goto L_0x0046c7b4;
    }
    // 0046c790  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046c792  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046c797  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046c799  e826570100             -call 0x481ec4
    cpu.esp -= 4;
    sub_481ec4(app, cpu);
    if (cpu.terminate) return;
    // 0046c79e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c7a0  0f8e7c000000           -jle 0x46c822
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c822;
    }
    // 0046c7a6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046c7a8:
    // 0046c7a8  3b0d2ca45100           +cmp ecx, dword ptr [0x51a42c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5350444) /* 0x51a42c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c7ae  0f849e000000           -je 0x46c852
    if (cpu.flags.zf)
    {
        goto L_0x0046c852;
    }
L_0x0046c7b4:
    // 0046c7b4  e8474efeff             -call 0x451600
    cpu.esp -= 4;
    sub_451600(app, cpu);
    if (cpu.terminate) return;
    // 0046c7b9  b8a4a35100             -mov eax, 0x51a3a4
    cpu.eax = 5350308 /*0x51a3a4*/;
    // 0046c7be  b988a35100             -mov ecx, 0x51a388
    cpu.ecx = 5350280 /*0x51a388*/;
    // 0046c7c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c7c5  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0046c7ca  e8e1f8ffff             -call 0x46c0b0
    cpu.esp -= 4;
    sub_46c0b0(app, cpu);
    if (cpu.terminate) return;
    // 0046c7cf  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046c7d4  e873570100             -call 0x481f4c
    cpu.esp -= 4;
    sub_481f4c(app, cpu);
    if (cpu.terminate) return;
    // 0046c7d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c7db  0f85dc000000           -jne 0x46c8bd
    if (!cpu.flags.zf)
    {
        goto L_0x0046c8bd;
    }
    // 0046c7e1  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0046c7e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c7e8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046c7ed  e84e5bf9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046c7f2  66890d7a074e00         -mov word ptr [0x4e077a], cx
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.cx;
    // 0046c7f9  e822f9ffff             -call 0x46c120
    cpu.esp -= 4;
    sub_46c120(app, cpu);
    if (cpu.terminate) return;
    // 0046c7fe  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046c800  e82f470100             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
    // 0046c805  6689357a074e00         -mov word ptr [0x4e077a], si
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.si;
L_0x0046c80c:
    // 0046c80c  e8af90f9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046c811  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c813  0f847b000000           -je 0x46c894
    if (cpu.flags.zf)
    {
        goto L_0x0046c894;
    }
    // 0046c819  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046c81b  e820d40000             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0046c820  ebea                   -jmp 0x46c80c
    goto L_0x0046c80c;
L_0x0046c822:
    // 0046c822  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0046c827  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c829  e8125bf9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
L_0x0046c82e:
    // 0046c82e  e87ec60000             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0046c833  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c835  7509                   -jne 0x46c840
    if (!cpu.flags.zf)
    {
        goto L_0x0046c840;
    }
    // 0046c837  e88490f9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046c83c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c83e  74ee                   -je 0x46c82e
    if (cpu.flags.zf)
    {
        goto L_0x0046c82e;
    }
L_0x0046c840:
    // 0046c840  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c842  e8494ffeff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
L_0x0046c847:
    // 0046c847  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c849  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c84c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c84d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c84e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c84f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c850  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c851  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c852:
    // 0046c852  e8794dfeff             -call 0x4515d0
    cpu.esp -= 4;
    sub_4515d0(app, cpu);
    if (cpu.terminate) return;
    // 0046c857  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c859  0f8449ffffff           -je 0x46c7a8
    if (cpu.flags.zf)
    {
        goto L_0x0046c7a8;
    }
    // 0046c85f  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0046c864  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c866  e8d55af9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046c86b  e8b0f8ffff             -call 0x46c120
    cpu.esp -= 4;
    sub_46c120(app, cpu);
    if (cpu.terminate) return;
L_0x0046c870:
    // 0046c870  e83cc60000             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0046c875  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c877  75c7                   -jne 0x46c840
    if (!cpu.flags.zf)
    {
        goto L_0x0046c840;
    }
    // 0046c879  e84290f9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046c87e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c880  74ee                   -je 0x46c870
    if (cpu.flags.zf)
    {
        goto L_0x0046c870;
    }
    // 0046c882  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c884  e8074ffeff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 0046c889  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c88b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c88e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c88f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c890  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c891  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c892  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c893  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c894:
    // 0046c894  e818c60000             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0046c899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c89b  7509                   -jne 0x46c8a6
    if (!cpu.flags.zf)
    {
        goto L_0x0046c8a6;
    }
    // 0046c89d  e81e90f9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046c8a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c8a4  74ee                   -je 0x46c894
    if (cpu.flags.zf)
    {
        goto L_0x0046c894;
    }
L_0x0046c8a6:
    // 0046c8a6  e84523faff             -call 0x40ebf0
    cpu.esp -= 4;
    sub_40ebf0(app, cpu);
    if (cpu.terminate) return;
    // 0046c8ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c8ad  e8de4efeff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 0046c8b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c8b4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c8b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c8bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c8bd:
    // 0046c8bd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046c8bf:
    // 0046c8bf  663b0d44074e00         +cmp cx, word ptr [0x4e0744]
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(5113668) /* 0x4e0744 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046c8c6  7554                   -jne 0x46c91c
    if (!cpu.flags.zf)
    {
        goto L_0x0046c91c;
    }
    // 0046c8c8  e8034dfeff             -call 0x4515d0
    cpu.esp -= 4;
    sub_4515d0(app, cpu);
    if (cpu.terminate) return;
    // 0046c8cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c8cf  74ee                   -je 0x46c8bf
    if (cpu.flags.zf)
    {
        goto L_0x0046c8bf;
    }
    // 0046c8d1  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0046c8d6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c8d8  e8635af9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046c8dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046c8e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c8e4  66a37a074e00           -mov word ptr [0x4e077a], ax
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.ax;
    // 0046c8ea  e845460100             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
    // 0046c8ef  6689157a074e00         -mov word ptr [0x4e077a], dx
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.dx;
    // 0046c8f6  e8a54cfeff             -call 0x4515a0
    cpu.esp -= 4;
    sub_4515a0(app, cpu);
    if (cpu.terminate) return;
L_0x0046c8fb:
    // 0046c8fb  e8b1c50000             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0046c900  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c902  0f853fffffff           -jne 0x46c847
    if (!cpu.flags.zf)
    {
        goto L_0x0046c847;
    }
    // 0046c908  e8b38ff9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046c90d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c90f  74ea                   -je 0x46c8fb
    if (cpu.flags.zf)
    {
        goto L_0x0046c8fb;
    }
    // 0046c911  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c913  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c916  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c917  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c918  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c919  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c91a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c91b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c91c:
    // 0046c91c  a03e074e00             -mov al, byte ptr [0x4e073e]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5113662) /* 0x4e073e */);
    // 0046c921  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c923  a27f074e00             -mov byte ptr [0x4e077f], al
    app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */) = cpu.al;
    // 0046c928  e8e34ffbff             -call 0x421910
    cpu.esp -= 4;
    sub_421910(app, cpu);
    if (cpu.terminate) return;
    // 0046c92d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c92f  e80c5af9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046c934  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046c939  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c93c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c93d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c93e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c93f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c940  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c941  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c955  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c956  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046c959  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c95b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046c960  bfe1064e00             -mov edi, 0x4e06e1
    cpu.edi = 5113569 /*0x4e06e1*/;
    // 0046c965  a02bba4600             -mov al, byte ptr [0x46ba2b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4635179) /* 0x46ba2b */);
    // 0046c96a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0046c96c  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0046c970  e82bf3ffff             -call 0x46bca0
    cpu.esp -= 4;
    sub_46bca0(app, cpu);
    if (cpu.terminate) return;
    // 0046c975  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046c97a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046c97c  e80f4efeff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 0046c981  b403                   -mov ah, 3
    cpu.ah = 3 /*0x3*/;
    // 0046c983  8815e0064e00           -mov byte ptr [0x4e06e0], dl
    app->getMemory<x86::reg8>(x86::reg32(5113568) /* 0x4e06e0 */) = cpu.dl;
    // 0046c989  66891d2a074e00         -mov word ptr [0x4e072a], bx
    app->getMemory<x86::reg16>(x86::reg32(5113642) /* 0x4e072a */) = cpu.bx;
    // 0046c990  6689352e074e00         -mov word ptr [0x4e072e], si
    app->getMemory<x86::reg16>(x86::reg32(5113646) /* 0x4e072e */) = cpu.si;
    // 0046c997  88257e074e00           -mov byte ptr [0x4e077e], ah
    app->getMemory<x86::reg8>(x86::reg32(5113726) /* 0x4e077e */) = cpu.ah;
    // 0046c99d  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0046c99f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c9a1  6689152c074e00         -mov word ptr [0x4e072c], dx
    app->getMemory<x86::reg16>(x86::reg32(5113644) /* 0x4e072c */) = cpu.dx;
    // 0046c9a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046c9a9:
    // 0046c9a9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046c9ab  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046c9ad  3c00                   +cmp al, 0
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
    // 0046c9af  7410                   -je 0x46c9c1
    if (cpu.flags.zf)
    {
        goto L_0x0046c9c1;
    }
    // 0046c9b1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046c9b4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c9b7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046c9ba  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c9bd  3c00                   +cmp al, 0
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
    // 0046c9bf  75e8                   -jne 0x46c9a9
    if (!cpu.flags.zf)
    {
        goto L_0x0046c9a9;
    }
L_0x0046c9c1:
    // 0046c9c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c9c2  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 0046c9c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0046c9c9:
    // 0046c9c9  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0046c9cc  40                     -inc eax
    (cpu.eax)++;
    // 0046c9cd  66893c552e074e00       -mov word ptr [edx*2 + 0x4e072e], di
    app->getMemory<x86::reg16>(x86::reg32(5113646) /* 0x4e072e */ + cpu.edx * 2) = cpu.di;
    // 0046c9d5  663d0800               +cmp ax, 8
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
    // 0046c9d9  7cee                   -jl 0x46c9c9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c9c9;
    }
    // 0046c9db  bf34a45100             -mov edi, 0x51a434
    cpu.edi = 5350452 /*0x51a434*/;
    // 0046c9e0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c9e2  e899f1ffff             -call 0x46bb80
    cpu.esp -= 4;
    sub_46bb80(app, cpu);
    if (cpu.terminate) return;
    // 0046c9e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046c9e8:
    // 0046c9e8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046c9ea  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046c9ec  3c00                   +cmp al, 0
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
    // 0046c9ee  7410                   -je 0x46ca00
    if (cpu.flags.zf)
    {
        goto L_0x0046ca00;
    }
    // 0046c9f0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046c9f3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c9f6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046c9f9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046c9fc  3c00                   +cmp al, 0
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
    // 0046c9fe  75e8                   -jne 0x46c9e8
    if (!cpu.flags.zf)
    {
        goto L_0x0046c9e8;
    }
L_0x0046ca00:
    // 0046ca00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca01  803d7f074e0000         +cmp byte ptr [0x4e077f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ca08  0f84ab000000           -je 0x46cab9
    if (cpu.flags.zf)
    {
        goto L_0x0046cab9;
    }
    // 0046ca0e  c70564a4510008000000   -mov dword ptr [0x51a464], 8
    app->getMemory<x86::reg32>(x86::reg32(5350500) /* 0x51a464 */) = 8 /*0x8*/;
L_0x0046ca18:
    // 0046ca18  833dec944c0000         +cmp dword ptr [0x4c94ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ca1f  0f85bc000000           -jne 0x46cae1
    if (!cpu.flags.zf)
    {
        goto L_0x0046cae1;
    }
    // 0046ca25  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046ca2b  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046ca32  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ca34  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046ca3a  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
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
    // 0046ca3f  0f8483000000           -je 0x46cac8
    if (cpu.flags.zf)
    {
        goto L_0x0046cac8;
    }
    // 0046ca45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ca47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046ca49:
    // 0046ca49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ca4a  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ca4e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ca4f  8b0de8944c00           -mov ecx, dword ptr [0x4c94e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046ca55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046ca56  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046ca5d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ca5f  8b0df0944c00           -mov ecx, dword ptr [0x4c94f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046ca65  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046ca68  bb08954c00             -mov ebx, 0x4c9508
    cpu.ebx = 5018888 /*0x4c9508*/;
    // 0046ca6d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ca6f  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046ca74  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046ca77  e8b8520100             -call 0x481d34
    cpu.esp -= 4;
    sub_481d34(app, cpu);
    if (cpu.terminate) return;
    // 0046ca7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ca7e  7557                   -jne 0x46cad7
    if (!cpu.flags.zf)
    {
        goto L_0x0046cad7;
    }
    // 0046ca80  b803030000             -mov eax, 0x303
    cpu.eax = 771 /*0x303*/;
    // 0046ca85  e81662f9ff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 0046ca8a  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0046ca8f  e803c40000             -call 0x478e97
    cpu.esp -= 4;
    sub_478e97(app, cpu);
    if (cpu.terminate) return;
L_0x0046ca94:
    // 0046ca94  e818c40000             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0046ca99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ca9b  7509                   -jne 0x46caa6
    if (!cpu.flags.zf)
    {
        goto L_0x0046caa6;
    }
    // 0046ca9d  e81e8ef9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046caa2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046caa4  74ee                   -je 0x46ca94
    if (cpu.flags.zf)
    {
        goto L_0x0046ca94;
    }
L_0x0046caa6:
    // 0046caa6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046caa8  e8e34cfeff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 0046caad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046caaf  83c410                 +add esp, 0x10
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
    // 0046cab2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cab3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cab4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cab5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cab6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cab7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cab8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cab9:
    // 0046cab9  c70564a4510002000000   -mov dword ptr [0x51a464], 2
    app->getMemory<x86::reg32>(x86::reg32(5350500) /* 0x51a464 */) = 2 /*0x2*/;
    // 0046cac3  e950ffffff             -jmp 0x46ca18
    goto L_0x0046ca18;
L_0x0046cac8:
    // 0046cac8  b806040000             -mov eax, 0x406
    cpu.eax = 1030 /*0x406*/;
    // 0046cacd  bac0bc4600             -mov edx, 0x46bcc0
    cpu.edx = 4635840 /*0x46bcc0*/;
    // 0046cad2  e972ffffff             -jmp 0x46ca49
    goto L_0x0046ca49;
L_0x0046cad7:
    // 0046cad7  c705ec944c0001000000   -mov dword ptr [0x4c94ec], 1
    app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */) = 1 /*0x1*/;
L_0x0046cae1:
    // 0046cae1  e81a4bfeff             -call 0x451600
    cpu.esp -= 4;
    sub_451600(app, cpu);
    if (cpu.terminate) return;
    // 0046cae6  e8254efbff             -call 0x421910
    cpu.esp -= 4;
    sub_421910(app, cpu);
    if (cpu.terminate) return;
    // 0046caeb  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046caf1  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046caf8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cafa  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046caff  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cb02  807c020f00             +cmp byte ptr [edx + eax + 0xf], 0
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
    // 0046cb07  0f847b000000           -je 0x46cb88
    if (cpu.flags.zf)
    {
        goto L_0x0046cb88;
    }
    // 0046cb0d  bd20000000             -mov ebp, 0x20
    cpu.ebp = 32 /*0x20*/;
    // 0046cb12  b930bd4600             -mov ecx, 0x46bd30
    cpu.ecx = 4635952 /*0x46bd30*/;
    // 0046cb17  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046cb1b  ba34a45100             -mov edx, 0x51a434
    cpu.edx = 5350452 /*0x51a434*/;
    // 0046cb20  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046cb25  892d3ca44c00           -mov dword ptr [0x4ca43c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */) = cpu.ebp;
    // 0046cb2b  e8ac530100             -call 0x481edc
    cpu.esp -= 4;
    sub_481edc(app, cpu);
    if (cpu.terminate) return;
    // 0046cb30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cb32  754d                   -jne 0x46cb81
    if (!cpu.flags.zf)
    {
        goto L_0x0046cb81;
    }
    // 0046cb34  a33ca44c00             -mov dword ptr [0x4ca43c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */) = cpu.eax;
    // 0046cb39  b803030000             -mov eax, 0x303
    cpu.eax = 771 /*0x303*/;
    // 0046cb3e  e85d61f9ff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 0046cb43  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0046cb48  e84ac30000             -call 0x478e97
    cpu.esp -= 4;
    sub_478e97(app, cpu);
    if (cpu.terminate) return;
    // 0046cb4d  e8e2430100             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
L_0x0046cb52:
    // 0046cb52  e85ac30000             -call 0x478eb1
    cpu.esp -= 4;
    sub_478eb1(app, cpu);
    if (cpu.terminate) return;
    // 0046cb57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cb59  7509                   -jne 0x46cb64
    if (!cpu.flags.zf)
    {
        goto L_0x0046cb64;
    }
    // 0046cb5b  e8608df9ff             -call 0x4058c0
    cpu.esp -= 4;
    sub_4058c0(app, cpu);
    if (cpu.terminate) return;
    // 0046cb60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cb62  74ee                   -je 0x46cb52
    if (cpu.flags.zf)
    {
        goto L_0x0046cb52;
    }
L_0x0046cb64:
    // 0046cb64  e8974dfbff             -call 0x421900
    cpu.esp -= 4;
    sub_421900(app, cpu);
    if (cpu.terminate) return;
    // 0046cb69  e88220faff             -call 0x40ebf0
    cpu.esp -= 4;
    sub_40ebf0(app, cpu);
    if (cpu.terminate) return;
    // 0046cb6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046cb70  e81b4cfeff             -call 0x451790
    cpu.esp -= 4;
    sub_451790(app, cpu);
    if (cpu.terminate) return;
    // 0046cb75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046cb77  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046cb7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cb81:
    // 0046cb81  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046cb83  a33ca44c00             -mov dword ptr [0x4ca43c], eax
    app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */) = cpu.eax;
L_0x0046cb88:
    // 0046cb88  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046cb8d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cb8f  891500954c00           -mov dword ptr [0x4c9500], edx
    app->getMemory<x86::reg32>(x86::reg32(5018880) /* 0x4c9500 */) = cpu.edx;
    // 0046cb95  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046cb98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46cba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046cba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cba2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cba3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046cba5  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0046cba8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046cbaa  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046cbae  a02aba4600             -mov al, byte ptr [0x46ba2a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4635178) /* 0x46ba2a */);
    // 0046cbb3  be20ba4600             -mov esi, 0x46ba20
    cpu.esi = 4635168 /*0x46ba20*/;
    // 0046cbb8  8b0dec944c00           -mov ecx, dword ptr [0x4c94ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */);
    // 0046cbbe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cbc0  88442464               -mov byte ptr [esp + 0x64], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.al;
    // 0046cbc4  66891df8944c00         -mov word ptr [0x4c94f8], bx
    app->getMemory<x86::reg16>(x86::reg32(5018872) /* 0x4c94f8 */) = cpu.bx;
    // 0046cbcb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046cbcc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046cbcd  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0046cbcf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046cbd1  7547                   -jne 0x46cc1a
    if (!cpu.flags.zf)
    {
        goto L_0x0046cc1a;
    }
    // 0046cbd3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cbd4  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046cbd8  8b15e8944c00           -mov edx, dword ptr [0x4c94e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046cbde  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046cbdf  bb08954c00             -mov ebx, 0x4c9508
    cpu.ebx = 5018888 /*0x4c9508*/;
    // 0046cbe4  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046cbeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cbec  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cbee  8b0df0944c00           -mov ecx, dword ptr [0x4c94f0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046cbf4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cbf7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cbf9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cbfb  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046cc00  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046cc03  e82c510100             -call 0x481d34
    cpu.esp -= 4;
    sub_481d34(app, cpu);
    if (cpu.terminate) return;
    // 0046cc08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cc0a  0f8472010000           -je 0x46cd82
    if (cpu.flags.zf)
    {
        goto L_0x0046cd82;
    }
    // 0046cc10  c705ec944c0001000000   -mov dword ptr [0x4c94ec], 1
    app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */) = 1 /*0x1*/;
L_0x0046cc1a:
    // 0046cc1a  bee09d5100             -mov esi, 0x519de0
    cpu.esi = 5348832 /*0x519de0*/;
    // 0046cc1f  8d4c2464               -lea ecx, [esp + 0x64]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0046cc23  ba60bd4600             -mov edx, 0x46bd60
    cpu.edx = 4636000 /*0x46bd60*/;
    // 0046cc28  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046cc2d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046cc2f  8935fc944c00           -mov dword ptr [0x4c94fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */) = cpu.esi;
    // 0046cc35  e87e520100             -call 0x481eb8
    cpu.esp -= 4;
    sub_481eb8(app, cpu);
    if (cpu.terminate) return;
    // 0046cc3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cc3c  0f8440010000           -je 0x46cd82
    if (cpu.flags.zf)
    {
        goto L_0x0046cd82;
    }
    // 0046cc42  66833df8944c0001       +cmp word ptr [0x4c94f8], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5018872) /* 0x4c94f8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046cc4a  0f8e32010000           -jle 0x46cd82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046cd82;
    }
    // 0046cc50  a1f6944c00             -mov eax, dword ptr [0x4c94f6]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018870) /* 0x4c94f6 */);
    // 0046cc55  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046cc57  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046cc5a  897c245c               -mov dword ptr [esp + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 0046cc5e  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0046cc62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046cc64  0f8e18010000           -jle 0x46cd82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046cd82;
    }
    // 0046cc6a  897c2458               -mov dword ptr [esp + 0x58], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edi;
L_0x0046cc6e:
    // 0046cc6e  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046cc72  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046cc76  8b35fc944c00           -mov esi, dword ptr [0x4c94fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046cc7c  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046cc80  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cc82  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0046cc86  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046cc88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046cc89:
    // 0046cc89  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046cc8b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046cc8d  3c00                   +cmp al, 0
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
    // 0046cc8f  7410                   -je 0x46cca1
    if (cpu.flags.zf)
    {
        goto L_0x0046cca1;
    }
    // 0046cc91  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046cc94  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046cc97  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046cc9a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046cc9d  3c00                   +cmp al, 0
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
    // 0046cc9f  75e8                   -jne 0x46cc89
    if (!cpu.flags.zf)
    {
        goto L_0x0046cc89;
    }
L_0x0046cca1:
    // 0046cca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cca2  39d5                   +cmp ebp, edx
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
    // 0046cca4  7d4e                   -jge 0x46ccf4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046ccf4;
    }
    // 0046cca6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046cca8  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
L_0x0046ccab:
    // 0046ccab  8b15fc944c00           -mov edx, dword ptr [0x4c94fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046ccb1  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0046ccb5  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ccb7  e8f4c70000             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 0046ccbc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ccbe  7e28                   -jle 0x46cce8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046cce8;
    }
    // 0046ccc0  8b35fc944c00           -mov esi, dword ptr [0x4c94fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046ccc6  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0046ccca  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cccc  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046ccce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046cccf:
    // 0046cccf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046ccd1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046ccd3  3c00                   +cmp al, 0
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
    // 0046ccd5  7410                   -je 0x46cce7
    if (cpu.flags.zf)
    {
        goto L_0x0046cce7;
    }
    // 0046ccd7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046ccda  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046ccdd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046cce0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046cce3  3c00                   +cmp al, 0
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
    // 0046cce5  75e8                   -jne 0x46cccf
    if (!cpu.flags.zf)
    {
        goto L_0x0046cccf;
    }
L_0x0046cce7:
    // 0046cce7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046cce8:
    // 0046cce8  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046ccec  41                     -inc ecx
    (cpu.ecx)++;
    // 0046cced  83c340                 -add ebx, 0x40
    (cpu.ebx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046ccf0  39f1                   +cmp ecx, esi
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
    // 0046ccf2  7cb7                   -jl 0x46ccab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ccab;
    }
L_0x0046ccf4:
    // 0046ccf4  3b6c245c               +cmp ebp, dword ptr [esp + 0x5c]
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
    // 0046ccf8  7468                   -je 0x46cd62
    if (cpu.flags.zf)
    {
        goto L_0x0046cd62;
    }
    // 0046ccfa  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046ccfe  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0046cd03  8b35fc944c00           -mov esi, dword ptr [0x4c94fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046cd09  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046cd0b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cd0d  c1e506                 -shl ebp, 6
    cpu.ebp <<= 6 /*0x6*/ % 32;
    // 0046cd10  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cd11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046cd13  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046cd16  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046cd18  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046cd1a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046cd1d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046cd1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd20  a1fc944c00             -mov eax, dword ptr [0x4c94fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046cd25  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046cd29  8d3428                 -lea esi, [eax + ebp]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0046cd2c  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0046cd31  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cd33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cd34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046cd36  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046cd39  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046cd3b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046cd3d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046cd40  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046cd42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd43  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0046cd48  8b3dfc944c00           -mov edi, dword ptr [0x4c94fc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5018876) /* 0x4c94fc */);
    // 0046cd4e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046cd50  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cd52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cd53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046cd55  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046cd58  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046cd5a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046cd5c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046cd5f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046cd61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046cd62:
    // 0046cd62  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046cd66  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046cd6a  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046cd6e  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046cd71  42                     -inc edx
    (cpu.edx)++;
    // 0046cd72  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0046cd76  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 0046cd7a  39ca                   +cmp edx, ecx
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
    // 0046cd7c  0f8cecfeffff           -jl 0x46cc6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046cc6e;
    }
L_0x0046cd82:
    // 0046cd82  bef8944c00             -mov esi, 0x4c94f8
    cpu.esi = 5018872 /*0x4c94f8*/;
    // 0046cd87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046cd89  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0046cd8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cda0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cda1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cda2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cda3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cda4  8b35e8944c00           -mov esi, dword ptr [0x4c94e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046cdaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046cdac  833d04954c0000         +cmp dword ptr [0x4c9504], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018884) /* 0x4c9504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046cdb3  0f84b2000000           -je 0x46ce6b
    if (cpu.flags.zf)
    {
        goto L_0x0046ce6b;
    }
L_0x0046cdb9:
    // 0046cdb9  833dec944c0000         +cmp dword ptr [0x4c94ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046cdc0  7412                   -je 0x46cdd4
    if (cpu.flags.zf)
    {
        goto L_0x0046cdd4;
    }
    // 0046cdc2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046cdc4  b888a35100             -mov eax, 0x51a388
    cpu.eax = 5350280 /*0x51a388*/;
    // 0046cdc9  893dec944c00           -mov dword ptr [0x4c94ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5018860) /* 0x4c94ec */) = cpu.edi;
    // 0046cdcf  e8a8500100             -call 0x481e7c
    cpu.esp -= 4;
    sub_481e7c(app, cpu);
    if (cpu.terminate) return;
L_0x0046cdd4:
    // 0046cdd4  833df0944c0000         +cmp dword ptr [0x4c94f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046cddb  7536                   -jne 0x46ce13
    if (!cpu.flags.zf)
    {
        goto L_0x0046ce13;
    }
    // 0046cddd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046cdde  c6057f074e0001         -mov byte ptr [0x4e077f], 1
    app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */) = 1 /*0x1*/;
    // 0046cde5  b8ecde4b00             -mov eax, 0x4bdeec
    cpu.eax = 4972268 /*0x4bdeec*/;
    // 0046cdea  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0046cdef  e8cc08fbff             -call 0x41d6c0
    cpu.esp -= 4;
    sub_41d6c0(app, cpu);
    if (cpu.terminate) return;
    // 0046cdf4  b8f0de4b00             -mov eax, 0x4bdef0
    cpu.eax = 4972272 /*0x4bdef0*/;
    // 0046cdf9  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046cdfe  e8ed13fbff             -call 0x41e1f0
    cpu.esp -= 4;
    sub_41e1f0(app, cpu);
    if (cpu.terminate) return;
    // 0046ce03  a3f4944c00             -mov dword ptr [0x4c94f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5018868) /* 0x4c94f4 */) = cpu.eax;
    // 0046ce08  b880250000             -mov eax, 0x2580
    cpu.eax = 9600 /*0x2580*/;
    // 0046ce0d  e87ef1ffff             -call 0x46bf90
    cpu.esp -= 4;
    sub_46bf90(app, cpu);
    if (cpu.terminate) return;
    // 0046ce12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046ce13:
    // 0046ce13  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046ce18  8b35e8944c00           -mov esi, dword ptr [0x4c94e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */);
    // 0046ce1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ce20  743e                   -je 0x46ce60
    if (cpu.flags.zf)
    {
        goto L_0x0046ce60;
    }
    // 0046ce22  8b1560a55100           -mov edx, dword ptr [0x51a560]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5350752) /* 0x51a560 */);
    // 0046ce28  46                     -inc esi
    (cpu.esi)++;
    // 0046ce29  39d6                   +cmp esi, edx
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
    // 0046ce2b  7c02                   -jl 0x46ce2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ce2f;
    }
    // 0046ce2d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046ce2f:
    // 0046ce2f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046ce31  741a                   -je 0x46ce4d
    if (cpu.flags.zf)
    {
        goto L_0x0046ce4d;
    }
    // 0046ce33  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046ce3a  8b15f0944c00           -mov edx, dword ptr [0x4c94f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046ce40  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ce42  8a44820f               -mov al, byte ptr [edx + eax*4 + 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
    // 0046ce46  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046ce4b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0046ce4d:
    // 0046ce4d  8d14f500000000         -lea edx, [esi*8]
    cpu.edx = x86::reg32(cpu.esi * 8);
    // 0046ce54  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ce56  a1f0944c00             -mov eax, dword ptr [0x4c94f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5018864) /* 0x4c94f0 */);
    // 0046ce5b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046ce5e  01d0                   +add eax, edx
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
L_0x0046ce60:
    // 0046ce60  8935e8944c00           -mov dword ptr [0x4c94e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5018856) /* 0x4c94e8 */) = cpu.esi;
    // 0046ce66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ce6b:
    // 0046ce6b  e8083d0100             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 0046ce70  a304954c00             -mov dword ptr [0x4c9504], eax
    app->getMemory<x86::reg32>(x86::reg32(5018884) /* 0x4c9504 */) = cpu.eax;
    // 0046ce75  e93fffffff             -jmp 0x46cdb9
    goto L_0x0046cdb9;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ce80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ce80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ce81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ce82  b9a0ce4600             -mov ecx, 0x46cea0
    cpu.ecx = 4640416 /*0x46cea0*/;
    // 0046ce87  bac0ce4600             -mov edx, 0x46cec0
    cpu.edx = 4640448 /*0x46cec0*/;
    // 0046ce8c  890db4a64c00           -mov dword ptr [0x4ca6b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023412) /* 0x4ca6b4 */) = cpu.ecx;
    // 0046ce92  8915b0a64c00           -mov dword ptr [0x4ca6b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023408) /* 0x4ca6b0 */) = cpu.edx;
    // 0046ce98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ce9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cea1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046cea3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cea5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046cea7  7502                   -jne 0x46ceab
    if (!cpu.flags.zf)
    {
        goto L_0x0046ceab;
    }
    // 0046cea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ceaa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ceab:
    // 0046ceab  e888dc0000             -call 0x47ab38
    cpu.esp -= 4;
    sub_47ab38(app, cpu);
    if (cpu.terminate) return;
    // 0046ceb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ceb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cec0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ced0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ced0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ced1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ced2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ced3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ced4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ced5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046ced7  a1d0ab5100             -mov eax, dword ptr [0x51abd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 0046cedc  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0046cedf  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cee1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046cee6  e8f50a0000             -call 0x46d9e0
    cpu.esp -= 4;
    sub_46d9e0(app, cpu);
    if (cpu.terminate) return;
    // 0046ceeb  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046ceed  8db300010000           -lea esi, [ebx + 0x100]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(256) /* 0x100 */);
L_0x0046cef3:
    // 0046cef3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046cef5  8b1dd0ab5100           -mov ebx, dword ptr [0x51abd0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 0046cefb  e830e1ffff             -call 0x46b030
    cpu.esp -= 4;
    sub_46b030(app, cpu);
    if (cpu.terminate) return;
    // 0046cf00  8b3dd0ab5100           -mov edi, dword ptr [0x51abd0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 0046cf06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046cf08  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cf0a  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cf0c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046cf0e  41                     -inc ecx
    (cpu.ecx)++;
    // 0046cf0f  e8ec0a0000             -call 0x46da00
    cpu.esp -= 4;
    sub_46da00(app, cpu);
    if (cpu.terminate) return;
    // 0046cf14  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046cf1a  83f910                 +cmp ecx, 0x10
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
    // 0046cf1d  7cd4                   -jl 0x46cef3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046cef3;
    }
    // 0046cf1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cf30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cf30  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0046cf33  01d0                   +add eax, edx
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
    // 0046cf35  e94e420200             -jmp 0x491188
    return sub_491188(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cf40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cf40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cf41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046cf43  a1d0ab5100             -mov eax, dword ptr [0x51abd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 0046cf48  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0046cf4b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cf4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46cf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cf50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cf51  8b15ccab5100           -mov edx, dword ptr [0x51abcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352396) /* 0x51abcc */);
    // 0046cf57  81fae0020000           +cmp edx, 0x2e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(736 /*0x2e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046cf5d  7d0d                   -jge 0x46cf6c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046cf6c;
    }
    // 0046cf5f  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046cf62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cf64  8915ccab5100           -mov dword ptr [0x51abcc], edx
    app->getMemory<x86::reg32>(x86::reg32(5352396) /* 0x51abcc */) = cpu.edx;
    // 0046cf6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cf6c:
    // 0046cf6c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046cf6e  8915ccab5100           -mov dword ptr [0x51abcc], edx
    app->getMemory<x86::reg32>(x86::reg32(5352396) /* 0x51abcc */) = cpu.edx;
    // 0046cf74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cf75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cf80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046cf81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cf82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cf83  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0046cf88  b974e44b00             -mov ecx, 0x4be474
    cpu.ecx = 4973684 /*0x4be474*/;
    // 0046cf8d  bb5a020000             -mov ebx, 0x25a
    cpu.ebx = 602 /*0x25a*/;
    // 0046cf92  b8c8e54b00             -mov eax, 0x4be5c8
    cpu.eax = 4974024 /*0x4be5c8*/;
    // 0046cf97  8915ccab5100           -mov dword ptr [0x51abcc], edx
    app->getMemory<x86::reg32>(x86::reg32(5352396) /* 0x51abcc */) = cpu.edx;
    // 0046cf9d  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 0046cfa3  ba00e00200             -mov edx, 0x2e000
    cpu.edx = 188416 /*0x2e000*/;
    // 0046cfa8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cfaa  890d78a64c00           -mov dword ptr [0x4ca678], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ecx;
    // 0046cfb0  e873d20000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046cfb5  a3d0ab5100             -mov dword ptr [0x51abd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */) = cpu.eax;
    // 0046cfba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cfbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cfbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cfbd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46cfc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cfc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cfc1  bac4a55100             -mov edx, 0x51a5c4
    cpu.edx = 5350852 /*0x51a5c4*/;
    // 0046cfc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046cfc8  e803ffffff             -call 0x46ced0
    cpu.esp -= 4;
    sub_46ced0(app, cpu);
    if (cpu.terminate) return;
    // 0046cfcd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046cfcf:
    // 0046cfcf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cfd1  42                     -inc edx
    (cpu.edx)++;
    // 0046cfd2  e809000000             -call 0x46cfe0
    cpu.esp -= 4;
    sub_46cfe0(app, cpu);
    if (cpu.terminate) return;
    // 0046cfd7  83fa08                 +cmp edx, 8
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
    // 0046cfda  7cf3                   -jl 0x46cfcf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046cfcf;
    }
    // 0046cfdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cfdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46cfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cfe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046cfe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cfe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046cfe3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046cfe5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cfe8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cfea  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cfed  0564a55100             -add eax, 0x51a564
    (cpu.eax) += x86::reg32(x86::sreg32(5350756 /*0x51a564*/));
    // 0046cff2  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046cff5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046cff7  7429                   -je 0x46d022
    if (cpu.flags.zf)
    {
        goto L_0x0046d022;
    }
L_0x0046cff9:
    // 0046cff9  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046cffb  8d5108                 -lea edx, [ecx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046cffe  83fb01                 +cmp ebx, 1
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
    // 0046d001  7423                   -je 0x46d026
    if (cpu.flags.zf)
    {
        goto L_0x0046d026;
    }
    // 0046d003  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046d005  752c                   -jne 0x46d033
    if (!cpu.flags.zf)
    {
        goto L_0x0046d033;
    }
    // 0046d007  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046d00a  e861090000             -call 0x46d970
    cpu.esp -= 4;
    sub_46d970(app, cpu);
    if (cpu.terminate) return;
L_0x0046d00f:
    // 0046d00f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d011  8b9110070000           -mov edx, dword ptr [ecx + 0x710]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 0046d017  e870d60000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046d01c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046d01e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d020  75d7                   -jne 0x46cff9
    if (!cpu.flags.zf)
    {
        goto L_0x0046cff9;
    }
L_0x0046d022:
    // 0046d022  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d024  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d025  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d026:
    // 0046d026  8b810c070000           -mov eax, dword ptr [ecx + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */);
    // 0046d02c  e89ffeffff             -call 0x46ced0
    cpu.esp -= 4;
    sub_46ced0(app, cpu);
    if (cpu.terminate) return;
    // 0046d031  ebdc                   -jmp 0x46d00f
    goto L_0x0046d00f;
L_0x0046d033:
    // 0046d033  83fb03                 +cmp ebx, 3
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
    // 0046d036  75d7                   -jne 0x46d00f
    if (!cpu.flags.zf)
    {
        goto L_0x0046d00f;
    }
    // 0046d038  8b9908070000           -mov ebx, dword ptr [ecx + 0x708]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1800) /* 0x708 */);
    // 0046d03e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046d041  e8ea080000             -call 0x46d930
    cpu.esp -= 4;
    sub_46d930(app, cpu);
    if (cpu.terminate) return;
    // 0046d046  ebc7                   -jmp 0x46d00f
    goto L_0x0046d00f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d050  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d051  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d052  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d053  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046d056  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d05a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046d05c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046d05e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d060  741d                   -je 0x46d07f
    if (cpu.flags.zf)
    {
        goto L_0x0046d07f;
    }
    // 0046d062  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046d064  81c1fc030000           -add ecx, 0x3fc
    (cpu.ecx) += x86::reg32(x86::sreg32(1020 /*0x3fc*/));
    // 0046d06a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
L_0x0046d06d:
    // 0046d06d  833e00                 +cmp dword ptr [esi], 0
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
    // 0046d070  7514                   -jne 0x46d086
    if (!cpu.flags.zf)
    {
        goto L_0x0046d086;
    }
L_0x0046d072:
    // 0046d072  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d075  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046d078  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046d07b  39ce                   +cmp esi, ecx
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
    // 0046d07d  75ee                   -jne 0x46d06d
    if (!cpu.flags.zf)
    {
        goto L_0x0046d06d;
    }
L_0x0046d07f:
    // 0046d07f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046d082  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d083  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d085  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d086:
    // 0046d086  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d08a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046d08c  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d090  e8cb070000             -call 0x46d860
    cpu.esp -= 4;
    sub_46d860(app, cpu);
    if (cpu.terminate) return;
    // 0046d095  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046d097  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d09b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046d0a0  e82b0b0000             -call 0x46dbd0
    cpu.esp -= 4;
    sub_46dbd0(app, cpu);
    if (cpu.terminate) return;
    // 0046d0a5  83f8ff                 +cmp eax, -1
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
    // 0046d0a8  74c8                   -je 0x46d072
    if (cpu.flags.zf)
    {
        goto L_0x0046d072;
    }
    // 0046d0aa  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0046d0b0  ebc0                   -jmp 0x46d072
    goto L_0x0046d072;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d0c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d0c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d0c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d0c3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046d0c6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d0ca  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046d0ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046d0d0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046d0d2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d0d4  7467                   -je 0x46d13d
    if (cpu.flags.zf)
    {
        goto L_0x0046d13d;
    }
    // 0046d0d6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d0d8  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046d0dc  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0046d0df  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046d0e1  7e32                   -jle 0x46d115
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d115;
    }
L_0x0046d0e3:
    // 0046d0e3  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046d0e7  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046d0eb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d0ed  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d0f1  e86a070000             -call 0x46d860
    cpu.esp -= 4;
    sub_46d860(app, cpu);
    if (cpu.terminate) return;
    // 0046d0f6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d0fa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046d0ff  e8cc0a0000             -call 0x46dbd0
    cpu.esp -= 4;
    sub_46dbd0(app, cpu);
    if (cpu.terminate) return;
    // 0046d104  83f8ff                 +cmp eax, -1
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
    // 0046d107  7418                   -je 0x46d121
    if (cpu.flags.zf)
    {
        goto L_0x0046d121;
    }
L_0x0046d109:
    // 0046d109  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046d10d  45                     -inc ebp
    (cpu.ebp)++;
    // 0046d10e  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046d111  39c5                   +cmp ebp, eax
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
    // 0046d113  7cce                   -jl 0x46d0e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d0e3;
    }
L_0x0046d115:
    // 0046d115  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d118  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046d11b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d11c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d11d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d11e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046d121:
    // 0046d121  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046d123  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046d125  83c703                 +add edi, 3
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046d128  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046d12b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d12e  8847fe                 -mov byte ptr [edi - 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 0046d131  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046d132  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0046d135  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046d138  8847ff                 -mov byte ptr [edi - 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046d13b  ebcc                   -jmp 0x46d109
    goto L_0x0046d109;
L_0x0046d13d:
    // 0046d13d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046d141  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046d144  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046d14b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d14d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d14e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d150  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046d153  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046d155  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046d157  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046d15a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046d15c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d15d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d160  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046d163  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d164  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d165  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d166  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d172  833dc8ab510000         +cmp dword ptr [0x51abc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5352392) /* 0x51abc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d179  7425                   -je 0x46d1a0
    if (cpu.flags.zf)
    {
        goto L_0x0046d1a0;
    }
    // 0046d17b  8b15c4ab5100           -mov edx, dword ptr [0x51abc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352388) /* 0x51abc4 */);
    // 0046d181  0310                   -add edx, dword ptr [eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0046d183  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 0046d188  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d18a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046d18c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046d18e  7e10                   -jle 0x46d1a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d1a0;
    }
    // 0046d190  3b0dc8ab5100           +cmp ecx, dword ptr [0x51abc8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5352392) /* 0x51abc8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d196  7d06                   -jge 0x46d19e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046d19e;
    }
    // 0046d198  890dc8ab5100           -mov dword ptr [0x51abc8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352392) /* 0x51abc8 */) = cpu.ecx;
L_0x0046d19e:
    // 0046d19e  0110                   -add dword ptr [eax], edx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0046d1a0:
    // 0046d1a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d1b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d1b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d1b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d1b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d1b4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d1b7  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046d1bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d1bd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d1c0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d1c2  bd64a55100             -mov ebp, 0x51a564
    cpu.ebp = 5350756 /*0x51a564*/;
    // 0046d1c7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d1ca  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d1cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d1ce  e8cd0d0000             -call 0x46dfa0
    cpu.esp -= 4;
    sub_46dfa0(app, cpu);
    if (cpu.terminate) return;
    // 0046d1d3  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d1d6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046d1d8  7471                   -je 0x46d24b
    if (cpu.flags.zf)
    {
        goto L_0x0046d24b;
    }
L_0x0046d1da:
    // 0046d1da  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d1dd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d1df  7460                   -je 0x46d241
    if (cpu.flags.zf)
    {
        goto L_0x0046d241;
    }
    // 0046d1e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d1e3  e8e81b0200             -call 0x48edd0
    cpu.esp -= 4;
    sub_48edd0(app, cpu);
    if (cpu.terminate) return;
    // 0046d1e8  ba6ce54b00             -mov edx, 0x4be56c
    cpu.edx = 4973932 /*0x4be56c*/;
    // 0046d1ed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046d1ef  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d1f1  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d1f4  8dbd08030000           -lea edi, [ebp + 0x308]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(776) /* 0x308 */);
    // 0046d1fa  e859b70000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046d1ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d201  745e                   -je 0x46d261
    if (cpu.flags.zf)
    {
        goto L_0x0046d261;
    }
    // 0046d203  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 0046d208  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046d20b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d20c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d20e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046d211  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046d213  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046d215  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046d218  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046d21a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046d21b:
    // 0046d21b  b8c4a85100             -mov eax, 0x51a8c4
    cpu.eax = 5351620 /*0x51a8c4*/;
    // 0046d220  8dbd08030000           -lea edi, [ebp + 0x308]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(776) /* 0x308 */);
    // 0046d226  8b15c4ab5100           -mov edx, dword ptr [0x51abc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352388) /* 0x51abc4 */);
    // 0046d22c  8d7508                 -lea esi, [ebp + 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d22f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046d231  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046d233  e818feffff             -call 0x46d050
    cpu.esp -= 4;
    sub_46d050(app, cpu);
    if (cpu.terminate) return;
    // 0046d238  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046d23a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d23c  e82f0d0000             -call 0x46df70
    cpu.esp -= 4;
    sub_46df70(app, cpu);
    if (cpu.terminate) return;
L_0x0046d241:
    // 0046d241  8bad10070000           -mov ebp, dword ptr [ebp + 0x710]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1808) /* 0x710 */);
    // 0046d247  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046d249  758f                   -jne 0x46d1da
    if (!cpu.flags.zf)
    {
        goto L_0x0046d1da;
    }
L_0x0046d24b:
    // 0046d24b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d24f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046d251  e86a0a0000             -call 0x46dcc0
    cpu.esp -= 4;
    sub_46dcc0(app, cpu);
    if (cpu.terminate) return;
    // 0046d256  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d259  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d25c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d25d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d25e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d25f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d260  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d261:
    // 0046d261  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d263  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046d265  7eb4                   -jle 0x46d21b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d21b;
    }
    // 0046d267  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0046d269:
    // 0046d269  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046d26b  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d26e  e8611b0200             -call 0x48edd4
    cpu.esp -= 4;
    sub_48edd4(app, cpu);
    if (cpu.terminate) return;
    // 0046d273  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046d275  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046d27b  83fa7b                 +cmp edx, 0x7b
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
    // 0046d27e  7509                   -jne 0x46d289
    if (!cpu.flags.zf)
    {
        goto L_0x0046d289;
    }
    // 0046d280  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d282  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046d284  e8c7070000             -call 0x46da50
    cpu.esp -= 4;
    sub_46da50(app, cpu);
    if (cpu.terminate) return;
L_0x0046d289:
    // 0046d289  41                     -inc ecx
    (cpu.ecx)++;
    // 0046d28a  39f1                   +cmp ecx, esi
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
    // 0046d28c  7d8d                   -jge 0x46d21b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046d21b;
    }
    // 0046d28e  ebd9                   -jmp 0x46d269
    goto L_0x0046d269;
}

/* align: skip  */
void Application::sub_46d290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d290  b8c4a55100             -mov eax, 0x51a5c4
    cpu.eax = 5350852 /*0x51a5c4*/;
    // 0046d295  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d2a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d2a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d2a2  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0046d2a8  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0046d2aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d2ac  8825b6a54c00           -mov byte ptr [0x4ca5b6], ah
    app->getMemory<x86::reg8>(x86::reg32(5023158) /* 0x4ca5b6 */) = cpu.ah;
    // 0046d2b2  e851300200             -call 0x490308
    cpu.esp -= 4;
    sub_490308(app, cpu);
    if (cpu.terminate) return;
    // 0046d2b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046d2b9:
    // 0046d2b9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046d2bc  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0046d2be  885c04ff               -mov byte ptr [esp + eax - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = cpu.bl;
    // 0046d2c2  8a9ac4a55100           -mov bl, byte ptr [edx + 0x51a5c4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5350852) /* 0x51a5c4 */);
    // 0046d2c8  885c04fe               -mov byte ptr [esp + eax - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.bl;
    // 0046d2cc  8a9ac5a55100           -mov bl, byte ptr [edx + 0x51a5c5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5350853) /* 0x51a5c5 */);
    // 0046d2d2  885c04fd               -mov byte ptr [esp + eax - 3], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.eax * 1) = cpu.bl;
    // 0046d2d6  8a9ac6a55100           -mov bl, byte ptr [edx + 0x51a5c6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5350854) /* 0x51a5c6 */);
    // 0046d2dc  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046d2df  885c04fc               -mov byte ptr [esp + eax - 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.bl;
    // 0046d2e3  3d00040000             +cmp eax, 0x400
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
    // 0046d2e8  75cf                   -jne 0x46d2b9
    if (!cpu.flags.zf)
    {
        goto L_0x0046d2b9;
    }
    // 0046d2ea  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046d2ec  e837300200             -call 0x490328
    cpu.esp -= 4;
    sub_490328(app, cpu);
    if (cpu.terminate) return;
    // 0046d2f1  a3b4a44c00             -mov dword ptr [0x4ca4b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */) = cpu.eax;
    // 0046d2f6  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0046d2fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46d300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d301  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d302  bbc4a55100             -mov ebx, 0x51a5c4
    cpu.ebx = 5350852 /*0x51a5c4*/;
    // 0046d307  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0046d30c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d30e  e8454a0200             -call 0x491d58
    cpu.esp -= 4;
    sub_491d58(app, cpu);
    if (cpu.terminate) return;
    // 0046d313  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d314  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d315  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d322  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d323  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d324  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d325  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d327  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046d329  8b35c4ab5100           -mov esi, dword ptr [0x51abc4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5352388) /* 0x51abc4 */);
    // 0046d32f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046d331  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d333  7e43                   -jle 0x46d378
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d378;
    }
    // 0046d335  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 0046d33c  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d33e  81c3c4a85100           -add ebx, 0x51a8c4
    (cpu.ebx) += x86::reg32(x86::sreg32(5351620 /*0x51a8c4*/));
L_0x0046d344:
    // 0046d344  8d0476                 -lea eax, [esi + esi*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 2);
    // 0046d347  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046d349  8890c4a55100           -mov byte ptr [eax + 0x51a5c4], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5350852) /* 0x51a5c4 */) = cpu.dl;
    // 0046d34f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046d352  8890c5a55100           -mov byte ptr [eax + 0x51a5c5], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5350853) /* 0x51a5c5 */) = cpu.dl;
    // 0046d358  8a5102                 -mov dl, byte ptr [ecx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046d35b  47                     -inc edi
    (cpu.edi)++;
    // 0046d35c  8890c6a55100           -mov byte ptr [eax + 0x51a5c6], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5350854) /* 0x51a5c6 */) = cpu.dl;
    // 0046d362  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046d364  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d366  46                     -inc esi
    (cpu.esi)++;
    // 0046d367  e8f4040000             -call 0x46d860
    cpu.esp -= 4;
    sub_46d860(app, cpu);
    if (cpu.terminate) return;
    // 0046d36c  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046d36f  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046d372  39ef                   +cmp edi, ebp
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
    // 0046d374  7cce                   -jl 0x46d344
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d344;
    }
    // 0046d376  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0046d378:
    // 0046d378  012dc4ab5100           -add dword ptr [0x51abc4], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5352388) /* 0x51abc4 */)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d37e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d37f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d380  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d381  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d382  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d383  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d391  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d392  bb7d010000             -mov ebx, 0x17d
    cpu.ebx = 381 /*0x17d*/;
    // 0046d397  ba44aa5100             -mov edx, 0x51aa44
    cpu.edx = 5352004 /*0x51aa44*/;
    // 0046d39c  b841aa5100             -mov eax, 0x51aa41
    cpu.eax = 5352001 /*0x51aa41*/;
    // 0046d3a1  e85a420100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046d3a6  bb7d010000             -mov ebx, 0x17d
    cpu.ebx = 381 /*0x17d*/;
    // 0046d3ab  ba44aa5100             -mov edx, 0x51aa44
    cpu.edx = 5352004 /*0x51aa44*/;
    // 0046d3b0  b841a75100             -mov eax, 0x51a741
    cpu.eax = 5351233 /*0x51a741*/;
    // 0046d3b5  e846420100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046d3ba  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 0046d3bc  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0046d3be  882541a75100           -mov byte ptr [0x51a741], ah
    app->getMemory<x86::reg8>(x86::reg32(5351233) /* 0x51a741 */) = cpu.ah;
    // 0046d3c4  881542a75100           -mov byte ptr [0x51a742], dl
    app->getMemory<x86::reg8>(x86::reg32(5351234) /* 0x51a742 */) = cpu.dl;
    // 0046d3ca  882543a75100           -mov byte ptr [0x51a743], ah
    app->getMemory<x86::reg8>(x86::reg32(5351235) /* 0x51a743 */) = cpu.ah;
    // 0046d3d0  881537a54c00           -mov byte ptr [0x4ca537], dl
    app->getMemory<x86::reg8>(x86::reg32(5023031) /* 0x4ca537 */) = cpu.dl;
    // 0046d3d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d3d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d3e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d3e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d3e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d3e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d3e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d3e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d3e6  81ec08060000           -sub esp, 0x608
    (cpu.esp) -= x86::reg32(x86::sreg32(1544 /*0x608*/));
    // 0046d3ec  b964a55100             -mov ecx, 0x51a564
    cpu.ecx = 5350756 /*0x51a564*/;
    // 0046d3f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d3f3  898c2404060000         -mov dword ptr [esp + 0x604], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */) = cpu.ecx;
    // 0046d3fa  89942400060000         -mov dword ptr [esp + 0x600], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */) = cpu.edx;
L_0x0046d401:
    // 0046d401  8bac2404060000         -mov ebp, dword ptr [esp + 0x604]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */);
    // 0046d408  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d40c  7464                   -je 0x46d472
    if (cpu.flags.zf)
    {
        goto L_0x0046d472;
    }
    // 0046d40e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d411  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d413  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d415  7412                   -je 0x46d429
    if (cpu.flags.zf)
    {
        goto L_0x0046d429;
    }
L_0x0046d417:
    // 0046d417  8bb008070000           -mov esi, dword ptr [eax + 0x708]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1800) /* 0x708 */);
    // 0046d41d  8b8010070000           -mov eax, dword ptr [eax + 0x710]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1808) /* 0x710 */);
    // 0046d423  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046d425  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d427  75ee                   -jne 0x46d417
    if (!cpu.flags.zf)
    {
        goto L_0x0046d417;
    }
L_0x0046d429:
    // 0046d429  3b5504                 +cmp edx, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d42c  0f8e76000000           -jle 0x46d4a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d4a8;
    }
    // 0046d432  837d0001               +cmp dword ptr [ebp], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d436  7570                   -jne 0x46d4a8
    if (!cpu.flags.zf)
    {
        goto L_0x0046d4a8;
    }
    // 0046d438  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d43b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046d43d  e82efdffff             -call 0x46d170
    cpu.esp -= 4;
    sub_46d170(app, cpu);
    if (cpu.terminate) return;
    // 0046d442  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d445  8b842400060000         -mov eax, dword ptr [esp + 0x600]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */);
    // 0046d44c  42                     -inc edx
    (cpu.edx)++;
    // 0046d44d  e85efdffff             -call 0x46d1b0
    cpu.esp -= 4;
    sub_46d1b0(app, cpu);
    if (cpu.terminate) return;
    // 0046d452  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d455  42                     -inc edx
    (cpu.edx)++;
    // 0046d456  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d458  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d45a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d45c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d45e  7e06                   -jle 0x46d466
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d466;
    }
    // 0046d460  8915c8ab5100           -mov dword ptr [0x51abc8], edx
    app->getMemory<x86::reg32>(x86::reg32(5352392) /* 0x51abc8 */) = cpu.edx;
L_0x0046d466:
    // 0046d466  8d442403               -lea eax, [esp + 3]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 0046d46a  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0046d46d  e8aefeffff             -call 0x46d320
    cpu.esp -= 4;
    sub_46d320(app, cpu);
    if (cpu.terminate) return;
L_0x0046d472:
    // 0046d472  8b9c2400060000         -mov ebx, dword ptr [esp + 0x600]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */);
    // 0046d479  8b8c2404060000         -mov ecx, dword ptr [esp + 0x604]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */);
    // 0046d480  43                     -inc ebx
    (cpu.ebx)++;
    // 0046d481  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046d484  899c2400060000         -mov dword ptr [esp + 0x600], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */) = cpu.ebx;
    // 0046d48b  898c2404060000         -mov dword ptr [esp + 0x604], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */) = cpu.ecx;
    // 0046d492  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d495  0f8c66ffffff           -jl 0x46d401
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d401;
    }
    // 0046d49b  81c408060000           -add esp, 0x608
    (cpu.esp) += x86::reg32(x86::sreg32(1544 /*0x608*/));
    // 0046d4a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d4a8:
    // 0046d4a8  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d4ab  e8c0fcffff             -call 0x46d170
    cpu.esp -= 4;
    sub_46d170(app, cpu);
    if (cpu.terminate) return;
    // 0046d4b0  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d4b3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d4b5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046d4b7  7448                   -je 0x46d501
    if (cpu.flags.zf)
    {
        goto L_0x0046d501;
    }
L_0x0046d4b9:
    // 0046d4b9  b8c4a85100             -mov eax, 0x51a8c4
    cpu.eax = 5351620 /*0x51a8c4*/;
    // 0046d4be  8b8f08070000           -mov ecx, dword ptr [edi + 0x708]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1800) /* 0x708 */);
    // 0046d4c4  8b15c4ab5100           -mov edx, dword ptr [0x51abc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352388) /* 0x51abc4 */);
    // 0046d4ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d4cb  8d5f08                 -lea ebx, [edi + 8]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046d4ce  8d8c2404030000         -lea ecx, [esp + 0x304]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0046d4d5  e8e6fbffff             -call 0x46d0c0
    cpu.esp -= 4;
    sub_46d0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046d4da  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d4dd  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d4df  39de                   +cmp esi, ebx
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
    // 0046d4e1  7e06                   -jle 0x46d4e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d4e9;
    }
    // 0046d4e3  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d4e5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d4e7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0046d4e9:
    // 0046d4e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d4eb  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0046d4f2  e829feffff             -call 0x46d320
    cpu.esp -= 4;
    sub_46d320(app, cpu);
    if (cpu.terminate) return;
    // 0046d4f7  8bbf10070000           -mov edi, dword ptr [edi + 0x710]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1808) /* 0x710 */);
    // 0046d4fd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046d4ff  75b8                   -jne 0x46d4b9
    if (!cpu.flags.zf)
    {
        goto L_0x0046d4b9;
    }
L_0x0046d501:
    // 0046d501  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d504  39d6                   +cmp esi, edx
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
    // 0046d506  0f8d66ffffff           -jge 0x46d472
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046d472;
    }
    // 0046d50c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d50e  29f0                   +sub eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046d510  a3c8ab5100             -mov dword ptr [0x51abc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5352392) /* 0x51abc8 */) = cpu.eax;
    // 0046d515  e958ffffff             -jmp 0x46d472
    goto L_0x0046d472;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d520  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d521  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d522  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d523  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d526  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046d529  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046d52b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046d52d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046d531  ba74e44b00             -mov edx, 0x4be474
    cpu.edx = 4973684 /*0x4be474*/;
    // 0046d536  b9c6000000             -mov ecx, 0xc6
    cpu.ecx = 198 /*0xc6*/;
    // 0046d53b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046d540  b890e44b00             -mov eax, 0x4be490
    cpu.eax = 4973712 /*0x4be490*/;
    // 0046d545  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046d54b  ba14070000             -mov edx, 0x714
    cpu.edx = 1812 /*0x714*/;
    // 0046d550  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046d556  e8cdcc0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046d55b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d55d  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046d560  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046d562  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046d564  e817050000             -call 0x46da80
    cpu.esp -= 4;
    sub_46da80(app, cpu);
    if (cpu.terminate) return;
    // 0046d569  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d56d  898608070000           -mov dword ptr [esi + 0x708], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1800) /* 0x708 */) = cpu.eax;
    // 0046d573  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046d575  8b8e08070000           -mov ecx, dword ptr [esi + 0x708]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1800) /* 0x708 */);
    // 0046d57b  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0046d57e  e80d95fdff             -call 0x446a90
    cpu.esp -= 4;
    sub_446a90(app, cpu);
    if (cpu.terminate) return;
    // 0046d583  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046d588  8d8608030000           -lea eax, [esi + 0x308]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(776) /* 0x308 */);
    // 0046d58e  e809370100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046d593  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0046d599  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d59c  c7860c07000000000000   -mov dword ptr [esi + 0x70c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */) = 0 /*0x0*/;
    // 0046d5a6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d5a8  c7861007000000000000   -mov dword ptr [esi + 0x710], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0046d5b2  e879010000             -call 0x46d730
    cpu.esp -= 4;
    sub_46d730(app, cpu);
    if (cpu.terminate) return;
    // 0046d5b7  8b860c070000           -mov eax, dword ptr [esi + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */);
    // 0046d5bd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d5c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d5d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d5d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d5d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d5d3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d5d6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d5da  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046d5dc  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0046d5df  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046d5e1  ba74e44b00             -mov edx, 0x4be474
    cpu.edx = 4973684 /*0x4be474*/;
    // 0046d5e6  b9a3000000             -mov ecx, 0xa3
    cpu.ecx = 163 /*0xa3*/;
    // 0046d5eb  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046d5f0  b890e44b00             -mov eax, 0x4be490
    cpu.eax = 4973712 /*0x4be490*/;
    // 0046d5f5  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046d5fb  ba14070000             -mov edx, 0x714
    cpu.edx = 1812 /*0x714*/;
    // 0046d600  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046d606  e81dcc0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046d60b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d60d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d60f  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046d612  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046d614  e867040000             -call 0x46da80
    cpu.esp -= 4;
    sub_46da80(app, cpu);
    if (cpu.terminate) return;
    // 0046d619  898108070000           -mov dword ptr [ecx + 0x708], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1800) /* 0x708 */) = cpu.eax;
    // 0046d61f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046d621  e8da96fdff             -call 0x446d00
    cpu.esp -= 4;
    sub_446d00(app, cpu);
    if (cpu.terminate) return;
    // 0046d626  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d628  745d                   -je 0x46d687
    if (cpu.flags.zf)
    {
        goto L_0x0046d687;
    }
    // 0046d62a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0046d631:
    // 0046d631  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d634  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046d637  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046d639  8b8e08070000           -mov ecx, dword ptr [esi + 0x708]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1800) /* 0x708 */);
    // 0046d63f  e84c94fdff             -call 0x446a90
    cpu.esp -= 4;
    sub_446a90(app, cpu);
    if (cpu.terminate) return;
    // 0046d644  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046d649  8d8608030000           -lea eax, [esi + 0x308]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(776) /* 0x308 */);
    // 0046d64f  e848360100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046d654  c70601000000           -mov dword ptr [esi], 1
    app->getMemory<x86::reg32>(cpu.esi) = 1 /*0x1*/;
    // 0046d65a  e8f1f8ffff             -call 0x46cf50
    cpu.esp -= 4;
    sub_46cf50(app, cpu);
    if (cpu.terminate) return;
    // 0046d65f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d661  89860c070000           -mov dword ptr [esi + 0x70c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */) = cpu.eax;
    // 0046d667  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d66b  c7861007000000000000   -mov dword ptr [esi + 0x710], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0046d675  e8b6000000             -call 0x46d730
    cpu.esp -= 4;
    sub_46d730(app, cpu);
    if (cpu.terminate) return;
    // 0046d67a  8b860c070000           -mov eax, dword ptr [esi + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */);
    // 0046d680  83c408                 +add esp, 8
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
    // 0046d683  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d684  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d685  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d686  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d687:
    // 0046d687  896904                 -mov dword ptr [ecx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0046d68a  eba5                   -jmp 0x46d631
    goto L_0x0046d631;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46d690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d691  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d692  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d693  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d694  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046d696  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046d698  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046d69a  ba74e44b00             -mov edx, 0x4be474
    cpu.edx = 4973684 /*0x4be474*/;
    // 0046d69f  b989000000             -mov ecx, 0x89
    cpu.ecx = 137 /*0x89*/;
    // 0046d6a4  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046d6a9  b890e44b00             -mov eax, 0x4be490
    cpu.eax = 4973712 /*0x4be490*/;
    // 0046d6ae  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046d6b4  ba14070000             -mov edx, 0x714
    cpu.edx = 1812 /*0x714*/;
    // 0046d6b9  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046d6bf  e864cb0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046d6c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d6c6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046d6c8  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046d6cb  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0046d6ce  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d6d0  e8ab030000             -call 0x46da80
    cpu.esp -= 4;
    sub_46da80(app, cpu);
    if (cpu.terminate) return;
    // 0046d6d5  898108070000           -mov dword ptr [ecx + 0x708], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1800) /* 0x708 */) = cpu.eax;
    // 0046d6db  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0046d6dd  83ff01                 +cmp edi, 1
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
    // 0046d6e0  7438                   -je 0x46d71a
    if (cpu.flags.zf)
    {
        goto L_0x0046d71a;
    }
    // 0046d6e2  c7810c07000000000000   -mov dword ptr [ecx + 0x70c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 0 /*0x0*/;
L_0x0046d6ec:
    // 0046d6ec  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046d6f1  8d8308030000           -lea eax, [ebx + 0x308]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(776) /* 0x308 */);
    // 0046d6f7  e8a0350100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046d6fc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046d6fe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046d700  c7831007000000000000   -mov dword ptr [ebx + 0x710], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0046d70a  e821000000             -call 0x46d730
    cpu.esp -= 4;
    sub_46d730(app, cpu);
    if (cpu.terminate) return;
    // 0046d70f  8b830c070000           -mov eax, dword ptr [ebx + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1804) /* 0x70c */);
    // 0046d715  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d716  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d717  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d718  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d719  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d71a:
    // 0046d71a  e831f8ffff             -call 0x46cf50
    cpu.esp -= 4;
    sub_46cf50(app, cpu);
    if (cpu.terminate) return;
    // 0046d71f  89810c070000           -mov dword ptr [ecx + 0x70c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = cpu.eax;
    // 0046d725  ebc5                   -jmp 0x46d6ec
    goto L_0x0046d6ec;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d731  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d733  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d736  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d738  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d73b  0564a55100             -add eax, 0x51a564
    (cpu.eax) += x86::reg32(x86::sreg32(5350756 /*0x51a564*/));
    // 0046d740  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046d743  898a10070000           -mov dword ptr [edx + 0x710], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.ecx;
    // 0046d749  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046d74c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d74d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46d750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d750  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d751  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d752  8b35d4ab5100           -mov esi, dword ptr [0x51abd4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5352404) /* 0x51abd4 */);
    // 0046d758  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d75a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d75d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d75f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d762  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0046d765  0564a55100             -add eax, 0x51a564
    (cpu.eax) += x86::reg32(x86::sreg32(5350756 /*0x51a564*/));
    // 0046d76a  81f9ff000000           +cmp ecx, 0xff
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
    // 0046d770  7e07                   -jle 0x46d779
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d779;
    }
    // 0046d772  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0046d777  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046d779:
    // 0046d779  83e301                 -and ebx, 1
    cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0046d77c  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0046d783  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d785  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046d788  8935d4ab5100           -mov dword ptr [0x51abd4], esi
    app->getMemory<x86::reg32>(x86::reg32(5352404) /* 0x51abd4 */) = cpu.esi;
    // 0046d78e  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0046d790  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d791  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d792  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d7a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d7a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046d7a3:
    // 0046d7a3  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046d7a6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d7a8  89905ca55100           -mov dword ptr [eax + 0x51a55c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5350748) /* 0x51a55c */) = cpu.edx;
    // 0046d7ae  83f860                 +cmp eax, 0x60
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
    // 0046d7b1  75f0                   -jne 0x46d7a3
    if (!cpu.flags.zf)
    {
        goto L_0x0046d7a3;
    }
    // 0046d7b3  8915d4ab5100           -mov dword ptr [0x51abd4], edx
    app->getMemory<x86::reg32>(x86::reg32(5352404) /* 0x51abd4 */) = cpu.edx;
    // 0046d7b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d7c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d7c1  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0046d7c6  b8c4a55100             -mov eax, 0x51a5c4
    cpu.eax = 5350852 /*0x51a5c4*/;
    // 0046d7cb  e8cc340100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046d7d0  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0046d7d5  b8c4a85100             -mov eax, 0x51a8c4
    cpu.eax = 5351620 /*0x51a8c4*/;
    // 0046d7da  e8bd340100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046d7df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d7e1  8915c4ab5100           -mov dword ptr [0x51abc4], edx
    app->getMemory<x86::reg32>(x86::reg32(5352388) /* 0x51abc4 */) = cpu.edx;
    // 0046d7e7  8915c8ab5100           -mov dword ptr [0x51abc8], edx
    app->getMemory<x86::reg32>(x86::reg32(5352392) /* 0x51abc8 */) = cpu.edx;
    // 0046d7ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46d7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d7f0  a1d0ab5100             -mov eax, dword ptr [0x51abd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 0046d7f5  e992ce0000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d801  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d802  e80995fdff             -call 0x446d10
    cpu.esp -= 4;
    sub_446d10(app, cpu);
    if (cpu.terminate) return;
    // 0046d807  e8b4ffffff             -call 0x46d7c0
    cpu.esp -= 4;
    sub_46d7c0(app, cpu);
    if (cpu.terminate) return;
    // 0046d80c  e86ff7ffff             -call 0x46cf80
    cpu.esp -= 4;
    sub_46cf80(app, cpu);
    if (cpu.terminate) return;
    // 0046d811  e88affffff             -call 0x46d7a0
    cpu.esp -= 4;
    sub_46d7a0(app, cpu);
    if (cpu.terminate) return;
    // 0046d816  ba1a000000             -mov edx, 0x1a
    cpu.edx = 26 /*0x1a*/;
    // 0046d81b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d81d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d81f  e82cffffff             -call 0x46d750
    cpu.esp -= 4;
    sub_46d750(app, cpu);
    if (cpu.terminate) return;
    // 0046d824  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 0046d829  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046d82e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d830  e81bffffff             -call 0x46d750
    cpu.esp -= 4;
    sub_46d750(app, cpu);
    if (cpu.terminate) return;
    // 0046d835  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046d83a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0046d83f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0046d844  e807ffffff             -call 0x46d750
    cpu.esp -= 4;
    sub_46d750(app, cpu);
    if (cpu.terminate) return;
    // 0046d849  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046d84e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d850  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d852  e8f9feffff             -call 0x46d750
    cpu.esp -= 4;
    sub_46d750(app, cpu);
    if (cpu.terminate) return;
    // 0046d857  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d858  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d859  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d862  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d864  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d867  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046d86a  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d86d  8d348d00000000         -lea esi, [ecx*4]
    cpu.esi = x86::reg32(cpu.ecx * 4);
    // 0046d874  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d876  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046d878  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d87b  8b1c8d2c9b4c00         -mov ebx, dword ptr [ecx*4 + 0x4c9b2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5020460) /* 0x4c9b2c */ + cpu.ecx * 4);
    // 0046d882  039e2c984c00           -add ebx, dword ptr [esi + 0x4c982c]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5019692) /* 0x4c982c */)));
    // 0046d888  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d88a  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046d88d  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d890  031c8d2c954c00         -add ebx, dword ptr [ecx*4 + 0x4c952c]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5018924) /* 0x4c952c */ + cpu.ecx * 4)));
    // 0046d897  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0046d899  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d89b  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0046d89d  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046d8a0  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d8a3  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0046d8aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d8ac  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046d8ae  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d8b1  8bbb2c994c00           -mov edi, dword ptr [ebx + 0x4c992c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5019948) /* 0x4c992c */);
    // 0046d8b7  8b0c8d2c9c4c00         -mov ecx, dword ptr [ecx*4 + 0x4c9c2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5020716) /* 0x4c9c2c */ + cpu.ecx * 4);
    // 0046d8be  8d1c39                 -lea ebx, [ecx + edi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0046d8c1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d8c3  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046d8c6  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d8c9  8b0c8d2c964c00         -mov ecx, dword ptr [ecx*4 + 0x4c962c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5019180) /* 0x4c962c */ + cpu.ecx * 4);
    // 0046d8d0  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d8d2  81c100010000           -add ecx, 0x100
    (cpu.ecx) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046d8d8  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0046d8da  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0046d8dd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d8df  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046d8e2  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d8e5  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0046d8ec  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d8ee  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046d8f0  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046d8f3  8bab2c9a4c00           -mov ebp, dword ptr [ebx + 0x4c9a2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5020204) /* 0x4c9a2c */);
    // 0046d8f9  8b0c8d2c9d4c00         -mov ecx, dword ptr [ecx*4 + 0x4c9d2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5020972) /* 0x4c9d2c */ + cpu.ecx * 4);
    // 0046d900  8a4002                 -mov al, byte ptr [eax + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046d903  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d905  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046d90a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046d90d  030c852c974c00         -add ecx, dword ptr [eax*4 + 0x4c972c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5019436) /* 0x4c972c */ + cpu.eax * 4)));
    // 0046d914  81c100010000           -add ecx, 0x100
    (cpu.ecx) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046d91a  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0046d91c  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 0046d91f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d920  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d921  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d922  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d923  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d924  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d931  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046d937  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d939  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d93b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046d93d  e81e020000             -call 0x46db60
    cpu.esp -= 4;
    sub_46db60(app, cpu);
    if (cpu.terminate) return;
    // 0046d942  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 0046d944  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046d946  88a424ff000000         -mov byte ptr [esp + 0xff], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(255) /* 0xff */) = cpu.ah;
    // 0046d94d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046d94f  e85cd5ffff             -call 0x46aeb0
    cpu.esp -= 4;
    sub_46aeb0(app, cpu);
    if (cpu.terminate) return;
    // 0046d954  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046d956  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d958  e843000000             -call 0x46d9a0
    cpu.esp -= 4;
    sub_46d9a0(app, cpu);
    if (cpu.terminate) return;
    // 0046d95d  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046d963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d964  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d970  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d971  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046d977  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d979  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d97b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046d97d  e8de010000             -call 0x46db60
    cpu.esp -= 4;
    sub_46db60(app, cpu);
    if (cpu.terminate) return;
    // 0046d982  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 0046d984  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046d986  88a424ff000000         -mov byte ptr [esp + 0xff], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(255) /* 0xff */) = cpu.ah;
    // 0046d98d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d98f  e80c000000             -call 0x46d9a0
    cpu.esp -= 4;
    sub_46d9a0(app, cpu);
    if (cpu.terminate) return;
    // 0046d994  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046d99a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d99b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46d9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d9a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d9a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d9a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d9a3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046d9a5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046d9a7  e824140200             -call 0x48edd0
    cpu.esp -= 4;
    sub_48edd0(app, cpu);
    if (cpu.terminate) return;
    // 0046d9ac  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046d9ae:
    // 0046d9ae  49                     -dec ecx
    (cpu.ecx)--;
    // 0046d9af  83f9ff                 +cmp ecx, -1
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
    // 0046d9b2  7504                   -jne 0x46d9b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046d9b8;
    }
    // 0046d9b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d9b8:
    // 0046d9b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046d9ba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046d9bc  e813140200             -call 0x48edd4
    cpu.esp -= 4;
    sub_48edd4(app, cpu);
    if (cpu.terminate) return;
    // 0046d9c1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046d9c3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046d9c9  83fa7b                 +cmp edx, 0x7b
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
    // 0046d9cc  75e0                   -jne 0x46d9ae
    if (!cpu.flags.zf)
    {
        goto L_0x0046d9ae;
    }
    // 0046d9ce  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046d9d0  e85b000000             -call 0x46da30
    cpu.esp -= 4;
    sub_46da30(app, cpu);
    if (cpu.terminate) return;
    // 0046d9d5  49                     -dec ecx
    (cpu.ecx)--;
    // 0046d9d6  83f9ff                 +cmp ecx, -1
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
    // 0046d9d9  75dd                   -jne 0x46d9b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046d9b8;
    }
    // 0046d9db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46d9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d9e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d9e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046d9e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d9e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046d9e7  e874010000             -call 0x46db60
    cpu.esp -= 4;
    sub_46db60(app, cpu);
    if (cpu.terminate) return;
    // 0046d9ec  c681ff000000ff         -mov byte ptr [ecx + 0xff], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(255) /* 0xff */) = 255 /*0xff*/;
    // 0046d9f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46da00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046da00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046da01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046da02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046da03  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046da05  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046da07  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046da09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046da0b  81c3ff000000           -add ebx, 0xff
    (cpu.ebx) += x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x0046da11:
    // 0046da11  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da13  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046da15  42                     -inc edx
    (cpu.edx)++;
    // 0046da16  8a0c31                 -mov cl, byte ptr [ecx + esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1);
    // 0046da19  40                     -inc eax
    (cpu.eax)++;
    // 0046da1a  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0046da1d  39d8                   +cmp eax, ebx
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
    // 0046da1f  75f0                   -jne 0x46da11
    if (!cpu.flags.zf)
    {
        goto L_0x0046da11;
    }
    // 0046da21  c687ff000000ff         -mov byte ptr [edi + 0xff], 0xff
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(255) /* 0xff */) = 255 /*0xff*/;
    // 0046da28  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da29  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46da30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046da30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046da31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046da32  8b5802                 -mov ebx, dword ptr [eax + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046da35  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046da38  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046da3b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046da3e  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046da41  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046da44  e8cb440200             -call 0x491f14
    cpu.esp -= 4;
    sub_491f14(app, cpu);
    if (cpu.terminate) return;
    // 0046da49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46da50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046da50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046da51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046da52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046da53  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046da55  8d4210                 -lea eax, [edx + 0x10]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046da58  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046da5b  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046da5e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046da61  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046da64  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
L_0x0046da67:
    // 0046da67  4a                     -dec edx
    (cpu.edx)--;
    // 0046da68  83faff                 +cmp edx, -1
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
    // 0046da6b  740e                   -je 0x46da7b
    if (cpu.flags.zf)
    {
        goto L_0x0046da7b;
    }
    // 0046da6d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046da6f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046da71  8b348b                 -mov esi, dword ptr [ebx + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4);
    // 0046da74  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046da75  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046da76  89348b                 -mov dword ptr [ebx + ecx*4], esi
    app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4) = cpu.esi;
    // 0046da79  ebec                   -jmp 0x46da67
    goto L_0x0046da67;
L_0x0046da7b:
    // 0046da7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46da80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046da80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046da81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046da82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046da83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046da84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046da85  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046da87  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046da89  e842130200             -call 0x48edd0
    cpu.esp -= 4;
    sub_48edd0(app, cpu);
    if (cpu.terminate) return;
    // 0046da8e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046da90:
    // 0046da90  49                     -dec ecx
    (cpu.ecx)--;
    // 0046da91  83f9ff                 +cmp ecx, -1
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
    // 0046da94  750a                   -jne 0x46daa0
    if (!cpu.flags.zf)
    {
        goto L_0x0046daa0;
    }
    // 0046da96  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046da98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046da9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046da9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046daa0:
    // 0046daa0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046daa2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046daa4  e82b130200             -call 0x48edd4
    cpu.esp -= 4;
    sub_48edd4(app, cpu);
    if (cpu.terminate) return;
    // 0046daa9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046daab  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046dab1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dab3  83fa24                 +cmp edx, 0x24
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
    // 0046dab6  755a                   -jne 0x46db12
    if (!cpu.flags.zf)
    {
        goto L_0x0046db12;
    }
L_0x0046dab8:
    // 0046dab8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046daba  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046dabd  8dbd00030000           -lea edi, [ebp + 0x300]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0046dac3:
    // 0046dac3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046dac5  40                     -inc eax
    (cpu.eax)++;
    // 0046dac6  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046dac8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046daca  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0046dacc  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046dace  40                     -inc eax
    (cpu.eax)++;
    // 0046dacf  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0046dad2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046dad4  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046dad7  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046dad9  40                     -inc eax
    (cpu.eax)++;
    // 0046dada  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0046dadd  39fa                   +cmp edx, edi
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
    // 0046dadf  75e2                   -jne 0x46dac3
    if (!cpu.flags.zf)
    {
        goto L_0x0046dac3;
    }
    // 0046dae1  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046dae3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046dae8  83f822                 +cmp eax, 0x22
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
    // 0046daeb  7517                   -jne 0x46db04
    if (!cpu.flags.zf)
    {
        goto L_0x0046db04;
    }
    // 0046daed  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046daef  8d9500030000           -lea edx, [ebp + 0x300]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0046daf5:
    // 0046daf5  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046daf7  40                     -inc eax
    (cpu.eax)++;
    // 0046daf8  c0e302                 -shl bl, 2
    cpu.bl <<= 2 /*0x2*/ % 32;
    // 0046dafb  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0046dafe  39d0                   +cmp eax, edx
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
    // 0046db00  75f3                   -jne 0x46daf5
    if (!cpu.flags.zf)
    {
        goto L_0x0046daf5;
    }
    // 0046db02  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0046db04:
    // 0046db04  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0046db07  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046db0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046db0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046db12:
    // 0046db12  83fa22                 +cmp edx, 0x22
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
    // 0046db15  74a1                   -je 0x46dab8
    if (cpu.flags.zf)
    {
        goto L_0x0046dab8;
    }
    // 0046db17  83fa2a                 +cmp edx, 0x2a
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
    // 0046db1a  0f8570ffffff           -jne 0x46da90
    if (!cpu.flags.zf)
    {
        goto L_0x0046da90;
    }
    // 0046db20  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046db22  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046db25  8dbd00030000           -lea edi, [ebp + 0x300]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0046db2b:
    // 0046db2b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046db2d  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046db2f  40                     -inc eax
    (cpu.eax)++;
    // 0046db30  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0046db33  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046db35  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046db37  40                     -inc eax
    (cpu.eax)++;
    // 0046db38  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0046db3b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046db3d  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046db40  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046db42  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046db45  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0046db48  39fa                   +cmp edx, edi
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
    // 0046db4a  75df                   -jne 0x46db2b
    if (!cpu.flags.zf)
    {
        goto L_0x0046db2b;
    }
    // 0046db4c  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0046db4f  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046db52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046db54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46db60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046db60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046db61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046db62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046db63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046db64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046db66  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046db68  8dbaff000000           -lea edi, [edx + 0xff]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(255) /* 0xff */);
L_0x0046db6e:
    // 0046db6e  46                     -inc esi
    (cpu.esi)++;
    // 0046db6f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046db71  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046db73  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046db75  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046db78  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046db7b  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046db7d  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046db80  e81b000000             -call 0x46dba0
    cpu.esp -= 4;
    sub_46dba0(app, cpu);
    if (cpu.terminate) return;
    // 0046db85  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046db88  39fe                   +cmp esi, edi
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
    // 0046db8a  75e2                   -jne 0x46db6e
    if (!cpu.flags.zf)
    {
        goto L_0x0046db6e;
    }
    // 0046db8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dba0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046dba3  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0046dba6  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0046dba9  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046dbac  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0046dbaf  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dbb1  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dbb3  a1b4a44c00             -mov eax, dword ptr [0x4ca4b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022900) /* 0x4ca4b4 */);
    // 0046dbb8  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0046dbbb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046dbc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dbd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dbd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dbd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046dbd3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dbd6  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046dbda  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046dbdc  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046dbe3  a1e4ab5100             -mov eax, dword ptr [0x51abe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352420) /* 0x51abe4 */);
    // 0046dbe8  bf9f860100             -mov edi, 0x1869f
    cpu.edi = 99999 /*0x1869f*/;
    // 0046dbed  8b0c01                 -mov ecx, dword ptr [ecx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046dbf0  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0046dbf5  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0046dbfc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dbfe  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc00  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dc04  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046dc07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046dc09  7e24                   -jle 0x46dc2f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046dc2f;
    }
    // 0046dc0b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x0046dc0d:
    // 0046dc0d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046dc0f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046dc11  e82a000000             -call 0x46dc40
    cpu.esp -= 4;
    sub_46dc40(app, cpu);
    if (cpu.terminate) return;
    // 0046dc16  3b0424                 +cmp eax, dword ptr [esp]
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
    // 0046dc19  7f08                   -jg 0x46dc23
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046dc23;
    }
    // 0046dc1b  39f8                   +cmp eax, edi
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
    // 0046dc1d  7d04                   -jge 0x46dc23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046dc23;
    }
    // 0046dc1f  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046dc21  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0046dc23:
    // 0046dc23  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dc27  43                     -inc ebx
    (cpu.ebx)++;
    // 0046dc28  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046dc2b  39c3                   +cmp ebx, eax
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
    // 0046dc2d  7cde                   -jl 0x46dc0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046dc0d;
    }
L_0x0046dc2f:
    // 0046dc2f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046dc31  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dc34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dc40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dc41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046dc42  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dc45  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dc47  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc49  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046dc4b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046dc4d  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dc4f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046dc51  7e60                   -jle 0x46dcb3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046dcb3;
    }
L_0x0046dc53:
    // 0046dc53  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 0046dc56  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dc58  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc5a  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046dc5d  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046dc60  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dc62  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046dc64  7e51                   -jle 0x46dcb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046dcb7;
    }
L_0x0046dc66:
    // 0046dc66  8a4002                 -mov al, byte ptr [eax + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046dc69  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046dc6e  8a5202                 -mov dl, byte ptr [edx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046dc71  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046dc77  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dc79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dc7b  7e3e                   -jle 0x46dcbb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046dcbb;
    }
L_0x0046dc7d:
    // 0046dc7d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dc7f  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0046dc83  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 0046dc86  a1e4ab5100             -mov eax, dword ptr [0x51abe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352420) /* 0x51abe4 */);
    // 0046dc8b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046dc8e  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0046dc91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dc93  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0046dc95  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046dc98  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0046dc9b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046dc9d  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046dc9f  8d0c1a                 -lea ecx, [edx + ebx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0046dca2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dca4  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dca8  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0046dcab  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dcad  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046dcb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dcb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dcb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046dcb3:
    // 0046dcb3  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046dcb5  eb9c                   -jmp 0x46dc53
    goto L_0x0046dc53;
L_0x0046dcb7:
    // 0046dcb7  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046dcb9  ebab                   -jmp 0x46dc66
    goto L_0x0046dc66;
L_0x0046dcbb:
    // 0046dcbb  f7d8                   +neg eax
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
    // 0046dcbd  ebbe                   -jmp 0x46dc7d
    goto L_0x0046dc7d;
}

/* align: skip 0x00 */
void Application::sub_46dcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dcc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dcc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046dcc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dcc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dcc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046dcc5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0046dcc7  81ec1c200000           -sub esp, 0x201c
    (cpu.esp) -= x86::reg32(x86::sreg32(8220 /*0x201c*/));
    // 0046dccd  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0046dcd0  89842408200000         -mov dword ptr [esp + 0x2008], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8200) /* 0x2008 */) = cpu.eax;
    // 0046dcd7  8994240c200000         -mov dword ptr [esp + 0x200c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8204) /* 0x200c */) = cpu.edx;
    // 0046dcde  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dce3  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 0046dce8  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046dceb  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046dcee  89942404200000         -mov dword ptr [esp + 0x2004], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8196) /* 0x2004 */) = cpu.edx;
    // 0046dcf5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046dcf7  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046dcfa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dcfb  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046dcfe  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046dd01  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046dd06  e8b50c0000             -call 0x46e9c0
    cpu.esp -= 4;
    sub_46e9c0(app, cpu);
    if (cpu.terminate) return;
    // 0046dd0b  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046dd0f  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0046dd13  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd15  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046dd19  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0046dd1d  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0046dd21  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046dd25  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0046dd27:
    // 0046dd27  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dd2c  3b701c                 +cmp esi, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dd2f  7c72                   -jl 0x46dda3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046dda3;
    }
L_0x0046dd31:
    // 0046dd31  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dd36  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046dd38  e84fc90000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046dd3d  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dd42  8bb4240c200000         -mov esi, dword ptr [esp + 0x200c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8204) /* 0x200c */);
    // 0046dd49  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0046dd4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046dd51  0f84b5010000           -je 0x46df0c
    if (cpu.flags.zf)
    {
        goto L_0x0046df0c;
    }
    // 0046dd57  8b942404200000         -mov edx, dword ptr [esp + 0x2004]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8196) /* 0x2004 */);
    // 0046dd5e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046dd65  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dd69  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dd6b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046dd6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046dd6f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046dd71  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dd73  e8242f0100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
L_0x0046dd78:
    // 0046dd78  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dd7d  3b581c                 +cmp ebx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dd80  0f8d86010000           -jge 0x46df0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046df0c;
    }
    // 0046dd86  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046dd89  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046dd8b  e8600b0000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046dd90  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dd92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dd94  0f8519010000           -jne 0x46deb3
    if (!cpu.flags.zf)
    {
        goto L_0x0046deb3;
    }
    // 0046dd9a  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046dd9d  43                     -inc ebx
    (cpu.ebx)++;
    // 0046dd9e  83c11c                 +add ecx, 0x1c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046dda1  ebd5                   -jmp 0x46dd78
    goto L_0x0046dd78;
L_0x0046dda3:
    // 0046dda3  6bde1c                 -imul ebx, esi, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0046dda6  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ddaa  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ddac  6bd71c                 -imul edx, edi, 0x1c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0046ddaf  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ddb3  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ddb5  89942414200000         -mov dword ptr [esp + 0x2014], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8212) /* 0x2014 */) = cpu.edx;
    // 0046ddbc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046ddbe  e8fd020000             -call 0x46e0c0
    cpu.esp -= 4;
    sub_46e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046ddc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ddc5  0f84d0000000           -je 0x46de9b
    if (cpu.flags.zf)
    {
        goto L_0x0046de9b;
    }
    // 0046ddcb  8b842414200000         -mov eax, dword ptr [esp + 0x2014]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8212) /* 0x2014 */);
    // 0046ddd2  837c041c01             +cmp dword ptr [esp + eax + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ddd7  0f8ea5000000           -jle 0x46de82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046de82;
    }
    // 0046dddd  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dde2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046dde4  e8c7060000             -call 0x46e4b0
    cpu.esp -= 4;
    sub_46e4b0(app, cpu);
    if (cpu.terminate) return;
    // 0046dde9  d99c2418200000         -fstp dword ptr [esp + 0x2018]
    app->getMemory<float>(cpu.esp + x86::reg32(8216) /* 0x2018 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046ddf0:
    // 0046ddf0  6bd61c                 -imul edx, esi, 0x1c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0046ddf3  8b842418200000         -mov eax, dword ptr [esp + 0x2018]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8216) /* 0x2018 */);
    // 0046ddfa  8b4c141c               -mov ecx, dword ptr [esp + edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.edx * 1);
    // 0046ddfe  8984bc041c0000         -mov dword ptr [esp + edi*4 + 0x1c04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edi * 4) = cpu.eax;
    // 0046de05  83f901                 +cmp ecx, 1
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
    // 0046de08  0f8e82000000           -jle 0x46de90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046de90;
    }
    // 0046de0e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046de12  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046de14  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046de19  e892060000             -call 0x46e4b0
    cpu.esp -= 4;
    sub_46e4b0(app, cpu);
    if (cpu.terminate) return;
    // 0046de1e  d99c2410200000         -fstp dword ptr [esp + 0x2010]
    app->getMemory<float>(cpu.esp + x86::reg32(8208) /* 0x2010 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046de25:
    // 0046de25  8b942410200000         -mov edx, dword ptr [esp + 0x2010]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8208) /* 0x2010 */);
    // 0046de2c  8994b4041c0000         -mov dword ptr [esp + esi*4 + 0x1c04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.esi * 4) = cpu.edx;
L_0x0046de33:
    // 0046de33  8b8424041c0000         -mov eax, dword ptr [esp + 0x1c04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */);
    // 0046de3a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046de3f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046de41  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046de44  39ce                   +cmp esi, ecx
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
    // 0046de46  7c28                   -jl 0x46de70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046de70;
    }
    // 0046de48  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x0046de4d:
    // 0046de4d  d98414041c0000         +fld dword ptr [esp + edx + 0x1c04]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edx * 1)));
    // 0046de54  d81c24                 +fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0046de57  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046de59  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046de5a  760c                   -jbe 0x46de68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046de68;
    }
    // 0046de5c  8b8414041c0000         -mov eax, dword ptr [esp + edx + 0x1c04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edx * 1);
    // 0046de63  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046de65  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0046de68:
    // 0046de68  41                     -inc ecx
    (cpu.ecx)++;
    // 0046de69  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046de6c  39f1                   +cmp ecx, esi
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
    // 0046de6e  7edd                   -jle 0x46de4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046de4d;
    }
L_0x0046de70:
    // 0046de70  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046de73  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0046de75  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0046de77  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046de79  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046de7a  7329                   -jae 0x46dea5
    if (!cpu.flags.cf)
    {
        goto L_0x0046dea5;
    }
    // 0046de7c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046de7d  e9a5feffff             -jmp 0x46dd27
    goto L_0x0046dd27;
L_0x0046de82:
    // 0046de82  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046de84  89842418200000         -mov dword ptr [esp + 0x2018], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8216) /* 0x2018 */) = cpu.eax;
    // 0046de8b  e960ffffff             -jmp 0x46ddf0
    goto L_0x0046ddf0;
L_0x0046de90:
    // 0046de90  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046de92  899c2410200000         -mov dword ptr [esp + 0x2010], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8208) /* 0x2010 */) = cpu.ebx;
    // 0046de99  eb8a                   -jmp 0x46de25
    goto L_0x0046de25;
L_0x0046de9b:
    // 0046de9b  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046de9c  8984bc041c0000         -mov dword ptr [esp + edi*4 + 0x1c04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edi * 4) = cpu.eax;
    // 0046dea3  eb8e                   -jmp 0x46de33
    goto L_0x0046de33;
L_0x0046dea5:
    // 0046dea5  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046deaa  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046deab  89701c                 -mov dword ptr [eax + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0046deae  e97efeffff             -jmp 0x46dd31
    goto L_0x0046dd31;
L_0x0046deb3:
    // 0046deb3  8b15e0ab5100           -mov edx, dword ptr [0x51abe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046deb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046debb  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046debe  e82d0a0000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046dec3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046dec5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046dec8  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046deca  8b15e0ab5100           -mov edx, dword ptr [0x51abe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046ded0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046ded2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ded4  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046ded7  e8140a0000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046dedc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046dede  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046dee1  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046dee3  8b15e0ab5100           -mov edx, dword ptr [0x51abe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046dee9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046deec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046deee  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046def1  e8fa090000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046def6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046def8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046defb  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046defd  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0046df00  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046df03  43                     -inc ebx
    (cpu.ebx)++;
    // 0046df04  83c11c                 +add ecx, 0x1c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046df07  e96cfeffff             -jmp 0x46dd78
    goto L_0x0046dd78;
L_0x0046df0c:
    // 0046df0c  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046df11  8b8c2408200000         -mov ecx, dword ptr [esp + 0x2008]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8200) /* 0x2008 */);
    // 0046df18  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046df1b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0046df1d  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046df20  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046df22  7407                   -je 0x46df2b
    if (cpu.flags.zf)
    {
        goto L_0x0046df2b;
    }
    // 0046df24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046df26  e861c70000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0046df2b:
    // 0046df2b  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046df30  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046df32  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046df34  7512                   -jne 0x46df48
    if (!cpu.flags.zf)
    {
        goto L_0x0046df48;
    }
    // 0046df36  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046df3b  e84cc70000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046df40  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046df42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046df48:
    // 0046df48  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046df4a  e83dc70000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046df4f  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046df54  e833c70000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046df59  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046df5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46df70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046df71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046df72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046df74  a1e0ab5100             -mov eax, dword ptr [0x51abe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */);
    // 0046df79  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046df7c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046df7e  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0046df81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046df82  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046df85  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046df88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046df89  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046df8c  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046df8f  e86c0c0000             -call 0x46ec00
    cpu.esp -= 4;
    sub_46ec00(app, cpu);
    if (cpu.terminate) return;
    // 0046df94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dfa0  e80b000000             -call 0x46dfb0
    cpu.esp -= 4;
    sub_46dfb0(app, cpu);
    if (cpu.terminate) return;
    // 0046dfa5  a3e0ab5100             -mov dword ptr [0x51abe0], eax
    app->getMemory<x86::reg32>(x86::reg32(5352416) /* 0x51abe0 */) = cpu.eax;
    // 0046dfaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dfb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dfb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046dfb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dfb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dfb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dfb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046dfb6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046dfb8  ba04e64b00             -mov edx, 0x4be604
    cpu.edx = 4974084 /*0x4be604*/;
    // 0046dfbd  b964010000             -mov ecx, 0x164
    cpu.ecx = 356 /*0x164*/;
    // 0046dfc2  b82ce64b00             -mov eax, 0x4be62c
    cpu.eax = 4974124 /*0x4be62c*/;
    // 0046dfc7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dfc9  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046dfcf  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046dfd4  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046dfda  e849c20000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046dfdf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046dfe1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dfe3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dfe5  7507                   -jne 0x46dfee
    if (!cpu.flags.zf)
    {
        goto L_0x0046dfee;
    }
    // 0046dfe7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfe8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfe9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046dfee:
    // 0046dfee  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046dff3  bb04e64b00             -mov ebx, 0x4be604
    cpu.ebx = 4974084 /*0x4be604*/;
    // 0046dff8  bd6f010000             -mov ebp, 0x16f
    cpu.ebp = 367 /*0x16f*/;
    // 0046dffd  e89a2c0100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046e002  ba10c60800             -mov edx, 0x8c610
    cpu.edx = 574992 /*0x8c610*/;
    // 0046e007  b830e64b00             -mov eax, 0x4be630
    cpu.eax = 4974128 /*0x4be630*/;
    // 0046e00c  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 0046e012  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e014  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 0046e01a  e809c20000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046e01f  ba75010000             -mov edx, 0x175
    cpu.edx = 373 /*0x175*/;
    // 0046e024  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e026  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046e029  b804e64b00             -mov eax, 0x4be604
    cpu.eax = 4974084 /*0x4be604*/;
    // 0046e02e  89157ca64c00           -mov dword ptr [0x4ca67c], edx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.edx;
    // 0046e034  ba84310200             -mov edx, 0x23184
    cpu.edx = 143748 /*0x23184*/;
    // 0046e039  a378a64c00             -mov dword ptr [0x4ca678], eax
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.eax;
    // 0046e03e  b83ce64b00             -mov eax, 0x4be63c
    cpu.eax = 4974140 /*0x4be63c*/;
    // 0046e043  e8e0c10000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046e048  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046e04b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0046e04d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046e04f  7529                   -jne 0x46e07a
    if (!cpu.flags.zf)
    {
        goto L_0x0046e07a;
    }
L_0x0046e051:
    // 0046e051  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0046e054  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e056  7405                   -je 0x46e05d
    if (cpu.flags.zf)
    {
        goto L_0x0046e05d;
    }
    // 0046e058  e82fc60000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0046e05d:
    // 0046e05d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046e05f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046e061  7407                   -je 0x46e06a
    if (cpu.flags.zf)
    {
        goto L_0x0046e06a;
    }
    // 0046e063  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e065  e822c60000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0046e06a:
    // 0046e06a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e06c  e81bc60000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046e071  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e073  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e074  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e075  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e078  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e079  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e07a:
    // 0046e07a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e07c  74d3                   -je 0x46e051
    if (cpu.flags.zf)
    {
        goto L_0x0046e051;
    }
    // 0046e07e  ba10c60800             -mov edx, 0x8c610
    cpu.edx = 574992 /*0x8c610*/;
    // 0046e083  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046e085  e8122c0100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046e08a  ba84310200             -mov edx, 0x23184
    cpu.edx = 143748 /*0x23184*/;
    // 0046e08f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e091  e8062c0100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0046e096  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046e099  89791c                 -mov dword ptr [ecx + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0046e09c  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046e09f  0584310200             -add eax, 0x23184
    (cpu.eax) += x86::reg32(x86::sreg32(143748 /*0x23184*/));
    // 0046e0a4  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046e0a7  0584310200             -add eax, 0x23184
    (cpu.eax) += x86::reg32(x86::sreg32(143748 /*0x23184*/));
    // 0046e0ac  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046e0af  0584310200             -add eax, 0x23184
    (cpu.eax) += x86::reg32(x86::sreg32(143748 /*0x23184*/));
    // 0046e0b4  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046e0b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e0b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46e0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e0c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e0c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e0c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e0c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e0c4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046e0c7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046e0c9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046e0cb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046e0cd  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e0d0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e0d2  e819080000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e0d7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046e0db  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046e0de  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e0e0  e80b080000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e0e5  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046e0e9  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046e0ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e0ee  e8fd070000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e0f3  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046e0f7  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046e0fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e0fc  e8ef070000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e101  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e102  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e106  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e107  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e10b  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046e10f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e110  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e114  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046e117  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e118  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e11c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046e11e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e11f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0046e124  41                     -inc ecx
    (cpu.ecx)++;
    // 0046e125  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e126  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046e128  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e12a  e891010000             -call 0x46e2c0
    cpu.esp -= 4;
    sub_46e2c0(app, cpu);
    if (cpu.terminate) return;
    // 0046e12f  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e133  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e134  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e138  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e139  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e13d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e13e  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e143  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e147  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046e14a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e14b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046e150  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e152  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e153  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046e156  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046e158  41                     -inc ecx
    (cpu.ecx)++;
    // 0046e159  d95c243c               -fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e15d  e85e010000             -call 0x46e2c0
    cpu.esp -= 4;
    sub_46e2c0(app, cpu);
    if (cpu.terminate) return;
    // 0046e162  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e166  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e167  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e16b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e16c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e170  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e171  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e175  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e176  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e17a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046e17d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e17e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e180  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046e183  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e184  41                     -inc ecx
    (cpu.ecx)++;
    // 0046e185  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046e187  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046e189  d95c2438               +fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e18d  e82e010000             -call 0x46e2c0
    cpu.esp -= 4;
    sub_46e2c0(app, cpu);
    if (cpu.terminate) return;
    // 0046e192  d9442424               +fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0046e196  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e198  d95c241c               +fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e19c  d85c2420               +fcomp dword ptr [esp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0046e1a0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046e1a2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046e1a3  0f82a9000000           -jb 0x46e252
    if (cpu.flags.cf)
    {
        goto L_0x0046e252;
    }
    // 0046e1a9  d9442424               +fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0046e1ad  d85c241c               +fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0046e1b1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046e1b3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046e1b4  0f8298000000           -jb 0x46e252
    if (cpu.flags.cf)
    {
        goto L_0x0046e252;
    }
    // 0046e1ba  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1bd  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 0046e1bf  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046e1c1  0f8c81000000           -jl 0x46e248
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046e248;
    }
L_0x0046e1c7:
    // 0046e1c7  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046e1ca  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e1cd  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046e1d0  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046e1d3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046e1d6  895714                 -mov dword ptr [edi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046e1d9  3c01                   +cmp al, 1
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
    // 0046e1db  0f8399000000           -jae 0x46e27a
    if (!cpu.flags.cf)
    {
        goto L_0x0046e27a;
    }
    // 0046e1e1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046e1e3  7514                   -jne 0x46e1f9
    if (!cpu.flags.zf)
    {
        goto L_0x0046e1f9;
    }
    // 0046e1e5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e1e9  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046e1ec  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046e1ef  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046e1f1  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046e1f3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046e1f6  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0046e1f9:
    // 0046e1f9  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046e1fc  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046e1ff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e201  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046e203  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e205  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046e208  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e20a  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046e20d  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046e210  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046e213  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e215  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046e218  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046e21b  8b570c                 -mov edx, dword ptr [edi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0046e21e  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046e221  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0046e224  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0046e226  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e228  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e22a  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046e22d  8b4f10                 -mov ecx, dword ptr [edi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0046e230  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046e233  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e235  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046e238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046e23d  895718                 -mov dword ptr [edi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046e240  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046e243  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e244  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e245  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e246  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e247  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e248:
    // 0046e248  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e24a  83c428                 +add esp, 0x28
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046e24d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e24e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e24f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e250  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e251  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e252:
    // 0046e252  d9442420               +fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0046e256  d85c2424               +fcomp dword ptr [esp + 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    cpu.fpu.pop();
    // 0046e25a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046e25c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046e25d  7214                   -jb 0x46e273
    if (cpu.flags.cf)
    {
        goto L_0x0046e273;
    }
    // 0046e25f  d9442420               +fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0046e263  d85c241c               +fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0046e267  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046e269  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046e26a  7207                   -jb 0x46e273
    if (cpu.flags.cf)
    {
        goto L_0x0046e273;
    }
    // 0046e26c  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0046e26e  e954ffffff             -jmp 0x46e1c7
    goto L_0x0046e1c7;
L_0x0046e273:
    // 0046e273  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0046e275  e94dffffff             -jmp 0x46e1c7
    goto L_0x0046e1c7;
L_0x0046e27a:
    // 0046e27a  7719                   -ja 0x46e295
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046e295;
    }
    // 0046e27c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e280  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046e283  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046e286  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046e288  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046e28a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046e28d  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046e290  e964ffffff             -jmp 0x46e1f9
    goto L_0x0046e1f9;
L_0x0046e295:
    // 0046e295  3c02                   +cmp al, 2
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
    // 0046e297  0f855cffffff           -jne 0x46e1f9
    if (!cpu.flags.zf)
    {
        goto L_0x0046e1f9;
    }
    // 0046e29d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e2a0  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046e2a3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046e2a5  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046e2a8  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046e2ab  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046e2ae  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046e2b1  e943ffffff             -jmp 0x46e1f9
    goto L_0x0046e1f9;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e2c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e2c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e2c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e2c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0046e2c5  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046e2c8  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0046e2cb  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046e2cf  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046e2d3  885c2430               -mov byte ptr [esp + 0x30], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.bl;
    // 0046e2d7  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046e2d9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e2db  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e2de  8a4c2430               -mov cl, byte ptr [esp + 0x30]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046e2e2  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e2e6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e2e8  e873040000             -call 0x46e760
    cpu.esp -= 4;
    sub_46e760(app, cpu);
    if (cpu.terminate) return;
    // 0046e2ed  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e2f1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046e2f5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e2f7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e2fb  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0046e2fe  e85d040000             -call 0x46e760
    cpu.esp -= 4;
    sub_46e760(app, cpu);
    if (cpu.terminate) return;
    // 0046e303  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e307  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046e30b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e30d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e311  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046e314  e847040000             -call 0x46e760
    cpu.esp -= 4;
    sub_46e760(app, cpu);
    if (cpu.terminate) return;
    // 0046e319  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e31d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046e321  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e323  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e327  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046e32a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0046e32c  e82f040000             -call 0x46e760
    cpu.esp -= 4;
    sub_46e760(app, cpu);
    if (cpu.terminate) return;
    // 0046e331  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046e335  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e337  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0046e33a  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046e33d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046e340  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 0046e346  39cf                   +cmp edi, ecx
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
    // 0046e348  0f8d87000000           -jge 0x46e3d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046e3d5;
    }
L_0x0046e34e:
    // 0046e34e  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e352  0fb67c2430             -movzx edi, byte ptr [esp + 0x30]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */));
    // 0046e357  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e35b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046e35d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e35f  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046e362  e879020000             -call 0x46e5e0
    cpu.esp -= 4;
    sub_46e5e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e367  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e36b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e36d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046e36f  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0046e373  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e377  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e379  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e37d  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046e380  e85b020000             -call 0x46e5e0
    cpu.esp -= 4;
    sub_46e5e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e385  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e389  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e38b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046e38d  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0046e391  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e395  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e397  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e39b  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046e39e  e83d020000             -call 0x46e5e0
    cpu.esp -= 4;
    sub_46e5e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e3a3  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e3a7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e3a9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046e3ab  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0046e3af  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e3b3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e3b5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e3b9  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046e3bc  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e3c0  e81b020000             -call 0x46e5e0
    cpu.esp -= 4;
    sub_46e5e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e3c5  01c7                   +add edi, eax
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
    // 0046e3c7  7517                   -jne 0x46e3e0
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3e0;
    }
L_0x0046e3c9:
    // 0046e3c9  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046e3cc  46                     -inc esi
    (cpu.esi)++;
    // 0046e3cd  39de                   +cmp esi, ebx
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
    // 0046e3cf  0f8c79ffffff           -jl 0x46e34e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046e34e;
    }
L_0x0046e3d5:
    // 0046e3d5  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046e3d8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046e3da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3dd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0046e3e0:
    // 0046e3e0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e3e4  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046e3e8  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e3ec  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e3f0  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046e3f2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046e3f6  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e3fa  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046e3fc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046e400  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e402  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046e406  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e40a  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046e40c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e40e  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0046e412  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e416  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e418  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e41c  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0046e41f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e421  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e425  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046e429  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046e42c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e42e  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046e432  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046e436  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0046e439  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e43b  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0046e43f  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0046e442  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046e444  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e446  d95c2428               +fstp dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e44a  0f8479ffffff           -je 0x46e3c9
    if (cpu.flags.zf)
    {
        goto L_0x0046e3c9;
    }
    // 0046e450  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e454  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046e458  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e45c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e460  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046e462  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046e466  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e46a  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046e46c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046e470  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e472  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046e476  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e47a  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046e47c  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e47e  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0046e482  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046e486  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e488  d8442428               +fadd dword ptr [esp + 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 0046e48c  d9542428               +fst dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    // 0046e490  d81c24                 +fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0046e493  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046e495  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046e496  0f862dffffff           -jbe 0x46e3c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046e3c9;
    }
    // 0046e49c  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046e4a0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e4a3  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0046e4a6  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0046e4a8  e91cffffff             -jmp 0x46e3c9
    goto L_0x0046e3c9;
}

}
