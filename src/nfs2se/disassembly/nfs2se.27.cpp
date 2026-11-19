#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_49a6b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a6b9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a6ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a6bb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a6bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a6bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a6be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a6bf  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a6c2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049a6c4  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0049a6c9  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049a6cc  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049a6cf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a6d2  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a6d4  b9941d4c00             -mov ecx, 0x4c1d94
    cpu.ecx = 4988308 /*0x4c1d94*/;
    // 0049a6d9  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049a6dc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a6de  81fea17efbf4           +cmp esi, 0xf4fb7ea1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4110122657 /*0xf4fb7ea1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a6e4  7d0a                   -jge 0x49a6f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a6f0;
    }
L_0x0049a6e6:
    // 0049a6e6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049a6eb  e94e010000             -jmp 0x49a83e
    goto L_0x0049a83e;
L_0x0049a6f0:
    // 0049a6f0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049a6f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a6f5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a6f8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a6fa  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049a6fc:
    // 0049a6fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049a6fe  7d06                   -jge 0x49a706
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a706;
    }
    // 0049a700  4e                     -dec esi
    (cpu.esi)--;
    // 0049a701  83c70c                 +add edi, 0xc
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a704  ebf6                   -jmp 0x49a6fc
    goto L_0x0049a6fc;
L_0x0049a706:
    // 0049a706  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a708  7cdc                   -jl 0x49a6e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a6e6;
    }
    // 0049a70a  8d866c070000           -lea eax, [esi + 0x76c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1900) /* 0x76c */);
    // 0049a710  e8cfcb0000             -call 0x4a72e4
    cpu.esp -= 4;
    sub_4a72e4(app, cpu);
    if (cpu.terminate) return;
    // 0049a715  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a717  7405                   -je 0x49a71e
    if (cpu.flags.zf)
    {
        goto L_0x0049a71e;
    }
    // 0049a719  b9ae1d4c00             -mov ecx, 0x4c1dae
    cpu.ecx = 4988334 /*0x4c1dae*/;
L_0x0049a71e:
    // 0049a71e  8d5603                 -lea edx, [esi + 3]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 0049a721  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a723  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a726  c1e202                 +shl edx, 2
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
    // 0049a729  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049a72b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049a72e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a730  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a732  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049a735  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a737  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049a73a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049a73c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a73e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a741  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049a743  8d5663                 -lea edx, [esi + 0x63]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(99) /* 0x63 */);
    // 0049a746  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a748  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0049a74d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049a750  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a752  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a755  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a757  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a75a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a75c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049a75f  8d962b010000           -lea edx, [esi + 0x12b]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(299) /* 0x12b */);
    // 0049a765  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 0049a76a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a76c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049a76f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049a771  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049a774  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a776  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a778  0fbf0441               -movsx eax, word ptr [ecx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2)));
    // 0049a77c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049a77e  03450c                 -add eax, dword ptr [ebp + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0049a781  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049a784  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0049a787  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a789  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0049a78c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a78e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a791  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049a794  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a796  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a798  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0049a79b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a79d  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049a7a0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049a7a3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049a7a5:
    // 0049a7a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a7a7  7d09                   -jge 0x49a7b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a7b2;
    }
    // 0049a7a9  4f                     -dec edi
    (cpu.edi)--;
    // 0049a7aa  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a7b0  ebf3                   -jmp 0x49a7a5
    goto L_0x0049a7a5;
L_0x0049a7b2:
    // 0049a7b2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049a7b4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049a7b6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a7b8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a7ba  e85ecf0000             -call 0x4a771d
    cpu.esp -= 4;
    sub_4a771d(app, cpu);
    if (cpu.terminate) return;
    // 0049a7bf  e8d8d10000             -call 0x4a799c
    cpu.esp -= 4;
    sub_4a799c(app, cpu);
    if (cpu.terminate) return;
    // 0049a7c4  8b1d2ef74c00           -mov ebx, dword ptr [0x4cf72e]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044014) /* 0x4cf72e */);
    // 0049a7ca  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0049a7cd  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a7cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a7d1  7d07                   -jge 0x49a7da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a7da;
    }
    // 0049a7d3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a7d5  e864cc0000             -call 0x4a743e
    cpu.esp -= 4;
    sub_4a743e(app, cpu);
    if (cpu.terminate) return;
L_0x0049a7da:
    // 0049a7da  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a7de  7e06                   -jle 0x49a7e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a7e6;
    }
    // 0049a7e0  2b3536f74c00           -sub esi, dword ptr [0x4cf736]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044022) /* 0x4cf736 */)));
L_0x0049a7e6:
    // 0049a7e6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a7e8  7d09                   -jge 0x49a7f3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a7f3;
    }
    // 0049a7ea  4f                     -dec edi
    (cpu.edi)--;
    // 0049a7eb  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a7f1  ebf3                   -jmp 0x49a7e6
    goto L_0x0049a7e6;
L_0x0049a7f3:
    // 0049a7f3  81ffde630000           +cmp edi, 0x63de
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25566 /*0x63de*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a7f9  0f8ce7feffff           -jl 0x49a6e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a6e6;
    }
    // 0049a7ff  751d                   -jne 0x49a81e
    if (!cpu.flags.zf)
    {
        goto L_0x0049a81e;
    }
    // 0049a801  8b1d2ef74c00           -mov ebx, dword ptr [0x4cf72e]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044014) /* 0x4cf72e */);
    // 0049a807  81ee80510100           -sub esi, 0x15180
    (cpu.esi) -= x86::reg32(x86::sreg32(86400 /*0x15180*/));
    // 0049a80d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a80f  0f8ed1feffff           -jle 0x49a6e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a6e6;
    }
    // 0049a815  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a817  7d23                   -jge 0x49a83c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a83c;
    }
    // 0049a819  e9c8feffff             -jmp 0x49a6e6
    goto L_0x0049a6e6;
L_0x0049a81e:
    // 0049a81e  8d87219cffff           -lea eax, [edi - 0x63df]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-25567) /* -0x63df */);
    // 0049a824  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a826  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 0049a829  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a82b  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0049a82e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a830  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 0049a833  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a835  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049a838  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a83a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
L_0x0049a83c:
    // 0049a83c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049a83e:
    // 0049a83e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a841  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a842  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a843  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a844  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a845  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a846  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a847  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a848(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a848  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a849  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 0049a84a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a84b  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049a84d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049a850  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 0049a851  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a852  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a854  3500002000             -xor eax, 0x200000
    cpu.eax ^= x86::reg32(x86::sreg32(2097152 /*0x200000*/));
    // 0049a859  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a85a  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a85b  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 0049a85c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a85d  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a85f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049a861  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a862  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a863  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a864  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a865(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a865  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a866  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a867  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a868  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a869  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a86a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049a86b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a86d  0fa2                   -cpuid 
    cpu.cpuid();
    // 0049a86f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a870  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049a872  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049a875  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049a878  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049a87b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a87c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a87d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a87e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a87f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a880  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a881(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a881  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a882  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a883  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a885  9e                     -sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049a886  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049a88b  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049a890  f6f3                   -div bl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.bl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
    // 0049a892  9f                     -lahf 
    cpu.ah = 0x02 | (cpu.flags.lo & 0xD7);
    // 0049a893  80fc02                 +cmp ah, 2
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
    // 0049a896  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 0049a89b  7505                   -jne 0x49a8a2
    if (!cpu.flags.zf)
    {
        goto L_0x0049a8a2;
    }
    // 0049a89d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049a8a2:
    // 0049a8a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49a8a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a8a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a8a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a8a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a8a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a8a9  ff0d4ad04c00           +dec dword ptr [0x4cd04a]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5034058) /* 0x4cd04a */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049a8af  753f                   -jne 0x49a8f0
    if (!cpu.flags.zf)
    {
        goto L_0x0049a8f0;
    }
    // 0049a8b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a8b3  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 0049a8b5  7421                   -je 0x49a8d8
    if (cpu.flags.zf)
    {
        goto L_0x0049a8d8;
    }
    // 0049a8b7  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 0049a8ba  8a9244cf4c00           -mov dl, byte ptr [edx + 0x4ccf44]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5033796) /* 0x4ccf44 */);
L_0x0049a8c0:
    // 0049a8c0  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049a8c1  7c2d                   -jl 0x49a8f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a8f0;
    }
    // 0049a8c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a8c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a8c5  ff14954ed04c00         -call dword ptr [edx*4 + 0x4cd04e]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5034062) /* 0x4cd04e */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a8cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a8d0  ff054ad04c00           -inc dword ptr [0x4cd04a]
    (app->getMemory<x86::reg32>(x86::reg32(5034058) /* 0x4cd04a */))++;
    // 0049a8d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a8d8:
    // 0049a8d8  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 0049a8db  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a8e1  7c05                   -jl 0x49a8e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a8e8;
    }
    // 0049a8e3  ba84000000             -mov edx, 0x84
    cpu.edx = 132 /*0x84*/;
L_0x0049a8e8:
    // 0049a8e8  8a92c4cf4c00           -mov dl, byte ptr [edx + 0x4ccfc4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5033924) /* 0x4ccfc4 */);
    // 0049a8ee  ebd0                   -jmp 0x49a8c0
    goto L_0x0049a8c0;
L_0x0049a8f0:
    // 0049a8f0  ff054ad04c00           -inc dword ptr [0x4cd04a]
    (app->getMemory<x86::reg32>(x86::reg32(5034058) /* 0x4cd04a */))++;
    // 0049a8f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a8f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a8f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a8f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a8f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a8fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a8fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a8fd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a8ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a901  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0049a906  ba4ed04c00             -mov edx, 0x4cd04e
    cpu.edx = 5034062 /*0x4cd04e*/;
L_0x0049a90b:
    // 0049a90b  3902                   +cmp dword ptr [edx], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a90d  7412                   -je 0x49a921
    if (cpu.flags.zf)
    {
        goto L_0x0049a921;
    }
    // 0049a90f  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049a913  740a                   -je 0x49a91f
    if (cpu.flags.zf)
    {
        goto L_0x0049a91f;
    }
    // 0049a915  83c204                 +add edx, 4
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
    // 0049a918  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049a919  75f0                   -jne 0x49a90b
    if (!cpu.flags.zf)
    {
        goto L_0x0049a90b;
    }
    // 0049a91b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a91c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a91d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a91e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a91f:
    // 0049a91f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0049a921:
    // 0049a921  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 0049a926  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049a928:
    // 0049a928  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049a92a  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 0049a92c  740f                   -je 0x49a93d
    if (cpu.flags.zf)
    {
        goto L_0x0049a93d;
    }
    // 0049a92e  83fa7f                 +cmp edx, 0x7f
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
    // 0049a931  7f06                   -jg 0x49a939
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a939;
    }
    // 0049a933  888244cf4c00           -mov byte ptr [edx + 0x4ccf44], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5033796) /* 0x4ccf44 */) = cpu.al;
L_0x0049a939:
    // 0049a939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a93a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a93b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a93c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a93d:
    // 0049a93d  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 0049a940  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a946  7ff1                   -jg 0x49a939
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a939;
    }
    // 0049a948  8882c4cf4c00           -mov byte ptr [edx + 0x4ccfc4], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5033924) /* 0x4ccfc4 */) = cpu.al;
    // 0049a94e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a94f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a950  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a951  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0049a952  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a955  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a957  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049a959  ebcd                   -jmp 0x49a928
    goto L_0x0049a928;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49a960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a961  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a963  83f80f                 +cmp eax, 0xf
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
    // 0049a966  7313                   -jae 0x49a97b
    if (!cpu.flags.cf)
    {
        goto L_0x0049a97b;
    }
    // 0049a968  83f804                 +cmp eax, 4
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
    // 0049a96b  7333                   -jae 0x49a9a0
    if (!cpu.flags.cf)
    {
        goto L_0x0049a9a0;
    }
    // 0049a96d  83f801                 +cmp eax, 1
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
    // 0049a970  7505                   -jne 0x49a977
    if (!cpu.flags.zf)
    {
        goto L_0x0049a977;
    }
    // 0049a972  ba79000000             -mov edx, 0x79
    cpu.edx = 121 /*0x79*/;
L_0x0049a977:
    // 0049a977  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a979  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a97a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a97b:
    // 0049a97b  763c                   -jbe 0x49a9b9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a9b9;
    }
    // 0049a97d  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a980  730e                   -jae 0x49a990
    if (!cpu.flags.cf)
    {
        goto L_0x0049a990;
    }
    // 0049a982  83f810                 +cmp eax, 0x10
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
    // 0049a985  75f0                   -jne 0x49a977
    if (!cpu.flags.zf)
    {
        goto L_0x0049a977;
    }
    // 0049a987  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 0049a98c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a98e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a98f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a990:
    // 0049a990  7630                   -jbe 0x49a9c2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a9c2;
    }
    // 0049a992  83f820                 +cmp eax, 0x20
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
    // 0049a995  75e0                   -jne 0x49a977
    if (!cpu.flags.zf)
    {
        goto L_0x0049a977;
    }
    // 0049a997  ba7d000000             -mov edx, 0x7d
    cpu.edx = 125 /*0x7d*/;
    // 0049a99c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a99e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a99f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a9a0:
    // 0049a9a0  760e                   -jbe 0x49a9b0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a9b0;
    }
    // 0049a9a2  83f808                 +cmp eax, 8
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
    // 0049a9a5  75d0                   -jne 0x49a977
    if (!cpu.flags.zf)
    {
        goto L_0x0049a977;
    }
    // 0049a9a7  ba7b000000             -mov edx, 0x7b
    cpu.edx = 123 /*0x7b*/;
    // 0049a9ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a9ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a9b0:
    // 0049a9b0  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 0049a9b5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a9b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a9b9:
    // 0049a9b9  ba7e000000             -mov edx, 0x7e
    cpu.edx = 126 /*0x7e*/;
    // 0049a9be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a9c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a9c2:
    // 0049a9c2  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0049a9c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a9c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a9ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a9cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a9cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a9cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a9cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a9ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a9cf  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049a9d1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049a9d3  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0049a9d8  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049a9da  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0049a9dc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049a9dd  e30b                   -jecxz 0x49a9ea
    if (cpu.ecx == 0)
    {
        goto L_0x0049a9ea;
    }
    // 0049a9df  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049a9e1  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0049a9e3  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0049a9e5  7503                   -jne 0x49a9ea
    if (!cpu.flags.zf)
    {
        goto L_0x0049a9ea;
    }
    // 0049a9e7  4f                     -dec edi
    (cpu.edi)--;
    // 0049a9e8  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0049a9ec;
L_0x0049a9ea:
    // 0049a9ea  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049a9ec:
    // 0049a9ec  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a9ed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0049a9ef:
    // 0049a9ef  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a9f1  740d                   -je 0x49aa00
    if (cpu.flags.zf)
    {
        goto L_0x0049aa00;
    }
    // 0049a9f3  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049a9f5  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049a9f7  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0049a9f9  7405                   -je 0x49aa00
    if (cpu.flags.zf)
    {
        goto L_0x0049aa00;
    }
    // 0049a9fb  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a9fc  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a9fd  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049a9fe  ebef                   -jmp 0x49a9ef
    goto L_0x0049a9ef;
L_0x0049aa00:
    // 0049aa00  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0049aa03  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049aa05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49aa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aa10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aa11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049aa12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049aa14  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049aa16  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049aa1b  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aa1e  7509                   -jne 0x49aa29
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa29;
    }
    // 0049aa20  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049aa23  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049aa26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049aa29:
    // 0049aa29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049aa2b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049aa2d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049aa30  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0049aa36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049aa38  83f80f                 +cmp eax, 0xf
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
    // 0049aa3b  7505                   -jne 0x49aa42
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa42;
    }
    // 0049aa3d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x0049aa42:
    // 0049aa42  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049aa43  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049aa46  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0049aa49  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049aa4c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049aa4e  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 0049aa53  83f840                 +cmp eax, 0x40
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
    // 0049aa56  750c                   -jne 0x49aa64
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa64;
    }
    // 0049aa58  8d410f                 -lea eax, [ecx + 0xf]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(15) /* 0xf */);
    // 0049aa5b  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0049aa5d  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049aa60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049aa64:
    // 0049aa64  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0049aa67  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0049aa69  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049aa6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49aa70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aa70  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049aa72  7501                   -jne 0x49aa75
    if (!cpu.flags.zf)
    {
        goto L_0x0049aa75;
    }
    // 0049aa74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049aa75:
    // 0049aa75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aa76  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049aa77  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049aa79  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049aa7a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049aa7c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049aa7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049aa80  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049aa84  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049aa87  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049aa89  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049aa8c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aa8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049aa90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49aa94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049aa94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049aa95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049aa96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049aa97  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049aa98  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049aa9e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049aaa0  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0049aaa4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0049aaa8  baa9144900             -mov edx, 0x4914a9
    cpu.edx = 4789417 /*0x4914a9*/;
    // 0049aaad  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049aab0  8b1dfca34c00           -mov ebx, dword ptr [0x4ca3fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022716) /* 0x4ca3fc */);
    // 0049aab6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049aab9  89942490000000         -mov dword ptr [esp + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 0049aac0  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0049aac7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049aac9  7418                   -je 0x49aae3
    if (cpu.flags.zf)
    {
        goto L_0x0049aae3;
    }
    // 0049aacb  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aad2  0f845c010000           -je 0x49ac34
    if (cpu.flags.zf)
    {
        goto L_0x0049ac34;
    }
    // 0049aad8  c784249000000084174900 -mov dword ptr [esp + 0x90], 0x491784
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = 4790148 /*0x491784*/;
L_0x0049aae3:
    // 0049aae3  ba3cae5200             -mov edx, 0x52ae3c
    cpu.edx = 5418556 /*0x52ae3c*/;
    // 0049aae8  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049aaeb  e8e066ffff             -call 0x4911d0
    cpu.esp -= 4;
    sub_4911d0(app, cpu);
    if (cpu.terminate) return;
    // 0049aaf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049aaf2  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0049aaf9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049aafb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049aafd  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049ab00  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0049ab06  83f820                 +cmp eax, 0x20
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
    // 0049ab09  750b                   -jne 0x49ab16
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab16;
    }
    // 0049ab0b  c784248400000002000000 -mov dword ptr [esp + 0x84], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 2 /*0x2*/;
L_0x0049ab16:
    // 0049ab16  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ab18  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ab1a  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049ab1d  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0049ab23  40                     -inc eax
    (cpu.eax)++;
    // 0049ab24  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049ab26  83f810                 +cmp eax, 0x10
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
    // 0049ab29  750b                   -jne 0x49ab36
    if (!cpu.flags.zf)
    {
        goto L_0x0049ab36;
    }
    // 0049ab2b  c784248400000001000000 -mov dword ptr [esp + 0x84], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 1 /*0x1*/;
L_0x0049ab36:
    // 0049ab36  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049ab3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ab3c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049ab40  895c2440               -mov dword ptr [esp + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 0049ab44  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049ab47  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049ab4a  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0049ab4e  39f8                   +cmp eax, edi
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
    // 0049ab50  7e08                   -jle 0x49ab5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ab5a;
    }
    // 0049ab52  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
L_0x0049ab5a:
    // 0049ab5a  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049ab5e  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049ab62  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049ab65  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ab67  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049ab6b  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049ab6e  3b480c                 +cmp ecx, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ab71  7e08                   -jle 0x49ab7b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ab7b;
    }
    // 0049ab73  c744243c01000000       -mov dword ptr [esp + 0x3c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 1 /*0x1*/;
L_0x0049ab7b:
    // 0049ab7b  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049ab7f  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049ab83  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049ab86  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049ab88  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049ab8b  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 0049ab8e  7e08                   -jle 0x49ab98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ab98;
    }
    // 0049ab90  c744244002000000       -mov dword ptr [esp + 0x40], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x0049ab98:
    // 0049ab98  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049ab9c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049aba0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049aba3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049aba5  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049aba9  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049abac  3b4814                 +cmp ecx, dword ptr [eax + 0x14]
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
    // 0049abaf  7e08                   -jle 0x49abb9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049abb9;
    }
    // 0049abb1  c744243c02000000       -mov dword ptr [esp + 0x3c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 2 /*0x2*/;
L_0x0049abb9:
    // 0049abb9  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049abbd  8b742440               -mov esi, dword ptr [esp + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049abc1  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0049abc6  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049abc8  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049abcc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049abce  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049abd2  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049abd6  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0049abdd  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0049abe0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049abe2  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049abe4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049abe7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049abe9  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0049abed  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0049abf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049abf3  8d14f500000000         -lea edx, [esi*8]
    cpu.edx = x86::reg32(cpu.esi * 8);
    // 0049abfa  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049abfd  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049abff  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ac01  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049ac05  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049ac07  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ac09  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049ac0c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049ac10  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049ac13  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ac15  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0049ac19  3d00000100             +cmp eax, 0x10000
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
    // 0049ac1e  7d28                   -jge 0x49ac48
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ac48;
    }
    // 0049ac20  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ac27  751b                   -jne 0x49ac44
    if (!cpu.flags.zf)
    {
        goto L_0x0049ac44;
    }
L_0x0049ac29:
    // 0049ac29  81c4a4000000           +add esp, 0xa4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ac2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ac34:
    // 0049ac34  c78424900000005e1a4900 -mov dword ptr [esp + 0x90], 0x491a5e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = 4790878 /*0x491a5e*/;
    // 0049ac3f  e99ffeffff             -jmp 0x49aae3
    goto L_0x0049aae3;
L_0x0049ac44:
    // 0049ac44  0f77                   -emms 
    cpu.mmx.init();
    // 0049ac46  ebe1                   -jmp 0x49ac29
    goto L_0x0049ac29;
L_0x0049ac48:
    // 0049ac48  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ac4c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ac4e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ac52  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ac54  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ac56  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ac58  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ac5a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ac5c  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049ac60  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049ac64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ac66  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ac68  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049ac6c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049ac6e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ac70  7c1e                   -jl 0x49ac90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ac90;
    }
L_0x0049ac72:
    // 0049ac72  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ac78  7d23                   -jge 0x49ac9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ac9d;
    }
L_0x0049ac7a:
    // 0049ac7a  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ac81  74a6                   -je 0x49ac29
    if (cpu.flags.zf)
    {
        goto L_0x0049ac29;
    }
    // 0049ac83  0f77                   -emms 
    cpu.mmx.init();
    // 0049ac85  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049ac8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ac8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ac90:
    // 0049ac90  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049ac95  f7d9                   +neg ecx
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
    // 0049ac97  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049ac9b  ebd5                   -jmp 0x49ac72
    goto L_0x0049ac72;
L_0x0049ac9d:
    // 0049ac9d  81f900000006           +cmp ecx, 0x6000000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100663296 /*0x6000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aca3  7dd5                   -jge 0x49ac7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ac7a;
    }
    // 0049aca5  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049aca9  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049acad  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049acb0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049acb2  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0049acb6  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049acba  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049acbc  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049acc0  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049acc4  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049acc7  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049acc9  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049accd  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049acd1  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 0049acd4  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049acd8  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049acda  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049acdc  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0049ace0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ace2  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049ace6  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ace8  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049acec  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049acee  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049acf0  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049acf4  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049acf7  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049acfa  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049acfc  2b542448               -sub edx, dword ptr [esp + 0x48]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 0049ad00  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049ad04  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049ad08  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ad0b  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 0049ad0e  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049ad12  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049ad14  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ad16  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049ad1a  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049ad1d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ad1f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ad23  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049ad26  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049ad2a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049ad2d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ad2f  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049ad33  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049ad35  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049ad37  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ad39  e832fdffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049ad3e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ad40  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ad44  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049ad47  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ad4a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ad4c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049ad4e  e81dfdffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049ad53  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049ad55  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049ad58  42                     -inc edx
    (cpu.edx)++;
    // 0049ad59  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ad5a  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049ad61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ad62  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049ad66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ad67  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049ad69  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0049ad6e  b83cae5200             -mov eax, 0x52ae3c
    cpu.eax = 5418556 /*0x52ae3c*/;
    // 0049ad73  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ad75  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049ad79  e8f2070000             -call 0x49b570
    cpu.esp -= 4;
    sub_49b570(app, cpu);
    if (cpu.terminate) return;
    // 0049ad7e  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049ad82  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049ad86  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049ad88  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ad8a  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049ad8d  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049ad90  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049ad92  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0049ad95  89bc249c000000         -mov dword ptr [esp + 0x9c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.edi;
    // 0049ad9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ad9e  0f8452010000           -je 0x49aef6
    if (cpu.flags.zf)
    {
        goto L_0x0049aef6;
    }
    // 0049ada4  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ada8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049adab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049adad  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049adb1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049adb5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049adb7  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049adb9  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049adbd  e8aefcffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049adc2  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0049adc9  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049adcc  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049add0  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049add4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049add6  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x0049adda:
    // 0049adda  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049addd  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049ade0  e88bfcffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049ade5  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0049adec  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049adf0  0f8d17030000           -jge 0x49b10d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b10d;
    }
    // 0049adf6  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049adfa  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049adfe  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049ae01  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049ae05  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ae07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ae09  0f8438010000           -je 0x49af47
    if (cpu.flags.zf)
    {
        goto L_0x0049af47;
    }
    // 0049ae0f  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049ae13  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ae16  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ae18  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ae1a  2b442444               -sub eax, dword ptr [esp + 0x44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0049ae1e  e84dfcffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049ae23  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049ae27  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0049ae2b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ae2f  e83cfcffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049ae34  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0049ae38:
    // 0049ae38  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049ae3c  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0049ae41  39d0                   +cmp eax, edx
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
    // 0049ae43  7d02                   -jge 0x49ae47
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ae47;
    }
    // 0049ae45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049ae47:
    // 0049ae47  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0049ae4d  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0049ae51  39cb                   +cmp ebx, ecx
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
    // 0049ae53  0f8d1c010000           -jge 0x49af75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049af75;
    }
L_0x0049ae59:
    // 0049ae59  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049ae60  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
L_0x0049ae64:
    // 0049ae64  3b5c2450               +cmp ebx, dword ptr [esp + 0x50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ae68  0f8d9f020000           -jge 0x49b10d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b10d;
    }
    // 0049ae6e  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049ae75  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ae77  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049ae7a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049ae7d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ae7f  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0049ae82  2b0dd0a64c00           -sub ecx, dword ptr [0x4ca6d0]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
    // 0049ae88  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ae8a  7e02                   -jle 0x49ae8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ae8e;
    }
    // 0049ae8c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049ae8e:
    // 0049ae8e  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0049ae94  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ae96  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0049ae9d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ae9f  0f8ef3010000           -jle 0x49b098
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b098;
    }
    // 0049aea5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049aea7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049aea9:
    // 0049aea9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049aeab  7e0c                   -jle 0x49aeb9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049aeb9;
    }
    // 0049aead  3b1dcca64c00           +cmp ebx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aeb3  0f8ded010000           -jge 0x49b0a6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b0a6;
    }
L_0x0049aeb9:
    // 0049aeb9  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049aec0  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049aec7  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049aece  43                     -inc ebx
    (cpu.ebx)++;
    // 0049aecf  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049aed1  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049aed3  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0049aed7  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0049aedb  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049aede  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049aee0  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049aee4  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0049aeeb  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0049aeef  01c7                   +add edi, eax
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
    // 0049aef1  e96effffff             -jmp 0x49ae64
    goto L_0x0049ae64;
L_0x0049aef6:
    // 0049aef6  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049aef9  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0049af00  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049af04  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0049af0b  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049af0e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049af10  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049af14  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049af18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049af1a  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049af1c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049af20  e84bfbffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049af25  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049af29  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0049af30  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049af33  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049af36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049af38  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049af3c  29ca                   +sub edx, ecx
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
    // 0049af3e  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049af42  e993feffff             -jmp 0x49adda
    goto L_0x0049adda;
L_0x0049af47:
    // 0049af47  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049af4b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049af4e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049af50  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049af52  2b442444               +sub eax, dword ptr [esp + 0x44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049af56  e815fbffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049af5b  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049af5f  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0049af63  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049af67  e804fbffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049af6c  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0049af70  e9c3feffff             -jmp 0x49ae38
    goto L_0x0049ae38;
L_0x0049af75:
    // 0049af75  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049af79  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049af7d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049af80  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049af82  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049af84  3b0dc8a64c00           +cmp ecx, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049af8a  0f8cc9feffff           -jl 0x49ae59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ae59;
    }
    // 0049af90  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049af92  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049af98  0f8dbbfeffff           -jge 0x49ae59
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ae59;
    }
    // 0049af9e  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049afa2  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afa8  0f8cabfeffff           -jl 0x49ae59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ae59;
    }
    // 0049afae  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afb4  0f8d9ffeffff           -jge 0x49ae59
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ae59;
    }
    // 0049afba  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049afbe  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afc4  0f8c8ffeffff           -jl 0x49ae59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ae59;
    }
    // 0049afca  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049afd0  0f8d83feffff           -jge 0x49ae59
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ae59;
    }
    // 0049afd6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049afdd  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049afe0  8944247c               -mov dword ptr [esp + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0049afe4  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
L_0x0049afe8:
    // 0049afe8  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049afec  3b44245c               +cmp eax, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049aff0  0f8d17010000           -jge 0x49b10d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b10d;
    }
    // 0049aff6  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049affd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049afff  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b002  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b005  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b007  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b009  7e50                   -jle 0x49b05b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b05b;
    }
    // 0049b00b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b00c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049b00e  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049b015  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b018  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049b01b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b01d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b020  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b022  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b026  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b02d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b031  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049b033  8b8c2480000000         -mov ecx, dword ptr [esp + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0049b03a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b03b  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049b040  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b043  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b045  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049b04a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b04c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049b04e  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049b050  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b051  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b058  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0049b05b:
    // 0049b05b  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049b062  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b069  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049b070  43                     -inc ebx
    (cpu.ebx)++;
    // 0049b071  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b073  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b075  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049b079  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0049b07d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b080  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b082  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049b086  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0049b08d  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0049b091  01c7                   +add edi, eax
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
    // 0049b093  e950ffffff             -jmp 0x49afe8
    goto L_0x0049afe8;
L_0x0049b098:
    // 0049b098  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049b09a  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0049b0a1  e903feffff             -jmp 0x49aea9
    goto L_0x0049aea9;
L_0x0049b0a6:
    // 0049b0a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b0a7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049b0a9  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049b0b0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b0b3  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049b0b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b0b8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b0bb  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b0bd  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049b0c4  030c853cae5200         -add ecx, dword ptr [eax*4 + 0x52ae3c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418556) /* 0x52ae3c */ + cpu.eax * 4)));
    // 0049b0cb  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b0ce  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b0d2  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b0d9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b0dd  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049b0e1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049b0e3  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049b0e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b0e8  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049b0ed  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049b0f3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b0f5  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049b0f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b0fb  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049b0fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b0fe  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b105  83c40c                 +add esp, 0xc
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
    // 0049b108  e9acfdffff             -jmp 0x49aeb9
    goto L_0x0049aeb9;
L_0x0049b10d:
    // 0049b10d  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049b111  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049b115  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b118  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b11a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049b11e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b121  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b124  39c3                   +cmp ebx, eax
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
    // 0049b126  0f8d4a030000           -jge 0x49b476
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b476;
    }
    // 0049b12c  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 0049b131  0f8471010000           -je 0x49b2a8
    if (cpu.flags.zf)
    {
        goto L_0x0049b2a8;
    }
    // 0049b137  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049b13b  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049b13f  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b142  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049b144  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b146  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049b148  e823f9ffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049b14d  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049b151  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0049b155  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049b159  e812f9ffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049b15e  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0049b162  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049b166  8984249c000000         -mov dword ptr [esp + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0049b16d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049b171  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049b175  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b178  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b17a  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049b17e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049b182  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b184  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b187  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049b18a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049b18e  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0049b195  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049b199  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b19b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049b19f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b1a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b1a5  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049b1a7  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0049b1ae  e8bdf8ffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049b1b3  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049b1b7  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0049b1be  2b5104                 -sub edx, dword ptr [ecx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049b1c1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b1c5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b1c9  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049b1cc  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049b1cf  e89cf8ffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049b1d4  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x0049b1db:
    // 0049b1db  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049b1df  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049b1e3  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0049b1e6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b1e8  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b1eb  a1d4a64c00             -mov eax, dword ptr [0x4ca6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0049b1f0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b1f3  39c2                   +cmp edx, eax
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
    // 0049b1f5  7e02                   -jle 0x49b1f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b1f9;
    }
    // 0049b1f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049b1f9:
    // 0049b1f9  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0049b1ff  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0049b203  39cb                   +cmp ebx, ecx
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
    // 0049b205  0f8dcf000000           -jge 0x49b2da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b2da;
    }
L_0x0049b20b:
    // 0049b20b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049b212  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x0049b216:
    // 0049b216  3b5c2454               +cmp ebx, dword ptr [esp + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b21a  0f8d56020000           -jge 0x49b476
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b476;
    }
    // 0049b220  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049b227  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b229  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b22c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b22f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b231  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0049b234  2b0dd0a64c00           -sub ecx, dword ptr [0x4ca6d0]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
    // 0049b23a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b23c  7e02                   -jle 0x49b240
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b240;
    }
    // 0049b23e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049b240:
    // 0049b240  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0049b246  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049b248  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0049b24f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049b251  0f8eab010000           -jle 0x49b402
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b402;
    }
    // 0049b257  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b259  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049b25b:
    // 0049b25b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b25d  7e0c                   -jle 0x49b26b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b26b;
    }
    // 0049b25f  3b1dcca64c00           +cmp ebx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b265  0f8da5010000           -jge 0x49b410
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b410;
    }
L_0x0049b26b:
    // 0049b26b  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049b272  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b279  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049b280  43                     -inc ebx
    (cpu.ebx)++;
    // 0049b281  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b283  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b285  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0049b289  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049b28d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b290  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b292  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0049b296  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0049b29d  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0049b2a1  01c7                   +add edi, eax
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
    // 0049b2a3  e96effffff             -jmp 0x49b216
    goto L_0x0049b216;
L_0x0049b2a8:
    // 0049b2a8  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0049b2ac  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049b2af  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049b2b3  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049b2b5  2b01                   +sub eax, dword ptr [ecx]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049b2b7  e8b4f7ffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049b2bc  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049b2c0  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0049b2c4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049b2c8  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049b2cc  e89ff7ffff             -call 0x49aa70
    cpu.esp -= 4;
    sub_49aa70(app, cpu);
    if (cpu.terminate) return;
    // 0049b2d1  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0049b2d5  e901ffffff             -jmp 0x49b1db
    goto L_0x0049b1db;
L_0x0049b2da:
    // 0049b2da  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049b2de  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049b2e2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049b2e5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b2e7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049b2e9  3b0dc8a64c00           +cmp ecx, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b2ef  0f8c16ffffff           -jl 0x49b20b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b20b;
    }
    // 0049b2f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049b2f7  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b2fd  0f8d08ffffff           -jge 0x49b20b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b20b;
    }
    // 0049b303  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049b307  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b30d  0f8cf8feffff           -jl 0x49b20b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b20b;
    }
    // 0049b313  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b319  0f8decfeffff           -jge 0x49b20b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b20b;
    }
    // 0049b31f  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049b323  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b329  0f8cdcfeffff           -jl 0x49b20b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b20b;
    }
    // 0049b32f  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b335  0f8dd0feffff           -jge 0x49b20b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b20b;
    }
    // 0049b33b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049b342  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b345  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0049b349  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
L_0x0049b34d:
    // 0049b34d  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049b351  3b442458               +cmp eax, dword ptr [esp + 0x58]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b355  0f8d1b010000           -jge 0x49b476
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049b476;
    }
    // 0049b35b  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049b362  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049b364  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b367  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b36a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b36c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b36e  7e55                   -jle 0x49b3c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b3c5;
    }
    // 0049b370  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b371  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049b373  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049b37a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b37d  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049b380  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049b382  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049b385  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b387  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0049b38e  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b395  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0049b39c  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049b39e  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0049b3a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b3a3  8b15e8a64c00           -mov edx, dword ptr [0x4ca6e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049b3a9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049b3ac  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b3ae  8b15eca64c00           -mov edx, dword ptr [0x4ca6ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049b3b4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b3b6  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049b3b8  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049b3ba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b3bb  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b3c2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0049b3c5:
    // 0049b3c5  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0049b3cc  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b3d3  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049b3da  43                     -inc ebx
    (cpu.ebx)++;
    // 0049b3db  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b3dd  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049b3df  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0049b3e3  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049b3e7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b3ea  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b3ec  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0049b3f0  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0049b3f7  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0049b3fb  01c7                   +add edi, eax
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
    // 0049b3fd  e94bffffff             -jmp 0x49b34d
    goto L_0x0049b34d;
L_0x0049b402:
    // 0049b402  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049b404  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0049b40b  e94bfeffff             -jmp 0x49b25b
    goto L_0x0049b25b;
L_0x0049b410:
    // 0049b410  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b411  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049b413  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0049b41a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b41d  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049b420  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049b422  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b425  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b427  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0049b42e  030c853cae5200         -add ecx, dword ptr [eax*4 + 0x52ae3c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418556) /* 0x52ae3c */ + cpu.eax * 4)));
    // 0049b435  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0049b43c  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0049b443  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0049b44a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049b44c  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0049b450  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b451  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0049b456  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049b459  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b45b  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0049b460  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b462  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049b464  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0049b466  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049b467  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b46e  83c40c                 +add esp, 0xc
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
    // 0049b471  e9f5fdffff             -jmp 0x49b26b
    goto L_0x0049b26b;
L_0x0049b476:
    // 0049b476  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b47d  0f84a6f7ffff           -je 0x49ac29
    if (cpu.flags.zf)
    {
        goto L_0x0049ac29;
    }
    // 0049b483  0f77                   -emms 
    cpu.mmx.init();
    // 0049b485  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049b48b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b48c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b48d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b48e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b48f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b490  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b491  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049b494  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049b496  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049b499  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b49f  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049b4a2  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049b4a5  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049b4a8  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b4ae  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049b4b2  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049b4b5  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049b4b8  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b4be  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049b4c2  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049b4c5  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049b4c8  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b4ce  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049b4d2  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049b4d5  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049b4d8  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b4de  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049b4e2  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0049b4e5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b4e8  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b4ee  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049b4f2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049b4f4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b4f7  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b4fd  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049b501  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049b504  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b507  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b50d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049b511  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049b514  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b517  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b51d  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049b521  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0049b524  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b527  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b52d  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049b531  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049b534  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b537  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b53d  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049b541  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0049b544  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049b547  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049b54d  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049b551  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0049b555  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049b557  e838f5ffff             -call 0x49aa94
    cpu.esp -= 4;
    sub_49aa94(app, cpu);
    if (cpu.terminate) return;
    // 0049b55c  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049b55f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b560  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b573  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049b576  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049b57a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049b57c  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049b57e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049b582  47                     -inc edi
    (cpu.edi)++;
    // 0049b583  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 0049b585  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049b587  7e5b                   -jle 0x49b5e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049b5e4;
    }
    // 0049b589  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049b58c  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 0049b58e  745d                   -je 0x49b5ed
    if (cpu.flags.zf)
    {
        goto L_0x0049b5ed;
    }
L_0x0049b590:
    // 0049b590  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049b592  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b595  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049b598  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049b59c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049b59e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b5a1  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049b5a4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049b5a8  030c24                 -add ecx, dword ptr [esp]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0049b5ab  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0049b5ad  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b5b1  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049b5b3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049b5b5  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b5b8  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049b5bb  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b5bd  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049b5c0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049b5c2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049b5c5  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049b5c9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b5cc  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b5cf  034c2404               -add ecx, dword ptr [esp + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049b5d3  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049b5d6  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b5da  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b5dc  01cb                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049b5de  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b5df  75af                   -jne 0x49b590
    if (!cpu.flags.zf)
    {
        goto L_0x0049b590;
    }
    // 0049b5e1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049b5e4:
    // 0049b5e4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049b5e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b5ea  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049b5ed:
    // 0049b5ed  e8eec60000             -call 0x4a7ce0
    cpu.esp -= 4;
    sub_4a7ce0(app, cpu);
    if (cpu.terminate) return;
    // 0049b5f2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0049b5f6:
    // 0049b5f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b5f8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b5fb  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b5ff  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049b601  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049b604  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b606  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b609  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b60c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b60e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b612  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b614  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b616  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0049b618  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b61b  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049b61f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049b621  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b623  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049b626  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049b628  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049b62b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049b62e  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b631  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049b633  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049b636  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049b63a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b63c  01cb                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049b63e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049b63f  75b5                   -jne 0x49b5f6
    if (!cpu.flags.zf)
    {
        goto L_0x0049b5f6;
    }
    // 0049b641  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049b644  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b645  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b646  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b647  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49b650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b650  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49b654(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b654  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b655  a100a44c00             -mov eax, dword ptr [0x4ca400]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
    // 0049b65a  a320d54c00             -mov dword ptr [0x4cd520], eax
    app->getMemory<x86::reg32>(x86::reg32(5035296) /* 0x4cd520 */) = cpu.eax;
    // 0049b65f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049b661  7502                   -jne 0x49b665
    if (!cpu.flags.zf)
    {
        goto L_0x0049b665;
    }
    // 0049b663  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b664  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b665:
    // 0049b665  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b666  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b667  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b668  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b669  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b66a  b9cc904a00             -mov ecx, 0x4a90cc
    cpu.ecx = 4886732 /*0x4a90cc*/;
    // 0049b66f  bbcc914a00             -mov ebx, 0x4a91cc
    cpu.ebx = 4886988 /*0x4a91cc*/;
    // 0049b674  be9c924a00             -mov esi, 0x4a929c
    cpu.esi = 4887196 /*0x4a929c*/;
    // 0049b679  bf90934a00             -mov edi, 0x4a9390
    cpu.edi = 4887440 /*0x4a9390*/;
    // 0049b67e  bd70944a00             -mov ebp, 0x4a9470
    cpu.ebp = 4887664 /*0x4a9470*/;
    // 0049b683  b8a4944a00             -mov eax, 0x4a94a4
    cpu.eax = 4887716 /*0x4a94a4*/;
    // 0049b688  ba54954a00             -mov edx, 0x4a9554
    cpu.edx = 4887892 /*0x4a9554*/;
    // 0049b68d  890dc8d44c00           -mov dword ptr [0x4cd4c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035208) /* 0x4cd4c8 */) = cpu.ecx;
    // 0049b693  891dccd44c00           -mov dword ptr [0x4cd4cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035212) /* 0x4cd4cc */) = cpu.ebx;
    // 0049b699  8935d0d44c00           -mov dword ptr [0x4cd4d0], esi
    app->getMemory<x86::reg32>(x86::reg32(5035216) /* 0x4cd4d0 */) = cpu.esi;
    // 0049b69f  893dd4d44c00           -mov dword ptr [0x4cd4d4], edi
    app->getMemory<x86::reg32>(x86::reg32(5035220) /* 0x4cd4d4 */) = cpu.edi;
    // 0049b6a5  892df8d44c00           -mov dword ptr [0x4cd4f8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035256) /* 0x4cd4f8 */) = cpu.ebp;
    // 0049b6ab  a3fcd44c00             -mov dword ptr [0x4cd4fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5035260) /* 0x4cd4fc */) = cpu.eax;
    // 0049b6b0  891500d54c00           -mov dword ptr [0x4cd500], edx
    app->getMemory<x86::reg32>(x86::reg32(5035264) /* 0x4cd500 */) = cpu.edx;
    // 0049b6b6  b984954a00             -mov ecx, 0x4a9584
    cpu.ecx = 4887940 /*0x4a9584*/;
    // 0049b6bb  bb04964a00             -mov ebx, 0x4a9604
    cpu.ebx = 4888068 /*0x4a9604*/;
    // 0049b6c0  be68994a00             -mov esi, 0x4a9968
    cpu.esi = 4888936 /*0x4a9968*/;
    // 0049b6c5  bf5c9d4a00             -mov edi, 0x4a9d5c
    cpu.edi = 4889948 /*0x4a9d5c*/;
    // 0049b6ca  bdd0a04a00             -mov ebp, 0x4aa0d0
    cpu.ebp = 4890832 /*0x4aa0d0*/;
    // 0049b6cf  b814a54a00             -mov eax, 0x4aa514
    cpu.eax = 4891924 /*0x4aa514*/;
    // 0049b6d4  890d04d54c00           -mov dword ptr [0x4cd504], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035268) /* 0x4cd504 */) = cpu.ecx;
    // 0049b6da  891d08d54c00           -mov dword ptr [0x4cd508], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035272) /* 0x4cd508 */) = cpu.ebx;
    // 0049b6e0  8935e8d44c00           -mov dword ptr [0x4cd4e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5035240) /* 0x4cd4e8 */) = cpu.esi;
    // 0049b6e6  893decd44c00           -mov dword ptr [0x4cd4ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5035244) /* 0x4cd4ec */) = cpu.edi;
    // 0049b6ec  892df0d44c00           -mov dword ptr [0x4cd4f0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035248) /* 0x4cd4f0 */) = cpu.ebp;
    // 0049b6f2  a3f4d44c00             -mov dword ptr [0x4cd4f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5035252) /* 0x4cd4f4 */) = cpu.eax;
    // 0049b6f7  8935d8d44c00           -mov dword ptr [0x4cd4d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5035224) /* 0x4cd4d8 */) = cpu.esi;
    // 0049b6fd  893ddcd44c00           -mov dword ptr [0x4cd4dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5035228) /* 0x4cd4dc */) = cpu.edi;
    // 0049b703  892de0d44c00           -mov dword ptr [0x4cd4e0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035232) /* 0x4cd4e0 */) = cpu.ebp;
    // 0049b709  a3e4d44c00             -mov dword ptr [0x4cd4e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5035236) /* 0x4cd4e4 */) = cpu.eax;
    // 0049b70e  bf54a54a00             -mov edi, 0x4aa554
    cpu.edi = 4891988 /*0x4aa554*/;
    // 0049b713  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049b715  893d0cd54c00           -mov dword ptr [0x4cd50c], edi
    app->getMemory<x86::reg32>(x86::reg32(5035276) /* 0x4cd50c */) = cpu.edi;
    // 0049b71b  892d1cd54c00           -mov dword ptr [0x4cd51c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035292) /* 0x4cd51c */) = cpu.ebp;
    // 0049b721  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b722  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b723  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b724  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b725  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b727  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b728(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b728  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b729  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b72a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049b72b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049b72c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049b72d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b730  8b1d10d54c00           -mov ebx, dword ptr [0x4cd510]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049b736  8b3518d54c00           -mov esi, dword ptr [0x4cd518]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */);
    // 0049b73c  8b3d14d54c00           -mov edi, dword ptr [0x4cd514]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */);
    // 0049b742  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049b744  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049b746  e815ee0000             -call 0x4aa560
    cpu.esp -= 4;
    sub_4aa560(app, cpu);
    if (cpu.terminate) return;
    // 0049b74b  e8c0ee0000             -call 0x4aa610
    cpu.esp -= 4;
    sub_4aa610(app, cpu);
    if (cpu.terminate) return;
    // 0049b750  e8fbef0000             -call 0x4aa750
    cpu.esp -= 4;
    sub_4aa750(app, cpu);
    if (cpu.terminate) return;
    // 0049b755  e8a6f00000             -call 0x4aa800
    cpu.esp -= 4;
    sub_4aa800(app, cpu);
    if (cpu.terminate) return;
    // 0049b75a  8b3d14d54c00           -mov edi, dword ptr [0x4cd514]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */);
    // 0049b760  8b3518d54c00           -mov esi, dword ptr [0x4cd518]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */);
L_0x0049b766:
    // 0049b766  8b1d10d54c00           -mov ebx, dword ptr [0x4cd510]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049b76c  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 0049b773  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049b775  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049b777  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049b77a  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049b77d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b77f  7518                   -jne 0x49b799
    if (!cpu.flags.zf)
    {
        goto L_0x0049b799;
    }
L_0x0049b781:
    // 0049b781  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 0049b788  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049b78a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049b78c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049b78f  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049b792  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b794  740c                   -je 0x49b7a2
    if (cpu.flags.zf)
    {
        goto L_0x0049b7a2;
    }
    // 0049b796  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049b797  ebe8                   -jmp 0x49b781
    goto L_0x0049b781;
L_0x0049b799:
    // 0049b799  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049b79a  891d10d54c00           -mov dword ptr [0x4cd510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */) = cpu.ebx;
    // 0049b7a0  ebc4                   -jmp 0x49b766
    goto L_0x0049b766;
L_0x0049b7a2:
    // 0049b7a2  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 0049b7a9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049b7ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049b7ad  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049b7b0  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049b7b3  891d10d54c00           -mov dword ptr [0x4cd510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */) = cpu.ebx;
    // 0049b7b9  893518d54c00           -mov dword ptr [0x4cd518], esi
    app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */) = cpu.esi;
    // 0049b7bf  893d14d54c00           -mov dword ptr [0x4cd514], edi
    app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */) = cpu.edi;
    // 0049b7c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049b7c7  7403                   -je 0x49b7cc
    if (cpu.flags.zf)
    {
        goto L_0x0049b7cc;
    }
    // 0049b7c9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049b7ca  ebd6                   -jmp 0x49b7a2
    goto L_0x0049b7a2;
L_0x0049b7cc:
    // 0049b7cc  e883feffff             -call 0x49b654
    cpu.esp -= 4;
    sub_49b654(app, cpu);
    if (cpu.terminate) return;
    // 0049b7d1  892d40f65300           -mov dword ptr [0x53f640], ebp
    app->getMemory<x86::reg32>(x86::reg32(5502528) /* 0x53f640 */) = cpu.ebp;
    // 0049b7d7  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0049b7da  0f84a5000000           -je 0x49b885
    if (cpu.flags.zf)
    {
        goto L_0x0049b885;
    }
    // 0049b7e0  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0049b7e5  8b3d14d54c00           -mov edi, dword ptr [0x4cd514]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */);
    // 0049b7eb  8b3518d54c00           -mov esi, dword ptr [0x4cd518]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */);
    // 0049b7f1  a104d54c00             -mov eax, dword ptr [0x4cd504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035268) /* 0x4cd504 */);
    // 0049b7f6  8b1d10d54c00           -mov ebx, dword ptr [0x4cd510]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
L_0x0049b7fc:
    // 0049b7fc  a344f65300             -mov dword ptr [0x53f644], eax
    app->getMemory<x86::reg32>(x86::reg32(5502532) /* 0x53f644 */) = cpu.eax;
    // 0049b801  891548f65300           -mov dword ptr [0x53f648], edx
    app->getMemory<x86::reg32>(x86::reg32(5502536) /* 0x53f648 */) = cpu.edx;
L_0x0049b807:
    // 0049b807  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0049b80a  0f84ec000000           -je 0x49b8fc
    if (cpu.flags.zf)
    {
        goto L_0x0049b8fc;
    }
    // 0049b810  c7054cf6530044ac0000   -mov dword ptr [0x53f64c], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = 44100 /*0xac44*/;
L_0x0049b81a:
    // 0049b81a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b81c  893518d54c00           -mov dword ptr [0x4cd518], esi
    app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */) = cpu.esi;
    // 0049b822  893d14d54c00           -mov dword ptr [0x4cd514], edi
    app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */) = cpu.edi;
L_0x0049b828:
    // 0049b828  05e40d0000             -add eax, 0xde4
    (cpu.eax) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 0049b82d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049b82f  8890180a5300           -mov byte ptr [eax + 0x530a18], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5442072) /* 0x530a18 */) = cpu.dl;
    // 0049b835  3d40de0000             +cmp eax, 0xde40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56896 /*0xde40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049b83a  75ec                   -jne 0x49b828
    if (!cpu.flags.zf)
    {
        goto L_0x0049b828;
    }
    // 0049b83c  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0049b841  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b842  891d10d54c00           -mov dword ptr [0x4cd510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */) = cpu.ebx;
    // 0049b848  ff1508d54c00           -call dword ptr [0x4cd508]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035272) /* 0x4cd508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b84e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b851  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 0049b856  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 0049b85b  6824d94c00             -push 0x4cd924
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036324 /*0x4cd924*/;
    cpu.esp -= 4;
    // 0049b860  a33cf65300             -mov dword ptr [0x53f63c], eax
    app->getMemory<x86::reg32>(x86::reg32(5502524) /* 0x53f63c */) = cpu.eax;
    // 0049b865  ff1508d54c00           -call dword ptr [0x4cd508]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035272) /* 0x4cd508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049b86b  8b1d10d54c00           -mov ebx, dword ptr [0x4cd510]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049b871  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049b874  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049b876  891d10d54c00           -mov dword ptr [0x4cd510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */) = cpu.ebx;
    // 0049b87c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b87f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b880  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b882  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b883  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b884  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b885:
    // 0049b885  8b3d14d54c00           -mov edi, dword ptr [0x4cd514]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */);
    // 0049b88b  8b3518d54c00           -mov esi, dword ptr [0x4cd518]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */);
    // 0049b891  8b1d10d54c00           -mov ebx, dword ptr [0x4cd510]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049b897  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0049b89a  7419                   -je 0x49b8b5
    if (cpu.flags.zf)
    {
        goto L_0x0049b8b5;
    }
    // 0049b89c  a1fcd44c00             -mov eax, dword ptr [0x4cd4fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035260) /* 0x4cd4fc */);
    // 0049b8a1  a344f65300             -mov dword ptr [0x53f644], eax
    app->getMemory<x86::reg32>(x86::reg32(5502532) /* 0x53f644 */) = cpu.eax;
    // 0049b8a6  c70548f6530000020000   -mov dword ptr [0x53f648], 0x200
    app->getMemory<x86::reg32>(x86::reg32(5502536) /* 0x53f648 */) = 512 /*0x200*/;
    // 0049b8b0  e952ffffff             -jmp 0x49b807
    goto L_0x0049b807;
L_0x0049b8b5:
    // 0049b8b5  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0049b8b8  741a                   -je 0x49b8d4
    if (cpu.flags.zf)
    {
        goto L_0x0049b8d4;
    }
    // 0049b8ba  a100d54c00             -mov eax, dword ptr [0x4cd500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035264) /* 0x4cd500 */);
    // 0049b8bf  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 0049b8c4  a344f65300             -mov dword ptr [0x53f644], eax
    app->getMemory<x86::reg32>(x86::reg32(5502532) /* 0x53f644 */) = cpu.eax;
    // 0049b8c9  892d48f65300           -mov dword ptr [0x53f648], ebp
    app->getMemory<x86::reg32>(x86::reg32(5502536) /* 0x53f648 */) = cpu.ebp;
    // 0049b8cf  e933ffffff             -jmp 0x49b807
    goto L_0x0049b807;
L_0x0049b8d4:
    // 0049b8d4  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0049b8d7  740f                   -je 0x49b8e8
    if (cpu.flags.zf)
    {
        goto L_0x0049b8e8;
    }
    // 0049b8d9  a1f8d44c00             -mov eax, dword ptr [0x4cd4f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035256) /* 0x4cd4f8 */);
    // 0049b8de  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049b8e3  e914ffffff             -jmp 0x49b7fc
    goto L_0x0049b7fc;
L_0x0049b8e8:
    // 0049b8e8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049b8ed  891d10d54c00           -mov dword ptr [0x4cd510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */) = cpu.ebx;
    // 0049b8f3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b8f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b8fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b8fc:
    // 0049b8fc  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0049b8ff  740f                   -je 0x49b910
    if (cpu.flags.zf)
    {
        goto L_0x0049b910;
    }
    // 0049b901  c7054cf65300007d0000   -mov dword ptr [0x53f64c], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = 32000 /*0x7d00*/;
    // 0049b90b  e90affffff             -jmp 0x49b81a
    goto L_0x0049b81a;
L_0x0049b910:
    // 0049b910  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 0049b913  740f                   -je 0x49b924
    if (cpu.flags.zf)
    {
        goto L_0x0049b924;
    }
    // 0049b915  c7054cf6530022560000   -mov dword ptr [0x53f64c], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = 22050 /*0x5622*/;
    // 0049b91f  e9f6feffff             -jmp 0x49b81a
    goto L_0x0049b81a;
L_0x0049b924:
    // 0049b924  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0049b927  740f                   -je 0x49b938
    if (cpu.flags.zf)
    {
        goto L_0x0049b938;
    }
    // 0049b929  c7054cf65300803e0000   -mov dword ptr [0x53f64c], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = 16000 /*0x3e80*/;
    // 0049b933  e9e2feffff             -jmp 0x49b81a
    goto L_0x0049b81a;
L_0x0049b938:
    // 0049b938  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 0049b93b  740f                   -je 0x49b94c
    if (cpu.flags.zf)
    {
        goto L_0x0049b94c;
    }
    // 0049b93d  c7054cf65300112b0000   -mov dword ptr [0x53f64c], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = 11025 /*0x2b11*/;
    // 0049b947  e9cefeffff             -jmp 0x49b81a
    goto L_0x0049b81a;
L_0x0049b94c:
    // 0049b94c  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 0049b94f  740f                   -je 0x49b960
    if (cpu.flags.zf)
    {
        goto L_0x0049b960;
    }
    // 0049b951  c7054cf65300401f0000   -mov dword ptr [0x53f64c], 0x1f40
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = 8000 /*0x1f40*/;
    // 0049b95b  e9bafeffff             -jmp 0x49b81a
    goto L_0x0049b81a;
L_0x0049b960:
    // 0049b960  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049b965  893518d54c00           -mov dword ptr [0x4cd518], esi
    app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */) = cpu.esi;
    // 0049b96b  893d14d54c00           -mov dword ptr [0x4cd514], edi
    app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */) = cpu.edi;
    // 0049b971  891d10d54c00           -mov dword ptr [0x4cd510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */) = cpu.ebx;
    // 0049b977  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049b97a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b97f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49b980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049b980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049b981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049b982  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049b983  8b154cf65300           -mov edx, dword ptr [0x53f64c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */);
    // 0049b989  8b0d44f65300           -mov ecx, dword ptr [0x53f644]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5502532) /* 0x53f644 */);
    // 0049b98f  8b1d48f65300           -mov ebx, dword ptr [0x53f648]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5502536) /* 0x53f648 */);
    // 0049b995  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0049b997  7435                   -je 0x49b9ce
    if (cpu.flags.zf)
    {
        goto L_0x0049b9ce;
    }
    // 0049b999  bb00040000             -mov ebx, 0x400
    cpu.ebx = 1024 /*0x400*/;
    // 0049b99e  8b0d04d54c00           -mov ecx, dword ptr [0x4cd504]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035268) /* 0x4cd504 */);
L_0x0049b9a4:
    // 0049b9a4  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 0049b9a7  745f                   -je 0x49ba08
    if (cpu.flags.zf)
    {
        goto L_0x0049ba08;
    }
    // 0049b9a9  ba44ac0000             -mov edx, 0xac44
    cpu.edx = 44100 /*0xac44*/;
L_0x0049b9ae:
    // 0049b9ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049b9b0:
    // 0049b9b0  40                     -inc eax
    (cpu.eax)++;
    // 0049b9b1  83f810                 +cmp eax, 0x10
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
    // 0049b9b4  7cfa                   -jl 0x49b9b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049b9b0;
    }
    // 0049b9b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049b9b8:
    // 0049b9b8  891d48f65300           -mov dword ptr [0x53f648], ebx
    app->getMemory<x86::reg32>(x86::reg32(5502536) /* 0x53f648 */) = cpu.ebx;
    // 0049b9be  890d44f65300           -mov dword ptr [0x53f644], ecx
    app->getMemory<x86::reg32>(x86::reg32(5502532) /* 0x53f644 */) = cpu.ecx;
    // 0049b9c4  89154cf65300           -mov dword ptr [0x53f64c], edx
    app->getMemory<x86::reg32>(x86::reg32(5502540) /* 0x53f64c */) = cpu.edx;
    // 0049b9ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049b9cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049b9ce:
    // 0049b9ce  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0049b9d0  740d                   -je 0x49b9df
    if (cpu.flags.zf)
    {
        goto L_0x0049b9df;
    }
    // 0049b9d2  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 0049b9d7  8b0dfcd44c00           -mov ecx, dword ptr [0x4cd4fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035260) /* 0x4cd4fc */);
    // 0049b9dd  ebc5                   -jmp 0x49b9a4
    goto L_0x0049b9a4;
L_0x0049b9df:
    // 0049b9df  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0049b9e1  740d                   -je 0x49b9f0
    if (cpu.flags.zf)
    {
        goto L_0x0049b9f0;
    }
    // 0049b9e3  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 0049b9e8  8b0d00d54c00           -mov ecx, dword ptr [0x4cd500]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035264) /* 0x4cd500 */);
    // 0049b9ee  ebb4                   -jmp 0x49b9a4
    goto L_0x0049b9a4;
L_0x0049b9f0:
    // 0049b9f0  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0049b9f2  740d                   -je 0x49ba01
    if (cpu.flags.zf)
    {
        goto L_0x0049ba01;
    }
    // 0049b9f4  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0049b9f9  8b0df8d44c00           -mov ecx, dword ptr [0x4cd4f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035256) /* 0x4cd4f8 */);
    // 0049b9ff  eba3                   -jmp 0x49b9a4
    goto L_0x0049b9a4;
L_0x0049ba01:
    // 0049ba01  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049ba06  ebb0                   -jmp 0x49b9b8
    goto L_0x0049b9b8;
L_0x0049ba08:
    // 0049ba08  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0049ba0b  7407                   -je 0x49ba14
    if (cpu.flags.zf)
    {
        goto L_0x0049ba14;
    }
    // 0049ba0d  ba007d0000             -mov edx, 0x7d00
    cpu.edx = 32000 /*0x7d00*/;
    // 0049ba12  eb9a                   -jmp 0x49b9ae
    goto L_0x0049b9ae;
L_0x0049ba14:
    // 0049ba14  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 0049ba17  7407                   -je 0x49ba20
    if (cpu.flags.zf)
    {
        goto L_0x0049ba20;
    }
    // 0049ba19  ba22560000             -mov edx, 0x5622
    cpu.edx = 22050 /*0x5622*/;
    // 0049ba1e  eb8e                   -jmp 0x49b9ae
    goto L_0x0049b9ae;
L_0x0049ba20:
    // 0049ba20  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0049ba23  7407                   -je 0x49ba2c
    if (cpu.flags.zf)
    {
        goto L_0x0049ba2c;
    }
    // 0049ba25  ba803e0000             -mov edx, 0x3e80
    cpu.edx = 16000 /*0x3e80*/;
    // 0049ba2a  eb82                   -jmp 0x49b9ae
    goto L_0x0049b9ae;
L_0x0049ba2c:
    // 0049ba2c  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 0049ba2f  740a                   -je 0x49ba3b
    if (cpu.flags.zf)
    {
        goto L_0x0049ba3b;
    }
    // 0049ba31  ba112b0000             -mov edx, 0x2b11
    cpu.edx = 11025 /*0x2b11*/;
    // 0049ba36  e973ffffff             -jmp 0x49b9ae
    goto L_0x0049b9ae;
L_0x0049ba3b:
    // 0049ba3b  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0049ba3e  74c1                   -je 0x49ba01
    if (cpu.flags.zf)
    {
        goto L_0x0049ba01;
    }
    // 0049ba40  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 0049ba45  e964ffffff             -jmp 0x49b9ae
    goto L_0x0049b9ae;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49ba4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ba4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ba4d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ba4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ba4f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ba52  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049ba56  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ba59  8d34c500000000         -lea esi, [eax*8]
    cpu.esi = x86::reg32(cpu.eax * 8);
    // 0049ba60  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba62  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ba64  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 0049ba67  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ba69  81c6fc175300           -add esi, 0x5317fc
    (cpu.esi) += x86::reg32(x86::sreg32(5445628 /*0x5317fc*/));
    // 0049ba6f  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0049ba72  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049ba75  c64609ff               -mov byte ptr [esi + 9], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 255 /*0xff*/;
    // 0049ba79  8986600d0000           -mov dword ptr [esi + 0xd60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */) = cpu.eax;
    // 0049ba7f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0049ba82  7559                   -jne 0x49badd
    if (!cpu.flags.zf)
    {
        goto L_0x0049badd;
    }
    // 0049ba84  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0049ba87  0f847a000000           -je 0x49bb07
    if (cpu.flags.zf)
    {
        goto L_0x0049bb07;
    }
    // 0049ba8d  a1d4d44c00             -mov eax, dword ptr [0x4cd4d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035220) /* 0x4cd4d4 */);
    // 0049ba92  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049ba95  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0049ba9a  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ba9d  7f60                   -jg 0x49baff
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049baff;
    }
    // 0049ba9f  8b3de4d44c00           -mov edi, dword ptr [0x4cd4e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035236) /* 0x4cd4e4 */);
L_0x0049baa5:
    // 0049baa5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049baa7  0f85bc000000           -jne 0x49bb69
    if (!cpu.flags.zf)
    {
        goto L_0x0049bb69;
    }
L_0x0049baad:
    // 0049baad  83f901                 +cmp ecx, 1
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
    // 0049bab0  0f8520010000           -jne 0x49bbd6
    if (!cpu.flags.zf)
    {
        goto L_0x0049bbd6;
    }
    // 0049bab6  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 0049babb  7e02                   -jle 0x49babf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049babf;
    }
L_0x0049babd:
    // 0049babd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049babf:
    // 0049babf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bac2  83b850d44c0000         +cmp dword ptr [eax + 0x4cd450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5035088) /* 0x4cd450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bac9  0f851e010000           -jne 0x49bbed
    if (!cpu.flags.zf)
    {
        goto L_0x0049bbed;
    }
L_0x0049bacf:
    // 0049bacf  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 0049bad4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bad7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bad9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bada  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049badd:
    // 0049badd  a1d0d44c00             -mov eax, dword ptr [0x4cd4d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035216) /* 0x4cd4d0 */);
    // 0049bae2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049bae5  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0049baea  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049baed  7f08                   -jg 0x49baf7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049baf7;
    }
    // 0049baef  8b3de0d44c00           -mov edi, dword ptr [0x4cd4e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035232) /* 0x4cd4e0 */);
    // 0049baf5  ebae                   -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049baf7:
    // 0049baf7  8b3df0d44c00           -mov edi, dword ptr [0x4cd4f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035248) /* 0x4cd4f0 */);
    // 0049bafd  eba6                   -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049baff:
    // 0049baff  8b3df4d44c00           -mov edi, dword ptr [0x4cd4f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035252) /* 0x4cd4f4 */);
    // 0049bb05  eb9e                   -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049bb07:
    // 0049bb07  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0049bb0a  7422                   -je 0x49bb2e
    if (cpu.flags.zf)
    {
        goto L_0x0049bb2e;
    }
    // 0049bb0c  a1c8d44c00             -mov eax, dword ptr [0x4cd4c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035208) /* 0x4cd4c8 */);
    // 0049bb11  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049bb14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bb16  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bb19  7f08                   -jg 0x49bb23
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049bb23;
    }
    // 0049bb1b  8b3dd8d44c00           -mov edi, dword ptr [0x4cd4d8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035224) /* 0x4cd4d8 */);
    // 0049bb21  eb82                   -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049bb23:
    // 0049bb23  8b3de8d44c00           -mov edi, dword ptr [0x4cd4e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035240) /* 0x4cd4e8 */);
    // 0049bb29  e977ffffff             -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049bb2e:
    // 0049bb2e  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0049bb31  7428                   -je 0x49bb5b
    if (cpu.flags.zf)
    {
        goto L_0x0049bb5b;
    }
    // 0049bb33  a1ccd44c00             -mov eax, dword ptr [0x4cd4cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035212) /* 0x4cd4cc */);
    // 0049bb38  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049bb3b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0049bb40  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bb43  7f0b                   -jg 0x49bb50
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049bb50;
    }
    // 0049bb45  8b3ddcd44c00           -mov edi, dword ptr [0x4cd4dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035228) /* 0x4cd4dc */);
    // 0049bb4b  e955ffffff             -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049bb50:
    // 0049bb50  8b3decd44c00           -mov edi, dword ptr [0x4cd4ec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035244) /* 0x4cd4ec */);
    // 0049bb56  e94affffff             -jmp 0x49baa5
    goto L_0x0049baa5;
L_0x0049bb5b:
    // 0049bb5b  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 0049bb60  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bb63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb66  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049bb69:
    // 0049bb69  83fb07                 +cmp ebx, 7
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
    // 0049bb6c  752c                   -jne 0x49bb9a
    if (!cpu.flags.zf)
    {
        goto L_0x0049bb9a;
    }
    // 0049bb6e  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0049bb71  740a                   -je 0x49bb7d
    if (cpu.flags.zf)
    {
        goto L_0x0049bb7d;
    }
    // 0049bb73  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0049bb78  e930ffffff             -jmp 0x49baad
    goto L_0x0049baad;
L_0x0049bb7d:
    // 0049bb7d  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0049bb80  740a                   -je 0x49bb8c
    if (cpu.flags.zf)
    {
        goto L_0x0049bb8c;
    }
    // 0049bb82  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0049bb87  e921ffffff             -jmp 0x49baad
    goto L_0x0049baad;
L_0x0049bb8c:
    // 0049bb8c  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0049bb91  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bb94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bb97  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049bb9a:
    // 0049bb9a  83fb09                 +cmp ebx, 9
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
    // 0049bb9d  750f                   -jne 0x49bbae
    if (!cpu.flags.zf)
    {
        goto L_0x0049bbae;
    }
L_0x0049bb9f:
    // 0049bb9f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0049bba2  74e8                   -je 0x49bb8c
    if (cpu.flags.zf)
    {
        goto L_0x0049bb8c;
    }
    // 0049bba4  b81b000000             -mov eax, 0x1b
    cpu.eax = 27 /*0x1b*/;
    // 0049bba9  e9fffeffff             -jmp 0x49baad
    goto L_0x0049baad;
L_0x0049bbae:
    // 0049bbae  83fb08                 +cmp ebx, 8
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
    // 0049bbb1  74ec                   -je 0x49bb9f
    if (cpu.flags.zf)
    {
        goto L_0x0049bb9f;
    }
    // 0049bbb3  83fb02                 +cmp ebx, 2
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
    // 0049bbb6  75a3                   -jne 0x49bb5b
    if (!cpu.flags.zf)
    {
        goto L_0x0049bb5b;
    }
    // 0049bbb8  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0049bbbb  740a                   -je 0x49bbc7
    if (cpu.flags.zf)
    {
        goto L_0x0049bbc7;
    }
    // 0049bbbd  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0049bbc2  e9e6feffff             -jmp 0x49baad
    goto L_0x0049baad;
L_0x0049bbc7:
    // 0049bbc7  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0049bbca  74c0                   -je 0x49bb8c
    if (cpu.flags.zf)
    {
        goto L_0x0049bb8c;
    }
    // 0049bbcc  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 0049bbd1  e9d7feffff             -jmp 0x49baad
    goto L_0x0049baad;
L_0x0049bbd6:
    // 0049bbd6  83f902                 +cmp ecx, 2
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
    // 0049bbd9  0f84defeffff           -je 0x49babd
    if (cpu.flags.zf)
    {
        goto L_0x0049babd;
    }
    // 0049bbdf  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 0049bbe4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bbe7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bbe8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bbe9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bbea  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049bbed:
    // 0049bbed  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049bbef  8d86ac0d0000           -lea eax, [esi + 0xdac]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3500) /* 0xdac */);
    // 0049bbf5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bbf6  8d86a80d0000           -lea eax, [esi + 0xda8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    // 0049bbfc  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bc00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc01  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bc05  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049bc09  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bc0a  8b86600d0000           -mov eax, dword ptr [esi + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 0049bc10  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bc14  ff9550d44c00           -call dword ptr [ebp + 0x4cd450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5035088) /* 0x4cd450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bc1a  833c2400               +cmp dword ptr [esp], 0
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
    // 0049bc1e  0f84abfeffff           -je 0x49bacf
    if (cpu.flags.zf)
    {
        goto L_0x0049bacf;
    }
    // 0049bc24  8d86bc0d0000           -lea eax, [esi + 0xdbc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    // 0049bc2a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc2b  8d86c00d0000           -lea eax, [esi + 0xdc0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    // 0049bc31  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc32  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 0049bc38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc39  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bc3d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bc40  8d86dc0d0000           -lea eax, [esi + 0xddc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3548) /* 0xddc */);
    // 0049bc46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc47  8d86e00d0000           -lea eax, [esi + 0xde0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    // 0049bc4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc4e  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 0049bc54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc55  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bc59  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bc5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049bc5e  0f846bfeffff           -je 0x49bacf
    if (cpu.flags.zf)
    {
        goto L_0x0049bacf;
    }
    // 0049bc64  8d86b80d0000           -lea eax, [esi + 0xdb8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    // 0049bc6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc6b  8d86b40d0000           -lea eax, [esi + 0xdb4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    // 0049bc71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc72  8d86b00d0000           -lea eax, [esi + 0xdb0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    // 0049bc78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc79  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 0049bc7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bc80  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bc82  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bc85  817c242c00000800       +cmp dword ptr [esp + 0x2c], 0x80000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bc8d  7608                   -jbe 0x49bc97
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049bc97;
    }
    // 0049bc8f  c744242c00000800       -mov dword ptr [esp + 0x2c], 0x80000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 524288 /*0x80000*/;
L_0x0049bc97:
    // 0049bc97  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049bc9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bc9c  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 0049bca2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bca3  ff96b00d0000           -call dword ptr [esi + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bca9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049bcac  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bcb0  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049bcb3  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bcb7  884602                 -mov byte ptr [esi + 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0049bcba  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049bcbe  884604                 -mov byte ptr [esi + 4], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0049bcc1  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bcc5  884605                 -mov byte ptr [esi + 5], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 0049bcc8  8a442434               -mov al, byte ptr [esp + 0x34]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049bccc  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0049bccf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bcd1  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bcd5  e826020000             -call 0x49bf00
    cpu.esp -= 4;
    sub_49bf00(app, cpu);
    if (cpu.terminate) return;
    // 0049bcda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bcdb  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049bcdf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bce0  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 0049bce6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bce7  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bced  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bcf0  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 0049bcf3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bcf5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049bcf8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcf9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcfa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bcfb  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49bd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bd02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049bd03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049bd04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049bd05  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bd08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049bd0a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049bd0c  05c40d0000             -add eax, 0xdc4
    (cpu.eax) += x86::reg32(x86::sreg32(3524 /*0xdc4*/));
    // 0049bd11  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049bd14  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bd16  05900d0000             -add eax, 0xd90
    (cpu.eax) += x86::reg32(x86::sreg32(3472 /*0xd90*/));
    // 0049bd1b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049bd1f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bd21  05640d0000             -add eax, 0xd64
    (cpu.eax) += x86::reg32(x86::sreg32(3428 /*0xd64*/));
    // 0049bd26  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049bd28  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0049bd2c:
    // 0049bd2c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049bd2f  3a4604                 +cmp al, byte ptr [esi + 4]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bd32  0f84cd000000           -je 0x49be05
    if (cpu.flags.zf)
    {
        goto L_0x0049be05;
    }
L_0x0049bd38:
    // 0049bd38  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049bd3a  0f84d1000000           -je 0x49be11
    if (cpu.flags.zf)
    {
        goto L_0x0049be11;
    }
    // 0049bd40  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049bd43  8a7604                 -mov dh, byte ptr [esi + 4]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049bd46  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049bd47  38f0                   +cmp al, dh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bd49  0f85cd000000           -jne 0x49be1c
    if (!cpu.flags.zf)
    {
        goto L_0x0049be1c;
    }
L_0x0049bd4f:
    // 0049bd4f  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049bd52  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049bd55  7406                   -je 0x49bd5d
    if (cpu.flags.zf)
    {
        goto L_0x0049bd5d;
    }
    // 0049bd57  8a4607                 -mov al, byte ptr [esi + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 0049bd5a  004602                 -add byte ptr [esi + 2], al
    (app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)) += x86::reg8(x86::sreg8(cpu.al));
L_0x0049bd5d:
    // 0049bd5d  0fbe4602               -movsx eax, byte ptr [esi + 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)));
    // 0049bd61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bd62  0fbe4601               -movsx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
    // 0049bd66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bd67  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049bd6b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bd6c  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bd72  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bd75  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049bd77  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049bd7b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bd7c  ff96b40d0000           -call dword ptr [esi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bd82  8b0d14d54c00           -mov ecx, dword ptr [0x4cd514]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */);
    // 0049bd88  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049bd8b  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bd8e  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049bd92  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049bd96  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 0049bd9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bd9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049bda0  ff96a80d0000           -call dword ptr [esi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bda6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049bda8  7c67                   -jl 0x49be11
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049be11;
    }
    // 0049bdaa  a118d54c00             -mov eax, dword ptr [0x4cd518]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */);
    // 0049bdaf  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049bdb3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049bdb7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049bdbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bdbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bdbd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049bdbf  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049bdc3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049bdc4  ff96b80d0000           -call dword ptr [esi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bdca  8a0d1cd54c00           -mov cl, byte ptr [0x4cd51c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5035292) /* 0x4cd51c */);
    // 0049bdd0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049bdd2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049bdd4  8b0d10d54c00           -mov ecx, dword ptr [0x4cd510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049bdda  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bddd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bde0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bde2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bde3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049bde7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049bde8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049bdea  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049bdee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bdef  ff96c00d0000           -call dword ptr [esi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bdf5  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049bdf8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049bdfb  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0049bdfd  7528                   -jne 0x49be27
    if (!cpu.flags.zf)
    {
        goto L_0x0049be27;
    }
    // 0049bdff  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049be00  e927ffffff             -jmp 0x49bd2c
    goto L_0x0049bd2c;
L_0x0049be05:
    // 0049be05  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0049be08  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049be0b  0f8527ffffff           -jne 0x49bd38
    if (!cpu.flags.zf)
    {
        goto L_0x0049bd38;
    }
L_0x0049be11:
    // 0049be11  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049be13  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049be16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be17  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049be1c:
    // 0049be1c  8a4606                 -mov al, byte ptr [esi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049be1f  004601                 +add byte ptr [esi + 1], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049be22  e928ffffff             -jmp 0x49bd4f
    goto L_0x0049bd4f;
L_0x0049be27:
    // 0049be27  8a0d1cd54c00           -mov cl, byte ptr [0x4cd51c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5035292) /* 0x4cd51c */);
    // 0049be2d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049be2f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049be31  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049be34  0524d94c00             -add eax, 0x4cd924
    (cpu.eax) += x86::reg32(x86::sreg32(5036324 /*0x4cd924*/));
    // 0049be39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049be3a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049be3e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049be3f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049be41  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049be45  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049be46  ff96e00d0000           -call dword ptr [esi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049be4c  83c410                 +add esp, 0x10
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
    // 0049be4f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049be50  e9d7feffff             -jmp 0x49bd2c
    goto L_0x0049bd2c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49be58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049be58  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049be59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049be5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049be5b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049be5d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049be60  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049be62  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049be65  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049be67  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049be69  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0049be6c  bffc175300             -mov edi, 0x5317fc
    cpu.edi = 5445628 /*0x5317fc*/;
    // 0049be71  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049be73  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049be75  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049be78  7509                   -jne 0x49be83
    if (!cpu.flags.zf)
    {
        goto L_0x0049be83;
    }
    // 0049be7a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049be7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049be82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049be83:
    // 0049be83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049be84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049be85  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049be87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049be89  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049be8b  e8c0000000             -call 0x49bf50
    cpu.esp -= 4;
    sub_49bf50(app, cpu);
    if (cpu.terminate) return;
    // 0049be90  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049be95  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049be97  e864feffff             -call 0x49bd00
    cpu.esp -= 4;
    sub_49bd00(app, cpu);
    if (cpu.terminate) return;
    // 0049be9c  ff150cd54c00           -call dword ptr [0x4cd50c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035276) /* 0x4cd50c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bea2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049bea4  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 0049bea7  ff1540f65300           -call dword ptr [0x53f640]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5502528) /* 0x53f640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bead  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049beaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049beb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49beb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049beb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049beb9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049bebb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bebe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bec0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049bec3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bec5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bec7  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0049beca  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049becc  05fc175300             -add eax, 0x5317fc
    (cpu.eax) += x86::reg32(x86::sreg32(5445628 /*0x5317fc*/));
    // 0049bed1  803800                 +cmp byte ptr [eax], 0
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
    // 0049bed4  7422                   -je 0x49bef8
    if (cpu.flags.zf)
    {
        goto L_0x0049bef8;
    }
    // 0049bed6  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bedc  7605                   -jbe 0x49bee3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049bee3;
    }
    // 0049bede  b900000800             -mov ecx, 0x80000
    cpu.ecx = 524288 /*0x80000*/;
L_0x0049bee3:
    // 0049bee3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bee4  8d90640d0000           -lea edx, [eax + 0xd64]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3428) /* 0xd64 */);
    // 0049beea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049beeb  ff90b00d0000           -call dword ptr [eax + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bef1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049bef4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bef6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bef7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bef8:
    // 0049bef8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049befd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049befe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49bf00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bf01  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0049bf04  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0049bf06  7505                   -jne 0x49bf0d
    if (!cpu.flags.zf)
    {
        goto L_0x0049bf0d;
    }
    // 0049bf08  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 0049bf0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bf0d:
    // 0049bf0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf0e  8b5001                 -mov edx, dword ptr [eax + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049bf11  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049bf14  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049bf17  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0049bf1a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049bf1c  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0049bf1e  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 0049bf21  8b4805                 -mov ecx, dword ptr [eax + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0049bf24  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049bf26  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0049bf29  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049bf2c  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049bf2f  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 0049bf32  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 0049bf35  8b5005                 -mov edx, dword ptr [eax + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0049bf38  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049bf3b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bf3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bf3d  8d90c40d0000           -lea edx, [eax + 0xdc4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3524) /* 0xdc4 */);
    // 0049bf43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bf44  ff90dc0d0000           -call dword ptr [eax + 0xddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3548) /* 0xddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049bf4a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049bf4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49bf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bf50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049bf51  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049bf53  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bf56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bf58  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049bf5b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bf5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bf5f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0049bf62  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bf64  05fc175300             -add eax, 0x5317fc
    (cpu.eax) += x86::reg32(x86::sreg32(5445628 /*0x5317fc*/));
    // 0049bf69  803800                 +cmp byte ptr [eax], 0
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
    // 0049bf6c  7427                   -je 0x49bf95
    if (cpu.flags.zf)
    {
        goto L_0x0049bf95;
    }
    // 0049bf6e  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
    // 0049bf71  0fbe5001               -movsx edx, byte ptr [eax + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */)));
    // 0049bf75  885805                 -mov byte ptr [eax + 5], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = cpu.bl;
    // 0049bf78  39ca                   +cmp edx, ecx
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
    // 0049bf7a  7c20                   -jl 0x49bf9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049bf9c;
    }
    // 0049bf7c  c64006ff               -mov byte ptr [eax + 6], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 255 /*0xff*/;
L_0x0049bf80:
    // 0049bf80  0fbe5002               -movsx edx, byte ptr [eax + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */)));
    // 0049bf84  39da                   +cmp edx, ebx
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
    // 0049bf86  7d1a                   -jge 0x49bfa2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049bfa2;
    }
    // 0049bf88  c6400701               -mov byte ptr [eax + 7], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 1 /*0x1*/;
    // 0049bf8c  e86fffffff             -call 0x49bf00
    cpu.esp -= 4;
    sub_49bf00(app, cpu);
    if (cpu.terminate) return;
    // 0049bf91  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049bf93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bf95:
    // 0049bf95  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049bf9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bf9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bf9c:
    // 0049bf9c  c6400601               -mov byte ptr [eax + 6], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 0049bfa0  ebde                   -jmp 0x49bf80
    goto L_0x0049bf80;
L_0x0049bfa2:
    // 0049bfa2  c64007ff               -mov byte ptr [eax + 7], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 255 /*0xff*/;
    // 0049bfa6  e855ffffff             -call 0x49bf00
    cpu.esp -= 4;
    sub_49bf00(app, cpu);
    if (cpu.terminate) return;
    // 0049bfab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bfad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049bfae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49bfb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bfb0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bfb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bfb5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049bfb8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bfbc  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0049bfbf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfc1  05fc175300             -add eax, 0x5317fc
    (cpu.eax) += x86::reg32(x86::sreg32(5445628 /*0x5317fc*/));
    // 0049bfc6  803800                 +cmp byte ptr [eax], 0
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
    // 0049bfc9  7506                   -jne 0x49bfd1
    if (!cpu.flags.zf)
    {
        goto L_0x0049bfd1;
    }
    // 0049bfcb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049bfd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049bfd1:
    // 0049bfd1  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 0049bfd4  e827ffffff             -call 0x49bf00
    cpu.esp -= 4;
    sub_49bf00(app, cpu);
    if (cpu.terminate) return;
    // 0049bfd9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049bfdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49bfdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049bfdc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049bfdd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049bfe0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bfe2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049bfe5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfe7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049bfe9  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0049bfec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049bfee  bafc175300             -mov edx, 0x5317fc
    cpu.edx = 5445628 /*0x5317fc*/;
    // 0049bff3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049bff5  83baac0d000000         +cmp dword ptr [edx + 0xdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049bffc  7507                   -jne 0x49c005
    if (!cpu.flags.zf)
    {
        goto L_0x0049c005;
    }
    // 0049bffe  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049c003  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c004  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c005:
    // 0049c005  8b82600d0000           -mov eax, dword ptr [edx + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3424) /* 0xd60 */);
    // 0049c00b  ff92ac0d0000           -call dword ptr [edx + 0xdac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c011  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c012  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c014  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c015  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c016  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c019  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c01d  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c021  ff150cd54c00           -call dword ptr [0x4cd50c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035276) /* 0x4cd50c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c027  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049c02b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049c02e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c030  39cb                   +cmp ebx, ecx
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
    // 0049c032  7320                   -jae 0x49c054
    if (!cpu.flags.cf)
    {
        goto L_0x0049c054;
    }
L_0x0049c034:
    // 0049c034  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049c036  0fbf16                 -movsx edx, word ptr [esi]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi)));
    // 0049c039  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049c03c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c03e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c041  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c044  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c047  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 0049c04a  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c04d  39cb                   +cmp ebx, ecx
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
    // 0049c04f  72e3                   -jb 0x49c034
    if (cpu.flags.cf)
    {
        goto L_0x0049c034;
    }
    // 0049c051  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049c054:
    // 0049c054  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c057  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c058  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c05c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c05c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c05d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c05e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c061  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049c065  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049c069  ff150cd54c00           -call dword ptr [0x4cd50c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035276) /* 0x4cd50c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c06f  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049c073  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049c076  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049c078  39ce                   +cmp esi, ecx
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
    // 0049c07a  0f8390000000           -jae 0x49c110
    if (!cpu.flags.cf)
    {
        goto L_0x0049c110;
    }
L_0x0049c080:
    // 0049c080  df03                   -fild word ptr [ebx]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx))));
    // 0049c082  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 0049c084  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c088  df4302                 -fild word ptr [ebx + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */))));
    // 0049c08b  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 0049c08d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c091  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0049c095  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049c097  dd0538144c00           -fld qword ptr [0x4c1438]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4985912) /* 0x4c1438 */)));
    // 0049c09d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049c09f  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049c0a1  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c0a4  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c0a6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049c0a8  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c0ac  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049c0b0  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049c0b2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c0b6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049c0b8  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c0ba  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c0be  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c0c2  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0049c0c7  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0049c0cd  3dff7f0000             +cmp eax, 0x7fff
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
    // 0049c0d2  7649                   -jbe 0x49c11d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c11d;
    }
    // 0049c0d4  3d00800f00             +cmp eax, 0xf8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0d9  7342                   -jae 0x49c11d
    if (!cpu.flags.cf)
    {
        goto L_0x0049c11d;
    }
    // 0049c0db  3d00000800             +cmp eax, 0x80000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0e0  7334                   -jae 0x49c116
    if (!cpu.flags.cf)
    {
        goto L_0x0049c116;
    }
    // 0049c0e2  66c703ff7f             -mov word ptr [ebx], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx) = 32767 /*0x7fff*/;
L_0x0049c0e7:
    // 0049c0e7  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0ed  763b                   -jbe 0x49c12a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049c12a;
    }
    // 0049c0ef  81fa00800f00           +cmp edx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0f5  7333                   -jae 0x49c12a
    if (!cpu.flags.cf)
    {
        goto L_0x0049c12a;
    }
    // 0049c0f7  81fa00000800           +cmp edx, 0x80000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c0fd  7323                   -jae 0x49c122
    if (!cpu.flags.cf)
    {
        goto L_0x0049c122;
    }
    // 0049c0ff  66c74302ff7f           -mov word ptr [ebx + 2], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32767 /*0x7fff*/;
L_0x0049c105:
    // 0049c105  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c108  39ce                   +cmp esi, ecx
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
    // 0049c10a  0f8270ffffff           -jb 0x49c080
    if (cpu.flags.cf)
    {
        goto L_0x0049c080;
    }
L_0x0049c110:
    // 0049c110  83c410                 +add esp, 0x10
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
    // 0049c113  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c114  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c115  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c116:
    // 0049c116  66c7030080             -mov word ptr [ebx], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx) = 32768 /*0x8000*/;
    // 0049c11b  ebca                   -jmp 0x49c0e7
    goto L_0x0049c0e7;
L_0x0049c11d:
    // 0049c11d  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 0049c120  ebc5                   -jmp 0x49c0e7
    goto L_0x0049c0e7;
L_0x0049c122:
    // 0049c122  66c743020080           -mov word ptr [ebx + 2], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32768 /*0x8000*/;
    // 0049c128  ebdb                   -jmp 0x49c105
    goto L_0x0049c105;
L_0x0049c12a:
    // 0049c12a  66895302               -mov word ptr [ebx + 2], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 0049c12e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c131  39ce                   +cmp esi, ecx
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
    // 0049c133  0f8247ffffff           -jb 0x49c080
    if (cpu.flags.cf)
    {
        goto L_0x0049c080;
    }
    // 0049c139  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c13c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c13d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c13e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c142  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c144  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c145  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0049c148  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0049c14c  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0049c150  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c152  befc175300             -mov esi, 0x5317fc
    cpu.esi = 5445628 /*0x5317fc*/;
    // 0049c157  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0049c15b  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x0049c15f:
    // 0049c15f  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 0049c161  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049c163  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049c165  0f85bb000000           -jne 0x49c226
    if (!cpu.flags.zf)
    {
        goto L_0x0049c226;
    }
L_0x0049c16b:
    // 0049c16b  8b6c2460               -mov ebp, dword ptr [esp + 0x60]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049c16f  45                     -inc ebp
    (cpu.ebp)++;
    // 0049c170  81c6e40d0000           -add esi, 0xde4
    (cpu.esi) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 0049c176  896c2460               -mov dword ptr [esp + 0x60], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ebp;
    // 0049c17a  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c17d  7ce0                   -jl 0x49c15f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c15f;
    }
L_0x0049c17f:
    // 0049c17f  837c245000             +cmp dword ptr [esp + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c184  0f8498010000           -je 0x49c322
    if (cpu.flags.zf)
    {
        goto L_0x0049c322;
    }
    // 0049c18a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049c18c  89353cf65300           -mov dword ptr [0x53f63c], esi
    app->getMemory<x86::reg32>(x86::reg32(5502524) /* 0x53f63c */) = cpu.esi;
L_0x0049c192:
    // 0049c192  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049c196  8b3d20d54c00           -mov edi, dword ptr [0x4cd520]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5035296) /* 0x4cd520 */);
    // 0049c19c  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c19e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049c1a0  0f849a010000           -je 0x49c340
    if (cpu.flags.zf)
    {
        goto L_0x0049c340;
    }
    // 0049c1a6  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0049c1ab  6824d94c00             -push 0x4cd924
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036324 /*0x4cd924*/;
    cpu.esp -= 4;
    // 0049c1b0  8b74245c               -mov esi, dword ptr [esp + 0x5c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0049c1b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c1b5  e85afeffff             -call 0x49c014
    cpu.esp -= 4;
    sub_49c014(app, cpu);
    if (cpu.terminate) return;
    // 0049c1ba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c1bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c1be  6824d94c00             -push 0x4cd924
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036324 /*0x4cd924*/;
    cpu.esp -= 4;
    // 0049c1c3  ff1508d54c00           -call dword ptr [0x4cd508]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035272) /* 0x4cd508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c1c9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c1cc  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0049c1d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c1d2  e879e60000             -call 0x4aa850
    cpu.esp -= 4;
    sub_4aa850(app, cpu);
    if (cpu.terminate) return;
    // 0049c1d7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c1da  8b2d10d54c00           -mov ebp, dword ptr [0x4cd510]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049c1e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c1e1  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0049c1e6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c1e7  e870feffff             -call 0x49c05c
    cpu.esp -= 4;
    sub_49c05c(app, cpu);
    if (cpu.terminate) return;
    // 0049c1ec  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0049c1ef:
    // 0049c1ef  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049c1f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c1f4  8b0d10d54c00           -mov ecx, dword ptr [0x4cd510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049c1fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c1fb  8b5c245c               -mov ebx, dword ptr [esp + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0049c1ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c200  ff1544f65300           -call dword ptr [0x53f644]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5502532) /* 0x53f644 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c206  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c209  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0049c20c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c20d  8b3510d54c00           -mov esi, dword ptr [0x4cd510]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049c213  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c214  ff1508d54c00           -call dword ptr [0x4cd508]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035272) /* 0x4cd508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c21a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c21d  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0049c220  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c221  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c222  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c223  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c224  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c225  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c226:
    // 0049c226  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049c22a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c22c  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049c230  e8cbfaffff             -call 0x49bd00
    cpu.esp -= 4;
    sub_49bd00(app, cpu);
    if (cpu.terminate) return;
    // 0049c235  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 0049c239  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c23b  0f843effffff           -je 0x49c17f
    if (cpu.flags.zf)
    {
        goto L_0x0049c17f;
    }
    // 0049c241  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c242  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 0049c248  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c249  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0049c24d  ff97b40d0000           -call dword ptr [edi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c253  8b0d14d54c00           -mov ecx, dword ptr [0x4cd514]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035284) /* 0x4cd514 */);
    // 0049c259  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c25c  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c25f  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 0049c263  8d5c2440               -lea ebx, [esp + 0x40]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049c267  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 0049c26d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c26f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c271  ff97a80d0000           -call dword ptr [edi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c277  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c279  0f8c95000000           -jl 0x49c314
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c314;
    }
    // 0049c27f  8b0d18d54c00           -mov ecx, dword ptr [0x4cd518]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035288) /* 0x4cd518 */);
    // 0049c285  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049c289  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 0049c28d  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049c291  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c292  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c294  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049c298  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c299  ff97b80d0000           -call dword ptr [edi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c29f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c2a2  8a0d1cd54c00           -mov cl, byte ptr [0x4cd51c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5035292) /* 0x4cd51c */);
    // 0049c2a8  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0049c2ac  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049c2ae  8b0d10d54c00           -mov ecx, dword ptr [0x4cd510]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049c2b4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049c2b7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c2b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2ba  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049c2be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c2bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c2c0  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 0049c2c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2c7  ff97c00d0000           -call dword ptr [edi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c2cd  8a5608                 -mov dl, byte ptr [esi + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049c2d0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c2d3  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0049c2d5  0f8490feffff           -je 0x49c16b
    if (cpu.flags.zf)
    {
        goto L_0x0049c16b;
    }
    // 0049c2db  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0049c2df  8a0d1cd54c00           -mov cl, byte ptr [0x4cd51c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5035292) /* 0x4cd51c */);
    // 0049c2e5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049c2e7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049c2ea  0524d94c00             -add eax, 0x4cd924
    (cpu.eax) += x86::reg32(x86::sreg32(5036324 /*0x4cd924*/));
    // 0049c2ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2f0  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049c2f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c2f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c2f6  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 0049c2fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c2fd  ff97e00d0000           -call dword ptr [edi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c303  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049c308  83c410                 +add esp, 0x10
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
    // 0049c30b  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 0049c30f  e957feffff             -jmp 0x49c16b
    goto L_0x0049c16b;
L_0x0049c314:
    // 0049c314  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049c318  e83bfbffff             -call 0x49be58
    cpu.esp -= 4;
    sub_49be58(app, cpu);
    if (cpu.terminate) return;
    // 0049c31d  e949feffff             -jmp 0x49c16b
    goto L_0x0049c16b;
L_0x0049c322:
    // 0049c322  8b0d3cf65300           -mov ecx, dword ptr [0x53f63c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5502524) /* 0x53f63c */);
    // 0049c328  41                     -inc ecx
    (cpu.ecx)++;
    // 0049c329  890d3cf65300           -mov dword ptr [0x53f63c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5502524) /* 0x53f63c */) = cpu.ecx;
    // 0049c32f  81f9f4010000           +cmp ecx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c335  0f8c57feffff           -jl 0x49c192
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c192;
    }
    // 0049c33b  e9affeffff             -jmp 0x49c1ef
    goto L_0x0049c1ef;
L_0x0049c340:
    // 0049c340  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0049c345  6824d94c00             -push 0x4cd924
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036324 /*0x4cd924*/;
    cpu.esp -= 4;
    // 0049c34a  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0049c34e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c34f  e8cce60000             -call 0x4aaa20
    cpu.esp -= 4;
    sub_4aaa20(app, cpu);
    if (cpu.terminate) return;
    // 0049c354  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c357  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c358  6824d94c00             -push 0x4cd924
    app->getMemory<x86::reg32>(cpu.esp-4) = 5036324 /*0x4cd924*/;
    cpu.esp -= 4;
    // 0049c35d  ff1508d54c00           -call dword ptr [0x4cd508]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035272) /* 0x4cd508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c363  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c366  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0049c36b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c36c  e8dfe40000             -call 0x4aa850
    cpu.esp -= 4;
    sub_4aa850(app, cpu);
    if (cpu.terminate) return;
    // 0049c371  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c374  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0049c378  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c379  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049c37d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c37e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c382  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c383  e8b0b90000             -call 0x4a7d38
    cpu.esp -= 4;
    sub_4a7d38(app, cpu);
    if (cpu.terminate) return;
    // 0049c388  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c38b  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 0049c38d  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 0049c38f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c393  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c394  ff542450               -call dword ptr [esp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c398  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c39b  8b1510d54c00           -mov edx, dword ptr [0x4cd510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5035280) /* 0x4cd510 */);
    // 0049c3a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c3a2  6824d54c00             -push 0x4cd524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5035300 /*0x4cd524*/;
    cpu.esp -= 4;
    // 0049c3a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c3a8  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c3ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c3ad  ff542458               -call dword ptr [esp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c3b1  83c410                 +add esp, 0x10
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
    // 0049c3b4  e936feffff             -jmp 0x49c1ef
    goto L_0x0049c1ef;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c3bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c3bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c3bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c3be  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049c3c0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c3c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c3c4  7e28                   -jle 0x49c3ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c3ee;
    }
L_0x0049c3c6:
    // 0049c3c6  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c3cc  7e23                   -jle 0x49c3f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c3f1;
    }
    // 0049c3ce  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
L_0x0049c3d3:
    // 0049c3d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c3d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c3d7  e864fdffff             -call 0x49c140
    cpu.esp -= 4;
    sub_49c140(app, cpu);
    if (cpu.terminate) return;
    // 0049c3dc  8b1548f65300           -mov edx, dword ptr [0x53f648]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5502536) /* 0x53f648 */);
    // 0049c3e2  81e900010000           -sub ecx, 0x100
    (cpu.ecx) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0049c3e8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c3ea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c3ec  7fd8                   -jg 0x49c3c6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c3c6;
    }
L_0x0049c3ee:
    // 0049c3ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c3f1:
    // 0049c3f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c3f3  ebde                   -jmp 0x49c3d3
    goto L_0x0049c3d3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c400  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c401  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c402  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c403  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c404  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c405  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c408  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c40c  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0049c410  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 0049c414  e8f7fbfdff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0049c419  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x0049c41c:
    // 0049c41c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049c421  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c424  7f11                   -jg 0x49c437
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c437;
    }
    // 0049c426  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x0049c429:
    // 0049c429  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c42c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c42e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c431  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c433  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c435  750f                   -jne 0x49c446
    if (!cpu.flags.zf)
    {
        goto L_0x0049c446;
    }
L_0x0049c437:
    // 0049c437  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c43a  39f9                   +cmp ecx, edi
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
    // 0049c43c  740f                   -je 0x49c44d
    if (cpu.flags.zf)
    {
        goto L_0x0049c44d;
    }
    // 0049c43e  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0049c441  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0049c444  ebd6                   -jmp 0x49c41c
    goto L_0x0049c41c;
L_0x0049c446:
    // 0049c446  41                     -inc ecx
    (cpu.ecx)++;
    // 0049c447  39f1                   +cmp ecx, esi
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
    // 0049c449  7ede                   -jle 0x49c429
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c429;
    }
    // 0049c44b  ebea                   -jmp 0x49c437
    goto L_0x0049c437;
L_0x0049c44d:
    // 0049c44d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c44f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c452  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c453  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c454  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c455  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c456  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c457  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c45c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c45c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c45d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c45e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c45f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c462  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c464  c7442408cdcccc3d       -mov dword ptr [esp + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 0049c46c  3d22560000             +cmp eax, 0x5622
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c471  0f8f96000000           -jg 0x49c50d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c50d;
    }
    // 0049c477  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049c479:
    // 0049c479  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c47c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c47e  898a5cf65300           -mov dword ptr [edx + 0x53f65c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5502556) /* 0x53f65c */) = cpu.ecx;
    // 0049c484  81fa10590000           +cmp edx, 0x5910
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22800 /*0x5910*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c48a  75ed                   -jne 0x49c479
    if (!cpu.flags.zf)
    {
        goto L_0x0049c479;
    }
    // 0049c48c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c48d  b960f65300             -mov ecx, 0x53f660
    cpu.ecx = 5502560 /*0x53f660*/;
    // 0049c492  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049c494:
    // 0049c494  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c497  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0049c49b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c49d  898a8c4f5400           -mov dword ptr [edx + 0x544f8c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525388) /* 0x544f8c */) = cpu.ecx;
    // 0049c4a3  e858ffffff             -call 0x49c400
    cpu.esp -= 4;
    sub_49c400(app, cpu);
    if (cpu.terminate) return;
    // 0049c4a8  d98230e14c00           -fld dword ptr [edx + 0x4ce130]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(5038384) /* 0x4ce130 */)));
    // 0049c4ae  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049c4b0  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0049c4b2  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0049c4b9  d99a40e14c00           -fstp dword ptr [edx + 0x4ce140]
    app->getMemory<float>(cpu.edx + x86::reg32(5038400) /* 0x4ce140 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c4bf  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0049c4c3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049c4c5  dc0d40144c00           -fmul qword ptr [0x4c1440]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4985920) /* 0x4c1440 */));
    // 0049c4cb  8b828c4f5400           -mov eax, dword ptr [edx + 0x544f8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525388) /* 0x544f8c */);
    // 0049c4d1  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c4d3  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c4d6  89826c4f5400           -mov dword ptr [edx + 0x544f6c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525356) /* 0x544f6c */) = cpu.eax;
    // 0049c4dc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c4de  89827c4f5400           -mov dword ptr [edx + 0x544f7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525372) /* 0x544f7c */) = cpu.eax;
    // 0049c4e4  899aac4f5400           -mov dword ptr [edx + 0x544fac], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525420) /* 0x544fac */) = cpu.ebx;
    // 0049c4ea  899a4cf65300           -mov dword ptr [edx + 0x53f64c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5502540) /* 0x53f64c */) = cpu.ebx;
    // 0049c4f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c4f2  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c4f4  899a9c4f5400           -mov dword ptr [edx + 0x544f9c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525404) /* 0x544f9c */) = cpu.ebx;
    // 0049c4fa  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049c4fe  83fa10                 +cmp edx, 0x10
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
    // 0049c501  7591                   -jne 0x49c494
    if (!cpu.flags.zf)
    {
        goto L_0x0049c494;
    }
    // 0049c503  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c505  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c506  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c509  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c50a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c50b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c50c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c50d:
    // 0049c50d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049c512  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c515  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c516  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c517  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c518  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c520  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c521  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c524  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c526  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c528  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049c52c  e81fe50000             -call 0x4aaa50
    cpu.esp -= 4;
    sub_4aaa50(app, cpu);
    if (cpu.terminate) return;
    // 0049c531  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0049c535  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c537  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049c53b  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0049c53f  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049c541  d80d48144c00           -fmul dword ptr [0x4c1448]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4985928) /* 0x4c1448 */));
    // 0049c547  e8c4fafdff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 0049c54c  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049c54f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049c552  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c555  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c560  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0049c562  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0049c564  83f840                 +cmp eax, 0x40
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
    // 0049c567  740a                   -je 0x49c573
    if (cpu.flags.zf)
    {
        goto L_0x0049c573;
    }
    // 0049c569  7d09                   -jge 0x49c574
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c574;
    }
    // 0049c56b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049c56e  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049c571  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0049c573:
    // 0049c573  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c574:
    // 0049c574  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 0049c579  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c57b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c57d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049c580  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0049c583  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049c585  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c592  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c593  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c595  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049c597:
    // 0049c597  4a                     -dec edx
    (cpu.edx)--;
    // 0049c598  83faff                 +cmp edx, -1
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
    // 0049c59b  740c                   -je 0x49c5a9
    if (cpu.flags.zf)
    {
        goto L_0x0049c5a9;
    }
    // 0049c59d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c59f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0049c5a2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049c5a4  40                     -inc eax
    (cpu.eax)++;
    // 0049c5a5  01d9                   +add ecx, ebx
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
    // 0049c5a7  ebee                   -jmp 0x49c597
    goto L_0x0049c597;
L_0x0049c5a9:
    // 0049c5a9  83fe01                 +cmp esi, 1
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
    // 0049c5ac  7505                   -jne 0x49c5b3
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5b3;
    }
    // 0049c5ae  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c5b1  7f26                   -jg 0x49c5d9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c5d9;
    }
L_0x0049c5b3:
    // 0049c5b3  83fe02                 +cmp esi, 2
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
    // 0049c5b6  7508                   -jne 0x49c5c0
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5c0;
    }
    // 0049c5b8  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c5be  7f21                   -jg 0x49c5e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c5e1;
    }
L_0x0049c5c0:
    // 0049c5c0  83fe03                 +cmp esi, 3
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
    // 0049c5c3  750e                   -jne 0x49c5d3
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5d3;
    }
    // 0049c5c5  81f9ffff7f00           +cmp ecx, 0x7fffff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388607 /*0x7fffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c5cb  7e06                   -jle 0x49c5d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c5d3;
    }
    // 0049c5cd  81e900000001           -sub ecx, 0x1000000
    (cpu.ecx) -= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
L_0x0049c5d3:
    // 0049c5d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c5d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c5d9:
    // 0049c5d9  81e900010000           +sub ecx, 0x100
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c5df  ebf2                   -jmp 0x49c5d3
    goto L_0x0049c5d3;
L_0x0049c5e1:
    // 0049c5e1  81e900000100           -sub ecx, 0x10000
    (cpu.ecx) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0049c5e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c5e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c5f0  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0049c5f6  c7809000000000000000   -mov dword ptr [eax + 0x90], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 0049c600  c7406c0f000000         -mov dword ptr [eax + 0x6c], 0xf
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 15 /*0xf*/;
    // 0049c607  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c608(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c608  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049c60f  c740087f000000         -mov dword ptr [eax + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 0049c616  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0049c61d  c740107f000000         -mov dword ptr [eax + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
    // 0049c624  c74014ffffffff         -mov dword ptr [eax + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 0049c62b  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0049c632  c7401c3c000000         -mov dword ptr [eax + 0x1c], 0x3c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 60 /*0x3c*/;
    // 0049c639  c74020ffffffff         -mov dword ptr [eax + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 0049c640  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 0049c647  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0049c64e  c7402c01000000         -mov dword ptr [eax + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 0049c655  c7403040000000         -mov dword ptr [eax + 0x30], 0x40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 64 /*0x40*/;
    // 0049c65c  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 0049c663  c740387f000000         -mov dword ptr [eax + 0x38], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 127 /*0x7f*/;
    // 0049c66a  c7403c00000000         -mov dword ptr [eax + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0049c671  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 0049c678  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0049c67f  c7404800000000         -mov dword ptr [eax + 0x48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 0049c686  c7404c00000000         -mov dword ptr [eax + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 0049c68d  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 0049c694  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 0049c69b  c7406464e14c00         -mov dword ptr [eax + 0x64], 0x4ce164
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 5038436 /*0x4ce164*/;
    // 0049c6a2  c740707f000000         -mov dword ptr [eax + 0x70], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = 127 /*0x7f*/;
    // 0049c6a9  c7407400000000         -mov dword ptr [eax + 0x74], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 0049c6b0  c7407800000000         -mov dword ptr [eax + 0x78], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 0049c6b7  c7407c00000000         -mov dword ptr [eax + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 0049c6be  c7808000000000000000   -mov dword ptr [eax + 0x80], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 0049c6c8  c7808400000000000000   -mov dword ptr [eax + 0x84], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 0049c6d2  c7808c00000000000000   -mov dword ptr [eax + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 0049c6dc  c7808800000000000000   -mov dword ptr [eax + 0x88], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 0049c6e6  c7809400000001000000   -mov dword ptr [eax + 0x94], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
    // 0049c6f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c6f2  81c298000000           -add edx, 0x98
    (cpu.edx) += x86::reg32(x86::sreg32(152 /*0x98*/));
L_0x0049c6f8:
    // 0049c6f8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049c6fe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049c701  39d0                   +cmp eax, edx
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
    // 0049c703  75f3                   -jne 0x49c6f8
    if (!cpu.flags.zf)
    {
        goto L_0x0049c6f8;
    }
    // 0049c705  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49c708(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c708  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c709  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c70a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c70b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c70c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c70d  83784800               +cmp dword ptr [eax + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c711  7552                   -jne 0x49c765
    if (!cpu.flags.zf)
    {
        goto L_0x0049c765;
    }
L_0x0049c713:
    // 0049c713  8b7054                 -mov esi, dword ptr [eax + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0049c716  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c718  7409                   -je 0x49c723
    if (cpu.flags.zf)
    {
        goto L_0x0049c723;
    }
    // 0049c71a  8b4a54                 -mov ecx, dword ptr [edx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 0049c71d  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0049c720  897854                 -mov dword ptr [eax + 0x54], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edi;
L_0x0049c723:
    // 0049c723  8b685c                 -mov ebp, dword ptr [eax + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0049c726  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049c728  7409                   -je 0x49c733
    if (cpu.flags.zf)
    {
        goto L_0x0049c733;
    }
    // 0049c72a  8b4a5c                 -mov ecx, dword ptr [edx + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 0049c72d  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0049c730  89585c                 -mov dword ptr [eax + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.ebx;
L_0x0049c733:
    // 0049c733  8b7064                 -mov esi, dword ptr [eax + 0x64]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 0049c736  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c738  7409                   -je 0x49c743
    if (cpu.flags.zf)
    {
        goto L_0x0049c743;
    }
    // 0049c73a  8b4a64                 -mov ecx, dword ptr [edx + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    // 0049c73d  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0049c740  897864                 -mov dword ptr [eax + 0x64], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = cpu.edi;
L_0x0049c743:
    // 0049c743  8b6874                 -mov ebp, dword ptr [eax + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0049c746  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049c748  7409                   -je 0x49c753
    if (cpu.flags.zf)
    {
        goto L_0x0049c753;
    }
    // 0049c74a  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 0049c74d  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0049c750  895874                 -mov dword ptr [eax + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ebx;
L_0x0049c753:
    // 0049c753  8bb080000000           -mov esi, dword ptr [eax + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0049c759  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049c75b  7510                   -jne 0x49c76d
    if (!cpu.flags.zf)
    {
        goto L_0x0049c76d;
    }
    // 0049c75d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c75f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c760  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c761  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c762  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c764  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c765:
    // 0049c765  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0049c768  014848                 +add dword ptr [eax + 0x48], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c76b  eba6                   -jmp 0x49c713
    goto L_0x0049c713;
L_0x0049c76d:
    // 0049c76d  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 0049c773  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 0049c776  89b880000000           -mov dword ptr [eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = cpu.edi;
    // 0049c77c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c77e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c77f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c780  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c781  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c782  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c783  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c784(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c784  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c785  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c786  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c787  8a3d6ce14c00           -mov bh, byte ptr [0x4ce16c]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5038444) /* 0x4ce16c */);
    // 0049c78d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x0049c78f:
    // 0049c78f  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0049c791  742a                   -je 0x49c7bd
    if (cpu.flags.zf)
    {
        goto L_0x0049c7bd;
    }
L_0x0049c793:
    // 0049c793  b8d0a75200             -mov eax, 0x52a7d0
    cpu.eax = 5416912 /*0x52a7d0*/;
    // 0049c798  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0049c79a:
    // 0049c79a  3a480c                 +cmp cl, byte ptr [eax + 0xc]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c79d  7407                   -je 0x49c7a6
    if (cpu.flags.zf)
    {
        goto L_0x0049c7a6;
    }
    // 0049c79f  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 0049c7a2  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c7a4  74e9                   -je 0x49c78f
    if (cpu.flags.zf)
    {
        goto L_0x0049c78f;
    }
L_0x0049c7a6:
    // 0049c7a6  42                     -inc edx
    (cpu.edx)++;
    // 0049c7a7  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049c7aa  83fa10                 +cmp edx, 0x10
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
    // 0049c7ad  7ceb                   -jl 0x49c79a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c79a;
    }
    // 0049c7af  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049c7b1  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0049c7b3  883d6ce14c00           -mov byte ptr [0x4ce16c], bh
    app->getMemory<x86::reg8>(x86::reg32(5038444) /* 0x4ce16c */) = cpu.bh;
    // 0049c7b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c7bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c7bd:
    // 0049c7bd  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0049c7bf  ebd2                   -jmp 0x49c793
    goto L_0x0049c793;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c7c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c7c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c7c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c7c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c7c7  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049c7ca  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049c7cd  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049c7d1  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049c7d3  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049c7d5  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049c7d9  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c7dc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049c7df  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049c7e3  8b4305                 -mov eax, dword ptr [ebx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 0049c7e6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049c7e9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049c7ed  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0049c7f0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049c7f3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049c7f7  8b4307                 -mov eax, dword ptr [ebx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 0049c7fa  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049c7fd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c801  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049c803  e800ffffff             -call 0x49c708
    cpu.esp -= 4;
    sub_49c708(app, cpu);
    if (cpu.terminate) return;
    // 0049c808  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c80c  83faff                 +cmp edx, -1
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
    // 0049c80f  0f8429030000           -je 0x49cb3e
    if (cpu.flags.zf)
    {
        goto L_0x0049cb3e;
    }
    // 0049c815  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c817  0f8c2e030000           -jl 0x49cb4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cb4b;
    }
    // 0049c81d  83fa7f                 +cmp edx, 0x7f
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
    // 0049c820  0f8f25030000           -jg 0x49cb4b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cb4b;
    }
L_0x0049c826:
    // 0049c826  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c82a  83f8ff                 +cmp eax, -1
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
    // 0049c82d  0f8526030000           -jne 0x49cb59
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb59;
    }
    // 0049c833  c744241840000000       -mov dword ptr [esp + 0x18], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 64 /*0x40*/;
L_0x0049c83b:
    // 0049c83b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049c83f  83fdff                 +cmp ebp, -1
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
    // 0049c842  0f852c030000           -jne 0x49cb74
    if (!cpu.flags.zf)
    {
        goto L_0x0049cb74;
    }
    // 0049c848  c74424087f000000       -mov dword ptr [esp + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
L_0x0049c850:
    // 0049c850  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0049c853  8b5e34                 -mov ebx, dword ptr [esi + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0049c856  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049c85a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c85c  7411                   -je 0x49c86f
    if (cpu.flags.zf)
    {
        goto L_0x0049c86f;
    }
    // 0049c85e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c860  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c864  e837a30000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 0049c869  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c86b  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x0049c86f:
    // 0049c86f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c873  83f87f                 +cmp eax, 0x7f
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
    // 0049c876  0f8e13030000           -jle 0x49cb8f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cb8f;
    }
    // 0049c87c  c74424147f000000       -mov dword ptr [esp + 0x14], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 127 /*0x7f*/;
L_0x0049c884:
    // 0049c884  8bae94000000           -mov ebp, dword ptr [esi + 0x94]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0049c88a  83fd01                 +cmp ebp, 1
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
    // 0049c88d  7411                   -je 0x49c8a0
    if (cpu.flags.zf)
    {
        goto L_0x0049c8a0;
    }
    // 0049c88f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c893  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049c896  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049c899  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049c89c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0049c8a0:
    // 0049c8a0  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c8a4  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0049c8a8  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049c8ab  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049c8af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c8b1  0f8ceb020000           -jl 0x49cba2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cba2;
    }
    // 0049c8b7  83f87f                 +cmp eax, 0x7f
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
    // 0049c8ba  7e08                   -jle 0x49c8c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c8c4;
    }
    // 0049c8bc  c74424187f000000       -mov dword ptr [esp + 0x18], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 127 /*0x7f*/;
L_0x0049c8c4:
    // 0049c8c4  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049c8c8  83f9ff                 +cmp ecx, -1
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
    // 0049c8cb  0f85dc020000           -jne 0x49cbad
    if (!cpu.flags.zf)
    {
        goto L_0x0049cbad;
    }
    // 0049c8d1  c744241040000000       -mov dword ptr [esp + 0x10], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 64 /*0x40*/;
L_0x0049c8d9:
    // 0049c8d9  b9c04f5400             -mov ecx, 0x544fc0
    cpu.ecx = 5525440 /*0x544fc0*/;
    // 0049c8de  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049c8e1  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0049c8e4  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049c8e7  e820c5ffff             -call 0x498e0c
    cpu.esp -= 4;
    sub_498e0c(app, cpu);
    if (cpu.terminate) return;
    // 0049c8ec  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049c8ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c8f0  0f8c3f020000           -jl 0x49cb35
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cb35;
    }
    // 0049c8f6  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0049c8fd  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c8ff  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0049c902  81c1d0a75200           -add ecx, 0x52a7d0
    (cpu.ecx) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0049c908  8a8694000000           -mov al, byte ptr [esi + 0x94]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0049c90e  884137                 -mov byte ptr [ecx + 0x37], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */) = cpu.al;
    // 0049c911  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0049c915  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 0049c919  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049c91d  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049c921  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c923  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0049c926  668b5910               -mov bx, word ptr [ecx + 0x10]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049c92a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c92c  66895910               -mov word ptr [ecx + 0x10], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.bx;
    // 0049c930  83be9000000000         +cmp dword ptr [esi + 0x90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c937  740c                   -je 0x49c945
    if (cpu.flags.zf)
    {
        goto L_0x0049c945;
    }
    // 0049c939  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049c93d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049c93f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c941  66895110               -mov word ptr [ecx + 0x10], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dx;
L_0x0049c945:
    // 0049c945  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0049c948  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c94a  740b                   -je 0x49c957
    if (cpu.flags.zf)
    {
        goto L_0x0049c957;
    }
    // 0049c94c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c94e  e84da20000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 0049c953  66014110               -add word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x0049c957:
    // 0049c957  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0049c95a  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0049c95d  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 0049c960  894150                 -mov dword ptr [ecx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0049c963  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 0049c966  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 0049c969  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0049c96c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c96e  740b                   -je 0x49c97b
    if (cpu.flags.zf)
    {
        goto L_0x0049c97b;
    }
    // 0049c970  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0049c974  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 0049c977  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0049c97b:
    // 0049c97b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049c97d  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 0049c980  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049c984  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0049c98b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049c98e  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049c991  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0049c994  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0049c997  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c999  7409                   -je 0x49c9a4
    if (cpu.flags.zf)
    {
        goto L_0x0049c9a4;
    }
    // 0049c99b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c99d  e8fea10000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 0049c9a2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c9a4:
    // 0049c9a4  83fa7f                 +cmp edx, 0x7f
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
    // 0049c9a7  0f8e1b020000           -jle 0x49cbc8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cbc8;
    }
    // 0049c9ad  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x0049c9b2:
    // 0049c9b2  0faf542434             -imul edx, dword ptr [esp + 0x34]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 0049c9b7  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0049c9bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c9be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c9c1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c9c3  884130                 -mov byte ptr [ecx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 0049c9c6  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049c9ca  884132                 -mov byte ptr [ecx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 0049c9cd  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049c9d1  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0049c9d4  668b4628               -mov ax, word ptr [esi + 0x28]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0049c9d8  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0049c9db  66894142               -mov word ptr [ecx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 0049c9df  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049c9e3  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 0049c9e6  8b4664                 -mov eax, dword ptr [esi + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 0049c9e9  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049c9ec  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0049c9ef  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049c9f2  c6413500               -mov byte ptr [ecx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 0049c9f6  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049c9f9  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049c9fc  884134                 -mov byte ptr [ecx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 0049c9ff  8a4620                 -mov al, byte ptr [esi + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0049ca02  884136                 -mov byte ptr [ecx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 0049ca05  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0049ca08  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ca0a  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049ca0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ca0f  0f8cc6010000           -jl 0x49cbdb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cbdb;
    }
L_0x0049ca15:
    // 0049ca15  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0049ca18  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ca1b  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0049ca1e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049ca21  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ca23  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ca25  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0049ca28  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049ca2b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049ca2d  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049ca30  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 0049ca33  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0049ca36  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0049ca3c  89415c                 -mov dword ptr [ecx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 0049ca3f  8a4678                 -mov al, byte ptr [esi + 0x78]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0049ca42  88413c                 -mov byte ptr [ecx + 0x3c], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.al;
    // 0049ca45  8a8684000000           -mov al, byte ptr [esi + 0x84]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0049ca4b  88413d                 -mov byte ptr [ecx + 0x3d], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(61) /* 0x3d */) = cpu.al;
    // 0049ca4e  668b8688000000         -mov ax, word ptr [esi + 0x88]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0049ca55  66894140               -mov word ptr [ecx + 0x40], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.ax;
    // 0049ca59  837e7c00               +cmp dword ptr [esi + 0x7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ca5d  0f8484010000           -je 0x49cbe7
    if (cpu.flags.zf)
    {
        goto L_0x0049cbe7;
    }
    // 0049ca63  e8c81dfeff             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0049ca68  8b5e78                 -mov ebx, dword ptr [esi + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0049ca6b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ca6d  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049ca6f  88513e                 -mov byte ptr [ecx + 0x3e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.dl;
L_0x0049ca72:
    // 0049ca72  83be8c00000000         +cmp dword ptr [esi + 0x8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ca79  0f8471010000           -je 0x49cbf0
    if (cpu.flags.zf)
    {
        goto L_0x0049cbf0;
    }
    // 0049ca7f  e8ac1dfeff             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0049ca84  8b9e84000000           -mov ebx, dword ptr [esi + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0049ca8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ca8c  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049ca8e  88513f                 -mov byte ptr [ecx + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = cpu.dl;
L_0x0049ca91:
    // 0049ca91  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ca93  e8283f0000             -call 0x4a09c0
    cpu.esp -= 4;
    sub_4a09c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ca98  8a466c                 -mov al, byte ptr [esi + 0x6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0049ca9b  88410b                 -mov byte ptr [ecx + 0xb], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = cpu.al;
    // 0049ca9e  8a464c                 -mov al, byte ptr [esi + 0x4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 0049caa1  884138                 -mov byte ptr [ecx + 0x38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 0049caa4  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049caa8  884139                 -mov byte ptr [ecx + 0x39], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 0049caab  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049caae  88410a                 -mov byte ptr [ecx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 0049cab1  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0049cab4  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0049cab8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049caba  e831080000             -call 0x49d2f0
    cpu.esp -= 4;
    sub_49d2f0(app, cpu);
    if (cpu.terminate) return;
    // 0049cabf  807f0b00               +cmp byte ptr [edi + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cac3  0f8430010000           -je 0x49cbf9
    if (cpu.flags.zf)
    {
        goto L_0x0049cbf9;
    }
    // 0049cac9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049cacb:
    // 0049cacb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cacc  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049cacf  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049cad2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cad3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cad5  668b470c               -mov ax, word ptr [edi + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049cad9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cada  8b4135                 -mov eax, dword ptr [ecx + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 0049cadd  8b3dc4a75200           -mov edi, dword ptr [0x52a7c4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5416900) /* 0x52a7c4 */);
    // 0049cae3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049cae6  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049cae9  8b5136                 -mov edx, dword ptr [ecx + 0x36]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(54) /* 0x36 */);
    // 0049caec  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049caef  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049caf2  bb013f0000             -mov ebx, 0x3f01
    cpu.ebx = 16129 /*0x3f01*/;
    // 0049caf7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049caf9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049cafc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049cafe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049caff  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049cb02  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049cb05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cb06  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 0049cb09  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049cb0c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049cb10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cb11  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0049cb15  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049cb17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cb18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cb1a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049cb1c  8a4202                 -mov al, byte ptr [edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049cb1f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049cb23  e89030feff             -call 0x47fbb8
    cpu.esp -= 4;
    sub_47fbb8(app, cpu);
    if (cpu.terminate) return;
    // 0049cb28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb2a  0f8cd3000000           -jl 0x49cc03
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cc03;
    }
    // 0049cb30  a1c04f5400             -mov eax, dword ptr [0x544fc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525440) /* 0x544fc0 */);
L_0x0049cb35:
    // 0049cb35  83c41c                 +add esp, 0x1c
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
    // 0049cb38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb3b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049cb3e:
    // 0049cb3e  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
    // 0049cb46  e9dbfcffff             -jmp 0x49c826
    goto L_0x0049c826;
L_0x0049cb4b:
    // 0049cb4b  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049cb50  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049cb53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb56  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049cb59:
    // 0049cb59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb5b  7c09                   -jl 0x49cb66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cb66;
    }
    // 0049cb5d  83f87f                 +cmp eax, 0x7f
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
    // 0049cb60  0f8ed5fcffff           -jle 0x49c83b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c83b;
    }
L_0x0049cb66:
    // 0049cb66  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049cb6b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049cb6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb71  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049cb74:
    // 0049cb74  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049cb76  7c09                   -jl 0x49cb81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cb81;
    }
    // 0049cb78  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cb7b  0f8ecffcffff           -jle 0x49c850
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c850;
    }
L_0x0049cb81:
    // 0049cb81  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049cb86  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049cb89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cb8c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049cb8f:
    // 0049cb8f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cb91  0f8dedfcffff           -jge 0x49c884
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c884;
    }
    // 0049cb97  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049cb99  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049cb9d  e9e2fcffff             -jmp 0x49c884
    goto L_0x0049c884;
L_0x0049cba2:
    // 0049cba2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049cba4  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049cba8  e917fdffff             -jmp 0x49c8c4
    goto L_0x0049c8c4;
L_0x0049cbad:
    // 0049cbad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049cbaf  7c09                   -jl 0x49cbba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cbba;
    }
    // 0049cbb1  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cbb4  0f8e1ffdffff           -jle 0x49c8d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c8d9;
    }
L_0x0049cbba:
    // 0049cbba  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049cbbf  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049cbc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cbc5  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049cbc8:
    // 0049cbc8  83fa80                 +cmp edx, -0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-128 /*-0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cbcb  0f8de1fdffff           -jge 0x49c9b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c9b2;
    }
    // 0049cbd1  ba80ffffff             -mov edx, 0xffffff80
    cpu.edx = 4294967168 /*0xffffff80*/;
    // 0049cbd6  e9d7fdffff             -jmp 0x49c9b2
    goto L_0x0049c9b2;
L_0x0049cbdb:
    // 0049cbdb  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 0049cbe2  e92efeffff             -jmp 0x49ca15
    goto L_0x0049ca15;
L_0x0049cbe7:
    // 0049cbe7  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
    // 0049cbeb  e982feffff             -jmp 0x49ca72
    goto L_0x0049ca72;
L_0x0049cbf0:
    // 0049cbf0  c6413f00               -mov byte ptr [ecx + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
    // 0049cbf4  e998feffff             -jmp 0x49ca91
    goto L_0x0049ca91;
L_0x0049cbf9:
    // 0049cbf9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049cbfe  e9c8feffff             -jmp 0x49cacb
    goto L_0x0049cacb;
L_0x0049cc03:
    // 0049cc03  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049cc05  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0049cc0a  e8b9c4ffff             -call 0x4990c8
    cpu.esp -= 4;
    sub_4990c8(app, cpu);
    if (cpu.terminate) return;
    // 0049cc0f  8915c04f5400           -mov dword ptr [0x544fc0], edx
    app->getMemory<x86::reg32>(x86::reg32(5525440) /* 0x544fc0 */) = cpu.edx;
    // 0049cc15  a1c04f5400             -mov eax, dword ptr [0x544fc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525440) /* 0x544fc0 */);
    // 0049cc1a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049cc1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc20  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49cc24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cc24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cc25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cc26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cc27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cc28  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cc29  81ec98010000           -sub esp, 0x198
    (cpu.esp) -= x86::reg32(x86::sreg32(408 /*0x198*/));
    // 0049cc2f  89842480010000         -mov dword ptr [esp + 0x180], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.eax;
    // 0049cc36  8994247c010000         -mov dword ptr [esp + 0x17c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */) = cpu.edx;
    // 0049cc3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cc3f  b9f7ffffff             -mov ecx, 0xfffffff7
    cpu.ecx = 4294967287 /*0xfffffff7*/;
    // 0049cc44  89942488010000         -mov dword ptr [esp + 0x188], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.edx;
    // 0049cc4b  898c2470010000         -mov dword ptr [esp + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 0049cc52  8994248c010000         -mov dword ptr [esp + 0x18c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.edx;
    // 0049cc59  89942490010000         -mov dword ptr [esp + 0x190], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.edx;
    // 0049cc60  89942474010000         -mov dword ptr [esp + 0x174], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.edx;
    // 0049cc67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cc69  0f84e8000000           -je 0x49cd57
    if (cpu.flags.zf)
    {
        goto L_0x0049cd57;
    }
    // 0049cc6f  6681385054             +cmp word ptr [eax], 0x5450
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
    // 0049cc74  0f85ba000000           -jne 0x49cd34
    if (!cpu.flags.zf)
    {
        goto L_0x0049cd34;
    }
    // 0049cc7a  8bac247c010000         -mov ebp, dword ptr [esp + 0x17c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 0049cc81  8bbc247c010000         -mov edi, dword ptr [esp + 0x17c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 0049cc88  8b6d03                 -mov ebp, dword ptr [ebp + 3]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0049cc8b  8b7f02                 -mov edi, dword ptr [edi + 2]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049cc8e  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 0049cc91  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 0049cc94  83fdff                 +cmp ebp, -1
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
    // 0049cc97  0f859e000000           -jne 0x49cd3b
    if (!cpu.flags.zf)
    {
        goto L_0x0049cd3b;
    }
    // 0049cc9d  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x0049cca2:
    // 0049cca2  83ffff                 +cmp edi, -1
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
    // 0049cca5  0f859f000000           -jne 0x49cd4a
    if (!cpu.flags.zf)
    {
        goto L_0x0049cd4a;
    }
    // 0049ccab  bf3c000000             -mov edi, 0x3c
    cpu.edi = 60 /*0x3c*/;
L_0x0049ccb0:
    // 0049ccb0  8b842480010000         -mov eax, dword ptr [esp + 0x180]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 0049ccb7  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 0049ccbb  0f84a7000000           -je 0x49cd68
    if (cpu.flags.zf)
    {
        goto L_0x0049cd68;
    }
    // 0049ccc1  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x0049ccc4:
    // 0049ccc4  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049cccb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049cccd  e81ef9ffff             -call 0x49c5f0
    cpu.esp -= 4;
    sub_49c5f0(app, cpu);
    if (cpu.terminate) return;
    // 0049ccd2  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049ccd9  e82af9ffff             -call 0x49c608
    cpu.esp -= 4;
    sub_49c608(app, cpu);
    if (cpu.terminate) return;
    // 0049ccde  e8cdc0ffff             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0049cce3  e89cfaffff             -call 0x49c784
    cpu.esp -= 4;
    sub_49c784(app, cpu);
    if (cpu.terminate) return;
    // 0049cce8  89842478010000         -mov dword ptr [esp + 0x178], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */) = cpu.eax;
    // 0049ccef  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 0049ccf6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ccf9  89842494010000         -mov dword ptr [esp + 0x194], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.eax;
L_0x0049cd00:
    // 0049cd00  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 0049cd07  40                     -inc eax
    (cpu.eax)++;
    // 0049cd08  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 0049cd0a  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 0049cd11  80feff                 +cmp dh, 0xff
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cd14  0f8489010000           -je 0x49cea3
    if (cpu.flags.zf)
    {
        goto L_0x0049cea3;
    }
    // 0049cd1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cd1c  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 0049cd1e  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049cd21  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd27  7547                   -jne 0x49cd70
    if (!cpu.flags.zf)
    {
        goto L_0x0049cd70;
    }
    // 0049cd29  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cd2b  89842488010000         -mov dword ptr [esp + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 0049cd32  ebcc                   -jmp 0x49cd00
    goto L_0x0049cd00;
L_0x0049cd34:
    // 0049cd34  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0049cd39  eb21                   -jmp 0x49cd5c
    goto L_0x0049cd5c;
L_0x0049cd3b:
    // 0049cd3b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049cd3d  7c18                   -jl 0x49cd57
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd57;
    }
    // 0049cd3f  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd42  0f8e5affffff           -jle 0x49cca2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cca2;
    }
    // 0049cd48  eb0d                   -jmp 0x49cd57
    goto L_0x0049cd57;
L_0x0049cd4a:
    // 0049cd4a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cd4c  7c09                   -jl 0x49cd57
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd57;
    }
    // 0049cd4e  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd51  0f8e59ffffff           -jle 0x49ccb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ccb0;
    }
L_0x0049cd57:
    // 0049cd57  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0049cd5c:
    // 0049cd5c  81c498010000           +add esp, 0x198
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(408 /*0x198*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049cd62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cd63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cd64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cd65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cd66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cd67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cd68:
    // 0049cd68  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049cd6b  e954ffffff             -jmp 0x49ccc4
    goto L_0x0049ccc4;
L_0x0049cd70:
    // 0049cd70  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd76  0f85b1000000           -jne 0x49ce2d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce2d;
    }
    // 0049cd7c  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd83  7d14                   -jge 0x49cd99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cd99;
    }
L_0x0049cd85:
    // 0049cd85  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049cd87  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049cd8e  e875f8ffff             -call 0x49c608
    cpu.esp -= 4;
    sub_49c608(app, cpu);
    if (cpu.terminate) return;
    // 0049cd93  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049cd94  e967ffffff             -jmp 0x49cd00
    goto L_0x0049cd00;
L_0x0049cd99:
    // 0049cd99  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cda0  7fe3                   -jg 0x49cd85
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cd85;
    }
    // 0049cda2  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cda9  7cda                   -jl 0x49cd85
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cd85;
    }
    // 0049cdab  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cdb2  7fd1                   -jg 0x49cd85
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cd85;
    }
    // 0049cdb4  8b942474010000         -mov edx, dword ptr [esp + 0x174]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 0049cdbb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cdbc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cdbd  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049cdc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cdc2  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0049cdc9  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 0049cdd0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cdd1  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 0049cdd8  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 0049cddf  e8e0f9ffff             -call 0x49c7c4
    cpu.esp -= 4;
    sub_49c7c4(app, cpu);
    if (cpu.terminate) return;
    // 0049cde4  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 0049cdeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cded  0f8c3a010000           -jl 0x49cf2d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf2d;
    }
    // 0049cdf3  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 0049cdfa  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049cdfd  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 0049ce04  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 0049ce0b  898c2494010000         -mov dword ptr [esp + 0x194], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.ecx;
    // 0049ce12  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 0049ce19  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049ce1b  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049ce22  e8e1f7ffff             -call 0x49c608
    cpu.esp -= 4;
    sub_49c608(app, cpu);
    if (cpu.terminate) return;
    // 0049ce27  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049ce28  e9d3feffff             -jmp 0x49cd00
    goto L_0x0049cd00;
L_0x0049ce2d:
    // 0049ce2d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ce2f  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ce35  0f84c5feffff           -je 0x49cd00
    if (cpu.flags.zf)
    {
        goto L_0x0049cd00;
    }
    // 0049ce3b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ce3d  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049ce3f  81f9ff000000           +cmp ecx, 0xff
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
    // 0049ce45  7514                   -jne 0x49ce5b
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce5b;
    }
    // 0049ce47  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049ce4a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049ce4f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ce51  e83af7ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0049ce56  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ce58  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0049ce5b:
    // 0049ce5b  46                     -inc esi
    (cpu.esi)++;
    // 0049ce5c  83fb26                 +cmp ebx, 0x26
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ce5f  7c07                   -jl 0x49ce68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ce68;
    }
L_0x0049ce61:
    // 0049ce61  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ce63  e998feffff             -jmp 0x49cd00
    goto L_0x0049cd00;
L_0x0049ce68:
    // 0049ce68  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049ce6a  7cf5                   -jl 0x49ce61
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ce61;
    }
    // 0049ce6c  83f904                 +cmp ecx, 4
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
    // 0049ce6f  7ff0                   -jg 0x49ce61
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049ce61;
    }
    // 0049ce71  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049ce73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ce75  e816f7ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0049ce7a  89849c98000000         -mov dword ptr [esp + ebx*4 + 0x98], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */ + cpu.ebx * 4) = cpu.eax;
    // 0049ce81  89349c                 -mov dword ptr [esp + ebx*4], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 4) = cpu.esi;
    // 0049ce84  83fb24                 +cmp ebx, 0x24
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ce87  75d8                   -jne 0x49ce61
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce61;
    }
    // 0049ce89  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 0049ce90  e80b9d0000             -call 0x4a6ba0
    cpu.esp -= 4;
    sub_4a6ba0(app, cpu);
    if (cpu.terminate) return;
    // 0049ce95  89842474010000         -mov dword ptr [esp + 0x174], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.eax;
    // 0049ce9c  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ce9e  e95dfeffff             -jmp 0x49cd00
    goto L_0x0049cd00;
L_0x0049cea3:
    // 0049cea3  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ceaa  0f8c72000000           -jl 0x49cf22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf22;
    }
    // 0049ceb0  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ceb7  7f69                   -jg 0x49cf22
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cf22;
    }
    // 0049ceb9  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cec0  7c60                   -jl 0x49cf22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf22;
    }
    // 0049cec2  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cec9  7f57                   -jg 0x49cf22
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cf22;
    }
    // 0049cecb  8bb42474010000         -mov esi, dword ptr [esp + 0x174]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 0049ced2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ced3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ced4  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ced8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ced9  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0049cee0  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 0049cee7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049cee8  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 0049ceef  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 0049cef6  e8c9f8ffff             -call 0x49c7c4
    cpu.esp -= 4;
    sub_49c7c4(app, cpu);
    if (cpu.terminate) return;
    // 0049cefb  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 0049cf02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cf04  7c27                   -jl 0x49cf2d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf2d;
    }
    // 0049cf06  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 0049cf0d  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 0049cf14  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 0049cf1b  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
L_0x0049cf22:
    // 0049cf22  8bbc248c010000         -mov edi, dword ptr [esp + 0x18c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 0049cf29  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cf2b  7542                   -jne 0x49cf6f
    if (!cpu.flags.zf)
    {
        goto L_0x0049cf6f;
    }
L_0x0049cf2d:
    // 0049cf2d  8b9c248c010000         -mov ebx, dword ptr [esp + 0x18c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 0049cf34  e88bbeffff             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0049cf39  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049cf3b  7e1f                   -jle 0x49cf5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cf5c;
    }
    // 0049cf3d  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 0049cf44  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049cf46:
    // 0049cf46  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 0049cf4d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049cf50  e86b35feff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
    // 0049cf55  39d1                   +cmp ecx, edx
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
    // 0049cf57  7ced                   -jl 0x49cf46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf46;
    }
    // 0049cf59  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0049cf5c:
    // 0049cf5c  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0049cf63  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 0049cf69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cf6f:
    // 0049cf6f  83ff01                 +cmp edi, 1
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
    // 0049cf72  753f                   -jne 0x49cfb3
    if (!cpu.flags.zf)
    {
        goto L_0x0049cfb3;
    }
    // 0049cf74  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 0049cf7b  e83cc2ffff             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0049cf80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cf82  7c17                   -jl 0x49cf9b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf9b;
    }
    // 0049cf84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049cf86  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cf89  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cf8b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049cf8e  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0049cf93  c6403b00               -mov byte ptr [eax + 0x3b], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */) = 0 /*0x0*/;
    // 0049cf97  c6403a00               -mov byte ptr [eax + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
L_0x0049cf9b:
    // 0049cf9b  e824beffff             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0049cfa0  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0049cfa7  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 0049cfad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cfb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cfb3:
    // 0049cfb3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cfb5  7e3f                   -jle 0x49cff6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cff6;
    }
    // 0049cfb7  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0049cfbe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049cfc0:
    // 0049cfc0  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 0049cfc7  e8f0c1ffff             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0049cfcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049cfce  7c1f                   -jl 0x49cfef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cfef;
    }
    // 0049cfd0  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 0049cfd3  bbd0a75200             -mov ebx, 0x52a7d0
    cpu.ebx = 5416912 /*0x52a7d0*/;
    // 0049cfd8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cfda  8a842478010000         -mov al, byte ptr [esp + 0x178]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 0049cfe1  c6433a00               -mov byte ptr [ebx + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
    // 0049cfe5  899c2490010000         -mov dword ptr [esp + 0x190], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.ebx;
    // 0049cfec  88433b                 -mov byte ptr [ebx + 0x3b], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(59) /* 0x3b */) = cpu.al;
L_0x0049cfef:
    // 0049cfef  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049cff2  39d1                   +cmp ecx, edx
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
    // 0049cff4  7cca                   -jl 0x49cfc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cfc0;
    }
L_0x0049cff6:
    // 0049cff6  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 0049cffd  c6403a01               -mov byte ptr [eax + 0x3a], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 1 /*0x1*/;
    // 0049d001  eb98                   -jmp 0x49cf9b
    goto L_0x0049cf9b;
}

/* align: skip 0x90 */
void Application::sub_49d004(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d004  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d005  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d006  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d009  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049d00c  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049d00e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d010  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049d013  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0049d018  6681fa5054             +cmp dx, 0x5450
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049d01d  7552                   -jne 0x49d071
    if (!cpu.flags.zf)
    {
        goto L_0x0049d071;
    }
    // 0049d01f  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0049d022  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0049d025  7555                   -jne 0x49d07c
    if (!cpu.flags.zf)
    {
        goto L_0x0049d07c;
    }
    // 0049d027  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d028  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d029  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0049d02c  7452                   -je 0x49d080
    if (cpu.flags.zf)
    {
        goto L_0x0049d080;
    }
    // 0049d02e  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x0049d031:
    // 0049d031  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d033  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d035  7460                   -je 0x49d097
    if (cpu.flags.zf)
    {
        goto L_0x0049d097;
    }
    // 0049d037  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 0049d03a  81fefd000000           +cmp esi, 0xfd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d040  750e                   -jne 0x49d050
    if (!cpu.flags.zf)
    {
        goto L_0x0049d050;
    }
    // 0049d042  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d043  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d045  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049d047  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d049  e8e22efeff             -call 0x47ff30
    cpu.esp -= 4;
    sub_47ff30(app, cpu);
    if (cpu.terminate) return;
    // 0049d04e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049d050:
    // 0049d050  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d051  81fefe000000           +cmp esi, 0xfe
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d057  74d8                   -je 0x49d031
    if (cpu.flags.zf)
    {
        goto L_0x0049d031;
    }
    // 0049d059  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d05f  74d0                   -je 0x49d031
    if (cpu.flags.zf)
    {
        goto L_0x0049d031;
    }
    // 0049d061  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d063  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d065  3dff000000             +cmp eax, 0xff
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
    // 0049d06a  7419                   -je 0x49d085
    if (cpu.flags.zf)
    {
        goto L_0x0049d085;
    }
L_0x0049d06c:
    // 0049d06c  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d06d  01c1                   +add ecx, eax
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
    // 0049d06f  ebc0                   -jmp 0x49d031
    goto L_0x0049d031;
L_0x0049d071:
    // 0049d071  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x0049d076:
    // 0049d076  83c404                 +add esp, 4
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
    // 0049d079  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d07a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d07b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d07c:
    // 0049d07c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d07e  ebf6                   -jmp 0x49d076
    goto L_0x0049d076;
L_0x0049d080:
    // 0049d080  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d083  ebac                   -jmp 0x49d031
    goto L_0x0049d031;
L_0x0049d085:
    // 0049d085  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d086  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049d08b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d08d  e8fef4ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0049d092  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d095  ebd5                   -jmp 0x49d06c
    goto L_0x0049d06c;
L_0x0049d097:
    // 0049d097  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d099  7c08                   -jl 0x49d0a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d0a3;
    }
    // 0049d09b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049d09f  80480301               -or byte ptr [eax + 3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0049d0a3:
    // 0049d0a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d0a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0a7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d0aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d0ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49d0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d0b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d0b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d0b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d0b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d0b4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d0b6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d0b8  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 0049d0bc  7437                   -je 0x49d0f5
    if (cpu.flags.zf)
    {
        goto L_0x0049d0f5;
    }
    // 0049d0be  8d4f08                 -lea ecx, [edi + 8]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
L_0x0049d0c1:
    // 0049d0c1  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d0c3  80faff                 +cmp dl, 0xff
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d0c6  7450                   -je 0x49d118
    if (cpu.flags.zf)
    {
        goto L_0x0049d118;
    }
    // 0049d0c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d0ca  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 0049d0cc  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d0d2  7426                   -je 0x49d0fa
    if (cpu.flags.zf)
    {
        goto L_0x0049d0fa;
    }
L_0x0049d0d4:
    // 0049d0d4  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d0d5  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d0db  74e4                   -je 0x49d0c1
    if (cpu.flags.zf)
    {
        goto L_0x0049d0c1;
    }
    // 0049d0dd  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d0e3  74dc                   -je 0x49d0c1
    if (cpu.flags.zf)
    {
        goto L_0x0049d0c1;
    }
    // 0049d0e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d0e7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d0e9  3dff000000             +cmp eax, 0xff
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
    // 0049d0ee  7416                   -je 0x49d106
    if (cpu.flags.zf)
    {
        goto L_0x0049d106;
    }
L_0x0049d0f0:
    // 0049d0f0  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d0f1  01c1                   +add ecx, eax
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
    // 0049d0f3  ebcc                   -jmp 0x49d0c1
    goto L_0x0049d0c1;
L_0x0049d0f5:
    // 0049d0f5  8d4f04                 -lea ecx, [edi + 4]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049d0f8  ebc7                   -jmp 0x49d0c1
    goto L_0x0049d0c1;
L_0x0049d0fa:
    // 0049d0fa  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d0fb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d0fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d0ff  e8ac26feff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0049d104  ebce                   -jmp 0x49d0d4
    goto L_0x0049d0d4;
L_0x0049d106:
    // 0049d106  41                     -inc ecx
    (cpu.ecx)++;
    // 0049d107  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049d10c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d10e  e87df4ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0049d113  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d116  ebd8                   -jmp 0x49d0f0
    goto L_0x0049d0f0;
L_0x0049d118:
    // 0049d118  8a7703                 -mov dh, byte ptr [edi + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 0049d11b  80e6fe                 -and dh, 0xfe
    cpu.dh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049d11e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d120  887703                 -mov byte ptr [edi + 3], dh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 0049d123  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d124  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d125  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d126  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d127  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d130  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d132  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d134  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049d136  e895d90000             -call 0x4aaad0
    cpu.esp -= 4;
    sub_4aaad0(app, cpu);
    if (cpu.terminate) return;
    // 0049d13b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d13d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d13f  7c09                   -jl 0x49d14a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d14a;
    }
    // 0049d141  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d143  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d145  7c11                   -jl 0x49d158
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d158;
    }
    // 0049d147  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d148  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d149  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d14a:
    // 0049d14a  6bc2ff                 -imul eax, edx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0049d14d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049d14f  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d151  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d153  7c03                   -jl 0x49d158
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d158;
    }
    // 0049d155  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d156  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d157  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d158:
    // 0049d158  6bc3ff                 -imul eax, ebx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0049d15b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049d15d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d15e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d15f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d160  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d161  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d162  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d163  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d166  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d16a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049d16d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d16f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049d171  e85ad90000             -call 0x4aaad0
    cpu.esp -= 4;
    sub_4aaad0(app, cpu);
    if (cpu.terminate) return;
    // 0049d176  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d17a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d17c  0f8c93000000           -jl 0x49d215
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d215;
    }
L_0x0049d182:
    // 0049d182  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d186  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d188  0f8ca1000000           -jl 0x49d22f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d22f;
    }
    // 0049d18e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d190  0f8c99000000           -jl 0x49d22f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d22f;
    }
    // 0049d196  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d198  0f8e87000000           -jle 0x49d225
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d225;
    }
L_0x0049d19e:
    // 0049d19e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0049d1a3:
    // 0049d1a3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049d1a6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d1a8  81f900400000           +cmp ecx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d1ae  0f8cc5000000           -jl 0x49d279
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d279;
    }
    // 0049d1b4  81f900c00000           +cmp ecx, 0xc000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d1ba  0f8db9000000           -jge 0x49d279
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d279;
    }
    // 0049d1c0  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d1c2  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d1c4  0f8da5000000           -jge 0x49d26f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d26f;
    }
    // 0049d1ca  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
L_0x0049d1cf:
    // 0049d1cf  83f802                 +cmp eax, 2
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
    // 0049d1d2  7f13                   -jg 0x49d1e7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049d1e7;
    }
    // 0049d1d4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049d1d9  83f903                 +cmp ecx, 3
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
    // 0049d1dc  7509                   -jne 0x49d1e7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1e7;
    }
    // 0049d1de  39d0                   +cmp eax, edx
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
L_0x0049d1e0:
    // 0049d1e0  7505                   -jne 0x49d1e7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1e7;
    }
    // 0049d1e2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049d1e7:
    // 0049d1e7  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 0049d1ec  0f8cb7000000           -jl 0x49d2a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d2a9;
    }
L_0x0049d1f2:
    // 0049d1f2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d1f4  0f8cbb000000           -jl 0x49d2b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d2b5;
    }
L_0x0049d1fa:
    // 0049d1fa  83fa01                 +cmp edx, 1
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
    // 0049d1fd  0f84be000000           -je 0x49d2c1
    if (cpu.flags.zf)
    {
        goto L_0x0049d2c1;
    }
    // 0049d203  83fa02                 +cmp edx, 2
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
    // 0049d206  0f84c5000000           -je 0x49d2d1
    if (cpu.flags.zf)
    {
        goto L_0x0049d2d1;
    }
    // 0049d20c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d20f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d210  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d211  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d212  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d215:
    // 0049d215  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d217  0f8d65ffffff           -jge 0x49d182
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d182;
    }
    // 0049d21d  39d5                   +cmp ebp, edx
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
    // 0049d21f  0f8e79ffffff           -jle 0x49d19e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d19e;
    }
L_0x0049d225:
    // 0049d225  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d22a  e974ffffff             -jmp 0x49d1a3
    goto L_0x0049d1a3;
L_0x0049d22f:
    // 0049d22f  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d233  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d235  7e16                   -jle 0x49d24d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d24d;
    }
    // 0049d237  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049d239:
    // 0049d239  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049d23b  7e16                   -jle 0x49d253
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d253;
    }
    // 0049d23d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049d23f  39d0                   +cmp eax, edx
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
    // 0049d241  7e22                   -jle 0x49d265
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d265;
    }
    // 0049d243  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049d248  e956ffffff             -jmp 0x49d1a3
    goto L_0x0049d1a3;
L_0x0049d24d:
    // 0049d24d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d24f  f7d8                   +neg eax
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
    // 0049d251  ebe6                   -jmp 0x49d239
    goto L_0x0049d239;
L_0x0049d253:
    // 0049d253  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049d255  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049d257  39d0                   +cmp eax, edx
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
    // 0049d259  7e0a                   -jle 0x49d265
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d265;
    }
    // 0049d25b  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049d260  e93effffff             -jmp 0x49d1a3
    goto L_0x0049d1a3;
L_0x0049d265:
    // 0049d265  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0049d26a  e934ffffff             -jmp 0x49d1a3
    goto L_0x0049d1a3;
L_0x0049d26f:
    // 0049d26f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049d274  e956ffffff             -jmp 0x49d1cf
    goto L_0x0049d1cf;
L_0x0049d279:
    // 0049d279  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d27b  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d27d  7d23                   -jge 0x49d2a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d2a2;
    }
    // 0049d27f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x0049d284:
    // 0049d284  83f803                 +cmp eax, 3
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
    // 0049d287  0f8c5affffff           -jl 0x49d1e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d1e7;
    }
    // 0049d28d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049d292  39d1                   +cmp ecx, edx
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
    // 0049d294  0f854dffffff           -jne 0x49d1e7
    if (!cpu.flags.zf)
    {
        goto L_0x0049d1e7;
    }
    // 0049d29a  83f803                 +cmp eax, 3
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
    // 0049d29d  e93effffff             -jmp 0x49d1e0
    goto L_0x0049d1e0;
L_0x0049d2a2:
    // 0049d2a2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049d2a7  ebdb                   -jmp 0x49d284
    goto L_0x0049d284;
L_0x0049d2a9:
    // 0049d2a9  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d2ab  6bc1ff                 +imul eax, ecx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0049d2ae  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049d2b0  e93dffffff             -jmp 0x49d1f2
    goto L_0x0049d1f2;
L_0x0049d2b5:
    // 0049d2b5  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d2b7  6bc3ff                 +imul eax, ebx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0049d2ba  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049d2bc  e939ffffff             -jmp 0x49d1fa
    goto L_0x0049d1fa;
L_0x0049d2c1:
    // 0049d2c1  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d2c3  6bc5ff                 -imul eax, ebp, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0049d2c6  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049d2c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d2cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2ce  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0049d2d1:
    // 0049d2d1  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d2d3  6bc7ff                 -imul eax, edi, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0049d2d6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049d2d8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d2db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d2de  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49d2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d2f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d2f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d2f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d2f3  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0049d2fa  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d2fc  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0049d2ff  81c1d0a75200           -add ecx, 0x52a7d0
    (cpu.ecx) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 0049d305  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049d308  8b512d                 -mov edx, dword ptr [ecx + 0x2d]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(45) /* 0x2d */);
    // 0049d30b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049d30e  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049d311  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049d314  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0049d317  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049d31a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049d31d  8b152aae5200           -mov edx, dword ptr [0x52ae2a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5418538) /* 0x52ae2a */);
    // 0049d323  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049d326  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d329  bb7f411f00             -mov ebx, 0x1f417f
    cpu.ebx = 2048383 /*0x1f417f*/;
    // 0049d32e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d330  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049d333  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049d335  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0049d338  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 0049d33b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d33d  750b                   -jne 0x49d34a
    if (!cpu.flags.zf)
    {
        goto L_0x0049d34a;
    }
    // 0049d33f  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0049d342  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d344  7533                   -jne 0x49d379
    if (!cpu.flags.zf)
    {
        goto L_0x0049d379;
    }
    // 0049d346  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d347  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d348  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d349  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d34a:
    // 0049d34a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d34c  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0049d34f  8a513e                 -mov dl, byte ptr [ecx + 0x3e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 0049d352  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
    // 0049d356  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 0049d359  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049d35c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049d35f  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0049d364  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d366  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049d369  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049d36b  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 0049d36e  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0049d371  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d373  7504                   -jne 0x49d379
    if (!cpu.flags.zf)
    {
        goto L_0x0049d379;
    }
    // 0049d375  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d376  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d377  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d378  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d379:
    // 0049d379  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 0049d37c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049d37e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049d381  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0049d384  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 0049d387  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d388  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d389  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d38a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d38b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d38b  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d38e  7c08                   -jl 0x49d398
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d398;
    }
    // 0049d390  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d393  7f03                   -jg 0x49d398
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049d398;
    }
    // 0049d395  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0049d398:
    // 0049d398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d399(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d399  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d39a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d39b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d39f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d3a2  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0049d3a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d3a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d3a8  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d3ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d3ad  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d3b1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d3b2  e806000000             -call 0x49d3bd
    cpu.esp -= 4;
    sub_49d3bd(app, cpu);
    if (cpu.terminate) return;
    // 0049d3b7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049d3ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d3bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d3bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d3be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d3bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d3c0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d3c3  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049d3c7  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0049d3c9  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d3cd  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d3d1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049d3d4  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d3d8  e807000000             -call 0x49d3e4
    cpu.esp -= 4;
    sub_49d3e4(app, cpu);
    if (cpu.terminate) return;
    // 0049d3dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d3e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d3e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d3e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d3e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d3e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d3e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d3e7  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049d3ea  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d3ec  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049d3f0  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049d3f4  e837d80000             -call 0x4aac30
    cpu.esp -= 4;
    sub_4aac30(app, cpu);
    if (cpu.terminate) return;
    // 0049d3f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d3fb  7414                   -je 0x49d411
    if (cpu.flags.zf)
    {
        goto L_0x0049d411;
    }
    // 0049d3fd  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
L_0x0049d402:
    // 0049d402  e8f9ccffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049d407  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049d40c  e9d5010000             -jmp 0x49d5e6
    goto L_0x0049d5e6;
L_0x0049d411:
    // 0049d411  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d413  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d417  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049d41a  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049d41e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d420  e84fda0000             -call 0x4aae74
    cpu.esp -= 4;
    sub_4aae74(app, cpu);
    if (cpu.terminate) return;
    // 0049d425  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049d429  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d42d  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d42f  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 0049d434  e867da0000             -call 0x4aaea0
    cpu.esp -= 4;
    sub_4aaea0(app, cpu);
    if (cpu.terminate) return;
    // 0049d439  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d43b  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0049d440  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049d444  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d448  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049d44b  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 0049d44e  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0049d451  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d456  8b15dce34c00           -mov edx, dword ptr [0x4ce3dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5039068) /* 0x4ce3dc */);
    // 0049d45c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049d460  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d462  7435                   -je 0x49d499
    if (cpu.flags.zf)
    {
        goto L_0x0049d499;
    }
    // 0049d464  ba4c144c00             -mov edx, 0x4c144c
    cpu.edx = 4985932 /*0x4c144c*/;
    // 0049d469  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d46b  e87325ffff             -call 0x48f9e3
    cpu.esp -= 4;
    sub_48f9e3(app, cpu);
    if (cpu.terminate) return;
    // 0049d470  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d472  7525                   -jne 0x49d499
    if (!cpu.flags.zf)
    {
        goto L_0x0049d499;
    }
    // 0049d474  e8a5d90000             -call 0x4aae1e
    cpu.esp -= 4;
    sub_4aae1e(app, cpu);
    if (cpu.terminate) return;
    // 0049d479  ff1594e34c00           -call dword ptr [0x4ce394]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038996) /* 0x4ce394 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d47f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0049d481  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d482  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d484  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 0049d489  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d48b  ff15dce34c00           -call dword ptr [0x4ce3dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039068) /* 0x4ce3dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d491  83c40c                 +add esp, 0xc
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
    // 0049d494  e9fd000000             -jmp 0x49d596
    goto L_0x0049d596;
L_0x0049d499:
    // 0049d499  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d49d  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 0049d4a0  7462                   -je 0x49d504
    if (cpu.flags.zf)
    {
        goto L_0x0049d504;
    }
    // 0049d4a2  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049d4a4  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d4a7  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 0049d4a9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d4ac  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049d4b0  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0049d4b6  a1e0f74c00             -mov eax, dword ptr [0x4cf7e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044192) /* 0x4cf7e0 */);
    // 0049d4bb  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049d4bf  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0049d4c1  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d4c3  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049d4c7  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 0049d4cc  740c                   -je 0x49d4da
    if (cpu.flags.zf)
    {
        goto L_0x0049d4da;
    }
    // 0049d4ce  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 0049d4d3  7505                   -jne 0x49d4da
    if (!cpu.flags.zf)
    {
        goto L_0x0049d4da;
    }
    // 0049d4d5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0049d4da:
    // 0049d4da  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 0049d4df  7409                   -je 0x49d4ea
    if (cpu.flags.zf)
    {
        goto L_0x0049d4ea;
    }
    // 0049d4e1  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049d4e6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049d4e8  eb24                   -jmp 0x49d50e
    goto L_0x0049d50e;
L_0x0049d4ea:
    // 0049d4ea  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 0049d4ef  740c                   -je 0x49d4fd
    if (cpu.flags.zf)
    {
        goto L_0x0049d4fd;
    }
    // 0049d4f1  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
L_0x0049d4f6:
    // 0049d4f6  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049d4fb  eb11                   -jmp 0x49d50e
    goto L_0x0049d50e;
L_0x0049d4fd:
    // 0049d4fd  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 0049d502  eb05                   -jmp 0x49d509
    goto L_0x0049d509;
L_0x0049d504:
    // 0049d504  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0049d507  75ed                   -jne 0x49d4f6
    if (!cpu.flags.zf)
    {
        goto L_0x0049d4f6;
    }
L_0x0049d509:
    // 0049d509  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x0049d50e:
    // 0049d50e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d511  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d512  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049d516  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d517  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d51b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d51c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d520  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d521  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d522  2eff1558744b00         -call dword ptr cs:[0x4b7458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944984) /* 0x4b7458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d529  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d52b  83f8ff                 +cmp eax, -1
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
    // 0049d52e  7530                   -jne 0x49d560
    if (!cpu.flags.zf)
    {
        goto L_0x0049d560;
    }
    // 0049d530  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 0049d535  741a                   -je 0x49d551
    if (cpu.flags.zf)
    {
        goto L_0x0049d551;
    }
    // 0049d537  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d539  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d53a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d53b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d53d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049d541  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d542  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049d546  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d547  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d548  2eff1558744b00         -call dword ptr cs:[0x4b7458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944984) /* 0x4b7458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d54f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0049d551:
    // 0049d551  83f9ff                 +cmp ecx, -1
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
    // 0049d554  750a                   -jne 0x49d560
    if (!cpu.flags.zf)
    {
        goto L_0x0049d560;
    }
    // 0049d556  e8a7caffff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
    // 0049d55b  e986000000             -jmp 0x49d5e6
    goto L_0x0049d5e6;
L_0x0049d560:
    // 0049d560  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d562  ff1594e34c00           -call dword ptr [0x4ce394]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038996) /* 0x4ce394 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d568  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d56a  8b2de4f74c00           -mov ebp, dword ptr [0x4cf7e4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */);
    // 0049d570  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d572  39e8                   +cmp eax, ebp
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
    // 0049d574  7212                   -jb 0x49d588
    if (cpu.flags.cf)
    {
        goto L_0x0049d588;
    }
    // 0049d576  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d577  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d57e  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049d583  e97afeffff             -jmp 0x49d402
    goto L_0x0049d402;
L_0x0049d588:
    // 0049d588  e8e1d90000             -call 0x4aaf6e
    cpu.esp -= 4;
    sub_4aaf6e(app, cpu);
    if (cpu.terminate) return;
    // 0049d58d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d58f  7405                   -je 0x49d596
    if (cpu.flags.zf)
    {
        goto L_0x0049d596;
    }
    // 0049d591  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x0049d596:
    // 0049d596  83fe02                 +cmp esi, 2
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
    // 0049d599  7505                   -jne 0x49d5a0
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5a0;
    }
    // 0049d59b  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049d59e  eb11                   -jmp 0x49d5b1
    goto L_0x0049d5b1;
L_0x0049d5a0:
    // 0049d5a0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d5a2  7505                   -jne 0x49d5a9
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5a9;
    }
    // 0049d5a4  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0049d5a7  eb08                   -jmp 0x49d5b1
    goto L_0x0049d5b1;
L_0x0049d5a9:
    // 0049d5a9  83fe01                 +cmp esi, 1
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
    // 0049d5ac  7503                   -jne 0x49d5b1
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5b1;
    }
    // 0049d5ae  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0049d5b1:
    // 0049d5b1  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 0049d5b6  7403                   -je 0x49d5bb
    if (cpu.flags.zf)
    {
        goto L_0x0049d5bb;
    }
    // 0049d5b8  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0049d5bb:
    // 0049d5bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d5bd  8a7c241d               -mov bh, byte ptr [esp + 0x1d]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 0049d5c1  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0049d5c3  f6c703                 +test bh, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 3 /*0x3*/));
    // 0049d5c6  7407                   -je 0x49d5cf
    if (cpu.flags.zf)
    {
        goto L_0x0049d5cf;
    }
    // 0049d5c8  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 0049d5cb  7410                   -je 0x49d5dd
    if (cpu.flags.zf)
    {
        goto L_0x0049d5dd;
    }
    // 0049d5cd  eb0c                   -jmp 0x49d5db
    goto L_0x0049d5db;
L_0x0049d5cf:
    // 0049d5cf  813d7de34c0000020000   +cmp dword ptr [0x4ce37d], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038973) /* 0x4ce37d */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d5d9  7502                   -jne 0x49d5dd
    if (!cpu.flags.zf)
    {
        goto L_0x0049d5dd;
    }
L_0x0049d5db:
    // 0049d5db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049d5dd:
    // 0049d5dd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d5df  e869d90000             -call 0x4aaf4d
    cpu.esp -= 4;
    sub_4aaf4d(app, cpu);
    if (cpu.terminate) return;
    // 0049d5e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0049d5e6:
    // 0049d5e6  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049d5e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d5ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d5ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d5ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d5ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d5f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d5f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d5f2  ff159ce34c00           -call dword ptr [0x4ce39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039004) /* 0x4ce39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d5f8  8b35c84f5400           -mov esi, dword ptr [0x544fc8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */);
    // 0049d5fe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d600  7419                   -je 0x49d61b
    if (cpu.flags.zf)
    {
        goto L_0x0049d61b;
    }
    // 0049d602  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049d605  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049d608  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d60a  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 0049d610  a3c84f5400             -mov dword ptr [0x544fc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */) = cpu.eax;
    // 0049d615  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 0049d619  eb47                   -jmp 0x49d662
    goto L_0x0049d662;
L_0x0049d61b:
    // 0049d61b  b974e14c00             -mov ecx, 0x4ce174
    cpu.ecx = 5038452 /*0x4ce174*/;
    // 0049d620  eb20                   -jmp 0x49d642
    goto L_0x0049d642;
L_0x0049d622:
    // 0049d622  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 0049d626  7517                   -jne 0x49d63f
    if (!cpu.flags.zf)
    {
        goto L_0x0049d63f;
    }
    // 0049d628  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 0049d62d  e8e1c9ffff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 0049d632  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d634  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d636  7458                   -je 0x49d690
    if (cpu.flags.zf)
    {
        goto L_0x0049d690;
    }
    // 0049d638  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 0049d63d  eb23                   -jmp 0x49d662
    goto L_0x0049d662;
L_0x0049d63f:
    // 0049d63f  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
L_0x0049d642:
    // 0049d642  81f97ce34c00           +cmp ecx, 0x4ce37c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5038972 /*0x4ce37c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d648  72d8                   -jb 0x49d622
    if (cpu.flags.cf)
    {
        goto L_0x0049d622;
    }
    // 0049d64a  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 0049d64f  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 0049d654  e8bac9ffff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 0049d659  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d65b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d65d  7431                   -je 0x49d690
    if (cpu.flags.zf)
    {
        goto L_0x0049d690;
    }
    // 0049d65f  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x0049d662:
    // 0049d662  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 0049d667  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d669  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049d66b  e83fbcfeff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 0049d670  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049d673  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049d676  a1c44f5400             -mov eax, dword ptr [0x544fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 0049d67b  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049d67e  8935c44f5400           -mov dword ptr [0x544fc4], esi
    app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */) = cpu.esi;
    // 0049d684  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049d686  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d68c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d68e  eb12                   -jmp 0x49d6a2
    goto L_0x0049d6a2;
L_0x0049d690:
    // 0049d690  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049d695  e866caffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049d69a  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d6a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049d6a2:
    // 0049d6a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d6a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d6a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d6a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d6aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d6ab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d6ad  bac44f5400             -mov edx, 0x544fc4
    cpu.edx = 5525444 /*0x544fc4*/;
L_0x0049d6b2:
    // 0049d6b2  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d6b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d6b6  7425                   -je 0x49d6dd
    if (cpu.flags.zf)
    {
        goto L_0x0049d6dd;
    }
    // 0049d6b8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049d6bb  39cb                   +cmp ebx, ecx
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
    // 0049d6bd  7404                   -je 0x49d6c3
    if (cpu.flags.zf)
    {
        goto L_0x0049d6c3;
    }
    // 0049d6bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d6c1  ebef                   -jmp 0x49d6b2
    goto L_0x0049d6b2;
L_0x0049d6c3:
    // 0049d6c3  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049d6c6  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 0049d6c9  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 0049d6cc  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d6ce  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0049d6d0  8b15c84f5400           -mov edx, dword ptr [0x544fc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */);
    // 0049d6d6  a3c84f5400             -mov dword ptr [0x544fc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */) = cpu.eax;
    // 0049d6db  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049d6dd:
    // 0049d6dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d6e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d6e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x0049d6e2:
    // 0049d6e2  8b15c84f5400           -mov edx, dword ptr [0x544fc8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */);
    // 0049d6e8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d6ea  7411                   -je 0x49d6fd
    if (cpu.flags.zf)
    {
        goto L_0x0049d6fd;
    }
    // 0049d6ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d6ee  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d6f0  e8b4190000             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 0049d6f5  8915c84f5400           -mov dword ptr [0x544fc8], edx
    app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */) = cpu.edx;
    // 0049d6fb  ebe5                   -jmp 0x49d6e2
    goto L_0x0049d6e2;
L_0x0049d6fd:
    // 0049d6fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d6fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d6ff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d6ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d701  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d702  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d703  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d706  7f2c                   -jg 0x49d734
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049d734;
    }
    // 0049d708  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d70b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d70d  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049d710  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d712  39d8                   +cmp eax, ebx
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
    // 0049d714  7c1e                   -jl 0x49d734
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d734;
    }
    // 0049d716  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049d719  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049d71b  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d71e  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049d721  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d723  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0049d726  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d728  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0049d72a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d72c  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049d72f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d730  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d732  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d733  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d734:
    // 0049d734  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d739  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d73a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d73b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d73c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d73d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d73e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d73e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d73f  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049d743  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d746  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d749  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049d750  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049d752  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d753  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d754(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d754  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d755  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d756  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d757  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d759  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d75b  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049d75e  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d764  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049d767  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 0049d76a  7465                   -je 0x49d7d1
    if (cpu.flags.zf)
    {
        goto L_0x0049d7d1;
    }
    // 0049d76c  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0049d770  741f                   -je 0x49d791
    if (cpu.flags.zf)
    {
        goto L_0x0049d791;
    }
    // 0049d772  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d774  e8c7160000             -call 0x49ee40
    cpu.esp -= 4;
    sub_49ee40(app, cpu);
    if (cpu.terminate) return;
    // 0049d779  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d77b  742b                   -je 0x49d7a8
    if (cpu.flags.zf)
    {
        goto L_0x0049d7a8;
    }
    // 0049d77d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d77f  753e                   -jne 0x49d7bf
    if (!cpu.flags.zf)
    {
        goto L_0x0049d7bf;
    }
    // 0049d781  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d783  7d3a                   -jge 0x49d7bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d7bf;
    }
L_0x0049d785:
    // 0049d785  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0049d78a  e871c9ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049d78f  eb2e                   -jmp 0x49d7bf
    goto L_0x0049d7bf;
L_0x0049d791:
    // 0049d791  83fb01                 +cmp ebx, 1
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
    // 0049d794  7503                   -jne 0x49d799
    if (!cpu.flags.zf)
    {
        goto L_0x0049d799;
    }
    // 0049d796  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x0049d799:
    // 0049d799  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049d79c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d79f  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049d7a6  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0049d7a8:
    // 0049d7a8  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 0049d7ac  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d7ae  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
L_0x0049d7b1:
    // 0049d7b1  e8f2170000             -call 0x49efa8
    cpu.esp -= 4;
    sub_49efa8(app, cpu);
    if (cpu.terminate) return;
    // 0049d7b6  83f8ff                 +cmp eax, -1
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
    // 0049d7b9  0f8596000000           -jne 0x49d855
    if (!cpu.flags.zf)
    {
        goto L_0x0049d855;
    }
L_0x0049d7bf:
    // 0049d7bf  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049d7c2  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d7c8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049d7cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049d7d1:
    // 0049d7d1  83fb01                 +cmp ebx, 1
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
    // 0049d7d4  7209                   -jb 0x49d7df
    if (cpu.flags.cf)
    {
        goto L_0x0049d7df;
    }
    // 0049d7d6  760d                   -jbe 0x49d7e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d7e5;
    }
    // 0049d7d8  83fb02                 +cmp ebx, 2
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
    // 0049d7db  7457                   -je 0x49d834
    if (cpu.flags.zf)
    {
        goto L_0x0049d834;
    }
    // 0049d7dd  eba6                   -jmp 0x49d785
    goto L_0x0049d785;
L_0x0049d7df:
    // 0049d7df  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d7e1  742c                   -je 0x49d80f
    if (cpu.flags.zf)
    {
        goto L_0x0049d80f;
    }
    // 0049d7e3  eba0                   -jmp 0x49d785
    goto L_0x0049d785;
L_0x0049d7e5:
    // 0049d7e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d7e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d7e9  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049d7ec  e80effffff             -call 0x49d6ff
    cpu.esp -= 4;
    sub_49d6ff(app, cpu);
    if (cpu.terminate) return;
    // 0049d7f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d7f3  7460                   -je 0x49d855
    if (cpu.flags.zf)
    {
        goto L_0x0049d855;
    }
    // 0049d7f5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d7f7  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049d7fa  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049d7fc:
    // 0049d7fc  e8a7170000             -call 0x49efa8
    cpu.esp -= 4;
    sub_49efa8(app, cpu);
    if (cpu.terminate) return;
    // 0049d801  83f8ff                 +cmp eax, -1
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
    // 0049d804  74b9                   -je 0x49d7bf
    if (cpu.flags.zf)
    {
        goto L_0x0049d7bf;
    }
    // 0049d806  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d808  e831ffffff             -call 0x49d73e
    cpu.esp -= 4;
    sub_49d73e(app, cpu);
    if (cpu.terminate) return;
    // 0049d80d  eb46                   -jmp 0x49d855
    goto L_0x0049d855;
L_0x0049d80f:
    // 0049d80f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049d812  e8add70000             -call 0x4aafc4
    cpu.esp -= 4;
    sub_4aafc4(app, cpu);
    if (cpu.terminate) return;
    // 0049d817  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049d81a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049d81c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d81e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d820  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d822  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d824  e8d6feffff             -call 0x49d6ff
    cpu.esp -= 4;
    sub_49d6ff(app, cpu);
    if (cpu.terminate) return;
    // 0049d829  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d82b  7428                   -je 0x49d855
    if (cpu.flags.zf)
    {
        goto L_0x0049d855;
    }
    // 0049d82d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d82f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049d832  ebc8                   -jmp 0x49d7fc
    goto L_0x0049d7fc;
L_0x0049d834:
    // 0049d834  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0049d836  80e2ef                 +and dl, 0xef
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 0049d839  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049d83c  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 0049d83f  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d842  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049d844  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d846  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049d849  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049d850  e95cffffff             -jmp 0x49d7b1
    goto L_0x0049d7b1;
L_0x0049d855:
    // 0049d855  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049d858  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d85e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d862  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d863  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d864  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d865  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d866  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d867  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d869  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 0049d86d  7522                   -jne 0x49d891
    if (!cpu.flags.zf)
    {
        goto L_0x0049d891;
    }
    // 0049d86f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049d872  e8f7d60000             -call 0x4aaf6e
    cpu.esp -= 4;
    sub_4aaf6e(app, cpu);
    if (cpu.terminate) return;
    // 0049d877  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d879  7416                   -je 0x49d891
    if (cpu.flags.zf)
    {
        goto L_0x0049d891;
    }
    // 0049d87b  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0049d87e  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049d881  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 0049d884  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 0049d887  7508                   -jne 0x49d891
    if (!cpu.flags.zf)
    {
        goto L_0x0049d891;
    }
    // 0049d889  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049d88b  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0049d88e  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x0049d891:
    // 0049d891  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d892  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d895(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d895  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d89b  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 0049d8a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d8a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d8a1  a1d04f5400             -mov eax, dword ptr [0x544fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525456) /* 0x544fd0 */);
    // 0049d8a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d8a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049d8a6;
    // 0049d8a1  a1d04f5400             -mov eax, dword ptr [0x544fd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525456) /* 0x544fd0 */);
L_entry_0x0049d8a6:
    // 0049d8a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d8a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d8a7  e9c9d30000             -jmp 0x4aac75
    return sub_4aac75(app, cpu);
}

/* align: skip  */
void Application::sub_49d8ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d8ac  e9e2d40000             -jmp 0x4aad93
    return sub_4aad93(app, cpu);
}

/* align: skip  */
void Application::sub_49d8b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d8b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d8b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d8b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d8b4  81ec18060000           -sub esp, 0x618
    (cpu.esp) -= x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 0049d8ba  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d8bc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049d8be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d8c0  893dcc4f5400           -mov dword ptr [0x544fcc], edi
    app->getMemory<x86::reg32>(x86::reg32(5525452) /* 0x544fcc */) = cpu.edi;
    // 0049d8c6  e82fd90000             -call 0x4ab1fa
    cpu.esp -= 4;
    sub_4ab1fa(app, cpu);
    if (cpu.terminate) return;
    // 0049d8cb  a3d04f5400             -mov dword ptr [0x544fd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5525456) /* 0x544fd0 */) = cpu.eax;
    // 0049d8d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d8d2  7511                   -jne 0x49d8e5
    if (!cpu.flags.zf)
    {
        goto L_0x0049d8e5;
    }
    // 0049d8d4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049d8d6  0f85f6010000           -jne 0x49dad2
    if (!cpu.flags.zf)
    {
        goto L_0x0049dad2;
    }
    // 0049d8dc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049d8de  2eff1580744b00         -call dword ptr cs:[0x4b7480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945024) /* 0x4b7480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049d8e5:
    // 0049d8e5  e8d5d40000             -call 0x4aadbf
    cpu.esp -= 4;
    sub_4aadbf(app, cpu);
    if (cpu.terminate) return;
    // 0049d8ea  2eff15d8744b00         -call dword ptr cs:[0x4b74d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945112) /* 0x4b74d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d8f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d8f3  a341ce4c00             -mov dword ptr [0x4cce41], eax
    app->getMemory<x86::reg32>(x86::reg32(5033537) /* 0x4cce41 */) = cpu.eax;
    // 0049d8f8  8915cc935400           -mov dword ptr [0x5493cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */) = cpu.edx;
    // 0049d8fe  2eff1528754b00         -call dword ptr cs:[0x4b7528]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945192) /* 0x4b7528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d905  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d907  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d909  a247ce4c00             -mov byte ptr [0x4cce47], al
    app->getMemory<x86::reg8>(x86::reg32(5033543) /* 0x4cce47 */) = cpu.al;
    // 0049d90e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049d911  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049d916  66a349ce4c00           -mov word ptr [0x4cce49], ax
    app->getMemory<x86::reg16>(x86::reg32(5033545) /* 0x4cce49 */) = cpu.ax;
    // 0049d91c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d91e  66a149ce4c00           -mov ax, word ptr [0x4cce49]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5033545) /* 0x4cce49 */);
    // 0049d924  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049d92a  a34bce4c00             -mov dword ptr [0x4cce4b], eax
    app->getMemory<x86::reg32>(x86::reg32(5033547) /* 0x4cce4b */) = cpu.eax;
    // 0049d92f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d931  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0049d934  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0049d936  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d93c  a34fce4c00             -mov dword ptr [0x4cce4f], eax
    app->getMemory<x86::reg32>(x86::reg32(5033551) /* 0x4cce4f */) = cpu.eax;
    // 0049d941  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d943  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0049d945  881548ce4c00           -mov byte ptr [0x4cce48], dl
    app->getMemory<x86::reg8>(x86::reg32(5033544) /* 0x4cce48 */) = cpu.dl;
    // 0049d94b  a353ce4c00             -mov dword ptr [0x4cce53], eax
    app->getMemory<x86::reg32>(x86::reg32(5033555) /* 0x4cce53 */) = cpu.eax;
    // 0049d950  a14fce4c00             -mov eax, dword ptr [0x4cce4f]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033551) /* 0x4cce4f */);
    // 0049d955  8b1553ce4c00           -mov edx, dword ptr [0x4cce53]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033555) /* 0x4cce53 */);
    // 0049d95b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049d95e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d960  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0049d965  a357ce4c00             -mov dword ptr [0x4cce57], eax
    app->getMemory<x86::reg32>(x86::reg32(5033559) /* 0x4cce57 */) = cpu.eax;
    // 0049d96a  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0049d971  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d972  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d974  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 0049d979  2eff15fc744b00         -call dword ptr cs:[0x4b74fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945148) /* 0x4b74fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d980  8d842410040000         -lea eax, [esp + 0x410]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1040) /* 0x410 */);
    // 0049d987  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049d989  e852db0000             -call 0x4ab4e0
    cpu.esp -= 4;
    strdup(app, cpu);
    if (cpu.terminate) return;
    // 0049d98e  a308ce4c00             -mov dword ptr [0x4cce08], eax
    app->getMemory<x86::reg32>(x86::reg32(5033480) /* 0x4cce08 */) = cpu.eax;
    // 0049d993  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d995  e88bdb0000             -call 0x4ab525
    cpu.esp -= 4;
    sub_4ab525(app, cpu);
    if (cpu.terminate) return;
    // 0049d99a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049d99c  e814dc0000             -call 0x4ab5b5
    cpu.esp -= 4;
    sub_4ab5b5(app, cpu);
    if (cpu.terminate) return;
    // 0049d9a1  a314ce4c00             -mov dword ptr [0x4cce14], eax
    app->getMemory<x86::reg32>(x86::reg32(5033492) /* 0x4cce14 */) = cpu.eax;
    // 0049d9a6  2eff15b0744b00         -call dword ptr cs:[0x4b74b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945072) /* 0x4b74b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049d9ad  e82edb0000             -call 0x4ab4e0
    cpu.esp -= 4;
    strdup(app, cpu);
    if (cpu.terminate) return;
    // 0049d9b2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d9b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d9b6  80fb22                 +cmp bl, 0x22
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d9b9  7514                   -jne 0x49d9cf
    if (!cpu.flags.zf)
    {
        goto L_0x0049d9cf;
    }
L_0x0049d9bb:
    // 0049d9bb  40                     -inc eax
    (cpu.eax)++;
    // 0049d9bc  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d9be  80fd22                 +cmp ch, 0x22
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049d9c1  7404                   -je 0x49d9c7
    if (cpu.flags.zf)
    {
        goto L_0x0049d9c7;
    }
    // 0049d9c3  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0049d9c5  75f4                   -jne 0x49d9bb
    if (!cpu.flags.zf)
    {
        goto L_0x0049d9bb;
    }
L_0x0049d9c7:
    // 0049d9c7  803800                 +cmp byte ptr [eax], 0
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
    // 0049d9ca  741e                   -je 0x49d9ea
    if (cpu.flags.zf)
    {
        goto L_0x0049d9ea;
    }
L_0x0049d9cc:
    // 0049d9cc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d9cd  eb1b                   -jmp 0x49d9ea
    goto L_0x0049d9ea;
L_0x0049d9cf:
    // 0049d9cf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d9d1  fec2                   -inc dl
    (cpu.dl)++;
    // 0049d9d3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d9d9  f682c8ea4c0002         +test byte ptr [edx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049d9e0  7508                   -jne 0x49d9ea
    if (!cpu.flags.zf)
    {
        goto L_0x0049d9ea;
    }
    // 0049d9e2  803800                 +cmp byte ptr [eax], 0
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
    // 0049d9e5  7403                   -je 0x49d9ea
    if (cpu.flags.zf)
    {
        goto L_0x0049d9ea;
    }
    // 0049d9e7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d9e8  ebe5                   -jmp 0x49d9cf
    goto L_0x0049d9cf;
L_0x0049d9ea:
    // 0049d9ea  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049d9ec  fec2                   -inc dl
    (cpu.dl)++;
    // 0049d9ee  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d9f4  f682c8ea4c0002         +test byte ptr [edx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049d9fb  75cf                   -jne 0x49d9cc
    if (!cpu.flags.zf)
    {
        goto L_0x0049d9cc;
    }
    // 0049d9fd  a304ce4c00             -mov dword ptr [0x4cce04], eax
    app->getMemory<x86::reg32>(x86::reg32(5033476) /* 0x4cce04 */) = cpu.eax;
    // 0049da02  2eff15b4744b00         -call dword ptr cs:[0x4b74b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945076) /* 0x4b74b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049da0b  0f845f000000           -je 0x49da70
    if (cpu.flags.zf)
    {
        goto L_0x0049da70;
    }
    // 0049da11  e89fdb0000             -call 0x4ab5b5
    cpu.esp -= 4;
    sub_4ab5b5(app, cpu);
    if (cpu.terminate) return;
    // 0049da16  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049da19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049da1b  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049da1f  751c                   -jne 0x49da3d
    if (!cpu.flags.zf)
    {
        goto L_0x0049da3d;
    }
L_0x0049da21:
    // 0049da21  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049da24  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049da27  6683fa22               +cmp dx, 0x22
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049da2b  7405                   -je 0x49da32
    if (cpu.flags.zf)
    {
        goto L_0x0049da32;
    }
    // 0049da2d  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0049da30  75ef                   -jne 0x49da21
    if (!cpu.flags.zf)
    {
        goto L_0x0049da21;
    }
L_0x0049da32:
    // 0049da32  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049da36  7423                   -je 0x49da5b
    if (cpu.flags.zf)
    {
        goto L_0x0049da5b;
    }
L_0x0049da38:
    // 0049da38  83c002                 +add eax, 2
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
    // 0049da3b  eb1e                   -jmp 0x49da5b
    goto L_0x0049da5b;
L_0x0049da3d:
    // 0049da3d  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049da3f  fec2                   -inc dl
    (cpu.dl)++;
    // 0049da41  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049da47  f682c8ea4c0002         +test byte ptr [edx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049da4e  750b                   -jne 0x49da5b
    if (!cpu.flags.zf)
    {
        goto L_0x0049da5b;
    }
    // 0049da50  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049da54  7405                   -je 0x49da5b
    if (cpu.flags.zf)
    {
        goto L_0x0049da5b;
    }
    // 0049da56  83c002                 +add eax, 2
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
    // 0049da59  ebe2                   -jmp 0x49da3d
    goto L_0x0049da3d;
L_0x0049da5b:
    // 0049da5b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049da5d  fec2                   -inc dl
    (cpu.dl)++;
    // 0049da5f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049da65  f682c8ea4c0002         +test byte ptr [edx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049da6c  740c                   -je 0x49da7a
    if (cpu.flags.zf)
    {
        goto L_0x0049da7a;
    }
    // 0049da6e  ebc8                   -jmp 0x49da38
    goto L_0x0049da38;
L_0x0049da70:
    // 0049da70  b850144c00             -mov eax, 0x4c1450
    cpu.eax = 4985936 /*0x4c1450*/;
    // 0049da75  e83bdb0000             -call 0x4ab5b5
    cpu.esp -= 4;
    sub_4ab5b5(app, cpu);
    if (cpu.terminate) return;
L_0x0049da7a:
    // 0049da7a  a310ce4c00             -mov dword ptr [0x4cce10], eax
    app->getMemory<x86::reg32>(x86::reg32(5033488) /* 0x4cce10 */) = cpu.eax;
    // 0049da7f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049da81  744a                   -je 0x49dacd
    if (cpu.flags.zf)
    {
        goto L_0x0049dacd;
    }
    // 0049da83  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0049da88  8d842418050000         -lea eax, [esp + 0x518]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 0049da8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049da90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049da91  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 0049da96  2eff15fc744b00         -call dword ptr cs:[0x4b74fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945148) /* 0x4b74fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049da9d  8d842414050000         -lea eax, [esp + 0x514]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 0049daa4  8d942408020000         -lea edx, [esp + 0x208]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0049daab  e830da0000             -call 0x4ab4e0
    cpu.esp -= 4;
    strdup(app, cpu);
    if (cpu.terminate) return;
    // 0049dab0  a30cce4c00             -mov dword ptr [0x4cce0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5033484) /* 0x4cce0c */) = cpu.eax;
    // 0049dab5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dab7  e869da0000             -call 0x4ab525
    cpu.esp -= 4;
    sub_4ab525(app, cpu);
    if (cpu.terminate) return;
    // 0049dabc  8d842408020000         -lea eax, [esp + 0x208]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0049dac3  e8edda0000             -call 0x4ab5b5
    cpu.esp -= 4;
    sub_4ab5b5(app, cpu);
    if (cpu.terminate) return;
    // 0049dac8  a318ce4c00             -mov dword ptr [0x4cce18], eax
    app->getMemory<x86::reg32>(x86::reg32(5033496) /* 0x4cce18 */) = cpu.eax;
L_0x0049dacd:
    // 0049dacd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049dad2:
    // 0049dad2  81c418060000           -add esp, 0x618
    (cpu.esp) += x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 0049dad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dad9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dada  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dadb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dadc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049dadc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dadd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dade  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dadf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dae0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049dae2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049dae4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049dae6  2eff1504754b00         -call dword ptr cs:[0x4b7504]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945156) /* 0x4b7504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049daed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049daef  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049daf1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049daf3  e8b9fdffff             -call 0x49d8b1
    cpu.esp -= 4;
    sub_49d8b1(app, cpu);
    if (cpu.terminate) return;
    // 0049daf8  ba24ce4c00             -mov edx, 0x4cce24
    cpu.edx = 5033508 /*0x4cce24*/;
    // 0049dafd  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db03  e8d4da0000             -call 0x4ab5dc
    cpu.esp -= 4;
    sub_4ab5dc(app, cpu);
    if (cpu.terminate) return;
    // 0049db08  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049db0a  e854df0000             -call 0x4aba63
    cpu.esp -= 4;
    sub_4aba63(app, cpu);
    if (cpu.terminate) return;
    // 0049db0f  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 0049db14  e806540000             -call 0x4a2f1f
    cpu.esp -= 4;
    sub_4a2f1f(app, cpu);
    if (cpu.terminate) return;
    // 0049db19  ff15c8e34c00           -call dword ptr [0x4ce3c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039048) /* 0x4ce3c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db1f  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0049db24  e8f6530000             -call 0x4a2f1f
    cpu.esp -= 4;
    sub_4a2f1f(app, cpu);
    if (cpu.terminate) return;
    // 0049db29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
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
}

/* align: skip  */
void Application::sub_49db2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049db2e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049db30  833dcc4f540000         +cmp dword ptr [0x544fcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5525452) /* 0x544fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049db37  7418                   -je 0x49db51
    if (cpu.flags.zf)
    {
        goto L_0x0049db51;
    }
    // 0049db39  833dd0e34c0000         +cmp dword ptr [0x4ce3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5039056) /* 0x4ce3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049db40  7426                   -je 0x49db68
    if (cpu.flags.zf)
    {
        goto L_0x0049db68;
    }
    // 0049db42  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049db47  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049db49  ff15d0e34c00           -call dword ptr [0x4ce3d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039056) /* 0x4ce3d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db4f  eb17                   -jmp 0x49db68
    goto L_0x0049db68;
L_0x0049db51:
    // 0049db51  e859df0000             -call 0x4abaaf
    cpu.esp -= 4;
    sub_4abaaf(app, cpu);
    if (cpu.terminate) return;
    // 0049db56  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0049db5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049db5d  e809540000             -call 0x4a2f6b
    cpu.esp -= 4;
    sub_4a2f6b(app, cpu);
    if (cpu.terminate) return;
    // 0049db62  ff15c4e34c00           -call dword ptr [0x4ce3c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039044) /* 0x4ce3c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049db68:
    // 0049db68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049db69  2eff1580744b00         -call dword ptr cs:[0x4b7480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945024) /* 0x4b7480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049db71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049db72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049db73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049db74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049db75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049db77  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049db7a  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db80  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049db83  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049db86  83fb01                 +cmp ebx, 1
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
    // 0049db89  741e                   -je 0x49dba9
    if (cpu.flags.zf)
    {
        goto L_0x0049dba9;
    }
    // 0049db8b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049db8d  7413                   -je 0x49dba2
    if (cpu.flags.zf)
    {
        goto L_0x0049dba2;
    }
    // 0049db8f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049db92  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db98  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049db9d  e98d000000             -jmp 0x49dc2f
    goto L_0x0049dc2f;
L_0x0049dba2:
    // 0049dba2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0049dba9:
    // 0049dba9  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049dbad  7515                   -jne 0x49dbc4
    if (!cpu.flags.zf)
    {
        goto L_0x0049dbc4;
    }
    // 0049dbaf  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049dbb4  e847c5ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049dbb9  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049dbbd  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0049dbc2  eb1f                   -jmp 0x49dbe3
    goto L_0x0049dbe3;
L_0x0049dbc4:
    // 0049dbc4  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049dbc7  4e                     -dec esi
    (cpu.esi)--;
    // 0049dbc8  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049dbcb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049dbcd  7d0b                   -jge 0x49dbda
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dbda;
    }
    // 0049dbcf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049dbd1  e85f000000             -call 0x49dc35
    cpu.esp -= 4;
    sub_49dc35(app, cpu);
    if (cpu.terminate) return;
    // 0049dbd6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049dbd8  eb09                   -jmp 0x49dbe3
    goto L_0x0049dbe3;
L_0x0049dbda:
    // 0049dbda  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dbdc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dbde  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dbe0  40                     -inc eax
    (cpu.eax)++;
    // 0049dbe1  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0049dbe3:
    // 0049dbe3  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 0049dbe7  753b                   -jne 0x49dc24
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc24;
    }
    // 0049dbe9  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dbec  7523                   -jne 0x49dc11
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc11;
    }
    // 0049dbee  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049dbf1  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049dbf2  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0049dbf5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049dbf7  7d0b                   -jge 0x49dc04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dc04;
    }
    // 0049dbf9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049dbfb  e835000000             -call 0x49dc35
    cpu.esp -= 4;
    sub_49dc35(app, cpu);
    if (cpu.terminate) return;
    // 0049dc00  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049dc02  eb0d                   -jmp 0x49dc11
    goto L_0x0049dc11;
L_0x0049dc04:
    // 0049dc04  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dc06  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dc08  40                     -inc eax
    (cpu.eax)++;
    // 0049dc09  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dc0f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0049dc11:
    // 0049dc11  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dc14  750e                   -jne 0x49dc24
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc24;
    }
    // 0049dc16  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049dc19  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0049dc1c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0049dc21  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x0049dc24:
    // 0049dc24  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dc27  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049dc2f:
    // 0049dc2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49db70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049db70;
    // 0049db2e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049db30  833dcc4f540000         +cmp dword ptr [0x544fcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5525452) /* 0x544fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049db37  7418                   -je 0x49db51
    if (cpu.flags.zf)
    {
        goto L_0x0049db51;
    }
    // 0049db39  833dd0e34c0000         +cmp dword ptr [0x4ce3d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5039056) /* 0x4ce3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049db40  7426                   -je 0x49db68
    if (cpu.flags.zf)
    {
        goto L_0x0049db68;
    }
    // 0049db42  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049db47  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049db49  ff15d0e34c00           -call dword ptr [0x4ce3d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039056) /* 0x4ce3d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db4f  eb17                   -jmp 0x49db68
    goto L_0x0049db68;
L_0x0049db51:
    // 0049db51  e859df0000             -call 0x4abaaf
    cpu.esp -= 4;
    sub_4abaaf(app, cpu);
    if (cpu.terminate) return;
    // 0049db56  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0049db5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049db5d  e809540000             -call 0x4a2f6b
    cpu.esp -= 4;
    sub_4a2f6b(app, cpu);
    if (cpu.terminate) return;
    // 0049db62  ff15c4e34c00           -call dword ptr [0x4ce3c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039044) /* 0x4ce3c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049db68:
    // 0049db68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049db69  2eff1580744b00         -call dword ptr cs:[0x4b7480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945024) /* 0x4b7480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x0049db70:
    // 0049db70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049db71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049db72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049db73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049db74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049db75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049db77  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049db7a  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db80  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049db83  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049db86  83fb01                 +cmp ebx, 1
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
    // 0049db89  741e                   -je 0x49dba9
    if (cpu.flags.zf)
    {
        goto L_0x0049dba9;
    }
    // 0049db8b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049db8d  7413                   -je 0x49dba2
    if (cpu.flags.zf)
    {
        goto L_0x0049dba2;
    }
    // 0049db8f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049db92  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049db98  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049db9d  e98d000000             -jmp 0x49dc2f
    goto L_0x0049dc2f;
L_0x0049dba2:
    // 0049dba2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0049dba9:
    // 0049dba9  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049dbad  7515                   -jne 0x49dbc4
    if (!cpu.flags.zf)
    {
        goto L_0x0049dbc4;
    }
    // 0049dbaf  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049dbb4  e847c5ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049dbb9  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049dbbd  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0049dbc2  eb1f                   -jmp 0x49dbe3
    goto L_0x0049dbe3;
L_0x0049dbc4:
    // 0049dbc4  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049dbc7  4e                     -dec esi
    (cpu.esi)--;
    // 0049dbc8  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049dbcb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049dbcd  7d0b                   -jge 0x49dbda
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dbda;
    }
    // 0049dbcf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049dbd1  e85f000000             -call 0x49dc35
    cpu.esp -= 4;
    sub_49dc35(app, cpu);
    if (cpu.terminate) return;
    // 0049dbd6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049dbd8  eb09                   -jmp 0x49dbe3
    goto L_0x0049dbe3;
L_0x0049dbda:
    // 0049dbda  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dbdc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dbde  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dbe0  40                     -inc eax
    (cpu.eax)++;
    // 0049dbe1  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0049dbe3:
    // 0049dbe3  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 0049dbe7  753b                   -jne 0x49dc24
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc24;
    }
    // 0049dbe9  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dbec  7523                   -jne 0x49dc11
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc11;
    }
    // 0049dbee  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049dbf1  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049dbf2  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0049dbf5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049dbf7  7d0b                   -jge 0x49dc04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dc04;
    }
    // 0049dbf9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049dbfb  e835000000             -call 0x49dc35
    cpu.esp -= 4;
    sub_49dc35(app, cpu);
    if (cpu.terminate) return;
    // 0049dc00  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049dc02  eb0d                   -jmp 0x49dc11
    goto L_0x0049dc11;
L_0x0049dc04:
    // 0049dc04  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dc06  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049dc08  40                     -inc eax
    (cpu.eax)++;
    // 0049dc09  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dc0f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0049dc11:
    // 0049dc11  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dc14  750e                   -jne 0x49dc24
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc24;
    }
    // 0049dc16  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049dc19  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0049dc1c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0049dc21  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x0049dc24:
    // 0049dc24  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dc27  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dc2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049dc2f:
    // 0049dc2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dc35(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049dc35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dc36  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dc37  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dc38  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dc3a  e825000000             -call 0x49dc64
    cpu.esp -= 4;
    sub_49dc64(app, cpu);
    if (cpu.terminate) return;
    // 0049dc3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049dc41  7509                   -jne 0x49dc4c
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc4c;
    }
    // 0049dc43  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049dc48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dc4c:
    // 0049dc4c  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049dc4f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dc51  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049dc52  41                     -inc ecx
    (cpu.ecx)++;
    // 0049dc53  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049dc56  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049dc58  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049dc5b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dc60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dc63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dc64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049dc64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dc65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dc66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dc67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dc68  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049dc6a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049dc6d  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dc71  7507                   -jne 0x49dc7a
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc7a;
    }
    // 0049dc73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049dc75  e801540000             -call 0x4a307b
    cpu.esp -= 4;
    sub_4a307b(app, cpu);
    if (cpu.terminate) return;
L_0x0049dc7a:
    // 0049dc7a  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0049dc7d  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 0049dc80  740f                   -je 0x49dc91
    if (cpu.flags.zf)
    {
        goto L_0x0049dc91;
    }
    // 0049dc82  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 0049dc85  740a                   -je 0x49dc91
    if (cpu.flags.zf)
    {
        goto L_0x0049dc91;
    }
    // 0049dc87  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0049dc8c  e847de0000             -call 0x4abad8
    cpu.esp -= 4;
    sub_4abad8(app, cpu);
    if (cpu.terminate) return;
L_0x0049dc91:
    // 0049dc91  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049dc94  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0049dc97  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049dc9a  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 0049dc9d  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049dca0  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049dca2  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049dca5  2500240000             -and eax, 0x2400
    cpu.eax &= x86::reg32(x86::sreg32(9216 /*0x2400*/));
    // 0049dcaa  3d00240000             +cmp eax, 0x2400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9216 /*0x2400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dcaf  7523                   -jne 0x49dcd4
    if (!cpu.flags.zf)
    {
        goto L_0x0049dcd4;
    }
    // 0049dcb1  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049dcb4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049dcb6  751c                   -jne 0x49dcd4
    if (!cpu.flags.zf)
    {
        goto L_0x0049dcd4;
    }
    // 0049dcb8  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049dcbb  e853de0000             -call 0x4abb13
    cpu.esp -= 4;
    sub_4abb13(app, cpu);
    if (cpu.terminate) return;
    // 0049dcc0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dcc2  83f8ff                 +cmp eax, -1
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
    // 0049dcc5  742a                   -je 0x49dcf1
    if (cpu.flags.zf)
    {
        goto L_0x0049dcf1;
    }
    // 0049dcc7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049dcc9  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049dccb  c7410401000000         -mov dword ptr [ecx + 4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0049dcd2  eb3c                   -jmp 0x49dd10
    goto L_0x0049dd10;
L_0x0049dcd4:
    // 0049dcd4  f6410d04               +test byte ptr [ecx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0049dcd8  7407                   -je 0x49dce1
    if (cpu.flags.zf)
    {
        goto L_0x0049dce1;
    }
    // 0049dcda  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049dcdf  eb03                   -jmp 0x49dce4
    goto L_0x0049dce4;
L_0x0049dce1:
    // 0049dce1  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
L_0x0049dce4:
    // 0049dce4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049dce6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049dce9  e8737f0000             -call 0x4a5c61
    cpu.esp -= 4;
    sub_4a5c61(app, cpu);
    if (cpu.terminate) return;
    // 0049dcee  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0049dcf1:
    // 0049dcf1  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049dcf4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049dcf6  7f18                   -jg 0x49dd10
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049dd10;
    }
    // 0049dcf8  7506                   -jne 0x49dd00
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd00;
    }
    // 0049dcfa  80490c10               +or byte ptr [ecx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049dcfe  eb10                   -jmp 0x49dd10
    goto L_0x0049dd10;
L_0x0049dd00:
    // 0049dd00  8a790c                 -mov bh, byte ptr [ecx + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049dd03  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049dd0a  80cf20                 -or bh, 0x20
    cpu.bh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049dd0d  88790c                 -mov byte ptr [ecx + 0xc], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bh;
L_0x0049dd10:
    // 0049dd10  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049dd13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dd18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049dd18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049dd19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dd1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dd1b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049dd1c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049dd1e  83f8ff                 +cmp eax, -1
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
    // 0049dd21  0f84a6000000           -je 0x49ddcd
    if (cpu.flags.zf)
    {
        goto L_0x0049ddcd;
    }
    // 0049dd27  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dd2a  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dd30  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dd33  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049dd36  83f901                 +cmp ecx, 1
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
    // 0049dd39  741e                   -je 0x49dd59
    if (cpu.flags.zf)
    {
        goto L_0x0049dd59;
    }
    // 0049dd3b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049dd3d  7413                   -je 0x49dd52
    if (cpu.flags.zf)
    {
        goto L_0x0049dd52;
    }
L_0x0049dd3f:
    // 0049dd3f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dd42  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dd48  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049dd4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dd51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049dd52:
    // 0049dd52  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0049dd59:
    // 0049dd59  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0049dd5d  75e0                   -jne 0x49dd3f
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd3f;
    }
    // 0049dd5f  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049dd63  74da                   -je 0x49dd3f
    if (cpu.flags.zf)
    {
        goto L_0x0049dd3f;
    }
    // 0049dd65  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dd68  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dd6c  7507                   -jne 0x49dd75
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd75;
    }
    // 0049dd6e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049dd70  e806530000             -call 0x4a307b
    cpu.esp -= 4;
    sub_4a307b(app, cpu);
    if (cpu.terminate) return;
L_0x0049dd75:
    // 0049dd75  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049dd78  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049dd7a  7517                   -jne 0x49dd93
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd93;
    }
    // 0049dd7c  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0049dd83  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dd86  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0049dd89  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049dd8c  01c8                   +add eax, ecx
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
    // 0049dd8e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049dd8f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0049dd91  eb21                   -jmp 0x49ddb4
    goto L_0x0049ddb4;
L_0x0049dd93:
    // 0049dd93  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dd96  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dd98  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dd9b  74a2                   -je 0x49dd3f
    if (cpu.flags.zf)
    {
        goto L_0x0049dd3f;
    }
    // 0049dd9d  8d7d01                 -lea edi, [ebp + 1]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0049dda0  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0049dda2  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049dda5  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049dda6  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 0049dda8  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049ddab  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049ddb0  39d8                   +cmp eax, ebx
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
    // 0049ddb2  7404                   -je 0x49ddb8
    if (cpu.flags.zf)
    {
        goto L_0x0049ddb8;
    }
L_0x0049ddb4:
    // 0049ddb4  804a0c04               -or byte ptr [edx + 0xc], 4
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0049ddb8:
    // 0049ddb8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049ddba  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0049ddbc  80620cef               -and byte ptr [edx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049ddc0  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ddc3  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ddc9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ddcb  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x0049ddcd:
    // 0049ddcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ddd2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ddd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ddd3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ddd5  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ddd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ddd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ddd9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ddd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ddda  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049dddc  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049dddf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dde0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49dde1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049dde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dde2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dde3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dde4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049dde5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049dde8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ddea  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049dded  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049ddef  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ddf3  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049ddf6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ddf8  80e4fd                 -and ah, 0xfd
    cpu.ah &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0049ddfb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049ddfd  886610                 -mov byte ptr [esi + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ah;
L_0x0049de00:
    // 0049de00  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049de03  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049de06  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049de09  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0049de0b  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049de11  0f8423020000           -je 0x49e03a
    if (cpu.flags.zf)
    {
        goto L_0x0049e03a;
    }
    // 0049de17  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0049de19  fec0                   -inc al
    (cpu.al)++;
    // 0049de1b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049de20  f680c8ea4c0002         +test byte ptr [eax + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049de27  740e                   -je 0x49de37
    if (cpu.flags.zf)
    {
        goto L_0x0049de37;
    }
    // 0049de29  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049de2b  e81c030000             -call 0x49e14c
    cpu.esp -= 4;
    sub_49e14c(app, cpu);
    if (cpu.terminate) return;
    // 0049de30  01c7                   +add edi, eax
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
    // 0049de32  e9cd010000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049de37:
    // 0049de37  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049de3a  7425                   -je 0x49de61
    if (cpu.flags.zf)
    {
        goto L_0x0049de61;
    }
    // 0049de3c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049de3e  e88fffffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049de43  39d8                   +cmp eax, ebx
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
    // 0049de45  0f84b8010000           -je 0x49e003
    if (cpu.flags.zf)
    {
        goto L_0x0049e003;
    }
L_0x0049de4b:
    // 0049de4b  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049de4f  0f85e5010000           -jne 0x49e03a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e03a;
    }
    // 0049de55  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049de57  e87dffffff             -call 0x49ddd9
    cpu.esp -= 4;
    sub_49ddd9(app, cpu);
    if (cpu.terminate) return;
    // 0049de5c  e9d9010000             -jmp 0x49e03a
    goto L_0x0049e03a;
L_0x0049de61:
    // 0049de61  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049de64  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049de66  e8ea010000             -call 0x49e055
    cpu.esp -= 4;
    sub_49e055(app, cpu);
    if (cpu.terminate) return;
    // 0049de6b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049de6d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049de70  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049de72  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049de74  7404                   -je 0x49de7a
    if (cpu.flags.zf)
    {
        goto L_0x0049de7a;
    }
    // 0049de76  40                     -inc eax
    (cpu.eax)++;
    // 0049de77  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0049de7a:
    // 0049de7a  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049de7d  7265                   -jb 0x49dee4
    if (cpu.flags.cf)
    {
        goto L_0x0049dee4;
    }
    // 0049de7f  0f86c3000000           -jbe 0x49df48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df48;
    }
    // 0049de85  83fb6f                 +cmp ebx, 0x6f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049de88  7233                   -jb 0x49debd
    if (cpu.flags.cf)
    {
        goto L_0x0049debd;
    }
    // 0049de8a  0f86e1000000           -jbe 0x49df71
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df71;
    }
    // 0049de90  83fb73                 +cmp ebx, 0x73
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049de93  7223                   -jb 0x49deb8
    if (cpu.flags.cf)
    {
        goto L_0x0049deb8;
    }
    // 0049de95  0f860e010000           -jbe 0x49dfa9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dfa9;
    }
    // 0049de9b  83fb75                 +cmp ebx, 0x75
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049de9e  0f8260010000           -jb 0x49e004
    if (cpu.flags.cf)
    {
        goto L_0x0049e004;
    }
    // 0049dea4  0f86d3000000           -jbe 0x49df7d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df7d;
    }
    // 0049deaa  83fb78                 +cmp ebx, 0x78
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x0049dead:
    // 0049dead  0f84d9000000           -je 0x49df8c
    if (cpu.flags.zf)
    {
        goto L_0x0049df8c;
    }
    // 0049deb3  e94c010000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049deb8:
    // 0049deb8  83fb70                 +cmp ebx, 0x70
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049debb  ebf0                   -jmp 0x49dead
    goto L_0x0049dead;
L_0x0049debd:
    // 0049debd  83fb69                 +cmp ebx, 0x69
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dec0  7214                   -jb 0x49ded6
    if (cpu.flags.cf)
    {
        goto L_0x0049ded6;
    }
    // 0049dec2  0f869a000000           -jbe 0x49df62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df62;
    }
    // 0049dec8  83fb6e                 +cmp ebx, 0x6e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049decb  0f8414010000           -je 0x49dfe5
    if (cpu.flags.zf)
    {
        goto L_0x0049dfe5;
    }
    // 0049ded1  e92e010000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049ded6:
    // 0049ded6  83fb67                 +cmp ebx, 0x67
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ded9  0f86b9000000           -jbe 0x49df98
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df98;
    }
    // 0049dedf  e920010000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049dee4:
    // 0049dee4  83fb47                 +cmp ebx, 0x47
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dee7  723c                   -jb 0x49df25
    if (cpu.flags.cf)
    {
        goto L_0x0049df25;
    }
    // 0049dee9  0f86a9000000           -jbe 0x49df98
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df98;
    }
    // 0049deef  83fb58                 +cmp ebx, 0x58
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049def2  7223                   -jb 0x49df17
    if (cpu.flags.cf)
    {
        goto L_0x0049df17;
    }
    // 0049def4  0f8692000000           -jbe 0x49df8c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049df8c;
    }
    // 0049defa  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049defd  0f8201010000           -jb 0x49e004
    if (cpu.flags.cf)
    {
        goto L_0x0049e004;
    }
    // 0049df03  0f86ad000000           -jbe 0x49dfb6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dfb6;
    }
    // 0049df09  83fb63                 +cmp ebx, 0x63
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df0c  0f84b7000000           -je 0x49dfc9
    if (cpu.flags.zf)
    {
        goto L_0x0049dfc9;
    }
    // 0049df12  e9ed000000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049df17:
    // 0049df17  83fb53                 +cmp ebx, 0x53
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df1a  0f8485000000           -je 0x49dfa5
    if (cpu.flags.zf)
    {
        goto L_0x0049dfa5;
    }
    // 0049df20  e9df000000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049df25:
    // 0049df25  83fb43                 +cmp ebx, 0x43
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df28  7210                   -jb 0x49df3a
    if (cpu.flags.cf)
    {
        goto L_0x0049df3a;
    }
    // 0049df2a  0f8695000000           -jbe 0x49dfc5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dfc5;
    }
    // 0049df30  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df33  7463                   -je 0x49df98
    if (cpu.flags.zf)
    {
        goto L_0x0049df98;
    }
    // 0049df35  e9ca000000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049df3a:
    // 0049df3a  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df3d  0f84b1000000           -je 0x49dff4
    if (cpu.flags.zf)
    {
        goto L_0x0049dff4;
    }
    // 0049df43  e9bc000000             -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049df48:
    // 0049df48  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049df4d  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
L_0x0049df52:
    // 0049df52  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049df56  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049df58:
    // 0049df58  e8c8080000             -call 0x49e825
    cpu.esp -= 4;
    sub_49e825(app, cpu);
    if (cpu.terminate) return;
    // 0049df5d  e972000000             -jmp 0x49dfd4
    goto L_0x0049dfd4;
L_0x0049df62:
    // 0049df62  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049df67  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049df6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049df6d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0049df6f  ebe7                   -jmp 0x49df58
    goto L_0x0049df58;
L_0x0049df71:
    // 0049df71  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049df76  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0049df7b  ebd5                   -jmp 0x49df52
    goto L_0x0049df52;
L_0x0049df7d:
    // 0049df7d  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0049df82  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049df86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049df88  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049df8a  ebcc                   -jmp 0x49df58
    goto L_0x0049df58;
L_0x0049df8c:
    // 0049df8c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049df91  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0049df96  ebba                   -jmp 0x49df52
    goto L_0x0049df52;
L_0x0049df98:
    // 0049df98  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049df9c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049df9e  e8ac050000             -call 0x49e54f
    cpu.esp -= 4;
    sub_49e54f(app, cpu);
    if (cpu.terminate) return;
    // 0049dfa3  eb2f                   -jmp 0x49dfd4
    goto L_0x0049dfd4;
L_0x0049dfa5:
    // 0049dfa5  804e1020               +or byte ptr [esi + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
L_0x0049dfa9:
    // 0049dfa9  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049dfad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dfaf  e8b1020000             -call 0x49e265
    cpu.esp -= 4;
    sub_49e265(app, cpu);
    if (cpu.terminate) return;
    // 0049dfb4  eb1e                   -jmp 0x49dfd4
    goto L_0x0049dfd4;
L_0x0049dfb6:
    // 0049dfb6  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049dfb8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049dfbc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dfbe  e896040000             -call 0x49e459
    cpu.esp -= 4;
    sub_49e459(app, cpu);
    if (cpu.terminate) return;
    // 0049dfc3  eb0f                   -jmp 0x49dfd4
    goto L_0x0049dfd4;
L_0x0049dfc5:
    // 0049dfc5  804e1020               -or byte ptr [esi + 0x10], 0x20
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0049dfc9:
    // 0049dfc9  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049dfcd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dfcf  e8af010000             -call 0x49e183
    cpu.esp -= 4;
    sub_49e183(app, cpu);
    if (cpu.terminate) return;
L_0x0049dfd4:
    // 0049dfd4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049dfd6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049dfd8  7e60                   -jle 0x49e03a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e03a;
    }
    // 0049dfda  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dfdc  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049dfe0  7422                   -je 0x49e004
    if (cpu.flags.zf)
    {
        goto L_0x0049e004;
    }
    // 0049dfe2  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049dfe3  eb1f                   -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049dfe5:
    // 0049dfe5  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049dfe9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049dfeb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dfed  e8c6030000             -call 0x49e3b8
    cpu.esp -= 4;
    sub_49e3b8(app, cpu);
    if (cpu.terminate) return;
    // 0049dff2  eb10                   -jmp 0x49e004
    goto L_0x0049e004;
L_0x0049dff4:
    // 0049dff4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049dff6  e8d7fdffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049dffb  39d8                   +cmp eax, ebx
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
    // 0049dffd  0f8548feffff           -jne 0x49de4b
    if (!cpu.flags.zf)
    {
        goto L_0x0049de4b;
    }
L_0x0049e003:
    // 0049e003  47                     -inc edi
    (cpu.edi)++;
L_0x0049e004:
    // 0049e004  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049e008  0f84f2fdffff           -je 0x49de00
    if (cpu.flags.zf)
    {
        goto L_0x0049de00;
    }
    // 0049e00e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e011  803825                 +cmp byte ptr [eax], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e014  7524                   -jne 0x49e03a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e03a;
    }
    // 0049e016  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049e019  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049e01b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e01d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049e020  e830000000             -call 0x49e055
    cpu.esp -= 4;
    sub_49e055(app, cpu);
    if (cpu.terminate) return;
    // 0049e025  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049e028  80386e                 +cmp byte ptr [eax], 0x6e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e02b  750d                   -jne 0x49e03a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e03a;
    }
    // 0049e02d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e031  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049e033  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e035  e87e030000             -call 0x49e3b8
    cpu.esp -= 4;
    sub_49e3b8(app, cpu);
    if (cpu.terminate) return;
L_0x0049e03a:
    // 0049e03a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e03c  750d                   -jne 0x49e04b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e04b;
    }
    // 0049e03e  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049e042  7407                   -je 0x49e04b
    if (cpu.flags.zf)
    {
        goto L_0x0049e04b;
    }
    // 0049e044  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049e049  eb02                   -jmp 0x49e04d
    goto L_0x0049e04d;
L_0x0049e04b:
    // 0049e04b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0049e04d:
    // 0049e04d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e050  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e051  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e052  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e053  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e054  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e055(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e055  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e056  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e057  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e058  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e05b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049e05d  8a5210                 -mov dl, byte ptr [edx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049e060  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049e063  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0049e066  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 0049e068  c7430cffffffff         -mov dword ptr [ebx + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 0049e06f  80e603                 -and dh, 3
    cpu.dh &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 0049e072  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 0049e075  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e078  750a                   -jne 0x49e084
    if (!cpu.flags.zf)
    {
        goto L_0x0049e084;
    }
    // 0049e07a  8a6b10                 -mov ch, byte ptr [ebx + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049e07d  80e5fe                 -and ch, 0xfe
    cpu.ch &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049e080  40                     -inc eax
    (cpu.eax)++;
    // 0049e081  886b10                 -mov byte ptr [ebx + 0x10], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ch;
L_0x0049e084:
    // 0049e084  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e086  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049e088  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049e08b  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049e08e  fec2                   -inc dl
    (cpu.dl)++;
    // 0049e090  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e096  f682c8ea4c0020         +test byte ptr [edx + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e09d  7428                   -je 0x49e0c7
    if (cpu.flags.zf)
    {
        goto L_0x0049e0c7;
    }
    // 0049e09f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e0a1:
    // 0049e0a1  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0049e0a4  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e0a7  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049e0aa  40                     -inc eax
    (cpu.eax)++;
    // 0049e0ab  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049e0ad  0fb630                 -movzx esi, byte ptr [eax]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 0049e0b0  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0049e0b3  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0049e0b6  fec1                   -inc cl
    (cpu.cl)++;
    // 0049e0b8  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 0049e0bb  f686c8ea4c0020         +test byte ptr [esi + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e0c2  75dd                   -jne 0x49e0a1
    if (!cpu.flags.zf)
    {
        goto L_0x0049e0a1;
    }
    // 0049e0c4  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0049e0c7:
    // 0049e0c7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049e0c9  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049e0cc  80f94e                 +cmp cl, 0x4e
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e0cf  7506                   -jne 0x49e0d7
    if (!cpu.flags.zf)
    {
        goto L_0x0049e0d7;
    }
    // 0049e0d1  804b1008               +or byte ptr [ebx + 0x10], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0049e0d5  eb09                   -jmp 0x49e0e0
    goto L_0x0049e0e0;
L_0x0049e0d7:
    // 0049e0d7  80f946                 +cmp cl, 0x46
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e0da  7506                   -jne 0x49e0e2
    if (!cpu.flags.zf)
    {
        goto L_0x0049e0e2;
    }
    // 0049e0dc  804b1004               -or byte ptr [ebx + 0x10], 4
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0049e0e0:
    // 0049e0e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049e0e2:
    // 0049e0e2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049e0e4  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049e0e7  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e0ea  7210                   -jb 0x49e0fc
    if (cpu.flags.cf)
    {
        goto L_0x0049e0fc;
    }
    // 0049e0ec  761c                   -jbe 0x49e10a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e10a;
    }
    // 0049e0ee  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e0f1  7252                   -jb 0x49e145
    if (cpu.flags.cf)
    {
        goto L_0x0049e145;
    }
    // 0049e0f3  761f                   -jbe 0x49e114
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e114;
    }
    // 0049e0f5  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e0f8  741a                   -je 0x49e114
    if (cpu.flags.zf)
    {
        goto L_0x0049e114;
    }
    // 0049e0fa  eb49                   -jmp 0x49e145
    goto L_0x0049e145;
L_0x0049e0fc:
    // 0049e0fc  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e0ff  7244                   -jb 0x49e145
    if (cpu.flags.cf)
    {
        goto L_0x0049e145;
    }
    // 0049e101  762a                   -jbe 0x49e12d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e12d;
    }
    // 0049e103  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e106  7418                   -je 0x49e120
    if (cpu.flags.zf)
    {
        goto L_0x0049e120;
    }
    // 0049e108  eb3b                   -jmp 0x49e145
    goto L_0x0049e145;
L_0x0049e10a:
    // 0049e10a  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049e10d  80ce10                 +or dh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049e110  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e112  eb2e                   -jmp 0x49e142
    goto L_0x0049e142;
L_0x0049e114:
    // 0049e114  8a5310                 -mov dl, byte ptr [ebx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049e117  80ca20                 +or dl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049e11a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e11b  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0049e11e  eb25                   -jmp 0x49e145
    goto L_0x0049e145;
L_0x0049e120:
    // 0049e120  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049e123  80c940                 +or cl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0049e126  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e128  884b10                 -mov byte ptr [ebx + 0x10], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.cl;
    // 0049e12b  eb18                   -jmp 0x49e145
    goto L_0x0049e145;
L_0x0049e12d:
    // 0049e12d  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e131  7512                   -jne 0x49e145
    if (!cpu.flags.zf)
    {
        goto L_0x0049e145;
    }
    // 0049e133  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e137  750c                   -jne 0x49e145
    if (!cpu.flags.zf)
    {
        goto L_0x0049e145;
    }
    // 0049e139  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049e13c  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0049e13f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0049e142:
    // 0049e142  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
L_0x0049e145:
    // 0049e145  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e148  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e149  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e14a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e14b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e14c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e14c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e14d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e14e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e14f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e151  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049e153:
    // 0049e153  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e155  e878fcffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e15a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e15c  fec2                   -inc dl
    (cpu.dl)++;
    // 0049e15e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e164  f682c8ea4c0002         +test byte ptr [edx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049e16b  7403                   -je 0x49e170
    if (cpu.flags.zf)
    {
        goto L_0x0049e170;
    }
    // 0049e16d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e16e  ebe3                   -jmp 0x49e153
    goto L_0x0049e153;
L_0x0049e170:
    // 0049e170  f6431002               +test byte ptr [ebx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049e174  7507                   -jne 0x49e17d
    if (!cpu.flags.zf)
    {
        goto L_0x0049e17d;
    }
    // 0049e176  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049e178  e85cfcffff             -call 0x49ddd9
    cpu.esp -= 4;
    sub_49ddd9(app, cpu);
    if (cpu.terminate) return;
L_0x0049e17d:
    // 0049e17d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e17f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e180  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e181  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e182  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e183(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e183  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e184  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e185  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e186  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e187  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e188  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e189  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e18c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e18e  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049e192  7437                   -je 0x49e1cb
    if (cpu.flags.zf)
    {
        goto L_0x0049e1cb;
    }
    // 0049e194  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e197  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0049e19a  740c                   -je 0x49e1a8
    if (cpu.flags.zf)
    {
        goto L_0x0049e1a8;
    }
    // 0049e19c  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e19e  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e1a1  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0049e1a3  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0049e1a6  eb23                   -jmp 0x49e1cb
    goto L_0x0049e1cb;
L_0x0049e1a8:
    // 0049e1a8  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0049e1ab  7410                   -je 0x49e1bd
    if (cpu.flags.zf)
    {
        goto L_0x0049e1bd;
    }
    // 0049e1ad  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e1af  83c604                 +add esi, 4
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
    // 0049e1b2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e1b4  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0049e1b6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e1b8  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0049e1bb  eb0e                   -jmp 0x49e1cb
    goto L_0x0049e1cb;
L_0x0049e1bd:
    // 0049e1bd  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e1bf  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e1c2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e1c4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0049e1c6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e1c8  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0049e1cb:
    // 0049e1cb  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049e1ce  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e1d0  83ffff                 +cmp edi, -1
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
    // 0049e1d3  7505                   -jne 0x49e1da
    if (!cpu.flags.zf)
    {
        goto L_0x0049e1da;
    }
    // 0049e1d5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x0049e1da:
    // 0049e1da  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e1dc  0f8e77000000           -jle 0x49e259
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e259;
    }
    // 0049e1e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e1e4  e8e9fbffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e1e9  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e1ec  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0049e1ef  0f8564000000           -jne 0x49e259
    if (!cpu.flags.zf)
    {
        goto L_0x0049e259;
    }
    // 0049e1f5  45                     -inc ebp
    (cpu.ebp)++;
    // 0049e1f6  4f                     -dec edi
    (cpu.edi)--;
    // 0049e1f7  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0049e1fa  74de                   -je 0x49e1da
    if (cpu.flags.zf)
    {
        goto L_0x0049e1da;
    }
    // 0049e1fc  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 0049e1ff  7452                   -je 0x49e253
    if (cpu.flags.zf)
    {
        goto L_0x0049e253;
    }
    // 0049e201  8b15dc935400           -mov edx, dword ptr [0x5493dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
    // 0049e207  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0049e20b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e20d  741f                   -je 0x49e22e
    if (cpu.flags.zf)
    {
        goto L_0x0049e22e;
    }
    // 0049e20f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e214  8a80e1935400           -mov al, byte ptr [eax + 0x5493e1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5542881) /* 0x5493e1 */);
    // 0049e21a  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049e21c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e221  740b                   -je 0x49e22e
    if (cpu.flags.zf)
    {
        goto L_0x0049e22e;
    }
    // 0049e223  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e225  e8a8fbffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e22a  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0049e22e:
    // 0049e22e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049e233  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e237  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049e239  e80cd90000             -call 0x4abb4a
    cpu.esp -= 4;
    sub_4abb4a(app, cpu);
    if (cpu.terminate) return;
    // 0049e23e  83f8ff                 +cmp eax, -1
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
    // 0049e241  7504                   -jne 0x49e247
    if (!cpu.flags.zf)
    {
        goto L_0x0049e247;
    }
    // 0049e243  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e245  eb14                   -jmp 0x49e25b
    goto L_0x0049e25b;
L_0x0049e247:
    // 0049e247  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e24a  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 0049e24e  83c602                 +add esi, 2
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
    // 0049e251  eb87                   -jmp 0x49e1da
    goto L_0x0049e1da;
L_0x0049e253:
    // 0049e253  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 0049e256  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e257  eb81                   -jmp 0x49e1da
    goto L_0x0049e1da;
L_0x0049e259:
    // 0049e259  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0049e25b:
    // 0049e25b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e25e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e25f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049e260  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e261  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e262  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e263  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e264  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e25e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049e25e;
    // 0049e183  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e184  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e185  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e186  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e187  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e188  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e189  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049e18c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e18e  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049e192  7437                   -je 0x49e1cb
    if (cpu.flags.zf)
    {
        goto L_0x0049e1cb;
    }
    // 0049e194  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e197  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0049e19a  740c                   -je 0x49e1a8
    if (cpu.flags.zf)
    {
        goto L_0x0049e1a8;
    }
    // 0049e19c  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e19e  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e1a1  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0049e1a3  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0049e1a6  eb23                   -jmp 0x49e1cb
    goto L_0x0049e1cb;
L_0x0049e1a8:
    // 0049e1a8  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0049e1ab  7410                   -je 0x49e1bd
    if (cpu.flags.zf)
    {
        goto L_0x0049e1bd;
    }
    // 0049e1ad  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e1af  83c604                 +add esi, 4
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
    // 0049e1b2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e1b4  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0049e1b6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e1b8  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0049e1bb  eb0e                   -jmp 0x49e1cb
    goto L_0x0049e1cb;
L_0x0049e1bd:
    // 0049e1bd  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e1bf  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e1c2  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e1c4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0049e1c6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e1c8  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0049e1cb:
    // 0049e1cb  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049e1ce  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e1d0  83ffff                 +cmp edi, -1
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
    // 0049e1d3  7505                   -jne 0x49e1da
    if (!cpu.flags.zf)
    {
        goto L_0x0049e1da;
    }
    // 0049e1d5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x0049e1da:
    // 0049e1da  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e1dc  0f8e77000000           -jle 0x49e259
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e259;
    }
    // 0049e1e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e1e4  e8e9fbffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e1e9  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e1ec  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0049e1ef  0f8564000000           -jne 0x49e259
    if (!cpu.flags.zf)
    {
        goto L_0x0049e259;
    }
    // 0049e1f5  45                     -inc ebp
    (cpu.ebp)++;
    // 0049e1f6  4f                     -dec edi
    (cpu.edi)--;
    // 0049e1f7  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0049e1fa  74de                   -je 0x49e1da
    if (cpu.flags.zf)
    {
        goto L_0x0049e1da;
    }
    // 0049e1fc  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 0049e1ff  7452                   -je 0x49e253
    if (cpu.flags.zf)
    {
        goto L_0x0049e253;
    }
    // 0049e201  8b15dc935400           -mov edx, dword ptr [0x5493dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
    // 0049e207  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0049e20b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e20d  741f                   -je 0x49e22e
    if (cpu.flags.zf)
    {
        goto L_0x0049e22e;
    }
    // 0049e20f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e214  8a80e1935400           -mov al, byte ptr [eax + 0x5493e1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5542881) /* 0x5493e1 */);
    // 0049e21a  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049e21c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e221  740b                   -je 0x49e22e
    if (cpu.flags.zf)
    {
        goto L_0x0049e22e;
    }
    // 0049e223  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e225  e8a8fbffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e22a  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0049e22e:
    // 0049e22e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049e233  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e237  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049e239  e80cd90000             -call 0x4abb4a
    cpu.esp -= 4;
    sub_4abb4a(app, cpu);
    if (cpu.terminate) return;
    // 0049e23e  83f8ff                 +cmp eax, -1
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
    // 0049e241  7504                   -jne 0x49e247
    if (!cpu.flags.zf)
    {
        goto L_0x0049e247;
    }
    // 0049e243  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e245  eb14                   -jmp 0x49e25b
    goto L_0x0049e25b;
L_0x0049e247:
    // 0049e247  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e24a  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 0049e24e  83c602                 +add esi, 2
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
    // 0049e251  eb87                   -jmp 0x49e1da
    goto L_0x0049e1da;
L_0x0049e253:
    // 0049e253  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 0049e256  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e257  eb81                   -jmp 0x49e1da
    goto L_0x0049e1da;
L_0x0049e259:
    // 0049e259  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x0049e25b:
    // 0049e25b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_entry_0x0049e25e:
    // 0049e25e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e25f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049e260  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e261  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e262  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e263  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e264  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e265(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e265  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e266  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e267  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e268  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e269  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e26a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e26b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049e26e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e270  f6401020               +test byte ptr [eax + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 0049e274  7407                   -je 0x49e27d
    if (cpu.flags.zf)
    {
        goto L_0x0049e27d;
    }
    // 0049e276  c644240802             -mov byte ptr [esp + 8], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 2 /*0x2*/;
    // 0049e27b  eb09                   -jmp 0x49e286
    goto L_0x0049e286;
L_0x0049e27d:
    // 0049e27d  f6411010               -test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049e281  c644240801             -mov byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x0049e286:
    // 0049e286  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e289  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0049e28c  7434                   -je 0x49e2c2
    if (cpu.flags.zf)
    {
        goto L_0x0049e2c2;
    }
    // 0049e28e  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0049e291  740c                   -je 0x49e29f
    if (cpu.flags.zf)
    {
        goto L_0x0049e29f;
    }
    // 0049e293  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e295  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e298  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0049e29a  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0049e29d  eb23                   -jmp 0x49e2c2
    goto L_0x0049e2c2;
L_0x0049e29f:
    // 0049e29f  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0049e2a2  7410                   -je 0x49e2b4
    if (cpu.flags.zf)
    {
        goto L_0x0049e2b4;
    }
    // 0049e2a4  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e2a6  83c604                 +add esi, 4
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
    // 0049e2a9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e2ab  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0049e2ad  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e2af  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0049e2b2  eb0e                   -jmp 0x49e2c2
    goto L_0x0049e2c2;
L_0x0049e2b4:
    // 0049e2b4  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e2b6  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e2b9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e2bb  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0049e2bd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e2bf  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x0049e2c2:
    // 0049e2c2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049e2c4:
    // 0049e2c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e2c6  e807fbffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e2cb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e2cd  fec0                   -inc al
    (cpu.al)++;
    // 0049e2cf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e2d4  f680c8ea4c0002         +test byte ptr [eax + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049e2db  7403                   -je 0x49e2e0
    if (cpu.flags.zf)
    {
        goto L_0x0049e2e0;
    }
    // 0049e2dd  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e2de  ebe4                   -jmp 0x49e2c4
    goto L_0x0049e2c4;
L_0x0049e2e0:
    // 0049e2e0  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049e2e4  7407                   -je 0x49e2ed
    if (cpu.flags.zf)
    {
        goto L_0x0049e2ed;
    }
    // 0049e2e6  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049e2e8  e9a4000000             -jmp 0x49e391
    goto L_0x0049e391;
L_0x0049e2ed:
    // 0049e2ed  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049e2f0  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049e2f3  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049e2f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e2f8  0f848a000000           -je 0x49e388
    if (cpu.flags.zf)
    {
        goto L_0x0049e388;
    }
L_0x0049e2fe:
    // 0049e2fe  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e301  47                     -inc edi
    (cpu.edi)++;
    // 0049e302  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0049e304  7460                   -je 0x49e366
    if (cpu.flags.zf)
    {
        goto L_0x0049e366;
    }
    // 0049e306  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e30b  7505                   -jne 0x49e312
    if (!cpu.flags.zf)
    {
        goto L_0x0049e312;
    }
    // 0049e30d  26881e                 -mov byte ptr es:[esi], bl
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.bl;
    // 0049e310  eb4c                   -jmp 0x49e35e
    goto L_0x0049e35e;
L_0x0049e312:
    // 0049e312  8b2ddc935400           -mov ebp, dword ptr [0x5493dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
    // 0049e318  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 0049e31c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e31e  741e                   -je 0x49e33e
    if (cpu.flags.zf)
    {
        goto L_0x0049e33e;
    }
    // 0049e320  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e322  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0049e324  8a80e1935400           -mov al, byte ptr [eax + 0x5493e1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5542881) /* 0x5493e1 */);
    // 0049e32a  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0049e32c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e331  740b                   -je 0x49e33e
    if (cpu.flags.zf)
    {
        goto L_0x0049e33e;
    }
    // 0049e333  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e335  e898faffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e33a  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x0049e33e:
    // 0049e33e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049e343  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049e347  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049e349  e8fcd70000             -call 0x4abb4a
    cpu.esp -= 4;
    sub_4abb4a(app, cpu);
    if (cpu.terminate) return;
    // 0049e34e  83f8ff                 +cmp eax, -1
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
    // 0049e351  7504                   -jne 0x49e357
    if (!cpu.flags.zf)
    {
        goto L_0x0049e357;
    }
    // 0049e353  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e355  eb59                   -jmp 0x49e3b0
    goto L_0x0049e3b0;
L_0x0049e357:
    // 0049e357  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049e35a  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
L_0x0049e35e:
    // 0049e35e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e360  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e364  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e366:
    // 0049e366  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e368  e8e4080000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e36d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e36f  83f8ff                 +cmp eax, -1
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
    // 0049e372  741d                   -je 0x49e391
    if (cpu.flags.zf)
    {
        goto L_0x0049e391;
    }
    // 0049e374  fec0                   -inc al
    (cpu.al)++;
    // 0049e376  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e37b  f680c8ea4c0002         +test byte ptr [eax + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049e382  0f8476ffffff           -je 0x49e2fe
    if (cpu.flags.zf)
    {
        goto L_0x0049e2fe;
    }
L_0x0049e388:
    // 0049e388  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049e38a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e38c  e848faffff             -call 0x49ddd9
    cpu.esp -= 4;
    sub_49ddd9(app, cpu);
    if (cpu.terminate) return;
L_0x0049e391:
    // 0049e391  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049e395  7417                   -je 0x49e3ae
    if (cpu.flags.zf)
    {
        goto L_0x0049e3ae;
    }
    // 0049e397  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e399  7e13                   -jle 0x49e3ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e3ae;
    }
    // 0049e39b  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e3a0  7506                   -jne 0x49e3a8
    if (!cpu.flags.zf)
    {
        goto L_0x0049e3a8;
    }
    // 0049e3a2  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
    // 0049e3a6  eb06                   -jmp 0x49e3ae
    goto L_0x0049e3ae;
L_0x0049e3a8:
    // 0049e3a8  6626c7060000           -mov word ptr es:[esi], 0
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0049e3ae:
    // 0049e3ae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0049e3b0:
    // 0049e3b0  83c40c                 +add esp, 0xc
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
    // 0049e3b3  e9a6feffff             -jmp 0x49e25e
    return sub_49e25e(app, cpu);
}

/* align: skip  */
void Application::sub_49e3b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e3b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e3b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e3ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e3bb  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e3bc  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049e3bf  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0049e3c2  744d                   -je 0x49e411
    if (cpu.flags.zf)
    {
        goto L_0x0049e411;
    }
    // 0049e3c4  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0049e3c7  740c                   -je 0x49e3d5
    if (cpu.flags.zf)
    {
        goto L_0x0049e3d5;
    }
    // 0049e3c9  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e3cb  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e3ce  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 0049e3d0  c457f8                 -les edx, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 0049e3d3  eb25                   -jmp 0x49e3fa
    goto L_0x0049e3fa;
L_0x0049e3d5:
    // 0049e3d5  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0049e3d8  7410                   -je 0x49e3ea
    if (cpu.flags.zf)
    {
        goto L_0x0049e3ea;
    }
    // 0049e3da  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e3dc  83c604                 +add esi, 4
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
    // 0049e3df  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 0049e3e1  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0049e3e3  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 0049e3e5  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 0049e3e8  eb10                   -jmp 0x49e3fa
    goto L_0x0049e3fa;
L_0x0049e3ea:
    // 0049e3ea  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049e3ec  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e3ef  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0049e3f1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049e3f3  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 0049e3f5  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 0049e3f7  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0049e3fa:
    // 0049e3fa  8a6810                 -mov ch, byte ptr [eax + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049e3fd  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0049e400  7409                   -je 0x49e40b
    if (cpu.flags.zf)
    {
        goto L_0x0049e40b;
    }
    // 0049e402  6626891a               -mov word ptr es:[edx], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.bx;
    // 0049e406  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049e407  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e408  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e409  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e40a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e40b:
    // 0049e40b  f6c520                 -test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0049e40e  26891a                 -mov dword ptr es:[edx], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.ebx;
L_0x0049e411:
    // 0049e411  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049e412  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e413  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e414  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e416(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e416  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e417  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e418  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e419  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e41b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049e41d  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0049e422  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e424  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e426  e884aefeff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 0049e42b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e42d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e42f  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e430  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e432  741f                   -je 0x49e453
    if (cpu.flags.zf)
    {
        goto L_0x0049e453;
    }
L_0x0049e434:
    // 0049e434  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e436  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049e439  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0049e43c  8a8018e44c00           -mov al, byte ptr [eax + 0x4ce418]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5039128) /* 0x4ce418 */);
    // 0049e442  080432                 -or byte ptr [edx + esi], al
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) |= x86::reg8(x86::sreg8(cpu.al));
    // 0049e445  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e447  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049e449  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e44b  7406                   -je 0x49e453
    if (cpu.flags.zf)
    {
        goto L_0x0049e453;
    }
    // 0049e44d  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e44e  83f85d                 +cmp eax, 0x5d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e451  75e1                   -jne 0x49e434
    if (!cpu.flags.zf)
    {
        goto L_0x0049e434;
    }
L_0x0049e453:
    // 0049e453  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e455  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e456  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e457  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e458  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e459(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e459  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e45a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e45b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e45c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e45d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e45e  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049e461  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e463  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049e465  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e467  80385e                 +cmp byte ptr [eax], 0x5e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e46a  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0049e46d  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049e473  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049e477  7403                   -je 0x49e47c
    if (cpu.flags.zf)
    {
        goto L_0x0049e47c;
    }
    // 0049e479  40                     -inc eax
    (cpu.eax)++;
    // 0049e47a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0049e47c:
    // 0049e47c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049e47e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e480  e891ffffff             -call 0x49e416
    cpu.esp -= 4;
    sub_49e416(app, cpu);
    if (cpu.terminate) return;
    // 0049e485  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049e487  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e48a  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0049e48d  7434                   -je 0x49e4c3
    if (cpu.flags.zf)
    {
        goto L_0x0049e4c3;
    }
    // 0049e48f  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0049e492  740c                   -je 0x49e4a0
    if (cpu.flags.zf)
    {
        goto L_0x0049e4a0;
    }
    // 0049e494  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0049e496  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e499  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0049e49b  c476f8                 -les esi, ptr [esi - 8]
    NFS2_ASSERT(false);
    // 0049e49e  eb23                   -jmp 0x49e4c3
    goto L_0x0049e4c3;
L_0x0049e4a0:
    // 0049e4a0  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0049e4a3  7410                   -je 0x49e4b5
    if (cpu.flags.zf)
    {
        goto L_0x0049e4b5;
    }
    // 0049e4a5  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049e4a7  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e4aa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e4ac  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0049e4ae  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e4b0  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0049e4b3  eb0e                   -jmp 0x49e4c3
    goto L_0x0049e4c3;
L_0x0049e4b5:
    // 0049e4b5  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049e4b7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e4ba  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e4bc  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0049e4be  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e4c0  8b72fc                 -mov esi, dword ptr [edx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0049e4c3:
    // 0049e4c3  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049e4c6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049e4c8:
    // 0049e4c8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e4ca  766a                   -jbe 0x49e536
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049e536;
    }
    // 0049e4cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e4ce  e8fff8ffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e4d3  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e4d6  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049e4da  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0049e4dd  7557                   -jne 0x49e536
    if (!cpu.flags.zf)
    {
        goto L_0x0049e536;
    }
    // 0049e4df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e4e1  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0049e4e4  8a1c1c                 -mov bl, byte ptr [esp + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.ebx * 1);
    // 0049e4e7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e4ed  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049e4f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e4f3  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049e4f6  8a9b18e44c00           -mov bl, byte ptr [ebx + 0x4ce418]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5039128) /* 0x4ce418 */);
    // 0049e4fc  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049e500  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e506  85eb                   +test ebx, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebp));
    // 0049e508  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 0049e50b  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049e50f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e515  39eb                   +cmp ebx, ebp
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
    // 0049e517  7409                   -je 0x49e522
    if (cpu.flags.zf)
    {
        goto L_0x0049e522;
    }
    // 0049e519  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049e51b  e8b9f8ffff             -call 0x49ddd9
    cpu.esp -= 4;
    sub_49ddd9(app, cpu);
    if (cpu.terminate) return;
    // 0049e520  eb14                   -jmp 0x49e536
    goto L_0x0049e536;
L_0x0049e522:
    // 0049e522  47                     -inc edi
    (cpu.edi)++;
    // 0049e523  8a7910                 -mov bh, byte ptr [ecx + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049e526  4a                     -dec edx
    (cpu.edx)--;
    // 0049e527  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0049e52a  749c                   -je 0x49e4c8
    if (cpu.flags.zf)
    {
        goto L_0x0049e4c8;
    }
    // 0049e52c  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e530  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 0049e533  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e534  eb92                   -jmp 0x49e4c8
    goto L_0x0049e4c8;
L_0x0049e536:
    // 0049e536  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049e53a  7408                   -je 0x49e544
    if (cpu.flags.zf)
    {
        goto L_0x0049e544;
    }
    // 0049e53c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e53e  7e04                   -jle 0x49e544
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e544;
    }
    // 0049e540  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0049e544:
    // 0049e544  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e546  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049e549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e54a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049e54b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e54c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e54d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e54e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49e54f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e54f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e553  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e554  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e555  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049e558  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049e55a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 0049e55e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049e560  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049e562  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
L_0x0049e566:
    // 0049e566  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e568  e865f8ffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e56d  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049e56f  fec2                   -inc dl
    (cpu.dl)++;
    // 0049e571  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 0049e574  8a95c8ea4c00           -mov dl, byte ptr [ebp + 0x4ceac8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5040840) /* 0x4ceac8 */);
    // 0049e57a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e57c  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0049e57f  7406                   -je 0x49e587
    if (cpu.flags.zf)
    {
        goto L_0x0049e587;
    }
    // 0049e581  ff442468               +inc dword ptr [esp + 0x68]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e585  ebdf                   -jmp 0x49e566
    goto L_0x0049e566;
L_0x0049e587:
    // 0049e587  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049e58b  0f85d7010000           -jne 0x49e768
    if (!cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
    // 0049e591  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049e594  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049e597  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0049e59a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e59c  0f84bd010000           -je 0x49e75f
    if (cpu.flags.zf)
    {
        goto L_0x0049e75f;
    }
    // 0049e5a2  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5a5  7405                   -je 0x49e5ac
    if (cpu.flags.zf)
    {
        goto L_0x0049e5ac;
    }
    // 0049e5a7  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5aa  751e                   -jne 0x49e5ca
    if (!cpu.flags.zf)
    {
        goto L_0x0049e5ca;
    }
L_0x0049e5ac:
    // 0049e5ac  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0049e5b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e5b2  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e5b4  e898060000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e5b9  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e5ba  45                     -inc ebp
    (cpu.ebp)++;
    // 0049e5bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e5bd  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 0049e5c1  83f8ff                 +cmp eax, -1
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
    // 0049e5c4  0f849e010000           -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
L_0x0049e5ca:
    // 0049e5ca  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049e5cc  fec0                   -inc al
    (cpu.al)++;
    // 0049e5ce  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e5d3  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e5da  7509                   -jne 0x49e5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0049e5e5;
    }
    // 0049e5dc  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e5df  0f857a010000           -jne 0x49e75f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e75f;
    }
L_0x0049e5e5:
    // 0049e5e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e5e7  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0049e5eb  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049e5ed  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e5ef  fec0                   -inc al
    (cpu.al)++;
    // 0049e5f1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e5f6  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e5fd  7441                   -je 0x49e640
    if (cpu.flags.zf)
    {
        goto L_0x0049e640;
    }
    // 0049e5ff  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0049e604:
    // 0049e604  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e606  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049e609  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e60a  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0049e60c  740f                   -je 0x49e61d
    if (cpu.flags.zf)
    {
        goto L_0x0049e61d;
    }
    // 0049e60e  6b4424660a             -imul eax, dword ptr [esp + 0x66], 0xa
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(102) /* 0x66 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0049e613  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e615  83e930                 -sub ecx, 0x30
    (cpu.ecx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049e618  66894c2466             -mov word ptr [esp + 0x66], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.cx;
L_0x0049e61d:
    // 0049e61d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e61f  47                     -inc edi
    (cpu.edi)++;
    // 0049e620  e82c060000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e625  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e627  83f8ff                 +cmp eax, -1
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
    // 0049e62a  0f8438010000           -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
    // 0049e630  fec0                   -inc al
    (cpu.al)++;
    // 0049e632  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e637  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e63e  75c4                   -jne 0x49e604
    if (!cpu.flags.zf)
    {
        goto L_0x0049e604;
    }
L_0x0049e640:
    // 0049e640  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e643  0f8598000000           -jne 0x49e6e1
    if (!cpu.flags.zf)
    {
        goto L_0x0049e6e1;
    }
    // 0049e649  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e64b  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e64d  e8ff050000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e652  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e653  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e655  83f8ff                 +cmp eax, -1
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
    // 0049e658  0f840a010000           -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
    // 0049e65e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049e660  7514                   -jne 0x49e676
    if (!cpu.flags.zf)
    {
        goto L_0x0049e676;
    }
    // 0049e662  fec0                   -inc al
    (cpu.al)++;
    // 0049e664  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e669  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e670  0f84e9000000           -je 0x49e75f
    if (cpu.flags.zf)
    {
        goto L_0x0049e75f;
    }
L_0x0049e676:
    // 0049e676  47                     -inc edi
    (cpu.edi)++;
L_0x0049e677:
    // 0049e677  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049e679  fec0                   -inc al
    (cpu.al)++;
    // 0049e67b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e680  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e687  7412                   -je 0x49e69b
    if (cpu.flags.zf)
    {
        goto L_0x0049e69b;
    }
    // 0049e689  47                     -inc edi
    (cpu.edi)++;
    // 0049e68a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e68c  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e68e  e8be050000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e693  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e694  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e696  83f8ff                 +cmp eax, -1
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
    // 0049e699  75dc                   -jne 0x49e677
    if (!cpu.flags.zf)
    {
        goto L_0x0049e677;
    }
L_0x0049e69b:
    // 0049e69b  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049e69f  7437                   -je 0x49e6d8
    if (cpu.flags.zf)
    {
        goto L_0x0049e6d8;
    }
    // 0049e6a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e6a3  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049e6a5  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x0049e6a9:
    // 0049e6a9  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049e6aa  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049e6ad  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e6af  741e                   -je 0x49e6cf
    if (cpu.flags.zf)
    {
        goto L_0x0049e6cf;
    }
    // 0049e6b1  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0049e6b3  c744245c0a000000       -mov dword ptr [esp + 0x5c], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 10 /*0xa*/;
    // 0049e6bb  88442462               -mov byte ptr [esp + 0x62], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.al;
    // 0049e6bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e6c1  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049e6c5  f774245c               +div dword ptr [esp + 0x5c]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049e6c9  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0049e6cd  ebda                   -jmp 0x49e6a9
    goto L_0x0049e6a9;
L_0x0049e6cf:
    // 0049e6cf  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049e6d3  6689442464             -mov word ptr [esp + 0x64], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ax;
L_0x0049e6d8:
    // 0049e6d8  83f9ff                 +cmp ecx, -1
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
    // 0049e6db  0f8487000000           -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
L_0x0049e6e1:
    // 0049e6e1  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049e6e5  0f8574000000           -jne 0x49e75f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e75f;
    }
    // 0049e6eb  83f965                 +cmp ecx, 0x65
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e6ee  7409                   -je 0x49e6f9
    if (cpu.flags.zf)
    {
        goto L_0x0049e6f9;
    }
    // 0049e6f0  83f945                 +cmp ecx, 0x45
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e6f3  0f8566000000           -jne 0x49e75f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e75f;
    }
L_0x0049e6f9:
    // 0049e6f9  47                     -inc edi
    (cpu.edi)++;
    // 0049e6fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e6fc  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e6fe  e84e050000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e703  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e704  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e706  83f8ff                 +cmp eax, -1
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
    // 0049e709  745d                   -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
    // 0049e70b  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e70e  7405                   -je 0x49e715
    if (cpu.flags.zf)
    {
        goto L_0x0049e715;
    }
    // 0049e710  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e713  7512                   -jne 0x49e727
    if (!cpu.flags.zf)
    {
        goto L_0x0049e727;
    }
L_0x0049e715:
    // 0049e715  47                     -inc edi
    (cpu.edi)++;
    // 0049e716  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e718  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e71a  e832050000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e71f  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e720  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e722  83f8ff                 +cmp eax, -1
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
    // 0049e725  7441                   -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
L_0x0049e727:
    // 0049e727  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049e729  fec0                   -inc al
    (cpu.al)++;
    // 0049e72b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e730  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e737  7504                   -jne 0x49e73d
    if (!cpu.flags.zf)
    {
        goto L_0x0049e73d;
    }
    // 0049e739  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049e73b  eb22                   -jmp 0x49e75f
    goto L_0x0049e75f;
L_0x0049e73d:
    // 0049e73d  47                     -inc edi
    (cpu.edi)++;
    // 0049e73e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e740  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049e742  e80a050000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e747  43                     -inc ebx
    (cpu.ebx)++;
    // 0049e748  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e74a  83f8ff                 +cmp eax, -1
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
    // 0049e74d  7419                   -je 0x49e768
    if (cpu.flags.zf)
    {
        goto L_0x0049e768;
    }
    // 0049e74f  fec0                   -inc al
    (cpu.al)++;
    // 0049e751  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e756  f680c8ea4c0020         +test byte ptr [eax + 0x4ceac8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 32 /*0x20*/));
    // 0049e75d  75de                   -jne 0x49e73d
    if (!cpu.flags.zf)
    {
        goto L_0x0049e73d;
    }
L_0x0049e75f:
    // 0049e75f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049e761  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e763  e871f6ffff             -call 0x49ddd9
    cpu.esp -= 4;
    sub_49ddd9(app, cpu);
    if (cpu.terminate) return;
L_0x0049e768:
    // 0049e768  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049e76a  0f8eab000000           -jle 0x49e81b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e81b;
    }
    // 0049e770  037c2468               -add edi, dword ptr [esp + 0x68]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 0049e774  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049e778  0f849d000000           -je 0x49e81b
    if (cpu.flags.zf)
    {
        goto L_0x0049e81b;
    }
    // 0049e77e  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 0049e781  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049e785  740c                   -je 0x49e793
    if (cpu.flags.zf)
    {
        goto L_0x0049e793;
    }
    // 0049e787  803c242d               +cmp byte ptr [esp], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049e78b  7512                   -jne 0x49e79f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e79f;
    }
    // 0049e78d  f75c2464               +neg dword ptr [esp + 0x64]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0049e791  eb0c                   -jmp 0x49e79f
    goto L_0x0049e79f;
L_0x0049e793:
    // 0049e793  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049e797  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049e799  ff1568f84c00           -call dword ptr [0x4cf868]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5044328) /* 0x4cf868 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049e79f:
    // 0049e79f  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049e7a2  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0049e7a5  7410                   -je 0x49e7b7
    if (cpu.flags.zf)
    {
        goto L_0x0049e7b7;
    }
    // 0049e7a7  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049e7ab  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e7ad  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e7b0  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049e7b2  c459f8                 -les ebx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 0049e7b5  eb2b                   -jmp 0x49e7e2
    goto L_0x0049e7e2;
L_0x0049e7b7:
    // 0049e7b7  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 0049e7ba  7414                   -je 0x49e7d0
    if (cpu.flags.zf)
    {
        goto L_0x0049e7d0;
    }
    // 0049e7bc  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049e7c0  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e7c2  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049e7c5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0049e7c7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e7c9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e7cb  8b5bfc                 -mov ebx, dword ptr [ebx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0049e7ce  eb12                   -jmp 0x49e7e2
    goto L_0x0049e7e2;
L_0x0049e7d0:
    // 0049e7d0  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049e7d4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e7d6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e7d9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049e7db  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049e7dd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049e7df  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0049e7e2:
    // 0049e7e2  8a7610                 -mov dh, byte ptr [esi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049e7e5  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0049e7e8  7406                   -je 0x49e7f0
    if (cpu.flags.zf)
    {
        goto L_0x0049e7f0;
    }
    // 0049e7ea  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049e7ee  eb28                   -jmp 0x49e818
    goto L_0x0049e818;
L_0x0049e7f0:
    // 0049e7f0  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0049e7f3  7505                   -jne 0x49e7fa
    if (!cpu.flags.zf)
    {
        goto L_0x0049e7fa;
    }
    // 0049e7f5  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 0049e7f8  7411                   -je 0x49e80b
    if (cpu.flags.zf)
    {
        goto L_0x0049e80b;
    }
L_0x0049e7fa:
    // 0049e7fa  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049e7fe  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
    // 0049e801  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049e805  26894304               -mov dword ptr es:[ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049e809  eb10                   -jmp 0x49e81b
    goto L_0x0049e81b;
L_0x0049e80b:
    // 0049e80b  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049e80f  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049e813  e8d8d30000             -call 0x4abbf0
    cpu.esp -= 4;
    sub_4abbf0(app, cpu);
    if (cpu.terminate) return;
L_0x0049e818:
    // 0049e818  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
L_0x0049e81b:
    // 0049e81b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e81d  83c46c                 +add esp, 0x6c
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
    // 0049e820  e939faffff             -jmp 0x49e25e
    return sub_49e25e(app, cpu);
}

/* align: skip  */
void Application::sub_49e825(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e825  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e826  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e827  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049e828  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e829  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049e82c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049e82e  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049e832  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0049e836  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e838  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e83a  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049e83e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049e842  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049e846  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0049e84a:
    // 0049e84a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e84c  e881f5ffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049e851  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e855  8a5c242c               -mov bl, byte ptr [esp + 0x2c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049e859  fec3                   -inc bl
    (cpu.bl)++;
    // 0049e85b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049e861  f683c8ea4c0002         +test byte ptr [ebx + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 0049e868  7406                   -je 0x49e870
    if (cpu.flags.zf)
    {
        goto L_0x0049e870;
    }
    // 0049e86a  ff442420               +inc dword ptr [esp + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e86e  ebda                   -jmp 0x49e84a
    goto L_0x0049e84a;
L_0x0049e870:
    // 0049e870  f6471002               +test byte ptr [edi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049e874  0f8590020000           -jne 0x49eb0a
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049e87a  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049e87d  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0049e880  89770c                 -mov dword ptr [edi + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049e883  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e885  0f8474020000           -je 0x49eaff
    if (cpu.flags.zf)
    {
        goto L_0x0049eaff;
    }
    // 0049e88b  bb2b000000             -mov ebx, 0x2b
    cpu.ebx = 43 /*0x2b*/;
    // 0049e890  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049e894  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049e896  742e                   -je 0x49e8c6
    if (cpu.flags.zf)
    {
        goto L_0x0049e8c6;
    }
    // 0049e898  39d8                   +cmp eax, ebx
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
    // 0049e89a  7405                   -je 0x49e8a1
    if (cpu.flags.zf)
    {
        goto L_0x0049e8a1;
    }
    // 0049e89c  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e89f  7525                   -jne 0x49e8c6
    if (!cpu.flags.zf)
    {
        goto L_0x0049e8c6;
    }
L_0x0049e8a1:
    // 0049e8a1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049e8a5  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049e8a9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049e8ad  41                     -inc ecx
    (cpu.ecx)++;
    // 0049e8ae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e8b0  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049e8b4  e898030000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e8b9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e8bd  83f8ff                 +cmp eax, -1
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
    // 0049e8c0  0f8444020000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
L_0x0049e8c6:
    // 0049e8c6  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e8ca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e8cc  0f8569000000           -jne 0x49e93b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e93b;
    }
    // 0049e8d2  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e8d7  7558                   -jne 0x49e931
    if (!cpu.flags.zf)
    {
        goto L_0x0049e931;
    }
    // 0049e8d9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e8db  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049e8e0  e86c030000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e8e5  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e8e9  83f8ff                 +cmp eax, -1
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
    // 0049e8ec  0f8418020000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049e8f2  83f878                 +cmp eax, 0x78
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
    // 0049e8f5  7405                   -je 0x49e8fc
    if (cpu.flags.zf)
    {
        goto L_0x0049e8fc;
    }
    // 0049e8f7  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e8fa  752b                   -jne 0x49e927
    if (!cpu.flags.zf)
    {
        goto L_0x0049e927;
    }
L_0x0049e8fc:
    // 0049e8fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e8fe  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049e902  e84a030000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e907  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e909  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e90c  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e910  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049e914  83f8ff                 +cmp eax, -1
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
    // 0049e917  0f84ed010000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049e91d  c744242810000000       -mov dword ptr [esp + 0x28], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 16 /*0x10*/;
    // 0049e925  eb64                   -jmp 0x49e98b
    goto L_0x0049e98b;
L_0x0049e927:
    // 0049e927  c744242808000000       -mov dword ptr [esp + 0x28], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 0049e92f  eb5a                   -jmp 0x49e98b
    goto L_0x0049e98b;
L_0x0049e931:
    // 0049e931  c74424280a000000       -mov dword ptr [esp + 0x28], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 10 /*0xa*/;
    // 0049e939  eb50                   -jmp 0x49e98b
    goto L_0x0049e98b;
L_0x0049e93b:
    // 0049e93b  83fe10                 +cmp esi, 0x10
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
    // 0049e93e  754b                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
    // 0049e940  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e945  7544                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
    // 0049e947  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e949  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049e94e  e8fe020000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e953  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e957  83f8ff                 +cmp eax, -1
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
    // 0049e95a  0f84aa010000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049e960  83f878                 +cmp eax, 0x78
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
    // 0049e963  7405                   -je 0x49e96a
    if (cpu.flags.zf)
    {
        goto L_0x0049e96a;
    }
    // 0049e965  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e968  7521                   -jne 0x49e98b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e98b;
    }
L_0x0049e96a:
    // 0049e96a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e96c  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049e970  e8dc020000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049e975  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049e977  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e97a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049e97e  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049e982  83f8ff                 +cmp eax, -1
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
    // 0049e985  0f847f010000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
L_0x0049e98b:
    // 0049e98b  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0049e98f  0f84ff000000           -je 0x49ea94
    if (cpu.flags.zf)
    {
        goto L_0x0049ea94;
    }
    // 0049e995  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e999  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e99b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049e99f  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x0049e9a3:
    // 0049e9a3  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049e9a7  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049e9ab  e87a020000             -call 0x49ec2a
    cpu.esp -= 4;
    sub_49ec2a(app, cpu);
    if (cpu.terminate) return;
    // 0049e9b0  39d0                   +cmp eax, edx
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
    // 0049e9b2  7d5d                   -jge 0x49ea11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ea11;
    }
    // 0049e9b4  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e9b8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049e9bb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e9bd  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e9c1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049e9c5  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049e9c9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e9cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e9ce  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e9d1  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e9d3  e864d20000             -call 0x4abc3c
    cpu.esp -= 4;
    sub_4abc3c(app, cpu);
    if (cpu.terminate) return;
    // 0049e9d8  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049e9db  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049e9dd  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e9e1  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049e9e3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049e9e7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049e9ea  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049e9ec  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049e9ef  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049e9f1  01d8                   +add eax, ebx
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
    // 0049e9f3  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049e9f5  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049e9f8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049e9fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049e9fc  45                     -inc ebp
    (cpu.ebp)++;
    // 0049e9fd  e84f020000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049ea02  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049ea06  83f8ff                 +cmp eax, -1
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
    // 0049ea09  0f84fb000000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049ea0f  eb92                   -jmp 0x49e9a3
    goto L_0x0049e9a3;
L_0x0049ea11:
    // 0049ea11  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ea16  0f85e3000000           -jne 0x49eaff
    if (!cpu.flags.zf)
    {
        goto L_0x0049eaff;
    }
    // 0049ea1c  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0049ea20  0f84d9000000           -je 0x49eaff
    if (cpu.flags.zf)
    {
        goto L_0x0049eaff;
    }
L_0x0049ea26:
    // 0049ea26  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ea28  45                     -inc ebp
    (cpu.ebp)++;
    // 0049ea29  e823020000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049ea2e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049ea32  83f8ff                 +cmp eax, -1
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
    // 0049ea35  0f84cf000000           -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049ea3b  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049ea3f  e8e6010000             -call 0x49ec2a
    cpu.esp -= 4;
    sub_49ec2a(app, cpu);
    if (cpu.terminate) return;
    // 0049ea44  39f0                   +cmp eax, esi
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
    // 0049ea46  0f8db3000000           -jge 0x49eaff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049eaff;
    }
    // 0049ea4c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ea50  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049ea53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ea55  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049ea59  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049ea5d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ea61  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ea64  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ea66  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049ea69  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049ea6b  e8ccd10000             -call 0x4abc3c
    cpu.esp -= 4;
    sub_4abc3c(app, cpu);
    if (cpu.terminate) return;
    // 0049ea70  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049ea73  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049ea75  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ea79  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049ea7b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049ea7f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ea82  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ea84  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049ea87  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049ea89  01d8                   +add eax, ebx
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
    // 0049ea8b  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ea8d  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049ea90  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049ea92  eb92                   -jmp 0x49ea26
    goto L_0x0049ea26;
L_0x0049ea94:
    // 0049ea94  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0049ea98:
    // 0049ea98  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049ea9c  e889010000             -call 0x49ec2a
    cpu.esp -= 4;
    sub_49ec2a(app, cpu);
    if (cpu.terminate) return;
    // 0049eaa1  39f0                   +cmp eax, esi
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
    // 0049eaa3  7d20                   -jge 0x49eac5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049eac5;
    }
    // 0049eaa5  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049eaa9  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049eaac  45                     -inc ebp
    (cpu.ebp)++;
    // 0049eaad  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049eaaf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049eab1  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049eab5  e897010000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049eaba  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049eabe  83f8ff                 +cmp eax, -1
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
    // 0049eac1  7447                   -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049eac3  ebd3                   -jmp 0x49ea98
    goto L_0x0049ea98;
L_0x0049eac5:
    // 0049eac5  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eaca  7533                   -jne 0x49eaff
    if (!cpu.flags.zf)
    {
        goto L_0x0049eaff;
    }
    // 0049eacc  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0049ead0  742d                   -je 0x49eaff
    if (cpu.flags.zf)
    {
        goto L_0x0049eaff;
    }
    // 0049ead2  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0049ead6:
    // 0049ead6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049ead8  45                     -inc ebp
    (cpu.ebp)++;
    // 0049ead9  e873010000             -call 0x49ec51
    cpu.esp -= 4;
    sub_49ec51(app, cpu);
    if (cpu.terminate) return;
    // 0049eade  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049eae2  83f8ff                 +cmp eax, -1
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
    // 0049eae5  7423                   -je 0x49eb0a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb0a;
    }
    // 0049eae7  e83e010000             -call 0x49ec2a
    cpu.esp -= 4;
    sub_49ec2a(app, cpu);
    if (cpu.terminate) return;
    // 0049eaec  39c8                   +cmp eax, ecx
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
    // 0049eaee  7d0f                   -jge 0x49eaff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049eaff;
    }
    // 0049eaf0  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049eaf4  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049eaf7  01c3                   +add ebx, eax
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
    // 0049eaf9  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049eafd  ebd7                   -jmp 0x49ead6
    goto L_0x0049ead6;
L_0x0049eaff:
    // 0049eaff  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049eb03  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049eb05  e8cff2ffff             -call 0x49ddd9
    cpu.esp -= 4;
    sub_49ddd9(app, cpu);
    if (cpu.terminate) return;
L_0x0049eb0a:
    // 0049eb0a  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0049eb0e  0f8492000000           -je 0x49eba6
    if (cpu.flags.zf)
    {
        goto L_0x0049eba6;
    }
    // 0049eb14  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb19  7524                   -jne 0x49eb3f
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb3f;
    }
    // 0049eb1b  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049eb1f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049eb23  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0049eb25  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0049eb27  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049eb2b  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049eb2e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049eb32  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049eb36  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049eb38  7501                   -jne 0x49eb3b
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb3b;
    }
    // 0049eb3a  40                     -inc eax
    (cpu.eax)++;
L_0x0049eb3b:
    // 0049eb3b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049eb3f:
    // 0049eb3f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049eb41  0f8ed9000000           -jle 0x49ec20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ec20;
    }
    // 0049eb47  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049eb4b  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049eb4e  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049eb50  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0049eb53  0f84c7000000           -je 0x49ec20
    if (cpu.flags.zf)
    {
        goto L_0x0049ec20;
    }
    // 0049eb59  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0049eb5c  7414                   -je 0x49eb72
    if (cpu.flags.zf)
    {
        goto L_0x0049eb72;
    }
    // 0049eb5e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049eb62  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049eb64  83c208                 +add edx, 8
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
    // 0049eb67  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049eb69  668b42fc               -mov ax, word ptr [edx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0049eb6d  8b7af8                 -mov edi, dword ptr [edx - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0049eb70  eb27                   -jmp 0x49eb99
    goto L_0x0049eb99;
L_0x0049eb72:
    // 0049eb72  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 0049eb75  7412                   -je 0x49eb89
    if (cpu.flags.zf)
    {
        goto L_0x0049eb89;
    }
    // 0049eb77  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049eb7b  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049eb7d  83c704                 +add edi, 4
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
    // 0049eb80  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0049eb82  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049eb84  8b7ffc                 -mov edi, dword ptr [edi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0049eb87  eb10                   -jmp 0x49eb99
    goto L_0x0049eb99;
L_0x0049eb89:
    // 0049eb89  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049eb8d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049eb8f  83c604                 +add esi, 4
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
    // 0049eb92  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0049eb94  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049eb96  8b7efc                 -mov edi, dword ptr [esi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0049eb99:
    // 0049eb99  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049eb9d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049eb9f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049eba0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049eba1  e97a000000             -jmp 0x49ec20
    goto L_0x0049ec20;
L_0x0049eba6:
    // 0049eba6  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ebab  7504                   -jne 0x49ebb1
    if (!cpu.flags.zf)
    {
        goto L_0x0049ebb1;
    }
    // 0049ebad  f75c2424               -neg dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = ~app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) + 1;
L_0x0049ebb1:
    // 0049ebb1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049ebb3  0f8e67000000           -jle 0x49ec20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ec20;
    }
    // 0049ebb9  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049ebbd  8a4710                 -mov al, byte ptr [edi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049ebc0  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ebc2  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0049ebc4  745a                   -je 0x49ec20
    if (cpu.flags.zf)
    {
        goto L_0x0049ec20;
    }
    // 0049ebc6  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0049ebc8  7410                   -je 0x49ebda
    if (cpu.flags.zf)
    {
        goto L_0x0049ebda;
    }
    // 0049ebca  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ebce  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ebd0  83c308                 +add ebx, 8
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
    // 0049ebd3  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0049ebd5  c443f8                 -les eax, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 0049ebd8  eb2a                   -jmp 0x49ec04
    goto L_0x0049ec04;
L_0x0049ebda:
    // 0049ebda  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0049ebdc  7414                   -je 0x49ebf2
    if (cpu.flags.zf)
    {
        goto L_0x0049ebf2;
    }
    // 0049ebde  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ebe2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ebe4  83c204                 +add edx, 4
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
    // 0049ebe7  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0049ebe9  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049ebeb  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0049ebed  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0049ebf0  eb12                   -jmp 0x49ec04
    goto L_0x0049ec04;
L_0x0049ebf2:
    // 0049ebf2  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049ebf6  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049ebf8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ebfb  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0049ebfd  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0049ebff  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0049ec01  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0049ec04:
    // 0049ec04  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049ec07  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0049ec0a  740a                   -je 0x49ec16
    if (cpu.flags.zf)
    {
        goto L_0x0049ec16;
    }
    // 0049ec0c  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ec10  66268918               -mov word ptr es:[eax], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.eax) = cpu.bx;
    // 0049ec14  eb0a                   -jmp 0x49ec20
    goto L_0x0049ec20;
L_0x0049ec16:
    // 0049ec16  f6c620                 -test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0049ec19  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049ec1d  268918                 -mov dword ptr es:[eax], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.eax) = cpu.ebx;
L_0x0049ec20:
    // 0049ec20  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ec22  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049ec25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec26  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ec27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ec2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ec2a  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec2d  7c09                   -jl 0x49ec38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ec38;
    }
    // 0049ec2f  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec32  7f04                   -jg 0x49ec38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049ec38;
    }
    // 0049ec34  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049ec37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ec38:
    // 0049ec38  e84ee7ffff             -call 0x49d38b
    cpu.esp -= 4;
    sub_49d38b(app, cpu);
    if (cpu.terminate) return;
    // 0049ec3d  83f861                 +cmp eax, 0x61
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
    // 0049ec40  7c09                   -jl 0x49ec4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ec4b;
    }
    // 0049ec42  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec45  7f04                   -jg 0x49ec4b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049ec4b;
    }
    // 0049ec47  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0049ec4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ec4b:
    // 0049ec4b  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0049ec50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ec51(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ec51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ec52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ec53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ec55  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049ec58  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049ec5b  895a0c                 -mov dword ptr [edx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049ec5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ec60  740d                   -je 0x49ec6f
    if (cpu.flags.zf)
    {
        goto L_0x0049ec6f;
    }
    // 0049ec62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ec64  e869f1ffff             -call 0x49ddd2
    cpu.esp -= 4;
    sub_49ddd2(app, cpu);
    if (cpu.terminate) return;
    // 0049ec69  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049ec6d  7405                   -je 0x49ec74
    if (cpu.flags.zf)
    {
        goto L_0x0049ec74;
    }
L_0x0049ec6f:
    // 0049ec6f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0049ec74:
    // 0049ec74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ec77(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ec77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ec78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ec79  2eff15c4744b00         -call dword ptr cs:[0x4b74c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945092) /* 0x4b74c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ec80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ec83(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ec83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ec84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ec85  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ec86  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ec87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ec88  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 0049ec8e  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ec94  bd6d144c00             -mov ebp, 0x4c146d
    cpu.ebp = 4985965 /*0x4c146d*/;
    // 0049ec99  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049ec9c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049ec9e:
    // 0049ec9e  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049eca5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049eca7  e8eb27feff             -call 0x481497
    cpu.esp -= 4;
    sub_481497(app, cpu);
    if (cpu.terminate) return;
    // 0049ecac  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049ecb1  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049ecb8  41                     -inc ecx
    (cpu.ecx)++;
    // 0049ecb9  e89acf0000             -call 0x4abc58
    cpu.esp -= 4;
    sub_4abc58(app, cpu);
    if (cpu.terminate) return;
    // 0049ecbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ecc0  74dc                   -je 0x49ec9e
    if (cpu.flags.zf)
    {
        goto L_0x0049ec9e;
    }
    // 0049ecc2  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049ecc9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049eccb  e84e25feff             -call 0x48121e
    cpu.esp -= 4;
    sub_48121e(app, cpu);
    if (cpu.terminate) return;
    // 0049ecd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ecd2  751b                   -jne 0x49ecef
    if (!cpu.flags.zf)
    {
        goto L_0x0049ecef;
    }
    // 0049ecd4  e8b3cf0000             -call 0x4abc8c
    cpu.esp -= 4;
    sub_4abc8c(app, cpu);
    if (cpu.terminate) return;
    // 0049ecd9  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ecdc  740a                   -je 0x49ece8
    if (cpu.flags.zf)
    {
        goto L_0x0049ece8;
    }
    // 0049ecde  e8a9cf0000             -call 0x4abc8c
    cpu.esp -= 4;
    sub_4abc8c(app, cpu);
    if (cpu.terminate) return;
    // 0049ece3  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ece6  75b6                   -jne 0x49ec9e
    if (!cpu.flags.zf)
    {
        goto L_0x0049ec9e;
    }
L_0x0049ece8:
    // 0049ece8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ecea  e97d000000             -jmp 0x49ed6c
    goto L_0x0049ed6c;
L_0x0049ecef:
    // 0049ecef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ecf1  e84127feff             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 0049ecf6  8a1d7ce34c00           -mov bl, byte ptr [0x4ce37c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5038972) /* 0x4ce37c */);
L_0x0049ecfc:
    // 0049ecfc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049ecfe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ed00  e89227feff             -call 0x481497
    cpu.esp -= 4;
    sub_481497(app, cpu);
    if (cpu.terminate) return;
    // 0049ed05  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049ed07  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049ed0e  e88dcf0000             -call 0x4abca0
    cpu.esp -= 4;
    sub_4abca0(app, cpu);
    if (cpu.terminate) return;
    // 0049ed13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ed15  7539                   -jne 0x49ed50
    if (!cpu.flags.zf)
    {
        goto L_0x0049ed50;
    }
    // 0049ed17  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049ed19  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049ed1b  e8fe24feff             -call 0x48121e
    cpu.esp -= 4;
    sub_48121e(app, cpu);
    if (cpu.terminate) return;
    // 0049ed20  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ed22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ed24  7420                   -je 0x49ed46
    if (cpu.flags.zf)
    {
        goto L_0x0049ed46;
    }
    // 0049ed26  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0049ed29  80cc08                 +or ah, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0049ed2c  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 0049ed2f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049ed32  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 0049ed35  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ed37  881d7ce34c00           -mov byte ptr [0x4ce37c], bl
    app->getMemory<x86::reg8>(x86::reg32(5038972) /* 0x4ce37c */) = cpu.bl;
    // 0049ed3d  e8beb3ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049ed42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ed44  eb26                   -jmp 0x49ed6c
    goto L_0x0049ed6c;
L_0x0049ed46:
    // 0049ed46  e841cf0000             -call 0x4abc8c
    cpu.esp -= 4;
    sub_4abc8c(app, cpu);
    if (cpu.terminate) return;
    // 0049ed4b  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ed4e  7498                   -je 0x49ece8
    if (cpu.flags.zf)
    {
        goto L_0x0049ece8;
    }
L_0x0049ed50:
    // 0049ed50  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0049ed55  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0049ed5c  43                     -inc ebx
    (cpu.ebx)++;
    // 0049ed5d  e8f6ce0000             -call 0x4abc58
    cpu.esp -= 4;
    sub_4abc58(app, cpu);
    if (cpu.terminate) return;
    // 0049ed62  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ed64  0f8534ffffff           -jne 0x49ec9e
    if (!cpu.flags.zf)
    {
        goto L_0x0049ec9e;
    }
    // 0049ed6a  eb90                   -jmp 0x49ecfc
    goto L_0x0049ecfc;
L_0x0049ed6c:
    // 0049ed6c  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 0049ed72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ed78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ed78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ed79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ed7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ed7b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ed7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ed7d  803d34e44c0000         +cmp byte ptr [0x4ce434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5039156) /* 0x4ce434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ed84  0f85ab000000           -jne 0x49ee35
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee35;
    }
    // 0049ed8a  bb20e44c00             -mov ebx, 0x4ce420
    cpu.ebx = 5039136 /*0x4ce420*/;
    // 0049ed8f  eb39                   -jmp 0x49edca
    goto L_0x0049edca;
L_0x0049ed91:
    // 0049ed91  e823cf0000             -call 0x4abcb9
    cpu.esp -= 4;
    sub_4abcb9(app, cpu);
    if (cpu.terminate) return;
    // 0049ed96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ed98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ed9a  742b                   -je 0x49edc7
    if (cpu.flags.zf)
    {
        goto L_0x0049edc7;
    }
    // 0049ed9c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049ed9e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ed9f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049eda1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049eda3  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049eda5  49                     -dec ecx
    (cpu.ecx)--;
    // 0049eda6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049eda8  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049edaa  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049edac  49                     -dec ecx
    (cpu.ecx)--;
    // 0049edad  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049edae  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049edb4  7711                   -ja 0x49edc7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049edc7;
    }
    // 0049edb6  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 0049edbb  b834e44c00             -mov eax, 0x4ce434
    cpu.eax = 5039156 /*0x4ce434*/;
    // 0049edc0  e84ecf0000             -call 0x4abd13
    cpu.esp -= 4;
    sub_4abd13(app, cpu);
    if (cpu.terminate) return;
    // 0049edc5  eb0a                   -jmp 0x49edd1
    goto L_0x0049edd1;
L_0x0049edc7:
    // 0049edc7  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049edca:
    // 0049edca  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049edcc  803800                 +cmp byte ptr [eax], 0
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
    // 0049edcf  75c0                   -jne 0x49ed91
    if (!cpu.flags.zf)
    {
        goto L_0x0049ed91;
    }
L_0x0049edd1:
    // 0049edd1  803d34e44c0000         +cmp byte ptr [0x4ce434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5039156) /* 0x4ce434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049edd8  752a                   -jne 0x49ee04
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee04;
    }
    // 0049edda  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049eddc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049edde  bf34e44c00             -mov edi, 0x4ce434
    cpu.edi = 5039156 /*0x4ce434*/;
    // 0049ede3  e83dd7fdff             -call 0x47c525
    cpu.esp -= 4;
    sub_47c525(app, cpu);
    if (cpu.terminate) return;
    // 0049ede8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049edea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049edeb:
    // 0049edeb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049eded  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049edef  3c00                   +cmp al, 0
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
    // 0049edf1  7410                   -je 0x49ee03
    if (cpu.flags.zf)
    {
        goto L_0x0049ee03;
    }
    // 0049edf3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049edf6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049edf9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049edfc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049edff  3c00                   +cmp al, 0
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
    // 0049ee01  75e8                   -jne 0x49edeb
    if (!cpu.flags.zf)
    {
        goto L_0x0049edeb;
    }
L_0x0049ee03:
    // 0049ee03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049ee04:
    // 0049ee04  bf34e44c00             -mov edi, 0x4ce434
    cpu.edi = 5039156 /*0x4ce434*/;
    // 0049ee09  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049ee0a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049ee0c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049ee0e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ee10  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ee11  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ee13  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049ee15  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049ee17  49                     -dec ecx
    (cpu.ecx)--;
    // 0049ee18  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049ee19  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0049ee1c  0534e44c00             -add eax, 0x4ce434
    (cpu.eax) += x86::reg32(x86::sreg32(5039156 /*0x4ce434*/));
    // 0049ee21  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049ee23  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ee26  740d                   -je 0x49ee35
    if (cpu.flags.zf)
    {
        goto L_0x0049ee35;
    }
    // 0049ee28  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ee2b  7408                   -je 0x49ee35
    if (cpu.flags.zf)
    {
        goto L_0x0049ee35;
    }
    // 0049ee2d  40                     -inc eax
    (cpu.eax)++;
    // 0049ee2e  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 0049ee31  40                     -inc eax
    (cpu.eax)++;
    // 0049ee32  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0049ee35:
    // 0049ee35  b834e44c00             -mov eax, 0x4ce434
    cpu.eax = 5039156 /*0x4ce434*/;
    // 0049ee3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ee40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ee40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ee41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ee42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ee43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ee44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ee45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ee46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ee48  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049ee4b  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ee51  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0049ee54  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ee56  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0049ee59  0f8478000000           -je 0x49eed7
    if (cpu.flags.zf)
    {
        goto L_0x0049eed7;
    }
    // 0049ee5f  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 0049ee61  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049ee64  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049ee67  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0049ee6a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0049ee6c  0f84a0000000           -je 0x49ef12
    if (cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049ee72  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049ee75  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049ee78  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049ee7a  0f8492000000           -je 0x49ef12
    if (cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049ee80  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049ee82  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x0049ee85:
    // 0049ee85  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ee87  0f8485000000           -je 0x49ef12
    if (cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049ee8d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049ee8f  0f857d000000           -jne 0x49ef12
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049ee95  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049ee97  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049ee99  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ee9c  e861420000             -call 0x4a3102
    cpu.esp -= 4;
    sub_4a3102(app, cpu);
    if (cpu.terminate) return;
    // 0049eea1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049eea3  83f8ff                 +cmp eax, -1
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
    // 0049eea6  750d                   -jne 0x49eeb5
    if (!cpu.flags.zf)
    {
        goto L_0x0049eeb5;
    }
    // 0049eea8  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049eeab  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049eeae  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049eeb0  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0049eeb3  eb1c                   -jmp 0x49eed1
    goto L_0x0049eed1;
L_0x0049eeb5:
    // 0049eeb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049eeb7  7518                   -jne 0x49eed1
    if (!cpu.flags.zf)
    {
        goto L_0x0049eed1;
    }
    // 0049eeb9  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0049eebe  e83db2ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049eec3  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049eec6  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049eec9  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0049eece  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x0049eed1:
    // 0049eed1  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049eed3  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049eed5  ebae                   -jmp 0x49ee85
    goto L_0x0049ee85;
L_0x0049eed7:
    // 0049eed7  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049eeda  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eede  7432                   -je 0x49ef12
    if (cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049eee0  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0049eee4  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 0049eee8  7528                   -jne 0x49ef12
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049eeea  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049eeed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049eeef  7411                   -je 0x49ef02
    if (cpu.flags.zf)
    {
        goto L_0x0049ef02;
    }
    // 0049eef1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049eef3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049eef8  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0049eefa  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049eefd  e8a6000000             -call 0x49efa8
    cpu.esp -= 4;
    sub_49efa8(app, cpu);
    if (cpu.terminate) return;
L_0x0049ef02:
    // 0049ef02  83f8ff                 +cmp eax, -1
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
    // 0049ef05  750b                   -jne 0x49ef12
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef12;
    }
    // 0049ef07  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049ef0a  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0049ef0d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049ef0f  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x0049ef12:
    // 0049ef12  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049ef15  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049ef18  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049ef1f  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049ef21  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049ef23  7518                   -jne 0x49ef3d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef3d;
    }
    // 0049ef25  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049ef28  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049ef2c  740f                   -je 0x49ef3d
    if (cpu.flags.zf)
    {
        goto L_0x0049ef3d;
    }
    // 0049ef2e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ef31  e86ece0000             -call 0x4abda4
    cpu.esp -= 4;
    sub_4abda4(app, cpu);
    if (cpu.terminate) return;
    // 0049ef36  83f8ff                 +cmp eax, -1
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
    // 0049ef39  7502                   -jne 0x49ef3d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef3d;
    }
    // 0049ef3b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x0049ef3d:
    // 0049ef3d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049ef40  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ef46  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049ef48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ef4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ef4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ef50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ef51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ef52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ef53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ef55  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 0049ef59  740d                   -je 0x49ef68
    if (cpu.flags.zf)
    {
        goto L_0x0049ef68;
    }
    // 0049ef5b  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0049ef5f  7407                   -je 0x49ef68
    if (cpu.flags.zf)
    {
        goto L_0x0049ef68;
    }
    // 0049ef61  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ef63  e8103b0000             -call 0x4a2a78
    cpu.esp -= 4;
    sub_4a2a78(app, cpu);
    if (cpu.terminate) return;
L_0x0049ef68:
    // 0049ef68  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ef6b  e854c00000             -call 0x4aafc4
    cpu.esp -= 4;
    sub_4aafc4(app, cpu);
    if (cpu.terminate) return;
    // 0049ef70  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ef72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ef74  83f8ff                 +cmp eax, -1
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
    // 0049ef77  742a                   -je 0x49efa3
    if (cpu.flags.zf)
    {
        goto L_0x0049efa3;
    }
    // 0049ef79  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ef7c  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ef82  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049ef85  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049ef87  740f                   -je 0x49ef98
    if (cpu.flags.zf)
    {
        goto L_0x0049ef98;
    }
    // 0049ef89  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 0049ef8d  7405                   -je 0x49ef94
    if (cpu.flags.zf)
    {
        goto L_0x0049ef94;
    }
    // 0049ef8f  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 0049ef92  eb04                   -jmp 0x49ef98
    goto L_0x0049ef98;
L_0x0049ef94:
    // 0049ef94  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049ef96  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049ef98:
    // 0049ef98  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ef9b  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049efa1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049efa3:
    // 0049efa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49efa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049efa8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049efa9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049efaa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049efac  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049efae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049efb0  7c08                   -jl 0x49efba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049efba;
    }
    // 0049efb2  3b05e4f74c00           +cmp eax, dword ptr [0x4cf7e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049efb8  7612                   -jbe 0x49efcc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049efcc;
    }
L_0x0049efba:
    // 0049efba  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049efbf  e83cb1ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049efc4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049efc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efcb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049efcc:
    // 0049efcc  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049efd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049efd4  e81fbf0000             -call 0x4aaef8
    cpu.esp -= 4;
    sub_4aaef8(app, cpu);
    if (cpu.terminate) return;
    // 0049efd9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049efdb  7e10                   -jle 0x49efed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049efed;
    }
    // 0049efdd  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0049efdf  750c                   -jne 0x49efed
    if (!cpu.flags.zf)
    {
        goto L_0x0049efed;
    }
    // 0049efe1  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0049efe4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049efe6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049efe8  e860bf0000             -call 0x4aaf4d
    cpu.esp -= 4;
    sub_4aaf4d(app, cpu);
    if (cpu.terminate) return;
L_0x0049efed:
    // 0049efed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049efee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049eff0  a1d4f74c00             -mov eax, dword ptr [0x4cf7d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 0049eff5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049eff7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eff8  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0049effb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049effc  2eff158c754b00         -call dword ptr cs:[0x4b758c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945292) /* 0x4b758c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f003  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f005  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f007  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f00d  83f9ff                 +cmp ecx, -1
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
    // 0049f010  7505                   -jne 0x49f017
    if (!cpu.flags.zf)
    {
        goto L_0x0049f017;
    }
    // 0049f012  e8ebafffff             -call 0x49a002
    cpu.esp -= 4;
    sub_49a002(app, cpu);
    if (cpu.terminate) return;
L_0x0049f017:
    // 0049f017  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f019  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f01a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f01b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f01c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f01c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f01d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f01e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f01f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f020  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f021  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f022  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049f024  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f026  7c08                   -jl 0x49f030
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f030;
    }
    // 0049f028  3b05e4f74c00           +cmp eax, dword ptr [0x4cf7e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5044196) /* 0x4cf7e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f02e  7611                   -jbe 0x49f041
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049f041;
    }
L_0x0049f030:
    // 0049f030  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049f035  e8c6b0ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049f03a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049f03f  eb61                   -jmp 0x49f0a2
    goto L_0x0049f0a2;
L_0x0049f041:
    // 0049f041  8b15d4f74c00           -mov edx, dword ptr [0x4cf7d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5044180) /* 0x4cf7d4 */);
    // 0049f047  8b2de0e34c00           -mov ebp, dword ptr [0x4ce3e0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5039072) /* 0x4ce3e0 */);
    // 0049f04d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f04f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f051  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 0049f054  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049f056  741e                   -je 0x49f076
    if (cpu.flags.zf)
    {
        goto L_0x0049f076;
    }
    // 0049f058  ff15d4e34c00           -call dword ptr [0x4ce3d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039060) /* 0x4ce3d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f05e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049f060  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f062  7412                   -je 0x49f076
    if (cpu.flags.zf)
    {
        goto L_0x0049f076;
    }
    // 0049f064  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f066  ff15d8e34c00           -call dword ptr [0x4ce3d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039064) /* 0x4ce3d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f06c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f06e  ff15e0e34c00           -call dword ptr [0x4ce3e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039072) /* 0x4ce3e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f074  eb21                   -jmp 0x49f097
    goto L_0x0049f097;
L_0x0049f076:
    // 0049f076  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049f078  751d                   -jne 0x49f097
    if (!cpu.flags.zf)
    {
        goto L_0x0049f097;
    }
    // 0049f07a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f07b  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f082  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f084  7511                   -jne 0x49f097
    if (!cpu.flags.zf)
    {
        goto L_0x0049f097;
    }
    // 0049f086  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0049f08b  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0049f090  e86bb0ffff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 0049f095  eb09                   -jmp 0x49f0a0
    goto L_0x0049f0a0;
L_0x0049f097:
    // 0049f097  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f099  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f09b  e8adbe0000             -call 0x4aaf4d
    cpu.esp -= 4;
    sub_4aaf4d(app, cpu);
    if (cpu.terminate) return;
L_0x0049f0a0:
    // 0049f0a0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0049f0a2:
    // 0049f0a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f0a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f0a9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f0a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f0aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f0ab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f0ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f0ad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f0af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f0b1  0f84f1000000           -je 0x49f1a8
    if (cpu.flags.zf)
    {
        goto L_0x0049f1a8;
    }
    // 0049f0b7  ff15a4e34c00           -call dword ptr [0x4ce3a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039012) /* 0x4ce3a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f0bd  8b0dd44f5400           -mov ecx, dword ptr [0x544fd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5525460) /* 0x544fd4 */);
    // 0049f0c3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f0c5  7440                   -je 0x49f107
    if (cpu.flags.zf)
    {
        goto L_0x0049f107;
    }
    // 0049f0c7  39f1                   +cmp ecx, esi
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
    // 0049f0c9  770c                   -ja 0x49f0d7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f0d7;
    }
    // 0049f0cb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f0cd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f0cf  39f0                   +cmp eax, esi
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
    // 0049f0d1  0f878b000000           -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f0d7:
    // 0049f0d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f0d9  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049f0dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f0de  7410                   -je 0x49f0f0
    if (cpu.flags.zf)
    {
        goto L_0x0049f0f0;
    }
    // 0049f0e0  39f1                   +cmp ecx, esi
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
    // 0049f0e2  770c                   -ja 0x49f0f0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f0f0;
    }
    // 0049f0e4  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f0e6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f0e8  39f2                   +cmp edx, esi
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
    // 0049f0ea  0f8772000000           -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f0f0:
    // 0049f0f0  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f0f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f0f5  7410                   -je 0x49f107
    if (cpu.flags.zf)
    {
        goto L_0x0049f107;
    }
    // 0049f0f7  39f1                   +cmp ecx, esi
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
    // 0049f0f9  770c                   -ja 0x49f107
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f107;
    }
    // 0049f0fb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f0fd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f0ff  39f0                   +cmp eax, esi
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
    // 0049f101  0f875b000000           -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f107:
    // 0049f107  8b0d78ce4c00           -mov ecx, dword ptr [0x4cce78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5033592) /* 0x4cce78 */);
    // 0049f10d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f10f  7434                   -je 0x49f145
    if (cpu.flags.zf)
    {
        goto L_0x0049f145;
    }
    // 0049f111  39f1                   +cmp ecx, esi
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
    // 0049f113  7708                   -ja 0x49f11d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f11d;
    }
    // 0049f115  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f117  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f119  39f0                   +cmp eax, esi
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
    // 0049f11b  7745                   -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f11d:
    // 0049f11d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f11f  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049f122  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f124  740c                   -je 0x49f132
    if (cpu.flags.zf)
    {
        goto L_0x0049f132;
    }
    // 0049f126  39f1                   +cmp ecx, esi
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
    // 0049f128  7708                   -ja 0x49f132
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f132;
    }
    // 0049f12a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f12c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f12e  39f2                   +cmp edx, esi
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
    // 0049f130  7730                   -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f132:
    // 0049f132  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f135  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f137  740c                   -je 0x49f145
    if (cpu.flags.zf)
    {
        goto L_0x0049f145;
    }
    // 0049f139  39f1                   +cmp ecx, esi
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
    // 0049f13b  7708                   -ja 0x49f145
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f145;
    }
    // 0049f13d  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f13f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f141  39f0                   +cmp eax, esi
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
    // 0049f143  771d                   -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f145:
    // 0049f145  8b0d74ce4c00           -mov ecx, dword ptr [0x4cce74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5033588) /* 0x4cce74 */);
    // 0049f14b  eb0f                   -jmp 0x49f15c
    goto L_0x0049f15c;
L_0x0049f14d:
    // 0049f14d  39f1                   +cmp ecx, esi
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
    // 0049f14f  7708                   -ja 0x49f159
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f159;
    }
    // 0049f151  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f153  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f155  39f0                   +cmp eax, esi
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
    // 0049f157  7709                   -ja 0x49f162
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049f162;
    }
L_0x0049f159:
    // 0049f159  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x0049f15c:
    // 0049f15c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f15e  75ed                   -jne 0x49f14d
    if (!cpu.flags.zf)
    {
        goto L_0x0049f14d;
    }
    // 0049f160  eb40                   -jmp 0x49f1a2
    goto L_0x0049f1a2;
L_0x0049f162:
    // 0049f162  b874ce4c00             -mov eax, 0x4cce74
    cpu.eax = 5033588 /*0x4cce74*/;
    // 0049f167  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0049f169  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049f16f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049f171  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f173  e8d87e0000             -call 0x4a7050
    cpu.esp -= 4;
    sub_4a7050(app, cpu);
    if (cpu.terminate) return;
    // 0049f178  8b1578ce4c00           -mov edx, dword ptr [0x4cce78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033592) /* 0x4cce78 */);
    // 0049f17e  890dd44f5400           -mov dword ptr [0x544fd4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525460) /* 0x544fd4 */) = cpu.ecx;
    // 0049f184  39d1                   +cmp ecx, edx
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
    // 0049f186  7312                   -jae 0x49f19a
    if (!cpu.flags.cf)
    {
        goto L_0x0049f19a;
    }
    // 0049f188  8b1d7cce4c00           -mov ebx, dword ptr [0x4cce7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5033596) /* 0x4cce7c */);
    // 0049f18e  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0049f191  39d8                   +cmp eax, ebx
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
    // 0049f193  7605                   -jbe 0x49f19a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049f19a;
    }
    // 0049f195  a37cce4c00             -mov dword ptr [0x4cce7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5033596) /* 0x4cce7c */) = cpu.eax;
L_0x0049f19a:
    // 0049f19a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049f19c  882560845400           -mov byte ptr [0x548460], ah
    app->getMemory<x86::reg8>(x86::reg32(5538912) /* 0x548460 */) = cpu.ah;
L_0x0049f1a2:
    // 0049f1a2  ff15ace34c00           -call dword ptr [0x4ce3ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039020) /* 0x4ce3ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049f1a8:
    // 0049f1a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f1ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f1ad  e91ce1fdff             -jmp 0x47d2ce
    return sub_47d2ce(app, cpu);
}

/* align: skip  */
void Application::sub_49f1b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f1b2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f1b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f1b4  ba01be4a00             -mov edx, 0x4abe01
    cpu.edx = 4898305 /*0x4abe01*/;
    // 0049f1b9  bb15bf4a00             -mov ebx, 0x4abf15
    cpu.ebx = 4898581 /*0x4abf15*/;
    // 0049f1be  891564f84c00           -mov dword ptr [0x4cf864], edx
    app->getMemory<x86::reg32>(x86::reg32(5044324) /* 0x4cf864 */) = cpu.edx;
    // 0049f1c4  891d68f84c00           -mov dword ptr [0x4cf868], ebx
    app->getMemory<x86::reg32>(x86::reg32(5044328) /* 0x4cf868 */) = cpu.ebx;
    // 0049f1ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49f1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f1d0  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049f1d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f1d2  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049f1d7  757f                   -jne 0x49f258
    if (!cpu.flags.zf)
    {
        goto L_0x0049f258;
    }
L_0x0049f1d9:
    // 0049f1d9  83eb20                 +sub ebx, 0x20
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
    // 0049f1dc  7825                   -js 0x49f203
    if (cpu.flags.sf)
    {
        goto L_0x0049f203;
    }
L_0x0049f1de:
    // 0049f1de  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049f1e0  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0049f1e3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049f1e5  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1e7  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1ea  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 0049f1ed  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 0049f1f0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049f1f2  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1f5  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1f8  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049f1fb  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049f1fe  83eb20                 +sub ebx, 0x20
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
    // 0049f201  79db                   -jns 0x49f1de
    if (!cpu.flags.sf)
    {
        goto L_0x0049f1de;
    }
L_0x0049f203:
    // 0049f203  83c318                 +add ebx, 0x18
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
    // 0049f206  780f                   -js 0x49f217
    if (cpu.flags.sf)
    {
        goto L_0x0049f217;
    }
L_0x0049f208:
    // 0049f208  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049f20a  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f20c  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049f20f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f212  83eb08                 +sub ebx, 8
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
    // 0049f215  79f1                   -jns 0x49f208
    if (!cpu.flags.sf)
    {
        goto L_0x0049f208;
    }
L_0x0049f217:
    // 0049f217  83c308                 +add ebx, 8
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
    // 0049f21a  7502                   -jne 0x49f21e
    if (!cpu.flags.zf)
    {
        goto L_0x0049f21e;
    }
    // 0049f21c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f21d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f21e:
    // 0049f21e  83fb04                 +cmp ebx, 4
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
    // 0049f221  720d                   -jb 0x49f230
    if (cpu.flags.cf)
    {
        goto L_0x0049f230;
    }
    // 0049f223  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f225  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f228  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f22a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f22d  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049f230:
    // 0049f230  83fb02                 +cmp ebx, 2
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
    // 0049f233  720f                   -jb 0x49f244
    if (cpu.flags.cf)
    {
        goto L_0x0049f244;
    }
    // 0049f235  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f238  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f23b  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f23e  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f241  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f244:
    // 0049f244  83fb01                 +cmp ebx, 1
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
    // 0049f247  720d                   -jb 0x49f256
    if (cpu.flags.cf)
    {
        goto L_0x0049f256;
    }
    // 0049f249  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f24b  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f24e  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f250  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f253  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f256:
    // 0049f256  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f257  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f258:
    // 0049f258  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049f25d  7412                   -je 0x49f271
    if (cpu.flags.zf)
    {
        goto L_0x0049f271;
    }
    // 0049f25f  83fb01                 +cmp ebx, 1
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
    // 0049f262  7c0d                   -jl 0x49f271
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f271;
    }
    // 0049f264  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f266  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f269  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f26b  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f26e  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f271:
    // 0049f271  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049f276  7414                   -je 0x49f28c
    if (cpu.flags.zf)
    {
        goto L_0x0049f28c;
    }
    // 0049f278  83fb02                 +cmp ebx, 2
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
    // 0049f27b  7c0f                   -jl 0x49f28c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f28c;
    }
    // 0049f27d  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f280  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f283  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f286  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f289  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f28c:
    // 0049f28c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049f291  7412                   -je 0x49f2a5
    if (cpu.flags.zf)
    {
        goto L_0x0049f2a5;
    }
    // 0049f293  83fb04                 +cmp ebx, 4
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
    // 0049f296  7c0d                   -jl 0x49f2a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f2a5;
    }
    // 0049f298  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f29a  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f29d  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f29f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f2a2  83eb04                 +sub ebx, 4
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
L_0x0049f2a5:
    // 0049f2a5  e92fffffff             -jmp 0x49f1d9
    goto L_0x0049f1d9;
}

/* align: skip  */
void Application::sub_49f1d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049f1d1;
    // 0049f1d0  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x0049f1d1:
    // 0049f1d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f1d2  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049f1d7  757f                   -jne 0x49f258
    if (!cpu.flags.zf)
    {
        goto L_0x0049f258;
    }
L_0x0049f1d9:
    // 0049f1d9  83eb20                 +sub ebx, 0x20
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
    // 0049f1dc  7825                   -js 0x49f203
    if (cpu.flags.sf)
    {
        goto L_0x0049f203;
    }
L_0x0049f1de:
    // 0049f1de  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049f1e0  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0049f1e3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049f1e5  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1e7  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1ea  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 0049f1ed  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 0049f1f0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049f1f2  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1f5  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f1f8  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049f1fb  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049f1fe  83eb20                 +sub ebx, 0x20
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
    // 0049f201  79db                   -jns 0x49f1de
    if (!cpu.flags.sf)
    {
        goto L_0x0049f1de;
    }
L_0x0049f203:
    // 0049f203  83c318                 +add ebx, 0x18
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
    // 0049f206  780f                   -js 0x49f217
    if (cpu.flags.sf)
    {
        goto L_0x0049f217;
    }
L_0x0049f208:
    // 0049f208  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 0049f20a  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049f20c  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049f20f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f212  83eb08                 +sub ebx, 8
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
    // 0049f215  79f1                   -jns 0x49f208
    if (!cpu.flags.sf)
    {
        goto L_0x0049f208;
    }
L_0x0049f217:
    // 0049f217  83c308                 +add ebx, 8
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
    // 0049f21a  7502                   -jne 0x49f21e
    if (!cpu.flags.zf)
    {
        goto L_0x0049f21e;
    }
    // 0049f21c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f21d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f21e:
    // 0049f21e  83fb04                 +cmp ebx, 4
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
    // 0049f221  720d                   -jb 0x49f230
    if (cpu.flags.cf)
    {
        goto L_0x0049f230;
    }
    // 0049f223  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f225  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f228  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f22a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f22d  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049f230:
    // 0049f230  83fb02                 +cmp ebx, 2
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
    // 0049f233  720f                   -jb 0x49f244
    if (cpu.flags.cf)
    {
        goto L_0x0049f244;
    }
    // 0049f235  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f238  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f23b  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f23e  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f241  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f244:
    // 0049f244  83fb01                 +cmp ebx, 1
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
    // 0049f247  720d                   -jb 0x49f256
    if (cpu.flags.cf)
    {
        goto L_0x0049f256;
    }
    // 0049f249  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f24b  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f24e  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f250  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f253  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f256:
    // 0049f256  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f257  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f258:
    // 0049f258  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049f25d  7412                   -je 0x49f271
    if (cpu.flags.zf)
    {
        goto L_0x0049f271;
    }
    // 0049f25f  83fb01                 +cmp ebx, 1
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
    // 0049f262  7c0d                   -jl 0x49f271
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f271;
    }
    // 0049f264  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f266  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f269  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f26b  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f26e  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f271:
    // 0049f271  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049f276  7414                   -je 0x49f28c
    if (cpu.flags.zf)
    {
        goto L_0x0049f28c;
    }
    // 0049f278  83fb02                 +cmp ebx, 2
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
    // 0049f27b  7c0f                   -jl 0x49f28c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f28c;
    }
    // 0049f27d  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f280  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f283  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f286  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f289  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f28c:
    // 0049f28c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049f291  7412                   -je 0x49f2a5
    if (cpu.flags.zf)
    {
        goto L_0x0049f2a5;
    }
    // 0049f293  83fb04                 +cmp ebx, 4
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
    // 0049f296  7c0d                   -jl 0x49f2a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f2a5;
    }
    // 0049f298  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f29a  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f29d  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f29f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f2a2  83eb04                 +sub ebx, 4
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
L_0x0049f2a5:
    // 0049f2a5  e92fffffff             -jmp 0x49f1d9
    goto L_0x0049f1d9;
}

/* align: skip 0x00 0x00 */
void Application::sub_49f2ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f2ac  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049f2ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f2ae  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049f2b3  0f8585000000           -jne 0x49f33e
    if (!cpu.flags.zf)
    {
        goto L_0x0049f33e;
    }
L_0x0049f2b9:
    // 0049f2b9  83eb20                 +sub ebx, 0x20
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
    // 0049f2bc  7829                   -js 0x49f2e7
    if (cpu.flags.sf)
    {
        goto L_0x0049f2e7;
    }
L_0x0049f2be:
    // 0049f2be  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049f2c1  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049f2c5  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049f2c9  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049f2cd  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049f2d0  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0049f2d4  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 0049f2d8  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 0049f2dc  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049f2df  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049f2e2  83eb20                 +sub ebx, 0x20
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
    // 0049f2e5  79d7                   -jns 0x49f2be
    if (!cpu.flags.sf)
    {
        goto L_0x0049f2be;
    }
L_0x0049f2e7:
    // 0049f2e7  83c318                 +add ebx, 0x18
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
    // 0049f2ea  7811                   -js 0x49f2fd
    if (cpu.flags.sf)
    {
        goto L_0x0049f2fd;
    }
L_0x0049f2ec:
    // 0049f2ec  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049f2ef  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049f2f2  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049f2f5  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f2f8  83eb08                 +sub ebx, 8
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
    // 0049f2fb  79ef                   -jns 0x49f2ec
    if (!cpu.flags.sf)
    {
        goto L_0x0049f2ec;
    }
L_0x0049f2fd:
    // 0049f2fd  83c308                 +add ebx, 8
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
    // 0049f300  7502                   -jne 0x49f304
    if (!cpu.flags.zf)
    {
        goto L_0x0049f304;
    }
    // 0049f302  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f304:
    // 0049f304  83fb04                 +cmp ebx, 4
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
    // 0049f307  720d                   -jb 0x49f316
    if (cpu.flags.cf)
    {
        goto L_0x0049f316;
    }
    // 0049f309  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f30b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f30e  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f310  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f313  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049f316:
    // 0049f316  83fb02                 +cmp ebx, 2
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
    // 0049f319  720f                   -jb 0x49f32a
    if (cpu.flags.cf)
    {
        goto L_0x0049f32a;
    }
    // 0049f31b  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f31e  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f321  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f324  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f327  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f32a:
    // 0049f32a  83fb01                 +cmp ebx, 1
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
    // 0049f32d  720d                   -jb 0x49f33c
    if (cpu.flags.cf)
    {
        goto L_0x0049f33c;
    }
    // 0049f32f  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f331  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f334  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f336  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f339  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f33c:
    // 0049f33c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f33d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f33e:
    // 0049f33e  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049f343  7412                   -je 0x49f357
    if (cpu.flags.zf)
    {
        goto L_0x0049f357;
    }
    // 0049f345  83fb01                 +cmp ebx, 1
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
    // 0049f348  7c0d                   -jl 0x49f357
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f357;
    }
    // 0049f34a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f34c  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f34f  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f351  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f354  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f357:
    // 0049f357  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049f35c  7414                   -je 0x49f372
    if (cpu.flags.zf)
    {
        goto L_0x0049f372;
    }
    // 0049f35e  83fb02                 +cmp ebx, 2
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
    // 0049f361  7c0f                   -jl 0x49f372
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f372;
    }
    // 0049f363  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f366  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f369  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f36c  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f36f  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f372:
    // 0049f372  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049f377  7412                   -je 0x49f38b
    if (cpu.flags.zf)
    {
        goto L_0x0049f38b;
    }
    // 0049f379  83fb04                 +cmp ebx, 4
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
    // 0049f37c  7c0d                   -jl 0x49f38b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f38b;
    }
    // 0049f37e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f380  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f383  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f385  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f388  83eb04                 +sub ebx, 4
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
L_0x0049f38b:
    // 0049f38b  e929ffffff             -jmp 0x49f2b9
    goto L_0x0049f2b9;
}

/* align: skip  */
void Application::sub_49f2ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049f2ad;
    // 0049f2ac  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x0049f2ad:
    // 0049f2ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f2ae  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0049f2b3  0f8585000000           -jne 0x49f33e
    if (!cpu.flags.zf)
    {
        goto L_0x0049f33e;
    }
L_0x0049f2b9:
    // 0049f2b9  83eb20                 +sub ebx, 0x20
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
    // 0049f2bc  7829                   -js 0x49f2e7
    if (cpu.flags.sf)
    {
        goto L_0x0049f2e7;
    }
L_0x0049f2be:
    // 0049f2be  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049f2c1  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 0049f2c5  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 0049f2c9  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 0049f2cd  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049f2d0  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0049f2d4  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 0049f2d8  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 0049f2dc  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049f2df  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049f2e2  83eb20                 +sub ebx, 0x20
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
    // 0049f2e5  79d7                   -jns 0x49f2be
    if (!cpu.flags.sf)
    {
        goto L_0x0049f2be;
    }
L_0x0049f2e7:
    // 0049f2e7  83c318                 +add ebx, 0x18
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
    // 0049f2ea  7811                   -js 0x49f2fd
    if (cpu.flags.sf)
    {
        goto L_0x0049f2fd;
    }
L_0x0049f2ec:
    // 0049f2ec  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 0049f2ef  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 0049f2f2  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049f2f5  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f2f8  83eb08                 +sub ebx, 8
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
    // 0049f2fb  79ef                   -jns 0x49f2ec
    if (!cpu.flags.sf)
    {
        goto L_0x0049f2ec;
    }
L_0x0049f2fd:
    // 0049f2fd  83c308                 +add ebx, 8
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
    // 0049f300  7502                   -jne 0x49f304
    if (!cpu.flags.zf)
    {
        goto L_0x0049f304;
    }
    // 0049f302  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f303  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f304:
    // 0049f304  83fb04                 +cmp ebx, 4
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
    // 0049f307  720d                   -jb 0x49f316
    if (cpu.flags.cf)
    {
        goto L_0x0049f316;
    }
    // 0049f309  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f30b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f30e  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f310  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f313  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049f316:
    // 0049f316  83fb02                 +cmp ebx, 2
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
    // 0049f319  720f                   -jb 0x49f32a
    if (cpu.flags.cf)
    {
        goto L_0x0049f32a;
    }
    // 0049f31b  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f31e  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f321  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f324  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f327  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f32a:
    // 0049f32a  83fb01                 +cmp ebx, 1
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
    // 0049f32d  720d                   -jb 0x49f33c
    if (cpu.flags.cf)
    {
        goto L_0x0049f33c;
    }
    // 0049f32f  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f331  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f334  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f336  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f339  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f33c:
    // 0049f33c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f33d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f33e:
    // 0049f33e  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0049f343  7412                   -je 0x49f357
    if (cpu.flags.zf)
    {
        goto L_0x0049f357;
    }
    // 0049f345  83fb01                 +cmp ebx, 1
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
    // 0049f348  7c0d                   -jl 0x49f357
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f357;
    }
    // 0049f34a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0049f34c  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049f34f  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0049f351  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049f354  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0049f357:
    // 0049f357  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0049f35c  7414                   -je 0x49f372
    if (cpu.flags.zf)
    {
        goto L_0x0049f372;
    }
    // 0049f35e  83fb02                 +cmp ebx, 2
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
    // 0049f361  7c0f                   -jl 0x49f372
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f372;
    }
    // 0049f363  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 0049f366  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049f369  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 0049f36c  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049f36f  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0049f372:
    // 0049f372  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0049f377  7412                   -je 0x49f38b
    if (cpu.flags.zf)
    {
        goto L_0x0049f38b;
    }
    // 0049f379  83fb04                 +cmp ebx, 4
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
    // 0049f37c  7c0d                   -jl 0x49f38b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f38b;
    }
    // 0049f37e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049f380  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049f383  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f385  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f388  83eb04                 +sub ebx, 4
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
L_0x0049f38b:
    // 0049f38b  e929ffffff             -jmp 0x49f2b9
    goto L_0x0049f2b9;
}

/* align: skip  */
void Application::sub_49f390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f394  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f395  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f396  ba74144c00             -mov edx, 0x4c1474
    cpu.edx = 4985972 /*0x4c1474*/;
    // 0049f39b  e87e1efeff             -call 0x48121e
    cpu.esp -= 4;
    sub_48121e(app, cpu);
    if (cpu.terminate) return;
    // 0049f3a0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f3a2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f3a4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f3a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3a8  7509                   -jne 0x49f3b3
    if (!cpu.flags.zf)
    {
        goto L_0x0049f3b3;
    }
L_0x0049f3aa:
    // 0049f3aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f3ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f3b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f3b3:
    // 0049f3b3  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049f3b8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f3ba  e895e3ffff             -call 0x49d754
    cpu.esp -= 4;
    sub_49d754(app, cpu);
    if (cpu.terminate) return;
    // 0049f3bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3c1  75e7                   -jne 0x49f3aa
    if (!cpu.flags.zf)
    {
        goto L_0x0049f3aa;
    }
    // 0049f3c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f3c5  e885fbffff             -call 0x49ef4f
    cpu.esp -= 4;
    sub_49ef4f(app, cpu);
    if (cpu.terminate) return;
    // 0049f3ca  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049f3cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3ce  7eda                   -jle 0x49f3aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f3aa;
    }
    // 0049f3d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f3d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f3d4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f3d6  e879e3ffff             -call 0x49d754
    cpu.esp -= 4;
    sub_49d754(app, cpu);
    if (cpu.terminate) return;
    // 0049f3db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3dd  75cb                   -jne 0x49f3aa
    if (!cpu.flags.zf)
    {
        goto L_0x0049f3aa;
    }
    // 0049f3df  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 0049f3e4  e8d7f8feff             -call 0x48ecc0
    cpu.esp -= 4;
    sub_48ecc0(app, cpu);
    if (cpu.terminate) return;
    // 0049f3e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f3eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3ed  74bb                   -je 0x49f3aa
    if (cpu.flags.zf)
    {
        goto L_0x0049f3aa;
    }
    // 0049f3ef  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049f3f1  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049f3f4  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049f3f7  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0049f3fa  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 0049f400  89b818100000           -mov dword ptr [eax + 0x1018], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = cpu.edi;
    // 0049f406  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049f409  898810100000           -mov dword ptr [eax + 0x1010], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ecx;
    // 0049f40f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f411  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f412  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f413  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f414  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f415  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f416  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f417  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
