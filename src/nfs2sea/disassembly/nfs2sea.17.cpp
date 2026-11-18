#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483961  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00483963:
    // 00483963  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483966  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483968  89907c375600           -mov dword ptr [eax + 0x56377c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650300) /* 0x56377c */) = cpu.edx;
    // 0048396e  83f820                 +cmp eax, 0x20
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
    // 00483971  75f0                   -jne 0x483963
    if (!cpu.flags.zf)
    {
        goto L_0x00483963;
    }
    // 00483973  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483974  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483978  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483979  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048397a  a1a0375600             -mov eax, dword ptr [0x5637a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650336) /* 0x5637a0 */);
    // 0048397f  8b15c8375600           -mov edx, dword ptr [0x5637c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650376) /* 0x5637c8 */);
    // 00483985  8b0da8375600           -mov ecx, dword ptr [0x5637a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5650344) /* 0x5637a8 */);
    // 0048398b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048398d  8b1dd0375600           -mov ebx, dword ptr [0x5637d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */);
    // 00483993  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483995  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00483998  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048399e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004839a0  8915c8375600           -mov dword ptr [0x5637c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5650376) /* 0x5637c8 */) = cpu.edx;
    // 004839a6  890da8375600           -mov dword ptr [0x5637a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5650344) /* 0x5637a8 */) = cpu.ecx;
    // 004839ac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004839ae  753f                   -jne 0x4839ef
    if (!cpu.flags.zf)
    {
        goto L_0x004839ef;
    }
L_0x004839b0:
    // 004839b0  8b0dcc375600           -mov ecx, dword ptr [0x5637cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5650380) /* 0x5637cc */);
    // 004839b6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004839b8  740c                   -je 0x4839c6
    if (cpu.flags.zf)
    {
        goto L_0x004839c6;
    }
    // 004839ba  b8b0375600             -mov eax, 0x5637b0
    cpu.eax = 5650352 /*0x5637b0*/;
    // 004839bf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004839c1  e85a640000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
L_0x004839c6:
    // 004839c6  8b1dd8375600           -mov ebx, dword ptr [0x5637d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */);
    // 004839cc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004839ce  7415                   -je 0x4839e5
    if (cpu.flags.zf)
    {
        goto L_0x004839e5;
    }
    // 004839d0  833db0b14d0000         +cmp dword ptr [0x4db1b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004839d7  750c                   -jne 0x4839e5
    if (!cpu.flags.zf)
    {
        goto L_0x004839e5;
    }
    // 004839d9  b8dc375600             -mov eax, 0x5637dc
    cpu.eax = 5650396 /*0x5637dc*/;
    // 004839de  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004839e0  e83b640000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
L_0x004839e5:
    // 004839e5  e826060200             -call 0x4a4010
    cpu.esp -= 4;
    sub_4a4010(app, cpu);
    if (cpu.terminate) return;
    // 004839ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004839eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004839ec  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x004839ef:
    // 004839ef  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004839f6  8b15a8375600           -mov edx, dword ptr [0x5637a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650344) /* 0x5637a8 */);
    // 004839fc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004839fe  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00483a01  83f801                 +cmp eax, 1
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
    // 00483a04  7d28                   -jge 0x483a2e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483a2e;
    }
    // 00483a06  3d18fcffff             +cmp eax, 0xfffffc18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966296 /*0xfffffc18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a0b  7d1c                   -jge 0x483a29
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483a29;
    }
    // 00483a0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483a0e  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483a15  8b35bcb14d00           -mov esi, dword ptr [0x4db1bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091772) /* 0x4db1bc */);
    // 00483a1b  40                     -inc eax
    (cpu.eax)++;
    // 00483a1c  46                     -inc esi
    (cpu.esi)++;
    // 00483a1d  a3a8375600             -mov dword ptr [0x5637a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5650344) /* 0x5637a8 */) = cpu.eax;
    // 00483a22  8935bcb14d00           -mov dword ptr [0x4db1bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091772) /* 0x4db1bc */) = cpu.esi;
    // 00483a28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483a29:
    // 00483a29  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00483a2e:
    // 00483a2e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483a30  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483a32  6878394800             -push 0x483978
    app->getMemory<x86::reg32>(cpu.esp-4) = 4733304 /*0x483978*/;
    cpu.esp -= 4;
    // 00483a37  8b3da4375600           -mov edi, dword ptr [0x5637a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5650340) /* 0x5637a4 */);
    // 00483a3d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483a3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483a3f  2eff1500664c00         -call dword ptr cs:[0x4c6600]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006848) /* 0x4c6600 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483a46  a3c4375600             -mov dword ptr [0x5637c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5650372) /* 0x5637c4 */) = cpu.eax;
    // 00483a4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483a4d  0f855dffffff           -jne 0x4839b0
    if (!cpu.flags.zf)
    {
        goto L_0x004839b0;
    }
    // 00483a53  8b15a4375600           -mov edx, dword ptr [0x5637a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650340) /* 0x5637a4 */);
    // 00483a59  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483a5a  a3ccab4d00             -mov dword ptr [0x4dabcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.eax;
    // 00483a5f  a3d0375600             -mov dword ptr [0x5637d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */) = cpu.eax;
    // 00483a64  2eff15f4654c00         -call dword ptr cs:[0x4c65f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006836) /* 0x4c65f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483a6b  e940ffffff             -jmp 0x4839b0
    goto L_0x004839b0;
}

/* align: skip  */
void Application::sub_483a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483a70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483a72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483a73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483a74  8b35b0b14d00           -mov esi, dword ptr [0x4db1b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */);
    // 00483a7a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483a7c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00483a81  46                     -inc esi
    (cpu.esi)++;
    // 00483a82  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483a84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00483a86:
    // 00483a86  83b88037560000         +cmp dword ptr [eax + 0x563780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a8d  7504                   -jne 0x483a93
    if (!cpu.flags.zf)
    {
        goto L_0x00483a93;
    }
    // 00483a8f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483a91  7c29                   -jl 0x483abc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483abc;
    }
L_0x00483a93:
    // 00483a93  3b9880375600           +cmp ebx, dword ptr [eax + 0x563780]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a99  7415                   -je 0x483ab0
    if (cpu.flags.zf)
    {
        goto L_0x00483ab0;
    }
L_0x00483a9b:
    // 00483a9b  42                     -inc edx
    (cpu.edx)++;
    // 00483a9c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483a9f  83fa08                 +cmp edx, 8
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
    // 00483aa2  7ce2                   -jl 0x483a86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483a86;
    }
    // 00483aa4  83f9ff                 +cmp ecx, -1
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
    // 00483aa7  7407                   -je 0x483ab0
    if (cpu.flags.zf)
    {
        goto L_0x00483ab0;
    }
    // 00483aa9  891c8d80375600         -mov dword ptr [ecx*4 + 0x563780], ebx
    app->getMemory<x86::reg32>(x86::reg32(5650304) /* 0x563780 */ + cpu.ecx * 4) = cpu.ebx;
L_0x00483ab0:
    // 00483ab0  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483ab1  8935b0b14d00           -mov dword ptr [0x4db1b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */) = cpu.esi;
    // 00483ab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ab8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ab9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483aba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483abb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483abc:
    // 00483abc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00483abe  ebdb                   -jmp 0x483a9b
    goto L_0x00483a9b;
}

/* align: skip  */
void Application::sub_483ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483ac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483ac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483ac4  8b1db0b14d00           -mov ebx, dword ptr [0x4db1b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */);
    // 00483aca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483acc  8b3580375600           -mov esi, dword ptr [0x563780]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5650304) /* 0x563780 */);
    // 00483ad2  43                     -inc ebx
    (cpu.ebx)++;
    // 00483ad3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483ad5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483ad7  39f1                   +cmp ecx, esi
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
    // 00483ad9  7411                   -je 0x483aec
    if (cpu.flags.zf)
    {
        goto L_0x00483aec;
    }
L_0x00483adb:
    // 00483adb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483ade  42                     -inc edx
    (cpu.edx)++;
    // 00483adf  83f820                 +cmp eax, 0x20
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
    // 00483ae2  7d08                   -jge 0x483aec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483aec;
    }
    // 00483ae4  3b8880375600           +cmp ecx, dword ptr [eax + 0x563780]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483aea  75ef                   -jne 0x483adb
    if (!cpu.flags.zf)
    {
        goto L_0x00483adb;
    }
L_0x00483aec:
    // 00483aec  83fa08                 +cmp edx, 8
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
    // 00483aef  7d32                   -jge 0x483b23
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483b23;
    }
    // 00483af1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00483af8  3b8880375600           +cmp ecx, dword ptr [eax + 0x563780]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483afe  7523                   -jne 0x483b23
    if (!cpu.flags.zf)
    {
        goto L_0x00483b23;
    }
    // 00483b00  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483b03  7d17                   -jge 0x483b1c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483b1c;
    }
L_0x00483b05:
    // 00483b05  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483b08  8b9080375600           -mov edx, dword ptr [eax + 0x563780]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */);
    // 00483b0e  89907c375600           -mov dword ptr [eax + 0x56377c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650300) /* 0x56377c */) = cpu.edx;
    // 00483b14  83f81c                 +cmp eax, 0x1c
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
    // 00483b17  7cec                   -jl 0x483b05
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483b05;
    }
    // 00483b19  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00483b1c:
    // 00483b1c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483b1e  a39c375600             -mov dword ptr [0x56379c], eax
    app->getMemory<x86::reg32>(x86::reg32(5650332) /* 0x56379c */) = cpu.eax;
L_0x00483b23:
    // 00483b23  4b                     -dec ebx
    (cpu.ebx)--;
    // 00483b24  891db0b14d00           -mov dword ptr [0x4db1b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */) = cpu.ebx;
    // 00483b2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483b30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483b31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483b32  8b0d80375600           -mov ecx, dword ptr [0x563780]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5650304) /* 0x563780 */);
    // 00483b38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483b3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483b3c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483b3e  7412                   -je 0x483b52
    if (cpu.flags.zf)
    {
        goto L_0x00483b52;
    }
L_0x00483b40:
    // 00483b40  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483b43  42                     -inc edx
    (cpu.edx)++;
    // 00483b44  83f820                 +cmp eax, 0x20
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
    // 00483b47  7d09                   -jge 0x483b52
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483b52;
    }
    // 00483b49  83b88037560000         +cmp dword ptr [eax + 0x563780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650304) /* 0x563780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483b50  75ee                   -jne 0x483b40
    if (!cpu.flags.zf)
    {
        goto L_0x00483b40;
    }
L_0x00483b52:
    // 00483b52  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483b54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483b58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483b58  ff05b0b14d00           -inc dword ptr [0x4db1b0]
    (app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */))++;
    // 00483b5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483b60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483b61  8b15b0b14d00           -mov edx, dword ptr [0x4db1b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */);
    // 00483b67  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483b69  7502                   -jne 0x483b6d
    if (!cpu.flags.zf)
    {
        goto L_0x00483b6d;
    }
    // 00483b6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483b6d:
    // 00483b6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483b6e  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00483b71  890db0b14d00           -mov dword ptr [0x4db1b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */) = cpu.ecx;
    // 00483b77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483b7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483b7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483b7d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483b7e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483b7f  833dd037560000         +cmp dword ptr [0x5637d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483b86  7448                   -je 0x483bd0
    if (cpu.flags.zf)
    {
        goto L_0x00483bd0;
    }
    // 00483b88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483b89  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483b8b  8b35c4375600           -mov esi, dword ptr [0x5637c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5650372) /* 0x5637c4 */);
    // 00483b91  890dccab4d00           -mov dword ptr [0x4dabcc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.ecx;
    // 00483b97  890dd0375600           -mov dword ptr [0x5637d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */) = cpu.ecx;
    // 00483b9d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483b9f  7553                   -jne 0x483bf4
    if (!cpu.flags.zf)
    {
        goto L_0x00483bf4;
    }
L_0x00483ba1:
    // 00483ba1  8b2da4375600           -mov ebp, dword ptr [0x5637a4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5650340) /* 0x5637a4 */);
    // 00483ba7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483ba8  2eff15f4654c00         -call dword ptr cs:[0x4c65f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006836) /* 0x4c65f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483baf  a1d8375600             -mov eax, dword ptr [0x5637d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */);
    // 00483bb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483bb6  7546                   -jne 0x483bfe
    if (!cpu.flags.zf)
    {
        goto L_0x00483bfe;
    }
L_0x00483bb8:
    // 00483bb8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483bbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483bbe:
    // 00483bbe  833dc437560000         +cmp dword ptr [0x5637c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650372) /* 0x5637c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483bc5  7409                   -je 0x483bd0
    if (cpu.flags.zf)
    {
        goto L_0x00483bd0;
    }
    // 00483bc7  833dd837560000         +cmp dword ptr [0x5637d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483bce  753c                   -jne 0x483c0c
    if (!cpu.flags.zf)
    {
        goto L_0x00483c0c;
    }
L_0x00483bd0:
    // 00483bd0  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00483bd2  8935c8375600           -mov dword ptr [0x5637c8], esi
    app->getMemory<x86::reg32>(x86::reg32(5650376) /* 0x5637c8 */) = cpu.esi;
    // 00483bd8  8935b0b14d00           -mov dword ptr [0x4db1b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5091760) /* 0x4db1b0 */) = cpu.esi;
    // 00483bde  8935a4375600           -mov dword ptr [0x5637a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5650340) /* 0x5637a4 */) = cpu.esi;
    // 00483be4  8935c4375600           -mov dword ptr [0x5637c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5650372) /* 0x5637c4 */) = cpu.esi;
    // 00483bea  893508ac4d00           -mov dword ptr [0x4dac08], esi
    app->getMemory<x86::reg32>(x86::reg32(5090312) /* 0x4dac08 */) = cpu.esi;
    // 00483bf0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bf2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483bf3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483bf4:
    // 00483bf4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483bf5  2eff15fc654c00         -call dword ptr cs:[0x4c65fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006844) /* 0x4c65fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483bfc  eba3                   -jmp 0x483ba1
    goto L_0x00483ba1;
L_0x00483bfe:
    // 00483bfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483c00  b8dc375600             -mov eax, 0x5637dc
    cpu.eax = 5650396 /*0x5637dc*/;
    // 00483c05  e816620000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00483c0a  ebac                   -jmp 0x483bb8
    goto L_0x00483bb8;
L_0x00483c0c:
    // 00483c0c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483c0e  e8895f0000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00483c13  eba9                   -jmp 0x483bbe
    goto L_0x00483bbe;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483c18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x00483c18, cpu);
    // 00483c18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483c19  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483c1a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483c1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483c1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483c1d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483c1e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483c21  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483c23  e854ffffff             -call 0x483b7c
    cpu.esp -= 4;
    sub_483b7c(app, cpu);
    if (cpu.terminate) return;
    // 00483c28  83fe01                 +cmp esi, 1
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
    // 00483c2b  7d70                   -jge 0x483c9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483c9d;
    }
L_0x00483c2d:
    // 00483c2d  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
L_0x00483c32:
    // 00483c32  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 00483c37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483c39  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00483c3c  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00483c3e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483c40  a3a0375600             -mov dword ptr [0x5637a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5650336) /* 0x5637a0 */) = cpu.eax;
    // 00483c45  8915c8375600           -mov dword ptr [0x5637c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5650376) /* 0x5637c8 */) = cpu.edx;
    // 00483c4b  8915f4375600           -mov dword ptr [0x5637f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */) = cpu.edx;
    // 00483c51  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00483c53  8915d4375600           -mov dword ptr [0x5637d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5650388) /* 0x5637d4 */) = cpu.edx;
    // 00483c59  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483c5d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483c5e  2eff15f8654c00         -call dword ptr cs:[0x4c65f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006840) /* 0x4c65f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483c65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483c67  753e                   -jne 0x483ca7
    if (!cpu.flags.zf)
    {
        goto L_0x00483ca7;
    }
    // 00483c69  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00483c6e  8b15a0375600           -mov edx, dword ptr [0x5637a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650336) /* 0x5637a0 */);
    // 00483c74  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00483c77  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00483c7b  893da4375600           -mov dword ptr [0x5637a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5650340) /* 0x5637a4 */) = cpu.edi;
    // 00483c81  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c87  732e                   -jae 0x483cb7
    if (!cpu.flags.cf)
    {
        goto L_0x00483cb7;
    }
L_0x00483c89:
    // 00483c89  a3ccab4d00             -mov dword ptr [0x4dabcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.eax;
    // 00483c8e  a3d0375600             -mov dword ptr [0x5637d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */) = cpu.eax;
L_0x00483c93:
    // 00483c93  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483c96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483c9d:
    // 00483c9d  81fe10270000           +cmp esi, 0x2710
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483ca3  7f88                   -jg 0x483c2d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483c2d;
    }
    // 00483ca5  eb8b                   -jmp 0x483c32
    goto L_0x00483c32;
L_0x00483ca7:
    // 00483ca7  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00483ca9  893dccab4d00           -mov dword ptr [0x4dabcc], edi
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.edi;
    // 00483caf  893dd0375600           -mov dword ptr [0x5637d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */) = cpu.edi;
    // 00483cb5  ebdc                   -jmp 0x483c93
    goto L_0x00483c93;
L_0x00483cb7:
    // 00483cb7  68dc375600             -push 0x5637dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5650396 /*0x5637dc*/;
    cpu.esp -= 4;
    // 00483cbc  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00483cc1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00483cc6  b8d0374800             -mov eax, 0x4837d0
    cpu.eax = 4732880 /*0x4837d0*/;
    // 00483ccb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483ccd  e80e5e0000             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 00483cd2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483cd4  74b3                   -je 0x483c89
    if (cpu.flags.zf)
    {
        goto L_0x00483c89;
    }
    // 00483cd6  8b0da4375600           -mov ecx, dword ptr [0x5637a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5650340) /* 0x5637a4 */);
    // 00483cdc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483cdd  2eff15f0654c00         -call dword ptr cs:[0x4c65f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006832) /* 0x4c65f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483ce4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483ce6  755e                   -jne 0x483d46
    if (!cpu.flags.zf)
    {
        goto L_0x00483d46;
    }
    // 00483ce8  b87c3b4800             -mov eax, 0x483b7c
    cpu.eax = 4733820 /*0x483b7c*/;
    // 00483ced  e8ae700100             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 00483cf2  8935ccab4d00           -mov dword ptr [0x4dabcc], esi
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.esi;
    // 00483cf8  8935d0375600           -mov dword ptr [0x5637d0], esi
    app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */) = cpu.esi;
    // 00483cfe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483d00  756c                   -jne 0x483d6e
    if (!cpu.flags.zf)
    {
        goto L_0x00483d6e;
    }
L_0x00483d02:
    // 00483d02  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483d07  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483d09  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d10  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483d12  b810270000             -mov eax, 0x2710
    cpu.eax = 10000 /*0x2710*/;
    // 00483d17  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483d19  8b3dccab4d00           -mov edi, dword ptr [0x4dabcc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00483d1f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00483d22  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00483d24  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00483d26:
    // 00483d26  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d2d  39f0                   +cmp eax, esi
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
    // 00483d2f  7362                   -jae 0x483d93
    if (!cpu.flags.cf)
    {
        goto L_0x00483d93;
    }
    // 00483d31  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483d36  39c3                   +cmp ebx, eax
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
    // 00483d38  7559                   -jne 0x483d93
    if (!cpu.flags.zf)
    {
        goto L_0x00483d93;
    }
    // 00483d3a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483d3f  e8585e0000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00483d44  ebe0                   -jmp 0x483d26
    goto L_0x00483d26;
L_0x00483d46:
    // 00483d46  b8dc375600             -mov eax, 0x5637dc
    cpu.eax = 5650396 /*0x5637dc*/;
    // 00483d4b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00483d4d  8b15d8375600           -mov edx, dword ptr [0x5637d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650392) /* 0x5637d8 */);
    // 00483d53  892dccab4d00           -mov dword ptr [0x4dabcc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */) = cpu.ebp;
    // 00483d59  892dd0375600           -mov dword ptr [0x5637d0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5650384) /* 0x5637d0 */) = cpu.ebp;
    // 00483d5f  e8bc600000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00483d64  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483d67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483d6e:
    // 00483d6e  8b1dc4375600           -mov ebx, dword ptr [0x5637c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650372) /* 0x5637c4 */);
    // 00483d74  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483d76  758a                   -jne 0x483d02
    if (!cpu.flags.zf)
    {
        goto L_0x00483d02;
    }
    // 00483d78  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d82  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d84  a3a8375600             -mov dword ptr [0x5637a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5650344) /* 0x5637a8 */) = cpu.eax;
    // 00483d89  e8eafbffff             -call 0x483978
    cpu.esp -= 4;
    sub_483978(app, cpu);
    if (cpu.terminate) return;
    // 00483d8e  e96fffffff             -jmp 0x483d02
    goto L_0x00483d02;
L_0x00483d93:
    // 00483d93  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483d98  39c3                   +cmp ebx, eax
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
    // 00483d9a  7505                   -jne 0x483da1
    if (!cpu.flags.zf)
    {
        goto L_0x00483da1;
    }
    // 00483d9c  e8dbfdffff             -call 0x483b7c
    cpu.esp -= 4;
    sub_483b7c(app, cpu);
    if (cpu.terminate) return;
L_0x00483da1:
    // 00483da1  833dccab4d0000         +cmp dword ptr [0x4dabcc], 0
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
    // 00483da8  0f84e5feffff           -je 0x483c93
    if (cpu.flags.zf)
    {
        goto L_0x00483c93;
    }
    // 00483dae  c70508ac4d0060394800   -mov dword ptr [0x4dac08], 0x483960
    app->getMemory<x86::reg32>(x86::reg32(5090312) /* 0x4dac08 */) = 4733280 /*0x483960*/;
    // 00483db8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483dbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_483dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483dd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483dd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483dd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483dd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483dd4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483dd7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483dd9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483ddc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483dde  8b1dc0b14d00           -mov ebx, dword ptr [0x4db1c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091776) /* 0x4db1c0 */);
    // 00483de4  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00483de9  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00483dec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483dee  8915c0b14d00           -mov dword ptr [0x4db1c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5091776) /* 0x4db1c0 */) = cpu.edx;
    // 00483df4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00483df6:
    // 00483df6  8baaf8375600           -mov ebp, dword ptr [edx + 0x5637f8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5650424) /* 0x5637f8 */);
    // 00483dfc  39ee                   +cmp esi, ebp
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
    // 00483dfe  751e                   -jne 0x483e1e
    if (!cpu.flags.zf)
    {
        goto L_0x00483e1e;
    }
L_0x00483e00:
    // 00483e00  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00483e02:
    // 00483e02  40                     -inc eax
    (cpu.eax)++;
    // 00483e03  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00483e06  83f810                 +cmp eax, 0x10
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
    // 00483e09  7ceb                   -jl 0x483df6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483df6;
    }
    // 00483e0b  83f9ff                 +cmp ecx, -1
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
    // 00483e0e  751e                   -jne 0x483e2e
    if (!cpu.flags.zf)
    {
        goto L_0x00483e2e;
    }
    // 00483e10  ff0dc0b14d00           -dec dword ptr [0x4db1c0]
    (app->getMemory<x86::reg32>(x86::reg32(5091776) /* 0x4db1c0 */))--;
    // 00483e16  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483e1e:
    // 00483e1e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483e20  75e0                   -jne 0x483e02
    if (!cpu.flags.zf)
    {
        goto L_0x00483e02;
    }
    // 00483e22  83f9ff                 +cmp ecx, -1
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
    // 00483e25  75db                   -jne 0x483e02
    if (!cpu.flags.zf)
    {
        goto L_0x00483e02;
    }
    // 00483e27  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483e29  74d5                   -je 0x483e00
    if (cpu.flags.zf)
    {
        goto L_0x00483e00;
    }
    // 00483e2b  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00483e2c  ebd4                   -jmp 0x483e02
    goto L_0x00483e02;
L_0x00483e2e:
    // 00483e2e  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00483e31  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00483e34  89b1f8375600           -mov dword ptr [ecx + 0x5637f8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650424) /* 0x5637f8 */) = cpu.esi;
    // 00483e3a  8981fc375600           -mov dword ptr [ecx + 0x5637fc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650428) /* 0x5637fc */) = cpu.eax;
    // 00483e40  033df0375600           -add edi, dword ptr [0x5637f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */)));
    // 00483e46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483e48  89b900385600           -mov dword ptr [ecx + 0x563800], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650432) /* 0x563800 */) = cpu.edi;
    // 00483e4e  899104385600           -mov dword ptr [ecx + 0x563804], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650436) /* 0x563804 */) = cpu.edx;
    // 00483e54  ff0dc0b14d00           -dec dword ptr [0x4db1c0]
    (app->getMemory<x86::reg32>(x86::reg32(5091776) /* 0x4db1c0 */))--;
    // 00483e5a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483e64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483e64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483e65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483e66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e67  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483e68  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483e6a  8b1df8375600           -mov ebx, dword ptr [0x5637f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650424) /* 0x5637f8 */);
    // 00483e70  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483e72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483e74  39d9                   +cmp ecx, ebx
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
    // 00483e76  7413                   -je 0x483e8b
    if (cpu.flags.zf)
    {
        goto L_0x00483e8b;
    }
L_0x00483e78:
    // 00483e78  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00483e7b  42                     -inc edx
    (cpu.edx)++;
    // 00483e7c  3d00010000             +cmp eax, 0x100
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
    // 00483e81  7d08                   -jge 0x483e8b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483e8b;
    }
    // 00483e83  3b88f8375600           +cmp ecx, dword ptr [eax + 0x5637f8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5650424) /* 0x5637f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483e89  75ed                   -jne 0x483e78
    if (!cpu.flags.zf)
    {
        goto L_0x00483e78;
    }
L_0x00483e8b:
    // 00483e8b  83fa10                 +cmp edx, 0x10
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
    // 00483e8e  7d0b                   -jge 0x483e9b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483e9b;
    }
    // 00483e90  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00483e93  3b8af8375600           +cmp ecx, dword ptr [edx + 0x5637f8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5650424) /* 0x5637f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483e99  7405                   -je 0x483ea0
    if (cpu.flags.zf)
    {
        goto L_0x00483ea0;
    }
L_0x00483e9b:
    // 00483e9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e9f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483ea0:
    // 00483ea0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00483ea2  89aaf8375600           -mov dword ptr [edx + 0x5637f8], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5650424) /* 0x5637f8 */) = cpu.ebp;
    // 00483ea8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ea9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483eaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483eab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483eac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483eb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483eb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483eb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483eb6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00483eb8  a1c4b14d00             -mov eax, dword ptr [0x4db1c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091780) /* 0x4db1c4 */);
    // 00483ebd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00483ebf  3b05f0375600           +cmp eax, dword ptr [0x5637f0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 00483ec5  0f8470000000           -je 0x483f3b
    if (cpu.flags.zf)
    {
        goto L_0x00483f3b;
    }
    // 00483ecb  a1f0375600             -mov eax, dword ptr [0x5637f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 00483ed0  a3c4b14d00             -mov dword ptr [0x4db1c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5091780) /* 0x4db1c4 */) = cpu.eax;
    // 00483ed5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00483ed7:
    // 00483ed7  8b99f8375600           -mov ebx, dword ptr [ecx + 0x5637f8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650424) /* 0x5637f8 */);
    // 00483edd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483edf  744f                   -je 0x483f30
    if (cpu.flags.zf)
    {
        goto L_0x00483f30;
    }
    // 00483ee1  a1f0375600             -mov eax, dword ptr [0x5637f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 00483ee6  3b8100385600           +cmp eax, dword ptr [ecx + 0x563800]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650432) /* 0x563800 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483eec  7c42                   -jl 0x483f30
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483f30;
    }
    // 00483eee  83b90438560000         +cmp dword ptr [ecx + 0x563804], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650436) /* 0x563804 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483ef5  7539                   -jne 0x483f30
    if (!cpu.flags.zf)
    {
        goto L_0x00483f30;
    }
    // 00483ef7  c7810438560001000000   -mov dword ptr [ecx + 0x563804], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650436) /* 0x563804 */) = 1 /*0x1*/;
    // 00483f01  8b15f0375600           -mov edx, dword ptr [0x5637f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 00483f07  8ba900385600           -mov ebp, dword ptr [ecx + 0x563800]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650432) /* 0x563800 */);
    // 00483f0d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483f0f  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00483f11  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483f13  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f15  a1f0375600             -mov eax, dword ptr [0x5637f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650416) /* 0x5637f0 */);
    // 00483f1a  8b91fc375600           -mov edx, dword ptr [ecx + 0x5637fc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650428) /* 0x5637fc */);
    // 00483f20  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483f22  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00483f24  899904385600           -mov dword ptr [ecx + 0x563804], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650436) /* 0x563804 */) = cpu.ebx;
    // 00483f2a  898100385600           -mov dword ptr [ecx + 0x563800], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5650432) /* 0x563800 */) = cpu.eax;
L_0x00483f30:
    // 00483f30  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00483f33  81f900010000           +cmp ecx, 0x100
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
    // 00483f39  759c                   -jne 0x483ed7
    if (!cpu.flags.zf)
    {
        goto L_0x00483ed7;
    }
L_0x00483f3b:
    // 00483f3b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483f3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483f45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483f46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483f48  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483f4d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483f4f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00483f51:
    // 00483f51  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00483f56  39c8                   +cmp eax, ecx
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
    // 00483f58  7d04                   -jge 0x483f5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00483f5e;
    }
    // 00483f5a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483f5c  7405                   -je 0x483f63
    if (cpu.flags.zf)
    {
        goto L_0x00483f63;
    }
L_0x00483f5e:
    // 00483f5e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483f60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f63:
    // 00483f63  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00483f65  e846ffffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00483f6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483f6c  ebe3                   -jmp 0x483f51
    goto L_0x00483f51;
}

/* align: skip 0x00 0x00 */
void Application::sub_483f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f70  ff05c8b14d00           -inc dword ptr [0x4db1c8]
    (app->getMemory<x86::reg32>(x86::reg32(5091784) /* 0x4db1c8 */))++;
    // 00483f76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f78  833d3c3d560000         +cmp dword ptr [0x563d3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651772) /* 0x563d3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483f7f  7509                   -jne 0x483f8a
    if (!cpu.flags.zf)
    {
        goto L_0x00483f8a;
    }
    // 00483f81  833dccb14d0000         +cmp dword ptr [0x4db1cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091788) /* 0x4db1cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483f88  7406                   -je 0x483f90
    if (cpu.flags.zf)
    {
        goto L_0x00483f90;
    }
L_0x00483f8a:
    // 00483f8a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483f8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f90:
    // 00483f90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00483f90;
    // 00483f78  833d3c3d560000         +cmp dword ptr [0x563d3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651772) /* 0x563d3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483f7f  7509                   -jne 0x483f8a
    if (!cpu.flags.zf)
    {
        goto L_0x00483f8a;
    }
    // 00483f81  833dccb14d0000         +cmp dword ptr [0x4db1cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091788) /* 0x4db1cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483f88  7406                   -je 0x483f90
    if (cpu.flags.zf)
    {
        goto L_0x00483f90;
    }
L_0x00483f8a:
    // 00483f8a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483f8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483f90:
L_entry_0x00483f90:
    // 00483f90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f96  a05f3d5600             -mov al, byte ptr [0x563d5f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651807) /* 0x563d5f */);
    // 00483f9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483f9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f9c  803d603d560000         +cmp byte ptr [0x563d60], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5651808) /* 0x563d60 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483fa3  74eb                   -je 0x483f90
    if (cpu.flags.zf)
    {
        return sub_483f90(app, cpu);
    }
    // 00483fa5  803d353d560000         +cmp byte ptr [0x563d35], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5651765) /* 0x563d35 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483fac  75e2                   -jne 0x483f90
    if (!cpu.flags.zf)
    {
        return sub_483f90(app, cpu);
    }
    // 00483fae  803d343d560000         +cmp byte ptr [0x563d34], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5651764) /* 0x563d34 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483fb5  75d9                   -jne 0x483f90
    if (!cpu.flags.zf)
    {
        return sub_483f90(app, cpu);
    }
    // 00483fb7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483fbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483fc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483fc2  a0623d5600             -mov al, byte ptr [0x563d62]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651810) /* 0x563d62 */);
    // 00483fc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483fc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483fc8  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483fcb  833d74b24d0000         +cmp dword ptr [0x4db274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091956) /* 0x4db274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483fd2  741c                   -je 0x483ff0
    if (cpu.flags.zf)
    {
        goto L_0x00483ff0;
    }
    // 00483fd4  833da4d74d0000         +cmp dword ptr [0x4dd7a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101476) /* 0x4dd7a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483fdb  741c                   -je 0x483ff9
    if (cpu.flags.zf)
    {
        goto L_0x00483ff9;
    }
    // 00483fdd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483fdf  e84c000200             -call 0x4a4030
    cpu.esp -= 4;
    sub_4a4030(app, cpu);
    if (cpu.terminate) return;
    // 00483fe4  e8d3e4ffff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 00483fe9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483feb  e864000200             -call 0x4a4054
    cpu.esp -= 4;
    sub_4a4054(app, cpu);
    if (cpu.terminate) return;
L_0x00483ff0:
    // 00483ff0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483ff5  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00483ff8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483ff9:
    // 00483ff9  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 00483ffe  e8e1dd0000             -call 0x491de4
    cpu.esp -= 4;
    sub_491de4(app, cpu);
    if (cpu.terminate) return;
    // 00484003  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00484006  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484008  833d743d560000         +cmp dword ptr [0x563d74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651828) /* 0x563d74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048400f  0f847bffffff           -je 0x483f90
    if (cpu.flags.zf)
    {
        return sub_483f90(app, cpu);
    }
    // 00484015  833d543d560000         +cmp dword ptr [0x563d54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048401c  0f846effffff           -je 0x483f90
    if (cpu.flags.zf)
    {
        return sub_483f90(app, cpu);
    }
    // 00484022  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00484024  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48402c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048402c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048402d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048402e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048402f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484031  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484033  2eff15f8634c00         -call dword ptr cs:[0x4c63f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006328) /* 0x4c63f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048403a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048403c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048403e  2eff15f8634c00         -call dword ptr cs:[0x4c63f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006328) /* 0x4c63f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484045  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048404c  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048404f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484050  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484051  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484052  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484054(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484054  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484055  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484056  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484057  833d44ab4d0000         +cmp dword ptr [0x4dab44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090116) /* 0x4dab44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048405e  750c                   -jne 0x48406c
    if (!cpu.flags.zf)
    {
        goto L_0x0048406c;
    }
    // 00484060  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484062  746c                   -je 0x4840d0
    if (cpu.flags.zf)
    {
        goto L_0x004840d0;
    }
    // 00484064  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00484066:
    // 00484066  891d44ab4d00           -mov dword ptr [0x4dab44], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090116) /* 0x4dab44 */) = cpu.ebx;
L_0x0048406c:
    // 0048406c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048406e  7505                   -jne 0x484075
    if (!cpu.flags.zf)
    {
        goto L_0x00484075;
    }
    // 00484070  a144ab4d00             -mov eax, dword ptr [0x4dab44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090116) /* 0x4dab44 */);
L_0x00484075:
    // 00484075  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484076  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484078  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048407a  2eff1564644c00         -call dword ptr cs:[0x4c6464]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006436) /* 0x4c6464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484081  a3783d5600             -mov dword ptr [0x563d78], eax
    app->getMemory<x86::reg32>(x86::reg32(5651832) /* 0x563d78 */) = cpu.eax;
    // 00484086  2eff15f0644c00         -call dword ptr cs:[0x4c64f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006576) /* 0x4c64f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048408d  3db7000000             +cmp eax, 0xb7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484092  7536                   -jne 0x4840ca
    if (!cpu.flags.zf)
    {
        goto L_0x004840ca;
    }
    // 00484094  8b0d44ab4d00           -mov ecx, dword ptr [0x4dab44]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090116) /* 0x4dab44 */);
    // 0048409a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048409b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048409d  2eff15e0634c00         -call dword ptr cs:[0x4c63e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006304) /* 0x4c63e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004840a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004840a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004840a8  7412                   -je 0x4840bc
    if (cpu.flags.zf)
    {
        goto L_0x004840bc;
    }
    // 004840aa  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004840ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004840ad  2eff1538644c00         -call dword ptr cs:[0x4c6438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006392) /* 0x4c6438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004840b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004840b5  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004840bc:
    // 004840bc  833dd4b14d0000         +cmp dword ptr [0x4db1d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091796) /* 0x4db1d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004840c3  7415                   -je 0x4840da
    if (cpu.flags.zf)
    {
        goto L_0x004840da;
    }
    // 004840c5  e8db6c0100             -call 0x49ada5
    cpu.esp -= 4;
    sub_49ada5(app, cpu);
    if (cpu.terminate) return;
L_0x004840ca:
    // 004840ca  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004840cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004840d0:
    // 004840d0  8b1d2c0e5700           -mov ebx, dword ptr [0x570e2c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705260) /* 0x570e2c */);
    // 004840d6  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004840d8  eb8c                   -jmp 0x484066
    goto L_0x00484066;
L_0x004840da:
    // 004840da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004840df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4840f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004840f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004840f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004840f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004840f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004840f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004840f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004840f6  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004840fc  8b15e8b14d00           -mov edx, dword ptr [0x4db1e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091816) /* 0x4db1e8 */);
    // 00484102  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00484104  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484106  0f8582010000           -jne 0x48428e
    if (!cpu.flags.zf)
    {
        goto L_0x0048428e;
    }
    // 0048410c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00484111  8b9c2420030000         -mov ebx, dword ptr [esp + 0x320]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00484118  890de8b14d00           -mov dword ptr [0x4db1e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091816) /* 0x4db1e8 */) = cpu.ecx;
    // 0048411e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00484120  0f8575010000           -jne 0x48429b
    if (!cpu.flags.zf)
    {
        goto L_0x0048429b;
    }
    // 00484126  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00484128  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x0048412b:
    // 0048412b  833d00ac4d0000         +cmp dword ptr [0x4dac00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090304) /* 0x4dac00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484132  0f8592010000           -jne 0x4842ca
    if (!cpu.flags.zf)
    {
        goto L_0x004842ca;
    }
L_0x00484138:
    // 00484138  833dfcab4d0000         +cmp dword ptr [0x4dabfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090300) /* 0x4dabfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048413f  0f84a4000000           -je 0x4841e9
    if (cpu.flags.zf)
    {
        goto L_0x004841e9;
    }
    // 00484145  8b15d8b14d00           -mov edx, dword ptr [0x4db1d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */);
    // 0048414b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048414d  7448                   -je 0x484197
    if (cpu.flags.zf)
    {
        goto L_0x00484197;
    }
    // 0048414f  8b0ddcb14d00           -mov ecx, dword ptr [0x4db1dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */);
    // 00484155  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484156  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484157  68c4f94c00             -push 0x4cf9c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044676 /*0x4cf9c4*/;
    cpu.esp -= 4;
    // 0048415c  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00484163  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00484164  e898230000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00484169  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048416c  8db42400020000         -lea esi, [esp + 0x200]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00484173  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00484175  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484176  2bc9                   +sub ecx, ecx
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
    // 00484178  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00484179  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048417b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048417d  4f                     -dec edi
    (cpu.edi)--;
L_0x0048417e:
    // 0048417e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00484180  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00484182  3c00                   +cmp al, 0
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
    // 00484184  7410                   -je 0x484196
    if (cpu.flags.zf)
    {
        goto L_0x00484196;
    }
    // 00484186  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00484189  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048418c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048418f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00484192  3c00                   +cmp al, 0
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
    // 00484194  75e8                   -jne 0x48417e
    if (!cpu.flags.zf)
    {
        goto L_0x0048417e;
    }
L_0x00484196:
    // 00484196  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484197:
    // 00484197  8b35e0b14d00           -mov esi, dword ptr [0x4db1e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091808) /* 0x4db1e0 */);
    // 0048419d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048419f  7448                   -je 0x4841e9
    if (cpu.flags.zf)
    {
        goto L_0x004841e9;
    }
    // 004841a1  8b3de4b14d00           -mov edi, dword ptr [0x4db1e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091812) /* 0x4db1e4 */);
    // 004841a7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004841a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004841a9  68d8f94c00             -push 0x4cf9d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044696 /*0x4cf9d8*/;
    cpu.esp -= 4;
    // 004841ae  8d84248c020000         -lea eax, [esp + 0x28c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(652) /* 0x28c */);
    // 004841b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004841b6  e846230000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004841bb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004841be  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004841c0  8db42480020000         -lea esi, [esp + 0x280]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 004841c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004841c8  2bc9                   +sub ecx, ecx
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
    // 004841ca  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004841cb  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004841cd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004841cf  4f                     -dec edi
    (cpu.edi)--;
L_0x004841d0:
    // 004841d0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004841d2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004841d4  3c00                   +cmp al, 0
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
    // 004841d6  7410                   -je 0x4841e8
    if (cpu.flags.zf)
    {
        goto L_0x004841e8;
    }
    // 004841d8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004841db  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004841de  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004841e1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004841e4  3c00                   +cmp al, 0
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
    // 004841e6  75e8                   -jne 0x4841d0
    if (!cpu.flags.zf)
    {
        goto L_0x004841d0;
    }
L_0x004841e8:
    // 004841e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004841e9:
    // 004841e9  833df0ab4d0000         +cmp dword ptr [0x4dabf0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090288) /* 0x4dabf0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004841f0  7411                   -je 0x484203
    if (cpu.flags.zf)
    {
        goto L_0x00484203;
    }
    // 004841f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004841f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004841f5  2eff1554654c00         -call dword ptr cs:[0x4c6554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006676) /* 0x4c6554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004841fc  2eff156c644c00         -call dword ptr cs:[0x4c646c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006444) /* 0x4c646c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00484203:
    // 00484203  833d04ac4d0000         +cmp dword ptr [0x4dac04], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090308) /* 0x4dac04 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048420a  7408                   -je 0x484214
    if (cpu.flags.zf)
    {
        goto L_0x00484214;
    }
    // 0048420c  ff1504ac4d00           -call dword ptr [0x4dac04]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090308) /* 0x4dac04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484212  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00484214:
    // 00484214  833d08ac4d0000         +cmp dword ptr [0x4dac08], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090312) /* 0x4dac08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048421b  7406                   -je 0x484223
    if (cpu.flags.zf)
    {
        goto L_0x00484223;
    }
    // 0048421d  ff1508ac4d00           -call dword ptr [0x4dac08]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090312) /* 0x4dac08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00484223:
    // 00484223  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00484225  2eff1534644c00         -call dword ptr cs:[0x4c6434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006388) /* 0x4c6434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048422c  6831100100             -push 0x11031
    app->getMemory<x86::reg32>(cpu.esp-4) = 69681 /*0x11031*/;
    cpu.esp -= 4;
    // 00484231  68f8f94c00             -push 0x4cf9f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044728 /*0x4cf9f8*/;
    cpu.esp -= 4;
    // 00484236  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048423a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048423b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048423d  2eff1504644c00         -call dword ptr cs:[0x4c6404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006340) /* 0x4c6404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00484244  83f801                 +cmp eax, 1
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
    // 00484247  7528                   -jne 0x484271
    if (!cpu.flags.zf)
    {
        goto L_0x00484271;
    }
    // 00484249  833df4ab4d0000         +cmp dword ptr [0x4dabf4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090292) /* 0x4dabf4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484250  741f                   -je 0x484271
    if (cpu.flags.zf)
    {
        goto L_0x00484271;
    }
    // 00484252  833df8ab4d0000         +cmp dword ptr [0x4dabf8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090296) /* 0x4dabf8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484259  7416                   -je 0x484271
    if (cpu.flags.zf)
    {
        goto L_0x00484271;
    }
    // 0048425b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048425d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048425e  6808fa4c00             -push 0x4cfa08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044744 /*0x4cfa08*/;
    cpu.esp -= 4;
    // 00484263  e8146b0100             -call 0x49ad7c
    cpu.esp -= 4;
    sub_49ad7c(app, cpu);
    if (cpu.terminate) return;
    // 00484268  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048426b  ff15f8ab4d00           -call dword ptr [0x4dabf8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090296) /* 0x4dabf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00484271:
    // 00484271  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00484273  7407                   -je 0x48427c
    if (cpu.flags.zf)
    {
        goto L_0x0048427c;
    }
    // 00484275  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484277  e8e45c0000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x0048427c:
    // 0048427c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048427e  e865590000             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 00484283  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484285  745a                   -je 0x4842e1
    if (cpu.flags.zf)
    {
        goto L_0x004842e1;
    }
    // 00484287  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484289  e8aa850100             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
L_0x0048428e:
    // 0048428e  81c404030000           +add esp, 0x304
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
    // 00484294  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484295  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484296  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484297  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484298  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484299  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048429a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048429b:
    // 0048429b  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 004842a2  8d9c2400030000         -lea ebx, [esp + 0x300]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004842a9  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 004842b0  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004842b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004842b9  e8c6fd0100             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 004842be  89ac2400030000         -mov dword ptr [esp + 0x300], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.ebp;
    // 004842c5  e961feffff             -jmp 0x48412b
    goto L_0x0048412b;
L_0x004842ca:
    // 004842ca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004842cc  ff1500ac4d00           -call dword ptr [0x4dac00]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090304) /* 0x4dac00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004842d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004842d4  0f855efeffff           -jne 0x484138
    if (!cpu.flags.zf)
    {
        goto L_0x00484138;
    }
    // 004842da  a3e8b14d00             -mov dword ptr [0x4db1e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5091816) /* 0x4db1e8 */) = cpu.eax;
    // 004842df  ebad                   -jmp 0x48428e
    goto L_0x0048428e;
L_0x004842e1:
    // 004842e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004842e2  2eff1584644c00         -call dword ptr cs:[0x4c6484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006468) /* 0x4c6484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004842e9  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004842ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004842f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_484300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484301  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484302  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484303  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484305  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00484307  e894fd0100             -call 0x4a40a0
    cpu.esp -= 4;
    sub_4a40a0(app, cpu);
    if (cpu.terminate) return;
    // 0048430c  a3003f5600             -mov dword ptr [0x563f00], eax
    app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */) = cpu.eax;
    // 00484311  e8aafd0100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484316  b8803d5600             -mov eax, 0x563d80
    cpu.eax = 5651840 /*0x563d80*/;
    // 0048431b  8915f8b14d00           -mov dword ptr [0x4db1f8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */) = cpu.edx;
    // 00484321  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00484326  e8f15c0000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048432b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048432d  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048432f  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 00484336  a1f8b14d00             -mov eax, dword ptr [0x4db1f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 0048433b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048433d  e8fe090000             -call 0x484d40
    cpu.esp -= 4;
    sub_484d40(app, cpu);
    if (cpu.terminate) return;
    // 00484342  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484344  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00484346  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00484348  b80cfa4c00             -mov eax, 0x4cfa0c
    cpu.eax = 5044748 /*0x4cfa0c*/;
    // 0048434d  8b1df8b14d00           -mov ebx, dword ptr [0x4db1f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 00484353  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00484355  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00484358  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048435a  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0048435c  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048435e  8935f4b14d00           -mov dword ptr [0x4db1f4], esi
    app->getMemory<x86::reg32>(x86::reg32(5091828) /* 0x4db1f4 */) = cpu.esi;
    // 00484364  e823000000             -call 0x48438c
    cpu.esp -= 4;
    sub_48438c(app, cpu);
    if (cpu.terminate) return;
    // 00484369  a1f4b14d00             -mov eax, dword ptr [0x4db1f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091828) /* 0x4db1f4 */);
    // 0048436e  8b15f8b14d00           -mov edx, dword ptr [0x4db1f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091832) /* 0x4db1f8 */);
    // 00484374  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00484376  a30c3f5600             -mov dword ptr [0x563f0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5652236) /* 0x563f0c */) = cpu.eax;
    // 0048437b  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484380  e843fd0100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484385  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484386  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484387  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484388  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48438c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048438c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048438d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048438e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048438f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484391  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00484393  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00484395  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484397  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048439d  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004843a0  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004843a7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004843a9  b9803d5600             -mov ecx, 0x563d80
    cpu.ecx = 5651840 /*0x563d80*/;
    // 004843ae  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004843b1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004843b5  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004843b7  48                     -dec eax
    (cpu.eax)--;
    // 004843b8  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004843bb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004843bf  48                     -dec eax
    (cpu.eax)--;
    // 004843c0  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004843c3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004843c7  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004843cb  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004843ce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004843d0  7405                   -je 0x4843d7
    if (cpu.flags.zf)
    {
        goto L_0x004843d7;
    }
    // 004843d2  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x004843d7:
    // 004843d7  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004843da  8b15043f5600           -mov edx, dword ptr [0x563f04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 004843e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004843e1  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004843e4  6814fa4c00             -push 0x4cfa14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044756 /*0x4cfa14*/;
    cpu.esp -= 4;
    // 004843e9  a3043f5600             -mov dword ptr [0x563f04], eax
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.eax;
    // 004843ee  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004843f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004843f2  e80a210000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004843f7  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004843fe  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00484405  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00484408  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048440b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048440d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0048440f  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00484412  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00484415  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484418  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0048441a  8b15043f5600           -mov edx, dword ptr [0x563f04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 00484420  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484421  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00484424  6820fa4c00             -push 0x4cfa20
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044768 /*0x4cfa20*/;
    cpu.esp -= 4;
    // 00484429  891d043f5600           -mov dword ptr [0x563f04], ebx
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.ebx;
    // 0048442f  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00484432  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484433  e8c9200000             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00484438  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0048443f  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00484446  6681ce2080             -or si, 0x8020
    cpu.si |= x86::reg16(x86::sreg16(32800 /*0x8020*/));
    // 0048444b  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 0048444d  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00484450  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00484453  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484456  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00484458  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048445b  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048445e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00484461  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00484463  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484465  895a24                 -mov dword ptr [edx + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00484468  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484469  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048446a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048446b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484470  c7050cb24d0080104a00   -mov dword ptr [0x4db20c], 0x4a1080
    app->getMemory<x86::reg32>(x86::reg32(5091852) /* 0x4db20c */) = 4853888 /*0x4a1080*/;
    // 0048447a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48447c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048447c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048447d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00484482  e84d000000             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 00484487  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484488  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48448c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048448c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048448d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048448f  e840000000             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 00484494  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484495  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484498(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484498  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484499  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048449e  e831000000             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 004844a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844a5  7502                   -jne 0x4844a9
    if (!cpu.flags.zf)
    {
        goto L_0x004844a9;
    }
    // 004844a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004844a9:
    // 004844a9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004844ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4844b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004844b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004844b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004844b3  e81c000000             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 004844b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844ba  7502                   -jne 0x4844be
    if (!cpu.flags.zf)
    {
        goto L_0x004844be;
    }
    // 004844bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004844be:
    // 004844be  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004844c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004844c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4844c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004844c4  e80b000000             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 004844c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844cb  7503                   -jne 0x4844d0
    if (!cpu.flags.zf)
    {
        goto L_0x004844d0;
    }
    // 004844cd  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004844ce  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004844d0:
    // 004844d0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004844d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4844d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004844d0;
    // 004844c4  e80b000000             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 004844c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004844cb  7503                   -jne 0x4844d0
    if (!cpu.flags.zf)
    {
        goto L_0x004844d0;
    }
    // 004844cd  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004844ce  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004844d0:
L_entry_0x004844d0:
    // 004844d0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004844d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4844d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004844d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004844d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004844d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004844d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004844d9  8b3d003f5600           -mov edi, dword ptr [0x563f00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004844df  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004844e1  7407                   -je 0x4844ea
    if (cpu.flags.zf)
    {
        goto L_0x004844ea;
    }
    // 004844e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004844e5  e8d6fb0100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
L_0x004844ea:
    // 004844ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004844ec  e81f000000             -call 0x484510
    cpu.esp -= 4;
    sub_484510(app, cpu);
    if (cpu.terminate) return;
    // 004844f1  8b2d003f5600           -mov ebp, dword ptr [0x563f00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004844f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004844f9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004844fb  7506                   -jne 0x484503
    if (!cpu.flags.zf)
    {
        goto L_0x00484503;
    }
    // 004844fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004844ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484500  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484502  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484503:
    // 00484503  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484505  e8befb0100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 0048450a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048450c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048450d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048450e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048450f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484511  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484512  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484513  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00484516  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048451a  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048451e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00484520  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00484526  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00484529  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00484530  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00484532  b9803d5600             -mov ecx, 0x563d80
    cpu.ecx = 5651840 /*0x563d80*/;
    // 00484537  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048453a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048453c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484540  e88bfb0100             -call 0x4a40d0
    cpu.esp -= 4;
    sub_4a40d0(app, cpu);
    if (cpu.terminate) return;
    // 00484545  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484549  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0048454c  0f850a010000           -jne 0x48465c
    if (!cpu.flags.zf)
    {
        goto L_0x0048465c;
    }
    // 00484552  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484556  034114                 -add eax, dword ptr [ecx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 00484559  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048455c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048455e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00484561:
    // 00484561  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00484563  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00484565  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00484568  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048456a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048456c  0f84b6010000           -je 0x484728
    if (cpu.flags.zf)
    {
        goto L_0x00484728;
    }
    // 00484572  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484574  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00484579  3d00030000             +cmp eax, 0x300
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
    // 0048457e  0f84ee000000           -je 0x484672
    if (cpu.flags.zf)
    {
        goto L_0x00484672;
    }
    // 00484584  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00484587  0f85d2010000           -jne 0x48475f
    if (!cpu.flags.zf)
    {
        goto L_0x0048475f;
    }
    // 0048458d  833d04b24d0000         +cmp dword ptr [0x4db204], 0
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
    // 00484594  0f8542010000           -jne 0x4846dc
    if (!cpu.flags.zf)
    {
        goto L_0x004846dc;
    }
L_0x0048459a:
    // 0048459a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048459c  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0048459f  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004845a1  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004845a4  0f854a010000           -jne 0x4846f4
    if (!cpu.flags.zf)
    {
        goto L_0x004846f4;
    }
L_0x004845aa:
    // 004845aa  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004845ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004845ae  39c7                   +cmp edi, eax
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
L_0x004845b0:
    // 004845b0  0f824f010000           -jb 0x484705
    if (cpu.flags.cf)
    {
        goto L_0x00484705;
    }
    // 004845b6  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004845b8  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004845bb  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004845be  740c                   -je 0x4845cc
    if (cpu.flags.zf)
    {
        goto L_0x004845cc;
    }
    // 004845c0  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004845c3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004845c5  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004845c8  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 004845ca  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x004845cc:
    // 004845cc  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004845cf  0f8539010000           -jne 0x48470e
    if (!cpu.flags.zf)
    {
        goto L_0x0048470e;
    }
L_0x004845d5:
    // 004845d5  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004845d8  0f8c3a010000           -jl 0x484718
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484718;
    }
    // 004845de  8b2d043f5600           -mov ebp, dword ptr [0x563f04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 004845e4  8b1500b24d00           -mov edx, dword ptr [0x4db200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 004845ea  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004845ed  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004845f1  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004845f4  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004845f7  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004845fc  a3043f5600             -mov dword ptr [0x563f04], eax
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.eax;
    // 00484601  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484605  42                     -inc edx
    (cpu.edx)++;
    // 00484606  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00484609  891500b24d00           -mov dword ptr [0x4db200], edx
    app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */) = cpu.edx;
    // 0048460f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00484612  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00484616  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484619  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048461c  e8bb1e0000             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 00484621  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 00484624  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00484627  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048462a  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0048462d  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00484630  896820                 -mov dword ptr [eax + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00484633  896e24                 -mov dword ptr [esi + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00484636  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048463a  7407                   -je 0x484643
    if (cpu.flags.zf)
    {
        goto L_0x00484643;
    }
    // 0048463c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048463e  e8cdfa0100             -call 0x4a4110
    cpu.esp -= 4;
    sub_4a4110(app, cpu);
    if (cpu.terminate) return;
L_0x00484643:
    // 00484643  833d04b24d0000         +cmp dword ptr [0x4db204], 0
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
    // 0048464a  7405                   -je 0x484651
    if (cpu.flags.zf)
    {
        goto L_0x00484651;
    }
    // 0048464c  e8c3040000             -call 0x484b14
    cpu.esp -= 4;
    sub_484b14(app, cpu);
    if (cpu.terminate) return;
L_0x00484651:
    // 00484651  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00484655:
    // 00484655  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00484658  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484659  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048465a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048465b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048465c:
    // 0048465c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00484660  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00484663  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00484666  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00484668  01c2                   +add edx, eax
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
    // 0048466a  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048466d  e9effeffff             -jmp 0x484561
    goto L_0x00484561;
L_0x00484672:
    // 00484672  8b0d043f5600           -mov ecx, dword ptr [0x563f04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 00484678  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048467b  a3043f5600             -mov dword ptr [0x563f04], eax
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.eax;
    // 00484680  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484682  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00484685  e84a840100             -call 0x49cad4
    cpu.esp -= 4;
    sub_49cad4(app, cpu);
    if (cpu.terminate) return;
    // 0048468a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0048468c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048468e  74c5                   -je 0x484655
    if (cpu.flags.zf)
    {
        goto L_0x00484655;
    }
    // 00484690  8b1500b24d00           -mov edx, dword ptr [0x4db200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 00484696  895918                 -mov dword ptr [ecx + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00484699  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048469d  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004846a0  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004846a5  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004846a8  42                     -inc edx
    (cpu.edx)++;
    // 004846a9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004846ac  891500b24d00           -mov dword ptr [0x4db200], edx
    app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */) = cpu.edx;
    // 004846b2  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004846b5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004846b9  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004846bc  e81b1e0000             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 004846c1  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004846c4  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004846c7  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004846ca  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004846cd  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004846d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004846d2  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004846d5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004846d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004846d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004846da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004846db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004846dc:
    // 004846dc  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 004846df  0f85b5feffff           -jne 0x48459a
    if (!cpu.flags.zf)
    {
        goto L_0x0048459a;
    }
    // 004846e5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004846e7  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004846ea  e859fb0100             -call 0x4a4248
    cpu.esp -= 4;
    sub_4a4248(app, cpu);
    if (cpu.terminate) return;
    // 004846ef  e9a6feffff             -jmp 0x48459a
    goto L_0x0048459a;
L_0x004846f4:
    // 004846f4  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004846f7  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004846f9  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004846fc  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 004846fe  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484700  e9a5feffff             -jmp 0x4845aa
    goto L_0x004845aa;
L_0x00484705:
    // 00484705  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00484707  29fa                   +sub edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00484709  e9c7feffff             -jmp 0x4845d5
    goto L_0x004845d5;
L_0x0048470e:
    // 0048470e  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00484711  3b3e                   +cmp edi, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484713  e998feffff             -jmp 0x4845b0
    goto L_0x004845b0;
L_0x00484718:
    // 00484718  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048471b  7514                   -jne 0x484731
    if (!cpu.flags.zf)
    {
        goto L_0x00484731;
    }
    // 0048471d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048471f  e8e4fd0100             -call 0x4a4508
    cpu.esp -= 4;
    sub_4a4508(app, cpu);
    if (cpu.terminate) return;
    // 00484724  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484726  7528                   -jne 0x484750
    if (!cpu.flags.zf)
    {
        goto L_0x00484750;
    }
L_0x00484728:
    // 00484728  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048472a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048472d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048472e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048472f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484730  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484731:
    // 00484731  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00484733  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00484736  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00484739  7508                   -jne 0x484743
    if (!cpu.flags.zf)
    {
        goto L_0x00484743;
    }
L_0x0048473b:
    // 0048473b  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0048473e  e967feffff             -jmp 0x4845aa
    goto L_0x004845aa;
L_0x00484743:
    // 00484743  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00484746  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484748  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048474a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048474c  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048474e  ebeb                   -jmp 0x48473b
    goto L_0x0048473b;
L_0x00484750:
    // 00484750  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00484752  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00484755  e8eefa0100             -call 0x4a4248
    cpu.esp -= 4;
    sub_4a4248(app, cpu);
    if (cpu.terminate) return;
    // 0048475a  e93bfeffff             -jmp 0x48459a
    goto L_0x0048459a;
L_0x0048475f:
    // 0048475f  833d04b24d0000         +cmp dword ptr [0x4db204], 0
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
    // 00484766  0f85c8000000           -jne 0x484834
    if (!cpu.flags.zf)
    {
        goto L_0x00484834;
    }
L_0x0048476c:
    // 0048476c  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048476f  8b7724                 -mov esi, dword ptr [edi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00484772  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00484774  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00484777  0f85cf000000           -jne 0x48484c
    if (!cpu.flags.zf)
    {
        goto L_0x0048484c;
    }
L_0x0048477d:
    // 0048477d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048477f  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00484783:
    // 00484783  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00484785  034610                 -add eax, dword ptr [esi + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00484788  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0048478b  740c                   -je 0x484799
    if (cpu.flags.zf)
    {
        goto L_0x00484799;
    }
    // 0048478d  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00484790  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484792  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00484795  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00484797  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
L_0x00484799:
    // 00484799  39f8                   +cmp eax, edi
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
    // 0048479b  0f83b7000000           -jae 0x484858
    if (!cpu.flags.cf)
    {
        goto L_0x00484858;
    }
    // 004847a1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004847a3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004847a5  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x004847a9:
    // 004847a9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004847ad  3b0424                 +cmp eax, dword ptr [esp]
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
    // 004847b0  0f8cc0000000           -jl 0x484876
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484876;
    }
    // 004847b6  8b2d043f5600           -mov ebp, dword ptr [0x563f04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 004847bc  8b1500b24d00           -mov edx, dword ptr [0x4db200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 004847c2  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004847c5  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004847c9  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004847cc  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004847cf  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004847d4  a3043f5600             -mov dword ptr [0x563f04], eax
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.eax;
    // 004847d9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004847dd  42                     -inc edx
    (cpu.edx)++;
    // 004847de  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004847e1  891500b24d00           -mov dword ptr [0x4db200], edx
    app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */) = cpu.edx;
    // 004847e7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004847ea  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004847ee  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004847f1  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004847f4  e8e31c0000             -call 0x4864dc
    cpu.esp -= 4;
    sub_4864dc(app, cpu);
    if (cpu.terminate) return;
    // 004847f9  2b3c24                 -sub edi, dword ptr [esp]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004847fc  897524                 -mov dword ptr [ebp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004847ff  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 00484802  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00484805  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00484808  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 0048480b  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0048480e  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484812  7407                   -je 0x48481b
    if (cpu.flags.zf)
    {
        goto L_0x0048481b;
    }
    // 00484814  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00484816  e8f5f80100             -call 0x4a4110
    cpu.esp -= 4;
    sub_4a4110(app, cpu);
    if (cpu.terminate) return;
L_0x0048481b:
    // 0048481b  833d04b24d0000         +cmp dword ptr [0x4db204], 0
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
    // 00484822  7405                   -je 0x484829
    if (cpu.flags.zf)
    {
        goto L_0x00484829;
    }
    // 00484824  e8eb020000             -call 0x484b14
    cpu.esp -= 4;
    sub_484b14(app, cpu);
    if (cpu.terminate) return;
L_0x00484829:
    // 00484829  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048482d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00484830  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484831  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484832  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484833  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484834:
    // 00484834  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00484837  0f852fffffff           -jne 0x48476c
    if (!cpu.flags.zf)
    {
        goto L_0x0048476c;
    }
    // 0048483d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048483f  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00484842  e811fb0100             -call 0x4a4358
    cpu.esp -= 4;
    sub_4a4358(app, cpu);
    if (cpu.terminate) return;
    // 00484847  e920ffffff             -jmp 0x48476c
    goto L_0x0048476c;
L_0x0048484c:
    // 0048484c  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048484f  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00484851  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484853  e925ffffff             -jmp 0x48477d
    goto L_0x0048477d;
L_0x00484858:
    // 00484858  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048485a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0048485d  7407                   -je 0x484866
    if (cpu.flags.zf)
    {
        goto L_0x00484866;
    }
    // 0048485f  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00484862  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00484864  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484866:
    // 00484866  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484868  0f843bffffff           -je 0x4847a9
    if (cpu.flags.zf)
    {
        goto L_0x004847a9;
    }
    // 0048486e  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00484871  e90dffffff             -jmp 0x484783
    goto L_0x00484783;
L_0x00484876:
    // 00484876  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484878  7418                   -je 0x484892
    if (cpu.flags.zf)
    {
        goto L_0x00484892;
    }
    // 0048487a  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048487c  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0048487f  7508                   -jne 0x484889
    if (!cpu.flags.zf)
    {
        goto L_0x00484889;
    }
L_0x00484881:
    // 00484881  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00484884  e9f4feffff             -jmp 0x48477d
    goto L_0x0048477d;
L_0x00484889:
    // 00484889  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048488c  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0048488e  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484890  ebef                   -jmp 0x484881
    goto L_0x00484881;
L_0x00484892:
    // 00484892  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484894  e86ffc0100             -call 0x4a4508
    cpu.esp -= 4;
    sub_4a4508(app, cpu);
    if (cpu.terminate) return;
    // 00484899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048489b  0f8487feffff           -je 0x484728
    if (cpu.flags.zf)
    {
        goto L_0x00484728;
    }
    // 004848a1  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004848a4  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004848a6  e8adfa0100             -call 0x4a4358
    cpu.esp -= 4;
    sub_4a4358(app, cpu);
    if (cpu.terminate) return;
    // 004848ab  e9bcfeffff             -jmp 0x48476c
    goto L_0x0048476c;
}

/* align: skip  */
void Application::sub_4848b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004848b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004848b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004848b2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004848b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004848b6  742e                   -je 0x4848e6
    if (cpu.flags.zf)
    {
        goto L_0x004848e6;
    }
    // 004848b8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004848ba:
    // 004848ba  8b93843d5600           -mov edx, dword ptr [ebx + 0x563d84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5651844) /* 0x563d84 */);
    // 004848c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004848c2  7417                   -je 0x4848db
    if (cpu.flags.zf)
    {
        goto L_0x004848db;
    }
    // 004848c4  8b83803d5600           -mov eax, dword ptr [ebx + 0x563d80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5651840) /* 0x563d80 */);
L_0x004848ca:
    // 004848ca  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004848cd  3b08                   +cmp ecx, dword ptr [eax]
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
    // 004848cf  7404                   -je 0x4848d5
    if (cpu.flags.zf)
    {
        goto L_0x004848d5;
    }
    // 004848d1  39d0                   +cmp eax, edx
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
    // 004848d3  75f5                   -jne 0x4848ca
    if (!cpu.flags.zf)
    {
        goto L_0x004848ca;
    }
L_0x004848d5:
    // 004848d5  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 004848d9  740d                   -je 0x4848e8
    if (cpu.flags.zf)
    {
        goto L_0x004848e8;
    }
L_0x004848db:
    // 004848db  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004848de  81fb80010000           +cmp ebx, 0x180
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004848e4  7cd4                   -jl 0x4848ba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004848ba;
    }
L_0x004848e6:
    // 004848e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004848e8:
    // 004848e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4848ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004848ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004848ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004848f2  e8b9ffffff             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    if (cpu.terminate) return;
    // 004848f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004848f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4848fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004848fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004848fd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484902  e8a9ffffff             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    if (cpu.terminate) return;
    // 00484907  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484909  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 0048490e  e8adf70100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484913  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484915  e82e000000             -call 0x484948
    cpu.esp -= 4;
    sub_484948(app, cpu);
    if (cpu.terminate) return;
    // 0048491a  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 0048491f  e8a4f70100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484924  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484925  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484928(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484928  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484929  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048492b  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484930  e88bf70100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484935  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484937  e80c000000             -call 0x484948
    cpu.esp -= 4;
    sub_484948(app, cpu);
    if (cpu.terminate) return;
    // 0048493c  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484941  e882f70100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484946  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484947  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484948(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484948  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484949  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048494b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048494d  743a                   -je 0x484989
    if (cpu.flags.zf)
    {
        goto L_0x00484989;
    }
    // 0048494f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484951  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00484954  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484957  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0048495a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048495c  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0048495f  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00484962  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484965  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0048496b  81f900030000           +cmp ecx, 0x300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484971  7418                   -je 0x48498b
    if (cpu.flags.zf)
    {
        goto L_0x0048498b;
    }
L_0x00484973:
    // 00484973  a1043f5600             -mov eax, dword ptr [0x563f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 00484978  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0048497e  8915043f5600           -mov dword ptr [0x563f04], edx
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.edx;
    // 00484984  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00484987  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484988  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484989:
    // 00484989  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048498a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048498b:
    // 0048498b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048498d  e8a6810100             -call 0x49cb38
    cpu.esp -= 4;
    sub_49cb38(app, cpu);
    if (cpu.terminate) return;
    // 00484992  ebdf                   -jmp 0x484973
    goto L_0x00484973;
}

/* align: skip  */
void Application::sub_484994(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484994  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484995  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048499a  e811ffffff             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    if (cpu.terminate) return;
    // 0048499f  e804000000             -call 0x4849a8
    cpu.esp -= 4;
    sub_4849a8(app, cpu);
    if (cpu.terminate) return;
    // 004849a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4849a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004849a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004849a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004849ab  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004849b0  e80bf70100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004849b5  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004849b8  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 004849bc  7512                   -jne 0x4849d0
    if (!cpu.flags.zf)
    {
        goto L_0x004849d0;
    }
L_0x004849be:
    // 004849be  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004849c1  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004849c4  e87fffffff             -call 0x484948
    cpu.esp -= 4;
    sub_484948(app, cpu);
    if (cpu.terminate) return;
    // 004849c9  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 004849cd  74ef                   -je 0x4849be
    if (cpu.flags.zf)
    {
        goto L_0x004849be;
    }
    // 004849cf  90                     -nop 
    ;
L_0x004849d0:
    // 004849d0  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004849d5  e8eef60100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004849da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4849dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004849dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004849dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004849df  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004849e4  e8d7f60100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 004849e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004849eb  e810000000             -call 0x484a00
    cpu.esp -= 4;
    sub_484a00(app, cpu);
    if (cpu.terminate) return;
    // 004849f0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004849f2  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 004849f7  e8ccf60100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 004849fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004849fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004849ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484a00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484a01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484a02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484a03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484a04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484a05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484a06  8b3500b24d00           -mov esi, dword ptr [0x4db200]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 00484a0c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484a0e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484a10  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00484a16  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00484a19  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00484a20  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00484a22  bd803d5600             -mov ebp, 0x563d80
    cpu.ebp = 5651840 /*0x563d80*/;
    // 00484a27  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00484a2a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484a2c  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00484a2f  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00484a32  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00484a34  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00484a37  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484a3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484a3c  39d0                   +cmp eax, edx
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
    // 00484a3e  7429                   -je 0x484a69
    if (cpu.flags.zf)
    {
        goto L_0x00484a69;
    }
L_0x00484a40:
    // 00484a40  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00484a44  741b                   -je 0x484a61
    if (cpu.flags.zf)
    {
        goto L_0x00484a61;
    }
    // 00484a46  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484a49  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00484a4c  39ca                   +cmp edx, ecx
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
    // 00484a4e  7632                   -jbe 0x484a82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00484a82;
    }
L_0x00484a50:
    // 00484a50  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484a52  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00484a54  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00484a57  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484a5a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484a5c  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00484a5f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00484a61:
    // 00484a61  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484a64  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484a67  75d7                   -jne 0x484a40
    if (!cpu.flags.zf)
    {
        goto L_0x00484a40;
    }
L_0x00484a69:
    // 00484a69  893500b24d00           -mov dword ptr [0x4db200], esi
    app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */) = cpu.esi;
    // 00484a6f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00484a71  751c                   -jne 0x484a8f
    if (!cpu.flags.zf)
    {
        goto L_0x00484a8f;
    }
    // 00484a73  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484a75  8b3500b24d00           -mov esi, dword ptr [0x4db200]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 00484a7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484a81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484a82:
    // 00484a82  75dd                   -jne 0x484a61
    if (!cpu.flags.zf)
    {
        goto L_0x00484a61;
    }
    // 00484a84  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00484a86  2b501c                 -sub edx, dword ptr [eax + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 00484a89  39da                   +cmp edx, ebx
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
    // 00484a8b  73c3                   -jae 0x484a50
    if (!cpu.flags.cf)
    {
        goto L_0x00484a50;
    }
    // 00484a8d  ebd2                   -jmp 0x484a61
    goto L_0x00484a61;
L_0x00484a8f:
    // 00484a8f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00484a91  e8b2feffff             -call 0x484948
    cpu.esp -= 4;
    sub_484948(app, cpu);
    if (cpu.terminate) return;
    // 00484a96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484a9b  8b3500b24d00           -mov esi, dword ptr [0x4db200]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091840) /* 0x4db200 */);
    // 00484aa1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aa2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aa4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aa5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aa6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484aa7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484aa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484aa8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484aa9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484aaa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484aab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484aac  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484aae  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00484ab4  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00484ab7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00484abe  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00484ac0  bf803d5600             -mov edi, 0x563d80
    cpu.edi = 5651840 /*0x563d80*/;
    // 00484ac5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00484ac8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484aca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484acc  e8fff50100             -call 0x4a40d0
    cpu.esp -= 4;
    sub_4a40d0(app, cpu);
    if (cpu.terminate) return;
    // 00484ad1  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00484ad3  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00484ad6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484ad8  39d1                   +cmp ecx, edx
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
    // 00484ada  741b                   -je 0x484af7
    if (cpu.flags.zf)
    {
        goto L_0x00484af7;
    }
L_0x00484adc:
    // 00484adc  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00484ae1  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00484ae4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484ae6  e8556e0000             -call 0x48b940
    cpu.esp -= 4;
    sub_48b940(app, cpu);
    if (cpu.terminate) return;
    // 00484aeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484aed  740f                   -je 0x484afe
    if (cpu.flags.zf)
    {
        goto L_0x00484afe;
    }
    // 00484aef  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00484af2  3b4f04                 +cmp ecx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484af5  75e5                   -jne 0x484adc
    if (!cpu.flags.zf)
    {
        goto L_0x00484adc;
    }
L_0x00484af7:
    // 00484af7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484af9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484afa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484afb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484afc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484afd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484afe:
    // 00484afe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484b00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484b08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b08  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b09  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484b0b  e898ffffff             -call 0x484aa8
    cpu.esp -= 4;
    sub_484aa8(app, cpu);
    if (cpu.terminate) return;
    // 00484b10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484b14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b14  833d08b24d0000         +cmp dword ptr [0x4db208], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5091848) /* 0x4db208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484b1b  7503                   -jne 0x484b20
    if (!cpu.flags.zf)
    {
        goto L_0x00484b20;
    }
    // 00484b1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484b1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484b20:
    // 00484b20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484b22  e83d000000             -call 0x484b64
    cpu.esp -= 4;
    sub_484b64(app, cpu);
    if (cpu.terminate) return;
    // 00484b27  3b050c3f5600           +cmp eax, dword ptr [0x563f0c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5652236) /* 0x563f0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484b2d  7d05                   -jge 0x484b34
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484b34;
    }
    // 00484b2f  a30c3f5600             -mov dword ptr [0x563f0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5652236) /* 0x563f0c */) = cpu.eax;
L_0x00484b34:
    // 00484b34  a10c3f5600             -mov eax, dword ptr [0x563f0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652236) /* 0x563f0c */);
    // 00484b39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484b3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484b3e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00484b40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484b43  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484b48  e873f50100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484b4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484b4f  e810000000             -call 0x484b64
    cpu.esp -= 4;
    sub_484b64(app, cpu);
    if (cpu.terminate) return;
    // 00484b54  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484b56  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484b5b  e868f50100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484b60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484b62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484b63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484b64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484b64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484b65  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484b66  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484b67  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00484b6c  3d00030000             +cmp eax, 0x300
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
    // 00484b71  7456                   -je 0x484bc9
    if (cpu.flags.zf)
    {
        goto L_0x00484bc9;
    }
    // 00484b73  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00484b76  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484b78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00484b7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00484b7d  be803d5600             -mov esi, 0x563d80
    cpu.esi = 5651840 /*0x563d80*/;
    // 00484b82  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00484b85  8b1504b24d00           -mov edx, dword ptr [0x4db204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091844) /* 0x4db204 */);
    // 00484b8b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484b8d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484b8f  7541                   -jne 0x484bd2
    if (!cpu.flags.zf)
    {
        goto L_0x00484bd2;
    }
L_0x00484b91:
    // 00484b91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484b92  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484b93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484b94  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00484b96  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00484b99  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484b9b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00484b9e  8b7f20                 -mov edi, dword ptr [edi + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00484ba1:
    // 00484ba1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00484ba3  2b11                   -sub edx, dword ptr [ecx]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 00484ba5  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00484ba8  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00484bab  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00484bad  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484baf  39da                   +cmp edx, ebx
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
    // 00484bb1  7e02                   -jle 0x484bb5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484bb5;
    }
    // 00484bb3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00484bb5:
    // 00484bb5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484bb7  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484bba  39f8                   +cmp eax, edi
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
    // 00484bbc  75e3                   -jne 0x484ba1
    if (!cpu.flags.zf)
    {
        goto L_0x00484ba1;
    }
    // 00484bbe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00484bc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00484bc3:
    // 00484bc3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484bc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484bc9:
    // 00484bc9  e8e2fb0100             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 00484bce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484bd0  ebf1                   -jmp 0x484bc3
    goto L_0x00484bc3;
L_0x00484bd2:
    // 00484bd2  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00484bd4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00484bd7  e86cf60100             -call 0x4a4248
    cpu.esp -= 4;
    sub_4a4248(app, cpu);
    if (cpu.terminate) return;
    // 00484bdc  ebb3                   -jmp 0x484b91
    goto L_0x00484b91;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484be0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484be1  8b15ecb14d00           -mov edx, dword ptr [0x4db1ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 00484be7  81fac83d5600           +cmp edx, 0x563dc8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5651912 /*0x563dc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484bed  741c                   -je 0x484c0b
    if (cpu.flags.zf)
    {
        goto L_0x00484c0b;
    }
    // 00484bef  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00484bf1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484bf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484bf5  7410                   -je 0x484c07
    if (cpu.flags.zf)
    {
        goto L_0x00484c07;
    }
L_0x00484bf7:
    // 00484bf7  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00484bfb  7503                   -jne 0x484c00
    if (!cpu.flags.zf)
    {
        goto L_0x00484c00;
    }
    // 00484bfd  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00484c00:
    // 00484c00  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484c03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484c05  75f0                   -jne 0x484bf7
    if (!cpu.flags.zf)
    {
        goto L_0x00484bf7;
    }
L_0x00484c07:
    // 00484c07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484c09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484c0b:
    // 00484c0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484c11  8b15ecb14d00           -mov edx, dword ptr [0x4db1ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 00484c17  81fac83d5600           +cmp edx, 0x563dc8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5651912 /*0x563dc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c1d  741c                   -je 0x484c3b
    if (cpu.flags.zf)
    {
        goto L_0x00484c3b;
    }
    // 00484c1f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00484c21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484c23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484c25  7410                   -je 0x484c37
    if (cpu.flags.zf)
    {
        goto L_0x00484c37;
    }
L_0x00484c27:
    // 00484c27  f6401810               +test byte ptr [eax + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 00484c2b  7403                   -je 0x484c30
    if (cpu.flags.zf)
    {
        goto L_0x00484c30;
    }
    // 00484c2d  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00484c30:
    // 00484c30  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484c33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484c35  75f0                   -jne 0x484c27
    if (!cpu.flags.zf)
    {
        goto L_0x00484c27;
    }
L_0x00484c37:
    // 00484c37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484c39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484c3b:
    // 00484c3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484c41  8b15ecb14d00           -mov edx, dword ptr [0x4db1ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 00484c47  81fac83d5600           +cmp edx, 0x563dc8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5651912 /*0x563dc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c4d  741c                   -je 0x484c6b
    if (cpu.flags.zf)
    {
        goto L_0x00484c6b;
    }
    // 00484c4f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00484c51  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484c53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484c55  7410                   -je 0x484c67
    if (cpu.flags.zf)
    {
        goto L_0x00484c67;
    }
L_0x00484c57:
    // 00484c57  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00484c5b  7403                   -je 0x484c60
    if (cpu.flags.zf)
    {
        goto L_0x00484c60;
    }
    // 00484c5d  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00484c60:
    // 00484c60  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484c63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00484c65  75f0                   -jne 0x484c57
    if (!cpu.flags.zf)
    {
        goto L_0x00484c57;
    }
L_0x00484c67:
    // 00484c67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484c69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484c6b:
    // 00484c6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484c6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484c70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484c71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484c72  8b35ecb14d00           -mov esi, dword ptr [0x4db1ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 00484c78  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484c7a  81fec83d5600           +cmp esi, 0x563dc8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5651912 /*0x563dc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484c80  7420                   -je 0x484ca2
    if (cpu.flags.zf)
    {
        goto L_0x00484ca2;
    }
    // 00484c82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484c83  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484c84  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00484c86  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
L_0x00484c89:
    // 00484c89  3b4604                 +cmp eax, dword ptr [esi + 4]
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
    // 00484c8c  7422                   -je 0x484cb0
    if (cpu.flags.zf)
    {
        goto L_0x00484cb0;
    }
    // 00484c8e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00484c90  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00484c93  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00484c95  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484c97  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00484c99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00484c9b  01d9                   +add ecx, ebx
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
    // 00484c9d  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00484ca0  ebe7                   -jmp 0x484c89
    goto L_0x00484c89;
L_0x00484ca2:
    // 00484ca2  e809fb0100             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 00484ca7  8b35ecb14d00           -mov esi, dword ptr [0x4db1ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 00484cad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484caf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484cb0:
    // 00484cb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484cb2  8935ecb14d00           -mov dword ptr [0x4db1ec], esi
    app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */) = cpu.esi;
    // 00484cb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cb9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cba  8b35ecb14d00           -mov esi, dword ptr [0x4db1ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091820) /* 0x4db1ec */);
    // 00484cc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484cc2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484cc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484cc4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484cc5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484cc6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484cc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484cc9  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00484ccf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00484cd1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484cd3  81fa00030000           +cmp edx, 0x300
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
    // 00484cd9  7450                   -je 0x484d2b
    if (cpu.flags.zf)
    {
        goto L_0x00484d2b;
    }
    // 00484cdb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484cdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484cdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484cde  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00484ce1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484ce3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00484ce6  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484ce8  bf803d5600             -mov edi, 0x563d80
    cpu.edi = 5651840 /*0x563d80*/;
    // 00484ced  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00484cf0  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00484cf2  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00484cf4  8b7704                 -mov esi, dword ptr [edi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00484cf7  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00484cfa  39f1                   +cmp ecx, esi
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
    // 00484cfc  7424                   -je 0x484d22
    if (cpu.flags.zf)
    {
        goto L_0x00484d22;
    }
L_0x00484cfe:
    // 00484cfe  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00484d00  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00484d03  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00484d05  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484d07  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484d09  8a4a18                 -mov cl, byte ptr [edx + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00484d0c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00484d0e  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00484d11  7421                   -je 0x484d34
    if (cpu.flags.zf)
    {
        goto L_0x00484d34;
    }
    // 00484d13  034210                 -add eax, dword ptr [edx + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
L_0x00484d16:
    // 00484d16  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484d18  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00484d1b  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00484d1e  39e9                   +cmp ecx, ebp
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
    // 00484d20  75dc                   -jne 0x484cfe
    if (!cpu.flags.zf)
    {
        goto L_0x00484cfe;
    }
L_0x00484d22:
    // 00484d22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484d24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484d2b:
    // 00484d2b  e880fa0100             -call 0x4a47b0
    cpu.esp -= 4;
    sub_4a47b0(app, cpu);
    if (cpu.terminate) return;
    // 00484d30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484d34:
    // 00484d34  39d8                   +cmp eax, ebx
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
    // 00484d36  7e02                   -jle 0x484d3a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484d3a;
    }
    // 00484d38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00484d3a:
    // 00484d3a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00484d3c  ebd8                   -jmp 0x484d16
    goto L_0x00484d16;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484d40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484d41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484d42  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484d44  a3043f5600             -mov dword ptr [0x563f04], eax
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.eax;
    // 00484d49  49                     -dec ecx
    (cpu.ecx)--;
    // 00484d4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484d4c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484d4e  7e10                   -jle 0x484d60
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484d60;
    }
L_0x00484d50:
    // 00484d50  8d5828                 -lea ebx, [eax + 0x28]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00484d53  42                     -inc edx
    (cpu.edx)++;
    // 00484d54  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00484d57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00484d59  39ca                   +cmp edx, ecx
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
    // 00484d5b  7cf3                   -jl 0x484d50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484d50;
    }
    // 00484d5d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00484d60:
    // 00484d60  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00484d67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484d6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484d6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484d6d  8b15043f5600           -mov edx, dword ptr [0x563f04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 00484d73  a3043f5600             -mov dword ptr [0x563f04], eax
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.eax;
    // 00484d78  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00484d7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484d80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484d81  a1043f5600             -mov eax, dword ptr [0x563f04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */);
    // 00484d86  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484d89  8915043f5600           -mov dword ptr [0x563f04], edx
    app->getMemory<x86::reg32>(x86::reg32(5652228) /* 0x563f04 */) = cpu.edx;
    // 00484d8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484d90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484d94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484d94  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484d95  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484d9a  e811fbffff             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    if (cpu.terminate) return;
    // 00484d9f  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00484da2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484da3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484da4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484da4  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00484da7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484da8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484da8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484dab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484dac  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484daf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484db1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484db3  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484db8  e803f30100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484dbd  806218ef               -and byte ptr [edx + 0x18], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00484dc1  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484dc6  e8fdf20100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484dcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484dcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484dd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484dd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00484dd3  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484dd8  e8e3f20100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484ddd  804a1810               -or byte ptr [edx + 0x18], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00484de1  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484de6  e8ddf20100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484deb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484df1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484df3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484df8  e8b3faffff             -call 0x4848b0
    cpu.esp -= 4;
    sub_4848b0(app, cpu);
    if (cpu.terminate) return;
    // 00484dfd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00484dff  e804000000             -call 0x484e08
    cpu.esp -= 4;
    sub_484e08(app, cpu);
    if (cpu.terminate) return;
    // 00484e04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_484e08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484e0b  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484e10  e8abf20100             -call 0x4a40c0
    cpu.esp -= 4;
    sub_4a40c0(app, cpu);
    if (cpu.terminate) return;
    // 00484e15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484e17  e80c000000             -call 0x484e28
    cpu.esp -= 4;
    sub_484e28(app, cpu);
    if (cpu.terminate) return;
    // 00484e1c  a1003f5600             -mov eax, dword ptr [0x563f00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652224) /* 0x563f00 */);
    // 00484e21  e8a2f20100             -call 0x4a40c8
    cpu.esp -= 4;
    sub_4a40c8(app, cpu);
    if (cpu.terminate) return;
    // 00484e26  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_484e28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e29  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484e2b  7405                   -je 0x484e32
    if (cpu.flags.zf)
    {
        goto L_0x00484e32;
    }
    // 00484e2d  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x00484e32:
    // 00484e32  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00484e35  80e5df                 -and ch, 0xdf
    cpu.ch &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 00484e38  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00484e3a  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00484e3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_484e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484e42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484e43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484e44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484e45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00484e47  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00484e49:
    // 00484e49  8b96843d5600           -mov edx, dword ptr [esi + 0x563d84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651844) /* 0x563d84 */);
    // 00484e4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484e51  7421                   -je 0x484e74
    if (cpu.flags.zf)
    {
        goto L_0x00484e74;
    }
    // 00484e53  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00484e55  8b86803d5600           -mov eax, dword ptr [esi + 0x563d80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5651840) /* 0x563d80 */);
L_0x00484e5b:
    // 00484e5b  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00484e5e  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00484e60  39f9                   +cmp ecx, edi
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
    // 00484e62  7223                   -jb 0x484e87
    if (cpu.flags.cf)
    {
        goto L_0x00484e87;
    }
    // 00484e64  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00484e67  8d142f                 -lea edx, [edi + ebp]
    cpu.edx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 00484e6a  39d1                   +cmp ecx, edx
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
    // 00484e6c  7319                   -jae 0x484e87
    if (!cpu.flags.cf)
    {
        goto L_0x00484e87;
    }
L_0x00484e6e:
    // 00484e6e  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 00484e72  740d                   -je 0x484e81
    if (cpu.flags.zf)
    {
        goto L_0x00484e81;
    }
L_0x00484e74:
    // 00484e74  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00484e77  81fe80010000           +cmp esi, 0x180
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
    // 00484e7d  7cca                   -jl 0x484e49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484e49;
    }
    // 00484e7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00484e81:
    // 00484e81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484e87:
    // 00484e87  39d8                   +cmp eax, ebx
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
    // 00484e89  75d0                   -jne 0x484e5b
    if (!cpu.flags.zf)
    {
        goto L_0x00484e5b;
    }
    // 00484e8b  ebe1                   -jmp 0x484e6e
    goto L_0x00484e6e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484e90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484e91  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484e96  e8a5ffffff             -call 0x484e40
    cpu.esp -= 4;
    sub_484e40(app, cpu);
    if (cpu.terminate) return;
    // 00484e9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484e9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484ea0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484ea1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00484ea3  e898ffffff             -call 0x484e40
    cpu.esp -= 4;
    sub_484e40(app, cpu);
    if (cpu.terminate) return;
    // 00484ea8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484ea9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_484ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00484ef0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484ef1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00484ef2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00484ef3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00484ef5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00484ef7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00484ef9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00484efb  7411                   -je 0x484f0e
    if (cpu.flags.zf)
    {
        goto L_0x00484f0e;
    }
    // 00484efd  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00484eff:
    // 00484eff  48                     -dec eax
    (cpu.eax)--;
    // 00484f00  83f8ff                 +cmp eax, -1
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
    // 00484f03  7409                   -je 0x484f0e
    if (cpu.flags.zf)
    {
        goto L_0x00484f0e;
    }
    // 00484f05  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00484f06  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00484f08  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00484f09  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00484f0c  ebf1                   -jmp 0x484eff
    goto L_0x00484eff;
L_0x00484f0e:
    // 00484f0e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00484f10  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00484f12  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00484f14  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00484f17  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00484f19  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00484f1b  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 00484f1e  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00484f21  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00484f24  83fe0f                 +cmp esi, 0xf
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
    // 00484f27  0f87c6000000           -ja 0x484ff3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00484ff3;
    }
    // 00484f2d  ff24b5b04e4800         -jmp dword ptr [esi*4 + 0x484eb0]
    cpu.ip = app->getMemory<x86::reg32>(4738736 + cpu.esi * 4); goto dynamic_jump;
  case 0x00484f34:
L_0x00484f34:
    // 00484f34  4d                     -dec ebp
    (cpu.ebp)--;
    // 00484f35  83fdff                 +cmp ebp, -1
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
    // 00484f38  0f84b5000000           -je 0x484ff3
    if (cpu.flags.zf)
    {
        goto L_0x00484ff3;
    }
    // 00484f3e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f41  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f43  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f46  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00484f49:
    // 00484f49  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f4c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f4e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f51  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484f54:
    // 00484f54  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f57  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f59  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f5c  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484f5f:
    // 00484f5f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f62  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f64  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f67  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484f6a:
    // 00484f6a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f6d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f6f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f72  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484f75:
    // 00484f75  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f78  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f7a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f7d  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00484f80:
    // 00484f80  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f83  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f85  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f88  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484f8b:
    // 00484f8b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f8e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f90  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f93  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484f96:
    // 00484f96  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f99  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484f9b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484f9e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484fa1:
    // 00484fa1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fa4  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fa6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fa9  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484fac:
    // 00484fac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484faf  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fb1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fb4  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00484fb7:
    // 00484fb7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fba  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fbc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fbf  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00484fc2:
    // 00484fc2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fc5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fc7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fca  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00484fcd:
    // 00484fcd  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fd0  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fd2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fd5  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00484fd8:
    // 00484fd8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fdb  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fdd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fe0  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00484fe3:
    // 00484fe3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00484fe6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00484fe8  83c204                 +add edx, 4
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
    // 00484feb  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00484fee  e941ffffff             -jmp 0x484f34
    goto L_0x00484f34;
L_0x00484ff3:
    // 00484ff3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00484ff5:
    // 00484ff5  4b                     -dec ebx
    (cpu.ebx)--;
    // 00484ff6  83fbff                 +cmp ebx, -1
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
    // 00484ff9  740d                   -je 0x485008
    if (cpu.flags.zf)
    {
        goto L_0x00485008;
    }
    // 00484ffb  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 00484ffe  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 00485001  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00485003  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00485004  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 00485006  ebed                   -jmp 0x484ff5
    goto L_0x00484ff5;
L_0x00485008:
    // 00485008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485009  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048500a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048500b  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_48500c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048500c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048500d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048500e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485010  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00485012  83fb04                 +cmp ebx, 4
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
    // 00485015  7d13                   -jge 0x48502a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048502a;
    }
L_0x00485017:
    // 00485017  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00485019  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048501b:
    // 0048501b  4b                     -dec ebx
    (cpu.ebx)--;
    // 0048501c  83fbff                 +cmp ebx, -1
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
    // 0048501f  742a                   -je 0x48504b
    if (cpu.flags.zf)
    {
        goto L_0x0048504b;
    }
    // 00485021  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485022  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00485025  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00485026  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00485028  ebf1                   -jmp 0x48501b
    goto L_0x0048501b;
L_0x0048502a:
    // 0048502a  39c2                   +cmp edx, eax
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
    // 0048502c  7607                   -jbe 0x485035
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00485035;
    }
    // 0048502e  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00485031  39ca                   +cmp edx, ecx
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
    // 00485033  72e2                   -jb 0x485017
    if (cpu.flags.cf)
    {
        goto L_0x00485017;
    }
L_0x00485035:
    // 00485035  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485037  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 0048503c  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048503f  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485041  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00485043  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00485046  e8a5feffff             -call 0x484ef0
    cpu.esp -= 4;
    sub_484ef0(app, cpu);
    if (cpu.terminate) return;
L_0x0048504b:
    // 0048504b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048504c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048504d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485050  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485051  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00485053  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 00485055  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485057  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485059  e8aeffffff             -call 0x48500c
    cpu.esp -= 4;
    sub_48500c(app, cpu);
    if (cpu.terminate) return;
    // 0048505e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048505f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485061  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00485063  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485065  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485067  e8a0ffffff             -call 0x48500c
    cpu.esp -= 4;
    sub_48500c(app, cpu);
    if (cpu.terminate) return;
    // 0048506c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048506d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485070  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485071  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00485073  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485075  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00485077  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485079  e88effffff             -call 0x48500c
    cpu.esp -= 4;
    sub_48500c(app, cpu);
    if (cpu.terminate) return;
    // 0048507e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048507f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485082  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485084  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00485086  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00485088  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0048508b  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048508d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048508f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485091  e876ffffff             -call 0x48500c
    cpu.esp -= 4;
    sub_48500c(app, cpu);
    if (cpu.terminate) return;
    // 00485096  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485097  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485098  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48509c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048509c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048509d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048509f  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004850a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004850a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004850a6  e861ffffff             -call 0x48500c
    cpu.esp -= 4;
    sub_48500c(app, cpu);
    if (cpu.terminate) return;
    // 004850ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4850b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004850b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004850b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004850b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004850b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004850b4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004850b6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004850b8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004850ba  b91cb24d00             -mov ecx, 0x4db21c
    cpu.ecx = 5091868 /*0x4db21c*/;
    // 004850bf  e8f8bf0100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 004850c4  6681660c00f0           -and word ptr [esi + 0xc], 0xf000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 004850ca  81e7ff0f0000           -and edi, 0xfff
    cpu.edi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004850d0  097e0c                 -or dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
    // 004850d3  668b5e0e               -mov bx, word ptr [esi + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004850d7  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004850dd  81e5ff0f0000           -and ebp, 0xfff
    cpu.ebp &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004850e3  66895e0e               -mov word ptr [esi + 0xe], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 004850e7  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004850ea  096e0c                 -or dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004850ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004850f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4850f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004850f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004850f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004850f6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004850f9  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004850fc  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004850ff  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00485102  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00485105  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00485108  e8a3ffffff             -call 0x4850b0
    cpu.esp -= 4;
    sub_4850b0(app, cpu);
    if (cpu.terminate) return;
    // 0048510d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048510e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048510f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485110  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485111  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485114  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00485117  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485119  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0048511c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048511f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485121  e88affffff             -call 0x4850b0
    cpu.esp -= 4;
    sub_4850b0(app, cpu);
    if (cpu.terminate) return;
    // 00485126  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485127  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485128  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485129  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048512a  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048512d  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00485130  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00485133  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00485136  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00485139  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0048513c  e86fffffff             -call 0x4850b0
    cpu.esp -= 4;
    sub_4850b0(app, cpu);
    if (cpu.terminate) return;
    // 00485141  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485142  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485143  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485144  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485145  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485148  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048514b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048514d  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00485150  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00485153  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485155  e856ffffff             -call 0x4850b0
    cpu.esp -= 4;
    sub_4850b0(app, cpu);
    if (cpu.terminate) return;
    // 0048515a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048515b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_485160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485160  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485161  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485163  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0048516a  7507                   -jne 0x485173
    if (!cpu.flags.zf)
    {
        goto L_0x00485173;
    }
    // 0048516c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00485171  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485172  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485173:
    // 00485173  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485175  e89a110000             -call 0x486314
    cpu.esp -= 4;
    sub_486314(app, cpu);
    if (cpu.terminate) return;
    // 0048517a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048517c  751c                   -jne 0x48519a
    if (!cpu.flags.zf)
    {
        goto L_0x0048519a;
    }
    // 0048517e  8b04d5b0c55900         -mov eax, dword ptr [edx*8 + 0x59c5b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.edx * 8);
    // 00485185  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
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
    // 0048518b  7519                   -jne 0x4851a6
    if (!cpu.flags.zf)
    {
        goto L_0x004851a6;
    }
    // 0048518d  80780401               +cmp byte ptr [eax + 4], 1
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
    // 00485191  770e                   -ja 0x4851a1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004851a1;
    }
    // 00485193  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00485198  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485199  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048519a:
    // 0048519a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048519f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004851a1:
    // 004851a1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004851a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004851a6:
    // 004851a6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004851ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4851b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004851b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004851b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004851b3  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 004851ba  7507                   -jne 0x4851c3
    if (!cpu.flags.zf)
    {
        goto L_0x004851c3;
    }
    // 004851bc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004851c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004851c3:
    // 004851c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004851c5  e84a110000             -call 0x486314
    cpu.esp -= 4;
    sub_486314(app, cpu);
    if (cpu.terminate) return;
    // 004851ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004851cc  752d                   -jne 0x4851fb
    if (!cpu.flags.zf)
    {
        goto L_0x004851fb;
    }
    // 004851ce  8b04cdb0c55900         -mov eax, dword ptr [ecx*8 + 0x59c5b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.ecx * 8);
    // 004851d5  80780401               +cmp byte ptr [eax + 4], 1
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
    // 004851d9  7627                   -jbe 0x485202
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00485202;
    }
    // 004851db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004851dd  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004851e1  39ca                   +cmp edx, ecx
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
    // 004851e3  7d16                   -jge 0x4851fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004851fb;
    }
    // 004851e5  8b44900c               -mov eax, dword ptr [eax + edx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 004851e9  6681385054             +cmp word ptr [eax], 0x5450
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
    // 004851ee  7520                   -jne 0x485210
    if (!cpu.flags.zf)
    {
        goto L_0x00485210;
    }
    // 004851f0  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004851f4  7413                   -je 0x485209
    if (cpu.flags.zf)
    {
        goto L_0x00485209;
    }
    // 004851f6  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004851f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004851fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004851fb:
    // 004851fb  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00485200  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485201  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485202:
    // 00485202  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00485207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485208  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485209:
    // 00485209  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 0048520e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048520f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485210:
    // 00485210  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00485215  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485216  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485218  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485219  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048521a  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048521d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048521f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00485223  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 00485229  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 0048522e  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00485230  740f                   -je 0x485241
    if (cpu.flags.zf)
    {
        goto L_0x00485241;
    }
    // 00485232  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00485234  7512                   -jne 0x485248
    if (!cpu.flags.zf)
    {
        goto L_0x00485248;
    }
    // 00485236  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0048523b:
    // 0048523b  83c410                 +add esp, 0x10
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
    // 0048523e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048523f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485240  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485241:
    // 00485241  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00485246  ebf3                   -jmp 0x48523b
    goto L_0x0048523b;
L_0x00485248:
    // 00485248  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048524a  e811ffffff             -call 0x485160
    cpu.esp -= 4;
    sub_485160(app, cpu);
    if (cpu.terminate) return;
    // 0048524f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485251  7ce8                   -jl 0x48523b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048523b;
    }
    // 00485253  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485254  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485255  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485256  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00485258  8b14d5b0c55900         -mov edx, dword ptr [edx*8 + 0x59c5b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.edx * 8);
    // 0048525f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00485263  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485265  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00485269  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048526b  e810570000             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00485270  8b14cdb0c55900         -mov edx, dword ptr [ecx*8 + 0x59c5b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.ecx * 8);
    // 00485277  807a0401               +cmp byte ptr [edx + 4], 1
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
    // 0048527b  7204                   -jb 0x485281
    if (cpu.flags.cf)
    {
        goto L_0x00485281;
    }
    // 0048527d  0fb76a06               -movzx ebp, word ptr [edx + 6]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */));
L_0x00485281:
    // 00485281  807a0402               +cmp byte ptr [edx + 4], 2
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
    // 00485285  7248                   -jb 0x4852cf
    if (cpu.flags.cf)
    {
        goto L_0x004852cf;
    }
    // 00485287  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00485289  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x0048528d:
    // 0048528d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048528f  7e28                   -jle 0x4852b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004852b9;
    }
    // 00485291  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00485294  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00485296:
    // 00485296  807a0402               +cmp byte ptr [edx + 4], 2
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
    // 0048529a  7239                   -jb 0x4852d5
    if (cpu.flags.cf)
    {
        goto L_0x004852d5;
    }
    // 0048529c  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0048529f  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004852a2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004852a4  740c                   -je 0x4852b2
    if (cpu.flags.zf)
    {
        goto L_0x004852b2;
    }
    // 004852a6  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004852a8  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004852ac  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004852ae  894c030c               -mov dword ptr [ebx + eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ecx;
L_0x004852b2:
    // 004852b2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004852b5  39e8                   +cmp eax, ebp
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
    // 004852b7  7cdd                   -jl 0x485296
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485296;
    }
L_0x004852b9:
    // 004852b9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004852bd  8934c5b0c55900         -mov dword ptr [eax*8 + 0x59c5b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.eax * 8) = cpu.esi;
    // 004852c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004852c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852c9  83c410                 +add esp, 0x10
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
    // 004852cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004852ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004852cf:
    // 004852cf  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004852d3  ebb8                   -jmp 0x48528d
    goto L_0x0048528d;
L_0x004852d5:
    // 004852d5  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004852d8  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004852db  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004852dd  74d3                   -je 0x4852b2
    if (cpu.flags.zf)
    {
        goto L_0x004852b2;
    }
    // 004852df  29d1                   +sub ecx, edx
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
    // 004852e1  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004852e4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004852e8  895c0108               -mov dword ptr [ecx + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 004852ec  ebc4                   -jmp 0x4852b2
    goto L_0x004852b2;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4852f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004852f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004852f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004852f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004852f4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004852f6  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 004852fd  740c                   -je 0x48530b
    if (cpu.flags.zf)
    {
        goto L_0x0048530b;
    }
    // 004852ff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485301  7510                   -jne 0x485313
    if (!cpu.flags.zf)
    {
        goto L_0x00485313;
    }
    // 00485303  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x00485308:
    // 00485308  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485309  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048530a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048530b:
    // 0048530b  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00485310  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485311  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485312  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485313:
    // 00485313  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00485315  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485317  e894feffff             -call 0x4851b0
    cpu.esp -= 4;
    sub_4851b0(app, cpu);
    if (cpu.terminate) return;
    // 0048531c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048531e  7ce8                   -jl 0x485308
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00485308;
    }
    // 00485320  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485321  8b3cf5b0c55900         -mov edi, dword ptr [esi*8 + 0x59c5b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.esi * 8);
    // 00485328  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0048532b  8a5704                 -mov dl, byte ptr [edi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048532e  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 00485331  80fa01                 +cmp dl, 1
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
    // 00485334  7517                   -jne 0x48534d
    if (!cpu.flags.zf)
    {
        goto L_0x0048534d;
    }
    // 00485336  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485338  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048533b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048533d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048533f  e83c560000             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 00485344  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00485347  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485349  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048534c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048534d:
    // 0048534d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048534f  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00485352  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485354  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00485356  e825560000             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 0048535b  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048535e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485360  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485361  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485362  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485363  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485364(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485364  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485365  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00485367  e810100000             -call 0x48637c
    cpu.esp -= 4;
    sub_48637c(app, cpu);
    if (cpu.terminate) return;
    // 0048536c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048536d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485371  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00485373  e828f60100             -call 0x4a49a0
    cpu.esp -= 4;
    sub_4a49a0(app, cpu);
    if (cpu.terminate) return;
    // 00485378  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485379  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_485380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485380  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485382  7506                   -jne 0x48538a
    if (!cpu.flags.zf)
    {
        goto L_0x0048538a;
    }
    // 00485384  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00485389  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048538a:
    // 0048538a  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 00485390  c64004ff               -mov byte ptr [eax + 4], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 255 /*0xff*/;
    // 00485394  c640053c               -mov byte ptr [eax + 5], 0x3c
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 60 /*0x3c*/;
    // 00485398  c640067f               -mov byte ptr [eax + 6], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 127 /*0x7f*/;
    // 0048539c  c6400740               -mov byte ptr [eax + 7], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 64 /*0x40*/;
    // 004853a0  c640087f               -mov byte ptr [eax + 8], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 004853a4  c6400940               -mov byte ptr [eax + 9], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = 64 /*0x40*/;
    // 004853a8  c6400a7f               -mov byte ptr [eax + 0xa], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = 127 /*0x7f*/;
    // 004853ac  c6400b00               -mov byte ptr [eax + 0xb], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = 0 /*0x0*/;
    // 004853b0  66c7400c0000           -mov word ptr [eax + 0xc], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004853b6  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004853bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004853be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4853c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004853c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004853c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004853c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004853c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004853c5  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 004853cb  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 004853d0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004853d2  740d                   -je 0x4853e1
    if (cpu.flags.zf)
    {
        goto L_0x004853e1;
    }
    // 004853d4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004853d6  7512                   -jne 0x4853ea
    if (!cpu.flags.zf)
    {
        goto L_0x004853ea;
    }
L_0x004853d8:
    // 004853d8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004853dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004853e1:
    // 004853e1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004853e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004853e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004853ea:
    // 004853ea  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004853ed  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004853f0  e81f0f0000             -call 0x486314
    cpu.esp -= 4;
    sub_486314(app, cpu);
    if (cpu.terminate) return;
    // 004853f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004853f7  7cdf                   -jl 0x4853d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004853d8;
    }
    // 004853f9  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004853fc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004853ff  8b04c5b0c55900         -mov eax, dword ptr [eax*8 + 0x59c5b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.eax * 8);
    // 00485406  80780401               +cmp byte ptr [eax + 4], 1
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
    // 0048540a  7206                   -jb 0x485412
    if (cpu.flags.cf)
    {
        goto L_0x00485412;
    }
    // 0048540c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048540e  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x00485412:
    // 00485412  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00485414  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485416  7cc0                   -jl 0x4853d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004853d8;
    }
    // 00485418  39d9                   +cmp ecx, ebx
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
    // 0048541a  7ebc                   -jle 0x4853d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004853d8;
    }
    // 0048541c  80780402               +cmp byte ptr [eax + 4], 2
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
    // 00485420  720f                   -jb 0x485431
    if (cpu.flags.cf)
    {
        goto L_0x00485431;
    }
    // 00485422  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00485424  8b44880c               -mov eax, dword ptr [eax + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 00485428  e8d3fb0100             -call 0x4a5000
    cpu.esp -= 4;
    sub_4a5000(app, cpu);
    if (cpu.terminate) return;
    // 0048542d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048542e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048542f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485430  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485431:
    // 00485431  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00485433  8b448808               -mov eax, dword ptr [eax + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 00485437  e8c4fb0100             -call 0x4a5000
    cpu.esp -= 4;
    sub_4a5000(app, cpu);
    if (cpu.terminate) return;
    // 0048543c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048543d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048543e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048543f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485440  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 00485443  7507                   -jne 0x48544c
    if (!cpu.flags.zf)
    {
        goto L_0x0048544c;
    }
    // 00485445  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048544a  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0048544b  90                     -nop 
    ;
L_0x0048544c:
    // 0048544c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048544e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48544c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048544c;
    // 00485440  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 00485443  7507                   -jne 0x48544c
    if (!cpu.flags.zf)
    {
        goto L_0x0048544c;
    }
    // 00485445  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048544a  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0048544b  90                     -nop 
    ;
L_0x0048544c:
L_entry_0x0048544c:
    // 0048544c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048544e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485451  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485452  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485458  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048545a  7434                   -je 0x485490
    if (cpu.flags.zf)
    {
        goto L_0x00485490;
    }
    // 0048545c  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048545f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485461  7407                   -je 0x48546a
    if (cpu.flags.zf)
    {
        goto L_0x0048546a;
    }
    // 00485463  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x0048546a:
    // 0048546a  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485470  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00485472  b8143f5600             -mov eax, 0x563f14
    cpu.eax = 5652244 /*0x563f14*/;
    // 00485477  e8a4490000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 0048547c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048547e:
    // 0048547e  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485483  3b10                   +cmp edx, dword ptr [eax]
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
    // 00485485  7409                   -je 0x485490
    if (cpu.flags.zf)
    {
        goto L_0x00485490;
    }
    // 00485487  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485489  7405                   -je 0x485490
    if (cpu.flags.zf)
    {
        goto L_0x00485490;
    }
    // 0048548b  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
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
    // 0048548e  7403                   -je 0x485493
    if (cpu.flags.zf)
    {
        goto L_0x00485493;
    }
L_0x00485490:
    // 00485490  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485491  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485492  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485493:
    // 00485493  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485495  e802470000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 0048549a  ebe2                   -jmp 0x48547e
    goto L_0x0048547e;
}

/* align: skip  */
void Application::sub_48549c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048549c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048549d  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004854a2  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004854a5  e8a2670000             -call 0x48bc4c
    cpu.esp -= 4;
    sub_48bc4c(app, cpu);
    if (cpu.terminate) return;
    // 004854aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004854ac  7707                   -ja 0x4854b5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004854b5;
    }
L_0x004854ae:
    // 004854ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004854b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004854b1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004854b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004854b5:
    // 004854b5  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004854ba  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004854bd  e87e660000             -call 0x48bb40
    cpu.esp -= 4;
    sub_48bb40(app, cpu);
    if (cpu.terminate) return;
    // 004854c2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004854c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004854c6  74e6                   -je 0x4854ae
    if (cpu.flags.zf)
    {
        goto L_0x004854ae;
    }
L_0x004854c8:
    // 004854c8  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004854cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004854cd  740a                   -je 0x4854d9
    if (cpu.flags.zf)
    {
        goto L_0x004854d9;
    }
    // 004854cf  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004854d4  3b5014                 +cmp edx, dword ptr [eax + 0x14]
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
    // 004854d7  752c                   -jne 0x485505
    if (!cpu.flags.zf)
    {
        goto L_0x00485505;
    }
L_0x004854d9:
    // 004854d9  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004854de  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004854e0  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x004854e3:
    // 004854e3  e898650000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 004854e8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004854eb  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004854ee  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004854f3  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004854f6  e845660000             -call 0x48bb40
    cpu.esp -= 4;
    sub_48bb40(app, cpu);
    if (cpu.terminate) return;
    // 004854fb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004854fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004854ff  75c7                   -jne 0x4854c8
    if (!cpu.flags.zf)
    {
        goto L_0x004854c8;
    }
    // 00485501  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485504  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485505:
    // 00485505  83c038                 +add eax, 0x38
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
    // 00485508  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048550a  ebd7                   -jmp 0x4854e3
    goto L_0x004854e3;
}

/* align: skip  */
void Application::sub_48550c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x0048550c, cpu);
    // 0048550c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048550d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048550e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485510  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485516  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00485519  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048551b  0f85dc000000           -jne 0x4855fd
    if (!cpu.flags.zf)
    {
        goto L_0x004855fd;
    }
L_0x00485521:
    // 00485521  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00485528  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048552a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048552d  8d888c000000           -lea ecx, [eax + 0x8c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 00485533  b82cfa4c00             -mov eax, 0x4cfa2c
    cpu.eax = 5044780 /*0x4cfa2c*/;
    // 00485538  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048553a  e859efffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 0048553f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485541  a3103f5600             -mov dword ptr [0x563f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */) = cpu.eax;
    // 00485546  e8d14a0000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048554b  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485550  e897f3ffff             -call 0x4848ec
    cpu.esp -= 4;
    sub_4848ec(app, cpu);
    if (cpu.terminate) return;
    // 00485555  8b0d103f5600           -mov ecx, dword ptr [0x563f10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048555b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048555d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048555f  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00485562  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00485565  e8c2640000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048556a  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048556f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485571  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485573  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00485576  e8b1640000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048557b  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485580  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485582  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485584  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00485587  e8a0640000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048558c  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485591  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485593  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00485595  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00485598  e88f640000             -call 0x48ba2c
    cpu.esp -= 4;
    sub_48ba2c(app, cpu);
    if (cpu.terminate) return;
    // 0048559d  8b0d103f5600           -mov ecx, dword ptr [0x563f10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004855a3  81c18c000000           -add ecx, 0x8c
    (cpu.ecx) += x86::reg32(x86::sreg32(140 /*0x8c*/));
L_0x004855a9:
    // 004855a9  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004855ae  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004855b0  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004855b3  e8c8640000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 004855b8  83c128                 +add ecx, 0x28
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
    // 004855bb  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004855bc  75eb                   -jne 0x4855a9
    if (!cpu.flags.zf)
    {
        goto L_0x004855a9;
    }
    // 004855be  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004855c3  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004855c8  b89c544800             -mov eax, 0x48549c
    cpu.eax = 4740252 /*0x48549c*/;
    // 004855cd  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004855d2  e8f9e7ffff             -call 0x483dd0
    cpu.esp -= 4;
    sub_483dd0(app, cpu);
    if (cpu.terminate) return;
    // 004855d7  68143f5600             -push 0x563f14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5652244 /*0x563f14*/;
    cpu.esp -= 4;
    // 004855dc  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004855e1  b8385c4800             -mov eax, 0x485c38
    cpu.eax = 4742200 /*0x485c38*/;
    // 004855e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004855e8  e8f3440000             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 004855ed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004855ef  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004855f4  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004855f6  39d9                   +cmp ecx, ebx
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
    // 004855f8  740d                   -je 0x485607
    if (cpu.flags.zf)
    {
        goto L_0x00485607;
    }
    // 004855fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004855fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004855fd:
    // 004855fd  e81a000000             -call 0x48561c
    cpu.esp -= 4;
    sub_48561c(app, cpu);
    if (cpu.terminate) return;
    // 00485602  e91affffff             -jmp 0x485521
    goto L_0x00485521;
L_0x00485607:
    // 00485607  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485609  e88e450000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 0048560e  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485613  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00485615  39d9                   +cmp ecx, ebx
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
    // 00485617  74ee                   -je 0x485607
    if (cpu.flags.zf)
    {
        goto L_0x00485607;
    }
    // 00485619  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048561a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048561b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48561c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048561c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048561d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048561e  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485624  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485626  7503                   -jne 0x48562b
    if (!cpu.flags.zf)
    {
        goto L_0x0048562b;
    }
    // 00485628  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485629  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048562a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048562b:
    // 0048562b  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00485632  e819feffff             -call 0x485450
    cpu.esp -= 4;
    sub_485450(app, cpu);
    if (cpu.terminate) return;
    // 00485637  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00485639:
    // 00485639  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048563e  3b10                   +cmp edx, dword ptr [eax]
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
    // 00485640  7409                   -je 0x48564b
    if (cpu.flags.zf)
    {
        goto L_0x0048564b;
    }
    // 00485642  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485644  e853450000             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 00485649  ebee                   -jmp 0x485639
    goto L_0x00485639;
L_0x0048564b:
    // 0048564b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048564c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048564d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048564e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048564f  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00485652  e8a5640000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 00485657  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485659  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048565b  743c                   -je 0x485699
    if (cpu.flags.zf)
    {
        goto L_0x00485699;
    }
L_0x0048565d:
    // 0048565d  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00485660  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485662  7407                   -je 0x48566b
    if (cpu.flags.zf)
    {
        goto L_0x0048566b;
    }
    // 00485664  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485666  e891f2ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x0048566b:
    // 0048566b  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048566e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00485670  7407                   -je 0x485679
    if (cpu.flags.zf)
    {
        goto L_0x00485679;
    }
    // 00485672  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485674  e8aff2ffff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
L_0x00485679:
    // 00485679  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048567e  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485681  e8fa630000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485686  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048568b  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048568e  e869640000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 00485693  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485695  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485697  75c4                   -jne 0x48565d
    if (!cpu.flags.zf)
    {
        goto L_0x0048565d;
    }
L_0x00485699:
    // 00485699  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048569e  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004856a1  e856640000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 004856a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004856a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004856aa  743c                   -je 0x4856e8
    if (cpu.flags.zf)
    {
        goto L_0x004856e8;
    }
L_0x004856ac:
    // 004856ac  8b7a1c                 -mov edi, dword ptr [edx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004856af  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004856b1  7407                   -je 0x4856ba
    if (cpu.flags.zf)
    {
        goto L_0x004856ba;
    }
    // 004856b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004856b5  e842f2ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x004856ba:
    // 004856ba  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004856bd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004856bf  7407                   -je 0x4856c8
    if (cpu.flags.zf)
    {
        goto L_0x004856c8;
    }
    // 004856c1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004856c3  e860f2ffff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
L_0x004856c8:
    // 004856c8  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004856cd  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004856d0  e8ab630000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 004856d5  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004856da  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004856dd  e81a640000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 004856e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004856e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004856e6  75c4                   -jne 0x4856ac
    if (!cpu.flags.zf)
    {
        goto L_0x004856ac;
    }
L_0x004856e8:
    // 004856e8  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004856ed  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004856f0  e807640000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 004856f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004856f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004856f9  743c                   -je 0x485737
    if (cpu.flags.zf)
    {
        goto L_0x00485737;
    }
L_0x004856fb:
    // 004856fb  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004856fe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485700  7407                   -je 0x485709
    if (cpu.flags.zf)
    {
        goto L_0x00485709;
    }
    // 00485702  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485704  e8f3f1ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
L_0x00485709:
    // 00485709  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048570c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048570e  7407                   -je 0x485717
    if (cpu.flags.zf)
    {
        goto L_0x00485717;
    }
    // 00485710  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00485712  e811f2ffff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
L_0x00485717:
    // 00485717  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048571c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048571f  e85c630000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485724  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485729  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0048572c  e8cb630000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 00485731  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485733  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485735  75c4                   -jne 0x4856fb
    if (!cpu.flags.zf)
    {
        goto L_0x004856fb;
    }
L_0x00485737:
    // 00485737  b89c544800             -mov eax, 0x48549c
    cpu.eax = 4740252 /*0x48549c*/;
    // 0048573c  e823e7ffff             -call 0x483e64
    cpu.esp -= 4;
    sub_483e64(app, cpu);
    if (cpu.terminate) return;
    // 00485741  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485746  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485749  e81e630000             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 0048574e  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485753  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00485756  e811630000             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 0048575b  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485760  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00485763  e804630000             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 00485768  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048576d  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00485770  e8f7620000             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 00485775  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048577a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048577d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048577f  7407                   -je 0x485788
    if (cpu.flags.zf)
    {
        goto L_0x00485788;
    }
    // 00485781  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00485783  e8c8210000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
L_0x00485788:
    // 00485788  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048578d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048578f  e868f1ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00485794  890d103f5600           -mov dword ptr [0x563f10], ecx
    app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */) = cpu.ecx;
    // 0048579a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048579b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048579c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048579d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048579e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048579f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4857a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004857a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004857a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004857a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004857a8  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004857ad  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004857b0  e847630000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 004857b5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004857b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004857b9  7503                   -jne 0x4857be
    if (!cpu.flags.zf)
    {
        goto L_0x004857be;
    }
    // 004857bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004857bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004857be:
    // 004857be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004857bf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004857c0  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004857c7  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004857ce  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004857d5  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004857dc  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004857e3  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004857e6  a1e8b24d00             -mov eax, dword ptr [0x4db2e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */);
    // 004857eb  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004857ee  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004857f0  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004857f3  40                     -inc eax
    (cpu.eax)++;
    // 004857f4  8b1de8ab4d00           -mov ebx, dword ptr [0x4dabe8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 004857fa  a3e8b24d00             -mov dword ptr [0x4db2e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */) = cpu.eax;
    // 004857ff  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485801  49                     -dec ecx
    (cpu.ecx)--;
    // 00485802  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00485804  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00485806  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00485808  49                     -dec ecx
    (cpu.ecx)--;
    // 00485809  b868fa4c00             -mov eax, 0x4cfa68
    cpu.eax = 5044840 /*0x4cfa68*/;
    // 0048580e  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00485811  e882ecffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00485816  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00485818  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048581b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048581c:
    // 0048581c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048581e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485820  3c00                   +cmp al, 0
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
    // 00485822  7410                   -je 0x485834
    if (cpu.flags.zf)
    {
        goto L_0x00485834;
    }
    // 00485824  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485827  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048582a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048582d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485830  3c00                   +cmp al, 0
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
    // 00485832  75e8                   -jne 0x48581c
    if (!cpu.flags.zf)
    {
        goto L_0x0048581c;
    }
L_0x00485834:
    // 00485834  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485835  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048583a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048583c  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048583f  e83c620000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485844  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048584a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048584c  b8143f5600             -mov eax, 0x563f14
    cpu.eax = 5652244 /*0x563f14*/;
    // 00485851  e8ca450000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00485856  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00485859  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048585a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048585b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048585c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048585d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485861  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485863  e83cffffff             -call 0x4857a4
    cpu.esp -= 4;
    sub_4857a4(app, cpu);
    if (cpu.terminate) return;
    // 00485868  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485869  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48586c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048586c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048586d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048586e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485870  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485875  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485878  e87f620000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 0048587d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048587f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485881  7503                   -jne 0x485886
    if (!cpu.flags.zf)
    {
        goto L_0x00485886;
    }
    // 00485883  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485884  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485885  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485886:
    // 00485886  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485887  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485888  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048588f  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00485896  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 0048589d  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004858a4  a1e8b24d00             -mov eax, dword ptr [0x4db2e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */);
    // 004858a9  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004858ac  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004858ae  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004858b1  8b15e8ab4d00           -mov edx, dword ptr [0x4dabe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 004858b7  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004858ba  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004858bc  40                     -inc eax
    (cpu.eax)++;
    // 004858bd  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004858c0  a3e8b24d00             -mov dword ptr [0x4db2e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */) = cpu.eax;
    // 004858c5  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004858c7  49                     -dec ecx
    (cpu.ecx)--;
    // 004858c8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004858ca  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004858cc  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004858ce  49                     -dec ecx
    (cpu.ecx)--;
    // 004858cf  b868fa4c00             -mov eax, 0x4cfa68
    cpu.eax = 5044840 /*0x4cfa68*/;
    // 004858d4  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004858d7  e8bcebffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004858dc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004858de  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004858e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004858e2:
    // 004858e2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004858e4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004858e6  3c00                   +cmp al, 0
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
    // 004858e8  7410                   -je 0x4858fa
    if (cpu.flags.zf)
    {
        goto L_0x004858fa;
    }
    // 004858ea  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004858ed  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004858f0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004858f3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004858f6  3c00                   +cmp al, 0
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
    // 004858f8  75e8                   -jne 0x4858e2
    if (!cpu.flags.zf)
    {
        goto L_0x004858e2;
    }
L_0x004858fa:
    // 004858fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004858fb  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485900  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00485902  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00485905  e876610000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 0048590a  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485910  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00485912  b8143f5600             -mov eax, 0x563f14
    cpu.eax = 5652244 /*0x563f14*/;
    // 00485917  e804450000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 0048591c  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048591f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485920  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485921  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485922  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485923  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485924  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485925  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00485927  e840ffffff             -call 0x48586c
    cpu.esp -= 4;
    sub_48586c(app, cpu);
    if (cpu.terminate) return;
    // 0048592c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048592d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00485930  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485931  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485932  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485935  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485937  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048593c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048593f  e8b8610000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 00485944  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485946  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00485949  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048594b  746d                   -je 0x4859ba
    if (cpu.flags.zf)
    {
        goto L_0x004859ba;
    }
    // 0048594d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048594e  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00485955  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048595c  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00485963  c7462002000000         -mov dword ptr [esi + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0048596a  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00485971  a1e8b24d00             -mov eax, dword ptr [0x4db2e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */);
    // 00485976  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048597d  8b15e8ab4d00           -mov edx, dword ptr [0x4dabe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 00485983  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00485986  40                     -inc eax
    (cpu.eax)++;
    // 00485987  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048598a  a3e8b24d00             -mov dword ptr [0x4db2e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */) = cpu.eax;
    // 0048598f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00485991  752d                   -jne 0x4859c0
    if (!cpu.flags.zf)
    {
        goto L_0x004859c0;
    }
    // 00485993  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
L_0x00485996:
    // 00485996  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048599b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048599f  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004859a2  e8d9600000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 004859a7  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 004859ad  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004859af  b8143f5600             -mov eax, 0x563f14
    cpu.eax = 5652244 /*0x563f14*/;
    // 004859b4  e867440000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 004859b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004859ba:
    // 004859ba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004859bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004859c0:
    // 004859c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004859c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004859c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004859c3  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004859c5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004859c7  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004859c9  49                     -dec ecx
    (cpu.ecx)--;
    // 004859ca  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004859cc  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004859ce  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004859d0  49                     -dec ecx
    (cpu.ecx)--;
    // 004859d1  b868fa4c00             -mov eax, 0x4cfa68
    cpu.eax = 5044840 /*0x4cfa68*/;
    // 004859d6  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004859d9  e8baeaffff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004859de  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004859e0  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004859e3  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004859e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004859e6:
    // 004859e6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004859e8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004859ea  3c00                   +cmp al, 0
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
    // 004859ec  7410                   -je 0x4859fe
    if (cpu.flags.zf)
    {
        goto L_0x004859fe;
    }
    // 004859ee  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004859f1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004859f4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004859f7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004859fa  3c00                   +cmp al, 0
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
    // 004859fc  75e8                   -jne 0x4859e6
    if (!cpu.flags.zf)
    {
        goto L_0x004859e6;
    }
L_0x004859fe:
    // 004859fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004859ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a02  eb92                   -jmp 0x485996
    goto L_0x00485996;
}

}
