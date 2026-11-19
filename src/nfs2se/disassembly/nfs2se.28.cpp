#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_49f418(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f418  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f419  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f41a  ba78144c00             -mov edx, 0x4c1478
    cpu.edx = 4985976 /*0x4c1478*/;
    // 0049f41f  e8fa1dfeff             -call 0x48121e
    cpu.esp -= 4;
    sub_48121e(app, cpu);
    if (cpu.terminate) return;
    // 0049f424  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f426  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049f428  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f42a  7505                   -jne 0x49f431
    if (!cpu.flags.zf)
    {
        goto L_0x0049f431;
    }
L_0x0049f42c:
    // 0049f42c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f42e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f42f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f430  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f431:
    // 0049f431  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 0049f436  e885f8feff             -call 0x48ecc0
    cpu.esp -= 4;
    sub_48ecc0(app, cpu);
    if (cpu.terminate) return;
    // 0049f43b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f43d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f43f  74eb                   -je 0x49f42c
    if (cpu.flags.zf)
    {
        goto L_0x0049f42c;
    }
    // 0049f441  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049f448  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0049f44f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0049f456  c7801410000000000000   -mov dword ptr [eax + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049f460  c7801810000001000000   -mov dword ptr [eax + 0x1018], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = 1 /*0x1*/;
    // 0049f46a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049f46c  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049f46f  899010100000           -mov dword ptr [eax + 0x1010], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.edx;
    // 0049f475  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f477  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f478  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f479  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f47c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f47c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f47d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049f47f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f481  7507                   -jne 0x49f48a
    if (!cpu.flags.zf)
    {
        goto L_0x0049f48a;
    }
    // 0049f483  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f488  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f489  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f48a:
    // 0049f48a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049f48c  e8a61ffeff             -call 0x481437
    cpu.esp -= 4;
    sub_481437(app, cpu);
    if (cpu.terminate) return;
    // 0049f491  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f493  e890f8feff             -call 0x48ed28
    cpu.esp -= 4;
    sub_48ed28(app, cpu);
    if (cpu.terminate) return;
    // 0049f498  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f49d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f49e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49f4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f4a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f4a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f4a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f4a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f4a4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f4a7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049f4a9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049f4ab  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f4ad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f4af  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049f4b3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f4b5  0f8eae000000           -jle 0x49f569
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f569;
    }
    // 0049f4bb  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049f4be  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0049f4c1:
    // 0049f4c1  8b8e14100000           -mov ecx, dword ptr [esi + 0x1014]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 0049f4c7  39cf                   +cmp edi, ecx
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
    // 0049f4c9  7d02                   -jge 0x49f4cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f4cd;
    }
    // 0049f4cb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x0049f4cd:
    // 0049f4cd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f4cf  7e41                   -jle 0x49f512
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f512;
    }
    // 0049f4d1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049f4d3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049f4d5  8b8610100000           -mov eax, dword ptr [esi + 0x1010]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 0049f4db  e82021feff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0049f4e0  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f4e2  8b9e10100000           -mov ebx, dword ptr [esi + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 0049f4e8  8b8614100000           -mov eax, dword ptr [esi + 0x1014]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 0049f4ee  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049f4f1  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f4f3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f4f5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f4f7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f4f9  899e10100000           -mov dword ptr [esi + 0x1010], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.ebx;
    // 0049f4ff  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f503  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
    // 0049f509  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f50b  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049f50e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0049f512:
    // 0049f512  83be1410000000         +cmp dword ptr [esi + 0x1014], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f519  7546                   -jne 0x49f561
    if (!cpu.flags.zf)
    {
        goto L_0x0049f561;
    }
    // 0049f51b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049f51d  7442                   -je 0x49f561
    if (cpu.flags.zf)
    {
        goto L_0x0049f561;
    }
    // 0049f51f  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049f522  898610100000           -mov dword ptr [esi + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
    // 0049f528  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049f52b  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049f52e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f530  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f535  7e3e                   -jle 0x49f575
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f575;
    }
    // 0049f537  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
L_0x0049f53c:
    // 0049f53c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f53e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f540  7e1b                   -jle 0x49f55d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f55d;
    }
    // 0049f542  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049f547  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049f54a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049f54c  e8a05bffff             -call 0x4950f1
    cpu.esp -= 4;
    sub_4950f1(app, cpu);
    if (cpu.terminate) return;
    // 0049f551  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f553  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f555  7e06                   -jle 0x49f55d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f55d;
    }
    // 0049f557  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
L_0x0049f55d:
    // 0049f55d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f55f  7408                   -je 0x49f569
    if (cpu.flags.zf)
    {
        goto L_0x0049f569;
    }
L_0x0049f561:
    // 0049f561  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049f563  0f8f58ffffff           -jg 0x49f4c1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f4c1;
    }
L_0x0049f569:
    // 0049f569  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f56d  83c408                 +add esp, 8
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
    // 0049f570  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f571  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f572  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f573  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f574  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f575:
    // 0049f575  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049f577  ebc3                   -jmp 0x49f53c
    goto L_0x0049f53c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49f57c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f57c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f57d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f57e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f57f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049f581  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f584  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f586  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f588  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049f58b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049f58e  39fa                   +cmp edx, edi
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
    // 0049f590  7e03                   -jle 0x49f595
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f595;
    }
    // 0049f592  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0049f595:
    // 0049f595  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049f59a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f59c  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f59e  e86c13ffff             -call 0x49090f
    cpu.esp -= 4;
    sub_49090f(app, cpu);
    if (cpu.terminate) return;
    // 0049f5a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f5a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f5ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f5ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f5ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f5ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f5af  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f5b0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049f5b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f5b7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f5b9  0f8c8d000000           -jl 0x49f64c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f64c;
    }
    // 0049f5bf  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049f5c2  39da                   +cmp edx, ebx
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
    // 0049f5c4  0f8e8b000000           -jle 0x49f655
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f655;
    }
    // 0049f5ca  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049f5cc  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0049f5ce:
    // 0049f5ce  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049f5d8  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049f5db  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049f5de  898110100000           -mov dword ptr [ecx + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
L_0x0049f5e4:
    // 0049f5e4  83b91810000000         +cmp dword ptr [ecx + 0x1018], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4120) /* 0x1018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f5eb  0f8596000000           -jne 0x49f687
    if (!cpu.flags.zf)
    {
        goto L_0x0049f687;
    }
    // 0049f5f1  8b9914100000           -mov ebx, dword ptr [ecx + 0x1014]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */);
    // 0049f5f7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f5f9  7e0c                   -jle 0x49f607
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f607;
    }
    // 0049f5fb  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f601  0f8eab000000           -jle 0x49f6b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f6b2;
    }
L_0x0049f607:
    // 0049f607  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f609  0f8cbd000000           -jl 0x49f6cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f6cc;
    }
    // 0049f60f  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f612  0f8fb4000000           -jg 0x49f6cc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f6cc;
    }
    // 0049f618  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049f61b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f61d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f61f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f621  e82ee1ffff             -call 0x49d754
    cpu.esp -= 4;
    sub_49d754(app, cpu);
    if (cpu.terminate) return;
    // 0049f626  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f628  0f859e000000           -jne 0x49f6cc
    if (!cpu.flags.zf)
    {
        goto L_0x0049f6cc;
    }
    // 0049f62e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f630  0f8496000000           -je 0x49f6cc
    if (cpu.flags.zf)
    {
        goto L_0x0049f6cc;
    }
    // 0049f636  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049f63b  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049f645  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f647  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f648  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f649  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f64c:
    // 0049f64c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f64e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049f650  e979ffffff             -jmp 0x49f5ce
    goto L_0x0049f5ce;
L_0x0049f655:
    // 0049f655  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f656  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049f658  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f65b  8ba810100000           -mov ebp, dword ptr [eax + 0x1010]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */);
    // 0049f661  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f663  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f665  8bb814100000           -mov edi, dword ptr [eax + 0x1014]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */);
    // 0049f66b  89a810100000           -mov dword ptr [eax + 0x1010], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ebp;
    // 0049f671  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f673  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f676  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 0049f67c  01dd                   +add ebp, ebx
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
    // 0049f67e  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0049f681  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f682  e95dffffff             -jmp 0x49f5e4
    goto L_0x0049f5e4;
L_0x0049f687:
    // 0049f687  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049f68a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049f68c  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f68e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f690  e8bfe0ffff             -call 0x49d754
    cpu.esp -= 4;
    sub_49d754(app, cpu);
    if (cpu.terminate) return;
    // 0049f695  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f697  7510                   -jne 0x49f6a9
    if (!cpu.flags.zf)
    {
        goto L_0x0049f6a9;
    }
    // 0049f699  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f69b  740c                   -je 0x49f6a9
    if (cpu.flags.zf)
    {
        goto L_0x0049f6a9;
    }
    // 0049f69d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049f6a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f6a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f6a9:
    // 0049f6a9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f6ab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f6ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f6b2:
    // 0049f6b2  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049f6b5  8b9910100000           -mov ebx, dword ptr [ecx + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */);
    // 0049f6bb  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f6bd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f6bf  0f8c42ffffff           -jl 0x49f607
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f607;
    }
    // 0049f6c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f6c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f6cc:
    // 0049f6cc  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f6ce  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 0049f6d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f6da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49f6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f6e0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049f6e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f6e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f6e4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049f6e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49f6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f6f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f6f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f6f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f6f3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f6f6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f6f8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049f6fa  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049f6fc  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f700  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f702  7506                   -jne 0x49f70a
    if (!cpu.flags.zf)
    {
        goto L_0x0049f70a;
    }
    // 0049f704  8b0dd8a34c00           -mov ecx, dword ptr [0x4ca3d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */);
L_0x0049f70a:
    // 0049f70a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f70c  7505                   -jne 0x49f713
    if (!cpu.flags.zf)
    {
        goto L_0x0049f713;
    }
    // 0049f70e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x0049f713:
    // 0049f713  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049f716  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049f718  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 0049f71d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049f720  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f722  e87515feff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0049f727  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 0049f72d  c6461eff               -mov byte ptr [esi + 0x1e], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */) = 255 /*0xff*/;
    // 0049f731  896e28                 -mov dword ptr [esi + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0049f734  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049f737  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049f73a  897e14                 -mov dword ptr [esi + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 0049f73d  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049f740  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f742  884e1c                 -mov byte ptr [esi + 0x1c], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cl;
    // 0049f745  e816b2ffff             -call 0x49a960
    cpu.esp -= 4;
    sub_49a960(app, cpu);
    if (cpu.terminate) return;
    // 0049f74a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049f74c  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 0049f74f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049f753  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049f755  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049f758  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049f75c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f75e  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0049f761  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f763  e81c7effff             -call 0x497584
    cpu.esp -= 4;
    sub_497584(app, cpu);
    if (cpu.terminate) return;
    // 0049f768  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049f76d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049f770  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049f772  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049f775  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f777  e8087effff             -call 0x497584
    cpu.esp -= 4;
    sub_497584(app, cpu);
    if (cpu.terminate) return;
    // 0049f77c  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0049f77f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f782  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f783  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f784  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f785  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_49f788(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f788  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f789  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f78a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f78b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f78e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f790  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049f792  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049f795  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f799  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f79b  7c26                   -jl 0x49f7c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f7c3;
    }
    // 0049f79d  3d00050000             +cmp eax, 0x500
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1280 /*0x500*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f7a2  7f1f                   -jg 0x49f7c3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f7c3;
    }
    // 0049f7a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f7a6  7c1b                   -jl 0x49f7c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f7c3;
    }
    // 0049f7a8  81fa00040000           +cmp edx, 0x400
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f7ae  7f13                   -jg 0x49f7c3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f7c3;
    }
    // 0049f7b0  83fbff                 +cmp ebx, -1
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
    // 0049f7b3  7519                   -jne 0x49f7ce
    if (!cpu.flags.zf)
    {
        goto L_0x0049f7ce;
    }
    // 0049f7b5  bef4a64c00             -mov esi, 0x4ca6f4
    cpu.esi = 5023476 /*0x4ca6f4*/;
L_0x0049f7ba:
    // 0049f7ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f7bc  752f                   -jne 0x49f7ed
    if (!cpu.flags.zf)
    {
        goto L_0x0049f7ed;
    }
    // 0049f7be  e809b1fdff             -call 0x47a8cc
    cpu.esp -= 4;
    sub_47a8cc(app, cpu);
    if (cpu.terminate) return;
L_0x0049f7c3:
    // 0049f7c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f7c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f7c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7cb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049f7ce:
    // 0049f7ce  83fbfe                 +cmp ebx, -2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f7d1  7507                   -jne 0x49f7da
    if (!cpu.flags.zf)
    {
        goto L_0x0049f7da;
    }
    // 0049f7d3  be2ca74c00             -mov esi, 0x4ca72c
    cpu.esi = 5023532 /*0x4ca72c*/;
    // 0049f7d8  ebe0                   -jmp 0x49f7ba
    goto L_0x0049f7ba;
L_0x0049f7da:
    // 0049f7da  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 0049f7df  b804154c00             -mov eax, 0x4c1504
    cpu.eax = 4986116 /*0x4c1504*/;
    // 0049f7e4  e83faafdff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0049f7e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f7eb  ebcd                   -jmp 0x49f7ba
    goto L_0x0049f7ba;
L_0x0049f7ed:
    // 0049f7ed  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049f7f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f7f2  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049f7f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f7f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f7f9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049f7fb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f7fc  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0049f7fe  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049f802  e8e9feffff             -call 0x49f6f0
    cpu.esp -= 4;
    sub_49f6f0(app, cpu);
    if (cpu.terminate) return;
    // 0049f807  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f809  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f80c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f80d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f80e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f80f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f814(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f814  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f815  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f816  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f817  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f818  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f81a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f81c  7505                   -jne 0x49f823
    if (!cpu.flags.zf)
    {
        goto L_0x0049f823;
    }
    // 0049f81e  bebca64c00             -mov esi, 0x4ca6bc
    cpu.esi = 5023420 /*0x4ca6bc*/;
L_0x0049f823:
    // 0049f823  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0049f826  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049f829  39ca                   +cmp edx, ecx
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
    // 0049f82b  7420                   -je 0x49f84d
    if (cpu.flags.zf)
    {
        goto L_0x0049f84d;
    }
    // 0049f82d  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0049f830  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f832  7407                   -je 0x49f83b
    if (cpu.flags.zf)
    {
        goto L_0x0049f83b;
    }
    // 0049f834  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f836  e8217effff             -call 0x49765c
    cpu.esp -= 4;
    sub_49765c(app, cpu);
    if (cpu.terminate) return;
L_0x0049f83b:
    // 0049f83b  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049f83e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f840  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f842  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049f845  e83a7dffff             -call 0x497584
    cpu.esp -= 4;
    sub_497584(app, cpu);
    if (cpu.terminate) return;
    // 0049f84a  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0049f84d:
    // 0049f84d  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049f850  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049f853  39f8                   +cmp eax, edi
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
    // 0049f855  7e03                   -jle 0x49f85a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f85a;
    }
    // 0049f857  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0049f85a:
    // 0049f85a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049f85d  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049f860  39e8                   +cmp eax, ebp
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
    // 0049f862  7e03                   -jle 0x49f867
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f867;
    }
    // 0049f864  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x0049f867:
    // 0049f867  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049f86a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049f86d  39d0                   +cmp eax, edx
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
    // 0049f86f  7e19                   -jle 0x49f88a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049f88a;
    }
    // 0049f871  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0049f874:
    // 0049f874  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049f877  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049f87a  39d8                   +cmp eax, ebx
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
    // 0049f87c  7f18                   -jg 0x49f896
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049f896;
    }
    // 0049f87e  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049f881  39f8                   +cmp eax, edi
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
    // 0049f883  7c19                   -jl 0x49f89e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049f89e;
    }
    // 0049f885  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f886  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f887  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f888  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f889  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f88a:
    // 0049f88a  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049f88d  39c8                   +cmp eax, ecx
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
    // 0049f88f  7de3                   -jge 0x49f874
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f874;
    }
    // 0049f891  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049f894  ebde                   -jmp 0x49f874
    goto L_0x0049f874;
L_0x0049f896:
    // 0049f896  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049f899  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f89a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f89b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f89c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f89d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f89e:
    // 0049f89e  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0049f8a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49f8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f8a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f8a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f8aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f8ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049f8ad  8b482c                 -mov ecx, dword ptr [eax + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0049f8b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049f8b2  7529                   -jne 0x49f8dd
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8dd;
    }
L_0x0049f8b4:
    // 0049f8b4  8b5a30                 -mov ebx, dword ptr [edx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0049f8b7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f8b9  740e                   -je 0x49f8c9
    if (cpu.flags.zf)
    {
        goto L_0x0049f8c9;
    }
    // 0049f8bb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f8bd  e89a7dffff             -call 0x49765c
    cpu.esp -= 4;
    sub_49765c(app, cpu);
    if (cpu.terminate) return;
    // 0049f8c2  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
L_0x0049f8c9:
    // 0049f8c9  81faf4a64c00           +cmp edx, 0x4ca6f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5023476 /*0x4ca6f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f8cf  7408                   -je 0x49f8d9
    if (cpu.flags.zf)
    {
        goto L_0x0049f8d9;
    }
    // 0049f8d1  81fa2ca74c00           +cmp edx, 0x4ca72c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5023532 /*0x4ca72c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f8d7  7514                   -jne 0x49f8ed
    if (!cpu.flags.zf)
    {
        goto L_0x0049f8ed;
    }
L_0x0049f8d9:
    // 0049f8d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f8dd:
    // 0049f8dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f8df  e8787dffff             -call 0x49765c
    cpu.esp -= 4;
    sub_49765c(app, cpu);
    if (cpu.terminate) return;
    // 0049f8e4  c7422c00000000         -mov dword ptr [edx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 0049f8eb  ebc7                   -jmp 0x49f8b4
    goto L_0x0049f8b4;
L_0x0049f8ed:
    // 0049f8ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f8ef  e898adfdff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0049f8f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f8f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f8f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f8f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f8f9  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049f8fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f8fe  7502                   -jne 0x49f902
    if (!cpu.flags.zf)
    {
        goto L_0x0049f902;
    }
    // 0049f900  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f901  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f902:
    // 0049f902  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f904  e82b96feff             -call 0x488f34
    cpu.esp -= 4;
    sub_488f34(app, cpu);
    if (cpu.terminate) return;
    // 0049f909  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f90a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49f90c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f90c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f90d  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0049f910  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f912  7502                   -jne 0x49f916
    if (!cpu.flags.zf)
    {
        goto L_0x0049f916;
    }
    // 0049f914  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f915  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f916:
    // 0049f916  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f918  e85796feff             -call 0x488f74
    cpu.esp -= 4;
    sub_488f74(app, cpu);
    if (cpu.terminate) return;
    // 0049f91d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f91e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49f920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f920  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f922  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f923  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049f926  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049f928  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f92a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f92b  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049f92f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f930  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f931  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049f933  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f934  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049f936  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049f938  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 0049f93d  e84292feff             -call 0x488b84
    cpu.esp -= 4;
    sub_488b84(app, cpu);
    if (cpu.terminate) return;
    // 0049f942  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f944  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f946  750b                   -jne 0x49f953
    if (!cpu.flags.zf)
    {
        goto L_0x0049f953;
    }
L_0x0049f948:
    // 0049f948  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f94a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049f94d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f94f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f950  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049f953:
    // 0049f953  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049f955  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f959  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f95a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049f95e  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f962  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f963  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f967  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f969  e8e294feff             -call 0x488e50
    cpu.esp -= 4;
    sub_488e50(app, cpu);
    if (cpu.terminate) return;
    // 0049f96e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f96f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049f973  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f974  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049f978  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f97c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f97d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049f981  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049f985  e8fefdffff             -call 0x49f788
    cpu.esp -= 4;
    sub_49f788(app, cpu);
    if (cpu.terminate) return;
    // 0049f98a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f98c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f98e  75b8                   -jne 0x49f948
    if (!cpu.flags.zf)
    {
        goto L_0x0049f948;
    }
    // 0049f990  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 0049f995  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f997  e8dc93feff             -call 0x488d78
    cpu.esp -= 4;
    sub_488d78(app, cpu);
    if (cpu.terminate) return;
    // 0049f99c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f99e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049f9a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9a4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49f9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f9b0  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f9b2  742c                   -je 0x49f9e0
    if (cpu.flags.zf)
    {
        goto L_0x0049f9e0;
    }
    // 0049f9b4  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x0049f9b6:
    // 0049f9b6  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 0049f9b8  7409                   -je 0x49f9c3
    if (cpu.flags.zf)
    {
        goto L_0x0049f9c3;
    }
    // 0049f9ba  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049f9bc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f9bd  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 0049f9c0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9c1  75f3                   -jne 0x49f9b6
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9b6;
    }
L_0x0049f9c3:
    // 0049f9c3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f9c4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f9c7  e81b000000             -call 0x49f9e7
    cpu.esp -= 4;
    sub_49f9e7(app, cpu);
    if (cpu.terminate) return;
    // 0049f9cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9cd  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049f9d0  740e                   -je 0x49f9e0
    if (cpu.flags.zf)
    {
        goto L_0x0049f9e0;
    }
    // 0049f9d2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049f9d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9d5  7409                   -je 0x49f9e0
    if (cpu.flags.zf)
    {
        goto L_0x0049f9e0;
    }
    // 0049f9d7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 0049f9da  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9db  7403                   -je 0x49f9e0
    if (cpu.flags.zf)
    {
        goto L_0x0049f9e0;
    }
    // 0049f9dd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x0049f9e0:
    // 0049f9e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49f9e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f9e2  90                     -nop 
    ;
    // 0049f9e3  90                     -nop 
    ;
    // 0049f9e4  90                     -nop 
    ;
    // 0049f9e5  90                     -nop 
    ;
    // 0049f9e6  90                     -nop 
    ;
    // 0049f9e7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f9e9  7467                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
L_0x0049f9eb:
    // 0049f9eb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 0049f9ed  7408                   -je 0x49f9f7
    if (cpu.flags.zf)
    {
        goto L_0x0049f9f7;
    }
    // 0049f9ef  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049f9f1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f9f4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9f5  75f4                   -jne 0x49f9eb
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9eb;
    }
L_0x0049f9f7:
    // 0049f9f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f9f8  c1e902                 +shr ecx, 2
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
    // 0049f9fb  743a                   -je 0x49fa37
    if (cpu.flags.zf)
    {
        goto L_0x0049fa37;
    }
    // 0049f9fd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9fe  7429                   -je 0x49fa29
    if (cpu.flags.zf)
    {
        goto L_0x0049fa29;
    }
L_0x0049fa00:
    // 0049fa00  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa02  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049fa05  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa06  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049fa09  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049fa0c  7418                   -je 0x49fa26
    if (cpu.flags.zf)
    {
        goto L_0x0049fa26;
    }
    // 0049fa0e  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049fa11  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049fa14  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049fa17  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa18  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049fa1b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049fa1e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049fa21  75dd                   -jne 0x49fa00
    if (!cpu.flags.zf)
    {
        goto L_0x0049fa00;
    }
    // 0049fa23  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x0049fa26:
    // 0049fa26  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049fa29:
    // 0049fa29  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa2b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049fa2e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049fa31  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049fa34  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049fa37:
    // 0049fa37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa38  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049fa3b  7415                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
    // 0049fa3d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa3f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049fa42  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa43  740d                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
    // 0049fa45  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa47  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049fa4a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa4b  7405                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
    // 0049fa4d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa4f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0049fa52:
    // 0049fa52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49f9e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049f9e7;
    // 0049f9e2  90                     -nop 
    ;
    // 0049f9e3  90                     -nop 
    ;
    // 0049f9e4  90                     -nop 
    ;
    // 0049f9e5  90                     -nop 
    ;
    // 0049f9e6  90                     -nop 
    ;
L_entry_0x0049f9e7:
    // 0049f9e7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f9e9  7467                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
L_0x0049f9eb:
    // 0049f9eb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 0049f9ed  7408                   -je 0x49f9f7
    if (cpu.flags.zf)
    {
        goto L_0x0049f9f7;
    }
    // 0049f9ef  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049f9f1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f9f4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9f5  75f4                   -jne 0x49f9eb
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9eb;
    }
L_0x0049f9f7:
    // 0049f9f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f9f8  c1e902                 +shr ecx, 2
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
    // 0049f9fb  743a                   -je 0x49fa37
    if (cpu.flags.zf)
    {
        goto L_0x0049fa37;
    }
    // 0049f9fd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049f9fe  7429                   -je 0x49fa29
    if (cpu.flags.zf)
    {
        goto L_0x0049fa29;
    }
L_0x0049fa00:
    // 0049fa00  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa02  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049fa05  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa06  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049fa09  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049fa0c  7418                   -je 0x49fa26
    if (cpu.flags.zf)
    {
        goto L_0x0049fa26;
    }
    // 0049fa0e  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049fa11  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049fa14  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0049fa17  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa18  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049fa1b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049fa1e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049fa21  75dd                   -jne 0x49fa00
    if (!cpu.flags.zf)
    {
        goto L_0x0049fa00;
    }
    // 0049fa23  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x0049fa26:
    // 0049fa26  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049fa29:
    // 0049fa29  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa2b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049fa2e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049fa31  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049fa34  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x0049fa37:
    // 0049fa37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa38  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0049fa3b  7415                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
    // 0049fa3d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa3f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049fa42  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa43  740d                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
    // 0049fa45  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa47  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049fa4a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049fa4b  7405                   -je 0x49fa52
    if (cpu.flags.zf)
    {
        goto L_0x0049fa52;
    }
    // 0049fa4d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049fa4f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0049fa52:
    // 0049fa52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_49fa54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fa54  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049fa57  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049fa5a  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049fa5d  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049fa60  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fa62  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fa64  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049fa67  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049fa6a  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049fa6c  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fa6e  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049fa71  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0049fa73  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049fa75  0f8410010000           -je 0x49fb8b
    if (cpu.flags.zf)
    {
        goto L_0x0049fb8b;
    }
    // 0049fa7b  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049fa7e  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049fa81  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049fa84  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fa86  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049fa89  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fa8b  891d38194d00           -mov dword ptr [0x4d1938], ebx
    app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */) = cpu.ebx;
    // 0049fa91  890d3c194d00           -mov dword ptr [0x4d193c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */) = cpu.ecx;
    // 0049fa97  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 0049fa9a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049fa9c  db0538194d00           -fild dword ptr [0x4d1938]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */))));
    // 0049faa2  db053c194d00           -fild dword ptr [0x4d193c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */))));
    // 0049faa8  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049faaa  d80d50194d00           -fmul dword ptr [0x4d1950]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5052752) /* 0x4d1950 */));
    // 0049fab0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049fab2  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049fab4  d80d4c194d00           -fmul dword ptr [0x4d194c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5052748) /* 0x4d194c */));
    // 0049faba  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049fabc  d80d54194d00           -fmul dword ptr [0x4d1954]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5052756) /* 0x4d1954 */));
    // 0049fac2  f72d48194d00           -imul dword ptr [0x4d1948]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052744) /* 0x4d1948 */))));
    // 0049fac8  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049faca  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049facc  d80558194d00           -fadd dword ptr [0x4d1958]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5052760) /* 0x4d1958 */));
    // 0049fad2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049fad4  d80558194d00           -fadd dword ptr [0x4d1958]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5052760) /* 0x4d1958 */));
    // 0049fada  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049fadd  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049fae0  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049fae2  dd1d40194d00           -fstp qword ptr [0x4d1940]
    app->getMemory<double>(x86::reg32(5052736) /* 0x4d1940 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049fae8  dd1d38194d00           -fstp qword ptr [0x4d1938]
    app->getMemory<double>(x86::reg32(5052728) /* 0x4d1938 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049faee  8b0d38194d00           -mov ecx, dword ptr [0x4d1938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */);
    // 0049faf4  8b3d40194d00           -mov edi, dword ptr [0x4d1940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5052736) /* 0x4d1940 */);
    // 0049fafa  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fafc  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049fafe  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fb00  890d3c194d00           -mov dword ptr [0x4d193c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */) = cpu.ecx;
    // 0049fb06  891540194d00           -mov dword ptr [0x4d1940], edx
    app->getMemory<x86::reg32>(x86::reg32(5052736) /* 0x4d1940 */) = cpu.edx;
    // 0049fb0c  893d44194d00           -mov dword ptr [0x4d1944], edi
    app->getMemory<x86::reg32>(x86::reg32(5052740) /* 0x4d1944 */) = cpu.edi;
    // 0049fb12  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049fb14  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049fb17  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0049fb1a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fb1c  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049fb1f  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fb21  f72d48194d00           -imul dword ptr [0x4d1948]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052744) /* 0x4d1948 */))));
    // 0049fb27  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049fb29  8b3d34194d00           -mov edi, dword ptr [0x4d1934]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fb2f  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fb31  8b2d3c194d00           -mov ebp, dword ptr [0x4d193c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */);
    // 0049fb37  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049fb3a  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fb3c  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 0049fb3f  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fb41  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0049fb44  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fb46  8b2d38194d00           -mov ebp, dword ptr [0x4d1938]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */);
    // 0049fb4c  897748                 -mov dword ptr [edi + 0x48], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.esi;
    // 0049fb4f  8b3540194d00           -mov esi, dword ptr [0x4d1940]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5052736) /* 0x4d1940 */);
    // 0049fb55  898fb4000000           -mov dword ptr [edi + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 0049fb5b  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0049fb5e  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fb60  8b2d44194d00           -mov ebp, dword ptr [0x4d1944]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5052740) /* 0x4d1944 */);
    // 0049fb66  894f6c                 -mov dword ptr [edi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 0049fb69  899f90000000           -mov dword ptr [edi + 0x90], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.ebx;
    // 0049fb6f  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0049fb72  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fb74  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049fb77  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fb79  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0049fb7b  895f24                 -mov dword ptr [edi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049fb7e  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 0049fb84  8997fc000000           -mov dword ptr [edi + 0xfc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.edx;
    // 0049fb8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fb8b:
    // 0049fb8b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049fb8d  8b3d34194d00           -mov edi, dword ptr [0x4d1934]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fb93  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0049fb95  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049fb98  894748                 -mov dword ptr [edi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049fb9b  89476c                 -mov dword ptr [edi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0049fb9e  898790000000           -mov dword ptr [edi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0049fba4  8987b4000000           -mov dword ptr [edi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0049fbaa  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 0049fbb0  8987fc000000           -mov dword ptr [edi + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.eax;
    // 0049fbb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fbb7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fbb7  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049fbba  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049fbbd  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049fbc0  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0049fbc3  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049fbc6  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fbc8  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049fbcb  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fbcd  891d38194d00           -mov dword ptr [0x4d1938], ebx
    app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */) = cpu.ebx;
    // 0049fbd3  890d3c194d00           -mov dword ptr [0x4d193c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */) = cpu.ecx;
    // 0049fbd9  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 0049fbdc  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049fbde  db0538194d00           -fild dword ptr [0x4d1938]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */))));
    // 0049fbe4  db053c194d00           -fild dword ptr [0x4d193c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */))));
    // 0049fbea  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0049fbec  d80d50194d00           -fmul dword ptr [0x4d1950]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5052752) /* 0x4d1950 */));
    // 0049fbf2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0049fbf4  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049fbf6  d80d4c194d00           -fmul dword ptr [0x4d194c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5052748) /* 0x4d194c */));
    // 0049fbfc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049fbfe  d80d54194d00           -fmul dword ptr [0x4d1954]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5052756) /* 0x4d1954 */));
    // 0049fc04  f72d48194d00           -imul dword ptr [0x4d1948]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052744) /* 0x4d1948 */))));
    // 0049fc0a  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 0049fc0c  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049fc0e  d80558194d00           -fadd dword ptr [0x4d1958]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5052760) /* 0x4d1958 */));
    // 0049fc14  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049fc16  d80558194d00           -fadd dword ptr [0x4d1958]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5052760) /* 0x4d1958 */));
    // 0049fc1c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049fc1f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0049fc22  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049fc24  dd1d40194d00           -fstp qword ptr [0x4d1940]
    app->getMemory<double>(x86::reg32(5052736) /* 0x4d1940 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049fc2a  dd1d38194d00           -fstp qword ptr [0x4d1938]
    app->getMemory<double>(x86::reg32(5052728) /* 0x4d1938 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049fc30  8b0d38194d00           -mov ecx, dword ptr [0x4d1938]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */);
    // 0049fc36  8b3d40194d00           -mov edi, dword ptr [0x4d1940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5052736) /* 0x4d1940 */);
    // 0049fc3c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fc3e  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049fc40  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fc42  890d3c194d00           -mov dword ptr [0x4d193c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */) = cpu.ecx;
    // 0049fc48  891540194d00           -mov dword ptr [0x4d1940], edx
    app->getMemory<x86::reg32>(x86::reg32(5052736) /* 0x4d1940 */) = cpu.edx;
    // 0049fc4e  893d44194d00           -mov dword ptr [0x4d1944], edi
    app->getMemory<x86::reg32>(x86::reg32(5052740) /* 0x4d1944 */) = cpu.edi;
    // 0049fc54  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049fc56  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049fc59  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0049fc5c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fc5e  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049fc61  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fc63  f72d48194d00           -imul dword ptr [0x4d1948]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5052744) /* 0x4d1948 */))));
    // 0049fc69  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 0049fc6b  8b3d34194d00           -mov edi, dword ptr [0x4d1934]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fc71  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fc73  8b2d3c194d00           -mov ebp, dword ptr [0x4d193c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5052732) /* 0x4d193c */);
    // 0049fc79  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0049fc7c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049fc7e  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 0049fc81  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fc83  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0049fc86  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fc88  8b2d38194d00           -mov ebp, dword ptr [0x4d1938]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5052728) /* 0x4d1938 */);
    // 0049fc8e  897708                 -mov dword ptr [edi + 8], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049fc91  8b3540194d00           -mov esi, dword ptr [0x4d1940]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5052736) /* 0x4d1940 */);
    // 0049fc97  894f14                 -mov dword ptr [edi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049fc9a  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 0049fc9d  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fc9f  8b2d44194d00           -mov ebp, dword ptr [0x4d1944]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5052740) /* 0x4d1944 */);
    // 0049fca5  894f0c                 -mov dword ptr [edi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049fca8  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049fcab  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0049fcae  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049fcb0  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049fcb3  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fcb5  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0049fcb7  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049fcba  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049fcbd  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049fcc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fcc1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fcc1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fcc2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fcc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fcc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fcc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fcc6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049fcc7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049fcca  891530194d00           -mov dword ptr [0x4d1930], edx
    app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */) = cpu.edx;
    // 0049fcd0  be7c1a4d00             -mov esi, 0x4d1a7c
    cpu.esi = 5053052 /*0x4d1a7c*/;
    // 0049fcd5  c70534194d005c194d00   -mov dword ptr [0x4d1934], 0x4d195c
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052764 /*0x4d195c*/;
    // 0049fcdf  e870fdffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fce4  be9c1a4d00             -mov esi, 0x4d1a9c
    cpu.esi = 5053084 /*0x4d1a9c*/;
    // 0049fce9  c70534194d0060194d00   -mov dword ptr [0x4d1934], 0x4d1960
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052768 /*0x4d1960*/;
    // 0049fcf3  e85cfdffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fcf8  bebc1a4d00             -mov esi, 0x4d1abc
    cpu.esi = 5053116 /*0x4d1abc*/;
    // 0049fcfd  c70534194d0064194d00   -mov dword ptr [0x4d1934], 0x4d1964
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052772 /*0x4d1964*/;
    // 0049fd07  e848fdffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fd0c  bedc1a4d00             -mov esi, 0x4d1adc
    cpu.esi = 5053148 /*0x4d1adc*/;
    // 0049fd11  c70534194d0068194d00   -mov dword ptr [0x4d1934], 0x4d1968
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052776 /*0x4d1968*/;
    // 0049fd1b  e834fdffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fd20  befc1a4d00             -mov esi, 0x4d1afc
    cpu.esi = 5053180 /*0x4d1afc*/;
    // 0049fd25  c70534194d006c194d00   -mov dword ptr [0x4d1934], 0x4d196c
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052780 /*0x4d196c*/;
    // 0049fd2f  e820fdffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fd34  be1c1b4d00             -mov esi, 0x4d1b1c
    cpu.esi = 5053212 /*0x4d1b1c*/;
    // 0049fd39  c70534194d0070194d00   -mov dword ptr [0x4d1934], 0x4d1970
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052784 /*0x4d1970*/;
    // 0049fd43  e80cfdffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fd48  be3c1b4d00             -mov esi, 0x4d1b3c
    cpu.esi = 5053244 /*0x4d1b3c*/;
    // 0049fd4d  c70534194d0074194d00   -mov dword ptr [0x4d1934], 0x4d1974
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052788 /*0x4d1974*/;
    // 0049fd57  e8f8fcffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fd5c  be5c1b4d00             -mov esi, 0x4d1b5c
    cpu.esi = 5053276 /*0x4d1b5c*/;
    // 0049fd61  c70534194d0078194d00   -mov dword ptr [0x4d1934], 0x4d1978
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = 5052792 /*0x4d1978*/;
    // 0049fd6b  e8e4fcffff             -call 0x49fa54
    cpu.esp -= 4;
    sub_49fa54(app, cpu);
    if (cpu.terminate) return;
    // 0049fd70  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd71  be5c194d00             -mov esi, 0x4d195c
    cpu.esi = 5052764 /*0x4d195c*/;
    // 0049fd76  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fd7b  e837feffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fd80  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fd85  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fd8b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fd8d  be80194d00             -mov esi, 0x4d1980
    cpu.esi = 5052800 /*0x4d1980*/;
    // 0049fd92  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fd97  e81bfeffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fd9c  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fda1  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fda7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fda9  bea4194d00             -mov esi, 0x4d19a4
    cpu.esi = 5052836 /*0x4d19a4*/;
    // 0049fdae  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fdb3  e8fffdffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fdb8  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fdbd  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fdc3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fdc5  bec8194d00             -mov esi, 0x4d19c8
    cpu.esi = 5052872 /*0x4d19c8*/;
    // 0049fdca  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fdcf  e8e3fdffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fdd4  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fdd9  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fddf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fde1  beec194d00             -mov esi, 0x4d19ec
    cpu.esi = 5052908 /*0x4d19ec*/;
    // 0049fde6  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fdeb  e8c7fdffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fdf0  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fdf5  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fdfb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fdfd  be101a4d00             -mov esi, 0x4d1a10
    cpu.esi = 5052944 /*0x4d1a10*/;
    // 0049fe02  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fe07  e8abfdffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fe0c  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fe11  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fe17  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fe19  be341a4d00             -mov esi, 0x4d1a34
    cpu.esi = 5052980 /*0x4d1a34*/;
    // 0049fe1e  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fe23  e88ffdffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fe28  a134194d00             -mov eax, dword ptr [0x4d1934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */);
    // 0049fe2d  8b1530194d00           -mov edx, dword ptr [0x4d1930]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5052720) /* 0x4d1930 */);
    // 0049fe33  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049fe35  be581a4d00             -mov esi, 0x4d1a58
    cpu.esi = 5053016 /*0x4d1a58*/;
    // 0049fe3a  a334194d00             -mov dword ptr [0x4d1934], eax
    app->getMemory<x86::reg32>(x86::reg32(5052724) /* 0x4d1934 */) = cpu.eax;
    // 0049fe3f  e873fdffff             -call 0x49fbb7
    cpu.esp -= 4;
    sub_49fbb7(app, cpu);
    if (cpu.terminate) return;
    // 0049fe44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_49fe4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fe4c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fe4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fe4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fe4f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fe50  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fe52  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fe54  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049fe57  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049fe59  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0049fe5c  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 0049fe61  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fe64  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049fe66:
    // 0049fe66  c1e816                 -shr eax, 0x16
    cpu.eax >>= 22 /*0x16*/ % 32;
    // 0049fe69  3dff010000             +cmp eax, 0x1ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(511 /*0x1ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fe6e  0f84de000000           -je 0x49ff52
    if (cpu.flags.zf)
    {
        goto L_0x0049ff52;
    }
    // 0049fe74  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049fe77  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fe7a  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 0049fe7d  83ed0a                 -sub ebp, 0xa
    (cpu.ebp) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0049fe80  83fd10                 +cmp ebp, 0x10
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
    // 0049fe83  7d16                   -jge 0x49fe9b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fe9b;
    }
    // 0049fe85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fe87  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049fe8c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049fe8f  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fe91  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049fe93  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fe96  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fe98  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049fe9b:
    // 0049fe9b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0049fe9d:
    // 0049fe9d  c1ea13                 -shr edx, 0x13
    cpu.edx >>= 19 /*0x13*/ % 32;
    // 0049fea0  8b0495cce15100         -mov eax, dword ptr [edx*4 + 0x51e1cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5366220) /* 0x51e1cc */ + cpu.edx * 4);
    // 0049fea7  a900002000             +test eax, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2097152 /*0x200000*/));
    // 0049feac  7461                   -je 0x49ff0f
    if (cpu.flags.zf)
    {
        goto L_0x0049ff0f;
    }
    // 0049feae  a900000100             +test eax, 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 65536 /*0x10000*/));
    // 0049feb3  742d                   -je 0x49fee2
    if (cpu.flags.zf)
    {
        goto L_0x0049fee2;
    }
    // 0049feb5  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 0049feb8  83ed06                 -sub ebp, 6
    (cpu.ebp) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0049febb  83fd10                 +cmp ebp, 0x10
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
    // 0049febe  7d16                   -jge 0x49fed6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049fed6;
    }
    // 0049fec0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fec2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049fec7  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049feca  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fecc  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049fece  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fed1  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fed3  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049fed6:
    // 0049fed6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049fed8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049fedb  0d00001000             +or eax, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 0049fee0  eb2d                   -jmp 0x49ff0f
    goto L_0x0049ff0f;
L_0x0049fee2:
    // 0049fee2  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049fee5  83ed08                 -sub ebp, 8
    (cpu.ebp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049fee8  83fd10                 +cmp ebp, 0x10
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
    // 0049feeb  7d16                   -jge 0x49ff03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ff03;
    }
    // 0049feed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049feef  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049fef4  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049fef7  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049fef9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0049fefb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fefe  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ff00  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049ff03:
    // 0049ff03  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ff05  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 0049ff08  8b0495cc615200         -mov eax, dword ptr [edx*4 + 0x5261cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5398988) /* 0x5261cc */ + cpu.edx * 4);
L_0x0049ff0f:
    // 0049ff0f  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049ff12  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ff14  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0049ff17  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ff1a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0049ff1c  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ff1e  83fd10                 +cmp ebp, 0x10
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
    // 0049ff21  7d16                   -jge 0x49ff39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ff39;
    }
    // 0049ff23  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ff25  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049ff2a  668b16                 -mov dx, word ptr [esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi);
    // 0049ff2d  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049ff2f  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0049ff31  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ff34  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ff36  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0049ff39:
    // 0049ff39  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049ff3e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049ff40  3d00fe0000             +cmp eax, 0xfe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65024 /*0xfe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ff45  0f8552ffffff           -jne 0x49fe9d
    if (!cpu.flags.zf)
    {
        goto L_0x0049fe9d;
    }
    // 0049ff4b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ff4d  e914ffffff             -jmp 0x49fe66
    goto L_0x0049fe66;
L_0x0049ff52:
    // 0049ff52  66c70700fe             -mov word ptr [edi], 0xfe00
    app->getMemory<x86::reg16>(cpu.edi) = 65024 /*0xfe00*/;
    // 0049ff57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ff5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ff5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ff5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ff5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ff5f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ff60  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ff61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ff62  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ff64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ff66  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 0049ff69  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ff6b  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 0049ff6e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049ff73  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 0049ff76  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 0049ff7b  f72dcc695200           -imul dword ptr [0x5269cc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5401036) /* 0x5269cc */))));
    // 0049ff81  a37c1a4d00             -mov dword ptr [0x4d1a7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5053052) /* 0x4d1a7c */) = cpu.eax;
    // 0049ff86  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0049ff88:
    // 0049ff88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ff8a  668b044e               -mov ax, word ptr [esi + ecx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ecx * 2);
    // 0049ff8e  41                     -inc ecx
    (cpu.ecx)++;
    // 0049ff8f  3d00fe0000             +cmp eax, 0xfe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65024 /*0xfe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ff94  7436                   -je 0x49ffcc
    if (cpu.flags.zf)
    {
        goto L_0x0049ffcc;
    }
    // 0049ff96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ff98  8a9f38e54c00           -mov bl, byte ptr [edi + 0x4ce538]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5039416) /* 0x4ce538 */);
    // 0049ff9e  c1ea0a                 +shr edx, 0xa
    {
        x86::reg8 tmp = 10 /*0xa*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0049ffa1  7412                   -je 0x49ffb5
    if (cpu.flags.zf)
    {
        goto L_0x0049ffb5;
    }
L_0x0049ffa3:
    // 0049ffa3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049ffa4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049ffa5  892c9d7c1a4d00         -mov dword ptr [ebx*4 + 0x4d1a7c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5053052) /* 0x4d1a7c */ + cpu.ebx * 4) = cpu.ebp;
    // 0049ffac  90                     -nop 
    ;
    // 0049ffad  8a9f38e54c00           -mov bl, byte ptr [edi + 0x4ce538]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5039416) /* 0x4ce538 */);
    // 0049ffb3  75ee                   -jne 0x49ffa3
    if (!cpu.flags.zf)
    {
        goto L_0x0049ffa3;
    }
L_0x0049ffb5:
    // 0049ffb5  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 0049ffb8  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 0049ffbb  4f                     -dec edi
    (cpu.edi)--;
    // 0049ffbc  f72c9dcc695200         +imul dword ptr [ebx*4 + 0x5269cc]
    {
        cpu.edx_eax = x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5401036) /* 0x5269cc */ + cpu.ebx * 4)));
        cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg64>(cpu.edx_eax) != x86::sreg64(static_cast<x86::sreg32>(cpu.eax)));
    }
    // 0049ffc3  89049d7c1a4d00         -mov dword ptr [ebx*4 + 0x4d1a7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5053052) /* 0x4d1a7c */ + cpu.ebx * 4) = cpu.eax;
    // 0049ffca  ebbc                   -jmp 0x49ff88
    goto L_0x0049ff88;
L_0x0049ffcc:
    // 0049ffcc  8a9f38e54c00           -mov bl, byte ptr [edi + 0x4ce538]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5039416) /* 0x4ce538 */);
L_0x0049ffd2:
    // 0049ffd2  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049ffd3  7810                   -js 0x49ffe5
    if (cpu.flags.sf)
    {
        goto L_0x0049ffe5;
    }
    // 0049ffd5  892c9d7c1a4d00         -mov dword ptr [ebx*4 + 0x4d1a7c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5053052) /* 0x4d1a7c */ + cpu.ebx * 4) = cpu.ebp;
    // 0049ffdc  90                     -nop 
    ;
    // 0049ffdd  8a9f38e54c00           -mov bl, byte ptr [edi + 0x4ce538]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5039416) /* 0x4ce538 */);
    // 0049ffe3  ebed                   -jmp 0x49ffd2
    goto L_0x0049ffd2;
L_0x0049ffe5:
    // 0049ffe5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ffe7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffe8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffe9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ffed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ffee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ffee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ffef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fff0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fff1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fff2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fff4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049fff6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049fff8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fffa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049fffc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049fffe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0000  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a0003  8a9f02010000           -mov bl, byte ptr [edi + 0x102]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(258) /* 0x102 */);
    // 004a0009  8a4e06                 -mov cl, byte ptr [esi + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004a000c  8a5702                 -mov dl, byte ptr [edi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a000f  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a0015  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a001b  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a001e  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0024  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a0027  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a002d  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a002f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0031  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a0034  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0036  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0038  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004a003b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a003d  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004a0040  8a9f06010000           -mov bl, byte ptr [edi + 0x106]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(262) /* 0x106 */);
    // 004a0046  8a4e0e                 -mov cl, byte ptr [esi + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a0049  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a004c  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a0052  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0058  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a005b  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0061  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a0064  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a006a  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a006c  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a006e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a0071  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0073  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0075  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0078  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a007a  8a4612                 -mov al, byte ptr [esi + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004a007d  8a9f0a010000           -mov bl, byte ptr [edi + 0x10a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(266) /* 0x10a */);
    // 004a0083  8a4e16                 -mov cl, byte ptr [esi + 0x16]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 004a0086  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004a0089  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a008f  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0095  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a0098  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a009e  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a00a1  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a00a7  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a00a9  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a00ab  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a00ae  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a00b0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a00b2  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a00b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a00b7  8a461a                 -mov al, byte ptr [esi + 0x1a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004a00ba  8a9f0e010000           -mov bl, byte ptr [edi + 0x10e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(270) /* 0x10e */);
    // 004a00c0  8a4e1e                 -mov cl, byte ptr [esi + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 004a00c3  8a570e                 -mov dl, byte ptr [edi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 004a00c6  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a00cc  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a00d2  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a00d5  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a00db  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a00de  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a00e4  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a00e6  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a00e8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a00eb  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a00ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a00ef  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a00f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a00f4  8a4622                 -mov al, byte ptr [esi + 0x22]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004a00f7  8a9f12010000           -mov bl, byte ptr [edi + 0x112]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(274) /* 0x112 */);
    // 004a00fd  8a4e26                 -mov cl, byte ptr [esi + 0x26]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004a0100  8a5712                 -mov dl, byte ptr [edi + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 004a0103  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a0109  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a010f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a0112  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0118  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a011b  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0121  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0123  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0125  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a0128  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a012a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a012c  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a012f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0131  8a462a                 -mov al, byte ptr [esi + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 004a0134  8a9f16010000           -mov bl, byte ptr [edi + 0x116]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(278) /* 0x116 */);
    // 004a013a  8a4e2e                 -mov cl, byte ptr [esi + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004a013d  8a5716                 -mov dl, byte ptr [edi + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 004a0140  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a0146  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a014c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a014f  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0155  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a0158  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a015e  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0160  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0162  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a0165  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0167  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0169  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a016c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a016e  8a4632                 -mov al, byte ptr [esi + 0x32]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 004a0171  8a9f1a010000           -mov bl, byte ptr [edi + 0x11a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(282) /* 0x11a */);
    // 004a0177  8a4e36                 -mov cl, byte ptr [esi + 0x36]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(54) /* 0x36 */);
    // 004a017a  8a571a                 -mov dl, byte ptr [edi + 0x1a]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 004a017d  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a0183  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0189  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a018c  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a0192  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a0195  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a019b  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a019d  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a019f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a01a2  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01a4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01a6  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a01a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a01ab  8a463a                 -mov al, byte ptr [esi + 0x3a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 004a01ae  8a9f1e010000           -mov bl, byte ptr [edi + 0x11e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(286) /* 0x11e */);
    // 004a01b4  8a4e3e                 -mov cl, byte ptr [esi + 0x3e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 004a01b7  8a571e                 -mov dl, byte ptr [edi + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(30) /* 0x1e */);
    // 004a01ba  8a80cc6a5200           -mov al, byte ptr [eax + 0x526acc]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5401292) /* 0x526acc */);
    // 004a01c0  8a9bcc6a5200           -mov bl, byte ptr [ebx + 0x526acc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5401292) /* 0x526acc */);
    // 004a01c6  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a01c9  8a89cc6a5200           -mov cl, byte ptr [ecx + 0x526acc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5401292) /* 0x526acc */);
    // 004a01cf  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a01d2  8a92cc6a5200           -mov dl, byte ptr [edx + 0x526acc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */);
    // 004a01d8  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a01da  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a01dc  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a01df  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a01e3  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a01e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a01e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a01ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a01f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a01f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a01f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a01f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a01f3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a01f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a01f8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a01fa  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a01fd  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a01ff  e81c55ffff             -call 0x495720
    cpu.esp -= 4;
    sub_495720(app, cpu);
    if (cpu.terminate) return;
    // 004a0204  e83f55ffff             -call 0x495748
    cpu.esp -= 4;
    sub_495748(app, cpu);
    if (cpu.terminate) return;
    // 004a0209  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a020b  7428                   -je 0x4a0235
    if (cpu.flags.zf)
    {
        goto L_0x004a0235;
    }
    // 004a020d  833d78e54c0000         +cmp dword ptr [0x4ce578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5039480) /* 0x4ce578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0214  741f                   -je 0x4a0235
    if (cpu.flags.zf)
    {
        goto L_0x004a0235;
    }
    // 004a0216  ba01120000             -mov edx, 0x1201
    cpu.edx = 4609 /*0x1201*/;
L_0x004a021b:
    // 004a021b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a021d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a021f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0221  e8fa8afaff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 004a0226  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0228  7512                   -jne 0x4a023c
    if (!cpu.flags.zf)
    {
        goto L_0x004a023c;
    }
    // 004a022a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a022c  83c404                 +add esp, 4
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
    // 004a022f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0230  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0231  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0232  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a0235:
    // 004a0235  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 004a023a  ebdf                   -jmp 0x4a021b
    goto L_0x004a021b;
L_0x004a023c:
    // 004a023c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a023e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0242  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a0244  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a0246  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0248  e89389faff             -call 0x448be0
    cpu.esp -= 4;
    sub_448be0(app, cpu);
    if (cpu.terminate) return;
    // 004a024d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a024f  7417                   -je 0x4a0268
    if (cpu.flags.zf)
    {
        goto L_0x004a0268;
    }
    // 004a0251  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0254  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a025a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a025f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0262  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0263  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0264  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0265  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a0268:
    // 004a0268  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a026a  e8d180faff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 004a026f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004a0275  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0277  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a027a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a027b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a027c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a027d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4a0280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0281  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a0283  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a0287  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0288  e863ffffff             -call 0x4a01f0
    cpu.esp -= 4;
    sub_4a01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a028d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a028e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0294(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0294  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0295  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a0297  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a029b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a029c  e84fffffff             -call 0x4a01f0
    cpu.esp -= 4;
    sub_4a01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a02a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02a2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a02a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a02a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a02aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a02ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a02ac  e98f80faff             -jmp 0x448340
    return sub_448340(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a02b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a02b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a02b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a02b6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a02b7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a02ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a02bc  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a02c0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a02c2  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a02c6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a02c8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a02ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a02cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a02cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a02cf  e80c89faff             -call 0x448be0
    cpu.esp -= 4;
    sub_448be0(app, cpu);
    if (cpu.terminate) return;
    // 004a02d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a02d6  7509                   -jne 0x4a02e1
    if (!cpu.flags.zf)
    {
        goto L_0x004a02e1;
    }
L_0x004a02d8:
    // 004a02d8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a02da  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a02dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a02e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a02e1:
    // 004a02e1  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a02e4  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a02e7  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a02eb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a02ed  e83e85faff             -call 0x448830
    cpu.esp -= 4;
    sub_448830(app, cpu);
    if (cpu.terminate) return;
    // 004a02f2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a02f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a02f8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a02fa  74dc                   -je 0x4a02d8
    if (cpu.flags.zf)
    {
        goto L_0x004a02d8;
    }
    // 004a02fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a02fe  75d8                   -jne 0x4a02d8
    if (!cpu.flags.zf)
    {
        goto L_0x004a02d8;
    }
    // 004a0300  85ed                   -test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a0302  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0304  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a0307  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0308  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a030a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a030c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a030c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a030d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a0312  e89dffffff             -call 0x4a02b4
    cpu.esp -= 4;
    sub_4a02b4(app, cpu);
    if (cpu.terminate) return;
    // 004a0317  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0318  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a031c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a031c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a031d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a031f  e890ffffff             -call 0x4a02b4
    cpu.esp -= 4;
    sub_4a02b4(app, cpu);
    if (cpu.terminate) return;
    // 004a0324  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0325  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0328(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0328  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0329  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a032b  e8f081faff             -call 0x448520
    cpu.esp -= 4;
    sub_448520(app, cpu);
    if (cpu.terminate) return;
    // 004a0330  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0332  e83981faff             -call 0x448470
    cpu.esp -= 4;
    sub_448470(app, cpu);
    if (cpu.terminate) return;
    // 004a0337  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0338  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a033c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a033c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a033d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a033f  e8dc81faff             -call 0x448520
    cpu.esp -= 4;
    sub_448520(app, cpu);
    if (cpu.terminate) return;
    // 004a0344  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0346  e82581faff             -call 0x448470
    cpu.esp -= 4;
    sub_448470(app, cpu);
    if (cpu.terminate) return;
    // 004a034b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a034c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0351  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0353  e8c881faff             -call 0x448520
    cpu.esp -= 4;
    sub_448520(app, cpu);
    if (cpu.terminate) return;
    // 004a0358  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a035a  e81181faff             -call 0x448470
    cpu.esp -= 4;
    sub_448470(app, cpu);
    if (cpu.terminate) return;
    // 004a035f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0360  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0371  8d480c                 -lea ecx, [eax + 0xc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a0374  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a0377  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0379  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004a037c  8a482d                 -mov cl, byte ptr [eax + 0x2d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(45) /* 0x2d */);
    // 004a037f  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004a0382  8a482f                 -mov cl, byte ptr [eax + 0x2f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 004a0385  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 004a0388  8a482e                 -mov cl, byte ptr [eax + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004a038b  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 004a038e  668b4032               -mov ax, word ptr [eax + 0x32]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(50) /* 0x32 */);
    // 004a0392  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a0397  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a039a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a039c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a039d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a03a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a03a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a03a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a03a2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a03a4  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a03aa  7445                   -je 0x4a03f1
    if (cpu.flags.zf)
    {
        goto L_0x004a03f1;
    }
    // 004a03ac  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004a03b0  7449                   -je 0x4a03fb
    if (cpu.flags.zf)
    {
        goto L_0x004a03fb;
    }
    // 004a03b2  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a03b5:
    // 004a03b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a03b6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a03b7  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 004a03ba  c6470100               -mov byte ptr [edi + 1], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 004a03be  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 004a03c2  c6470300               -mov byte ptr [edi + 3], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004a03c6  c7470400000000         -mov dword ptr [edi + 4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a03cd  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a03d0  7418                   -je 0x4a03ea
    if (cpu.flags.zf)
    {
        goto L_0x004a03ea;
    }
L_0x004a03d2:
    // 004a03d2  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a03d4  80fffe                 +cmp bh, 0xfe
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a03d7  7411                   -je 0x4a03ea
    if (cpu.flags.zf)
    {
        goto L_0x004a03ea;
    }
    // 004a03d9  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 004a03dc  41                     -inc ecx
    (cpu.ecx)++;
    // 004a03dd  81fefd000000           +cmp esi, 0xfd
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
    // 004a03e3  751b                   -jne 0x4a0400
    if (!cpu.flags.zf)
    {
        goto L_0x004a0400;
    }
L_0x004a03e5:
    // 004a03e5  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a03e8  75e8                   -jne 0x4a03d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a03d2;
    }
L_0x004a03ea:
    // 004a03ea  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a03ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a03f1:
    // 004a03f1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a03f3  e878ffffff             -call 0x4a0370
    cpu.esp -= 4;
    sub_4a0370(app, cpu);
    if (cpu.terminate) return;
    // 004a03f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a03fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a03fb:
    // 004a03fb  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a03fe  ebb5                   -jmp 0x4a03b5
    goto L_0x004a03b5;
L_0x004a0400:
    // 004a0400  81fefc000000           +cmp esi, 0xfc
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
    // 004a0406  74dd                   -je 0x4a03e5
    if (cpu.flags.zf)
    {
        goto L_0x004a03e5;
    }
    // 004a0408  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a040a  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a040c  81fbff000000           +cmp ebx, 0xff
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
    // 004a0412  7512                   -jne 0x4a0426
    if (!cpu.flags.zf)
    {
        goto L_0x004a0426;
    }
    // 004a0414  41                     -inc ecx
    (cpu.ecx)++;
    // 004a0415  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a041a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a041c  e86fc1ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 004a0421  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0423  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a0426:
    // 004a0426  41                     -inc ecx
    (cpu.ecx)++;
    // 004a0427  81fe82000000           +cmp esi, 0x82
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a042d  7313                   -jae 0x4a0442
    if (!cpu.flags.cf)
    {
        goto L_0x004a0442;
    }
    // 004a042f  83fe13                 +cmp esi, 0x13
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0432  7332                   -jae 0x4a0466
    if (!cpu.flags.cf)
    {
        goto L_0x004a0466;
    }
L_0x004a0434:
    // 004a0434  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0436  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a0439  7597                   -jne 0x4a03d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a03d2;
    }
    // 004a043b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a043d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a043e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a043f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0440  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0441  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0442:
    // 004a0442  7667                   -jbe 0x4a04ab
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a04ab;
    }
    // 004a0444  81fe83000000           +cmp esi, 0x83
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a044a  0f8679000000           -jbe 0x4a04c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a04c9;
    }
    // 004a0450  81fe84000000           +cmp esi, 0x84
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0456  75dc                   -jne 0x4a0434
    if (!cpu.flags.zf)
    {
        goto L_0x004a0434;
    }
    // 004a0458  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a045a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a045c  e82fc1ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 004a0461  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0464  ebce                   -jmp 0x4a0434
    goto L_0x004a0434;
L_0x004a0466:
    // 004a0466  7626                   -jbe 0x4a048e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a048e;
    }
    // 004a0468  81fe81000000           +cmp esi, 0x81
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a046e  75c4                   -jne 0x4a0434
    if (!cpu.flags.zf)
    {
        goto L_0x004a0434;
    }
    // 004a0470  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0472  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0474  e817c1ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 004a0479  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a047c  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a047e  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a0481  0f854bffffff           -jne 0x4a03d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a03d2;
    }
    // 004a0487  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0489  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a048a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a048b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a048c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a048d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a048e:
    // 004a048e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0490  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0492  e8f9c0ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 004a0497  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a0499  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a049b  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a049e  0f852effffff           -jne 0x4a03d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a03d2;
    }
    // 004a04a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04ab:
    // 004a04ab  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a04ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a04af  e8dcc0ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 004a04b4  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a04b7  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a04b9  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a04bc  0f8510ffffff           -jne 0x4a03d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a03d2;
    }
    // 004a04c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a04c9:
    // 004a04c9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a04cb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a04cd  e8bec0ffff             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 004a04d2  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a04d5  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a04d7  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a04da  0f85f2feffff           -jne 0x4a03d2
    if (!cpu.flags.zf)
    {
        goto L_0x004a03d2;
    }
    // 004a04e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a04e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a04e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a04f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a04f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a04f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a04f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a04f3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a04f6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a04f8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a04fc  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a0500  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0503  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0507  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a050a  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a050c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a050e  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 004a0514  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a0516  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004a0518  39d3                   +cmp ebx, edx
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
    // 004a051a  7c3c                   -jl 0x4a0558
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a051c  3b1dd0a64c00           +cmp ebx, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0522  7d34                   -jge 0x4a0558
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a0524  3b0dcca64c00           +cmp ecx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a052a  7c2c                   -jl 0x4a0558
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a052c  3b0dd4a64c00           +cmp ecx, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0532  7d24                   -jge 0x4a0558
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a0534  3b35c8a64c00           +cmp esi, dword ptr [0x4ca6c8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a053a  7c1c                   -jl 0x4a0558
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a053c  3b35d0a64c00           +cmp esi, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0542  7d14                   -jge 0x4a0558
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a0544  3b3dcca64c00           +cmp edi, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a054a  7c0c                   -jl 0x4a0558
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0558;
    }
    // 004a054c  3b3dd4a64c00           +cmp edi, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0552  0f8c60010000           -jl 0x4a06b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06b8;
    }
L_0x004a0558:
    // 004a0558  8b15d0a64c00           -mov edx, dword ptr [0x4ca6d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 004a055e  39d3                   +cmp ebx, edx
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
    // 004a0560  7c08                   -jl 0x4a056a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a056a;
    }
    // 004a0562  39d6                   +cmp esi, edx
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
    // 004a0564  0f8d5a010000           -jge 0x4a06c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
L_0x004a056a:
    // 004a056a  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 004a0570  39d3                   +cmp ebx, edx
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
    // 004a0572  7d08                   -jge 0x4a057c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a057c;
    }
    // 004a0574  39d6                   +cmp esi, edx
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
    // 004a0576  0f8c48010000           -jl 0x4a06c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
L_0x004a057c:
    // 004a057c  8b15d4a64c00           -mov edx, dword ptr [0x4ca6d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004a0582  39d1                   +cmp ecx, edx
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
    // 004a0584  7c08                   -jl 0x4a058e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a058e;
    }
    // 004a0586  39d7                   +cmp edi, edx
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
    // 004a0588  0f8d36010000           -jge 0x4a06c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
L_0x004a058e:
    // 004a058e  8b15cca64c00           -mov edx, dword ptr [0x4ca6cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 004a0594  39d1                   +cmp ecx, edx
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
    // 004a0596  7d08                   -jge 0x4a05a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a05a0;
    }
    // 004a0598  39d7                   +cmp edi, edx
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
    // 004a059a  0f8c24010000           -jl 0x4a06c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
L_0x004a05a0:
    // 004a05a0  39f3                   +cmp ebx, esi
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
    // 004a05a2  7e0c                   -jle 0x4a05b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a05b0;
    }
    // 004a05a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a05a6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a05a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a05aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a05ac  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a05ae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a05b0:
    // 004a05b0  8b15c8a64c00           -mov edx, dword ptr [0x4ca6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 004a05b6  39d3                   +cmp ebx, edx
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
    // 004a05b8  7d24                   -jge 0x4a05de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a05de;
    }
    // 004a05ba  39f3                   +cmp ebx, esi
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
    // 004a05bc  7420                   -je 0x4a05de
    if (cpu.flags.zf)
    {
        goto L_0x004a05de;
    }
    // 004a05be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a05c0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a05c2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a05c4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a05c6  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a05c9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a05cb  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a05cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a05cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a05d1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a05d4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a05d6  8b1dc8a64c00           -mov ebx, dword ptr [0x4ca6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 004a05dc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a05de:
    // 004a05de  8b15d0a64c00           -mov edx, dword ptr [0x4ca6d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 004a05e4  39d6                   +cmp esi, edx
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
    // 004a05e6  7c22                   -jl 0x4a060a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a060a;
    }
    // 004a05e8  39f3                   +cmp ebx, esi
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
    // 004a05ea  741e                   -je 0x4a060a
    if (cpu.flags.zf)
    {
        goto L_0x004a060a;
    }
    // 004a05ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a05ee  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a05f0  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a05f2  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a05f4  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a05f7  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a05f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a05fb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a05fe  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0600  8b35d0a64c00           -mov esi, dword ptr [0x4ca6d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 004a0606  8d3c08                 -lea edi, [eax + ecx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004a0609  4e                     -dec esi
    (cpu.esi)--;
L_0x004a060a:
    // 004a060a  39f9                   +cmp ecx, edi
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
    // 004a060c  7e0c                   -jle 0x4a061a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a061a;
    }
    // 004a060e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0610  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a0612  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0614  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0616  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a0618  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a061a:
    // 004a061a  a1cca64c00             -mov eax, dword ptr [0x4ca6cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 004a061f  39c1                   +cmp ecx, eax
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
    // 004a0621  7d22                   -jge 0x4a0645
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0645;
    }
    // 004a0623  39f9                   +cmp ecx, edi
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
    // 004a0625  741e                   -je 0x4a0645
    if (cpu.flags.zf)
    {
        goto L_0x004a0645;
    }
    // 004a0627  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0629  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a062b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a062d  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a0630  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0632  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0634  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0636  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0638  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a063b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a063d  8b0dcca64c00           -mov ecx, dword ptr [0x4ca6cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 004a0643  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0645:
    // 004a0645  8b15d4a64c00           -mov edx, dword ptr [0x4ca6d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004a064b  39d7                   +cmp edi, edx
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
    // 004a064d  7c1e                   -jl 0x4a066d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a066d;
    }
    // 004a064f  39f9                   +cmp ecx, edi
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
    // 004a0651  741a                   -je 0x4a066d
    if (cpu.flags.zf)
    {
        goto L_0x004a066d;
    }
    // 004a0653  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0655  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0657  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a065a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a065c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a065e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0661  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0663  8b3dd4a64c00           -mov edi, dword ptr [0x4ca6d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004a0669  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004a066c  4f                     -dec edi
    (cpu.edi)--;
L_0x004a066d:
    // 004a066d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0671  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 004a0674  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004a0676  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a067a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a067c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a067f  8b2dc8a64c00           -mov ebp, dword ptr [0x4ca6c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 004a0685  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004a0687  39eb                   +cmp ebx, ebp
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
    // 004a0689  7c39                   -jl 0x4a06c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a068b  a1d0a64c00             -mov eax, dword ptr [0x4ca6d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 004a0690  39c3                   +cmp ebx, eax
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
    // 004a0692  7d30                   -jge 0x4a06c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a0694  8b15cca64c00           -mov edx, dword ptr [0x4ca6cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 004a069a  39d1                   +cmp ecx, edx
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
    // 004a069c  7c26                   -jl 0x4a06c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a069e  8b1dd4a64c00           -mov ebx, dword ptr [0x4ca6d4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 004a06a4  39d9                   +cmp ecx, ebx
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
    // 004a06a6  7d1c                   -jge 0x4a06c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a06a8  39ee                   +cmp esi, ebp
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
    // 004a06aa  7c18                   -jl 0x4a06c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a06ac  39c6                   +cmp esi, eax
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
    // 004a06ae  7d14                   -jge 0x4a06c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a06b0  39d7                   +cmp edi, edx
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
    // 004a06b2  7c10                   -jl 0x4a06c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
    // 004a06b4  39df                   +cmp edi, ebx
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
    // 004a06b6  7d0c                   -jge 0x4a06c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a06c4;
    }
L_0x004a06b8:
    // 004a06b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a06bd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a06c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a06c4:
    // 004a06c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a06c6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a06c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a06cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a06d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a06d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a06d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a06d2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a06d5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a06d8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a06da  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a06dc  3b05c8a64c00           +cmp eax, dword ptr [0x4ca6c8]
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
    // 004a06e2  7c5c                   -jl 0x4a0740
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0740;
    }
    // 004a06e4  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
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
    // 004a06ea  7d54                   -jge 0x4a0740
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0740;
    }
    // 004a06ec  3b0dcca64c00           +cmp ecx, dword ptr [0x4ca6cc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a06f2  7c4c                   -jl 0x4a0740
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0740;
    }
    // 004a06f4  3b0dd4a64c00           +cmp ecx, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a06fa  7d44                   -jge 0x4a0740
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0740;
    }
    // 004a06fc  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 004a0701  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a0704  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0706  8b1deca64c00           -mov ebx, dword ptr [0x4ca6ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 004a070c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a070f  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a0711  8b3483                 -mov esi, dword ptr [ebx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 4);
    // 004a0714  a1dca64c00             -mov eax, dword ptr [0x4ca6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023452) /* 0x4ca6dc */);
    // 004a0719  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a071b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a071d  a0d8a64c00             -mov al, byte ptr [0x4ca6d8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 004a0722  3c0f                   +cmp al, 0xf
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
    // 004a0724  7320                   -jae 0x4a0746
    if (!cpu.flags.cf)
    {
        goto L_0x004a0746;
    }
    // 004a0726  3c04                   +cmp al, 4
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
    // 004a0728  7216                   -jb 0x4a0740
    if (cpu.flags.cf)
    {
        goto L_0x004a0740;
    }
    // 004a072a  7733                   -ja 0x4a075f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a075f;
    }
    // 004a072c  f6042401               +test byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 1 /*0x1*/));
    // 004a0730  7435                   -je 0x4a0767
    if (cpu.flags.zf)
    {
        goto L_0x004a0767;
    }
    // 004a0732  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a0734  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a0737  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a0739  c0e004                 -shl al, 4
    cpu.al <<= 4 /*0x4*/ % 32;
    // 004a073c  08c6                   -or dh, al
    cpu.dh |= x86::reg8(x86::sreg8(cpu.al));
    // 004a073e  8831                   -mov byte ptr [ecx], dh
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dh;
L_0x004a0740:
    // 004a0740  83c404                 +add esp, 4
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
    // 004a0743  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0744  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0745  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0746:
    // 004a0746  7608                   -jbe 0x4a0750
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0750;
    }
    // 004a0748  3c18                   +cmp al, 0x18
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
    // 004a074a  7309                   -jae 0x4a0755
    if (!cpu.flags.cf)
    {
        goto L_0x004a0755;
    }
    // 004a074c  3c10                   +cmp al, 0x10
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
    // 004a074e  75f0                   -jne 0x4a0740
    if (!cpu.flags.zf)
    {
        goto L_0x004a0740;
    }
L_0x004a0750:
    // 004a0750  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004a0753  ebeb                   -jmp 0x4a0740
    goto L_0x004a0740;
L_0x004a0755:
    // 004a0755  761e                   -jbe 0x4a0775
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0775;
    }
    // 004a0757  3c20                   +cmp al, 0x20
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
    // 004a0759  75e5                   -jne 0x4a0740
    if (!cpu.flags.zf)
    {
        goto L_0x004a0740;
    }
    // 004a075b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a075d  ebe1                   -jmp 0x4a0740
    goto L_0x004a0740;
L_0x004a075f:
    // 004a075f  3c08                   +cmp al, 8
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
    // 004a0761  75dd                   -jne 0x4a0740
    if (!cpu.flags.zf)
    {
        goto L_0x004a0740;
    }
    // 004a0763  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004a0765  ebd9                   -jmp 0x4a0740
    goto L_0x004a0740;
L_0x004a0767:
    // 004a0767  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a0769  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004a076b  08d0                   -or al, dl
    cpu.al |= x86::reg8(x86::sreg8(cpu.dl));
    // 004a076d  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004a076f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0772  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0773  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0774  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0775:
    // 004a0775  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004a077a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a077c  e86e25feff             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 004a0781  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0784  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0785  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0786  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0787(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0787  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0788  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0789  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a078a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a078c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a078e  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004a0793  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a0795  e8158bfeff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004a079a  eb1f                   -jmp 0x4a07bb
    goto L_0x004a07bb;
L_0x004a079c:
    // 004a079c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a079e  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a07a0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a07a3  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 004a07a6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a07ac  8a928c1d4c00           -mov dl, byte ptr [edx + 0x4c1d8c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4988300) /* 0x4c1d8c */);
    // 004a07b2  8a3406                 -mov dh, byte ptr [esi + eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004a07b5  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004a07b7  41                     -inc ecx
    (cpu.ecx)++;
    // 004a07b8  883406                 -mov byte ptr [esi + eax], dh
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dh;
L_0x004a07bb:
    // 004a07bb  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a07bd  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a07bf  75db                   -jne 0x4a079c
    if (!cpu.flags.zf)
    {
        goto L_0x004a079c;
    }
    // 004a07c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a07c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a07c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a07c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a07c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a07c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a07c7  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004a07cb  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a07cd  e83eb8fdff             -call 0x47c010
    cpu.esp -= 4;
    sub_47c010(app, cpu);
    if (cpu.terminate) return;
    // 004a07d2  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 004a07d4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a07d8  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a07da  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a07db  9b                     -wait 
    /*nothing*/;
    // 004a07dc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a07e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a07e0  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a07e2  e9c5eaffff             -jmp 0x49f2ac
    return sub_49f2ac(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4a07e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a07e8  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a07ea  e9bdeaffff             -jmp 0x49f2ac
    return sub_49f2ac(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4a07f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a07f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a07f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a07f3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a07fa  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a07fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a07fe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0800  e8a7eaffff             -call 0x49f2ac
    cpu.esp -= 4;
    sub_49f2ac(app, cpu);
    if (cpu.terminate) return;
    // 004a0805  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0806  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0808(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0808  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a080b  e99ceaffff             -jmp 0x49f2ac
    return sub_49f2ac(app, cpu);
}

/* align: skip  */
void Application::sub_4a0810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0810  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0811  b97ce54c00             -mov ecx, 0x4ce57c
    cpu.ecx = 5039484 /*0x4ce57c*/;
    // 004a0816  e8c168ffff             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004a081b  0f77                   -emms 
    cpu.mmx.init();
    // 004a081d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a081e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0823  b97ce54c00             -mov ecx, 0x4ce57c
    cpu.ecx = 5039484 /*0x4ce57c*/;
    // 004a0828  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a082b  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a082e  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004a0831  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004a0834  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004a0837  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004a083a  e89d68ffff             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004a083f  0f77                   -emms 
    cpu.mmx.init();
    // 004a0841  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0842  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0843  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0844  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0848(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0848  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0849  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a084c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a084f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0851  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004a0854  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a0857  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0859  b97ce54c00             -mov ecx, 0x4ce57c
    cpu.ecx = 5039484 /*0x4ce57c*/;
    // 004a085e  e87968ffff             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 004a0863  0f77                   -emms 
    cpu.mmx.init();
    // 004a0865  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0866  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0870  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0871  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0872  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0873  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0876  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0878  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a087a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a087c  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 004a0882  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0884  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a0886  7415                   -je 0x4a089d
    if (cpu.flags.zf)
    {
        goto L_0x004a089d;
    }
    // 004a0888  83fd01                 +cmp ebp, 1
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
    // 004a088b  7d04                   -jge 0x4a0891
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0891;
    }
    // 004a088d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a088f  7d13                   -jge 0x4a08a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a08a4;
    }
L_0x004a0891:
    // 004a0891  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004a0896:
    // 004a0896  83c408                 +add esp, 8
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
    // 004a0899  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a089a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a089b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a089c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a089d:
    // 004a089d  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004a08a2  ebf2                   -jmp 0x4a0896
    goto L_0x004a0896;
L_0x004a08a4:
    // 004a08a4  e80785ffff             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 004a08a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a08ab  e80c89ffff             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 004a08b0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a08b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a08b4  0f8ca9000000           -jl 0x4a0963
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0963;
    }
    // 004a08ba  83fb7f                 +cmp ebx, 0x7f
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
    // 004a08bd  0f8fa0000000           -jg 0x4a0963
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0963;
    }
    // 004a08c3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a08c5  0f8c98000000           -jl 0x4a0963
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0963;
    }
    // 004a08cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a08cc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a08cf  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a08d1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a08d4  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 004a08d9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a08db  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 004a08de  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a08e2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a08e4  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a08e8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004a08eb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a08ed  0f8481000000           -je 0x4a0974
    if (cpu.flags.zf)
    {
        goto L_0x004a0974;
    }
    // 004a08f3  bed0a75200             -mov esi, 0x52a7d0
    cpu.esi = 5416912 /*0x52a7d0*/;
    // 004a08f8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a08fc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a08fe:
    // 004a08fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0900  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0904  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 004a0907  39d8                   +cmp eax, ebx
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
    // 004a0909  7540                   -jne 0x4a094b
    if (!cpu.flags.zf)
    {
        goto L_0x004a094b;
    }
    // 004a090b  807e0c01               +cmp byte ptr [esi + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a090f  753a                   -jne 0x4a094b
    if (!cpu.flags.zf)
    {
        goto L_0x004a094b;
    }
    // 004a0911  833e00                 +cmp dword ptr [esi], 0
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
    // 004a0914  7c35                   -jl 0x4a094b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a094b;
    }
    // 004a0916  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 004a0919  8b5035                 -mov edx, dword ptr [eax + 0x35]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */);
    // 004a091c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a091f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a0922  884839                 -mov byte ptr [eax + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */) = cpu.cl;
    // 004a0925  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0929  0faf90c4a75200         -imul edx, dword ptr [eax + 0x52a7c4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416900) /* 0x52a7c4 */))));
    // 004a0930  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 004a0935  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0937  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a093a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a093c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a093e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0940  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a0942  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0944  e883f6fdff             -call 0x47ffcc
    cpu.esp -= 4;
    sub_47ffcc(app, cpu);
    if (cpu.terminate) return;
    // 004a0949  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004a094b:
    // 004a094b  47                     -inc edi
    (cpu.edi)++;
    // 004a094c  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004a094f  83ff10                 +cmp edi, 0x10
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
    // 004a0952  7caa                   -jl 0x4a08fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a08fe;
    }
    // 004a0954  e86b84ffff             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 004a0959  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a095b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a095c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a095f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0960  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0961  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0962  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0963:
    // 004a0963  e85c84ffff             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 004a0968  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004a096d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0970  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0971  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0972  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0973  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0974:
    // 004a0974  884c2839               -mov byte ptr [eax + ebp + 0x39], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(57) /* 0x39 */ + cpu.ebp * 1) = cpu.cl;
    // 004a0978  8b442835               -mov eax, dword ptr [eax + ebp + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(53) /* 0x35 */ + cpu.ebp * 1);
    // 004a097c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a097f  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a0982  8b93c4a75200           -mov edx, dword ptr [ebx + 0x52a7c4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5416900) /* 0x52a7c4 */);
    // 004a0988  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a098b  b9013f0000             -mov ecx, 0x3f01
    cpu.ecx = 16129 /*0x3f01*/;
    // 004a0990  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0992  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a0995  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a0997  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0999  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a099b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a099d  e82af6fdff             -call 0x47ffcc
    cpu.esp -= 4;
    sub_47ffcc(app, cpu);
    if (cpu.terminate) return;
    // 004a09a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a09a4  e81b84ffff             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 004a09a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a09ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a09ac  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a09af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a09b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a09b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a09b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a09c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a09c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a09c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a09c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a09c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a09c5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a09c8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a09ca  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a09cd  05d0a75200             -add eax, 0x52a7d0
    (cpu.eax) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 004a09d2  8b500e                 -mov edx, dword ptr [eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a09d5  668b5842               -mov bx, word ptr [eax + 0x42]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 004a09d9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a09dc  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004a09df  7424                   -je 0x4a0a05
    if (cpu.flags.zf)
    {
        goto L_0x004a0a05;
    }
    // 004a09e1  8b4854                 -mov ecx, dword ptr [eax + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a09e4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a09e6  7446                   -je 0x4a0a2e
    if (cpu.flags.zf)
    {
        goto L_0x004a0a2e;
    }
    // 004a09e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a09ea  8b5854                 -mov ebx, dword ptr [eax + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a09ed  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 004a09f0  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
L_0x004a09f4:
    // 004a09f4  8b5840                 -mov ebx, dword ptr [eax + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004a09f7  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a09fa  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004a09fd  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a0a00  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 004a0a03  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a0a05:
    // 004a0a05  8b585c                 -mov ebx, dword ptr [eax + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004a0a08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0a0a  741a                   -je 0x4a0a26
    if (cpu.flags.zf)
    {
        goto L_0x004a0a26;
    }
    // 004a0a0c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0a0e  8a483f                 -mov cl, byte ptr [eax + 0x3f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(63) /* 0x3f */);
    // 004a0a11  0fbe0c19               -movsx ecx, byte ptr [ecx + ebx]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1)));
    // 004a0a15  8b583e                 -mov ebx, dword ptr [eax + 0x3e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 004a0a18  83e940                 -sub ecx, 0x40
    (cpu.ecx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a0a1b  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004a0a1e  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a0a21  c1f906                 -sar ecx, 6
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (6 /*0x6*/ % 32));
    // 004a0a24  01ca                   +add edx, ecx
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
L_0x004a0a26:
    // 004a0a26  66895012               -mov word ptr [eax + 0x12], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 004a0a2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0a2e:
    // 004a0a2e  8a4833                 -mov cl, byte ptr [eax + 0x33]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(51) /* 0x33 */);
    // 004a0a31  ebc1                   -jmp 0x4a09f4
    goto L_0x004a09f4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0a41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0a42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0a43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0a44  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a0a47  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a0a49  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0a4b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a0a4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0a4f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a0a54  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a0a5a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0a5c  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a0a5f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0a61  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a0a64  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a0a68  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0a6a  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a0a6d  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 004a0a70  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0a74  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a0a77  0fafef                 -imul ebp, edi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a0a7a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0a7c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0a7e  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004a0a81  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a0a87  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a0a89  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a0a8b  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a0a91  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0a93  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0a95  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004a0a98  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004a0a9b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0a9d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0a9f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a0aa2  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004a0aa5  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a0aa8  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0aaa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0aac  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a0aaf  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a0ab1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a0ab3  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a0ab5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0ab7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0abb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0abc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0abd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0abf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a0ac2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ac3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ac4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ac5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ac6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0ac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0ac8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0ac9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0aca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0acb  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0ace  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a0ad0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0ad2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0ad4  7c23                   -jl 0x4a0af9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0af9;
    }
L_0x004a0ad6:
    // 004a0ad6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0ad8  7d05                   -jge 0x4a0adf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0adf;
    }
    // 004a0ada  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a0adc  80f301                 -xor bl, 1
    cpu.bl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004a0adf:
    // 004a0adf  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0ae1  e85affffff             -call 0x4a0a40
    cpu.esp -= 4;
    sub_4a0a40(app, cpu);
    if (cpu.terminate) return;
    // 004a0ae6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0ae8  7518                   -jne 0x4a0b02
    if (!cpu.flags.zf)
    {
        goto L_0x004a0b02;
    }
    // 004a0aea  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0aec  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a0aee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0aef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0af0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0af2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0af5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0af6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0af7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0af8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0af9:
    // 004a0af9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a0afe  f7d8                   +neg eax
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
    // 004a0b00  ebd4                   -jmp 0x4a0ad6
    goto L_0x004a0ad6;
L_0x004a0b02:
    // 004a0b02  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0b06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0b07  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0b0b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0b0c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0b10  e833030000             -call 0x4a0e48
    cpu.esp -= 4;
    sub_4a0e48(app, cpu);
    if (cpu.terminate) return;
    // 004a0b15  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0b17  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a0b19  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0b1a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0b1b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0b1d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0b20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0b24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0b24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0b25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0b26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0b27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0b28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0b29  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0b2d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0b31  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0b35  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004a0b3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a0b3c:
    // 004a0b3c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a0b3e  4b                     -dec ebx
    (cpu.ebx)--;
    // 004a0b3f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0b41  c1ee1f                 -shr esi, 0x1f
    cpu.esi >>= 31 /*0x1f*/ % 32;
    // 004a0b44  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0b46  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a0b48  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0b4a  39f8                   +cmp eax, edi
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
    // 004a0b4c  7203                   -jb 0x4a0b51
    if (cpu.flags.cf)
    {
        goto L_0x004a0b51;
    }
    // 004a0b4e  42                     -inc edx
    (cpu.edx)++;
    // 004a0b4f  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a0b51:
    // 004a0b51  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0b53  75e7                   -jne 0x4a0b3c
    if (!cpu.flags.zf)
    {
        goto L_0x004a0b3c;
    }
    // 004a0b55  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0b57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b5c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0b62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0b63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0b64  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0b68  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0b6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0b6e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0b70  7c28                   -jl 0x4a0b9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0b9a;
    }
L_0x004a0b72:
    // 004a0b72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a0b74  7d05                   -jge 0x4a0b7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0b7b;
    }
    // 004a0b76  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a0b78  80f201                 -xor dl, 1
    cpu.dl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004a0b7b:
    // 004a0b7b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0b7c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0b80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0b81  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0b85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0b86  e899ffffff             -call 0x4a0b24
    cpu.esp -= 4;
    sub_4a0b24(app, cpu);
    if (cpu.terminate) return;
    // 004a0b8b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0b8d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0b8f  7402                   -je 0x4a0b93
    if (cpu.flags.zf)
    {
        goto L_0x004a0b93;
    }
    // 004a0b91  f7d8                   +neg eax
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
L_0x004a0b93:
    // 004a0b93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0b97  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0b9a:
    // 004a0b9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0b9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0b9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0b9d  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0ba1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0ba2  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0ba6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a0bab  e898020000             -call 0x4a0e48
    cpu.esp -= 4;
    sub_4a0e48(app, cpu);
    if (cpu.terminate) return;
    // 004a0bb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0bb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0bb2  ebbe                   -jmp 0x4a0b72
    goto L_0x004a0b72;
}

/* align: skip  */
void Application::sub_4a0bb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0bb6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0bb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0bb8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0bb9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0bba  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a0bbd  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a0bc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0bc2  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a0bc6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0bc7  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a0bcb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0bcc  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0bd0  e84fffffff             -call 0x4a0b24
    cpu.esp -= 4;
    sub_4a0b24(app, cpu);
    if (cpu.terminate) return;
    // 004a0bd5  e866feffff             -call 0x4a0a40
    cpu.esp -= 4;
    sub_4a0a40(app, cpu);
    if (cpu.terminate) return;
    // 004a0bda  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a0bde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0bdf  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a0be3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0be4  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0be8  e85b020000             -call 0x4a0e48
    cpu.esp -= 4;
    sub_4a0e48(app, cpu);
    if (cpu.terminate) return;
    // 004a0bed  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0bf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0bf2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0bf6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0bf7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0bf8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0bf9  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0bfd  e872000000             -call 0x4a0c74
    cpu.esp -= 4;
    sub_4a0c74(app, cpu);
    if (cpu.terminate) return;
    // 004a0c02  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0c06  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a0c09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c0f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0c14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0c14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0c15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0c16  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0c17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0c18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0c19  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0c1a  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a0c1d  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a0c21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0c22  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a0c26  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0c27  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a0c2b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0c2c  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0c30  e82bffffff             -call 0x4a0b60
    cpu.esp -= 4;
    sub_4a0b60(app, cpu);
    if (cpu.terminate) return;
    // 004a0c35  e88efeffff             -call 0x4a0ac8
    cpu.esp -= 4;
    sub_4a0ac8(app, cpu);
    if (cpu.terminate) return;
    // 004a0c3a  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a0c3e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0c3f  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a0c43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0c44  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0c48  e8fb010000             -call 0x4a0e48
    cpu.esp -= 4;
    sub_4a0e48(app, cpu);
    if (cpu.terminate) return;
    // 004a0c4d  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0c51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0c52  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0c56  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0c57  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0c58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0c59  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0c5d  e812000000             -call 0x4a0c74
    cpu.esp -= 4;
    sub_4a0c74(app, cpu);
    if (cpu.terminate) return;
    // 004a0c62  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0c66  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a0c69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0c6f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0c74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0c74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0c75  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0c76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0c77  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0c7a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0c7c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0c80  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004a0c84  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0c88  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a0c8b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a0c8f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0c91  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a0c95  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0c99  3b3424                 +cmp esi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0c9c  7711                   -ja 0x4a0caf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a0caf;
    }
    // 004a0c9e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0ca0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0ca2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0ca3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0ca4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0ca6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0ca9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0caa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cac  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a0caf:
    // 004a0caf  ff442404               -inc dword ptr [esp + 4]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))++;
    // 004a0cb3  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0cb5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0cb7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0cb8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0cb9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0cbb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0cbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0cc1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4a0cc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0cc4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0cc5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0cc6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0cc7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0cca  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0cce  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0cd0  83f820                 +cmp eax, 0x20
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
    // 004a0cd3  7d46                   -jge 0x4a0d1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0d1b;
    }
    // 004a0cd5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0cd7  7458                   -je 0x4a0d31
    if (cpu.flags.zf)
    {
        goto L_0x004a0d31;
    }
    // 004a0cd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0cda  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0cde  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0ce0  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004a0ce2  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a0ce6  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0cea  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004a0cec  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a0cf1  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0cf3  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0cf7  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a0cf9  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0cfb  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a0cff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a0d00:
    // 004a0d00  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0d04  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004a0d06:
    // 004a0d06  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d07  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d08  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0d0c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0d0e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d0f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0d12  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0d15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d18  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0d1b:
    // 004a0d1b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d1d  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0d20  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d23  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0d25  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0d29  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a0d2b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0d2f  ebcf                   -jmp 0x4a0d00
    goto L_0x004a0d00;
L_0x004a0d31:
    // 004a0d31  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0d35  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0d39  ebcb                   -jmp 0x4a0d06
    goto L_0x004a0d06;
}

/* align: skip 0x90 */
void Application::sub_4a0d3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0d3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0d3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0d3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d3f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0d42  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0d46  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0d48  83f820                 +cmp eax, 0x20
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
    // 004a0d4b  7d4a                   -jge 0x4a0d97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0d97;
    }
    // 004a0d4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0d4f  745c                   -je 0x4a0dad
    if (cpu.flags.zf)
    {
        goto L_0x004a0dad;
    }
    // 004a0d51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0d52  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a0d57  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0d5b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0d5d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0d61  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004a0d63  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0d65  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004a0d67  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a0d69  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0d6b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a0d6f  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0d71  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0d75  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a0d77  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a0d7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a0d7c:
    // 004a0d7c  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0d80  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x004a0d82:
    // 004a0d82  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d83  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d84  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0d88  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0d8a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d8b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0d8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0d8e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0d91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d92  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d94  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0d97:
    // 004a0d97  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0d9a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0d9c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0da0  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a0da2  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a0da4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a0da7  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a0dab  ebcf                   -jmp 0x4a0d7c
    goto L_0x004a0d7c;
L_0x004a0dad:
    // 004a0dad  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0db1  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0db5  ebcb                   -jmp 0x4a0d82
    goto L_0x004a0d82;
}

/* align: skip 0x90 */
void Application::sub_4a0db8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0db8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0db9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0dba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0dbb  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0dbe  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0dc2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0dc4  83f820                 +cmp eax, 0x20
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
    // 004a0dc7  7d48                   -jge 0x4a0e11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0e11;
    }
    // 004a0dc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0dcb  7460                   -je 0x4a0e2d
    if (cpu.flags.zf)
    {
        goto L_0x004a0e2d;
    }
    // 004a0dcd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0dce  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a0dd3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0dd7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0dd9  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0ddd  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004a0ddf  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0de1  d3ee                   -shr esi, cl
    cpu.esi >>= cpu.cl % 32;
    // 004a0de3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a0de5  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a0de7  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a0deb  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0ded  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a0df1  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a0df3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a0df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a0df8:
    // 004a0df8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a0dfa  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0dfe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0dff  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e00  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0e02  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0e04  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e05  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0e08  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0e0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e0e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a0e11:
    // 004a0e11  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0e14  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a0e16  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0e1a  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a0e1c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a0e20  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0e24  c1f81f                 +sar eax, 0x1f
    {
        x86::reg8 tmp = 31 /*0x1f*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a0e27  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a0e2b  ebcb                   -jmp 0x4a0df8
    goto L_0x004a0df8;
L_0x004a0e2d:
    // 004a0e2d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a0e2f  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0e33  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e34  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e35  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0e37  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0e39  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e3a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0e3d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0e40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e43  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0e48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0e48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0e49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0e4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0e4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0e4c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0e4d  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0e50  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0e52  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a0e56  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0e58  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a0e5b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a0e5d  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a0e61  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0e64  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0e66  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0e6a  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 004a0e6c  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a0e6f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a0e73  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a0e76  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e78  7413                   -je 0x4a0e8d
    if (cpu.flags.zf)
    {
        goto L_0x004a0e8d;
    }
    // 004a0e7a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0e7c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0e7e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e7f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e80  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0e82  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0e85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e8a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a0e8d:
    // 004a0e8d  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a0e90  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a0e94  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0e96  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0e98  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e99  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0e9a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0e9c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0e9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ea0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ea1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ea2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ea3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ea4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0ea8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0ea9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0eaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0eab  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0eae  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a0eb0  83fa20                 +cmp edx, 0x20
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
    // 004a0eb3  7d29                   -jge 0x4a0ede
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0ede;
    }
    // 004a0eb5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0eb7  7433                   -je 0x4a0eec
    if (cpu.flags.zf)
    {
        goto L_0x004a0eec;
    }
    // 004a0eb9  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004a0ebb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0ebd  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a0ebf  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a0ec4  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0ec6  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a0ec8  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004a0ecb:
    // 004a0ecb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0ecf  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0ed1  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0ed3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0ed4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0ed5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0ed7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0eda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0edb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0edc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0edd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0ede:
    // 004a0ede  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0ee0  83ea20                 -sub edx, 0x20
    (cpu.edx) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a0ee3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0ee6  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004a0ee8  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a0eea  ebdf                   -jmp 0x4a0ecb
    goto L_0x004a0ecb;
L_0x004a0eec:
    // 004a0eec  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a0eef  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004a0ef2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a0ef6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004a0ef8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0efa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0efb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0efc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0efe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0f01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0f09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0f0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0f0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0f0c  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0f0f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0f11  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0f13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0f14  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0f18  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004a0f1d  e886ffffff             -call 0x4a0ea8
    cpu.esp -= 4;
    sub_4a0ea8(app, cpu);
    if (cpu.terminate) return;
    // 004a0f22  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0f26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0f27  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0f2b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0f2c  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004a0f31  e8defcffff             -call 0x4a0c14
    cpu.esp -= 4;
    sub_4a0c14(app, cpu);
    if (cpu.terminate) return;
    // 004a0f36  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a0f3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0f3b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a0f3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0f3f  e864ffffff             -call 0x4a0ea8
    cpu.esp -= 4;
    sub_4a0ea8(app, cpu);
    if (cpu.terminate) return;
    // 004a0f44  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a0f48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0f49  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a0f4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0f4e  e80dfcffff             -call 0x4a0b60
    cpu.esp -= 4;
    sub_4a0b60(app, cpu);
    if (cpu.terminate) return;
    // 004a0f53  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a0f56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0f61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0f62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0f63  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0f66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0f68  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0f6a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0f6c  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0f70  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a0f72  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a0f75  83e13f                 -and ecx, 0x3f
    cpu.ecx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a0f78  e853e3feff             -call 0x48f2d0
    cpu.esp -= 4;
    sub_48f2d0(app, cpu);
    if (cpu.terminate) return;
    // 004a0f7d  69c17e480600           -imul eax, ecx, 0x6487e
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 004a0f83  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0f87  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 004a0f8a  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004a0f8d  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a0f90  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0f93  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 004a0f96  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0f98  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004a0f9a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0f9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0f9f  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 004a0fa2  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a0fa5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a0fa9  c1f915                 -sar ecx, 0x15
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (21 /*0x15*/ % 32));
    // 004a0fac  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0fae  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a0fb0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0fb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0fc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0fc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0fc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0fc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0fc4  81ec44050000           -sub esp, 0x544
    (cpu.esp) -= x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 004a0fca  899424c4040000         -mov dword ptr [esp + 0x4c4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */) = cpu.edx;
    // 004a0fd1  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 004a0fd8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0fda  899424cc040000         -mov dword ptr [esp + 0x4cc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.edx;
    // 004a0fe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0fe3  0f8437120000           -je 0x4a2220
    if (cpu.flags.zf)
    {
        goto L_0x004a2220;
    }
    // 004a0fe9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0feb  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a0fed  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a0ff0  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a0ff3  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0ff5  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a0ff8  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a0fff  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a1001  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1003  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004a100a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a100c  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1013  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a1015  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1018  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a101f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1021  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a1024  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a102b  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1032  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1034  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1037  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a103a  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1041  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004a1044  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1047  89b424c8040000         -mov dword ptr [esp + 0x4c8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */) = cpu.esi;
    // 004a104e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1050  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1057  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004a105e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a1060  8aa424c9040000         -mov ah, byte ptr [esp + 0x4c9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 004a1067  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a106a  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004a106d  0f85e8010000           -jne 0x4a125b
    if (!cpu.flags.zf)
    {
        goto L_0x004a125b;
    }
L_0x004a1073:
    // 004a1073  8a9424c9040000         -mov dl, byte ptr [esp + 0x4c9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */);
    // 004a107a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a107c  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a107f  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a1082  c1ed18                 -shr ebp, 0x18
    cpu.ebp >>= 24 /*0x18*/ % 32;
    // 004a1085  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a1088  889424c9040000         -mov byte ptr [esp + 0x4c9], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1225) /* 0x4c9 */) = cpu.dl;
    // 004a108f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1091  0f8c39020000           -jl 0x4a12d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a12d0;
    }
L_0x004a1097:
    // 004a1097  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1099  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a109c  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a109f  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a10a2  898424cc040000         -mov dword ptr [esp + 0x4cc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.eax;
    // 004a10a9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a10ab  0f8c7d020000           -jl 0x4a132e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a132e;
    }
L_0x004a10b1:
    // 004a10b1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a10b3  8b8c24cc040000         -mov ecx, dword ptr [esp + 0x4cc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004a10ba  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a10bd  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a10bf  898c24cc040000         -mov dword ptr [esp + 0x4cc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */) = cpu.ecx;
    // 004a10c6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a10c8  0f85be020000           -jne 0x4a138c
    if (!cpu.flags.zf)
    {
        goto L_0x004a138c;
    }
L_0x004a10ce:
    // 004a10ce  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004a10d5  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004a10dc  89842400050000         -mov dword ptr [esp + 0x500], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */) = cpu.eax;
L_0x004a10e3:
    // 004a10e3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a10e5  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004a10e8  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 004a10eb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a10f0  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a10f2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a10f4  0f8cce000000           -jl 0x4a11c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a11c8;
    }
L_0x004a10fa:
    // 004a10fa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a10fc  8b8c2400050000         -mov ecx, dword ptr [esp + 0x500]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 004a1103  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004a1106  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1108  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004a110a  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a110c  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a1113  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1115  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 004a1117  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1119  8bac24d4040000         -mov ebp, dword ptr [esp + 0x4d4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a1120  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004a1123  45                     -inc ebp
    (cpu.ebp)++;
    // 004a1124  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004a1127  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004a112e  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004a1130  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1135  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1137  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1139  0f8c89000000           -jl 0x4a11c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a11c8;
    }
    // 004a113f  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 004a1146  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1148  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a114a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a114c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a114e  45                     -inc ebp
    (cpu.ebp)++;
    // 004a114f  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004a1152  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004a1155  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004a1158  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004a115f  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004a1161  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1166  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1168  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a116a  7c5c                   -jl 0x4a11c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a11c8;
    }
    // 004a116c  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 004a1173  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1175  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1177  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1179  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a117b  45                     -inc ebp
    (cpu.ebp)++;
    // 004a117c  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 004a117f  8865ff                 -mov byte ptr [ebp - 1], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 004a1182  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004a1185  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004a118c  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004a118e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a1193  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1195  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1197  7c2f                   -jl 0x4a11c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a11c8;
    }
    // 004a1199  03942400050000         -add edx, dword ptr [esp + 0x500]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */)));
    // 004a11a0  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004a11a2  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a11a4  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a11a6  886500                 -mov byte ptr [ebp], ah
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.ah;
    // 004a11a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a11ab  45                     -inc ebp
    (cpu.ebp)++;
    // 004a11ac  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004a11af  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004a11b6  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 004a11b9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a11be  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a11c0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a11c2  0f8d32ffffff           -jge 0x4a10fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a10fa;
    }
L_0x004a11c8:
    // 004a11c8  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a11cb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a11cd  0f8c420b0000           -jl 0x4a1d15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1d15;
    }
    // 004a11d3  8b842400050000         -mov eax, dword ptr [esp + 0x500]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1280) /* 0x500 */);
    // 004a11da  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004a11dd  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a11e4  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004a11e7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a11e9  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a11f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a11f2  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004a11f4  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a11fb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a11fe  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1200  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004a1207  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a120e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1210  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1213  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a121a  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a121f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1222  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a1224  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1226  8b8424d4040000         -mov eax, dword ptr [esp + 0x4d4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a122d  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a1234  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a123b  40                     -inc eax
    (cpu.eax)++;
    // 004a123c  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1243  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 004a124a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a124d  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a124f  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 004a1256  e988feffff             -jmp 0x4a10e3
    goto L_0x004a10e3;
L_0x004a125b:
    // 004a125b  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1262  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1264  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1267  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1269  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a126b  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a1272  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1274  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1277  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a127a  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a127c  8d7102                 -lea esi, [ecx + 2]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a127f  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004a1286  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1288  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a128b  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a128d  89b42430050000         -mov dword ptr [esp + 0x530], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.esi;
    // 004a1294  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1296  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004a1298  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a129f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a12a2  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a12a9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a12ab  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a12ae  8a5601                 -mov dl, byte ptr [esi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a12b1  89bc2430050000         -mov dword ptr [esp + 0x530], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edi;
    // 004a12b8  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a12ba  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004a12bf  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a12c1  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a12c8  c1e608                 +shl esi, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a12cb  e9a3fdffff             -jmp 0x4a1073
    goto L_0x004a1073;
L_0x004a12d0:
    // 004a12d0  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a12d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a12d9  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a12db  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a12e2  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a12e5  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a12e7  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a12ee  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a12f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a12f7  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a12f9  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a12fc  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1303  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1305  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1308  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a130b  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a130d  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1314  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a131b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a131d  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1320  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1322  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004a1329  e969fdffff             -jmp 0x4a1097
    goto L_0x004a1097;
L_0x004a132e:
    // 004a132e  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1335  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1337  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a1339  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1340  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1343  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1345  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a134c  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1353  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1355  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1357  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a135a  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1361  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1363  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1366  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1369  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a136b  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1372  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004a1379  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a137b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a137e  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1380  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 004a1387  e925fdffff             -jmp 0x4a10b1
    goto L_0x004a10b1;
L_0x004a138c:
    // 004a138c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a138e  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a1391  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004a1394  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a1397  88842440050000         -mov byte ptr [esp + 0x540], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */) = cpu.al;
    // 004a139e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a13a0  0f8ce4030000           -jl 0x4a178a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a178a;
    }
L_0x004a13a6:
    // 004a13a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a13ab  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004a13b0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a13b2  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004a13b7  89ac24e4040000         -mov dword ptr [esp + 0x4e4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebp;
    // 004a13be  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 004a13c5  89942418050000         -mov dword ptr [esp + 0x518], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.edx;
    // 004a13cc  898c241c050000         -mov dword ptr [esp + 0x51c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ecx;
L_0x004a13d3:
    // 004a13d3  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a13d5  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004a13dc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a13de  8b94241c050000         -mov edx, dword ptr [esp + 0x51c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004a13e5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a13e7  89841480040000         -mov dword ptr [esp + edx + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.edx * 1) = cpu.eax;
    // 004a13ee  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a13f0  0f8cf2030000           -jl 0x4a17e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a17e8;
    }
    // 004a13f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a13f8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a13fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a13fd  0f84be040000           -je 0x4a18c1
    if (cpu.flags.zf)
    {
        goto L_0x004a18c1;
    }
    // 004a1403  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004a1408:
    // 004a1408  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a140a  40                     -inc eax
    (cpu.eax)++;
    // 004a140b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a140d  7df9                   -jge 0x4a1408
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1408;
    }
    // 004a140f  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a1412  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1414  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1416  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1418  0f8c40040000           -jl 0x4a185e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a185e;
    }
L_0x004a141e:
    // 004a141e  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1425  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1428  89942410050000         -mov dword ptr [esp + 0x510], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */) = cpu.edx;
    // 004a142f  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1436  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1439  89942428050000         -mov dword ptr [esp + 0x528], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */) = cpu.edx;
    // 004a1440  83f810                 +cmp eax, 0x10
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
    // 004a1443  0f8ec5050000           -jle 0x4a1a0e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1a0e;
    }
    // 004a1449  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a144e  8d58f0                 -lea ebx, [eax - 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004a1451  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1453  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1455  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004a1457  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a1459  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a145b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a145d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a145f  0f8cd9040000           -jl 0x4a193e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a193e;
    }
L_0x004a1465:
    // 004a1465  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a1467  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a146a  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004a146d  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a1470  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1472  0f8c1e050000           -jl 0x4a1996
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1996;
    }
L_0x004a1478:
    // 004a1478  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a147b  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a147d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1482  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a1484:
    // 004a1484  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a1486  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a1488:
    // 004a1488  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a148b  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004a1492  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004a1499  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a149b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a149d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a149f  89940400040000         -mov dword ptr [esp + eax + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1) = cpu.edx;
    // 004a14a6  899c24e4040000         -mov dword ptr [esp + 0x4e4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */) = cpu.ebx;
    // 004a14ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a14af  7413                   -je 0x4a14c4
    if (cpu.flags.zf)
    {
        goto L_0x004a14c4;
    }
    // 004a14b1  8a8c2418050000         -mov cl, byte ptr [esp + 0x518]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 004a14b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a14ba  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a14bc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a14be  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x004a14c4:
    // 004a14c4  8b84241c050000         -mov eax, dword ptr [esp + 0x51c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004a14cb  898c0440040000         -mov dword ptr [esp + eax + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 1) = cpu.ecx;
    // 004a14d2  8b842418050000         -mov eax, dword ptr [esp + 0x518]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 004a14d9  48                     -dec eax
    (cpu.eax)--;
    // 004a14da  8b9c241c050000         -mov ebx, dword ptr [esp + 0x51c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */);
    // 004a14e1  89842418050000         -mov dword ptr [esp + 0x518], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1304) /* 0x518 */) = cpu.eax;
    // 004a14e8  8b8424d8040000         -mov eax, dword ptr [esp + 0x4d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */);
    // 004a14ef  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a14f2  40                     -inc eax
    (cpu.eax)++;
    // 004a14f3  899c241c050000         -mov dword ptr [esp + 0x51c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1308) /* 0x51c */) = cpu.ebx;
    // 004a14fa  898424d8040000         -mov dword ptr [esp + 0x4d8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1240) /* 0x4d8 */) = cpu.eax;
    // 004a1501  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1503  0f84cafeffff           -je 0x4a13d3
    if (cpu.flags.zf)
    {
        goto L_0x004a13d3;
    }
    // 004a1509  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a150b  0f85c2feffff           -jne 0x4a13d3
    if (!cpu.flags.zf)
    {
        goto L_0x004a13d3;
    }
    // 004a1511  48                     -dec eax
    (cpu.eax)--;
    // 004a1512  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a1517  898424dc040000         -mov dword ptr [esp + 0x4dc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */) = cpu.eax;
    // 004a151e  89948440040000         -mov dword ptr [esp + eax*4 + 0x440], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1088) /* 0x440 */ + cpu.eax * 4) = cpu.edx;
    // 004a1525  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004a152a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004a152c:
    // 004a152c  83c010                 +add eax, 0x10
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a152f  8948f0                 -mov dword ptr [eax - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 004a1532  8948f4                 -mov dword ptr [eax - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004a1535  8948f8                 -mov dword ptr [eax - 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 004a1538  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004a153b  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a153c  75ee                   -jne 0x4a152c
    if (!cpu.flags.zf)
    {
        goto L_0x004a152c;
    }
    // 004a153e  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004a1540  8b9c24e4040000         -mov ebx, dword ptr [esp + 0x4e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004a1547  899424e0040000         -mov dword ptr [esp + 0x4e0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.edx;
    // 004a154e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a1550  0f8efc000000           -jle 0x4a1652
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1652;
    }
L_0x004a1556:
    // 004a1556  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a1558  0f8c30050000           -jl 0x4a1a8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1a8e;
    }
    // 004a155e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1560  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a1563  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1565  0f84f7050000           -je 0x4a1b62
    if (cpu.flags.zf)
    {
        goto L_0x004a1b62;
    }
    // 004a156b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x004a1570:
    // 004a1570  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1572  42                     -inc edx
    (cpu.edx)++;
    // 004a1573  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a1575  7df9                   -jge 0x4a1570
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1570;
    }
    // 004a1577  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a157a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a157c  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a157e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1580  0f8c7e050000           -jl 0x4a1b04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1b04;
    }
L_0x004a1586:
    // 004a1586  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a158d  8bac2434050000         -mov ebp, dword ptr [esp + 0x534]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1594  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1597  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 004a159a  898c242c050000         -mov dword ptr [esp + 0x52c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */) = cpu.ecx;
    // 004a15a1  83fa10                 +cmp edx, 0x10
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
    // 004a15a4  0f8ecf060000           -jle 0x4a1c79
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1c79;
    }
    // 004a15aa  8d4af0                 -lea ecx, [edx - 0x10]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-16) /* -0x10 */);
    // 004a15ad  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004a15b4  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a15b9  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004a15c0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a15c2  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004a15c4  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004a15cb  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a15cd  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004a15d4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a15d6  0f8c03060000           -jl 0x4a1bdf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1bdf;
    }
L_0x004a15dc:
    // 004a15dc  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a15de  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a15e1  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a15e4  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a15e7  898c24e8040000         -mov dword ptr [esp + 0x4e8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */) = cpu.ecx;
    // 004a15ee  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a15f0  0f8c29060000           -jl 0x4a1c1f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1c1f;
    }
L_0x004a15f6:
    // 004a15f6  8b8c24e8040000         -mov ecx, dword ptr [esp + 0x4e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1256) /* 0x4e8 */);
    // 004a15fd  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004a1600  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a1602:
    // 004a1602  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004a1604  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a1609  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004a160b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004a160d:
    // 004a160d  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1610  43                     -inc ebx
    (cpu.ebx)++;
    // 004a1611  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004a1613:
    // 004a1613  fec0                   -inc al
    (cpu.al)++;
    // 004a1615  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1617  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004a1619  3a0c14                 +cmp cl, byte ptr [esp + edx]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a161c  7501                   -jne 0x4a161f
    if (!cpu.flags.zf)
    {
        goto L_0x004a161f;
    }
    // 004a161e  4b                     -dec ebx
    (cpu.ebx)--;
L_0x004a161f:
    // 004a161f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a1621  75f0                   -jne 0x4a1613
    if (!cpu.flags.zf)
    {
        goto L_0x004a1613;
    }
    // 004a1623  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1625  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004a1627  c6041401               -mov byte ptr [esp + edx], 1
    app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1) = 1 /*0x1*/;
    // 004a162b  8b9424e0040000         -mov edx, dword ptr [esp + 0x4e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */);
    // 004a1632  8b8c24e4040000         -mov ecx, dword ptr [esp + 0x4e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1252) /* 0x4e4 */);
    // 004a1639  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a163c  88841400030000         -mov byte ptr [esp + edx + 0x300], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.edx * 1) = cpu.al;
    // 004a1643  89ac24e0040000         -mov dword ptr [esp + 0x4e0], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1248) /* 0x4e0 */) = cpu.ebp;
    // 004a164a  39cd                   +cmp ebp, ecx
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
    // 004a164c  0f8c04ffffff           -jl 0x4a1556
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1556;
    }
L_0x004a1652:
    // 004a1652  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a1657  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004a165e  bb40404040             -mov ebx, 0x40404040
    cpu.ebx = 1077952576 /*0x40404040*/;
L_0x004a1663:
    // 004a1663  83c210                 +add edx, 0x10
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1666  895af0                 -mov dword ptr [edx - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004a1669  895af4                 -mov dword ptr [edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004a166c  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004a166f  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a1672  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a1673  75ee                   -jne 0x4a1663
    if (!cpu.flags.zf)
    {
        goto L_0x004a1663;
    }
    // 004a1675  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a167c  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004a1683  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004a168a  898424fc040000         -mov dword ptr [esp + 0x4fc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.eax;
    // 004a1691  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1696  8b8c24dc040000         -mov ecx, dword ptr [esp + 0x4dc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 004a169d  898424ec040000         -mov dword ptr [esp + 0x4ec], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.eax;
    // 004a16a4  39c1                   +cmp ecx, eax
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
    // 004a16a6  0f8c22faffff           -jl 0x4a10ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a10ce;
    }
    // 004a16ac  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a16b1  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004a16b6  89842420050000         -mov dword ptr [esp + 0x520], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.eax;
    // 004a16bd  898c2424050000         -mov dword ptr [esp + 0x524], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.ecx;
L_0x004a16c4:
    // 004a16c4  8b842420050000         -mov eax, dword ptr [esp + 0x520]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 004a16cb  8b840400040000         -mov eax, dword ptr [esp + eax + 0x400]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */ + cpu.eax * 1);
    // 004a16d2  8bac24ec040000         -mov ebp, dword ptr [esp + 0x4ec]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004a16d9  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 004a16e0  83fd09                 +cmp ebp, 9
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
    // 004a16e3  0f8de5f9ffff           -jge 0x4a10ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a10ce;
    }
    // 004a16e9  8a8c2424050000         -mov cl, byte ptr [esp + 0x524]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 004a16f0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a16f5  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
L_0x004a16f7:
    // 004a16f7  8b8424f0040000         -mov eax, dword ptr [esp + 0x4f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */);
    // 004a16fe  48                     -dec eax
    (cpu.eax)--;
    // 004a16ff  898424f0040000         -mov dword ptr [esp + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 004a1706  83f8ff                 +cmp eax, -1
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
    // 004a1709  0f84c3050000           -je 0x4a1cd2
    if (cpu.flags.zf)
    {
        goto L_0x004a1cd2;
    }
    // 004a170f  8b8c24fc040000         -mov ecx, dword ptr [esp + 0x4fc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */);
    // 004a1716  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1718  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a171a  41                     -inc ecx
    (cpu.ecx)++;
    // 004a171b  898424f4040000         -mov dword ptr [esp + 0x4f4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */) = cpu.eax;
    // 004a1722  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004a1729  898c24fc040000         -mov dword ptr [esp + 0x4fc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1276) /* 0x4fc */) = cpu.ecx;
    // 004a1730  898424f8040000         -mov dword ptr [esp + 0x4f8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = cpu.eax;
    // 004a1737  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1739  8b8c24f4040000         -mov ecx, dword ptr [esp + 0x4f4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 004a1740  8a842440050000         -mov al, byte ptr [esp + 0x540]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 004a1747  39c8                   +cmp eax, ecx
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
    // 004a1749  7519                   -jne 0x4a1764
    if (!cpu.flags.zf)
    {
        goto L_0x004a1764;
    }
    // 004a174b  8b8424ec040000         -mov eax, dword ptr [esp + 0x4ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004a1752  898424d0040000         -mov dword ptr [esp + 0x4d0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */) = cpu.eax;
    // 004a1759  c78424f804000060000000 -mov dword ptr [esp + 0x4f8], 0x60
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1272) /* 0x4f8 */) = 96 /*0x60*/;
L_0x004a1764:
    // 004a1764  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1766  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a1768  7e8d                   -jle 0x4a16f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a16f7;
    }
L_0x004a176a:
    // 004a176a  43                     -inc ebx
    (cpu.ebx)++;
    // 004a176b  8a8c24f4040000         -mov cl, byte ptr [esp + 0x4f4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1268) /* 0x4f4 */);
    // 004a1772  42                     -inc edx
    (cpu.edx)++;
    // 004a1773  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a1776  8a8c24f8040000         -mov cl, byte ptr [esp + 0x4f8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1272) /* 0x4f8 */);
    // 004a177d  40                     -inc eax
    (cpu.eax)++;
    // 004a177e  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a1781  39e8                   +cmp eax, ebp
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
    // 004a1783  7ce5                   -jl 0x4a176a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a176a;
    }
    // 004a1785  e96dffffff             -jmp 0x4a16f7
    goto L_0x004a16f7;
L_0x004a178a:
    // 004a178a  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1791  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1793  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a1795  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a179c  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a17a3  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a17a6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a17a8  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a17aa  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a17b1  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a17b8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a17ba  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a17bc  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a17bf  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a17c6  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a17c9  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a17cc  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a17cf  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a17d1  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 004a17d8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a17da  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a17e1  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a17e3  e9befbffff             -jmp 0x4a13a6
    goto L_0x004a13a6;
L_0x004a17e8:
    // 004a17e8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a17ea  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a17ed  c1ea1d                 -shr edx, 0x1d
    cpu.edx >>= 29 /*0x1d*/ % 32;
    // 004a17f0  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004a17f3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a17f5  0f8d8dfcffff           -jge 0x4a1488
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1488;
    }
    // 004a17fb  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1802  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1804  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a1806  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a180d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1810  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1812  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1819  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1820  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1822  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1825  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a182c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a182f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1831  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1838  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a183f  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1846  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1848  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a184b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a184d  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004a1854  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1857  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1859  e92afcffff             -jmp 0x4a1488
    goto L_0x004a1488;
L_0x004a185e:
    // 004a185e  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1865  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1867  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1869  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1870  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1873  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1875  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a187c  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1883  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1885  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1888  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a188f  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1896  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1899  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a189c  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a189e  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 004a18a5  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a18ac  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a18ae  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a18b5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a18b7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a18ba  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a18bc  e95dfbffff             -jmp 0x4a141e
    goto L_0x004a141e;
L_0x004a18c1:
    // 004a18c1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004a18c6:
    // 004a18c6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a18c8  40                     -inc eax
    (cpu.eax)++;
    // 004a18c9  4f                     -dec edi
    (cpu.edi)--;
    // 004a18ca  c1ea1f                 -shr edx, 0x1f
    cpu.edx >>= 31 /*0x1f*/ % 32;
    // 004a18cd  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a18cf  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a18d1  7c09                   -jl 0x4a18dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a18dc;
    }
    // 004a18d3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a18d5  74ef                   -je 0x4a18c6
    if (cpu.flags.zf)
    {
        goto L_0x004a18c6;
    }
    // 004a18d7  e942fbffff             -jmp 0x4a141e
    goto L_0x004a141e;
L_0x004a18dc:
    // 004a18dc  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a18e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a18e5  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a18e7  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a18ee  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a18f1  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a18f3  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a18fa  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1901  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1903  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a1906  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a190d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1910  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1912  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1914  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a1916  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1918  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a191a  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1921  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1928  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a192b  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a192e  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1935  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1937  748d                   -je 0x4a18c6
    if (cpu.flags.zf)
    {
        goto L_0x004a18c6;
    }
    // 004a1939  e9e0faffff             -jmp 0x4a141e
    goto L_0x004a141e;
L_0x004a193e:
    // 004a193e  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1945  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1947  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a1949  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 004a1950  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1952  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1959  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1960  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1962  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a1965  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a196c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a196f  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1971  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1973  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a1975  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1977  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a197e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1980  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 004a1987  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a198a  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1991  e9cffaffff             -jmp 0x4a1465
    goto L_0x004a1465;
L_0x004a1996:
    // 004a1996  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a199d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a199f  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a19a1  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004a19a8  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a19af  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004a19b6  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a19b9  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a19bb  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a19c2  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a19c9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a19cb  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a19ce  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004a19d5  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a19dc  8bb4240c050000         -mov esi, dword ptr [esp + 0x50c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004a19e3  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a19e6  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a19e8  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a19ea  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a19ec  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a19f3  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a19f5  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a19fc  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a19ff  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1a02  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1a09  e96afaffff             -jmp 0x4a1478
    goto L_0x004a1478;
L_0x004a1a0e:
    // 004a1a0e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a1a13  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1a15  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1a17  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004a1a19  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1a1b  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1a1d  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1a1f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1a21  7c0c                   -jl 0x4a1a2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1a2f;
    }
    // 004a1a23  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1a25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1a2a  e955faffff             -jmp 0x4a1484
    goto L_0x004a1484;
L_0x004a1a2f:
    // 004a1a2f  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1a36  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1a38  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a1a3a  8b9c2410050000         -mov ebx, dword ptr [esp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1296) /* 0x510 */);
    // 004a1a41  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1a43  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1a4a  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1a51  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1a53  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a1a56  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1a5d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1a60  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1a62  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1a64  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a1a66  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1a68  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1a6f  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1a71  8b8c2428050000         -mov ecx, dword ptr [esp + 0x528]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1320) /* 0x528 */);
    // 004a1a78  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1a7b  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1a82  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1a84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1a89  e9f6f9ffff             -jmp 0x4a1484
    goto L_0x004a1484;
L_0x004a1a8e:
    // 004a1a8e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a1a90  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a1a93  c1eb1d                 -shr ebx, 0x1d
    cpu.ebx >>= 29 /*0x1d*/ % 32;
    // 004a1a96  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004a1a99  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1a9b  0f8d6cfbffff           -jge 0x4a160d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a160d;
    }
    // 004a1aa1  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1aa8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1aaa  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1aac  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1ab3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1ab6  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1ab8  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1abf  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1ac6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1ac8  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1acb  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1ad2  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1ad9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1adc  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1adf  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1ae1  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004a1ae8  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1aef  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1af1  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1af8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1afa  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1afd  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1aff  e909fbffff             -jmp 0x4a160d
    goto L_0x004a160d;
L_0x004a1b04:
    // 004a1b04  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1b0b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1b0d  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a1b0f  8b9c2434050000         -mov ebx, dword ptr [esp + 0x534]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1b16  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a1b19  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1b1b  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1b22  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1b29  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1b2b  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a1b2e  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1b35  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1b3c  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1b3f  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1b42  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1b44  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004a1b4b  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1b52  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1b54  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a1b56  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1b58  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1b5b  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1b5d  e924faffff             -jmp 0x4a1586
    goto L_0x004a1586;
L_0x004a1b62:
    // 004a1b62  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x004a1b67:
    // 004a1b67  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a1b69  42                     -inc edx
    (cpu.edx)++;
    // 004a1b6a  4f                     -dec edi
    (cpu.edi)--;
    // 004a1b6b  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 004a1b6e  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1b70  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1b72  7c09                   -jl 0x4a1b7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1b7d;
    }
    // 004a1b74  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a1b76  74ef                   -je 0x4a1b67
    if (cpu.flags.zf)
    {
        goto L_0x004a1b67;
    }
    // 004a1b78  e909faffff             -jmp 0x4a1586
    goto L_0x004a1586;
L_0x004a1b7d:
    // 004a1b7d  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1b84  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1b86  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1b88  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1b8f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1b92  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1b94  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1b9b  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1ba2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1ba4  8a5901                 -mov bl, byte ptr [ecx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a1ba7  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1bae  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1bb1  09cb                   -or ebx, ecx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1bb3  899c2434050000         -mov dword ptr [esp + 0x534], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ebx;
    // 004a1bba  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1bbc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a1bbe  8b9c2430050000         -mov ebx, dword ptr [esp + 0x530]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1bc5  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1bc7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1bca  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1bcd  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1bcf  899c2430050000         -mov dword ptr [esp + 0x530], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebx;
    // 004a1bd6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a1bd8  748d                   -je 0x4a1b67
    if (cpu.flags.zf)
    {
        goto L_0x004a1b67;
    }
    // 004a1bda  e9a7f9ffff             -jmp 0x4a1586
    goto L_0x004a1586;
L_0x004a1bdf:
    // 004a1bdf  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1be6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1be8  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a1bea  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1bec  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004a1bf0  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1bf7  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1bfa  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1bfc  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1bfe  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1c00  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a1c07  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1c09  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 004a1c10  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1c13  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1c1a  e9bdf9ffff             -jmp 0x4a15dc
    goto L_0x004a15dc;
L_0x004a1c1f:
    // 004a1c1f  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1c26  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1c2d  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1c30  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004a1c33  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1c35  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1c3c  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a1c43  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1c46  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1c4d  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1c54  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1c57  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004a1c5b  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004a1c62  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1c64  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1c66  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a1c6d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1c6f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1c72  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1c74  e97df9ffff             -jmp 0x4a15f6
    goto L_0x004a15f6;
L_0x004a1c79:
    // 004a1c79  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a1c7e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a1c80  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1c82  d3eb                   -shr ebx, cl
    cpu.ebx >>= cpu.cl % 32;
    // 004a1c84  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004a1c86  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1c88  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1c8a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1c8c  0f8d70f9ffff           -jge 0x4a1602
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1602;
    }
    // 004a1c92  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1c99  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1c9b  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a1c9d  09e9                   -or ecx, ebp
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1c9f  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004a1ca3  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1caa  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1cad  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1caf  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1cb1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1cb3  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a1cba  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1cbc  8b8c242c050000         -mov ecx, dword ptr [esp + 0x52c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1324) /* 0x52c */);
    // 004a1cc3  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1cc6  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a1ccd  e930f9ffff             -jmp 0x4a1602
    goto L_0x004a1602;
L_0x004a1cd2:
    // 004a1cd2  8bac2420050000         -mov ebp, dword ptr [esp + 0x520]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */);
    // 004a1cd9  8b842424050000         -mov eax, dword ptr [esp + 0x524]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */);
    // 004a1ce0  8b8c24ec040000         -mov ecx, dword ptr [esp + 0x4ec]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */);
    // 004a1ce7  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1cea  48                     -dec eax
    (cpu.eax)--;
    // 004a1ceb  41                     -inc ecx
    (cpu.ecx)++;
    // 004a1cec  89ac2420050000         -mov dword ptr [esp + 0x520], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1312) /* 0x520 */) = cpu.ebp;
    // 004a1cf3  89842424050000         -mov dword ptr [esp + 0x524], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1316) /* 0x524 */) = cpu.eax;
    // 004a1cfa  8bac24dc040000         -mov ebp, dword ptr [esp + 0x4dc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1244) /* 0x4dc */);
    // 004a1d01  898c24ec040000         -mov dword ptr [esp + 0x4ec], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1260) /* 0x4ec */) = cpu.ecx;
    // 004a1d08  39e9                   +cmp ecx, ebp
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
    // 004a1d0a  0f8eb4f9ffff           -jle 0x4a16c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a16c4;
    }
    // 004a1d10  e9b9f3ffff             -jmp 0x4a10ce
    goto L_0x004a10ce;
L_0x004a1d15:
    // 004a1d15  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1d18  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1d1a  83f860                 +cmp eax, 0x60
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
    // 004a1d1d  7468                   -je 0x4a1d87
    if (cpu.flags.zf)
    {
        goto L_0x004a1d87;
    }
    // 004a1d1f  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004a1d24  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1d26  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a1d2b  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
L_0x004a1d2e:
    // 004a1d2e  8bac0c44040000         -mov ebp, dword ptr [esp + ecx + 0x444]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1092) /* 0x444 */ + cpu.ecx * 1);
    // 004a1d35  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1d38  40                     -inc eax
    (cpu.eax)++;
    // 004a1d39  39ea                   +cmp edx, ebp
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
    // 004a1d3b  73f1                   -jae 0x4a1d2e
    if (!cpu.flags.cf)
    {
        goto L_0x004a1d2e;
    }
L_0x004a1d3d:
    // 004a1d3d  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a1d42  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a1d44  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1d46  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004a1d48  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1d4a  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1d4c  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1d4e  8b8c8480040000         -mov ecx, dword ptr [esp + eax*4 + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */ + cpu.eax * 4);
    // 004a1d55  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1d57  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1d59  8a942440050000         -mov dl, byte ptr [esp + 0x540]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */);
    // 004a1d60  8a840400030000         -mov al, byte ptr [esp + eax + 0x300]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(768) /* 0x300 */ + cpu.eax * 1);
    // 004a1d67  38d0                   +cmp al, dl
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
    // 004a1d69  7425                   -je 0x4a1d90
    if (cpu.flags.zf)
    {
        goto L_0x004a1d90;
    }
    // 004a1d6b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1d6d  7c21                   -jl 0x4a1d90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1d90;
    }
    // 004a1d6f  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a1d76  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a1d78  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1d7b  898424d4040000         -mov dword ptr [esp + 0x4d4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.eax;
    // 004a1d82  e95cf3ffff             -jmp 0x4a10e3
    goto L_0x004a10e3;
L_0x004a1d87:
    // 004a1d87  8b8424d0040000         -mov eax, dword ptr [esp + 0x4d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1232) /* 0x4d0 */);
    // 004a1d8e  ebad                   -jmp 0x4a1d3d
    goto L_0x004a1d3d;
L_0x004a1d90:
    // 004a1d90  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1d92  7c21                   -jl 0x4a1db5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1db5;
    }
L_0x004a1d94:
    // 004a1d94  3a842440050000         +cmp al, byte ptr [esp + 0x540]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1344) /* 0x540 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a1d9b  747b                   -je 0x4a1e18
    if (cpu.flags.zf)
    {
        goto L_0x004a1e18;
    }
    // 004a1d9d  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a1da4  8d6a01                 -lea ebp, [edx + 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1da7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a1da9  89ac24d4040000         -mov dword ptr [esp + 0x4d4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ebp;
    // 004a1db0  e92ef3ffff             -jmp 0x4a10e3
    goto L_0x004a10e3;
L_0x004a1db5:
    // 004a1db5  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1dbc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1dbe  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1dc0  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1dc7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1dca  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1dcc  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1dd3  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1dda  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1ddc  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1ddf  8b942434050000         -mov edx, dword ptr [esp + 0x534]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1de6  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1ded  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a1df0  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1df3  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1df5  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004a1dfc  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1e03  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1e05  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1e0c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1e0e  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1e11  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1e13  e97cffffff             -jmp 0x4a1d94
    goto L_0x004a1d94;
L_0x004a1e18:
    // 004a1e18  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a1e1f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a1e21  0f8cf7000000           -jl 0x4a1f1e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1f1e;
    }
    // 004a1e27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1e29  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a1e2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1e2e  0f84c9010000           -je 0x4a1ffd
    if (cpu.flags.zf)
    {
        goto L_0x004a1ffd;
    }
    // 004a1e34  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004a1e39:
    // 004a1e39  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1e3b  40                     -inc eax
    (cpu.eax)++;
    // 004a1e3c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a1e3e  7df9                   -jge 0x4a1e39
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a1e39;
    }
    // 004a1e40  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a1e43  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1e45  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1e47  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1e49  0f8c5a010000           -jl 0x4a1fa9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1fa9;
    }
L_0x004a1e4f:
    // 004a1e4f  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1e56  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1e59  898c2414050000         -mov dword ptr [esp + 0x514], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */) = cpu.ecx;
    // 004a1e60  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1e67  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1e6a  898c24c0040000         -mov dword ptr [esp + 0x4c0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */) = cpu.ecx;
    // 004a1e71  83f810                 +cmp eax, 0x10
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
    // 004a1e74  0f8ec6020000           -jle 0x4a2140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2140;
    }
    // 004a1e7a  8d48f0                 -lea ecx, [eax - 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
    // 004a1e7d  898c240c050000         -mov dword ptr [esp + 0x50c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */) = cpu.ecx;
    // 004a1e84  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a1e89  2b8c240c050000         -sub ecx, dword ptr [esp + 0x50c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004a1e90  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a1e92  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 004a1e94  8a8c240c050000         -mov cl, byte ptr [esp + 0x50c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1292) /* 0x50c */);
    // 004a1e9b  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1e9d  2bbc240c050000         -sub edi, dword ptr [esp + 0x50c]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1292) /* 0x50c */)));
    // 004a1ea4  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 004a1eab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1ead  0f8cd6010000           -jl 0x4a2089
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2089;
    }
L_0x004a1eb3:
    // 004a1eb3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a1eb5  83ef10                 -sub edi, 0x10
    (cpu.edi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1eb8  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a1ebb  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004a1ebe  898c2408050000         -mov dword ptr [esp + 0x508], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */) = cpu.ecx;
    // 004a1ec5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1ec7  0f8c11020000           -jl 0x4a20de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a20de;
    }
L_0x004a1ecd:
    // 004a1ecd  8b8c2404050000         -mov ecx, dword ptr [esp + 0x504]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 004a1ed4  8bac2408050000         -mov ebp, dword ptr [esp + 0x508]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1288) /* 0x508 */);
    // 004a1edb  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004a1ede  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1ee0  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1ee2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1ee7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a1ee9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x004a1eeb:
    // 004a1eeb  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1eee  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
L_0x004a1ef5:
    // 004a1ef5  8bac2404050000         -mov ebp, dword ptr [esp + 0x504]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
    // 004a1efc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a1efe  0f84c7020000           -je 0x4a21cb
    if (cpu.flags.zf)
    {
        goto L_0x004a21cb;
    }
    // 004a1f04  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a1f07  8d042a                 -lea eax, [edx + ebp]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x004a1f0a:
    // 004a1f0a  42                     -inc edx
    (cpu.edx)++;
    // 004a1f0b  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a1f0e  39c2                   +cmp edx, eax
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
    // 004a1f10  72f8                   -jb 0x4a1f0a
    if (cpu.flags.cf)
    {
        goto L_0x004a1f0a;
    }
    // 004a1f12  899424d4040000         -mov dword ptr [esp + 0x4d4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.edx;
    // 004a1f19  e9c5f1ffff             -jmp 0x4a10e3
    goto L_0x004a10e3;
L_0x004a1f1e:
    // 004a1f1e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1f20  83ef03                 -sub edi, 3
    (cpu.edi) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a1f23  c1e81d                 -shr eax, 0x1d
    cpu.eax >>= 29 /*0x1d*/ % 32;
    // 004a1f26  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004a1f29  89842404050000         -mov dword ptr [esp + 0x504], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.eax;
    // 004a1f30  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1f32  7c0a                   -jl 0x4a1f3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1f3e;
    }
    // 004a1f34  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1f3c  ebb7                   -jmp 0x4a1ef5
    goto L_0x004a1ef5;
L_0x004a1f3e:
    // 004a1f3e  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1f45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1f47  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a1f49  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1f50  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1f53  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1f55  89842434050000         -mov dword ptr [esp + 0x534], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.eax;
    // 004a1f5c  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1f63  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1f65  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1f68  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1f6f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a1f72  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1f74  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1f7b  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1f82  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1f89  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1f8b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1f8e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1f90  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004a1f97  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1f9a  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a1f9c  83ac240405000004       +sub dword ptr [esp + 0x504], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1fa4  e94cffffff             -jmp 0x4a1ef5
    goto L_0x004a1ef5;
L_0x004a1fa9:
    // 004a1fa9  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1fb0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1fb2  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a1fb4  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a1fbb  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1fc2  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a1fc5  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a1fc8  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a1fca  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a1fd1  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a1fd8  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a1fdb  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004a1fdf  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004a1fe6  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1fe8  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a1fea  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a1ff1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a1ff3  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a1ff6  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a1ff8  e952feffff             -jmp 0x4a1e4f
    goto L_0x004a1e4f;
L_0x004a1ffd:
    // 004a1ffd  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004a2002  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004a2004:
    // 004a2004  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a2006  40                     -inc eax
    (cpu.eax)++;
    // 004a2007  4f                     -dec edi
    (cpu.edi)--;
    // 004a2008  c1e91f                 -shr ecx, 0x1f
    cpu.ecx >>= 31 /*0x1f*/ % 32;
    // 004a200b  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a200d  898c2438050000         -mov dword ptr [esp + 0x538], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */) = cpu.ecx;
    // 004a2014  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a2016  7c0e                   -jl 0x4a2026
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2026;
    }
    // 004a2018  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a201f  74e3                   -je 0x4a2004
    if (cpu.flags.zf)
    {
        goto L_0x004a2004;
    }
    // 004a2021  e929feffff             -jmp 0x4a1e4f
    goto L_0x004a1e4f;
L_0x004a2026:
    // 004a2026  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a202d  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2034  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a2037  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004a203a  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a203c  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a2043  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a204a  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2051  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a2054  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004a2058  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a205a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a205c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a205e  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a2065  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a2067  8b8c2430050000         -mov ecx, dword ptr [esp + 0x530]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a206e  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a2071  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2074  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a207b  3bac2438050000         +cmp ebp, dword ptr [esp + 0x538]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1336) /* 0x538 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2082  7480                   -je 0x4a2004
    if (cpu.flags.zf)
    {
        goto L_0x004a2004;
    }
    // 004a2084  e9c6fdffff             -jmp 0x4a1e4f
    goto L_0x004a1e4f;
L_0x004a2089:
    // 004a2089  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2090  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2092  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a2094  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 004a209b  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a209d  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a20a4  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a20ab  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a20b2  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a20b5  0fb67601               -movzx esi, byte ptr [esi + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 004a20b9  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a20bb  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a20bd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a20bf  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a20c6  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a20c8  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 004a20cf  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a20d2  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a20d9  e9d5fdffff             -jmp 0x4a1eb3
    goto L_0x004a1eb3;
L_0x004a20de:
    // 004a20de  8b8c2434050000         -mov ecx, dword ptr [esp + 0x534]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a20e5  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a20ec  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004a20ef  0fb636                 -movzx esi, byte ptr [esi]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi));
    // 004a20f2  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a20f4  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a20fb  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2102  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2104  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a2107  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a210e  8bac2430050000         -mov ebp, dword ptr [esp + 0x530]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2115  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a2118  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a211b  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a211d  89ac2430050000         -mov dword ptr [esp + 0x530], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ebp;
    // 004a2124  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a212b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a212d  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a2134  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2136  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2139  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a213b  e98dfdffff             -jmp 0x4a1ecd
    goto L_0x004a1ecd;
L_0x004a2140:
    // 004a2140  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004a2145  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a2147  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2149  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a214b  d3ed                   -shr ebp, cl
    cpu.ebp >>= cpu.cl % 32;
    // 004a214d  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a214f  89ac2404050000         -mov dword ptr [esp + 0x504], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */) = cpu.ebp;
    // 004a2156  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a2158  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a215a  7c15                   -jl 0x4a2171
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2171;
    }
L_0x004a215c:
    // 004a215c  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a215e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2163  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a2165  03842404050000         +add eax, dword ptr [esp + 0x504]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1284) /* 0x504 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a216c  e97afdffff             -jmp 0x4a1eeb
    goto L_0x004a1eeb;
L_0x004a2171:
    // 004a2171  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2178  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a217a  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a217c  8bb42414050000         -mov esi, dword ptr [esp + 0x514]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 004a2183  09ce                   -or esi, ecx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2185  89b42434050000         -mov dword ptr [esp + 0x534], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.esi;
    // 004a218c  8bb42430050000         -mov esi, dword ptr [esp + 0x530]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2193  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2195  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a2198  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a219f  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a21a2  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 004a21a4  898c2434050000         -mov dword ptr [esp + 0x534], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.ecx;
    // 004a21ab  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a21ad  8bb42434050000         -mov esi, dword ptr [esp + 0x534]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a21b4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a21b6  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 004a21b8  8b8c24c0040000         -mov ecx, dword ptr [esp + 0x4c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1216) /* 0x4c0 */);
    // 004a21bf  83c710                 +add edi, 0x10
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a21c2  898c2430050000         -mov dword ptr [esp + 0x530], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.ecx;
    // 004a21c9  eb91                   -jmp 0x4a215c
    goto L_0x004a215c;
L_0x004a21cb:
    // 004a21cb  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004a21cd  4f                     -dec edi
    (cpu.edi)--;
    // 004a21ce  c1ed1f                 -shr ebp, 0x1f
    cpu.ebp >>= 31 /*0x1f*/ % 32;
    // 004a21d1  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a21d3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a21d5  7c5b                   -jl 0x4a2232
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2232;
    }
L_0x004a21d7:
    // 004a21d7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a21d9  0f84b1000000           -je 0x4a2290
    if (cpu.flags.zf)
    {
        goto L_0x004a2290;
    }
    // 004a21df  8bbc24c4040000         -mov edi, dword ptr [esp + 0x4c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 004a21e6  8b9c24cc040000         -mov ebx, dword ptr [esp + 0x4cc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004a21ed  8bb424c8040000         -mov esi, dword ptr [esp + 0x4c8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1224) /* 0x4c8 */);
    // 004a21f4  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a21f6  81fefb320000           +cmp esi, 0x32fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13051 /*0x32fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a21fc  0f851e010000           -jne 0x4a2320
    if (!cpu.flags.zf)
    {
        goto L_0x004a2320;
    }
    // 004a2202  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 004a2209  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a220b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a220d  39c7                   +cmp edi, eax
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
    // 004a220f  760f                   -jbe 0x4a2220
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a2220;
    }
L_0x004a2211:
    // 004a2211  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2213  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2215  40                     -inc eax
    (cpu.eax)++;
    // 004a2216  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a2218  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 004a221b  39d8                   +cmp eax, ebx
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
    // 004a221d  72f2                   -jb 0x4a2211
    if (cpu.flags.cf)
    {
        goto L_0x004a2211;
    }
    // 004a221f  90                     -nop 
    ;
L_0x004a2220:
    // 004a2220  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004a2227  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 004a222d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a222e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a222f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2230  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2231  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2232:
    // 004a2232  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2239  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a223b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a223d  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a2244  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a2247  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2249  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2250  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a2257  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2259  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a225b  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a225e  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a2265  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2267  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a226a  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a226d  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a226f  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a2276  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a227d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a227f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a2282  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a2284  89842430050000         -mov dword ptr [esp + 0x530], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.eax;
    // 004a228b  e947ffffff             -jmp 0x4a21d7
    goto L_0x004a21d7;
L_0x004a2290:
    // 004a2290  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2292  83ef08                 -sub edi, 8
    (cpu.edi) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2295  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 004a2298  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004a229b  8884243c050000         -mov byte ptr [esp + 0x53c], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */) = cpu.al;
    // 004a22a2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a22a4  7c1f                   -jl 0x4a22c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a22c5;
    }
L_0x004a22a6:
    // 004a22a6  8b9424d4040000         -mov edx, dword ptr [esp + 0x4d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */);
    // 004a22ad  8a84243c050000         -mov al, byte ptr [esp + 0x53c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1340) /* 0x53c */);
    // 004a22b4  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a22b7  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004a22b9  898c24d4040000         -mov dword ptr [esp + 0x4d4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1236) /* 0x4d4 */) = cpu.ecx;
    // 004a22c0  e91eeeffff             -jmp 0x4a10e3
    goto L_0x004a10e3;
L_0x004a22c5:
    // 004a22c5  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a22cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a22ce  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a22d0  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a22d7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a22da  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a22dc  8b842430050000         -mov eax, dword ptr [esp + 0x530]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a22e3  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a22ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a22ec  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a22ef  8b842434050000         -mov eax, dword ptr [esp + 0x534]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */);
    // 004a22f6  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a22f9  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a22fb  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a22fd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a22ff  89942434050000         -mov dword ptr [esp + 0x534], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1332) /* 0x534 */) = cpu.edx;
    // 004a2306  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a2308  8b942430050000         -mov edx, dword ptr [esp + 0x530]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */);
    // 004a230f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2312  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a2315  d3e6                   +shl esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a2317  89942430050000         -mov dword ptr [esp + 0x530], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1328) /* 0x530 */) = cpu.edx;
    // 004a231e  eb86                   -jmp 0x4a22a6
    goto L_0x004a22a6;
L_0x004a2320:
    // 004a2320  81fefb340000           +cmp esi, 0x34fb
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13563 /*0x34fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2326  0f85f4feffff           -jne 0x4a2220
    if (!cpu.flags.zf)
    {
        goto L_0x004a2220;
    }
    // 004a232c  8b8424c4040000         -mov eax, dword ptr [esp + 0x4c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1220) /* 0x4c4 */);
    // 004a2333  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004a2335  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2337  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2339  39c7                   +cmp edi, eax
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
    // 004a233b  0f86dffeffff           -jbe 0x4a2220
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a2220;
    }
L_0x004a2341:
    // 004a2341  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2343  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2345  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2347  40                     -inc eax
    (cpu.eax)++;
    // 004a2348  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a234a  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004a234d  39f0                   +cmp eax, esi
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
    // 004a234f  72f0                   -jb 0x4a2341
    if (cpu.flags.cf)
    {
        goto L_0x004a2341;
    }
    // 004a2351  8b8424cc040000         -mov eax, dword ptr [esp + 0x4cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1228) /* 0x4cc */);
    // 004a2358  81c444050000           -add esp, 0x544
    (cpu.esp) += x86::reg32(x86::sreg32(1348 /*0x544*/));
    // 004a235e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a235f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2360  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2361  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2362  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a2380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004a2380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2382  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2383  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2384  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2385  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a2388  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a238a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a238c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004a2391  88642410               -mov byte ptr [esp + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 004a2395  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a2397  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a239b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a239d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a239f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a23a1  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a23a8  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a23aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a23ac  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004a23af  81fa314b0000           +cmp edx, 0x4b31
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19249 /*0x4b31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a23b5  0f8498000000           -je 0x4a2453
    if (cpu.flags.zf)
    {
        goto L_0x004a2453;
    }
    // 004a23bb  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004a23c0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a23c2  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a23c4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a23c6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a23cd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a23cf  83c505                 -add ebp, 5
    (cpu.ebp) += x86::reg32(x86::sreg32(5 /*0x5*/));
L_0x004a23d2:
    // 004a23d2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a23d6  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a23d9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a23dd  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a23e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a23e3  7e61                   -jle 0x4a2446
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2446;
    }
L_0x004a23e5:
    // 004a23e5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a23e8  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004a23ea  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004a23ec  80e43f                 -and ah, 0x3f
    cpu.ah &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004a23ef  0fb6ec                 -movzx ebp, ah
    cpu.ebp = x86::reg32(cpu.ah);
    // 004a23f2  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a23f5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a23fa  43                     -inc ebx
    (cpu.ebx)++;
    // 004a23fb  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004a23fe  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a2401  83f803                 +cmp eax, 3
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
    // 004a2404  7739                   -ja 0x4a243f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a243f;
    }
    // 004a2406  ff248570234a00         -jmp dword ptr [eax*4 + 0x4a2370]
    cpu.ip = app->getMemory<x86::reg32>(4858736 + cpu.eax * 4); goto dynamic_jump;
  case 0x004a240d:
    // 004a240d  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a2411  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a2413  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a2415  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a2419  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a241a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a241c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a241f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2421  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a2423  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a2426  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a2428  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2429  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a242d  8d3c2b                 -lea edi, [ebx + ebp]
    cpu.edi = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004a2430  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a2432  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004a2435  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a2437  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a243b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004a243f:
    // 004a243f  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004a2444  7f9f                   -jg 0x4a23e5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a23e5;
    }
L_0x004a2446:
    // 004a2446  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a244a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a244d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a244e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a244f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2450  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2451  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2452  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2453:
    // 004a2453  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004a2458  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a245a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004a245c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a245e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004a2465  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004a2467  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a246a  e963ffffff             -jmp 0x4a23d2
    goto L_0x004a23d2;
  case 0x004a246f:
    // 004a246f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a2471  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2474  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 004a2478  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
  [[fallthrough]];
  case 0x004a247b:
    // 004a247b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a247f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2481  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a2483  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a2487  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a248b  e81f6efeff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004a2490  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a2494  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a2496  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2498  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a249c  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a24a0  eb9d                   -jmp 0x4a243f
    goto L_0x004a243f;
  case 0x004a24a2:
    // 004a24a2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a24a6  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a24a9  8a23                   -mov ah, byte ptr [ebx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a24ab  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a24ae  8d7a01                 -lea edi, [edx + 1]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a24b1  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 004a24b3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a24b7  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004a24ba  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a24be  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a24c0  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a24c1  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a24c5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a24c7  0f8e72ffffff           -jle 0x4a243f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a243f;
    }
L_0x004a24cd:
    // 004a24cd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a24d0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004a24d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a24d4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a24d6  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004a24d8  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004a24da  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004a24dd  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a24df  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a24e3  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a24e7  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a24e8  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004a24ea  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a24ed  43                     -inc ebx
    (cpu.ebx)++;
    // 004a24ee  41                     -inc ecx
    (cpu.ecx)++;
    // 004a24ef  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a24f3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a24f6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a24f8  7e0e                   -jle 0x4a2508
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2508;
    }
    // 004a24fa  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a24fc  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a24ff  4d                     -dec ebp
    (cpu.ebp)--;
    // 004a2500  08e0                   -or al, ah
    cpu.al |= x86::reg8(x86::sreg8(cpu.ah));
    // 004a2502  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004a2506  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
L_0x004a2508:
    // 004a2508  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a250a  7fc1                   -jg 0x4a24cd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a24cd;
    }
    // 004a250c  e92effffff             -jmp 0x4a243f
    goto L_0x004a243f;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a2514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2514  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2515  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a2517  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a251a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a251b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a251c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a251d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a251f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2521  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a2523  c745fc00000000         -mov dword ptr [ebp - 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 0 /*0x0*/;
    // 004a252a  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a252c  0f84d8000000           -je 0x4a260a
    if (cpu.flags.zf)
    {
        return sub_4a260a(app, cpu);
    }
    // 004a2532  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a2535  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2538  2401                   +and al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004a253a  7403                   -je 0x4a253f
    if (cpu.flags.zf)
    {
        goto L_0x004a253f;
    }
    // 004a253c  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
L_0x004a253f:
    // 004a253f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2541  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a2543  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a2546  8a6301                 -mov ah, byte ptr [ebx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2549  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a254c  8d5b03                 -lea ebx, [ebx + 3]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a254f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a2552  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2555  0f84af000000           -je 0x4a260a
    if (cpu.flags.zf)
    {
        return sub_4a260a(app, cpu);
    }
    // 004a255b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a255d  eb46                   -jmp 0x4a25a5
    return sub_4a25a5(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4a2560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004a2560:
    // 004a2560  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2563  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a2565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2567  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a2569  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a256b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a256e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2571  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a2574  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2576  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a257a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a257d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a257f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a2581  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2583  7826                   -js 0x4a25ab
    if (cpu.flags.sf)
    {
        goto L_0x004a25ab;
    }
L_0x004a2585:
    // 004a2585  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a2588  75d6                   -jne 0x4a2560
    if (!cpu.flags.zf)
    {
        goto L_0x004a2560;
    }
    // 004a258a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a258d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a258f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a2591  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a2594  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2597  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a259a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a259c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25a0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a25a3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25a5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25a7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25a9  79da                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
L_0x004a25ab:
    // 004a25ab  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25ad  7831                   -js 0x4a25e0
    if (cpu.flags.sf)
    {
        goto L_0x004a25e0;
    }
    // 004a25af  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a25b1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a25b4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004a25b7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a25ba  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25bc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25be  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a25c0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a25c3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004a25c5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004a25c8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a25ca  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25ce  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a25d1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a25d4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25d6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25d8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25da  79a9                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25dc  ebcd                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a25e0:
    // 004a25e0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25e2  7930                   -jns 0x4a2614
    if (!cpu.flags.sf)
    {
        goto L_0x004a2614;
    }
    // 004a25e4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a25e7  7317                   -jae 0x4a2600
    if (!cpu.flags.cf)
    {
        goto L_0x004a2600;
    }
    // 004a25e9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a25ec  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a25ef  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a25f2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25f4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25f6  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004a25f8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a25fa  7989                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25fc  ebad                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25fe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a2600:
    // 004a2600  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2602  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2605  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2608  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a260a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a260d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2610  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2613  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2614:
    // 004a2614  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2616  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a2619  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a261c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a261e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2620  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2622  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2624  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2627  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004a262a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004a262d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004a262f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004a2631  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2633  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a2637  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004a263a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004a263d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004a2643  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2646  7d24                   -jge 0x4a266c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a266c(app, cpu);
    }
    // 004a2648  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a2651  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2654  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2656  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2658  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a265a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a265c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a265e  0f8921ffffff           -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a2664  e942ffffff             -jmp 0x4a25ab
    goto L_0x004a25ab;
}

/* align: skip  */
void Application::sub_4a25ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a25ab;
L_0x004a2560:
    // 004a2560  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2563  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a2565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2567  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a2569  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a256b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a256e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2571  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a2574  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2576  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a257a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a257d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a257f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a2581  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2583  7826                   -js 0x4a25ab
    if (cpu.flags.sf)
    {
        goto L_0x004a25ab;
    }
L_0x004a2585:
    // 004a2585  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a2588  75d6                   -jne 0x4a2560
    if (!cpu.flags.zf)
    {
        goto L_0x004a2560;
    }
    // 004a258a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a258d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a258f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a2591  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a2594  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2597  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a259a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a259c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25a0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a25a3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25a5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25a7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25a9  79da                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
L_0x004a25ab:
L_entry_0x004a25ab:
    // 004a25ab  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25ad  7831                   -js 0x4a25e0
    if (cpu.flags.sf)
    {
        goto L_0x004a25e0;
    }
    // 004a25af  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a25b1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a25b4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004a25b7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a25ba  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25bc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25be  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a25c0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a25c3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004a25c5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004a25c8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a25ca  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25ce  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a25d1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a25d4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25d6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25d8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25da  79a9                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25dc  ebcd                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a25e0:
    // 004a25e0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25e2  7930                   -jns 0x4a2614
    if (!cpu.flags.sf)
    {
        goto L_0x004a2614;
    }
    // 004a25e4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a25e7  7317                   -jae 0x4a2600
    if (!cpu.flags.cf)
    {
        goto L_0x004a2600;
    }
    // 004a25e9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a25ec  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a25ef  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a25f2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25f4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25f6  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004a25f8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a25fa  7989                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25fc  ebad                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25fe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a2600:
    // 004a2600  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2602  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2605  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2608  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a260a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a260d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2610  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2613  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2614:
    // 004a2614  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2616  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a2619  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a261c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a261e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2620  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2622  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2624  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2627  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004a262a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004a262d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004a262f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004a2631  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2633  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a2637  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004a263a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004a263d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004a2643  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2646  7d24                   -jge 0x4a266c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a266c(app, cpu);
    }
    // 004a2648  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a2651  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2654  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2656  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2658  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a265a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a265c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a265e  0f8921ffffff           -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a2664  e942ffffff             -jmp 0x4a25ab
    goto L_0x004a25ab;
}

/* align: skip  */
void Application::sub_4a25a5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a25a5;
L_0x004a2560:
    // 004a2560  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2563  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a2565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2567  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a2569  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a256b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a256e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2571  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a2574  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2576  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a257a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a257d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a257f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a2581  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2583  7826                   -js 0x4a25ab
    if (cpu.flags.sf)
    {
        goto L_0x004a25ab;
    }
L_0x004a2585:
    // 004a2585  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a2588  75d6                   -jne 0x4a2560
    if (!cpu.flags.zf)
    {
        goto L_0x004a2560;
    }
    // 004a258a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a258d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a258f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a2591  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a2594  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2597  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a259a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a259c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25a0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a25a3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
L_entry_0x004a25a5:
    // 004a25a5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25a7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25a9  79da                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
L_0x004a25ab:
    // 004a25ab  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25ad  7831                   -js 0x4a25e0
    if (cpu.flags.sf)
    {
        goto L_0x004a25e0;
    }
    // 004a25af  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a25b1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a25b4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004a25b7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a25ba  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25bc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25be  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a25c0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a25c3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004a25c5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004a25c8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a25ca  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25ce  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a25d1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a25d4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25d6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25d8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25da  79a9                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25dc  ebcd                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a25e0:
    // 004a25e0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25e2  7930                   -jns 0x4a2614
    if (!cpu.flags.sf)
    {
        goto L_0x004a2614;
    }
    // 004a25e4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a25e7  7317                   -jae 0x4a2600
    if (!cpu.flags.cf)
    {
        goto L_0x004a2600;
    }
    // 004a25e9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a25ec  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a25ef  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a25f2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25f4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25f6  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004a25f8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a25fa  7989                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25fc  ebad                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25fe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a2600:
    // 004a2600  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2602  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2605  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2608  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a260a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a260d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2610  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2613  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2614:
    // 004a2614  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2616  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a2619  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a261c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a261e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2620  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2622  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2624  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2627  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004a262a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004a262d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004a262f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004a2631  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2633  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a2637  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004a263a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004a263d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004a2643  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2646  7d24                   -jge 0x4a266c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a266c(app, cpu);
    }
    // 004a2648  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a2651  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2654  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2656  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2658  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a265a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a265c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a265e  0f8921ffffff           -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a2664  e942ffffff             -jmp 0x4a25ab
    goto L_0x004a25ab;
}

/* align: skip  */
void Application::sub_4a260a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a260a;
L_0x004a2560:
    // 004a2560  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2563  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a2565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2567  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a2569  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a256b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a256e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2571  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a2574  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2576  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a257a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a257d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a257f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a2581  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2583  7826                   -js 0x4a25ab
    if (cpu.flags.sf)
    {
        goto L_0x004a25ab;
    }
L_0x004a2585:
    // 004a2585  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a2588  75d6                   -jne 0x4a2560
    if (!cpu.flags.zf)
    {
        goto L_0x004a2560;
    }
    // 004a258a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a258d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a258f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a2591  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a2594  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2597  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a259a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a259c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25a0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a25a3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25a5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25a7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25a9  79da                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
L_0x004a25ab:
    // 004a25ab  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25ad  7831                   -js 0x4a25e0
    if (cpu.flags.sf)
    {
        goto L_0x004a25e0;
    }
    // 004a25af  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a25b1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a25b4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004a25b7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a25ba  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25bc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25be  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a25c0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a25c3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004a25c5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004a25c8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a25ca  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25ce  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a25d1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a25d4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25d6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25d8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25da  79a9                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25dc  ebcd                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a25e0:
    // 004a25e0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25e2  7930                   -jns 0x4a2614
    if (!cpu.flags.sf)
    {
        goto L_0x004a2614;
    }
    // 004a25e4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a25e7  7317                   -jae 0x4a2600
    if (!cpu.flags.cf)
    {
        goto L_0x004a2600;
    }
    // 004a25e9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a25ec  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a25ef  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a25f2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25f4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25f6  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004a25f8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a25fa  7989                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25fc  ebad                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25fe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a2600:
    // 004a2600  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2602  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2605  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2608  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
L_entry_0x004a260a:
    // 004a260a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a260d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2610  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2613  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2614:
    // 004a2614  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2616  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a2619  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a261c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a261e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2620  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2622  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2624  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2627  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004a262a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004a262d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004a262f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004a2631  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2633  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a2637  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004a263a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004a263d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004a2643  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2646  7d24                   -jge 0x4a266c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a266c(app, cpu);
    }
    // 004a2648  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a2651  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2654  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2656  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2658  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a265a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a265c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a265e  0f8921ffffff           -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a2664  e942ffffff             -jmp 0x4a25ab
    goto L_0x004a25ab;
}

/* align: skip  */
void Application::sub_4a2585(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a2585;
L_0x004a2560:
    // 004a2560  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2563  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a2565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2567  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a2569  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a256b  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a256e  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2571  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a2574  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2576  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a257a  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a257d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a257f  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a2581  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2583  7826                   -js 0x4a25ab
    if (cpu.flags.sf)
    {
        goto L_0x004a25ab;
    }
L_0x004a2585:
L_entry_0x004a2585:
    // 004a2585  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a2588  75d6                   -jne 0x4a2560
    if (!cpu.flags.zf)
    {
        goto L_0x004a2560;
    }
    // 004a258a  8d5b02                 -lea ebx, [ebx + 2]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a258d  88d5                   -mov ch, dl
    cpu.ch = cpu.dl;
    // 004a258f  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a2591  83e21c                 -and edx, 0x1c
    cpu.edx &= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a2594  c0ed05                 -shr ch, 5
    cpu.ch >>= 5 /*0x5*/ % 32;
    // 004a2597  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004a259a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a259c  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25a0  8d4a03                 -lea ecx, [edx + 3]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004a25a3  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25a5  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25a7  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25a9  79da                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
L_0x004a25ab:
    // 004a25ab  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25ad  7831                   -js 0x4a25e0
    if (cpu.flags.sf)
    {
        goto L_0x004a25e0;
    }
    // 004a25af  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004a25b1  8d7303                 -lea esi, [ebx + 3]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a25b4  c1e906                 -shr ecx, 6
    cpu.ecx >>= 6 /*0x6*/ % 32;
    // 004a25b7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a25ba  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25bc  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25be  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a25c0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a25c3  88f5                   -mov ch, dh
    cpu.ch = cpu.dh;
    // 004a25c5  80e53f                 -and ch, 0x3f
    cpu.ch &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 004a25c8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a25ca  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a25ce  83e23f                 -and edx, 0x3f
    cpu.edx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a25d1  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a25d4  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a25d6  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a25d8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a25da  79a9                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25dc  ebcd                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a25e0:
    // 004a25e0  00c9                   +add cl, cl
    {
        x86::reg8& tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25e2  7930                   -jns 0x4a2614
    if (!cpu.flags.sf)
    {
        goto L_0x004a2614;
    }
    // 004a25e4  80fafc                 +cmp dl, 0xfc
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(252 /*0xfc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a25e7  7317                   -jae 0x4a2600
    if (!cpu.flags.cf)
    {
        goto L_0x004a2600;
    }
    // 004a25e9  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004a25ec  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a25ef  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a25f2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25f4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a25f6  0a0e                   +or cl, byte ptr [esi]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi)))));
    // 004a25f8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a25fa  7989                   -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a25fc  ebad                   -jmp 0x4a25ab
    goto L_0x004a25ab;
    // 004a25fe  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a2600:
    // 004a2600  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2602  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2605  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2608  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a260a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a260d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a260f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2610  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2612  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2613  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2614:
    // 004a2614  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2616  8d7304                 -lea esi, [ebx + 4]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a2619  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a261c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a261e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2620  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2622  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2624  83e110                 -and ecx, 0x10
    cpu.ecx &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2627  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004a262a  c1e10c                 -shl ecx, 0xc
    cpu.ecx <<= 12 /*0xc*/ % 32;
    // 004a262d  88e1                   -mov cl, ah
    cpu.cl = cpu.ah;
    // 004a262f  88c5                   -mov ch, al
    cpu.ch = cpu.al;
    // 004a2631  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a2633  8d740fff               -lea esi, [edi + ecx - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 004a2637  c1c208                 -rol edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 8 /*0x8*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 004a263a  c0ee02                 -shr dh, 2
    cpu.dh >>= 2 /*0x2*/ % 32;
    // 004a263d  81e2ff030000           -and edx, 0x3ff
    cpu.edx &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004a2643  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2646  7d24                   -jge 0x4a266c
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a266c(app, cpu);
    }
    // 004a2648  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264b  8d5205                 -lea edx, [edx + 5]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a264e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a2651  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2654  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2656  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a2658  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a265a  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a265c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a265e  0f8921ffffff           -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        goto L_0x004a2585;
    }
    // 004a2664  e942ffffff             -jmp 0x4a25ab
    goto L_0x004a25ab;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a266c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a266c  8d4a05                 -lea ecx, [edx + 5]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004a266f  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004a2671  0a0b                   +or cl, byte ptr [ebx]
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx)))));
    // 004a2673  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2675  0f890affffff           -jns 0x4a2585
    if (!cpu.flags.sf)
    {
        return sub_4a2585(app, cpu);
    }
    // 004a267b  e92bffffff             -jmp 0x4a25ab
    return sub_4a25ab(app, cpu);
}

/* align: skip  */
void Application::sub_4a2680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2680  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2681  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004a2682:
    // 004a2682  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2684  8b0df04f5400           -mov ecx, dword ptr [0x544ff0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5525488) /* 0x544ff0 */);
    // 004a268a  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004a268c  803c1100               +cmp byte ptr [ecx + edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2690  7513                   -jne 0x4a26a5
    if (!cpu.flags.zf)
    {
        goto L_0x004a26a5;
    }
    // 004a2692  8b15e04f5400           -mov edx, dword ptr [0x544fe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */);
    // 004a2698  42                     -inc edx
    (cpu.edx)++;
    // 004a2699  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a269c  8915e04f5400           -mov dword ptr [0x544fe0], edx
    app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */) = cpu.edx;
    // 004a26a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a26a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a26a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a26a5:
    // 004a26a5  a1e44f5400             -mov eax, dword ptr [0x544fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525476) /* 0x544fe4 */);
    // 004a26aa  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a26ad  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a26b2  e8c9ffffff             -call 0x4a2680
    cpu.esp -= 4;
    sub_4a2680(app, cpu);
    if (cpu.terminate) return;
    // 004a26b7  a1ec4f5400             -mov eax, dword ptr [0x544fec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525484) /* 0x544fec */);
    // 004a26bc  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a26bf  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a26c4  ebbc                   -jmp 0x4a2682
    goto L_0x004a2682;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a26c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a26c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a26c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a26ca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a26cb  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004a26d1  8915e04f5400           -mov dword ptr [0x544fe0], edx
    app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */) = cpu.edx;
    // 004a26d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a26d9  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 004a26e0  8d942400020000         -lea edx, [esp + 0x200]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004a26e7  8915f04f5400           -mov dword ptr [0x544ff0], edx
    app->getMemory<x86::reg32>(x86::reg32(5525488) /* 0x544ff0 */) = cpu.edx;
    // 004a26ed  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a26ef  8915e44f5400           -mov dword ptr [0x544fe4], edx
    app->getMemory<x86::reg32>(x86::reg32(5525476) /* 0x544fe4 */) = cpu.edx;
    // 004a26f5  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004a26fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a26fe  8915ec4f5400           -mov dword ptr [0x544fec], edx
    app->getMemory<x86::reg32>(x86::reg32(5525484) /* 0x544fec */) = cpu.edx;
    // 004a2704  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2706  0f8445010000           -je 0x4a2851
    if (cpu.flags.zf)
    {
        goto L_0x004a2851;
    }
    // 004a270c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a270e  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2711  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2713  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2715  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a2718  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a271a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a271c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a271d  81fafb470000           +cmp edx, 0x47fb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18427 /*0x47fb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2723  0f84d0000000           -je 0x4a27f9
    if (cpu.flags.zf)
    {
        goto L_0x004a27f9;
    }
L_0x004a2729:
    // 004a2729  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a272b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a272d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a272f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a2732  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004a2739  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a273c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a273e  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004a2745  41                     -inc ecx
    (cpu.ecx)++;
    // 004a2746  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a274d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a274f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a2752  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a2755  41                     -inc ecx
    (cpu.ecx)++;
    // 004a2756  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a2758  41                     -inc ecx
    (cpu.ecx)++;
    // 004a2759  89942400030000         -mov dword ptr [esp + 0x300], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.edx;
    // 004a2760  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a2762:
    // 004a2762  a1f04f5400             -mov eax, dword ptr [0x544ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525488) /* 0x544ff0 */);
    // 004a2767  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004a276a  42                     -inc edx
    (cpu.edx)++;
    // 004a276b  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004a276e  81fa00010000           +cmp edx, 0x100
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
    // 004a2774  7cec                   -jl 0x4a2762
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2762;
    }
    // 004a2776  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2777  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2778  41                     -inc ecx
    (cpu.ecx)++;
    // 004a2779  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a277b  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004a277e  41                     -inc ecx
    (cpu.ecx)++;
    // 004a277f  c6040201               -mov byte ptr [edx + eax], 1
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 1 /*0x1*/;
    // 004a2783  0fb669ff               -movzx ebp, byte ptr [ecx - 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */));
    // 004a2787  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2789  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a278b  7e37                   -jle 0x4a27c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a27c4;
    }
L_0x004a278d:
    // 004a278d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a278f  8b1de44f5400           -mov ebx, dword ptr [0x544fe4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525476) /* 0x544fe4 */);
    // 004a2795  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a2797  8d7101                 -lea esi, [ecx + 1]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a279a  8d3c13                 -lea edi, [ebx + edx]
    cpu.edi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004a279d  8d4e01                 -lea ecx, [esi + 1]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a27a0  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a27a2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a27a4  881f                   -mov byte ptr [edi], bl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.bl;
    // 004a27a6  8b3dec4f5400           -mov edi, dword ptr [0x544fec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5525484) /* 0x544fec */);
    // 004a27ac  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 004a27ae  881c3a                 -mov byte ptr [edx + edi], bl
    app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1) = cpu.bl;
    // 004a27b1  8b1df04f5400           -mov ebx, dword ptr [0x544ff0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525488) /* 0x544ff0 */);
    // 004a27b7  40                     -inc eax
    (cpu.eax)++;
    // 004a27b8  41                     -inc ecx
    (cpu.ecx)++;
    // 004a27b9  c6041aff               -mov byte ptr [edx + ebx], 0xff
    app->getMemory<x86::reg8>(cpu.edx + cpu.ebx * 1) = 255 /*0xff*/;
    // 004a27bd  39e8                   +cmp eax, ebp
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
    // 004a27bf  7ccc                   -jl 0x4a278d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a278d;
    }
    // 004a27c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a27c4:
    // 004a27c4  890de84f5400           -mov dword ptr [0x544fe8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525480) /* 0x544fe8 */) = cpu.ecx;
    // 004a27ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a27cc:
    // 004a27cc  8b0de84f5400           -mov ecx, dword ptr [0x544fe8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5525480) /* 0x544fe8 */);
    // 004a27d2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a27d4  a1f04f5400             -mov eax, dword ptr [0x544ff0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525488) /* 0x544ff0 */);
    // 004a27d9  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a27db  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a27de  41                     -inc ecx
    (cpu.ecx)++;
    // 004a27df  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004a27e1  751e                   -jne 0x4a2801
    if (!cpu.flags.zf)
    {
        goto L_0x004a2801;
    }
    // 004a27e3  a1e04f5400             -mov eax, dword ptr [0x544fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */);
    // 004a27e8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a27e9  890de84f5400           -mov dword ptr [0x544fe8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525480) /* 0x544fe8 */) = cpu.ecx;
    // 004a27ef  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004a27f2  a3e04f5400             -mov dword ptr [0x544fe0], eax
    app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */) = cpu.eax;
    // 004a27f7  ebd3                   -jmp 0x4a27cc
    goto L_0x004a27cc;
L_0x004a27f9:
    // 004a27f9  83c103                 +add ecx, 3
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
    // 004a27fc  e928ffffff             -jmp 0x4a2729
    goto L_0x004a2729;
L_0x004a2801:
    // 004a2801  890de84f5400           -mov dword ptr [0x544fe8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525480) /* 0x544fe8 */) = cpu.ecx;
    // 004a2807  7c1f                   -jl 0x4a2828
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2828;
    }
    // 004a2809  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a280b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a280d  41                     -inc ecx
    (cpu.ecx)++;
    // 004a280e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a2810  743f                   -je 0x4a2851
    if (cpu.flags.zf)
    {
        goto L_0x004a2851;
    }
    // 004a2812  a1e04f5400             -mov eax, dword ptr [0x544fe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */);
    // 004a2817  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2818  890de84f5400           -mov dword ptr [0x544fe8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525480) /* 0x544fe8 */) = cpu.ecx;
    // 004a281e  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004a2821  a3e04f5400             -mov dword ptr [0x544fe0], eax
    app->getMemory<x86::reg32>(x86::reg32(5525472) /* 0x544fe0 */) = cpu.eax;
    // 004a2826  eba4                   -jmp 0x4a27cc
    goto L_0x004a27cc;
L_0x004a2828:
    // 004a2828  a1e44f5400             -mov eax, dword ptr [0x544fe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525476) /* 0x544fe4 */);
    // 004a282d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a2830  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a2835  e846feffff             -call 0x4a2680
    cpu.esp -= 4;
    sub_4a2680(app, cpu);
    if (cpu.terminate) return;
    // 004a283a  a1ec4f5400             -mov eax, dword ptr [0x544fec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525484) /* 0x544fec */);
    // 004a283f  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004a2842  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a2847  e834feffff             -call 0x4a2680
    cpu.esp -= 4;
    sub_4a2680(app, cpu);
    if (cpu.terminate) return;
    // 004a284c  e97bffffff             -jmp 0x4a27cc
    goto L_0x004a27cc;
L_0x004a2851:
    // 004a2851  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 004a2858  890de84f5400           -mov dword ptr [0x544fe8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525480) /* 0x544fe8 */) = cpu.ecx;
    // 004a285e  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004a2864  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2865  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2866  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a2870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2872  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2873  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2874  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2875  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2878  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a287a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a287c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a287e  0f8ee6000000           -jle 0x4a296a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a296a;
    }
L_0x004a2884:
    // 004a2884  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2887  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2889  0f8ee2000000           -jle 0x4a2971
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2971;
    }
L_0x004a288f:
    // 004a288f  39d1                   +cmp ecx, edx
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
    // 004a2891  7e0d                   -jle 0x4a28a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a28a0;
    }
    // 004a2893  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2896  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2898  0f8eda000000           -jle 0x4a2978
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2978;
    }
    // 004a289e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004a28a0:
    // 004a28a0  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a28a3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a28a5  0f8ed6000000           -jle 0x4a2981
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2981;
    }
    // 004a28ab  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x004a28ad:
    // 004a28ad  39d1                   +cmp ecx, edx
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
    // 004a28af  7e0d                   -jle 0x4a28be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a28be;
    }
    // 004a28b1  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a28b4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a28b6  0f8ece000000           -jle 0x4a298a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a298a;
    }
    // 004a28bc  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
L_0x004a28be:
    // 004a28be  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a28c0  0f84cd000000           -je 0x4a2993
    if (cpu.flags.zf)
    {
        goto L_0x004a2993;
    }
    // 004a28c6  81fa00008000           +cmp edx, 0x800000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388608 /*0x800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a28cc  0f8ed6000000           -jle 0x4a29a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a29a8;
    }
    // 004a28d2  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004a28d7  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004a28da  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004a28dd:
    // 004a28dd  81fa00002000           +cmp edx, 0x200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2097152 /*0x200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a28e3  7e0c                   -jle 0x4a28f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a28f1;
    }
    // 004a28e5  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a28e8  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a28eb  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 004a28ee  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
L_0x004a28f1:
    // 004a28f1  81fa00001000           +cmp edx, 0x100000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048576 /*0x100000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a28f7  7e0c                   -jle 0x4a2905
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2905;
    }
    // 004a28f9  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004a28fc  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a28ff  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 004a2902  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
L_0x004a2905:
    // 004a2905  81fa00800000           +cmp edx, 0x8000
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
    // 004a290b  7e04                   -jle 0x4a2911
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2911;
    }
    // 004a290d  83042402               -add dword ptr [esp], 2
    (app->getMemory<x86::reg32>(cpu.esp)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a2911:
    // 004a2911  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a2914  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2916  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004a2918  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a291a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a291d  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004a291f  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a2922  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a2925  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004a2927  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a292a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a292c  e8ff950000             -call 0x4abf30
    cpu.esp -= 4;
    sub_4abf30(app, cpu);
    if (cpu.terminate) return;
    // 004a2931  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2933  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a2936  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a2938  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a293a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a293d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a293f  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a2942  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a2945  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a2947  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2949  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a294c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a294e  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a2951  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a2954  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a2957  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2959  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a295c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a295e  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a2961  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2964  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2965  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2966  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2967  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2968  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2969  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a296a:
    // 004a296a  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004a296c  e913ffffff             -jmp 0x4a2884
    goto L_0x004a2884;
L_0x004a2971:
    // 004a2971  f7d9                   +neg ecx
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
    // 004a2973  e917ffffff             -jmp 0x4a288f
    goto L_0x004a288f;
L_0x004a2978:
    // 004a2978  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a297a  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004a297c  e91fffffff             -jmp 0x4a28a0
    goto L_0x004a28a0;
L_0x004a2981:
    // 004a2981  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a2983  f7d9                   +neg ecx
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
    // 004a2985  e923ffffff             -jmp 0x4a28ad
    goto L_0x004a28ad;
L_0x004a298a:
    // 004a298a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a298c  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004a298e  e92bffffff             -jmp 0x4a28be
    goto L_0x004a28be;
L_0x004a2993:
    // 004a2993  c70300000100           -mov dword ptr [ebx], 0x10000
    app->getMemory<x86::reg32>(cpu.ebx) = 65536 /*0x10000*/;
    // 004a2999  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a299c  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a299f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a29a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a29a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a29a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a29a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a29a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a29a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a29a8:
    // 004a29a8  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a29aa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a29ad  e92bffffff             -jmp 0x4a28dd
    goto L_0x004a28dd;
}

/* align: skip  */
void Application::sub_4a29b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a29b2  e9da950000             -jmp 0x4abf91
    return sub_4abf91(app, cpu);
}

/* align: skip  */
void Application::sub_4a29b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a29b7  803dacea4c0000         +cmp byte ptr [0x4ceaac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5040812) /* 0x4ceaac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a29be  741a                   -je 0x4a29da
    if (cpu.flags.zf)
    {
        goto L_0x004a29da;
    }
    // 004a29c0  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004a29c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a29c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a29c8  cc                     -int3 
    NFS2_ASSERT(false);
    // 004a29c9  eb06                   -jmp 0x4a29d1
    goto L_0x004a29d1;
    // 004a29cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a29cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a29cd  49                     -dec ecx
    (cpu.ecx)--;
    // 004a29ce  44                     -inc esp
    (cpu.esp)++;
    // 004a29cf  45                     -inc ebp
    (cpu.ebp)++;
    // 004a29d0  4f                     -dec edi
    (cpu.edi)--;
L_0x004a29d1:
    // 004a29d1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a29d6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a29d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a29da:
    // 004a29da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a29dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a29dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a29dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a29de  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a29e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a29e6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a29e8  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004a29ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a29eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a29ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a29ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a29ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a29ed  87442404               -xchg dword ptr [esp + 4], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a29f1  e807000000             -call 0x4a29fd
    cpu.esp -= 4;
    sub_4a29fd(app, cpu);
    if (cpu.terminate) return;
    // 004a29f6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a29fa  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a29fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a29fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a29fe  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2a00  731a                   -jae 0x4a2a1c
    if (!cpu.flags.cf)
    {
        goto L_0x004a2a1c;
    }
    // 004a2a02  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004a2a04  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a2a06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a08  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2a0e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a2a10  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a11  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2a13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a14  7606                   -jbe 0x4a2a1c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a2a1c;
    }
    // 004a2a16  e811000000             -call 0x4a2a2c
    cpu.esp -= 4;
    sub_4a2a2c(app, cpu);
    if (cpu.terminate) return;
    // 004a2a1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2a1c:
    // 004a2a1c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a1d  b8b0ea4c00             -mov eax, 0x4ceab0
    cpu.eax = 5040816 /*0x4ceab0*/;
    // 004a2a22  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a2a27  e8c5950000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
    // 004a2a2c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a2d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2a2e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a2a32  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004a2a37:
    // 004a2a37  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004a2a3a  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004a2a40  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2a45  7ff0                   -jg 0x4a2a37
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a2a37;
    }
    // 004a2a47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a48  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a49  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a2a2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a2a2c;
    // 004a29fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a29fe  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2a00  731a                   -jae 0x4a2a1c
    if (!cpu.flags.cf)
    {
        goto L_0x004a2a1c;
    }
    // 004a2a02  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004a2a04  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a2a06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a08  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2a0e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a2a10  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a11  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2a13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a14  7606                   -jbe 0x4a2a1c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a2a1c;
    }
    // 004a2a16  e811000000             -call 0x4a2a2c
    cpu.esp -= 4;
    sub_4a2a2c(app, cpu);
    if (cpu.terminate) return;
    // 004a2a1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2a1c:
    // 004a2a1c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a1d  b8b0ea4c00             -mov eax, 0x4ceab0
    cpu.eax = 5040816 /*0x4ceab0*/;
    // 004a2a22  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a2a27  e8c5950000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004a2a2c:
    // 004a2a2c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a2d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2a2e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a2a32  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004a2a37:
    // 004a2a37  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004a2a3a  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004a2a40  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2a45  7ff0                   -jg 0x4a2a37
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a2a37;
    }
    // 004a2a47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a48  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a49  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a2a4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2a4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a4d  e8daffffff             -call 0x4a2a2c
    cpu.esp -= 4;
    sub_4a2a2c(app, cpu);
    if (cpu.terminate) return;
    // 004a2a52  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2a53  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a2a57  2b0424                 +sub eax, dword ptr [esp]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2a5a  94                     -xchg esp, eax
    {
        x86::reg32 tmp = cpu.esp;
        cpu.esp = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a2a5b  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2a5e  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip  */
void Application::sub_4a2a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2a60  ff15c4ea4c00           -call dword ptr [0x4ceac4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5040836) /* 0x4ceac4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2a66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2a67  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a2a6c  b894164c00             -mov eax, 0x4c1694
    cpu.eax = 4986516 /*0x4c1694*/;
    // 004a2a71  e87b950000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
    // 004a2a76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2a66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a2a66;
    // 004a2a60  ff15c4ea4c00           -call dword ptr [0x4ceac4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5040836) /* 0x4ceac4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004a2a66:
    // 004a2a66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2a67  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004a2a6c  b894164c00             -mov eax, 0x4c1694
    cpu.eax = 4986516 /*0x4c1694*/;
    // 004a2a71  e87b950000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
    // 004a2a76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2a78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2a78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2a7a  0f85c0c3ffff           -jne 0x49ee40
    if (!cpu.flags.zf)
    {
        return sub_49ee40(app, cpu);
    }
    // 004a2a80  e84e900000             -call 0x4abad3
    cpu.esp -= 4;
    sub_4abad3(app, cpu);
    if (cpu.terminate) return;
    // 004a2a85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2a87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a2a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2a90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2a91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2a92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2a93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2a94  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2a96  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2a98  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a2a9a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2a9c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a2a9e  7e58                   -jle 0x4a2af8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2af8;
    }
    // 004a2aa0  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 004a2aa5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a2aa7:
    // 004a2aa7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2aa9  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a2aab  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a2ab1  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a2ab4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2ab6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2ab9  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2abb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2abd  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004a2abf  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a2ac2  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a2ac8  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a2acb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2acd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2ad0  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2ad2  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a2ad5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2ad7  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a2ada  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a2ae0  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a2ae3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2ae5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2ae8  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2aea  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2aed  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2af0  46                     -inc esi
    (cpu.esi)++;
    // 004a2af1  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a2af4  39fe                   +cmp esi, edi
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
    // 004a2af6  7caf                   -jl 0x4a2aa7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2aa7;
    }
L_0x004a2af8:
    // 004a2af8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2af9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2afa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2afb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2afc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a2b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2b00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2b01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2b02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2b03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2b04  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2b06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a2b08  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2b0a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a2b0c  7e68                   -jle 0x4a2b76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2b76;
    }
    // 004a2b0e  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 004a2b13  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a2b15  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a2b17:
    // 004a2b17  81feff000000           +cmp esi, 0xff
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2b1d  755c                   -jne 0x4a2b7b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2b7b;
    }
    // 004a2b1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a2b21:
    // 004a2b21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2b23  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a2b26  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a2b28  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a2b2e  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a2b31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2b33  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2b36  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2b38  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a2b3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2b3d  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2b40  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a2b46  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a2b49  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2b4b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2b4e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2b50  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a2b53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2b55  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2b58  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a2b5e  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a2b61  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2b63  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2b66  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2b68  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2b6b  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2b6e  46                     -inc esi
    (cpu.esi)++;
    // 004a2b6f  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 004a2b72  39fe                   +cmp esi, edi
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
    // 004a2b74  7ca1                   -jl 0x4a2b17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2b17;
    }
L_0x004a2b76:
    // 004a2b76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2b7b:
    // 004a2b7b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a2b80  eb9f                   -jmp 0x4a2b21
    goto L_0x004a2b21;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a2b84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2b84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2b85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2b86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2b87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2b88  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2b8a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2b8c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a2b8e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2b90  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a2b92  7e58                   -jle 0x4a2bec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2bec;
    }
    // 004a2b94  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004a2b99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a2b9b:
    // 004a2b9b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2b9d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a2b9f  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a2ba2  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a2ba8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2baa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2bad  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2baf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2bb1  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004a2bb3  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a2bb6  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a2bb9  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a2bbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2bc1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2bc4  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2bc6  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a2bc9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2bcb  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a2bce  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a2bd1  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a2bd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2bd9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2bdc  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2bde  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2be1  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2be4  46                     -inc esi
    (cpu.esi)++;
    // 004a2be5  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a2be8  39fe                   +cmp esi, edi
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
    // 004a2bea  7caf                   -jl 0x4a2b9b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2b9b;
    }
L_0x004a2bec:
    // 004a2bec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a2bf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2bf4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2bf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2bf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2bf7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2bfa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a2bfc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2bfe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2c00  7e33                   -jle 0x4a2c35
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2c35;
    }
    // 004a2c02  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a2c04:
    // 004a2c04  81f9ff000000           +cmp ecx, 0xff
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
    // 004a2c0a  7430                   -je 0x4a2c3c
    if (cpu.flags.zf)
    {
        goto L_0x004a2c3c;
    }
    // 004a2c0c  c70424ff000000         -mov dword ptr [esp], 0xff
    app->getMemory<x86::reg32>(cpu.esp) = 255 /*0xff*/;
L_0x004a2c13:
    // 004a2c13  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a2c16  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 004a2c19  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a2c1b  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004a2c1e  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a2c21  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2c24  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004a2c27  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2c2a  8a5aff                 -mov bl, byte ptr [edx - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a2c2d  41                     -inc ecx
    (cpu.ecx)++;
    // 004a2c2e  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 004a2c31  39f1                   +cmp ecx, esi
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
    // 004a2c33  7ccf                   -jl 0x4a2c04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2c04;
    }
L_0x004a2c35:
    // 004a2c35  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2c38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2c3c:
    // 004a2c3c  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a2c3e  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004a2c41  ebd0                   -jmp 0x4a2c13
    goto L_0x004a2c13;
}

/* align: skip 0x90 */
void Application::sub_4a2c44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2c44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2c45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2c46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2c47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2c48  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2c4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2c4c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a2c4e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2c50  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a2c52  7e5c                   -jle 0x4a2cb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2cb0;
    }
    // 004a2c54  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004a2c59  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a2c5b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a2c5d:
    // 004a2c5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2c5f  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2c62  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a2c65  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a2c6b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2c6d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2c70  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2c72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2c74  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004a2c76  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a2c79  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a2c7c  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a2c82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2c84  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2c87  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2c89  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a2c8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2c8e  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a2c90  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a2c93  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a2c99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2c9b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2c9e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2ca0  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2ca3  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2ca6  46                     -inc esi
    (cpu.esi)++;
    // 004a2ca7  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a2caa  39fe                   +cmp esi, edi
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
    // 004a2cac  7caf                   -jl 0x4a2c5d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2c5d;
    }
    // 004a2cae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a2cb0:
    // 004a2cb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2cb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2cb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2cb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2cb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a2cb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2cb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2cb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2cba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a2cbc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2cbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2cc0  7e1e                   -jle 0x4a2ce0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2ce0;
    }
    // 004a2cc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a2cc4:
    // 004a2cc4  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a2cc7  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004a2cc9  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a2ccc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2ccf  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004a2cd2  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2cd5  8a5afc                 -mov bl, byte ptr [edx - 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a2cd8  41                     -inc ecx
    (cpu.ecx)++;
    // 004a2cd9  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004a2cdc  39f1                   +cmp ecx, esi
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
    // 004a2cde  7ce4                   -jl 0x4a2cc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2cc4;
    }
L_0x004a2ce0:
    // 004a2ce0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ce1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ce2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2ce3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2ce3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2ce4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2ce5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2ce6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2ce7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a2ce9  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2cec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2cf1  e829020000             -call 0x4a2f1f
    cpu.esp -= 4;
    sub_4a2f1f(app, cpu);
    if (cpu.terminate) return;
    // 004a2cf6  a16cf84c00             -mov eax, dword ptr [0x4cf86c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004a2cfb  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2cfe  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004a2d00  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2d02  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2d04  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004a2d06  8b1d6cf84c00           -mov ebx, dword ptr [0x4cf86c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004a2d0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a2d0e  e89c65feff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004a2d13  a16cf84c00             -mov eax, dword ptr [0x4cf86c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004a2d18  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a2d1a  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004a2d20  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a2d23  e8b4adffff             -call 0x49dadc
    cpu.esp -= 4;
    sub_49dadc(app, cpu);
    if (cpu.terminate) return;
    // 004a2d28  e8e1920000             -call 0x4ac00e
    cpu.esp -= 4;
    sub_4ac00e(app, cpu);
    if (cpu.terminate) return;
    // 004a2d2d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2d2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2d34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2d34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2d35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2d36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2d37  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2d38  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2d39  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2d3a  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a2d3d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a2d3f  a104ce4c00             -mov eax, dword ptr [0x4cce04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5033476) /* 0x4cce04 */);
    // 004a2d44  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2d46  e8cb000000             -call 0x4a2e16
    cpu.esp -= 4;
    sub_4a2e16(app, cpu);
    if (cpu.terminate) return;
    // 004a2d4b  40                     -inc eax
    (cpu.eax)++;
    // 004a2d4c  8b1504ce4c00           -mov edx, dword ptr [0x4cce04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033476) /* 0x4cce04 */);
    // 004a2d52  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a2d56  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a2d59  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2d5b  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2d5e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2d61  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004a2d63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a2d65  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2d69  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a2d6c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a2d70  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2d73  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a2d75  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2d78  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004a2d7a  e89472ffff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a2d7f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a2d81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2d83  7455                   -je 0x4a2dda
    if (cpu.flags.zf)
    {
        goto L_0x004a2dda;
    }
    // 004a2d85  8b3504ce4c00           -mov esi, dword ptr [0x4cce04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5033476) /* 0x4cce04 */);
    // 004a2d8b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a2d8d  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a2d8f  a3ec845200             -mov dword ptr [0x5284ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */) = cpu.eax;
    // 004a2d94  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2d95  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a2d97  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a2d99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2d9a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a2d9c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a2d9f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2da1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a2da3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a2da6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a2da8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2da9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2daa  a1ec845200             -mov eax, dword ptr [0x5284ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */);
    // 004a2daf  8b1508ce4c00           -mov edx, dword ptr [0x4cce08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5033480) /* 0x4cce08 */);
    // 004a2db5  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a2db7  8d5004                 -lea edx, [eax + 4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2dba  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a2dbc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a2dbe  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a2dc2  e84f000000             -call 0x4a2e16
    cpu.esp -= 4;
    sub_4a2e16(app, cpu);
    if (cpu.terminate) return;
    // 004a2dc7  a1ec845200             -mov eax, dword ptr [0x5284ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */);
    // 004a2dcc  01f0                   +add eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2dce  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a2dd4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2dd8  eb05                   -jmp 0x4a2ddf
    goto L_0x004a2ddf;
L_0x004a2dda:
    // 004a2dda  a3ec845200             -mov dword ptr [0x5284ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */) = cpu.eax;
L_0x004a2ddf:
    // 004a2ddf  a3e8845200             -mov dword ptr [0x5284e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407976) /* 0x5284e8 */) = cpu.eax;
    // 004a2de4  a1e8845200             -mov eax, dword ptr [0x5284e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407976) /* 0x5284e8 */);
    // 004a2de9  a3e4945400             -mov dword ptr [0x5494e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5543140) /* 0x5494e4 */) = cpu.eax;
    // 004a2dee  a1ec845200             -mov eax, dword ptr [0x5284ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */);
    // 004a2df3  a3e8945400             -mov dword ptr [0x5494e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5543144) /* 0x5494e8 */) = cpu.eax;
    // 004a2df8  a1e4945400             -mov eax, dword ptr [0x5494e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5543140) /* 0x5494e4 */);
    // 004a2dfd  a3f0845200             -mov dword ptr [0x5284f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407984) /* 0x5284f0 */) = cpu.eax;
    // 004a2e02  a1e8945400             -mov eax, dword ptr [0x5494e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5543144) /* 0x5494e8 */);
    // 004a2e07  a3f4845200             -mov dword ptr [0x5284f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407988) /* 0x5284f4 */) = cpu.eax;
    // 004a2e0c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a2e0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2e16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2e16  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2e17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2e18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2e19  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2e1a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2e1d  8b0dec945400           -mov ecx, dword ptr [0x5494ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5543148) /* 0x5494ec */);
    // 004a2e23  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a2e25  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a2e28  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a2e2a:
    // 004a2e2a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2e2c  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e2f  7405                   -je 0x4a2e36
    if (cpu.flags.zf)
    {
        goto L_0x004a2e36;
    }
    // 004a2e31  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e34  7503                   -jne 0x4a2e39
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e39;
    }
L_0x004a2e36:
    // 004a2e36  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2e37  ebf1                   -jmp 0x4a2e2a
    goto L_0x004a2e2a;
L_0x004a2e39:
    // 004a2e39  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a2e3b  0f84bd000000           -je 0x4a2efe
    if (cpu.flags.zf)
    {
        goto L_0x004a2efe;
    }
    // 004a2e41  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2e43  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004a2e45  80ff22                 +cmp bh, 0x22
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e48  7503                   -jne 0x4a2e4d
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e4d;
    }
    // 004a2e4a  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004a2e4c  40                     -inc eax
    (cpu.eax)++;
L_0x004a2e4d:
    // 004a2e4d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a2e51  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a2e53:
    // 004a2e53  803822                 +cmp byte ptr [eax], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e56  751c                   -jne 0x4a2e74
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e74;
    }
    // 004a2e58  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2e5a  750f                   -jne 0x4a2e6b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e6b;
    }
    // 004a2e5c  40                     -inc eax
    (cpu.eax)++;
    // 004a2e5d  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a2e5f  7504                   -jne 0x4a2e65
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e65;
    }
    // 004a2e61  b202                   -mov dl, 2
    cpu.dl = 2 /*0x2*/;
    // 004a2e63  ebee                   -jmp 0x4a2e53
    goto L_0x004a2e53;
L_0x004a2e65:
    // 004a2e65  740d                   -je 0x4a2e74
    if (cpu.flags.zf)
    {
        goto L_0x004a2e74;
    }
    // 004a2e67  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004a2e69  ebe8                   -jmp 0x4a2e53
    goto L_0x004a2e53;
L_0x004a2e6b:
    // 004a2e6b  80fa01                 +cmp dl, 1
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
    // 004a2e6e  0f845e000000           -je 0x4a2ed2
    if (cpu.flags.zf)
    {
        goto L_0x004a2ed2;
    }
L_0x004a2e74:
    // 004a2e74  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2e76  80fe20                 +cmp dh, 0x20
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e79  7405                   -je 0x4a2e80
    if (cpu.flags.zf)
    {
        goto L_0x004a2e80;
    }
    // 004a2e7b  80fe09                 +cmp dh, 9
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e7e  7508                   -jne 0x4a2e88
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e88;
    }
L_0x004a2e80:
    // 004a2e80  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a2e82  0f844a000000           -je 0x4a2ed2
    if (cpu.flags.zf)
    {
        goto L_0x004a2ed2;
    }
L_0x004a2e88:
    // 004a2e88  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2e8a  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 004a2e8c  7444                   -je 0x4a2ed2
    if (cpu.flags.zf)
    {
        goto L_0x004a2ed2;
    }
    // 004a2e8e  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e91  7530                   -jne 0x4a2ec3
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ec3;
    }
    // 004a2e93  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2e95  7511                   -jne 0x4a2ea8
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ea8;
    }
    // 004a2e97  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2e9b  7526                   -jne 0x4a2ec3
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ec3;
    }
    // 004a2e9d  8a70ff                 -mov dh, byte ptr [eax - 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004a2ea0  40                     -inc eax
    (cpu.eax)++;
    // 004a2ea1  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2ea4  74ad                   -je 0x4a2e53
    if (cpu.flags.zf)
    {
        goto L_0x004a2e53;
    }
    // 004a2ea6  eb1b                   -jmp 0x4a2ec3
    goto L_0x004a2ec3;
L_0x004a2ea8:
    // 004a2ea8  80fa01                 +cmp dl, 1
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
    // 004a2eab  750f                   -jne 0x4a2ebc
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ebc;
    }
    // 004a2ead  8a7001                 -mov dh, byte ptr [eax + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2eb0  80fe22                 +cmp dh, 0x22
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2eb3  740d                   -je 0x4a2ec2
    if (cpu.flags.zf)
    {
        goto L_0x004a2ec2;
    }
    // 004a2eb5  80fe5c                 +cmp dh, 0x5c
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2eb8  7509                   -jne 0x4a2ec3
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ec3;
    }
    // 004a2eba  eb06                   -jmp 0x4a2ec2
    goto L_0x004a2ec2;
L_0x004a2ebc:
    // 004a2ebc  80780122               +cmp byte ptr [eax + 1], 0x22
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2ec0  7501                   -jne 0x4a2ec3
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ec3;
    }
L_0x004a2ec2:
    // 004a2ec2  40                     -inc eax
    (cpu.eax)++;
L_0x004a2ec3:
    // 004a2ec3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2ec5  7408                   -je 0x4a2ecf
    if (cpu.flags.zf)
    {
        goto L_0x004a2ecf;
    }
    // 004a2ec7  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2ec9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2eca  8833                   -mov byte ptr [ebx], dh
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dh;
    // 004a2ecc  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2ecd  eb84                   -jmp 0x4a2e53
    goto L_0x004a2e53;
L_0x004a2ecf:
    // 004a2ecf  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2ed0  eb81                   -jmp 0x4a2e53
    goto L_0x004a2e53;
L_0x004a2ed2:
    // 004a2ed2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2ed4  741d                   -je 0x4a2ef3
    if (cpu.flags.zf)
    {
        goto L_0x004a2ef3;
    }
    // 004a2ed6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a2ed8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2edc  892c96                 -mov dword ptr [esi + edx*4], ebp
    app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4) = cpu.ebp;
    // 004a2edf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2ee1  47                     -inc edi
    (cpu.edi)++;
    // 004a2ee2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a2ee4  7504                   -jne 0x4a2eea
    if (!cpu.flags.zf)
    {
        goto L_0x004a2eea;
    }
    // 004a2ee6  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004a2ee8  eb14                   -jmp 0x4a2efe
    goto L_0x004a2efe;
L_0x004a2eea:
    // 004a2eea  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a2eeb  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004a2eee  e937ffffff             -jmp 0x4a2e2a
    goto L_0x004a2e2a;
L_0x004a2ef3:
    // 004a2ef3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a2ef5  47                     -inc edi
    (cpu.edi)++;
    // 004a2ef6  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a2ef8  0f8538ffffff           -jne 0x4a2e36
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e36;
    }
L_0x004a2efe:
    // 004a2efe  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a2f01  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a2f03  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2f05  890dec945400           -mov dword ptr [0x5494ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5543148) /* 0x5494ec */) = cpu.ecx;
    // 004a2f0b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2f0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2f13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2f13  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2f14  833800                 +cmp dword ptr [eax], 0
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
    // 004a2f17  7404                   -je 0x4a2f1d
    if (cpu.flags.zf)
    {
        goto L_0x004a2f1d;
    }
    // 004a2f19  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004a2f1a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2f1b  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a2f1d:
    // 004a2f1d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2f1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2f1f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2f1f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2f20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2f21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2f22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2f23  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2f24  bea0024d00             -mov esi, 0x4d02a0
    cpu.esi = 5046944 /*0x4d02a0*/;
    // 004a2f29  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x004a2f2b:
    // 004a2f2b  b86a024d00             -mov eax, 0x4d026a
    cpu.eax = 5046890 /*0x4d026a*/;
    // 004a2f30  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2f32  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
L_0x004a2f34:
    // 004a2f34  3da0024d00             +cmp eax, 0x4d02a0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5046944 /*0x4d02a0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f39  7315                   -jae 0x4a2f50
    if (!cpu.flags.cf)
    {
        goto L_0x004a2f50;
    }
    // 004a2f3b  803802                 +cmp byte ptr [eax], 2
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
    // 004a2f3e  740b                   -je 0x4a2f4b
    if (cpu.flags.zf)
    {
        goto L_0x004a2f4b;
    }
    // 004a2f40  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2f43  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2f45  7204                   -jb 0x4a2f4b
    if (cpu.flags.cf)
    {
        goto L_0x004a2f4b;
    }
    // 004a2f47  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2f49  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x004a2f4b:
    // 004a2f4b  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2f4e  ebe4                   -jmp 0x4a2f34
    goto L_0x004a2f34;
L_0x004a2f50:
    // 004a2f50  81fba0024d00           +cmp ebx, 0x4d02a0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5046944 /*0x4d02a0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f56  740d                   -je 0x4a2f65
    if (cpu.flags.zf)
    {
        goto L_0x004a2f65;
    }
    // 004a2f58  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2f5b  e8b3ffffff             -call 0x4a2f13
    cpu.esp -= 4;
    sub_4a2f13(app, cpu);
    if (cpu.terminate) return;
    // 004a2f60  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 004a2f63  ebc6                   -jmp 0x4a2f2b
    goto L_0x004a2f2b;
L_0x004a2f65:
    // 004a2f65  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2f66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2f6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2f6b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2f6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2f6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2f6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2f6e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2f6f  beb8024d00             -mov esi, 0x4d02b8
    cpu.esi = 5046968 /*0x4d02b8*/;
    // 004a2f74  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a2f76  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x004a2f78:
    // 004a2f78  b8a0024d00             -mov eax, 0x4d02a0
    cpu.eax = 5046944 /*0x4d02a0*/;
    // 004a2f7d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a2f7f  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
L_0x004a2f81:
    // 004a2f81  3db8024d00             +cmp eax, 0x4d02b8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5046968 /*0x4d02b8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f86  7315                   -jae 0x4a2f9d
    if (!cpu.flags.cf)
    {
        goto L_0x004a2f9d;
    }
    // 004a2f88  803802                 +cmp byte ptr [eax], 2
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
    // 004a2f8b  740b                   -je 0x4a2f98
    if (cpu.flags.zf)
    {
        goto L_0x004a2f98;
    }
    // 004a2f8d  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a2f90  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2f92  7704                   -ja 0x4a2f98
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a2f98;
    }
    // 004a2f94  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2f96  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x004a2f98:
    // 004a2f98  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a2f9b  ebe4                   -jmp 0x4a2f81
    goto L_0x004a2f81;
L_0x004a2f9d:
    // 004a2f9d  81fbb8024d00           +cmp ebx, 0x4d02b8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5046968 /*0x4d02b8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2fa3  7412                   -je 0x4a2fb7
    if (cpu.flags.zf)
    {
        goto L_0x004a2fb7;
    }
    // 004a2fa5  3a7301                 +cmp dh, byte ptr [ebx + 1]
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2fa8  7208                   -jb 0x4a2fb2
    if (cpu.flags.cf)
    {
        goto L_0x004a2fb2;
    }
    // 004a2faa  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a2fad  e861ffffff             -call 0x4a2f13
    cpu.esp -= 4;
    sub_4a2f13(app, cpu);
    if (cpu.terminate) return;
L_0x004a2fb2:
    // 004a2fb2  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 004a2fb5  ebc1                   -jmp 0x4a2f78
    goto L_0x004a2f78;
L_0x004a2fb7:
    // 004a2fb7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a2fb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2fbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2fbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2fbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2fbe  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2fc0  8b1574505400           -mov edx, dword ptr [0x545074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525620) /* 0x545074 */);
    // 004a2fc6  83fa20                 +cmp edx, 0x20
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
    // 004a2fc9  7d15                   -jge 0x4a2fe0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a2fe0;
    }
    // 004a2fcb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2fcd  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2fcf  42                     -inc edx
    (cpu.edx)++;
    // 004a2fd0  891c95f04f5400         -mov dword ptr [edx*4 + 0x544ff0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5525488) /* 0x544ff0 */ + cpu.edx * 4) = cpu.ebx;
    // 004a2fd7  891574505400           -mov dword ptr [0x545074], edx
    app->getMemory<x86::reg32>(x86::reg32(5525620) /* 0x545074 */) = cpu.edx;
    // 004a2fdd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2fe0:
    // 004a2fe0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a2fe5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fe6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fe7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2fe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2fe9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2fea  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a2feb  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a2fed  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a2fef  8b1d74505400           -mov ebx, dword ptr [0x545074]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525620) /* 0x545074 */);
    // 004a2ff5  83fb21                 +cmp ebx, 0x21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2ff8  7421                   -je 0x4a301b
    if (cpu.flags.zf)
    {
        goto L_0x004a301b;
    }
    // 004a2ffa  c7057450540021000000   -mov dword ptr [0x545074], 0x21
    app->getMemory<x86::reg32>(x86::reg32(5525620) /* 0x545074 */) = 33 /*0x21*/;
    // 004a3004  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a3006  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
L_0x004a3009:
    // 004a3009  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a300b  740e                   -je 0x4a301b
    if (cpu.flags.zf)
    {
        goto L_0x004a301b;
    }
    // 004a300d  8b82f04f5400           -mov eax, dword ptr [edx + 0x544ff0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5525488) /* 0x544ff0 */);
    // 004a3013  83ea04                 +sub edx, 4
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
    // 004a3016  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a3017  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3019  ebee                   -jmp 0x4a3009
    goto L_0x004a3009;
L_0x004a301b:
    // 004a301b  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a301d  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a301f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a3020  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3021  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3022  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
