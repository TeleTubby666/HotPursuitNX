#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488048(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488048);
    // 00488048  e823ffffff             -call 0x487f70
    cpu.esp -= 4;
    sub_487f70(app, cpu);
    if (cpu.terminate) return;
    // 0048804d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048804f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488051  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488053  7402                   -je 0x488057
    if (cpu.flags.zf)
    {
        goto L_0x00488057;
    }
    // 00488055  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x00488057:
    // 00488057  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488058(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488058);
    // 00488058  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488059  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048805b  e8e8ffffff             -call 0x488048
    cpu.esp -= 4;
    sub_488048(app, cpu);
    if (cpu.terminate) return;
    // 00488060  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488061  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488064);
    // 00488064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488065  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048806a  e8d9ffffff             -call 0x488048
    cpu.esp -= 4;
    sub_488048(app, cpu);
    if (cpu.terminate) return;
    // 0048806f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488070  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_488074(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488074);
    // 00488074  a140b64d00             -mov eax, dword ptr [0x4db640]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092928) /* 0x4db640 */);
    // 00488079  03053cb64d00           +add eax, dword ptr [0x4db63c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092924) /* 0x4db63c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048807f  a33cb64d00             -mov dword ptr [0x4db63c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092924) /* 0x4db63c */) = cpu.eax;
    // 00488084  130538b64d00           +adc eax, dword ptr [0x4db638]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092920) /* 0x4db638 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048808a  a338b64d00             -mov dword ptr [0x4db638], eax
    app->getMemory<x86::reg32>(x86::reg32(5092920) /* 0x4db638 */) = cpu.eax;
    // 0048808f  130534b64d00           +adc eax, dword ptr [0x4db634]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092916) /* 0x4db634 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00488095  a334b64d00             -mov dword ptr [0x4db634], eax
    app->getMemory<x86::reg32>(x86::reg32(5092916) /* 0x4db634 */) = cpu.eax;
    // 0048809a  130530b64d00           +adc eax, dword ptr [0x4db630]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092912) /* 0x4db630 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004880a0  a330b64d00             -mov dword ptr [0x4db630], eax
    app->getMemory<x86::reg32>(x86::reg32(5092912) /* 0x4db630 */) = cpu.eax;
    // 004880a5  13052cb64d00           +adc eax, dword ptr [0x4db62c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092908) /* 0x4db62c */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004880ab  ff0540b64d00           +inc dword ptr [0x4db640]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5092928) /* 0x4db640 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004880b1  7521                   -jne 0x4880d4
    if (!cpu.flags.zf)
    {
        goto L_0x004880d4;
    }
    // 004880b3  ff053cb64d00           +inc dword ptr [0x4db63c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5092924) /* 0x4db63c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004880b9  7519                   -jne 0x4880d4
    if (!cpu.flags.zf)
    {
        goto L_0x004880d4;
    }
    // 004880bb  ff0538b64d00           +inc dword ptr [0x4db638]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5092920) /* 0x4db638 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004880c1  7511                   -jne 0x4880d4
    if (!cpu.flags.zf)
    {
        goto L_0x004880d4;
    }
    // 004880c3  ff0534b64d00           +inc dword ptr [0x4db634]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5092916) /* 0x4db634 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004880c9  7509                   -jne 0x4880d4
    if (!cpu.flags.zf)
    {
        goto L_0x004880d4;
    }
    // 004880cb  ff0530b64d00           +inc dword ptr [0x4db630]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5092912) /* 0x4db630 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004880d1  7501                   -jne 0x4880d4
    if (!cpu.flags.zf)
    {
        goto L_0x004880d4;
    }
    // 004880d3  40                     -inc eax
    (cpu.eax)++;
L_0x004880d4:
    // 004880d4  a32cb64d00             -mov dword ptr [0x4db62c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092908) /* 0x4db62c */) = cpu.eax;
    // 004880d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4880da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004880da);
    // 004880da  05560e2df2             -add eax, 0xf22d0e56
    (cpu.eax) += x86::reg32(x86::sreg32(4063039062 /*0xf22d0e56*/));
    // 004880df  a32cb64d00             -mov dword ptr [0x4db62c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092908) /* 0x4db62c */) = cpu.eax;
    // 004880e4  0593180496             -add eax, 0x96041893
    (cpu.eax) += x86::reg32(x86::sreg32(2516850835 /*0x96041893*/));
    // 004880e9  a330b64d00             -mov dword ptr [0x4db630], eax
    app->getMemory<x86::reg32>(x86::reg32(5092912) /* 0x4db630 */) = cpu.eax;
    // 004880ee  0546b6f33d             -add eax, 0x3df3b646
    (cpu.eax) += x86::reg32(x86::sreg32(1039382086 /*0x3df3b646*/));
    // 004880f3  a334b64d00             -mov dword ptr [0x4db634], eax
    app->getMemory<x86::reg32>(x86::reg32(5092916) /* 0x4db634 */) = cpu.eax;
    // 004880f8  056de7dd40             -add eax, 0x40dde76d
    (cpu.eax) += x86::reg32(x86::sreg32(1088284525 /*0x40dde76d*/));
    // 004880fd  a338b64d00             -mov dword ptr [0x4db638], eax
    app->getMemory<x86::reg32>(x86::reg32(5092920) /* 0x4db638 */) = cpu.eax;
    // 00488102  05e17a3297             -add eax, 0x97327ae1
    (cpu.eax) += x86::reg32(x86::sreg32(2536667873 /*0x97327ae1*/));
    // 00488107  a33cb64d00             -mov dword ptr [0x4db63c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092924) /* 0x4db63c */) = cpu.eax;
    // 0048810c  05e7fba9d1             -add eax, 0xd1a9fbe7
    (cpu.eax) += x86::reg32(x86::sreg32(3517578215 /*0xd1a9fbe7*/));
    // 00488111  a340b64d00             -mov dword ptr [0x4db640], eax
    app->getMemory<x86::reg32>(x86::reg32(5092928) /* 0x4db640 */) = cpu.eax;
    // 00488116  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_488120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488120);
    // 00488120  e8c7c7ffff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 00488125  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00488128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488129  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048812a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048812b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048812c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048812f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488131  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00488135  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488137  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048813a  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048813f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00488142  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00488146  83f803                 +cmp eax, 3
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
    // 00488149  0f8591000000           -jne 0x4881e0
    if (!cpu.flags.zf)
    {
        return sub_4881e0(app, cpu);
    }
    // 0048814f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488151  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488154  7f50                   -jg 0x4881a6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_4881a6(app, cpu);
    }
    // 00488156  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048815a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048815d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488160  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488163  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488164  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48815d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048815d);
    goto L_entry_0x0048815d;
    // 00488120  e8c7c7ffff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 00488125  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00488128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488129  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048812a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048812b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048812c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048812f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488131  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00488135  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488137  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048813a  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048813f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00488142  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00488146  83f803                 +cmp eax, 3
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
    // 00488149  0f8591000000           -jne 0x4881e0
    if (!cpu.flags.zf)
    {
        return sub_4881e0(app, cpu);
    }
    // 0048814f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488151  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488154  7f50                   -jg 0x4881a6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_4881a6(app, cpu);
    }
    // 00488156  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048815a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_entry_0x0048815d:
    // 0048815d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488160  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488163  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488164  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488128);
    goto L_entry_0x00488128;
    // 00488120  e8c7c7ffff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 00488125  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00488128:
    // 00488128  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488129  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048812a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048812b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048812c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048812f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488131  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00488135  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488137  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048813a  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048813f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00488142  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00488146  83f803                 +cmp eax, 3
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
    // 00488149  0f8591000000           -jne 0x4881e0
    if (!cpu.flags.zf)
    {
        return sub_4881e0(app, cpu);
    }
    // 0048814f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488151  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488154  7f50                   -jg 0x4881a6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_4881a6(app, cpu);
    }
    // 00488156  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048815a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048815d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488160  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488163  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488164  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488168);
    // 00488168  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488169  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048816e  e879c7ffff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 00488173  e8b0ffffff             -call 0x488128
    cpu.esp -= 4;
    sub_488128(app, cpu);
    if (cpu.terminate) return;
    // 00488178  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488179  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48817c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048817c);
    // 0048817c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048817d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048817f  e868c7ffff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 00488184  e89fffffff             -call 0x488128
    cpu.esp -= 4;
    sub_488128(app, cpu);
    if (cpu.terminate) return;
    // 00488189  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048818a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48818c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048818c);
    // 0048818c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048818d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00488192  e891ffffff             -call 0x488128
    cpu.esp -= 4;
    sub_488128(app, cpu);
    if (cpu.terminate) return;
    // 00488197  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488198  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48819c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048819c);
    // 0048819c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048819d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048819f  e884ffffff             -call 0x488128
    cpu.esp -= 4;
    sub_488128(app, cpu);
    if (cpu.terminate) return;
    // 004881a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4881a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004881a6);
    // 004881a6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004881a9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004881ab  e824490100             -call 0x49cad4
    cpu.esp -= 4;
    sub_49cad4(app, cpu);
    if (cpu.terminate) return;
    // 004881b0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004881b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004881b4  74a7                   -je 0x48815d
    if (cpu.flags.zf)
    {
        return sub_48815d(app, cpu);
    }
    // 004881b6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004881b8  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004881bb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004881bd  e8be270000             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004881c2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004881c4  e86f490100             -call 0x49cb38
    cpu.esp -= 4;
    sub_49cb38(app, cpu);
    if (cpu.terminate) return;
    // 004881c9  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004881cb  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004881ce  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004881d1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004881d5  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004881d8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004881db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004881df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4881e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004881e0);
    // 004881e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004881e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004881e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004881e7  bb803d5600             -mov ebx, 0x563d80
    cpu.ebx = 5651840 /*0x563d80*/;
    // 004881ec  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004881ef  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004881f1  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004881f6  e8c5be0100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004881fb  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004881fe  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488200  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00488203  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488205  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00488208  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048820a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048820d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048820f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488213  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00488215  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00488217  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488219  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048821b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048821f  21c1                   -and ecx, eax
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00488221  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488223  7c37                   -jl 0x48825c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048825c;
    }
L_0x00488225:
    // 00488225  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00488227:
    // 00488227  39f9                   +cmp ecx, edi
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
    // 00488229  7f4c                   -jg 0x488277
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00488277;
    }
    // 0048822b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048822d  7c48                   -jl 0x488277
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488277;
    }
    // 0048822f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488233  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00488236  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00488239  837b1400               +cmp dword ptr [ebx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048823d  7407                   -je 0x488246
    if (cpu.flags.zf)
    {
        goto L_0x00488246;
    }
    // 0048823f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488241  e8cabe0100             -call 0x4a4110
    cpu.esp -= 4;
    sub_4a4110(app, cpu);
    if (cpu.terminate) return;
L_0x00488246:
    // 00488246  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 0048824b  e878be0100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00488250  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488254  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488257  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488258  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488259  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048825a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048825b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048825c:
    // 0048825c  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048825e  83fdff                 +cmp ebp, -1
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
    // 00488261  74c2                   -je 0x488225
    if (cpu.flags.zf)
    {
        goto L_0x00488225;
    }
    // 00488263  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00488268  e85bbe0100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 0048826d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048826f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488272  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488273  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488274  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488275  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488276  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488277:
    // 00488277  833d04b24d0000         +cmp dword ptr [0x4db204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091844) /* 0x4db204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048827e  740d                   -je 0x48828d
    if (cpu.flags.zf)
    {
        goto L_0x0048828d;
    }
    // 00488280  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00488283  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00488287  7404                   -je 0x48828d
    if (cpu.flags.zf)
    {
        goto L_0x0048828d;
    }
    // 00488289  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048828b  742f                   -je 0x4882bc
    if (cpu.flags.zf)
    {
        goto L_0x004882bc;
    }
L_0x0048828d:
    // 0048828d  833d04b24d0000         +cmp dword ptr [0x4db204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091844) /* 0x4db204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488294  7406                   -je 0x48829c
    if (cpu.flags.zf)
    {
        goto L_0x0048829c;
    }
    // 00488296  f6461810               +test byte ptr [esi + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 0048829a  754d                   -jne 0x4882e9
    if (!cpu.flags.zf)
    {
        goto L_0x004882e9;
    }
L_0x0048829c:
    // 0048829c  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004882a1  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004882a5  e81ebe0100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004882aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004882ac  0f8cda000000           -jl 0x48838c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048838c;
    }
    // 004882b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004882b4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004882b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004882bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004882bc:
    // 004882bc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004882be  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004882c1  e882bf0100             -call 0x4a4248
    cpu.esp -= 4;
    sub_4a4248(app, cpu);
    if (cpu.terminate) return;
    // 004882c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004882c8  7415                   -je 0x4882df
    if (cpu.flags.zf)
    {
        goto L_0x004882df;
    }
    // 004882ca  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004882cd  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004882cf  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004882d2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004882d4  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 004882d6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004882d8  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 004882da  e948ffffff             -jmp 0x488227
    goto L_0x00488227;
L_0x004882df:
    // 004882df  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004882e4  e93effffff             -jmp 0x488227
    goto L_0x00488227;
L_0x004882e9:
    // 004882e9  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004882ec  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004882ee  e865c00100             -call 0x4a4358
    cpu.esp -= 4;
    sub_4a4358(app, cpu);
    if (cpu.terminate) return;
    // 004882f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004882f5  7415                   -je 0x48830c
    if (cpu.flags.zf)
    {
        goto L_0x0048830c;
    }
    // 004882f7  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004882fa  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004882fc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004882fe  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00488300  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00488303  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00488305  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488307  e91bffffff             -jmp 0x488227
    goto L_0x00488227;
L_0x0048830c:
    // 0048830c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488310  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488314  b8e0fc4c00             -mov eax, 0x4cfce0
    cpu.eax = 5045472 /*0x4cfce0*/;
    // 00488319  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048831b  e8f0c1ffff             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 00488320  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488322  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488324  0f8472ffffff           -je 0x48829c
    if (cpu.flags.zf)
    {
        goto L_0x0048829c;
    }
    // 0048832a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048832d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048832f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00488331  e84a260000             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00488336  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00488339  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0048833c  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048833f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488341  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00488344  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00488347  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0048834a  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0048834d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00488350  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00488353  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488355  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00488357  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048835a  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048835d  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00488360  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00488363  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00488366  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00488369  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048836c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048836f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488371  e8f6c9ffff             -call 0x484d6c
    cpu.esp -= 4;
    sub_484d6c(app, cpu);
    if (cpu.terminate) return;
    // 00488376  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 0048837b  e848bd0100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00488380  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488384  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488387  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488388  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488389  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048838a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048838b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048838c:
    // 0048838c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048838e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488391  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488392  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488393  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488394  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488395  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488396(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488396);
    // 00488396  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488397  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488398  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488399  2eff1578654c00         -call dword ptr cs:[0x4c6578]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006712) /* 0x4c6578 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004883a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004883a2  7508                   -jne 0x4883ac
    if (!cpu.flags.zf)
    {
        goto L_0x004883ac;
    }
    // 004883a4  e809e20100             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004883a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004883ac:
    // 004883ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004883ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4883c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004883c0);
    // 004883c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004883c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004883c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004883c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004883c5  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004883cb  8b1544b64d00           -mov edx, dword ptr [0x4db644]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092932) /* 0x4db644 */);
    // 004883d1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004883d3  83faff                 +cmp edx, -1
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
    // 004883d6  7409                   -je 0x4883e1
    if (cpu.flags.zf)
    {
        goto L_0x004883e1;
    }
    // 004883d8  bf39405600             -mov edi, 0x564039
    cpu.edi = 5652537 /*0x564039*/;
L_0x004883dd:
    // 004883dd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004883df  740e                   -je 0x4883ef
    if (cpu.flags.zf)
    {
        goto L_0x004883ef;
    }
L_0x004883e1:
    // 004883e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004883e3  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004883e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004883ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004883ef:
    // 004883ef  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004883f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004883f2  8b0d44b64d00           -mov ecx, dword ptr [0x4db644]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5092932) /* 0x4db644 */);
    // 004883f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004883f9  2eff1594644c00         -call dword ptr cs:[0x4c6494]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006484) /* 0x4c6494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488400  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488402  743f                   -je 0x488443
    if (cpu.flags.zf)
    {
        goto L_0x00488443;
    }
    // 00488404  8b1d303f5600           -mov ebx, dword ptr [0x563f30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652272) /* 0x563f30 */);
    // 0048840a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0048840c  ba343f5600             -mov edx, 0x563f34
    cpu.edx = 5652276 /*0x563f34*/;
    // 00488411  88a339405600           -mov byte ptr [ebx + 0x564039], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5652537) /* 0x564039 */) = cpu.ah;
    // 00488417  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488419  e8bee0ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048841e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00488423  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00488427  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00488429  e8d7ea0100             -call 0x4a6f05
    cpu.esp -= 4;
    sub_4a6f05(app, cpu);
    if (cpu.terminate) return;
    // 0048842e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048842f  2eff15e0644c00         -call dword ptr cs:[0x4c64e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006560) /* 0x4c64e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488436  83f8ff                 +cmp eax, -1
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
    // 00488439  74a2                   -je 0x4883dd
    if (cpu.flags.zf)
    {
        goto L_0x004883dd;
    }
    // 0048843b  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0048843d  759e                   -jne 0x4883dd
    if (!cpu.flags.zf)
    {
        goto L_0x004883dd;
    }
    // 0048843f  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00488441  eb9a                   -jmp 0x4883dd
    goto L_0x004883dd;
L_0x00488443:
    // 00488443  8b1d44b64d00           -mov ebx, dword ptr [0x4db644]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092932) /* 0x4db644 */);
    // 00488449  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048844a  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0048844f  2eff158c644c00         -call dword ptr cs:[0x4c648c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006476) /* 0x4c648c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488456  893544b64d00           -mov dword ptr [0x4db644], esi
    app->getMemory<x86::reg32>(x86::reg32(5092932) /* 0x4db644 */) = cpu.esi;
    // 0048845c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048845e  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00488464  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488465  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488466  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488468  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488469  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48846c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048846c);
    // 0048846c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048846d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048846e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048846f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488470  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488471  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00488477  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488479  8b1544b64d00           -mov edx, dword ptr [0x4db644]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092932) /* 0x4db644 */);
    // 0048847f  83faff                 +cmp edx, -1
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
    // 00488482  0f856b000000           -jne 0x4884f3
    if (!cpu.flags.zf)
    {
        goto L_0x004884f3;
    }
L_0x00488488:
    // 00488488  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0048848d  b8343f5600             -mov eax, 0x563f34
    cpu.eax = 5652276 /*0x563f34*/;
    // 00488492  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00488494  bf343f5600             -mov edi, 0x563f34
    cpu.edi = 5652276 /*0x563f34*/;
    // 00488499  e83ee0ffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048849e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004884a0  49                     -dec ecx
    (cpu.ecx)--;
    // 004884a1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004884a3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004884a5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004884a7  49                     -dec ecx
    (cpu.ecx)--;
    // 004884a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004884aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004884ac  7e15                   -jle 0x4884c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004884c3;
    }
L_0x004884ae:
    // 004884ae  8a90343f5600           -mov dl, byte ptr [eax + 0x563f34]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5652276) /* 0x563f34 */);
    // 004884b4  80fa5c                 +cmp dl, 0x5c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004884b7  740a                   -je 0x4884c3
    if (cpu.flags.zf)
    {
        goto L_0x004884c3;
    }
    // 004884b9  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004884bc  7405                   -je 0x4884c3
    if (cpu.flags.zf)
    {
        goto L_0x004884c3;
    }
    // 004884be  48                     -dec eax
    (cpu.eax)--;
    // 004884bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004884c1  7feb                   -jg 0x4884ae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004884ae;
    }
L_0x004884c3:
    // 004884c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004884c5  7536                   -jne 0x4884fd
    if (!cpu.flags.zf)
    {
        goto L_0x004884fd;
    }
L_0x004884c7:
    // 004884c7  a3303f5600             -mov dword ptr [0x563f30], eax
    app->getMemory<x86::reg32>(x86::reg32(5652272) /* 0x563f30 */) = cpu.eax;
    // 004884cc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004884ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004884cf  68343f5600             -push 0x563f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5652276 /*0x563f34*/;
    cpu.esp -= 4;
    // 004884d4  2eff1590644c00         -call dword ptr cs:[0x4c6490]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006480) /* 0x4c6490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004884db  a344b64d00             -mov dword ptr [0x4db644], eax
    app->getMemory<x86::reg32>(x86::reg32(5092932) /* 0x4db644 */) = cpu.eax;
    // 004884e0  83f8ff                 +cmp eax, -1
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
    // 004884e3  751b                   -jne 0x488500
    if (!cpu.flags.zf)
    {
        goto L_0x00488500;
    }
    // 004884e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004884e7  81c440010000           +add esp, 0x140
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004884ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004884ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004884ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004884f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004884f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004884f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004884f3:
    // 004884f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004884f4  2eff158c644c00         -call dword ptr cs:[0x4c648c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006476) /* 0x4c648c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004884fb  eb8b                   -jmp 0x488488
    goto L_0x00488488;
L_0x004884fd:
    // 004884fd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004884fe  ebc7                   -jmp 0x4884c7
    goto L_0x004884c7;
L_0x00488500:
    // 00488500  ba343f5600             -mov edx, 0x563f34
    cpu.edx = 5652276 /*0x563f34*/;
    // 00488505  8b1d303f5600           -mov ebx, dword ptr [0x563f30]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652272) /* 0x563f30 */);
    // 0048850b  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0048850d  b839405600             -mov eax, 0x564039
    cpu.eax = 5652537 /*0x564039*/;
    // 00488512  888b39405600           -mov byte ptr [ebx + 0x564039], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5652537) /* 0x564039 */) = cpu.cl;
    // 00488518  e8bfdfffff             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 0048851d  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00488522  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00488526  b839405600             -mov eax, 0x564039
    cpu.eax = 5652537 /*0x564039*/;
    // 0048852b  e8d5e90100             -call 0x4a6f05
    cpu.esp -= 4;
    sub_4a6f05(app, cpu);
    if (cpu.terminate) return;
    // 00488530  6839405600             -push 0x564039
    app->getMemory<x86::reg32>(cpu.esp-4) = 5652537 /*0x564039*/;
    cpu.esp -= 4;
    // 00488535  2eff15e0644c00         -call dword ptr cs:[0x4c64e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006560) /* 0x4c64e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048853c  83f8ff                 +cmp eax, -1
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
    // 0048853f  7415                   -je 0x488556
    if (cpu.flags.zf)
    {
        goto L_0x00488556;
    }
    // 00488541  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00488543  7511                   -jne 0x488556
    if (!cpu.flags.zf)
    {
        goto L_0x00488556;
    }
    // 00488545  b839405600             -mov eax, 0x564039
    cpu.eax = 5652537 /*0x564039*/;
    // 0048854a  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00488550  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488551  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488552  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488553  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488554  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488555  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488556:
    // 00488556  e865feffff             -call 0x4883c0
    cpu.esp -= 4;
    sub_4883c0(app, cpu);
    if (cpu.terminate) return;
    // 0048855b  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00488561  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488562  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488563  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488564  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488565  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488566  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_488570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488570);
    // 00488570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488573  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488576  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048857a  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048857e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488580  e837f2ffff             -call 0x4877bc
    cpu.esp -= 4;
    sub_4877bc(app, cpu);
    if (cpu.terminate) return;
    // 00488585  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00488588  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048858a  750a                   -jne 0x488596
    if (!cpu.flags.zf)
    {
        goto L_0x00488596;
    }
    // 0048858c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048858f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00488592  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488593  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488594  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488595  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488596:
    // 00488596  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488598  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048859d  e8aef3ffff             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 004885a2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004885a5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004885a8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004885ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004885ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4885b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004885b0);
    // 004885b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004885b2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004885b4  8b1d40415600           -mov ebx, dword ptr [0x564140]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652800) /* 0x564140 */);
    // 004885ba  d1fa                   +sar edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004885bc  e9701a0000             -jmp 0x48a031
    return sub_48a031(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4885c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004885c4);
    // 004885c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004885c6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004885c8  8b1d40415600           -mov ebx, dword ptr [0x564140]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652800) /* 0x564140 */);
    // 004885ce  e95e1a0000             -jmp 0x48a031
    return sub_48a031(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4885d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004885d4);
    // 004885d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004885d6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004885d8  8b1d40415600           -mov ebx, dword ptr [0x564140]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652800) /* 0x564140 */);
    // 004885de  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004885e0  e94c1a0000             -jmp 0x48a031
    return sub_48a031(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4885e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004885e8);
    // 004885e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004885e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004885ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004885ec  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004885ee:
    // 004885ee  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004885f3  8b1540415600           -mov edx, dword ptr [0x564140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652800) /* 0x564140 */);
    // 004885f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004885fb  e86f3a0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 00488600  83c103                 +add ecx, 3
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
    // 00488603  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00488604  75e8                   -jne 0x4885ee
    if (!cpu.flags.zf)
    {
        goto L_0x004885ee;
    }
    // 00488606  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488607  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488608  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48860c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048860c);
    // 0048860c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048860e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00488610  8b1d40415600           -mov ebx, dword ptr [0x564140]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652800) /* 0x564140 */);
    // 00488616  c1e202                 +shl edx, 2
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
    // 00488619  e9131a0000             -jmp 0x48a031
    return sub_48a031(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488620);
    // 00488620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488622  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488623  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00488626  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488628  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048862a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048862e  8a155cb24d00           -mov dl, byte ptr [0x4db25c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 00488634  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488637  735b                   -jae 0x488694
    if (!cpu.flags.cf)
    {
        goto L_0x00488694;
    }
    // 00488639  80fa04                 +cmp dl, 4
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
    // 0048863c  750a                   -jne 0x488648
    if (!cpu.flags.zf)
    {
        goto L_0x00488648;
    }
    // 0048863e  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00488641  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488643  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x00488646:
    // 00488646  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x00488648:
    // 00488648  a340415600             -mov dword ptr [0x564140], eax
    app->getMemory<x86::reg32>(x86::reg32(5652800) /* 0x564140 */) = cpu.eax;
    // 0048864d  66895c2404             -mov word ptr [esp + 4], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 00488652  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 00488657  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00488659  b948b64d00             -mov ecx, 0x4db648
    cpu.ecx = 5092936 /*0x4db648*/;
    // 0048865e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488660  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 00488663  a05db24d00             -mov al, byte ptr [0x4db25d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */);
    // 00488668  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048866b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00488670  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00488672  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00488674  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488676  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00488678  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048867b  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00488681  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00488683  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00488686  e8318a0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 0048868b  83c414                 +add esp, 0x14
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
    // 0048868e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048868f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488690  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488691  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00488694:
    // 00488694  7618                   -jbe 0x4886ae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004886ae;
    }
    // 00488696  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488699  72ad                   -jb 0x488648
    if (cpu.flags.cf)
    {
        goto L_0x00488648;
    }
    // 0048869b  7605                   -jbe 0x4886a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004886a2;
    }
    // 0048869d  80fa10                 +cmp dl, 0x10
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
    // 004886a0  75a6                   -jne 0x488648
    if (!cpu.flags.zf)
    {
        goto L_0x00488648;
    }
L_0x004886a2:
    // 004886a2  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004886a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004886a9  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004886ac  eb98                   -jmp 0x488646
    goto L_0x00488646;
L_0x004886ae:
    // 004886ae  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004886b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004886b5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004886b8  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004886ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004886bc  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004886bf  eb85                   -jmp 0x488646
    goto L_0x00488646;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4886d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004886d0);
    // 004886d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004886d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004886d3  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004886d8  e86b180000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004886dd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004886df  7423                   -je 0x488704
    if (cpu.flags.zf)
    {
        goto L_0x00488704;
    }
    // 004886e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004886e2  e8e9830000             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 004886e7  8b0d54425600           -mov ecx, dword ptr [0x564254]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653076) /* 0x564254 */);
    // 004886ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004886ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004886f1  ff1594b64d00           -call dword ptr [0x4db694]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093012) /* 0x4db694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004886f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004886f8  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004886fd  e85e180000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00488702  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488704:
    // 00488704  ff1598b64d00           -call dword ptr [0x4db698]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093016) /* 0x4db698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048870a  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 0048870f  e84c180000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00488714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488718);
    // 00488718  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488719  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048871a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048871b  833d7cb64d0000         +cmp dword ptr [0x4db67c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488722  7406                   -je 0x48872a
    if (cpu.flags.zf)
    {
        goto L_0x0048872a;
    }
    // 00488724  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488726  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488727  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488728  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488729  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048872a:
    // 0048872a  68e8fc4c00             -push 0x4cfce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045480 /*0x4cfce8*/;
    cpu.esp -= 4;
    // 0048872f  2eff1544654c00         -call dword ptr cs:[0x4c6544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006660) /* 0x4c6544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488736  a37cb64d00             -mov dword ptr [0x4db67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */) = cpu.eax;
    // 0048873b  83f820                 +cmp eax, 0x20
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
    // 0048873e  7d10                   -jge 0x488750
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488750;
    }
    // 00488740  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488742  a37cb64d00             -mov dword ptr [0x4db67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */) = cpu.eax;
    // 00488747  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048874c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048874d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048874e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048874f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488750:
    // 00488750  68f4fc4c00             -push 0x4cfcf4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045492 /*0x4cfcf4*/;
    cpu.esp -= 4;
    // 00488755  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488756  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048875d  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048875f  3d02000600             +cmp eax, 0x60002
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(393218 /*0x60002*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488764  7409                   -je 0x48876f
    if (cpu.flags.zf)
    {
        goto L_0x0048876f;
    }
    // 00488766  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0048876b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048876c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048876d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048876e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048876f:
    // 0048876f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488770  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488771  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488772  6804fd4c00             -push 0x4cfd04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045508 /*0x4cfd04*/;
    cpu.esp -= 4;
    // 00488777  8b0d7cb64d00           -mov ecx, dword ptr [0x4db67c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
    // 0048877d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048877e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488780  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488787  687cad4900             -push 0x49ad7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4828540 /*0x49ad7c*/;
    cpu.esp -= 4;
    // 0048878c  8b0d88da4d00           -mov ecx, dword ptr [0x4dda88]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102216) /* 0x4dda88 */);
    // 00488792  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488794  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488796  b8bc7c4a00             -mov eax, 0x4a7cbc
    cpu.eax = 4881596 /*0x4a7cbc*/;
    // 0048879b  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048879d  681cfd4c00             -push 0x4cfd1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045532 /*0x4cfd1c*/;
    cpu.esp -= 4;
    // 004887a2  8b1d7cb64d00           -mov ebx, dword ptr [0x4db67c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
    // 004887a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004887a9  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004887b0  682cfd4c00             -push 0x4cfd2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045548 /*0x4cfd2c*/;
    cpu.esp -= 4;
    // 004887b5  8b357cb64d00           -mov esi, dword ptr [0x4db67c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
    // 004887bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004887bc  a390b64d00             -mov dword ptr [0x4db690], eax
    app->getMemory<x86::reg32>(x86::reg32(5093008) /* 0x4db690 */) = cpu.eax;
    // 004887c1  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004887c8  6840fd4c00             -push 0x4cfd40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045568 /*0x4cfd40*/;
    cpu.esp -= 4;
    // 004887cd  8b3d7cb64d00           -mov edi, dword ptr [0x4db67c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
    // 004887d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004887d4  a394b64d00             -mov dword ptr [0x4db694], eax
    app->getMemory<x86::reg32>(x86::reg32(5093012) /* 0x4db694 */) = cpu.eax;
    // 004887d9  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004887e0  6850fd4c00             -push 0x4cfd50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045584 /*0x4cfd50*/;
    cpu.esp -= 4;
    // 004887e5  8b2d7cb64d00           -mov ebp, dword ptr [0x4db67c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
    // 004887eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004887ec  a398b64d00             -mov dword ptr [0x4db698], eax
    app->getMemory<x86::reg32>(x86::reg32(5093016) /* 0x4db698 */) = cpu.eax;
    // 004887f1  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004887f8  a39cb64d00             -mov dword ptr [0x4db69c], eax
    app->getMemory<x86::reg32>(x86::reg32(5093020) /* 0x4db69c */) = cpu.eax;
    // 004887fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488800  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488802  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488803  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488805  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488808(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488808);
    // 00488808  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488809  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048880a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048880b  8b157cb64d00           -mov edx, dword ptr [0x4db67c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */);
    // 00488811  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488813  750e                   -jne 0x488823
    if (!cpu.flags.zf)
    {
        goto L_0x00488823;
    }
    // 00488815  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488817  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488819  891d7cb64d00           -mov dword ptr [0x4db67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */) = cpu.ebx;
    // 0048881f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488820  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488821  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488822  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488823:
    // 00488823  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488824  2eff159c644c00         -call dword ptr cs:[0x4c649c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006492) /* 0x4c649c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048882b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048882d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048882f  891d7cb64d00           -mov dword ptr [0x4db67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092988) /* 0x4db67c */) = cpu.ebx;
    // 00488835  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488836  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488837  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488838  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48883c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048883c);
    // 0048883c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048883d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048883e  e8d5feffff             -call 0x488718
    cpu.esp -= 4;
    sub_488718(app, cpu);
    if (cpu.terminate) return;
    // 00488843  e888820000             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00488848  ff1590b64d00           -call dword ptr [0x4db690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093008) /* 0x4db690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048884e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488850  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488852  7e06                   -jle 0x48885a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048885a;
    }
    // 00488854  81ca00000100           -or edx, 0x10000
    cpu.edx |= x86::reg32(x86::sreg32(65536 /*0x10000*/));
L_0x0048885a:
    // 0048885a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048885c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048885d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048885e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488860);
    // 00488860  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488861  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488862  be80b64d00             -mov esi, 0x4db680
    cpu.esi = 5092992 /*0x4db680*/;
    // 00488867  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00488869  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048886b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048886c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048886d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048886e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048886f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488870  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488871  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488874);
    // 00488874  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488875  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488876  bf80b64d00             -mov edi, 0x4db680
    cpu.edi = 5092992 /*0x4db680*/;
    // 0048887b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048887d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048887e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048887f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00488880  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00488881  803d86b64d0010         +cmp byte ptr [0x4db686], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092998) /* 0x4db686 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488888  7608                   -jbe 0x488892
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488892;
    }
    // 0048888a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048888f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488890  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488891  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488892:
    // 00488892  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488894  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488895  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488898);
    // 00488898  a378b64d00             -mov dword ptr [0x4db678], eax
    app->getMemory<x86::reg32>(x86::reg32(5092984) /* 0x4db678 */) = cpu.eax;
    // 0048889d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048889f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4888a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004888a0);
    // 004888a0  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004888a7  7506                   -jne 0x4888af
    if (!cpu.flags.zf)
    {
        goto L_0x004888af;
    }
    // 004888a9  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004888ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004888af:
    // 004888af  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004888b4  e88f160000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004888b9  ff1598b64d00           -call dword ptr [0x4db698]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093016) /* 0x4db698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004888bf  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004888c4  e897160000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004888c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004888cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4888cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004888cc);
    // 004888cc  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004888d3  7506                   -jne 0x4888db
    if (!cpu.flags.zf)
    {
        goto L_0x004888db;
    }
    // 004888d5  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004888da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004888db:
    // 004888db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004888dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004888dd  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 004888e2  e861160000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004888e7  e8e4810000             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 004888ec  8b0d54425600           -mov ecx, dword ptr [0x564254]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653076) /* 0x564254 */);
    // 004888f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004888f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004888f6  ff1594b64d00           -call dword ptr [0x4db694]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093012) /* 0x4db694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004888fc  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 00488901  e85a160000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00488906  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488908  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488909  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048890a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48890c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048890c);
    // 0048890c  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 00488911  e832160000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00488916  ff159cb64d00           -call dword ptr [0x4db69c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093020) /* 0x4db69c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048891c  a100c65900             -mov eax, dword ptr [0x59c600]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883392) /* 0x59c600 */);
    // 00488921  e93a160000             -jmp 0x489f60
    return sub_489f60(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488928(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488928);
    // 00488928  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488929  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048892c  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488931  7443                   -je 0x488976
    if (cpu.flags.zf)
    {
        goto L_0x00488976;
    }
    // 00488933  803d6cb64d0000         +cmp byte ptr [0x4db66c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092972) /* 0x4db66c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048893a  0f8588010000           -jne 0x488ac8
    if (!cpu.flags.zf)
    {
        goto L_0x00488ac8;
    }
L_0x00488940:
    // 00488940  803d6db64d0000         +cmp byte ptr [0x4db66d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092973) /* 0x4db66d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488947  740f                   -je 0x488958
    if (cpu.flags.zf)
    {
        goto L_0x00488958;
    }
    // 00488949  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048894b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048894d  e87e98ffff             -call 0x4821d0
    cpu.esp -= 4;
    sub_4821d0(app, cpu);
    if (cpu.terminate) return;
    // 00488952  881d6db64d00           -mov byte ptr [0x4db66d], bl
    app->getMemory<x86::reg8>(x86::reg32(5092973) /* 0x4db66d */) = cpu.bl;
L_0x00488958:
    // 00488958  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048895a  ff1598b64d00           -call dword ptr [0x4db698]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093016) /* 0x4db698 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488960:
    // 00488960  890d70b64d00           -mov dword ptr [0x4db670], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */) = cpu.ecx;
L_0x00488966:
    // 00488966  c6056fb64d0001         -mov byte ptr [0x4db66f], 1
    app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */) = 1 /*0x1*/;
    // 0048896d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048896f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488972  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488973  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00488976:
    // 00488976  a150425600             -mov eax, dword ptr [0x564250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653072) /* 0x564250 */);
    // 0048897b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048897e  e84d810000             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00488983  ff1590b64d00           -call dword ptr [0x4db690]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093008) /* 0x4db690 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488989  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048898b  0f8eb8000000           -jle 0x488a49
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488a49;
    }
    // 00488991  8a7c2401               -mov bh, byte ptr [esp + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00488995  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 00488998  0f84c0000000           -je 0x488a5e
    if (cpu.flags.zf)
    {
        goto L_0x00488a5e;
    }
    // 0048899e  c70574b64d0022560000   -mov dword ptr [0x4db674], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 22050 /*0x5622*/;
L_0x004889a8:
    // 004889a8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004889ab  8a156eb64d00           -mov dl, byte ptr [0x4db66e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5092974) /* 0x4db66e */);
    // 004889b1  a354425600             -mov dword ptr [0x564254], eax
    app->getMemory<x86::reg32>(x86::reg32(5653076) /* 0x564254 */) = cpu.eax;
    // 004889b6  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004889b8  7512                   -jne 0x4889cc
    if (!cpu.flags.zf)
    {
        goto L_0x004889cc;
    }
    // 004889ba  b850fd4900             -mov eax, 0x49fd50
    cpu.eax = 4848976 /*0x49fd50*/;
    // 004889bf  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 004889c1  e8da230100             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 004889c6  88356eb64d00           -mov byte ptr [0x4db66e], dh
    app->getMemory<x86::reg8>(x86::reg32(5092974) /* 0x4db66e */) = cpu.dh;
L_0x004889cc:
    // 004889cc  ba78564a00             -mov edx, 0x4a5678
    cpu.edx = 4871800 /*0x4a5678*/;
    // 004889d1  a154425600             -mov eax, dword ptr [0x564254]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653076) /* 0x564254 */);
    // 004889d6  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004889db  e848e60100             -call 0x4a7028
    cpu.esp -= 4;
    sub_4a7028(app, cpu);
    if (cpu.terminate) return;
    // 004889e0  8b15a0bf5900           -mov edx, dword ptr [0x59bfa0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881760) /* 0x59bfa0 */);
    // 004889e6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004889e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004889ea  e8ed000000             -call 0x488adc
    cpu.esp -= 4;
    sub_488adc(app, cpu);
    if (cpu.terminate) return;
    // 004889ef  e8dc800000             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 004889f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004889f6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004889f9  ff1594b64d00           -call dword ptr [0x4db694]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5093012) /* 0x4db694 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004889ff  a370b64d00             -mov dword ptr [0x4db670], eax
    app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */) = cpu.eax;
    // 00488a04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488a06  0f8c5affffff           -jl 0x488966
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488966;
    }
    // 00488a0c  803d6cb64d0000         +cmp byte ptr [0x4db66c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092972) /* 0x4db66c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488a13  7512                   -jne 0x488a27
    if (!cpu.flags.zf)
    {
        goto L_0x00488a27;
    }
    // 00488a15  b80c894800             -mov eax, 0x48890c
    cpu.eax = 4753676 /*0x48890c*/;
    // 00488a1a  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
    // 00488a1c  e8abaeffff             -call 0x4838cc
    cpu.esp -= 4;
    sub_4838cc(app, cpu);
    if (cpu.terminate) return;
    // 00488a21  883d6cb64d00           -mov byte ptr [0x4db66c], bh
    app->getMemory<x86::reg8>(x86::reg32(5092972) /* 0x4db66c */) = cpu.bh;
L_0x00488a27:
    // 00488a27  803d6db64d0000         +cmp byte ptr [0x4db66d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092973) /* 0x4db66d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488a2e  7512                   -jne 0x488a42
    if (!cpu.flags.zf)
    {
        goto L_0x00488a42;
    }
    // 00488a30  b8d0864800             -mov eax, 0x4886d0
    cpu.eax = 4753104 /*0x4886d0*/;
    // 00488a35  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00488a37  e89497ffff             -call 0x4821d0
    cpu.esp -= 4;
    sub_4821d0(app, cpu);
    if (cpu.terminate) return;
    // 00488a3c  882d6db64d00           -mov byte ptr [0x4db66d], ch
    app->getMemory<x86::reg8>(x86::reg32(5092973) /* 0x4db66d */) = cpu.ch;
L_0x00488a42:
    // 00488a42  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00488a44  e917ffffff             -jmp 0x488960
    goto L_0x00488960;
L_0x00488a49:
    // 00488a49  a370b64d00             -mov dword ptr [0x4db670], eax
    app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */) = cpu.eax;
    // 00488a4e  c6056fb64d0001         -mov byte ptr [0x4db66f], 1
    app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */) = 1 /*0x1*/;
    // 00488a55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488a57  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488a5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a5b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00488a5e:
    // 00488a5e  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00488a61  740f                   -je 0x488a72
    if (cpu.flags.zf)
    {
        goto L_0x00488a72;
    }
    // 00488a63  c70574b64d00803e0000   -mov dword ptr [0x4db674], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 16000 /*0x3e80*/;
    // 00488a6d  e936ffffff             -jmp 0x4889a8
    goto L_0x004889a8;
L_0x00488a72:
    // 00488a72  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00488a75  740f                   -je 0x488a86
    if (cpu.flags.zf)
    {
        goto L_0x00488a86;
    }
    // 00488a77  c70574b64d00007d0000   -mov dword ptr [0x4db674], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 32000 /*0x7d00*/;
    // 00488a81  e922ffffff             -jmp 0x4889a8
    goto L_0x004889a8;
L_0x00488a86:
    // 00488a86  f6c720                 +test bh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 32 /*0x20*/));
    // 00488a89  740f                   -je 0x488a9a
    if (cpu.flags.zf)
    {
        goto L_0x00488a9a;
    }
    // 00488a8b  c70574b64d0044ac0000   -mov dword ptr [0x4db674], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 44100 /*0xac44*/;
    // 00488a95  e90effffff             -jmp 0x4889a8
    goto L_0x004889a8;
L_0x00488a9a:
    // 00488a9a  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00488a9d  740f                   -je 0x488aae
    if (cpu.flags.zf)
    {
        goto L_0x00488aae;
    }
    // 00488a9f  c70574b64d00112b0000   -mov dword ptr [0x4db674], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 11025 /*0x2b11*/;
    // 00488aa9  e9fafeffff             -jmp 0x4889a8
    goto L_0x004889a8;
L_0x00488aae:
    // 00488aae  c70570b64d00f8ffffff   -mov dword ptr [0x4db670], 0xfffffff8
    app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */) = 4294967288 /*0xfffffff8*/;
    // 00488ab8  c6056fb64d0001         -mov byte ptr [0x4db66f], 1
    app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */) = 1 /*0x1*/;
    // 00488abf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488ac1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488ac4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ac5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00488ac8:
    // 00488ac8  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00488aca  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488acc  88156cb64d00           -mov byte ptr [0x4db66c], dl
    app->getMemory<x86::reg8>(x86::reg32(5092972) /* 0x4db66c */) = cpu.dl;
    // 00488ad2  e8f5adffff             -call 0x4838cc
    cpu.esp -= 4;
    sub_4838cc(app, cpu);
    if (cpu.terminate) return;
    // 00488ad7  e964feffff             -jmp 0x488940
    goto L_0x00488940;
}

/* align: skip  */
void Application::sub_488adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488adc);
    // 00488adc  83fa28                 +cmp edx, 0x28
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
    // 00488adf  7316                   -jae 0x488af7
    if (!cpu.flags.cf)
    {
        goto L_0x00488af7;
    }
    // 00488ae1  83fa0a                 +cmp edx, 0xa
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
    // 00488ae4  720e                   -jb 0x488af4
    if (cpu.flags.cf)
    {
        goto L_0x00488af4;
    }
    // 00488ae6  761b                   -jbe 0x488b03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
    // 00488ae8  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488aeb  7207                   -jb 0x488af4
    if (cpu.flags.cf)
    {
        goto L_0x00488af4;
    }
    // 00488aed  7614                   -jbe 0x488b03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
    // 00488aef  83fa1e                 +cmp edx, 0x1e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488af2  740f                   -je 0x488b03
    if (cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
L_0x00488af4:
    // 00488af4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488af6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488af7:
    // 00488af7  760a                   -jbe 0x488b03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
    // 00488af9  83fa64                 +cmp edx, 0x64
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488afc  7312                   -jae 0x488b10
    if (!cpu.flags.cf)
    {
        goto L_0x00488b10;
    }
    // 00488afe  83fa32                 +cmp edx, 0x32
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488b01  75f1                   -jne 0x488af4
    if (!cpu.flags.zf)
    {
        goto L_0x00488af4;
    }
L_0x00488b03:
    // 00488b03  a174b64d00             -mov eax, dword ptr [0x4db674]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */);
    // 00488b08  e84ff20100             -call 0x4a7d5c
    cpu.esp -= 4;
    sub_4a7d5c(app, cpu);
    if (cpu.terminate) return;
    // 00488b0d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488b0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b10:
    // 00488b10  76f1                   -jbe 0x488b03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
    // 00488b12  83fa6e                 +cmp edx, 0x6e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488b15  72dd                   -jb 0x488af4
    if (cpu.flags.cf)
    {
        goto L_0x00488af4;
    }
    // 00488b17  76ea                   -jbe 0x488b03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
    // 00488b19  83fa78                 +cmp edx, 0x78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488b1c  74e5                   -je 0x488b03
    if (cpu.flags.zf)
    {
        goto L_0x00488b03;
    }
    // 00488b1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488b20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488b24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488b24);
    // 00488b24  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488b2b  75af                   -jne 0x488adc
    if (!cpu.flags.zf)
    {
        return sub_488adc(app, cpu);
    }
    // 00488b2d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00488b30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488b32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488b30);
    goto L_entry_0x00488b30;
    // 00488b24  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488b2b  75af                   -jne 0x488adc
    if (!cpu.flags.zf)
    {
        return sub_488adc(app, cpu);
    }
    // 00488b2d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00488b30:
    // 00488b30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488b32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488b34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488b34);
    // 00488b34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488b35  a350425600             -mov dword ptr [0x564250], eax
    app->getMemory<x86::reg32>(x86::reg32(5653072) /* 0x564250 */) = cpu.eax;
    // 00488b3a  e8d9fbffff             -call 0x488718
    cpu.esp -= 4;
    sub_488718(app, cpu);
    if (cpu.terminate) return;
    // 00488b3f  833dccab4d0000         +cmp dword ptr [0x4dabcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488b46  7507                   -jne 0x488b4f
    if (!cpu.flags.zf)
    {
        goto L_0x00488b4f;
    }
L_0x00488b48:
    // 00488b48  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00488b4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b4f:
    // 00488b4f  e87c7f0000             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00488b54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488b56  74f0                   -je 0x488b48
    if (cpu.flags.zf)
    {
        goto L_0x00488b48;
    }
    // 00488b58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488b59  6828894800             -push 0x488928
    app->getMemory<x86::reg32>(cpu.esp-4) = 4753704 /*0x488928*/;
    cpu.esp -= 4;
    // 00488b5e  6800820000             -push 0x8200
    app->getMemory<x86::reg32>(cpu.esp-4) = 33280 /*0x8200*/;
    cpu.esp -= 4;
    // 00488b63  e80897ffff             -call 0x482270
    cpu.esp -= 4;
    sub_482270(app, cpu);
    if (cpu.terminate) return;
    // 00488b68  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00488b6a  88256fb64d00           -mov byte ptr [0x4db66f], ah
    app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */) = cpu.ah;
    // 00488b70  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 00488b75  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488b77  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488b79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488b7b  e86096ffff             -call 0x4821e0
    cpu.esp -= 4;
    sub_4821e0(app, cpu);
    if (cpu.terminate) return;
    // 00488b80  803d6fb64d0000         +cmp byte ptr [0x4db66f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488b87  7513                   -jne 0x488b9c
    if (!cpu.flags.zf)
    {
        goto L_0x00488b9c;
    }
    // 00488b89  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00488b8b:
    // 00488b8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488b8d  e80a100000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00488b92  3a156fb64d00           +cmp dl, byte ptr [0x4db66f]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488b98  74f1                   -je 0x488b8b
    if (cpu.flags.zf)
    {
        goto L_0x00488b8b;
    }
    // 00488b9a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00488b9c:
    // 00488b9c  a170b64d00             -mov eax, dword ptr [0x4db670]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */);
    // 00488ba1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ba2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ba3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488ba4);
    // 00488ba4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488ba5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488ba6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488ba7  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00488ba9  88256fb64d00           -mov byte ptr [0x4db66f], ah
    app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */) = cpu.ah;
    // 00488baf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488bb4  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 00488bb9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488bbb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488bbd  e81e96ffff             -call 0x4821e0
    cpu.esp -= 4;
    sub_4821e0(app, cpu);
    if (cpu.terminate) return;
    // 00488bc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488bc4  7420                   -je 0x488be6
    if (cpu.flags.zf)
    {
        goto L_0x00488be6;
    }
L_0x00488bc6:
    // 00488bc6  803d6fb64d0000         +cmp byte ptr [0x4db66f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092975) /* 0x4db66f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488bcd  740e                   -je 0x488bdd
    if (cpu.flags.zf)
    {
        goto L_0x00488bdd;
    }
    // 00488bcf  e834fcffff             -call 0x488808
    cpu.esp -= 4;
    sub_488808(app, cpu);
    if (cpu.terminate) return;
    // 00488bd4  a170b64d00             -mov eax, dword ptr [0x4db670]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */);
    // 00488bd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488bda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488bdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488bdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488bdd:
    // 00488bdd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00488bdf  e8b80f0000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00488be4  ebe0                   -jmp 0x488bc6
    goto L_0x00488bc6;
L_0x00488be6:
    // 00488be6  803d6cb64d0000         +cmp byte ptr [0x4db66c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092972) /* 0x4db66c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488bed  740d                   -je 0x488bfc
    if (cpu.flags.zf)
    {
        goto L_0x00488bfc;
    }
    // 00488bef  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00488bf1  88356cb64d00           -mov byte ptr [0x4db66c], dh
    app->getMemory<x86::reg8>(x86::reg32(5092972) /* 0x4db66c */) = cpu.dh;
    // 00488bf7  e8d0acffff             -call 0x4838cc
    cpu.esp -= 4;
    sub_4838cc(app, cpu);
    if (cpu.terminate) return;
L_0x00488bfc:
    // 00488bfc  803d6db64d0000         +cmp byte ptr [0x4db66d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092973) /* 0x4db66d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488c03  740f                   -je 0x488c14
    if (cpu.flags.zf)
    {
        goto L_0x00488c14;
    }
    // 00488c05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488c07  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00488c09  e8c295ffff             -call 0x4821d0
    cpu.esp -= 4;
    sub_4821d0(app, cpu);
    if (cpu.terminate) return;
    // 00488c0e  883d6db64d00           -mov byte ptr [0x4db66d], bh
    app->getMemory<x86::reg8>(x86::reg32(5092973) /* 0x4db66d */) = cpu.bh;
L_0x00488c14:
    // 00488c14  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488c16  891570b64d00           -mov dword ptr [0x4db670], edx
    app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */) = cpu.edx;
    // 00488c1c  e8e7fbffff             -call 0x488808
    cpu.esp -= 4;
    sub_488808(app, cpu);
    if (cpu.terminate) return;
    // 00488c21  a170b64d00             -mov eax, dword ptr [0x4db670]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092976) /* 0x4db670 */);
    // 00488c26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488c2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488c2c);
    // 00488c2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488c2d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488c2f  e86cfcffff             -call 0x4888a0
    cpu.esp -= 4;
    sub_4888a0(app, cpu);
    if (cpu.terminate) return;
    // 00488c34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488c36  7c5b                   -jl 0x488c93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488c93;
    }
    // 00488c38  890d54425600           -mov dword ptr [0x564254], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653076) /* 0x564254 */) = cpu.ecx;
    // 00488c3e  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00488c41  7552                   -jne 0x488c95
    if (!cpu.flags.zf)
    {
        goto L_0x00488c95;
    }
    // 00488c43  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00488c46  7459                   -je 0x488ca1
    if (cpu.flags.zf)
    {
        goto L_0x00488ca1;
    }
    // 00488c48  c70574b64d00803e0000   -mov dword ptr [0x4db674], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 16000 /*0x3e80*/;
L_0x00488c52:
    // 00488c52  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00488c54  e827e60100             -call 0x4a7280
    cpu.esp -= 4;
    sub_4a7280(app, cpu);
    if (cpu.terminate) return;
    // 00488c59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488c5b  7c36                   -jl 0x488c93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488c93;
    }
    // 00488c5d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488c5e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488c60  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00488c62:
    // 00488c62  80b9bcbf590001         +cmp byte ptr [ecx + 0x59bfbc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5881788) /* 0x59bfbc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488c69  7519                   -jne 0x488c84
    if (!cpu.flags.zf)
    {
        goto L_0x00488c84;
    }
    // 00488c6b  83b9b0bf590000         +cmp dword ptr [ecx + 0x59bfb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5881776) /* 0x59bfb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488c72  7c10                   -jl 0x488c84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488c84;
    }
    // 00488c74  8b91c0bf5900           -mov edx, dword ptr [ecx + 0x59bfc0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5881792) /* 0x59bfc0 */);
    // 00488c7a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488c7c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00488c7f  e80c0a0000             -call 0x489690
    cpu.esp -= 4;
    sub_489690(app, cpu);
    if (cpu.terminate) return;
L_0x00488c84:
    // 00488c84  43                     -inc ebx
    (cpu.ebx)++;
    // 00488c85  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00488c88  83fb10                 +cmp ebx, 0x10
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
    // 00488c8b  7cd5                   -jl 0x488c62
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488c62;
    }
    // 00488c8d  e83afcffff             -call 0x4888cc
    cpu.esp -= 4;
    sub_4888cc(app, cpu);
    if (cpu.terminate) return;
    // 00488c92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00488c93:
    // 00488c93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488c95:
    // 00488c95  c70574b64d0022560000   -mov dword ptr [0x4db674], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 22050 /*0x5622*/;
    // 00488c9f  ebb1                   -jmp 0x488c52
    goto L_0x00488c52;
L_0x00488ca1:
    // 00488ca1  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00488ca4  740c                   -je 0x488cb2
    if (cpu.flags.zf)
    {
        goto L_0x00488cb2;
    }
    // 00488ca6  c70574b64d00007d0000   -mov dword ptr [0x4db674], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 32000 /*0x7d00*/;
    // 00488cb0  eba0                   -jmp 0x488c52
    goto L_0x00488c52;
L_0x00488cb2:
    // 00488cb2  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 00488cb5  740c                   -je 0x488cc3
    if (cpu.flags.zf)
    {
        goto L_0x00488cc3;
    }
    // 00488cb7  c70574b64d0044ac0000   -mov dword ptr [0x4db674], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 44100 /*0xac44*/;
    // 00488cc1  eb8f                   -jmp 0x488c52
    goto L_0x00488c52;
L_0x00488cc3:
    // 00488cc3  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 00488cc6  740f                   -je 0x488cd7
    if (cpu.flags.zf)
    {
        goto L_0x00488cd7;
    }
    // 00488cc8  c70574b64d00112b0000   -mov dword ptr [0x4db674], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */) = 11025 /*0x2b11*/;
    // 00488cd2  e97bffffff             -jmp 0x488c52
    goto L_0x00488c52;
L_0x00488cd7:
    // 00488cd7  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00488cdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488cdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488ce0);
    // 00488ce0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488ce2  7409                   -je 0x488ced
    if (cpu.flags.zf)
    {
        goto L_0x00488ced;
    }
    // 00488ce4  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488ce7  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00488cec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488ced:
    // 00488ced  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00488cf0  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00488cf3  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00488cf8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488cfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488cfc);
    // 00488cfc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488cfd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488cfe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488cff  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00488d02  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00488d06  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00488d08  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00488d0c  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00488d10  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00488d12  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00488d15  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00488d17  888a55415600           -mov byte ptr [edx + 0x564155], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5652821) /* 0x564155 */) = cpu.cl;
    // 00488d1d  c6825641560001         -mov byte ptr [edx + 0x564156], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5652822) /* 0x564156 */) = 1 /*0x1*/;
    // 00488d24  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00488d26  66898a5a415600         -mov word ptr [edx + 0x56415a], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5652826) /* 0x56415a */) = cpu.cx;
    // 00488d2d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488d2f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488d31  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00488d33  81fa544d706c           +cmp edx, 0x6c704d54
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1819299156 /*0x6c704d54*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488d39  0f85fa000000           -jne 0x488e39
    if (!cpu.flags.zf)
    {
        goto L_0x00488e39;
    }
    // 00488d3f  80780400               +cmp byte ptr [eax + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488d43  0f85fe000000           -jne 0x488e47
    if (!cpu.flags.zf)
    {
        goto L_0x00488e47;
    }
    // 00488d49  80780510               +cmp byte ptr [eax + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488d4d  0f8502010000           -jne 0x488e55
    if (!cpu.flags.zf)
    {
        goto L_0x00488e55;
    }
    // 00488d53  80780601               +cmp byte ptr [eax + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488d57  0f85f8000000           -jne 0x488e55
    if (!cpu.flags.zf)
    {
        goto L_0x00488e55;
    }
    // 00488d5d  c744241c04000000       -mov dword ptr [esp + 0x1c], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 4 /*0x4*/;
L_0x00488d65:
    // 00488d65  837c241002             +cmp dword ptr [esp + 0x10], 2
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
    // 00488d6a  0f8530010000           -jne 0x488ea0
    if (!cpu.flags.zf)
    {
        goto L_0x00488ea0;
    }
    // 00488d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488d72  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00488d77  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00488d7b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00488d7f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00488d83:
    // 00488d83  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00488d85  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00488d88  668b560a               -mov dx, word ptr [esi + 0xa]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00488d8c  66899050415600         -mov word ptr [eax + 0x564150], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5652816) /* 0x564150 */) = cpu.dx;
    // 00488d93  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00488d96  889052415600           -mov byte ptr [eax + 0x564152], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5652818) /* 0x564152 */) = cpu.dl;
    // 00488d9c  8a5606                 -mov dl, byte ptr [esi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00488d9f  889053415600           -mov byte ptr [eax + 0x564153], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5652819) /* 0x564153 */) = cpu.dl;
    // 00488da5  8a5607                 -mov dl, byte ptr [esi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 00488da8  889054415600           -mov byte ptr [eax + 0x564154], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5652820) /* 0x564154 */) = cpu.dl;
    // 00488dae  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00488db2  89905c415600           -mov dword ptr [eax + 0x56415c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5652828) /* 0x56415c */) = cpu.edx;
    // 00488db8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488dba  8b1574b64d00           -mov edx, dword ptr [0x4db674]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */);
    // 00488dc0  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00488dc4  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488dc8  e853f00100             -call 0x4a7e20
    cpu.esp -= 4;
    sub_4a7e20(app, cpu);
    if (cpu.terminate) return;
    // 00488dcd  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00488dcf  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00488dd3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00488dd7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488ddb  e880f00100             -call 0x4a7e60
    cpu.esp -= 4;
    sub_4a7e60(app, cpu);
    if (cpu.terminate) return;
    // 00488de0  033d78b64d00           -add edi, dword ptr [0x4db678]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092984) /* 0x4db678 */)));
    // 00488de6  83ff64                 +cmp edi, 0x64
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488de9  0f8eef000000           -jle 0x488ede
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488ede;
    }
    // 00488def  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
L_0x00488df4:
    // 00488df4  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00488df8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488df9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488dfa  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00488dfe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488dff  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00488e03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488e04  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00488e08  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488e09  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00488e0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e0e  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00488e12  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00488e16  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e17  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00488e1a  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00488e1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488e1f  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00488e23  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488e25  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488e26  8a5e07                 -mov bl, byte ptr [esi + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 00488e29  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00488e2b  e81ce50100             -call 0x4a734c
    cpu.esp -= 4;
    sub_4a734c(app, cpu);
    if (cpu.terminate) return;
    // 00488e30  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00488e33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e36  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00488e39:
    // 00488e39  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00488e3e  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00488e41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e44  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00488e47:
    // 00488e47  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00488e4c  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00488e4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e52  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00488e55:
    // 00488e55  807e0510               +cmp byte ptr [esi + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488e59  7513                   -jne 0x488e6e
    if (!cpu.flags.zf)
    {
        goto L_0x00488e6e;
    }
    // 00488e5b  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488e5f  750d                   -jne 0x488e6e
    if (!cpu.flags.zf)
    {
        goto L_0x00488e6e;
    }
    // 00488e61  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
    // 00488e69  e9f7feffff             -jmp 0x488d65
    goto L_0x00488d65;
L_0x00488e6e:
    // 00488e6e  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488e72  7513                   -jne 0x488e87
    if (!cpu.flags.zf)
    {
        goto L_0x00488e87;
    }
    // 00488e74  807e0601               +cmp byte ptr [esi + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488e78  750d                   -jne 0x488e87
    if (!cpu.flags.zf)
    {
        goto L_0x00488e87;
    }
    // 00488e7a  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00488e82  e9defeffff             -jmp 0x488d65
    goto L_0x00488d65;
L_0x00488e87:
    // 00488e87  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488e8b  75ac                   -jne 0x488e39
    if (!cpu.flags.zf)
    {
        goto L_0x00488e39;
    }
    // 00488e8d  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488e91  75a6                   -jne 0x488e39
    if (!cpu.flags.zf)
    {
        goto L_0x00488e39;
    }
    // 00488e93  c744241c02000000       -mov dword ptr [esp + 0x1c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 00488e9b  e9c5feffff             -jmp 0x488d65
    goto L_0x00488d65;
L_0x00488ea0:
    // 00488ea0  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00488ea3  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00488ea7  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00488eaa  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00488eae  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00488eb1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00488eb5  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00488eb9  83faff                 +cmp edx, -1
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
    // 00488ebc  7d08                   -jge 0x488ec6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488ec6;
    }
    // 00488ebe  c7442418ffffffff       -mov dword ptr [esp + 0x18], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 4294967295 /*0xffffffff*/;
L_0x00488ec6:
    // 00488ec6  837c2420ff             +cmp dword ptr [esp + 0x20], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488ecb  0f8db2feffff           -jge 0x488d83
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488d83;
    }
    // 00488ed1  c7442420ffffffff       -mov dword ptr [esp + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 00488ed9  e9a5feffff             -jmp 0x488d83
    goto L_0x00488d83;
L_0x00488ede:
    // 00488ede  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488ee0  0f8d0effffff           -jge 0x488df4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488df4;
    }
    // 00488ee6  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00488ee8  e907ffffff             -jmp 0x488df4
    goto L_0x00488df4;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488f38);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00488f38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488f39  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488f3a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488f3b  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00488f3e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00488f40  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00488f44  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00488f48  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00488f4d  bd22560000             -mov ebp, 0x5622
    cpu.ebp = 22050 /*0x5622*/;
    // 00488f52  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00488f57  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488f59  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00488f5d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00488f61  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00488f65  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00488f69  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00488f6d  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00488f71  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00488f75  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00488f78  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488f7d  81c750415600           -add edi, 0x564150
    (cpu.edi) += x86::reg32(x86::sreg32(5652816 /*0x564150*/));
    // 00488f83  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488f85  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00488f89  c6470500               -mov byte ptr [edi + 5], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 00488f8d  8a542458               -mov dl, byte ptr [esp + 0x58]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00488f91  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00488f93  885706                 -mov byte ptr [edi + 6], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00488f96  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00488f9a  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00488f9e  6689570a               -mov word ptr [edi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 00488fa2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488fa4  754f                   -jne 0x488ff5
    if (!cpu.flags.zf)
    {
        goto L_0x00488ff5;
    }
L_0x00488fa6:
    // 00488fa6  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00488fa8  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488fab  0f840f010000           -je 0x4890c0
    if (cpu.flags.zf)
    {
        goto L_0x004890c0;
    }
    // 00488fb1  80fcfe                 +cmp ah, 0xfe
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488fb4  0f8406010000           -je 0x4890c0
    if (cpu.flags.zf)
    {
        goto L_0x004890c0;
    }
    // 00488fba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488fbc  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 00488fbe  46                     -inc esi
    (cpu.esi)++;
    // 00488fbf  81fbfc000000           +cmp ebx, 0xfc
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
    // 00488fc5  74df                   -je 0x488fa6
    if (cpu.flags.zf)
    {
        goto L_0x00488fa6;
    }
    // 00488fc7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488fc9  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 00488fcb  81f9ff000000           +cmp ecx, 0xff
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
    // 00488fd1  7512                   -jne 0x488fe5
    if (!cpu.flags.zf)
    {
        goto L_0x00488fe5;
    }
    // 00488fd3  46                     -inc esi
    (cpu.esi)++;
    // 00488fd4  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00488fd9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488fdb  e8b0ee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00488fe0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488fe2  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00488fe5:
    // 00488fe5  8d837fffffff           -lea eax, [ebx - 0x81]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-129) /* -0x81 */);
    // 00488feb  46                     -inc esi
    (cpu.esi)++;
    // 00488fec  83f811                 +cmp eax, 0x11
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488fef  7612                   -jbe 0x489003
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00489003;
    }
  [[fallthrough]];
  case 0x00488ff1:
    // 00488ff1  01ce                   +add esi, ecx
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
    // 00488ff3  ebb1                   -jmp 0x488fa6
    goto L_0x00488fa6;
L_0x00488ff5:
    // 00488ff5  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00488ffa  83c430                 +add esp, 0x30
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
    // 00488ffd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ffe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489000  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x00489003:
    // 00489003  ff2485f08e4800         -jmp dword ptr [eax*4 + 0x488ef0]
    cpu.ip = app->getMemory<x86::reg32>(4755184 + cpu.eax * 4); goto dynamic_jump;
  case 0x0048900a:
    // 0048900a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048900c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048900e  e87dee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489013  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00489017  01ce                   +add esi, ecx
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
    // 00489019  eb8b                   -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x0048901b:
    // 0048901b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0048901f  01ce                   +add esi, ecx
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
    // 00489021  eb83                   -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x00489023:
    // 00489023  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489025  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489027  e864ee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 0048902c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00489030  01ce                   +add esi, ecx
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
    // 00489032  e96fffffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x00489037:
    // 00489037  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489039  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048903b  e850ee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489040  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00489044  01ce                   +add esi, ecx
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
    // 00489046  e95bffffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x0048904b:
    // 0048904b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048904d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048904f  e83cee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489054  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00489058  01ce                   +add esi, ecx
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
    // 0048905a  e947ffffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x0048905f:
    // 0048905f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489061  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489063  e828ee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489068  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048906c  01ce                   +add esi, ecx
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
    // 0048906e  e933ffffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x00489073:
    // 00489073  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489075  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489077  e814ee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 0048907c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00489080  01ce                   +add esi, ecx
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
    // 00489082  e91fffffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x00489087:
    // 00489087  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489089  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048908b  e800ee0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489090  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00489094  01ce                   +add esi, ecx
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
    // 00489096  e90bffffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x0048909b:
    // 0048909b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048909d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048909f  e8eced0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004890a4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004890a6  01ce                   +add esi, ecx
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
    // 004890a8  e9f9feffff             -jmp 0x488fa6
    goto L_0x00488fa6;
  case 0x004890ad:
    // 004890ad  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004890af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004890b1  e8daed0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004890b6  884705                 -mov byte ptr [edi + 5], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 004890b9  01ce                   +add esi, ecx
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
    // 004890bb  e9e6feffff             -jmp 0x488fa6
    goto L_0x00488fa6;
L_0x004890c0:
    // 004890c0  837c241402             +cmp dword ptr [esp + 0x14], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004890c5  0f85e4000000           -jne 0x4891af
    if (!cpu.flags.zf)
    {
        goto L_0x004891af;
    }
    // 004890cb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004890cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004890d2  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004890d6  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004890da  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x004890de:
    // 004890de  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004890e2  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004890e5  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004890e9  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004890ec  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004890f0  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004890f3  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004890f7  884704                 -mov byte ptr [edi + 4], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004890fa  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004890fe  8a7705                 -mov dh, byte ptr [edi + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 00489101  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00489104  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00489106  0f85e2000000           -jne 0x4891ee
    if (!cpu.flags.zf)
    {
        goto L_0x004891ee;
    }
    // 0048910c  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489111  0f84bf000000           -je 0x4891d6
    if (cpu.flags.zf)
    {
        goto L_0x004891d6;
    }
    // 00489117  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048911b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048911d  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00489121  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00489125  e836ed0100             -call 0x4a7e60
    cpu.esp -= 4;
    sub_4a7e60(app, cpu);
    if (cpu.terminate) return;
L_0x0048912a:
    // 0048912a  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048912f  0f851d010000           -jne 0x489252
    if (!cpu.flags.zf)
    {
        goto L_0x00489252;
    }
    // 00489135  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048913a  0f8512010000           -jne 0x489252
    if (!cpu.flags.zf)
    {
        goto L_0x00489252;
    }
    // 00489140  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
L_0x00489145:
    // 00489145  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00489149  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048914d  8b1574b64d00           -mov edx, dword ptr [0x4db674]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */);
    // 00489153  e8c8ec0100             -call 0x4a7e20
    cpu.esp -= 4;
    sub_4a7e20(app, cpu);
    if (cpu.terminate) return;
    // 00489158  032d78b64d00           -add ebp, dword ptr [0x4db678]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5092984) /* 0x4db678 */)));
    // 0048915e  83fd64                 +cmp ebp, 0x64
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489161  0f8e39010000           -jle 0x4892a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004892a0;
    }
    // 00489167  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
L_0x0048916c:
    // 0048916c  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00489170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489171  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489172  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489173  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00489177  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489178  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048917c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048917d  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00489181  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489182  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00489186  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489187  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048918b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048918f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489190  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00489192  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00489194  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00489198  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489199  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048919d  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004891a1  e8a6e10100             -call 0x4a734c
    cpu.esp -= 4;
    sub_4a734c(app, cpu);
    if (cpu.terminate) return;
    // 004891a6  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004891a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891ac  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x004891af:
    // 004891af  837c2424ff             +cmp dword ptr [esp + 0x24], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004891b4  7d08                   -jge 0x4891be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004891be;
    }
    // 004891b6  c7442424ffffffff       -mov dword ptr [esp + 0x24], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 4294967295 /*0xffffffff*/;
L_0x004891be:
    // 004891be  837c2428ff             +cmp dword ptr [esp + 0x28], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004891c3  0f8d15ffffff           -jge 0x4890de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004890de;
    }
    // 004891c9  c7442428ffffffff       -mov dword ptr [esp + 0x28], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 4294967295 /*0xffffffff*/;
    // 004891d1  e908ffffff             -jmp 0x4890de
    goto L_0x004890de;
L_0x004891d6:
    // 004891d6  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004891da  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004891dc  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004891e0  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004891e4  e847f80100             -call 0x4a8a30
    cpu.esp -= 4;
    sub_4a8a30(app, cpu);
    if (cpu.terminate) return;
    // 004891e9  e93cffffff             -jmp 0x48912a
    goto L_0x0048912a;
L_0x004891ee:
    // 004891ee  80fe01                 +cmp dh, 1
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004891f1  0f85fefdffff           -jne 0x488ff5
    if (!cpu.flags.zf)
    {
        goto L_0x00488ff5;
    }
    // 004891f7  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004891fc  0f85f3fdffff           -jne 0x488ff5
    if (!cpu.flags.zf)
    {
        goto L_0x00488ff5;
    }
    // 00489202  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489207  7414                   -je 0x48921d
    if (cpu.flags.zf)
    {
        goto L_0x0048921d;
    }
    // 00489209  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048920d  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489210  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489212  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00489216  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 00489219  89742450               -mov dword ptr [esp + 0x50], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.esi;
L_0x0048921d:
    // 0048921d  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 00489220  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00489223  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489224  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 00489227  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048922b  c1f818                 +sar eax, 0x18
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
    // 0048922e  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489232  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489233  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00489237  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0048923b  e820f80100             -call 0x4a8a60
    cpu.esp -= 4;
    sub_4a8a60(app, cpu);
    if (cpu.terminate) return;
    // 00489240  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00489243  884708                 -mov byte ptr [edi + 8], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00489246  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048924a  884709                 -mov byte ptr [edi + 9], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0048924d  e9d8feffff             -jmp 0x48912a
    goto L_0x0048912a;
L_0x00489252:
    // 00489252  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489257  7511                   -jne 0x48926a
    if (!cpu.flags.zf)
    {
        goto L_0x0048926a;
    }
    // 00489259  837c240c02             +cmp dword ptr [esp + 0xc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048925e  750a                   -jne 0x48926a
    if (!cpu.flags.zf)
    {
        goto L_0x0048926a;
    }
    // 00489260  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00489265  e9dbfeffff             -jmp 0x489145
    goto L_0x00489145;
L_0x0048926a:
    // 0048926a  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048926f  7510                   -jne 0x489281
    if (!cpu.flags.zf)
    {
        goto L_0x00489281;
    }
    // 00489271  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489275  83ff01                 +cmp edi, 1
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
    // 00489278  7507                   -jne 0x489281
    if (!cpu.flags.zf)
    {
        goto L_0x00489281;
    }
    // 0048927a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0048927c  e9c4feffff             -jmp 0x489145
    goto L_0x00489145;
L_0x00489281:
    // 00489281  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489286  0f8569fdffff           -jne 0x488ff5
    if (!cpu.flags.zf)
    {
        goto L_0x00488ff5;
    }
    // 0048928c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489290  83fa02                 +cmp edx, 2
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
    // 00489293  0f855cfdffff           -jne 0x488ff5
    if (!cpu.flags.zf)
    {
        goto L_0x00488ff5;
    }
    // 00489299  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048929b  e9a5feffff             -jmp 0x489145
    goto L_0x00489145;
L_0x004892a0:
    // 004892a0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004892a2  0f8dc4feffff           -jge 0x48916c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048916c;
    }
    // 004892a8  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004892aa  e9bdfeffff             -jmp 0x48916c
    goto L_0x0048916c;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_4892b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004892b0);
    // 004892b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004892b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004892b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004892b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004892b4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004892b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004892b9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004892bd  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004892c2  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004892c4  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004892c6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004892c8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004892cb  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892ce  7418                   -je 0x4892e8
    if (cpu.flags.zf)
    {
        goto L_0x004892e8;
    }
L_0x004892d0:
    // 004892d0  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004892d2  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892d5  7411                   -je 0x4892e8
    if (cpu.flags.zf)
    {
        goto L_0x004892e8;
    }
    // 004892d7  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 004892da  41                     -inc ecx
    (cpu.ecx)++;
    // 004892db  81fefc000000           +cmp esi, 0xfc
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
    // 004892e1  751a                   -jne 0x4892fd
    if (!cpu.flags.zf)
    {
        goto L_0x004892fd;
    }
L_0x004892e3:
    // 004892e3  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892e6  75e8                   -jne 0x4892d0
    if (!cpu.flags.zf)
    {
        goto L_0x004892d0;
    }
L_0x004892e8:
    // 004892e8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004892ec  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004892ee  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004892f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004892f4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004892f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892fb  90                     -nop 
    ;
    // 004892fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004892fd:
    // 004892fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004892ff  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00489301  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489307  7512                   -jne 0x48931b
    if (!cpu.flags.zf)
    {
        goto L_0x0048931b;
    }
    // 00489309  41                     -inc ecx
    (cpu.ecx)++;
    // 0048930a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048930f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489311  e87aeb0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489316  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489318  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0048931b:
    // 0048931b  41                     -inc ecx
    (cpu.ecx)++;
    // 0048931c  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489322  7c13                   -jl 0x489337
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489337;
    }
    // 00489324  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048932a  750f                   -jne 0x48933b
    if (!cpu.flags.zf)
    {
        goto L_0x0048933b;
    }
    // 0048932c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048932e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489330  e85beb0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489335  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00489337:
    // 00489337  01d9                   +add ecx, ebx
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
    // 00489339  eba8                   -jmp 0x4892e3
    goto L_0x004892e3;
L_0x0048933b:
    // 0048933b  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489341  75f4                   -jne 0x489337
    if (!cpu.flags.zf)
    {
        goto L_0x00489337;
    }
    // 00489343  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00489345  01d9                   +add ecx, ebx
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
    // 00489347  eb9a                   -jmp 0x4892e3
    goto L_0x004892e3;
}

/* align: skip  */
void Application::sub_4892fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004892fc);
    goto L_entry_0x004892fc;
    // 004892b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004892b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004892b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004892b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004892b4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004892b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004892b9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004892bd  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004892c2  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004892c4  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004892c6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004892c8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004892cb  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892ce  7418                   -je 0x4892e8
    if (cpu.flags.zf)
    {
        goto L_0x004892e8;
    }
L_0x004892d0:
    // 004892d0  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004892d2  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892d5  7411                   -je 0x4892e8
    if (cpu.flags.zf)
    {
        goto L_0x004892e8;
    }
    // 004892d7  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 004892da  41                     -inc ecx
    (cpu.ecx)++;
    // 004892db  81fefc000000           +cmp esi, 0xfc
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
    // 004892e1  751a                   -jne 0x4892fd
    if (!cpu.flags.zf)
    {
        goto L_0x004892fd;
    }
L_0x004892e3:
    // 004892e3  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892e6  75e8                   -jne 0x4892d0
    if (!cpu.flags.zf)
    {
        goto L_0x004892d0;
    }
L_0x004892e8:
    // 004892e8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004892ec  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004892ee  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004892f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004892f4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004892f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892fb  90                     -nop 
    ;
L_entry_0x004892fc:
    // 004892fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004892fd:
    // 004892fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004892ff  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00489301  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489307  7512                   -jne 0x48931b
    if (!cpu.flags.zf)
    {
        goto L_0x0048931b;
    }
    // 00489309  41                     -inc ecx
    (cpu.ecx)++;
    // 0048930a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048930f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489311  e87aeb0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489316  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489318  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0048931b:
    // 0048931b  41                     -inc ecx
    (cpu.ecx)++;
    // 0048931c  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489322  7c13                   -jl 0x489337
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489337;
    }
    // 00489324  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048932a  750f                   -jne 0x48933b
    if (!cpu.flags.zf)
    {
        goto L_0x0048933b;
    }
    // 0048932c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048932e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489330  e85beb0100             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 00489335  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00489337:
    // 00489337  01d9                   +add ecx, ebx
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
    // 00489339  eba8                   -jmp 0x4892e3
    goto L_0x004892e3;
L_0x0048933b:
    // 0048933b  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489341  75f4                   -jne 0x489337
    if (!cpu.flags.zf)
    {
        goto L_0x00489337;
    }
    // 00489343  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00489345  01d9                   +add ecx, ebx
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
    // 00489347  eb9a                   -jmp 0x4892e3
    goto L_0x004892e3;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48934c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048934c);
    // 0048934c  e95fe50100             -jmp 0x4a78b0
    return sub_4a78b0(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489354(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489354);
    // 00489354  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489355  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489356  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489357  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489358  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048935b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048935d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048935f  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00489361  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00489363  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00489366  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00489368  889656415600           -mov byte ptr [esi + 0x564156], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5652822) /* 0x564156 */) = cpu.dl;
    // 0048936e  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00489375  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489377  8a9e55415600           -mov bl, byte ptr [esi + 0x564155]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5652821) /* 0x564155 */);
    // 0048937d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00489380  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00489382  745c                   -je 0x4893e0
    if (cpu.flags.zf)
    {
        goto L_0x004893e0;
    }
    // 00489384  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489387  756d                   -jne 0x4893f6
    if (!cpu.flags.zf)
    {
        goto L_0x004893f6;
    }
    // 00489389  8b8e56415600           -mov ecx, dword ptr [esi + 0x564156]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5652822) /* 0x564156 */);
    // 0048938f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00489391  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00489394  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489397  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489398  8b8e55415600           -mov ecx, dword ptr [esi + 0x564155]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5652821) /* 0x564155 */);
    // 0048939e  8b92debf5900           -mov edx, dword ptr [edx + 0x59bfde]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5881822) /* 0x59bfde */);
    // 004893a4  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004893a7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004893aa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004893ab  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004893ae  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004893b2  e8a9f60100             -call 0x4a8a60
    cpu.esp -= 4;
    sub_4a8a60(app, cpu);
    if (cpu.terminate) return;
    // 004893b7  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004893ba  888658415600           -mov byte ptr [esi + 0x564158], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5652824) /* 0x564158 */) = cpu.al;
    // 004893c0  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004893c4  888659415600           -mov byte ptr [esi + 0x564159], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5652825) /* 0x564159 */) = cpu.al;
L_0x004893ca:
    // 004893ca  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004893ce  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004893d1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004893d3  e878e40100             -call 0x4a7850
    cpu.esp -= 4;
    sub_4a7850(app, cpu);
    if (cpu.terminate) return;
    // 004893d8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004893db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004893e0:
    // 004893e0  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004893e4  8b92debf5900           -mov edx, dword ptr [edx + 0x59bfde]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5881822) /* 0x59bfde */);
    // 004893ea  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004893ec  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004893ef  e86cea0100             -call 0x4a7e60
    cpu.esp -= 4;
    sub_4a7e60(app, cpu);
    if (cpu.terminate) return;
    // 004893f4  ebd4                   -jmp 0x4893ca
    goto L_0x004893ca;
L_0x004893f6:
    // 004893f6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004893fb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004893fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489400  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489401  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489402  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489404);
    // 00489404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489405  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489406  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489407  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489408  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048940b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048940d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048940f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489411  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00489414  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489417  81c650415600           -add esi, 0x564150
    (cpu.esi) += x86::reg32(x86::sreg32(5652816 /*0x564150*/));
    // 0048941d  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048941f  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 00489423  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00489426  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00489429  c6460600               -mov byte ptr [esi + 6], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0048942d  80fa01                 +cmp dl, 1
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
    // 00489430  7430                   -je 0x489462
    if (cpu.flags.zf)
    {
        goto L_0x00489462;
    }
    // 00489432  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00489434  7561                   -jne 0x489497
    if (!cpu.flags.zf)
    {
        goto L_0x00489497;
    }
    // 00489436  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048943a  8b90debf5900           -mov edx, dword ptr [eax + 0x59bfde]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881822) /* 0x59bfde */);
    // 00489440  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00489442  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00489445  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00489447  e8e4f50100             -call 0x4a8a30
    cpu.esp -= 4;
    sub_4a8a30(app, cpu);
    if (cpu.terminate) return;
L_0x0048944c:
    // 0048944c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489450  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00489453  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489455  e8f6e30100             -call 0x4a7850
    cpu.esp -= 4;
    sub_4a7850(app, cpu);
    if (cpu.terminate) return;
    // 0048945a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048945d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048945e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048945f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489460  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489461  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489462:
    // 00489462  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00489465  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00489468  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489469  8b5605                 -mov edx, dword ptr [esi + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 0048946c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048946f  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489473  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489474  8b90debf5900           -mov edx, dword ptr [eax + 0x59bfde]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881822) /* 0x59bfde */);
    // 0048947a  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048947e  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00489481  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00489483  e8d8f50100             -call 0x4a8a60
    cpu.esp -= 4;
    sub_4a8a60(app, cpu);
    if (cpu.terminate) return;
    // 00489488  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048948b  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0048948e  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489492  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 00489495  ebb5                   -jmp 0x48944c
    goto L_0x0048944c;
L_0x00489497:
    // 00489497  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048949c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048949f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4894a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004894a4);
    // 004894a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004894a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004894a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004894a7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004894a8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004894ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004894ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004894af  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004894b2  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004894b5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004894b7  8a9955415600           -mov bl, byte ptr [ecx + 0x564155]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5652821) /* 0x564155 */);
    // 004894bd  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004894c0  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004894c2  7549                   -jne 0x48950d
    if (!cpu.flags.zf)
    {
        goto L_0x0048950d;
    }
    // 004894c4  80b95641560000         +cmp byte ptr [ecx + 0x564156], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5652822) /* 0x564156 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004894cb  742a                   -je 0x4894f7
    if (cpu.flags.zf)
    {
        goto L_0x004894f7;
    }
    // 004894cd  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004894d1  8b80bcbf5900           -mov eax, dword ptr [eax + 0x59bfbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */);
    // 004894d7  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004894d9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004894dc  e87fe90100             -call 0x4a7e60
    cpu.esp -= 4;
    sub_4a7e60(app, cpu);
    if (cpu.terminate) return;
L_0x004894e1:
    // 004894e1  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004894e5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004894e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004894ea  e861e30100             -call 0x4a7850
    cpu.esp -= 4;
    sub_4a7850(app, cpu);
    if (cpu.terminate) return;
    // 004894ef  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004894f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004894f7:
    // 004894f7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004894f9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004894fb  668b815a415600         -mov ax, word ptr [ecx + 0x56415a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5652826) /* 0x56415a */);
    // 00489502  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489506  e825f50100             -call 0x4a8a30
    cpu.esp -= 4;
    sub_4a8a30(app, cpu);
    if (cpu.terminate) return;
    // 0048950b  ebd4                   -jmp 0x4894e1
    goto L_0x004894e1;
L_0x0048950d:
    // 0048950d  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489510  755b                   -jne 0x48956d
    if (!cpu.flags.zf)
    {
        goto L_0x0048956d;
    }
    // 00489512  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489513  80b95641560000         +cmp byte ptr [ecx + 0x564156], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5652822) /* 0x564156 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048951a  740f                   -je 0x48952b
    if (cpu.flags.zf)
    {
        goto L_0x0048952b;
    }
    // 0048951c  8bb8bcbf5900           -mov edi, dword ptr [eax + 0x59bfbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881788) /* 0x59bfbc */);
    // 00489522  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00489525  83ef40                 -sub edi, 0x40
    (cpu.edi) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489528  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
L_0x0048952b:
    // 0048952b  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0048952d  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 00489530  8b8556415600           -mov eax, dword ptr [ebp + 0x564156]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5652822) /* 0x564156 */);
    // 00489536  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00489539  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048953a  8b8555415600           -mov eax, dword ptr [ebp + 0x564155]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5652821) /* 0x564155 */);
    // 00489540  c1f818                 +sar eax, 0x18
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
    // 00489543  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489547  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489548  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048954c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048954e  e80df50100             -call 0x4a8a60
    cpu.esp -= 4;
    sub_4a8a60(app, cpu);
    if (cpu.terminate) return;
    // 00489553  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489557  888558415600           -mov byte ptr [ebp + 0x564158], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5652824) /* 0x564158 */) = cpu.al;
    // 0048955d  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489561  888559415600           -mov byte ptr [ebp + 0x564159], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5652825) /* 0x564159 */) = cpu.al;
    // 00489567  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489568  e974ffffff             -jmp 0x4894e1
    goto L_0x004894e1;
L_0x0048956d:
    // 0048956d  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00489572  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489575  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489576  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489577  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489578  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489579  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48957c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048957c);
    // 0048957c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048957d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048957e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489580  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00489583  8a9a55415600           -mov bl, byte ptr [edx + 0x564155]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5652821) /* 0x564155 */);
    // 00489589  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0048958b  740d                   -je 0x48959a
    if (cpu.flags.zf)
    {
        goto L_0x0048959a;
    }
    // 0048958d  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489590  7408                   -je 0x48959a
    if (cpu.flags.zf)
    {
        goto L_0x0048959a;
    }
    // 00489592  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00489597  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489598  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489599  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048959a:
    // 0048959a  e8b9e10100             -call 0x4a7758
    cpu.esp -= 4;
    sub_4a7758(app, cpu);
    if (cpu.terminate) return;
    // 0048959f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004895a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004895a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4895a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004895a4);
    // 004895a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004895a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004895a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004895a7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004895a9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004895ac  8a9055415600           -mov dl, byte ptr [eax + 0x564155]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5652821) /* 0x564155 */);
    // 004895b2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004895b4  740e                   -je 0x4895c4
    if (cpu.flags.zf)
    {
        goto L_0x004895c4;
    }
    // 004895b6  80fa01                 +cmp dl, 1
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
    // 004895b9  7409                   -je 0x4895c4
    if (cpu.flags.zf)
    {
        goto L_0x004895c4;
    }
    // 004895bb  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x004895c0:
    // 004895c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004895c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004895c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004895c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004895c4:
    // 004895c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004895c6  e811e30100             -call 0x4a78dc
    cpu.esp -= 4;
    sub_4a78dc(app, cpu);
    if (cpu.terminate) return;
    // 004895cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004895cd  7cf1                   -jl 0x4895c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004895c0;
    }
    // 004895cf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004895d1  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004895d4  8b9a5c415600           -mov ebx, dword ptr [edx + 0x56415c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5652828) /* 0x56415c */);
    // 004895da  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004895dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004895de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004895e0  7cde                   -jl 0x4895c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004895c0;
    }
    // 004895e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004895e4  668b9a50415600         -mov bx, word ptr [edx + 0x564150]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5652816) /* 0x564150 */);
    // 004895eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004895ed  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004895f0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004895f2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004895f5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004895f7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004895fa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004895fc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004895ff  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489601  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489603  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048960a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048960c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048960f  6683b8c2bf590000       +cmp word ptr [eax + 0x59bfc2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5881794) /* 0x59bfc2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00489617  7c2b                   -jl 0x489644
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489644;
    }
    // 00489619  8b88c0bf5900           -mov ecx, dword ptr [eax + 0x59bfc0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881792) /* 0x59bfc0 */);
    // 0048961f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489621  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489624  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489626  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00489629  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048962b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0048962e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489630  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00489633  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489635  81c1b0040000           -add ecx, 0x4b0
    (cpu.ecx) += x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 0048963b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048963e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489640  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489641  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489642  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489643  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489644:
    // 00489644  8b80c0bf5900           -mov eax, dword ptr [eax + 0x59bfc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881792) /* 0x59bfc0 */);
    // 0048964a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048964d  2db0040000             -sub eax, 0x4b0
    (cpu.eax) -= x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 00489652  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00489655  b950fbffff             -mov ecx, 0xfffffb50
    cpu.ecx = 4294966096 /*0xfffffb50*/;
    // 0048965a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048965c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048965f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489661  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489662  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489663  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489668);
    // 00489668  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489669  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048966a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048966c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0048966f  8a9a55415600           -mov bl, byte ptr [edx + 0x564155]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5652821) /* 0x564155 */);
    // 00489675  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00489677  740d                   -je 0x489686
    if (cpu.flags.zf)
    {
        goto L_0x00489686;
    }
    // 00489679  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048967c  7408                   -je 0x489686
    if (cpu.flags.zf)
    {
        goto L_0x00489686;
    }
    // 0048967e  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00489683  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489684  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489685  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489686:
    // 00489686  e851e20100             -call 0x4a78dc
    cpu.esp -= 4;
    sub_4a78dc(app, cpu);
    if (cpu.terminate) return;
    // 0048968b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048968c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048968d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489690);
    // 00489690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489692  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489694  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00489697  8a9855415600           -mov bl, byte ptr [eax + 0x564155]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5652821) /* 0x564155 */);
    // 0048969d  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0048969f  740d                   -je 0x4896ae
    if (cpu.flags.zf)
    {
        goto L_0x004896ae;
    }
    // 004896a1  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004896a4  7408                   -je 0x4896ae
    if (cpu.flags.zf)
    {
        goto L_0x004896ae;
    }
    // 004896a6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004896ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004896ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004896ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004896ae:
    // 004896ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004896af  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004896b1  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004896b4  a174b64d00             -mov eax, dword ptr [0x4db674]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092980) /* 0x4db674 */);
    // 004896b9  668bb650415600         -mov si, word ptr [esi + 0x564150]
    cpu.si = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5652816) /* 0x564150 */);
    // 004896c0  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004896c6  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004896c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004896ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004896cc  e84fe70100             -call 0x4a7e20
    cpu.esp -= 4;
    sub_4a7e20(app, cpu);
    if (cpu.terminate) return;
    // 004896d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004896d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004896d5  e8dee00100             -call 0x4a77b8
    cpu.esp -= 4;
    sub_4a77b8(app, cpu);
    if (cpu.terminate) return;
    // 004896da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004896db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004896dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004896dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4896e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004896e0);
    // 004896e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004896e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004896e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004896e3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004896e5  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004896e8  81c350415600           -add ebx, 0x564150
    (cpu.ebx) += x86::reg32(x86::sreg32(5652816 /*0x564150*/));
    // 004896ee  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004896f1  807b0407               +cmp byte ptr [ebx + 4], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004896f5  7461                   -je 0x489758
    if (cpu.flags.zf)
    {
        goto L_0x00489758;
    }
    // 004896f7  807b0409               +cmp byte ptr [ebx + 4], 9
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004896fb  7457                   -je 0x489754
    if (cpu.flags.zf)
    {
        goto L_0x00489754;
    }
    // 004896fd  807b0408               +cmp byte ptr [ebx + 4], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489701  7451                   -je 0x489754
    if (cpu.flags.zf)
    {
        goto L_0x00489754;
    }
    // 00489703  807b0402               +cmp byte ptr [ebx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489707  0f85a2000000           -jne 0x4897af
    if (!cpu.flags.zf)
    {
        goto L_0x004897af;
    }
    // 0048970d  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 00489712  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00489718  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048971e  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00489724  8a4303                 -mov al, byte ptr [ebx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00489727  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00489729  3c01                   +cmp al, 1
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
    // 0048972b  7515                   -jne 0x489742
    if (!cpu.flags.zf)
    {
        goto L_0x00489742;
    }
    // 0048972d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00489732  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489734  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489736  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489739  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048973b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048973d  7401                   -je 0x489740
    if (cpu.flags.zf)
    {
        goto L_0x00489740;
    }
    // 0048973f  41                     -inc ecx
    (cpu.ecx)++;
L_0x00489740:
    // 00489740  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
L_0x00489742:
    // 00489742  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489744  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489746  7e0c                   -jle 0x489754
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489754;
    }
    // 00489748  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0048974a:
    // 0048974a  40                     -inc eax
    (cpu.eax)++;
    // 0048974b  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0048974e  42                     -inc edx
    (cpu.edx)++;
    // 0048974f  39c8                   +cmp eax, ecx
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
    // 00489751  7cf7                   -jl 0x48974a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048974a;
    }
    // 00489753  90                     -nop 
    ;
L_0x00489754:
    // 00489754  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489755  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489756  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489757  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489758:
    // 00489758  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0048975d  be1c000000             -mov esi, 0x1c
    cpu.esi = 28 /*0x1c*/;
    // 00489762  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00489768  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048976a  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00489770  83c11b                 -add ecx, 0x1b
    (cpu.ecx) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00489773  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00489779  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048977b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048977d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489780  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489782  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00489789  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048978b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048978d  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00489790  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00489792  807b0302               +cmp byte ptr [ebx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489796  7502                   -jne 0x48979a
    if (!cpu.flags.zf)
    {
        goto L_0x0048979a;
    }
    // 00489798  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048979a:
    // 0048979a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048979c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048979e  7eb4                   -jle 0x489754
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489754;
    }
    // 004897a0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004897a2:
    // 004897a2  40                     -inc eax
    (cpu.eax)++;
    // 004897a3  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004897a6  42                     -inc edx
    (cpu.edx)++;
    // 004897a7  39c8                   +cmp eax, ecx
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
    // 004897a9  7cf7                   -jl 0x4897a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004897a2;
    }
    // 004897ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004897af:
    // 004897af  807b0400               +cmp byte ptr [ebx + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004897b3  759f                   -jne 0x489754
    if (!cpu.flags.zf)
    {
        goto L_0x00489754;
    }
    // 004897b5  807b0302               +cmp byte ptr [ebx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004897b9  7502                   -jne 0x4897bd
    if (!cpu.flags.zf)
    {
        goto L_0x004897bd;
    }
    // 004897bb  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004897bd:
    // 004897bd  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004897c0  80fa10                 +cmp dl, 0x10
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
    // 004897c3  7517                   -jne 0x4897dc
    if (!cpu.flags.zf)
    {
        goto L_0x004897dc;
    }
    // 004897c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004897c7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004897c9  7e89                   -jle 0x489754
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489754;
    }
L_0x004897cb:
    // 004897cb  42                     -inc edx
    (cpu.edx)++;
    // 004897cc  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 004897d1  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004897d4  39ca                   +cmp edx, ecx
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
    // 004897d6  7cf3                   -jl 0x4897cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004897cb;
    }
    // 004897d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004897dc:
    // 004897dc  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004897df  0f856fffffff           -jne 0x489754
    if (!cpu.flags.zf)
    {
        goto L_0x00489754;
    }
    // 004897e5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004897e7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004897e9  0f8e65ffffff           -jle 0x489754
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489754;
    }
L_0x004897ef:
    // 004897ef  42                     -inc edx
    (cpu.edx)++;
    // 004897f0  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004897f3  40                     -inc eax
    (cpu.eax)++;
    // 004897f4  39ca                   +cmp edx, ecx
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
    // 004897f6  7cf7                   -jl 0x4897ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004897ef;
    }
    // 004897f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_489800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489800);
    // 00489800  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489807  740f                   -je 0x489818
    if (cpu.flags.zf)
    {
        goto L_0x00489818;
    }
    // 00489809  83f87f                 +cmp eax, 0x7f
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
    // 0048980c  7f04                   -jg 0x489812
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489812;
    }
    // 0048980e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489810  7d0c                   -jge 0x48981e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048981e;
    }
L_0x00489812:
    // 00489812  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00489817  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489818:
    // 00489818  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048981d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048981e:
    // 0048981e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048981f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489820  a2dece4d00             -mov byte ptr [0x4dcede], al
    app->getMemory<x86::reg8>(x86::reg32(5099230) /* 0x4dcede */) = cpu.al;
    // 00489825  8b0d6cce4d00           -mov ecx, dword ptr [0x4dce6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 0048982b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048982d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048982f  e868010000             -call 0x48999c
    cpu.esp -= 4;
    sub_48999c(app, cpu);
    if (cpu.terminate) return;
    // 00489834  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489836  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489837  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489838  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489840);
    // 00489840  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489841  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489842  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489844  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 0048984a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048984c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048984e  750a                   -jne 0x48985a
    if (!cpu.flags.zf)
    {
        goto L_0x0048985a;
    }
    // 00489850  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00489855  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489857  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489859  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048985a:
    // 0048985a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048985b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048985c  e8ffba0100             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00489861  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489863  e804bf0100             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 00489868  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048986a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048986c  7c56                   -jl 0x4898c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004898c4;
    }
    // 0048986e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489871  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489873  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00489876  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489878  8a98ebbf5900           -mov bl, byte ptr [eax + 0x59bfeb]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5881835) /* 0x59bfeb */);
    // 0048987e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489880  7439                   -je 0x4898bb
    if (cpu.flags.zf)
    {
        goto L_0x004898bb;
    }
    // 00489882  b9b0bf5900             -mov ecx, 0x59bfb0
    cpu.ecx = 5881776 /*0x59bfb0*/;
    // 00489887  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00489889:
    // 00489889  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048988b  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0048988e  39d8                   +cmp eax, ebx
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
    // 00489890  7512                   -jne 0x4898a4
    if (!cpu.flags.zf)
    {
        goto L_0x004898a4;
    }
    // 00489892  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 00489896  750c                   -jne 0x4898a4
    if (!cpu.flags.zf)
    {
        goto L_0x004898a4;
    }
    // 00489898  833900                 +cmp dword ptr [ecx], 0
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
    // 0048989b  7c07                   -jl 0x4898a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004898a4;
    }
    // 0048989d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048989f  e8d8fcffff             -call 0x48957c
    cpu.esp -= 4;
    sub_48957c(app, cpu);
    if (cpu.terminate) return;
L_0x004898a4:
    // 004898a4  42                     -inc edx
    (cpu.edx)++;
    // 004898a5  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004898a8  83fa10                 +cmp edx, 0x10
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
    // 004898ab  7cdc                   -jl 0x489889
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489889;
    }
L_0x004898ad:
    // 004898ad  e8c2ba0100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004898b2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004898b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004898b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004898bb:
    // 004898bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004898bd  e8bafcffff             -call 0x48957c
    cpu.esp -= 4;
    sub_48957c(app, cpu);
    if (cpu.terminate) return;
    // 004898c2  ebe9                   -jmp 0x4898ad
    goto L_0x004898ad;
L_0x004898c4:
    // 004898c4  bef8ffffff             -mov esi, 0xfffffff8
    cpu.esi = 4294967288 /*0xfffffff8*/;
    // 004898c9  e8a6ba0100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004898ce  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004898d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004898d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4898e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004898e0);
    // 004898e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004898e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004898e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004898e3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004898e5  e882be0100             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 004898ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004898ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004898ee  0f8c75000000           -jl 0x489969
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489969;
    }
    // 004898f4  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004898fb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004898fd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00489900  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489902  81c2b0bf5900           -add edx, 0x59bfb0
    (cpu.edx) += x86::reg32(x86::sreg32(5881776 /*0x59bfb0*/));
    // 00489908  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048990b  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048990e  39d8                   +cmp eax, ebx
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
    // 00489910  7460                   -je 0x489972
    if (cpu.flags.zf)
    {
        goto L_0x00489972;
    }
    // 00489912  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489913  0fb67a3b               -movzx edi, byte ptr [edx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 00489917  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489919  745d                   -je 0x489978
    if (cpu.flags.zf)
    {
        goto L_0x00489978;
    }
    // 0048991b  b9b0bf5900             -mov ecx, 0x59bfb0
    cpu.ecx = 5881776 /*0x59bfb0*/;
    // 00489920  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00489922:
    // 00489922  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489924  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 00489927  39fa                   +cmp edx, edi
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
    // 00489929  752e                   -jne 0x489959
    if (!cpu.flags.zf)
    {
        goto L_0x00489959;
    }
    // 0048992b  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0048992f  7528                   -jne 0x489959
    if (!cpu.flags.zf)
    {
        goto L_0x00489959;
    }
    // 00489931  833900                 +cmp dword ptr [ecx], 0
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
    // 00489934  7c23                   -jl 0x489959
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489959;
    }
    // 00489936  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489938  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048993b  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048993e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489940  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00489947  e8a4f20100             -call 0x4a8bf0
    cpu.esp -= 4;
    sub_4a8bf0(app, cpu);
    if (cpu.terminate) return;
    // 0048994c  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 0048994f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489951  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00489954  e84bfbffff             -call 0x4894a4
    cpu.esp -= 4;
    sub_4894a4(app, cpu);
    if (cpu.terminate) return;
L_0x00489959:
    // 00489959  43                     -inc ebx
    (cpu.ebx)++;
    // 0048995a  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048995d  83fb10                 +cmp ebx, 0x10
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
    // 00489960  7cc0                   -jl 0x489922
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489922;
    }
    // 00489962  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489964  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489965  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489967  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489968  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489969:
    // 00489969  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048996e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048996f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489970  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489971  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489972:
    // 00489972  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489974  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489975  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489976  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489977  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489978:
    // 00489978  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048997b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048997d  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00489980  e86bf20100             -call 0x4a8bf0
    cpu.esp -= 4;
    sub_4a8bf0(app, cpu);
    if (cpu.terminate) return;
    // 00489985  8b522e                 -mov edx, dword ptr [edx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 00489988  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048998a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048998d  e812fbffff             -call 0x4894a4
    cpu.esp -= 4;
    sub_4894a4(app, cpu);
    if (cpu.terminate) return;
    // 00489992  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489994  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489995  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489996  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489997  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489998  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48999c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048999c);
    // 0048999c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048999d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048999f  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004899a6  7410                   -je 0x4899b8
    if (cpu.flags.zf)
    {
        goto L_0x004899b8;
    }
    // 004899a8  83fa7f                 +cmp edx, 0x7f
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
    // 004899ab  7f04                   -jg 0x4899b1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004899b1;
    }
    // 004899ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004899af  7d0e                   -jge 0x4899bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004899bf;
    }
L_0x004899b1:
    // 004899b1  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004899b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004899b8:
    // 004899b8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004899bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004899bf:
    // 004899bf  e89cb90100             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004899c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004899c6  e815ffffff             -call 0x4898e0
    cpu.esp -= 4;
    sub_4898e0(app, cpu);
    if (cpu.terminate) return;
    // 004899cb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004899cd  e8a2b90100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 004899d2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004899d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4899e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004899e0);
    // 004899e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004899e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004899e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004899e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004899e6  8b1da8b64d00           -mov ebx, dword ptr [0x4db6a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */);
    // 004899ec  8b35a4b64d00           -mov esi, dword ptr [0x4db6a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093028) /* 0x4db6a4 */);
    // 004899f2  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004899f9  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004899fb  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004899fe  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489a01  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00489a03  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00489a05  e8ca300100             -call 0x49cad4
    cpu.esp -= 4;
    sub_49cad4(app, cpu);
    if (cpu.terminate) return;
    // 00489a0a  8b35a4b64d00           -mov esi, dword ptr [0x4db6a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5093028) /* 0x4db6a4 */);
    // 00489a10  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489a12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489a14  741d                   -je 0x489a33
    if (cpu.flags.zf)
    {
        goto L_0x00489a33;
    }
    // 00489a16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489a17  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489a19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00489a1b  7e13                   -jle 0x489a30
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489a30;
    }
L_0x00489a1d:
    // 00489a1d  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 00489a24  42                     -inc edx
    (cpu.edx)++;
    // 00489a25  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00489a27  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00489a29  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00489a2c  39f2                   +cmp edx, esi
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
    // 00489a2e  7ced                   -jl 0x489a1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489a1d;
    }
L_0x00489a30:
    // 00489a30  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489a32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00489a33:
    // 00489a33  8935a4b64d00           -mov dword ptr [0x4db6a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5093028) /* 0x4db6a4 */) = cpu.esi;
    // 00489a39  891da8b64d00           -mov dword ptr [0x4db6a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */) = cpu.ebx;
    // 00489a3f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489a42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489a48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489a48);
    // 00489a48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489a49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489a4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489a4b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489a4d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00489a4f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489a51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489a52  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489a54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489a55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a56  2eff15d4654c00         -call dword ptr cs:[0x4c65d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006804) /* 0x4c65d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489a5d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489a5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489a61  7c04                   -jl 0x489a67
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489a67;
    }
    // 00489a63  39f8                   +cmp eax, edi
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
    // 00489a65  7c0c                   -jl 0x489a73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489a73;
    }
L_0x00489a67:
    // 00489a67  81fb02010000           -cmp ebx, 0x102
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(258 /*0x102*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489a6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489a6f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489a73:
    // 00489a73  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00489a76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489a7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489a7c);
    // 00489a7c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489a80  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489a82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489a84  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_489a88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489a88);
    // 00489a88  833d6842560000         +cmp dword ptr [0x564268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653096) /* 0x564268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489a8f  7401                   -je 0x489a92
    if (cpu.flags.zf)
    {
        goto L_0x00489a92;
    }
    // 00489a91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489a92:
    // 00489a92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489a93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489a94  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489a9b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00489a9d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489a9f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489aa1  6860425600             -push 0x564260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5653088 /*0x564260*/;
    cpu.esp -= 4;
    // 00489aa6  a364425600             -mov dword ptr [0x564264], eax
    app->getMemory<x86::reg32>(x86::reg32(5653092) /* 0x564264 */) = cpu.eax;
    // 00489aab  2eff15c4644c00         -call dword ptr cs:[0x4c64c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006532) /* 0x4c64c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489ab2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489ab3  2eff15d0644c00         -call dword ptr cs:[0x4c64d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006544) /* 0x4c64d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489aba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489abb  2eff15c4644c00         -call dword ptr cs:[0x4c64c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006532) /* 0x4c64c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489ac2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489ac3  2eff1578644c00         -call dword ptr cs:[0x4c6478]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006456) /* 0x4c6478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489aca  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00489acf  e80cffffff             -call 0x4899e0
    cpu.esp -= 4;
    sub_4899e0(app, cpu);
    if (cpu.terminate) return;
    // 00489ad4  890d68425600           -mov dword ptr [0x564268], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653096) /* 0x564268 */) = cpu.ecx;
    // 00489ada  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489adb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489adc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489ae0);
    // 00489ae0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489ae1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489ae2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489ae3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489ae6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00489ae8  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00489aea  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00489aee  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00489af0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489af1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00489af3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489af4  687c9a4800             -push 0x489a7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4758140 /*0x489a7c*/;
    cpu.esp -= 4;
    // 00489af9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489afa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489afc  2eff1568644c00         -call dword ptr cs:[0x4c6468]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006440) /* 0x4c6468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489b03  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489b05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489b07  7441                   -je 0x489b4a
    if (cpu.flags.zf)
    {
        goto L_0x00489b4a;
    }
    // 00489b09  833d6842560000         +cmp dword ptr [0x564268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653096) /* 0x564268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489b10  7507                   -jne 0x489b19
    if (!cpu.flags.zf)
    {
        goto L_0x00489b19;
    }
    // 00489b12  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489b14  e86fffffff             -call 0x489a88
    cpu.esp -= 4;
    sub_489a88(app, cpu);
    if (cpu.terminate) return;
L_0x00489b19:
    // 00489b19  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00489b20  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00489b22  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00489b25  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00489b28  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489b2b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00489b2d  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00489b30  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489b32  e8a9010000             -call 0x489ce0
    cpu.esp -= 4;
    sub_489ce0(app, cpu);
    if (cpu.terminate) return;
    // 00489b37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489b38  2eff1564654c00         -call dword ptr cs:[0x4c6564]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006692) /* 0x4c6564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489b3f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489b41  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489b43  2eff15a4654c00         -call dword ptr cs:[0x4c65a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006756) /* 0x4c65a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00489b4a:
    // 00489b4a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489b4c  740e                   -je 0x489b5c
    if (cpu.flags.zf)
    {
        goto L_0x00489b5c;
    }
    // 00489b4e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489b53  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489b56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b59  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00489b5c:
    // 00489b5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489b5e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489b61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b64  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_489b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489b68);
    // 00489b68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489b6a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489b70);
    // 00489b70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489b71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489b72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489b73  83f8ff                 +cmp eax, -1
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
    // 00489b76  7418                   -je 0x489b90
    if (cpu.flags.zf)
    {
        goto L_0x00489b90;
    }
    // 00489b78  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
L_0x00489b7a:
    // 00489b7a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489b7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489b7d  2eff15a8654c00         -call dword ptr cs:[0x4c65a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006760) /* 0x4c65a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489b84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489b85  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489b8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b8e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489b90:
    // 00489b90  2eff15d0644c00         -call dword ptr cs:[0x4c64d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006544) /* 0x4c64d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489b97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489b99  ebdf                   -jmp 0x489b7a
    goto L_0x00489b7a;
}

/* align: skip 0x90 */
void Application::sub_489b9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489b9c);
    // 00489b9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489b9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489b9e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489ba0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489ba1  2eff15a4654c00         -call dword ptr cs:[0x4c65a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006756) /* 0x4c65a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489ba8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ba9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489baa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489bac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489bac);
    // 00489bac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489bad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489bae  8b0dccab4d00           -mov ecx, dword ptr [0x4dabcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00489bb4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489bb6  7505                   -jne 0x489bbd
    if (!cpu.flags.zf)
    {
        goto L_0x00489bbd;
    }
    // 00489bb8  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x00489bbd:
    // 00489bbd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489bbf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489bc2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489bc4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00489bc7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489bc9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00489bcc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489bce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489bd1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489bd3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489bd5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489bd8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489bda  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489bdc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489bdd  2eff15a4654c00         -call dword ptr cs:[0x4c65a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006756) /* 0x4c65a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489be4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489be8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489be8);
    // 00489be8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489be9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489bea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489beb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489bed  2eff15cc644c00         -call dword ptr cs:[0x4c64cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006540) /* 0x4c64cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489bf4  8b0d68425600           -mov ecx, dword ptr [0x564268]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653096) /* 0x564268 */);
    // 00489bfa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489bfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489bfe  7415                   -je 0x489c15
    if (cpu.flags.zf)
    {
        goto L_0x00489c15;
    }
L_0x00489c00:
    // 00489c00  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489c02  7520                   -jne 0x489c24
    if (!cpu.flags.zf)
    {
        goto L_0x00489c24;
    }
    // 00489c04  3b1564425600           +cmp edx, dword ptr [0x564264]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5653092) /* 0x564264 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c0a  7512                   -jne 0x489c1e
    if (!cpu.flags.zf)
    {
        goto L_0x00489c1e;
    }
L_0x00489c0c:
    // 00489c0c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489c11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489c15:
    // 00489c15  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489c17  e86cfeffff             -call 0x489a88
    cpu.esp -= 4;
    sub_489a88(app, cpu);
    if (cpu.terminate) return;
    // 00489c1c  ebe2                   -jmp 0x489c00
    goto L_0x00489c00;
L_0x00489c1e:
    // 00489c1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489c20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489c24:
    // 00489c24  83fbff                 +cmp ebx, -1
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
    // 00489c27  74e3                   -je 0x489c0c
    if (cpu.flags.zf)
    {
        goto L_0x00489c0c;
    }
    // 00489c29  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c2c  74de                   -je 0x489c0c
    if (cpu.flags.zf)
    {
        goto L_0x00489c0c;
    }
    // 00489c2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489c30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489c34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489c34);
    // 00489c34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489c35  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489c36  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489c38  833d6842560000         +cmp dword ptr [0x564268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653096) /* 0x564268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c3f  742f                   -je 0x489c70
    if (cpu.flags.zf)
    {
        goto L_0x00489c70;
    }
L_0x00489c41:
    // 00489c41  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489c43  7534                   -jne 0x489c79
    if (!cpu.flags.zf)
    {
        goto L_0x00489c79;
    }
    // 00489c45  a160425600             -mov eax, dword ptr [0x564260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653088) /* 0x564260 */);
L_0x00489c4a:
    // 00489c4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489c4b  2eff1520654c00         -call dword ptr cs:[0x4c6520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006624) /* 0x4c6520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489c52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489c54  7c35                   -jl 0x489c8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489c8b;
    }
    // 00489c56  0f8e5b000000           -jle 0x489cb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489cb7;
    }
    // 00489c5c  83f802                 +cmp eax, 2
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
    // 00489c5f  7c4e                   -jl 0x489caf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489caf;
    }
    // 00489c61  7e44                   -jle 0x489ca7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489ca7;
    }
    // 00489c63  83f80f                 +cmp eax, 0xf
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
    // 00489c66  754f                   -jne 0x489cb7
    if (!cpu.flags.zf)
    {
        goto L_0x00489cb7;
    }
    // 00489c68  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00489c6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489c70:
    // 00489c70  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489c72  e811feffff             -call 0x489a88
    cpu.esp -= 4;
    sub_489a88(app, cpu);
    if (cpu.terminate) return;
    // 00489c77  ebc8                   -jmp 0x489c41
    goto L_0x00489c41;
L_0x00489c79:
    // 00489c79  83faff                 +cmp edx, -1
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
    // 00489c7c  7404                   -je 0x489c82
    if (cpu.flags.zf)
    {
        goto L_0x00489c82;
    }
    // 00489c7e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00489c80  ebc8                   -jmp 0x489c4a
    goto L_0x00489c4a;
L_0x00489c82:
    // 00489c82  2eff15d0644c00         -call dword ptr cs:[0x4c64d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006544) /* 0x4c64d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489c89  ebbf                   -jmp 0x489c4a
    goto L_0x00489c4a;
L_0x00489c8b:
    // 00489c8b  83f8fe                 +cmp eax, -2
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
    // 00489c8e  7d0d                   -jge 0x489c9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489c9d;
    }
    // 00489c90  83f8f1                 +cmp eax, -0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-15 /*-0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c93  7522                   -jne 0x489cb7
    if (!cpu.flags.zf)
    {
        goto L_0x00489cb7;
    }
    // 00489c95  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 00489c9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489c9d:
    // 00489c9d  7f1d                   -jg 0x489cbc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489cbc;
    }
    // 00489c9f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00489ca4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ca5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489ca7:
    // 00489ca7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00489cac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489caf:
    // 00489caf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489cb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cb7:
    // 00489cb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489cb9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cbb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cbc:
    // 00489cbc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00489cc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489ce0);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00489ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ce2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489ce4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00489ce6  833d6842560000         +cmp dword ptr [0x564268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653096) /* 0x564268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489ced  742a                   -je 0x489d19
    if (cpu.flags.zf)
    {
        goto L_0x00489d19;
    }
L_0x00489cef:
    // 00489cef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489cf1  752f                   -jne 0x489d22
    if (!cpu.flags.zf)
    {
        goto L_0x00489d22;
    }
    // 00489cf3  8b0d60425600           -mov ecx, dword ptr [0x564260]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653088) /* 0x564260 */);
    // 00489cf9  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00489cfc  83f806                 +cmp eax, 6
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
    // 00489cff  7764                   -ja 0x489d65
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489d65;
    }
    // 00489d01  ff2485c49c4800         -jmp dword ptr [eax*4 + 0x489cc4]
    cpu.ip = app->getMemory<x86::reg32>(4758724 + cpu.eax * 4); goto dynamic_jump;
  case 0x00489d08:
    // 00489d08  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
L_0x00489d0d:
    // 00489d0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489d0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489d0f  2eff159c654c00         -call dword ptr cs:[0x4c659c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006748) /* 0x4c659c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489d16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489d19:
    // 00489d19  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489d1b  e868fdffff             -call 0x489a88
    cpu.esp -= 4;
    sub_489a88(app, cpu);
    if (cpu.terminate) return;
    // 00489d20  ebcd                   -jmp 0x489cef
    goto L_0x00489cef;
L_0x00489d22:
    // 00489d22  83f9ff                 +cmp ecx, -1
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
    // 00489d25  7411                   -je 0x489d38
    if (cpu.flags.zf)
    {
        goto L_0x00489d38;
    }
    // 00489d27  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00489d29  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00489d2c  83f806                 +cmp eax, 6
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
    // 00489d2f  7734                   -ja 0x489d65
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489d65;
    }
    // 00489d31  ff2485c49c4800         -jmp dword ptr [eax*4 + 0x489cc4]
    cpu.ip = app->getMemory<x86::reg32>(4758724 + cpu.eax * 4); goto dynamic_jump;
L_0x00489d38:
    // 00489d38  2eff15d0644c00         -call dword ptr cs:[0x4c64d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006544) /* 0x4c64d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489d3f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489d41  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 00489d44  83f806                 +cmp eax, 6
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
    // 00489d47  771c                   -ja 0x489d65
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489d65;
    }
    // 00489d49  ff2485c49c4800         -jmp dword ptr [eax*4 + 0x489cc4]
    cpu.ip = app->getMemory<x86::reg32>(4758724 + cpu.eax * 4); goto dynamic_jump;
  case 0x00489d50:
    // 00489d50  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00489d55  ebb6                   -jmp 0x489d0d
    goto L_0x00489d0d;
  case 0x00489d57:
    // 00489d57  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00489d5c  ebaf                   -jmp 0x489d0d
    goto L_0x00489d0d;
  case 0x00489d5e:
    // 00489d5e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489d63  eba8                   -jmp 0x489d0d
    goto L_0x00489d0d;
  case 0x00489d65:
L_0x00489d65:
    // 00489d65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489d67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489d68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489d69  2eff159c654c00         -call dword ptr cs:[0x4c659c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006748) /* 0x4c659c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489d70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d72  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489d73:
    // 00489d73  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00489d78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489d79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489d7a  2eff159c654c00         -call dword ptr cs:[0x4c659c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006748) /* 0x4c659c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489d81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d83  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489d84:
    // 00489d84  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00489d89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489d8a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489d8b  2eff159c654c00         -call dword ptr cs:[0x4c659c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006748) /* 0x4c659c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489d92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d94  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489d98);
    // 00489d98  833dacb64d0000         +cmp dword ptr [0x4db6ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093036) /* 0x4db6ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489d9f  750a                   -jne 0x489dab
    if (!cpu.flags.zf)
    {
        goto L_0x00489dab;
    }
    // 00489da1  e852010000             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00489da6  a3acb64d00             -mov dword ptr [0x4db6ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5093036) /* 0x4db6ac */) = cpu.eax;
L_0x00489dab:
    // 00489dab  a1acb64d00             -mov eax, dword ptr [0x4db6ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093036) /* 0x4db6ac */);
    // 00489db0  e893010000             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 00489db5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00489dba  e875feffff             -call 0x489c34
    cpu.esp -= 4;
    sub_489c34(app, cpu);
    if (cpu.terminate) return;
    // 00489dbf  83f803                 +cmp eax, 3
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
    // 00489dc2  7501                   -jne 0x489dc5
    if (!cpu.flags.zf)
    {
        goto L_0x00489dc5;
    }
    // 00489dc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489dc5:
    // 00489dc5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489dc6  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00489dcb  a3b0b64d00             -mov dword ptr [0x4db6b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5093040) /* 0x4db6b0 */) = cpu.eax;
    // 00489dd0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00489dd5  e806ffffff             -call 0x489ce0
    cpu.esp -= 4;
    sub_489ce0(app, cpu);
    if (cpu.terminate) return;
    // 00489dda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ddb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489ddc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489ddc);
    // 00489ddc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489ddd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00489de2  8b15b0b64d00           -mov edx, dword ptr [0x4db6b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093040) /* 0x4db6b0 */);
    // 00489de8  e8f3feffff             -call 0x489ce0
    cpu.esp -= 4;
    sub_489ce0(app, cpu);
    if (cpu.terminate) return;
    // 00489ded  a1acb64d00             -mov eax, dword ptr [0x4db6ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093036) /* 0x4db6ac */);
    // 00489df2  e869010000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00489df7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489dfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489dfc);
    // 00489dfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489dfd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489dfe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489e00  2eff1588644c00         -call dword ptr cs:[0x4c6488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006472) /* 0x4c6488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489e07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489e0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489e0c);
    // 00489e0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489e0e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489e10  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489e12  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489e14  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489e16  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489e1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489e20);
    // 00489e20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489e22  2eff1588654c00         -call dword ptr cs:[0x4c6588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006728) /* 0x4c6588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489e29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489e2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489e2c);
    // 00489e2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489e2e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e31  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489e34  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00489e36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489e3b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489e3d  e806fcffff             -call 0x489a48
    cpu.esp -= 4;
    sub_489a48(app, cpu);
    if (cpu.terminate) return;
    // 00489e42  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00489e45  750b                   -jne 0x489e52
    if (!cpu.flags.zf)
    {
        goto L_0x00489e52;
    }
    // 00489e47  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489e4c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e4f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489e52:
    // 00489e52  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489e54  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489e5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489e5c);
    // 00489e5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e5d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489e5e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e61  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489e64  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00489e69  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00489e6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489e70  e8d3fbffff             -call 0x489a48
    cpu.esp -= 4;
    sub_489a48(app, cpu);
    if (cpu.terminate) return;
    // 00489e75  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489e7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489e7c);
    // 00489e7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e7e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e81  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489e84  8b0dccab4d00           -mov ecx, dword ptr [0x4dabcc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00489e8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489e8c  7505                   -jne 0x489e93
    if (!cpu.flags.zf)
    {
        goto L_0x00489e93;
    }
    // 00489e8e  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x00489e93:
    // 00489e93  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00489e9a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489e9c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00489e9f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489ea1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00489ea4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489ea6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489ea9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489eab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489ead  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489eb0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489eb2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00489eb4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489eb6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489ebb  e888fbffff             -call 0x489a48
    cpu.esp -= 4;
    sub_489a48(app, cpu);
    if (cpu.terminate) return;
    // 00489ec0  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00489ec3  750b                   -jne 0x489ed0
    if (!cpu.flags.zf)
    {
        goto L_0x00489ed0;
    }
    // 00489ec5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489eca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489ecd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ece  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ecf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489ed0:
    // 00489ed0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489ed2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489ed5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ed6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ed7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489ed8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489ed8);
    // 00489ed8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ed9  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00489ede  e865fbffff             -call 0x489a48
    cpu.esp -= 4;
    sub_489a48(app, cpu);
    if (cpu.terminate) return;
    // 00489ee3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489ee8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489ee8);
    // 00489ee8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ee9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489eea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489eeb  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489ef2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ef3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ef4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489ef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489ef8);
    // 00489ef8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ef9  833da8b64d0000         +cmp dword ptr [0x4db6a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489f00  740e                   -je 0x489f10
    if (cpu.flags.zf)
    {
        goto L_0x00489f10;
    }
    // 00489f02  8b0da8b64d00           -mov ecx, dword ptr [0x4db6a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */);
    // 00489f08  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489f0a  7517                   -jne 0x489f23
    if (!cpu.flags.zf)
    {
        goto L_0x00489f23;
    }
    // 00489f0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f10:
    // 00489f10  e8cbfaffff             -call 0x4899e0
    cpu.esp -= 4;
    sub_4899e0(app, cpu);
    if (cpu.terminate) return;
    // 00489f15  8b0da8b64d00           -mov ecx, dword ptr [0x4db6a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */);
    // 00489f1b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489f1d  7504                   -jne 0x489f23
    if (!cpu.flags.zf)
    {
        goto L_0x00489f23;
    }
    // 00489f1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489f21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f23:
    // 00489f23  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489f24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f25  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00489f27  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00489f2c  a3a8b64d00             -mov dword ptr [0x4db6a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */) = cpu.eax;
    // 00489f31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489f33  e8e4000000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00489f38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f39  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489f3b  2eff153c654c00         -call dword ptr cs:[0x4c653c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006652) /* 0x4c653c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489f42  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489f44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489f48);
    // 00489f48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489f4a  7501                   -jne 0x489f4d
    if (!cpu.flags.zf)
    {
        goto L_0x00489f4d;
    }
    // 00489f4c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f4d:
    // 00489f4d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489f4e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489f50  2eff157c644c00         -call dword ptr cs:[0x4c647c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006460) /* 0x4c647c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489f57  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489f5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489f60);
    // 00489f60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489f62  7501                   -jne 0x489f65
    if (!cpu.flags.zf)
    {
        goto L_0x00489f65;
    }
    // 00489f64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f65:
    // 00489f65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489f66  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489f68  2eff1540654c00         -call dword ptr cs:[0x4c6540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006656) /* 0x4c6540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489f6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489f74);
    // 00489f74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f75  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489f77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489f79  7502                   -jne 0x489f7d
    if (!cpu.flags.zf)
    {
        goto L_0x00489f7d;
    }
    // 00489f7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f7d:
    // 00489f7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489f7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f7f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489f80  2eff1570644c00         -call dword ptr cs:[0x4c6470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006448) /* 0x4c6470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489f87  a1a8b64d00             -mov eax, dword ptr [0x4db6a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */);
    // 00489f8c  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 00489f93  891da8b64d00           -mov dword ptr [0x4db6a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5093032) /* 0x4db6a8 */) = cpu.ebx;
    // 00489f99  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00489f9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489fa0);
    // 00489fa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489fa2  750b                   -jne 0x489faf
    if (!cpu.flags.zf)
    {
        goto L_0x00489faf;
    }
    // 00489fa4  a16c425600             -mov eax, dword ptr [0x56426c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653100) /* 0x56426c */);
    // 00489fa9  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00489fae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489faf:
    // 00489faf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489fb0  8b156c425600           -mov edx, dword ptr [0x56426c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653100) /* 0x56426c */);
    // 00489fb6  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00489fbc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489fbd  681cfe4c00             -push 0x4cfe1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5045788 /*0x4cfe1c*/;
    cpu.esp -= 4;
    // 00489fc2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489fc3  e839c5ffff             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00489fc8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00489fcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fcc  a16c425600             -mov eax, dword ptr [0x56426c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653100) /* 0x56426c */);
    // 00489fd1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00489fd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00489fd8);
    // 00489fd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489fd9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489fda  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00489fe1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489fe3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489fe5  7503                   -jne 0x489fea
    if (!cpu.flags.zf)
    {
        goto L_0x00489fea;
    }
L_0x00489fe7:
    // 00489fe7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489fea:
    // 00489fea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489fec  e8f7fbffff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 00489ff1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489ff3  74f2                   -je 0x489fe7
    if (cpu.flags.zf)
    {
        goto L_0x00489fe7;
    }
    // 00489ff5  89156c425600           -mov dword ptr [0x56426c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653100) /* 0x56426c */) = cpu.edx;
    // 00489ffb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ffc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ffd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a000);
    // 0048a000  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a001  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a005  7502                   -jne 0x48a009
    if (!cpu.flags.zf)
    {
        goto L_0x0048a009;
    }
L_0x0048a007:
    // 0048a007  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a008  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a009:
    // 0048a009  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a00b  e8d8fbffff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 0048a010  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a012  74f3                   -je 0x48a007
    if (cpu.flags.zf)
    {
        goto L_0x0048a007;
    }
    // 0048a014  89156c425600           -mov dword ptr [0x56426c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653100) /* 0x56426c */) = cpu.edx;
    // 0048a01a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a01b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a01c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a01c);
    // 0048a01c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a01d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a01f  e80d000000             -call 0x48a031
    cpu.esp -= 4;
    sub_48a031(app, cpu);
    if (cpu.terminate) return;
    // 0048a024  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a025  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a026(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a026);
    // 0048a026  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 0048a028  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a029  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a02b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048a02e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a030  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a031  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0048a036  0f85a7000000           -jne 0x48a0e3
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0e3;
    }
L_0x0048a03c:
    // 0048a03c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a03f  7c3f                   -jl 0x48a080
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a080;
    }
    // 0048a041  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a044  743b                   -je 0x48a081
    if (cpu.flags.zf)
    {
        goto L_0x0048a081;
    }
    // 0048a046  38fb                   +cmp bl, bh
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
    // 0048a048  7537                   -jne 0x48a081
    if (!cpu.flags.zf)
    {
        goto L_0x0048a081;
    }
    // 0048a04a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a04b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a04c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048a04f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a052  7813                   -js 0x48a067
    if (cpu.flags.sf)
    {
        goto L_0x0048a067;
    }
L_0x0048a054:
    // 0048a054  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0048a056  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 0048a059  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 0048a05c  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 0048a05f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048a062  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a065  79ed                   -jns 0x48a054
    if (!cpu.flags.sf)
    {
        goto L_0x0048a054;
    }
L_0x0048a067:
    // 0048a067  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a06a  780a                   -js 0x48a076
    if (cpu.flags.sf)
    {
        goto L_0x0048a076;
    }
L_0x0048a06c:
    // 0048a06c  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0048a06e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048a071  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a074  79f6                   -jns 0x48a06c
    if (!cpu.flags.sf)
    {
        goto L_0x0048a06c;
    }
L_0x0048a076:
    // 0048a076  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048a078  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048a07b  83c208                 +add edx, 8
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
    // 0048a07e  753d                   -jne 0x48a0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0bd;
    }
L_0x0048a080:
    // 0048a080  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a081:
    // 0048a081  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a084  781f                   -js 0x48a0a5
    if (cpu.flags.sf)
    {
        goto L_0x0048a0a5;
    }
L_0x0048a086:
    // 0048a086  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a088  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048a08b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0048a08e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048a091  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0048a094  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0048a097  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048a09a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048a09d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048a0a0  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0a3  79e1                   -jns 0x48a086
    if (!cpu.flags.sf)
    {
        goto L_0x0048a086;
    }
L_0x0048a0a5:
    // 0048a0a5  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0a8  780d                   -js 0x48a0b7
    if (cpu.flags.sf)
    {
        goto L_0x0048a0b7;
    }
L_0x0048a0aa:
    // 0048a0aa  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a0ac  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048a0af  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048a0b2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0b5  79f3                   -jns 0x48a0aa
    if (!cpu.flags.sf)
    {
        goto L_0x0048a0aa;
    }
L_0x0048a0b7:
    // 0048a0b7  83c208                 +add edx, 8
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
    // 0048a0ba  7501                   -jne 0x48a0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0bd;
    }
    // 0048a0bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a0bd:
    // 0048a0bd  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 0048a0c3  7405                   -je 0x48a0ca
    if (cpu.flags.zf)
    {
        goto L_0x0048a0ca;
    }
    // 0048a0c5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a0c7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0048a0ca:
    // 0048a0ca  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0048a0d0  7406                   -je 0x48a0d8
    if (cpu.flags.zf)
    {
        goto L_0x0048a0d8;
    }
    // 0048a0d2  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0048a0d5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x0048a0d8:
    // 0048a0d8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0048a0de  7402                   -je 0x48a0e2
    if (cpu.flags.zf)
    {
        goto L_0x0048a0e2;
    }
    // 0048a0e0  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0048a0e2:
    // 0048a0e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a0e3:
    // 0048a0e3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0048a0e8  740d                   -je 0x48a0f7
    if (cpu.flags.zf)
    {
        goto L_0x0048a0f7;
    }
    // 0048a0ea  83fa01                 +cmp edx, 1
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
    // 0048a0ed  7c08                   -jl 0x48a0f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a0f7;
    }
    // 0048a0ef  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0048a0f1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048a0f4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0048a0f7:
    // 0048a0f7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0048a0fc  740e                   -je 0x48a10c
    if (cpu.flags.zf)
    {
        goto L_0x0048a10c;
    }
    // 0048a0fe  83fa02                 +cmp edx, 2
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
    // 0048a101  7c09                   -jl 0x48a10c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a10c;
    }
    // 0048a103  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0048a106  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048a109  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0048a10c:
    // 0048a10c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0048a111  740d                   -je 0x48a120
    if (cpu.flags.zf)
    {
        goto L_0x0048a120;
    }
    // 0048a113  83fa04                 +cmp edx, 4
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
    // 0048a116  7c08                   -jl 0x48a120
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a120;
    }
    // 0048a118  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a11a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048a11d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0048a120:
    // 0048a120  e917ffffff             -jmp 0x48a03c
    goto L_0x0048a03c;
}

/* align: skip  */
void Application::sub_48a031(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a031);
    goto L_entry_0x0048a031;
    // 0048a026  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 0048a028  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a029  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a02b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048a02e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a030  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x0048a031:
    // 0048a031  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0048a036  0f85a7000000           -jne 0x48a0e3
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0e3;
    }
L_0x0048a03c:
    // 0048a03c  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a03f  7c3f                   -jl 0x48a080
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a080;
    }
    // 0048a041  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a044  743b                   -je 0x48a081
    if (cpu.flags.zf)
    {
        goto L_0x0048a081;
    }
    // 0048a046  38fb                   +cmp bl, bh
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
    // 0048a048  7537                   -jne 0x48a081
    if (!cpu.flags.zf)
    {
        goto L_0x0048a081;
    }
    // 0048a04a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a04b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a04c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0048a04f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a052  7813                   -js 0x48a067
    if (cpu.flags.sf)
    {
        goto L_0x0048a067;
    }
L_0x0048a054:
    // 0048a054  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0048a056  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 0048a059  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 0048a05c  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 0048a05f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048a062  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a065  79ed                   -jns 0x48a054
    if (!cpu.flags.sf)
    {
        goto L_0x0048a054;
    }
L_0x0048a067:
    // 0048a067  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a06a  780a                   -js 0x48a076
    if (cpu.flags.sf)
    {
        goto L_0x0048a076;
    }
L_0x0048a06c:
    // 0048a06c  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0048a06e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048a071  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a074  79f6                   -jns 0x48a06c
    if (!cpu.flags.sf)
    {
        goto L_0x0048a06c;
    }
L_0x0048a076:
    // 0048a076  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048a078  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048a07b  83c208                 +add edx, 8
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
    // 0048a07e  753d                   -jne 0x48a0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0bd;
    }
L_0x0048a080:
    // 0048a080  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a081:
    // 0048a081  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a084  781f                   -js 0x48a0a5
    if (cpu.flags.sf)
    {
        goto L_0x0048a0a5;
    }
L_0x0048a086:
    // 0048a086  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a088  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048a08b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0048a08e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048a091  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0048a094  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0048a097  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048a09a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048a09d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048a0a0  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0a3  79e1                   -jns 0x48a086
    if (!cpu.flags.sf)
    {
        goto L_0x0048a086;
    }
L_0x0048a0a5:
    // 0048a0a5  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0a8  780d                   -js 0x48a0b7
    if (cpu.flags.sf)
    {
        goto L_0x0048a0b7;
    }
L_0x0048a0aa:
    // 0048a0aa  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a0ac  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048a0af  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048a0b2  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0b5  79f3                   -jns 0x48a0aa
    if (!cpu.flags.sf)
    {
        goto L_0x0048a0aa;
    }
L_0x0048a0b7:
    // 0048a0b7  83c208                 +add edx, 8
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
    // 0048a0ba  7501                   -jne 0x48a0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0bd;
    }
    // 0048a0bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a0bd:
    // 0048a0bd  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 0048a0c3  7405                   -je 0x48a0ca
    if (cpu.flags.zf)
    {
        goto L_0x0048a0ca;
    }
    // 0048a0c5  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a0c7  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0048a0ca:
    // 0048a0ca  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0048a0d0  7406                   -je 0x48a0d8
    if (cpu.flags.zf)
    {
        goto L_0x0048a0d8;
    }
    // 0048a0d2  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0048a0d5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x0048a0d8:
    // 0048a0d8  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0048a0de  7402                   -je 0x48a0e2
    if (cpu.flags.zf)
    {
        goto L_0x0048a0e2;
    }
    // 0048a0e0  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0048a0e2:
    // 0048a0e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a0e3:
    // 0048a0e3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0048a0e8  740d                   -je 0x48a0f7
    if (cpu.flags.zf)
    {
        goto L_0x0048a0f7;
    }
    // 0048a0ea  83fa01                 +cmp edx, 1
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
    // 0048a0ed  7c08                   -jl 0x48a0f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a0f7;
    }
    // 0048a0ef  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0048a0f1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048a0f4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0048a0f7:
    // 0048a0f7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0048a0fc  740e                   -je 0x48a10c
    if (cpu.flags.zf)
    {
        goto L_0x0048a10c;
    }
    // 0048a0fe  83fa02                 +cmp edx, 2
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
    // 0048a101  7c09                   -jl 0x48a10c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a10c;
    }
    // 0048a103  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0048a106  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048a109  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0048a10c:
    // 0048a10c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0048a111  740d                   -je 0x48a120
    if (cpu.flags.zf)
    {
        goto L_0x0048a120;
    }
    // 0048a113  83fa04                 +cmp edx, 4
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
    // 0048a116  7c08                   -jl 0x48a120
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a120;
    }
    // 0048a118  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0048a11a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048a11d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0048a120:
    // 0048a120  e917ffffff             -jmp 0x48a03c
    goto L_0x0048a03c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48a130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a130);
    // 0048a130  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a134);
    // 0048a134  833dc0ba4d0000         +cmp dword ptr [0x4dbac0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094080) /* 0x4dbac0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a13b  7501                   -jne 0x48a13e
    if (!cpu.flags.zf)
    {
        goto L_0x0048a13e;
    }
    // 0048a13d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a13e:
    // 0048a13e  e871010000             -call 0x48a2b4
    cpu.esp -= 4;
    sub_48a2b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a143  b88c425600             -mov eax, 0x56428c
    cpu.eax = 5653132 /*0x56428c*/;
    // 0048a148  e81f190000             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 0048a14d  b870425600             -mov eax, 0x564270
    cpu.eax = 5653104 /*0x564270*/;
    // 0048a152  e915190000             -jmp 0x48ba6c
    return sub_48ba6c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_48a158(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a158);
    // 0048a158  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a15b  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 0048a15f  7506                   -jne 0x48a167
    if (!cpu.flags.zf)
    {
        goto L_0x0048a167;
    }
    // 0048a161  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048a166  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a167:
    // 0048a167  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a16a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048a16f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a170);
    // 0048a170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a172  ba58a14800             -mov edx, 0x48a158
    cpu.edx = 4759896 /*0x48a158*/;
    // 0048a177  b88c425600             -mov eax, 0x56428c
    cpu.eax = 5653132 /*0x56428c*/;
    // 0048a17c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a17e  e8f11d0000             -call 0x48bf74
    cpu.esp -= 4;
    sub_48bf74(app, cpu);
    if (cpu.terminate) return;
    // 0048a183  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a184  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a185  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a188);
    // 0048a188  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a189  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a18a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a18c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048a18e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048a190  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048a192  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048a196  833dc0ba4d0000         +cmp dword ptr [0x4dbac0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094080) /* 0x4dbac0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a19d  0f84b0000000           -je 0x48a253
    if (cpu.flags.zf)
    {
        goto L_0x0048a253;
    }
L_0x0048a1a3:
    // 0048a1a3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a1a5  745e                   -je 0x48a205
    if (cpu.flags.zf)
    {
        goto L_0x0048a205;
    }
    // 0048a1a7  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a1ab  7507                   -jne 0x48a1b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1b4;
    }
    // 0048a1ad  c7462402000000         -mov dword ptr [esi + 0x24], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 2 /*0x2*/;
L_0x0048a1b4:
    // 0048a1b4  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 0048a1b8  7507                   -jne 0x48a1c1
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1c1;
    }
    // 0048a1ba  c7462804000000         -mov dword ptr [esi + 0x28], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 4 /*0x4*/;
L_0x0048a1c1:
    // 0048a1c1  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 0048a1c5  7507                   -jne 0x48a1ce
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1ce;
    }
    // 0048a1c7  c7462c06000000         -mov dword ptr [esi + 0x2c], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 6 /*0x6*/;
L_0x0048a1ce:
    // 0048a1ce  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a1d2  7507                   -jne 0x48a1db
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1db;
    }
    // 0048a1d4  c7461430a14800         -mov dword ptr [esi + 0x14], 0x48a130
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 4759856 /*0x48a130*/;
L_0x0048a1db:
    // 0048a1db  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a1df  7507                   -jne 0x48a1e8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1e8;
    }
    // 0048a1e1  c7461c30a14800         -mov dword ptr [esi + 0x1c], 0x48a130
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4759856 /*0x48a130*/;
L_0x0048a1e8:
    // 0048a1e8  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a1ec  7507                   -jne 0x48a1f5
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1f5;
    }
    // 0048a1ee  c7461830a14800         -mov dword ptr [esi + 0x18], 0x48a130
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4759856 /*0x48a130*/;
L_0x0048a1f5:
    // 0048a1f5  837e2000               +cmp dword ptr [esi + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a1f9  7507                   -jne 0x48a202
    if (!cpu.flags.zf)
    {
        goto L_0x0048a202;
    }
    // 0048a1fb  c7462030a14800         -mov dword ptr [esi + 0x20], 0x48a130
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 4759856 /*0x48a130*/;
L_0x0048a202:
    // 0048a202  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0048a205:
    // 0048a205  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a207  741f                   -je 0x48a228
    if (cpu.flags.zf)
    {
        goto L_0x0048a228;
    }
    // 0048a209  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a20d  7419                   -je 0x48a228
    if (cpu.flags.zf)
    {
        goto L_0x0048a228;
    }
    // 0048a20f  833dc4ba4d0000         +cmp dword ptr [0x4dbac4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094084) /* 0x4dbac4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a216  750a                   -jne 0x48a222
    if (!cpu.flags.zf)
    {
        goto L_0x0048a222;
    }
    // 0048a218  b870a14800             -mov eax, 0x48a170
    cpu.eax = 4759920 /*0x48a170*/;
    // 0048a21d  e8e29c0100             -call 0x4a3f04
    cpu.esp -= 4;
    sub_4a3f04(app, cpu);
    if (cpu.terminate) return;
L_0x0048a222:
    // 0048a222  ff05c4ba4d00           -inc dword ptr [0x4dbac4]
    (app->getMemory<x86::reg32>(x86::reg32(5094084) /* 0x4dbac4 */))++;
L_0x0048a228:
    // 0048a228  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a22a  ff5704                 -call dword ptr [edi + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a22d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a22f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a231  7419                   -je 0x48a24c
    if (cpu.flags.zf)
    {
        goto L_0x0048a24c;
    }
    // 0048a233  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a237  7413                   -je 0x48a24c
    if (cpu.flags.zf)
    {
        goto L_0x0048a24c;
    }
    // 0048a239  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a23b  750f                   -jne 0x48a24c
    if (!cpu.flags.zf)
    {
        goto L_0x0048a24c;
    }
    // 0048a23d  8b1dc4ba4d00           -mov ebx, dword ptr [0x4dbac4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094084) /* 0x4dbac4 */);
    // 0048a243  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a244  891dc4ba4d00           -mov dword ptr [0x4dbac4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094084) /* 0x4dbac4 */) = cpu.ebx;
    // 0048a24a  7411                   -je 0x48a25d
    if (cpu.flags.zf)
    {
        goto L_0x0048a25d;
    }
L_0x0048a24c:
    // 0048a24c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a24e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a24f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a250  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048a253:
    // 0048a253  e818000000             -call 0x48a270
    cpu.esp -= 4;
    sub_48a270(app, cpu);
    if (cpu.terminate) return;
    // 0048a258  e946ffffff             -jmp 0x48a1a3
    goto L_0x0048a1a3;
L_0x0048a25d:
    // 0048a25d  b870a14800             -mov eax, 0x48a170
    cpu.eax = 4759920 /*0x48a170*/;
    // 0048a262  e8059d0100             -call 0x4a3f6c
    cpu.esp -= 4;
    sub_4a3f6c(app, cpu);
    if (cpu.terminate) return;
    // 0048a267  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a26a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a26b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a270);
    // 0048a270  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a271  8b15c0ba4d00           -mov edx, dword ptr [0x4dbac0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5094080) /* 0x4dbac0 */);
    // 0048a277  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048a279  7402                   -je 0x48a27d
    if (cpu.flags.zf)
    {
        goto L_0x0048a27d;
    }
    // 0048a27b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a27c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a27d:
    // 0048a27d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a27e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a27f  b88c425600             -mov eax, 0x56428c
    cpu.eax = 5653132 /*0x56428c*/;
    // 0048a284  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a286  e8a1170000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048a28b  b870425600             -mov eax, 0x564270
    cpu.eax = 5653104 /*0x564270*/;
    // 0048a290  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a292  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a294  e893170000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048a299  b834a14800             -mov eax, 0x48a134
    cpu.eax = 4759860 /*0x48a134*/;
    // 0048a29e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048a2a3  e8f80a0100             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 0048a2a8  890dc0ba4d00           -mov dword ptr [0x4dbac0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094080) /* 0x4dbac0 */) = cpu.ecx;
    // 0048a2ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a2b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a2b4);
    // 0048a2b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a2b5  833dc0ba4d0000         +cmp dword ptr [0x4dbac0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094080) /* 0x4dbac0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a2bc  7420                   -je 0x48a2de
    if (cpu.flags.zf)
    {
        goto L_0x0048a2de;
    }
L_0x0048a2be:
    // 0048a2be  b88c425600             -mov eax, 0x56428c
    cpu.eax = 5653132 /*0x56428c*/;
    // 0048a2c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a2c5  e8aa1a0000             -call 0x48bd74
    cpu.esp -= 4;
    sub_48bd74(app, cpu);
    if (cpu.terminate) return;
    // 0048a2ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a2cc  7512                   -jne 0x48a2e0
    if (!cpu.flags.zf)
    {
        goto L_0x0048a2e0;
    }
L_0x0048a2ce:
    // 0048a2ce  b870425600             -mov eax, 0x564270
    cpu.eax = 5653104 /*0x564270*/;
    // 0048a2d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a2d5  e89a1a0000             -call 0x48bd74
    cpu.esp -= 4;
    sub_48bd74(app, cpu);
    if (cpu.terminate) return;
    // 0048a2da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a2dc  7509                   -jne 0x48a2e7
    if (!cpu.flags.zf)
    {
        goto L_0x0048a2e7;
    }
L_0x0048a2de:
    // 0048a2de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a2e0:
    // 0048a2e0  e823000000             -call 0x48a308
    cpu.esp -= 4;
    sub_48a308(app, cpu);
    if (cpu.terminate) return;
    // 0048a2e5  ebd7                   -jmp 0x48a2be
    goto L_0x0048a2be;
L_0x0048a2e7:
    // 0048a2e7  e81c000000             -call 0x48a308
    cpu.esp -= 4;
    sub_48a308(app, cpu);
    if (cpu.terminate) return;
    // 0048a2ec  ebe0                   -jmp 0x48a2ce
    goto L_0x0048a2ce;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a2f0);
    // 0048a2f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a2f2  7406                   -je 0x48a2fa
    if (cpu.flags.zf)
    {
        goto L_0x0048a2fa;
    }
    // 0048a2f4  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0048a2f8  7503                   -jne 0x48a2fd
    if (!cpu.flags.zf)
    {
        goto L_0x0048a2fd;
    }
L_0x0048a2fa:
    // 0048a2fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a2fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a2fd:
    // 0048a2fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a2fe  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a301  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a304  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a308(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048a308);
    // 0048a308  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a309  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a30b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a30d  7406                   -je 0x48a315
    if (cpu.flags.zf)
    {
        goto L_0x0048a315;
    }
    // 0048a30f  83781000               +cmp dword ptr [eax + 0x10], 0
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
    // 0048a313  7504                   -jne 0x48a319
    if (!cpu.flags.zf)
    {
        goto L_0x0048a319;
    }
L_0x0048a315:
    // 0048a315  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a317  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a318  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a319:
    // 0048a319  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a31a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a31b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a31c  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a31f  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a322  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a324  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a326  742a                   -je 0x48a352
    if (cpu.flags.zf)
    {
        goto L_0x0048a352;
    }
    // 0048a328  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048a32b  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a32f  7421                   -je 0x48a352
    if (cpu.flags.zf)
    {
        goto L_0x0048a352;
    }
    // 0048a331  8b35c4ba4d00           -mov esi, dword ptr [0x4dbac4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5094084) /* 0x4dbac4 */);
    // 0048a337  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a339  7417                   -je 0x48a352
    if (cpu.flags.zf)
    {
        goto L_0x0048a352;
    }
    // 0048a33b  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0048a33e  893dc4ba4d00           -mov dword ptr [0x4dbac4], edi
    app->getMemory<x86::reg32>(x86::reg32(5094084) /* 0x4dbac4 */) = cpu.edi;
    // 0048a344  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048a346  750a                   -jne 0x48a352
    if (!cpu.flags.zf)
    {
        goto L_0x0048a352;
    }
    // 0048a348  b870a14800             -mov eax, 0x48a170
    cpu.eax = 4759920 /*0x48a170*/;
    // 0048a34d  e81a9c0100             -call 0x4a3f6c
    cpu.esp -= 4;
    sub_4a3f6c(app, cpu);
    if (cpu.terminate) return;
L_0x0048a352:
    // 0048a352  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a354  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a355  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a356  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a357  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a358  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
