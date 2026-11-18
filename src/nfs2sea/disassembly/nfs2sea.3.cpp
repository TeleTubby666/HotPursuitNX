#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_41f710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f710  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041f713  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041f715  7e0f                   -jle 0x41f726
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041f726;
    }
    // 0041f717  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f718  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0041f71b  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0041f71e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0041f720  7e0a                   -jle 0x41f72c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041f72c;
    }
    // 0041f722  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f724  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f725  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f726:
    // 0041f726  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f72b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f72c:
    // 0041f72c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41f740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f740  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041f743  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41f750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041f751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041f752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041f753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041f756  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f759  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041f75b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f75d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0041f760  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041f762  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041f766  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041f769  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0041f76c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f770  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0041f772  0f858f000000           -jne 0x41f807
    if (!cpu.flags.zf)
    {
        goto L_0x0041f807;
    }
L_0x0041f778:
    // 0041f778  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0041f77b  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0041f77e  39c8                   +cmp eax, ecx
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
    // 0041f780  7617                   -jbe 0x41f799
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041f799;
    }
    // 0041f782  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f786  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0041f788  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041f78b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041f78f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f791  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f793  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041f796  014724                 -add dword ptr [edi + 0x24], eax
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0041f799:
    // 0041f799  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0041f79c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f79e  7452                   -je 0x41f7f2
    if (cpu.flags.zf)
    {
        goto L_0x0041f7f2;
    }
    // 0041f7a0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041f7a2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0041f7a4:
    // 0041f7a4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0041f7a6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0041f7a8  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041f7ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f7ad  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0041f7af  e86c000000             -call 0x41f820
    cpu.esp -= 4;
    sub_41f820(app, cpu);
    if (cpu.terminate) return;
    // 0041f7b4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f7b8  807a1f00               +cmp byte ptr [edx + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f7bc  7516                   -jne 0x41f7d4
    if (!cpu.flags.zf)
    {
        goto L_0x0041f7d4;
    }
    // 0041f7be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f7c0  7412                   -je 0x41f7d4
    if (cpu.flags.zf)
    {
        goto L_0x0041f7d4;
    }
    // 0041f7c2  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f7c4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041f7c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f7c8  740a                   -je 0x41f7d4
    if (cpu.flags.zf)
    {
        goto L_0x0041f7d4;
    }
    // 0041f7ca  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041f7ce  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0041f7d2  75d0                   -jne 0x41f7a4
    if (!cpu.flags.zf)
    {
        goto L_0x0041f7a4;
    }
L_0x0041f7d4:
    // 0041f7d4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f7d8  80781f00               +cmp byte ptr [eax + 0x1f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f7dc  7514                   -jne 0x41f7f2
    if (!cpu.flags.zf)
    {
        goto L_0x0041f7f2;
    }
    // 0041f7de  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0041f7e0  7410                   -je 0x41f7f2
    if (cpu.flags.zf)
    {
        goto L_0x0041f7f2;
    }
    // 0041f7e2  8b571c                 -mov edx, dword ptr [edi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0041f7e5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0041f7e7  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0041f7ea  e891b10600             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0041f7ef  897724                 -mov dword ptr [edi + 0x24], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x0041f7f2:
    // 0041f7f2  833c2400               +cmp dword ptr [esp], 0
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
    // 0041f7f6  741b                   -je 0x41f813
    if (cpu.flags.zf)
    {
        goto L_0x0041f813;
    }
    // 0041f7f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f7fd  83c40c                 +add esp, 0xc
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
    // 0041f800  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f801  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f802  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f803  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f805  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f806  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f807:
    // 0041f807  c7472400000000         -mov dword ptr [edi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0041f80e  e965ffffff             -jmp 0x41f778
    goto L_0x0041f778;
L_0x0041f813:
    // 0041f813  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f815  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041f818  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f819  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f81a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f81b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f81c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f81d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f81e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_41f820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041f820  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041f821  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041f822  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041f823  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041f826  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041f828  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0041f82c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0041f82e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041f830  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0041f832  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041f836  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041f839  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0041f83b  8a501f                 -mov dl, byte ptr [eax + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(31) /* 0x1f */);
    // 0041f83e  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0041f841  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0041f843  7512                   -jne 0x41f857
    if (!cpu.flags.zf)
    {
        goto L_0x0041f857;
    }
    // 0041f845  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041f847  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x0041f84a:
    // 0041f84a  39d0                   +cmp eax, edx
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
    // 0041f84c  7309                   -jae 0x41f857
    if (!cpu.flags.cf)
    {
        goto L_0x0041f857;
    }
    // 0041f84e  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f851  7404                   -je 0x41f857
    if (cpu.flags.zf)
    {
        goto L_0x0041f857;
    }
    // 0041f853  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041f854  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0041f855  ebf3                   -jmp 0x41f84a
    goto L_0x0041f84a;
L_0x0041f857:
    // 0041f857  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0041f85a  8038fe                 +cmp byte ptr [eax], 0xfe
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f85d  7529                   -jne 0x41f888
    if (!cpu.flags.zf)
    {
        goto L_0x0041f888;
    }
    // 0041f85f  8d4e06                 -lea ecx, [esi + 6]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0041f862  39d9                   +cmp ecx, ebx
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
    // 0041f864  7626                   -jbe 0x41f88c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041f88c;
    }
L_0x0041f866:
    // 0041f866  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0041f869  83c728                 -add edi, 0x28
    (cpu.edi) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0041f86c  39d6                   +cmp esi, edx
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
    // 0041f86e  0f8677010000           -jbe 0x41f9eb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041f9eb;
    }
    // 0041f874  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f879  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041f87b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041f87d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041f87f  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x0041f881:
    // 0041f881  83c410                 +add esp, 0x10
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
    // 0041f884  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f885  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f886  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f887  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041f888:
    // 0041f888  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0041f88a  ebf5                   -jmp 0x41f881
    goto L_0x0041f881;
L_0x0041f88c:
    // 0041f88c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f88e  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0041f891  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0041f893  3b5708                 +cmp edx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f896  0f8733010000           -ja 0x41f9cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041f9cf;
    }
    // 0041f89c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0041f89e  39d9                   +cmp ecx, ebx
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
    // 0041f8a0  77c4                   -ja 0x41f866
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041f866;
    }
    // 0041f8a2  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0041f8a4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0041f8a6  e885060000             -call 0x41ff30
    cpu.esp -= 4;
    sub_41ff30(app, cpu);
    if (cpu.terminate) return;
    // 0041f8ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f8ad  0f8414010000           -je 0x41f9c7
    if (cpu.flags.zf)
    {
        goto L_0x0041f9c7;
    }
    // 0041f8b3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f8b7  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0041f8bb  740c                   -je 0x41f8c9
    if (cpu.flags.zf)
    {
        goto L_0x0041f8c9;
    }
    // 0041f8bd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0041f8c1  a1bcba4d00             -mov eax, dword ptr [0x4dbabc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5094076) /* 0x4dbabc */);
    // 0041f8c6  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0041f8c9:
    // 0041f8c9  ff4710                 -inc dword ptr [edi + 0x10]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))++;
    // 0041f8cc  8a7503                 -mov dh, byte ptr [ebp + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0041f8cf  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f8d1  80fe7f                 +cmp dh, 0x7f
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f8d4  770c                   -ja 0x41f8e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041f8e2;
    }
    // 0041f8d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f8d8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f8da  8a5503                 -mov dl, byte ptr [ebp + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0041f8dd  e86e020000             -call 0x41fb50
    cpu.esp -= 4;
    sub_41fb50(app, cpu);
    if (cpu.terminate) return;
L_0x0041f8e2:
    // 0041f8e2  8a5d01                 -mov bl, byte ptr [ebp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0041f8e5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0041f8e8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0041f8ea  7408                   -je 0x41f8f4
    if (cpu.flags.zf)
    {
        goto L_0x0041f8f4;
    }
    // 0041f8ec  8a7d02                 -mov bh, byte ptr [ebp + 2]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0041f8ef  80ff7f                 +cmp bh, 0x7f
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f8f2  7642                   -jbe 0x41f936
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041f936;
    }
L_0x0041f8f4:
    // 0041f8f4  8a4d02                 -mov cl, byte ptr [ebp + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0041f8f7  80f97f                 +cmp cl, 0x7f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f8fa  0f86b7000000           -jbe 0x41f9b7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041f9b7;
    }
    // 0041f900  80f9ff                 +cmp cl, 0xff
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
    // 0041f903  0f855dffffff           -jne 0x41f866
    if (!cpu.flags.zf)
    {
        goto L_0x0041f866;
    }
    // 0041f909  833db8ba4d0002         +cmp dword ptr [0x4dbab8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f910  7c18                   -jl 0x41f92a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f92a;
    }
    // 0041f912  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f914  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041f917  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f918  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041f91a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041f91c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041f91e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041f920  b8e4924c00             -mov eax, 0x4c92e4
    cpu.eax = 5018340 /*0x4c92e4*/;
    // 0041f925  e8fabd0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
L_0x0041f92a:
    // 0041f92a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f92c  e8cf000000             -call 0x41fa00
    cpu.esp -= 4;
    sub_41fa00(app, cpu);
    if (cpu.terminate) return;
    // 0041f931  e930ffffff             -jmp 0x41f866
    goto L_0x0041f866;
L_0x0041f936:
    // 0041f936  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041f938  8b4770                 -mov eax, dword ptr [edi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */);
    // 0041f93b  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 0041f93d  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0041f942  e849060000             -call 0x41ff90
    cpu.esp -= 4;
    sub_41ff90(app, cpu);
    if (cpu.terminate) return;
    // 0041f947  8d5f78                 -lea ebx, [edi + 0x78]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(120) /* 0x78 */);
    // 0041f94a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041f94c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0041f94e  e8b9c50600             -call 0x48bf0c
    cpu.esp -= 4;
    sub_48bf0c(app, cpu);
    if (cpu.terminate) return;
    // 0041f953  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0041f957  c6470e00               -mov byte ptr [edi + 0xe], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0041f95b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041f95d  0f8403ffffff           -je 0x41f866
    if (cpu.flags.zf)
    {
        goto L_0x0041f866;
    }
    // 0041f963  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0041f966  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041f968  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041f96a  e811b00600             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0041f96f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041f973  8d8794000000           -lea eax, [edi + 0x94]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(148) /* 0x94 */);
    // 0041f979  e826c20600             -call 0x48bba4
    cpu.esp -= 4;
    sub_48bba4(app, cpu);
    if (cpu.terminate) return;
    // 0041f97e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041f982  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
    // 0041f984  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041f98b  0f8cd5feffff           -jl 0x41f866
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041f866;
    }
    // 0041f991  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f993  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041f996  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041f997  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0041f99b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041f99d  8d5812                 -lea ebx, [eax + 0x12]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0041f9a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041f9a2  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041f9a5  8a480d                 -mov cl, byte ptr [eax + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0041f9a8  b8dc924c00             -mov eax, 0x4c92dc
    cpu.eax = 5018332 /*0x4c92dc*/;
    // 0041f9ad  e872bd0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041f9b2  e9affeffff             -jmp 0x41f866
    goto L_0x0041f866;
L_0x0041f9b7:
    // 0041f9b7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041f9b9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041f9bb  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0041f9bd  e80e010000             -call 0x41fad0
    cpu.esp -= 4;
    sub_41fad0(app, cpu);
    if (cpu.terminate) return;
    // 0041f9c2  e99ffeffff             -jmp 0x41f866
    goto L_0x0041f866;
L_0x0041f9c7:
    // 0041f9c7  83c603                 +add esi, 3
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0041f9ca  e997feffff             -jmp 0x41f866
    goto L_0x0041f866;
L_0x0041f9cf:
    // 0041f9cf  80fafe                 +cmp dl, 0xfe
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0041f9d2  740d                   -je 0x41f9e1
    if (cpu.flags.zf)
    {
        goto L_0x0041f9e1;
    }
    // 0041f9d4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041f9d9  40                     -inc eax
    (cpu.eax)++;
    // 0041f9da  01c6                   +add esi, eax
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
    // 0041f9dc  e985feffff             -jmp 0x41f866
    goto L_0x0041f866;
L_0x0041f9e1:
    // 0041f9e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f9e3  40                     -inc eax
    (cpu.eax)++;
    // 0041f9e4  01c6                   +add esi, eax
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
    // 0041f9e6  e97bfeffff             -jmp 0x41f866
    goto L_0x0041f866;
L_0x0041f9eb:
    // 0041f9eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041f9ed  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041f9ef  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0041f9f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041f9f3  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0041f9f5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0041f9f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041f9fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_41fa00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fa00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fa01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fa02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fa03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fa04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fa05  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041fa07  833db8ba4d0002         +cmp dword ptr [0x4dbab8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fa0e  7c18                   -jl 0x41fa28
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fa28;
    }
    // 0041fa10  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fa12  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fa15  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fa16  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fa18  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fa1a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fa1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fa1e  b8a4924c00             -mov eax, 0x4c92a4
    cpu.eax = 5018276 /*0x4c92a4*/;
    // 0041fa23  e8fcbc0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
L_0x0041fa28:
    // 0041fa28  b88c425600             -mov eax, 0x56428c
    cpu.eax = 5653132 /*0x56428c*/;
    // 0041fa2d  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0041fa2f  e8e4c10600             -call 0x48bc18
    cpu.esp -= 4;
    sub_48bc18(app, cpu);
    if (cpu.terminate) return;
    // 0041fa34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fa36  746e                   -je 0x41faa6
    if (cpu.flags.zf)
    {
        goto L_0x0041faa6;
    }
    // 0041fa38  8b1db8ba4d00           -mov ebx, dword ptr [0x4dbab8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
    // 0041fa3e  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0041fa40  83fb01                 +cmp ebx, 1
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
    // 0041fa43  7c18                   -jl 0x41fa5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fa5d;
    }
    // 0041fa45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fa47  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fa4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fa4b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fa4d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fa4f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fa51  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fa53  b8b4924c00             -mov eax, 0x4c92b4
    cpu.eax = 5018292 /*0x4c92b4*/;
    // 0041fa58  e8c7bc0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
L_0x0041fa5d:
    // 0041fa5d  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0041fa64  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0041fa67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fa69  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fa6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fa6e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041fa70  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fa73  b870425600             -mov eax, 0x564270
    cpu.eax = 5653104 /*0x564270*/;
    // 0041fa78  e803c00600             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 0041fa7d  833db8ba4d0002         +cmp dword ptr [0x4dbab8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fa84  7d06                   -jge 0x41fa8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fa8c;
    }
L_0x0041fa86:
    // 0041fa86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fa8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fa8c:
    // 0041fa8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fa8e  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fa91  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fa92  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fa94  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fa96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fa98  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0041fa9a  b8c0924c00             -mov eax, 0x4c92c0
    cpu.eax = 5018304 /*0x4c92c0*/;
    // 0041fa9f  e880bc0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041faa4  ebe0                   -jmp 0x41fa86
    goto L_0x0041fa86;
L_0x0041faa6:
    // 0041faa6  833db8ba4d0001         +cmp dword ptr [0x4dbab8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041faad  7cd7                   -jl 0x41fa86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fa86;
    }
    // 0041faaf  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fab2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fab3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fab5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fab7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fab9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fabb  b8cc924c00             -mov eax, 0x4c92cc
    cpu.eax = 5018316 /*0x4c92cc*/;
    // 0041fac0  e85fbc0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041fac5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fac6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fac7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fac8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fac9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041faca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41fad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fad3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fad4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fad7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fad9  8d4854                 -lea ecx, [eax + 0x54]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 0041fadc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041fade  e8ddc10600             -call 0x48bcc0
    cpu.esp -= 4;
    sub_48bcc0(app, cpu);
    if (cpu.terminate) return;
    // 0041fae3  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0041fae8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041faee  e89d040000             -call 0x41ff90
    cpu.esp -= 4;
    sub_41ff90(app, cpu);
    if (cpu.terminate) return;
    // 0041faf3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0041faf6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041faf8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041fafa  e8b9c20600             -call 0x48bdb8
    cpu.esp -= 4;
    sub_48bdb8(app, cpu);
    if (cpu.terminate) return;
    // 0041faff  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0041fb01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fb03  7410                   -je 0x41fb15
    if (cpu.flags.zf)
    {
        goto L_0x0041fb15;
    }
    // 0041fb05  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb0c  7d0f                   -jge 0x41fb1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fb1d;
    }
    // 0041fb0e  c7470800000000         -mov dword ptr [edi + 8], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0041fb15:
    // 0041fb15  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fb18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fb1d:
    // 0041fb1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fb1f  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fb22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fb23  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fb27  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fb29  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fb2b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fb2d  b89c924c00             -mov eax, 0x4c929c
    cpu.eax = 5018268 /*0x4c929c*/;
    // 0041fb32  e8edbb0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041fb37  c7470800000000         -mov dword ptr [edi + 8], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0041fb3e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fb41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41fb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fb50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fb51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fb52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fb53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fb54  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fb57  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fb59  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0041fb5e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041fb64  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0041fb67  e824040000             -call 0x41ff90
    cpu.esp -= 4;
    sub_41ff90(app, cpu);
    if (cpu.terminate) return;
    // 0041fb6c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0041fb6f  3b4630                 +cmp eax, dword ptr [esi + 0x30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb72  7349                   -jae 0x41fbbd
    if (!cpu.flags.cf)
    {
        goto L_0x0041fbbd;
    }
    // 0041fb74  3b4634                 +cmp eax, dword ptr [esi + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb77  7644                   -jbe 0x41fbbd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fbbd;
    }
    // 0041fb79  8b3db8ba4d00           -mov edi, dword ptr [0x4dbab8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
    // 0041fb7f  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0041fb82  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb85  7d1a                   -jge 0x41fba1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fba1;
    }
L_0x0041fb87:
    // 0041fb87  8d5e38                 -lea ebx, [esi + 0x38]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0041fb8a  8d4e54                 -lea ecx, [esi + 0x54]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(84) /* 0x54 */);
L_0x0041fb8d:
    // 0041fb8d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041fb8f  e82cc10600             -call 0x48bcc0
    cpu.esp -= 4;
    sub_48bcc0(app, cpu);
    if (cpu.terminate) return;
    // 0041fb94  3b4634                 +cmp eax, dword ptr [esi + 0x34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fb97  7649                   -jbe 0x41fbe2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041fbe2;
    }
L_0x0041fb99:
    // 0041fb99  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fb9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fb9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fba0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fba1:
    // 0041fba1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fba3  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fba6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fba7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fbab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fbad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041fbaf  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0041fbb1  b88c924c00             -mov eax, 0x4c928c
    cpu.eax = 5018252 /*0x4c928c*/;
    // 0041fbb6  e869bb0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041fbbb  ebca                   -jmp 0x41fb87
    goto L_0x0041fb87;
L_0x0041fbbd:
    // 0041fbbd  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fbc4  7cc1                   -jl 0x41fb87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fb87;
    }
    // 0041fbc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fbc8  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fbcb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fbcc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0041fbd0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fbd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041fbd4  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0041fbd6  b894924c00             -mov eax, 0x4c9294
    cpu.eax = 5018260 /*0x4c9294*/;
    // 0041fbdb  e844bb0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041fbe0  eba5                   -jmp 0x41fb87
    goto L_0x0041fb87;
L_0x0041fbe2:
    // 0041fbe2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041fbe4  e813bf0600             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 0041fbe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fbeb  74ac                   -je 0x41fb99
    if (cpu.flags.zf)
    {
        goto L_0x0041fb99;
    }
    // 0041fbed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041fbef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0041fbf1  e88abe0600             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 0041fbf6  eb95                   -jmp 0x41fb8d
    goto L_0x0041fb8d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41fc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fc01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fc02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fc04  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0041fc06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fc08  740d                   -je 0x41fc17
    if (cpu.flags.zf)
    {
        goto L_0x0041fc17;
    }
    // 0041fc0a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0041fc0d  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0041fc10  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0041fc13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041fc15  7e08                   -jle 0x41fc1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0041fc1f;
    }
L_0x0041fc17:
    // 0041fc17  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041fc1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fc1f:
    // 0041fc1f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fc20  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fc27  7c1b                   -jl 0x41fc44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fc44;
    }
    // 0041fc29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fc2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fc2c  8a470d                 -mov al, byte ptr [edi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(13) /* 0xd */);
    // 0041fc2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fc30  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fc33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fc35  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fc37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fc39  b884924c00             -mov eax, 0x4c9284
    cpu.eax = 5018244 /*0x4c9284*/;
    // 0041fc3e  e8e1ba0600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041fc43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0041fc44:
    // 0041fc44  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0041fc46  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fc49  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0041fc4c  83e37f                 -and ebx, 0x7f
    cpu.ebx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0041fc4f  e80c000000             -call 0x41fc60
    cpu.esp -= 4;
    sub_41fc60(app, cpu);
    if (cpu.terminate) return;
    // 0041fc54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41fc60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fc60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fc61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fc62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fc63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fc64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fc67  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041fc69  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0041fc6b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0041fc6e  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0041fc70  c7400801000000         -mov dword ptr [eax + 8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0041fc77  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fc7a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041fc7c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fc7e  ff550c                 -call dword ptr [ebp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fc81  83f806                 +cmp eax, 6
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
    // 0041fc84  730a                   -jae 0x41fc90
    if (!cpu.flags.cf)
    {
        goto L_0x0041fc90;
    }
L_0x0041fc86:
    // 0041fc86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041fc88  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fc8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fc8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fc90:
    // 0041fc90  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fc92  e829020000             -call 0x41fec0
    cpu.esp -= 4;
    sub_41fec0(app, cpu);
    if (cpu.terminate) return;
    // 0041fc97  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0041fc9c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0041fca1  c6410cfe               -mov byte ptr [ecx + 0xc], 0xfe
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 254 /*0xfe*/;
    // 0041fca5  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 0041fca8  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0041fcad  88610e                 -mov byte ptr [ecx + 0xe], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ah;
    // 0041fcb0  8d690c                 -lea ebp, [ecx + 0xc]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0041fcb3  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0041fcb6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0041fcb8  c6410d00               -mov byte ptr [ecx + 0xd], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 0041fcbc  e89f020000             -call 0x41ff60
    cpu.esp -= 4;
    sub_41ff60(app, cpu);
    if (cpu.terminate) return;
    // 0041fcc1  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fcc4  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0041fcc6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041fcc8  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fccb  83f806                 +cmp eax, 6
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
    // 0041fcce  7521                   -jne 0x41fcf1
    if (!cpu.flags.zf)
    {
        goto L_0x0041fcf1;
    }
    // 0041fcd0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0041fcd5:
    // 0041fcd5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0041fcd7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0041fcd9  74ab                   -je 0x41fc86
    if (cpu.flags.zf)
    {
        goto L_0x0041fc86;
    }
    // 0041fcdb  833c247f               +cmp dword ptr [esp], 0x7f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fcdf  77a5                   -ja 0x41fc86
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0041fc86;
    }
    // 0041fce1  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0041fce4  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041fce7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041fce9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fcec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fced  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fcf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fcf1:
    // 0041fcf1  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0041fcf3  ebe0                   -jmp 0x41fcd5
    goto L_0x0041fcd5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41fd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041fd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fd02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fd03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fd04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fd05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0041fd07  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0041fd0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fd0c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041fd0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fd10  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0041fd12  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0041fd15  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0041fd18  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0041fd1b  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fd1e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fd20  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0041fd22  8a560d                 -mov dl, byte ptr [esi + 0xd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fd25  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fd28  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041fd2b  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0041fd2e  39d0                   +cmp eax, edx
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
    // 0041fd30  734a                   -jae 0x41fd7c
    if (!cpu.flags.cf)
    {
        goto L_0x0041fd7c;
    }
    // 0041fd32  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0041fd36  0f8cf8000000           -jl 0x41fe34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fe34;
    }
    // 0041fd3c  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd43  7c19                   -jl 0x41fd5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fd5e;
    }
    // 0041fd45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fd47  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0041fd4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fd4b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0041fd4e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fd50  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fd52  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fd54  b87c924c00             -mov eax, 0x4c927c
    cpu.eax = 5018236 /*0x4c927c*/;
L_0x0041fd59:
    // 0041fd59  e8c6b90600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
L_0x0041fd5e:
    // 0041fd5e  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fd62  0f84f2000000           -je 0x41fe5a
    if (cpu.flags.zf)
    {
        goto L_0x0041fe5a;
    }
    // 0041fd68  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0041fd6b  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0041fd6e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041fd71  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041fd74  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041fd76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fd7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fd7c:
    // 0041fd7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041fd7e  e83d010000             -call 0x41fec0
    cpu.esp -= 4;
    sub_41fec0(app, cpu);
    if (cpu.terminate) return;
    // 0041fd83  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0041fd85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fd87  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fd8a  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041fd8d  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0041fd90  88560f                 -mov byte ptr [esi + 0xf], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 0041fd93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041fd95  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0041fd97  8a560d                 -mov dl, byte ptr [esi + 0xd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fd9a  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041fd9d  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0041fda0  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0041fda3  e8b8010000             -call 0x41ff60
    cpu.esp -= 4;
    sub_41ff60(app, cpu);
    if (cpu.terminate) return;
    // 0041fda8  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0041fdab  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0041fdae  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0041fdb1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0041fdb4  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0041fdb7  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0041fdba  39d0                   +cmp eax, edx
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
    // 0041fdbc  754f                   -jne 0x41fe0d
    if (!cpu.flags.zf)
    {
        goto L_0x0041fe0d;
    }
    // 0041fdbe  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fdc5  7c24                   -jl 0x41fdeb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fdeb;
    }
    // 0041fdc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fdc9  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0041fdcc  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0041fdcf  8d5e12                 -lea ebx, [esi + 0x12]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0041fdd2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fdd3  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0041fdd6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041fdd8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041fdda  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 0041fddd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041fddf  7c25                   -jl 0x41fe06
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fe06;
    }
    // 0041fde1  b85c924c00             -mov eax, 0x4c925c
    cpu.eax = 5018204 /*0x4c925c*/;
L_0x0041fde6:
    // 0041fde6  e839b90600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
L_0x0041fdeb:
    // 0041fdeb  c745f001000000         -mov dword ptr [ebp - 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 1 /*0x1*/;
    // 0041fdf2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0041fdf5  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0041fdf8  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0041fdfb  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041fdfe  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041fe00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fe06:
    // 0041fe06  b854924c00             -mov eax, 0x4c9254
    cpu.eax = 5018196 /*0x4c9254*/;
    // 0041fe0b  ebd9                   -jmp 0x41fde6
    goto L_0x0041fde6;
L_0x0041fe0d:
    // 0041fe0d  833db8ba4d0001         +cmp dword ptr [0x4dbab8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe14  0f8c44ffffff           -jl 0x41fd5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fd5e;
    }
    // 0041fe1a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041fe1c  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0041fe1f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fe20  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0041fe23  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041fe25  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fe27  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0041fe2a  b864924c00             -mov eax, 0x4c9264
    cpu.eax = 5018212 /*0x4c9264*/;
    // 0041fe2f  e925ffffff             -jmp 0x41fd59
    goto L_0x0041fd59;
L_0x0041fe34:
    // 0041fe34  833db8ba4d0003         +cmp dword ptr [0x4dbab8], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041fe3b  0f8c1dffffff           -jl 0x41fd5e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041fd5e;
    }
    // 0041fe41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041fe43  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0041fe46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041fe47  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0041fe4a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041fe4c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0041fe4e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0041fe50  b874924c00             -mov eax, 0x4c9274
    cpu.eax = 5018228 /*0x4c9274*/;
    // 0041fe55  e9fffeffff             -jmp 0x41fd59
    goto L_0x0041fd59;
L_0x0041fe5a:
    // 0041fe5a  c7460801000000         -mov dword ptr [esi + 8], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0041fe61  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0041fe64  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0041fe66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fe6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_41fe70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fe70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041fe71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041fe72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0041fe73  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041fe75  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0041fe77  8d6812                 -lea ebp, [eax + 0x12]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0041fe7a  8b426c                 -mov eax, dword ptr [edx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0041fe7d  e8c6a00600             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 0041fe82  8b4230                 -mov eax, dword ptr [edx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0041fe85  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0041fe88  895a30                 -mov dword ptr [edx + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0041fe8b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0041fe8e  8b426c                 -mov eax, dword ptr [edx + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0041fe91  e8caa00600             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 0041fe96  c74608ffffffff         -mov dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 0041fe9d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0041fe9f  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0041fea2  c6460cfe               -mov byte ptr [esi + 0xc], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 254 /*0xfe*/;
    // 0041fea6  80e27f                 -and dl, 0x7f
    cpu.dl &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0041fea9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041feab  88560e                 -mov byte ptr [esi + 0xe], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.dl;
    // 0041feae  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0041feb0  884e0d                 -mov byte ptr [esi + 0xd], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 0041feb3  e8c8aa0600             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0041feb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041feb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041feba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041febb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_41fec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041fec0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041fec1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041fec2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041fec5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041fec7  83c078                 -add eax, 0x78
    (cpu.eax) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 0041feca  e8f1bd0600             -call 0x48bcc0
    cpu.esp -= 4;
    sub_48bcc0(app, cpu);
    if (cpu.terminate) return;
    // 0041fecf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0041fed2  83f8ff                 +cmp eax, -1
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
    // 0041fed5  7422                   -je 0x41fef9
    if (cpu.flags.zf)
    {
        goto L_0x0041fef9;
    }
L_0x0041fed7:
    // 0041fed7  48                     -dec eax
    (cpu.eax)--;
    // 0041fed8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0041fedb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0041fedd  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0041fee0  8b0db8ba4d00           -mov ecx, dword ptr [0x4dbab8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5094072) /* 0x4dbab8 */);
    // 0041fee6  89422c                 -mov dword ptr [edx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0041fee9  83f903                 +cmp ecx, 3
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
    // 0041feec  7d10                   -jge 0x41fefe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041fefe;
    }
    // 0041feee  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0041fef1  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0041fef3  83c404                 +add esp, 4
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
    // 0041fef6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fef7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041fef8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041fef9:
    // 0041fef9  8b4274                 -mov eax, dword ptr [edx + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 0041fefc  ebd9                   -jmp 0x41fed7
    goto L_0x0041fed7;
L_0x0041fefe:
    // 0041fefe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041feff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff01  8a420d                 -mov al, byte ptr [edx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0041ff04  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0041ff05  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ff07  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041ff09  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0041ff0b  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0041ff0f  b84c924c00             -mov eax, 0x4c924c
    cpu.eax = 5018188 /*0x4c924c*/;
    // 0041ff14  e80bb80600             -call 0x48b724
    cpu.esp -= 4;
    sub_48b724(app, cpu);
    if (cpu.terminate) return;
    // 0041ff19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff1a  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0041ff1d  247f                   -and al, 0x7f
    cpu.al &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0041ff1f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0041ff22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41ff30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ff30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0041ff31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ff32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041ff34  8a5804                 -mov bl, byte ptr [eax + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0041ff37  8a7805                 -mov bh, byte ptr [eax + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0041ff3a  e821000000             -call 0x41ff60
    cpu.esp -= 4;
    sub_41ff60(app, cpu);
    if (cpu.terminate) return;
    // 0041ff3f  8b4102                 -mov eax, dword ptr [ecx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0041ff42  0fbfd3                 -movsx edx, bx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0041ff45  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0041ff48  39c2                   +cmp edx, eax
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
    // 0041ff4a  7508                   -jne 0x41ff54
    if (!cpu.flags.zf)
    {
        goto L_0x0041ff54;
    }
    // 0041ff4c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0041ff51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ff54:
    // 0041ff54  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ff56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41ff60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ff60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ff61  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041ff63  c6400500               -mov byte ptr [eax + 5], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 0041ff67  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0041ff6a  884104                 -mov byte ptr [ecx + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0041ff6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0041ff6f  e86cec0600             -call 0x48ebe0
    cpu.esp -= 4;
    sub_48ebe0(app, cpu);
    if (cpu.terminate) return;
    // 0041ff74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041ff76  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0041ff79  885105                 -mov byte ptr [ecx + 5], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0041ff7c  884104                 -mov byte ptr [ecx + 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0041ff7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ff80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41ff90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ff90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ff91  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0041ff93  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0041ff95  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0041ff97  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041ff99  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0041ff9b  39c8                   +cmp eax, ecx
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
    // 0041ff9d  7303                   -jae 0x41ffa2
    if (!cpu.flags.cf)
    {
        goto L_0x0041ffa2;
    }
    // 0041ff9f  43                     -inc ebx
    (cpu.ebx)++;
    // 0041ffa0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0041ffa2:
    // 0041ffa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffa3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_41ffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041ffb1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0041ffb3  833d30724e0000         +cmp dword ptr [0x4e7230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ffba  7417                   -je 0x41ffd3
    if (cpu.flags.zf)
    {
        goto L_0x0041ffd3;
    }
L_0x0041ffbc:
    // 0041ffbc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0041ffbe  7c1a                   -jl 0x41ffda
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0041ffda;
    }
    // 0041ffc0  3b1514724e00           +cmp edx, dword ptr [0x4e7214]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0041ffc6  7312                   -jae 0x41ffda
    if (!cpu.flags.cf)
    {
        goto L_0x0041ffda;
    }
    // 0041ffc8  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 0041ffcd  8b44d004               -mov eax, dword ptr [eax + edx*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.edx * 8);
    // 0041ffd1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffd2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0041ffd3:
    // 0041ffd3  e848080000             -call 0x420820
    cpu.esp -= 4;
    sub_420820(app, cpu);
    if (cpu.terminate) return;
    // 0041ffd8  ebe2                   -jmp 0x41ffbc
    goto L_0x0041ffbc;
L_0x0041ffda:
    // 0041ffda  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0041ffdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041ffdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_41ffe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0041ffe0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0041ffe1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0041ffe2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0041ffe4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0041ffe6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0041ffe8  745b                   -je 0x420045
    if (cpu.flags.zf)
    {
        goto L_0x00420045;
    }
    // 0041ffea  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 0041ffee  7516                   -jne 0x420006
    if (!cpu.flags.zf)
    {
        goto L_0x00420006;
    }
    // 0041fff0  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0041fff6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0041fff8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0041fffb  c1e204                 +shl edx, 4
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
    // 0041fffe  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00420000  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00420003  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00420006:
    // 00420006  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 0042000a  7516                   -jne 0x420022
    if (!cpu.flags.zf)
    {
        goto L_0x00420022;
    }
    // 0042000c  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00420012  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420014  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00420017  c1e202                 +shl edx, 2
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
    // 0042001a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0042001c  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0042001f  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00420022:
    // 00420022  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 00420026  7516                   -jne 0x42003e
    if (!cpu.flags.zf)
    {
        goto L_0x0042003e;
    }
    // 00420028  8b15ccab4d00           -mov edx, dword ptr [0x4dabcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 0042002e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420030  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00420033  c1e202                 +shl edx, 2
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
    // 00420036  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00420038  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0042003b  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0042003e:
    // 0042003e  c7460806000000         -mov dword ptr [esi + 8], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 6 /*0x6*/;
L_0x00420045:
    // 00420045  bac84b4d00             -mov edx, 0x4d4bc8
    cpu.edx = 5065672 /*0x4d4bc8*/;
    // 0042004a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042004b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042004d  bbe44b4d00             -mov ebx, 0x4d4be4
    cpu.ebx = 5065700 /*0x4d4be4*/;
    // 00420052  e831a10600             -call 0x48a188
    cpu.esp -= 4;
    sub_48a188(app, cpu);
    if (cpu.terminate) return;
    // 00420057  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420058  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420061  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420063  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420065  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00420067  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0042006a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042006c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042006e  e895ff0600             -call 0x490008
    cpu.esp -= 4;
    sub_490008(app, cpu);
    if (cpu.terminate) return;
    // 00420073  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420074  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420081  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420083  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420085  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00420087  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0042008a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042008c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042008e  e8e5030700             -call 0x490478
    cpu.esp -= 4;
    sub_490478(app, cpu);
    if (cpu.terminate) return;
    // 00420093  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420095  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420097  7c04                   -jl 0x42009d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042009d;
    }
    // 00420099  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042009b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042009c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042009d:
    // 0042009d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0042009f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004200a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4200b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004200b0  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004200b3  e950020700             -jmp 0x490308
    return sub_490308(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4200c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004200c0  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004200c3  e994020700             -jmp 0x49035c
    return sub_49035c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4200d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004200d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004200d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004200d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004200d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004200d6  833d38724e0009         +cmp dword ptr [0x4e7238], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004200dd  750f                   -jne 0x4200ee
    if (!cpu.flags.zf)
    {
        goto L_0x004200ee;
    }
    // 004200df  833de04b4d0000         +cmp dword ptr [0x4d4be0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065696) /* 0x4d4be0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004200e6  752a                   -jne 0x420112
    if (!cpu.flags.zf)
    {
        goto L_0x00420112;
    }
L_0x004200e8:
    // 004200e8  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004200eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004200ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004200ee:
    // 004200ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004200ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004200f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004200f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004200f4  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 004200f9  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00420100  8b3d00724e00           -mov edi, dword ptr [0x4e7200]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5140992) /* 0x4e7200 */);
    // 00420106  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420107  2eff1510644c00         -call dword ptr cs:[0x4c6410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006352) /* 0x4c6410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042010e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042010f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420110  ebd6                   -jmp 0x4200e8
    goto L_0x004200e8;
L_0x00420112:
    // 00420112  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00420115  e8ee010700             -call 0x490308
    cpu.esp -= 4;
    sub_490308(app, cpu);
    if (cpu.terminate) return;
    // 0042011a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042011c  74ca                   -je 0x4200e8
    if (cpu.flags.zf)
    {
        goto L_0x004200e8;
    }
    // 0042011e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420120  ff15e04b4d00           -call dword ptr [0x4d4be0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5065696) /* 0x4d4be0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420126  8b4330                 -mov eax, dword ptr [ebx + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 00420129  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042012a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042012b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420131  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420132  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420134  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420136  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 0042013b  c7403000000000         -mov dword ptr [eax + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00420142  8b1500724e00           -mov edx, dword ptr [0x4e7200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5140992) /* 0x4e7200 */);
    // 00420148  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420149  2eff1510644c00         -call dword ptr cs:[0x4c6410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006352) /* 0x4c6410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420150  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420155  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420156  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420157  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420162  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420163  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420164  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420165  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420167  a318724e00             -mov dword ptr [0x4e7218], eax
    app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */) = cpu.eax;
    // 0042016c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0042016e  8915e04b4d00           -mov dword ptr [0x4d4be0], edx
    app->getMemory<x86::reg32>(x86::reg32(5065696) /* 0x4d4be0 */) = cpu.edx;
    // 00420174  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420176  891538724e00           -mov dword ptr [0x4e7238], edx
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = cpu.edx;
    // 0042017c  c74034ffffffff         -mov dword ptr [eax + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 00420183  68f0714e00             -push 0x4e71f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5140976 /*0x4e71f0*/;
    cpu.esp -= 4;
    // 00420188  895030                 -mov dword ptr [eax + 0x30], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0042018b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00420190  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00420195  b890024200             -mov eax, 0x420290
    cpu.eax = 4326032 /*0x420290*/;
    // 0042019a  890d34724e00           -mov dword ptr [0x4e7234], ecx
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = cpu.ecx;
    // 004201a0  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004201a5  e836990600             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 004201aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004201ac  0f84b3000000           -je 0x420265
    if (cpu.flags.zf)
    {
        goto L_0x00420265;
    }
    // 004201b2  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
L_0x004201b7:
    // 004201b7  833d34724e0000         +cmp dword ptr [0x4e7234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004201be  7416                   -je 0x4201d6
    if (cpu.flags.zf)
    {
        goto L_0x004201d6;
    }
    // 004201c0  8b1dccab4d00           -mov ebx, dword ptr [0x4dabcc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 004201c6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004201c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004201ca  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004201cd  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004201cf  e8c8990600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004201d4  ebe1                   -jmp 0x4201b7
    goto L_0x004201b7;
L_0x004201d6:
    // 004201d6  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004201db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004201dd:
    // 004201dd  8b2d34724e00           -mov ebp, dword ptr [0x4e7234]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */);
    // 004201e3  39e9                   +cmp ecx, ebp
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
    // 004201e5  752a                   -jne 0x420211
    if (!cpu.flags.zf)
    {
        goto L_0x00420211;
    }
    // 004201e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004201e9  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004201ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004201ee  7521                   -jne 0x420211
    if (!cpu.flags.zf)
    {
        goto L_0x00420211;
    }
    // 004201f0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004201f2  e8b93c0600             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 004201f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004201f9  7c16                   -jl 0x420211
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420211;
    }
    // 004201fb  8b2dccab4d00           -mov ebp, dword ptr [0x4dabcc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00420201  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00420203  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420205  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00420208  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042020a  e88d990600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 0042020f  ebcc                   -jmp 0x4201dd
    goto L_0x004201dd;
L_0x00420211:
    // 00420211  833d34724e0000         +cmp dword ptr [0x4e7234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420218  7540                   -jne 0x42025a
    if (!cpu.flags.zf)
    {
        goto L_0x0042025a;
    }
L_0x0042021a:
    // 0042021a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042021c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042021e  c7473000000000         -mov dword ptr [edi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00420225  68c8040000             -push 0x4c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1224 /*0x4c8*/;
    cpu.esp -= 4;
    // 0042022a  8b0d00724e00           -mov ecx, dword ptr [0x4e7200]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5140992) /* 0x4e7200 */);
    // 00420230  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420231  2eff1510644c00         -call dword ptr cs:[0x4c6410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006352) /* 0x4c6410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00420238:
    // 00420238  837f3000               +cmp dword ptr [edi + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042023c  7413                   -je 0x420251
    if (cpu.flags.zf)
    {
        goto L_0x00420251;
    }
    // 0042023e  833d38724e0009         +cmp dword ptr [0x4e7238], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420245  750a                   -jne 0x420251
    if (!cpu.flags.zf)
    {
        goto L_0x00420251;
    }
    // 00420247  8b0d2c724e00           -mov ecx, dword ptr [0x4e722c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141036) /* 0x4e722c */);
    // 0042024d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042024f  7520                   -jne 0x420271
    if (!cpu.flags.zf)
    {
        goto L_0x00420271;
    }
L_0x00420251:
    // 00420251  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00420254  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420255  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420256  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420257  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420258  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420259  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042025a:
    // 0042025a  833d38724e0009         +cmp dword ptr [0x4e7238], 9
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420261  75b7                   -jne 0x42021a
    if (!cpu.flags.zf)
    {
        goto L_0x0042021a;
    }
    // 00420263  ebd3                   -jmp 0x420238
    goto L_0x00420238;
L_0x00420265:
    // 00420265  c70538724e0001000000   -mov dword ptr [0x4e7238], 1
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 1 /*0x1*/;
    // 0042026f  ebc7                   -jmp 0x420238
    goto L_0x00420238;
L_0x00420271:
    // 00420271  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00420276  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00420278  e897fb0600             -call 0x48fe14
    cpu.esp -= 4;
    sub_48fe14(app, cpu);
    if (cpu.terminate) return;
    // 0042027d  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00420280  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00420283  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420284  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420285  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420286  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420287  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420288  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420290  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420291  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00420294  a118724e00             -mov eax, dword ptr [0x4e7218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */);
    // 00420299  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0042029c  e88f070000             -call 0x420a30
    cpu.esp -= 4;
    sub_420a30(app, cpu);
    if (cpu.terminate) return;
    // 004202a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004202a3  0f84c4000000           -je 0x42036d
    if (cpu.flags.zf)
    {
        goto L_0x0042036d;
    }
    // 004202a9  a118724e00             -mov eax, dword ptr [0x4e7218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */);
    // 004202ae  83786400               +cmp dword ptr [eax + 0x64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202b2  0f8583000000           -jne 0x42033b
    if (!cpu.flags.zf)
    {
        goto L_0x0042033b;
    }
    // 004202b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004202bd:
    // 004202bd  e82e080000             -call 0x420af0
    cpu.esp -= 4;
    sub_420af0(app, cpu);
    if (cpu.terminate) return;
    // 004202c2  a338724e00             -mov dword ptr [0x4e7238], eax
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = cpu.eax;
    // 004202c7  833d38724e0000         +cmp dword ptr [0x4e7238], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004202ce  0f858f000000           -jne 0x420363
    if (!cpu.flags.zf)
    {
        goto L_0x00420363;
    }
    // 004202d4  c70538724e0002000000   -mov dword ptr [0x4e7238], 2
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 2 /*0x2*/;
    // 004202de  a118724e00             -mov eax, dword ptr [0x4e7218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */);
    // 004202e3  8b6864                 -mov ebp, dword ptr [eax + 0x64]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 004202e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004202e8  7558                   -jne 0x420342
    if (!cpu.flags.zf)
    {
        goto L_0x00420342;
    }
L_0x004202ea:
    // 004202ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004202ef:
    // 004202ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004202f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004202f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004202f2  8b1518724e00           -mov edx, dword ptr [0x4e7218]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */);
    // 004202f8  894230                 -mov dword ptr [edx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004202fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004202fd  a334724e00             -mov dword ptr [0x4e7234], eax
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = cpu.eax;
    // 00420302  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00420304:
    // 00420304  a118724e00             -mov eax, dword ptr [0x4e7218]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */);
    // 00420309  3b5830                 +cmp ebx, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042030c  744d                   -je 0x42035b
    if (cpu.flags.zf)
    {
        goto L_0x0042035b;
    }
    // 0042030e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042030f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420311  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00420315  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420316  2eff15f4634c00         -call dword ptr cs:[0x4c63f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006324) /* 0x4c63f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042031d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042031f  742e                   -je 0x42034f
    if (cpu.flags.zf)
    {
        goto L_0x0042034f;
    }
    // 00420321  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420325  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420326  2eff1540644c00         -call dword ptr cs:[0x4c6440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006400) /* 0x4c6440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042032d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00420331  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420332  2eff15d8634c00         -call dword ptr cs:[0x4c63d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006296) /* 0x4c63d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420339  ebc9                   -jmp 0x420304
    goto L_0x00420304;
L_0x0042033b:
    // 0042033b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042033d  e97bffffff             -jmp 0x4202bd
    goto L_0x004202bd;
L_0x00420342:
    // 00420342  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420344  e837010000             -call 0x420480
    cpu.esp -= 4;
    sub_420480(app, cpu);
    if (cpu.terminate) return;
    // 00420349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042034b  759d                   -jne 0x4202ea
    if (!cpu.flags.zf)
    {
        goto L_0x004202ea;
    }
    // 0042034d  eba0                   -jmp 0x4202ef
    goto L_0x004202ef;
L_0x0042034f:
    // 0042034f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420354  e843980600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00420359  eba9                   -jmp 0x420304
    goto L_0x00420304;
L_0x0042035b:
    // 0042035b  e830000000             -call 0x420390
    cpu.esp -= 4;
    sub_420390(app, cpu);
    if (cpu.terminate) return;
    // 00420360  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420361  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420362  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00420363:
    // 00420363  e848080000             -call 0x420bb0
    cpu.esp -= 4;
    sub_420bb0(app, cpu);
    if (cpu.terminate) return;
    // 00420368  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042036b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042036c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042036d:
    // 0042036d  c70538724e0002000080   -mov dword ptr [0x4e7238], 0x80000002
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 2147483650 /*0x80000002*/;
    // 00420377  a318724e00             -mov dword ptr [0x4e7218], eax
    app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */) = cpu.eax;
    // 0042037c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0042037f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420380  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420391  8b1524724e00           -mov edx, dword ptr [0x4e7224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5141028) /* 0x4e7224 */);
    // 00420397  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420399  7502                   -jne 0x42039d
    if (!cpu.flags.zf)
    {
        goto L_0x0042039d;
    }
    // 0042039b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042039c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042039d:
    // 0042039d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042039e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042039f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004203a1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004203a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004203a4  bbec984c00             -mov ebx, 0x4c98ec
    cpu.ebx = 5019884 /*0x4c98ec*/;
    // 004203a9  e8db430a00             -call 0x4c4789
    cpu.esp -= 4;
    sub_4c4789(app, cpu);
    if (cpu.terminate) return;
    // 004203ae  891dc4be4d00           -mov dword ptr [0x4dbec4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.ebx;
    // 004203b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004203b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4203c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004203c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004203c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004203c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004203c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004203c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004203c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004203c6  ba10984c00             -mov edx, 0x4c9810
    cpu.edx = 5019664 /*0x4c9810*/;
    // 004203cb  b9ba020000             -mov ecx, 0x2ba
    cpu.ecx = 698 /*0x2ba*/;
    // 004203d0  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004203d5  b8dc984c00             -mov eax, 0x4c98dc
    cpu.eax = 5019868 /*0x4c98dc*/;
    // 004203da  bd10984c00             -mov ebp, 0x4c9810
    cpu.ebp = 5019664 /*0x4c9810*/;
    // 004203df  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 004203e5  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004203ea  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 004203f0  e8a3400600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004203f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004203f7  c70018000000           -mov dword ptr [eax], 0x18
    app->getMemory<x86::reg32>(cpu.eax) = 24 /*0x18*/;
L_0x004203fd:
    // 004203fd  68a8984c00             -push 0x4c98a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019816 /*0x4c98a8*/;
    cpu.esp -= 4;
    // 00420402  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420403  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00420405  8b3524724e00           -mov esi, dword ptr [0x4e7224]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5141028) /* 0x4e7224 */);
    // 0042040b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042040c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042040e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420410  e85c440a00             -call 0x4c4871
    cpu.esp -= 4;
    sub_4c4871(app, cpu);
    if (cpu.terminate) return;
    // 00420415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420417  7535                   -jne 0x42044e
    if (!cpu.flags.zf)
    {
        goto L_0x0042044e;
    }
    // 00420419  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0042041c  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042041e  7641                   -jbe 0x420461
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420461;
    }
    // 00420420  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420422  e8d5440600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00420427  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00420429  b8cd020000             -mov eax, 0x2cd
    cpu.eax = 717 /*0x2cd*/;
    // 0042042e  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00420433  a3dcb14d00             -mov dword ptr [0x4db1dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.eax;
    // 00420438  b8dc984c00             -mov eax, 0x4c98dc
    cpu.eax = 5019868 /*0x4c98dc*/;
    // 0042043d  892dd8b14d00           -mov dword ptr [0x4db1d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebp;
    // 00420443  e850400600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00420448  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042044a  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0042044c  ebaf                   -jmp 0x4203fd
    goto L_0x004203fd;
L_0x0042044e:
    // 0042044e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00420450  e8a7440600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00420455  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0042045a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042045b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042045c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042045d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042045e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042045f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420460  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420461:
    // 00420461  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00420464  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00420467  a32c724e00             -mov dword ptr [0x4e722c], eax
    app->getMemory<x86::reg32>(x86::reg32(5141036) /* 0x4e722c */) = cpu.eax;
    // 0042046c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042046e  e889440600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00420473  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420475  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420476  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420477  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420478  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420479  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042047a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042047b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420484  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420485  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420487  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420489  740b                   -je 0x420496
    if (cpu.flags.zf)
    {
        goto L_0x00420496;
    }
    // 0042048b  833d10724e0000         +cmp dword ptr [0x4e7210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420492  7508                   -jne 0x42049c
    if (!cpu.flags.zf)
    {
        goto L_0x0042049c;
    }
    // 00420494  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00420496:
    // 00420496  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420497  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420498  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420499  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042049a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042049b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042049c:
    // 0042049c  bb10984c00             -mov ebx, 0x4c9810
    cpu.ebx = 5019664 /*0x4c9810*/;
    // 004204a1  be97020000             -mov esi, 0x297
    cpu.esi = 663 /*0x297*/;
    // 004204a6  ba70000000             -mov edx, 0x70
    cpu.edx = 112 /*0x70*/;
    // 004204ab  b8c8984c00             -mov eax, 0x4c98c8
    cpu.eax = 5019848 /*0x4c98c8*/;
    // 004204b0  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 004204b6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004204bb  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 004204c1  e8d23f0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004204c6  bb70000000             -mov ebx, 0x70
    cpu.ebx = 112 /*0x70*/;
    // 004204cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004204cd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004204cf  e85b210700             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004204d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004204d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004204d7  c70670000000           -mov dword ptr [esi], 0x70
    app->getMemory<x86::reg32>(cpu.esi) = 112 /*0x70*/;
    // 004204dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004204de  c7460401000000         -mov dword ptr [esi + 4], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004204e5  6824724e00             -push 0x4e7224
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141028 /*0x4e7224*/;
    cpu.esp -= 4;
    // 004204ea  8b3d10724e00           -mov edi, dword ptr [0x4e7210]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
    // 004204f0  c7461010000000         -mov dword ptr [esi + 0x10], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 16 /*0x10*/;
    // 004204f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004204f8  c7462cb80b0000         -mov dword ptr [esi + 0x2c], 0xbb8
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 3000 /*0xbb8*/;
    // 004204ff  e85b440a00             -call 0x4c495f
    cpu.esp -= 4;
    sub_4c495f(app, cpu);
    if (cpu.terminate) return;
    // 00420504  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420506  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00420508  e8ef430600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0042050d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042050f  7c0b                   -jl 0x42051c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042051c;
    }
    // 00420511  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420516  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420517  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420518  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420519  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042051a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042051b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042051c:
    // 0042051c  c70538724e000f000000   -mov dword ptr [0x4e7238], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 15 /*0xf*/;
    // 00420526  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420528  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420529  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042052a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042052b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042052c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042052d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_420530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420530  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420531  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420532  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420533  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420534  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420535  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420536  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420538  8b151c724e00           -mov edx, dword ptr [0x4e721c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 0042053e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420540  0f8598000000           -jne 0x4205de
    if (!cpu.flags.zf)
    {
        goto L_0x004205de;
    }
L_0x00420546:
    // 00420546  bb10984c00             -mov ebx, 0x4c9810
    cpu.ebx = 5019664 /*0x4c9810*/;
    // 0042054b  bf6a020000             -mov edi, 0x26a
    cpu.edi = 618 /*0x26a*/;
    // 00420550  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 00420555  b8b8984c00             -mov eax, 0x4c98b8
    cpu.eax = 5019832 /*0x4c98b8*/;
    // 0042055a  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 00420560  893ddcb14d00           -mov dword ptr [0x4db1dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.edi;
    // 00420566  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0042056b  bf10984c00             -mov edi, 0x4c9810
    cpu.edi = 5019664 /*0x4c9810*/;
    // 00420570  e8233f0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00420575  a31c724e00             -mov dword ptr [0x4e721c], eax
    app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */) = cpu.eax;
    // 0042057a  c700f0000000           -mov dword ptr [eax], 0xf0
    app->getMemory<x86::reg32>(cpu.eax) = 240 /*0xf0*/;
L_0x00420580:
    // 00420580  8b2d1c724e00           -mov ebp, dword ptr [0x4e721c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 00420586  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420587  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420589  a120724e00             -mov eax, dword ptr [0x4e7220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141024) /* 0x4e7220 */);
    // 0042058e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042058f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420590  8b1504724e00           -mov edx, dword ptr [0x4e7204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 00420596  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420597  e838420a00             -call 0x4c47d4
    cpu.esp -= 4;
    sub_4c47d4(app, cpu);
    if (cpu.terminate) return;
    // 0042059c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042059e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004205a0  7550                   -jne 0x4205f2
    if (!cpu.flags.zf)
    {
        goto L_0x004205f2;
    }
    // 004205a2  a11c724e00             -mov eax, dword ptr [0x4e721c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 004205a7  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004205aa  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004205ac  7655                   -jbe 0x420603
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420603;
    }
    // 004205ae  e849430600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004205b3  bd7f020000             -mov ebp, 0x27f
    cpu.ebp = 639 /*0x27f*/;
    // 004205b8  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004205bd  b8b8984c00             -mov eax, 0x4c98b8
    cpu.eax = 5019832 /*0x4c98b8*/;
    // 004205c2  893dd8b14d00           -mov dword ptr [0x4db1d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edi;
    // 004205c8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004205ca  892ddcb14d00           -mov dword ptr [0x4db1dc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebp;
    // 004205d0  e8c33e0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004205d5  a31c724e00             -mov dword ptr [0x4e721c], eax
    app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */) = cpu.eax;
    // 004205da  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004205dc  eba2                   -jmp 0x420580
    goto L_0x00420580;
L_0x004205de:
    // 004205de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004205e0  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004205e2  e815430600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004205e7  890d1c724e00           -mov dword ptr [0x4e721c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */) = cpu.ecx;
    // 004205ed  e954ffffff             -jmp 0x420546
    goto L_0x00420546;
L_0x004205f2:
    // 004205f2  a11c724e00             -mov eax, dword ptr [0x4e721c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 004205f7  e800430600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004205fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004205fe  a31c724e00             -mov dword ptr [0x4e721c], eax
    app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */) = cpu.eax;
L_0x00420603:
    // 00420603  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420605  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420606  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420607  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420608  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420609  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042060a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042060b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_420610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420613  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420614  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 0042061a  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 0042061f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00420621  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420623  e807200700             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 00420628  68a8984c00             -push 0x4c98a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019816 /*0x4c98a8*/;
    cpu.esp -= 4;
    // 0042062d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420631  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420632  8b0ddc4b4d00           -mov ecx, dword ptr [0x4d4bdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */);
    // 00420638  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 0042063d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042063e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00420642  e8df410a00             -call 0x4c4826
    cpu.esp -= 4;
    sub_4c4826(app, cpu);
    if (cpu.terminate) return;
    // 00420647  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420649  7509                   -jne 0x420654
    if (!cpu.flags.zf)
    {
        goto L_0x00420654;
    }
    // 0042064b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042064f  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00420652  760d                   -jbe 0x420661
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420661;
    }
L_0x00420654:
    // 00420654  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420656  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 0042065c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042065d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042065e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042065f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420660  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420661:
    // 00420661  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420662  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420666  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0042066a  8d503c                 -lea edx, [eax + 0x3c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 0042066d  806220f8               -and byte ptr [edx + 0x20], 0xf8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(32) /* 0x20 */) &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00420671  68a8984c00             -push 0x4c98a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019816 /*0x4c98a8*/;
    cpu.esp -= 4;
    // 00420676  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0042067a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042067b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042067c  8b2ddc4b4d00           -mov ebp, dword ptr [0x4d4bdc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */);
    // 00420682  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420683  e8dc430a00             -call 0x4c4a64
    cpu.esp -= 4;
    sub_4c4a64(app, cpu);
    if (cpu.terminate) return;
    // 00420688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042068a  7405                   -je 0x420691
    if (cpu.flags.zf)
    {
        goto L_0x00420691;
    }
    // 0042068c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00420691:
    // 00420691  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420692  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420698  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420699  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042069a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042069b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042069c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4206a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004206a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004206a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004206a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004206a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004206a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004206a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004206a6  81ec401f0000           -sub esp, 0x1f40
    (cpu.esp) -= x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004206ac  bb401f0000             -mov ebx, 0x1f40
    cpu.ebx = 8000 /*0x1f40*/;
    // 004206b1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004206b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004206b5  e8751f0700             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004206ba  68a8984c00             -push 0x4c98a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019816 /*0x4c98a8*/;
    cpu.esp -= 4;
    // 004206bf  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004206c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004206c4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004206c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004206c8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004206ca  8b0d10724e00           -mov ecx, dword ptr [0x4e7210]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
    // 004206d0  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004206d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004206d6  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004206da  e892410a00             -call 0x4c4871
    cpu.esp -= 4;
    sub_4c4871(app, cpu);
    if (cpu.terminate) return;
    // 004206df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004206e1  740f                   -je 0x4206f2
    if (cpu.flags.zf)
    {
        goto L_0x004206f2;
    }
L_0x004206e3:
    // 004206e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004206e5  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 004206eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004206ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004206ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004206ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004206ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004206f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004206f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004206f2:
    // 004206f2  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004206f4  035c2414               -add ebx, dword ptr [esp + 0x14]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004206f8  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 004206fd  68f0614e00             -push 0x4e61f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5136880 /*0x4e61f0*/;
    cpu.esp -= 4;
    // 00420702  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00420704  bf2ef53ce7             -mov edi, 0xe73cf52e
    cpu.edi = 3879531822 /*0xe73cf52e*/;
    // 00420709  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0042070a  668915f0614e00         -mov word ptr [0x4e61f0], dx
    app->getMemory<x86::reg16>(x86::reg32(5136880) /* 0x4e61f0 */) = cpu.dx;
    // 00420711  893d24624e00           -mov dword ptr [0x4e6224], edi
    app->getMemory<x86::reg32>(x86::reg32(5136932) /* 0x4e6224 */) = cpu.edi;
    // 00420717  2eff15ac644c00         -call dword ptr cs:[0x4c64ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006508) /* 0x4c64ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042071e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00420720  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00420722  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420723  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042072a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042072c  74b5                   -je 0x4206e3
    if (cpu.flags.zf)
    {
        goto L_0x004206e3;
    }
    // 0042072e  b8f0614e00             -mov eax, 0x4e61f0
    cpu.eax = 5136880 /*0x4e61f0*/;
    // 00420733  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00420736  a308724e00             -mov dword ptr [0x4e7208], eax
    app->getMemory<x86::reg32>(x86::reg32(5141000) /* 0x4e7208 */) = cpu.eax;
    // 0042073b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420740  81c4401f0000           -add esp, 0x1f40
    (cpu.esp) += x86::reg32(x86::sreg32(8000 /*0x1f40*/));
    // 00420746  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420747  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420748  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420749  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042074a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042074b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042074c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_420750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420753  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420754  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420755  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420758  8b15dc4b4d00           -mov edx, dword ptr [0x4d4bdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */);
    // 0042075e  83faff                 +cmp edx, -1
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
    // 00420761  750b                   -jne 0x42076e
    if (!cpu.flags.zf)
    {
        goto L_0x0042076e;
    }
L_0x00420763:
    // 00420763  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420765  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420768  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420769  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042076a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042076b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042076c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042076d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042076e:
    // 0042076e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00420770  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420771  6820724e00             -push 0x4e7220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141024 /*0x4e7220*/;
    cpu.esp -= 4;
    // 00420776  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 0042077b  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 00420780  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420781  8b1d04724e00           -mov ebx, dword ptr [0x4e7204]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 00420787  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420788  e824420a00             -call 0x4c49b1
    cpu.esp -= 4;
    sub_4c49b1(app, cpu);
    if (cpu.terminate) return;
    // 0042078d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042078f  75d2                   -jne 0x420763
    if (!cpu.flags.zf)
    {
        goto L_0x00420763;
    }
    // 00420791  a1dc4b4d00             -mov eax, dword ptr [0x4d4bdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */);
    // 00420796  e895fdffff             -call 0x420530
    cpu.esp -= 4;
    sub_420530(app, cpu);
    if (cpu.terminate) return;
    // 0042079b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042079d  75c4                   -jne 0x420763
    if (!cpu.flags.zf)
    {
        goto L_0x00420763;
    }
    // 0042079f  833d0c724e0000         +cmp dword ptr [0x4e720c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141004) /* 0x4e720c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004207a6  746b                   -je 0x420813
    if (cpu.flags.zf)
    {
        goto L_0x00420813;
    }
    // 004207a8  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004207ad:
    // 004207ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004207af  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004207b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004207b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004207b4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004207b6  8b3d20724e00           -mov edi, dword ptr [0x4e7220]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5141024) /* 0x4e7220 */);
    // 004207bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004207bd  6810724e00             -push 0x4e7210
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141008 /*0x4e7210*/;
    cpu.esp -= 4;
    // 004207c2  8b2ddc4b4d00           -mov ebp, dword ptr [0x4d4bdc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */);
    // 004207c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004207c9  a104724e00             -mov eax, dword ptr [0x4e7204]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 004207ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004207cf  e832420a00             -call 0x4c4a06
    cpu.esp -= 4;
    sub_4c4a06(app, cpu);
    if (cpu.terminate) return;
    // 004207d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004207d6  758b                   -jne 0x420763
    if (!cpu.flags.zf)
    {
        goto L_0x00420763;
    }
    // 004207d8  833d08724e0000         +cmp dword ptr [0x4e7208], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141000) /* 0x4e7208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004207df  7424                   -je 0x420805
    if (cpu.flags.zf)
    {
        goto L_0x00420805;
    }
    // 004207e1  a110724e00             -mov eax, dword ptr [0x4e7210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
    // 004207e6  e825feffff             -call 0x420610
    cpu.esp -= 4;
    sub_420610(app, cpu);
    if (cpu.terminate) return;
    // 004207eb  a11c724e00             -mov eax, dword ptr [0x4e721c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 004207f0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004207f2  8b8880000000           -mov ecx, dword ptr [eax + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004207f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004207f9  8b1d10724e00           -mov ebx, dword ptr [0x4e7210]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
    // 004207ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420800  e8ae420a00             -call 0x4c4ab3
    cpu.esp -= 4;
    sub_4c4ab3(app, cpu);
    if (cpu.terminate) return;
L_0x00420805:
    // 00420805  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042080a  83c410                 +add esp, 0x10
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
    // 0042080d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042080e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042080f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420810  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420811  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420812  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420813:
    // 00420813  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420818  eb93                   -jmp 0x4207ad
    goto L_0x004207ad;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420821  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420822  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420823  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420824  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00420827  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420829  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 0042082b  891514724e00           -mov dword ptr [0x4e7214], edx
    app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */) = cpu.edx;
    // 00420831  e89a020700             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00420836  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420837  2eff15fc634c00         -call dword ptr cs:[0x4c63fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006332) /* 0x4c63fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042083e  6828724e00             -push 0x4e7228
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141032 /*0x4e7228*/;
    cpu.esp -= 4;
    // 00420843  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420845  68100d4200             -push 0x420d10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4328720 /*0x420d10*/;
    cpu.esp -= 4;
    // 0042084a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042084b  6804724e00             -push 0x4e7204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5140996 /*0x4e7204*/;
    cpu.esp -= 4;
    // 00420850  e8b8400a00             -call 0x4c490d
    cpu.esp -= 4;
    sub_4c490d(app, cpu);
    if (cpu.terminate) return;
    // 00420855  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420857  0f8505010000           -jne 0x420962
    if (!cpu.flags.zf)
    {
        goto L_0x00420962;
    }
    // 0042085d  833d28724e0000         +cmp dword ptr [0x4e7228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141032) /* 0x4e7228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420864  0f84fc000000           -je 0x420966
    if (cpu.flags.zf)
    {
        goto L_0x00420966;
    }
    // 0042086a  833d30724e0000         +cmp dword ptr [0x4e7230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420871  7433                   -je 0x4208a6
    if (cpu.flags.zf)
    {
        goto L_0x004208a6;
    }
    // 00420873  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00420875:
    // 00420875  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 0042087a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042087c  8b6804                 -mov ebp, dword ptr [eax + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0042087f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00420881  7407                   -je 0x42088a
    if (cpu.flags.zf)
    {
        goto L_0x0042088a;
    }
    // 00420883  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420885  e872400600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0042088a:
    // 0042088a  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0042088d  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420893  75e0                   -jne 0x420875
    if (!cpu.flags.zf)
    {
        goto L_0x00420875;
    }
    // 00420895  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 0042089a  e85d400600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 0042089f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004208a1  a330724e00             -mov dword ptr [0x4e7230], eax
    app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */) = cpu.eax;
L_0x004208a6:
    // 004208a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004208a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004208a8  ba10984c00             -mov edx, 0x4c9810
    cpu.edx = 5019664 /*0x4c9810*/;
    // 004208ad  b9b7010000             -mov ecx, 0x1b7
    cpu.ecx = 439 /*0x1b7*/;
    // 004208b2  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004208b7  b890984c00             -mov eax, 0x4c9890
    cpu.eax = 5019792 /*0x4c9890*/;
    // 004208bc  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004208be  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 004208c4  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 004208c9  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 004208cf  e8c43b0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004208d4  a330724e00             -mov dword ptr [0x4e7230], eax
    app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */) = cpu.eax;
    // 004208d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004208db:
    // 004208db  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 004208e0  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004208e3  895406fc               -mov dword ptr [esi + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004208e7  895406f8               -mov dword ptr [esi + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 004208eb  81fea0000000           +cmp esi, 0xa0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004208f1  75e8                   -jne 0x4208db
    if (!cpu.flags.zf)
    {
        goto L_0x004208db;
    }
    // 004208f3  8b1d28724e00           -mov ebx, dword ptr [0x4e7228]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5141032) /* 0x4e7228 */);
    // 004208f9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004208fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004208fd  7630                   -jbe 0x42092f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042092f;
    }
L_0x004208ff:
    // 004208ff  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00420903  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420904  6820724e00             -push 0x4e7220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141024 /*0x4e7220*/;
    cpu.esp -= 4;
    // 00420909  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 0042090e  6804000100             -push 0x10004
    app->getMemory<x86::reg32>(cpu.esp-4) = 65540 /*0x10004*/;
    cpu.esp -= 4;
    // 00420913  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420914  8b1504724e00           -mov edx, dword ptr [0x4e7204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 0042091a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042091b  e891400a00             -call 0x4c49b1
    cpu.esp -= 4;
    sub_4c49b1(app, cpu);
    if (cpu.terminate) return;
    // 00420920  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420922  746a                   -je 0x42098e
    if (cpu.flags.zf)
    {
        goto L_0x0042098e;
    }
L_0x00420924:
    // 00420924  8b3d28724e00           -mov edi, dword ptr [0x4e7228]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5141032) /* 0x4e7228 */);
    // 0042092a  46                     -inc esi
    (cpu.esi)++;
    // 0042092b  39fe                   +cmp esi, edi
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
    // 0042092d  72d0                   -jb 0x4208ff
    if (cpu.flags.cf)
    {
        goto L_0x004208ff;
    }
L_0x0042092f:
    // 0042092f  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 00420934  e863920600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00420939  8b2d04724e00           -mov ebp, dword ptr [0x4e7204]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 0042093f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420940  e8b9410a00             -call 0x4c4afe
    cpu.esp -= 4;
    sub_4c4afe(app, cpu);
    if (cpu.terminate) return;
    // 00420945  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420947  740a                   -je 0x420953
    if (cpu.flags.zf)
    {
        goto L_0x00420953;
    }
    // 00420949  c705c4be4d00f8974c00   -mov dword ptr [0x4dbec4], 0x4c97f8
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = 5019640 /*0x4c97f8*/;
L_0x00420953:
    // 00420953  a114724e00             -mov eax, dword ptr [0x4e7214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */);
    // 00420958  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420959  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042095a:
    // 0042095a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042095d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042095e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042095f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420960  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420961  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420962:
    // 00420962  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00420964  ebf4                   -jmp 0x42095a
    goto L_0x0042095a;
L_0x00420966:
    // 00420966  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 0042096b  e82c920600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00420970  8b3504724e00           -mov esi, dword ptr [0x4e7204]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 00420976  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420977  e882410a00             -call 0x4c4afe
    cpu.esp -= 4;
    sub_4c4afe(app, cpu);
    if (cpu.terminate) return;
    // 0042097c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042097e  740a                   -je 0x42098a
    if (cpu.flags.zf)
    {
        goto L_0x0042098a;
    }
    // 00420980  c705c4be4d00f8974c00   -mov dword ptr [0x4dbec4], 0x4c97f8
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = 5019640 /*0x4c97f8*/;
L_0x0042098a:
    // 0042098a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042098c  ebcc                   -jmp 0x42095a
    goto L_0x0042095a;
L_0x0042098e:
    // 0042098e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00420990  e89bfbffff             -call 0x420530
    cpu.esp -= 4;
    sub_420530(app, cpu);
    if (cpu.terminate) return;
    // 00420995  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420997  758b                   -jne 0x420924
    if (!cpu.flags.zf)
    {
        goto L_0x00420924;
    }
    // 00420999  a11c724e00             -mov eax, dword ptr [0x4e721c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 0042099e  f6403c10               +test byte ptr [eax + 0x3c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(60) /* 0x3c */) & 16 /*0x10*/));
    // 004209a2  7480                   -je 0x420924
    if (cpu.flags.zf)
    {
        goto L_0x00420924;
    }
    // 004209a4  b910984c00             -mov ecx, 0x4c9810
    cpu.ecx = 5019664 /*0x4c9810*/;
    // 004209a9  bbcf010000             -mov ebx, 0x1cf
    cpu.ebx = 463 /*0x1cf*/;
    // 004209ae  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004209b1  b89c984c00             -mov eax, 0x4c989c
    cpu.eax = 5019804 /*0x4c989c*/;
    // 004209b6  891ddcb14d00           -mov dword ptr [0x4db1dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebx;
    // 004209bc  42                     -inc edx
    (cpu.edx)++;
    // 004209bd  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004209c2  890dd8b14d00           -mov dword ptr [0x4db1d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ecx;
    // 004209c8  e8e33a0600             -call 0x4844b0
    cpu.esp -= 4;
    sub_4844b0(app, cpu);
    if (cpu.terminate) return;
    // 004209cd  8b0d14724e00           -mov ecx, dword ptr [0x4e7214]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */);
    // 004209d3  8b1530724e00           -mov edx, dword ptr [0x4e7230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 004209d9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004209dc  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004209de  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004209e1  a11c724e00             -mov eax, dword ptr [0x4e721c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 004209e6  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004209e9  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004209ec  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004209ee  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004209f1  e8e65a0600             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 004209f6  8b1514724e00           -mov edx, dword ptr [0x4e7214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */);
    // 004209fc  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 00420a01  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00420a04  8b0d1c724e00           -mov ecx, dword ptr [0x4e721c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 00420a0a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00420a0c  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00420a0f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00420a12  8b2d14724e00           -mov ebp, dword ptr [0x4e7214]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */);
    // 00420a18  01fa                   +add edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420a1a  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00420a1b  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00420a1e  892d14724e00           -mov dword ptr [0x4e7214], ebp
    app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */) = cpu.ebp;
    // 00420a24  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00420a26  e9f9feffff             -jmp 0x420924
    goto L_0x00420924;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420a30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420a31  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420a33  833d30724e0000         +cmp dword ptr [0x4e7230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a3a  741c                   -je 0x420a58
    if (cpu.flags.zf)
    {
        goto L_0x00420a58;
    }
L_0x00420a3c:
    // 00420a3c  3b1514724e00           +cmp edx, dword ptr [0x4e7214]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420a42  7d1b                   -jge 0x420a5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420a5f;
    }
    // 00420a44  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 00420a49  8b04d0                 -mov eax, dword ptr [eax + edx*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 00420a4c  a3dc4b4d00             -mov dword ptr [0x4d4bdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */) = cpu.eax;
    // 00420a51  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420a56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420a58:
    // 00420a58  e8c3fdffff             -call 0x420820
    cpu.esp -= 4;
    sub_420820(app, cpu);
    if (cpu.terminate) return;
    // 00420a5d  ebdd                   -jmp 0x420a3c
    goto L_0x00420a3c;
L_0x00420a5f:
    // 00420a5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420a61  be10984c00             -mov esi, 0x4c9810
    cpu.esi = 5019664 /*0x4c9810*/;
    // 00420a66  bf82010000             -mov edi, 0x182
    cpu.edi = 386 /*0x182*/;
    // 00420a6b  6878984c00             -push 0x4c9878
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019768 /*0x4c9878*/;
    cpu.esp -= 4;
    // 00420a70  8935d8b14d00           -mov dword ptr [0x4db1d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.esi;
    // 00420a76  893ddcb14d00           -mov dword ptr [0x4db1dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.edi;
    // 00420a7c  e86f360600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00420a81  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420a84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420a86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420a89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420a90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420a91  6828724e00             -push 0x4e7228
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141032 /*0x4e7228*/;
    cpu.esp -= 4;
    // 00420a96  89150c724e00           -mov dword ptr [0x4e720c], edx
    app->getMemory<x86::reg32>(x86::reg32(5141004) /* 0x4e720c */) = cpu.edx;
    // 00420a9c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420a9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420a9f  68100d4200             -push 0x420d10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4328720 /*0x420d10*/;
    cpu.esp -= 4;
    // 00420aa4  89151c724e00           -mov dword ptr [0x4e721c], edx
    app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */) = cpu.edx;
    // 00420aaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420aab  89152c724e00           -mov dword ptr [0x4e722c], edx
    app->getMemory<x86::reg32>(x86::reg32(5141036) /* 0x4e722c */) = cpu.edx;
    // 00420ab1  891524724e00           -mov dword ptr [0x4e7224], edx
    app->getMemory<x86::reg32>(x86::reg32(5141028) /* 0x4e7224 */) = cpu.edx;
    // 00420ab7  6804724e00             -push 0x4e7204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5140996 /*0x4e7204*/;
    cpu.esp -= 4;
    // 00420abc  891510724e00           -mov dword ptr [0x4e7210], edx
    app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */) = cpu.edx;
    // 00420ac2  891530724e00           -mov dword ptr [0x4e7230], edx
    app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */) = cpu.edx;
    // 00420ac8  e8403e0a00             -call 0x4c490d
    cpu.esp -= 4;
    sub_4c490d(app, cpu);
    if (cpu.terminate) return;
    // 00420acd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420acf  7510                   -jne 0x420ae1
    if (!cpu.flags.zf)
    {
        goto L_0x00420ae1;
    }
    // 00420ad1  833d28724e0000         +cmp dword ptr [0x4e7228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141032) /* 0x4e7228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420ad8  7505                   -jne 0x420adf
    if (!cpu.flags.zf)
    {
        goto L_0x00420adf;
    }
    // 00420ada  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x00420adf:
    // 00420adf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ae0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420ae1:
    // 00420ae1  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00420ae6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ae7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420af1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420af2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420af3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00420af5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420af7  891538724e00           -mov dword ptr [0x4e7238], edx
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = cpu.edx;
    // 00420afd  833ddc4b4d00ff         +cmp dword ptr [0x4d4bdc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065692) /* 0x4d4bdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420b04  745b                   -je 0x420b61
    if (cpu.flags.zf)
    {
        goto L_0x00420b61;
    }
    // 00420b06  6afa                   -push -6
    app->getMemory<x86::reg32>(cpu.esp-4) = -6 /*-0x6*/;
    cpu.esp -= 4;
    // 00420b08  e8c3ff0600             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00420b0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420b0e  2eff15fc634c00         -call dword ptr cs:[0x4c63fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006332) /* 0x4c63fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420b15  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00420b1a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420b1c  e86fffffff             -call 0x420a90
    cpu.esp -= 4;
    sub_420a90(app, cpu);
    if (cpu.terminate) return;
    // 00420b21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00420b23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420b25  7568                   -jne 0x420b8f
    if (!cpu.flags.zf)
    {
        goto L_0x00420b8f;
    }
    // 00420b27  e824fcffff             -call 0x420750
    cpu.esp -= 4;
    sub_420750(app, cpu);
    if (cpu.terminate) return;
    // 00420b2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420b2e  746a                   -je 0x420b9a
    if (cpu.flags.zf)
    {
        goto L_0x00420b9a;
    }
    // 00420b30  e86bfbffff             -call 0x4206a0
    cpu.esp -= 4;
    sub_4206a0(app, cpu);
    if (cpu.terminate) return;
    // 00420b35  e876000000             -call 0x420bb0
    cpu.esp -= 4;
    sub_420bb0(app, cpu);
    if (cpu.terminate) return;
    // 00420b3a  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 00420b3f  e858900600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00420b44  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00420b46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00420b48  e843ffffff             -call 0x420a90
    cpu.esp -= 4;
    sub_420a90(app, cpu);
    if (cpu.terminate) return;
    // 00420b4d  83f80a                 +cmp eax, 0xa
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
    // 00420b50  7448                   -je 0x420b9a
    if (cpu.flags.zf)
    {
        goto L_0x00420b9a;
    }
    // 00420b52  e8f9fbffff             -call 0x420750
    cpu.esp -= 4;
    sub_420750(app, cpu);
    if (cpu.terminate) return;
    // 00420b57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420b59  7444                   -je 0x420b9f
    if (cpu.flags.zf)
    {
        goto L_0x00420b9f;
    }
    // 00420b5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420b5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420b61:
    // 00420b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420b62  bb10984c00             -mov ebx, 0x4c9810
    cpu.ebx = 5019664 /*0x4c9810*/;
    // 00420b67  be2f010000             -mov esi, 0x12f
    cpu.esi = 303 /*0x12f*/;
    // 00420b6c  6830984c00             -push 0x4c9830
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019696 /*0x4c9830*/;
    cpu.esp -= 4;
    // 00420b71  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 00420b77  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 00420b7d  e86e350600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00420b82  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00420b87  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420b8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420b8f:
    // 00420b8f  e81c000000             -call 0x420bb0
    cpu.esp -= 4;
    sub_420bb0(app, cpu);
    if (cpu.terminate) return;
    // 00420b94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420b96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420b99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420b9a:
    // 00420b9a  e811000000             -call 0x420bb0
    cpu.esp -= 4;
    sub_420bb0(app, cpu);
    if (cpu.terminate) return;
L_0x00420b9f:
    // 00420b9f  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00420ba4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ba5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ba6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420ba7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420bb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420bb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420bb5  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 00420bba  e8dd8f0600             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00420bbf  8b1524724e00           -mov edx, dword ptr [0x4e7224]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5141028) /* 0x4e7224 */);
    // 00420bc5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420bc7  0f85c5000000           -jne 0x420c92
    if (!cpu.flags.zf)
    {
        goto L_0x00420c92;
    }
L_0x00420bcd:
    // 00420bcd  8b1d10724e00           -mov ebx, dword ptr [0x4e7210]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
    // 00420bd3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00420bd5  7414                   -je 0x420beb
    if (cpu.flags.zf)
    {
        goto L_0x00420beb;
    }
    // 00420bd7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420bd8  e8263b0a00             -call 0x4c4703
    cpu.esp -= 4;
    sub_4c4703(app, cpu);
    if (cpu.terminate) return;
    // 00420bdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420bdf  740a                   -je 0x420beb
    if (cpu.flags.zf)
    {
        goto L_0x00420beb;
    }
    // 00420be1  c705c4be4d00c4974c00   -mov dword ptr [0x4dbec4], 0x4c97c4
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = 5019588 /*0x4c97c4*/;
L_0x00420beb:
    // 00420beb  8b2d18724e00           -mov ebp, dword ptr [0x4e7218]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */);
    // 00420bf1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00420bf3  0f84a4000000           -je 0x420c9d
    if (cpu.flags.zf)
    {
        goto L_0x00420c9d;
    }
    // 00420bf9  8b5534                 -mov edx, dword ptr [ebp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00420bfc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420bfe  83faff                 +cmp edx, -1
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
    // 00420c01  0f8496000000           -je 0x420c9d
    if (cpu.flags.zf)
    {
        goto L_0x00420c9d;
    }
    // 00420c07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00420c09  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00420c0b  e830f10600             -call 0x48fd40
    cpu.esp -= 4;
    sub_48fd40(app, cpu);
    if (cpu.terminate) return;
    // 00420c10  893d18724e00           -mov dword ptr [0x4e7218], edi
    app->getMemory<x86::reg32>(x86::reg32(5141016) /* 0x4e7218 */) = cpu.edi;
L_0x00420c16:
    // 00420c16  8b2d1c724e00           -mov ebp, dword ptr [0x4e721c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */);
    // 00420c1c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00420c1e  740e                   -je 0x420c2e
    if (cpu.flags.zf)
    {
        goto L_0x00420c2e;
    }
    // 00420c20  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00420c22  e8d53c0600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00420c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420c29  a31c724e00             -mov dword ptr [0x4e721c], eax
    app->getMemory<x86::reg32>(x86::reg32(5141020) /* 0x4e721c */) = cpu.eax;
L_0x00420c2e:
    // 00420c2e  833d30724e0000         +cmp dword ptr [0x4e7230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420c35  7445                   -je 0x420c7c
    if (cpu.flags.zf)
    {
        goto L_0x00420c7c;
    }
    // 00420c37  8b0d14724e00           -mov ecx, dword ptr [0x4e7214]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */);
    // 00420c3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00420c3f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00420c41  7e25                   -jle 0x420c68
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420c68;
    }
    // 00420c43  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00420c45:
    // 00420c45  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 00420c4a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00420c4c  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00420c4f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00420c51  7407                   -je 0x420c5a
    if (cpu.flags.zf)
    {
        goto L_0x00420c5a;
    }
    // 00420c53  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00420c55  e8a23c0600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x00420c5a:
    // 00420c5a  8b1d14724e00           -mov ebx, dword ptr [0x4e7214]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5141012) /* 0x4e7214 */);
    // 00420c60  42                     -inc edx
    (cpu.edx)++;
    // 00420c61  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00420c64  39da                   +cmp edx, ebx
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
    // 00420c66  7cdd                   -jl 0x420c45
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00420c45;
    }
L_0x00420c68:
    // 00420c68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420c69  a130724e00             -mov eax, dword ptr [0x4e7230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */);
    // 00420c6e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00420c70  e8873c0600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00420c75  893530724e00           -mov dword ptr [0x4e7230], esi
    app->getMemory<x86::reg32>(x86::reg32(5141040) /* 0x4e7230 */) = cpu.esi;
    // 00420c7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00420c7c:
    // 00420c7c  8b2d04724e00           -mov ebp, dword ptr [0x4e7204]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5140996) /* 0x4e7204 */);
    // 00420c82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420c83  e8763e0a00             -call 0x4c4afe
    cpu.esp -= 4;
    sub_4c4afe(app, cpu);
    if (cpu.terminate) return;
    // 00420c88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420c8a  753e                   -jne 0x420cca
    if (!cpu.flags.zf)
    {
        goto L_0x00420cca;
    }
    // 00420c8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420c91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420c92:
    // 00420c92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420c93  e8ae3a0a00             -call 0x4c4746
    cpu.esp -= 4;
    sub_4c4746(app, cpu);
    if (cpu.terminate) return;
    // 00420c98  e930ffffff             -jmp 0x420bcd
    goto L_0x00420bcd;
L_0x00420c9d:
    // 00420c9d  8b0d2c724e00           -mov ecx, dword ptr [0x4e722c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141036) /* 0x4e722c */);
    // 00420ca3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00420ca5  0f846bffffff           -je 0x420c16
    if (cpu.flags.zf)
    {
        goto L_0x00420c16;
    }
    // 00420cab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420cac  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420cb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00420cb5  0f855bffffff           -jne 0x420c16
    if (!cpu.flags.zf)
    {
        goto L_0x00420c16;
    }
    // 00420cbb  c705c4be4d00d8974c00   -mov dword ptr [0x4dbec4], 0x4c97d8
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = 5019608 /*0x4c97d8*/;
    // 00420cc5  e94cffffff             -jmp 0x420c16
    goto L_0x00420c16;
L_0x00420cca:
    // 00420cca  c705c4be4d00f8974c00   -mov dword ptr [0x4dbec4], 0x4c97f8
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = 5019640 /*0x4c97f8*/;
    // 00420cd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cd5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420cd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00420d10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420d11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420d13  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420d16  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00420d1a  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00420d1e  8b74246c               -mov esi, dword ptr [esp + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00420d22  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00420d26  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00420d29  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420d2c  0f871d020000           -ja 0x420f4f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00420f4f;
    }
    // 00420d32  ff2495e00c4200         -jmp dword ptr [edx*4 + 0x420ce0]
    cpu.ip = app->getMemory<x86::reg32>(4328672 + cpu.edx * 4); goto dynamic_jump;
  case 0x00420d39:
    // 00420d39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d3a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420d3b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420d3c  b820974c00             -mov eax, 0x4c9720
    cpu.eax = 5019424 /*0x4c9720*/;
    // 00420d41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d42  b83c724e00             -mov eax, 0x4e723c
    cpu.eax = 5141052 /*0x4e723c*/;
    // 00420d47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d48  be3c724e00             -mov esi, 0x4e723c
    cpu.esi = 5141052 /*0x4e723c*/;
    // 00420d4d  2eff154c644c00         -call dword ptr cs:[0x4c644c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006412) /* 0x4c644c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420d54  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00420d57  8935c4be4d00           -mov dword ptr [0x4dbec4], esi
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.esi;
L_0x00420d5d:
    // 00420d5d  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420d60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d63  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x00420d66:
    // 00420d66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00420d67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420d69  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420d6a  68bc964c00             -push 0x4c96bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019324 /*0x4c96bc*/;
    cpu.esp -= 4;
    // 00420d6f  683c724e00             -push 0x4e723c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141052 /*0x4e723c*/;
    cpu.esp -= 4;
    // 00420d74  2eff154c644c00         -call dword ptr cs:[0x4c644c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006412) /* 0x4c644c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420d7b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00420d7e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00420d82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420d83  8b2d10724e00           -mov ebp, dword ptr [0x4e7210]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5141008) /* 0x4e7210 */);
    // 00420d89  bf3c724e00             -mov edi, 0x4e723c
    cpu.edi = 5141052 /*0x4e723c*/;
    // 00420d8e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00420d8f  893dc4be4d00           -mov dword ptr [0x4dbec4], edi
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.edi;
    // 00420d95  e82c3b0a00             -call 0x4c48c6
    cpu.esp -= 4;
    sub_4c48c6(app, cpu);
    if (cpu.terminate) return;
    // 00420d9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d9b  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420d9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420d9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420da0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420da1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x00420da4:
    // 00420da4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420da5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420da6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420da7  68f0964c00             -push 0x4c96f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019376 /*0x4c96f0*/;
    cpu.esp -= 4;
    // 00420dac  683c724e00             -push 0x4e723c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141052 /*0x4e723c*/;
    cpu.esp -= 4;
    // 00420db1  2eff154c644c00         -call dword ptr cs:[0x4c644c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006412) /* 0x4c644c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420db8  b93c724e00             -mov ecx, 0x4e723c
    cpu.ecx = 5141052 /*0x4e723c*/;
    // 00420dbd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00420dc0  890dc4be4d00           -mov dword ptr [0x4dbec4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.ecx;
    // 00420dc6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00420dc8  7493                   -je 0x420d5d
    if (cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
    // 00420dca  c70538724e000f000000   -mov dword ptr [0x4e7238], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 15 /*0xf*/;
    // 00420dd4  c70534724e0001000000   -mov dword ptr [0x4e7234], 1
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = 1 /*0x1*/;
    // 00420dde  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420de1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420de2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420de3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420de4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x00420de7:
    // 00420de7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420de8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420de9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420dea  6854974c00             -push 0x4c9754
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019476 /*0x4c9754*/;
    cpu.esp -= 4;
    // 00420def  683c724e00             -push 0x4e723c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141052 /*0x4e723c*/;
    cpu.esp -= 4;
    // 00420df4  2eff154c644c00         -call dword ptr cs:[0x4c644c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006412) /* 0x4c644c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420dfb  b83c724e00             -mov eax, 0x4e723c
    cpu.eax = 5141052 /*0x4e723c*/;
    // 00420e00  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00420e03  a3c4be4d00             -mov dword ptr [0x4dbec4], eax
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.eax;
    // 00420e08  83fb10                 +cmp ebx, 0x10
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
    // 00420e0b  732d                   -jae 0x420e3a
    if (!cpu.flags.cf)
    {
        goto L_0x00420e3a;
    }
    // 00420e0d  83fb02                 +cmp ebx, 2
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
    // 00420e10  0f83a4000000           -jae 0x420eba
    if (!cpu.flags.cf)
    {
        goto L_0x00420eba;
    }
    // 00420e16  83fb01                 +cmp ebx, 1
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
    // 00420e19  0f853effffff           -jne 0x420d5d
    if (!cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
    // 00420e1f  8b0d24724e00           -mov ecx, dword ptr [0x4e7224]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5141028) /* 0x4e7224 */);
    // 00420e25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420e26  e81b390a00             -call 0x4c4746
    cpu.esp -= 4;
    sub_4c4746(app, cpu);
    if (cpu.terminate) return;
    // 00420e2b  891d34724e00           -mov dword ptr [0x4e7234], ebx
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = cpu.ebx;
    // 00420e31  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420e34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e37  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00420e3a:
    // 00420e3a  0f861dffffff           -jbe 0x420d5d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
    // 00420e40  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e46  7326                   -jae 0x420e6e
    if (!cpu.flags.cf)
    {
        goto L_0x00420e6e;
    }
    // 00420e48  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e4b  0f850cffffff           -jne 0x420d5d
    if (!cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
L_0x00420e51:
    // 00420e51  c70538724e000c000000   -mov dword ptr [0x4e7238], 0xc
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 12 /*0xc*/;
    // 00420e5b  c70534724e0001000000   -mov dword ptr [0x4e7234], 1
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = 1 /*0x1*/;
    // 00420e65  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420e68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420e6b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00420e6e:
    // 00420e6e  0f86e9feffff           -jbe 0x420d5d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
    // 00420e74  81fb00010000           +cmp ebx, 0x100
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
    // 00420e7a  0f82ddfeffff           -jb 0x420d5d
    if (cpu.flags.cf)
    {
        goto L_0x00420d5d;
    }
    // 00420e80  765e                   -jbe 0x420ee0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420ee0;
    }
    // 00420e82  81fb00400000           +cmp ebx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e88  0f85cffeffff           -jne 0x420d5d
    if (!cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
    // 00420e8e  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420e91  7370                   -jae 0x420f03
    if (!cpu.flags.cf)
    {
        goto L_0x00420f03;
    }
    // 00420e93  83fe01                 +cmp esi, 1
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
    // 00420e96  7205                   -jb 0x420e9d
    if (cpu.flags.cf)
    {
        goto L_0x00420e9d;
    }
    // 00420e98  7603                   -jbe 0x420e9d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420e9d;
    }
    // 00420e9a  83fe02                 -cmp esi, 2
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
L_0x00420e9d:
    // 00420e9d  c70538724e000b000000   -mov dword ptr [0x4e7238], 0xb
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 11 /*0xb*/;
    // 00420ea7  c70534724e0001000000   -mov dword ptr [0x4e7234], 1
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = 1 /*0x1*/;
    // 00420eb1  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420eb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420eb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420eb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420eb7  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00420eba:
    // 00420eba  0f879dfeffff           -ja 0x420d5d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00420d5d;
    }
    // 00420ec0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420ec2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00420ec4  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00420ec8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00420ec9  e8ea370a00             -call 0x4c46b8
    cpu.esp -= 4;
    sub_4c46b8(app, cpu);
    if (cpu.terminate) return;
    // 00420ece  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00420ed2  a324724e00             -mov dword ptr [0x4e7224], eax
    app->getMemory<x86::reg32>(x86::reg32(5141028) /* 0x4e7224 */) = cpu.eax;
    // 00420ed7  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420eda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420edb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420edc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420edd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00420ee0:
    // 00420ee0  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 00420ee5  e8d6f4ffff             -call 0x4203c0
    cpu.esp -= 4;
    sub_4203c0(app, cpu);
    if (cpu.terminate) return;
    // 00420eea  893538724e00           -mov dword ptr [0x4e7238], esi
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = cpu.esi;
    // 00420ef0  c70534724e0001000000   -mov dword ptr [0x4e7234], 1
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = 1 /*0x1*/;
    // 00420efa  83c44c                 +add esp, 0x4c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(76 /*0x4c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00420efd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420efe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420eff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f00  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00420f03:
    // 00420f03  762d                   -jbe 0x420f32
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420f32;
    }
    // 00420f05  83fe20                 +cmp esi, 0x20
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
    // 00420f08  7293                   -jb 0x420e9d
    if (cpu.flags.cf)
    {
        goto L_0x00420e9d;
    }
    // 00420f0a  0f8641ffffff           -jbe 0x420e51
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00420e51;
    }
    // 00420f10  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420f13  7588                   -jne 0x420e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00420e9d;
    }
    // 00420f15  c70538724e000d000000   -mov dword ptr [0x4e7238], 0xd
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 13 /*0xd*/;
    // 00420f1f  c70534724e0001000000   -mov dword ptr [0x4e7234], 1
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = 1 /*0x1*/;
    // 00420f29  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420f2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f2f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00420f32:
    // 00420f32  c70538724e000e000000   -mov dword ptr [0x4e7238], 0xe
    app->getMemory<x86::reg32>(x86::reg32(5141048) /* 0x4e7238 */) = 14 /*0xe*/;
    // 00420f3c  c70534724e0001000000   -mov dword ptr [0x4e7234], 1
    app->getMemory<x86::reg32>(x86::reg32(5141044) /* 0x4e7234 */) = 1 /*0x1*/;
    // 00420f46  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420f49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f4c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  case 0x00420f4f:
L_0x00420f4f:
    // 00420f4f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00420f50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00420f51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420f52  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420f53  6888974c00             -push 0x4c9788
    app->getMemory<x86::reg32>(cpu.esp-4) = 5019528 /*0x4c9788*/;
    cpu.esp -= 4;
    // 00420f58  683c724e00             -push 0x4e723c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5141052 /*0x4e723c*/;
    cpu.esp -= 4;
    // 00420f5d  2eff154c644c00         -call dword ptr cs:[0x4c644c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006412) /* 0x4c644c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00420f64  ba3c724e00             -mov edx, 0x4e723c
    cpu.edx = 5141052 /*0x4e723c*/;
    // 00420f69  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00420f6c  8915c4be4d00           -mov dword ptr [0x4dbec4], edx
    app->getMemory<x86::reg32>(x86::reg32(5095108) /* 0x4dbec4 */) = cpu.edx;
    // 00420f72  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00420f75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00420f78  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420f80  81fa00470000           +cmp edx, 0x4700
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18176 /*0x4700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420f86  741d                   -je 0x420fa5
    if (cpu.flags.zf)
    {
        goto L_0x00420fa5;
    }
    // 00420f88  83fa08                 +cmp edx, 8
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
    // 00420f8b  0f843f220000           -je 0x4231d0
    if (cpu.flags.zf)
    {
        return sub_4231d0(app, cpu);
    }
    // 00420f91  81fa00530000           +cmp edx, 0x5300
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21248 /*0x5300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00420f97  0f8433220000           -je 0x4231d0
    if (cpu.flags.zf)
    {
        return sub_4231d0(app, cpu);
    }
    // 00420f9d  f6c2ff                 +test dl, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 255 /*0xff*/));
    // 00420fa0  750e                   -jne 0x420fb0
    if (!cpu.flags.zf)
    {
        goto L_0x00420fb0;
    }
    // 00420fa2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00420fa4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420fa5:
    // 00420fa5  e886240000             -call 0x423430
    cpu.esp -= 4;
    sub_423430(app, cpu);
    if (cpu.terminate) return;
    // 00420faa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00420faf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00420fb0:
    // 00420fb0  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00420fb6  e9d5220000             -jmp 0x423290
    return sub_423290(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420fc0  e9cb240000             -jmp 0x423490
    return sub_423490(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_420fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00420fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00420fd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00420fd2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00420fd5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00420fd7  a10a345100             -mov eax, dword ptr [0x51340a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321738) /* 0x51340a */);
    // 00420fdc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00420fdf  e8dc2d0400             -call 0x463dc0
    cpu.esp -= 4;
    sub_463dc0(app, cpu);
    if (cpu.terminate) return;
    // 00420fe4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00420fe6  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00420fe7  83f8ff                 +cmp eax, -1
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
    // 00420fea  7448                   -je 0x421034
    if (cpu.flags.zf)
    {
        goto L_0x00421034;
    }
    // 00420fec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00420fee  743c                   -je 0x42102c
    if (cpu.flags.zf)
    {
        goto L_0x0042102c;
    }
    // 00420ff0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00420ff2  0f84aa010000           -je 0x4211a2
    if (cpu.flags.zf)
    {
        goto L_0x004211a2;
    }
    // 00420ff8  83f908                 +cmp ecx, 8
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
    // 00420ffb  753b                   -jne 0x421038
    if (!cpu.flags.zf)
    {
        goto L_0x00421038;
    }
L_0x00420ffd:
    // 00420ffd  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00421000  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00421002  e879ffffff             -call 0x420f80
    cpu.esp -= 4;
    sub_420f80(app, cpu);
    if (cpu.terminate) return;
    // 00421007  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421009  741c                   -je 0x421027
    if (cpu.flags.zf)
    {
        goto L_0x00421027;
    }
    // 0042100b  b408                   -mov ah, 8
    cpu.ah = 8 /*0x8*/;
    // 0042100d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0042100f  885c2401               -mov byte ptr [esp + 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00421013  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00421018  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0042101b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042101d  66894c2402             -mov word ptr [esp + 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 00421022  e849300400             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
L_0x00421027:
    // 00421027  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0042102c:
    // 0042102c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042102e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421033  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421034:
    // 00421034  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00421036  ebf4                   -jmp 0x42102c
    goto L_0x0042102c;
L_0x00421038:
    // 00421038  81f900530000           +cmp ecx, 0x5300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21248 /*0x5300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042103e  74bd                   -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421040  81f900470000           +cmp ecx, 0x4700
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18176 /*0x4700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421046  74b5                   -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421048  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042104b  7c05                   -jl 0x421052
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421052;
    }
    // 0042104d  83f922                 +cmp ecx, 0x22
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421050  7eab                   -jle 0x420ffd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420ffd;
    }
L_0x00421052:
    // 00421052  83f926                 +cmp ecx, 0x26
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421055  7c05                   -jl 0x42105c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042105c;
    }
    // 00421057  83f93b                 +cmp ecx, 0x3b
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(59 /*0x3b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042105a  7ea1                   -jle 0x420ffd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420ffd;
    }
L_0x0042105c:
    // 0042105c  83f93d                 +cmp ecx, 0x3d
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61 /*0x3d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042105f  749c                   -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421061  83f93f                 +cmp ecx, 0x3f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421064  7497                   -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421066  83f941                 +cmp ecx, 0x41
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421069  7c05                   -jl 0x421070
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421070;
    }
    // 0042106b  83f97d                 +cmp ecx, 0x7d
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042106e  7e8d                   -jle 0x420ffd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00420ffd;
    }
L_0x00421070:
    // 00421070  81f991000000           +cmp ecx, 0x91
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(145 /*0x91*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421076  7485                   -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421078  81f992000000           +cmp ecx, 0x92
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(146 /*0x92*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042107e  0f8479ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421084  81f9a1000000           +cmp ecx, 0xa1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(161 /*0xa1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042108a  0f846dffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421090  81f9b0000000           +cmp ecx, 0xb0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(176 /*0xb0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421096  0f8461ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 0042109c  81f9bf000000           +cmp ecx, 0xbf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(191 /*0xbf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210a2  0f8455ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210a8  81f9c1000000           +cmp ecx, 0xc1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(193 /*0xc1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210ae  0f8449ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210b4  81f9e1000000           +cmp ecx, 0xe1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210ba  0f843dffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210c0  81f9c4000000           +cmp ecx, 0xc4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(196 /*0xc4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210c6  0f8431ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210cc  81f9e4000000           +cmp ecx, 0xe4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(228 /*0xe4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210d2  0f8425ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210d8  81f9c7000000           +cmp ecx, 0xc7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(199 /*0xc7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210de  0f8419ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210e4  81f9e7000000           +cmp ecx, 0xe7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(231 /*0xe7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004210ea  0f840dffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210f0  81f9c9000000           +cmp ecx, 0xc9
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
    // 004210f6  0f8401ffffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004210fc  81f9e9000000           +cmp ecx, 0xe9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(233 /*0xe9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421102  0f84f5feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421108  81f9cd000000           +cmp ecx, 0xcd
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
    // 0042110e  0f84e9feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421114  81f9ed000000           +cmp ecx, 0xed
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(237 /*0xed*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042111a  0f84ddfeffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421120  81f9d1000000           +cmp ecx, 0xd1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(209 /*0xd1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421126  0f84d1feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 0042112c  81f9f1000000           +cmp ecx, 0xf1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(241 /*0xf1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421132  0f84c5feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421138  81f9d3000000           +cmp ecx, 0xd3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(211 /*0xd3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042113e  0f84b9feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421144  81f9f3000000           +cmp ecx, 0xf3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(243 /*0xf3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042114a  0f84adfeffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421150  81f9d6000000           +cmp ecx, 0xd6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(214 /*0xd6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421156  0f84a1feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 0042115c  81f9f6000000           +cmp ecx, 0xf6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(246 /*0xf6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421162  0f8495feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421168  81f9da000000           +cmp ecx, 0xda
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(218 /*0xda*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042116e  0f8489feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421174  81f9fa000000           +cmp ecx, 0xfa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(250 /*0xfa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042117a  0f847dfeffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421180  81f9dc000000           +cmp ecx, 0xdc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(220 /*0xdc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421186  0f8471feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 0042118c  81f9fc000000           +cmp ecx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421192  0f8465feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 00421198  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042119a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042119c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042119f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004211a2:
    // 004211a2  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004211a5  0f8d52feffff           -jge 0x420ffd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00420ffd;
    }
    // 004211ab  83f908                 +cmp ecx, 8
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
    // 004211ae  0f8449feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004211b4  81f900530000           +cmp ecx, 0x5300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21248 /*0x5300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004211ba  0f843dfeffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004211c0  81f900470000           +cmp ecx, 0x4700
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18176 /*0x4700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004211c6  0f8431feffff           -je 0x420ffd
    if (cpu.flags.zf)
    {
        goto L_0x00420ffd;
    }
    // 004211cc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004211ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004211d0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004211d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004211d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4211e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004211e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004211e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004211e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004211e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004211e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004211e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004211e6  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004211e9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004211ed  803d5f34510001         +cmp byte ptr [0x51345f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5321823) /* 0x51345f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004211f4  0f84b4000000           -je 0x4212ae
    if (cpu.flags.zf)
    {
        goto L_0x004212ae;
    }
    // 004211fa  c744242002000000       -mov dword ptr [esp + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
L_0x00421202:
    // 00421202  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421204  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421208  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0042120c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042120e  0f8e90000000           -jle 0x4212a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004212a4;
    }
    // 00421214  bf842e5100             -mov edi, 0x512e84
    cpu.edi = 5320324 /*0x512e84*/;
    // 00421219  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0042121d  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00421221  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00421225  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x00421229:
    // 00421229  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042122d  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421231  e86a1e0000             -call 0x4230a0
    cpu.esp -= 4;
    sub_4230a0(app, cpu);
    if (cpu.terminate) return;
    // 00421236  8bbf0c345100           -mov edi, dword ptr [edi + 0x51340c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5321740) /* 0x51340c */);
    // 0042123c  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0042123f  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00421243  83ffff                 +cmp edi, -1
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
    // 00421246  7416                   -je 0x42125e
    if (cpu.flags.zf)
    {
        goto L_0x0042125e;
    }
    // 00421248  837c241800             +cmp dword ptr [esp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042124d  0f84bc000000           -je 0x42130f
    if (cpu.flags.zf)
    {
        goto L_0x0042130f;
    }
    // 00421253  66833c7d4834510000     +cmp word ptr [edi*2 + 0x513448], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5321800) /* 0x513448 */ + cpu.edi * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042125c  745d                   -je 0x4212bb
    if (cpu.flags.zf)
    {
        goto L_0x004212bb;
    }
L_0x0042125e:
    // 0042125e  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421262  e8c9210000             -call 0x423430
    cpu.esp -= 4;
    sub_423430(app, cpu);
    if (cpu.terminate) return;
L_0x00421267:
    // 00421267  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042126b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042126f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00421273  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00421277  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0042127b  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0042127f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00421282  83c509                 -add ebp, 9
    (cpu.ebp) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00421285  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421288  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042128b  41                     -inc ecx
    (cpu.ecx)++;
    // 0042128c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00421290  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00421294  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00421298  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0042129c  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004212a0  39d9                   +cmp ecx, ebx
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
    // 004212a2  7c85                   -jl 0x421229
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421229;
    }
L_0x004212a4:
    // 004212a4  83c42c                 +add esp, 0x2c
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
    // 004212a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004212ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004212ae:
    // 004212ae  c744242008000000       -mov dword ptr [esp + 0x20], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 8 /*0x8*/;
    // 004212b6  e947ffffff             -jmp 0x421202
    goto L_0x00421202;
L_0x004212bb:
    // 004212bb  837c242002             +cmp dword ptr [esp + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004212c0  0f85bf000000           -jne 0x421385
    if (!cpu.flags.zf)
    {
        goto L_0x00421385;
    }
    // 004212c6  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004212ca  ba86000000             -mov edx, 0x86
    cpu.edx = 134 /*0x86*/;
    // 004212cf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x004212d3:
    // 004212d3  8b9b044c4d00           -mov ebx, dword ptr [ebx + 0x4d4c04]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5065732) /* 0x4d4c04 */);
    // 004212d9  e8e2aa0500             -call 0x47bdc0
    cpu.esp -= 4;
    sub_47bdc0(app, cpu);
    if (cpu.terminate) return;
    // 004212de  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004212e2  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 004212e7  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004212e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004212eb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004212ed  7e17                   -jle 0x421306
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00421306;
    }
    // 004212ef  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004212f1  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
L_0x004212f5:
    // 004212f5  807e0400               +cmp byte ptr [esi + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004212f9  7401                   -je 0x4212fc
    if (cpu.flags.zf)
    {
        goto L_0x004212fc;
    }
    // 004212fb  47                     -inc edi
    (cpu.edi)++;
L_0x004212fc:
    // 004212fc  40                     -inc eax
    (cpu.eax)++;
    // 004212fd  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004212ff  83c626                 -add esi, 0x26
    (cpu.esi) += x86::reg32(x86::sreg32(38 /*0x26*/));
    // 00421302  39e8                   +cmp eax, ebp
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
    // 00421304  7cef                   -jl 0x4212f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004212f5;
    }
L_0x00421306:
    // 00421306  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421309  0f8d8c000000           -jge 0x42139b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042139b;
    }
L_0x0042130f:
    // 0042130f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00421311:
    // 00421311  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00421315  3b38                   +cmp edi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421317  0f8d4affffff           -jge 0x421267
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421267;
    }
    // 0042131d  6bf726                 -imul esi, edi, 0x26
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(38 /*0x26*/)));
    // 00421320  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421323  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00421325  6bc714                 -imul eax, edi, 0x14
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 00421328  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0042132c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00421330  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00421334  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00421336  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00421339  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0042133d:
    // 0042133d  837c241800             +cmp dword ptr [esp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421342  7471                   -je 0x4213b5
    if (cpu.flags.zf)
    {
        goto L_0x004213b5;
    }
    // 00421344  837c242002             +cmp dword ptr [esp + 0x20], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421349  7558                   -jne 0x4213a3
    if (!cpu.flags.zf)
    {
        goto L_0x004213a3;
    }
    // 0042134b  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0042134f  bad6000000             -mov edx, 0xd6
    cpu.edx = 214 /*0xd6*/;
    // 00421354  8b9b044c4d00           -mov ebx, dword ptr [ebx + 0x4d4c04]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5065732) /* 0x4d4c04 */);
    // 0042135a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0042135c  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0042135e:
    // 0042135e  e85daa0500             -call 0x47bdc0
    cpu.esp -= 4;
    sub_47bdc0(app, cpu);
    if (cpu.terminate) return;
L_0x00421363:
    // 00421363  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00421367  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0042136b  83c626                 -add esi, 0x26
    (cpu.esi) += x86::reg32(x86::sreg32(38 /*0x26*/));
    // 0042136e  47                     -inc edi
    (cpu.edi)++;
    // 0042136f  83c50f                 -add ebp, 0xf
    (cpu.ebp) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00421372  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00421375  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421377  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0042137b  39cf                   +cmp edi, ecx
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
    // 0042137d  0f8de4feffff           -jge 0x421267
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421267;
    }
    // 00421383  ebb8                   -jmp 0x42133d
    goto L_0x0042133d;
L_0x00421385:
    // 00421385  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00421389  8d04ff                 -lea eax, [edi + edi*8]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 8);
    // 0042138c  ba86000000             -mov edx, 0x86
    cpu.edx = 134 /*0x86*/;
    // 00421391  05842e5100             +add eax, 0x512e84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5320324 /*0x512e84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421396  e938ffffff             -jmp 0x4212d3
    goto L_0x004212d3;
L_0x0042139b:
    // 0042139b  83ef03                 +sub edi, 3
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0042139e  e96effffff             -jmp 0x421311
    goto L_0x00421311;
L_0x004213a3:
    // 004213a3  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004213a6  bad6000000             -mov edx, 0xd6
    cpu.edx = 214 /*0xd6*/;
    // 004213ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004213ad  8b9b044c4d00           -mov ebx, dword ptr [ebx + 0x4d4c04]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5065732) /* 0x4d4c04 */);
    // 004213b3  eba9                   -jmp 0x42135e
    goto L_0x0042135e;
L_0x004213b5:
    // 004213b5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004213b9  83f802                 +cmp eax, 2
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
    // 004213bc  752d                   -jne 0x4213eb
    if (!cpu.flags.zf)
    {
        goto L_0x004213eb;
    }
    // 004213be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004213bf  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004213c3  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004213c7  bafd000000             -mov edx, 0xfd
    cpu.edx = 253 /*0xfd*/;
    // 004213cc  668b80244c4d00         -mov ax, word ptr [eax + 0x4d4c24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5065764) /* 0x4d4c24 */);
    // 004213d3  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004213d5  01c8                   +add eax, ecx
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
    // 004213d7  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004213dc  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004213df  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004213e1  e8fa40feff             -call 0x4054e0
    cpu.esp -= 4;
    sub_4054e0(app, cpu);
    if (cpu.terminate) return;
    // 004213e6  e978ffffff             -jmp 0x421363
    goto L_0x00421363;
L_0x004213eb:
    // 004213eb  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004213ed  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004213f1  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004213f6  bafd000000             -mov edx, 0xfd
    cpu.edx = 253 /*0xfd*/;
    // 004213fb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004213fd  8b9b224c4d00           -mov ebx, dword ptr [ebx + 0x4d4c22]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5065762) /* 0x4d4c22 */);
    // 00421403  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00421405  c1fb10                 +sar ebx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00421408  e8d340feff             -call 0x4054e0
    cpu.esp -= 4;
    sub_4054e0(app, cpu);
    if (cpu.terminate) return;
    // 0042140d  e951ffffff             -jmp 0x421363
    goto L_0x00421363;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421420  e99b200000             -jmp 0x4234c0
    return sub_4234c0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421431  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421432  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421433  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421434  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00421437  803d5f34510001         +cmp byte ptr [0x51345f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5321823) /* 0x51345f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042143e  753f                   -jne 0x42147f
    if (!cpu.flags.zf)
    {
        goto L_0x0042147f;
    }
    // 00421440  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00421445  be25000000             -mov esi, 0x25
    cpu.esi = 37 /*0x25*/;
    // 0042144a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0042144f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00421451  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00421455  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00421459  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0042145d  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00421461  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 00421465  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00421469  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0042146d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00421470  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00421472  e8a9200000             -call 0x423520
    cpu.esp -= 4;
    sub_423520(app, cpu);
    if (cpu.terminate) return;
    // 00421477  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0042147a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042147b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042147c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042147d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042147e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042147f:
    // 0042147f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421480  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00421485  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0042148a  bb25000000             -mov ebx, 0x25
    cpu.ebx = 37 /*0x25*/;
    // 0042148f  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00421494  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421496  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042149a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0042149e  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004214a2  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004214a6  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004214aa  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004214ae  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004214b3  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004214b7  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004214bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004214bc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004214be  e85d200000             -call 0x423520
    cpu.esp -= 4;
    sub_423520(app, cpu);
    if (cpu.terminate) return;
    // 004214c3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004214c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004214c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004214c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004214c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004214ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4214d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004214d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004214d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004214d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004214d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004214d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004214d7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004214d9  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004214db  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004214de  66833d5834510000       +cmp word ptr [0x513458], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5321816) /* 0x513458 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004214e6  744c                   -je 0x421534
    if (cpu.flags.zf)
    {
        goto L_0x00421534;
    }
    // 004214e8  803d5f34510001         +cmp byte ptr [0x51345f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5321823) /* 0x51345f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004214ef  7543                   -jne 0x421534
    if (!cpu.flags.zf)
    {
        goto L_0x00421534;
    }
    // 004214f1  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004214f6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004214fb:
    // 004214fb  a108345100             -mov eax, dword ptr [0x513408]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321736) /* 0x513408 */);
    // 00421500  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00421503  39c1                   +cmp ecx, eax
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
    // 00421505  7d2d                   -jge 0x421534
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421534;
    }
    // 00421507  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0042150a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042150c  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0042150f  8b04450c345100         -mov eax, dword ptr [eax*2 + 0x51340c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321740) /* 0x51340c */ + cpu.eax * 2);
    // 00421516  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00421519  39c1                   +cmp ecx, eax
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
    // 0042151b  7506                   -jne 0x421523
    if (!cpu.flags.zf)
    {
        goto L_0x00421523;
    }
L_0x0042151d:
    // 0042151d  41                     -inc ecx
    (cpu.ecx)++;
    // 0042151e  83c604                 +add esi, 4
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
    // 00421521  ebd8                   -jmp 0x4214fb
    goto L_0x004214fb;
L_0x00421523:
    // 00421523  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00421525  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00421527  8b8680305100           -mov eax, dword ptr [esi + 0x513080]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5320832) /* 0x513080 */);
    // 0042152d  e83e2b0400             -call 0x464070
    cpu.esp -= 4;
    sub_464070(app, cpu);
    if (cpu.terminate) return;
    // 00421532  ebe9                   -jmp 0x42151d
    goto L_0x0042151d;
L_0x00421534:
    // 00421534  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00421537  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0042153a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042153c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0042153e  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00421541  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00421544  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00421549  e832faffff             -call 0x420f80
    cpu.esp -= 4;
    sub_420f80(app, cpu);
    if (cpu.terminate) return;
    // 0042154e  66891d34345100         -mov word ptr [0x513434], bx
    app->getMemory<x86::reg16>(x86::reg32(5321780) /* 0x513434 */) = cpu.bx;
    // 00421555  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421558  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421559  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042155a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042155b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042155c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_421560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421560  1827                   -sbb byte ptr [edi], ah
    (app->getMemory<x86::reg8>(cpu.edi)) -= x86::reg8(x86::sreg8(cpu.ah) + cpu.flags.cf);
    // 00421562  4e                     -dec esi
    (cpu.esi)--;
    // 00421563  0028                   -add byte ptr [eax], ch
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.ch));
    // 00421565  27                     -daa 
    NFS2_ASSERT(false);
    // 00421566  4e                     -dec esi
    (cpu.esi)--;
    // 00421567  0038                   -add byte ptr [eax], bh
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.bh));
    // 00421569  27                     -daa 
    NFS2_ASSERT(false);
    // 0042156a  4e                     -dec esi
    (cpu.esi)--;
    // 0042156b  004827                 -add byte ptr [eax + 0x27], cl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 0042156e  4e                     -dec esi
    (cpu.esi)--;
    // 0042156f  005827                 -add byte ptr [eax + 0x27], bl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.bl));
    // 00421572  4e                     -dec esi
    (cpu.esi)--;
    // 00421573  006827                 -add byte ptr [eax + 0x27], ch
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.ch));
    // 00421576  4e                     -dec esi
    (cpu.esi)--;
    // 00421577  007827                 -add byte ptr [eax + 0x27], bh
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.bh));
    // 0042157a  4e                     -dec esi
    (cpu.esi)--;
    // 0042157b  0088274e0098           -add byte ptr [eax - 0x67ffb1d9], cl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1744810457) /* -0x67ffb1d9 */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 00421581  27                     -daa 
    NFS2_ASSERT(false);
    // 00421582  4e                     -dec esi
    (cpu.esi)--;
    // 00421583  0098274e00a8           -add byte ptr [eax - 0x57ffb1d9], bl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1476375001) /* -0x57ffb1d9 */)) += x86::reg8(x86::sreg8(cpu.bl));
    // 00421589  27                     -daa 
    NFS2_ASSERT(false);
    // 0042158a  4e                     -dec esi
    (cpu.esi)--;
    // 0042158b  00b8274e00c8           -add byte ptr [eax - 0x37ffb1d9], bh
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-939504089) /* -0x37ffb1d9 */)) += x86::reg8(x86::sreg8(cpu.bh));
    // 00421591  27                     -daa 
    NFS2_ASSERT(false);
    // 00421592  4e                     -dec esi
    (cpu.esi)--;
    // 00421593  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421595  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421597  000400                 -add byte ptr [eax + eax], al
    (app->getMemory<x86::reg8>(cpu.eax + cpu.eax * 1)) += x86::reg8(x86::sreg8(cpu.al));
    // 0042159a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0042159c  0800                   -or byte ptr [eax], al
    app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.al));
    // 0042159e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004215a0  1400                   -adc al, 0
    (cpu.al) += x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 004215a2  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004215a4  1800                   -sbb byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) -= x86::reg8(x86::sreg8(cpu.al) + cpu.flags.cf);
    // 004215a6  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004215a8  1c00                   -sbb al, 0
    (cpu.al) -= x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 004215aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004215ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004215ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004215b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004215b2  7416                   -je 0x4215ca
    if (cpu.flags.zf)
    {
        goto L_0x004215ca;
    }
    // 004215b4  83f801                 +cmp eax, 1
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
    // 004215b7  7410                   -je 0x4215c9
    if (cpu.flags.zf)
    {
        goto L_0x004215c9;
    }
    // 004215b9  3d57000780             +cmp eax, 0x80070057
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942487 /*0x80070057*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215be  7407                   -je 0x4215c7
    if (cpu.flags.zf)
    {
        goto L_0x004215c7;
    }
    // 004215c0  3d05000780             +cmp eax, 0x80070005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942405 /*0x80070005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215c5  7509                   -jne 0x4215d0
    if (!cpu.flags.zf)
    {
        goto L_0x004215d0;
    }
L_0x004215c7:
    // 004215c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004215c9:
    // 004215c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004215ca:
    // 004215ca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004215cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004215d0:
    // 004215d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004215d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004215d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004215d3  b9e09a4c00             -mov ecx, 0x4c9ae0
    cpu.ecx = 5020384 /*0x4c9ae0*/;
    // 004215d8  bb74070000             -mov ebx, 0x774
    cpu.ebx = 1908 /*0x774*/;
    // 004215dd  68009b4c00             -push 0x4c9b00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020416 /*0x4c9b00*/;
    cpu.esp -= 4;
    // 004215e2  890dd8b14d00           -mov dword ptr [0x4db1d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ecx;
    // 004215e8  891ddcb14d00           -mov dword ptr [0x4db1dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebx;
    // 004215ee  e8fd2a0600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 004215f3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004215f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004215f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004215f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004215fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4215b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004215b0;
    // 00421560  1827                   -sbb byte ptr [edi], ah
    (app->getMemory<x86::reg8>(cpu.edi)) -= x86::reg8(x86::sreg8(cpu.ah) + cpu.flags.cf);
    // 00421562  4e                     -dec esi
    (cpu.esi)--;
    // 00421563  0028                   -add byte ptr [eax], ch
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.ch));
    // 00421565  27                     -daa 
    NFS2_ASSERT(false);
    // 00421566  4e                     -dec esi
    (cpu.esi)--;
    // 00421567  0038                   -add byte ptr [eax], bh
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.bh));
    // 00421569  27                     -daa 
    NFS2_ASSERT(false);
    // 0042156a  4e                     -dec esi
    (cpu.esi)--;
    // 0042156b  004827                 -add byte ptr [eax + 0x27], cl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 0042156e  4e                     -dec esi
    (cpu.esi)--;
    // 0042156f  005827                 -add byte ptr [eax + 0x27], bl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.bl));
    // 00421572  4e                     -dec esi
    (cpu.esi)--;
    // 00421573  006827                 -add byte ptr [eax + 0x27], ch
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.ch));
    // 00421576  4e                     -dec esi
    (cpu.esi)--;
    // 00421577  007827                 -add byte ptr [eax + 0x27], bh
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(39) /* 0x27 */)) += x86::reg8(x86::sreg8(cpu.bh));
    // 0042157a  4e                     -dec esi
    (cpu.esi)--;
    // 0042157b  0088274e0098           -add byte ptr [eax - 0x67ffb1d9], cl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1744810457) /* -0x67ffb1d9 */)) += x86::reg8(x86::sreg8(cpu.cl));
    // 00421581  27                     -daa 
    NFS2_ASSERT(false);
    // 00421582  4e                     -dec esi
    (cpu.esi)--;
    // 00421583  0098274e00a8           -add byte ptr [eax - 0x57ffb1d9], bl
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1476375001) /* -0x57ffb1d9 */)) += x86::reg8(x86::sreg8(cpu.bl));
    // 00421589  27                     -daa 
    NFS2_ASSERT(false);
    // 0042158a  4e                     -dec esi
    (cpu.esi)--;
    // 0042158b  00b8274e00c8           -add byte ptr [eax - 0x37ffb1d9], bh
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-939504089) /* -0x37ffb1d9 */)) += x86::reg8(x86::sreg8(cpu.bh));
    // 00421591  27                     -daa 
    NFS2_ASSERT(false);
    // 00421592  4e                     -dec esi
    (cpu.esi)--;
    // 00421593  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421595  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00421597  000400                 -add byte ptr [eax + eax], al
    (app->getMemory<x86::reg8>(cpu.eax + cpu.eax * 1)) += x86::reg8(x86::sreg8(cpu.al));
    // 0042159a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0042159c  0800                   -or byte ptr [eax], al
    app->getMemory<x86::reg8>(cpu.eax) |= x86::reg8(x86::sreg8(cpu.al));
    // 0042159e  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004215a0  1400                   -adc al, 0
    (cpu.al) += x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 004215a2  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004215a4  1800                   -sbb byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) -= x86::reg8(x86::sreg8(cpu.al) + cpu.flags.cf);
    // 004215a6  0000                   +add byte ptr [eax], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004215a8  1c00                   -sbb al, 0
    (cpu.al) -= x86::reg8(x86::sreg8(0 /*0x0*/) + cpu.flags.cf);
    // 004215aa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004215ac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004215ae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x004215b0:
    // 004215b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004215b2  7416                   -je 0x4215ca
    if (cpu.flags.zf)
    {
        goto L_0x004215ca;
    }
    // 004215b4  83f801                 +cmp eax, 1
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
    // 004215b7  7410                   -je 0x4215c9
    if (cpu.flags.zf)
    {
        goto L_0x004215c9;
    }
    // 004215b9  3d57000780             +cmp eax, 0x80070057
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942487 /*0x80070057*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215be  7407                   -je 0x4215c7
    if (cpu.flags.zf)
    {
        goto L_0x004215c7;
    }
    // 004215c0  3d05000780             +cmp eax, 0x80070005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942405 /*0x80070005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004215c5  7509                   -jne 0x4215d0
    if (!cpu.flags.zf)
    {
        goto L_0x004215d0;
    }
L_0x004215c7:
    // 004215c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004215c9:
    // 004215c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004215ca:
    // 004215ca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004215cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004215d0:
    // 004215d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004215d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004215d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004215d3  b9e09a4c00             -mov ecx, 0x4c9ae0
    cpu.ecx = 5020384 /*0x4c9ae0*/;
    // 004215d8  bb74070000             -mov ebx, 0x774
    cpu.ebx = 1908 /*0x774*/;
    // 004215dd  68009b4c00             -push 0x4c9b00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020416 /*0x4c9b00*/;
    cpu.esp -= 4;
    // 004215e2  890dd8b14d00           -mov dword ptr [0x4db1d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ecx;
    // 004215e8  891ddcb14d00           -mov dword ptr [0x4db1dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebx;
    // 004215ee  e8fd2a0600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 004215f3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004215f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004215f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004215f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004215fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421600  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421602  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421603  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421604  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421605  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421606  8b15444c4d00           -mov edx, dword ptr [0x4d4c44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
    // 0042160c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0042160e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421610  743a                   -je 0x42164c
    if (cpu.flags.zf)
    {
        goto L_0x0042164c;
    }
    // 00421612  3c13                   +cmp al, 0x13
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(19 /*0x13*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421614  743f                   -je 0x421655
    if (cpu.flags.zf)
    {
        goto L_0x00421655;
    }
    // 00421616  3c11                   +cmp al, 0x11
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421618  7361                   -jae 0x42167b
    if (!cpu.flags.cf)
    {
        goto L_0x0042167b;
    }
    // 0042161a  3c10                   +cmp al, 0x10
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
    // 0042161c  0f85ae000000           -jne 0x4216d0
    if (!cpu.flags.zf)
    {
        goto L_0x004216d0;
    }
    // 00421622  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421624  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00421626:
    // 00421626  8bae48734e00           -mov ebp, dword ptr [esi + 0x4e7348]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5141320) /* 0x4e7348 */);
    // 0042162c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042162e  7413                   -je 0x421643
    if (cpu.flags.zf)
    {
        goto L_0x00421643;
    }
    // 00421630  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421631  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00421634  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421637  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421639  e872ffffff             -call 0x4215b0
    cpu.esp -= 4;
    sub_4215b0(app, cpu);
    if (cpu.terminate) return;
    // 0042163e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421640  7401                   -je 0x421643
    if (cpu.flags.zf)
    {
        goto L_0x00421643;
    }
    // 00421642  47                     -inc edi
    (cpu.edi)++;
L_0x00421643:
    // 00421643  43                     -inc ebx
    (cpu.ebx)++;
    // 00421644  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421647  83fb10                 +cmp ebx, 0x10
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
    // 0042164a  7cda                   -jl 0x421626
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421626;
    }
L_0x0042164c:
    // 0042164c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0042164e:
    // 0042164e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042164f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421650  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421651  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421652  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421653  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421654  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421655:
    // 00421655  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0042165a  e8a1ffffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 0042165f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00421661  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00421666  e895ffffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 0042166b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042166d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00421672  e889ffffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 00421677  01d0                   +add eax, edx
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
    // 00421679  ebd3                   -jmp 0x42164e
    goto L_0x0042164e;
L_0x0042167b:
    // 0042167b  7712                   -ja 0x42168f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0042168f;
    }
    // 0042167d  833d484c4d0000         +cmp dword ptr [0x4d4c48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421684  752e                   -jne 0x4216b4
    if (!cpu.flags.zf)
    {
        goto L_0x004216b4;
    }
    // 00421686  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00421688  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421689  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042168a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042168b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042168c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042168d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042168e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042168f:
    // 0042168f  3c12                   +cmp al, 0x12
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421691  753d                   -jne 0x4216d0
    if (!cpu.flags.zf)
    {
        goto L_0x004216d0;
    }
    // 00421693  8b0d4c4c4d00           -mov ecx, dword ptr [0x4d4c4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 00421699  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042169b  74af                   -je 0x42164c
    if (cpu.flags.zf)
    {
        goto L_0x0042164c;
    }
    // 0042169d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042169e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004216a0  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004216a3  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004216a6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004216a8  e803ffffff             -call 0x4215b0
    cpu.esp -= 4;
    sub_4215b0(app, cpu);
    if (cpu.terminate) return;
    // 004216ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004216b4:
    // 004216b4  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004216b7  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 004216bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004216bd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004216bf  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004216c2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004216c4  e8e7feffff             -call 0x4215b0
    cpu.esp -= 4;
    sub_4215b0(app, cpu);
    if (cpu.terminate) return;
    // 004216c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004216d0:
    // 004216d0  3c13                   +cmp al, 0x13
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(19 /*0x13*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004216d2  7f2c                   -jg 0x421700
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00421700;
    }
    // 004216d4  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 004216d7  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004216de  8bb048734e00           -mov esi, dword ptr [eax + 0x4e7348]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141320) /* 0x4e7348 */);
    // 004216e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004216e6  0f8460ffffff           -je 0x42164c
    if (cpu.flags.zf)
    {
        goto L_0x0042164c;
    }
    // 004216ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004216ed  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004216ef  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004216f2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004216f4  e8b7feffff             -call 0x4215b0
    cpu.esp -= 4;
    sub_4215b0(app, cpu);
    if (cpu.terminate) return;
    // 004216f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004216ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421700:
    // 00421700  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421702  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421703  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421704  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421705  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421706  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421707  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421708  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421712  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421713  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421714  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421715  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421718  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0042171b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0042171d  e8aef30600             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 00421722  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421724  7435                   -je 0x42175b
    if (cpu.flags.zf)
    {
        goto L_0x0042175b;
    }
    // 00421726  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 00421729  80fc10                 +cmp ah, 0x10
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
    // 0042172c  7d36                   -jge 0x421764
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421764;
    }
    // 0042172e  8b7424fd               -mov esi, dword ptr [esp - 3]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-3) /* -0x3 */);
    // 00421732  c1fe18                 -sar esi, 0x18
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (24 /*0x18*/ % 32));
    // 00421735  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00421738  8bbe48734e00           -mov edi, dword ptr [esi + 0x4e7348]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5141320) /* 0x4e7348 */);
    // 0042173e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421740  7446                   -je 0x421788
    if (cpu.flags.zf)
    {
        goto L_0x00421788;
    }
    // 00421742  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421743  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00421745  e886f30600             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 0042174a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042174b  8bae48734e00           -mov ebp, dword ptr [esi + 0x4e7348]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5141320) /* 0x4e7348 */);
    // 00421751  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421752  ff5734                 -call dword ptr [edi + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421755  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421757  742f                   -je 0x421788
    if (cpu.flags.zf)
    {
        goto L_0x00421788;
    }
    // 00421759  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042175b:
    // 0042175b  83c408                 +add esp, 8
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
    // 0042175e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042175f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421761  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421762  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421763  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421764:
    // 00421764  7530                   -jne 0x421796
    if (!cpu.flags.zf)
    {
        goto L_0x00421796;
    }
    // 00421766  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00421768  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
L_0x0042176c:
    // 0042176c  8b442401               -mov eax, dword ptr [esp + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00421770  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00421772  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00421775  e896ffffff             -call 0x421710
    cpu.esp -= 4;
    sub_421710(app, cpu);
    if (cpu.terminate) return;
    // 0042177a  ff442404               -inc dword ptr [esp + 4]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))++;
    // 0042177e  807c240410             +cmp byte ptr [esp + 4], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421783  7ce7                   -jl 0x42176c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042176c;
    }
    // 00421785  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00421788:
    // 00421788  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042178d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00421790  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421791  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421792  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421793  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421794  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421795  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421796:
    // 00421796  80fc11                 +cmp ah, 0x11
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421799  742c                   -je 0x4217c7
    if (cpu.flags.zf)
    {
        goto L_0x004217c7;
    }
    // 0042179b  80fc12                 +cmp ah, 0x12
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042179e  75e8                   -jne 0x421788
    if (!cpu.flags.zf)
    {
        goto L_0x00421788;
    }
    // 004217a0  a14c4c4d00             -mov eax, dword ptr [0x4d4c4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 004217a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004217a6  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004217a8  e823f30600             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 004217ad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004217ae  8b154c4c4d00           -mov edx, dword ptr [0x4d4c4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 004217b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004217b5  ff5634                 -call dword ptr [esi + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004217b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004217ba  74cc                   -je 0x421788
    if (cpu.flags.zf)
    {
        goto L_0x00421788;
    }
    // 004217bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004217be  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004217c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004217c7:
    // 004217c7  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 004217cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004217cd  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004217cf  e8fcf20600             -call 0x490ad0
    cpu.esp -= 4;
    sub_490ad0(app, cpu);
    if (cpu.terminate) return;
    // 004217d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004217d5  8b0d484c4d00           -mov ecx, dword ptr [0x4d4c48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 004217db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004217dc  ff5634                 -call dword ptr [esi + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004217df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004217e1  74a5                   -je 0x421788
    if (cpu.flags.zf)
    {
        goto L_0x00421788;
    }
    // 004217e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004217e5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004217e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004217ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4217f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004217f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004217f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004217f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004217f3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004217f6  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004217fa  8b155c4c4d00           -mov edx, dword ptr [0x4d4c5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 00421800  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421807  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421809  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042180c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0042180e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00421811  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00421813  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 00421818  889091734e00           -mov byte ptr [eax + 0x4e7391], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5141393) /* 0x4e7391 */) = cpu.dl;
    // 0042181e  0588734e00             -add eax, 0x4e7388
    (cpu.eax) += x86::reg32(x86::sreg32(5141384 /*0x4e7388*/));
    // 00421823  8d962c010000           -lea edx, [esi + 0x12c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(300) /* 0x12c */);
    // 00421829  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0042182c  e8ab4c0600             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 00421831  8b155c4c4d00           -mov edx, dword ptr [0x4d4c5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 00421837  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0042183e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421840  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421843  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421845  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0042184c  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0042184e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421850  889ae0734e00           -mov byte ptr [edx + 0x4e73e0], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5141472) /* 0x4e73e0 */) = cpu.bl;
    // 00421856  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0042185a  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0042185d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00421862  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00421866  3c04                   +cmp al, 4
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
    // 00421868  7239                   -jb 0x4218a3
    if (cpu.flags.cf)
    {
        goto L_0x004218a3;
    }
    // 0042186a  772a                   -ja 0x421896
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00421896;
    }
    // 0042186c  c68290734e0004         -mov byte ptr [edx + 0x4e7390], 4
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5141392) /* 0x4e7390 */) = 4 /*0x4*/;
L_0x00421873:
    // 00421873  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00421875  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421879  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042187a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042187d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0042187e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00421880  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421881  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421884  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421886  7439                   -je 0x4218c1
    if (cpu.flags.zf)
    {
        goto L_0x004218c1;
    }
    // 00421888  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042188d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421890  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421891  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421892  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421893  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421896:
    // 00421896  3c06                   +cmp al, 6
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421898  7509                   -jne 0x4218a3
    if (!cpu.flags.zf)
    {
        goto L_0x004218a3;
    }
    // 0042189a  c68290734e0002         -mov byte ptr [edx + 0x4e7390], 2
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5141392) /* 0x4e7390 */) = 2 /*0x2*/;
    // 004218a1  ebd0                   -jmp 0x421873
    goto L_0x00421873;
L_0x004218a3:
    // 004218a3  8b155c4c4d00           -mov edx, dword ptr [0x4d4c5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 004218a9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004218b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004218b2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004218b5  29d0                   +sub eax, edx
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
    // 004218b7  c6048590734e0001       -mov byte ptr [eax*4 + 0x4e7390], 1
    app->getMemory<x86::reg8>(x86::reg32(5141392) /* 0x4e7390 */ + cpu.eax * 4) = 1 /*0x1*/;
    // 004218bf  ebb2                   -jmp 0x421873
    goto L_0x00421873;
L_0x004218c1:
    // 004218c1  68a04e4c00             -push 0x4c4ea0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5000864 /*0x4c4ea0*/;
    cpu.esp -= 4;
    // 004218c6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004218ca  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004218ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004218cf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004218d1  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004218d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004218d6  7543                   -jne 0x42191b
    if (!cpu.flags.zf)
    {
        goto L_0x0042191b;
    }
    // 004218d8  a15c4c4d00             -mov eax, dword ptr [0x4d4c5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 004218dd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004218e0  0548734e00             -add eax, 0x4e7348
    (cpu.eax) += x86::reg32(x86::sreg32(5141320 /*0x4e7348*/));
    // 004218e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004218e6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004218ea  68e8274e00             -push 0x4e27e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122024 /*0x4e27e8*/;
    cpu.esp -= 4;
    // 004218ef  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004218f3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004218f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004218f6  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004218f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004218fa  7539                   -jne 0x421935
    if (!cpu.flags.zf)
    {
        goto L_0x00421935;
    }
    // 004218fc  a1594c4d00             -mov eax, dword ptr [0x4d4c59]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065817) /* 0x4d4c59 */);
    // 00421901  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 00421906  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00421909  e802feffff             -call 0x421710
    cpu.esp -= 4;
    sub_421710(app, cpu);
    if (cpu.terminate) return;
    // 0042190e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421910  7541                   -jne 0x421953
    if (!cpu.flags.zf)
    {
        goto L_0x00421953;
    }
    // 00421912  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421915  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421916  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421917  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421918  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0042191b:
    // 0042191b  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0042191e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00421921  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421922  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00421924  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421927  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042192c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042192f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421930  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421932  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421935:
    // 00421935  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421936  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042193a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0042193e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042193f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00421941  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421944  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042194a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042194d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042194e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042194f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421950  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00421953:
    // 00421953  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00421956  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00421959  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042195a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0042195c  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042195f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421964  01055c4c4d00           -add dword ptr [0x4d4c5c], eax
    (app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042196a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042196d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042196e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042196f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421970  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00421980, cpu);
    // 00421980  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421981  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421982  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421989  0f848e000000           -je 0x421a1d
    if (cpu.flags.zf)
    {
        goto L_0x00421a1d;
    }
    // 0042198f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421991  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421992  833d484c4d0000         +cmp dword ptr [0x4d4c48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421999  7432                   -je 0x4219cd
    if (cpu.flags.zf)
    {
        goto L_0x004219cd;
    }
    // 0042199b  8b1d504c4d00           -mov ebx, dword ptr [0x4d4c50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065808) /* 0x4d4c50 */);
    // 004219a1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004219a3  7408                   -je 0x4219ad
    if (cpu.flags.zf)
    {
        goto L_0x004219ad;
    }
    // 004219a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004219a6  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004219ad:
    // 004219ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004219ae  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 004219b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004219b4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004219b6  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004219b9  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 004219be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004219bf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004219c1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004219c3  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004219c6  893d484c4d00           -mov dword ptr [0x4d4c48], edi
    app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */) = cpu.edi;
    // 004219cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004219cd:
    // 004219cd  8b2d4c4c4d00           -mov ebp, dword ptr [0x4d4c4c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 004219d3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004219d5  7557                   -jne 0x421a2e
    if (!cpu.flags.zf)
    {
        goto L_0x00421a2e;
    }
L_0x004219d7:
    // 004219d7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004219d9:
    // 004219d9  8b9348734e00           -mov edx, dword ptr [ebx + 0x4e7348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5141320) /* 0x4e7348 */);
    // 004219df  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004219e1  741c                   -je 0x4219ff
    if (cpu.flags.zf)
    {
        goto L_0x004219ff;
    }
    // 004219e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004219e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004219e6  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004219e8  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004219eb  8b8348734e00           -mov eax, dword ptr [ebx + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5141320) /* 0x4e7348 */);
    // 004219f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004219f2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004219f4  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004219f7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004219f9  898b48734e00           -mov dword ptr [ebx + 0x4e7348], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5141320) /* 0x4e7348 */) = cpu.ecx;
L_0x004219ff:
    // 004219ff  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421a02  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421a05  75d2                   -jne 0x4219d9
    if (!cpu.flags.zf)
    {
        goto L_0x004219d9;
    }
    // 00421a07  a1444c4d00             -mov eax, dword ptr [0x4d4c44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
    // 00421a0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421a0d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421a0f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421a11  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421a14  891d444c4d00           -mov dword ptr [0x4d4c44], ebx
    app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */) = cpu.ebx;
    // 00421a1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00421a1d:
    // 00421a1d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00421a1f  89355c4c4d00           -mov dword ptr [0x4d4c5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */) = cpu.esi;
    // 00421a25  8935584c4d00           -mov dword ptr [0x4d4c58], esi
    app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */) = cpu.esi;
    // 00421a2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421a2e:
    // 00421a2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421a2f  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00421a32  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421a35  a14c4c4d00             -mov eax, dword ptr [0x4d4c4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 00421a3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421a3b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421a3d  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421a40  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00421a42  a34c4c4d00             -mov dword ptr [0x4d4c4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */) = cpu.eax;
    // 00421a47  eb8e                   -jmp 0x4219d7
    goto L_0x004219d7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00421a50, cpu);
    // 00421a50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421a51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421a52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421a53  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421a56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00421a58  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00421a5c  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00421a5e  0fbed8                 -movsx ebx, al
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00421a61  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 00421a68  8b9748734e00           -mov edx, dword ptr [edi + 0x4e7348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5141320) /* 0x4e7348 */);
    // 00421a6e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421a70  7521                   -jne 0x421a93
    if (!cpu.flags.zf)
    {
        goto L_0x00421a93;
    }
    // 00421a72  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00421a76  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421a78  7515                   -jne 0x421a8f
    if (!cpu.flags.zf)
    {
        goto L_0x00421a8f;
    }
L_0x00421a7a:
    // 00421a7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421a7c  7406                   -je 0x421a84
    if (cpu.flags.zf)
    {
        goto L_0x00421a84;
    }
    // 00421a7e  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x00421a84:
    // 00421a84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421a86  83c454                 +add esp, 0x54
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421a89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421a8c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00421a8f:
    // 00421a8f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00421a91  ebe7                   -jmp 0x421a7a
    goto L_0x00421a7a;
L_0x00421a93:
    // 00421a93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00421a95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421a96  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00421a98  ff5264                 -call dword ptr [edx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421a9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421a9d  7420                   -je 0x421abf
    if (cpu.flags.zf)
    {
        goto L_0x00421abf;
    }
    // 00421a9f  3d1e000780             +cmp eax, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421aa4  7407                   -je 0x421aad
    if (cpu.flags.zf)
    {
        goto L_0x00421aad;
    }
    // 00421aa6  3d0c000780             +cmp eax, 0x8007000c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942412 /*0x8007000c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421aab  75d7                   -jne 0x421a84
    if (!cpu.flags.zf)
    {
        goto L_0x00421a84;
    }
L_0x00421aad:
    // 00421aad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00421aaf  e84cfbffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 00421ab4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421ab6  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421ab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421aba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421abb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421abc  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00421abf:
    // 00421abf  8b8748734e00           -mov eax, dword ptr [edi + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5141320) /* 0x4e7348 */);
    // 00421ac5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00421ac7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421ac8  6a50                   -push 0x50
    app->getMemory<x86::reg32>(cpu.esp-4) = 80 /*0x50*/;
    cpu.esp -= 4;
    // 00421aca  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421acc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421acd  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ad0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421ad2  7419                   -je 0x421aed
    if (cpu.flags.zf)
    {
        goto L_0x00421aed;
    }
    // 00421ad4  3d1e000780             +cmp eax, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421ad9  75a9                   -jne 0x421a84
    if (!cpu.flags.zf)
    {
        goto L_0x00421a84;
    }
    // 00421adb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00421add  e81efbffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 00421ae2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421ae4  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421ae7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ae8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ae9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421aea  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00421aed:
    // 00421aed  8b4c2450               -mov ecx, dword ptr [esp + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00421af1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421af3  7405                   -je 0x421afa
    if (cpu.flags.zf)
    {
        goto L_0x00421afa;
    }
    // 00421af5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00421af8  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00421afa:
    // 00421afa  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421afc  7407                   -je 0x421b05
    if (cpu.flags.zf)
    {
        goto L_0x00421b05;
    }
    // 00421afe  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421b02  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00421b05:
    // 00421b05  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00421b09  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00421b0b  7406                   -je 0x421b13
    if (cpu.flags.zf)
    {
        goto L_0x00421b13;
    }
    // 00421b0d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00421b11  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00421b13:
    // 00421b13  8b7c2468               -mov edi, dword ptr [esp + 0x68]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00421b17  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421b19  7406                   -je 0x421b21
    if (cpu.flags.zf)
    {
        goto L_0x00421b21;
    }
    // 00421b1b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00421b1f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00421b21:
    // 00421b21  8b6c246c               -mov ebp, dword ptr [esp + 0x6c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00421b25  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421b27  7407                   -je 0x421b30
    if (cpu.flags.zf)
    {
        goto L_0x00421b30;
    }
    // 00421b29  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00421b2d  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00421b30:
    // 00421b30  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421b35  740a                   -je 0x421b41
    if (cpu.flags.zf)
    {
        goto L_0x00421b41;
    }
    // 00421b37  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00421b3b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00421b3f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00421b41:
    // 00421b41  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00421b45  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421b47  7406                   -je 0x421b4f
    if (cpu.flags.zf)
    {
        goto L_0x00421b4f;
    }
    // 00421b49  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421b4d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00421b4f:
    // 00421b4f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421b51  7424                   -je 0x421b77
    if (cpu.flags.zf)
    {
        goto L_0x00421b77;
    }
    // 00421b53  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00421b59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00421b5b:
    // 00421b5b  f644043080             +test byte ptr [esp + eax + 0x30], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 00421b60  740f                   -je 0x421b71
    if (cpu.flags.zf)
    {
        goto L_0x00421b71;
    }
    // 00421b62  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00421b67  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00421b69  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421b6b  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00421b6d  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00421b6f  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
L_0x00421b71:
    // 00421b71  40                     -inc eax
    (cpu.eax)++;
    // 00421b72  83f820                 +cmp eax, 0x20
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
    // 00421b75  7ce4                   -jl 0x421b5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421b5b;
    }
L_0x00421b77:
    // 00421b77  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421b7c  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00421b7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421b82  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00421b90, cpu);
    // 00421b90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421b91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421b92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421b93  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421b97  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421b98  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421b9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421b9d  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421ba1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421ba2  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421ba6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421ba7  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00421bab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421bac  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00421baf  e89cfeffff             -call 0x421a50
    cpu.esp -= 4;
    sub_421a50(app, cpu);
    if (cpu.terminate) return;
    // 00421bb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421bb6  7405                   -je 0x421bbd
    if (cpu.flags.zf)
    {
        goto L_0x00421bbd;
    }
    // 00421bb8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00421bbd:
    // 00421bbd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421bc0  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00421bd0, cpu);
    // 00421bd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421bd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421bd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421bd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00421bd4  81ec8c010000           -sub esp, 0x18c
    (cpu.esp) -= x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 00421bda  88842488010000         -mov byte ptr [esp + 0x188], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.al;
    // 00421be1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00421be3  899c2480010000         -mov dword ptr [esp + 0x180], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.ebx;
    // 00421bea  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00421bef  8dbc2468010000         -lea edi, [esp + 0x168]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(360) /* 0x168 */);
    // 00421bf6  be94154200             -mov esi, 0x421594
    cpu.esi = 4330900 /*0x421594*/;
    // 00421bfb  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00421bfd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421bff  756c                   -jne 0x421c6d
    if (!cpu.flags.zf)
    {
        goto L_0x00421c6d;
    }
L_0x00421c01:
    // 00421c01  8b942480010000         -mov edx, dword ptr [esp + 0x180]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00421c08  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421c0a  7406                   -je 0x421c12
    if (cpu.flags.zf)
    {
        goto L_0x00421c12;
    }
    // 00421c0c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x00421c12:
    // 00421c12  80bc248801000010       +cmp byte ptr [esp + 0x188], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(392) /* 0x188 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421c1a  7559                   -jne 0x421c75
    if (!cpu.flags.zf)
    {
        goto L_0x00421c75;
    }
    // 00421c1c  c78424840100000f000000 -mov dword ptr [esp + 0x184], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = 15 /*0xf*/;
L_0x00421c27:
    // 00421c27  8b842481010000         -mov eax, dword ptr [esp + 0x181]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(385) /* 0x181 */);
    // 00421c2e  8b9c2480010000         -mov ebx, dword ptr [esp + 0x180]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00421c35  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00421c37  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00421c3a  e891ffffff             -call 0x421bd0
    cpu.esp -= 4;
    sub_421bd0(app, cpu);
    if (cpu.terminate) return;
    // 00421c3f  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00421c46  48                     -dec eax
    (cpu.eax)--;
    // 00421c47  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 00421c4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421c50  7fd5                   -jg 0x421c27
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00421c27;
    }
    // 00421c52  8b9c2480010000         -mov ebx, dword ptr [esp + 0x180]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00421c59  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00421c5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421c5d  e86effffff             -call 0x421bd0
    cpu.esp -= 4;
    sub_421bd0(app, cpu);
    if (cpu.terminate) return;
    // 00421c62  81c48c010000           +add esp, 0x18c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(396 /*0x18c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00421c68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421c6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421c6d:
    // 00421c6d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00421c73  eb8c                   -jmp 0x421c01
    goto L_0x00421c01;
L_0x00421c75:
    // 00421c75  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421c7c  7427                   -je 0x421ca5
    if (cpu.flags.zf)
    {
        goto L_0x00421ca5;
    }
L_0x00421c7e:
    // 00421c7e  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421c85  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00421c88  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00421c8f  83b948734e0000         +cmp dword ptr [ecx + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5141320) /* 0x4e7348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421c96  7528                   -jne 0x421cc0
    if (!cpu.flags.zf)
    {
        goto L_0x00421cc0;
    }
    // 00421c98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421c9a  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 00421ca0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ca4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421ca5:
    // 00421ca5  e886080000             -call 0x422530
    cpu.esp -= 4;
    sub_422530(app, cpu);
    if (cpu.terminate) return;
    // 00421caa  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421cb1  75cb                   -jne 0x421c7e
    if (!cpu.flags.zf)
    {
        goto L_0x00421c7e;
    }
L_0x00421cb3:
    // 00421cb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421cb5  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 00421cbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421cbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421cc0:
    // 00421cc0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00421cc2  e839f9ffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 00421cc7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421cce  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421cd0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421cd3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421cd5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00421cd8  83b888734e0000         +cmp dword ptr [eax + 0x4e7388], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141384) /* 0x4e7388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421cdf  0f847d000000           -je 0x421d62
    if (cpu.flags.zf)
    {
        goto L_0x00421d62;
    }
L_0x00421ce5:
    // 00421ce5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421ce7  7422                   -je 0x421d0b
    if (cpu.flags.zf)
    {
        goto L_0x00421d0b;
    }
    // 00421ce9  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421cf0  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00421cf3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421cfa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421cfc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421cff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d01  8b048588734e00         -mov eax, dword ptr [eax*4 + 0x4e7388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141384) /* 0x4e7388 */ + cpu.eax * 4);
    // 00421d08  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00421d0b:
    // 00421d0b  8b8c2480010000         -mov ecx, dword ptr [esp + 0x180]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00421d12  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00421d14  7421                   -je 0x421d37
    if (cpu.flags.zf)
    {
        goto L_0x00421d37;
    }
    // 00421d16  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421d1d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00421d20  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421d27  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d29  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421d2c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d2e  8b04858c734e00         -mov eax, dword ptr [eax*4 + 0x4e738c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141388) /* 0x4e738c */ + cpu.eax * 4);
    // 00421d35  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00421d37:
    // 00421d37  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421d3e  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00421d41  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421d48  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d4a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421d4d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421d4f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00421d52  0588734e00             -add eax, 0x4e7388
    (cpu.eax) += x86::reg32(x86::sreg32(5141384 /*0x4e7388*/));
    // 00421d57  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 00421d5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421d61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421d62:
    // 00421d62  83b88c734e0000         +cmp dword ptr [eax + 0x4e738c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141388) /* 0x4e738c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421d69  0f8576ffffff           -jne 0x421ce5
    if (!cpu.flags.zf)
    {
        goto L_0x00421ce5;
    }
    // 00421d6f  bb2c000000             -mov ebx, 0x2c
    cpu.ebx = 44 /*0x2c*/;
    // 00421d74  8b8148734e00           -mov eax, dword ptr [ecx + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5141320) /* 0x4e7348 */);
    // 00421d7a  8d8c243c010000         -lea ecx, [esp + 0x13c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00421d81  899c243c010000         -mov dword ptr [esp + 0x13c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.ebx;
    // 00421d88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421d89  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421d8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421d8c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421d8f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421d91  0f851cffffff           -jne 0x421cb3
    if (!cpu.flags.zf)
    {
        goto L_0x00421cb3;
    }
    // 00421d97  f684244101000001       +test byte ptr [esp + 0x141], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(321) /* 0x141 */) & 1 /*0x1*/));
    // 00421d9f  741f                   -je 0x421dc0
    if (cpu.flags.zf)
    {
        goto L_0x00421dc0;
    }
    // 00421da1  8b8c2485010000         -mov ecx, dword ptr [esp + 0x185]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421da8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421dad  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00421db0  8b35584c4d00           -mov esi, dword ptr [0x4d4c58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00421db6  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00421db8  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00421dba  8935584c4d00           -mov dword ptr [0x4d4c58], esi
    app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */) = cpu.esi;
L_0x00421dc0:
    // 00421dc0  bf3c010000             -mov edi, 0x13c
    cpu.edi = 316 /*0x13c*/;
    // 00421dc5  8b94244c010000         -mov edx, dword ptr [esp + 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 00421dcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421dce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421dd0  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 00421dd7  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00421dda  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00421ddc  7669                   -jbe 0x421e47
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00421e47;
    }
    // 00421dde  be30000000             -mov esi, 0x30
    cpu.esi = 48 /*0x30*/;
L_0x00421de3:
    // 00421de3  83fb20                 +cmp ebx, 0x20
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
    // 00421de6  7d5f                   -jge 0x421e47
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421e47;
    }
    // 00421de8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00421dea  8bbc2489010000         -mov edi, dword ptr [esp + 0x189]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(393) /* 0x189 */);
    // 00421df1  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00421df5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421df6  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00421df9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421dfa  8b04bd48734e00         -mov eax, dword ptr [edi*4 + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141320) /* 0x4e7348 */ + cpu.edi * 4);
    // 00421e01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421e02  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421e04  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421e07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421e09  7528                   -jne 0x421e33
    if (!cpu.flags.zf)
    {
        goto L_0x00421e33;
    }
    // 00421e0b  6bc75c                 -imul eax, edi, 0x5c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(92 /*0x5c*/)));
    // 00421e0e  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00421e10  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00421e15  8b9088734e00           -mov edx, dword ptr [eax + 0x4e7388]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141384) /* 0x4e7388 */);
    // 00421e1b  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 00421e1d  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00421e1f  899088734e00           -mov dword ptr [eax + 0x4e7388], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141384) /* 0x4e7388 */) = cpu.edx;
    // 00421e25  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00421e27  7403                   -je 0x421e2c
    if (cpu.flags.zf)
    {
        goto L_0x00421e2c;
    }
    // 00421e29  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x00421e2c:
    // 00421e2c  ff842484010000         -inc dword ptr [esp + 0x184]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */))++;
L_0x00421e33:
    // 00421e33  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00421e3a  8bbc244c010000         -mov edi, dword ptr [esp + 0x14c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 00421e41  46                     -inc esi
    (cpu.esi)++;
    // 00421e42  43                     -inc ebx
    (cpu.ebx)++;
    // 00421e43  39f8                   +cmp eax, edi
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
    // 00421e45  729c                   -jb 0x421de3
    if (cpu.flags.cf)
    {
        goto L_0x00421de3;
    }
L_0x00421e47:
    // 00421e47  8b842448010000         -mov eax, dword ptr [esp + 0x148]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 00421e4e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00421e50  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421e52  89ac2484010000         -mov dword ptr [esp + 0x184], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.ebp;
    // 00421e59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421e5b  0f8675000000           -jbe 0x421ed6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00421ed6;
    }
    // 00421e61  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00421e63:
    // 00421e63  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421e66  7d6e                   -jge 0x421ed6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421ed6;
    }
    // 00421e68  8bac2485010000         -mov ebp, dword ptr [esp + 0x185]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421e6f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00421e71  8b94346c010000         -mov edx, dword ptr [esp + esi + 0x16c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */ + cpu.esi * 1);
    // 00421e78  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 00421e7b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421e7c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00421e80  8b04ad48734e00         -mov eax, dword ptr [ebp*4 + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141320) /* 0x4e7348 */ + cpu.ebp * 4);
    // 00421e87  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421e88  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421e8a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421e8b  ff5138                 -call dword ptr [ecx + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421e8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00421e90  752e                   -jne 0x421ec0
    if (!cpu.flags.zf)
    {
        goto L_0x00421ec0;
    }
    // 00421e92  6bed5c                 -imul ebp, ebp, 0x5c
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(92 /*0x5c*/)));
    // 00421e95  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00421e9a  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00421e9c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00421e9e  8b8d8c734e00           -mov ecx, dword ptr [ebp + 0x4e738c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5141388) /* 0x4e738c */);
    // 00421ea4  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00421ea6  8bbc2480010000         -mov edi, dword ptr [esp + 0x180]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00421ead  898d8c734e00           -mov dword ptr [ebp + 0x4e738c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5141388) /* 0x4e738c */) = cpu.ecx;
    // 00421eb3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421eb5  7402                   -je 0x421eb9
    if (cpu.flags.zf)
    {
        goto L_0x00421eb9;
    }
    // 00421eb7  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
L_0x00421eb9:
    // 00421eb9  ff842484010000         -inc dword ptr [esp + 0x184]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */))++;
L_0x00421ec0:
    // 00421ec0  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00421ec7  8bbc2448010000         -mov edi, dword ptr [esp + 0x148]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 00421ece  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00421ed1  43                     -inc ebx
    (cpu.ebx)++;
    // 00421ed2  39f8                   +cmp eax, edi
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
    // 00421ed4  728d                   -jb 0x421e63
    if (cpu.flags.cf)
    {
        goto L_0x00421e63;
    }
L_0x00421ed6:
    // 00421ed6  8b942485010000         -mov edx, dword ptr [esp + 0x185]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(389) /* 0x185 */);
    // 00421edd  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00421ee0  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00421ee7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421ee9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00421eec  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00421eee  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00421ef1  0588734e00             -add eax, 0x4e7388
    (cpu.eax) += x86::reg32(x86::sreg32(5141384 /*0x4e7388*/));
    // 00421ef6  81c48c010000           -add esp, 0x18c
    (cpu.esp) += x86::reg32(x86::sreg32(396 /*0x18c*/));
    // 00421efc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421efd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421efe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421eff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00421f10, cpu);
    // 00421f10  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421f17  7463                   -je 0x421f7c
    if (cpu.flags.zf)
    {
        goto L_0x00421f7c;
    }
    // 00421f19  833d644c4d0000         +cmp dword ptr [0x4d4c64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065828) /* 0x4d4c64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421f20  756b                   -jne 0x421f8d
    if (!cpu.flags.zf)
    {
        goto L_0x00421f8d;
    }
L_0x00421f22:
    // 00421f22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00421f23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421f24  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00421f29  8b3d5c4c4d00           -mov edi, dword ptr [0x4d4c5c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 00421f2f  8935644c4d00           -mov dword ptr [0x4d4c64], esi
    app->getMemory<x86::reg32>(x86::reg32(5065828) /* 0x4d4c64 */) = cpu.esi;
    // 00421f35  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00421f37  7528                   -jne 0x421f61
    if (!cpu.flags.zf)
    {
        goto L_0x00421f61;
    }
    // 00421f39  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421f3a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421f3b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421f3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421f3d  a1444c4d00             -mov eax, dword ptr [0x4d4c44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
    // 00421f42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421f43  68f0174200             -push 0x4217f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4331504 /*0x4217f0*/;
    cpu.esp -= 4;
    // 00421f48  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00421f4a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00421f4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00421f4d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00421f4f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421f52  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00421f57  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00421f59  e872fcffff             -call 0x421bd0
    cpu.esp -= 4;
    sub_421bd0(app, cpu);
    if (cpu.terminate) return;
    // 00421f5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00421f61:
    // 00421f61  833d5c4c4d0000         +cmp dword ptr [0x4d4c5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421f68  740a                   -je 0x421f74
    if (cpu.flags.zf)
    {
        goto L_0x00421f74;
    }
    // 00421f6a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00421f6f  e88cf6ffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
L_0x00421f74:
    // 00421f74  a15c4c4d00             -mov eax, dword ptr [0x4d4c5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 00421f79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421f7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421f7c:
    // 00421f7c  e8af050000             -call 0x422530
    cpu.esp -= 4;
    sub_422530(app, cpu);
    if (cpu.terminate) return;
    // 00421f81  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00421f88  7598                   -jne 0x421f22
    if (!cpu.flags.zf)
    {
        goto L_0x00421f22;
    }
    // 00421f8a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00421f8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421f8d:
    // 00421f8d  a15c4c4d00             -mov eax, dword ptr [0x4d4c5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
    // 00421f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_421fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00421fa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00421fa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00421fa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00421fa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421fa4  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00421fa6  3c13                   +cmp al, 0x13
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(19 /*0x13*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421fa8  741b                   -je 0x421fc5
    if (cpu.flags.zf)
    {
        goto L_0x00421fc5;
    }
L_0x00421faa:
    // 00421faa  80fa10                 +cmp dl, 0x10
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
    // 00421fad  7536                   -jne 0x421fe5
    if (!cpu.flags.zf)
    {
        goto L_0x00421fe5;
    }
    // 00421faf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00421fb1:
    // 00421fb1  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00421fb4  42                     -inc edx
    (cpu.edx)++;
    // 00421fb5  e8e6ffffff             -call 0x421fa0
    cpu.esp -= 4;
    sub_421fa0(app, cpu);
    if (cpu.terminate) return;
    // 00421fba  83fa10                 +cmp edx, 0x10
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
    // 00421fbd  7cf2                   -jl 0x421fb1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421fb1;
    }
    // 00421fbf  90                     -nop 
    ;
L_0x00421fc0:
    // 00421fc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fc3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421fc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421fc5:
    // 00421fc5  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00421fca  e8d1ffffff             -call 0x421fa0
    cpu.esp -= 4;
    sub_421fa0(app, cpu);
    if (cpu.terminate) return;
    // 00421fcf  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00421fd4  e8c7ffffff             -call 0x421fa0
    cpu.esp -= 4;
    sub_421fa0(app, cpu);
    if (cpu.terminate) return;
    // 00421fd9  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00421fde  e8bdffffff             -call 0x421fa0
    cpu.esp -= 4;
    sub_421fa0(app, cpu);
    if (cpu.terminate) return;
    // 00421fe3  ebc5                   -jmp 0x421faa
    goto L_0x00421faa;
L_0x00421fe5:
    // 00421fe5  80fa11                 +cmp dl, 0x11
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00421fe8  7515                   -jne 0x421fff
    if (!cpu.flags.zf)
    {
        goto L_0x00421fff;
    }
    // 00421fea  8b35484c4d00           -mov esi, dword ptr [0x4d4c48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 00421ff0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00421ff2  74cc                   -je 0x421fc0
    if (cpu.flags.zf)
    {
        goto L_0x00421fc0;
    }
    // 00421ff4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00421ff5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00421ff7  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00421ffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ffb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ffc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ffd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00421ffe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00421fff:
    // 00421fff  80fa12                 +cmp dl, 0x12
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422002  7515                   -jne 0x422019
    if (!cpu.flags.zf)
    {
        goto L_0x00422019;
    }
    // 00422004  8b1d4c4c4d00           -mov ebx, dword ptr [0x4d4c4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 0042200a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0042200c  74b2                   -je 0x421fc0
    if (cpu.flags.zf)
    {
        goto L_0x00421fc0;
    }
    // 0042200e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042200f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00422011  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422014  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422015  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422016  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422017  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422019:
    // 00422019  7515                   -jne 0x422030
    if (!cpu.flags.zf)
    {
        goto L_0x00422030;
    }
    // 0042201b  8b0d4c4c4d00           -mov ecx, dword ptr [0x4d4c4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065804) /* 0x4d4c4c */);
    // 00422021  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00422023  749b                   -je 0x421fc0
    if (cpu.flags.zf)
    {
        goto L_0x00421fc0;
    }
    // 00422025  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422026  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422028  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042202b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042202c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042202d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042202e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042202f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422030:
    // 00422030  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00422032  7c8c                   -jl 0x421fc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00421fc0;
    }
    // 00422034  80fa10                 +cmp dl, 0x10
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
    // 00422037  7d87                   -jge 0x421fc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00421fc0;
    }
    // 00422039  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 0042203c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042203f  8b9048734e00           -mov edx, dword ptr [eax + 0x4e7348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141320) /* 0x4e7348 */);
    // 00422045  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00422047  0f8473ffffff           -je 0x421fc0
    if (cpu.flags.zf)
    {
        goto L_0x00421fc0;
    }
    // 0042204d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0042204f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422050  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00422052  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422055  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422056  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422058  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422059  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00422060, cpu);
    // 00422060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422061  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422062  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422063  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422064  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0042206a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0042206c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0042206e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00422070  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00422072  8d8c2404020000         -lea ecx, [esp + 0x204]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 00422079  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042207a  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0042207e  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00422083  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422084  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 00422089  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 00422090  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00422092  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422094  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422095  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422098  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0042209a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042209c  0f8580000000           -jne 0x422122
    if (!cpu.flags.zf)
    {
        goto L_0x00422122;
    }
    // 004220a2  8b8c2400020000         -mov ecx, dword ptr [esp + 0x200]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004220a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004220ab  7635                   -jbe 0x4220e2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004220e2;
    }
    // 004220ad  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004220af  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
L_0x004220b2:
    // 004220b2  8b0c04                 -mov ecx, dword ptr [esp + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 004220b5  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004220b8  0f85c9000000           -jne 0x422187
    if (!cpu.flags.zf)
    {
        goto L_0x00422187;
    }
    // 004220be  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 004220c3  0f84af000000           -je 0x422178
    if (cpu.flags.zf)
    {
        goto L_0x00422178;
    }
    // 004220c9  8a2d50894e00           -mov ch, byte ptr [0x4e8950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5146960) /* 0x4e8950 */);
    // 004220cf  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004220d2  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004220d5:
    // 004220d5  882d50894e00           -mov byte ptr [0x4e8950], ch
    app->getMemory<x86::reg8>(x86::reg32(5146960) /* 0x4e8950 */) = cpu.ch;
L_0x004220db:
    // 004220db  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004220de  39d8                   +cmp eax, ebx
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
    // 004220e0  7cd0                   -jl 0x4220b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004220b2;
    }
L_0x004220e2:
    // 004220e2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004220e4  740a                   -je 0x4220f0
    if (cpu.flags.zf)
    {
        goto L_0x004220f0;
    }
    // 004220e6  a150894e00             -mov eax, dword ptr [0x4e8950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */);
    // 004220eb  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004220ed  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x004220f0:
    // 004220f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004220f2  7407                   -je 0x4220fb
    if (cpu.flags.zf)
    {
        goto L_0x004220fb;
    }
    // 004220f4  a148894e00             -mov eax, dword ptr [0x4e8948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */);
    // 004220f9  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004220fb:
    // 004220fb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004220fd  7407                   -je 0x422106
    if (cpu.flags.zf)
    {
        goto L_0x00422106;
    }
    // 004220ff  a14c894e00             -mov eax, dword ptr [0x4e894c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */);
    // 00422104  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00422106:
    // 00422106  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042210d  7408                   -je 0x422117
    if (cpu.flags.zf)
    {
        goto L_0x00422117;
    }
    // 0042210f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00422111  0f858d010000           -jne 0x4222a4
    if (!cpu.flags.zf)
    {
        goto L_0x004222a4;
    }
L_0x00422117:
    // 00422117  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0042211d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042211e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042211f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422120  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422121  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422122:
    // 00422122  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422124  891d50894e00           -mov dword ptr [0x4e8950], ebx
    app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */) = cpu.ebx;
    // 0042212a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042212c  7403                   -je 0x422131
    if (cpu.flags.zf)
    {
        goto L_0x00422131;
    }
    // 0042212e  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
L_0x00422131:
    // 00422131  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00422133  7407                   -je 0x42213c
    if (cpu.flags.zf)
    {
        goto L_0x0042213c;
    }
    // 00422135  a148894e00             -mov eax, dword ptr [0x4e8948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */);
    // 0042213a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0042213c:
    // 0042213c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042213e  7407                   -je 0x422147
    if (cpu.flags.zf)
    {
        goto L_0x00422147;
    }
    // 00422140  a14c894e00             -mov eax, dword ptr [0x4e894c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */);
    // 00422145  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00422147:
    // 00422147  81fa07020480           +cmp edx, 0x80040207
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147746311 /*0x80040207*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042214d  72c8                   -jb 0x422117
    if (cpu.flags.cf)
    {
        goto L_0x00422117;
    }
    // 0042214f  76c6                   -jbe 0x422117
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422117;
    }
    // 00422151  81fa0c000780           +cmp edx, 0x8007000c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942412 /*0x8007000c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422157  72be                   -jb 0x422117
    if (cpu.flags.cf)
    {
        goto L_0x00422117;
    }
    // 00422159  7608                   -jbe 0x422163
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422163;
    }
    // 0042215b  81fa1e000780           +cmp edx, 0x8007001e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147942430 /*0x8007001e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422161  75b4                   -jne 0x422117
    if (!cpu.flags.zf)
    {
        goto L_0x00422117;
    }
L_0x00422163:
    // 00422163  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00422168  e893f4ffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
    // 0042216d  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00422173  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422174  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422175  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422177  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422178:
    // 00422178  812550894e00fe000000   +and dword ptr [0x4e8950], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */) &= x86::reg32(x86::sreg32(254 /*0xfe*/))));
    // 00422182  e954ffffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x00422187:
    // 00422187  83f90d                 +cmp ecx, 0xd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042218a  7527                   -jne 0x4221b3
    if (!cpu.flags.zf)
    {
        goto L_0x004221b3;
    }
    // 0042218c  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 00422191  7411                   -je 0x4221a4
    if (cpu.flags.zf)
    {
        goto L_0x004221a4;
    }
    // 00422193  8a2d50894e00           -mov ch, byte ptr [0x4e8950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5146960) /* 0x4e8950 */);
    // 00422199  80cd02                 -or ch, 2
    cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0042219c  80ca02                 +or dl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0042219f  e931ffffff             -jmp 0x4220d5
    goto L_0x004220d5;
L_0x004221a4:
    // 004221a4  812550894e00fd000000   +and dword ptr [0x4e8950], 0xfd
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */) &= x86::reg32(x86::sreg32(253 /*0xfd*/))));
    // 004221ae  e928ffffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x004221b3:
    // 004221b3  83f90e                 +cmp ecx, 0xe
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
    // 004221b6  7527                   -jne 0x4221df
    if (!cpu.flags.zf)
    {
        goto L_0x004221df;
    }
    // 004221b8  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 004221bd  7411                   -je 0x4221d0
    if (cpu.flags.zf)
    {
        goto L_0x004221d0;
    }
    // 004221bf  8a2d50894e00           -mov ch, byte ptr [0x4e8950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5146960) /* 0x4e8950 */);
    // 004221c5  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004221c8  80ca04                 +or dl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004221cb  e905ffffff             -jmp 0x4220d5
    goto L_0x004220d5;
L_0x004221d0:
    // 004221d0  812550894e00fb000000   +and dword ptr [0x4e8950], 0xfb
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */) &= x86::reg32(x86::sreg32(251 /*0xfb*/))));
    // 004221da  e9fcfeffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x004221df:
    // 004221df  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004221e2  7527                   -jne 0x42220b
    if (!cpu.flags.zf)
    {
        goto L_0x0042220b;
    }
    // 004221e4  f644040480             +test byte ptr [esp + eax + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) & 128 /*0x80*/));
    // 004221e9  7411                   -je 0x4221fc
    if (cpu.flags.zf)
    {
        goto L_0x004221fc;
    }
    // 004221eb  8a2d50894e00           -mov ch, byte ptr [0x4e8950]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5146960) /* 0x4e8950 */);
    // 004221f1  80cd08                 -or ch, 8
    cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004221f4  80ca08                 +or dl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004221f7  e9d9feffff             -jmp 0x4220d5
    goto L_0x004220d5;
L_0x004221fc:
    // 004221fc  812550894e00f7000000   +and dword ptr [0x4e8950], 0xf7
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */) &= x86::reg32(x86::sreg32(247 /*0xf7*/))));
    // 00422206  e9d0feffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x0042220b:
    // 0042220b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0042220d  7546                   -jne 0x422255
    if (!cpu.flags.zf)
    {
        goto L_0x00422255;
    }
    // 0042220f  8b4c0404               -mov ecx, dword ptr [esp + eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00422213  010d48894e00           -add dword ptr [0x4e8948], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422219  8b0d48894e00           -mov ecx, dword ptr [0x4e8948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */);
    // 0042221f  3b0d38894e00           +cmp ecx, dword ptr [0x4e8938]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5146936) /* 0x4e8938 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422225  7d11                   -jge 0x422238
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422238;
    }
    // 00422227  8b0d38894e00           -mov ecx, dword ptr [0x4e8938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146936) /* 0x4e8938 */);
    // 0042222d  890d48894e00           -mov dword ptr [0x4e8948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */) = cpu.ecx;
    // 00422233  e9a3feffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x00422238:
    // 00422238  3b0d40894e00           +cmp ecx, dword ptr [0x4e8940]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5146944) /* 0x4e8940 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042223e  0f8e97feffff           -jle 0x4220db
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004220db;
    }
    // 00422244  8b0d40894e00           -mov ecx, dword ptr [0x4e8940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146944) /* 0x4e8940 */);
    // 0042224a  890d48894e00           -mov dword ptr [0x4e8948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */) = cpu.ecx;
    // 00422250  e986feffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x00422255:
    // 00422255  83f904                 +cmp ecx, 4
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
    // 00422258  0f857dfeffff           -jne 0x4220db
    if (!cpu.flags.zf)
    {
        goto L_0x004220db;
    }
    // 0042225e  8b4c0404               -mov ecx, dword ptr [esp + eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 00422262  010d4c894e00           -add dword ptr [0x4e894c], ecx
    (app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422268  8b0d4c894e00           -mov ecx, dword ptr [0x4e894c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */);
    // 0042226e  3b0d3c894e00           +cmp ecx, dword ptr [0x4e893c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5146940) /* 0x4e893c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422274  7d11                   -jge 0x422287
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422287;
    }
    // 00422276  8b0d3c894e00           -mov ecx, dword ptr [0x4e893c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146940) /* 0x4e893c */);
    // 0042227c  890d4c894e00           -mov dword ptr [0x4e894c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */) = cpu.ecx;
    // 00422282  e954feffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x00422287:
    // 00422287  3b0d44894e00           +cmp ecx, dword ptr [0x4e8944]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5146948) /* 0x4e8944 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042228d  0f8e48feffff           -jle 0x4220db
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004220db;
    }
    // 00422293  8b0d44894e00           -mov ecx, dword ptr [0x4e8944]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146948) /* 0x4e8944 */);
    // 00422299  890d4c894e00           -mov dword ptr [0x4e894c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */) = cpu.ecx;
    // 0042229f  e937feffff             -jmp 0x4220db
    goto L_0x004220db;
L_0x004222a4:
    // 004222a4  a150894e00             -mov eax, dword ptr [0x4e8950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */);
    // 004222a9  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004222ab  ff154cac4d00           -call dword ptr [0x4dac4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004222b1  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 004222b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004222b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004222b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004222ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004222bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4222c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004222c0  a338894e00             -mov dword ptr [0x4e8938], eax
    app->getMemory<x86::reg32>(x86::reg32(5146936) /* 0x4e8938 */) = cpu.eax;
    // 004222c5  89153c894e00           -mov dword ptr [0x4e893c], edx
    app->getMemory<x86::reg32>(x86::reg32(5146940) /* 0x4e893c */) = cpu.edx;
    // 004222cb  891d40894e00           -mov dword ptr [0x4e8940], ebx
    app->getMemory<x86::reg32>(x86::reg32(5146944) /* 0x4e8940 */) = cpu.ebx;
    // 004222d1  8b154c894e00           -mov edx, dword ptr [0x4e894c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */);
    // 004222d7  a148894e00             -mov eax, dword ptr [0x4e8948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */);
    // 004222dc  890d44894e00           -mov dword ptr [0x4e8944], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146948) /* 0x4e8944 */) = cpu.ecx;
    // 004222e2  e909000000             -jmp 0x4222f0
    return sub_4222f0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4222f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004222f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004222f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004222f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004222f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004222f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004222f5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004222f8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004222fa  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004222fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004222fe  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00422302  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422303  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00422308  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0042230a  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 0042230f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00422313  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00422315  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422317  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422318  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042231b  8b0d38894e00           -mov ecx, dword ptr [0x4e8938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146936) /* 0x4e8938 */);
    // 00422321  39ce                   +cmp esi, ecx
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
    // 00422323  7c31                   -jl 0x422356
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422356;
    }
    // 00422325  8b3d40894e00           -mov edi, dword ptr [0x4e8940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5146944) /* 0x4e8940 */);
    // 0042232b  39fe                   +cmp esi, edi
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
    // 0042232d  7e2f                   -jle 0x42235e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042235e;
    }
    // 0042232f  893d48894e00           -mov dword ptr [0x4e8948], edi
    app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */) = cpu.edi;
L_0x00422335:
    // 00422335  8b2d3c894e00           -mov ebp, dword ptr [0x4e893c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5146940) /* 0x4e893c */);
    // 0042233b  39eb                   +cmp ebx, ebp
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
    // 0042233d  7c27                   -jl 0x422366
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422366;
    }
    // 0042233f  a144894e00             -mov eax, dword ptr [0x4e8944]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146948) /* 0x4e8944 */);
    // 00422344  39c3                   +cmp ebx, eax
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
    // 00422346  7e26                   -jle 0x42236e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042236e;
    }
    // 00422348  a34c894e00             -mov dword ptr [0x4e894c], eax
    app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */) = cpu.eax;
L_0x0042234d:
    // 0042234d  83c404                 +add esp, 4
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
    // 00422350  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422351  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422352  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422353  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422354  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422355  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422356:
    // 00422356  890d48894e00           -mov dword ptr [0x4e8948], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */) = cpu.ecx;
    // 0042235c  ebd7                   -jmp 0x422335
    goto L_0x00422335;
L_0x0042235e:
    // 0042235e  893548894e00           -mov dword ptr [0x4e8948], esi
    app->getMemory<x86::reg32>(x86::reg32(5146952) /* 0x4e8948 */) = cpu.esi;
    // 00422364  ebcf                   -jmp 0x422335
    goto L_0x00422335;
L_0x00422366:
    // 00422366  892d4c894e00           -mov dword ptr [0x4e894c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */) = cpu.ebp;
    // 0042236c  ebdf                   -jmp 0x42234d
    goto L_0x0042234d;
L_0x0042236e:
    // 0042236e  891d4c894e00           -mov dword ptr [0x4e894c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5146956) /* 0x4e894c */) = cpu.ebx;
    // 00422374  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422377  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422378  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422379  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042237a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042237b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042237c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_422380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00422380, cpu);
    // 00422380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422383  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422384  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422385  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00422388  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042238f  7446                   -je 0x4223d7
    if (cpu.flags.zf)
    {
        goto L_0x004223d7;
    }
L_0x00422391:
    // 00422391  8b1d484c4d00           -mov ebx, dword ptr [0x4d4c48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 00422397  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00422399  744e                   -je 0x4223e9
    if (cpu.flags.zf)
    {
        goto L_0x004223e9;
    }
L_0x0042239b:
    // 0042239b  833d484c4d0000         +cmp dword ptr [0x4d4c48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004223a2  740a                   -je 0x4223ae
    if (cpu.flags.zf)
    {
        goto L_0x004223ae;
    }
    // 004223a4  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 004223a9  e852f2ffff             -call 0x421600
    cpu.esp -= 4;
    sub_421600(app, cpu);
    if (cpu.terminate) return;
L_0x004223ae:
    // 004223ae  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 004223b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004223b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004223b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004223b9  891d50894e00           -mov dword ptr [0x4e8950], ebx
    app->getMemory<x86::reg32>(x86::reg32(5146960) /* 0x4e8950 */) = cpu.ebx;
    // 004223bf  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 004223c4  e8f7feffff             -call 0x4222c0
    cpu.esp -= 4;
    sub_4222c0(app, cpu);
    if (cpu.terminate) return;
    // 004223c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004223ce:
    // 004223ce  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004223d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004223d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004223d7:
    // 004223d7  e854010000             -call 0x422530
    cpu.esp -= 4;
    sub_422530(app, cpu);
    if (cpu.terminate) return;
    // 004223dc  833d444c4d0000         +cmp dword ptr [0x4d4c44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004223e3  75ac                   -jne 0x422391
    if (!cpu.flags.zf)
    {
        goto L_0x00422391;
    }
    // 004223e5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004223e7  ebe5                   -jmp 0x4223ce
    goto L_0x004223ce;
L_0x004223e9:
    // 004223e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004223ea  68484c4d00             -push 0x4d4c48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5065800 /*0x4d4c48*/;
    cpu.esp -= 4;
    // 004223ef  a1444c4d00             -mov eax, dword ptr [0x4d4c44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
    // 004223f4  68d8274e00             -push 0x4e27d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122008 /*0x4e27d8*/;
    cpu.esp -= 4;
    // 004223f9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004223fb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004223fc  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004223ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422401  740b                   -je 0x42240e
    if (cpu.flags.zf)
    {
        goto L_0x0042240e;
    }
    // 00422403  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422405  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00422408  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422409  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042240a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042240b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042240c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042240d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042240e:
    // 0042240e  68c04b4c00             -push 0x4c4bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5000128 /*0x4c4bc0*/;
    cpu.esp -= 4;
    // 00422413  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 00422418  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422419  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042241b  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042241e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422420  740b                   -je 0x42242d
    if (cpu.flags.zf)
    {
        goto L_0x0042242d;
    }
    // 00422422  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00422424  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00422427  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422428  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422429  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042242a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042242b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042242c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042242d:
    // 0042242d  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00422432  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00422437  e8d4f2ffff             -call 0x421710
    cpu.esp -= 4;
    sub_421710(app, cpu);
    if (cpu.terminate) return;
    // 0042243c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042243e  748e                   -je 0x4223ce
    if (cpu.flags.zf)
    {
        goto L_0x004223ce;
    }
    // 00422440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422441  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422442  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422443  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422444  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042244b  a3504c4d00             -mov dword ptr [0x4d4c50], eax
    app->getMemory<x86::reg32>(x86::reg32(5065808) /* 0x4d4c50 */) = cpu.eax;
    // 00422450  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422452  0f8476ffffff           -je 0x4223ce
    if (cpu.flags.zf)
    {
        goto L_0x004223ce;
    }
    // 00422458  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422459  8b15484c4d00           -mov edx, dword ptr [0x4d4c48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 0042245f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422460  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00422462  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422465  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422467  7536                   -jne 0x42249f
    if (!cpu.flags.zf)
    {
        goto L_0x0042249f;
    }
    // 00422469  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 0042246e  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 00422473  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00422478  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0042247a  a1484c4d00             -mov eax, dword ptr [0x4d4c48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065800) /* 0x4d4c48 */);
    // 0042247f  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00422483  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00422487  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0042248a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042248b  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0042248f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00422493  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00422495  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422497  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422498  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042249b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042249d  740b                   -je 0x4224aa
    if (cpu.flags.zf)
    {
        goto L_0x004224aa;
    }
L_0x0042249f:
    // 0042249f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004224a1  83c414                 +add esp, 0x14
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
    // 004224a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004224aa:
    // 004224aa  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004224ac  e8affe0500             -call 0x482360
    cpu.esp -= 4;
    sub_482360(app, cpu);
    if (cpu.terminate) return;
    // 004224b1  68d0244200             -push 0x4224d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4334800 /*0x4224d0*/;
    cpu.esp -= 4;
    // 004224b6  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004224b8  a3544c4d00             -mov dword ptr [0x4d4c54], eax
    app->getMemory<x86::reg32>(x86::reg32(5065812) /* 0x4d4c54 */) = cpu.eax;
    // 004224bd  e8aefd0500             -call 0x482270
    cpu.esp -= 4;
    sub_482270(app, cpu);
    if (cpu.terminate) return;
    // 004224c2  e9d4feffff             -jmp 0x42239b
    goto L_0x0042239b;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4224d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004224d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004224d1  833d544c4d0000         +cmp dword ptr [0x4d4c54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065812) /* 0x4d4c54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004224d8  751b                   -jne 0x4224f5
    if (!cpu.flags.zf)
    {
        goto L_0x004224f5;
    }
L_0x004224da:
    // 004224da  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004224dc  2eff1520644c00         -call dword ptr cs:[0x4c6420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006368) /* 0x4c6420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004224e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004224e5  2eff1534644c00         -call dword ptr cs:[0x4c6434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006388) /* 0x4c6434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004224ec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004224f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004224f2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004224f5:
    // 004224f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004224f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004224f7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004224f8  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004224fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004224fd  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00422501  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422502  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00422506  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422507  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042250b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042250c  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00422510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422511  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00422515  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422516  ff15544c4d00           -call dword ptr [0x4d4c54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5065812) /* 0x4d4c54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042251c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042251d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042251e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042251f  ebb9                   -jmp 0x4224da
    goto L_0x004224da;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00422530, cpu);
    // 00422530  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422531  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422532  8b15444c4d00           -mov edx, dword ptr [0x4d4c44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */);
    // 00422538  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042253a  7568                   -jne 0x4225a4
    if (!cpu.flags.zf)
    {
        goto L_0x004225a4;
    }
    // 0042253c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0042253e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00422540:
    // 00422540  83c05c                 -add eax, 0x5c
    (cpu.eax) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 00422543  89882c734e00           -mov dword ptr [eax + 0x4e732c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141292) /* 0x4e732c */) = cpu.ecx;
    // 00422549  898830734e00           -mov dword ptr [eax + 0x4e7330], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5141296) /* 0x4e7330 */) = cpu.ecx;
    // 0042254f  888834734e00           -mov byte ptr [eax + 0x4e7334], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5141300) /* 0x4e7334 */) = cpu.cl;
    // 00422555  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00422558  888835734e00           -mov byte ptr [eax + 0x4e7335], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5141301) /* 0x4e7335 */) = cpu.cl;
    // 0042255e  898a44734e00           -mov dword ptr [edx + 0x4e7344], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141316) /* 0x4e7344 */) = cpu.ecx;
    // 00422564  83fa40                 +cmp edx, 0x40
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
    // 00422567  75d7                   -jne 0x422540
    if (!cpu.flags.zf)
    {
        goto L_0x00422540;
    }
    // 00422569  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0042256b:
    // 0042256b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042256e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00422570  8988bc884e00           -mov dword ptr [eax + 0x4e88bc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5146812) /* 0x4e88bc */) = cpu.ecx;
    // 00422576  83f878                 +cmp eax, 0x78
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
    // 00422579  75f0                   -jne 0x42256b
    if (!cpu.flags.zf)
    {
        goto L_0x0042256b;
    }
    // 0042257b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042257c  68444c4d00             -push 0x4d4c44
    app->getMemory<x86::reg32>(cpu.esp-4) = 5065796 /*0x4d4c44*/;
    cpu.esp -= 4;
    // 00422581  6800050000             -push 0x500
    app->getMemory<x86::reg32>(cpu.esp-4) = 1280 /*0x500*/;
    cpu.esp -= 4;
    // 00422586  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422587  890d584c4d00           -mov dword ptr [0x4d4c58], ecx
    app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */) = cpu.ecx;
    // 0042258d  890d5c4c4d00           -mov dword ptr [0x4d4c5c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */) = cpu.ecx;
    // 00422593  2eff1508654c00         -call dword ptr cs:[0x4c6508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006600) /* 0x4c6508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042259a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042259b  e8ae2c0a00             -call 0x4c524e
    cpu.esp -= 4;
    sub_4c524e(app, cpu);
    if (cpu.terminate) return;
    // 004225a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004225a2  7503                   -jne 0x4225a7
    if (!cpu.flags.zf)
    {
        goto L_0x004225a7;
    }
L_0x004225a4:
    // 004225a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004225a7:
    // 004225a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004225a8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004225aa  893d444c4d00           -mov dword ptr [0x4d4c44], edi
    app->getMemory<x86::reg32>(x86::reg32(5065796) /* 0x4d4c44 */) = cpu.edi;
    // 004225b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004225b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4225c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004225c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004225c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004225c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004225c3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004225c6  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004225ca  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004225ce  6689442408             -mov word ptr [esp + 8], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004225d3  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004225d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004225d9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004225db  7455                   -je 0x422632
    if (cpu.flags.zf)
    {
        goto L_0x00422632;
    }
    // 004225dd  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004225df  81ff68010000           +cmp edi, 0x168
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(360 /*0x168*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004225e5  0f8e02020000           -jle 0x4227ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004227ed;
    }
    // 004225eb  c70368010000           -mov dword ptr [ebx], 0x168
    app->getMemory<x86::reg32>(cpu.ebx) = 360 /*0x168*/;
L_0x004225f1:
    // 004225f1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004225f3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004225f6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004225f9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004225fc  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004225fe  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422601  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00422603  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422606  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00422608  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0042260c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0042260f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00422612  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00422615  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422618  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0042261a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042261d  8bb8c0794e00           -mov edi, dword ptr [eax + 0x4e79c0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142976) /* 0x4e79c0 */);
    // 00422623  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422625  740b                   -je 0x422632
    if (cpu.flags.zf)
    {
        goto L_0x00422632;
    }
    // 00422627  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00422629  80ca40                 -or dl, 0x40
    cpu.dl |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0042262c  8998c0794e00           -mov dword ptr [eax + 0x4e79c0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142976) /* 0x4e79c0 */) = cpu.ebx;
L_0x00422632:
    // 00422632  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00422634  7437                   -je 0x42266d
    if (cpu.flags.zf)
    {
        goto L_0x0042266d;
    }
    // 00422636  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00422638  3dffffff00             +cmp eax, 0xffffff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042263d  0f85b9010000           -jne 0x4227fc
    if (!cpu.flags.zf)
    {
        goto L_0x004227fc;
    }
    // 00422643  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x00422649:
    // 00422649  8b5c2406               -mov ebx, dword ptr [esp + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0042264d  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00422650  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00422652  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422655  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00422657  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0042265a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042265c  3bb850794e00           +cmp edi, dword ptr [eax + 0x4e7950]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142864) /* 0x4e7950 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422662  7409                   -je 0x42266d
    if (cpu.flags.zf)
    {
        goto L_0x0042266d;
    }
    // 00422664  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00422667  89b850794e00           -mov dword ptr [eax + 0x4e7950], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142864) /* 0x4e7950 */) = cpu.edi;
L_0x0042266d:
    // 0042266d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042266f  7432                   -je 0x4226a3
    if (cpu.flags.zf)
    {
        goto L_0x004226a3;
    }
    // 00422671  813e10270000           +cmp dword ptr [esi], 0x2710
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422677  7606                   -jbe 0x42267f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0042267f;
    }
    // 00422679  c70610270000           -mov dword ptr [esi], 0x2710
    app->getMemory<x86::reg32>(cpu.esi) = 10000 /*0x2710*/;
L_0x0042267f:
    // 0042267f  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422683  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422686  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422688  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0042268b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042268d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422690  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00422692  3b9858794e00           +cmp ebx, dword ptr [eax + 0x4e7958]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142872) /* 0x4e7958 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422698  7409                   -je 0x4226a3
    if (cpu.flags.zf)
    {
        goto L_0x004226a3;
    }
    // 0042269a  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0042269d  899858794e00           -mov dword ptr [eax + 0x4e7958], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142872) /* 0x4e7958 */) = cpu.ebx;
L_0x004226a3:
    // 004226a3  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004226a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004226a9  745b                   -je 0x422706
    if (cpu.flags.zf)
    {
        goto L_0x00422706;
    }
    // 004226ab  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004226af  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004226b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004226b4  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004226b7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004226b9  bb48794e00             -mov ebx, 0x4e7948
    cpu.ebx = 5142856 /*0x4e7948*/;
    // 004226be  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004226c1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004226c3  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004226c5  83c334                 -add ebx, 0x34
    (cpu.ebx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004226c8  8b8874794e00           -mov ecx, dword ptr [eax + 0x4e7974]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142900) /* 0x4e7974 */);
    // 004226ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004226d0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004226d4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004226d6  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004226d8  7405                   -je 0x4226df
    if (cpu.flags.zf)
    {
        goto L_0x004226df;
    }
    // 004226da  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004226dc  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004226df:
    // 004226df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004226e1  7423                   -je 0x422706
    if (cpu.flags.zf)
    {
        goto L_0x00422706;
    }
    // 004226e3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004226e7  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004226eb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004226ed  8b8974794e00           -mov ecx, dword ptr [ecx + 0x4e7974]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142900) /* 0x4e7974 */);
    // 004226f3  80ce01                 -or dh, 1
    cpu.dh |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004226f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004226f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004226f9  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004226fc  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004226fe  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00422700  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00422703  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00422705  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00422706:
    // 00422706  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042270a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042270c  742d                   -je 0x42273b
    if (cpu.flags.zf)
    {
        goto L_0x0042273b;
    }
    // 0042270e  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00422710  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422713  7d26                   -jge 0x42273b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042273b;
    }
    // 00422715  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422718  83f8ff                 +cmp eax, -1
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
    // 0042271b  0f8509010000           -jne 0x42282a
    if (!cpu.flags.zf)
    {
        goto L_0x0042282a;
    }
    // 00422721  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00422723:
    // 00422723  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422727  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0042272a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0042272c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0042272f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422731  80ca08                 -or dl, 8
    cpu.dl |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00422734  891c855c794e00         -mov dword ptr [eax*4 + 0x4e795c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5142876) /* 0x4e795c */ + cpu.eax * 4) = cpu.ebx;
L_0x0042273b:
    // 0042273b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0042273d  7459                   -je 0x422798
    if (cpu.flags.zf)
    {
        goto L_0x00422798;
    }
    // 0042273f  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422743  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422746  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422748  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0042274b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042274d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422750  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00422753  3b98b0794e00           +cmp ebx, dword ptr [eax + 0x4e79b0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142960) /* 0x4e79b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422759  0f84da000000           -je 0x422839
    if (cpu.flags.zf)
    {
        goto L_0x00422839;
    }
L_0x0042275f:
    // 0042275f  8b4c2406               -mov ecx, dword ptr [esp + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00422763  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00422766  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422768  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0042276b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0042276d  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00422770  890c85b0794e00         -mov dword ptr [eax*4 + 0x4e79b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142960) /* 0x4e79b0 */ + cpu.eax * 4) = cpu.ecx;
    // 00422777  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0042277a  890c85b4794e00         -mov dword ptr [eax*4 + 0x4e79b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142964) /* 0x4e79b4 */ + cpu.eax * 4) = cpu.ecx;
    // 00422781  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00422784  890c85b8794e00         -mov dword ptr [eax*4 + 0x4e79b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142968) /* 0x4e79b8 */ + cpu.eax * 4) = cpu.ecx;
    // 0042278b  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042278e  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00422791  890c85bc794e00         -mov dword ptr [eax*4 + 0x4e79bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142972) /* 0x4e79bc */ + cpu.eax * 4) = cpu.ecx;
L_0x00422798:
    // 00422798  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042279a  0f85cb000000           -jne 0x42286b
    if (!cpu.flags.zf)
    {
        goto L_0x0042286b;
    }
    // 004227a0  807c240c01             +cmp byte ptr [esp + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004227a5  7520                   -jne 0x4227c7
    if (!cpu.flags.zf)
    {
        goto L_0x004227c7;
    }
    // 004227a7  8b542406               -mov edx, dword ptr [esp + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004227ab  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004227ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004227b0  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004227b3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004227b5  8b0485c8794e00         -mov eax, dword ptr [eax*4 + 0x4e79c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5142984) /* 0x4e79c8 */ + cpu.eax * 4);
    // 004227bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004227be  7507                   -jne 0x4227c7
    if (!cpu.flags.zf)
    {
        goto L_0x004227c7;
    }
    // 004227c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004227c2  e8e9010000             -call 0x4229b0
    cpu.esp -= 4;
    sub_4229b0(app, cpu);
    if (cpu.terminate) return;
L_0x004227c7:
    // 004227c7  807c240c03             +cmp byte ptr [esp + 0xc], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004227cc  7514                   -jne 0x4227e2
    if (!cpu.flags.zf)
    {
        goto L_0x004227e2;
    }
    // 004227ce  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004227d2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004227d5  8b0485c0884e00         -mov eax, dword ptr [eax*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.eax * 4);
    // 004227dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004227dd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004227df  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004227e2:
    // 004227e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004227e4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004227e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004227e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004227e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004227ea  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004227ed:
    // 004227ed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004227ef  0f8dfcfdffff           -jge 0x4225f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004225f1;
    }
    // 004227f5  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004227f7  e9f5fdffff             -jmp 0x4225f1
    goto L_0x004225f1;
L_0x004227fc:
    // 004227fc  3ddc050000             +cmp eax, 0x5dc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1500 /*0x5dc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422801  7606                   -jbe 0x422809
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00422809;
    }
    // 00422803  c701dc050000           -mov dword ptr [ecx], 0x5dc
    app->getMemory<x86::reg32>(cpu.ecx) = 1500 /*0x5dc*/;
L_0x00422809:
    // 00422809  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042280b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00422812  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422814  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422817  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00422819  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042281c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0042281e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422821  01d8                   +add eax, ebx
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
    // 00422823  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00422825  e91ffeffff             -jmp 0x422649
    goto L_0x00422649;
L_0x0042282a:
    // 0042282a  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0042282e  0fbe1b                 -movsx ebx, byte ptr [ebx]
    cpu.ebx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx)));
    // 00422831  83c330                 +add ebx, 0x30
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422834  e9eafeffff             -jmp 0x422723
    goto L_0x00422723;
L_0x00422839:
    // 00422839  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0042283c  3bb0b4794e00           +cmp esi, dword ptr [eax + 0x4e79b4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142964) /* 0x4e79b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422842  0f8517ffffff           -jne 0x42275f
    if (!cpu.flags.zf)
    {
        goto L_0x0042275f;
    }
    // 00422848  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0042284b  3bb8b8794e00           +cmp edi, dword ptr [eax + 0x4e79b8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142968) /* 0x4e79b8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422851  0f8508ffffff           -jne 0x42275f
    if (!cpu.flags.zf)
    {
        goto L_0x0042275f;
    }
    // 00422857  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0042285a  3b88bc794e00           +cmp ecx, dword ptr [eax + 0x4e79bc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142972) /* 0x4e79bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422860  0f85f9feffff           -jne 0x42275f
    if (!cpu.flags.zf)
    {
        goto L_0x0042275f;
    }
    // 00422866  e92dffffff             -jmp 0x422798
    goto L_0x00422798;
L_0x0042286b:
    // 0042286b  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0042286f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00422872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422873  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00422875  8b0c85c0884e00         -mov ecx, dword ptr [eax*4 + 0x4e88c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.eax * 4);
    // 0042287c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0042287f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00422881  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422884  0548794e00             -add eax, 0x4e7948
    (cpu.eax) += x86::reg32(x86::sreg32(5142856 /*0x4e7948*/));
    // 00422889  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042288a  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0042288c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042288d  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422890  8a7c240c               -mov bh, byte ptr [esp + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00422894  80ff01                 +cmp bh, 1
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422897  752e                   -jne 0x4228c7
    if (!cpu.flags.zf)
    {
        goto L_0x004228c7;
    }
L_0x00422899:
    // 00422899  8b542406               -mov edx, dword ptr [esp + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 0042289d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004228a0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004228a2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004228a5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004228a7  8b0485c8794e00         -mov eax, dword ptr [eax*4 + 0x4e79c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5142984) /* 0x4e79c8 */ + cpu.eax * 4);
    // 004228ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004228b0  751c                   -jne 0x4228ce
    if (!cpu.flags.zf)
    {
        goto L_0x004228ce;
    }
    // 004228b2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004228b4  e8f7000000             -call 0x4229b0
    cpu.esp -= 4;
    sub_4229b0(app, cpu);
    if (cpu.terminate) return;
L_0x004228b9:
    // 004228b9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004228be  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004228c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228c4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004228c7:
    // 004228c7  80ff02                 +cmp bh, 2
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004228ca  74cd                   -je 0x422899
    if (cpu.flags.zf)
    {
        goto L_0x00422899;
    }
    // 004228cc  ebeb                   -jmp 0x4228b9
    goto L_0x004228b9;
L_0x004228ce:
    // 004228ce  807c240c03             +cmp byte ptr [esp + 0xc], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004228d3  75e4                   -jne 0x4228b9
    if (!cpu.flags.zf)
    {
        goto L_0x004228b9;
    }
    // 004228d5  8b0495c0884e00         -mov eax, dword ptr [edx*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.edx * 4);
    // 004228dc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004228dd  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004228df  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004228e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004228e7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004228ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004228ed  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4228f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004228f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004228f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004228f2  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004228f3  8b0485c0884e00         -mov eax, dword ptr [eax*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.eax * 4);
    // 004228fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004228fb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004228fd  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422900  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422901  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422902  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422910  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422911  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422912  3c10                   +cmp al, 0x10
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
    // 00422914  7513                   -jne 0x422929
    if (!cpu.flags.zf)
    {
        goto L_0x00422929;
    }
    // 00422916  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00422918:
    // 00422918  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 0042291b  42                     -inc edx
    (cpu.edx)++;
    // 0042291c  e8efffffff             -call 0x422910
    cpu.esp -= 4;
    sub_422910(app, cpu);
    if (cpu.terminate) return;
    // 00422921  83fa10                 +cmp edx, 0x10
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
    // 00422924  7cf2                   -jl 0x422918
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422918;
    }
    // 00422926  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422927  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422928  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422929:
    // 00422929  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0042292a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0042292b  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042292e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00422931  83ba48734e0000         +cmp dword ptr [edx + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422938  751d                   -jne 0x422957
    if (!cpu.flags.zf)
    {
        goto L_0x00422957;
    }
L_0x0042293a:
    // 0042293a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0042293c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042293d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042293e:
    // 0042293e  81c284000000           -add edx, 0x84
    (cpu.edx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00422944  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00422946  89b244794e00           -mov dword ptr [edx + 0x4e7944], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5142852) /* 0x4e7944 */) = cpu.esi;
    // 0042294c  81fa780f0000           +cmp edx, 0xf78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3960 /*0xf78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422952  75ea                   -jne 0x42293e
    if (!cpu.flags.zf)
    {
        goto L_0x0042293e;
    }
    // 00422954  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422955  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422956  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422957:
    // 00422957  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0042295a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042295f  8b1d584c4d00           -mov ebx, dword ptr [0x4d4c58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422965  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422967  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 00422969  74cf                   -je 0x42293a
    if (cpu.flags.zf)
    {
        goto L_0x0042293a;
    }
    // 0042296b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0042296d  8b8248734e00           -mov eax, dword ptr [edx + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
    // 00422973  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422974  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422976  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422979  ebbf                   -jmp 0x42293a
    goto L_0x0042293a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422982  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422983  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00422986  8b049dc0884e00         -mov eax, dword ptr [ebx*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.ebx * 4);
    // 0042298d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0042298e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422990  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422993  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00422995  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422998  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0042299a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042299c  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0042299e  891485c8794e00         -mov dword ptr [eax*4 + 0x4e79c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5142984) /* 0x4e79c8 */ + cpu.eax * 4) = cpu.edx;
    // 004229a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4229b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004229b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004229b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004229b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004229b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004229b5  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004229b8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004229ba  8b049dc0884e00         -mov eax, dword ptr [ebx*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.ebx * 4);
    // 004229c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004229c2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004229c4  ff521c                 -call dword ptr [edx + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004229c7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004229c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004229cb  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004229ce  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004229d0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004229d3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004229d5  750e                   -jne 0x4229e5
    if (!cpu.flags.zf)
    {
        goto L_0x004229e5;
    }
    // 004229d7  c780c8794e0001000000   -mov dword ptr [eax + 0x4e79c8], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142984) /* 0x4e79c8 */) = 1 /*0x1*/;
    // 004229e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004229e5:
    // 004229e5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004229e7  8990c8794e00           -mov dword ptr [eax + 0x4e79c8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142984) /* 0x4e79c8 */) = cpu.edx;
    // 004229ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004229f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422a34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00422a34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422a35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422a36  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422a37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422a38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422a39  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00422a3b  833d604c4d001e         +cmp dword ptr [0x4d4c60], 0x1e
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422a42  0f8dd5010000           -jge 0x422c1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00422c1d;
    }
    // 00422a48  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422a4b  833c8548734e0000       +cmp dword ptr [eax*4 + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141320) /* 0x4e7348 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422a53  0f84c4010000           -je 0x422c1d
    if (cpu.flags.zf)
    {
        goto L_0x00422c1d;
    }
    // 00422a59  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422a5e  0fbecb                 -movsx ecx, bl
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422a61  8b3d584c4d00           -mov edi, dword ptr [0x4d4c58]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422a67  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422a69  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 00422a6b  0f84ac010000           -je 0x422c1d
    if (cpu.flags.zf)
    {
        goto L_0x00422c1d;
    }
    // 00422a71  8b6a34                 -mov ebp, dword ptr [edx + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 00422a74  81fdffffff00           +cmp ebp, 0xffffff
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422a7a  0f85a8010000           -jne 0x422c28
    if (!cpu.flags.zf)
    {
        goto L_0x00422c28;
    }
    // 00422a80  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00422a85:
    // 00422a85  8b35604c4d00           -mov esi, dword ptr [0x4d4c60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422a8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00422a8d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422a90  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00422a92  890c8550794e00         -mov dword ptr [eax*4 + 0x4e7950], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142864) /* 0x4e7950 */ + cpu.eax * 4) = cpu.ecx;
    // 00422a99  8b4a38                 -mov ecx, dword ptr [edx + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 00422a9c  890c8558794e00         -mov dword ptr [eax*4 + 0x4e7958], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142872) /* 0x4e7958 */ + cpu.eax * 4) = cpu.ecx;
    // 00422aa3  8b423a                 -mov eax, dword ptr [edx + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 00422aa6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00422aa9  83f8ff                 +cmp eax, -1
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
    // 00422aac  0f8593010000           -jne 0x422c45
    if (!cpu.flags.zf)
    {
        goto L_0x00422c45;
    }
    // 00422ab2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00422ab4:
    // 00422ab4  a1604c4d00             -mov eax, dword ptr [0x4d4c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422ab9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00422abb  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00422abe  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00422ac0  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00422ac3  89b15c794e00           -mov dword ptr [ecx + 0x4e795c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142876) /* 0x4e795c */) = cpu.esi;
    // 00422ac9  8b4240                 -mov eax, dword ptr [edx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 00422acc  898160794e00           -mov dword ptr [ecx + 0x4e7960], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142880) /* 0x4e7960 */) = cpu.eax;
    // 00422ad2  8b7244                 -mov esi, dword ptr [edx + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 00422ad5  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00422adc  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00422ade  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422ae1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00422ae3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422ae6  8981c0794e00           -mov dword ptr [ecx + 0x4e79c0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142976) /* 0x4e79c0 */) = cpu.eax;
    // 00422aec  807a3c00               +cmp byte ptr [edx + 0x3c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(60) /* 0x3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422af0  0f855d010000           -jne 0x422c53
    if (!cpu.flags.zf)
    {
        goto L_0x00422c53;
    }
L_0x00422af6:
    // 00422af6  8b0d604c4d00           -mov ecx, dword ptr [0x4d4c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422afc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422afe  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422b01  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00422b06  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422b08  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00422b0a  b940734e00             -mov ecx, 0x4e7340
    cpu.ecx = 5141312 /*0x4e7340*/;
    // 00422b0f  892c8564794e00         -mov dword ptr [eax*4 + 0x4e7964], ebp
    app->getMemory<x86::reg32>(x86::reg32(5142884) /* 0x4e7964 */ + cpu.eax * 4) = cpu.ebp;
    // 00422b16  893540734e00           -mov dword ptr [0x4e7340], esi
    app->getMemory<x86::reg32>(x86::reg32(5141312) /* 0x4e7340 */) = cpu.esi;
    // 00422b1c  890c8568794e00         -mov dword ptr [eax*4 + 0x4e7968], ecx
    app->getMemory<x86::reg32>(x86::reg32(5142888) /* 0x4e7968 */ + cpu.eax * 4) = cpu.ecx;
L_0x00422b23:
    // 00422b23  8b0d604c4d00           -mov ecx, dword ptr [0x4d4c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422b29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422b2b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422b2e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422b30  bf48794e00             -mov edi, 0x4e7948
    cpu.edi = 5142856 /*0x4e7948*/;
    // 00422b35  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422b38  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00422b3b  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00422b3d  b930000000             -mov ecx, 0x30
    cpu.ecx = 48 /*0x30*/;
    // 00422b42  83c734                 -add edi, 0x34
    (cpu.edi) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00422b45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422b46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422b48  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00422b4b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00422b4d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00422b4f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00422b52  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00422b54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422b55  8b0d604c4d00           -mov ecx, dword ptr [0x4d4c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422b5b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422b5d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422b60  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422b62  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422b65  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00422b67  bd22000000             -mov ebp, 0x22
    cpu.ebp = 34 /*0x22*/;
    // 00422b6c  898854794e00           -mov dword ptr [eax + 0x4e7954], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142868) /* 0x4e7954 */) = cpu.ecx;
    // 00422b72  b948794e00             -mov ecx, 0x4e7948
    cpu.ecx = 5142856 /*0x4e7948*/;
    // 00422b77  bf34000000             -mov edi, 0x34
    cpu.edi = 52 /*0x34*/;
    // 00422b7c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00422b7e  89b848794e00           -mov dword ptr [eax + 0x4e7948], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142856) /* 0x4e7948 */) = cpu.edi;
    // 00422b84  8d3439                 -lea esi, [ecx + edi]
    cpu.esi = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 00422b87  89a84c794e00           -mov dword ptr [eax + 0x4e794c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142860) /* 0x4e794c */) = cpu.ebp;
    // 00422b8d  83c178                 -add ecx, 0x78
    (cpu.ecx) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00422b90  89b078794e00           -mov dword ptr [eax + 0x4e7978], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142904) /* 0x4e7978 */) = cpu.esi;
    // 00422b96  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00422b98  89886c794e00           -mov dword ptr [eax + 0x4e796c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142892) /* 0x4e796c */) = cpu.ecx;
    // 00422b9e  89b8c4794e00           -mov dword ptr [eax + 0x4e79c4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142980) /* 0x4e79c4 */) = cpu.edi;
    // 00422ba4  89b870794e00           -mov dword ptr [eax + 0x4e7970], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142896) /* 0x4e7970 */) = cpu.edi;
    // 00422baa  89b078794e00           -mov dword ptr [eax + 0x4e7978], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142904) /* 0x4e7978 */) = cpu.esi;
    // 00422bb0  89b8c8794e00           -mov dword ptr [eax + 0x4e79c8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142984) /* 0x4e79c8 */) = cpu.edi;
    // 00422bb6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00422bb8  80f90c                 +cmp cl, 0xc
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(12 /*0xc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422bbb  7760                   -ja 0x422c1d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00422c1d;
    }
    // 00422bbd  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00422bc3  ff248d002a4200         -jmp dword ptr [ecx*4 + 0x422a00]
    cpu.ip = app->getMemory<x86::reg32>(4336128 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00422bca:
    // 00422bca  c78074794e0004000000   -mov dword ptr [eax + 0x4e7974], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142900) /* 0x4e7974 */) = 4 /*0x4*/;
L_0x00422bd4:
    // 00422bd4  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422bd7  8b348548734e00         -mov esi, dword ptr [eax*4 + 0x4e7348]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5141320) /* 0x4e7348 */ + cpu.eax * 4);
    // 00422bde  a1604c4d00             -mov eax, dword ptr [0x4d4c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422be3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422be6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00422be8  05c0884e00             -add eax, 0x4e88c0
    (cpu.eax) += x86::reg32(x86::sreg32(5146816 /*0x4e88c0*/));
    // 00422bed  8b0d604c4d00           -mov ecx, dword ptr [0x4d4c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422bf3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422bf4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422bf6  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422bf9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00422bfb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422bfe  0548794e00             -add eax, 0x4e7948
    (cpu.eax) += x86::reg32(x86::sreg32(5142856 /*0x4e7948*/));
    // 00422c03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422c04  0fbe02                 -movsx eax, byte ptr [edx]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx)));
    // 00422c07  8b2c8560154200         -mov ebp, dword ptr [eax*4 + 0x421560]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(4330848) /* 0x421560 */ + cpu.eax * 4);
    // 00422c0e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422c0f  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00422c11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422c12  ff5748                 -call dword ptr [edi + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422c15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00422c17  0f8416010000           -je 0x422d33
    if (cpu.flags.zf)
    {
        goto L_0x00422d33;
    }
L_0x00422c1d:
    // 00422c1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00422c22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422c27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422c28:
    // 00422c28  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00422c2f  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00422c31  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422c34  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00422c36  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422c39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00422c3b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00422c3e  01c1                   +add ecx, eax
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
    // 00422c40  e940feffff             -jmp 0x422a85
    goto L_0x00422a85;
L_0x00422c45:
    // 00422c45  8b723a                 -mov esi, dword ptr [edx + 0x3a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 00422c48  c1fe18                 -sar esi, 0x18
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (24 /*0x18*/ % 32));
    // 00422c4b  83c630                 +add esi, 0x30
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00422c4e  e961feffff             -jmp 0x422ab4
    goto L_0x00422ab4;
L_0x00422c53:
    // 00422c53  0fbef3                 -movsx esi, bl
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422c56  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00422c5d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00422c5f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422c62  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00422c64  f6048590734e0002       +test byte ptr [eax*4 + 0x4e7390], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5141392) /* 0x4e7390 */ + cpu.eax * 4) & 2 /*0x2*/));
    // 00422c6c  0f8584feffff           -jne 0x422af6
    if (!cpu.flags.zf)
    {
        goto L_0x00422af6;
    }
    // 00422c72  807a3c01               +cmp byte ptr [edx + 0x3c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(60) /* 0x3c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00422c76  7526                   -jne 0x422c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00422c9e;
    }
    // 00422c78  be40734e00             -mov esi, 0x4e7340
    cpu.esi = 5141312 /*0x4e7340*/;
    // 00422c7d  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 00422c82  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422c87  89b168794e00           -mov dword ptr [ecx + 0x4e7968], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142888) /* 0x4e7968 */) = cpu.esi;
    // 00422c8d  893d40734e00           -mov dword ptr [0x4e7340], edi
    app->getMemory<x86::reg32>(x86::reg32(5141312) /* 0x4e7340 */) = cpu.edi;
    // 00422c93  898164794e00           -mov dword ptr [ecx + 0x4e7964], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142884) /* 0x4e7964 */) = cpu.eax;
    // 00422c99  e985feffff             -jmp 0x422b23
    goto L_0x00422b23;
L_0x00422c9e:
    // 00422c9e  be40734e00             -mov esi, 0x4e7340
    cpu.esi = 5141312 /*0x4e7340*/;
    // 00422ca3  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 00422ca8  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00422caa  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00422caf  893d40734e00           -mov dword ptr [0x4e7340], edi
    app->getMemory<x86::reg32>(x86::reg32(5141312) /* 0x4e7340 */) = cpu.edi;
    // 00422cb5  89b168794e00           -mov dword ptr [ecx + 0x4e7968], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142888) /* 0x4e7968 */) = cpu.esi;
    // 00422cbb  892d44734e00           -mov dword ptr [0x4e7344], ebp
    app->getMemory<x86::reg32>(x86::reg32(5141316) /* 0x4e7344 */) = cpu.ebp;
    // 00422cc1  898164794e00           -mov dword ptr [ecx + 0x4e7964], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5142884) /* 0x4e7964 */) = cpu.eax;
    // 00422cc7  e957feffff             -jmp 0x422b23
    goto L_0x00422b23;
  case 0x00422ccc:
    // 00422ccc  c78074794e0008000000   -mov dword ptr [eax + 0x4e7974], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142900) /* 0x4e7974 */) = 8 /*0x8*/;
    // 00422cd6  e9f9feffff             -jmp 0x422bd4
    goto L_0x00422bd4;
  case 0x00422cdb:
    // 00422cdb  c78074794e0010000000   -mov dword ptr [eax + 0x4e7974], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142900) /* 0x4e7974 */) = 16 /*0x10*/;
    // 00422ce5  e9eafeffff             -jmp 0x422bd4
    goto L_0x00422bd4;
  case 0x00422cea:
    // 00422cea  8b0d604c4d00           -mov ecx, dword ptr [0x4d4c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422cf0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422cf2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422cf5  01c8                   +add eax, ecx
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
    // 00422cf7  c7048574794e0010000000 -mov dword ptr [eax*4 + 0x4e7974], 0x10
    app->getMemory<x86::reg32>(x86::reg32(5142900) /* 0x4e7974 */ + cpu.eax * 4) = 16 /*0x10*/;
    // 00422d02  e9cdfeffff             -jmp 0x422bd4
    goto L_0x00422bd4;
  case 0x00422d07:
    // 00422d07  8b0d604c4d00           -mov ecx, dword ptr [0x4d4c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422d0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00422d0f  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00422d12  01c8                   +add eax, ecx
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
    // 00422d14  c7048574794e0018000000 -mov dword ptr [eax*4 + 0x4e7974], 0x18
    app->getMemory<x86::reg32>(x86::reg32(5142900) /* 0x4e7974 */ + cpu.eax * 4) = 24 /*0x18*/;
    // 00422d1f  e9b0feffff             -jmp 0x422bd4
    goto L_0x00422bd4;
  case 0x00422d24:
    // 00422d24  c78074794e0030000000   -mov dword ptr [eax + 0x4e7974], 0x30
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5142900) /* 0x4e7974 */) = 48 /*0x30*/;
    // 00422d2e  e9a1feffff             -jmp 0x422bd4
    goto L_0x00422bd4;
L_0x00422d33:
    // 00422d33  66a1604c4d00           -mov ax, word ptr [0x4d4c60]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422d39  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00422d3a  8b0485c0884e00         -mov eax, dword ptr [eax*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.eax * 4);
    // 00422d41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422d42  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422d44  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422d47  a1604c4d00             -mov eax, dword ptr [0x4d4c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422d4c  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00422d4f  8915604c4d00           -mov dword ptr [0x4d4c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */) = cpu.edx;
    // 00422d55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d5a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422d60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422d61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422d62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422d63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00422d64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00422d65  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00422d68  88442414               -mov byte ptr [esp + 0x14], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.al;
    // 00422d6c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00422d6e  3c10                   +cmp al, 0x10
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
    // 00422d70  751b                   -jne 0x422d8d
    if (!cpu.flags.zf)
    {
        goto L_0x00422d8d;
    }
    // 00422d72  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00422d74:
    // 00422d74  0fbec3                 -movsx eax, bl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.bl));
    // 00422d77  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00422d79  43                     -inc ebx
    (cpu.ebx)++;
    // 00422d7a  e8e1ffffff             -call 0x422d60
    cpu.esp -= 4;
    sub_422d60(app, cpu);
    if (cpu.terminate) return;
    // 00422d7f  83fb10                 +cmp ebx, 0x10
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
    // 00422d82  7cf0                   -jl 0x422d74
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422d74;
    }
L_0x00422d84:
    // 00422d84  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00422d87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d8b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422d8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422d8d:
    // 00422d8d  8b4c2411               -mov ecx, dword ptr [esp + 0x11]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00422d91  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422d96  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00422d99  8b15584c4d00           -mov edx, dword ptr [0x4d4c58]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422d9f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422da1  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00422da3  0f849e000000           -je 0x422e47
    if (cpu.flags.zf)
    {
        goto L_0x00422e47;
    }
L_0x00422da9:
    // 00422da9  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 00422dae  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00422db3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00422db5  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00422db9  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00422dbd  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00422dc1  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00422dc4  83fe64                 +cmp esi, 0x64
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422dc7  0f8e98000000           -jle 0x422e65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00422e65;
    }
    // 00422dcd  c744241010270000       -mov dword ptr [esp + 0x10], 0x2710
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 10000 /*0x2710*/;
L_0x00422dd5:
    // 00422dd5  8b35604c4d00           -mov esi, dword ptr [0x4d4c60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422ddb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422ddd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422ddf  7e1b                   -jle 0x422dfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00422dfc;
    }
L_0x00422de1:
    // 00422de1  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00422de4  8b0485c0884e00         -mov eax, dword ptr [eax*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.eax * 4);
    // 00422deb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422dec  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00422dee  43                     -inc ebx
    (cpu.ebx)++;
    // 00422def  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422df2  3b1d604c4d00           +cmp ebx, dword ptr [0x4d4c60]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422df8  7ce7                   -jl 0x422de1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422de1;
    }
    // 00422dfa  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00422dfc:
    // 00422dfc  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00422dfe  8b442411               -mov eax, dword ptr [esp + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00422e02  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422e03  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00422e06  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00422e08  8b048548734e00         -mov eax, dword ptr [eax*4 + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5141320) /* 0x4e7348 */ + cpu.eax * 4);
    // 00422e0f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422e10  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422e12  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422e15  8b2d604c4d00           -mov ebp, dword ptr [0x4d4c60]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */);
    // 00422e1b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00422e1d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00422e1f  0f8e5fffffff           -jle 0x422d84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00422d84;
    }
L_0x00422e25:
    // 00422e25  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00422e28  8b0485c0884e00         -mov eax, dword ptr [eax*4 + 0x4e88c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146816) /* 0x4e88c0 */ + cpu.eax * 4);
    // 00422e2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422e30  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00422e32  43                     -inc ebx
    (cpu.ebx)++;
    // 00422e33  ff5628                 -call dword ptr [esi + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422e36  3b1d604c4d00           +cmp ebx, dword ptr [0x4d4c60]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5065824) /* 0x4d4c60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422e3c  7ce7                   -jl 0x422e25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422e25;
    }
    // 00422e3e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00422e41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422e47:
    // 00422e47  8b442411               -mov eax, dword ptr [esp + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(17) /* 0x11 */);
    // 00422e4b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00422e4e  833c8548734e0000       +cmp dword ptr [eax*4 + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5141320) /* 0x4e7348 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422e56  0f854dffffff           -jne 0x422da9
    if (!cpu.flags.zf)
    {
        goto L_0x00422da9;
    }
    // 00422e5c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00422e5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422e64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422e65:
    // 00422e65  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00422e67  7c1a                   -jl 0x422e83
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422e83;
    }
    // 00422e69  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00422e70  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00422e72  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00422e75  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00422e77  c1e002                 +shl eax, 2
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
    // 00422e7a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00422e7e  e952ffffff             -jmp 0x422dd5
    goto L_0x00422dd5;
L_0x00422e83:
    // 00422e83  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00422e87  e949ffffff             -jmp 0x422dd5
    goto L_0x00422dd5;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_422e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422e92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422e93  3c10                   +cmp al, 0x10
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
    // 00422e95  7515                   -jne 0x422eac
    if (!cpu.flags.zf)
    {
        goto L_0x00422eac;
    }
    // 00422e97  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00422e99:
    // 00422e99  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00422e9c  42                     -inc edx
    (cpu.edx)++;
    // 00422e9d  e8eeffffff             -call 0x422e90
    cpu.esp -= 4;
    sub_422e90(app, cpu);
    if (cpu.terminate) return;
    // 00422ea2  83fa10                 +cmp edx, 0x10
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
    // 00422ea5  7cf2                   -jl 0x422e99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422e99;
    }
    // 00422ea7  90                     -nop 
    ;
L_0x00422ea8:
    // 00422ea8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422eaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422eab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422eac:
    // 00422eac  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422eaf  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00422eb2  83ba48734e0000         +cmp dword ptr [edx + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422eb9  74ed                   -je 0x422ea8
    if (cpu.flags.zf)
    {
        goto L_0x00422ea8;
    }
    // 00422ebb  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422ebe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422ec3  8b1d584c4d00           -mov ebx, dword ptr [0x4d4c58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422ec9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422ecb  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 00422ecd  74d9                   -je 0x422ea8
    if (cpu.flags.zf)
    {
        goto L_0x00422ea8;
    }
    // 00422ecf  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00422ed1  8b8248734e00           -mov eax, dword ptr [edx + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
    // 00422ed7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422ed8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422eda  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422edd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422edf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422ef3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00422ef4  3c10                   +cmp al, 0x10
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
    // 00422ef6  7521                   -jne 0x422f19
    if (!cpu.flags.zf)
    {
        goto L_0x00422f19;
    }
    // 00422ef8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00422efa:
    // 00422efa  0fbed1                 -movsx edx, cl
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.cl));
    // 00422efd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422eff  e80cfaffff             -call 0x422910
    cpu.esp -= 4;
    sub_422910(app, cpu);
    if (cpu.terminate) return;
    // 00422f04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422f06  41                     -inc ecx
    (cpu.ecx)++;
    // 00422f07  e8e4ffffff             -call 0x422ef0
    cpu.esp -= 4;
    sub_422ef0(app, cpu);
    if (cpu.terminate) return;
    // 00422f0c  83f910                 +cmp ecx, 0x10
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
    // 00422f0f  7ce9                   -jl 0x422efa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422efa;
    }
    // 00422f11  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00422f14:
    // 00422f14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422f19:
    // 00422f19  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422f1c  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 00422f23  83bb48734e0000         +cmp dword ptr [ebx + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5141320) /* 0x4e7348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422f2a  74e8                   -je 0x422f14
    if (cpu.flags.zf)
    {
        goto L_0x00422f14;
    }
    // 00422f2c  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422f2f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422f34  8b35584c4d00           -mov esi, dword ptr [0x4d4c58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422f3a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422f3c  85f0                   +test eax, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.esi));
    // 00422f3e  74d4                   -je 0x422f14
    if (cpu.flags.zf)
    {
        goto L_0x00422f14;
    }
    // 00422f40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00422f42  e8c9f9ffff             -call 0x422910
    cpu.esp -= 4;
    sub_422910(app, cpu);
    if (cpu.terminate) return;
    // 00422f47  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00422f49  8b9348734e00           -mov edx, dword ptr [ebx + 0x4e7348]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5141320) /* 0x4e7348 */);
    // 00422f4f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422f50  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00422f52  ff5058                 -call dword ptr [eax + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422f55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422f62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422f63  3c10                   +cmp al, 0x10
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
    // 00422f65  7515                   -jne 0x422f7c
    if (!cpu.flags.zf)
    {
        goto L_0x00422f7c;
    }
    // 00422f67  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00422f69:
    // 00422f69  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00422f6c  42                     -inc edx
    (cpu.edx)++;
    // 00422f6d  e8eeffffff             -call 0x422f60
    cpu.esp -= 4;
    sub_422f60(app, cpu);
    if (cpu.terminate) return;
    // 00422f72  83fa10                 +cmp edx, 0x10
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
    // 00422f75  7cf2                   -jl 0x422f69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422f69;
    }
    // 00422f77  90                     -nop 
    ;
L_0x00422f78:
    // 00422f78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422f7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422f7c:
    // 00422f7c  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422f7f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00422f82  83ba48734e0000         +cmp dword ptr [edx + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422f89  74ed                   -je 0x422f78
    if (cpu.flags.zf)
    {
        goto L_0x00422f78;
    }
    // 00422f8b  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422f8e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422f93  8b1d584c4d00           -mov ebx, dword ptr [0x4d4c58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422f99  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422f9b  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 00422f9d  74d9                   -je 0x422f78
    if (cpu.flags.zf)
    {
        goto L_0x00422f78;
    }
    // 00422f9f  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00422fa1  8b8248734e00           -mov eax, dword ptr [edx + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
    // 00422fa7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00422fa8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00422faa  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00422fad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422fae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422faf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422fb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_422fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00422fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00422fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00422fc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00422fc3  3c10                   +cmp al, 0x10
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
    // 00422fc5  7515                   -jne 0x422fdc
    if (!cpu.flags.zf)
    {
        goto L_0x00422fdc;
    }
    // 00422fc7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00422fc9:
    // 00422fc9  0fbec2                 -movsx eax, dl
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.dl));
    // 00422fcc  42                     -inc edx
    (cpu.edx)++;
    // 00422fcd  e8eeffffff             -call 0x422fc0
    cpu.esp -= 4;
    sub_422fc0(app, cpu);
    if (cpu.terminate) return;
    // 00422fd2  83fa10                 +cmp edx, 0x10
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
    // 00422fd5  7cf2                   -jl 0x422fc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00422fc9;
    }
    // 00422fd7  90                     -nop 
    ;
L_0x00422fd8:
    // 00422fd8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422fd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422fda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00422fdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00422fdc:
    // 00422fdc  0fbed0                 -movsx edx, al
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422fdf  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00422fe2  83ba48734e0000         +cmp dword ptr [edx + 0x4e7348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00422fe9  74ed                   -je 0x422fd8
    if (cpu.flags.zf)
    {
        goto L_0x00422fd8;
    }
    // 00422feb  0fbec8                 -movsx ecx, al
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 00422fee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00422ff3  8b1d584c4d00           -mov ebx, dword ptr [0x4d4c58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00422ff9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00422ffb  85d8                   +test eax, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebx));
    // 00422ffd  74d9                   -je 0x422fd8
    if (cpu.flags.zf)
    {
        goto L_0x00422fd8;
    }
    // 00422fff  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00423001  8b8248734e00           -mov eax, dword ptr [edx + 0x4e7348]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5141320) /* 0x4e7348 */);
    // 00423007  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423008  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042300a  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0042300d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042300e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042300f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423010  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423022  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423023  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423024  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423025  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423026  833d5c4c4d0000         +cmp dword ptr [0x4d4c5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065820) /* 0x4d4c5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042302d  7447                   -je 0x423076
    if (cpu.flags.zf)
    {
        goto L_0x00423076;
    }
L_0x0042302f:
    // 0042302f  833d584c4d0000         +cmp dword ptr [0x4d4c58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423036  7432                   -je 0x42306a
    if (cpu.flags.zf)
    {
        goto L_0x0042306a;
    }
    // 00423038  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0042303a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0042303c:
    // 0042303c  8bbe48734e00           -mov edi, dword ptr [esi + 0x4e7348]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5141320) /* 0x4e7348 */);
    // 00423042  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00423044  741b                   -je 0x423061
    if (cpu.flags.zf)
    {
        goto L_0x00423061;
    }
    // 00423046  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042304b  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0042304d  8b2d584c4d00           -mov ebp, dword ptr [0x4d4c58]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 00423053  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00423055  85e8                   +test eax, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ebp));
    // 00423057  7408                   -je 0x423061
    if (cpu.flags.zf)
    {
        goto L_0x00423061;
    }
    // 00423059  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0042305b  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0042305d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042305e  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00423061:
    // 00423061  43                     -inc ebx
    (cpu.ebx)++;
    // 00423062  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423065  83fb10                 +cmp ebx, 0x10
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
    // 00423068  7cd2                   -jl 0x42303c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042303c;
    }
L_0x0042306a:
    // 0042306a  a1584c4d00             -mov eax, dword ptr [0x4d4c58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065816) /* 0x4d4c58 */);
    // 0042306f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423070  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423071  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423072  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423073  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423074  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423075  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423076:
    // 00423076  e895eeffff             -call 0x421f10
    cpu.esp -= 4;
    sub_421f10(app, cpu);
    if (cpu.terminate) return;
    // 0042307b  ebb2                   -jmp 0x42302f
    goto L_0x0042302f;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_423080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00423080, cpu);
    // 00423080  e9fbf2ffff             -jmp 0x422380
    return sub_422380(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423090  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4230a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004230a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004230a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004230a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004230a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004230a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004230a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004230a6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004230a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004230ab  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004230ae  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004230b0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004230b3  8b1d6c4c4d00           -mov ebx, dword ptr [0x4d4c6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 004230b9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004230bb  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004230bd  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004230c0  83f901                 +cmp ecx, 1
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
    // 004230c3  0f8599000000           -jne 0x423162
    if (!cpu.flags.zf)
    {
        goto L_0x00423162;
    }
    // 004230c9  8b1d684c4d00           -mov ebx, dword ptr [0x4d4c68]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004230cf  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004230d2  8b7c1a34               -mov edi, dword ptr [edx + ebx + 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */ + cpu.ebx * 1);
    // 004230d6  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004230d8  8d1437                 -lea edx, [edi + esi]
    cpu.edx = x86::reg32(cpu.edi + cpu.esi * 1);
    // 004230db  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004230dd  39f2                   +cmp edx, esi
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
    // 004230df  7e05                   -jle 0x4230e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004230e6;
    }
    // 004230e1  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004230e3  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004230e5  41                     -inc ecx
    (cpu.ecx)++;
L_0x004230e6:
    // 004230e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004230e8  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004230eb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004230ed  8b2d6c4c4d00           -mov ebp, dword ptr [0x4d4c6c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 004230f3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004230f6  8b1d684c4d00           -mov ebx, dword ptr [0x4d4c68]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004230fc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004230fe  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423101  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00423104  8d4328                 -lea eax, [ebx + 0x28]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00423107  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0042310b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0042310d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0042310f  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00423112  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00423114  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00423116  e865780600             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0042311b  39f1                   +cmp ecx, esi
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
    // 0042311d  7c0f                   -jl 0x42312e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042312e;
    }
L_0x0042311f:
    // 0042311f  a16c4c4d00             -mov eax, dword ptr [0x4d4c6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 00423124  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00423127  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423128  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423129  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042312a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042312b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042312c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042312d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042312e:
    // 0042312e  a16c4c4d00             -mov eax, dword ptr [0x4d4c6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 00423133  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423136  8d1408                 -lea edx, [eax + ecx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00423139  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0042313b  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 00423140  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00423144  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00423147  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00423149  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042314b  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0042314e  e82d780600             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00423153  a16c4c4d00             -mov eax, dword ptr [0x4d4c6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 00423158  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042315b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042315c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042315d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042315e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042315f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423160  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423161  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423162:
    // 00423162  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 00423167  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0042316b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0042316d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0042316f  8b5c0228               -mov ebx, dword ptr [edx + eax + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */ + cpu.eax * 1);
L_0x00423173:
    // 00423173  8b356c4c4d00           -mov esi, dword ptr [0x4d4c6c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 00423179  3b2e                   +cmp ebp, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042317b  7da2                   -jge 0x42311f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0042311f;
    }
    // 0042317d  8b3d684c4d00           -mov edi, dword ptr [0x4d4c68]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 00423183  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00423185  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423187  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0042318a  f77f04                 -idiv dword ptr [edi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042318d  6bd234                 -imul edx, edx, 0x34
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(52 /*0x34*/)));
    // 00423190  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00423194  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00423197  8d5728                 -lea edx, [edi + 0x28]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 0042319a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042319c  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0042319f  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004231a2  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004231a4  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004231a7  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004231aa  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004231ad  45                     -inc ebp
    (cpu.ebp)++;
    // 004231ae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004231b0  43                     -inc ebx
    (cpu.ebx)++;
    // 004231b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004231b2:
    // 004231b2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004231b4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004231b6  3c00                   +cmp al, 0
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
    // 004231b8  7410                   -je 0x4231ca
    if (cpu.flags.zf)
    {
        goto L_0x004231ca;
    }
    // 004231ba  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004231bd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004231c0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004231c3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004231c6  3c00                   +cmp al, 0
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
    // 004231c8  75e8                   -jne 0x4231b2
    if (!cpu.flags.zf)
    {
        goto L_0x004231b2;
    }
L_0x004231ca:
    // 004231ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004231cb  83c126                 +add ecx, 0x26
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004231ce  eba3                   -jmp 0x423173
    goto L_0x00423173;
}

/* align: skip  */
void Application::sub_4231d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004231d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004231d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004231d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004231d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004231d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004231d5  8b35684c4d00           -mov esi, dword ptr [0x4d4c68]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004231db  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004231dd  833d704c4d0000         +cmp dword ptr [0x4d4c70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004231e4  0f8482000000           -je 0x42326c
    if (cpu.flags.zf)
    {
        goto L_0x0042326c;
    }
    // 004231ea  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004231ed  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004231ef  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004231f2  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004231f4  8d4e28                 -lea ecx, [esi + 0x28]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004231f7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004231fa  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004231fc  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004231ff  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423202  740d                   -je 0x423211
    if (cpu.flags.zf)
    {
        goto L_0x00423211;
    }
L_0x00423204:
    // 00423204  6bd034                 -imul edx, eax, 0x34
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(52 /*0x34*/)));
    // 00423207  8b5c1114               -mov ebx, dword ptr [ecx + edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */ + cpu.edx * 1);
    // 0042320b  3b5c1110               +cmp ebx, dword ptr [ecx + edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.edx * 1)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042320f  745f                   -je 0x423270
    if (cpu.flags.zf)
    {
        goto L_0x00423270;
    }
L_0x00423211:
    // 00423211  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00423218  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0042321a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0042321d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042321f  8d590c                 -lea ebx, [ecx + 0xc]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00423222  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00423225  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00423227  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0042322a  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042322d  743d                   -je 0x42326c
    if (cpu.flags.zf)
    {
        goto L_0x0042326c;
    }
    // 0042322f  4b                     -dec ebx
    (cpu.ebx)--;
    // 00423230  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00423233  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00423235  7c4b                   -jl 0x423282
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423282;
    }
L_0x00423237:
    // 00423237  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0042323a  035208                 -add edx, dword ptr [edx + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0042323d  c6420c00               -mov byte ptr [edx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00423241  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00423244  8935684c4d00           -mov dword ptr [0x4d4c68], esi
    app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */) = cpu.esi;
    // 0042324a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0042324c  7407                   -je 0x423255
    if (cpu.flags.zf)
    {
        goto L_0x00423255;
    }
    // 0042324e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00423250  e83bfeffff             -call 0x423090
    cpu.esp -= 4;
    sub_423090(app, cpu);
    if (cpu.terminate) return;
L_0x00423255:
    // 00423255  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0042325a  8b35684c4d00           -mov esi, dword ptr [0x4d4c68]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
L_0x00423260:
    // 00423260  8935684c4d00           -mov dword ptr [0x4d4c68], esi
    app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */) = cpu.esi;
    // 00423266  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423267  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423268  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423269  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042326a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042326b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042326c:
    // 0042326c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0042326e  ebf0                   -jmp 0x423260
    goto L_0x00423260;
L_0x00423270:
    // 00423270  48                     -dec eax
    (cpu.eax)--;
    // 00423271  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423273  7c07                   -jl 0x42327c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042327c;
    }
L_0x00423275:
    // 00423275  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423278  758a                   -jne 0x423204
    if (!cpu.flags.zf)
    {
        goto L_0x00423204;
    }
    // 0042327a  eb95                   -jmp 0x423211
    goto L_0x00423211;
L_0x0042327c:
    // 0042327c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0042327f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00423280  ebf3                   -jmp 0x423275
    goto L_0x00423275;
L_0x00423282:
    // 00423282  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00423284  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00423287  ebae                   -jmp 0x423237
    goto L_0x00423237;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423291  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423292  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423295  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00423297  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 0042329a  833d704c4d0000         +cmp dword ptr [0x4d4c70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004232a1  0f849a000000           -je 0x423341
    if (cpu.flags.zf)
    {
        goto L_0x00423341;
    }
    // 004232a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004232a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004232a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004232aa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004232ac  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 004232af  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004232b1  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 004232b4  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004232b6  8b35684c4d00           -mov esi, dword ptr [0x4d4c68]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004232bc  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 004232bf  8d3c2e                 -lea edi, [esi + ebp]
    cpu.edi = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 004232c2  8b5730                 -mov edx, dword ptr [edi + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004232c5  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004232cc  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004232ce  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004232d1  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004232d4  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004232d6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004232d8  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004232db  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004232de  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004232e0  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004232e3  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004232e6  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004232e9  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004232ed  8854010c               -mov byte ptr [ecx + eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.dl;
    // 004232f1  837e0c01               +cmp dword ptr [esi + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004232f5  754e                   -jne 0x423345
    if (!cpu.flags.zf)
    {
        goto L_0x00423345;
    }
    // 004232f7  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004232f9  3b5908                 +cmp ebx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004232fc  7d07                   -jge 0x423305
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423305;
    }
    // 004232fe  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00423305:
    // 00423305  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00423308  3b7108                 +cmp esi, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042330b  751a                   -jne 0x423327
    if (!cpu.flags.zf)
    {
        goto L_0x00423327;
    }
    // 0042330d  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423310  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 00423315  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00423318  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0042331a  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0042331c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0042331f  43                     -inc ebx
    (cpu.ebx)++;
    // 00423320  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00423322  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00423324  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00423327:
    // 00423327  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042332a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0042332c:
    // 0042332c  034908                 -add ecx, dword ptr [ecx + 8]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0042332f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423334  c6410c00               -mov byte ptr [ecx + 0xc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00423338  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423339  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042333a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0042333b:
    // 0042333b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0042333e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042333f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423340  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423341:
    // 00423341  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00423343  ebf6                   -jmp 0x42333b
    goto L_0x0042333b;
L_0x00423345:
    // 00423345  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00423347  3b5108                 +cmp edx, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042334a  7541                   -jne 0x42338d
    if (!cpu.flags.zf)
    {
        goto L_0x0042338d;
    }
    // 0042334c  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0042334f  40                     -inc eax
    (cpu.eax)++;
    // 00423350  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423352  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00423355  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00423358  f77e04                 -idiv dword ptr [esi + 4]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042335b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042335d  895730                 -mov dword ptr [edi + 0x30], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00423360  e86b000000             -call 0x4233d0
    cpu.esp -= 4;
    sub_4233d0(app, cpu);
    if (cpu.terminate) return;
    // 00423365  8b3d684c4d00           -mov edi, dword ptr [0x4d4c68]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 0042336b  8d342f                 -lea esi, [edi + ebp]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0042336e  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00423371  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00423374  39d0                   +cmp eax, edx
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
    // 00423376  7515                   -jne 0x42338d
    if (!cpu.flags.zf)
    {
        goto L_0x0042338d;
    }
    // 00423378  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0042337b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0042337d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0042337f  896e2c                 -mov dword ptr [esi + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 00423382  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00423385  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00423388  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0042338a  89562c                 -mov dword ptr [esi + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.edx;
L_0x0042338d:
    // 0042338d  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 00423392  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00423396  7407                   -je 0x42339f
    if (cpu.flags.zf)
    {
        goto L_0x0042339f;
    }
    // 00423398  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0042339a  e8f1fcffff             -call 0x423090
    cpu.esp -= 4;
    sub_423090(app, cpu);
    if (cpu.terminate) return;
L_0x0042339f:
    // 0042339f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004233a1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004233a4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004233a6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004233a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004233ab  8b15684c4d00           -mov edx, dword ptr [0x4d4c68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004233b1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004233b4  01d0                   +add eax, edx
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
    // 004233b6  8b502c                 -mov edx, dword ptr [eax + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004233b9  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004233bc  e96bffffff             -jmp 0x42332c
    goto L_0x0042332c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4233d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004233d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004233d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004233d2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004233d4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004233d6  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004233d9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004233db  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004233de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004233e0  8b1d684c4d00           -mov ebx, dword ptr [0x4d4c68]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004233e6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004233e9  8d5328                 -lea edx, [ebx + 0x28]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004233ec  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004233ef  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004233f1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004233f8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004233fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004233fd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004233ff  8d530c                 -lea edx, [ebx + 0xc]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00423402  c7048200000000         -mov dword ptr [edx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
    // 00423409  c744820400000000       -mov dword ptr [edx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 00423411  c744820800000000       -mov dword ptr [edx + eax*4 + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 00423419  c644820c00             -mov byte ptr [edx + eax*4 + 0xc], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) = 0 /*0x0*/;
    // 0042341e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042341f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423420  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423430  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423431  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423432  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00423434  8b35704c4d00           -mov esi, dword ptr [0x4d4c70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */);
    // 0042343a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0042343c  7442                   -je 0x423480
    if (cpu.flags.zf)
    {
        goto L_0x00423480;
    }
    // 0042343e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042343f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423440  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423442  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423444  8915704c4d00           -mov dword ptr [0x4d4c70], edx
    app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */) = cpu.edx;
L_0x0042344a:
    // 0042344a  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 0042344f  3b4804                 +cmp ecx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423452  7c2f                   -jl 0x423483
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423483;
    }
    // 00423454  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00423456  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00423459  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0042345b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0042345e  01d9                   +add ecx, ebx
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
    // 00423460  c744882800000000       -mov dword ptr [eax + ecx*4 + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 00423468  c744882c00000000       -mov dword ptr [eax + ecx*4 + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 00423470  c744883000000000       -mov dword ptr [eax + ecx*4 + 0x30], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */ + cpu.ecx * 4) = 0 /*0x0*/;
    // 00423478  8935704c4d00           -mov dword ptr [0x4d4c70], esi
    app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */) = cpu.esi;
    // 0042347e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042347f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00423480:
    // 00423480  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423481  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423482  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423483:
    // 00423483  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00423485  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423487  e844ffffff             -call 0x4233d0
    cpu.esp -= 4;
    sub_4233d0(app, cpu);
    if (cpu.terminate) return;
    // 0042348c  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0042348d  ebbb                   -jmp 0x42344a
    goto L_0x0042344a;
}

/* align: skip 0x00 */
void Application::sub_423490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423490  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423491  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423493  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 00423498  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042349b  7c02                   -jl 0x42349f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042349f;
    }
    // 0042349d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042349e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0042349f:
    // 0042349f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004234a1  e88affffff             -call 0x423430
    cpu.esp -= 4;
    sub_423430(app, cpu);
    if (cpu.terminate) return;
    // 004234a6  42                     -inc edx
    (cpu.edx)++;
    // 004234a7  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004234ac  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004234af  7cee                   -jl 0x42349f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0042349f;
    }
    // 004234b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4234c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004234c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004234c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004234c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004234c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004234c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004234c6  8b0d684c4d00           -mov ecx, dword ptr [0x4d4c68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004234cc  8915704c4d00           -mov dword ptr [0x4d4c70], edx
    app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */) = cpu.edx;
    // 004234d2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004234d4  751d                   -jne 0x4234f3
    if (!cpu.flags.zf)
    {
        goto L_0x004234f3;
    }
L_0x004234d6:
    // 004234d6  8b1d6c4c4d00           -mov ebx, dword ptr [0x4d4c6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 004234dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004234de  751c                   -jne 0x4234fc
    if (!cpu.flags.zf)
    {
        goto L_0x004234fc;
    }
    // 004234e0  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004234e2  8935684c4d00           -mov dword ptr [0x4d4c68], esi
    app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */) = cpu.esi;
    // 004234e8  89356c4c4d00           -mov dword ptr [0x4d4c6c], esi
    app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */) = cpu.esi;
    // 004234ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004234f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004234f3:
    // 004234f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004234f5  e802140600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004234fa  ebda                   -jmp 0x4234d6
    goto L_0x004234d6;
L_0x004234fc:
    // 004234fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004234fe  e8f9130600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00423503  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00423505  8935684c4d00           -mov dword ptr [0x4d4c68], esi
    app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */) = cpu.esi;
    // 0042350b  89356c4c4d00           -mov dword ptr [0x4d4c6c], esi
    app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */) = cpu.esi;
    // 00423511  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423512  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423513  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423514  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423515  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423521  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423522  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423523  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423524  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423525  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423526  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423528  833d684c4d0000         +cmp dword ptr [0x4d4c68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0042352f  0f85fd000000           -jne 0x423632
    if (!cpu.flags.zf)
    {
        goto L_0x00423632;
    }
L_0x00423535:
    // 00423535  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00423538  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042353b  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042353e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00423540  740b                   -je 0x42354d
    if (cpu.flags.zf)
    {
        goto L_0x0042354d;
    }
    // 00423542  83fe01                 +cmp esi, 1
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
    // 00423545  0f8e0f010000           -jle 0x42365a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0042365a;
    }
    // 0042354b  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x0042354d:
    // 0042354d  bb249b4c00             -mov ebx, 0x4c9b24
    cpu.ebx = 5020452 /*0x4c9b24*/;
    // 00423552  bd74000000             -mov ebp, 0x74
    cpu.ebp = 116 /*0x74*/;
    // 00423557  bac8100000             -mov edx, 0x10c8
    cpu.edx = 4296 /*0x10c8*/;
    // 0042355c  b85c9b4c00             -mov eax, 0x4c9b5c
    cpu.eax = 5020508 /*0x4c9b5c*/;
    // 00423561  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 00423567  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0042356c  892ddcb14d00           -mov dword ptr [0x4db1dc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebp;
    // 00423572  e8210f0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00423577  a3684c4d00             -mov dword ptr [0x4d4c68], eax
    app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */) = cpu.eax;
    // 0042357c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042357e  7527                   -jne 0x4235a7
    if (!cpu.flags.zf)
    {
        goto L_0x004235a7;
    }
    // 00423580  68c8100000             -push 0x10c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4296 /*0x10c8*/;
    cpu.esp -= 4;
    // 00423585  b8249b4c00             -mov eax, 0x4c9b24
    cpu.eax = 5020452 /*0x4c9b24*/;
    // 0042358a  ba76000000             -mov edx, 0x76
    cpu.edx = 118 /*0x76*/;
    // 0042358f  68649b4c00             -push 0x4c9b64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020516 /*0x4c9b64*/;
    cpu.esp -= 4;
    // 00423594  a3d8b14d00             -mov dword ptr [0x4db1d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.eax;
    // 00423599  8915dcb14d00           -mov dword ptr [0x4db1dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.edx;
    // 0042359f  e84c0b0600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 004235a4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004235a7:
    // 004235a7  bac8100000             -mov edx, 0x10c8
    cpu.edx = 4296 /*0x10c8*/;
    // 004235ac  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004235b1  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004235b6  e8616a0600             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 004235bb  8b15684c4d00           -mov edx, dword ptr [0x4d4c68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004235c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004235c3  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004235c6  e8b5730600             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004235cb  a1684c4d00             -mov eax, dword ptr [0x4d4c68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065832) /* 0x4d4c68 */);
    // 004235d0  bb249b4c00             -mov ebx, 0x4c9b24
    cpu.ebx = 5020452 /*0x4c9b24*/;
    // 004235d5  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 004235da  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004235dd  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 004235e3  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004235e5  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 004235ea  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004235ef  b8849b4c00             -mov eax, 0x4c9b84
    cpu.eax = 5020548 /*0x4c9b84*/;
    // 004235f4  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 004235fa  e8990e0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004235ff  a36c4c4d00             -mov dword ptr [0x4d4c6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */) = cpu.eax;
    // 00423604  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423606  7459                   -je 0x423661
    if (cpu.flags.zf)
    {
        goto L_0x00423661;
    }
L_0x00423608:
    // 00423608  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 0042360d  a16c4c4d00             -mov eax, dword ptr [0x4d4c6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 00423612  e8056a0600             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00423617  a16c4c4d00             -mov eax, dword ptr [0x4d4c6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065836) /* 0x4d4c6c */);
    // 0042361c  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0042361f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00423621  c705704c4d0001000000   -mov dword ptr [0x4d4c70], 1
    app->getMemory<x86::reg32>(x86::reg32(5065840) /* 0x4d4c70 */) = 1 /*0x1*/;
    // 0042362b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042362c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042362d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042362e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042362f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423630  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423631  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423632:
    // 00423632  bb249b4c00             -mov ebx, 0x4c9b24
    cpu.ebx = 5020452 /*0x4c9b24*/;
    // 00423637  be5f000000             -mov esi, 0x5f
    cpu.esi = 95 /*0x5f*/;
    // 0042363c  68449b4c00             -push 0x4c9b44
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020484 /*0x4c9b44*/;
    cpu.esp -= 4;
    // 00423641  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 00423647  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 0042364d  e89e0a0600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00423652  83c404                 +add esp, 4
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
    // 00423655  e9dbfeffff             -jmp 0x423535
    goto L_0x00423535;
L_0x0042365a:
    // 0042365a  01ef                   +add edi, ebp
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
    // 0042365c  e9ecfeffff             -jmp 0x42354d
    goto L_0x0042354d;
L_0x00423661:
    // 00423661  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00423666  bf249b4c00             -mov edi, 0x4c9b24
    cpu.edi = 5020452 /*0x4c9b24*/;
    // 0042366b  bd82000000             -mov ebp, 0x82
    cpu.ebp = 130 /*0x82*/;
    // 00423670  68649b4c00             -push 0x4c9b64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020516 /*0x4c9b64*/;
    cpu.esp -= 4;
    // 00423675  893dd8b14d00           -mov dword ptr [0x4db1d8], edi
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edi;
    // 0042367b  892ddcb14d00           -mov dword ptr [0x4db1dc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ebp;
    // 00423681  e86a0a0600             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 00423686  83c408                 +add esp, 8
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
    // 00423689  e97affffff             -jmp 0x423608
    goto L_0x00423608;
}

/* align: skip 0x00 0x00 */
void Application::sub_423690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423692  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423693  81ec00090000           -sub esp, 0x900
    (cpu.esp) -= x86::reg32(x86::sreg32(2304 /*0x900*/));
    // 00423699  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0042369b  b8909b4c00             -mov eax, 0x4c9b90
    cpu.eax = 5020560 /*0x4c9b90*/;
    // 004236a0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004236a2  e8f962feff             -call 0x4099a0
    cpu.esp -= 4;
    sub_4099a0(app, cpu);
    if (cpu.terminate) return;
    // 004236a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004236a9  e8e2d9fdff             -call 0x401090
    cpu.esp -= 4;
    sub_401090(app, cpu);
    if (cpu.terminate) return;
    // 004236ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004236b0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004236b3  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004236b5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004236b7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004236b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004236ba  8b1dc0345100           -mov ebx, dword ptr [0x5134c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5321920) /* 0x5134c0 */);
    // 004236c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004236c1  68989b4c00             -push 0x4c9b98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020568 /*0x4c9b98*/;
    cpu.esp -= 4;
    // 004236c6  8d8424d8080000         -lea eax, [esp + 0x8d8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2264) /* 0x8d8 */);
    // 004236cd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004236ce  e82e2e0600             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004236d3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004236d6  83faff                 +cmp edx, -1
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
    // 004236d9  750a                   -jne 0x4236e5
    if (!cpu.flags.zf)
    {
        goto L_0x004236e5;
    }
L_0x004236db:
    // 004236db  81c400090000           -add esp, 0x900
    (cpu.esp) += x86::reg32(x86::sreg32(2304 /*0x900*/));
    // 004236e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004236e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004236e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004236e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004236e5:
    // 004236e5  68f7020000             -push 0x2f7
    app->getMemory<x86::reg32>(cpu.esp-4) = 759 /*0x2f7*/;
    cpu.esp -= 4;
    // 004236ea  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004236ec  e8efe3fdff             -call 0x401ae0
    cpu.esp -= 4;
    sub_401ae0(app, cpu);
    if (cpu.terminate) return;
    // 004236f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004236f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004236f6  74e3                   -je 0x4236db
    if (cpu.flags.zf)
    {
        goto L_0x004236db;
    }
    // 004236f8  8d8424cc080000         -lea eax, [esp + 0x8cc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2252) /* 0x8cc */);
    // 004236ff  e8aa420600             -call 0x4879ae
    cpu.esp -= 4;
    sub_4879ae(app, cpu);
    if (cpu.terminate) return;
    // 00423704  b8f8020000             -mov eax, 0x2f8
    cpu.eax = 760 /*0x2f8*/;
    // 00423709  ba862f5100             -mov edx, 0x512f86
    cpu.edx = 5320582 /*0x512f86*/;
    // 0042370e  e8bdf5fdff             -call 0x402cd0
    cpu.esp -= 4;
    sub_402cd0(app, cpu);
    if (cpu.terminate) return;
    // 00423713  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423715  e806000600             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 0042371a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042371c  75bd                   -jne 0x4236db
    if (!cpu.flags.zf)
    {
        goto L_0x004236db;
    }
    // 0042371e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0042371f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423720  bea49b4c00             -mov esi, 0x4c9ba4
    cpu.esi = 5020580 /*0x4c9ba4*/;
    // 00423725  bf5e2f5100             -mov edi, 0x512f5e
    cpu.edi = 5320542 /*0x512f5e*/;
    // 0042372a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042372b:
    // 0042372b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0042372d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042372f  3c00                   +cmp al, 0
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
    // 00423731  7410                   -je 0x423743
    if (cpu.flags.zf)
    {
        goto L_0x00423743;
    }
    // 00423733  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423736  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423739  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0042373c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042373f  3c00                   +cmp al, 0
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
    // 00423741  75e8                   -jne 0x42372b
    if (!cpu.flags.zf)
    {
        goto L_0x0042372b;
    }
L_0x00423743:
    // 00423743  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423744  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423745  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423746  81c400090000           -add esp, 0x900
    (cpu.esp) += x86::reg32(x86::sreg32(2304 /*0x900*/));
    // 0042374c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042374d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042374e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042374f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423755  81ec740a0000           -sub esp, 0xa74
    (cpu.esp) -= x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 0042375b  b8ea020000             -mov eax, 0x2ea
    cpu.eax = 746 /*0x2ea*/;
    // 00423760  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00423762  e8a97fffff             -call 0x41b710
    cpu.esp -= 4;
    sub_41b710(app, cpu);
    if (cpu.terminate) return;
    // 00423767  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00423769  b8909b4c00             -mov eax, 0x4c9b90
    cpu.eax = 5020560 /*0x4c9b90*/;
    // 0042376e  e82d62feff             -call 0x4099a0
    cpu.esp -= 4;
    sub_4099a0(app, cpu);
    if (cpu.terminate) return;
    // 00423773  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423775  e816d9fdff             -call 0x401090
    cpu.esp -= 4;
    sub_401090(app, cpu);
    if (cpu.terminate) return;
    // 0042377a  83f8ff                 +cmp eax, -1
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
    // 0042377d  7437                   -je 0x4237b6
    if (cpu.flags.zf)
    {
        goto L_0x004237b6;
    }
    // 0042377f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423781  0f8590010000           -jne 0x423917
    if (!cpu.flags.zf)
    {
        goto L_0x00423917;
    }
    // 00423787  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0042378c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00423791  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00423793  baeb020000             -mov edx, 0x2eb
    cpu.edx = 747 /*0x2eb*/;
    // 00423798  88a424d4090000         -mov byte ptr [esp + 0x9d4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2516) /* 0x9d4 */) = cpu.ah;
    // 0042379f  88a424240a0000         -mov byte ptr [esp + 0xa24], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2596) /* 0xa24 */) = cpu.ah;
    // 004237a6  8d8424240a0000         -lea eax, [esp + 0xa24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 004237ad  e8aeecfdff             -call 0x402460
    cpu.esp -= 4;
    sub_402460(app, cpu);
    if (cpu.terminate) return;
    // 004237b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004237b4  750c                   -jne 0x4237c2
    if (!cpu.flags.zf)
    {
        goto L_0x004237c2;
    }
L_0x004237b6:
    // 004237b6  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 004237bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004237bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004237be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004237bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004237c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004237c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004237c2:
    // 004237c2  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004237c7  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004237cc  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004237ce  8d8424d4090000         -lea eax, [esp + 0x9d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 004237d5  88b424d4090000         -mov byte ptr [esp + 0x9d4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2516) /* 0x9d4 */) = cpu.dh;
    // 004237dc  bae7020000             -mov edx, 0x2e7
    cpu.edx = 743 /*0x2e7*/;
    // 004237e1  e87aecfdff             -call 0x402460
    cpu.esp -= 4;
    sub_402460(app, cpu);
    if (cpu.terminate) return;
    // 004237e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004237e8  74cc                   -je 0x4237b6
    if (cpu.flags.zf)
    {
        goto L_0x004237b6;
    }
    // 004237ea  8d8424d4090000         -lea eax, [esp + 0x9d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 004237f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004237f2  8b0dc0345100           -mov ecx, dword ptr [0x5134c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5321920) /* 0x5134c0 */);
    // 004237f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004237f9  68989b4c00             -push 0x4c9b98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020568 /*0x4c9b98*/;
    cpu.esp -= 4;
    // 004237fe  8d8424e0080000         -lea eax, [esp + 0x8e0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2272) /* 0x8e0 */);
    // 00423805  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423806  e8f62c0600             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0042380b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042380e  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423815  e8564d0600             -call 0x488570
    cpu.esp -= 4;
    sub_488570(app, cpu);
    if (cpu.terminate) return;
    // 0042381a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0042381c  0f848a000000           -je 0x4238ac
    if (cpu.flags.zf)
    {
        goto L_0x004238ac;
    }
    // 00423822  68f9020000             -push 0x2f9
    app->getMemory<x86::reg32>(cpu.esp-4) = 761 /*0x2f9*/;
    cpu.esp -= 4;
    // 00423827  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00423829  e8b2e2fdff             -call 0x401ae0
    cpu.esp -= 4;
    sub_401ae0(app, cpu);
    if (cpu.terminate) return;
    // 0042382e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00423831  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423833  7481                   -je 0x4237b6
    if (cpu.flags.zf)
    {
        goto L_0x004237b6;
    }
    // 00423835  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 0042383c  8d9424240a0000         -lea edx, [esp + 0xa24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 00423843  8db424240a0000         -lea esi, [esp + 0xa24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 0042384a  e85f410600             -call 0x4879ae
    cpu.esp -= 4;
    sub_4879ae(app, cpu);
    if (cpu.terminate) return;
    // 0042384f  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423856  bf5e2f5100             -mov edi, 0x512f5e
    cpu.edi = 5320542 /*0x512f5e*/;
    // 0042385b  e890010000             -call 0x4239f0
    cpu.esp -= 4;
    sub_4239f0(app, cpu);
    if (cpu.terminate) return;
    // 00423860  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423861:
    // 00423861  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423863  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423865  3c00                   +cmp al, 0
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
    // 00423867  7410                   -je 0x423879
    if (cpu.flags.zf)
    {
        goto L_0x00423879;
    }
    // 00423869  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042386c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042386f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423872  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423875  3c00                   +cmp al, 0
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
    // 00423877  75e8                   -jne 0x423861
    if (!cpu.flags.zf)
    {
        goto L_0x00423861;
    }
L_0x00423879:
    // 00423879  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042387a  8db424d4090000         -lea esi, [esp + 0x9d4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 00423881  bf862f5100             -mov edi, 0x512f86
    cpu.edi = 5320582 /*0x512f86*/;
    // 00423886  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423887:
    // 00423887  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423889  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0042388b  3c00                   +cmp al, 0
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
    // 0042388d  7410                   -je 0x42389f
    if (cpu.flags.zf)
    {
        goto L_0x0042389f;
    }
    // 0042388f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423892  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423895  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423898  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042389b  3c00                   +cmp al, 0
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
    // 0042389d  75e8                   -jne 0x423887
    if (!cpu.flags.zf)
    {
        goto L_0x00423887;
    }
L_0x0042389f:
    // 0042389f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238a0  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 004238a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004238ac:
    // 004238ac  8d9424240a0000         -lea edx, [esp + 0xa24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 004238b3  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 004238ba  8db424240a0000         -lea esi, [esp + 0xa24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2596) /* 0xa24 */);
    // 004238c1  bf5e2f5100             -mov edi, 0x512f5e
    cpu.edi = 5320542 /*0x512f5e*/;
    // 004238c6  e825010000             -call 0x4239f0
    cpu.esp -= 4;
    sub_4239f0(app, cpu);
    if (cpu.terminate) return;
    // 004238cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004238cc:
    // 004238cc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004238ce  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004238d0  3c00                   +cmp al, 0
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
    // 004238d2  7410                   -je 0x4238e4
    if (cpu.flags.zf)
    {
        goto L_0x004238e4;
    }
    // 004238d4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004238d7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004238da  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004238dd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004238e0  3c00                   +cmp al, 0
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
    // 004238e2  75e8                   -jne 0x4238cc
    if (!cpu.flags.zf)
    {
        goto L_0x004238cc;
    }
L_0x004238e4:
    // 004238e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004238e5  8db424d4090000         -lea esi, [esp + 0x9d4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2516) /* 0x9d4 */);
    // 004238ec  bf862f5100             -mov edi, 0x512f86
    cpu.edi = 5320582 /*0x512f86*/;
    // 004238f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004238f2:
    // 004238f2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004238f4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004238f6  3c00                   +cmp al, 0
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
    // 004238f8  7410                   -je 0x42390a
    if (cpu.flags.zf)
    {
        goto L_0x0042390a;
    }
    // 004238fa  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004238fd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423900  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423903  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423906  3c00                   +cmp al, 0
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
    // 00423908  75e8                   -jne 0x4238f2
    if (!cpu.flags.zf)
    {
        goto L_0x004238f2;
    }
L_0x0042390a:
    // 0042390a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0042390b  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 00423911  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423912  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423913  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423914  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423915  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423916  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423917:
    // 00423917  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00423919  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0042391c  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0042391e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00423920  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00423922  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423923  8b15c0345100           -mov edx, dword ptr [0x5134c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5321920) /* 0x5134c0 */);
    // 00423929  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0042392a  68989b4c00             -push 0x4c9b98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020568 /*0x4c9b98*/;
    cpu.esp -= 4;
    // 0042392f  8d8424e0080000         -lea eax, [esp + 0x8e0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2272) /* 0x8e0 */);
    // 00423936  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00423937  8db424340a0000         -lea esi, [esp + 0xa34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 0042393e  8d9424340a0000         -lea edx, [esp + 0xa34]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(2612) /* 0xa34 */);
    // 00423945  e8b72b0600             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0042394a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0042394d  8d8424d4080000         -lea eax, [esp + 0x8d4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(2260) /* 0x8d4 */);
    // 00423954  bf5e2f5100             -mov edi, 0x512f5e
    cpu.edi = 5320542 /*0x512f5e*/;
    // 00423959  e852000000             -call 0x4239b0
    cpu.esp -= 4;
    sub_4239b0(app, cpu);
    if (cpu.terminate) return;
    // 0042395e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0042395f:
    // 0042395f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423961  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423963  3c00                   +cmp al, 0
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
    // 00423965  7410                   -je 0x423977
    if (cpu.flags.zf)
    {
        goto L_0x00423977;
    }
    // 00423967  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042396a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042396d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423970  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423973  3c00                   +cmp al, 0
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
    // 00423975  75e8                   -jne 0x42395f
    if (!cpu.flags.zf)
    {
        goto L_0x0042395f;
    }
L_0x00423977:
    // 00423977  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423978  bf862f5100             -mov edi, 0x512f86
    cpu.edi = 5320582 /*0x512f86*/;
    // 0042397d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0042397f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423980:
    // 00423980  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423982  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423984  3c00                   +cmp al, 0
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
    // 00423986  7410                   -je 0x423998
    if (cpu.flags.zf)
    {
        goto L_0x00423998;
    }
    // 00423988  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0042398b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0042398e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423991  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423994  3c00                   +cmp al, 0
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
    // 00423996  75e8                   -jne 0x423980
    if (!cpu.flags.zf)
    {
        goto L_0x00423980;
    }
L_0x00423998:
    // 00423998  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423999  81c4740a0000           -add esp, 0xa74
    (cpu.esp) += x86::reg32(x86::sreg32(2676 /*0xa74*/));
    // 0042399f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4239b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004239b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004239b1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004239b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004239b5  e886350600             -call 0x486f40
    cpu.esp -= 4;
    sub_486f40(app, cpu);
    if (cpu.terminate) return;
    // 004239ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004239bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004239be  7502                   -jne 0x4239c2
    if (!cpu.flags.zf)
    {
        goto L_0x004239c2;
    }
    // 004239c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004239c2:
    // 004239c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004239c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004239c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004239c6:
    // 004239c6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004239c8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004239ca  3c00                   +cmp al, 0
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
    // 004239cc  7410                   -je 0x4239de
    if (cpu.flags.zf)
    {
        goto L_0x004239de;
    }
    // 004239ce  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004239d1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004239d4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004239d7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004239da  3c00                   +cmp al, 0
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
    // 004239dc  75e8                   -jne 0x4239c6
    if (!cpu.flags.zf)
    {
        goto L_0x004239c6;
    }
L_0x004239de:
    // 004239de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004239e1  e8160f0600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004239e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004239e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4239f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004239f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004239f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004239f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004239f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004239f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004239f6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004239f8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004239fa  49                     -dec ecx
    (cpu.ecx)--;
    // 004239fb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004239fd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004239ff  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00423a01  49                     -dec ecx
    (cpu.ecx)--;
    // 00423a02  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00423a05  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00423a07  e8a43b0600             -call 0x4875b0
    cpu.esp -= 4;
    sub_4875b0(app, cpu);
    if (cpu.terminate) return;
    // 00423a0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423a0e  7405                   -je 0x423a15
    if (cpu.flags.zf)
    {
        goto L_0x00423a15;
    }
    // 00423a10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423a15:
    // 00423a15  b8f3020000             -mov eax, 0x2f3
    cpu.eax = 755 /*0x2f3*/;
    // 00423a1a  e8b1f2fdff             -call 0x402cd0
    cpu.esp -= 4;
    sub_402cd0(app, cpu);
    if (cpu.terminate) return;
    // 00423a1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423a23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423a30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423a32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423a33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423a34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423a35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423a36  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423a39  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423a3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00423a3d  890d64894e00           -mov dword ptr [0x4e8964], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146980) /* 0x4e8964 */) = cpu.ecx;
    // 00423a43  e868c5ffff             -call 0x41ffb0
    cpu.esp -= 4;
    sub_41ffb0(app, cpu);
    if (cpu.terminate) return;
    // 00423a48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423a4a  0f84ba000000           -je 0x423b0a
    if (cpu.flags.zf)
    {
        goto L_0x00423b0a;
    }
    // 00423a50  8b1d744c4d00           -mov ebx, dword ptr [0x4d4c74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */);
    // 00423a56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00423a58  7407                   -je 0x423a61
    if (cpu.flags.zf)
    {
        goto L_0x00423a61;
    }
    // 00423a5a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423a5c  e89b0e0600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x00423a61:
    // 00423a61  bea89b4c00             -mov esi, 0x4c9ba8
    cpu.esi = 5020584 /*0x4c9ba8*/;
    // 00423a66  bf8f000000             -mov edi, 0x8f
    cpu.edi = 143 /*0x8f*/;
    // 00423a6b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00423a70  ba6c0c0000             -mov edx, 0xc6c
    cpu.edx = 3180 /*0xc6c*/;
    // 00423a75  b8cc9b4c00             -mov eax, 0x4c9bcc
    cpu.eax = 5020620 /*0x4c9bcc*/;
    // 00423a7a  8935d8b14d00           -mov dword ptr [0x4db1d8], esi
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.esi;
    // 00423a80  893ddcb14d00           -mov dword ptr [0x4db1dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.edi;
    // 00423a86  e80d0a0600             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00423a8b  a3744c4d00             -mov dword ptr [0x4d4c74], eax
    app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */) = cpu.eax;
    // 00423a90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423a92  0f8472000000           -je 0x423b0a
    if (cpu.flags.zf)
    {
        goto L_0x00423b0a;
    }
    // 00423a98  69e9d4000000           -imul ebp, ecx, 0xd4
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(212 /*0xd4*/)));
L_0x00423a9e:
    // 00423a9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423aa0  bbd4000000             -mov ebx, 0xd4
    cpu.ebx = 212 /*0xd4*/;
    // 00423aa5  e806c5ffff             -call 0x41ffb0
    cpu.esp -= 4;
    sub_41ffb0(app, cpu);
    if (cpu.terminate) return;
    // 00423aaa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00423aac  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00423aaf  a1744c4d00             -mov eax, dword ptr [0x4d4c74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */);
    // 00423ab4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423ab6  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00423ab8  e872eb0600             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 00423abd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423abf  7422                   -je 0x423ae3
    if (cpu.flags.zf)
    {
        goto L_0x00423ae3;
    }
    // 00423ac1  8b3d744c4d00           -mov edi, dword ptr [0x4d4c74]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */);
    // 00423ac7  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00423ac9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00423aca:
    // 00423aca  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00423acc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00423ace  3c00                   +cmp al, 0
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
    // 00423ad0  7410                   -je 0x423ae2
    if (cpu.flags.zf)
    {
        goto L_0x00423ae2;
    }
    // 00423ad2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00423ad5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423ad8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00423adb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00423ade  3c00                   +cmp al, 0
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
    // 00423ae0  75e8                   -jne 0x423aca
    if (!cpu.flags.zf)
    {
        goto L_0x00423aca;
    }
L_0x00423ae2:
    // 00423ae2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00423ae3:
    // 00423ae3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00423ae6  41                     -inc ecx
    (cpu.ecx)++;
    // 00423ae7  81c5d4000000           -add ebp, 0xd4
    (cpu.ebp) += x86::reg32(x86::sreg32(212 /*0xd4*/));
    // 00423aed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423aef  7405                   -je 0x423af6
    if (cpu.flags.zf)
    {
        goto L_0x00423af6;
    }
    // 00423af1  83f90e                 +cmp ecx, 0xe
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
    // 00423af4  7ca8                   -jl 0x423a9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423a9e;
    }
L_0x00423af6:
    // 00423af6  a1744c4d00             -mov eax, dword ptr [0x4d4c74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */);
    // 00423afb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423afd  49                     -dec ecx
    (cpu.ecx)--;
    // 00423afe  891560894e00           -mov dword ptr [0x4e8960], edx
    app->getMemory<x86::reg32>(x86::reg32(5146976) /* 0x4e8960 */) = cpu.edx;
    // 00423b04  890d64894e00           -mov dword ptr [0x4e8964], ecx
    app->getMemory<x86::reg32>(x86::reg32(5146980) /* 0x4e8964 */) = cpu.ecx;
L_0x00423b0a:
    // 00423b0a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423b0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423b20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423b21  833d744c4d0000         +cmp dword ptr [0x4d4c74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423b28  743d                   -je 0x423b67
    if (cpu.flags.zf)
    {
        goto L_0x00423b67;
    }
    // 00423b2a  8b0d64894e00           -mov ecx, dword ptr [0x4e8964]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5146980) /* 0x4e8964 */);
    // 00423b30  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00423b32  7433                   -je 0x423b67
    if (cpu.flags.zf)
    {
        goto L_0x00423b67;
    }
    // 00423b34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423b35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423b36  8b1d60894e00           -mov ebx, dword ptr [0x4e8960]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5146976) /* 0x4e8960 */);
    // 00423b3c  43                     -inc ebx
    (cpu.ebx)++;
    // 00423b3d  891d60894e00           -mov dword ptr [0x4e8960], ebx
    app->getMemory<x86::reg32>(x86::reg32(5146976) /* 0x4e8960 */) = cpu.ebx;
    // 00423b43  39cb                   +cmp ebx, ecx
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
    // 00423b45  7c0a                   -jl 0x423b51
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00423b51;
    }
    // 00423b47  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423b48  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00423b4a  893d60894e00           -mov dword ptr [0x4e8960], edi
    app->getMemory<x86::reg32>(x86::reg32(5146976) /* 0x4e8960 */) = cpu.edi;
    // 00423b50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00423b51:
    // 00423b51  690560894e00d4000000   -imul eax, dword ptr [0x4e8960], 0xd4
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5146976) /* 0x4e8960 */))) * x86::sreg64(x86::sreg32(212 /*0xd4*/)));
    // 00423b5b  8b15744c4d00           -mov edx, dword ptr [0x4d4c74]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065844) /* 0x4d4c74 */);
    // 00423b61  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00423b63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423b67:
    // 00423b67  e8c4feffff             -call 0x423a30
    cpu.esp -= 4;
    sub_423a30(app, cpu);
    if (cpu.terminate) return;
    // 00423b6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423b6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_423b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423b70  a160894e00             -mov eax, dword ptr [0x4e8960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5146976) /* 0x4e8960 */);
    // 00423b75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423b80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423b92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423b93  bb804c4d00             -mov ebx, 0x4d4c80
    cpu.ebx = 5065856 /*0x4d4c80*/;
    // 00423b98  ba7c4c4d00             -mov edx, 0x4d4c7c
    cpu.edx = 5065852 /*0x4d4c7c*/;
    // 00423b9d  b8844c4d00             -mov eax, 0x4d4c84
    cpu.eax = 5065860 /*0x4d4c84*/;
    // 00423ba2  e8b9e4ffff             -call 0x422060
    cpu.esp -= 4;
    sub_422060(app, cpu);
    if (cpu.terminate) return;
    // 00423ba7  833df88a4e0000         +cmp dword ptr [0x4e8af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5147384) /* 0x4e8af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423bae  741c                   -je 0x423bcc
    if (cpu.flags.zf)
    {
        goto L_0x00423bcc;
    }
    // 00423bb0  8b0d7c4c4d00           -mov ecx, dword ptr [0x4d4c7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423bb6  3b0d008b4e00           +cmp ecx, dword ptr [0x4e8b00]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5147392) /* 0x4e8b00 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423bbc  7526                   -jne 0x423be4
    if (!cpu.flags.zf)
    {
        goto L_0x00423be4;
    }
    // 00423bbe  8b1d804c4d00           -mov ebx, dword ptr [0x4d4c80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423bc4  3b1d048b4e00           +cmp ebx, dword ptr [0x4e8b04]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5147396) /* 0x4e8b04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423bca  7518                   -jne 0x423be4
    if (!cpu.flags.zf)
    {
        goto L_0x00423be4;
    }
L_0x00423bcc:
    // 00423bcc  a17c4c4d00             -mov eax, dword ptr [0x4d4c7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423bd1  a3008b4e00             -mov dword ptr [0x4e8b00], eax
    app->getMemory<x86::reg32>(x86::reg32(5147392) /* 0x4e8b00 */) = cpu.eax;
    // 00423bd6  a1804c4d00             -mov eax, dword ptr [0x4d4c80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423bdb  a3048b4e00             -mov dword ptr [0x4e8b04], eax
    app->getMemory<x86::reg32>(x86::reg32(5147396) /* 0x4e8b04 */) = cpu.eax;
    // 00423be0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423be1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423be2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423be3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423be4:
    // 00423be4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00423be6  ff1544375600           -call dword ptr [0x563744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650244) /* 0x563744 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423bec  ff1578375600           -call dword ptr [0x563778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650296) /* 0x563778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423bf2  a1244d4d00             -mov eax, dword ptr [0x4d4d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */);
    // 00423bf7  e8ace90500             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 00423bfc  a1244d4d00             -mov eax, dword ptr [0x4d4d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5066020) /* 0x4d4d24 */);
    // 00423c01  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00423c04  e8672f0000             -call 0x426b70
    cpu.esp -= 4;
    sub_426b70(app, cpu);
    if (cpu.terminate) return;
    // 00423c09  a17c4c4d00             -mov eax, dword ptr [0x4d4c7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423c0e  8b15804c4d00           -mov edx, dword ptr [0x4d4c80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423c14  83e807                 +sub eax, 7
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00423c17  e8a42b0000             -call 0x4267c0
    cpu.esp -= 4;
    sub_4267c0(app, cpu);
    if (cpu.terminate) return;
    // 00423c1c  ff155c375600           -call dword ptr [0x56375c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650268) /* 0x56375c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423c22  ff154c375600           -call dword ptr [0x56374c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5650252) /* 0x56374c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00423c28  eba2                   -jmp 0x423bcc
    goto L_0x00423bcc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423c30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423c42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423c43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423c44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423c45  8b15784c4d00           -mov edx, dword ptr [0x4d4c78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065848) /* 0x4d4c78 */);
    // 00423c4b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00423c4d  752b                   -jne 0x423c7a
    if (!cpu.flags.zf)
    {
        goto L_0x00423c7a;
    }
L_0x00423c4f:
    // 00423c4f  8b1df88a4e00           -mov ebx, dword ptr [0x4e8af8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5147384) /* 0x4e8af8 */);
    // 00423c55  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00423c57  7411                   -je 0x423c6a
    if (cpu.flags.zf)
    {
        goto L_0x00423c6a;
    }
    // 00423c59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423c5a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423c5c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00423c5e  e83df10500             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
    // 00423c63  8935f88a4e00           -mov dword ptr [0x4e8af8], esi
    app->getMemory<x86::reg32>(x86::reg32(5147384) /* 0x4e8af8 */) = cpu.esi;
    // 00423c69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00423c6a:
    // 00423c6a  8b3dfc8a4e00           -mov edi, dword ptr [0x4e8afc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5147388) /* 0x4e8afc */);
    // 00423c70  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00423c72  7517                   -jne 0x423c8b
    if (!cpu.flags.zf)
    {
        goto L_0x00423c8b;
    }
    // 00423c74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423c7a:
    // 00423c7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00423c7c  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00423c7e  e8790c0600             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00423c83  890d784c4d00           -mov dword ptr [0x4d4c78], ecx
    app->getMemory<x86::reg32>(x86::reg32(5065848) /* 0x4d4c78 */) = cpu.ecx;
    // 00423c89  ebc4                   -jmp 0x423c4f
    goto L_0x00423c4f;
L_0x00423c8b:
    // 00423c8b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00423c8d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00423c8f  e80cf10500             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
    // 00423c94  892dfc8a4e00           -mov dword ptr [0x4e8afc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5147388) /* 0x4e8afc */) = cpu.ebp;
    // 00423c9a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423c9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423ca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423ca2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423ca3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423ca4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423ca5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423ca6  8b1d7c4c4d00           -mov ebx, dword ptr [0x4d4c7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423cac  8b35804c4d00           -mov esi, dword ptr [0x4d4c80]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423cb2  668b3d068c4e00         -mov di, word ptr [0x4e8c06]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */);
    // 00423cb9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00423cbb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00423cbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00423cbf:
    // 00423cbf  0fbfd7                 -movsx edx, di
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.di));
    // 00423cc2  39d1                   +cmp ecx, edx
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
    // 00423cc4  0f8daf000000           -jge 0x423d79
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423d79;
    }
    // 00423cca  8b90a68a4e00           -mov edx, dword ptr [eax + 0x4e8aa6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5147302) /* 0x4e8aa6 */);
    // 00423cd0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00423cd3  39d6                   +cmp esi, edx
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
    // 00423cd5  7f06                   -jg 0x423cdd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00423cdd;
    }
L_0x00423cd7:
    // 00423cd7  41                     -inc ecx
    (cpu.ecx)++;
    // 00423cd8  83c002                 +add eax, 2
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
    // 00423cdb  ebe2                   -jmp 0x423cbf
    goto L_0x00423cbf;
L_0x00423cdd:
    // 00423cdd  8b9066894e00           -mov edx, dword ptr [eax + 0x4e8966]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5146982) /* 0x4e8966 */);
    // 00423ce3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00423ce6  39d6                   +cmp esi, edx
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
    // 00423ce8  7ded                   -jge 0x423cd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423cd7;
    }
    // 00423cea  8b90568a4e00           -mov edx, dword ptr [eax + 0x4e8a56]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5147222) /* 0x4e8a56 */);
    // 00423cf0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00423cf3  39d3                   +cmp ebx, edx
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
    // 00423cf5  7ee0                   -jle 0x423cd7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423cd7;
    }
    // 00423cf7  8b90068a4e00           -mov edx, dword ptr [eax + 0x4e8a06]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5147142) /* 0x4e8a06 */);
    // 00423cfd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00423d00  39d3                   +cmp ebx, edx
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
    // 00423d02  7dd3                   -jge 0x423cd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423cd7;
    }
    // 00423d04  891d7c4c4d00           -mov dword ptr [0x4d4c7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */) = cpu.ebx;
    // 00423d0a  8935804c4d00           -mov dword ptr [0x4d4c80], esi
    app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */) = cpu.esi;
    // 00423d10  66893d068c4e00         -mov word ptr [0x4e8c06], di
    app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */) = cpu.di;
    // 00423d17  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00423d1a  8b80b6894e00           -mov eax, dword ptr [eax + 0x4e89b6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5147062) /* 0x4e89b6 */);
    // 00423d20  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00423d23  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00423d26  39d0                   +cmp eax, edx
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
    // 00423d28  740f                   -je 0x423d39
    if (cpu.flags.zf)
    {
        goto L_0x00423d39;
    }
    // 00423d2a  8b44850c               -mov eax, dword ptr [ebp + eax*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 00423d2e  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423d31  7517                   -jne 0x423d4a
    if (!cpu.flags.zf)
    {
        goto L_0x00423d4a;
    }
    // 00423d33  f6400801               +test byte ptr [eax + 8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 1 /*0x1*/));
    // 00423d37  7411                   -je 0x423d4a
    if (cpu.flags.zf)
    {
        goto L_0x00423d4a;
    }
L_0x00423d39:
    // 00423d39  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423d3b  8b1d7c4c4d00           -mov ebx, dword ptr [0x4d4c7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423d41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423d43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423d4a:
    // 00423d4a  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 00423d4f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423d54  e897e60100             -call 0x4423f0
    cpu.esp -= 4;
    sub_4423f0(app, cpu);
    if (cpu.terminate) return;
    // 00423d59  668b044db8894e00       -mov ax, word ptr [ecx*2 + 0x4e89b8]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5147064) /* 0x4e89b8 */ + cpu.ecx * 2);
    // 00423d61  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00423d66  6689450a               -mov word ptr [ebp + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00423d6a  8b1d7c4c4d00           -mov ebx, dword ptr [0x4d4c7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423d70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423d72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423d78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423d79:
    // 00423d79  66837d0a64             +cmp word ptr [ebp + 0xa], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00423d7e  7411                   -je 0x423d91
    if (cpu.flags.zf)
    {
        goto L_0x00423d91;
    }
    // 00423d80  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00423d83  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00423d86  66c7450a6400           -mov word ptr [ebp + 0xa], 0x64
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */) = 100 /*0x64*/;
    // 00423d8c  a3088b4e00             -mov dword ptr [0x4e8b08], eax
    app->getMemory<x86::reg32>(x86::reg32(5147400) /* 0x4e8b08 */) = cpu.eax;
L_0x00423d91:
    // 00423d91  891d7c4c4d00           -mov dword ptr [0x4d4c7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */) = cpu.ebx;
    // 00423d97  8935804c4d00           -mov dword ptr [0x4d4c80], esi
    app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */) = cpu.esi;
    // 00423d9d  66893d068c4e00         -mov word ptr [0x4e8c06], di
    app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */) = cpu.di;
    // 00423da4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00423da6  8b1d7c4c4d00           -mov ebx, dword ptr [0x4d4c7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423dac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00423dae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423daf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423db0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423db1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423db2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423db3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423db4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423dc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423dc1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423dc2  8b35804c4d00           -mov esi, dword ptr [0x4d4c80]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423dc8  39f2                   +cmp edx, esi
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
    // 00423dca  7d1e                   -jge 0x423dea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423dea;
    }
    // 00423dcc  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00423dce  39f2                   +cmp edx, esi
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
    // 00423dd0  7e18                   -jle 0x423dea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423dea;
    }
    // 00423dd2  8b2d7c4c4d00           -mov ebp, dword ptr [0x4d4c7c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423dd8  39e8                   +cmp eax, ebp
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
    // 00423dda  7d0e                   -jge 0x423dea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423dea;
    }
    // 00423ddc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00423dde  39e8                   +cmp eax, ebp
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
    // 00423de0  7e08                   -jle 0x423dea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423dea;
    }
    // 00423de2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00423de7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423de8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423de9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423dea:
    // 00423dea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00423dec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423ded  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423dee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_423df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423df1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00423df3  8b15804c4d00           -mov edx, dword ptr [0x4d4c80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423df9  39d0                   +cmp eax, edx
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
    // 00423dfb  7e07                   -jle 0x423e04
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00423e04;
    }
    // 00423dfd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00423e02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423e04:
    // 00423e04  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00423e06  4a                     -dec edx
    (cpu.edx)--;
    // 00423e07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00423e09  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00423e0c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00423e0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_423e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423e10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423e11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423e12  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00423e15  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00423e18  8b54900c               -mov edx, dword ptr [eax + edx*4 + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 00423e1c  803a02                 +cmp byte ptr [edx], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423e1f  7413                   -je 0x423e34
    if (cpu.flags.zf)
    {
        goto L_0x00423e34;
    }
L_0x00423e21:
    // 00423e21  8b15804c4d00           -mov edx, dword ptr [0x4d4c80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423e27  a17c4c4d00             -mov eax, dword ptr [0x4d4c7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423e2c  e8bfe4ffff             -call 0x4222f0
    cpu.esp -= 4;
    sub_4222f0(app, cpu);
    if (cpu.terminate) return;
    // 00423e31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423e34:
    // 00423e34  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423e36  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00423e39  e83278ffff             -call 0x41b670
    cpu.esp -= 4;
    sub_41b670(app, cpu);
    if (cpu.terminate) return;
    // 00423e3e  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00423e41  a37c4c4d00             -mov dword ptr [0x4d4c7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */) = cpu.eax;
    // 00423e46  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00423e48  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00423e4b  e80078ffff             -call 0x41b650
    cpu.esp -= 4;
    sub_41b650(app, cpu);
    if (cpu.terminate) return;
    // 00423e50  83c00d                 -add eax, 0xd
    (cpu.eax) += x86::reg32(x86::sreg32(13 /*0xd*/));
    // 00423e53  8a5a09                 -mov bl, byte ptr [edx + 9]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 00423e56  a3804c4d00             -mov dword ptr [0x4d4c80], eax
    app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */) = cpu.eax;
    // 00423e5b  80fb0d                 +cmp bl, 0xd
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423e5e  7513                   -jne 0x423e73
    if (!cpu.flags.zf)
    {
        goto L_0x00423e73;
    }
    // 00423e60  803da82d510000         +cmp byte ptr [0x512da8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5320104) /* 0x512da8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00423e67  740a                   -je 0x423e73
    if (cpu.flags.zf)
    {
        goto L_0x00423e73;
    }
    // 00423e69  81057c4c4d009f000000   -add dword ptr [0x4d4c7c], 0x9f
    (app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */)) += x86::reg32(x86::sreg32(159 /*0x9f*/));
L_0x00423e73:
    // 00423e73  f6420810               +test byte ptr [edx + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00423e77  74a8                   -je 0x423e21
    if (cpu.flags.zf)
    {
        goto L_0x00423e21;
    }
    // 00423e79  83057c4c4d002e         -add dword ptr [0x4d4c7c], 0x2e
    (app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */)) += x86::reg32(x86::sreg32(46 /*0x2e*/));
    // 00423e80  8b15804c4d00           -mov edx, dword ptr [0x4d4c80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5065856) /* 0x4d4c80 */);
    // 00423e86  a17c4c4d00             -mov eax, dword ptr [0x4d4c7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065852) /* 0x4d4c7c */);
    // 00423e8b  e860e4ffff             -call 0x4222f0
    cpu.esp -= 4;
    sub_4222f0(app, cpu);
    if (cpu.terminate) return;
    // 00423e90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423e92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_423ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00423ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00423ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00423ea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00423ea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00423ea5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00423ea6  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00423eac  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00423eae  833d784c4d0000         +cmp dword ptr [0x4d4c78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5065848) /* 0x4d4c78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423eb5  0f84d7000000           -je 0x423f92
    if (cpu.flags.zf)
    {
        goto L_0x00423f92;
    }
L_0x00423ebb:
    // 00423ebb  bae49b4c00             -mov edx, 0x4c9be4
    cpu.edx = 5020644 /*0x4c9be4*/;
    // 00423ec0  a1784c4d00             -mov eax, dword ptr [0x4d4c78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5065848) /* 0x4d4c78 */);
    // 00423ec5  e8eaef0500             -call 0x482eb4
    cpu.esp -= 4;
    sub_482eb4(app, cpu);
    if (cpu.terminate) return;
    // 00423eca  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00423ecc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423ece  e8bd290000             -call 0x426890
    cpu.esp -= 4;
    sub_426890(app, cpu);
    if (cpu.terminate) return;
    // 00423ed3  8b1df88a4e00           -mov ebx, dword ptr [0x4e8af8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5147384) /* 0x4e8af8 */);
    // 00423ed9  8b7902                 -mov edi, dword ptr [ecx + 2]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00423edc  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00423edf  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00423ee2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00423ee5  47                     -inc edi
    (cpu.edi)++;
    // 00423ee6  41                     -inc ecx
    (cpu.ecx)++;
    // 00423ee7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00423ee9  7407                   -je 0x423ef2
    if (cpu.flags.zf)
    {
        goto L_0x00423ef2;
    }
    // 00423eeb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00423eed  e8aeee0500             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
L_0x00423ef2:
    // 00423ef2  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 00423ef5  8d470a                 -lea eax, [edi + 0xa]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00423ef8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00423efa  e875e50500             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00423eff  8b35fc8a4e00           -mov esi, dword ptr [0x4e8afc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5147388) /* 0x4e8afc */);
    // 00423f05  a3f88a4e00             -mov dword ptr [0x4e8af8], eax
    app->getMemory<x86::reg32>(x86::reg32(5147384) /* 0x4e8af8 */) = cpu.eax;
    // 00423f0a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00423f0c  7407                   -je 0x423f15
    if (cpu.flags.zf)
    {
        goto L_0x00423f15;
    }
    // 00423f0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00423f10  e88bee0500             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
L_0x00423f15:
    // 00423f15  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 00423f18  8d470a                 -lea eax, [edi + 0xa]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00423f1b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00423f1d  e852e50500             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00423f22  a3fc8a4e00             -mov dword ptr [0x4e8afc], eax
    app->getMemory<x86::reg32>(x86::reg32(5147388) /* 0x4e8afc */) = cpu.eax;
    // 00423f27  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00423f29  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00423f2b  a1f88a4e00             -mov eax, dword ptr [0x4e8af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147384) /* 0x4e8af8 */);
    // 00423f30  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00423f32  e871e60500             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 00423f37  89bc2400010000         -mov dword ptr [esp + 0x100], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edi;
    // 00423f3e  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00423f41  668915068c4e00         -mov word ptr [0x4e8c06], dx
    app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */) = cpu.dx;
    // 00423f48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00423f4a  7422                   -je 0x423f6e
    if (cpu.flags.zf)
    {
        goto L_0x00423f6e;
    }
L_0x00423f4c:
    // 00423f4c  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00423f4f  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00423f51  3c01                   +cmp al, 1
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
    // 00423f53  736f                   -jae 0x423fc4
    if (!cpu.flags.cf)
    {
        goto L_0x00423fc4;
    }
L_0x00423f55:
    // 00423f55  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00423f5c  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00423f5f  42                     -inc edx
    (cpu.edx)++;
    // 00423f60  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423f63  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 00423f6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00423f6c  75de                   -jne 0x423f4c
    if (!cpu.flags.zf)
    {
        goto L_0x00423f4c;
    }
L_0x00423f6e:
    // 00423f6e  e849e50500             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 00423f73  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00423f75  bfe0424200             -mov edi, 0x4242e0
    cpu.edi = 4342496 /*0x4242e0*/;
    // 00423f7a  e891feffff             -call 0x423e10
    cpu.esp -= 4;
    sub_423e10(app, cpu);
    if (cpu.terminate) return;
    // 00423f7f  893d4cac4d00           -mov dword ptr [0x4dac4c], edi
    app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */) = cpu.edi;
    // 00423f85  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00423f8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00423f91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00423f92:
    // 00423f92  8b0db4345100           -mov ecx, dword ptr [0x5134b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5321908) /* 0x5134b4 */);
    // 00423f98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00423f99  68d89b4c00             -push 0x4c9bd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5020632 /*0x4c9bd8*/;
    cpu.esp -= 4;
    // 00423f9e  680c8b4e00             -push 0x4e8b0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5147404 /*0x4e8b0c*/;
    cpu.esp -= 4;
    // 00423fa3  e859250600             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00423fa8  83c40c                 +add esp, 0xc
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
    // 00423fab  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00423fb0  b80c8b4e00             -mov eax, 0x4e8b0c
    cpu.eax = 5147404 /*0x4e8b0c*/;
    // 00423fb5  e8862f0600             -call 0x486f40
    cpu.esp -= 4;
    sub_486f40(app, cpu);
    if (cpu.terminate) return;
    // 00423fba  a3784c4d00             -mov dword ptr [0x4d4c78], eax
    app->getMemory<x86::reg32>(x86::reg32(5065848) /* 0x4d4c78 */) = cpu.eax;
    // 00423fbf  e9f7feffff             -jmp 0x423ebb
    goto L_0x00423ebb;
L_0x00423fc4:
    // 00423fc4  0f87a8000000           -ja 0x424072
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00424072;
    }
    // 00423fca  f6420201               +test byte ptr [edx + 2], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) & 1 /*0x1*/));
    // 00423fce  7585                   -jne 0x423f55
    if (!cpu.flags.zf)
    {
        goto L_0x00423f55;
    }
    // 00423fd0  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 00423fd5  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00423fdc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00423fdf  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00423fe2  66890c45b8894e00       -mov word ptr [eax*2 + 0x4e89b8], cx
    app->getMemory<x86::reg16>(x86::reg32(5147064) /* 0x4e89b8 */ + cpu.eax * 2) = cpu.cx;
    // 00423fea  a1b8404d00             -mov eax, dword ptr [0x4d40b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5062840) /* 0x4d40b8 */);
    // 00423fef  e8c0ee0500             -call 0x482eb4
    cpu.esp -= 4;
    sub_482eb4(app, cpu);
    if (cpu.terminate) return;
    // 00423ff4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00423ff6  81fdfc3c4d00           +cmp ebp, 0x4d3cfc
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5061884 /*0x4d3cfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00423ffc  0f852e020000           -jne 0x424230
    if (!cpu.flags.zf)
    {
        goto L_0x00424230;
    }
    // 00424002  e80962ffff             -call 0x41a210
    cpu.esp -= 4;
    sub_41a210(app, cpu);
    if (cpu.terminate) return;
L_0x00424007:
    // 00424007  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0042400a  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0042400d  0fbff8                 -movsx edi, ax
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00424010  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00424013  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00424015  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00424017  8b15048c4e00           -mov edx, dword ptr [0x4e8c04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 0042401d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00424020  66893455a88a4e00       -mov word ptr [edx*2 + 0x4e8aa8], si
    app->getMemory<x86::reg16>(x86::reg32(5147304) /* 0x4e8aa8 */ + cpu.edx * 2) = cpu.si;
    // 00424028  66037106               -add si, word ptr [ecx + 6]
    (cpu.si) += x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */)));
    // 0042402c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0042402e  6689045568894e00       -mov word ptr [edx*2 + 0x4e8968], ax
    app->getMemory<x86::reg16>(x86::reg32(5146984) /* 0x4e8968 */ + cpu.edx * 2) = cpu.ax;
    // 00424036  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00424039  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 0042403c  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 0042403f  66890455588a4e00       -mov word ptr [edx*2 + 0x4e8a58], ax
    app->getMemory<x86::reg16>(x86::reg32(5147224) /* 0x4e8a58 */ + cpu.edx * 2) = cpu.ax;
    // 00424047  66034104               -add ax, word ptr [ecx + 4]
    (cpu.ax) += x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0042404b  668b3d068c4e00         -mov di, word ptr [0x4e8c06]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */);
    // 00424052  66890455088a4e00       -mov word ptr [edx*2 + 0x4e8a08], ax
    app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.edx * 2) = cpu.ax;
    // 0042405a  6683ff28               +cmp di, 0x28
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(40 /*0x28*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0042405e  0f8df1feffff           -jge 0x423f55
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423f55;
    }
    // 00424064  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00424066  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00424067  66a3068c4e00           -mov word ptr [0x4e8c06], ax
    app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */) = cpu.ax;
    // 0042406d  e9e3feffff             -jmp 0x423f55
    goto L_0x00423f55;
L_0x00424072:
    // 00424072  3c02                   +cmp al, 2
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
    // 00424074  0f85dbfeffff           -jne 0x423f55
    if (!cpu.flags.zf)
    {
        goto L_0x00423f55;
    }
    // 0042407a  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 0042407f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424082  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00424089  66890c45b8894e00       -mov word ptr [eax*2 + 0x4e89b8], cx
    app->getMemory<x86::reg16>(x86::reg32(5147064) /* 0x4e89b8 */ + cpu.eax * 2) = cpu.cx;
    // 00424091  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00424093  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424096  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00424098  e87376ffff             -call 0x41b710
    cpu.esp -= 4;
    sub_41b710(app, cpu);
    if (cpu.terminate) return;
    // 0042409d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0042409f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004240a0:
    // 004240a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004240a2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004240a4  3c00                   +cmp al, 0
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
    // 004240a6  7410                   -je 0x4240b8
    if (cpu.flags.zf)
    {
        goto L_0x004240b8;
    }
    // 004240a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004240ab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004240ae  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004240b1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004240b4  3c00                   +cmp al, 0
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
    // 004240b6  75e8                   -jne 0x4240a0
    if (!cpu.flags.zf)
    {
        goto L_0x004240a0;
    }
L_0x004240b8:
    // 004240b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004240b9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004240bb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004240be  e88d75ffff             -call 0x41b650
    cpu.esp -= 4;
    sub_41b650(app, cpu);
    if (cpu.terminate) return;
    // 004240c3  8b0d048c4e00           -mov ecx, dword ptr [0x4e8c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 004240c9  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004240cc  6689044da88a4e00       -mov word ptr [ecx*2 + 0x4e8aa8], ax
    app->getMemory<x86::reg16>(x86::reg32(5147304) /* 0x4e8aa8 */ + cpu.ecx * 2) = cpu.ax;
    // 004240d4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004240d6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004240d9  e81276ffff             -call 0x41b6f0
    cpu.esp -= 4;
    sub_41b6f0(app, cpu);
    if (cpu.terminate) return;
    // 004240de  668b344da88a4e00       -mov si, word ptr [ecx*2 + 0x4e8aa8]
    cpu.si = app->getMemory<x86::reg16>(x86::reg32(5147304) /* 0x4e8aa8 */ + cpu.ecx * 2);
    // 004240e6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004240e8  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 004240ed  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004240ef  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004240f2  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004240f5  66890c4568894e00       -mov word ptr [eax*2 + 0x4e8968], cx
    app->getMemory<x86::reg16>(x86::reg32(5146984) /* 0x4e8968 */ + cpu.eax * 2) = cpu.cx;
    // 004240fd  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004240ff  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424102  e8e975ffff             -call 0x41b6f0
    cpu.esp -= 4;
    sub_41b6f0(app, cpu);
    if (cpu.terminate) return;
    // 00424107  e8e415feff             -call 0x4056f0
    cpu.esp -= 4;
    sub_4056f0(app, cpu);
    if (cpu.terminate) return;
    // 0042410c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0042410e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424111  e87a75ffff             -call 0x41b690
    cpu.esp -= 4;
    sub_41b690(app, cpu);
    if (cpu.terminate) return;
    // 00424116  83f801                 +cmp eax, 1
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
    // 00424119  0f85c7000000           -jne 0x4241e6
    if (!cpu.flags.zf)
    {
        goto L_0x004241e6;
    }
L_0x0042411f:
    // 0042411f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00424121  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424124  e84775ffff             -call 0x41b670
    cpu.esp -= 4;
    sub_41b670(app, cpu);
    if (cpu.terminate) return;
    // 00424129  8b0d048c4e00           -mov ecx, dword ptr [0x4e8c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 0042412f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00424132  050c000000             -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00424137  6689044d088a4e00       -mov word ptr [ecx*2 + 0x4e8a08], ax
    app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.ecx * 2) = cpu.ax;
    // 0042413f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00424141  e8dee20500             -call 0x482424
    cpu.esp -= 4;
    sub_482424(app, cpu);
    if (cpu.terminate) return;
    // 00424146  668b0c4d088a4e00       -mov cx, word ptr [ecx*2 + 0x4e8a08]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.ecx * 2);
    // 0042414e  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00424150  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 00424155  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424158  83e90c                 -sub ecx, 0xc
    (cpu.ecx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0042415b  66890c45588a4e00       -mov word ptr [eax*2 + 0x4e8a58], cx
    app->getMemory<x86::reg16>(x86::reg32(5147224) /* 0x4e8a58 */ + cpu.eax * 2) = cpu.cx;
L_0x00424163:
    // 00424163  807a0912               +cmp byte ptr [edx + 9], 0x12
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(18 /*0x12*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00424167  7512                   -jne 0x42417b
    if (!cpu.flags.zf)
    {
        goto L_0x0042417b;
    }
    // 00424169  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 0042416e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424171  66810445088a4e002c01   -add word ptr [eax*2 + 0x4e8a08], 0x12c
    (app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(300 /*0x12c*/));
L_0x0042417b:
    // 0042417b  807a090d               +cmp byte ptr [edx + 9], 0xd
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0042417f  7512                   -jne 0x424193
    if (!cpu.flags.zf)
    {
        goto L_0x00424193;
    }
    // 00424181  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 00424186  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00424189  66810445088a4e00f000   -add word ptr [eax*2 + 0x4e8a08], 0xf0
    (app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(240 /*0xf0*/));
L_0x00424193:
    // 00424193  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00424197  7417                   -je 0x4241b0
    if (cpu.flags.zf)
    {
        goto L_0x004241b0;
    }
    // 00424199  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 0042419d  7511                   -jne 0x4241b0
    if (!cpu.flags.zf)
    {
        goto L_0x004241b0;
    }
    // 0042419f  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 004241a4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004241a7  66830445088a4e0078     -add word ptr [eax*2 + 0x4e8a08], 0x78
    (app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(120 /*0x78*/));
L_0x004241b0:
    // 004241b0  807a0905               +cmp byte ptr [edx + 9], 5
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004241b4  7511                   -jne 0x4241c7
    if (!cpu.flags.zf)
    {
        goto L_0x004241c7;
    }
    // 004241b6  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 004241bb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004241be  66830445088a4e006e     -add word ptr [eax*2 + 0x4e8a08], 0x6e
    (app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.eax * 2)) += x86::reg16(x86::sreg16(110 /*0x6e*/));
L_0x004241c7:
    // 004241c7  66a1068c4e00           -mov ax, word ptr [0x4e8c06]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */);
    // 004241cd  663d2800               +cmp ax, 0x28
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(40 /*0x28*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004241d1  0f8d7efdffff           -jge 0x423f55
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00423f55;
    }
    // 004241d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004241d9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004241da  668915068c4e00         -mov word ptr [0x4e8c06], dx
    app->getMemory<x86::reg16>(x86::reg32(5147654) /* 0x4e8c06 */) = cpu.dx;
    // 004241e1  e96ffdffff             -jmp 0x423f55
    goto L_0x00423f55;
L_0x004241e6:
    // 004241e6  83f804                 +cmp eax, 4
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
    // 004241e9  0f8430ffffff           -je 0x42411f
    if (cpu.flags.zf)
    {
        goto L_0x0042411f;
    }
    // 004241ef  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004241f1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004241f4  e87774ffff             -call 0x41b670
    cpu.esp -= 4;
    sub_41b670(app, cpu);
    if (cpu.terminate) return;
    // 004241f9  8b0d048c4e00           -mov ecx, dword ptr [0x4e8c04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 004241ff  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00424202  6689044d588a4e00       -mov word ptr [ecx*2 + 0x4e8a58], ax
    app->getMemory<x86::reg16>(x86::reg32(5147224) /* 0x4e8a58 */ + cpu.ecx * 2) = cpu.ax;
    // 0042420a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0042420c  e813e20500             -call 0x482424
    cpu.esp -= 4;
    sub_482424(app, cpu);
    if (cpu.terminate) return;
    // 00424211  668b0c4d588a4e00       -mov cx, word ptr [ecx*2 + 0x4e8a58]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5147224) /* 0x4e8a58 */ + cpu.ecx * 2);
    // 00424219  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0042421b  a1048c4e00             -mov eax, dword ptr [0x4e8c04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5147652) /* 0x4e8c04 */);
    // 00424220  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00424223  66890c45088a4e00       -mov word ptr [eax*2 + 0x4e8a08], cx
    app->getMemory<x86::reg16>(x86::reg32(5147144) /* 0x4e8a08 */ + cpu.eax * 2) = cpu.cx;
    // 0042422b  e933ffffff             -jmp 0x424163
    goto L_0x00424163;
L_0x00424230:
    // 00424230  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00424232  e9d0fdffff             -jmp 0x424007
    goto L_0x00424007;
}

}
