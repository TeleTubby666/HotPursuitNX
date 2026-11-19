#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8b 0xc0 */
void Application::sub_485930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485930);
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

/* align: skip  */
void Application::sub_485a04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a04);
    // 00485a04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485a05  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485a07  e840faffff             -call 0x48544c
    cpu.esp -= 4;
    sub_48544c(app, cpu);
    if (cpu.terminate) return;
    // 00485a0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485a10);
    // 00485a10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485a11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485a12  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485a15  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00485a17  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00485a1a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00485a1c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485a1e  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485a23  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485a26  e8d1600000             -call 0x48bafc
    cpu.esp -= 4;
    sub_48bafc(app, cpu);
    if (cpu.terminate) return;
    // 00485a2b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485a2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485a2f  7506                   -jne 0x485a37
    if (!cpu.flags.zf)
    {
        goto L_0x00485a37;
    }
    // 00485a31  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485a34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485a37:
    // 00485a37  a1e8b24d00             -mov eax, dword ptr [0x4db2e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */);
    // 00485a3c  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00485a3f  40                     -inc eax
    (cpu.eax)++;
    // 00485a40  8b1d103f5600           -mov ebx, dword ptr [0x563f10]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485a46  a3e8b24d00             -mov dword ptr [0x4db2e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5092072) /* 0x4db2e8 */) = cpu.eax;
    // 00485a4b  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00485a4e  c7412003000000         -mov dword ptr [ecx + 0x20], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 00485a55  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485a5c  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00485a63  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00485a65  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00485a68  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00485a6b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00485a6e  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00485a71  a1e8ab4d00             -mov eax, dword ptr [0x4dabe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 00485a76  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485a78  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00485a7b  8d4370                 -lea eax, [ebx + 0x70]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 00485a7e  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00485a81  e8fa5f0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485a86  8b15103f5600           -mov edx, dword ptr [0x563f10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485a8c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00485a8e  b8143f5600             -mov eax, 0x563f14
    cpu.eax = 5652244 /*0x563f14*/;
    // 00485a93  e888430000             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 00485a98  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00485a9b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00485a9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485a9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_485aa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485aa4);
    // 00485aa4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485aa5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485aa7  e864ffffff             -call 0x485a10
    cpu.esp -= 4;
    sub_485a10(app, cpu);
    if (cpu.terminate) return;
    // 00485aac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485aad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485ab0);
    // 00485ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485ab1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00485ab3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00485ab5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485ab7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485ab9  e852ffffff             -call 0x485a10
    cpu.esp -= 4;
    sub_485a10(app, cpu);
    if (cpu.terminate) return;
    // 00485abe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485abf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_485ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485ac0);
    // 00485ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485ac2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00485ac4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00485ac6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485ac8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485aca  e841ffffff             -call 0x485a10
    cpu.esp -= 4;
    sub_485a10(app, cpu);
    if (cpu.terminate) return;
    // 00485acf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ad0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ad1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485ad4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485ad4);
    // 00485ad4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485ad5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485ad6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485ad7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485ad8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485ada  ba40544800             -mov edx, 0x485440
    cpu.edx = 4740160 /*0x485440*/;
    // 00485adf  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485ae4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00485ae6  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00485ae9  e822630000             -call 0x48be10
    cpu.esp -= 4;
    sub_48be10(app, cpu);
    if (cpu.terminate) return;
    // 00485aee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485af0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485af2  7438                   -je 0x485b2c
    if (cpu.flags.zf)
    {
        goto L_0x00485b2c;
    }
    // 00485af4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485af5  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00485af8  83fe01                 +cmp esi, 1
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
    // 00485afb  7528                   -jne 0x485b25
    if (!cpu.flags.zf)
    {
        goto L_0x00485b25;
    }
L_0x00485afd:
    // 00485afd  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00485b00  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00485b02  740e                   -je 0x485b12
    if (cpu.flags.zf)
    {
        goto L_0x00485b12;
    }
    // 00485b04  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485b06  e8f1edffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00485b0b  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x00485b12:
    // 00485b12  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485b17  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485b1a  e8615f0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485b1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00485b20:
    // 00485b20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485b25:
    // 00485b25  83fe02                 +cmp esi, 2
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
    // 00485b28  74d3                   -je 0x485afd
    if (cpu.flags.zf)
    {
        goto L_0x00485afd;
    }
    // 00485b2a  ebe6                   -jmp 0x485b12
    goto L_0x00485b12;
L_0x00485b2c:
    // 00485b2c  e81ff9ffff             -call 0x485450
    cpu.esp -= 4;
    sub_485450(app, cpu);
    if (cpu.terminate) return;
    // 00485b31  ba40544800             -mov edx, 0x485440
    cpu.edx = 4740160 /*0x485440*/;
    // 00485b36  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485b3b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00485b3d  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00485b40  e8cb620000             -call 0x48be10
    cpu.esp -= 4;
    sub_48be10(app, cpu);
    if (cpu.terminate) return;
    // 00485b45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485b47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485b49  7516                   -jne 0x485b61
    if (!cpu.flags.zf)
    {
        goto L_0x00485b61;
    }
    // 00485b4b  ba40544800             -mov edx, 0x485440
    cpu.edx = 4740160 /*0x485440*/;
    // 00485b50  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485b55  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00485b57  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00485b5a  e8b1620000             -call 0x48be10
    cpu.esp -= 4;
    sub_48be10(app, cpu);
    if (cpu.terminate) return;
    // 00485b5f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00485b61:
    // 00485b61  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00485b63  74bb                   -je 0x485b20
    if (cpu.flags.zf)
    {
        goto L_0x00485b20;
    }
    // 00485b65  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00485b68  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485b6a  7411                   -je 0x485b7d
    if (cpu.flags.zf)
    {
        goto L_0x00485b7d;
    }
    // 00485b6c  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485b71  3b4814                 +cmp ecx, dword ptr [eax + 0x14]
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
    // 00485b74  7407                   -je 0x485b7d
    if (cpu.flags.zf)
    {
        goto L_0x00485b7d;
    }
    // 00485b76  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485b78  e8abedffff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
L_0x00485b7d:
    // 00485b7d  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485b82  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485b85  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485b8c  e8ef5e0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485b91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485b95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485b98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485b98);
    // 00485b98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485b99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485b9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485b9b  8b0d103f5600           -mov ecx, dword ptr [0x563f10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485ba1  ba40544800             -mov edx, 0x485440
    cpu.edx = 4740160 /*0x485440*/;
    // 00485ba6  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00485ba9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485bab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485bad  e85e620000             -call 0x48be10
    cpu.esp -= 4;
    sub_48be10(app, cpu);
    if (cpu.terminate) return;
    // 00485bb2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485bb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485bb6  7506                   -jne 0x485bbe
    if (!cpu.flags.zf)
    {
        goto L_0x00485bbe;
    }
L_0x00485bb8:
    // 00485bb8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00485bba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485bbe:
    // 00485bbe  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485bc3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485bc5  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485bc8  e8b35e0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485bcd  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 00485bd1  74e5                   -je 0x485bb8
    if (cpu.flags.zf)
    {
        goto L_0x00485bb8;
    }
    // 00485bd3  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00485bd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_485bdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485bdc);
    // 00485bdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485bdd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485bde  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485bdf  8b0d103f5600           -mov ecx, dword ptr [0x563f10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485be5  ba40544800             -mov edx, 0x485440
    cpu.edx = 4740160 /*0x485440*/;
    // 00485bea  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00485bed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00485bef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485bf1  e81a620000             -call 0x48be10
    cpu.esp -= 4;
    sub_48be10(app, cpu);
    if (cpu.terminate) return;
    // 00485bf6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00485bf8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485bfa  7504                   -jne 0x485c00
    if (!cpu.flags.zf)
    {
        goto L_0x00485c00;
    }
    // 00485bfc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bfe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485bff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485c00:
    // 00485c00  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485c05  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00485c07  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00485c0a  e8715e0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485c0f  83792000               +cmp dword ptr [ecx + 0x20], 0
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
    // 00485c13  7409                   -je 0x485c1e
    if (cpu.flags.zf)
    {
        goto L_0x00485c1e;
    }
    // 00485c15  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00485c1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485c1e:
    // 00485c1e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00485c23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485c26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_485c38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00485c38);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00485c38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00485c39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00485c3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00485c3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00485c3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00485c3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00485c3e  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 00485c44  e8c3410000             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 00485c49  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485c4b  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485c50  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00485c52  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485c59  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x00485c60:
    // 00485c60  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485c65  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00485c69  743d                   -je 0x485ca8
    if (cpu.flags.zf)
    {
        goto L_0x00485ca8;
    }
    // 00485c6b  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485c6e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485c70  0f85b0030000           -jne 0x486026
    if (!cpu.flags.zf)
    {
        goto L_0x00486026;
    }
L_0x00485c76:
    // 00485c76  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485c7b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00485c82  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485c89  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485c8b  e858420000             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 00485c90  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485c95  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00485c9b  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 00485ca1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ca2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ca3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ca4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ca5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ca6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485ca7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00485ca8:
    // 00485ca8  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00485cab  e8905e0000             -call 0x48bb40
    cpu.esp -= 4;
    sub_48bb40(app, cpu);
    if (cpu.terminate) return;
    // 00485cb0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00485cb2  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00485cb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485cbb  0f8454030000           -je 0x486015
    if (cpu.flags.zf)
    {
        goto L_0x00486015;
    }
    // 00485cc1  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485cc6  896818                 -mov dword ptr [eax + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00485cc9  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00485ccc  4a                     -dec edx
    (cpu.edx)--;
    // 00485ccd  83fa03                 +cmp edx, 3
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
    // 00485cd0  760e                   -jbe 0x485ce0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00485ce0;
    }
    // 00485cd2  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485cd7  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485cde  eb80                   -jmp 0x485c60
    goto L_0x00485c60;
L_0x00485ce0:
    // 00485ce0  ff2495285c4800         -jmp dword ptr [edx*4 + 0x485c28]
    cpu.ip = app->getMemory<x86::reg32>(4742184 + cpu.edx * 4); goto dynamic_jump;
  case 0x00485ce7:
    // 00485ce7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00485ce9  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00485cec  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485cf3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00485cf4:
    // 00485cf4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00485cf6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00485cf8  3c00                   +cmp al, 0
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
    // 00485cfa  7410                   -je 0x485d0c
    if (cpu.flags.zf)
    {
        goto L_0x00485d0c;
    }
    // 00485cfc  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00485cff  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485d02  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00485d05  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00485d08  3c00                   +cmp al, 0
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
    // 00485d0a  75e8                   -jne 0x485cf4
    if (!cpu.flags.zf)
    {
        goto L_0x00485cf4;
    }
L_0x00485d0c:
    // 00485d0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00485d0d  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00485d10  8d4d10                 -lea ecx, [ebp + 0x10]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00485d13  e8e4ebffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00485d18  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485d1b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485d1d  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00485d24  e88b1a0000             -call 0x4877b4
    cpu.esp -= 4;
    sub_4877b4(app, cpu);
    if (cpu.terminate) return;
    // 00485d29  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485d30  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485d37  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00485d39  0f8435010000           -je 0x485e74
    if (cpu.flags.zf)
    {
        goto L_0x00485e74;
    }
    // 00485d3f  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00485d42  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485d44  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 00485d49  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485d4c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00485d4e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485d51  8d8890010000           -lea ecx, [eax + 0x190]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 00485d57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485d59  0f8505010000           -jne 0x485e64
    if (!cpu.flags.zf)
    {
        goto L_0x00485e64;
    }
    // 00485d5f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00485d61  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00485d64  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00485d67  e810e7ffff             -call 0x48447c
    cpu.esp -= 4;
    sub_48447c(app, cpu);
    if (cpu.terminate) return;
    // 00485d6c  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00485d6f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00485d71  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00485d74:
    // 00485d74  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00485d76  e8edf20100             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
    // 00485d7b  e8bcf30100             -call 0x4a513c
    cpu.esp -= 4;
    sub_4a513c(app, cpu);
    if (cpu.terminate) return;
    // 00485d80  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485d87  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485d8e  e8ad3dfdff             -call 0x459b40
    cpu.esp -= 4;
    sub_459b40(app, cpu);
    if (cpu.terminate) return;
    // 00485d93  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485d9a  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00485d9d  8b9c2404010000         -mov ebx, dword ptr [esp + 0x104]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485da4  e8bf1b0000             -call 0x487968
    cpu.esp -= 4;
    sub_487968(app, cpu);
    if (cpu.terminate) return;
    // 00485da9  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485db0  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485db7  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00485dba  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00485dbd  e8961b0000             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00485dc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485dc4  750e                   -jne 0x485dd4
    if (!cpu.flags.zf)
    {
        goto L_0x00485dd4;
    }
    // 00485dc6  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485dcd  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x00485dd4:
    // 00485dd4  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485ddb  e8203dfdff             -call 0x459b00
    cpu.esp -= 4;
    sub_459b00(app, cpu);
    if (cpu.terminate) return;
    // 00485de0  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00485de7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00485de9  e8621b0000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 00485dee  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485df5  89b42400010000         -mov dword ptr [esp + 0x100], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.esi;
    // 00485dfc  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00485e00  7530                   -jne 0x485e32
    if (!cpu.flags.zf)
    {
        goto L_0x00485e32;
    }
    // 00485e02  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485e09  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485e0e  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00485e11  3b5014                 +cmp edx, dword ptr [eax + 0x14]
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
    // 00485e14  741c                   -je 0x485e32
    if (cpu.flags.zf)
    {
        goto L_0x00485e32;
    }
    // 00485e16  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485e1d  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00485e20  e803ebffff             -call 0x484928
    cpu.esp -= 4;
    sub_484928(app, cpu);
    if (cpu.terminate) return;
    // 00485e25  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485e2c  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00485e2f  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00485e32:
    // 00485e32  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485e39  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 00485e3d  743a                   -je 0x485e79
    if (cpu.flags.zf)
    {
        goto L_0x00485e79;
    }
    // 00485e3f  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485e44  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485e4b  83c054                 +add eax, 0x54
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
    // 00485e4e  e82d5c0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485e53  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485e58  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485e5f  e9fcfdffff             -jmp 0x485c60
    goto L_0x00485c60;
L_0x00485e64:
    // 00485e64  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485e69  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00485e6c  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00485e6f  e900ffffff             -jmp 0x485d74
    goto L_0x00485d74;
L_0x00485e74:
    // 00485e74  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00485e77  ebb9                   -jmp 0x485e32
    goto L_0x00485e32;
L_0x00485e79:
    // 00485e79  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485e7e  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485e85  83c038                 +add eax, 0x38
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
    // 00485e88  e8f35b0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485e8d  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485e92  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485e99  e9c2fdffff             -jmp 0x485c60
    goto L_0x00485c60;
  case 0x00485e9e:
    // 00485e9e  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485ea1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00485ea3  7407                   -je 0x485eac
    if (cpu.flags.zf)
    {
        goto L_0x00485eac;
    }
    // 00485ea5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00485ea7  e8a41a0000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
L_0x00485eac:
    // 00485eac  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485eb1  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00485eb8  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485ebf  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 00485ec3  7449                   -je 0x485f0e
    if (cpu.flags.zf)
    {
        goto L_0x00485f0e;
    }
    // 00485ec5  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 00485eca  e899f10100             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
    // 00485ecf  e868f20100             -call 0x4a513c
    cpu.esp -= 4;
    sub_4a513c(app, cpu);
    if (cpu.terminate) return;
    // 00485ed4  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485ed9  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00485edc  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00485edf  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485ee2  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485ee9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485eec  e8cb180000             -call 0x4877bc
    cpu.esp -= 4;
    sub_4877bc(app, cpu);
    if (cpu.terminate) return;
    // 00485ef1  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485ef8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00485efb  e8fce9ffff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00485f00  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485f07  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x00485f0e:
    // 00485f0e  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485f13  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485f1a  83c01c                 +add eax, 0x1c
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
    // 00485f1d  e85e5b0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485f22  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485f27  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485f2e  e92dfdffff             -jmp 0x485c60
    goto L_0x00485c60;
  case 0x00485f33:
    // 00485f33  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485f36  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00485f38  0f8498000000           -je 0x485fd6
    if (cpu.flags.zf)
    {
        goto L_0x00485fd6;
    }
    // 00485f3e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00485f41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00485f43  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 00485f48  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00485f4b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00485f4d  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 00485f52  e811f10100             -call 0x4a5068
    cpu.esp -= 4;
    sub_4a5068(app, cpu);
    if (cpu.terminate) return;
    // 00485f57  e8e0f10100             -call 0x4a513c
    cpu.esp -= 4;
    sub_4a513c(app, cpu);
    if (cpu.terminate) return;
    // 00485f5c  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485f61  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485f64  e8d73bfdff             -call 0x459b40
    cpu.esp -= 4;
    sub_459b40(app, cpu);
    if (cpu.terminate) return;
    // 00485f69  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485f6e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00485f71  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485f74  e8ef190000             -call 0x487968
    cpu.esp -= 4;
    sub_487968(app, cpu);
    if (cpu.terminate) return;
    // 00485f79  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485f7e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00485f81  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00485f84  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485f87  e8cc190000             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00485f8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00485f8e  7503                   -jne 0x485f93
    if (!cpu.flags.zf)
    {
        goto L_0x00485f93;
    }
    // 00485f90  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00485f93:
    // 00485f93  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485f98  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485f9b  e8603bfdff             -call 0x459b00
    cpu.esp -= 4;
    sub_459b00(app, cpu);
    if (cpu.terminate) return;
L_0x00485fa0:
    // 00485fa0  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485fa7  83782400               +cmp dword ptr [eax + 0x24], 0
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
    // 00485fab  0f84c8feffff           -je 0x485e79
    if (cpu.flags.zf)
    {
        goto L_0x00485e79;
    }
    // 00485fb1  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485fb6  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485fbd  83c054                 +add eax, 0x54
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
    // 00485fc0  e8bb5a0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00485fc5  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485fca  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00485fd1  e98afcffff             -jmp 0x485c60
    goto L_0x00485c60;
L_0x00485fd6:
    // 00485fd6  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00485fd9  ebc5                   -jmp 0x485fa0
    goto L_0x00485fa0;
  case 0x00485fdb:
    // 00485fdb  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00485fde  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00485fe0  7407                   -je 0x485fe9
    if (cpu.flags.zf)
    {
        goto L_0x00485fe9;
    }
    // 00485fe2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00485fe4  e867190000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
L_0x00485fe9:
    // 00485fe9  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00485fee  83c01c                 +add eax, 0x1c
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
    // 00485ff1  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00485ff8  c740ec00000000         -mov dword ptr [eax - 0x14], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00485fff  e87c5a0000             -call 0x48ba80
    cpu.esp -= 4;
    sub_48ba80(app, cpu);
    if (cpu.terminate) return;
    // 00486004  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 00486009  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00486010  e94bfcffff             -jmp 0x485c60
    goto L_0x00485c60;
L_0x00486015:
    // 00486015  a1103f5600             -mov eax, dword ptr [0x563f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5652240) /* 0x563f10 */);
    // 0048601a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048601c  e83b3e0000             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 00486021  e93afcffff             -jmp 0x485c60
    goto L_0x00485c60;
L_0x00486026:
    // 00486026  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486028  e823190000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 0048602d  e944fcffff             -jmp 0x485c76
    goto L_0x00485c76;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486040);
    // 00486040  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486041  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486043  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0048604a  7507                   -jne 0x486053
    if (!cpu.flags.zf)
    {
        goto L_0x00486053;
    }
    // 0048604c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486051  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486052  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486053:
    // 00486053  e808f30100             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 00486058  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048605a  e80df70100             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 0048605f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486061  7c0b                   -jl 0x48606e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048606e;
    }
    // 00486063  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486065  e80af30100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 0048606a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048606c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048606d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048606e:
    // 0048606e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00486073  e8fcf20100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00486078  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048607a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048607b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_486080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486080);
    // 00486080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486082  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486083  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486085  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00486087  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 0048608e  7415                   -je 0x4860a5
    if (cpu.flags.zf)
    {
        goto L_0x004860a5;
    }
    // 00486090  83fb7f                 +cmp ebx, 0x7f
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
    // 00486093  7f05                   -jg 0x48609a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048609a;
    }
    // 00486095  83fbff                 +cmp ebx, -1
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
    // 00486098  7d12                   -jge 0x4860ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004860ac;
    }
L_0x0048609a:
    // 0048609a  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x0048609f:
    // 0048609f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004860a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004860a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004860a5:
    // 004860a5  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 004860aa  ebf3                   -jmp 0x48609f
    goto L_0x0048609f;
L_0x004860ac:
    // 004860ac  e8aff20100             -call 0x4a5360
    cpu.esp -= 4;
    sub_4a5360(app, cpu);
    if (cpu.terminate) return;
    // 004860b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004860b3  e8b4f60100             -call 0x4a576c
    cpu.esp -= 4;
    sub_4a576c(app, cpu);
    if (cpu.terminate) return;
    // 004860b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004860ba  0f8c6d000000           -jl 0x48612d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048612d;
    }
    // 004860c0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004860c7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004860c9  b9b0bf5900             -mov ecx, 0x59bfb0
    cpu.ecx = 5881776 /*0x59bfb0*/;
    // 004860ce  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004860d1  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004860d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004860d5  7e66                   -jle 0x48613d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048613d;
    }
L_0x004860d7:
    // 004860d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004860d8  0fb6793b               -movzx edi, byte ptr [ecx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */));
    // 004860dc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004860de  7464                   -je 0x486144
    if (cpu.flags.zf)
    {
        goto L_0x00486144;
    }
    // 004860e0  b9b0bf5900             -mov ecx, 0x59bfb0
    cpu.ecx = 5881776 /*0x59bfb0*/;
    // 004860e5  8da900060000           -lea ebp, [ecx + 0x600]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(1536) /* 0x600 */);
L_0x004860eb:
    // 004860eb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004860ed  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004860f0  39fa                   +cmp edx, edi
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
    // 004860f2  7524                   -jne 0x486118
    if (!cpu.flags.zf)
    {
        goto L_0x00486118;
    }
    // 004860f4  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004860f8  751e                   -jne 0x486118
    if (!cpu.flags.zf)
    {
        goto L_0x00486118;
    }
    // 004860fa  833900                 +cmp dword ptr [ecx], 0
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
    // 004860fd  7c19                   -jl 0x486118
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486118;
    }
    // 004860ff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486101  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00486104  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00486107  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486109  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048610c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048610e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486110  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00486113  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00486115  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00486118:
    // 00486118  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048611b  39e9                   +cmp ecx, ebp
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
    // 0048611d  75cc                   -jne 0x4860eb
    if (!cpu.flags.zf)
    {
        goto L_0x004860eb;
    }
    // 0048611f  e850f20100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00486124  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00486126  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486127  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486129  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048612a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048612b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048612c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048612d:
    // 0048612d  e842f20100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00486132  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 00486137  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486139  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048613a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048613b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048613c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048613d:
    // 0048613d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00486142  eb93                   -jmp 0x4860d7
    goto L_0x004860d7;
L_0x00486144:
    // 00486144  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00486147  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048614a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048614c  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048614f  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486151  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486153  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00486156  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00486158  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048615b  e814f20100             -call 0x4a5374
    cpu.esp -= 4;
    sub_4a5374(app, cpu);
    if (cpu.terminate) return;
    // 00486160  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486162  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486163  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486165  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486166  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486167  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486168  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486170);
    // 00486170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486173  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486174  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486175  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486176  81ec1c0c0000           -sub esp, 0xc1c
    (cpu.esp) -= x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0048617c  898424100c0000         -mov dword ptr [esp + 0xc10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */) = cpu.eax;
    // 00486183  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00486188  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0048618d  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 00486192  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00486197  899424140c0000         -mov dword ptr [esp + 0xc14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.edx;
    // 0048619e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004861a0  898c24080c0000         -mov dword ptr [esp + 0xc08], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = cpu.ecx;
    // 004861a7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004861a9:
    // 004861a9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004861ac  89740cf4               -mov dword ptr [esp + ecx - 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.esi;
    // 004861b0  81f9000c0000           +cmp ecx, 0xc00
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
    // 004861b6  75f1                   -jne 0x4861a9
    if (!cpu.flags.zf)
    {
        goto L_0x004861a9;
    }
    // 004861b8  8bb424100c0000         -mov esi, dword ptr [esp + 0xc10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 004861bf  8b34f5b0c55900         -mov esi, dword ptr [esi*8 + 0x59c5b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.esi * 8);
    // 004861c6  807e0401               +cmp byte ptr [esi + 4], 1
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
    // 004861ca  7206                   -jb 0x4861d2
    if (cpu.flags.cf)
    {
        goto L_0x004861d2;
    }
    // 004861cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004861ce  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x004861d2:
    // 004861d2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004861d4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004861d6  89bc24180c0000         -mov dword ptr [esp + 0xc18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.edi;
    // 004861dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004861df  0f8ea6000000           -jle 0x48628b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048628b;
    }
    // 004861e5  8b9424100c0000         -mov edx, dword ptr [esp + 0xc10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 004861ec  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004861ef  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004861f2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004861f4  899424000c0000         -mov dword ptr [esp + 0xc00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.edx;
    // 004861fb  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004861fe  8984240c0c0000         -mov dword ptr [esp + 0xc0c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */) = cpu.eax;
    // 00486205  899424040c0000         -mov dword ptr [esp + 0xc04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.edx;
    // 0048620c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0048620e:
    // 0048620e  807e0402               +cmp byte ptr [esi + 4], 2
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
    // 00486212  0f82b8000000           -jb 0x4862d0
    if (cpu.flags.cf)
    {
        goto L_0x004862d0;
    }
    // 00486218  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0048621a  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
L_0x0048621d:
    // 0048621d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048621f  744a                   -je 0x48626b
    if (cpu.flags.zf)
    {
        goto L_0x0048626b;
    }
    // 00486221  807e0402               +cmp byte ptr [esi + 4], 2
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
    // 00486225  0f82ad000000           -jb 0x4862d8
    if (cpu.flags.cf)
    {
        goto L_0x004862d8;
    }
    // 0048622b  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0048622e  8d550c                 -lea edx, [ebp + 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00486231  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00486234  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486236  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00486238  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0048623b:
    // 0048623b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048623d  8b9424000c0000         -mov edx, dword ptr [esp + 0xc00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 00486244  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00486246  8b92b4c55900           -mov edx, dword ptr [edx + 0x59c5b4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5883316) /* 0x59c5b4 */);
    // 0048624c  e8cfe90100             -call 0x4a4c20
    cpu.esp -= 4;
    sub_4a4c20(app, cpu);
    if (cpu.terminate) return;
    // 00486251  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486253  83f807                 +cmp eax, 7
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
    // 00486256  740b                   -je 0x486263
    if (cpu.flags.zf)
    {
        goto L_0x00486263;
    }
    // 00486258  c78424080c000008000000 -mov dword ptr [esp + 0xc08], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = 8 /*0x8*/;
L_0x00486263:
    // 00486263  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00486265  0f8c86000000           -jl 0x4862f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004862f1;
    }
L_0x0048626b:
    // 0048626b  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 00486272  8b94240c0c0000         -mov edx, dword ptr [esp + 0xc0c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */);
    // 00486279  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048627c  40                     -inc eax
    (cpu.eax)++;
    // 0048627d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486280  898424180c0000         -mov dword ptr [esp + 0xc18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.eax;
    // 00486287  39d1                   +cmp ecx, edx
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
    // 00486289  7c83                   -jl 0x48620e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048620e;
    }
L_0x0048628b:
    // 0048628b  8b9424140c0000         -mov edx, dword ptr [esp + 0xc14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
    // 00486292  83faff                 +cmp edx, -1
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
    // 00486295  7e21                   -jle 0x4862b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004862b8;
    }
    // 00486297  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486299  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048629b  7c1b                   -jl 0x4862b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004862b8;
    }
    // 0048629d  8bbc24140c0000         -mov edi, dword ptr [esp + 0xc14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
L_0x004862a4:
    // 004862a4  8b8424100c0000         -mov eax, dword ptr [esp + 0xc10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 004862ab  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004862ad  41                     -inc ecx
    (cpu.ecx)++;
    // 004862ae  e81de80100             -call 0x4a4ad0
    cpu.esp -= 4;
    sub_4a4ad0(app, cpu);
    if (cpu.terminate) return;
    // 004862b3  39f9                   +cmp ecx, edi
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
    // 004862b5  7eed                   -jle 0x4862a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004862a4;
    }
    // 004862b7  90                     -nop 
    ;
L_0x004862b8:
    // 004862b8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004862ba  7c46                   -jl 0x486302
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486302;
    }
    // 004862bc  8b8424080c0000         -mov eax, dword ptr [esp + 0xc08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */);
    // 004862c3  81c41c0c0000           +add esp, 0xc1c
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
    // 004862c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004862cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004862d0:
    // 004862d0  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004862d3  e945ffffff             -jmp 0x48621d
    goto L_0x0048621d;
L_0x004862d8:
    // 004862d8  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004862db  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 004862e2  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004862e5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004862e7  01da                   +add edx, ebx
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
    // 004862e9  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004862ec  e94affffff             -jmp 0x48623b
    goto L_0x0048623b;
L_0x004862f1:
    // 004862f1  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 004862f8  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004862f9  898424140c0000         -mov dword ptr [esp + 0xc14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.eax;
    // 00486300  eb89                   -jmp 0x48628b
    goto L_0x0048628b;
L_0x00486302:
    // 00486302  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486304  81c41c0c0000           -add esp, 0xc1c
    (cpu.esp) += x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0048630a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048630b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048630c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048630d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048630e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048630f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486310  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486314);
    // 00486314  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486316  7c0f                   -jl 0x486327
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486327;
    }
    // 00486318  83f80a                 +cmp eax, 0xa
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
    // 0048631b  7d0a                   -jge 0x486327
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486327;
    }
    // 0048631d  833cc5b0c5590000       +cmp dword ptr [eax*8 + 0x59c5b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486325  7506                   -jne 0x48632d
    if (!cpu.flags.zf)
    {
        goto L_0x0048632d;
    }
L_0x00486327:
    // 00486327  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048632c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048632d:
    // 0048632d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048632f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486330);
    // 00486330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486332  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486333  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486334  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 0048633a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048633c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048633e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00486343  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00486345:
    // 00486345  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00486348  89540cf4               -mov dword ptr [esp + ecx - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.edx;
    // 0048634c  81f9000c0000           +cmp ecx, 0xc00
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
    // 00486352  75f1                   -jne 0x486345
    if (!cpu.flags.zf)
    {
        goto L_0x00486345;
    }
    // 00486354  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486356  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00486358  7e12                   -jle 0x48636c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048636c;
    }
L_0x0048635a:
    // 0048635a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048635c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048635e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486360  41                     -inc ecx
    (cpu.ecx)++;
    // 00486361  e85ae50100             -call 0x4a48c0
    cpu.esp -= 4;
    sub_4a48c0(app, cpu);
    if (cpu.terminate) return;
    // 00486366  39f9                   +cmp ecx, edi
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
    // 00486368  7cf0                   -jl 0x48635a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048635a;
    }
    // 0048636a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048636c:
    // 0048636c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048636e  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 00486374  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486375  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486376  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486377  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486378  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48637c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048637c);
    // 0048637c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048637d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048637e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048637f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486380  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486382  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486384  8a1574da4d00           -mov dl, byte ptr [0x4dda74]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 0048638a  bff7ffffff             -mov edi, 0xfffffff7
    cpu.edi = 4294967287 /*0xfffffff7*/;
    // 0048638f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00486391  7449                   -je 0x4863dc
    if (cpu.flags.zf)
    {
        goto L_0x004863dc;
    }
    // 00486393  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
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
    // 00486399  754b                   -jne 0x4863e6
    if (!cpu.flags.zf)
    {
        goto L_0x004863e6;
    }
    // 0048639b  bab0c55900             -mov edx, 0x59c5b0
    cpu.edx = 5883312 /*0x59c5b0*/;
    // 004863a0  8b2db0c55900           -mov ebp, dword ptr [0x59c5b0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */);
    // 004863a6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004863a8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004863aa  740e                   -je 0x4863ba
    if (cpu.flags.zf)
    {
        goto L_0x004863ba;
    }
L_0x004863ac:
    // 004863ac  41                     -inc ecx
    (cpu.ecx)++;
    // 004863ad  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004863b0  83f90a                 +cmp ecx, 0xa
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
    // 004863b3  7d46                   -jge 0x4863fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004863fb;
    }
    // 004863b5  833a00                 +cmp dword ptr [edx], 0
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
    // 004863b8  75f2                   -jne 0x4863ac
    if (!cpu.flags.zf)
    {
        goto L_0x004863ac;
    }
L_0x004863ba:
    // 004863ba  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004863bc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004863be  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004863c1  e8aafdffff             -call 0x486170
    cpu.esp -= 4;
    sub_486170(app, cpu);
    if (cpu.terminate) return;
    // 004863c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004863c8  7c26                   -jl 0x4863f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004863f0;
    }
    // 004863ca  ba04644800             -mov edx, 0x486404
    cpu.edx = 4744196 /*0x486404*/;
    // 004863cf  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004863d1  89158cda4d00           -mov dword ptr [0x4dda8c], edx
    app->getMemory<x86::reg32>(x86::reg32(5102220) /* 0x4dda8c */) = cpu.edx;
    // 004863d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004863dc:
    // 004863dc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004863e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004863e6:
    // 004863e6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004863eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004863f0:
    // 004863f0  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004863f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004863fb:
    // 004863fb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004863fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004863ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486400  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486401  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486404);
    // 00486404  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486405  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486406  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486407  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486409  8a2574da4d00           -mov ah, byte ptr [0x4dda74]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102196) /* 0x4dda74 */);
    // 0048640f  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 00486414  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00486416  741a                   -je 0x486432
    if (cpu.flags.zf)
    {
        goto L_0x00486432;
    }
    // 00486418  83f9ff                 +cmp ecx, -1
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
    // 0048641b  751e                   -jne 0x48643b
    if (!cpu.flags.zf)
    {
        goto L_0x0048643b;
    }
    // 0048641d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048641f:
    // 0048641f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486421  42                     -inc edx
    (cpu.edx)++;
    // 00486422  e8ddffffff             -call 0x486404
    cpu.esp -= 4;
    sub_486404(app, cpu);
    if (cpu.terminate) return;
    // 00486427  83fa0a                 +cmp edx, 0xa
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
    // 0048642a  7cf3                   -jl 0x48641f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048641f;
    }
    // 0048642c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048642e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048642f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486430  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486431  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486432:
    // 00486432  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00486437  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486438  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486439  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048643a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048643b:
    // 0048643b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048643d  e8d2feffff             -call 0x486314
    cpu.esp -= 4;
    sub_486314(app, cpu);
    if (cpu.terminate) return;
    // 00486442  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486444  7550                   -jne 0x486496
    if (!cpu.flags.zf)
    {
        goto L_0x00486496;
    }
    // 00486446  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486447  bab0bf5900             -mov edx, 0x59bfb0
    cpu.edx = 5881776 /*0x59bfb0*/;
    // 0048644c  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x00486452:
    // 00486452  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 00486455  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00486458  39c8                   +cmp eax, ecx
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
    // 0048645a  7507                   -jne 0x486463
    if (!cpu.flags.zf)
    {
        goto L_0x00486463;
    }
    // 0048645c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048645e  e8dd330000             -call 0x489840
    cpu.esp -= 4;
    sub_489840(app, cpu);
    if (cpu.terminate) return;
L_0x00486463:
    // 00486463  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00486466  39da                   +cmp edx, ebx
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
    // 00486468  75e8                   -jne 0x486452
    if (!cpu.flags.zf)
    {
        goto L_0x00486452;
    }
    // 0048646a  8b04cdb0c55900         -mov eax, dword ptr [ecx*8 + 0x59c5b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.ecx * 8);
    // 00486471  80780401               +cmp byte ptr [eax + 4], 1
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
    // 00486475  7206                   -jb 0x48647d
    if (cpu.flags.cf)
    {
        goto L_0x0048647d;
    }
    // 00486477  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00486479  668b7006               -mov si, word ptr [eax + 6]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x0048647d:
    // 0048647d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048647f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486481  e8aafeffff             -call 0x486330
    cpu.esp -= 4;
    sub_486330(app, cpu);
    if (cpu.terminate) return;
    // 00486486  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486488  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048648a  8914cdb0c55900         -mov dword ptr [ecx*8 + 0x59c5b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5883312) /* 0x59c5b0 */ + cpu.ecx * 8) = cpu.edx;
    // 00486491  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486492  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486493  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486494  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486495  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486496:
    // 00486496  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048649b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048649c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048649d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048649e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4864a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864a0);
    // 004864a0  803d74da4d0000         +cmp byte ptr [0x4dda74], 0
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
    // 004864a7  740f                   -je 0x4864b8
    if (cpu.flags.zf)
    {
        goto L_0x004864b8;
    }
    // 004864a9  83fa7f                 +cmp edx, 0x7f
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
    // 004864ac  7f04                   -jg 0x4864b2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004864b2;
    }
    // 004864ae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004864b0  7d0c                   -jge 0x4864be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004864be;
    }
L_0x004864b2:
    // 004864b2  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004864b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004864b8:
    // 004864b8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004864bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004864be:
    // 004864be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004864bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004864c0  8815dece4d00           -mov byte ptr [0x4dcede], dl
    app->getMemory<x86::reg8>(x86::reg32(5099230) /* 0x4dcede */) = cpu.dl;
    // 004864c6  8b0d6cce4d00           -mov ecx, dword ptr [0x4dce6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099116) /* 0x4dce6c */);
    // 004864cc  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004864ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004864d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004864d2  e8a9fbffff             -call 0x486080
    cpu.esp -= 4;
    sub_486080(app, cpu);
    if (cpu.terminate) return;
    // 004864d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004864d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4864dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004864dc);
    // 004864dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004864dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004864de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004864e0  eb0b                   -jmp 0x4864ed
    goto L_0x004864ed;
L_0x004864e2:
    // 004864e2  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004864e4  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004864e6  7409                   -je 0x4864f1
    if (cpu.flags.zf)
    {
        goto L_0x004864f1;
    }
    // 004864e8  42                     -inc edx
    (cpu.edx)++;
    // 004864e9  4b                     -dec ebx
    (cpu.ebx)--;
    // 004864ea  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004864ec  40                     -inc eax
    (cpu.eax)++;
L_0x004864ed:
    // 004864ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004864ef  75f1                   -jne 0x4864e2
    if (!cpu.flags.zf)
    {
        goto L_0x004864e2;
    }
L_0x004864f1:
    // 004864f1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004864f3  7407                   -je 0x4864fc
    if (cpu.flags.zf)
    {
        goto L_0x004864fc;
    }
    // 004864f5  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004864f6  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004864f9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004864fa  ebf5                   -jmp 0x4864f1
    goto L_0x004864f1;
L_0x004864fc:
    // 004864fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004864fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004864ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486500  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486501(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486501);
    // 00486501  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486502  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486503  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486506  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048650a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048650c  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00486510  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00486513  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00486517  e868db0100             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 0048651c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048651f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486520  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486521  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486522(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486522);
    // 00486522  83f861                 +cmp eax, 0x61
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
    // 00486525  7c08                   -jl 0x48652f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048652f;
    }
    // 00486527  83f87a                 +cmp eax, 0x7a
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
    // 0048652a  7f03                   -jg 0x48652f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048652f;
    }
    // 0048652c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0048652f:
    // 0048652f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486530);
    // 00486530  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486531  9b                     -wait 
    /*nothing*/;
    // 00486532  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00486535  9b                     -wait 
    /*nothing*/;
    // 00486536  ff3424                 -push dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 00486539  c64424011f             -mov byte ptr [esp + 1], 0x1f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 0048653e  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00486541  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00486543  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486547  9b                     -wait 
    /*nothing*/;
    // 00486548  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048654c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_486550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486550);
    // 00486550  0fb680f4b24d00         -movzx eax, byte ptr [eax + 0x4db2f4]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092084) /* 0x4db2f4 */));
    // 00486557  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486558(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486558);
    // 00486558  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486559(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486559);
    // 00486559  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486560);
    // 00486560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486562  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486563  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00486566  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486568  8b1d14d74d00           -mov ebx, dword ptr [0x4dd714]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */);
    // 0048656e  890d98d74d00           -mov dword ptr [0x4dd798], ecx
    app->getMemory<x86::reg32>(x86::reg32(5101464) /* 0x4dd798 */) = cpu.ecx;
    // 00486574  39d8                   +cmp eax, ebx
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
    // 00486576  750c                   -jne 0x486584
    if (!cpu.flags.zf)
    {
        goto L_0x00486584;
    }
    // 00486578  3b1518d74d00           +cmp edx, dword ptr [0x4dd718]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5101336) /* 0x4dd718 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048657e  0f8439010000           -je 0x4866bd
    if (cpu.flags.zf)
    {
        goto L_0x004866bd;
    }
L_0x00486584:
    // 00486584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486585  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486586  a314d74d00             -mov dword ptr [0x4dd714], eax
    app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */) = cpu.eax;
    // 0048658b  891518d74d00           -mov dword ptr [0x4dd718], edx
    app->getMemory<x86::reg32>(x86::reg32(5101336) /* 0x4dd718 */) = cpu.edx;
    // 00486591  e84a4d0100             -call 0x49b2e0
    cpu.esp -= 4;
    sub_49b2e0(app, cpu);
    if (cpu.terminate) return;
    // 00486596  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486598  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0048659b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004865a1  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004865a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004865a7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004865ac  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004865b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004865b2  e8294d0100             -call 0x49b2e0
    cpu.esp -= 4;
    sub_49b2e0(app, cpu);
    if (cpu.terminate) return;
    // 004865b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004865b9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004865bb  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004865be  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 004865c2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004865c8  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 004865cc  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004865d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004865d2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004865d7  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004865da  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004865de  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004865e2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004865e8  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 004865ef  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004865f3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004865f5  8d2c9500000000         -lea ebp, [edx*4]
    cpu.ebp = x86::reg32(cpu.edx * 4);
    // 004865fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004865fe  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00486601  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486603  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00486605  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00486607  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0048660a  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0048660d  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048660f  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00486613  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00486619  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00486620  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00486624  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486626  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486628  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048662a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0048662d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048662f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00486631:
    // 00486631  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00486634  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00486637  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048663b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048663f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00486641  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00486644  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00486648  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048664c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048664e  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00486651  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00486655  037c2424               -add edi, dword ptr [esp + 0x24]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 00486659  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048665d  01442438               -add dword ptr [esp + 0x38], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486661  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00486665  01442434               -add dword ptr [esp + 0x34], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486669  2b74242c               -sub esi, dword ptr [esp + 0x2c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0048666d  2b6c2428               -sub ebp, dword ptr [esp + 0x28]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00486671  2b5c2430               -sub ebx, dword ptr [esp + 0x30]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 00486675  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486679  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048667c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048667e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00486682  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00486686  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00486689  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048668d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00486691  0b442418               -or eax, dword ptr [esp + 0x18]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00486695  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486698  0b442410               -or eax, dword ptr [esp + 0x10]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0048669c  81c100000010           -add ecx, 0x10000000
    (cpu.ecx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004866a2  e8c5bfffff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004866a7  898218d74d00           -mov dword ptr [edx + 0x4dd718], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5101336) /* 0x4dd718 */) = cpu.eax;
    // 004866ad  83fa40                 +cmp edx, 0x40
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
    // 004866b0  0f857bffffff           -jne 0x486631
    if (!cpu.flags.zf)
    {
        goto L_0x00486631;
    }
    // 004866b6  e899fc0100             -call 0x4a6354
    cpu.esp -= 4;
    sub_4a6354(app, cpu);
    if (cpu.terminate) return;
    // 004866bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004866bd:
    // 004866bd  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004866c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004866c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4866d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004866d0);
    // 004866d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004866d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004866d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004866d3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004866d5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004866d7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004866d9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004866db  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004866dd  7436                   -je 0x486715
    if (cpu.flags.zf)
    {
        goto L_0x00486715;
    }
L_0x004866df:
    // 004866df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004866e1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004866e3  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004866e6  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004866e9  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004866ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004866f0  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004866f4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004866f6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004866fd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004866ff  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00486701  29c1                   +sub ecx, eax
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
    // 00486703  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486705  7414                   -je 0x48671b
    if (cpu.flags.zf)
    {
        goto L_0x0048671b;
    }
    // 00486707  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486709  7e04                   -jle 0x48670f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048670f;
    }
    // 0048670b  4a                     -dec edx
    (cpu.edx)--;
    // 0048670c  8d3c33                 -lea edi, [ebx + esi]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x0048670f:
    // 0048670f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00486711  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486713  75ca                   -jne 0x4866df
    if (!cpu.flags.zf)
    {
        goto L_0x004866df;
    }
L_0x00486715:
    // 00486715  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486717  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486718  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486719  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048671a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048671b:
    // 0048671b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048671d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048671e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048671f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486720  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486724);
    // 00486724  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486725  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486726  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486727  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486728  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048672a  8d48e0                 -lea ecx, [eax - 0x20]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
    // 0048672d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00486734  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486736  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00486739  8b156cd74d00           -mov edx, dword ptr [0x4dd76c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101420) /* 0x4dd76c */);
    // 0048673f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486741  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00486744  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00486749  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048674b  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0048674f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00486751  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00486758  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048675a  39f0                   +cmp eax, esi
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
    // 0048675c  7507                   -jne 0x486765
    if (!cpu.flags.zf)
    {
        goto L_0x00486765;
    }
    // 0048675e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486761  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486762  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486764  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486765:
    // 00486765  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0048676a  8b1d5cd74d00           -mov ebx, dword ptr [0x4dd75c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5101404) /* 0x4dd75c */);
    // 00486770  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486772  e859ffffff             -call 0x4866d0
    cpu.esp -= 4;
    sub_4866d0(app, cpu);
    if (cpu.terminate) return;
    // 00486777  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486778  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486779  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048677a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048677b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48677c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048677c);
    // 0048677c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048677d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048677e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048677f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486780  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486783  8b3590d74d00           -mov esi, dword ptr [0x4dd790]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5101456) /* 0x4dd790 */);
    // 00486789  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048678b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048678e  a194d74d00             -mov eax, dword ptr [0x4dd794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101460) /* 0x4dd794 */);
    // 00486793  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486795  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486797  7e26                   -jle 0x4867bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004867bf;
    }
L_0x00486799:
    // 00486799  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048679b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048679d  6689fb                 -mov bx, di
    cpu.bx = cpu.di;
    // 004867a0  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004867a4  39d9                   +cmp ecx, ebx
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
    // 004867a6  750f                   -jne 0x4867b7
    if (!cpu.flags.zf)
    {
        goto L_0x004867b7;
    }
    // 004867a8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004867aa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004867ac  668b0c24               -mov cx, word ptr [esp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp);
    // 004867b0  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004867b3  39cb                   +cmp ebx, ecx
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
    // 004867b5  7412                   -je 0x4867c9
    if (cpu.flags.zf)
    {
        goto L_0x004867c9;
    }
L_0x004867b7:
    // 004867b7  42                     -inc edx
    (cpu.edx)++;
    // 004867b8  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004867bb  39f2                   +cmp edx, esi
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
    // 004867bd  7cda                   -jl 0x486799
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486799;
    }
L_0x004867bf:
    // 004867bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004867c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004867c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004867c9:
    // 004867c9  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004867cc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004867cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004867d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004867d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4867d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004867d8);
    // 004867d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004867d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004867da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004867db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004867dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004867dd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004867de  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004867e1  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004867e5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004867e8  a17cd74d00             -mov eax, dword ptr [0x4dd77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101436) /* 0x4dd77c */);
    // 004867ed  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004867f2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004867f6  a188d74d00             -mov eax, dword ptr [0x4dd788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101448) /* 0x4dd788 */);
    // 004867fb  8b35ecd64d00           -mov esi, dword ptr [0x4dd6ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */);
    // 00486801  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00486805  a18cd74d00             -mov eax, dword ptr [0x4dd78c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101452) /* 0x4dd78c */);
    // 0048680a  8b15f4d64d00           -mov edx, dword ptr [0x4dd6f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101300) /* 0x4dd6f4 */);
    // 00486810  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00486814  a194d74d00             -mov eax, dword ptr [0x4dd794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101460) /* 0x4dd794 */);
    // 00486819  8b0df8d64d00           -mov ecx, dword ptr [0x4dd6f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5101304) /* 0x4dd6f8 */);
    // 0048681f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00486823  a1f0d64d00             -mov eax, dword ptr [0x4dd6f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */);
    // 00486828  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048682a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048682c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00486830  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00486834  a1ecd64d00             -mov eax, dword ptr [0x4dd6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */);
    // 00486839  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0048683d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00486841  a180d74d00             -mov eax, dword ptr [0x4dd780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101440) /* 0x4dd780 */);
    // 00486846  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486848  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048684a  0f85fe000000           -jne 0x48694e
    if (!cpu.flags.zf)
    {
        goto L_0x0048694e;
    }
L_0x00486850:
    // 00486850  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00486855  e8cafeffff             -call 0x486724
    cpu.esp -= 4;
    sub_486724(app, cpu);
    if (cpu.terminate) return;
    // 0048685a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048685c  0f85f7000000           -jne 0x486959
    if (!cpu.flags.zf)
    {
        goto L_0x00486959;
    }
L_0x00486862:
    // 00486862  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00486866  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0048686a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048686c  45                     -inc ebp
    (cpu.ebp)++;
    // 0048686d  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486871  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486873  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00486877  83f820                 +cmp eax, 0x20
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
    // 0048687a  0f8efc000000           -jle 0x48697c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048697c;
    }
    // 00486880  e89ffeffff             -call 0x486724
    cpu.esp -= 4;
    sub_486724(app, cpu);
    if (cpu.terminate) return;
    // 00486885  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486887  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486889  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048688b  74d5                   -je 0x486862
    if (cpu.flags.zf)
    {
        goto L_0x00486862;
    }
    // 0048688d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00486892  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486895  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00486899  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048689b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004868a2  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004868a4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004868a9  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004868ad  8d4206                 -lea eax, [edx + 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004868b0  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004868b4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004868b6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004868bd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004868bf  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004868c3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004868c5  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004868c9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004868cd  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004868d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004868d3  740d                   -je 0x4868e2
    if (cpu.flags.zf)
    {
        goto L_0x004868e2;
    }
    // 004868d5  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004868d9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004868db  e89cfeffff             -call 0x48677c
    cpu.esp -= 4;
    sub_48677c(app, cpu);
    if (cpu.terminate) return;
    // 004868e0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004868e2:
    // 004868e2  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004868e5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004868e8  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004868eb  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004868ef  8b4707                 -mov eax, dword ptr [edi + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004868f2  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004868f6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004868f9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004868fb  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004868ff  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00486903  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486905  7561                   -jne 0x486968
    if (!cpu.flags.zf)
    {
        goto L_0x00486968;
    }
L_0x00486907:
    // 00486907  8b1d60d74d00           -mov ebx, dword ptr [0x4dd760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5101408) /* 0x4dd760 */);
    // 0048690d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048690f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486910  8a4703                 -mov al, byte ptr [edi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00486913  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00486917  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486918  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048691a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048691e  8a4702                 -mov al, byte ptr [edi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00486921  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486923  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486924  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00486928  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048692c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048692d  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00486931  8b1d70d74d00           -mov ebx, dword ptr [0x4dd770]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5101424) /* 0x4dd770 */);
    // 00486937  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00486939  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048693d  ff542420               -call dword ptr [esp + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486941  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 00486944  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00486947  01c6                   +add esi, eax
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
    // 00486949  e914ffffff             -jmp 0x486862
    goto L_0x00486862;
L_0x0048694e:
    // 0048694e  ff1580d74d00           -call dword ptr [0x4dd780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5101440) /* 0x4dd780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486954  e9f7feffff             -jmp 0x486850
    goto L_0x00486850;
L_0x00486959:
    // 00486959  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0048695c  c1f818                 +sar eax, 0x18
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
    // 0048695f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00486963  e9fafeffff             -jmp 0x486862
    goto L_0x00486862;
L_0x00486968:
    // 00486968  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048696c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486970  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486974  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00486976  ff54243c               -call dword ptr [esp + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048697a  eb8b                   -jmp 0x486907
    goto L_0x00486907;
L_0x0048697c:
    // 0048697c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048697e  7535                   -jne 0x4869b5
    if (!cpu.flags.zf)
    {
        goto L_0x004869b5;
    }
    // 00486980  833d84d74d0000         +cmp dword ptr [0x4dd784], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101444) /* 0x4dd784 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486987  0f8598000000           -jne 0x486a25
    if (!cpu.flags.zf)
    {
        goto L_0x00486a25;
    }
L_0x0048698d:
    // 0048698d  a1f4d64d00             -mov eax, dword ptr [0x4dd6f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101300) /* 0x4dd6f4 */);
    // 00486992  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00486996  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00486998  a1f8d64d00             -mov eax, dword ptr [0x4dd6f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101304) /* 0x4dd6f8 */);
    // 0048699d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048699f  8935ecd64d00           -mov dword ptr [0x4dd6ec], esi
    app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */) = cpu.esi;
    // 004869a5  8915f0d64d00           -mov dword ptr [0x4dd6f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */) = cpu.edx;
    // 004869ab  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004869ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004869b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004869b5:
    // 004869b5  83f80a                 +cmp eax, 0xa
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
    // 004869b8  7521                   -jne 0x4869db
    if (!cpu.flags.zf)
    {
        goto L_0x004869db;
    }
    // 004869ba  8b1504d74d00           -mov edx, dword ptr [0x4dd704]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5101316) /* 0x4dd704 */);
    // 004869c0  8b3d08d74d00           -mov edi, dword ptr [0x4dd708]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5101320) /* 0x4dd708 */);
    // 004869c6  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004869ca  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004869cc  01d0                   +add eax, edx
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
    // 004869ce  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004869d2  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004869d6  e987feffff             -jmp 0x486862
    goto L_0x00486862;
L_0x004869db:
    // 004869db  833d44b54d0000         +cmp dword ptr [0x4db544], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092676) /* 0x4db544 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004869e2  7509                   -jne 0x4869ed
    if (!cpu.flags.zf)
    {
        goto L_0x004869ed;
    }
L_0x004869e4:
    // 004869e4  0374241c               +add esi, dword ptr [esp + 0x1c]
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
    // 004869e8  e975feffff             -jmp 0x486862
    goto L_0x00486862;
L_0x004869ed:
    // 004869ed  83f809                 +cmp eax, 9
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
    // 004869f0  75f2                   -jne 0x4869e4
    if (!cpu.flags.zf)
    {
        goto L_0x004869e4;
    }
    // 004869f2  8b1d40b54d00           -mov ebx, dword ptr [0x4db540]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092672) /* 0x4db540 */);
    // 004869f8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004869fa  0f8e62feffff           -jle 0x486862
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486862;
    }
    // 00486a00  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00486a03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00486a05:
    // 00486a05  a144b54d00             -mov eax, dword ptr [0x4db544]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092676) /* 0x4db544 */);
    // 00486a0a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00486a0c  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00486a0e  39fe                   +cmp esi, edi
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
    // 00486a10  7d07                   -jge 0x486a19
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00486a19;
    }
    // 00486a12  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00486a14  e949feffff             -jmp 0x486862
    goto L_0x00486862;
L_0x00486a19:
    // 00486a19  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486a1c  39da                   +cmp edx, ebx
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
    // 00486a1e  7ce5                   -jl 0x486a05
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486a05;
    }
    // 00486a20  e93dfeffff             -jmp 0x486862
    goto L_0x00486862;
L_0x00486a25:
    // 00486a25  ff1584d74d00           -call dword ptr [0x4dd784]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5101444) /* 0x4dd784 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486a2b  e95dffffff             -jmp 0x48698d
    goto L_0x0048698d;
}

/* align: skip  */
void Application::sub_486a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a30);
    // 00486a30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486a31  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486a33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00486a35  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00486a37  e8bc070000             -call 0x4871f8
    cpu.esp -= 4;
    sub_4871f8(app, cpu);
    if (cpu.terminate) return;
    // 00486a3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486a3e  e895fdffff             -call 0x4867d8
    cpu.esp -= 4;
    sub_4867d8(app, cpu);
    if (cpu.terminate) return;
    // 00486a43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486a44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486a45(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486a45);
    // 00486a45  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486a46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486a47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486a48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486a49  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00486a4f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486a51  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00486a53  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00486a55  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486a56  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00486a5b  2eff15c0644c00         -call dword ptr cs:[0x4c64c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006528) /* 0x4c64c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486a62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486a64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486a66  7507                   -jne 0x486a6f
    if (!cpu.flags.zf)
    {
        goto L_0x00486a6f;
    }
    // 00486a68  e845fb0100             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 00486a6d  eb20                   -jmp 0x486a8f
    goto L_0x00486a8f;
L_0x00486a6f:
    // 00486a6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00486a71  7520                   -jne 0x486a93
    if (!cpu.flags.zf)
    {
        goto L_0x00486a93;
    }
    // 00486a73  40                     -inc eax
    (cpu.eax)++;
    // 00486a74  39c6                   +cmp esi, eax
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
    // 00486a76  7602                   -jbe 0x486a7a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486a7a;
    }
    // 00486a78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00486a7a:
    // 00486a7a  e844fb0100             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 00486a7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486a81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486a83  7519                   -jne 0x486a9e
    if (!cpu.flags.zf)
    {
        goto L_0x00486a9e;
    }
    // 00486a85  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x00486a8a:
    // 00486a8a  e821fc0100             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
L_0x00486a8f:
    // 00486a8f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486a91  eb28                   -jmp 0x486abb
    goto L_0x00486abb;
L_0x00486a93:
    // 00486a93  39f0                   +cmp eax, esi
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
    // 00486a95  7607                   -jbe 0x486a9e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00486a9e;
    }
    // 00486a97  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00486a9c  ebec                   -jmp 0x486a8a
    goto L_0x00486a8a;
L_0x00486a9e:
    // 00486a9e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00486aa0  41                     -inc ecx
    (cpu.ecx)++;
    // 00486aa1  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00486aa3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00486aa4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00486aa6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00486aa8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486aa9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486aab  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00486aae  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00486ab0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00486ab2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00486ab5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00486ab7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ab8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00486ab9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00486abb:
    // 00486abb  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00486ac1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ac2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ac4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ac5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486ac6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486ac6);
    // 00486ac6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486ac7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486ac8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486acb  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00486acd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486acf  7419                   -je 0x486aea
    if (cpu.flags.zf)
    {
        goto L_0x00486aea;
    }
    // 00486ad1  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00486ad3  b25c                   -mov dl, 0x5c
    cpu.dl = 92 /*0x5c*/;
    // 00486ad5  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00486ad8  88542402               -mov byte ptr [esp + 2], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dl;
    // 00486adc  b43a                   -mov ah, 0x3a
    cpu.ah = 58 /*0x3a*/;
    // 00486ade  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00486ae0  88642401               -mov byte ptr [esp + 1], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.ah;
    // 00486ae4  88742403               -mov byte ptr [esp + 3], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 00486ae8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x00486aea:
    // 00486aea  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486aee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486aef  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00486af3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486af4  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00486af8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486af9  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00486afd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486afe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00486aff  2eff15d4644c00         -call dword ptr cs:[0x4c64d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006548) /* 0x4c64d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486b06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486b08  7507                   -jne 0x486b11
    if (!cpu.flags.zf)
    {
        goto L_0x00486b11;
    }
    // 00486b0a  e8a3fa0100             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 00486b0f  eb1d                   -jmp 0x486b2e
    goto L_0x00486b2e;
L_0x00486b11:
    // 00486b11  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00486b15  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00486b17  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486b1b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00486b1e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00486b22  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00486b25  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00486b29  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00486b2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00486b2e:
    // 00486b2e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00486b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486b40);
    // 00486b40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486b41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486b42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486b43  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486b45  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00486b47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486b49  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00486b4b  7e41                   -jle 0x486b8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00486b8e;
    }
L_0x00486b4d:
    // 00486b4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486b4f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00486b51  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00486b53  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00486b55  743b                   -je 0x486b92
    if (cpu.flags.zf)
    {
        goto L_0x00486b92;
    }
    // 00486b57  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486b59  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00486b5b  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
L_0x00486b5e:
    // 00486b5e  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00486b60  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00486b62  7425                   -je 0x486b89
    if (cpu.flags.zf)
    {
        goto L_0x00486b89;
    }
    // 00486b64  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486b66  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00486b68  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00486b6a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00486b6c  742f                   -je 0x486b9d
    if (cpu.flags.zf)
    {
        goto L_0x00486b9d;
    }
    // 00486b6e  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00486b70  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00486b73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486b75  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00486b77  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00486b7d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x00486b80:
    // 00486b80  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486b82  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486b84  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00486b86  881431                 -mov byte ptr [ecx + esi], dl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.dl;
L_0x00486b89:
    // 00486b89  40                     -inc eax
    (cpu.eax)++;
    // 00486b8a  39d8                   +cmp eax, ebx
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
    // 00486b8c  7cbf                   -jl 0x486b4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486b4d;
    }
L_0x00486b8e:
    // 00486b8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486b91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486b92:
    // 00486b92  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00486b94  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486b96  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 00486b99  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00486b9b  ebc1                   -jmp 0x486b5e
    goto L_0x00486b5e;
L_0x00486b9d:
    // 00486b9d  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00486b9f  80e6f0                 -and dh, 0xf0
    cpu.dh &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00486ba2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486ba4  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 00486ba6  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00486bac  ebd2                   -jmp 0x486b80
    goto L_0x00486b80;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486bb0);
    // 00486bb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00486bb1:
    // 00486bb1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00486bb3  40                     -inc eax
    (cpu.eax)++;
    // 00486bb4  80f9ff                 +cmp cl, 0xff
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
    // 00486bb7  7506                   -jne 0x486bbf
    if (!cpu.flags.zf)
    {
        goto L_0x00486bbf;
    }
    // 00486bb9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486bba  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486bbb  75f4                   -jne 0x486bb1
    if (!cpu.flags.zf)
    {
        goto L_0x00486bb1;
    }
    // 00486bbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bbe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486bbf:
    // 00486bbf  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 00486bc1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00486bc2  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486bc3  75ec                   -jne 0x486bb1
    if (!cpu.flags.zf)
    {
        goto L_0x00486bb1;
    }
    // 00486bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486bc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486bc8);
    // 00486bc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x00486bc9:
    // 00486bc9  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00486bcc  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00486bcf  750b                   -jne 0x486bdc
    if (!cpu.flags.zf)
    {
        goto L_0x00486bdc;
    }
    // 00486bd1  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00486bd4  83c202                 +add edx, 2
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
    // 00486bd7  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486bd8  75ef                   -jne 0x486bc9
    if (!cpu.flags.zf)
    {
        goto L_0x00486bc9;
    }
    // 00486bda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486bdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486bdc:
    // 00486bdc  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00486bdf  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00486be2  83c202                 +add edx, 2
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
    // 00486be5  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486be6  75e1                   -jne 0x486bc9
    if (!cpu.flags.zf)
    {
        goto L_0x00486bc9;
    }
    // 00486be8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486be9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486bec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486bec);
    // 00486bec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486bed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486bee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486bef  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00486bf4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00486bf6:
    // 00486bf6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00486bf8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486bfa  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00486bfe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00486c00  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00486c07  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00486c09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486c0b  750d                   -jne 0x486c1a
    if (!cpu.flags.zf)
    {
        goto L_0x00486c1a;
    }
    // 00486c0d  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00486c10  83c203                 +add edx, 3
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
    // 00486c13  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486c14  75e0                   -jne 0x486bf6
    if (!cpu.flags.zf)
    {
        goto L_0x00486bf6;
    }
    // 00486c16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c1a:
    // 00486c1a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00486c1c  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00486c1e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00486c21  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00486c24  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00486c27  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00486c2a  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00486c2d  83c203                 +add edx, 3
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
    // 00486c30  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486c31  75c3                   -jne 0x486bf6
    if (!cpu.flags.zf)
    {
        goto L_0x00486bf6;
    }
    // 00486c33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486c38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486c38);
    // 00486c38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486c39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x00486c3a:
    // 00486c3a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00486c3c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00486c3e  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 00486c41  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00486c43  750c                   -jne 0x486c51
    if (!cpu.flags.zf)
    {
        goto L_0x00486c51;
    }
    // 00486c45  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486c48  83c204                 +add edx, 4
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
    // 00486c4b  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486c4c  75ec                   -jne 0x486c3a
    if (!cpu.flags.zf)
    {
        goto L_0x00486c3a;
    }
    // 00486c4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486c51:
    // 00486c51  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00486c53  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00486c56  83c204                 +add edx, 4
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
    // 00486c59  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00486c5a  75de                   -jne 0x486c3a
    if (!cpu.flags.zf)
    {
        goto L_0x00486c3a;
    }
    // 00486c5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486c5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486c60);
    // 00486c60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486c61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486c62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486c63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486c64  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 00486c6a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486c6c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00486c6e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00486c70  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00486c73  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 00486c79  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486c7b  83f804                 +cmp eax, 4
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
    // 00486c7e  0f8580000000           -jne 0x486d04
    if (!cpu.flags.zf)
    {
        goto L_0x00486d04;
    }
    // 00486c84  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00486c86:
    // 00486c86  8b0cad600e5700         -mov ecx, dword ptr [ebp*4 + 0x570e60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.ebp * 4);
    // 00486c8d  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 00486c94  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486c96  890d64b54d00           -mov dword ptr [0x4db564], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092708) /* 0x4db564 */) = cpu.ecx;
    // 00486c9c  890cad600e5700         -mov dword ptr [ebp*4 + 0x570e60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.ebp * 4) = cpu.ecx;
    // 00486ca3  83fa08                 +cmp edx, 8
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
    // 00486ca6  752d                   -jne 0x486cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00486cd5;
    }
    // 00486ca8  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486caf  7524                   -jne 0x486cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00486cd5;
    }
    // 00486cb1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00486cb3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486cb5  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 00486cba  e801320100             -call 0x499ec0
    cpu.esp -= 4;
    sub_499ec0(app, cpu);
    if (cpu.terminate) return;
    // 00486cbf  baec664a00             -mov edx, 0x4a66ec
    cpu.edx = 4876012 /*0x4a66ec*/;
    // 00486cc4  a3283f5600             -mov dword ptr [0x563f28], eax
    app->getMemory<x86::reg32>(x86::reg32(5652264) /* 0x563f28 */) = cpu.eax;
    // 00486cc9  890d6cb54d00           -mov dword ptr [0x4db56c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092716) /* 0x4db56c */) = cpu.ecx;
    // 00486ccf  891564b54d00           -mov dword ptr [0x4db564], edx
    app->getMemory<x86::reg32>(x86::reg32(5092708) /* 0x4db564 */) = cpu.edx;
L_0x00486cd5:
    // 00486cd5  b94cb54d00             -mov ecx, 0x4db54c
    cpu.ecx = 5092684 /*0x4db54c*/;
    // 00486cda  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00486cdc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486cde  e8d9a30100             -call 0x4a10bc
    cpu.esp -= 4;
    sub_4a10bc(app, cpu);
    if (cpu.terminate) return;
    // 00486ce3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486ce5  8b842400040000         -mov eax, dword ptr [esp + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00486cec  891d6cb54d00           -mov dword ptr [0x4db56c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092716) /* 0x4db56c */) = cpu.ebx;
    // 00486cf2  8904ad600e5700         -mov dword ptr [ebp*4 + 0x570e60], eax
    app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.ebp * 4) = cpu.eax;
    // 00486cf9  81c404040000           +add esp, 0x404
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
    // 00486cff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486d04:
    // 00486d04  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 00486d09  e978ffffff             -jmp 0x486c86
    goto L_0x00486c86;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d10);
    // 00486d10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486d11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486d12  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00486d15  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00486d18  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00486d1b  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00486d1e  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00486d21  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00486d24  e837ffffff             -call 0x486c60
    cpu.esp -= 4;
    sub_486c60(app, cpu);
    if (cpu.terminate) return;
    // 00486d29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486d2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d2c);
    // 00486d2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486d2d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00486d30  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00486d33  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486d35  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00486d38  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00486d3b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486d3d  e81effffff             -call 0x486c60
    cpu.esp -= 4;
    sub_486c60(app, cpu);
    if (cpu.terminate) return;
    // 00486d42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486d44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d44);
    // 00486d44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486d45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486d46  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00486d49  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00486d4c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00486d4f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00486d52  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00486d55  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00486d58  e803ffffff             -call 0x486c60
    cpu.esp -= 4;
    sub_486c60(app, cpu);
    if (cpu.terminate) return;
    // 00486d5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d60);
    // 00486d60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486d61  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00486d64  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00486d67  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486d69  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00486d6c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00486d6f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486d71  e8eafeffff             -call 0x486c60
    cpu.esp -= 4;
    sub_486c60(app, cpu);
    if (cpu.terminate) return;
    // 00486d76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486d77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_486d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486d80);
    // 00486d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486d82  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00486d84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486d86  83fb3a                 +cmp ebx, 0x3a
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
    // 00486d89  0f8486000000           -je 0x486e15
    if (cpu.flags.zf)
    {
        goto L_0x00486e15;
    }
    // 00486d8f  803d2cb34d0000         +cmp byte ptr [0x4db32c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092140) /* 0x4db32c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486d96  7426                   -je 0x486dbe
    if (cpu.flags.zf)
    {
        goto L_0x00486dbe;
    }
    // 00486d98  b9e0b44d00             -mov ecx, 0x4db4e0
    cpu.ecx = 5092576 /*0x4db4e0*/;
L_0x00486d9d:
    // 00486d9d  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 00486da0  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00486da2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00486da7  3d80000000             +cmp eax, 0x80
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
    // 00486dac  7c0d                   -jl 0x486dbb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486dbb;
    }
    // 00486dae  3d90000000             +cmp eax, 0x90
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
    // 00486db3  7c03                   -jl 0x486db8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486db8;
    }
    // 00486db5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x00486db8:
    // 00486db8  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
L_0x00486dbb:
    // 00486dbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486dbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486dbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486dbe:
    // 00486dbe  803d11b34d0000         +cmp byte ptr [0x4db311], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092113) /* 0x4db311 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486dc5  741e                   -je 0x486de5
    if (cpu.flags.zf)
    {
        goto L_0x00486de5;
    }
    // 00486dc7  833decb24d0000         +cmp dword ptr [0x4db2ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092076) /* 0x4db2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486dce  7405                   -je 0x486dd5
    if (cpu.flags.zf)
    {
        goto L_0x00486dd5;
    }
    // 00486dd0  83fb01                 +cmp ebx, 1
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
    // 00486dd3  7407                   -je 0x486ddc
    if (cpu.flags.zf)
    {
        goto L_0x00486ddc;
    }
L_0x00486dd5:
    // 00486dd5  b985b44d00             -mov ecx, 0x4db485
    cpu.ecx = 5092485 /*0x4db485*/;
    // 00486dda  ebc1                   -jmp 0x486d9d
    goto L_0x00486d9d;
L_0x00486ddc:
    // 00486ddc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00486dde  e8555a0100             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
    // 00486de3  ebb8                   -jmp 0x486d9d
    goto L_0x00486d9d;
L_0x00486de5:
    // 00486de5  803d1eb34d0000         +cmp byte ptr [0x4db31e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092126) /* 0x4db31e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486dec  7407                   -je 0x486df5
    if (cpu.flags.zf)
    {
        goto L_0x00486df5;
    }
L_0x00486dee:
    // 00486dee  b9cfb34d00             -mov ecx, 0x4db3cf
    cpu.ecx = 5092303 /*0x4db3cf*/;
    // 00486df3  eba8                   -jmp 0x486d9d
    goto L_0x00486d9d;
L_0x00486df5:
    // 00486df5  803d2ab34d0000         +cmp byte ptr [0x4db32a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092138) /* 0x4db32a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00486dfc  75f0                   -jne 0x486dee
    if (!cpu.flags.zf)
    {
        goto L_0x00486dee;
    }
    // 00486dfe  833df0b24d0000         +cmp dword ptr [0x4db2f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092080) /* 0x4db2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486e05  7407                   -je 0x486e0e
    if (cpu.flags.zf)
    {
        goto L_0x00486e0e;
    }
    // 00486e07  b92ab44d00             -mov ecx, 0x4db42a
    cpu.ecx = 5092394 /*0x4db42a*/;
    // 00486e0c  eb8f                   -jmp 0x486d9d
    goto L_0x00486d9d;
L_0x00486e0e:
    // 00486e0e  b974b34d00             -mov ecx, 0x4db374
    cpu.ecx = 5092212 /*0x4db374*/;
    // 00486e13  eb88                   -jmp 0x486d9d
    goto L_0x00486d9d;
L_0x00486e15:
    // 00486e15  833df0b24d0000         +cmp dword ptr [0x4db2f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092080) /* 0x4db2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486e1c  750e                   -jne 0x486e2c
    if (!cpu.flags.zf)
    {
        goto L_0x00486e2c;
    }
    // 00486e1e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00486e23  890df0b24d00           -mov dword ptr [0x4db2f0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092080) /* 0x4db2f0 */) = cpu.ecx;
    // 00486e29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486e2c:
    // 00486e2c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00486e2e  890df0b24d00           -mov dword ptr [0x4db2f0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5092080) /* 0x4db2f0 */) = cpu.ecx;
    // 00486e34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e35  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486e36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486e38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486e38);
    // 00486e38  e8f3b1ffff             -call 0x482030
    cpu.esp -= 4;
    sub_482030(app, cpu);
    if (cpu.terminate) return;
    // 00486e3d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00486e42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486e44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486e44);
    // 00486e44  e8e7b1ffff             -call 0x482030
    cpu.esp -= 4;
    sub_482030(app, cpu);
    if (cpu.terminate) return;
    // 00486e49  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00486e4e  e955f90100             -jmp 0x4a67a8
    return sub_4a67a8(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_486e54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486e54);
    // 00486e54  a370b54d00             -mov dword ptr [0x4db570], eax
    app->getMemory<x86::reg32>(x86::reg32(5092720) /* 0x4db570 */) = cpu.eax;
    // 00486e59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486e5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486e5c);
    // 00486e5c  833d70b54d0000         +cmp dword ptr [0x4db570], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092720) /* 0x4db570 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486e63  7503                   -jne 0x486e68
    if (!cpu.flags.zf)
    {
        goto L_0x00486e68;
    }
    // 00486e65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486e67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486e68:
    // 00486e68  ff1570b54d00           -call dword ptr [0x4db570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092720) /* 0x4db570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00486e6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486e70);
L_0x00486e70:
    // 00486e70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486e72  e839d0ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00486e77  e8e0ffffff             -call 0x486e5c
    cpu.esp -= 4;
    sub_486e5c(app, cpu);
    if (cpu.terminate) return;
    // 00486e7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486e7e  74f0                   -je 0x486e70
    if (cpu.flags.zf)
    {
        goto L_0x00486e70;
    }
    // 00486e80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486e84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486e84);
    // 00486e84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486e85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486e86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486e87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00486e89:
    // 00486e89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00486e8b  e820d0ffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00486e90  e8c7ffffff             -call 0x486e5c
    cpu.esp -= 4;
    sub_486e5c(app, cpu);
    if (cpu.terminate) return;
    // 00486e95  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486e97  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486e99  e863c5ffff             -call 0x483401
    cpu.esp -= 4;
    sub_483401(app, cpu);
    if (cpu.terminate) return;
    // 00486e9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ea0  7508                   -jne 0x486eaa
    if (!cpu.flags.zf)
    {
        goto L_0x00486eaa;
    }
    // 00486ea2  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486ea4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486ea6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ea7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ea8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ea9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486eaa:
    // 00486eaa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486eac  74db                   -je 0x486e89
    if (cpu.flags.zf)
    {
        goto L_0x00486e89;
    }
    // 00486eae  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486eb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486eb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486eb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486eb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486eb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486eb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486eb8);
    // 00486eb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486eb9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486eba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00486ebc  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00486ec1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00486ec3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00486ec5:
    // 00486ec5  e892ffffff             -call 0x486e5c
    cpu.esp -= 4;
    sub_486e5c(app, cpu);
    if (cpu.terminate) return;
    // 00486eca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ecc  7403                   -je 0x486ed1
    if (cpu.flags.zf)
    {
        goto L_0x00486ed1;
    }
    // 00486ece  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ecf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ed0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486ed1:
    // 00486ed1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486ed3  e8d8cfffff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
    // 00486ed8  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00486edd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00486edf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ee1  7ce2                   -jl 0x486ec5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00486ec5;
    }
    // 00486ee3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00486ee5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ee6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486ee7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486ee8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486ee8);
    // 00486ee8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486ee9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486eea  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486ef1  741d                   -je 0x486f10
    if (cpu.flags.zf)
    {
        goto L_0x00486f10;
    }
L_0x00486ef3:
    // 00486ef3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00486ef8  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 00486efd  b8f4b24d00             -mov eax, 0x4db2f4
    cpu.eax = 5092084 /*0x4db2f4*/;
    // 00486f02  890dd8355600           -mov dword ptr [0x5635d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5649880) /* 0x5635d8 */) = cpu.ecx;
    // 00486f08  e80f310000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 00486f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486f10:
    // 00486f10  e8e32f0000             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 00486f15  a338ab4d00             -mov dword ptr [0x4dab38], eax
    app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */) = cpu.eax;
    // 00486f1a  ebd7                   -jmp 0x486ef3
    goto L_0x00486ef3;
}

/* align: skip  */
void Application::sub_486f1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f1c);
    // 00486f1c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00486f1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00486f1f  8915d8355600           -mov dword ptr [0x5635d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5649880) /* 0x5635d8 */) = cpu.edx;
    // 00486f25  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_486f28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f28);
L_0x00486f28:
    // 00486f28  e803b1ffff             -call 0x482030
    cpu.esp -= 4;
    sub_482030(app, cpu);
    if (cpu.terminate) return;
    // 00486f2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486f2f  75f7                   -jne 0x486f28
    if (!cpu.flags.zf)
    {
        goto L_0x00486f28;
    }
    // 00486f31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f34);
    // 00486f34  e847b0ffff             -call 0x481f80
    cpu.esp -= 4;
    sub_481f80(app, cpu);
    if (cpu.terminate) return;
    // 00486f39  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00486f3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_486f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f40);
    // 00486f40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486f41  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00486f46  e811000000             -call 0x486f5c
    cpu.esp -= 4;
    sub_486f5c(app, cpu);
    if (cpu.terminate) return;
    // 00486f4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f50);
    // 00486f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486f51  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486f53  e804000000             -call 0x486f5c
    cpu.esp -= 4;
    sub_486f5c(app, cpu);
    if (cpu.terminate) return;
    // 00486f58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486f5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f5c);
    // 00486f5c  e823000000             -call 0x486f84
    cpu.esp -= 4;
    sub_486f84(app, cpu);
    if (cpu.terminate) return;
    // 00486f61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486f63  7402                   -je 0x486f67
    if (cpu.flags.zf)
    {
        goto L_0x00486f67;
    }
    // 00486f65  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00486f67:
    // 00486f67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_486f68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f68);
    // 00486f68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486f69  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00486f6e  e811000000             -call 0x486f84
    cpu.esp -= 4;
    sub_486f84(app, cpu);
    if (cpu.terminate) return;
    // 00486f73  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_486f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f78);
    // 00486f78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486f79  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00486f7b  e804000000             -call 0x486f84
    cpu.esp -= 4;
    sub_486f84(app, cpu);
    if (cpu.terminate) return;
    // 00486f80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486f81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_486f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00486f84);
    // 00486f84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00486f85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00486f86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00486f87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00486f88  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486f8b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00486f8d  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00486f91  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00486f93  e88cd60100             -call 0x4a4624
    cpu.esp -= 4;
    sub_4a4624(app, cpu);
    if (cpu.terminate) return;
    // 00486f98  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486f9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486f9c  7417                   -je 0x486fb5
    if (cpu.flags.zf)
    {
        goto L_0x00486fb5;
    }
L_0x00486f9e:
    // 00486f9e  833d50dd4d0000         +cmp dword ptr [0x4ddd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102928) /* 0x4ddd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00486fa5  0f8590000000           -jne 0x48703b
    if (!cpu.flags.zf)
    {
        goto L_0x0048703b;
    }
    // 00486fab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00486fad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00486fb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00486fb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00486fb5:
    // 00486fb5  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 00486fba  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00486fbc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486fc0  e85fe10100             -call 0x4a5124
    cpu.esp -= 4;
    sub_4a5124(app, cpu);
    if (cpu.terminate) return;
    // 00486fc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00486fc6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486fc8  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486fcc  e897060000             -call 0x487668
    cpu.esp -= 4;
    sub_487668(app, cpu);
    if (cpu.terminate) return;
    // 00486fd1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00486fd4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00486fd6  7511                   -jne 0x486fe9
    if (!cpu.flags.zf)
    {
        goto L_0x00486fe9;
    }
    // 00486fd8  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00486fdc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00486fde  74be                   -je 0x486f9e
    if (cpu.flags.zf)
    {
        goto L_0x00486f9e;
    }
    // 00486fe0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00486fe2  e869090000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 00486fe7  ebb5                   -jmp 0x486f9e
    goto L_0x00486f9e;
L_0x00486fe9:
    // 00486fe9  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00486fed  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00486fef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00486ff1  e8ded4ffff             -call 0x4844d4
    cpu.esp -= 4;
    sub_4844d4(app, cpu);
    if (cpu.terminate) return;
    // 00486ff6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00486ff8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00486ffa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00486ffc  742f                   -je 0x48702d
    if (cpu.flags.zf)
    {
        goto L_0x0048702d;
    }
    // 00486ffe  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487001  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487003  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 00487008  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048700b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048700d  05c8000000             +add eax, 0xc8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487012  e80de10100             -call 0x4a5124
    cpu.esp -= 4;
    sub_4a5124(app, cpu);
    if (cpu.terminate) return;
    // 00487017  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048701a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048701e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00487020  e833090000             -call 0x487958
    cpu.esp -= 4;
    sub_487958(app, cpu);
    if (cpu.terminate) return;
    // 00487025  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487028  a3ecab4d00             -mov dword ptr [0x4dabec], eax
    app->getMemory<x86::reg32>(x86::reg32(5090284) /* 0x4dabec */) = cpu.eax;
L_0x0048702d:
    // 0048702d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487031  e81a090000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 00487036  e963ffffff             -jmp 0x486f9e
    goto L_0x00486f9e;
L_0x0048703b:
    // 0048703b  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048703f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00487041  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00487043  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00487045  ff1550dd4d00           -call dword ptr [0x4ddd50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5102928) /* 0x4ddd50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048704b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048704d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048704f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487052  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487053  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487054  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487055  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487056  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487060);
    // 00487060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487062  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487063  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487064  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487065  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487067  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048706a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048706c  8b400d                 -mov eax, dword ptr [eax + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0048706f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00487072  a3f4d64d00             -mov dword ptr [0x4dd6f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5101300) /* 0x4dd6f4 */) = cpu.eax;
    // 00487077  8b420e                 -mov eax, dword ptr [edx + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 0048707a  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0048707f  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00487082  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00487087  a3f8d64d00             -mov dword ptr [0x4dd6f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5101304) /* 0x4dd6f8 */) = cpu.eax;
    // 0048708c  8b420f                 -mov eax, dword ptr [edx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0048708f  891568d74d00           -mov dword ptr [0x4dd768], edx
    app->getMemory<x86::reg32>(x86::reg32(5101416) /* 0x4dd768 */) = cpu.edx;
    // 00487095  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00487098  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048709a  a304d74d00             -mov dword ptr [0x4dd704], eax
    app->getMemory<x86::reg32>(x86::reg32(5101316) /* 0x4dd704 */) = cpu.eax;
    // 0048709f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004870a2  891d64d74d00           -mov dword ptr [0x4dd764], ebx
    app->getMemory<x86::reg32>(x86::reg32(5101412) /* 0x4dd764 */) = cpu.ebx;
    // 004870a8  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004870ab  893500d74d00           -mov dword ptr [0x4dd700], esi
    app->getMemory<x86::reg32>(x86::reg32(5101312) /* 0x4dd700 */) = cpu.esi;
    // 004870b1  a308d74d00             -mov dword ptr [0x4dd708], eax
    app->getMemory<x86::reg32>(x86::reg32(5101320) /* 0x4dd708 */) = cpu.eax;
    // 004870b6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004870b8  a104d74d00             -mov eax, dword ptr [0x4dd704]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101316) /* 0x4dd704 */);
    // 004870bd  893d98d74d00           -mov dword ptr [0x4dd798], edi
    app->getMemory<x86::reg32>(x86::reg32(5101464) /* 0x4dd798 */) = cpu.edi;
    // 004870c3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004870c5  893d94d74d00           -mov dword ptr [0x4dd794], edi
    app->getMemory<x86::reg32>(x86::reg32(5101460) /* 0x4dd794 */) = cpu.edi;
    // 004870cb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004870cd  891d0cd74d00           -mov dword ptr [0x4dd70c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5101324) /* 0x4dd70c */) = cpu.ebx;
    // 004870d3  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004870d5  891d10d74d00           -mov dword ptr [0x4dd710], ebx
    app->getMemory<x86::reg32>(x86::reg32(5101328) /* 0x4dd710 */) = cpu.ebx;
    // 004870db  668b420a               -mov ax, word ptr [edx + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 004870df  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004870e1  a35cd74d00             -mov dword ptr [0x4dd75c], eax
    app->getMemory<x86::reg32>(x86::reg32(5101404) /* 0x4dd75c */) = cpu.eax;
    // 004870e6  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004870e9  890d70d74d00           -mov dword ptr [0x4dd770], ecx
    app->getMemory<x86::reg32>(x86::reg32(5101424) /* 0x4dd770 */) = cpu.ecx;
    // 004870ef  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004870f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004870f3  891d6cd74d00           -mov dword ptr [0x4dd76c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5101420) /* 0x4dd76c */) = cpu.ebx;
    // 004870f9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004870fb  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004870fe  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 00487104  a3fcd64d00             -mov dword ptr [0x4dd6fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5101308) /* 0x4dd6fc */) = cpu.eax;
    // 00487109  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0048710c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048710e  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00487111  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00487113  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00487116  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 0048711c  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048711f  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00487122  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00487124  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00487127  a360d74d00             -mov dword ptr [0x4dd760], eax
    app->getMemory<x86::reg32>(x86::reg32(5101408) /* 0x4dd760 */) = cpu.eax;
    // 0048712c  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048712f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00487132  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00487135  83f802                 +cmp eax, 2
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
    // 00487138  740c                   -je 0x487146
    if (cpu.flags.zf)
    {
        goto L_0x00487146;
    }
    // 0048713a  813d5cd74d00ff000000   +cmp dword ptr [0x4dd75c], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101404) /* 0x4dd75c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487144  7e38                   -jle 0x48717e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048717e;
    }
L_0x00487146:
    // 00487146  c70588d74d008c684a00   -mov dword ptr [0x4dd788], 0x4a688c
    app->getMemory<x86::reg32>(x86::reg32(5101448) /* 0x4dd788 */) = 4876428 /*0x4a688c*/;
L_0x00487150:
    // 00487150  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00487155  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00487157  b81cd74d00             -mov eax, 0x4dd71c
    cpu.eax = 5101340 /*0x4dd71c*/;
    // 0048715c  893d14d74d00           -mov dword ptr [0x4dd714], edi
    app->getMemory<x86::reg32>(x86::reg32(5101332) /* 0x4dd714 */) = cpu.edi;
    // 00487162  893d18d74d00           -mov dword ptr [0x4dd718], edi
    app->getMemory<x86::reg32>(x86::reg32(5101336) /* 0x4dd718 */) = cpu.edi;
    // 00487168  e8af2e0000             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 0048716d  e886f10100             -call 0x4a62f8
    cpu.esp -= 4;
    sub_4a62f8(app, cpu);
    if (cpu.terminate) return;
    // 00487172  893d8cd74d00           -mov dword ptr [0x4dd78c], edi
    app->getMemory<x86::reg32>(x86::reg32(5101452) /* 0x4dd78c */) = cpu.edi;
    // 00487178  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487179  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048717a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048717b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048717c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048717d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048717e:
    // 0048717e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00487183  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00487186  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0048718a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048718c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00487193  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00487195  3dff000000             +cmp eax, 0xff
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
    // 0048719a  77aa                   -ja 0x487146
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00487146;
    }
    // 0048719c  c70588d74d0060684a00   -mov dword ptr [0x4dd788], 0x4a6860
    app->getMemory<x86::reg32>(x86::reg32(5101448) /* 0x4dd788 */) = 4876384 /*0x4a6860*/;
    // 004871a6  eba8                   -jmp 0x487150
    goto L_0x00487150;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4871b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004871b0);
    // 004871b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004871b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004871b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004871b3  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 004871b8  bee8d64d00             -mov esi, 0x4dd6e8
    cpu.esi = 5101288 /*0x4dd6e8*/;
    // 004871bd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004871bf  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004871c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4871c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004871c8);
    // 004871c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004871c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004871ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004871cb  b92d000000             -mov ecx, 0x2d
    cpu.ecx = 45 /*0x2d*/;
    // 004871d0  bfe8d64d00             -mov edi, 0x4dd6e8
    cpu.edi = 5101288 /*0x4dd6e8*/;
    // 004871d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004871d7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004871d9  e876f10100             -call 0x4a6354
    cpu.esp -= 4;
    sub_4a6354(app, cpu);
    if (cpu.terminate) return;
    // 004871de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004871e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4871f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004871f0);
    // 004871f0  a10cd74d00             -mov eax, dword ptr [0x4dd70c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101324) /* 0x4dd70c */);
    // 004871f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4871f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004871f8);
    // 004871f8  a3ecd64d00             -mov dword ptr [0x4dd6ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5101292) /* 0x4dd6ec */) = cpu.eax;
    // 004871fd  8915f0d64d00           -mov dword ptr [0x4dd6f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5101296) /* 0x4dd6f0 */) = cpu.edx;
    // 00487203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487204(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487204);
    // 00487204  a300d74d00             -mov dword ptr [0x4dd700], eax
    app->getMemory<x86::reg32>(x86::reg32(5101312) /* 0x4dd700 */) = cpu.eax;
    // 00487209  e9eaf00100             -jmp 0x4a62f8
    return sub_4a62f8(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_487210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487210);
    // 00487210  a100d74d00             -mov eax, dword ptr [0x4dd700]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5101312) /* 0x4dd700 */);
    // 00487215  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487220);
    // 00487220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487221  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487222  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487223  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00487226  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00487228  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048722c  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00487230  0fb6355cb24d00         -movzx esi, byte ptr [0x4db25c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */));
    // 00487237  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048723a  83c607                 -add esi, 7
    (cpu.esi) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048723d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048723f  6683e6f8               -and si, 0xfff8
    cpu.si &= x86::reg16(x86::sreg16(65528 /*0xfff8*/));
    // 00487243  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00487247:
    // 00487247  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048724b  4a                     -dec edx
    (cpu.edx)--;
    // 0048724c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00487250  83faff                 +cmp edx, -1
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
    // 00487253  0f847f000000           -je 0x4872d8
    if (cpu.flags.zf)
    {
        goto L_0x004872d8;
    }
    // 00487259  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0048725c  3b7c2408               +cmp edi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487260  7d22                   -jge 0x487284
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487284;
    }
L_0x00487262:
    // 00487262  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00487264  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00487266  e865f60100             -call 0x4a68d0
    cpu.esp -= 4;
    sub_4a68d0(app, cpu);
    if (cpu.terminate) return;
    // 0048726b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048726d  83fe10                 +cmp esi, 0x10
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
    // 00487270  7315                   -jae 0x487287
    if (!cpu.flags.cf)
    {
        goto L_0x00487287;
    }
    // 00487272  83fe08                 +cmp esi, 8
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
    // 00487275  7504                   -jne 0x48727b
    if (!cpu.flags.zf)
    {
        goto L_0x0048727b;
    }
    // 00487277  41                     -inc ecx
    (cpu.ecx)++;
    // 00487278  8851ff                 -mov byte ptr [ecx - 1], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
L_0x0048727b:
    // 0048727b  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048727f  47                     -inc edi
    (cpu.edi)++;
    // 00487280  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487282  7cde                   -jl 0x487262
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487262;
    }
L_0x00487284:
    // 00487284  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00487285  ebc0                   -jmp 0x487247
    goto L_0x00487247;
L_0x00487287:
    // 00487287  7713                   -ja 0x48729c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048729c;
    }
    // 00487289  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048728c  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00487290  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487294  47                     -inc edi
    (cpu.edi)++;
    // 00487295  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487297  7cc9                   -jl 0x487262
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487262;
    }
    // 00487299  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048729a  ebab                   -jmp 0x487247
    goto L_0x00487247;
L_0x0048729c:
    // 0048729c  83fe18                 +cmp esi, 0x18
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048729f  72da                   -jb 0x48727b
    if (cpu.flags.cf)
    {
        goto L_0x0048727b;
    }
    // 004872a1  7617                   -jbe 0x4872ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004872ba;
    }
    // 004872a3  83fe20                 +cmp esi, 0x20
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
    // 004872a6  75d3                   -jne 0x48727b
    if (!cpu.flags.zf)
    {
        goto L_0x0048727b;
    }
    // 004872a8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004872ab  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004872ae  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004872b2  47                     -inc edi
    (cpu.edi)++;
    // 004872b3  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004872b5  7cab                   -jl 0x487262
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487262;
    }
    // 004872b7  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004872b8  eb8d                   -jmp 0x487247
    goto L_0x00487247;
L_0x004872ba:
    // 004872ba  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004872bf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004872c1  e8a94d0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 004872c6  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004872c9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004872cd  47                     -inc edi
    (cpu.edi)++;
    // 004872ce  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004872d0  7c90                   -jl 0x487262
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487262;
    }
    // 004872d2  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004872d3  e96fffffff             -jmp 0x487247
    goto L_0x00487247;
L_0x004872d8:
    // 004872d8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004872db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004872de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4872e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004872e4);
    // 004872e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004872e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004872e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004872e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004872e9  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004872ee  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004872f1  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004872f3  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004872f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004872fb  a154b24d00             -mov eax, dword ptr [0x4db254]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 00487300  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487302  8b1d50b24d00           -mov ebx, dword ptr [0x4db250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 00487308  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048730a  a158b24d00             -mov eax, dword ptr [0x4db258]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 0048730f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487311  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00487314  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00487317  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487319  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048731c  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0048731f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00487321  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00487324  83c012                 -add eax, 0x12
    (cpu.eax) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00487327  83f908                 +cmp ecx, 8
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
    // 0048732a  7505                   -jne 0x487331
    if (!cpu.flags.zf)
    {
        goto L_0x00487331;
    }
    // 0048732c  0500030000             -add eax, 0x300
    (cpu.eax) += x86::reg32(x86::sreg32(768 /*0x300*/));
L_0x00487331:
    // 00487331  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487332  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487333  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487334  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487338(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487338);
    // 00487338  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487339  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048733a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048733b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048733c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048733d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048733e  81ec08030000           -sub esp, 0x308
    (cpu.esp) -= x86::reg32(x86::sreg32(776 /*0x308*/));
    // 00487344  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487346  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487348  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048734a  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 0048734f  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 00487355  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00487358  8b2d58b24d00           -mov ebp, dword ptr [0x4db258]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 0048735e  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00487360  8b1d50b24d00           -mov ebx, dword ptr [0x4db250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 00487366  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487368  a154b24d00             -mov eax, dword ptr [0x4db254]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 0048736d  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048736f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00487371  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00487376  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 0048737d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048737f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487381  e8e94c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 00487386  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048738b  83ff08                 +cmp edi, 8
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
    // 0048738e  0f8564010000           -jne 0x4874f8
    if (!cpu.flags.zf)
    {
        goto L_0x004874f8;
    }
    // 00487394  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00487396:
    // 00487396  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00487399  e8d14c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 0048739e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004873a3  83ff08                 +cmp edi, 8
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
    // 004873a6  0f8553010000           -jne 0x4874ff
    if (!cpu.flags.zf)
    {
        goto L_0x004874ff;
    }
    // 004873ac  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004873ae:
    // 004873ae  8d4102                 -lea eax, [ecx + 2]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004873b1  e8b94c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 004873b6  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004873bb  8d4103                 -lea eax, [ecx + 3]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004873be  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004873c0  e8aa4c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 004873c5  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004873ca  83ff08                 +cmp edi, 8
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
    // 004873cd  0f8536010000           -jne 0x487509
    if (!cpu.flags.zf)
    {
        goto L_0x00487509;
    }
    // 004873d3  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x004873d8:
    // 004873d8  8d4105                 -lea eax, [ecx + 5]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 004873db  e88f4c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 004873e0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004873e5  83ff08                 +cmp edi, 8
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
    // 004873e8  0f8522010000           -jne 0x487510
    if (!cpu.flags.zf)
    {
        goto L_0x00487510;
    }
    // 004873ee  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
L_0x004873f3:
    // 004873f3  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 004873f6  e8744c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 004873fb  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00487400  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 00487406  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00487409  e8614c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 0048740e  a148b24d00             -mov eax, dword ptr [0x4db248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091912) /* 0x4db248 */);
    // 00487413  2b0558b24d00           -sub eax, dword ptr [0x4db258]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
    // 00487419  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 0048741c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00487421  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 00487428  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048742a  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00487431  e8394c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 00487436  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048743b  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00487442  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00487445  e8254c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 0048744a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048744f  8d410e                 -lea eax, [ecx + 0xe]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 00487452  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00487454  e8164c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 00487459  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048745e  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00487461  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00487463  e8074c0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 00487468  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048746d  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00487472  8d4111                 -lea eax, [ecx + 0x11]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 00487475  83c612                 -add esi, 0x12
    (cpu.esi) += x86::reg32(x86::sreg32(18 /*0x12*/));
    // 00487478  e8f24b0000             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 0048747d  83ff08                 +cmp edi, 8
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
    // 00487480  7532                   -jne 0x4874b4
    if (!cpu.flags.zf)
    {
        goto L_0x004874b4;
    }
    // 00487482  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00487484  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00487489  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048748b  e8508f0100             -call 0x4a03e0
    cpu.esp -= 4;
    sub_4a03e0(app, cpu);
    if (cpu.terminate) return;
    // 00487490  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00487492:
    // 00487492  46                     -inc esi
    (cpu.esi)++;
    // 00487493  46                     -inc esi
    (cpu.esi)++;
    // 00487494  8a1404                 -mov dl, byte ptr [esp + eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00487497  46                     -inc esi
    (cpu.esi)++;
    // 00487498  8a5c0402               -mov bl, byte ptr [esp + eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 0048749c  8a4c0401               -mov cl, byte ptr [esp + eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004874a0  885efd                 -mov byte ptr [esi - 3], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 004874a3  884efe                 -mov byte ptr [esi - 2], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.cl;
    // 004874a6  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004874a9  8856ff                 -mov byte ptr [esi - 1], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004874ac  3d00030000             +cmp eax, 0x300
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
    // 004874b1  75df                   -jne 0x487492
    if (!cpu.flags.zf)
    {
        goto L_0x00487492;
    }
    // 004874b3  90                     -nop 
    ;
L_0x004874b4:
    // 004874b4  a158b24d00             -mov eax, dword ptr [0x4db258]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004874b9  8b0d50b24d00           -mov ecx, dword ptr [0x4db250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004874bf  8b1d4cb24d00           -mov ebx, dword ptr [0x4db24c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004874c5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004874c7  8b1550b24d00           -mov edx, dword ptr [0x4db250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004874cd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004874cf  a154b24d00             -mov eax, dword ptr [0x4db254]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004874d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004874d5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004874d7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004874d9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004874db  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004874dd  e83efdffff             -call 0x487220
    cpu.esp -= 4;
    sub_487220(app, cpu);
    if (cpu.terminate) return;
    // 004874e2  803d5cb24d0010         +cmp byte ptr [0x4db25c], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004874e9  742c                   -je 0x487517
    if (cpu.flags.zf)
    {
        goto L_0x00487517;
    }
    // 004874eb  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 004874f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004874f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004874f8:
    // 004874f8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004874fa  e997feffff             -jmp 0x487396
    goto L_0x00487396;
L_0x004874ff:
    // 004874ff  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00487504  e9a5feffff             -jmp 0x4873ae
    goto L_0x004873ae;
L_0x00487509:
    // 00487509  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048750b  e9c8feffff             -jmp 0x4873d8
    goto L_0x004873d8;
L_0x00487510:
    // 00487510  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00487512  e9dcfeffff             -jmp 0x4873f3
    goto L_0x004873f3;
L_0x00487517:
    // 00487517  8b9c2404030000         -mov ebx, dword ptr [esp + 0x304]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0048751e  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00487521  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00487523  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487525  e85ef40100             -call 0x4a6988
    cpu.esp -= 4;
    sub_4a6988(app, cpu);
    if (cpu.terminate) return;
    // 0048752a  81c408030000           -add esp, 0x308
    (cpu.esp) += x86::reg32(x86::sreg32(776 /*0x308*/));
    // 00487530  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487531  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487532  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487533  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487534  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487535  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487536  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_487538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487538);
    // 00487538  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487539  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048753a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048753b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048753c  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048753f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487541  e89efdffff             -call 0x4872e4
    cpu.esp -= 4;
    sub_4872e4(app, cpu);
    if (cpu.terminate) return;
    // 00487546  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00487548  e8936e0100             -call 0x49e3e0
    cpu.esp -= 4;
    sub_49e3e0(app, cpu);
    if (cpu.terminate) return;
    // 0048754d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048754f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487551  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487553  750a                   -jne 0x48755f
    if (!cpu.flags.zf)
    {
        goto L_0x0048755f;
    }
    // 00487555  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487557  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048755a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048755e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048755f:
    // 0048755f  e8d4fdffff             -call 0x487338
    cpu.esp -= 4;
    sub_487338(app, cpu);
    if (cpu.terminate) return;
    // 00487564  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487566  e8c5ca0100             -call 0x4a4030
    cpu.esp -= 4;
    sub_4a4030(app, cpu);
    if (cpu.terminate) return;
    // 0048756b  e84cafffff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 00487570  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487572  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00487574  e837000000             -call 0x4875b0
    cpu.esp -= 4;
    sub_4875b0(app, cpu);
    if (cpu.terminate) return;
    // 00487579  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048757b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048757d  e8d2ca0100             -call 0x4a4054
    cpu.esp -= 4;
    sub_4a4054(app, cpu);
    if (cpu.terminate) return;
    // 00487582  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487584  e8bf6e0100             -call 0x49e448
    cpu.esp -= 4;
    sub_49e448(app, cpu);
    if (cpu.terminate) return;
    // 00487589  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048758b  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0048758e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048758f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487590  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487591  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487592  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4875a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004875a0);
    // 004875a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004875a1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004875a6  e811000000             -call 0x4875bc
    cpu.esp -= 4;
    sub_4875bc(app, cpu);
    if (cpu.terminate) return;
    // 004875ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004875ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4875b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004875b0);
    // 004875b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004875b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004875b3  e804000000             -call 0x4875bc
    cpu.esp -= 4;
    sub_4875bc(app, cpu);
    if (cpu.terminate) return;
    // 004875b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004875b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4875bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004875bc);
    // 004875bc  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004875bf  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004875c2  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004875c6  8b15e8ab4d00           -mov edx, dword ptr [0x4dabe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 004875cc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004875ce  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004875d2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004875d4  e823000000             -call 0x4875fc
    cpu.esp -= 4;
    sub_4875fc(app, cpu);
    if (cpu.terminate) return;
    // 004875d9  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004875dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4875e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004875e0);
    // 004875e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004875e1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004875e6  e811000000             -call 0x4875fc
    cpu.esp -= 4;
    sub_4875fc(app, cpu);
    if (cpu.terminate) return;
    // 004875eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004875ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4875f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004875f0);
    // 004875f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004875f1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004875f3  e804000000             -call 0x4875fc
    cpu.esp -= 4;
    sub_4875fc(app, cpu);
    if (cpu.terminate) return;
    // 004875f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004875f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4875fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004875fc);
    // 004875fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004875fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004875fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004875ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487600  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00487603  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487605  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487607  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048760b  e894d7ffff             -call 0x484da4
    cpu.esp -= 4;
    sub_484da4(app, cpu);
    if (cpu.terminate) return;
    // 00487610  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00487612  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487614  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487618  e8b3ceffff             -call 0x4844d0
    cpu.esp -= 4;
    sub_4844d0(app, cpu);
    if (cpu.terminate) return;
    // 0048761d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048761f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487621  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00487623  e89c010000             -call 0x4877c4
    cpu.esp -= 4;
    sub_4877c4(app, cpu);
    if (cpu.terminate) return;
    // 00487628  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048762a  7508                   -jne 0x487634
    if (!cpu.flags.zf)
    {
        goto L_0x00487634;
    }
    // 0048762c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048762f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487630  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487631  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487632  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487633  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487634:
    // 00487634  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487637  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00487639  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048763b  e820030000             -call 0x487960
    cpu.esp -= 4;
    sub_487960(app, cpu);
    if (cpu.terminate) return;
    // 00487640  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487642  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487645  e806030000             -call 0x487950
    cpu.esp -= 4;
    sub_487950(app, cpu);
    if (cpu.terminate) return;
    // 0048764a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048764c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048764f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487650  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487651  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487652  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487660);
    // 00487660  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487662  e9e935fdff             -jmp 0x45ac50
    return sub_45ac50(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_487668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487668);
    // 00487668  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487669  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048766a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048766b  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048766e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00487672  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00487674  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00487676  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00487678  ba05030000             -mov edx, 0x305
    cpu.edx = 773 /*0x305*/;
    // 0048767d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048767f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00487683  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00487687  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487689  7504                   -jne 0x48768f
    if (!cpu.flags.zf)
    {
        goto L_0x0048768f;
    }
    // 0048768b  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0048768f:
    // 0048768f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00487691  7502                   -jne 0x487695
    if (!cpu.flags.zf)
    {
        goto L_0x00487695;
    }
    // 00487693  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x00487695:
    // 00487695  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487699  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048769d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048769f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004876a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004876a7  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 004876ae  e8ad2efdff             -call 0x45a560
    cpu.esp -= 4;
    sub_45a560(app, cpu);
    if (cpu.terminate) return;
    // 004876b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004876b5  0f85b1000000           -jne 0x48776c
    if (!cpu.flags.zf)
    {
        goto L_0x0048776c;
    }
    // 004876bb  833df8b54d0000         +cmp dword ptr [0x4db5f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092856) /* 0x4db5f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004876c2  7409                   -je 0x4876cd
    if (cpu.flags.zf)
    {
        goto L_0x004876cd;
    }
    // 004876c4  803d74b54d0000         +cmp byte ptr [0x4db574], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092724) /* 0x4db574 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004876cb  750d                   -jne 0x4876da
    if (!cpu.flags.zf)
    {
        goto L_0x004876da;
    }
L_0x004876cd:
    // 004876cd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004876d1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004876d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004876d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004876d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004876d7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004876da:
    // 004876da  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004876de  b874b54d00             -mov eax, 0x4db574
    cpu.eax = 5092724 /*0x4db574*/;
    // 004876e3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004876e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004876e7  e8742efdff             -call 0x45a560
    cpu.esp -= 4;
    sub_45a560(app, cpu);
    if (cpu.terminate) return;
    // 004876ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004876ee  74dd                   -je 0x4876cd
    if (cpu.flags.zf)
    {
        goto L_0x004876cd;
    }
    // 004876f0  8b1d00b64d00           -mov ebx, dword ptr [0x4db600]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5092864) /* 0x4db600 */);
    // 004876f6  8b15f4b54d00           -mov edx, dword ptr [0x4db5f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5092852) /* 0x4db5f4 */);
    // 004876fc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004876fe  e86d29fdff             -call 0x45a070
    cpu.esp -= 4;
    sub_45a070(app, cpu);
    if (cpu.terminate) return;
    // 00487703  a300b64d00             -mov dword ptr [0x4db600], eax
    app->getMemory<x86::reg32>(x86::reg32(5092864) /* 0x4db600 */) = cpu.eax;
    // 00487708  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048770a  751e                   -jne 0x48772a
    if (!cpu.flags.zf)
    {
        goto L_0x0048772a;
    }
L_0x0048770c:
    // 0048770c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487710  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487712  75b9                   -jne 0x4876cd
    if (!cpu.flags.zf)
    {
        goto L_0x004876cd;
    }
    // 00487714  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487716  e86524fdff             -call 0x459b80
    cpu.esp -= 4;
    sub_459b80(app, cpu);
    if (cpu.terminate) return;
    // 0048771b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0048771d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487721  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487724  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487725  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487726  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487727  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048772a:
    // 0048772a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048772e  a1f4b54d00             -mov eax, dword ptr [0x4db5f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092852) /* 0x4db5f4 */);
    // 00487733  ff15f8b54d00           -call dword ptr [0x4db5f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092856) /* 0x4db5f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487739  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0048773c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048773e  74cc                   -je 0x48770c
    if (cpu.flags.zf)
    {
        goto L_0x0048770c;
    }
    // 00487740  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487742  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487744  e81726fdff             -call 0x459d60
    cpu.esp -= 4;
    sub_459d60(app, cpu);
    if (cpu.terminate) return;
    // 00487749  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048774b  74bf                   -je 0x48770c
    if (cpu.flags.zf)
    {
        goto L_0x0048770c;
    }
    // 0048774d  a1fcb54d00             -mov eax, dword ptr [0x4db5fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092860) /* 0x4db5fc */);
    // 00487752  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00487757  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00487759  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0048775d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048775f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487763  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487766  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487767  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487768  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487769  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048776c:
    // 0048776c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00487771  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487773  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00487775  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00487777  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487779  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0048777d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048777f  e89c2cfdff             -call 0x45a420
    cpu.esp -= 4;
    sub_45a420(app, cpu);
    if (cpu.terminate) return;
    // 00487784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487786  0f8541ffffff           -jne 0x4876cd
    if (!cpu.flags.zf)
    {
        goto L_0x004876cd;
    }
    // 0048778c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048778e  e8ed23fdff             -call 0x459b80
    cpu.esp -= 4;
    sub_459b80(app, cpu);
    if (cpu.terminate) return;
    // 00487793  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00487799  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048779b  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004877a1  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004877a5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004877a9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004877ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004877af  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4877b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004877b4);
    // 004877b4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004877b6  e8adfeffff             -call 0x487668
    cpu.esp -= 4;
    sub_487668(app, cpu);
    if (cpu.terminate) return;
    // 004877bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4877bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004877bc);
    // 004877bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004877be  e8a5feffff             -call 0x487668
    cpu.esp -= 4;
    sub_487668(app, cpu);
    if (cpu.terminate) return;
    // 004877c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4877c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004877c4);
    // 004877c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004877c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004877c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004877c7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004877ca  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004877cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004877ce  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004877d0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004877d2  7504                   -jne 0x4877d8
    if (!cpu.flags.zf)
    {
        goto L_0x004877d8;
    }
    // 004877d4  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004877d8:
    // 004877d8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004877da  7502                   -jne 0x4877de
    if (!cpu.flags.zf)
    {
        goto L_0x004877de;
    }
    // 004877dc  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004877de:
    // 004877de  ba32030000             -mov edx, 0x332
    cpu.edx = 818 /*0x332*/;
    // 004877e3  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004877e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004877e7  e8742dfdff             -call 0x45a560
    cpu.esp -= 4;
    sub_45a560(app, cpu);
    if (cpu.terminate) return;
    // 004877ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004877ee  751a                   -jne 0x48780a
    if (!cpu.flags.zf)
    {
        goto L_0x0048780a;
    }
    // 004877f0  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004877f2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004877f6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004877f8:
    // 004877f8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004877fc  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00487803  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00487806  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487807  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487808  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487809  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048780a:
    // 0048780a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048780f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00487811  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00487813  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00487815  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487817  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048781b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048781d  e8fe2bfdff             -call 0x45a420
    cpu.esp -= 4;
    sub_45a420(app, cpu);
    if (cpu.terminate) return;
    // 00487822  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487824  75d2                   -jne 0x4877f8
    if (!cpu.flags.zf)
    {
        goto L_0x004877f8;
    }
    // 00487826  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00487828  e85323fdff             -call 0x459b80
    cpu.esp -= 4;
    sub_459b80(app, cpu);
    if (cpu.terminate) return;
    // 0048782d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048782f  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00487835  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00487839  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0048783f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487843  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0048784a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048784d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048784e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048784f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487850  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487854(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487854);
    // 00487854  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487855  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487856  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487857  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048785a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048785e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00487860  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00487862  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00487864  ba05080000             -mov edx, 0x805
    cpu.edx = 2053 /*0x805*/;
    // 00487869  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048786b  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048786f  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00487873  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487875  7504                   -jne 0x48787b
    if (!cpu.flags.zf)
    {
        goto L_0x0048787b;
    }
    // 00487877  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x0048787b:
    // 0048787b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048787d  7502                   -jne 0x487881
    if (!cpu.flags.zf)
    {
        goto L_0x00487881;
    }
    // 0048787f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
L_0x00487881:
    // 00487881  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487885  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487889  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048788b  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 00487891  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487893  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0048789a  e8c12cfdff             -call 0x45a560
    cpu.esp -= 4;
    sub_45a560(app, cpu);
    if (cpu.terminate) return;
    // 0048789f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004878a1  751f                   -jne 0x4878c2
    if (!cpu.flags.zf)
    {
        goto L_0x004878c2;
    }
    // 004878a3  833df8b54d0000         +cmp dword ptr [0x4db5f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092856) /* 0x4db5f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004878aa  7409                   -je 0x4878b5
    if (cpu.flags.zf)
    {
        goto L_0x004878b5;
    }
    // 004878ac  803d74b54d0000         +cmp byte ptr [0x4db574], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092724) /* 0x4db574 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004878b3  7542                   -jne 0x4878f7
    if (!cpu.flags.zf)
    {
        goto L_0x004878f7;
    }
L_0x004878b5:
    // 004878b5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004878b9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004878bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004878bf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004878c2:
    // 004878c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004878c4  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004878c6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004878c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004878ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004878cc  e84f2bfdff             -call 0x45a420
    cpu.esp -= 4;
    sub_45a420(app, cpu);
    if (cpu.terminate) return;
    // 004878d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004878d3  740d                   -je 0x4878e2
    if (cpu.flags.zf)
    {
        goto L_0x004878e2;
    }
    // 004878d5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004878d7  e8e421fdff             -call 0x459ac0
    cpu.esp -= 4;
    sub_459ac0(app, cpu);
    if (cpu.terminate) return;
    // 004878dc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004878e0  ebd3                   -jmp 0x4878b5
    goto L_0x004878b5;
L_0x004878e2:
    // 004878e2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004878e4  e89722fdff             -call 0x459b80
    cpu.esp -= 4;
    sub_459b80(app, cpu);
    if (cpu.terminate) return;
    // 004878e9  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004878ef  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
    // 004878f5  ebbe                   -jmp 0x4878b5
    goto L_0x004878b5;
L_0x004878f7:
    // 004878f7  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004878fb  b874b54d00             -mov eax, 0x4db574
    cpu.eax = 5092724 /*0x4db574*/;
    // 00487900  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00487902  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487904  e8572cfdff             -call 0x45a560
    cpu.esp -= 4;
    sub_45a560(app, cpu);
    if (cpu.terminate) return;
    // 00487909  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048790b  74a8                   -je 0x4878b5
    if (cpu.flags.zf)
    {
        goto L_0x004878b5;
    }
    // 0048790d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048790f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487913  e8a821fdff             -call 0x459ac0
    cpu.esp -= 4;
    sub_459ac0(app, cpu);
    if (cpu.terminate) return;
    // 00487918  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048791a  ff15f8b54d00           -call dword ptr [0x4db5f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092856) /* 0x4db5f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00487920  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00487923  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00487925  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00487929  a1fcb54d00             -mov eax, dword ptr [0x4db5fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5092860) /* 0x4db5fc */);
    // 0048792e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00487930  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00487932  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487936  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487939  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048793a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048793b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048793c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_487940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487940);
    // 00487940  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00487942  e80dffffff             -call 0x487854
    cpu.esp -= 4;
    sub_487854(app, cpu);
    if (cpu.terminate) return;
    // 00487947  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487948(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487948);
    // 00487948  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048794a  e805ffffff             -call 0x487854
    cpu.esp -= 4;
    sub_487854(app, cpu);
    if (cpu.terminate) return;
    // 0048794f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_487950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487950);
    // 00487950  e92b22fdff             -jmp 0x459b80
    return sub_459b80(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487958);
    // 00487958  e91327fdff             -jmp 0x45a070
    return sub_45a070(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487960);
    // 00487960  e9db24fdff             -jmp 0x459e40
    return sub_459e40(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487968(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487968);
    // 00487968  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487969  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048796b  e8f023fdff             -call 0x459d60
    cpu.esp -= 4;
    sub_459d60(app, cpu);
    if (cpu.terminate) return;
    // 00487970  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487972  7502                   -jne 0x487976
    if (!cpu.flags.zf)
    {
        goto L_0x00487976;
    }
    // 00487974  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487975  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487976:
    // 00487976  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487978  e83323fdff             -call 0x459cb0
    cpu.esp -= 4;
    sub_459cb0(app, cpu);
    if (cpu.terminate) return;
    // 0048797d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048797e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48797f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048797f);
    // 0048797f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487980  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487981  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00487984  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487986  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487988  e825f30100             -call 0x4a6cb2
    cpu.esp -= 4;
    sub_4a6cb2(app, cpu);
    if (cpu.terminate) return;
    // 0048798d  3df4010000             +cmp eax, 0x1f4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487992  7c03                   -jl 0x487997
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487997;
    }
    // 00487994  ff0424                 -inc dword ptr [esp]
    (app->getMemory<x86::reg32>(cpu.esp))++;
L_0x00487997:
    // 00487997  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487999  e87bf30100             -call 0x4a6d19
    cpu.esp -= 4;
    sub_4a6d19(app, cpu);
    if (cpu.terminate) return;
    // 0048799e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004879a0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004879a2  7402                   -je 0x4879a6
    if (cpu.flags.zf)
    {
        goto L_0x004879a6;
    }
    // 004879a4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004879a6:
    // 004879a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004879a8  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004879ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4879ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004879ae);
    // 004879ae  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004879af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004879b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004879b1  2eff1574644c00         -call dword ptr cs:[0x4c6474]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006452) /* 0x4c6474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004879b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004879ba  7508                   -jne 0x4879c4
    if (!cpu.flags.zf)
    {
        goto L_0x004879c4;
    }
    // 004879bc  e8f1eb0100             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004879c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004879c4:
    // 004879c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004879c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004879c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4879d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004879d0);
    // 004879d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004879d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004879d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004879d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004879d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004879d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004879d6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004879d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004879db  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004879dd  89151cb64d00           -mov dword ptr [0x4db61c], edx
    app->getMemory<x86::reg32>(x86::reg32(5092892) /* 0x4db61c */) = cpu.edx;
    // 004879e3  891518b64d00           -mov dword ptr [0x4db618], edx
    app->getMemory<x86::reg32>(x86::reg32(5092888) /* 0x4db618 */) = cpu.edx;
    // 004879e9  891514b64d00           -mov dword ptr [0x4db614], edx
    app->getMemory<x86::reg32>(x86::reg32(5092884) /* 0x4db614 */) = cpu.edx;
    // 004879ef  8915c0ab4d00           -mov dword ptr [0x4dabc0], edx
    app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */) = cpu.edx;
    // 004879f5  8915bcab4d00           -mov dword ptr [0x4dabbc], edx
    app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */) = cpu.edx;
    // 004879fb  8915b8ab4d00           -mov dword ptr [0x4dabb8], edx
    app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */) = cpu.edx;
    // 00487a01  8915b4ab4d00           -mov dword ptr [0x4dabb4], edx
    app->getMemory<x86::reg32>(x86::reg32(5090228) /* 0x4dabb4 */) = cpu.edx;
    // 00487a07  8915b0ab4d00           -mov dword ptr [0x4dabb0], edx
    app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */) = cpu.edx;
    // 00487a0d  8915acab4d00           -mov dword ptr [0x4dabac], edx
    app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */) = cpu.edx;
    // 00487a13  8915a8ab4d00           -mov dword ptr [0x4daba8], edx
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = cpu.edx;
    // 00487a19  8915a4ab4d00           -mov dword ptr [0x4daba4], edx
    app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */) = cpu.edx;
    // 00487a1f  882504b64d00           -mov byte ptr [0x4db604], ah
    app->getMemory<x86::reg8>(x86::reg32(5092868) /* 0x4db604 */) = cpu.ah;
    // 00487a25  e87ef40100             -call 0x4a6ea8
    cpu.esp -= 4;
    sub_4a6ea8(app, cpu);
    if (cpu.terminate) return;
    // 00487a2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487a2c  0f8461010000           -je 0x487b93
    if (cpu.flags.zf)
    {
        goto L_0x00487b93;
    }
    // 00487a32  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487a34  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00487a39  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487a3d  bf04b64d00             -mov edi, 0x4db604
    cpu.edi = 5092868 /*0x4db604*/;
    // 00487a42  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00487a46  e87af40100             -call 0x4a6ec5
    cpu.esp -= 4;
    sub_4a6ec5(app, cpu);
    if (cpu.terminate) return;
    // 00487a4b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00487a4d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00487a50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487a51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00487a53  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00487a56  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00487a58  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00487a5a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00487a5d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00487a5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a60  881d10b64d00           -mov byte ptr [0x4db610], bl
    app->getMemory<x86::reg8>(x86::reg32(5092880) /* 0x4db610 */) = cpu.bl;
    // 00487a66  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00487a68  7f0a                   -jg 0x487a74
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00487a74;
    }
    // 00487a6a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487a6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a72  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487a73  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487a74:
    // 00487a74  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00487a79  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487a7b  e845f40100             -call 0x4a6ec5
    cpu.esp -= 4;
    sub_4a6ec5(app, cpu);
    if (cpu.terminate) return;
    // 00487a80  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487a83  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00487a88  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00487a8b  a314b64d00             -mov dword ptr [0x4db614], eax
    app->getMemory<x86::reg32>(x86::reg32(5092884) /* 0x4db614 */) = cpu.eax;
    // 00487a90  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487a93  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 00487a98  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00487a9b  a318b64d00             -mov dword ptr [0x4db618], eax
    app->getMemory<x86::reg32>(x86::reg32(5092888) /* 0x4db618 */) = cpu.eax;
    // 00487aa0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00487aa3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00487aa6  8b2d14b64d00           -mov ebp, dword ptr [0x4db614]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5092884) /* 0x4db614 */);
    // 00487aac  a31cb64d00             -mov dword ptr [0x4db61c], eax
    app->getMemory<x86::reg32>(x86::reg32(5092892) /* 0x4db61c */) = cpu.eax;
    // 00487ab1  83fd05                 +cmp ebp, 5
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ab4  7c0a                   -jl 0x487ac0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ac0;
    }
    // 00487ab6  c705a4ab4d0001000000   -mov dword ptr [0x4daba4], 1
    app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */) = 1 /*0x1*/;
L_0x00487ac0:
    // 00487ac0  833d14b64d0006         +cmp dword ptr [0x4db614], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092884) /* 0x4db614 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ac7  7c0a                   -jl 0x487ad3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487ad3;
    }
    // 00487ac9  c705a8ab4d0001000000   -mov dword ptr [0x4daba8], 1
    app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */) = 1 /*0x1*/;
L_0x00487ad3:
    // 00487ad3  bac4fb4c00             -mov edx, 0x4cfbc4
    cpu.edx = 5045188 /*0x4cfbc4*/;
    // 00487ad8  b804b64d00             -mov eax, 0x4db604
    cpu.eax = 5092868 /*0x4db604*/;
    // 00487add  e83ebcffff             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 00487ae2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487ae4  7553                   -jne 0x487b39
    if (!cpu.flags.zf)
    {
        goto L_0x00487b39;
    }
    // 00487ae6  c705b8ab4d0001000000   -mov dword ptr [0x4dabb8], 1
    app->getMemory<x86::reg32>(x86::reg32(5090232) /* 0x4dabb8 */) = 1 /*0x1*/;
L_0x00487af0:
    // 00487af0  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 00487af5  0f847f000000           -je 0x487b7a
    if (cpu.flags.zf)
    {
        goto L_0x00487b7a;
    }
    // 00487afb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487b00:
    // 00487b00  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487b04  a3acab4d00             -mov dword ptr [0x4dabac], eax
    app->getMemory<x86::reg32>(x86::reg32(5090220) /* 0x4dabac */) = cpu.eax;
    // 00487b09  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00487b0c  0f846c000000           -je 0x487b7e
    if (cpu.flags.zf)
    {
        goto L_0x00487b7e;
    }
    // 00487b12  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00487b17:
    // 00487b17  8a6c2409               -mov ch, byte ptr [esp + 9]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */);
    // 00487b1b  a3b0ab4d00             -mov dword ptr [0x4dabb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */) = cpu.eax;
    // 00487b20  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 00487b23  745d                   -je 0x487b82
    if (cpu.flags.zf)
    {
        goto L_0x00487b82;
    }
    // 00487b25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487b2a  a3b4ab4d00             -mov dword ptr [0x4dabb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5090228) /* 0x4dabb4 */) = cpu.eax;
    // 00487b2f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487b32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487b39:
    // 00487b39  bad4fb4c00             -mov edx, 0x4cfbd4
    cpu.edx = 5045204 /*0x4cfbd4*/;
    // 00487b3e  b804b64d00             -mov eax, 0x4db604
    cpu.eax = 5092868 /*0x4db604*/;
    // 00487b43  e8d8bbffff             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 00487b48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487b4a  750c                   -jne 0x487b58
    if (!cpu.flags.zf)
    {
        goto L_0x00487b58;
    }
    // 00487b4c  c705c0ab4d0001000000   -mov dword ptr [0x4dabc0], 1
    app->getMemory<x86::reg32>(x86::reg32(5090240) /* 0x4dabc0 */) = 1 /*0x1*/;
    // 00487b56  eb98                   -jmp 0x487af0
    goto L_0x00487af0;
L_0x00487b58:
    // 00487b58  bae4fb4c00             -mov edx, 0x4cfbe4
    cpu.edx = 5045220 /*0x4cfbe4*/;
    // 00487b5d  b804b64d00             -mov eax, 0x4db604
    cpu.eax = 5092868 /*0x4db604*/;
    // 00487b62  e8b9bbffff             -call 0x483720
    cpu.esp -= 4;
    sub_483720(app, cpu);
    if (cpu.terminate) return;
    // 00487b67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487b69  7585                   -jne 0x487af0
    if (!cpu.flags.zf)
    {
        goto L_0x00487af0;
    }
    // 00487b6b  c705bcab4d0001000000   -mov dword ptr [0x4dabbc], 1
    app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */) = 1 /*0x1*/;
    // 00487b75  e976ffffff             -jmp 0x487af0
    goto L_0x00487af0;
L_0x00487b7a:
    // 00487b7a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487b7c  eb82                   -jmp 0x487b00
    goto L_0x00487b00;
L_0x00487b7e:
    // 00487b7e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487b80  eb95                   -jmp 0x487b17
    goto L_0x00487b17;
L_0x00487b82:
    // 00487b82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00487b84  a3b4ab4d00             -mov dword ptr [0x4dabb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5090228) /* 0x4dabb4 */) = cpu.eax;
    // 00487b89  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487b8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487b92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487b93:
    // 00487b93  e849f30100             -call 0x4a6ee1
    cpu.esp -= 4;
    sub_4a6ee1(app, cpu);
    if (cpu.terminate) return;
    // 00487b98  a3bcab4d00             -mov dword ptr [0x4dabbc], eax
    app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */) = cpu.eax;
    // 00487b9d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00487ba0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ba1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ba2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ba3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ba4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ba5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487bb0);
    // 00487bb0  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487bb3  29d0                   +sub eax, edx
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
    // 00487bb5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00487bb9  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00487bbd  d84c2414               +fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 00487bc1  d9542408               +fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 00487bc5  dd1c24                 +fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487bc8  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00487bca  dc1c24                 +fcomp qword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.esp)));
    cpu.fpu.pop();
    // 00487bcd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00487bcf  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00487bd0  770a                   -ja 0x487bdc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00487bdc;
    }
    // 00487bd2  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00487bd6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487bd9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00487bdc:
    // 00487bdc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00487bdf  dc0df4fb4c00           -fmul qword ptr [0x4cfbf4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045236) /* 0x4cfbf4 */));
    // 00487be5  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487be9  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00487bed  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487bf0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_487bf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487bf4);
    // 00487bf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487bf5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487bf6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487bf7  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00487bfa  833db0ab4d0000         +cmp dword ptr [0x4dabb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487c01  0f8492010000           -je 0x487d99
    if (cpu.flags.zf)
    {
        goto L_0x00487d99;
    }
L_0x00487c07:
    // 00487c07  833da4ab4d0000         +cmp dword ptr [0x4daba4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487c0e  0f848f010000           -je 0x487da3
    if (cpu.flags.zf)
    {
        goto L_0x00487da3;
    }
    // 00487c14  833d24b64d0000         +cmp dword ptr [0x4db624], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092900) /* 0x4db624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487c1b  0f8582010000           -jne 0x487da3
    if (!cpu.flags.zf)
    {
        goto L_0x00487da3;
    }
    // 00487c21  e88a010000             -call 0x487db0
    cpu.esp -= 4;
    sub_487db0(app, cpu);
    if (cpu.terminate) return;
L_0x00487c26:
    // 00487c26  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487c28  b940420f00             -mov ecx, 0xf4240
    cpu.ecx = 1000000 /*0xf4240*/;
    // 00487c2d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00487c2f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487c32  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487c34  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00487c38  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00487c3c  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00487c3e  dc05fcfb4c00           +fadd qword ptr [0x4cfbfc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5045244) /* 0x4cfbfc */));
    // 00487c44  dc0d04fc4c00           +fmul qword ptr [0x4cfc04]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045252) /* 0x4cfc04 */));
    // 00487c4a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487c4c  e8dfe8ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487c51  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487c55  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487c59  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00487c5d  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00487c61  dc0d0cfc4c00           +fmul qword ptr [0x4cfc0c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045260) /* 0x4cfc0c */));
    // 00487c67  dd0514fc4c00           +fld qword ptr [0x4cfc14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5045268) /* 0x4cfc14 */)));
    // 00487c6d  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00487c6f  d8c1                   +fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00487c71  e8bae8ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487c76  db5c2410               +fistp dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487c7a  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 00487c7c  dc051cfc4c00           +fadd qword ptr [0x4cfc1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5045276) /* 0x4cfc1c */));
    // 00487c82  dc0d24fc4c00           +fmul qword ptr [0x4cfc24]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045284) /* 0x4cfc24 */));
    // 00487c88  e8a3e8ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487c8d  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487c91  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487c95  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00487c99  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00487c9d  dc0d2cfc4c00           +fmul qword ptr [0x4cfc2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045292) /* 0x4cfc2c */));
    // 00487ca3  dc0534fc4c00           +fadd qword ptr [0x4cfc34]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5045300) /* 0x4cfc34 */));
    // 00487ca9  e882e8ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487cae  db5c2408               +fistp dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487cb2  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00487cb4  dc053cfc4c00           +fadd qword ptr [0x4cfc3c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5045308) /* 0x4cfc3c */));
    // 00487cba  dc0d44fc4c00           +fmul qword ptr [0x4cfc44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045316) /* 0x4cfc44 */));
    // 00487cc0  e86be8ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487cc5  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487cc9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487ccd  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00487cd1  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 00487cd5  dc0d4cfc4c00           +fmul qword ptr [0x4cfc4c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045324) /* 0x4cfc4c */));
    // 00487cdb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487cdd  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00487cdf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487ce3  e848e8ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487ce8  db5c240c               +fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487cec  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00487cf1  e8bafeffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487cf6  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487cfa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00487cfe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487d00  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 00487d05  e8a6feffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487d0a  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487d0e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487d12  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487d14  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 00487d19  e892feffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487d1e  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487d22  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 00487d27  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00487d2b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487d2d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487d31  e87afeffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487d36  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487d3a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487d3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487d3e  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00487d43  e868feffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487d48  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    cpu.fpu.pop();
    // 00487d4c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00487d4e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00487d4f  7604                   -jbe 0x487d55
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487d55;
    }
    // 00487d51  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x00487d55:
    // 00487d55  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487d59  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487d5b  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 00487d60  e84bfeffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487d65  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487d69  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00487d6b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487d6d  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 00487d72  e839feffff             -call 0x487bb0
    cpu.esp -= 4;
    sub_487bb0(app, cpu);
    if (cpu.terminate) return;
    // 00487d77  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    cpu.fpu.pop();
    // 00487d7b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00487d7d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00487d7e  7604                   -jbe 0x487d84
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487d84;
    }
    // 00487d80  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00487d84:
    // 00487d84  69db40420f00           -imul ebx, ebx, 0xf4240
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1000000 /*0xf4240*/)));
    // 00487d8a  891d20b64d00           -mov dword ptr [0x4db620], ebx
    app->getMemory<x86::reg32>(x86::reg32(5092896) /* 0x4db620 */) = cpu.ebx;
    // 00487d90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00487d92  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00487d95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487d98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487d99:
    // 00487d99  e832fcffff             -call 0x4879d0
    cpu.esp -= 4;
    sub_4879d0(app, cpu);
    if (cpu.terminate) return;
    // 00487d9e  e964feffff             -jmp 0x487c07
    goto L_0x00487c07;
L_0x00487da3:
    // 00487da3  e888000000             -call 0x487e30
    cpu.esp -= 4;
    sub_487e30(app, cpu);
    if (cpu.terminate) return;
    // 00487da8  e979feffff             -jmp 0x487c26
    goto L_0x00487c26;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_487db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487db0);
    // 00487db0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487db1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487db2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487db3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487db4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487db5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487db6  bd05000000             -mov ebp, 5
    cpu.ebp = 5 /*0x5*/;
    // 00487dbb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00487dbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487dbf  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00487dc1:
    // 00487dc1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487dc6  e845b6ffff             -call 0x483410
    cpu.esp -= 4;
    sub_483410(app, cpu);
    if (cpu.terminate) return;
    // 00487dcb  833db0ab4d0000         +cmp dword ptr [0x4dabb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487dd2  7402                   -je 0x487dd6
    if (cpu.flags.zf)
    {
        goto L_0x00487dd6;
    }
    // 00487dd4  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x00487dd6:
    // 00487dd6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00487dd8  a1ccab4d00             -mov eax, dword ptr [0x4dabcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00487ddd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00487ddf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00487de2  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487de4  e827b6ffff             -call 0x483410
    cpu.esp -= 4;
    sub_483410(app, cpu);
    if (cpu.terminate) return;
    // 00487de9  833db0ab4d0000         +cmp dword ptr [0x4dabb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090224) /* 0x4dabb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487df0  7402                   -je 0x487df4
    if (cpu.flags.zf)
    {
        goto L_0x00487df4;
    }
    // 00487df2  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x00487df4:
    // 00487df4  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00487df6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487df8  7408                   -je 0x487e02
    if (cpu.flags.zf)
    {
        goto L_0x00487e02;
    }
    // 00487dfa  39d8                   +cmp eax, ebx
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
    // 00487dfc  7d20                   -jge 0x487e1e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487e1e;
    }
L_0x00487dfe:
    // 00487dfe  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00487e00  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00487e02:
    // 00487e02  46                     -inc esi
    (cpu.esi)++;
    // 00487e03  83fe05                 +cmp esi, 5
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
    // 00487e06  7cb9                   -jl 0x487dc1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487dc1;
    }
    // 00487e08  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487e0a  7502                   -jne 0x487e0e
    if (!cpu.flags.zf)
    {
        goto L_0x00487e0e;
    }
    // 00487e0c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00487e0e:
    // 00487e0e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00487e15  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00487e17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487e1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487e1e:
    // 00487e1e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487e20  74dc                   -je 0x487dfe
    if (cpu.flags.zf)
    {
        goto L_0x00487dfe;
    }
    // 00487e22  39c8                   +cmp eax, ecx
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
    // 00487e24  7d04                   -jge 0x487e2a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487e2a;
    }
L_0x00487e26:
    // 00487e26  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00487e28  ebd8                   -jmp 0x487e02
    goto L_0x00487e02;
L_0x00487e2a:
    // 00487e2a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00487e2c  74f8                   -je 0x487e26
    if (cpu.flags.zf)
    {
        goto L_0x00487e26;
    }
    // 00487e2e  ebd2                   -jmp 0x487e02
    goto L_0x00487e02;
}

/* align: skip  */
void Application::sub_487e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487e30);
    // 00487e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00487e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487e32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00487e33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487e34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487e35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487e36  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487e39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487e3b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00487e3d  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00487e41  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00487e45:
    // 00487e45  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00487e4a  e8c1b5ffff             -call 0x483410
    cpu.esp -= 4;
    sub_483410(app, cpu);
    if (cpu.terminate) return;
    // 00487e4f  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00487e54  8b3dccab4d00           -mov edi, dword ptr [0x4dabcc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090252) /* 0x4dabcc */);
    // 00487e5a  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00487e5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487e5f  8b35f4375600           -mov esi, dword ptr [0x5637f4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
L_0x00487e65:
    // 00487e65  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00487e67  b8aaaa5555             -mov eax, 0x5555aaaa
    cpu.eax = 1431677610 /*0x5555aaaa*/;
    // 00487e6c  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 00487e71  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00487e73  a1f4375600             -mov eax, dword ptr [0x5637f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00487e78  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00487e7a  41                     -inc ecx
    (cpu.ecx)++;
    // 00487e7b  39f8                   +cmp eax, edi
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
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 00487e7d  7ce6                   -jl 0x487e65
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487e65;
    }
    // 00487e7f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487e83  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00487e85  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487e87  7414                   -je 0x487e9d
    if (cpu.flags.zf)
    {
        goto L_0x00487e9d;
    }
    // 00487e89  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487e8d  39f1                   +cmp ecx, esi
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
    // 00487e8f  0f8d7c000000           -jge 0x487f11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487f11;
    }
L_0x00487e95:
    // 00487e95  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00487e99  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x00487e9d:
    // 00487e9d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00487ea1  42                     -inc edx
    (cpu.edx)++;
    // 00487ea2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00487ea6  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ea9  7c9a                   -jl 0x487e45
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00487e45;
    }
    // 00487eab  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00487ead  7504                   -jne 0x487eb3
    if (!cpu.flags.zf)
    {
        goto L_0x00487eb3;
    }
    // 00487eaf  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00487eb3:
    // 00487eb3  8b1da8ab4d00           -mov ebx, dword ptr [0x4daba8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090216) /* 0x4daba8 */);
    // 00487eb9  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00487ebc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00487ebe  7566                   -jne 0x487f26
    if (!cpu.flags.zf)
    {
        goto L_0x00487f26;
    }
    // 00487ec0  833da4ab4d0000         +cmp dword ptr [0x4daba4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090212) /* 0x4daba4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ec7  0f856f000000           -jne 0x487f3c
    if (!cpu.flags.zf)
    {
        goto L_0x00487f3c;
    }
    // 00487ecd  833dbcab4d0000         +cmp dword ptr [0x4dabbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090236) /* 0x4dabbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00487ed4  0f8478000000           -je 0x487f52
    if (cpu.flags.zf)
    {
        goto L_0x00487f52;
    }
    // 00487eda  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00487ede  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00487ee2  dc0da4fc4c00           -fmul qword ptr [0x4cfca4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045412) /* 0x4cfca4 */));
    // 00487ee8  dc0dacfc4c00           -fmul qword ptr [0x4cfcac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045420) /* 0x4cfcac */));
L_0x00487eee:
    // 00487eee  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00487ef1  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 00487ef4  d80dd4fc4c00           -fmul dword ptr [0x4cfcd4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5045460) /* 0x4cfcd4 */));
    // 00487efa  e831e6ffff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 00487eff  db5c240c               -fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00487f03  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00487f07  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00487f0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487f11:
    // 00487f11  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00487f13  7480                   -je 0x487e95
    if (cpu.flags.zf)
    {
        goto L_0x00487e95;
    }
    // 00487f15  39e9                   +cmp ecx, ebp
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
    // 00487f17  7d04                   -jge 0x487f1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00487f1d;
    }
L_0x00487f19:
    // 00487f19  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00487f1b  eb80                   -jmp 0x487e9d
    goto L_0x00487e9d;
L_0x00487f1d:
    // 00487f1d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00487f1f  74f8                   -je 0x487f19
    if (cpu.flags.zf)
    {
        goto L_0x00487f19;
    }
    // 00487f21  e977ffffff             -jmp 0x487e9d
    goto L_0x00487e9d;
L_0x00487f26:
    // 00487f26  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00487f2a  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00487f2e  dc0dc4fc4c00           +fmul qword ptr [0x4cfcc4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045444) /* 0x4cfcc4 */));
    // 00487f34  dc0dccfc4c00           +fmul qword ptr [0x4cfccc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045452) /* 0x4cfccc */));
    // 00487f3a  ebb2                   -jmp 0x487eee
    goto L_0x00487eee;
L_0x00487f3c:
    // 00487f3c  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00487f40  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00487f44  dc0db4fc4c00           +fmul qword ptr [0x4cfcb4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045428) /* 0x4cfcb4 */));
    // 00487f4a  dc0dbcfc4c00           +fmul qword ptr [0x4cfcbc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045436) /* 0x4cfcbc */));
    // 00487f50  eb9c                   -jmp 0x487eee
    goto L_0x00487eee;
L_0x00487f52:
    // 00487f52  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00487f56  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 00487f5a  dc0d94fc4c00           +fmul qword ptr [0x4cfc94]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045396) /* 0x4cfc94 */));
    // 00487f60  dc0d9cfc4c00           +fmul qword ptr [0x4cfc9c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5045404) /* 0x4cfc9c */));
    // 00487f66  eb86                   -jmp 0x487eee
    goto L_0x00487eee;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_487f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00487f70);
    // 00487f70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00487f71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00487f72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487f73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00487f74  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00487f7a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00487f7c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00487f7e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00487f80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00487f81:
    // 00487f81  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00487f83  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00487f85  3c00                   +cmp al, 0
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
    // 00487f87  7410                   -je 0x487f99
    if (cpu.flags.zf)
    {
        goto L_0x00487f99;
    }
    // 00487f89  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00487f8c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00487f8f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00487f92  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00487f95  3c00                   +cmp al, 0
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
    // 00487f97  75e8                   -jne 0x487f81
    if (!cpu.flags.zf)
    {
        goto L_0x00487f81;
    }
L_0x00487f99:
    // 00487f99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487f9a  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00487f9c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00487f9e  49                     -dec ecx
    (cpu.ecx)--;
    // 00487f9f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00487fa1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00487fa3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00487fa5  49                     -dec ecx
    (cpu.ecx)--;
    // 00487fa6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487fa8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00487faa  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00487fac  48                     -dec eax
    (cpu.eax)--;
    // 00487fad  39d0                   +cmp eax, edx
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
    // 00487faf  7607                   -jbe 0x487fb8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00487fb8;
    }
L_0x00487fb1:
    // 00487fb1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00487fb3  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487fb6  7545                   -jne 0x487ffd
    if (!cpu.flags.zf)
    {
        goto L_0x00487ffd;
    }
L_0x00487fb8:
    // 00487fb8  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00487fbb  742a                   -je 0x487fe7
    if (cpu.flags.zf)
    {
        goto L_0x00487fe7;
    }
    // 00487fbd  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00487fbf  8b3528b64d00           -mov esi, dword ptr [0x4db628]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5092904) /* 0x4db628 */);
    // 00487fc5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00487fc6  2bc9                   +sub ecx, ecx
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
    // 00487fc8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00487fc9  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00487fcb  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00487fcd  4f                     -dec edi
    (cpu.edi)--;
L_0x00487fce:
    // 00487fce  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00487fd0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00487fd2  3c00                   +cmp al, 0
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
    // 00487fd4  7410                   -je 0x487fe6
    if (cpu.flags.zf)
    {
        goto L_0x00487fe6;
    }
    // 00487fd6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00487fd9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00487fdc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00487fdf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00487fe2  3c00                   +cmp al, 0
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
    // 00487fe4  75e8                   -jne 0x487fce
    if (!cpu.flags.zf)
    {
        goto L_0x00487fce;
    }
L_0x00487fe6:
    // 00487fe6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00487fe7:
    // 00487fe7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00487fe9  e836c60100             -call 0x4a4624
    cpu.esp -= 4;
    sub_4a4624(app, cpu);
    if (cpu.terminate) return;
    // 00487fee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00487ff0  7423                   -je 0x488015
    if (cpu.flags.zf)
    {
        goto L_0x00488015;
    }
    // 00487ff2  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00487ff8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ff9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ffb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00487ffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00487ffd:
    // 00487ffd  80fa3a                 +cmp dl, 0x3a
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
    // 00488000  74b6                   -je 0x487fb8
    if (cpu.flags.zf)
    {
        goto L_0x00487fb8;
    }
    // 00488002  80fa2f                 +cmp dl, 0x2f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488005  74b1                   -je 0x487fb8
    if (cpu.flags.zf)
    {
        goto L_0x00487fb8;
    }
    // 00488007  80fa5c                 +cmp dl, 0x5c
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
    // 0048800a  74ac                   -je 0x487fb8
    if (cpu.flags.zf)
    {
        goto L_0x00487fb8;
    }
    // 0048800c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048800e  48                     -dec eax
    (cpu.eax)--;
    // 0048800f  39d0                   +cmp eax, edx
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
    // 00488011  779e                   -ja 0x487fb1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00487fb1;
    }
    // 00488013  eba3                   -jmp 0x487fb8
    goto L_0x00487fb8;
L_0x00488015:
    // 00488015  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488017  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00488019  e89a590100             -call 0x49d9b8
    cpu.esp -= 4;
    sub_49d9b8(app, cpu);
    if (cpu.terminate) return;
    // 0048801e  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00488024  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488025  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488026  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488027  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48802c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x0048802c);
    // 0048802c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048802d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048802f  e83cffffff             -call 0x487f70
    cpu.esp -= 4;
    sub_487f70(app, cpu);
    if (cpu.terminate) return;
    // 00488034  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488035  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488038(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x00488038);
    // 00488038  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488039  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048803e  e82dffffff             -call 0x487f70
    cpu.esp -= 4;
    sub_487f70(app, cpu);
    if (cpu.terminate) return;
    // 00488043  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488044  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
