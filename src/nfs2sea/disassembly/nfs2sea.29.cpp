#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x8b 0xc0 */
void Application::sub_4ab8cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab8cc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab8cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab8cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab8d1  7507                   -jne 0x4ab8da
    if (!cpu.flags.zf)
    {
        goto L_0x004ab8da;
    }
    // 004ab8d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab8d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab8d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab8da:
    // 004ab8da  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab8dc  e8d6eefdff             -call 0x48a7b7
    cpu.esp -= 4;
    sub_48a7b7(app, cpu);
    if (cpu.terminate) return;
    // 004ab8e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab8e3  e8602bffff             -call 0x49e448
    cpu.esp -= 4;
    sub_49e448(app, cpu);
    if (cpu.terminate) return;
    // 004ab8e8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab8ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab8ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ab8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab8f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab8f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab8f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab8f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab8f4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab8f7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ab8f9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ab8fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab8fd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab8ff  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ab903  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab905  0f8eae000000           -jle 0x4ab9b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab9b9;
    }
    // 004ab90b  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ab90e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004ab911:
    // 004ab911  8b8e14100000           -mov ecx, dword ptr [esi + 0x1014]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 004ab917  39cf                   +cmp edi, ecx
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
    // 004ab919  7d02                   -jge 0x4ab91d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ab91d;
    }
    // 004ab91b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x004ab91d:
    // 004ab91d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab91f  7e41                   -jle 0x4ab962
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab962;
    }
    // 004ab921  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ab923  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ab925  8b8610100000           -mov eax, dword ptr [esi + 0x1010]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 004ab92b  e850f0fdff             -call 0x48a980
    cpu.esp -= 4;
    sub_48a980(app, cpu);
    if (cpu.terminate) return;
    // 004ab930  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab932  8b9e10100000           -mov ebx, dword ptr [esi + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 004ab938  8b8614100000           -mov eax, dword ptr [esi + 0x1014]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 004ab93e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ab941  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab943  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab945  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab947  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab949  899e10100000           -mov dword ptr [esi + 0x1010], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.ebx;
    // 004ab94f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab953  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
    // 004ab959  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab95b  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ab95e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004ab962:
    // 004ab962  83be1410000000         +cmp dword ptr [esi + 0x1014], 0
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
    // 004ab969  7546                   -jne 0x4ab9b1
    if (!cpu.flags.zf)
    {
        goto L_0x004ab9b1;
    }
    // 004ab96b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ab96d  7442                   -je 0x4ab9b1
    if (cpu.flags.zf)
    {
        goto L_0x004ab9b1;
    }
    // 004ab96f  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ab972  898610100000           -mov dword ptr [esi + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
    // 004ab978  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ab97b  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ab97e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab980  3d00100000             +cmp eax, 0x1000
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
    // 004ab985  7e3e                   -jle 0x4ab9c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab9c5;
    }
    // 004ab987  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
L_0x004ab98c:
    // 004ab98c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab98e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab990  7e1b                   -jle 0x4ab9ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab9ad;
    }
    // 004ab992  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ab997  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab99a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab99c  e8910cffff             -call 0x49c632
    cpu.esp -= 4;
    sub_49c632(app, cpu);
    if (cpu.terminate) return;
    // 004ab9a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab9a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab9a5  7e06                   -jle 0x4ab9ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab9ad;
    }
    // 004ab9a7  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
L_0x004ab9ad:
    // 004ab9ad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ab9af  7408                   -je 0x4ab9b9
    if (cpu.flags.zf)
    {
        goto L_0x004ab9b9;
    }
L_0x004ab9b1:
    // 004ab9b1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ab9b3  0f8f58ffffff           -jg 0x4ab911
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ab911;
    }
L_0x004ab9b9:
    // 004ab9b9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab9bd  83c408                 +add esp, 8
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
    // 004ab9c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ab9c5:
    // 004ab9c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab9c7  ebc3                   -jmp 0x4ab98c
    goto L_0x004ab98c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ab9cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab9cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab9cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab9ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab9cf  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ab9d1  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab9d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab9d6  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab9d8  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ab9db  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ab9de  39fa                   +cmp edx, edi
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
    // 004ab9e0  7e03                   -jle 0x4ab9e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab9e5;
    }
    // 004ab9e2  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004ab9e5:
    // 004ab9e5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ab9ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab9ec  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab9ee  e82c45ffff             -call 0x49ff1f
    cpu.esp -= 4;
    sub_49ff1f(app, cpu);
    if (cpu.terminate) return;
    // 004ab9f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab9f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab9fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab9fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab9fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ab9fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab9fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab9ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aba00  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004aba05  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aba07  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aba09  0f8c8d000000           -jl 0x4aba9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aba9c;
    }
    // 004aba0f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004aba12  39da                   +cmp edx, ebx
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
    // 004aba14  0f8e8b000000           -jle 0x4abaa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004abaa5;
    }
    // 004aba1a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aba1c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004aba1e:
    // 004aba1e  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004aba28  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004aba2b  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004aba2e  898110100000           -mov dword ptr [ecx + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
L_0x004aba34:
    // 004aba34  83b91810000000         +cmp dword ptr [ecx + 0x1018], 0
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
    // 004aba3b  0f8596000000           -jne 0x4abad7
    if (!cpu.flags.zf)
    {
        goto L_0x004abad7;
    }
    // 004aba41  8b9914100000           -mov ebx, dword ptr [ecx + 0x1014]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */);
    // 004aba47  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aba49  7e0c                   -jle 0x4aba57
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aba57;
    }
    // 004aba4b  81fb00100000           +cmp ebx, 0x1000
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
    // 004aba51  0f8eab000000           -jle 0x4abb02
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004abb02;
    }
L_0x004aba57:
    // 004aba57  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aba59  0f8cbd000000           -jl 0x4abb1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004abb1c;
    }
    // 004aba5f  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
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
    // 004aba62  0f8fb4000000           -jg 0x4abb1c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004abb1c;
    }
    // 004aba68  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004aba6b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aba6d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aba6f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004aba71  e82de1ffff             -call 0x4a9ba3
    cpu.esp -= 4;
    sub_4a9ba3(app, cpu);
    if (cpu.terminate) return;
    // 004aba76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aba78  0f859e000000           -jne 0x4abb1c
    if (!cpu.flags.zf)
    {
        goto L_0x004abb1c;
    }
    // 004aba7e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aba80  0f8496000000           -je 0x4abb1c
    if (cpu.flags.zf)
    {
        goto L_0x004abb1c;
    }
    // 004aba86  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004aba8b  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004aba95  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aba97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba9a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aba9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aba9c:
    // 004aba9c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004aba9e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004abaa0  e979ffffff             -jmp 0x4aba1e
    goto L_0x004aba1e;
L_0x004abaa5:
    // 004abaa5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abaa6  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004abaa8  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004abaab  8ba810100000           -mov ebp, dword ptr [eax + 0x1010]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */);
    // 004abab1  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004abab3  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004abab5  8bb814100000           -mov edi, dword ptr [eax + 0x1014]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */);
    // 004ababb  89a810100000           -mov dword ptr [eax + 0x1010], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ebp;
    // 004abac1  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abac3  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004abac6  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 004abacc  01dd                   +add ebp, ebx
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
    // 004abace  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004abad1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abad2  e95dffffff             -jmp 0x4aba34
    goto L_0x004aba34;
L_0x004abad7:
    // 004abad7  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004abada  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004abadc  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004abade  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abae0  e8bee0ffff             -call 0x4a9ba3
    cpu.esp -= 4;
    sub_4a9ba3(app, cpu);
    if (cpu.terminate) return;
    // 004abae5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abae7  7510                   -jne 0x4abaf9
    if (!cpu.flags.zf)
    {
        goto L_0x004abaf9;
    }
    // 004abae9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004abaeb  740c                   -je 0x4abaf9
    if (cpu.flags.zf)
    {
        goto L_0x004abaf9;
    }
    // 004abaed  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004abaf2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abaf4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaf5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaf7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abaf9:
    // 004abaf9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004abafb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abafd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abafe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abaff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abb02:
    // 004abb02  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004abb05  8b9910100000           -mov ebx, dword ptr [ecx + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */);
    // 004abb0b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004abb0d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004abb0f  0f8c42ffffff           -jl 0x4aba57
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aba57;
    }
    // 004abb15  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abb17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abb1c:
    // 004abb1c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004abb1e  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004abb28  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004abb2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4abb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb30  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004abb33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abb34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb34  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004abb37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4abb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abb40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abb41  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004abb45  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004abb49  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004abb4f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004abb51  7505                   -jne 0x4abb58
    if (!cpu.flags.zf)
    {
        goto L_0x004abb58;
    }
    // 004abb53  bb00395600             -mov ebx, 0x563900
    cpu.ebx = 5650688 /*0x563900*/;
L_0x004abb58:
    // 004abb58  e8ab84fdff             -call 0x484008
    cpu.esp -= 4;
    sub_484008(app, cpu);
    if (cpu.terminate) return;
    // 004abb5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abb5f  743a                   -je 0x4abb9b
    if (cpu.flags.zf)
    {
        goto L_0x004abb9b;
    }
    // 004abb61  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abb64  7407                   -je 0x4abb6d
    if (cpu.flags.zf)
    {
        goto L_0x004abb6d;
    }
    // 004abb66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abb68  e8f75dfeff             -call 0x491964
    cpu.esp -= 4;
    sub_491964(app, cpu);
    if (cpu.terminate) return;
L_0x004abb6d:
    // 004abb6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abb6f  e8b84ffeff             -call 0x490b2c
    cpu.esp -= 4;
    sub_490b2c(app, cpu);
    if (cpu.terminate) return;
    // 004abb74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abb76  7412                   -je 0x4abb8a
    if (cpu.flags.zf)
    {
        goto L_0x004abb8a;
    }
    // 004abb78  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abb7a  e88952feff             -call 0x490e08
    cpu.esp -= 4;
    sub_490e08(app, cpu);
    if (cpu.terminate) return;
    // 004abb7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abb81  7407                   -je 0x4abb8a
    if (cpu.flags.zf)
    {
        goto L_0x004abb8a;
    }
    // 004abb83  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abb85  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
L_0x004abb8a:
    // 004abb8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abb8c  891518ef4d00           -mov dword ptr [0x4def18], edx
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.edx;
    // 004abb92  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abb97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abb98  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004abb9b:
    // 004abb9b  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004abba1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abba3  741a                   -je 0x4abbbf
    if (cpu.flags.zf)
    {
        goto L_0x004abbbf;
    }
    // 004abba5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abba6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004abba8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abba9  2eff1538644c00         -call dword ptr cs:[0x4c6438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006392) /* 0x4c6438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abbb0  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004abbb6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abbb7  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abbbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004abbbf:
    // 004abbbf  c70518ef4d00ffffffff   -mov dword ptr [0x4def18], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = 4294967295 /*0xffffffff*/;
    // 004abbc9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abbce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abbcf  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4abbd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abbd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abbd5  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004abbd9  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004abbdd  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004abbe1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004abbe7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abbe9  7505                   -jne 0x4abbf0
    if (!cpu.flags.zf)
    {
        goto L_0x004abbf0;
    }
    // 004abbeb  b900395600             -mov ecx, 0x563900
    cpu.ecx = 5650688 /*0x563900*/;
L_0x004abbf0:
    // 004abbf0  e81384fdff             -call 0x484008
    cpu.esp -= 4;
    sub_484008(app, cpu);
    if (cpu.terminate) return;
    // 004abbf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abbf7  7513                   -jne 0x4abc0c
    if (!cpu.flags.zf)
    {
        goto L_0x004abc0c;
    }
    // 004abbf9  c70518ef4d00ffffffff   -mov dword ptr [0x4def18], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = 4294967295 /*0xffffffff*/;
    // 004abc03  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abc08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc09  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004abc0c:
    // 004abc0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004abc0e  e80554feff             -call 0x491018
    cpu.esp -= 4;
    sub_491018(app, cpu);
    if (cpu.terminate) return;
    // 004abc13  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004abc15  e85659feff             -call 0x491570
    cpu.esp -= 4;
    sub_491570(app, cpu);
    if (cpu.terminate) return;
    // 004abc1a  83f8ff                 +cmp eax, -1
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
    // 004abc1d  7c54                   -jl 0x4abc73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004abc73;
    }
    // 004abc1f  7f24                   -jg 0x4abc45
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004abc45;
    }
    // 004abc21  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abc22  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004abc27  b804154d00             -mov eax, 0x4d1504
    cpu.eax = 5051652 /*0x4d1504*/;
    // 004abc2c  891d18ef4d00           -mov dword ptr [0x4def18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.ebx;
    // 004abc32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abc34  752f                   -jne 0x4abc65
    if (!cpu.flags.zf)
    {
        goto L_0x004abc65;
    }
L_0x004abc36:
    // 004abc36  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 004abc3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abc41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc42  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004abc45:
    // 004abc45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abc47  752a                   -jne 0x4abc73
    if (!cpu.flags.zf)
    {
        goto L_0x004abc73;
    }
    // 004abc49  a318ef4d00             -mov dword ptr [0x4def18], eax
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.eax;
    // 004abc4e  b810154d00             -mov eax, 0x4d1510
    cpu.eax = 5051664 /*0x4d1510*/;
    // 004abc53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abc55  7515                   -jne 0x4abc6c
    if (!cpu.flags.zf)
    {
        goto L_0x004abc6c;
    }
L_0x004abc57:
    // 004abc57  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 004abc5c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abc61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abc62  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004abc65:
    // 004abc65  b80c154d00             -mov eax, 0x4d150c
    cpu.eax = 5051660 /*0x4d150c*/;
    // 004abc6a  ebca                   -jmp 0x4abc36
    goto L_0x004abc36;
L_0x004abc6c:
    // 004abc6c  b80c154d00             -mov eax, 0x4d150c
    cpu.eax = 5051660 /*0x4d150c*/;
    // 004abc71  ebe4                   -jmp 0x4abc57
    goto L_0x004abc57;
L_0x004abc73:
    // 004abc73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004abc75  e83a54feff             -call 0x4910b4
    cpu.esp -= 4;
    sub_4910b4(app, cpu);
    if (cpu.terminate) return;
    // 004abc7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abc7c  752b                   -jne 0x4abca9
    if (!cpu.flags.zf)
    {
        goto L_0x004abca9;
    }
    // 004abc7e  833d1cef4d0000         +cmp dword ptr [0x4def1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abc85  7529                   -jne 0x4abcb0
    if (!cpu.flags.zf)
    {
        goto L_0x004abcb0;
    }
    // 004abc87  b804154d00             -mov eax, 0x4d1504
    cpu.eax = 5051652 /*0x4d1504*/;
    // 004abc8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abc8e  752e                   -jne 0x4abcbe
    if (!cpu.flags.zf)
    {
        goto L_0x004abcbe;
    }
L_0x004abc90:
    // 004abc90  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004abc95  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 004abc9a  892d18ef4d00           -mov dword ptr [0x4def18], ebp
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.ebp;
    // 004abca0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abca5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abca6  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004abca9:
    // 004abca9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abcab  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
L_0x004abcb0:
    // 004abcb0  a318ef4d00             -mov dword ptr [0x4def18], eax
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.eax;
    // 004abcb5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abcba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abcbb  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004abcbe:
    // 004abcbe  b80c154d00             -mov eax, 0x4d150c
    cpu.eax = 5051660 /*0x4d150c*/;
    // 004abcc3  ebcb                   -jmp 0x4abc90
    goto L_0x004abc90;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4abcc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abcc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abcc9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abcca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abccb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abccc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abccd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abccf  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004abcd1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004abcd6  b818154d00             -mov eax, 0x4d1518
    cpu.eax = 5051672 /*0x4d1518*/;
    // 004abcdb  891518ef4d00           -mov dword ptr [0x4def18], edx
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.edx;
    // 004abce1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abce3  7530                   -jne 0x4abd15
    if (!cpu.flags.zf)
    {
        goto L_0x004abd15;
    }
L_0x004abce5:
    // 004abce5  a31cef4d00             -mov dword ptr [0x4def1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */) = cpu.eax;
    // 004abcea  e8cd67fdff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004abcef  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004abcf1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004abcf3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abcf5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004abcf7  e8e464fdff             -call 0x4821e0
    cpu.esp -= 4;
    sub_4821e0(app, cpu);
    if (cpu.terminate) return;
    // 004abcfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abcfe  740a                   -je 0x4abd0a
    if (cpu.flags.zf)
    {
        goto L_0x004abd0a;
    }
    // 004abd00  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004abd02:
    // 004abd02  3b2d18ef4d00           +cmp ebp, dword ptr [0x4def18]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abd08  7512                   -jne 0x4abd1c
    if (!cpu.flags.zf)
    {
        goto L_0x004abd1c;
    }
L_0x004abd0a:
    // 004abd0a  a11cef4d00             -mov eax, dword ptr [0x4def1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107484) /* 0x4def1c */);
    // 004abd0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abd14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abd15:
    // 004abd15  b80c154d00             -mov eax, 0x4d150c
    cpu.eax = 5051660 /*0x4d150c*/;
    // 004abd1a  ebc9                   -jmp 0x4abce5
    goto L_0x004abce5;
L_0x004abd1c:
    // 004abd1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abd21  e876defdff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004abd26  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004abd28  e8bbdefdff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004abd2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd2f  7407                   -je 0x4abd38
    if (cpu.flags.zf)
    {
        goto L_0x004abd38;
    }
    // 004abd31  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004abd33  e87881fdff             -call 0x483eb0
    cpu.esp -= 4;
    sub_483eb0(app, cpu);
    if (cpu.terminate) return;
L_0x004abd38:
    // 004abd38  3b2d18ef4d00           +cmp ebp, dword ptr [0x4def18]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abd3e  7ec2                   -jle 0x4abd02
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004abd02;
    }
    // 004abd40  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004abd45  e852defdff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004abd4a  e8b982fdff             -call 0x484008
    cpu.esp -= 4;
    sub_484008(app, cpu);
    if (cpu.terminate) return;
    // 004abd4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd51  74af                   -je 0x4abd02
    if (cpu.flags.zf)
    {
        goto L_0x004abd02;
    }
    // 004abd53  8b15543d5600           -mov edx, dword ptr [0x563d54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 004abd59  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abd5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abd5f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004abd61  a318ef4d00             -mov dword ptr [0x4def18], eax
    app->getMemory<x86::reg32>(x86::reg32(5107480) /* 0x4def18 */) = cpu.eax;
    // 004abd66  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abd6d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004abd6f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004abd71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004abd73  e86864fdff             -call 0x4821e0
    cpu.esp -= 4;
    sub_4821e0(app, cpu);
    if (cpu.terminate) return;
    // 004abd78  eb88                   -jmp 0x4abd02
    goto L_0x004abd02;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4abd7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abd7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abd7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abd7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abd7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abd81  e862defdff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004abd86  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abd88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abd8a  7527                   -jne 0x4abdb3
    if (!cpu.flags.zf)
    {
        goto L_0x004abdb3;
    }
    // 004abd8c  8b15a0b64d00           -mov edx, dword ptr [0x4db6a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004abd92  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004abd94  740d                   -je 0x4abda3
    if (cpu.flags.zf)
    {
        goto L_0x004abda3;
    }
    // 004abd96  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004abd98  e8abe1fdff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004abd9d  8b1da0b64d00           -mov ebx, dword ptr [0x4db6a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
L_0x004abda3:
    // 004abda3  8b0d543d5600           -mov ecx, dword ptr [0x563d54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 004abda9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abdab  751b                   -jne 0x4abdc8
    if (!cpu.flags.zf)
    {
        goto L_0x004abdc8;
    }
    // 004abdad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abdaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abdb3:
    // 004abdb3  e80467fdff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004abdb8  8b0d543d5600           -mov ecx, dword ptr [0x563d54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 004abdbe  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abdc0  7506                   -jne 0x4abdc8
    if (!cpu.flags.zf)
    {
        goto L_0x004abdc8;
    }
    // 004abdc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abdc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdc7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abdc8:
    // 004abdc8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004abdca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abdcb  2eff1538644c00         -call dword ptr cs:[0x4c6438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006392) /* 0x4c6438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004abdd2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004abdd4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdd6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abdd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4abdd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abdd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abdd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abdda  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abddb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abddc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004abddd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004abdde  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004abde1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004abde3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abde5  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004abde9:
    // 004abde9  80bf5d04000000         +cmp byte ptr [edi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004abdf0  0f8413010000           -je 0x4abf09
    if (cpu.flags.zf)
    {
        goto L_0x004abf09;
    }
    // 004abdf6  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004abdf9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004abdfd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004abe01  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004abe04  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004abe07  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004abe0a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004abe0c  0f8579000000           -jne 0x4abe8b
    if (!cpu.flags.zf)
    {
        goto L_0x004abe8b;
    }
L_0x004abe12:
    // 004abe12  bea0860100             -mov esi, 0x186a0
    cpu.esi = 100000 /*0x186a0*/;
    // 004abe17  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004abe1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abe1c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004abe1e  7e37                   -jle 0x4abe57
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004abe57;
    }
    // 004abe20  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x004abe23:
    // 004abe23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004abe25  8a4812                 -mov cl, byte ptr [eax + 0x12]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004abe28  3b0c24                 +cmp ecx, dword ptr [esp]
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
    // 004abe2b  751f                   -jne 0x4abe4c
    if (!cpu.flags.zf)
    {
        goto L_0x004abe4c;
    }
    // 004abe2d  f6400f80               +test byte ptr [eax + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) & 128 /*0x80*/));
    // 004abe31  7519                   -jne 0x4abe4c
    if (!cpu.flags.zf)
    {
        goto L_0x004abe4c;
    }
    // 004abe33  3b18                   +cmp ebx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abe35  7715                   -ja 0x4abe4c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004abe4c;
    }
    // 004abe37  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004abe3b  3b4804                 +cmp ecx, dword ptr [eax + 4]
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
    // 004abe3e  770c                   -ja 0x4abe4c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004abe4c;
    }
    // 004abe40  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004abe42  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004abe44  39f1                   +cmp ecx, esi
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
    // 004abe46  7304                   -jae 0x4abe4c
    if (!cpu.flags.cf)
    {
        goto L_0x004abe4c;
    }
    // 004abe48  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004abe4a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x004abe4c:
    // 004abe4c  42                     -inc edx
    (cpu.edx)++;
    // 004abe4d  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004abe50  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004abe53  39ca                   +cmp edx, ecx
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
    // 004abe55  7ccc                   -jl 0x4abe23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004abe23;
    }
L_0x004abe57:
    // 004abe57  3b6f08                 +cmp ebp, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abe5a  7d4f                   -jge 0x4abeab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004abeab;
    }
    // 004abe5c  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004abe61  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004abe63  e860feffff             -call 0x4abcc8
    cpu.esp -= 4;
    sub_4abcc8(app, cpu);
    if (cpu.terminate) return;
    // 004abe68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abe6a  753b                   -jne 0x4abea7
    if (!cpu.flags.zf)
    {
        goto L_0x004abea7;
    }
    // 004abe6c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004abe71:
    // 004abe71  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004abe75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abe77  750b                   -jne 0x4abe84
    if (!cpu.flags.zf)
    {
        goto L_0x004abe84;
    }
    // 004abe79  6bed14                 -imul ebp, ebp, 0x14
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 004abe7c  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004abe7f  804c280f80             -or byte ptr [eax + ebp + 0xf], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */ + cpu.ebp * 1) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004abe84:
    // 004abe84  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004abe89  7487                   -je 0x4abe12
    if (cpu.flags.zf)
    {
        goto L_0x004abe12;
    }
L_0x004abe8b:
    // 004abe8b  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004abe8f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004abe91  7406                   -je 0x4abe99
    if (cpu.flags.zf)
    {
        goto L_0x004abe99;
    }
    // 004abe93  0f8450ffffff           -je 0x4abde9
    if (cpu.flags.zf)
    {
        goto L_0x004abde9;
    }
L_0x004abe99:
    // 004abe99  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004abe9d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004abea0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abea1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abea2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abea3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abea4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abea5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abea6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abea7:
    // 004abea7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abea9  ebc6                   -jmp 0x4abe71
    goto L_0x004abe71;
L_0x004abeab:
    // 004abeab  81fb40010000           +cmp ebx, 0x140
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abeb1  7616                   -jbe 0x4abec9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004abec9;
    }
    // 004abeb3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004abeb7  81eac8000000           -sub edx, 0xc8
    (cpu.edx) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 004abebd  81ebc8000000           +sub ebx, 0xc8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004abec3  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004abec7  ebbb                   -jmp 0x4abe84
    goto L_0x004abe84;
L_0x004abec9:
    // 004abec9  833c2408               +cmp dword ptr [esp], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004abecd  7414                   -je 0x4abee3
    if (cpu.flags.zf)
    {
        goto L_0x004abee3;
    }
    // 004abecf  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004abed2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004abed6  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004abedb  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004abede  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004abee1  eba1                   -jmp 0x4abe84
    goto L_0x004abe84;
L_0x004abee3:
    // 004abee3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004abee8  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004abeed  e8d6fdffff             -call 0x4abcc8
    cpu.esp -= 4;
    sub_4abcc8(app, cpu);
    if (cpu.terminate) return;
    // 004abef2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abef4  750b                   -jne 0x4abf01
    if (!cpu.flags.zf)
    {
        goto L_0x004abf01;
    }
    // 004abef6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abefb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004abeff  eb8a                   -jmp 0x4abe8b
    goto L_0x004abe8b;
L_0x004abf01:
    // 004abf01  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abf03  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004abf07  eb82                   -jmp 0x4abe8b
    goto L_0x004abe8b;
L_0x004abf09:
    // 004abf09  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004abf0e  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004abf13  e8b0fdffff             -call 0x4abcc8
    cpu.esp -= 4;
    sub_4abcc8(app, cpu);
    if (cpu.terminate) return;
    // 004abf18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004abf1a  750e                   -jne 0x4abf2a
    if (!cpu.flags.zf)
    {
        goto L_0x004abf2a;
    }
    // 004abf1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abf21  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004abf25  e961ffffff             -jmp 0x4abe8b
    goto L_0x004abe8b;
L_0x004abf2a:
    // 004abf2a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004abf2c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004abf30  e956ffffff             -jmp 0x4abe8b
    goto L_0x004abe8b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4abf38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004abf38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004abf39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004abf3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004abf3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004abf3d  8a2588ab4d00           -mov ah, byte ptr [0x4dab88]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004abf43  8a155d3d5600           -mov dl, byte ptr [0x563d5d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */);
    // 004abf49  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004abf4c  0f8499000000           -je 0x4abfeb
    if (cpu.flags.zf)
    {
        goto L_0x004abfeb;
    }
    // 004abf52  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004abf54:
    // 004abf54  8a1d88ab4d00           -mov bl, byte ptr [0x4dab88]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004abf5a  a25d3d5600             -mov byte ptr [0x563d5d], al
    app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */) = cpu.al;
    // 004abf5f  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 004abf62  0f848a000000           -je 0x4abff2
    if (cpu.flags.zf)
    {
        goto L_0x004abff2;
    }
    // 004abf68  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 004abf6a  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004abf6c  b302                   -mov bl, 2
    cpu.bl = 2 /*0x2*/;
    // 004abf6e  880d363d5600           -mov byte ptr [0x563d36], cl
    app->getMemory<x86::reg8>(x86::reg32(5651766) /* 0x563d36 */) = cpu.cl;
    // 004abf74  880d353d5600           -mov byte ptr [0x563d35], cl
    app->getMemory<x86::reg8>(x86::reg32(5651765) /* 0x563d35 */) = cpu.cl;
    // 004abf7a  880d343d5600           -mov byte ptr [0x563d34], cl
    app->getMemory<x86::reg8>(x86::reg32(5651764) /* 0x563d34 */) = cpu.cl;
    // 004abf80  88255e3d5600           -mov byte ptr [0x563d5e], ah
    app->getMemory<x86::reg8>(x86::reg32(5651806) /* 0x563d5e */) = cpu.ah;
    // 004abf86  881d373d5600           -mov byte ptr [0x563d37], bl
    app->getMemory<x86::reg8>(x86::reg32(5651767) /* 0x563d37 */) = cpu.bl;
    // 004abf8c  881d633d5600           -mov byte ptr [0x563d63], bl
    app->getMemory<x86::reg8>(x86::reg32(5651811) /* 0x563d63 */) = cpu.bl;
L_0x004abf92:
    // 004abf92  a1e8ab4d00             -mov eax, dword ptr [0x4dabe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 004abf97  8b0d5cab4d00           -mov ecx, dword ptr [0x4dab5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
    // 004abf9d  a320395600             -mov dword ptr [0x563920], eax
    app->getMemory<x86::reg32>(x86::reg32(5650720) /* 0x563920 */) = cpu.eax;
    // 004abfa2  83f907                 +cmp ecx, 7
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
    // 004abfa5  7427                   -je 0x4abfce
    if (cpu.flags.zf)
    {
        goto L_0x004abfce;
    }
    // 004abfa7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004abfa8  e843f1feff             -call 0x49b0f0
    cpu.esp -= 4;
    sub_49b0f0(app, cpu);
    if (cpu.terminate) return;
    // 004abfad  b830c24a00             -mov eax, 0x4ac230
    cpu.eax = 4899376 /*0x4ac230*/;
    // 004abfb2  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 004abfb7  be7cbd4a00             -mov esi, 0x4abd7c
    cpu.esi = 4898172 /*0x4abd7c*/;
    // 004abfbc  e8dfedfeff             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 004abfc1  891d5cab4d00           -mov dword ptr [0x4dab5c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */) = cpu.ebx;
    // 004abfc7  893504ac4d00           -mov dword ptr [0x4dac04], esi
    app->getMemory<x86::reg32>(x86::reg32(5090308) /* 0x4dac04 */) = cpu.esi;
    // 004abfcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004abfce:
    // 004abfce  e8e964fdff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004abfd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004abfd5  a05d3d5600             -mov al, byte ptr [0x563d5d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */);
    // 004abfda  39c2                   +cmp edx, eax
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
    // 004abfdc  0f8485000000           -je 0x4ac067
    if (cpu.flags.zf)
    {
        goto L_0x004ac067;
    }
    // 004abfe2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004abfe7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfe8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfe9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004abfea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004abfeb:
    // 004abfeb  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004abfed  e962ffffff             -jmp 0x4abf54
    goto L_0x004abf54;
L_0x004abff2:
    // 004abff2  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004abff5  7451                   -je 0x4ac048
    if (cpu.flags.zf)
    {
        goto L_0x004ac048;
    }
    // 004abff7  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004abff9:
    // 004abff9  8a0d88ab4d00           -mov cl, byte ptr [0x4dab88]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004abfff  a2363d5600             -mov byte ptr [0x563d36], al
    app->getMemory<x86::reg8>(x86::reg32(5651766) /* 0x563d36 */) = cpu.al;
    // 004ac004  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004ac007  7443                   -je 0x4ac04c
    if (cpu.flags.zf)
    {
        goto L_0x004ac04c;
    }
    // 004ac009  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004ac00b:
    // 004ac00b  8a2d88ab4d00           -mov ch, byte ptr [0x4dab88]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac011  a2353d5600             -mov byte ptr [0x563d35], al
    app->getMemory<x86::reg8>(x86::reg32(5651765) /* 0x563d35 */) = cpu.al;
    // 004ac016  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004ac019  7435                   -je 0x4ac050
    if (cpu.flags.zf)
    {
        goto L_0x004ac050;
    }
    // 004ac01b  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004ac01d:
    // 004ac01d  a2343d5600             -mov byte ptr [0x563d34], al
    app->getMemory<x86::reg8>(x86::reg32(5651764) /* 0x563d34 */) = cpu.al;
    // 004ac022  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004ac024  a25e3d5600             -mov byte ptr [0x563d5e], al
    app->getMemory<x86::reg8>(x86::reg32(5651806) /* 0x563d5e */) = cpu.al;
    // 004ac029  a08cab4d00             -mov al, byte ptr [0x4dab8c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5090188) /* 0x4dab8c */);
    // 004ac02e  a2373d5600             -mov byte ptr [0x563d37], al
    app->getMemory<x86::reg8>(x86::reg32(5651767) /* 0x563d37 */) = cpu.al;
    // 004ac033  f60588ab4d0040         +test byte ptr [0x4dab88], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5090184) /* 0x4dab88 */) & 64 /*0x40*/));
    // 004ac03a  7418                   -je 0x4ac054
    if (cpu.flags.zf)
    {
        goto L_0x004ac054;
    }
L_0x004ac03c:
    // 004ac03c  c605633d560001         -mov byte ptr [0x563d63], 1
    app->getMemory<x86::reg8>(x86::reg32(5651811) /* 0x563d63 */) = 1 /*0x1*/;
    // 004ac043  e94affffff             -jmp 0x4abf92
    goto L_0x004abf92;
L_0x004ac048:
    // 004ac048  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004ac04a  ebad                   -jmp 0x4abff9
    goto L_0x004abff9;
L_0x004ac04c:
    // 004ac04c  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004ac04e  ebbb                   -jmp 0x4ac00b
    goto L_0x004ac00b;
L_0x004ac050:
    // 004ac050  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004ac052  ebc9                   -jmp 0x4ac01d
    goto L_0x004ac01d;
L_0x004ac054:
    // 004ac054  803d363d560000         +cmp byte ptr [0x563d36], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5651766) /* 0x563d36 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ac05b  75df                   -jne 0x4ac03c
    if (!cpu.flags.zf)
    {
        goto L_0x004ac03c;
    }
    // 004ac05d  a2633d5600             -mov byte ptr [0x563d63], al
    app->getMemory<x86::reg8>(x86::reg32(5651811) /* 0x563d63 */) = cpu.al;
    // 004ac062  e92bffffff             -jmp 0x4abf92
    goto L_0x004abf92;
L_0x004ac067:
    // 004ac067  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac069  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac06a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac06b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac06c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ac070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac071  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac072  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac073  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac075  a05c3d5600             -mov al, byte ptr [0x563d5c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651804) /* 0x563d5c */);
    // 004ac07a  8b154c3d5600           -mov edx, dword ptr [0x563d4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5651788) /* 0x563d4c */);
    // 004ac080  a384ab4d00             -mov dword ptr [0x4dab84], eax
    app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */) = cpu.eax;
    // 004ac085  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac087  7405                   -je 0x4ac08e
    if (cpu.flags.zf)
    {
        goto L_0x004ac08e;
    }
    // 004ac089  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac08e:
    // 004ac08e  833d503d560000         +cmp dword ptr [0x563d50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5651792) /* 0x563d50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac095  7470                   -je 0x4ac107
    if (cpu.flags.zf)
    {
        goto L_0x004ac107;
    }
    // 004ac097  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ac09c:
    // 004ac09c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac09e  a114395600             -mov eax, dword ptr [0x563914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650708) /* 0x563914 */);
    // 004ac0a3  a37cab4d00             -mov dword ptr [0x4dab7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */) = cpu.eax;
    // 004ac0a8  a118395600             -mov eax, dword ptr [0x563918]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650712) /* 0x563918 */);
    // 004ac0ad  a380ab4d00             -mov dword ptr [0x4dab80], eax
    app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */) = cpu.eax;
    // 004ac0b2  a10c395600             -mov eax, dword ptr [0x56390c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650700) /* 0x56390c */);
    // 004ac0b7  8b1d94ab4d00           -mov ebx, dword ptr [0x4dab94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090196) /* 0x4dab94 */);
    // 004ac0bd  a390ab4d00             -mov dword ptr [0x4dab90], eax
    app->getMemory<x86::reg32>(x86::reg32(5090192) /* 0x4dab90 */) = cpu.eax;
    // 004ac0c2  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004ac0c7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac0c9  8b3598ab4d00           -mov esi, dword ptr [0x4dab98]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090200) /* 0x4dab98 */);
    // 004ac0cf  a39cab4d00             -mov dword ptr [0x4dab9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090204) /* 0x4dab9c */) = cpu.eax;
    // 004ac0d4  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004ac0d9  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ac0db  a3a0ab4d00             -mov dword ptr [0x4daba0], eax
    app->getMemory<x86::reg32>(x86::reg32(5090208) /* 0x4daba0 */) = cpu.eax;
    // 004ac0e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac0e2  a0633d5600             -mov al, byte ptr [0x563d63]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651811) /* 0x563d63 */);
    // 004ac0e7  a310ef4d00             -mov dword ptr [0x4def10], eax
    app->getMemory<x86::reg32>(x86::reg32(5107472) /* 0x4def10 */) = cpu.eax;
    // 004ac0ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac0ee  a0623d5600             -mov al, byte ptr [0x563d62]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651810) /* 0x563d62 */);
    // 004ac0f3  89158cab4d00           -mov dword ptr [0x4dab8c], edx
    app->getMemory<x86::reg32>(x86::reg32(5090188) /* 0x4dab8c */) = cpu.edx;
    // 004ac0f9  a314ef4d00             -mov dword ptr [0x4def14], eax
    app->getMemory<x86::reg32>(x86::reg32(5107476) /* 0x4def14 */) = cpu.eax;
    // 004ac0fe  e8b963fdff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004ac103  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac104  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac105  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac106  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac107:
    // 004ac107  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ac109  eb91                   -jmp 0x4ac09c
    goto L_0x004ac09c;
}

/* align: skip 0x90 */
void Application::sub_4ac10c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac10c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac10d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac10e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac10f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac110  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac111  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac113  8b1500395600           -mov edx, dword ptr [0x563900]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650688) /* 0x563900 */);
    // 004ac119  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ac11b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac11d  0f85c7000000           -jne 0x4ac1ea
    if (!cpu.flags.zf)
    {
        goto L_0x004ac1ea;
    }
    // 004ac123  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ac128:
    // 004ac128  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ac12a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac12c  0f84bf000000           -je 0x4ac1f1
    if (cpu.flags.zf)
    {
        goto L_0x004ac1f1;
    }
L_0x004ac132:
    // 004ac132  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ac137:
    // 004ac137  6840bb4a00             -push 0x4abb40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4897600 /*0x4abb40*/;
    cpu.esp -= 4;
    // 004ac13c  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 004ac141  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac143  e82861fdff             -call 0x482270
    cpu.esp -= 4;
    sub_482270(app, cpu);
    if (cpu.terminate) return;
    // 004ac148  68d4bb4a00             -push 0x4abbd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4897748 /*0x4abbd4*/;
    cpu.esp -= 4;
    // 004ac14d  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 004ac152  e81961fdff             -call 0x482270
    cpu.esp -= 4;
    sub_482270(app, cpu);
    if (cpu.terminate) return;
    // 004ac157  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ac159  742f                   -je 0x4ac18a
    if (cpu.flags.zf)
    {
        goto L_0x004ac18a;
    }
    // 004ac15b  803d5d3d560000         +cmp byte ptr [0x563d5d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ac162  7426                   -je 0x4ac18a
    if (cpu.flags.zf)
    {
        goto L_0x004ac18a;
    }
    // 004ac164  833d1439560000         +cmp dword ptr [0x563914], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650708) /* 0x563914 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac16b  750a                   -jne 0x4ac177
    if (!cpu.flags.zf)
    {
        goto L_0x004ac177;
    }
    // 004ac16d  c7051439560080020000   -mov dword ptr [0x563914], 0x280
    app->getMemory<x86::reg32>(x86::reg32(5650708) /* 0x563914 */) = 640 /*0x280*/;
L_0x004ac177:
    // 004ac177  833d1839560000         +cmp dword ptr [0x563918], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650712) /* 0x563918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac17e  750a                   -jne 0x4ac18a
    if (!cpu.flags.zf)
    {
        goto L_0x004ac18a;
    }
    // 004ac180  c70518395600e0010000   -mov dword ptr [0x563918], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(5650712) /* 0x563918 */) = 480 /*0x1e0*/;
L_0x004ac18a:
    // 004ac18a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac18c  7438                   -je 0x4ac1c6
    if (cpu.flags.zf)
    {
        goto L_0x004ac1c6;
    }
    // 004ac18e  8b1518395600           -mov edx, dword ptr [0x563918]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650712) /* 0x563918 */);
    // 004ac194  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac196  a114395600             -mov eax, dword ptr [0x563914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650708) /* 0x563914 */);
    // 004ac19b  8a1d5d3d5600           -mov bl, byte ptr [0x563d5d]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */);
    // 004ac1a1  e8ba4afdff             -call 0x480c60
    cpu.esp -= 4;
    sub_480c60(app, cpu);
    if (cpu.terminate) return;
    // 004ac1a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac1a8  7454                   -je 0x4ac1fe
    if (cpu.flags.zf)
    {
        goto L_0x004ac1fe;
    }
    // 004ac1aa  b864040000             -mov eax, 0x464
    cpu.eax = 1124 /*0x464*/;
    // 004ac1af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac1b1  e812fbffff             -call 0x4abcc8
    cpu.esp -= 4;
    sub_4abcc8(app, cpu);
    if (cpu.terminate) return;
    // 004ac1b6  8b0d543d5600           -mov ecx, dword ptr [0x563d54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5651796) /* 0x563d54 */);
    // 004ac1bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac1bd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ac1bf  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ac1c6:
    // 004ac1c6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ac1c8  7411                   -je 0x4ac1db
    if (cpu.flags.zf)
    {
        goto L_0x004ac1db;
    }
    // 004ac1ca  bb7cf04d00             -mov ebx, 0x4df07c
    cpu.ebx = 5107836 /*0x4df07c*/;
    // 004ac1cf  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004ac1d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac1d6  e80d41ffff             -call 0x4a02e8
    cpu.esp -= 4;
    sub_4a02e8(app, cpu);
    if (cpu.terminate) return;
L_0x004ac1db:
    // 004ac1db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ac1dd  7526                   -jne 0x4ac205
    if (!cpu.flags.zf)
    {
        goto L_0x004ac205;
    }
    // 004ac1df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ac1e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac1e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac1ea:
    // 004ac1ea  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ac1ec  e937ffffff             -jmp 0x4ac128
    goto L_0x004ac128;
L_0x004ac1f1:
    // 004ac1f1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac1f3  0f8539ffffff           -jne 0x4ac132
    if (!cpu.flags.zf)
    {
        goto L_0x004ac132;
    }
    // 004ac1f9  e939ffffff             -jmp 0x4ac137
    goto L_0x004ac137;
L_0x004ac1fe:
    // 004ac1fe  be94154d00             -mov esi, 0x4d1594
    cpu.esi = 5051796 /*0x4d1594*/;
    // 004ac203  ebc1                   -jmp 0x4ac1c6
    goto L_0x004ac1c6;
L_0x004ac205:
    // 004ac205  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac207  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac208  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac209  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac20a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac20b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac20c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ac210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac210  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac211  8b150c395600           -mov edx, dword ptr [0x56390c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650700) /* 0x56390c */);
    // 004ac217  e88449fdff             -call 0x480ba0
    cpu.esp -= 4;
    sub_480ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ac21c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ac21e  e835040000             -call 0x4ac658
    cpu.esp -= 4;
    sub_4ac658(app, cpu);
    if (cpu.terminate) return;
    // 004ac223  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac224  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ac228(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac228  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ac22d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ac230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac230  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac231  e88662fdff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004ac236  833d9cd74d0000         +cmp dword ptr [0x4dd79c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5101468) /* 0x4dd79c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac23d  7544                   -jne 0x4ac283
    if (!cpu.flags.zf)
    {
        goto L_0x004ac283;
    }
    // 004ac23f  833d543d560000         +cmp dword ptr [0x563d54], 0
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
    // 004ac246  7543                   -jne 0x4ac28b
    if (!cpu.flags.zf)
    {
        goto L_0x004ac28b;
    }
L_0x004ac248:
    // 004ac248  833d5cab4d0007         +cmp dword ptr [0x4dab5c], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac24f  7530                   -jne 0x4ac281
    if (!cpu.flags.zf)
    {
        goto L_0x004ac281;
    }
    // 004ac251  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac252  8b35e4ab4d00           -mov esi, dword ptr [0x4dabe4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5090276) /* 0x4dabe4 */);
    // 004ac258  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ac25a  7411                   -je 0x4ac26d
    if (cpu.flags.zf)
    {
        goto L_0x004ac26d;
    }
    // 004ac25c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac25d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ac25f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ac261  e83a6bfdff             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
    // 004ac266  893de4ab4d00           -mov dword ptr [0x4dabe4], edi
    app->getMemory<x86::reg32>(x86::reg32(5090276) /* 0x4dabe4 */) = cpu.edi;
    // 004ac26c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ac26d:
    // 004ac26d  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004ac26f  e8d4eefeff             -call 0x49b148
    cpu.esp -= 4;
    sub_49b148(app, cpu);
    if (cpu.terminate) return;
    // 004ac274  892d5cab4d00           -mov dword ptr [0x4dab5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */) = cpu.ebp;
    // 004ac27a  892d04ac4d00           -mov dword ptr [0x4dac04], ebp
    app->getMemory<x86::reg32>(x86::reg32(5090308) /* 0x4dac04 */) = cpu.ebp;
    // 004ac280  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ac281:
    // 004ac281  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac282  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac283:
    // 004ac283  ff159cd74d00           -call dword ptr [0x4dd79c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5101468) /* 0x4dd79c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ac289  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac28a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac28b:
    // 004ac28b  e81049fdff             -call 0x480ba0
    cpu.esp -= 4;
    sub_480ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ac290  ebb6                   -jmp 0x4ac248
    goto L_0x004ac248;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ac294(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac294  833d0039560000         +cmp dword ptr [0x563900], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650688) /* 0x563900 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac29b  7406                   -je 0x4ac2a3
    if (cpu.flags.zf)
    {
        goto L_0x004ac2a3;
    }
    // 004ac29d  a108395600             -mov eax, dword ptr [0x563908]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650696) /* 0x563908 */);
    // 004ac2a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac2a3:
    // 004ac2a3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ac2a8  e8ab030000             -call 0x4ac658
    cpu.esp -= 4;
    sub_4ac658(app, cpu);
    if (cpu.terminate) return;
    // 004ac2ad  a108395600             -mov eax, dword ptr [0x563908]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650696) /* 0x563908 */);
    // 004ac2b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ac2b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac2b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac2b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac2b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac2b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac2b8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ac2ba  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ac2bc  833d0039560000         +cmp dword ptr [0x563900], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5650688) /* 0x563900 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac2c3  750a                   -jne 0x4ac2cf
    if (!cpu.flags.zf)
    {
        goto L_0x004ac2cf;
    }
    // 004ac2c5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ac2ca  e889030000             -call 0x4ac658
    cpu.esp -= 4;
    sub_4ac658(app, cpu);
    if (cpu.terminate) return;
L_0x004ac2cf:
    // 004ac2cf  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 004ac2d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ac2d6  e841ddfdff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 004ac2db  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac2dd  0f8cbe020000           -jl 0x4ac5a1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ac5a1;
    }
    // 004ac2e3  3b1d08395600           +cmp ebx, dword ptr [0x563908]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650696) /* 0x563908 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac2e9  0f8db2020000           -jge 0x4ac5a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ac5a1;
    }
    // 004ac2ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac2f0  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac2f7  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004ac2fa  a110395600             -mov eax, dword ptr [0x563910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac2ff  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ac302  8b3402                 -mov esi, dword ptr [edx + eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 004ac305  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 004ac307  8b740204               -mov esi, dword ptr [edx + eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004ac30b  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004ac30e  0fb6740213             -movzx esi, byte ptr [edx + eax + 0x13]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 1));
    // 004ac313  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004ac316  8a440212               -mov al, byte ptr [edx + eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */ + cpu.eax * 1);
    // 004ac31a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ac31f  e85c080000             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 004ac324  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ac327  a110395600             -mov eax, dword ptr [0x563910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac32c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac32e  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac331  f6420c08               +test byte ptr [edx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 004ac335  0f841c020000           -je 0x4ac557
    if (cpu.flags.zf)
    {
        goto L_0x004ac557;
    }
    // 004ac33b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac340:
    // 004ac340  8020fd                 -and byte ptr [eax], 0xfd
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004ac343  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac346  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004ac348  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ac34a  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac34c  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004ac34e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac355  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac357  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac35d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac360  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac362  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac365  f6420c04               +test byte ptr [edx + 0xc], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 4 /*0x4*/));
    // 004ac369  0f84ef010000           -je 0x4ac55e
    if (cpu.flags.zf)
    {
        goto L_0x004ac55e;
    }
    // 004ac36f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac374:
    // 004ac374  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac377  8020fb                 -and byte ptr [eax], 0xfb
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004ac37a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ac37d  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac37f  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac386  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004ac389  a110395600             -mov eax, dword ptr [0x563910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac38e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ac391  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac393  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac396  f6420c10               +test byte ptr [edx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 004ac39a  0f84c5010000           -je 0x4ac565
    if (cpu.flags.zf)
    {
        goto L_0x004ac565;
    }
    // 004ac3a0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac3a5:
    // 004ac3a5  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac3a8  8020f7                 -and byte ptr [eax], 0xf7
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004ac3ab  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004ac3ae  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac3b0  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac3b7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3b9  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac3bf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac3c2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac3c4  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac3c7  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 004ac3cb  0f849b010000           -je 0x4ac56c
    if (cpu.flags.zf)
    {
        goto L_0x004ac56c;
    }
    // 004ac3d1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac3d6:
    // 004ac3d6  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac3d9  8020ef                 -and byte ptr [eax], 0xef
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004ac3dc  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004ac3df  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac3e1  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac3e8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac3ea  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac3f0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac3f3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac3f5  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac3f8  f6420d08               +test byte ptr [edx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004ac3fc  0f8471010000           -je 0x4ac573
    if (cpu.flags.zf)
    {
        goto L_0x004ac573;
    }
    // 004ac402  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac407:
    // 004ac407  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac40a  806001f7               -and byte ptr [eax + 1], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004ac40e  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 004ac411  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac413  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac416  c1e01d                 -shl eax, 0x1d
    cpu.eax <<= 29 /*0x1d*/ % 32;
    // 004ac419  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004ac41c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac41e  0f8528010000           -jne 0x4ac54c
    if (!cpu.flags.zf)
    {
        goto L_0x004ac54c;
    }
    // 004ac424  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac42b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac42d  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac433  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac436  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac438  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac43b  f6420d04               +test byte ptr [edx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004ac43f  0f8435010000           -je 0x4ac57a
    if (cpu.flags.zf)
    {
        goto L_0x004ac57a;
    }
    // 004ac445  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac44a:
    // 004ac44a  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac44d  8020df                 -and byte ptr [eax], 0xdf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 004ac450  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004ac453  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac455  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac45c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac45e  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac464  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac467  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac469  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac46c  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004ac470  0f840b010000           -je 0x4ac581
    if (cpu.flags.zf)
    {
        goto L_0x004ac581;
    }
    // 004ac476  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac47b:
    // 004ac47b  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac47e  8020bf                 -and byte ptr [eax], 0xbf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 004ac481  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 004ac484  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac486  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac48d  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004ac490  a110395600             -mov eax, dword ptr [0x563910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac495  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ac498  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac49a  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac49d  f6420c80               +test byte ptr [edx + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 004ac4a1  0f84e1000000           -je 0x4ac588
    if (cpu.flags.zf)
    {
        goto L_0x004ac588;
    }
    // 004ac4a7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac4ac:
    // 004ac4ac  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac4af  80207f                 -and byte ptr [eax], 0x7f
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004ac4b2  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 004ac4b5  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac4b7  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac4be  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004ac4c1  a110395600             -mov eax, dword ptr [0x563910]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac4c6  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ac4c9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac4cb  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac4ce  f6420d01               +test byte ptr [edx + 0xd], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 1 /*0x1*/));
    // 004ac4d2  0f84b7000000           -je 0x4ac58f
    if (cpu.flags.zf)
    {
        goto L_0x004ac58f;
    }
    // 004ac4d8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac4dd:
    // 004ac4dd  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac4e0  806001fe               -and byte ptr [eax + 1], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004ac4e4  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004ac4e7  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac4e9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac4f0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac4f2  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac4f8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac4fb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac4fd  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac500  f6420d02               +test byte ptr [edx + 0xd], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 2 /*0x2*/));
    // 004ac504  0f848c000000           -je 0x4ac596
    if (cpu.flags.zf)
    {
        goto L_0x004ac596;
    }
    // 004ac50a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac50f:
    // 004ac50f  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac512  806001fd               -and byte ptr [eax + 1], 0xfd
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004ac516  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004ac519  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac51b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ac522  8b1510395600           -mov edx, dword ptr [0x563910]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5650704) /* 0x563910 */);
    // 004ac528  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac52a  8a5c820c               -mov bl, byte ptr [edx + eax*4 + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 004ac52e  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ac531  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004ac534  7467                   -je 0x4ac59d
    if (cpu.flags.zf)
    {
        goto L_0x004ac59d;
    }
    // 004ac536  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ac53b:
    // 004ac53b  8a7901                 -mov bh, byte ptr [ecx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004ac53e  80e7fb                 -and bh, 0xfb
    cpu.bh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004ac541  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac544  887901                 -mov byte ptr [ecx + 1], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bh;
    // 004ac547  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004ac54a  0901                   -or dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ac54c:
    // 004ac54c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ac551  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac552  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac553  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac554  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac555  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac556  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac557:
    // 004ac557  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac559  e9e2fdffff             -jmp 0x4ac340
    goto L_0x004ac340;
L_0x004ac55e:
    // 004ac55e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac560  e90ffeffff             -jmp 0x4ac374
    goto L_0x004ac374;
L_0x004ac565:
    // 004ac565  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac567  e939feffff             -jmp 0x4ac3a5
    goto L_0x004ac3a5;
L_0x004ac56c:
    // 004ac56c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac56e  e963feffff             -jmp 0x4ac3d6
    goto L_0x004ac3d6;
L_0x004ac573:
    // 004ac573  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac575  e98dfeffff             -jmp 0x4ac407
    goto L_0x004ac407;
L_0x004ac57a:
    // 004ac57a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac57c  e9c9feffff             -jmp 0x4ac44a
    goto L_0x004ac44a;
L_0x004ac581:
    // 004ac581  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac583  e9f3feffff             -jmp 0x4ac47b
    goto L_0x004ac47b;
L_0x004ac588:
    // 004ac588  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac58a  e91dffffff             -jmp 0x4ac4ac
    goto L_0x004ac4ac;
L_0x004ac58f:
    // 004ac58f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac591  e947ffffff             -jmp 0x4ac4dd
    goto L_0x004ac4dd;
L_0x004ac596:
    // 004ac596  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac598  e972ffffff             -jmp 0x4ac50f
    goto L_0x004ac50f;
L_0x004ac59d:
    // 004ac59d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ac59f  eb9a                   -jmp 0x4ac53b
    goto L_0x004ac53b;
L_0x004ac5a1:
    // 004ac5a1  83fbff                 +cmp ebx, -1
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
    // 004ac5a4  0f85a7000000           -jne 0x4ac651
    if (!cpu.flags.zf)
    {
        goto L_0x004ac651;
    }
    // 004ac5aa  803d5d3d560000         +cmp byte ptr [0x563d5d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5651805) /* 0x563d5d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ac5b1  0f859a000000           -jne 0x4ac651
    if (!cpu.flags.zf)
    {
        goto L_0x004ac651;
    }
    // 004ac5b7  a114395600             -mov eax, dword ptr [0x563914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650708) /* 0x563914 */);
    // 004ac5bc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004ac5be  a118395600             -mov eax, dword ptr [0x563918]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5650712) /* 0x563918 */);
    // 004ac5c3  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ac5c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac5c8  a05c3d5600             -mov al, byte ptr [0x563d5c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651804) /* 0x563d5c */);
    // 004ac5cd  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ac5d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac5d2  a095b24d00             -mov al, byte ptr [0x4db295]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091989) /* 0x4db295 */);
    // 004ac5d7  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac5da  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ac5dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac5df  80e2fd                 -and dl, 0xfd
    cpu.dl &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004ac5e2  a0623d5600             -mov al, byte ptr [0x563d62]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651810) /* 0x563d62 */);
    // 004ac5e7  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004ac5ea  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac5ed  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac5f0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ac5f2  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac5f4  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004ac5f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac5f9  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac5fc  a05f3d5600             -mov al, byte ptr [0x563d5f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5651807) /* 0x563d5f */);
    // 004ac601  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004ac604  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac607  887110                 -mov byte ptr [ecx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 004ac60a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ac60d  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ac610  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ac613  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac615  8a1d633d5600           -mov bl, byte ptr [0x563d63]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5651811) /* 0x563d63 */);
    // 004ac61b  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 004ac61d  80fb01                 +cmp bl, 1
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
    // 004ac620  762b                   -jbe 0x4ac64d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ac64d;
    }
    // 004ac622  803d603d560000         +cmp byte ptr [0x563d60], 0
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
    // 004ac629  7422                   -je 0x4ac64d
    if (cpu.flags.zf)
    {
        goto L_0x004ac64d;
    }
    // 004ac62b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ac630:
    // 004ac630  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ac632  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004ac635  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ac638  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004ac63a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ac63d  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ac63f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac641  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ac646  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004ac648  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac649  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac64a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac64b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac64c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac64d:
    // 004ac64d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ac64f  ebdf                   -jmp 0x4ac630
    goto L_0x004ac630;
L_0x004ac651:
    // 004ac651  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac653  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac654  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac655  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac656  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac657  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ac658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac658  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac659  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ac65b  e8d8f8ffff             -call 0x4abf38
    cpu.esp -= 4;
    sub_4abf38(app, cpu);
    if (cpu.terminate) return;
    // 004ac660  e8a7faffff             -call 0x4ac10c
    cpu.esp -= 4;
    sub_4ac10c(app, cpu);
    if (cpu.terminate) return;
    // 004ac665  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac667  7441                   -je 0x4ac6aa
    if (cpu.flags.zf)
    {
        goto L_0x004ac6aa;
    }
    // 004ac669  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac66b  7c08                   -jl 0x4ac675
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ac675;
    }
    // 004ac66d  3b1508395600           +cmp edx, dword ptr [0x563908]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5650696) /* 0x563908 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac673  7c05                   -jl 0x4ac67a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ac67a;
    }
L_0x004ac675:
    // 004ac675  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004ac67a:
    // 004ac67a  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004ac67f  e844f6ffff             -call 0x4abcc8
    cpu.esp -= 4;
    sub_4abcc8(app, cpu);
    if (cpu.terminate) return;
    // 004ac684  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac686  751e                   -jne 0x4ac6a6
    if (!cpu.flags.zf)
    {
        goto L_0x004ac6a6;
    }
    // 004ac688  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ac68d:
    // 004ac68d  e8def9ffff             -call 0x4ac070
    cpu.esp -= 4;
    sub_4ac070(app, cpu);
    if (cpu.terminate) return;
    // 004ac692  833d5cab4d0007         +cmp dword ptr [0x4dab5c], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac699  7514                   -jne 0x4ac6af
    if (!cpu.flags.zf)
    {
        goto L_0x004ac6af;
    }
    // 004ac69b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac69d  7410                   -je 0x4ac6af
    if (cpu.flags.zf)
    {
        goto L_0x004ac6af;
    }
    // 004ac69f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ac6a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac6a6:
    // 004ac6a6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ac6a8  ebe3                   -jmp 0x4ac68d
    goto L_0x004ac68d;
L_0x004ac6aa:
    // 004ac6aa  a35cab4d00             -mov dword ptr [0x4dab5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */) = cpu.eax;
L_0x004ac6af:
    // 004ac6af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac6b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ac6b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac6b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac6b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac6b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac6b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac6b8  8b3d88ab4d00           -mov edi, dword ptr [0x4dab88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac6be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ac6c0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ac6c2  8b2da0d74d00           -mov ebp, dword ptr [0x4dd7a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5101472) /* 0x4dd7a0 */);
    // 004ac6c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ac6ca  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ac6cc  7530                   -jne 0x4ac6fe
    if (!cpu.flags.zf)
    {
        goto L_0x004ac6fe;
    }
    // 004ac6ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac6d0  7536                   -jne 0x4ac708
    if (!cpu.flags.zf)
    {
        goto L_0x004ac708;
    }
    // 004ac6d2  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x004ac6d7:
    // 004ac6d7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ac6d9  7539                   -jne 0x4ac714
    if (!cpu.flags.zf)
    {
        goto L_0x004ac714;
    }
    // 004ac6db  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
L_0x004ac6e0:
    // 004ac6e0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac6e2  753c                   -jne 0x4ac720
    if (!cpu.flags.zf)
    {
        goto L_0x004ac720;
    }
L_0x004ac6e4:
    // 004ac6e4  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004ac6e9:
    // 004ac6e9  893d88ab4d00           -mov dword ptr [0x4dab88], edi
    app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */) = cpu.edi;
    // 004ac6ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac6f1  7439                   -je 0x4ac72c
    if (cpu.flags.zf)
    {
        goto L_0x004ac72c;
    }
L_0x004ac6f3:
    // 004ac6f3  8b3d88ab4d00           -mov edi, dword ptr [0x4dab88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac6f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac6fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac6fe:
    // 004ac6fe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ac700  ff15a0d74d00           -call dword ptr [0x4dd7a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5101472) /* 0x4dd7a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ac706  ebeb                   -jmp 0x4ac6f3
    goto L_0x004ac6f3;
L_0x004ac708:
    // 004ac708  83f8ff                 +cmp eax, -1
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
    // 004ac70b  75ca                   -jne 0x4ac6d7
    if (!cpu.flags.zf)
    {
        goto L_0x004ac6d7;
    }
    // 004ac70d  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 004ac712  ebc3                   -jmp 0x4ac6d7
    goto L_0x004ac6d7;
L_0x004ac714:
    // 004ac714  83feff                 +cmp esi, -1
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
    // 004ac717  75c7                   -jne 0x4ac6e0
    if (!cpu.flags.zf)
    {
        goto L_0x004ac6e0;
    }
    // 004ac719  be00030000             -mov esi, 0x300
    cpu.esi = 768 /*0x300*/;
    // 004ac71e  ebc0                   -jmp 0x4ac6e0
    goto L_0x004ac6e0;
L_0x004ac720:
    // 004ac720  83fbff                 +cmp ebx, -1
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
    // 004ac723  74bf                   -je 0x4ac6e4
    if (cpu.flags.zf)
    {
        goto L_0x004ac6e4;
    }
    // 004ac725  83fb0f                 +cmp ebx, 0xf
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
    // 004ac728  75bf                   -jne 0x4ac6e9
    if (!cpu.flags.zf)
    {
        goto L_0x004ac6e9;
    }
    // 004ac72a  ebb8                   -jmp 0x4ac6e4
    goto L_0x004ac6e4;
L_0x004ac72c:
    // 004ac72c  e807f8ffff             -call 0x4abf38
    cpu.esp -= 4;
    sub_4abf38(app, cpu);
    if (cpu.terminate) return;
    // 004ac731  890d14395600           -mov dword ptr [0x563914], ecx
    app->getMemory<x86::reg32>(x86::reg32(5650708) /* 0x563914 */) = cpu.ecx;
    // 004ac737  893518395600           -mov dword ptr [0x563918], esi
    app->getMemory<x86::reg32>(x86::reg32(5650712) /* 0x563918 */) = cpu.esi;
    // 004ac73d  891d1c395600           -mov dword ptr [0x56391c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5650716) /* 0x56391c */) = cpu.ebx;
    // 004ac743  881d5c3d5600           -mov byte ptr [0x563d5c], bl
    app->getMemory<x86::reg8>(x86::reg32(5651804) /* 0x563d5c */) = cpu.bl;
    // 004ac749  e8bef9ffff             -call 0x4ac10c
    cpu.esp -= 4;
    sub_4ac10c(app, cpu);
    if (cpu.terminate) return;
    // 004ac74e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac750  7511                   -jne 0x4ac763
    if (!cpu.flags.zf)
    {
        goto L_0x004ac763;
    }
    // 004ac752  89155cab4d00           -mov dword ptr [0x4dab5c], edx
    app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */) = cpu.edx;
    // 004ac758  8b3d88ab4d00           -mov edi, dword ptr [0x4dab88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac75e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac75f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac761  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac762  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac763:
    // 004ac763  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004ac768  e86bf6ffff             -call 0x4abdd8
    cpu.esp -= 4;
    sub_4abdd8(app, cpu);
    if (cpu.terminate) return;
    // 004ac76d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ac76f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac771  7527                   -jne 0x4ac79a
    if (!cpu.flags.zf)
    {
        goto L_0x004ac79a;
    }
    // 004ac773  8b3d88ab4d00           -mov edi, dword ptr [0x4dab88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac779  66f7c78000             +test di, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & 128 /*0x80*/));
    // 004ac77e  750a                   -jne 0x4ac78a
    if (!cpu.flags.zf)
    {
        goto L_0x004ac78a;
    }
    // 004ac780  6681cf8000             +or di, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(128 /*0x80*/))));
    // 004ac785  e95fffffff             -jmp 0x4ac6e9
    goto L_0x004ac6e9;
L_0x004ac78a:
    // 004ac78a  a35cab4d00             -mov dword ptr [0x4dab5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */) = cpu.eax;
    // 004ac78f  8b3d88ab4d00           -mov edi, dword ptr [0x4dab88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac795  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac796  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac797  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac798  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac799  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac79a:
    // 004ac79a  e8d1f8ffff             -call 0x4ac070
    cpu.esp -= 4;
    sub_4ac070(app, cpu);
    if (cpu.terminate) return;
    // 004ac79f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac7a1  7489                   -je 0x4ac72c
    if (cpu.flags.zf)
    {
        goto L_0x004ac72c;
    }
    // 004ac7a3  8b3d88ab4d00           -mov edi, dword ptr [0x4dab88]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5090184) /* 0x4dab88 */);
    // 004ac7a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ac7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac7b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac7b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac7b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac7b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac7b4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac7b7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ac7b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac7bb  8b3500395600           -mov esi, dword ptr [0x563900]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5650688) /* 0x563900 */);
    // 004ac7c1  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ac7c4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ac7c6  7419                   -je 0x4ac7e1
    if (cpu.flags.zf)
    {
        goto L_0x004ac7e1;
    }
L_0x004ac7c8:
    // 004ac7c8  833d5cab4d0000         +cmp dword ptr [0x4dab5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090140) /* 0x4dab5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac7cf  751c                   -jne 0x4ac7ed
    if (!cpu.flags.zf)
    {
        goto L_0x004ac7ed;
    }
L_0x004ac7d1:
    // 004ac7d1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ac7d3  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004ac7d6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac7d9  83c404                 +add esp, 4
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
    // 004ac7dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac7e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac7e1:
    // 004ac7e1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ac7e6  e86dfeffff             -call 0x4ac658
    cpu.esp -= 4;
    sub_4ac658(app, cpu);
    if (cpu.terminate) return;
    // 004ac7eb  ebdb                   -jmp 0x4ac7c8
    goto L_0x004ac7c8;
L_0x004ac7ed:
    // 004ac7ed  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004ac7f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac7f3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac7f5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ac7f7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ac7fb  e82c45feff             -call 0x490d2c
    cpu.esp -= 4;
    sub_490d2c(app, cpu);
    if (cpu.terminate) return;
    // 004ac800  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac802  74cd                   -je 0x4ac7d1
    if (cpu.flags.zf)
    {
        goto L_0x004ac7d1;
    }
    // 004ac804  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac807  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac80a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac80b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac80c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac80d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac80e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ac810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac810  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac811  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac812  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac813  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac816  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ac818  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ac81a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004ac81c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ac820  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ac822  7506                   -jne 0x4ac82a
    if (!cpu.flags.zf)
    {
        goto L_0x004ac82a;
    }
    // 004ac824  8b0d84ab4d00           -mov ecx, dword ptr [0x4dab84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
L_0x004ac82a:
    // 004ac82a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ac82c  7505                   -jne 0x4ac833
    if (!cpu.flags.zf)
    {
        goto L_0x004ac833;
    }
    // 004ac82e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x004ac833:
    // 004ac833  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004ac836  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004ac838  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004ac83d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ac840  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ac842  e8d5d7fdff             -call 0x48a01c
    cpu.esp -= 4;
    sub_48a01c(app, cpu);
    if (cpu.terminate) return;
    // 004ac847  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 004ac84d  c6461eff               -mov byte ptr [esi + 0x1e], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */) = 255 /*0xff*/;
    // 004ac851  896e28                 -mov dword ptr [esi + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004ac854  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004ac857  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004ac85a  897e14                 -mov dword ptr [esi + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004ac85d  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ac860  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ac862  884e1c                 -mov byte ptr [esi + 0x1c], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cl;
    // 004ac865  e816030000             -call 0x4acb80
    cpu.esp -= 4;
    sub_4acb80(app, cpu);
    if (cpu.terminate) return;
    // 004ac86a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ac86c  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 004ac86f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ac873  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ac875  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004ac878  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ac87c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac87e  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004ac881  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac883  e8ece8feff             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 004ac888  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004ac88d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ac890  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004ac892  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004ac895  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac897  e8d8e8feff             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 004ac89c  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004ac89f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac8a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8a5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4ac8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac8a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac8a9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac8aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac8ab  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac8ae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ac8b0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ac8b2  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ac8b5  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ac8b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac8bb  7c26                   -jl 0x4ac8e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ac8e3;
    }
    // 004ac8bd  3d00050000             +cmp eax, 0x500
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
    // 004ac8c2  7f1f                   -jg 0x4ac8e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac8e3;
    }
    // 004ac8c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ac8c6  7c1b                   -jl 0x4ac8e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ac8e3;
    }
    // 004ac8c8  81fa00040000           +cmp edx, 0x400
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
    // 004ac8ce  7f13                   -jg 0x4ac8e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac8e3;
    }
    // 004ac8d0  83fbff                 +cmp ebx, -1
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
    // 004ac8d3  7519                   -jne 0x4ac8ee
    if (!cpu.flags.zf)
    {
        goto L_0x004ac8ee;
    }
    // 004ac8d5  be78b24d00             -mov esi, 0x4db278
    cpu.esi = 5091960 /*0x4db278*/;
L_0x004ac8da:
    // 004ac8da  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ac8dc  752f                   -jne 0x4ac90d
    if (!cpu.flags.zf)
    {
        goto L_0x004ac90d;
    }
    // 004ac8de  e85982fdff             -call 0x484b3c
    cpu.esp -= 4;
    sub_484b3c(app, cpu);
    if (cpu.terminate) return;
L_0x004ac8e3:
    // 004ac8e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac8e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac8e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac8eb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004ac8ee:
    // 004ac8ee  83fbfe                 +cmp ebx, -2
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
    // 004ac8f1  7507                   -jne 0x4ac8fa
    if (!cpu.flags.zf)
    {
        goto L_0x004ac8fa;
    }
    // 004ac8f3  beb0b24d00             -mov esi, 0x4db2b0
    cpu.esi = 5092016 /*0x4db2b0*/;
    // 004ac8f8  ebe0                   -jmp 0x4ac8da
    goto L_0x004ac8da;
L_0x004ac8fa:
    // 004ac8fa  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004ac8ff  b824164d00             -mov eax, 0x4d1624
    cpu.eax = 5051940 /*0x4d1624*/;
    // 004ac904  e88f7bfdff             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004ac909  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ac90b  ebcd                   -jmp 0x4ac8da
    goto L_0x004ac8da;
L_0x004ac90d:
    // 004ac90d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ac911  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac912  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ac916  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac917  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ac919  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ac91b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac91c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004ac91e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ac922  e8e9feffff             -call 0x4ac810
    cpu.esp -= 4;
    sub_4ac810(app, cpu);
    if (cpu.terminate) return;
    // 004ac927  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ac929  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ac92c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac92d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac92e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac92f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ac934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac934  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac935  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ac936  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ac937  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ac938  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ac93a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ac93c  7505                   -jne 0x4ac943
    if (!cpu.flags.zf)
    {
        goto L_0x004ac943;
    }
    // 004ac93e  be40b24d00             -mov esi, 0x4db240
    cpu.esi = 5091904 /*0x4db240*/;
L_0x004ac943:
    // 004ac943  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ac946  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004ac949  39ca                   +cmp edx, ecx
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
    // 004ac94b  7420                   -je 0x4ac96d
    if (cpu.flags.zf)
    {
        goto L_0x004ac96d;
    }
    // 004ac94d  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004ac950  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac952  7407                   -je 0x4ac95b
    if (cpu.flags.zf)
    {
        goto L_0x004ac95b;
    }
    // 004ac954  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ac956  e8f1e8feff             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
L_0x004ac95b:
    // 004ac95b  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ac95e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ac960  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ac962  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004ac965  e80ae8feff             -call 0x49b174
    cpu.esp -= 4;
    sub_49b174(app, cpu);
    if (cpu.terminate) return;
    // 004ac96a  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004ac96d:
    // 004ac96d  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ac970  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac973  39f8                   +cmp eax, edi
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
    // 004ac975  7e03                   -jle 0x4ac97a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ac97a;
    }
    // 004ac977  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x004ac97a:
    // 004ac97a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ac97d  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ac980  39e8                   +cmp eax, ebp
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
    // 004ac982  7e03                   -jle 0x4ac987
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ac987;
    }
    // 004ac984  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x004ac987:
    // 004ac987  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ac98a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ac98d  39d0                   +cmp eax, edx
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
    // 004ac98f  7e19                   -jle 0x4ac9aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ac9aa;
    }
    // 004ac991  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x004ac994:
    // 004ac994  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ac997  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ac99a  39d8                   +cmp eax, ebx
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
    // 004ac99c  7f18                   -jg 0x4ac9b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ac9b6;
    }
    // 004ac99e  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ac9a1  39f8                   +cmp eax, edi
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
    // 004ac9a3  7c19                   -jl 0x4ac9be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ac9be;
    }
    // 004ac9a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac9aa:
    // 004ac9aa  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ac9ad  39c8                   +cmp eax, ecx
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
    // 004ac9af  7de3                   -jge 0x4ac994
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ac994;
    }
    // 004ac9b1  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ac9b4  ebde                   -jmp 0x4ac994
    goto L_0x004ac994;
L_0x004ac9b6:
    // 004ac9b6  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ac9b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac9be:
    // 004ac9be  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004ac9c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ac9c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ac9c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ac9c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ac9ca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ac9cb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ac9cd  8b482c                 -mov ecx, dword ptr [eax + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004ac9d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ac9d2  7529                   -jne 0x4ac9fd
    if (!cpu.flags.zf)
    {
        goto L_0x004ac9fd;
    }
L_0x004ac9d4:
    // 004ac9d4  8b5a30                 -mov ebx, dword ptr [edx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004ac9d7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ac9d9  740e                   -je 0x4ac9e9
    if (cpu.flags.zf)
    {
        goto L_0x004ac9e9;
    }
    // 004ac9db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ac9dd  e86ae8feff             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
    // 004ac9e2  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
L_0x004ac9e9:
    // 004ac9e9  81fa78b24d00           +cmp edx, 0x4db278
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5091960 /*0x4db278*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac9ef  7408                   -je 0x4ac9f9
    if (cpu.flags.zf)
    {
        goto L_0x004ac9f9;
    }
    // 004ac9f1  81fab0b24d00           +cmp edx, 0x4db2b0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5092016 /*0x4db2b0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ac9f7  7514                   -jne 0x4aca0d
    if (!cpu.flags.zf)
    {
        goto L_0x004aca0d;
    }
L_0x004ac9f9:
    // 004ac9f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ac9fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ac9fd:
    // 004ac9fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ac9ff  e848e8feff             -call 0x49b24c
    cpu.esp -= 4;
    sub_49b24c(app, cpu);
    if (cpu.terminate) return;
    // 004aca04  c7422c00000000         -mov dword ptr [edx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004aca0b  ebc7                   -jmp 0x4ac9d4
    goto L_0x004ac9d4;
L_0x004aca0d:
    // 004aca0d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aca0f  e8e87efdff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004aca14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aca18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aca18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aca19  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004aca1c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aca1e  7502                   -jne 0x4aca22
    if (!cpu.flags.zf)
    {
        goto L_0x004aca22;
    }
    // 004aca20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aca22:
    // 004aca22  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aca24  e88b58feff             -call 0x4922b4
    cpu.esp -= 4;
    sub_4922b4(app, cpu);
    if (cpu.terminate) return;
    // 004aca29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aca2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aca2c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aca2d  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004aca30  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aca32  7502                   -jne 0x4aca36
    if (!cpu.flags.zf)
    {
        goto L_0x004aca36;
    }
    // 004aca34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aca36:
    // 004aca36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aca38  e8b758feff             -call 0x4922f4
    cpu.esp -= 4;
    sub_4922f4(app, cpu);
    if (cpu.terminate) return;
    // 004aca3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aca40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aca40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aca41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aca42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aca43  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004aca46  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004aca48  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004aca4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aca4b  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004aca4f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aca50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aca51  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004aca53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aca54  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aca56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aca58  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004aca5d  e8a254feff             -call 0x491f04
    cpu.esp -= 4;
    sub_491f04(app, cpu);
    if (cpu.terminate) return;
    // 004aca62  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aca64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aca66  750b                   -jne 0x4aca73
    if (!cpu.flags.zf)
    {
        goto L_0x004aca73;
    }
L_0x004aca68:
    // 004aca68  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aca6a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004aca6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca70  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004aca73:
    // 004aca73  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aca75  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aca79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aca7a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aca7e  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aca82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aca83  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aca87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aca89  e84257feff             -call 0x4921d0
    cpu.esp -= 4;
    sub_4921d0(app, cpu);
    if (cpu.terminate) return;
    // 004aca8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aca8f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aca93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aca94  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aca98  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aca9c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aca9d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004acaa1  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004acaa5  e8fefdffff             -call 0x4ac8a8
    cpu.esp -= 4;
    sub_4ac8a8(app, cpu);
    if (cpu.terminate) return;
    // 004acaaa  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004acaac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004acaae  75b8                   -jne 0x4aca68
    if (!cpu.flags.zf)
    {
        goto L_0x004aca68;
    }
    // 004acab0  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004acab5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004acab7  e83c56feff             -call 0x4920f8
    cpu.esp -= 4;
    sub_4920f8(app, cpu);
    if (cpu.terminate) return;
    // 004acabc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004acabe  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004acac1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4acad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acad0  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004acad2  742c                   -je 0x4acb00
    if (cpu.flags.zf)
    {
        goto L_0x004acb00;
    }
    // 004acad4  3810                   -cmp byte ptr [eax], dl
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
L_0x004acad6:
    // 004acad6  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 004acad8  7409                   -je 0x4acae3
    if (cpu.flags.zf)
    {
        goto L_0x004acae3;
    }
    // 004acada  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004acadc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004acadd  c1ca08                 +ror edx, 8
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
    // 004acae0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acae1  75f3                   -jne 0x4acad6
    if (!cpu.flags.zf)
    {
        goto L_0x004acad6;
    }
L_0x004acae3:
    // 004acae3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004acae4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004acae7  e81b000000             -call 0x4acb07
    cpu.esp -= 4;
    sub_4acb07(app, cpu);
    if (cpu.terminate) return;
    // 004acaec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acaed  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004acaf0  740e                   -je 0x4acb00
    if (cpu.flags.zf)
    {
        goto L_0x004acb00;
    }
    // 004acaf2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004acaf4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acaf5  7409                   -je 0x4acb00
    if (cpu.flags.zf)
    {
        goto L_0x004acb00;
    }
    // 004acaf7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 004acafa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acafb  7403                   -je 0x4acb00
    if (cpu.flags.zf)
    {
        goto L_0x004acb00;
    }
    // 004acafd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x004acb00:
    // 004acb00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4acb02(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acb02  90                     -nop 
    ;
    // 004acb03  90                     -nop 
    ;
    // 004acb04  90                     -nop 
    ;
    // 004acb05  90                     -nop 
    ;
    // 004acb06  90                     -nop 
    ;
    // 004acb07  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004acb09  7467                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
L_0x004acb0b:
    // 004acb0b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 004acb0d  7408                   -je 0x4acb17
    if (cpu.flags.zf)
    {
        goto L_0x004acb17;
    }
    // 004acb0f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb11  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004acb14  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb15  75f4                   -jne 0x4acb0b
    if (!cpu.flags.zf)
    {
        goto L_0x004acb0b;
    }
L_0x004acb17:
    // 004acb17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004acb18  c1e902                 +shr ecx, 2
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
    // 004acb1b  743a                   -je 0x4acb57
    if (cpu.flags.zf)
    {
        goto L_0x004acb57;
    }
    // 004acb1d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb1e  7429                   -je 0x4acb49
    if (cpu.flags.zf)
    {
        goto L_0x004acb49;
    }
L_0x004acb20:
    // 004acb20  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb22  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004acb25  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb26  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acb29  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004acb2c  7418                   -je 0x4acb46
    if (cpu.flags.zf)
    {
        goto L_0x004acb46;
    }
    // 004acb2e  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 004acb31  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004acb34  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004acb37  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb38  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004acb3b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004acb3e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004acb41  75dd                   -jne 0x4acb20
    if (!cpu.flags.zf)
    {
        goto L_0x004acb20;
    }
    // 004acb43  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x004acb46:
    // 004acb46  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004acb49:
    // 004acb49  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb4b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004acb4e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acb51  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004acb54  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004acb57:
    // 004acb57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb58  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004acb5b  7415                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
    // 004acb5d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb5f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004acb62  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb63  740d                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
    // 004acb65  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb67  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004acb6a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb6b  7405                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
    // 004acb6d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb6f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004acb72:
    // 004acb72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4acb07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004acb07;
    // 004acb02  90                     -nop 
    ;
    // 004acb03  90                     -nop 
    ;
    // 004acb04  90                     -nop 
    ;
    // 004acb05  90                     -nop 
    ;
    // 004acb06  90                     -nop 
    ;
L_entry_0x004acb07:
    // 004acb07  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004acb09  7467                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
L_0x004acb0b:
    // 004acb0b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 004acb0d  7408                   -je 0x4acb17
    if (cpu.flags.zf)
    {
        goto L_0x004acb17;
    }
    // 004acb0f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb11  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004acb14  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb15  75f4                   -jne 0x4acb0b
    if (!cpu.flags.zf)
    {
        goto L_0x004acb0b;
    }
L_0x004acb17:
    // 004acb17  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004acb18  c1e902                 +shr ecx, 2
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
    // 004acb1b  743a                   -je 0x4acb57
    if (cpu.flags.zf)
    {
        goto L_0x004acb57;
    }
    // 004acb1d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb1e  7429                   -je 0x4acb49
    if (cpu.flags.zf)
    {
        goto L_0x004acb49;
    }
L_0x004acb20:
    // 004acb20  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb22  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004acb25  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb26  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acb29  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004acb2c  7418                   -je 0x4acb46
    if (cpu.flags.zf)
    {
        goto L_0x004acb46;
    }
    // 004acb2e  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 004acb31  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004acb34  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004acb37  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb38  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004acb3b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004acb3e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004acb41  75dd                   -jne 0x4acb20
    if (!cpu.flags.zf)
    {
        goto L_0x004acb20;
    }
    // 004acb43  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x004acb46:
    // 004acb46  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004acb49:
    // 004acb49  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb4b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004acb4e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acb51  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004acb54  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004acb57:
    // 004acb57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb58  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004acb5b  7415                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
    // 004acb5d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb5f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004acb62  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb63  740d                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
    // 004acb65  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb67  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004acb6a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004acb6b  7405                   -je 0x4acb72
    if (cpu.flags.zf)
    {
        goto L_0x004acb72;
    }
    // 004acb6d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acb6f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004acb72:
    // 004acb72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4acb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acb80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004acb81  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004acb83  83f80f                 +cmp eax, 0xf
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
    // 004acb86  7313                   -jae 0x4acb9b
    if (!cpu.flags.cf)
    {
        goto L_0x004acb9b;
    }
    // 004acb88  83f804                 +cmp eax, 4
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
    // 004acb8b  7333                   -jae 0x4acbc0
    if (!cpu.flags.cf)
    {
        goto L_0x004acbc0;
    }
    // 004acb8d  83f801                 +cmp eax, 1
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
    // 004acb90  7505                   -jne 0x4acb97
    if (!cpu.flags.zf)
    {
        goto L_0x004acb97;
    }
    // 004acb92  ba79000000             -mov edx, 0x79
    cpu.edx = 121 /*0x79*/;
L_0x004acb97:
    // 004acb97  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acb99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acb9b:
    // 004acb9b  763c                   -jbe 0x4acbd9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004acbd9;
    }
    // 004acb9d  83f818                 +cmp eax, 0x18
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
    // 004acba0  730e                   -jae 0x4acbb0
    if (!cpu.flags.cf)
    {
        goto L_0x004acbb0;
    }
    // 004acba2  83f810                 +cmp eax, 0x10
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
    // 004acba5  75f0                   -jne 0x4acb97
    if (!cpu.flags.zf)
    {
        goto L_0x004acb97;
    }
    // 004acba7  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 004acbac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acbae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acbaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acbb0:
    // 004acbb0  7630                   -jbe 0x4acbe2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004acbe2;
    }
    // 004acbb2  83f820                 +cmp eax, 0x20
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
    // 004acbb5  75e0                   -jne 0x4acb97
    if (!cpu.flags.zf)
    {
        goto L_0x004acb97;
    }
    // 004acbb7  ba7d000000             -mov edx, 0x7d
    cpu.edx = 125 /*0x7d*/;
    // 004acbbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acbbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acbbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acbc0:
    // 004acbc0  760e                   -jbe 0x4acbd0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004acbd0;
    }
    // 004acbc2  83f808                 +cmp eax, 8
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
    // 004acbc5  75d0                   -jne 0x4acb97
    if (!cpu.flags.zf)
    {
        goto L_0x004acb97;
    }
    // 004acbc7  ba7b000000             -mov edx, 0x7b
    cpu.edx = 123 /*0x7b*/;
    // 004acbcc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acbce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acbcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acbd0:
    // 004acbd0  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 004acbd5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acbd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acbd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acbd9:
    // 004acbd9  ba7e000000             -mov edx, 0x7e
    cpu.edx = 126 /*0x7e*/;
    // 004acbde  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acbe0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acbe1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acbe2:
    // 004acbe2  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004acbe7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acbe9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acbea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4acbec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acbec  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004acbef  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004acbf2  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004acbf5  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acbf8  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004acbfa  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004acbfc  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004acbff  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acc02  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004acc04  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004acc06  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004acc09  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004acc0b  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004acc0d  0f8410010000           -je 0x4acd23
    if (cpu.flags.zf)
    {
        goto L_0x004acd23;
    }
    // 004acc13  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004acc16  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acc19  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004acc1c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acc1e  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004acc21  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acc23  891da8284e00           -mov dword ptr [0x4e28a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */) = cpu.ebx;
    // 004acc29  890dac284e00           -mov dword ptr [0x4e28ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */) = cpu.ecx;
    // 004acc2f  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 004acc32  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004acc34  db05a8284e00           -fild dword ptr [0x4e28a8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */))));
    // 004acc3a  db05ac284e00           -fild dword ptr [0x4e28ac]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */))));
    // 004acc40  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004acc42  d80dc0284e00           -fmul dword ptr [0x4e28c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5122240) /* 0x4e28c0 */));
    // 004acc48  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004acc4a  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004acc4c  d80dbc284e00           -fmul dword ptr [0x4e28bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5122236) /* 0x4e28bc */));
    // 004acc52  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004acc54  d80dc4284e00           -fmul dword ptr [0x4e28c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5122244) /* 0x4e28c4 */));
    // 004acc5a  f72db8284e00           -imul dword ptr [0x4e28b8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122232) /* 0x4e28b8 */))));
    // 004acc60  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004acc62  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004acc64  d805c8284e00           -fadd dword ptr [0x4e28c8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5122248) /* 0x4e28c8 */));
    // 004acc6a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004acc6c  d805c8284e00           -fadd dword ptr [0x4e28c8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5122248) /* 0x4e28c8 */));
    // 004acc72  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004acc75  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acc78  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004acc7a  dd1db0284e00           -fstp qword ptr [0x4e28b0]
    app->getMemory<double>(x86::reg32(5122224) /* 0x4e28b0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004acc80  dd1da8284e00           -fstp qword ptr [0x4e28a8]
    app->getMemory<double>(x86::reg32(5122216) /* 0x4e28a8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004acc86  8b0da8284e00           -mov ecx, dword ptr [0x4e28a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */);
    // 004acc8c  8b3db0284e00           -mov edi, dword ptr [0x4e28b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5122224) /* 0x4e28b0 */);
    // 004acc92  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acc94  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004acc96  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004acc98  890dac284e00           -mov dword ptr [0x4e28ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */) = cpu.ecx;
    // 004acc9e  8915b0284e00           -mov dword ptr [0x4e28b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5122224) /* 0x4e28b0 */) = cpu.edx;
    // 004acca4  893db4284e00           -mov dword ptr [0x4e28b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5122228) /* 0x4e28b4 */) = cpu.edi;
    // 004accaa  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004accac  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004accaf  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004accb2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004accb4  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004accb7  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004accb9  f72db8284e00           -imul dword ptr [0x4e28b8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122232) /* 0x4e28b8 */))));
    // 004accbf  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004accc1  8b3da4284e00           -mov edi, dword ptr [0x4e28a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004accc7  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004accc9  8b2dac284e00           -mov ebp, dword ptr [0x4e28ac]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */);
    // 004acccf  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004accd2  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004accd4  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 004accd7  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004accd9  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004accdc  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004accde  8b2da8284e00           -mov ebp, dword ptr [0x4e28a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */);
    // 004acce4  897748                 -mov dword ptr [edi + 0x48], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.esi;
    // 004acce7  8b35b0284e00           -mov esi, dword ptr [0x4e28b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5122224) /* 0x4e28b0 */);
    // 004acced  898fb4000000           -mov dword ptr [edi + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 004accf3  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004accf6  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004accf8  8b2db4284e00           -mov ebp, dword ptr [0x4e28b4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5122228) /* 0x4e28b4 */);
    // 004accfe  894f6c                 -mov dword ptr [edi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 004acd01  899f90000000           -mov dword ptr [edi + 0x90], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.ebx;
    // 004acd07  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004acd0a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004acd0c  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 004acd0f  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004acd11  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004acd13  895f24                 -mov dword ptr [edi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004acd16  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 004acd1c  8997fc000000           -mov dword ptr [edi + 0xfc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.edx;
    // 004acd22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acd23:
    // 004acd23  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004acd25  8b3da4284e00           -mov edi, dword ptr [0x4e28a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acd2b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004acd2d  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004acd30  894748                 -mov dword ptr [edi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004acd33  89476c                 -mov dword ptr [edi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 004acd36  898790000000           -mov dword ptr [edi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 004acd3c  8987b4000000           -mov dword ptr [edi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 004acd42  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 004acd48  8987fc000000           -mov dword ptr [edi + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.eax;
    // 004acd4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4acd4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acd4f  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004acd52  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004acd55  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004acd58  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acd5b  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004acd5e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acd60  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004acd63  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acd65  891da8284e00           -mov dword ptr [0x4e28a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */) = cpu.ebx;
    // 004acd6b  890dac284e00           -mov dword ptr [0x4e28ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */) = cpu.ecx;
    // 004acd71  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 004acd74  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004acd76  db05a8284e00           -fild dword ptr [0x4e28a8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */))));
    // 004acd7c  db05ac284e00           -fild dword ptr [0x4e28ac]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */))));
    // 004acd82  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004acd84  d80dc0284e00           -fmul dword ptr [0x4e28c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5122240) /* 0x4e28c0 */));
    // 004acd8a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004acd8c  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004acd8e  d80dbc284e00           -fmul dword ptr [0x4e28bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5122236) /* 0x4e28bc */));
    // 004acd94  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004acd96  d80dc4284e00           -fmul dword ptr [0x4e28c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5122244) /* 0x4e28c4 */));
    // 004acd9c  f72db8284e00           -imul dword ptr [0x4e28b8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122232) /* 0x4e28b8 */))));
    // 004acda2  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004acda4  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004acda6  d805c8284e00           -fadd dword ptr [0x4e28c8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5122248) /* 0x4e28c8 */));
    // 004acdac  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004acdae  d805c8284e00           -fadd dword ptr [0x4e28c8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5122248) /* 0x4e28c8 */));
    // 004acdb4  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004acdb7  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acdba  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004acdbc  dd1db0284e00           -fstp qword ptr [0x4e28b0]
    app->getMemory<double>(x86::reg32(5122224) /* 0x4e28b0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004acdc2  dd1da8284e00           -fstp qword ptr [0x4e28a8]
    app->getMemory<double>(x86::reg32(5122216) /* 0x4e28a8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004acdc8  8b0da8284e00           -mov ecx, dword ptr [0x4e28a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */);
    // 004acdce  8b3db0284e00           -mov edi, dword ptr [0x4e28b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5122224) /* 0x4e28b0 */);
    // 004acdd4  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acdd6  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004acdd8  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004acdda  890dac284e00           -mov dword ptr [0x4e28ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */) = cpu.ecx;
    // 004acde0  8915b0284e00           -mov dword ptr [0x4e28b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5122224) /* 0x4e28b0 */) = cpu.edx;
    // 004acde6  893db4284e00           -mov dword ptr [0x4e28b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5122228) /* 0x4e28b4 */) = cpu.edi;
    // 004acdec  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004acdee  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004acdf1  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004acdf4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004acdf6  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004acdf9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acdfb  f72db8284e00           -imul dword ptr [0x4e28b8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5122232) /* 0x4e28b8 */))));
    // 004ace01  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004ace03  8b3da4284e00           -mov edi, dword ptr [0x4e28a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004ace09  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ace0b  8b2dac284e00           -mov ebp, dword ptr [0x4e28ac]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5122220) /* 0x4e28ac */);
    // 004ace11  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004ace14  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ace16  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 004ace19  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ace1b  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004ace1e  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ace20  8b2da8284e00           -mov ebp, dword ptr [0x4e28a8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5122216) /* 0x4e28a8 */);
    // 004ace26  897708                 -mov dword ptr [edi + 8], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004ace29  8b35b0284e00           -mov esi, dword ptr [0x4e28b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5122224) /* 0x4e28b0 */);
    // 004ace2f  894f14                 -mov dword ptr [edi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ace32  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004ace35  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ace37  8b2db4284e00           -mov ebp, dword ptr [0x4e28b4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5122228) /* 0x4e28b4 */);
    // 004ace3d  894f0c                 -mov dword ptr [edi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004ace40  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004ace43  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004ace46  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ace48  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 004ace4b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ace4d  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004ace4f  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004ace52  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ace55  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ace58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ace59(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ace59  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ace5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ace5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ace5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ace5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ace5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ace5f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ace62  8915a0284e00           -mov dword ptr [0x4e28a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */) = cpu.edx;
    // 004ace68  beec294e00             -mov esi, 0x4e29ec
    cpu.esi = 5122540 /*0x4e29ec*/;
    // 004ace6d  c705a4284e00cc284e00   -mov dword ptr [0x4e28a4], 0x4e28cc
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122252 /*0x4e28cc*/;
    // 004ace77  e870fdffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004ace7c  be0c2a4e00             -mov esi, 0x4e2a0c
    cpu.esi = 5122572 /*0x4e2a0c*/;
    // 004ace81  c705a4284e00d0284e00   -mov dword ptr [0x4e28a4], 0x4e28d0
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122256 /*0x4e28d0*/;
    // 004ace8b  e85cfdffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004ace90  be2c2a4e00             -mov esi, 0x4e2a2c
    cpu.esi = 5122604 /*0x4e2a2c*/;
    // 004ace95  c705a4284e00d4284e00   -mov dword ptr [0x4e28a4], 0x4e28d4
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122260 /*0x4e28d4*/;
    // 004ace9f  e848fdffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004acea4  be4c2a4e00             -mov esi, 0x4e2a4c
    cpu.esi = 5122636 /*0x4e2a4c*/;
    // 004acea9  c705a4284e00d8284e00   -mov dword ptr [0x4e28a4], 0x4e28d8
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122264 /*0x4e28d8*/;
    // 004aceb3  e834fdffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004aceb8  be6c2a4e00             -mov esi, 0x4e2a6c
    cpu.esi = 5122668 /*0x4e2a6c*/;
    // 004acebd  c705a4284e00dc284e00   -mov dword ptr [0x4e28a4], 0x4e28dc
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122268 /*0x4e28dc*/;
    // 004acec7  e820fdffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004acecc  be8c2a4e00             -mov esi, 0x4e2a8c
    cpu.esi = 5122700 /*0x4e2a8c*/;
    // 004aced1  c705a4284e00e0284e00   -mov dword ptr [0x4e28a4], 0x4e28e0
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122272 /*0x4e28e0*/;
    // 004acedb  e80cfdffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004acee0  beac2a4e00             -mov esi, 0x4e2aac
    cpu.esi = 5122732 /*0x4e2aac*/;
    // 004acee5  c705a4284e00e4284e00   -mov dword ptr [0x4e28a4], 0x4e28e4
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122276 /*0x4e28e4*/;
    // 004aceef  e8f8fcffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004acef4  becc2a4e00             -mov esi, 0x4e2acc
    cpu.esi = 5122764 /*0x4e2acc*/;
    // 004acef9  c705a4284e00e8284e00   -mov dword ptr [0x4e28a4], 0x4e28e8
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = 5122280 /*0x4e28e8*/;
    // 004acf03  e8e4fcffff             -call 0x4acbec
    cpu.esp -= 4;
    sub_4acbec(app, cpu);
    if (cpu.terminate) return;
    // 004acf08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acf09  becc284e00             -mov esi, 0x4e28cc
    cpu.esi = 5122252 /*0x4e28cc*/;
    // 004acf0e  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acf13  e837feffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acf18  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acf1d  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acf23  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acf25  bef0284e00             -mov esi, 0x4e28f0
    cpu.esi = 5122288 /*0x4e28f0*/;
    // 004acf2a  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acf2f  e81bfeffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acf34  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acf39  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acf3f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acf41  be14294e00             -mov esi, 0x4e2914
    cpu.esi = 5122324 /*0x4e2914*/;
    // 004acf46  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acf4b  e8fffdffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acf50  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acf55  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acf5b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acf5d  be38294e00             -mov esi, 0x4e2938
    cpu.esi = 5122360 /*0x4e2938*/;
    // 004acf62  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acf67  e8e3fdffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acf6c  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acf71  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acf77  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acf79  be5c294e00             -mov esi, 0x4e295c
    cpu.esi = 5122396 /*0x4e295c*/;
    // 004acf7e  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acf83  e8c7fdffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acf88  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acf8d  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acf93  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acf95  be80294e00             -mov esi, 0x4e2980
    cpu.esi = 5122432 /*0x4e2980*/;
    // 004acf9a  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acf9f  e8abfdffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acfa4  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acfa9  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acfaf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acfb1  bea4294e00             -mov esi, 0x4e29a4
    cpu.esi = 5122468 /*0x4e29a4*/;
    // 004acfb6  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acfbb  e88ffdffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acfc0  a1a4284e00             -mov eax, dword ptr [0x4e28a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */);
    // 004acfc5  8b15a0284e00           -mov edx, dword ptr [0x4e28a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5122208) /* 0x4e28a0 */);
    // 004acfcb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acfcd  bec8294e00             -mov esi, 0x4e29c8
    cpu.esi = 5122504 /*0x4e29c8*/;
    // 004acfd2  a3a4284e00             -mov dword ptr [0x4e28a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5122212) /* 0x4e28a4 */) = cpu.eax;
    // 004acfd7  e873fdffff             -call 0x4acd4f
    cpu.esp -= 4;
    sub_4acd4f(app, cpu);
    if (cpu.terminate) return;
    // 004acfdc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfdd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfe0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfe1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4acfe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acfe4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004acfe5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acfe6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004acfe7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004acfe8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004acfea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004acfec  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004acfef  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004acff1  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004acff4  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 004acff9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acffc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004acffe:
    // 004acffe  c1e816                 -shr eax, 0x16
    cpu.eax >>= 22 /*0x16*/ % 32;
    // 004ad001  3dff010000             +cmp eax, 0x1ff
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
    // 004ad006  0f84de000000           -je 0x4ad0ea
    if (cpu.flags.zf)
    {
        goto L_0x004ad0ea;
    }
    // 004ad00c  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004ad00f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad012  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 004ad015  83ed0a                 -sub ebp, 0xa
    (cpu.ebp) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004ad018  83fd10                 +cmp ebp, 0x10
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
    // 004ad01b  7d16                   -jge 0x4ad033
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad033;
    }
    // 004ad01d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad01f  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004ad024  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004ad027  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ad029  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004ad02b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad02e  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad030  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ad033:
    // 004ad033  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004ad035:
    // 004ad035  c1ea13                 -shr edx, 0x13
    cpu.edx >>= 19 /*0x13*/ % 32;
    // 004ad038  8b04955c475600         -mov eax, dword ptr [edx*4 + 0x56475c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5654364) /* 0x56475c */ + cpu.edx * 4);
    // 004ad03f  a900002000             +test eax, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2097152 /*0x200000*/));
    // 004ad044  7461                   -je 0x4ad0a7
    if (cpu.flags.zf)
    {
        goto L_0x004ad0a7;
    }
    // 004ad046  a900000100             +test eax, 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 65536 /*0x10000*/));
    // 004ad04b  742d                   -je 0x4ad07a
    if (cpu.flags.zf)
    {
        goto L_0x004ad07a;
    }
    // 004ad04d  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004ad050  83ed06                 -sub ebp, 6
    (cpu.ebp) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004ad053  83fd10                 +cmp ebp, 0x10
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
    // 004ad056  7d16                   -jge 0x4ad06e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad06e;
    }
    // 004ad058  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad05a  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004ad05f  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004ad062  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ad064  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004ad066  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad069  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad06b  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ad06e:
    // 004ad06e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ad070  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ad073  0d00001000             +or eax, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 004ad078  eb2d                   -jmp 0x4ad0a7
    goto L_0x004ad0a7;
L_0x004ad07a:
    // 004ad07a  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad07d  83ed08                 -sub ebp, 8
    (cpu.ebp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ad080  83fd10                 +cmp ebp, 0x10
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
    // 004ad083  7d16                   -jge 0x4ad09b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad09b;
    }
    // 004ad085  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad087  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004ad08c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004ad08f  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ad091  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004ad093  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad096  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad098  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ad09b:
    // 004ad09b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad09d  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 004ad0a0  8b04955cc75600         -mov eax, dword ptr [edx*4 + 0x56c75c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5687132) /* 0x56c75c */ + cpu.edx * 4);
L_0x004ad0a7:
    // 004ad0a7  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004ad0aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ad0ac  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ad0af  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad0b2  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004ad0b4  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad0b6  83fd10                 +cmp ebp, 0x10
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
    // 004ad0b9  7d16                   -jge 0x4ad0d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad0d1;
    }
    // 004ad0bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad0bd  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004ad0c2  668b16                 -mov dx, word ptr [esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi);
    // 004ad0c5  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ad0c7  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004ad0c9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad0cc  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad0ce  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ad0d1:
    // 004ad0d1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ad0d6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad0d8  3d00fe0000             +cmp eax, 0xfe00
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
    // 004ad0dd  0f8552ffffff           -jne 0x4ad035
    if (!cpu.flags.zf)
    {
        goto L_0x004ad035;
    }
    // 004ad0e3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ad0e5  e914ffffff             -jmp 0x4acffe
    goto L_0x004acffe;
L_0x004ad0ea:
    // 004ad0ea  66c70700fe             -mov word ptr [edi], 0xfe00
    app->getMemory<x86::reg16>(cpu.edi) = 65024 /*0xfe00*/;
    // 004ad0ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad0f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad0f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad0f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad0f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ad0f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad0f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ad0f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad0f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ad0f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad0f8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad0f9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad0fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad0fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad0fe  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004ad101  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad103  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 004ad106  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ad10b  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 004ad10e  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 004ad113  f72d5ccf5600           -imul dword ptr [0x56cf5c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5689180) /* 0x56cf5c */))));
    // 004ad119  a3ec294e00             -mov dword ptr [0x4e29ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5122540) /* 0x4e29ec */) = cpu.eax;
    // 004ad11e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004ad120:
    // 004ad120  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad122  668b044e               -mov ax, word ptr [esi + ecx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ecx * 2);
    // 004ad126  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad127  3d00fe0000             +cmp eax, 0xfe00
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
    // 004ad12c  7436                   -je 0x4ad164
    if (cpu.flags.zf)
    {
        goto L_0x004ad164;
    }
    // 004ad12e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad130  8a9f20ef4d00           -mov bl, byte ptr [edi + 0x4def20]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5107488) /* 0x4def20 */);
    // 004ad136  c1ea0a                 +shr edx, 0xa
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
    // 004ad139  7412                   -je 0x4ad14d
    if (cpu.flags.zf)
    {
        goto L_0x004ad14d;
    }
L_0x004ad13b:
    // 004ad13b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ad13c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ad13d  892c9dec294e00         -mov dword ptr [ebx*4 + 0x4e29ec], ebp
    app->getMemory<x86::reg32>(x86::reg32(5122540) /* 0x4e29ec */ + cpu.ebx * 4) = cpu.ebp;
    // 004ad144  90                     -nop 
    ;
    // 004ad145  8a9f20ef4d00           -mov bl, byte ptr [edi + 0x4def20]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5107488) /* 0x4def20 */);
    // 004ad14b  75ee                   -jne 0x4ad13b
    if (!cpu.flags.zf)
    {
        goto L_0x004ad13b;
    }
L_0x004ad14d:
    // 004ad14d  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 004ad150  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 004ad153  4f                     -dec edi
    (cpu.edi)--;
    // 004ad154  f72c9d5ccf5600         +imul dword ptr [ebx*4 + 0x56cf5c]
    {
        cpu.edx_eax = x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5689180) /* 0x56cf5c */ + cpu.ebx * 4)));
        cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg64>(cpu.edx_eax) != x86::sreg64(static_cast<x86::sreg32>(cpu.eax)));
    }
    // 004ad15b  89049dec294e00         -mov dword ptr [ebx*4 + 0x4e29ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5122540) /* 0x4e29ec */ + cpu.ebx * 4) = cpu.eax;
    // 004ad162  ebbc                   -jmp 0x4ad120
    goto L_0x004ad120;
L_0x004ad164:
    // 004ad164  8a9f20ef4d00           -mov bl, byte ptr [edi + 0x4def20]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5107488) /* 0x4def20 */);
L_0x004ad16a:
    // 004ad16a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ad16b  7810                   -js 0x4ad17d
    if (cpu.flags.sf)
    {
        goto L_0x004ad17d;
    }
    // 004ad16d  892c9dec294e00         -mov dword ptr [ebx*4 + 0x4e29ec], ebp
    app->getMemory<x86::reg32>(x86::reg32(5122540) /* 0x4e29ec */ + cpu.ebx * 4) = cpu.ebp;
    // 004ad174  90                     -nop 
    ;
    // 004ad175  8a9f20ef4d00           -mov bl, byte ptr [edi + 0x4def20]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5107488) /* 0x4def20 */);
    // 004ad17b  ebed                   -jmp 0x4ad16a
    goto L_0x004ad16a;
L_0x004ad17d:
    // 004ad17d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad17f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad180  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad181  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad182  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad183  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad184  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad185  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ad186(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad186  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad187  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad188  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad189  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad18a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad18c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ad18e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004ad190  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad192  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad194  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad196  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad198  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004ad19b  8a9f02010000           -mov bl, byte ptr [edi + 0x102]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(258) /* 0x102 */);
    // 004ad1a1  8a4e06                 -mov cl, byte ptr [esi + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004ad1a4  8a5702                 -mov dl, byte ptr [edi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004ad1a7  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1ad  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1b3  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad1b6  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1bc  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad1bf  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1c5  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad1c7  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad1c9  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad1cc  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad1ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad1d0  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004ad1d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad1d5  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004ad1d8  8a9f06010000           -mov bl, byte ptr [edi + 0x106]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(262) /* 0x106 */);
    // 004ad1de  8a4e0e                 -mov cl, byte ptr [esi + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004ad1e1  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004ad1e4  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1ea  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1f0  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad1f3  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad1f9  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad1fc  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad202  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad204  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad206  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad209  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad20b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad20d  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ad210  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad212  8a4612                 -mov al, byte ptr [esi + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004ad215  8a9f0a010000           -mov bl, byte ptr [edi + 0x10a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(266) /* 0x10a */);
    // 004ad21b  8a4e16                 -mov cl, byte ptr [esi + 0x16]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 004ad21e  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004ad221  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad227  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad22d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad230  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad236  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad239  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad23f  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad241  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad243  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad246  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad248  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad24a  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ad24d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad24f  8a461a                 -mov al, byte ptr [esi + 0x1a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004ad252  8a9f0e010000           -mov bl, byte ptr [edi + 0x10e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(270) /* 0x10e */);
    // 004ad258  8a4e1e                 -mov cl, byte ptr [esi + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 004ad25b  8a570e                 -mov dl, byte ptr [edi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 004ad25e  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad264  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad26a  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad26d  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad273  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad276  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad27c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad27e  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad280  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad283  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad285  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad287  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ad28a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad28c  8a4622                 -mov al, byte ptr [esi + 0x22]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ad28f  8a9f12010000           -mov bl, byte ptr [edi + 0x112]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(274) /* 0x112 */);
    // 004ad295  8a4e26                 -mov cl, byte ptr [esi + 0x26]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad298  8a5712                 -mov dl, byte ptr [edi + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 004ad29b  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2a1  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2a7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad2aa  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2b0  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad2b3  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2b9  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad2bb  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad2bd  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad2c0  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad2c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad2c4  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad2c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad2c9  8a462a                 -mov al, byte ptr [esi + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 004ad2cc  8a9f16010000           -mov bl, byte ptr [edi + 0x116]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(278) /* 0x116 */);
    // 004ad2d2  8a4e2e                 -mov cl, byte ptr [esi + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ad2d5  8a5716                 -mov dl, byte ptr [edi + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 004ad2d8  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2de  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2e4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad2e7  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2ed  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad2f0  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad2f6  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad2f8  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad2fa  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad2fd  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad2ff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad301  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004ad304  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad306  8a4632                 -mov al, byte ptr [esi + 0x32]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 004ad309  8a9f1a010000           -mov bl, byte ptr [edi + 0x11a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(282) /* 0x11a */);
    // 004ad30f  8a4e36                 -mov cl, byte ptr [esi + 0x36]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(54) /* 0x36 */);
    // 004ad312  8a571a                 -mov dl, byte ptr [edi + 0x1a]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 004ad315  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad31b  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad321  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad324  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad32a  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad32d  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad333  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad335  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad337  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad33a  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad33c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad33e  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ad341  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad343  8a463a                 -mov al, byte ptr [esi + 0x3a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 004ad346  8a9f1e010000           -mov bl, byte ptr [edi + 0x11e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(286) /* 0x11e */);
    // 004ad34c  8a4e3e                 -mov cl, byte ptr [esi + 0x3e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 004ad34f  8a571e                 -mov dl, byte ptr [edi + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(30) /* 0x1e */);
    // 004ad352  8a805cd05600           -mov al, byte ptr [eax + 0x56d05c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad358  8a9b5cd05600           -mov bl, byte ptr [ebx + 0x56d05c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad35e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ad361  8a895cd05600           -mov cl, byte ptr [ecx + 0x56d05c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad367  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004ad36a  8a925cd05600           -mov dl, byte ptr [edx + 0x56d05c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5689436) /* 0x56d05c */);
    // 004ad370  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad372  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad374  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ad377  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad379  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad37b  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ad37e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad380  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad381  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad382  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ad390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad390  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad391  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad392  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad393  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad396  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ad398  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ad39a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ad39d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004ad39f  e8dcfdfeff             -call 0x49d180
    cpu.esp -= 4;
    sub_49d180(app, cpu);
    if (cpu.terminate) return;
    // 004ad3a4  e8fffdfeff             -call 0x49d1a8
    cpu.esp -= 4;
    sub_49d1a8(app, cpu);
    if (cpu.terminate) return;
    // 004ad3a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad3ab  7428                   -je 0x4ad3d5
    if (cpu.flags.zf)
    {
        goto L_0x004ad3d5;
    }
    // 004ad3ad  833d60ef4d0000         +cmp dword ptr [0x4def60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107552) /* 0x4def60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad3b4  741f                   -je 0x4ad3d5
    if (cpu.flags.zf)
    {
        goto L_0x004ad3d5;
    }
    // 004ad3b6  ba01120000             -mov edx, 0x1201
    cpu.edx = 4609 /*0x1201*/;
L_0x004ad3bb:
    // 004ad3bb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004ad3bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ad3bf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad3c1  e89ad1faff             -call 0x45a560
    cpu.esp -= 4;
    sub_45a560(app, cpu);
    if (cpu.terminate) return;
    // 004ad3c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad3c8  7512                   -jne 0x4ad3dc
    if (!cpu.flags.zf)
    {
        goto L_0x004ad3dc;
    }
    // 004ad3ca  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004ad3cc  83c404                 +add esp, 4
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
    // 004ad3cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ad3d5:
    // 004ad3d5  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 004ad3da  ebdf                   -jmp 0x4ad3bb
    goto L_0x004ad3bb;
L_0x004ad3dc:
    // 004ad3dc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ad3de  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ad3e2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ad3e4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ad3e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad3e8  e833d0faff             -call 0x45a420
    cpu.esp -= 4;
    sub_45a420(app, cpu);
    if (cpu.terminate) return;
    // 004ad3ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad3ef  7417                   -je 0x4ad408
    if (cpu.flags.zf)
    {
        goto L_0x004ad408;
    }
    // 004ad3f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad3f4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ad3fa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ad3ff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad402  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad403  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad404  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad405  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ad408:
    // 004ad408  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ad40a  e871c7faff             -call 0x459b80
    cpu.esp -= 4;
    sub_459b80(app, cpu);
    if (cpu.terminate) return;
    // 004ad40f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004ad415  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad417  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad41a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad41b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad41c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad41d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4ad420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad420  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad421  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004ad423  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad427  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad428  e863ffffff             -call 0x4ad390
    cpu.esp -= 4;
    sub_4ad390(app, cpu);
    if (cpu.terminate) return;
    // 004ad42d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad42e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad434(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad434  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad435  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ad437  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad43b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad43c  e84fffffff             -call 0x4ad390
    cpu.esp -= 4;
    sub_4ad390(app, cpu);
    if (cpu.terminate) return;
    // 004ad441  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad442  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad448  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad44a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ad44c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad44c  e92fc7faff             -jmp 0x459b80
    return sub_459b80(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad454(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad454  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad455  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad456  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad457  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad45a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad45c  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ad460  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004ad462  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004ad466  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ad468  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004ad46a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad46b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad46d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad46f  e8accffaff             -call 0x45a420
    cpu.esp -= 4;
    sub_45a420(app, cpu);
    if (cpu.terminate) return;
    // 004ad474  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad476  7509                   -jne 0x4ad481
    if (!cpu.flags.zf)
    {
        goto L_0x004ad481;
    }
L_0x004ad478:
    // 004ad478  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ad47a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad47d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad47e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad47f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad480  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad481:
    // 004ad481  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad484  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ad487  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad48b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ad48d  e8decbfaff             -call 0x45a070
    cpu.esp -= 4;
    sub_45a070(app, cpu);
    if (cpu.terminate) return;
    // 004ad492  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad496  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ad498  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ad49a  74dc                   -je 0x4ad478
    if (cpu.flags.zf)
    {
        goto L_0x004ad478;
    }
    // 004ad49c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad49e  75d8                   -jne 0x4ad478
    if (!cpu.flags.zf)
    {
        goto L_0x004ad478;
    }
    // 004ad4a0  85ed                   -test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ad4a2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ad4a4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad4a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ad4ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad4ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad4ad  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ad4b2  e89dffffff             -call 0x4ad454
    cpu.esp -= 4;
    sub_4ad454(app, cpu);
    if (cpu.terminate) return;
    // 004ad4b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad4bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad4bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad4bd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad4bf  e890ffffff             -call 0x4ad454
    cpu.esp -= 4;
    sub_4ad454(app, cpu);
    if (cpu.terminate) return;
    // 004ad4c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ad4c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad4c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad4c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ad4cb  e890c8faff             -call 0x459d60
    cpu.esp -= 4;
    sub_459d60(app, cpu);
    if (cpu.terminate) return;
    // 004ad4d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad4d2  e8d9c7faff             -call 0x459cb0
    cpu.esp -= 4;
    sub_459cb0(app, cpu);
    if (cpu.terminate) return;
    // 004ad4d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad4dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad4dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad4dd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ad4df  e87cc8faff             -call 0x459d60
    cpu.esp -= 4;
    sub_459d60(app, cpu);
    if (cpu.terminate) return;
    // 004ad4e4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad4e6  e8c5c7faff             -call 0x459cb0
    cpu.esp -= 4;
    sub_459cb0(app, cpu);
    if (cpu.terminate) return;
    // 004ad4eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad4ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad4f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad4f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ad4f3  e868c8faff             -call 0x459d60
    cpu.esp -= 4;
    sub_459d60(app, cpu);
    if (cpu.terminate) return;
    // 004ad4f8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad4fa  e8b1c7faff             -call 0x459cb0
    cpu.esp -= 4;
    sub_459cb0(app, cpu);
    if (cpu.terminate) return;
    // 004ad4ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad500  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ad510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad510  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad511  8d480c                 -lea ecx, [eax + 0xc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ad514  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ad517  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad519  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004ad51c  8a482d                 -mov cl, byte ptr [eax + 0x2d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(45) /* 0x2d */);
    // 004ad51f  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004ad522  8a482f                 -mov cl, byte ptr [eax + 0x2f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 004ad525  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 004ad528  8a482e                 -mov cl, byte ptr [eax + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004ad52b  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 004ad52e  668b4032               -mov ax, word ptr [eax + 0x32]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(50) /* 0x32 */);
    // 004ad532  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ad537  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ad53a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad53c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad53d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ad540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad541  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad542  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ad544  81385041546c           +cmp dword ptr [eax], 0x6c544150
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
    // 004ad54a  7445                   -je 0x4ad591
    if (cpu.flags.zf)
    {
        goto L_0x004ad591;
    }
    // 004ad54c  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004ad550  7449                   -je 0x4ad59b
    if (cpu.flags.zf)
    {
        goto L_0x004ad59b;
    }
    // 004ad552  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004ad555:
    // 004ad555  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad556  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ad557  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 004ad55a  c6470100               -mov byte ptr [edi + 1], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 004ad55e  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 004ad562  c6470300               -mov byte ptr [edi + 3], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004ad566  c7470400000000         -mov dword ptr [edi + 4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ad56d  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad570  7418                   -je 0x4ad58a
    if (cpu.flags.zf)
    {
        goto L_0x004ad58a;
    }
L_0x004ad572:
    // 004ad572  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ad574  80fffe                 +cmp bh, 0xfe
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
    // 004ad577  7411                   -je 0x4ad58a
    if (cpu.flags.zf)
    {
        goto L_0x004ad58a;
    }
    // 004ad579  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 004ad57c  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad57d  81fefd000000           +cmp esi, 0xfd
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
    // 004ad583  751b                   -jne 0x4ad5a0
    if (!cpu.flags.zf)
    {
        goto L_0x004ad5a0;
    }
L_0x004ad585:
    // 004ad585  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad588  75e8                   -jne 0x4ad572
    if (!cpu.flags.zf)
    {
        goto L_0x004ad572;
    }
L_0x004ad58a:
    // 004ad58a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ad58c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad58d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad58e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad58f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad590  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad591:
    // 004ad591  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ad593  e878ffffff             -call 0x4ad510
    cpu.esp -= 4;
    sub_4ad510(app, cpu);
    if (cpu.terminate) return;
    // 004ad598  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad599  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad59a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad59b:
    // 004ad59b  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ad59e  ebb5                   -jmp 0x4ad555
    goto L_0x004ad555;
L_0x004ad5a0:
    // 004ad5a0  81fefc000000           +cmp esi, 0xfc
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
    // 004ad5a6  74dd                   -je 0x4ad585
    if (cpu.flags.zf)
    {
        goto L_0x004ad585;
    }
    // 004ad5a8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad5aa  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ad5ac  81fbff000000           +cmp ebx, 0xff
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
    // 004ad5b2  7512                   -jne 0x4ad5c6
    if (!cpu.flags.zf)
    {
        goto L_0x004ad5c6;
    }
    // 004ad5b4  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad5b5  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004ad5ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad5bc  e8cfa8ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004ad5c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ad5c3  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004ad5c6:
    // 004ad5c6  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad5c7  81fe82000000           +cmp esi, 0x82
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
    // 004ad5cd  7313                   -jae 0x4ad5e2
    if (!cpu.flags.cf)
    {
        goto L_0x004ad5e2;
    }
    // 004ad5cf  83fe13                 +cmp esi, 0x13
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
    // 004ad5d2  7332                   -jae 0x4ad606
    if (!cpu.flags.cf)
    {
        goto L_0x004ad606;
    }
L_0x004ad5d4:
    // 004ad5d4  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad5d6  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad5d9  7597                   -jne 0x4ad572
    if (!cpu.flags.zf)
    {
        goto L_0x004ad572;
    }
    // 004ad5db  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ad5dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad5de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad5df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad5e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad5e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad5e2:
    // 004ad5e2  7667                   -jbe 0x4ad64b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ad64b;
    }
    // 004ad5e4  81fe83000000           +cmp esi, 0x83
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
    // 004ad5ea  0f8679000000           -jbe 0x4ad669
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ad669;
    }
    // 004ad5f0  81fe84000000           +cmp esi, 0x84
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
    // 004ad5f6  75dc                   -jne 0x4ad5d4
    if (!cpu.flags.zf)
    {
        goto L_0x004ad5d4;
    }
    // 004ad5f8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad5fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad5fc  e88fa8ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004ad601  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ad604  ebce                   -jmp 0x4ad5d4
    goto L_0x004ad5d4;
L_0x004ad606:
    // 004ad606  7626                   -jbe 0x4ad62e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ad62e;
    }
    // 004ad608  81fe81000000           +cmp esi, 0x81
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
    // 004ad60e  75c4                   -jne 0x4ad5d4
    if (!cpu.flags.zf)
    {
        goto L_0x004ad5d4;
    }
    // 004ad610  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad612  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad614  e877a8ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004ad619  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ad61c  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad61e  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad621  0f854bffffff           -jne 0x4ad572
    if (!cpu.flags.zf)
    {
        goto L_0x004ad572;
    }
    // 004ad627  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad629  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad62a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad62b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad62c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad62d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad62e:
    // 004ad62e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad630  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad632  e859a8ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004ad637  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004ad639  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad63b  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad63e  0f852effffff           -jne 0x4ad572
    if (!cpu.flags.zf)
    {
        goto L_0x004ad572;
    }
    // 004ad644  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad646  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad647  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad648  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad649  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad64a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad64b:
    // 004ad64b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad64d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad64f  e83ca8ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004ad654  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004ad657  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad659  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad65c  0f8510ffffff           -jne 0x4ad572
    if (!cpu.flags.zf)
    {
        goto L_0x004ad572;
    }
    // 004ad662  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad664  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad665  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad666  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad667  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad668  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad669:
    // 004ad669  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad66b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad66d  e81ea8ffff             -call 0x4a7e90
    cpu.esp -= 4;
    sub_4a7e90(app, cpu);
    if (cpu.terminate) return;
    // 004ad672  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ad675  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad677  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004ad67a  0f85f2feffff           -jne 0x4ad572
    if (!cpu.flags.zf)
    {
        goto L_0x004ad572;
    }
    // 004ad680  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad682  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad683  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad684  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad685  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad686  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ad690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad692  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad693  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad696  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ad698  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ad69c  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004ad6a0  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ad6a3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad6a7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad6aa  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ad6ac  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ad6ae  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004ad6b4  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004ad6b6  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004ad6b8  39d3                   +cmp ebx, edx
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
    // 004ad6ba  7c3c                   -jl 0x4ad6f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6bc  3b1d54b24d00           +cmp ebx, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6c2  7d34                   -jge 0x4ad6f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6c4  3b0d50b24d00           +cmp ecx, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6ca  7c2c                   -jl 0x4ad6f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6cc  3b0d58b24d00           +cmp ecx, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6d2  7d24                   -jge 0x4ad6f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6d4  3b354cb24d00           +cmp esi, dword ptr [0x4db24c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6da  7c1c                   -jl 0x4ad6f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6dc  3b3554b24d00           +cmp esi, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6e2  7d14                   -jge 0x4ad6f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6e4  3b3d50b24d00           +cmp edi, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6ea  7c0c                   -jl 0x4ad6f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6f8;
    }
    // 004ad6ec  3b3d58b24d00           +cmp edi, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad6f2  0f8c60010000           -jl 0x4ad858
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad858;
    }
L_0x004ad6f8:
    // 004ad6f8  8b1554b24d00           -mov edx, dword ptr [0x4db254]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004ad6fe  39d3                   +cmp ebx, edx
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
    // 004ad700  7c08                   -jl 0x4ad70a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad70a;
    }
    // 004ad702  39d6                   +cmp esi, edx
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
    // 004ad704  0f8d5a010000           -jge 0x4ad864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad864;
    }
L_0x004ad70a:
    // 004ad70a  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004ad710  39d3                   +cmp ebx, edx
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
    // 004ad712  7d08                   -jge 0x4ad71c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad71c;
    }
    // 004ad714  39d6                   +cmp esi, edx
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
    // 004ad716  0f8c48010000           -jl 0x4ad864
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad864;
    }
L_0x004ad71c:
    // 004ad71c  8b1558b24d00           -mov edx, dword ptr [0x4db258]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004ad722  39d1                   +cmp ecx, edx
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
    // 004ad724  7c08                   -jl 0x4ad72e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad72e;
    }
    // 004ad726  39d7                   +cmp edi, edx
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
    // 004ad728  0f8d36010000           -jge 0x4ad864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad864;
    }
L_0x004ad72e:
    // 004ad72e  8b1550b24d00           -mov edx, dword ptr [0x4db250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004ad734  39d1                   +cmp ecx, edx
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
    // 004ad736  7d08                   -jge 0x4ad740
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad740;
    }
    // 004ad738  39d7                   +cmp edi, edx
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
    // 004ad73a  0f8c24010000           -jl 0x4ad864
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad864;
    }
L_0x004ad740:
    // 004ad740  39f3                   +cmp ebx, esi
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
    // 004ad742  7e0c                   -jle 0x4ad750
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad750;
    }
    // 004ad744  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ad746  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ad748  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad74a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad74c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004ad74e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004ad750:
    // 004ad750  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004ad756  39d3                   +cmp ebx, edx
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
    // 004ad758  7d24                   -jge 0x4ad77e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad77e;
    }
    // 004ad75a  39f3                   +cmp ebx, esi
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
    // 004ad75c  7420                   -je 0x4ad77e
    if (cpu.flags.zf)
    {
        goto L_0x004ad77e;
    }
    // 004ad75e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad760  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ad762  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad764  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad766  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004ad769  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ad76b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad76d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ad76f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad771  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad774  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad776  8b1d4cb24d00           -mov ebx, dword ptr [0x4db24c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004ad77c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004ad77e:
    // 004ad77e  8b1554b24d00           -mov edx, dword ptr [0x4db254]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004ad784  39d6                   +cmp esi, edx
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
    // 004ad786  7c22                   -jl 0x4ad7aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad7aa;
    }
    // 004ad788  39f3                   +cmp ebx, esi
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
    // 004ad78a  741e                   -je 0x4ad7aa
    if (cpu.flags.zf)
    {
        goto L_0x004ad7aa;
    }
    // 004ad78c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad78e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ad790  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad792  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad794  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004ad797  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad799  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad79b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad79e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad7a0  8b3554b24d00           -mov esi, dword ptr [0x4db254]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004ad7a6  8d3c08                 -lea edi, [eax + ecx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004ad7a9  4e                     -dec esi
    (cpu.esi)--;
L_0x004ad7aa:
    // 004ad7aa  39f9                   +cmp ecx, edi
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
    // 004ad7ac  7e0c                   -jle 0x4ad7ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad7ba;
    }
    // 004ad7ae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ad7b0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ad7b2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad7b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad7b6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004ad7b8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004ad7ba:
    // 004ad7ba  a150b24d00             -mov eax, dword ptr [0x4db250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004ad7bf  39c1                   +cmp ecx, eax
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
    // 004ad7c1  7d22                   -jge 0x4ad7e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad7e5;
    }
    // 004ad7c3  39f9                   +cmp ecx, edi
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
    // 004ad7c5  741e                   -je 0x4ad7e5
    if (cpu.flags.zf)
    {
        goto L_0x004ad7e5;
    }
    // 004ad7c7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ad7c9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad7cb  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad7cd  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004ad7d0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ad7d2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad7d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ad7d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad7d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad7db  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad7dd  8b0d50b24d00           -mov ecx, dword ptr [0x4db250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004ad7e3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004ad7e5:
    // 004ad7e5  8b1558b24d00           -mov edx, dword ptr [0x4db258]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004ad7eb  39d7                   +cmp edi, edx
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
    // 004ad7ed  7c1e                   -jl 0x4ad80d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad80d;
    }
    // 004ad7ef  39f9                   +cmp ecx, edi
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
    // 004ad7f1  741a                   -je 0x4ad80d
    if (cpu.flags.zf)
    {
        goto L_0x004ad80d;
    }
    // 004ad7f3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad7f5  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad7f7  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004ad7fa  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad7fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad7fe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad801  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad803  8b3d58b24d00           -mov edi, dword ptr [0x4db258]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004ad809  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004ad80c  4f                     -dec edi
    (cpu.edi)--;
L_0x004ad80d:
    // 004ad80d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad811  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 004ad814  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004ad816  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad81a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004ad81c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad81f  8b2d4cb24d00           -mov ebp, dword ptr [0x4db24c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004ad825  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004ad827  39eb                   +cmp ebx, ebp
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
    // 004ad829  7c39                   -jl 0x4ad864
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad82b  a154b24d00             -mov eax, dword ptr [0x4db254]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004ad830  39c3                   +cmp ebx, eax
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
    // 004ad832  7d30                   -jge 0x4ad864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad834  8b1550b24d00           -mov edx, dword ptr [0x4db250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004ad83a  39d1                   +cmp ecx, edx
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
    // 004ad83c  7c26                   -jl 0x4ad864
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad83e  8b1d58b24d00           -mov ebx, dword ptr [0x4db258]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004ad844  39d9                   +cmp ecx, ebx
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
    // 004ad846  7d1c                   -jge 0x4ad864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad848  39ee                   +cmp esi, ebp
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
    // 004ad84a  7c18                   -jl 0x4ad864
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad84c  39c6                   +cmp esi, eax
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
    // 004ad84e  7d14                   -jge 0x4ad864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad850  39d7                   +cmp edi, edx
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
    // 004ad852  7c10                   -jl 0x4ad864
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad864;
    }
    // 004ad854  39df                   +cmp edi, ebx
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
    // 004ad856  7d0c                   -jge 0x4ad864
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad864;
    }
L_0x004ad858:
    // 004ad858  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ad85d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad860  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad861  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad862  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad864:
    // 004ad864  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad866  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad869  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad86a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad86b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad86c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4ad870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad870  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad871  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad872  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad875  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ad878  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ad87a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad87c  3b054cb24d00           +cmp eax, dword ptr [0x4db24c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad882  7c5c                   -jl 0x4ad8e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad8e0;
    }
    // 004ad884  3b0554b24d00           +cmp eax, dword ptr [0x4db254]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad88a  7d54                   -jge 0x4ad8e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad8e0;
    }
    // 004ad88c  3b0d50b24d00           +cmp ecx, dword ptr [0x4db250]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad892  7c4c                   -jl 0x4ad8e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad8e0;
    }
    // 004ad894  3b0d58b24d00           +cmp ecx, dword ptr [0x4db258]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad89a  7d44                   -jge 0x4ad8e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad8e0;
    }
    // 004ad89c  a16cb24d00             -mov eax, dword ptr [0x4db26c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004ad8a1  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004ad8a4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad8a6  8b1d70b24d00           -mov ebx, dword ptr [0x4db270]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004ad8ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad8af  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ad8b1  8b3483                 -mov esi, dword ptr [ebx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 4);
    // 004ad8b4  a160b24d00             -mov eax, dword ptr [0x4db260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 004ad8b9  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ad8bb  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad8bd  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004ad8c2  3c0f                   +cmp al, 0xf
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
    // 004ad8c4  7320                   -jae 0x4ad8e6
    if (!cpu.flags.cf)
    {
        goto L_0x004ad8e6;
    }
    // 004ad8c6  3c04                   +cmp al, 4
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
    // 004ad8c8  7216                   -jb 0x4ad8e0
    if (cpu.flags.cf)
    {
        goto L_0x004ad8e0;
    }
    // 004ad8ca  7733                   -ja 0x4ad8ff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ad8ff;
    }
    // 004ad8cc  f6042401               +test byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 1 /*0x1*/));
    // 004ad8d0  7435                   -je 0x4ad907
    if (cpu.flags.zf)
    {
        goto L_0x004ad907;
    }
    // 004ad8d2  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ad8d4  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004ad8d7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004ad8d9  c0e004                 -shl al, 4
    cpu.al <<= 4 /*0x4*/ % 32;
    // 004ad8dc  08c6                   -or dh, al
    cpu.dh |= x86::reg8(x86::sreg8(cpu.al));
    // 004ad8de  8831                   -mov byte ptr [ecx], dh
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dh;
L_0x004ad8e0:
    // 004ad8e0  83c404                 +add esp, 4
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
    // 004ad8e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad8e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad8e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad8e6:
    // 004ad8e6  7608                   -jbe 0x4ad8f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ad8f0;
    }
    // 004ad8e8  3c18                   +cmp al, 0x18
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
    // 004ad8ea  7309                   -jae 0x4ad8f5
    if (!cpu.flags.cf)
    {
        goto L_0x004ad8f5;
    }
    // 004ad8ec  3c10                   +cmp al, 0x10
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
    // 004ad8ee  75f0                   -jne 0x4ad8e0
    if (!cpu.flags.zf)
    {
        goto L_0x004ad8e0;
    }
L_0x004ad8f0:
    // 004ad8f0  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004ad8f3  ebeb                   -jmp 0x4ad8e0
    goto L_0x004ad8e0;
L_0x004ad8f5:
    // 004ad8f5  761e                   -jbe 0x4ad915
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ad915;
    }
    // 004ad8f7  3c20                   +cmp al, 0x20
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
    // 004ad8f9  75e5                   -jne 0x4ad8e0
    if (!cpu.flags.zf)
    {
        goto L_0x004ad8e0;
    }
    // 004ad8fb  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004ad8fd  ebe1                   -jmp 0x4ad8e0
    goto L_0x004ad8e0;
L_0x004ad8ff:
    // 004ad8ff  3c08                   +cmp al, 8
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
    // 004ad901  75dd                   -jne 0x4ad8e0
    if (!cpu.flags.zf)
    {
        goto L_0x004ad8e0;
    }
    // 004ad903  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004ad905  ebd9                   -jmp 0x4ad8e0
    goto L_0x004ad8e0;
L_0x004ad907:
    // 004ad907  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ad909  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004ad90b  08d0                   -or al, dl
    cpu.al |= x86::reg8(x86::sreg8(cpu.dl));
    // 004ad90d  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004ad90f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad912  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad913  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad914  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad915:
    // 004ad915  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004ad91a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad91c  e84ee7fdff             -call 0x48c06f
    cpu.esp -= 4;
    sub_48c06f(app, cpu);
    if (cpu.terminate) return;
    // 004ad921  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad924  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad925  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad926  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ad927(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad927  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ad928  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad929  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad92a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad92c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ad92e  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004ad933  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ad935  e8f54cfeff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004ad93a  eb1f                   -jmp 0x4ad95b
    goto L_0x004ad95b;
L_0x004ad93c:
    // 004ad93c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad93e  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004ad940  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004ad943  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 004ad946  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ad94c  8a92a41f4d00           -mov dl, byte ptr [edx + 0x4d1fa4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5054372) /* 0x4d1fa4 */);
    // 004ad952  8a3406                 -mov dh, byte ptr [esi + eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004ad955  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004ad957  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad958  883406                 -mov byte ptr [esi + eax], dh
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dh;
L_0x004ad95b:
    // 004ad95b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ad95d  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004ad95f  75db                   -jne 0x4ad93c
    if (!cpu.flags.zf)
    {
        goto L_0x004ad93c;
    }
    // 004ad961  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad962  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad963  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad964  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ad966(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad966  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ad967  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004ad96b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004ad96d  e8be8bfdff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 004ad972  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 004ad974  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ad978  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ad97a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad97b  9b                     -wait 
    /*nothing*/;
    // 004ad97c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4ad97f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad97f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ad980  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ad981  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ad983  8b1540685b00           -mov edx, dword ptr [0x5b6840]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5990464) /* 0x5b6840 */);
    // 004ad989  83fa20                 +cmp edx, 0x20
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
    // 004ad98c  7d15                   -jge 0x4ad9a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad9a3;
    }
    // 004ad98e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad990  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad992  42                     -inc edx
    (cpu.edx)++;
    // 004ad993  891c95bc675b00         -mov dword ptr [edx*4 + 0x5b67bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5990332) /* 0x5b67bc */ + cpu.edx * 4) = cpu.ebx;
    // 004ad99a  891540685b00           -mov dword ptr [0x5b6840], edx
    app->getMemory<x86::reg32>(x86::reg32(5990464) /* 0x5b6840 */) = cpu.edx;
    // 004ad9a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad9a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad9a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad9a3:
    // 004ad9a3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ad9a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad9a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad9aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ad9ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad9ab  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ad9ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ad9ad  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ad9ae  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004ad9b0  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004ad9b2  8b1d40685b00           -mov ebx, dword ptr [0x5b6840]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5990464) /* 0x5b6840 */);
    // 004ad9b8  83fb21                 +cmp ebx, 0x21
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
    // 004ad9bb  7421                   -je 0x4ad9de
    if (cpu.flags.zf)
    {
        goto L_0x004ad9de;
    }
    // 004ad9bd  c70540685b0021000000   -mov dword ptr [0x5b6840], 0x21
    app->getMemory<x86::reg32>(x86::reg32(5990464) /* 0x5b6840 */) = 33 /*0x21*/;
    // 004ad9c7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad9c9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
L_0x004ad9cc:
    // 004ad9cc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ad9ce  740e                   -je 0x4ad9de
    if (cpu.flags.zf)
    {
        goto L_0x004ad9de;
    }
    // 004ad9d0  8b82bc675b00           -mov eax, dword ptr [edx + 0x5b67bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5990332) /* 0x5b67bc */);
    // 004ad9d6  83ea04                 +sub edx, 4
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
    // 004ad9d9  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ad9da  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ad9dc  ebee                   -jmp 0x4ad9cc
    goto L_0x004ad9cc;
L_0x004ad9de:
    // 004ad9de  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ad9e0  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ad9e2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ad9e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad9e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad9e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ad9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad9f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad9f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ad9f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ad9f4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad9f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad9f8  7c3f                   -jl 0x4ada39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada39;
    }
L_0x004ad9fa:
    // 004ad9fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad9fc  743f                   -je 0x4ada3d
    if (cpu.flags.zf)
    {
        goto L_0x004ada3d;
    }
    // 004ad9fe  3d00000100             +cmp eax, 0x10000
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
    // 004ada03  7c06                   -jl 0x4ada0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada0b;
    }
    // 004ada05  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ada08  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ada0b:
    // 004ada0b  3d00010000             +cmp eax, 0x100
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
    // 004ada10  7c06                   -jl 0x4ada18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada18;
    }
    // 004ada12  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004ada15  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004ada18:
    // 004ada18  83f810                 +cmp eax, 0x10
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
    // 004ada1b  7c06                   -jl 0x4ada23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada23;
    }
    // 004ada1d  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004ada20  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004ada23:
    // 004ada23  83f804                 +cmp eax, 4
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
    // 004ada26  7c06                   -jl 0x4ada2e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada2e;
    }
    // 004ada28  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004ada2b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004ada2e:
    // 004ada2e  83f802                 +cmp eax, 2
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
    // 004ada31  7c01                   -jl 0x4ada34
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada34;
    }
    // 004ada33  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004ada34:
    // 004ada34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ada36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ada39:
    // 004ada39  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004ada3b  ebbd                   -jmp 0x4ad9fa
    goto L_0x004ad9fa;
L_0x004ada3d:
    // 004ada3d  ba3f000000             -mov edx, 0x3f
    cpu.edx = 63 /*0x3f*/;
    // 004ada42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ada44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ada50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ada50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ada51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ada52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ada53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ada54  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ada56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ada58  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ada5a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ada5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ada5e  7e58                   -jle 0x4adab8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adab8;
    }
    // 004ada60  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 004ada65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004ada67:
    // 004ada67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ada69  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004ada6b  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004ada71  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004ada74  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ada76  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ada79  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ada7b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ada7d  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004ada7f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004ada82  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004ada88  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ada8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ada8d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ada90  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ada92  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ada95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ada97  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004ada9a  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004adaa0  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004adaa3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adaa5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adaa8  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adaaa  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adaad  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adab0  46                     -inc esi
    (cpu.esi)++;
    // 004adab1  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004adab4  39fe                   +cmp esi, edi
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
    // 004adab6  7caf                   -jl 0x4ada67
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ada67;
    }
L_0x004adab8:
    // 004adab8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adab9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adaba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adabb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adabc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4adac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adac0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adac1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adac2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adac3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adac4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004adac6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004adac8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004adaca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adacc  7e68                   -jle 0x4adb36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adb36;
    }
    // 004adace  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 004adad3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004adad5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004adad7:
    // 004adad7  81feff000000           +cmp esi, 0xff
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
    // 004adadd  755c                   -jne 0x4adb3b
    if (!cpu.flags.zf)
    {
        goto L_0x004adb3b;
    }
    // 004adadf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004adae1:
    // 004adae1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004adae3  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004adae6  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004adae8  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004adaee  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004adaf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adaf3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adaf6  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adaf8  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004adafb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adafd  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004adb00  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004adb06  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004adb09  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adb0b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adb0e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adb10  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004adb13  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adb15  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004adb18  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004adb1e  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004adb21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adb23  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adb26  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adb28  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adb2b  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adb2e  46                     -inc esi
    (cpu.esi)++;
    // 004adb2f  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 004adb32  39fe                   +cmp esi, edi
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
    // 004adb34  7ca1                   -jl 0x4adad7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adad7;
    }
L_0x004adb36:
    // 004adb36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adb3b:
    // 004adb3b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004adb40  eb9f                   -jmp 0x4adae1
    goto L_0x004adae1;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4adb44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adb44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adb45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adb46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adb47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adb48  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004adb4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adb4c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004adb4e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004adb50  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adb52  7e58                   -jle 0x4adbac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adbac;
    }
    // 004adb54  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004adb59  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004adb5b:
    // 004adb5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adb5d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004adb5f  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004adb62  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004adb68  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adb6a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adb6d  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adb6f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004adb71  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004adb73  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004adb76  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004adb79  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004adb7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adb81  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adb84  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adb86  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004adb89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adb8b  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004adb8e  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004adb91  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004adb97  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adb99  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adb9c  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adb9e  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adba1  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adba4  46                     -inc esi
    (cpu.esi)++;
    // 004adba5  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004adba8  39fe                   +cmp esi, edi
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
    // 004adbaa  7caf                   -jl 0x4adb5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adb5b;
    }
L_0x004adbac:
    // 004adbac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4adbb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adbb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adbb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adbb6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adbb7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adbba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004adbbc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004adbbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004adbc0  7e33                   -jle 0x4adbf5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adbf5;
    }
    // 004adbc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004adbc4:
    // 004adbc4  81f9ff000000           +cmp ecx, 0xff
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
    // 004adbca  7430                   -je 0x4adbfc
    if (cpu.flags.zf)
    {
        goto L_0x004adbfc;
    }
    // 004adbcc  c70424ff000000         -mov dword ptr [esp], 0xff
    app->getMemory<x86::reg32>(cpu.esp) = 255 /*0xff*/;
L_0x004adbd3:
    // 004adbd3  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 004adbd6  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 004adbd9  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004adbdb  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004adbde  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004adbe1  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adbe4  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004adbe7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adbea  8a5aff                 -mov bl, byte ptr [edx - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004adbed  41                     -inc ecx
    (cpu.ecx)++;
    // 004adbee  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 004adbf1  39f1                   +cmp ecx, esi
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
    // 004adbf3  7ccf                   -jl 0x4adbc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adbc4;
    }
L_0x004adbf5:
    // 004adbf5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adbf8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbf9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adbfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adbfc:
    // 004adbfc  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004adbfe  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004adc01  ebd0                   -jmp 0x4adbd3
    goto L_0x004adbd3;
}

/* align: skip 0x90 */
void Application::sub_4adc04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adc04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adc05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adc06  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adc07  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adc08  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004adc0a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adc0c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004adc0e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004adc10  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adc12  7e5c                   -jle 0x4adc70
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adc70;
    }
    // 004adc14  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004adc19  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004adc1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004adc1d:
    // 004adc1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004adc1f  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004adc22  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004adc25  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004adc2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adc2d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adc30  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adc32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004adc34  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004adc36  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004adc39  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004adc3c  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004adc42  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adc44  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adc47  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adc49  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004adc4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adc4e  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004adc50  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004adc53  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004adc59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adc5b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adc5e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adc60  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adc63  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adc66  46                     -inc esi
    (cpu.esi)++;
    // 004adc67  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004adc6a  39fe                   +cmp esi, edi
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
    // 004adc6c  7caf                   -jl 0x4adc1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adc1d;
    }
    // 004adc6e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004adc70:
    // 004adc70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4adc78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adc78  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adc79  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adc7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004adc7c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004adc7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004adc80  7e1e                   -jle 0x4adca0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adca0;
    }
    // 004adc82  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004adc84:
    // 004adc84  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004adc87  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004adc89  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004adc8c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adc8f  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004adc92  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adc95  8a5afc                 -mov bl, byte ptr [edx - 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004adc98  41                     -inc ecx
    (cpu.ecx)++;
    // 004adc99  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004adc9c  39f1                   +cmp ecx, esi
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
    // 004adc9e  7ce4                   -jl 0x4adc84
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adc84;
    }
L_0x004adca0:
    // 004adca0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adca1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adca2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4adca3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adca3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004adca4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004adca6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adca8  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004adcaa  e836540000             -call 0x4b30e5
    cpu.esp -= 4;
    sub_4b30e5(app, cpu);
    if (cpu.terminate) return;
    // 004adcaf  ff4310                 -inc dword ptr [ebx + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 004adcb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adcb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4adcb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adcb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adcb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adcb6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adcb7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adcb8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004adcba  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004adcbd  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004adcc3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004adcc6  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004adcc9  83f901                 +cmp ecx, 1
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
    // 004adccc  741b                   -je 0x4adce9
    if (cpu.flags.zf)
    {
        goto L_0x004adce9;
    }
    // 004adcce  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004adcd0  7410                   -je 0x4adce2
    if (cpu.flags.zf)
    {
        goto L_0x004adce2;
    }
    // 004adcd2  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adcd5  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004adcdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adcdd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adcde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adcdf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adce0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adce1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adce2:
    // 004adce2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004adce9:
    // 004adce9  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004adcec  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 004adcef  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004adcf2  88660c                 -mov byte ptr [esi + 0xc], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 004adcf5  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004adcf8  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004adcfb  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004adcfe  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004add00  7507                   -jne 0x4add09
    if (!cpu.flags.zf)
    {
        goto L_0x004add09;
    }
    // 004add02  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004add04  e802250000             -call 0x4b020b
    cpu.esp -= 4;
    sub_4b020b(app, cpu);
    if (cpu.terminate) return;
L_0x004add09:
    // 004add09  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004add0c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004add0e  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004add11  7414                   -je 0x4add27
    if (cpu.flags.zf)
    {
        goto L_0x004add27;
    }
    // 004add13  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004add15  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004add18  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 004add1a  886e0d                 -mov byte ptr [esi + 0xd], ch
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 004add1d  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004add1f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004add24  88460d                 -mov byte ptr [esi + 0xd], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x004add27:
    // 004add27  b9a3dc4a00             -mov ecx, 0x4adca3
    cpu.ecx = 4906147 /*0x4adca3*/;
    // 004add2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004add2e  e8c5540000             -call 0x4b31f8
    cpu.esp -= 4;
    sub_4b31f8(app, cpu);
    if (cpu.terminate) return;
    // 004add33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004add35  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004add37  7418                   -je 0x4add51
    if (cpu.flags.zf)
    {
        goto L_0x004add51;
    }
    // 004add39  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004add3c  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004add3f  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 004add41  88660d                 -mov byte ptr [esi + 0xd], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004add44  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004add47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004add49  885e0d                 -mov byte ptr [esi + 0xd], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004add4c  e83ed5ffff             -call 0x4ab28f
    cpu.esp -= 4;
    sub_4ab28f(app, cpu);
    if (cpu.terminate) return;
L_0x004add51:
    // 004add51  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004add55  7405                   -je 0x4add5c
    if (cpu.flags.zf)
    {
        goto L_0x004add5c;
    }
    // 004add57  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004add5c:
    // 004add5c  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004add5f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004add61  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004add64  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004add67  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004add6d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004add6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4add74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004add74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004add75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004add76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004add77  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004add7d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004add7f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004add81  83f90c                 +cmp ecx, 0xc
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
    // 004add84  7336                   -jae 0x4addbc
    if (!cpu.flags.cf)
    {
        goto L_0x004addbc;
    }
L_0x004add86:
    // 004add86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004add88  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004add8a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004add8d  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004add93  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004add96  43                     -inc ebx
    (cpu.ebx)++;
    // 004add97  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004add9e  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004adda3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004adda5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adda7  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004addaa  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004addb0  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004addb3  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004addb5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004addb6  75ce                   -jne 0x4add86
    if (!cpu.flags.zf)
    {
        goto L_0x004add86;
    }
    // 004addb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004addb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004addba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004addbb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004addbc:
    // 004addbc  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004addc2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004addc4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004addc6  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004addcc  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004addcf  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004addd2  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004addd7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004addd9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004adddb  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004addde  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adde1  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004adde6  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004addec  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004addf1  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004addf7  c1f810                 +sar eax, 0x10
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
    // 004addfa  7809                   -js 0x4ade05
    if (cpu.flags.sf)
    {
        goto L_0x004ade05;
    }
    // 004addfc  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ade03  eb0b                   -jmp 0x4ade10
    goto L_0x004ade10;
L_0x004ade05:
    // 004ade05  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ade07  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ade0e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ade10:
    // 004ade10  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ade13  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ade15  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004ade1a  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004ade20  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004ade25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ade27  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ade29  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ade2c  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ade32  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ade35  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ade3c  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ade3e  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004ade41  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ade47  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ade4a  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ade50  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004ade53  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004ade56:
    // 004ade56  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ade5c  781d                   -js 0x4ade7b
    if (cpu.flags.sf)
    {
        goto L_0x004ade7b;
    }
    // 004ade5e  43                     -inc ebx
    (cpu.ebx)++;
    // 004ade5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ade61  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ade63  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ade69  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004ade6c  01ca                   +add edx, ecx
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
    // 004ade6e  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ade70  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ade72  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ade79  ebdb                   -jmp 0x4ade56
    goto L_0x004ade56;
L_0x004ade7b:
    // 004ade7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ade7d  01ca                   +add edx, ecx
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
    // 004ade7f  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ade81  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ade83  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ade85  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ade8c  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004ade91  01ca                   +add edx, ecx
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
    // 004ade93  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ade95  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ade97  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ade99  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004adea0  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004adea5  01ca                   +add edx, ecx
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
    // 004adea7  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004adea9  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adeab  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004adead  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004adeb4  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004adeb9  01ca                   +add edx, ecx
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
    // 004adebb  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004adebd  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adebf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004adec1  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004adec8  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004adecd  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004aded3  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004aded8  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adedb  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adede  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004adee4  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004adee9  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004adeee  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004adef1  7588                   -jne 0x4ade7b
    if (!cpu.flags.zf)
    {
        goto L_0x004ade7b;
    }
L_0x004adef3:
    // 004adef3  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004adef9  781d                   -js 0x4adf18
    if (cpu.flags.sf)
    {
        goto L_0x004adf18;
    }
    // 004adefb  43                     -inc ebx
    (cpu.ebx)++;
    // 004adefc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adefe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004adf00  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004adf06  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004adf09  01ca                   +add edx, ecx
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
    // 004adf0b  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004adf0d  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adf0f  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adf16  ebdb                   -jmp 0x4adef3
    goto L_0x004adef3;
L_0x004adf18:
    // 004adf18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adf19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adf1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adf1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4adf1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adf1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adf1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adf1e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adf1f  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004adf25  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004adf27  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004adf29:
    // 004adf29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adf2b  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004adf2d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004adf30  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004adf36  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004adf39  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004adf3c  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004adf43  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004adf48  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004adf4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adf4c  668b047e               -mov ax, word ptr [esi + edi*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.edi * 2);
    // 004adf50  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004adf56  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004adf5a  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adf5c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004adf5d  75ca                   -jne 0x4adf29
    if (!cpu.flags.zf)
    {
        goto L_0x004adf29;
    }
    // 004adf5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adf60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adf61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adf62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4adf64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adf64  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adf65  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adf66  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adf67  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004adf6d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004adf6f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004adf71  83f90c                 +cmp ecx, 0xc
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
    // 004adf74  733a                   -jae 0x4adfb0
    if (!cpu.flags.cf)
    {
        goto L_0x004adfb0;
    }
L_0x004adf76:
    // 004adf76  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adf78  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004adf7a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004adf7d  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004adf83  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004adf86  43                     -inc ebx
    (cpu.ebx)++;
    // 004adf87  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004adf8e  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004adf93  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004adf95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adf97  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004adf9a  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004adfa0  3cff                   +cmp al, 0xff
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
    // 004adfa2  7403                   -je 0x4adfa7
    if (cpu.flags.zf)
    {
        goto L_0x004adfa7;
    }
    // 004adfa4  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004adfa7:
    // 004adfa7  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004adfa9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004adfaa  75ca                   -jne 0x4adf76
    if (!cpu.flags.zf)
    {
        goto L_0x004adf76;
    }
    // 004adfac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adfb0:
    // 004adfb0  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004adfb6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adfb8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004adfba  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004adfc0  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004adfc3  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adfc6  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004adfcb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adfcd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004adfcf  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004adfd2  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004adfd5  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004adfda  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004adfe0  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004adfe5  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004adfeb  c1f810                 +sar eax, 0x10
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
    // 004adfee  7809                   -js 0x4adff9
    if (cpu.flags.sf)
    {
        goto L_0x004adff9;
    }
    // 004adff0  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004adff7  eb0b                   -jmp 0x4ae004
    goto L_0x004ae004;
L_0x004adff9:
    // 004adff9  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004adffb  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae002  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ae004:
    // 004ae004  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae007  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae009  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004ae00e  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004ae014  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004ae019  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae01b  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ae01d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae020  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae026  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ae029  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae030  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae032  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004ae035  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae03b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ae03e  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae044  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004ae047  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004ae04a:
    // 004ae04a  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae050  7821                   -js 0x4ae073
    if (cpu.flags.sf)
    {
        goto L_0x004ae073;
    }
    // 004ae052  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae053  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae055  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae057  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae05d  3cff                   +cmp al, 0xff
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
    // 004ae05f  7403                   -je 0x4ae064
    if (cpu.flags.zf)
    {
        goto L_0x004ae064;
    }
    // 004ae061  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae064:
    // 004ae064  01ca                   +add edx, ecx
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
    // 004ae066  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae068  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae06a  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae071  ebd7                   -jmp 0x4ae04a
    goto L_0x004ae04a;
L_0x004ae073:
    // 004ae073  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae075  01ca                   +add edx, ecx
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
    // 004ae077  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae079  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae07b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae07d  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae084  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004ae089  01ca                   +add edx, ecx
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
    // 004ae08b  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae08d  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae08f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae091  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae098  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004ae09d  01ca                   +add edx, ecx
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
    // 004ae09f  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae0a1  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae0a3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae0a5  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae0ac  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004ae0b1  01ca                   +add edx, ecx
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
    // 004ae0b3  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae0b5  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae0b7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae0b9  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae0c0  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004ae0c5  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004ae0ca  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004ae0d0  3cff                   +cmp al, 0xff
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
    // 004ae0d2  7434                   -je 0x4ae108
    if (cpu.flags.zf)
    {
        goto L_0x004ae108;
    }
    // 004ae0d4  80fcff                 +cmp ah, 0xff
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
    // 004ae0d7  742a                   -je 0x4ae103
    if (cpu.flags.zf)
    {
        goto L_0x004ae103;
    }
    // 004ae0d9  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004ae0dc  3cff                   +cmp al, 0xff
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
    // 004ae0de  7412                   -je 0x4ae0f2
    if (cpu.flags.zf)
    {
        goto L_0x004ae0f2;
    }
    // 004ae0e0  80fcff                 +cmp ah, 0xff
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
    // 004ae0e3  7407                   -je 0x4ae0ec
    if (cpu.flags.zf)
    {
        goto L_0x004ae0ec;
    }
    // 004ae0e5  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004ae0e8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ae0ea  eb44                   -jmp 0x4ae130
    goto L_0x004ae130;
L_0x004ae0ec:
    // 004ae0ec  90                     -nop 
    ;
    // 004ae0ed  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ae0f0  eb09                   -jmp 0x4ae0fb
    goto L_0x004ae0fb;
L_0x004ae0f2:
    // 004ae0f2  80fcff                 +cmp ah, 0xff
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
    // 004ae0f5  7404                   -je 0x4ae0fb
    if (cpu.flags.zf)
    {
        goto L_0x004ae0fb;
    }
    // 004ae0f7  90                     -nop 
    ;
    // 004ae0f8  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004ae0fb:
    // 004ae0fb  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004ae0fe  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004ae101  eb2d                   -jmp 0x4ae130
    goto L_0x004ae130;
L_0x004ae103:
    // 004ae103  90                     -nop 
    ;
    // 004ae104  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004ae106  eb09                   -jmp 0x4ae111
    goto L_0x004ae111;
L_0x004ae108:
    // 004ae108  80fcff                 +cmp ah, 0xff
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
    // 004ae10b  7404                   -je 0x4ae111
    if (cpu.flags.zf)
    {
        goto L_0x004ae111;
    }
    // 004ae10d  90                     -nop 
    ;
    // 004ae10e  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004ae111:
    // 004ae111  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004ae114  3cff                   +cmp al, 0xff
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
    // 004ae116  7410                   -je 0x4ae128
    if (cpu.flags.zf)
    {
        goto L_0x004ae128;
    }
    // 004ae118  80fcff                 +cmp ah, 0xff
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
    // 004ae11b  7406                   -je 0x4ae123
    if (cpu.flags.zf)
    {
        goto L_0x004ae123;
    }
    // 004ae11d  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004ae121  eb0d                   -jmp 0x4ae130
    goto L_0x004ae130;
L_0x004ae123:
    // 004ae123  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ae126  eb08                   -jmp 0x4ae130
    goto L_0x004ae130;
L_0x004ae128:
    // 004ae128  80fcff                 +cmp ah, 0xff
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
    // 004ae12b  7403                   -je 0x4ae130
    if (cpu.flags.zf)
    {
        goto L_0x004ae130;
    }
    // 004ae12d  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004ae130:
    // 004ae130  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004ae135  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae138  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae13b  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae141  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae146  0f8527ffffff           -jne 0x4ae073
    if (!cpu.flags.zf)
    {
        goto L_0x004ae073;
    }
L_0x004ae14c:
    // 004ae14c  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae152  7821                   -js 0x4ae175
    if (cpu.flags.sf)
    {
        goto L_0x004ae175;
    }
    // 004ae154  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae155  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae157  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae159  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae15f  3cff                   +cmp al, 0xff
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
    // 004ae161  7403                   -je 0x4ae166
    if (cpu.flags.zf)
    {
        goto L_0x004ae166;
    }
    // 004ae163  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae166:
    // 004ae166  01ca                   +add edx, ecx
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
    // 004ae168  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae16a  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae16c  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae173  ebd7                   -jmp 0x4ae14c
    goto L_0x004ae14c;
L_0x004ae175:
    // 004ae175  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae176  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae177  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ae179(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae179  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae17a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae17b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae17c  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae182  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ae184  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004ae186:
    // 004ae186  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae188  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ae18a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae18d  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae193  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004ae196  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ae199  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae1a0  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae1a5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae1a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae1a9  668b047e               -mov ax, word ptr [esi + edi*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.edi * 2);
    // 004ae1ad  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae1b3  6683f800               +cmp ax, 0
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ae1b7  7404                   -je 0x4ae1bd
    if (cpu.flags.zf)
    {
        goto L_0x004ae1bd;
    }
    // 004ae1b9  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
L_0x004ae1bd:
    // 004ae1bd  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae1bf  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae1c0  75c4                   -jne 0x4ae186
    if (!cpu.flags.zf)
    {
        goto L_0x004ae186;
    }
    // 004ae1c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae1c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae1c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae1c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4ae1c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae1c8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae1c9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae1ca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae1cb  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae1d1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ae1d3  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae1d5  83f90c                 +cmp ecx, 0xc
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
    // 004ae1d8  7345                   -jae 0x4ae21f
    if (!cpu.flags.cf)
    {
        goto L_0x004ae21f;
    }
L_0x004ae1da:
    // 004ae1da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae1dc  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ae1de  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae1e1  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae1e7  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004ae1ea  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae1eb  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae1f2  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae1f7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae1f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae1fb  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004ae1fe  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae204  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae206  7509                   -jne 0x4ae211
    if (!cpu.flags.zf)
    {
        goto L_0x004ae211;
    }
    // 004ae208  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ae20b  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae211:
    // 004ae211  7703                   -ja 0x4ae216
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae216;
    }
    // 004ae213  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae216:
    // 004ae216  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae218  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae219  75bf                   -jne 0x4ae1da
    if (!cpu.flags.zf)
    {
        goto L_0x004ae1da;
    }
    // 004ae21b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae21c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae21d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae21e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae21f:
    // 004ae21f  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae225  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae227  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae229  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae22f  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004ae232  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae235  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004ae23a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae23c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ae23e  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004ae241  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae244  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae249  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004ae24f  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae254  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae25a  c1f810                 +sar eax, 0x10
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
    // 004ae25d  7809                   -js 0x4ae268
    if (cpu.flags.sf)
    {
        goto L_0x004ae268;
    }
    // 004ae25f  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae266  eb0b                   -jmp 0x4ae273
    goto L_0x004ae273;
L_0x004ae268:
    // 004ae268  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ae26a  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae271  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ae273:
    // 004ae273  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae276  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae278  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004ae27d  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004ae283  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004ae288  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae28a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ae28c  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae28f  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae295  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ae298  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae29f  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae2a1  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004ae2a4  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae2aa  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ae2ad  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae2b3  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004ae2b6  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004ae2b9:
    // 004ae2b9  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae2bf  782c                   -js 0x4ae2ed
    if (cpu.flags.sf)
    {
        goto L_0x004ae2ed;
    }
    // 004ae2c1  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae2c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae2c4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae2c6  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae2cc  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae2ce  7509                   -jne 0x4ae2d9
    if (!cpu.flags.zf)
    {
        goto L_0x004ae2d9;
    }
    // 004ae2d0  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ae2d3  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae2d9:
    // 004ae2d9  7703                   -ja 0x4ae2de
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae2de;
    }
    // 004ae2db  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae2de:
    // 004ae2de  01ca                   +add edx, ecx
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
    // 004ae2e0  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae2e2  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae2e4  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae2eb  ebcc                   -jmp 0x4ae2b9
    goto L_0x004ae2b9;
L_0x004ae2ed:
    // 004ae2ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae2ef  01ca                   +add edx, ecx
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
    // 004ae2f1  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae2f3  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae2f5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae2f7  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae2fe  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004ae303  01ca                   +add edx, ecx
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
    // 004ae305  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae307  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae309  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae30b  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae312  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004ae317  01ca                   +add edx, ecx
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
    // 004ae319  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae31b  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae31d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae31f  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae326  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004ae32b  01ca                   +add edx, ecx
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
    // 004ae32d  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae32f  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae331  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae333  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae33a  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004ae33f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ae340  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004ae345  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004ae34b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae34d  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae34f  7508                   -jne 0x4ae359
    if (!cpu.flags.zf)
    {
        goto L_0x004ae359;
    }
    // 004ae351  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004ae353  8a82ac054e00           -mov al, byte ptr [edx + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae359:
    // 004ae359  7760                   -ja 0x4ae3bb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae3bb;
    }
    // 004ae35b  80fcfe                 +cmp ah, 0xfe
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
    // 004ae35e  7509                   -jne 0x4ae369
    if (!cpu.flags.zf)
    {
        goto L_0x004ae369;
    }
    // 004ae360  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004ae363  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae369:
    // 004ae369  774b                   -ja 0x4ae3b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae3b6;
    }
    // 004ae36b  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004ae36e  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae370  7509                   -jne 0x4ae37b
    if (!cpu.flags.zf)
    {
        goto L_0x004ae37b;
    }
    // 004ae372  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004ae375  8a82ac054e00           -mov al, byte ptr [edx + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae37b:
    // 004ae37b  771d                   -ja 0x4ae39a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae39a;
    }
    // 004ae37d  80fcfe                 +cmp ah, 0xfe
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
    // 004ae380  7509                   -jne 0x4ae38b
    if (!cpu.flags.zf)
    {
        goto L_0x004ae38b;
    }
    // 004ae382  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004ae385  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae38b:
    // 004ae38b  7707                   -ja 0x4ae394
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae394;
    }
    // 004ae38d  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004ae390  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ae392  eb7b                   -jmp 0x4ae40f
    goto L_0x004ae40f;
L_0x004ae394:
    // 004ae394  90                     -nop 
    ;
    // 004ae395  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ae398  eb14                   -jmp 0x4ae3ae
    goto L_0x004ae3ae;
L_0x004ae39a:
    // 004ae39a  80fcfe                 +cmp ah, 0xfe
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
    // 004ae39d  7509                   -jne 0x4ae3a8
    if (!cpu.flags.zf)
    {
        goto L_0x004ae3a8;
    }
    // 004ae39f  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004ae3a2  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae3a8:
    // 004ae3a8  7704                   -ja 0x4ae3ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae3ae;
    }
    // 004ae3aa  90                     -nop 
    ;
    // 004ae3ab  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004ae3ae:
    // 004ae3ae  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004ae3b1  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004ae3b4  eb59                   -jmp 0x4ae40f
    goto L_0x004ae40f;
L_0x004ae3b6:
    // 004ae3b6  90                     -nop 
    ;
    // 004ae3b7  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004ae3b9  eb14                   -jmp 0x4ae3cf
    goto L_0x004ae3cf;
L_0x004ae3bb:
    // 004ae3bb  80fcfe                 +cmp ah, 0xfe
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
    // 004ae3be  7509                   -jne 0x4ae3c9
    if (!cpu.flags.zf)
    {
        goto L_0x004ae3c9;
    }
    // 004ae3c0  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004ae3c3  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae3c9:
    // 004ae3c9  7704                   -ja 0x4ae3cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae3cf;
    }
    // 004ae3cb  90                     -nop 
    ;
    // 004ae3cc  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004ae3cf:
    // 004ae3cf  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004ae3d2  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae3d4  7509                   -jne 0x4ae3df
    if (!cpu.flags.zf)
    {
        goto L_0x004ae3df;
    }
    // 004ae3d6  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004ae3d9  8a82ac054e00           -mov al, byte ptr [edx + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae3df:
    // 004ae3df  771b                   -ja 0x4ae3fc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae3fc;
    }
    // 004ae3e1  80fcfe                 +cmp ah, 0xfe
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
    // 004ae3e4  7509                   -jne 0x4ae3ef
    if (!cpu.flags.zf)
    {
        goto L_0x004ae3ef;
    }
    // 004ae3e6  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004ae3e9  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae3ef:
    // 004ae3ef  7706                   -ja 0x4ae3f7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae3f7;
    }
    // 004ae3f1  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004ae3f5  eb18                   -jmp 0x4ae40f
    goto L_0x004ae40f;
L_0x004ae3f7:
    // 004ae3f7  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ae3fa  eb13                   -jmp 0x4ae40f
    goto L_0x004ae40f;
L_0x004ae3fc:
    // 004ae3fc  80fcfe                 +cmp ah, 0xfe
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
    // 004ae3ff  7509                   -jne 0x4ae40a
    if (!cpu.flags.zf)
    {
        goto L_0x004ae40a;
    }
    // 004ae401  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004ae404  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae40a:
    // 004ae40a  7703                   -ja 0x4ae40f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae40f;
    }
    // 004ae40c  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004ae40f:
    // 004ae40f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae410  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004ae415  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae418  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae41b  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae421  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae426  0f85c1feffff           -jne 0x4ae2ed
    if (!cpu.flags.zf)
    {
        goto L_0x004ae2ed;
    }
L_0x004ae42c:
    // 004ae42c  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae432  782c                   -js 0x4ae460
    if (cpu.flags.sf)
    {
        goto L_0x004ae460;
    }
    // 004ae434  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae435  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae437  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae439  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae43f  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae441  7509                   -jne 0x4ae44c
    if (!cpu.flags.zf)
    {
        goto L_0x004ae44c;
    }
    // 004ae443  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ae446  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae44c:
    // 004ae44c  7703                   -ja 0x4ae451
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae451;
    }
    // 004ae44e  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae451:
    // 004ae451  01ca                   +add edx, ecx
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
    // 004ae453  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae455  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae457  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae45e  ebcc                   -jmp 0x4ae42c
    goto L_0x004ae42c;
L_0x004ae460:
    // 004ae460  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae461  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae462  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae463  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ae464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae464  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae465  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae466  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae467  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae46d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ae46f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae471  83f90c                 +cmp ecx, 0xc
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
    // 004ae474  733c                   -jae 0x4ae4b2
    if (!cpu.flags.cf)
    {
        goto L_0x004ae4b2;
    }
L_0x004ae476:
    // 004ae476  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae478  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ae47a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae47d  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae483  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004ae486  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae487  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae48e  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae493  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae495  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae497  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004ae49a  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae4a0  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae4a2  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae4a8  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004ae4ab  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae4ac  75c8                   -jne 0x4ae476
    if (!cpu.flags.zf)
    {
        goto L_0x004ae476;
    }
    // 004ae4ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae4af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae4b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae4b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae4b2:
    // 004ae4b2  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae4b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae4ba  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae4bc  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae4c2  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004ae4c5  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae4c8  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004ae4cd  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae4cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ae4d1  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004ae4d4  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae4d7  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae4dc  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004ae4e2  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae4e7  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae4ed  c1f810                 +sar eax, 0x10
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
    // 004ae4f0  7809                   -js 0x4ae4fb
    if (cpu.flags.sf)
    {
        goto L_0x004ae4fb;
    }
    // 004ae4f2  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae4f9  eb0b                   -jmp 0x4ae506
    goto L_0x004ae506;
L_0x004ae4fb:
    // 004ae4fb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ae4fd  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae504  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ae506:
    // 004ae506  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae509  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae50b  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004ae510  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004ae516  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004ae51b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae51d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ae51f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae522  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae528  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ae52b  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae532  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae534  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004ae537  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae53d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ae540  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae546  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004ae549  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004ae54c:
    // 004ae54c  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae552  7823                   -js 0x4ae577
    if (cpu.flags.sf)
    {
        goto L_0x004ae577;
    }
    // 004ae554  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae555  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae557  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae559  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae55f  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae565  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004ae568  01ca                   +add edx, ecx
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
    // 004ae56a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae56c  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae56e  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae575  ebd5                   -jmp 0x4ae54c
    goto L_0x004ae54c;
L_0x004ae577:
    // 004ae577  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae579  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae57b  01ca                   +add edx, ecx
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
    // 004ae57d  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae57f  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae581  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae587  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae58e  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004ae593  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae595  01ca                   +add edx, ecx
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
    // 004ae597  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae599  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae59b  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae5a1  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae5a8  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004ae5ad  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae5af  01ca                   +add edx, ecx
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
    // 004ae5b1  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae5b3  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae5b5  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae5bb  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae5c2  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004ae5c7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae5c9  01ca                   +add edx, ecx
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
    // 004ae5cb  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae5cd  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae5cf  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae5d5  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae5dc  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004ae5e1  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004ae5e7  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004ae5ec  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae5ef  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae5f2  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae5f8  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae5fd  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004ae602  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004ae605  0f856cffffff           -jne 0x4ae577
    if (!cpu.flags.zf)
    {
        goto L_0x004ae577;
    }
L_0x004ae60b:
    // 004ae60b  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae611  7823                   -js 0x4ae636
    if (cpu.flags.sf)
    {
        goto L_0x004ae636;
    }
    // 004ae613  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae614  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae616  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae618  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae61e  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae624  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004ae627  01ca                   +add edx, ecx
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
    // 004ae629  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae62b  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae62d  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae634  ebd5                   -jmp 0x4ae60b
    goto L_0x004ae60b;
L_0x004ae636:
    // 004ae636  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae637  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae638  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae639  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4ae63c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae63c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae63d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae63e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae63f  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae645  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ae647  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae649  83f90c                 +cmp ecx, 0xc
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
    // 004ae64c  7340                   -jae 0x4ae68e
    if (!cpu.flags.cf)
    {
        goto L_0x004ae68e;
    }
L_0x004ae64e:
    // 004ae64e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae650  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ae652  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae655  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae65b  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004ae65e  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae65f  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae666  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae66b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae66d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae66f  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004ae672  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae678  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ae67a  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae680  3cff                   +cmp al, 0xff
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
    // 004ae682  7403                   -je 0x4ae687
    if (cpu.flags.zf)
    {
        goto L_0x004ae687;
    }
    // 004ae684  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae687:
    // 004ae687  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae688  75c4                   -jne 0x4ae64e
    if (!cpu.flags.zf)
    {
        goto L_0x004ae64e;
    }
    // 004ae68a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae68b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae68c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae68d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae68e:
    // 004ae68e  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae694  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae696  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae698  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae69e  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004ae6a1  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae6a4  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004ae6a9  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae6ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ae6ad  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004ae6b0  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae6b3  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae6b8  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004ae6be  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae6c3  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae6c9  c1f810                 +sar eax, 0x10
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
    // 004ae6cc  7809                   -js 0x4ae6d7
    if (cpu.flags.sf)
    {
        goto L_0x004ae6d7;
    }
    // 004ae6ce  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae6d5  eb0b                   -jmp 0x4ae6e2
    goto L_0x004ae6e2;
L_0x004ae6d7:
    // 004ae6d7  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ae6d9  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae6e0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ae6e2:
    // 004ae6e2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae6e5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae6e7  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004ae6ec  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004ae6f2  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004ae6f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae6f9  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ae6fb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae6fe  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae704  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ae707  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae70e  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae710  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004ae713  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae719  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ae71c  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae722  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004ae725  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004ae728:
    // 004ae728  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae72e  7827                   -js 0x4ae757
    if (cpu.flags.sf)
    {
        goto L_0x004ae757;
    }
    // 004ae730  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae731  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae733  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae735  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae73b  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae741  3cff                   +cmp al, 0xff
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
    // 004ae743  7403                   -je 0x4ae748
    if (cpu.flags.zf)
    {
        goto L_0x004ae748;
    }
    // 004ae745  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae748:
    // 004ae748  01ca                   +add edx, ecx
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
    // 004ae74a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae74c  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae74e  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae755  ebd1                   -jmp 0x4ae728
    goto L_0x004ae728;
L_0x004ae757:
    // 004ae757  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae759  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae75b  01ca                   +add edx, ecx
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
    // 004ae75d  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae75f  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae761  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae767  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae76e  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004ae773  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae775  01ca                   +add edx, ecx
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
    // 004ae777  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae779  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae77b  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae781  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae788  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004ae78d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae78f  01ca                   +add edx, ecx
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
    // 004ae791  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae793  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae795  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae79b  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae7a2  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004ae7a7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae7a9  01ca                   +add edx, ecx
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
    // 004ae7ab  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae7ad  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae7af  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae7b5  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae7bc  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004ae7c1  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004ae7c6  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004ae7cc  3cff                   +cmp al, 0xff
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
    // 004ae7ce  7434                   -je 0x4ae804
    if (cpu.flags.zf)
    {
        goto L_0x004ae804;
    }
    // 004ae7d0  80fcff                 +cmp ah, 0xff
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
    // 004ae7d3  742a                   -je 0x4ae7ff
    if (cpu.flags.zf)
    {
        goto L_0x004ae7ff;
    }
    // 004ae7d5  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004ae7d8  3cff                   +cmp al, 0xff
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
    // 004ae7da  7412                   -je 0x4ae7ee
    if (cpu.flags.zf)
    {
        goto L_0x004ae7ee;
    }
    // 004ae7dc  80fcff                 +cmp ah, 0xff
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
    // 004ae7df  7407                   -je 0x4ae7e8
    if (cpu.flags.zf)
    {
        goto L_0x004ae7e8;
    }
    // 004ae7e1  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004ae7e4  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ae7e6  eb44                   -jmp 0x4ae82c
    goto L_0x004ae82c;
L_0x004ae7e8:
    // 004ae7e8  90                     -nop 
    ;
    // 004ae7e9  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ae7ec  eb09                   -jmp 0x4ae7f7
    goto L_0x004ae7f7;
L_0x004ae7ee:
    // 004ae7ee  80fcff                 +cmp ah, 0xff
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
    // 004ae7f1  7404                   -je 0x4ae7f7
    if (cpu.flags.zf)
    {
        goto L_0x004ae7f7;
    }
    // 004ae7f3  90                     -nop 
    ;
    // 004ae7f4  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004ae7f7:
    // 004ae7f7  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004ae7fa  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004ae7fd  eb2d                   -jmp 0x4ae82c
    goto L_0x004ae82c;
L_0x004ae7ff:
    // 004ae7ff  90                     -nop 
    ;
    // 004ae800  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004ae802  eb09                   -jmp 0x4ae80d
    goto L_0x004ae80d;
L_0x004ae804:
    // 004ae804  80fcff                 +cmp ah, 0xff
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
    // 004ae807  7404                   -je 0x4ae80d
    if (cpu.flags.zf)
    {
        goto L_0x004ae80d;
    }
    // 004ae809  90                     -nop 
    ;
    // 004ae80a  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004ae80d:
    // 004ae80d  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004ae810  3cff                   +cmp al, 0xff
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
    // 004ae812  7410                   -je 0x4ae824
    if (cpu.flags.zf)
    {
        goto L_0x004ae824;
    }
    // 004ae814  80fcff                 +cmp ah, 0xff
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
    // 004ae817  7406                   -je 0x4ae81f
    if (cpu.flags.zf)
    {
        goto L_0x004ae81f;
    }
    // 004ae819  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004ae81d  eb0d                   -jmp 0x4ae82c
    goto L_0x004ae82c;
L_0x004ae81f:
    // 004ae81f  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ae822  eb08                   -jmp 0x4ae82c
    goto L_0x004ae82c;
L_0x004ae824:
    // 004ae824  80fcff                 +cmp ah, 0xff
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
    // 004ae827  7403                   -je 0x4ae82c
    if (cpu.flags.zf)
    {
        goto L_0x004ae82c;
    }
    // 004ae829  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004ae82c:
    // 004ae82c  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004ae831  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae834  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae837  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae83d  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae842  0f850fffffff           -jne 0x4ae757
    if (!cpu.flags.zf)
    {
        goto L_0x004ae757;
    }
L_0x004ae848:
    // 004ae848  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae84e  7827                   -js 0x4ae877
    if (cpu.flags.sf)
    {
        goto L_0x004ae877;
    }
    // 004ae850  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae851  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae853  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae855  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae85b  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae861  3cff                   +cmp al, 0xff
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
    // 004ae863  7403                   -je 0x4ae868
    if (cpu.flags.zf)
    {
        goto L_0x004ae868;
    }
    // 004ae865  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae868:
    // 004ae868  01ca                   +add edx, ecx
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
    // 004ae86a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae86c  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae86e  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae875  ebd1                   -jmp 0x4ae848
    goto L_0x004ae848;
L_0x004ae877:
    // 004ae877  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae878  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae879  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae87a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ae87c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae87c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae87d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae87e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae87f  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae885  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ae887  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae889  83f90c                 +cmp ecx, 0xc
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
    // 004ae88c  734b                   -jae 0x4ae8d9
    if (!cpu.flags.cf)
    {
        goto L_0x004ae8d9;
    }
L_0x004ae88e:
    // 004ae88e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae890  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ae892  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae895  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae89b  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004ae89e  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae89f  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae8a6  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae8ab  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae8ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae8af  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004ae8b2  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae8b8  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ae8ba  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae8c0  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae8c2  7509                   -jne 0x4ae8cd
    if (!cpu.flags.zf)
    {
        goto L_0x004ae8cd;
    }
    // 004ae8c4  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ae8c7  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae8cd:
    // 004ae8cd  7703                   -ja 0x4ae8d2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae8d2;
    }
    // 004ae8cf  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae8d2:
    // 004ae8d2  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae8d3  75b9                   -jne 0x4ae88e
    if (!cpu.flags.zf)
    {
        goto L_0x004ae88e;
    }
    // 004ae8d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae8d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae8d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae8d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae8d9:
    // 004ae8d9  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae8df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae8e1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae8e3  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004ae8e9  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004ae8ec  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae8ef  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004ae8f4  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae8f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ae8f8  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004ae8fb  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ae8fe  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004ae903  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004ae909  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae90e  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae914  c1f810                 +sar eax, 0x10
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
    // 004ae917  7809                   -js 0x4ae922
    if (cpu.flags.sf)
    {
        goto L_0x004ae922;
    }
    // 004ae919  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae920  eb0b                   -jmp 0x4ae92d
    goto L_0x004ae92d;
L_0x004ae922:
    // 004ae922  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004ae924  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004ae92b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ae92d:
    // 004ae92d  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae930  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae932  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004ae937  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004ae93d  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004ae942  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae944  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ae946  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ae949  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004ae94f  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ae952  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004ae959  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae95b  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004ae95e  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004ae964  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ae967  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004ae96d  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004ae970  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004ae973:
    // 004ae973  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae979  7832                   -js 0x4ae9ad
    if (cpu.flags.sf)
    {
        goto L_0x004ae9ad;
    }
    // 004ae97b  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae97c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae97e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae980  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004ae986  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae98c  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ae98e  7509                   -jne 0x4ae999
    if (!cpu.flags.zf)
    {
        goto L_0x004ae999;
    }
    // 004ae990  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ae993  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004ae999:
    // 004ae999  7703                   -ja 0x4ae99e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ae99e;
    }
    // 004ae99b  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004ae99e:
    // 004ae99e  01ca                   +add edx, ecx
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
    // 004ae9a0  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ae9a2  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae9a4  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae9ab  ebc6                   -jmp 0x4ae973
    goto L_0x004ae973;
L_0x004ae9ad:
    // 004ae9ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae9af  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae9b1  01ca                   +add edx, ecx
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
    // 004ae9b3  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae9b5  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae9b7  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae9bd  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae9c4  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004ae9c9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae9cb  01ca                   +add edx, ecx
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
    // 004ae9cd  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae9cf  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae9d1  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae9d7  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae9de  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004ae9e3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae9e5  01ca                   +add edx, ecx
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
    // 004ae9e7  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004ae9e9  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae9eb  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004ae9f1  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004ae9f8  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004ae9fd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004ae9ff  01ca                   +add edx, ecx
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
    // 004aea01  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aea03  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aea05  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004aea0b  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aea12  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004aea17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aea18  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004aea1d  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004aea23  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aea25  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aea27  7508                   -jne 0x4aea31
    if (!cpu.flags.zf)
    {
        goto L_0x004aea31;
    }
    // 004aea29  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004aea2b  8a82ac054e00           -mov al, byte ptr [edx + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aea31:
    // 004aea31  7760                   -ja 0x4aea93
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aea93;
    }
    // 004aea33  80fcfe                 +cmp ah, 0xfe
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
    // 004aea36  7509                   -jne 0x4aea41
    if (!cpu.flags.zf)
    {
        goto L_0x004aea41;
    }
    // 004aea38  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aea3b  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aea41:
    // 004aea41  774b                   -ja 0x4aea8e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aea8e;
    }
    // 004aea43  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004aea46  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aea48  7509                   -jne 0x4aea53
    if (!cpu.flags.zf)
    {
        goto L_0x004aea53;
    }
    // 004aea4a  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004aea4d  8a82ac054e00           -mov al, byte ptr [edx + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aea53:
    // 004aea53  771d                   -ja 0x4aea72
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aea72;
    }
    // 004aea55  80fcfe                 +cmp ah, 0xfe
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
    // 004aea58  7509                   -jne 0x4aea63
    if (!cpu.flags.zf)
    {
        goto L_0x004aea63;
    }
    // 004aea5a  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aea5d  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aea63:
    // 004aea63  7707                   -ja 0x4aea6c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aea6c;
    }
    // 004aea65  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004aea68  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004aea6a  eb7b                   -jmp 0x4aeae7
    goto L_0x004aeae7;
L_0x004aea6c:
    // 004aea6c  90                     -nop 
    ;
    // 004aea6d  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004aea70  eb14                   -jmp 0x4aea86
    goto L_0x004aea86;
L_0x004aea72:
    // 004aea72  80fcfe                 +cmp ah, 0xfe
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
    // 004aea75  7509                   -jne 0x4aea80
    if (!cpu.flags.zf)
    {
        goto L_0x004aea80;
    }
    // 004aea77  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aea7a  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aea80:
    // 004aea80  7704                   -ja 0x4aea86
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aea86;
    }
    // 004aea82  90                     -nop 
    ;
    // 004aea83  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004aea86:
    // 004aea86  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004aea89  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004aea8c  eb59                   -jmp 0x4aeae7
    goto L_0x004aeae7;
L_0x004aea8e:
    // 004aea8e  90                     -nop 
    ;
    // 004aea8f  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004aea91  eb14                   -jmp 0x4aeaa7
    goto L_0x004aeaa7;
L_0x004aea93:
    // 004aea93  80fcfe                 +cmp ah, 0xfe
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
    // 004aea96  7509                   -jne 0x4aeaa1
    if (!cpu.flags.zf)
    {
        goto L_0x004aeaa1;
    }
    // 004aea98  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aea9b  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aeaa1:
    // 004aeaa1  7704                   -ja 0x4aeaa7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aeaa7;
    }
    // 004aeaa3  90                     -nop 
    ;
    // 004aeaa4  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004aeaa7:
    // 004aeaa7  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004aeaaa  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aeaac  7509                   -jne 0x4aeab7
    if (!cpu.flags.zf)
    {
        goto L_0x004aeab7;
    }
    // 004aeaae  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004aeab1  8a82ac054e00           -mov al, byte ptr [edx + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aeab7:
    // 004aeab7  771b                   -ja 0x4aead4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aead4;
    }
    // 004aeab9  80fcfe                 +cmp ah, 0xfe
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
    // 004aeabc  7509                   -jne 0x4aeac7
    if (!cpu.flags.zf)
    {
        goto L_0x004aeac7;
    }
    // 004aeabe  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aeac1  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aeac7:
    // 004aeac7  7706                   -ja 0x4aeacf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aeacf;
    }
    // 004aeac9  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004aeacd  eb18                   -jmp 0x4aeae7
    goto L_0x004aeae7;
L_0x004aeacf:
    // 004aeacf  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004aead2  eb13                   -jmp 0x4aeae7
    goto L_0x004aeae7;
L_0x004aead4:
    // 004aead4  80fcfe                 +cmp ah, 0xfe
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
    // 004aead7  7509                   -jne 0x4aeae2
    if (!cpu.flags.zf)
    {
        goto L_0x004aeae2;
    }
    // 004aead9  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aeadc  8aa2ac054e00           -mov ah, byte ptr [edx + 0x4e05ac]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aeae2:
    // 004aeae2  7703                   -ja 0x4aeae7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aeae7;
    }
    // 004aeae4  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004aeae7:
    // 004aeae7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeae8  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004aeaed  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aeaf0  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aeaf3  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004aeaf9  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004aeafe  0f85a9feffff           -jne 0x4ae9ad
    if (!cpu.flags.zf)
    {
        goto L_0x004ae9ad;
    }
L_0x004aeb04:
    // 004aeb04  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aeb0a  7832                   -js 0x4aeb3e
    if (cpu.flags.sf)
    {
        goto L_0x004aeb3e;
    }
    // 004aeb0c  43                     -inc ebx
    (cpu.ebx)++;
    // 004aeb0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb0f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aeb11  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004aeb17  8a80e8d54d00           -mov al, byte ptr [eax + 0x4dd5e8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101032) /* 0x4dd5e8 */);
    // 004aeb1d  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aeb1f  7509                   -jne 0x4aeb2a
    if (!cpu.flags.zf)
    {
        goto L_0x004aeb2a;
    }
    // 004aeb21  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aeb24  8a80ac054e00           -mov al, byte ptr [eax + 0x4e05ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5113260) /* 0x4e05ac */);
L_0x004aeb2a:
    // 004aeb2a  7703                   -ja 0x4aeb2f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aeb2f;
    }
    // 004aeb2c  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aeb2f:
    // 004aeb2f  01ca                   +add edx, ecx
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
    // 004aeb31  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aeb33  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aeb35  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aeb3c  ebc6                   -jmp 0x4aeb04
    goto L_0x004aeb04;
L_0x004aeb3e:
    // 004aeb3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4aeb44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aeb44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aeb45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aeb46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aeb47  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004aeb4d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aeb4f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aeb51  83f90c                 +cmp ecx, 0xc
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
    // 004aeb54  7345                   -jae 0x4aeb9b
    if (!cpu.flags.cf)
    {
        goto L_0x004aeb9b;
    }
L_0x004aeb56:
    // 004aeb56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aeb58  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aeb5a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aeb5d  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004aeb63  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aeb66  43                     -inc ebx
    (cpu.ebx)++;
    // 004aeb67  033c85282c4e00         -add edi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004aeb6e  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004aeb73  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb75  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb77  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004aeb7a  8b3d34eb4d00           -mov edi, dword ptr [0x4deb34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aeb80  8b3c87                 -mov edi, dword ptr [edi + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004aeb83  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aeb86  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 004aeb89  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004aeb8f  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aeb92  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aeb94  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aeb95  75bf                   -jne 0x4aeb56
    if (!cpu.flags.zf)
    {
        goto L_0x004aeb56;
    }
    // 004aeb97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aeb9b:
    // 004aeb9b  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004aeba1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aeba3  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aeba5  8b35242c4e00           -mov esi, dword ptr [0x4e2c24]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123108) /* 0x4e2c24 */);
    // 004aebab  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004aebae  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aebb1  a3f42b4e00             -mov dword ptr [0x4e2bf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */) = cpu.eax;
    // 004aebb6  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aebb8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aebba  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004aebbd  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aebc0  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004aebc5  890dfc2b4e00           -mov dword ptr [0x4e2bfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */) = cpu.ecx;
    // 004aebcb  a1182c4e00             -mov eax, dword ptr [0x4e2c18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004aebd0  8b0d102c4e00           -mov ecx, dword ptr [0x4e2c10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004aebd6  c1f810                 +sar eax, 0x10
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
    // 004aebd9  7809                   -js 0x4aebe4
    if (cpu.flags.sf)
    {
        goto L_0x004aebe4;
    }
    // 004aebdb  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004aebe2  eb0b                   -jmp 0x4aebef
    goto L_0x004aebef;
L_0x004aebe4:
    // 004aebe4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004aebe6  8b8486282c4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e2c28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4);
    // 004aebed  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004aebef:
    // 004aebef  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aebf2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aebf4  a3042c4e00             -mov dword ptr [0x4e2c04], eax
    app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */) = cpu.eax;
    // 004aebf9  03862c2c4e00           -add eax, dword ptr [esi + 0x4e2c2c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5123116) /* 0x4e2c2c */)));
    // 004aebff  a3002c4e00             -mov dword ptr [0x4e2c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5123072) /* 0x4e2c00 */) = cpu.eax;
    // 004aec04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aec06  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004aec08  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aec0b  8b35202c4e00           -mov esi, dword ptr [0x4e2c20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5123104) /* 0x4e2c20 */);
    // 004aec11  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aec14  033485282c4e00         -add esi, dword ptr [eax*4 + 0x4e2c28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123112) /* 0x4e2c28 */ + cpu.eax * 4)));
    // 004aec1b  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aec1d  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004aec20  8b3d102c4e00           -mov edi, dword ptr [0x4e2c10]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5123088) /* 0x4e2c10 */);
    // 004aec26  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aec29  8b0d182c4e00           -mov ecx, dword ptr [0x4e2c18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5123096) /* 0x4e2c18 */);
    // 004aec2f  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004aec32  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004aec35:
    // 004aec35  ff0df42b4e00           +dec dword ptr [0x4e2bf4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123060) /* 0x4e2bf4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aec3b  782e                   -js 0x4aec6b
    if (cpu.flags.sf)
    {
        goto L_0x004aec6b;
    }
    // 004aec3d  43                     -inc ebx
    (cpu.ebx)++;
    // 004aec3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aec40  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aec42  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004aec48  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aec49  8b3534eb4d00           -mov esi, dword ptr [0x4deb34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aec4f  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aec52  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aec55  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aec58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aec59  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aec5c  01ca                   +add edx, ecx
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
    // 004aec5e  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aec60  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aec62  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aec69  ebca                   -jmp 0x4aec35
    goto L_0x004aec35;
L_0x004aec6b:
    // 004aec6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aec6d  01ca                   +add edx, ecx
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
    // 004aec6f  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aec71  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aec73  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aec75  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aec7c  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004aec81  01ca                   +add edx, ecx
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
    // 004aec83  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aec85  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aec87  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aec89  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aec90  a2092c4e00             -mov byte ptr [0x4e2c09], al
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.al;
    // 004aec95  01ca                   +add edx, ecx
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
    // 004aec97  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aec99  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aec9b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aec9d  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aeca4  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004aeca9  01ca                   +add edx, ecx
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
    // 004aecab  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aecad  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aecaf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aecb1  13349d042c4e00         -adc esi, dword ptr [ebx*4 + 0x4e2c04]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aecb8  a20b2c4e00             -mov byte ptr [0x4e2c0b], al
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.al;
    // 004aecbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aecbe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aecbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aecc0  8b1df02b4e00           -mov ebx, dword ptr [0x4e2bf0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */);
    // 004aecc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aecc8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aecca  a0082c4e00             -mov al, byte ptr [0x4e2c08]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004aeccf  8b3534eb4d00           -mov esi, dword ptr [0x4deb34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aecd5  8a15092c4e00           -mov dl, byte ptr [0x4e2c09]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */);
    // 004aecdb  8b3d34eb4d00           -mov edi, dword ptr [0x4deb34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aece1  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aece4  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004aece6  8b3c97                 -mov edi, dword ptr [edi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.edx * 4);
    // 004aece9  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aecec  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aecef  8a1417                 -mov dl, byte ptr [edi + edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + cpu.edx * 1);
    // 004aecf2  a2082c4e00             -mov byte ptr [0x4e2c08], al
    app->getMemory<x86::reg8>(x86::reg32(5123080) /* 0x4e2c08 */) = cpu.al;
    // 004aecf7  8815092c4e00           -mov byte ptr [0x4e2c09], dl
    app->getMemory<x86::reg8>(x86::reg32(5123081) /* 0x4e2c09 */) = cpu.dl;
    // 004aecfd  a00a2c4e00             -mov al, byte ptr [0x4e2c0a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */);
    // 004aed02  8b3534eb4d00           -mov esi, dword ptr [0x4deb34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aed08  8a150b2c4e00           -mov dl, byte ptr [0x4e2c0b]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */);
    // 004aed0e  8b3d34eb4d00           -mov edi, dword ptr [0x4deb34]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aed14  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aed17  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004aed1a  8b3c97                 -mov edi, dword ptr [edi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.edx * 4);
    // 004aed1d  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aed20  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aed23  8a1417                 -mov dl, byte ptr [edi + edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + cpu.edx * 1);
    // 004aed26  a20a2c4e00             -mov byte ptr [0x4e2c0a], al
    app->getMemory<x86::reg8>(x86::reg32(5123082) /* 0x4e2c0a */) = cpu.al;
    // 004aed2b  88150b2c4e00           -mov byte ptr [0x4e2c0b], dl
    app->getMemory<x86::reg8>(x86::reg32(5123083) /* 0x4e2c0b */) = cpu.dl;
    // 004aed31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed34  a1f82b4e00             -mov eax, dword ptr [0x4e2bf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */);
    // 004aed39  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aed3c  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aed3f  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004aed45  a3f82b4e00             -mov dword ptr [0x4e2bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5123064) /* 0x4e2bf8 */) = cpu.eax;
    // 004aed4a  a1082c4e00             -mov eax, dword ptr [0x4e2c08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5123080) /* 0x4e2c08 */);
    // 004aed4f  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004aed52  0f8513ffffff           -jne 0x4aec6b
    if (!cpu.flags.zf)
    {
        goto L_0x004aec6b;
    }
L_0x004aed58:
    // 004aed58  ff0dfc2b4e00           +dec dword ptr [0x4e2bfc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5123068) /* 0x4e2bfc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aed5e  782e                   -js 0x4aed8e
    if (cpu.flags.sf)
    {
        goto L_0x004aed8e;
    }
    // 004aed60  43                     -inc ebx
    (cpu.ebx)++;
    // 004aed61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aed63  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aed65  891df02b4e00           -mov dword ptr [0x4e2bf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5123056) /* 0x4e2bf0 */) = cpu.ebx;
    // 004aed6b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aed6c  8b3534eb4d00           -mov esi, dword ptr [0x4deb34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5106484) /* 0x4deb34 */);
    // 004aed72  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aed75  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aed78  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aed7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed7c  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aed7f  01ca                   +add edx, ecx
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
    // 004aed81  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aed83  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aed85  133485042c4e00         +adc esi, dword ptr [eax*4 + 0x4e2c04]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5123076) /* 0x4e2c04 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aed8c  ebca                   -jmp 0x4aed58
    goto L_0x004aed58;
L_0x004aed8e:
    // 004aed8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aed91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aeda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aeda0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aeda1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aeda4  833d68f04d0000         +cmp dword ptr [0x4df068], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107816) /* 0x4df068 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aedab  7538                   -jne 0x4aede5
    if (!cpu.flags.zf)
    {
        goto L_0x004aede5;
    }
    // 004aedad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aedae  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 004aedb3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004aedb8  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004aedbd  890d50685b00           -mov dword ptr [0x5b6850], ecx
    app->getMemory<x86::reg32>(x86::reg32(5990480) /* 0x5b6850 */) = cpu.ecx;
    // 004aedc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aedc4:
    // 004aedc4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aedc7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004aedca  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004aedcc  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004aedce  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aedd1  40                     -inc eax
    (cpu.eax)++;
    // 004aedd2  d99a4c685b00           -fstp dword ptr [edx + 0x5b684c]
    app->getMemory<float>(cpu.edx + x86::reg32(5990476) /* 0x5b684c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aedd8  3d00040000             +cmp eax, 0x400
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
    // 004aeddd  7ce5                   -jl 0x4aedc4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aedc4;
    }
    // 004aeddf  ff0568f04d00           -inc dword ptr [0x4df068]
    (app->getMemory<x86::reg32>(x86::reg32(5107816) /* 0x4df068 */))++;
L_0x004aede5:
    // 004aede5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aede8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aede9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aedf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aedf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aedf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aedf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aedf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aedf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aedf5  8b3520845b00           -mov esi, dword ptr [0x5b8420]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5997600) /* 0x5b8420 */);
    // 004aedfb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aedfd  e89ea8ffff             -call 0x4a96a0
    cpu.esp -= 4;
    sub_4a96a0(app, cpu);
    if (cpu.terminate) return;
    // 004aee02  8b1d24845b00           -mov ebx, dword ptr [0x5b8424]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5997604) /* 0x5b8424 */);
    // 004aee08  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aee0a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aee0c  39d8                   +cmp eax, ebx
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
    // 004aee0e  7554                   -jne 0x4aee64
    if (!cpu.flags.zf)
    {
        goto L_0x004aee64;
    }
    // 004aee10  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aee13  8b3520845b00           -mov esi, dword ptr [0x5b8420]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5997600) /* 0x5b8420 */);
    // 004aee19  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004aee1c  39f2                   +cmp edx, esi
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
    // 004aee1e  7e38                   -jle 0x4aee58
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aee58;
    }
    // 004aee20  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004aee23  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aee25  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004aee27:
    // 004aee27  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004aee2e  81c250785b00           -add edx, 0x5b7850
    (cpu.edx) += x86::reg32(x86::sreg32(5994576 /*0x5b7850*/));
    // 004aee34  39f3                   +cmp ebx, esi
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
    // 004aee36  7d20                   -jge 0x4aee58
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aee58;
    }
L_0x004aee38:
    // 004aee38  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aee3b  8942f0                 -mov dword ptr [edx - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004aee3e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aee40  8942f4                 -mov dword ptr [edx - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004aee43  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aee45  8942f8                 -mov dword ptr [edx - 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004aee48  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aee4a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aee4d  8942fc                 -mov dword ptr [edx - 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004aee50  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aee52  39f3                   +cmp ebx, esi
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
    // 004aee54  7ce2                   -jl 0x4aee38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aee38;
    }
    // 004aee56  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004aee58:
    // 004aee58  893520845b00           -mov dword ptr [0x5b8420], esi
    app->getMemory<x86::reg32>(x86::reg32(5997600) /* 0x5b8420 */) = cpu.esi;
    // 004aee5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aee64:
    // 004aee64  893d24845b00           -mov dword ptr [0x5b8424], edi
    app->getMemory<x86::reg32>(x86::reg32(5997604) /* 0x5b8424 */) = cpu.edi;
    // 004aee6a  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aee6d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aee6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aee71  c1fe10                 +sar esi, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004aee74  ebb1                   -jmp 0x4aee27
    goto L_0x004aee27;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aee80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aee80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aee81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aee82  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aee85  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aee87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aee89  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004aee8b  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004aee8e  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aee94  0f8444010000           -je 0x4aefde
    if (cpu.flags.zf)
    {
        goto L_0x004aefde;
    }
    // 004aee9a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aee9b  81f9ff000000           +cmp ecx, 0xff
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
    // 004aeea1  0f84f1000000           -je 0x4aef98
    if (cpu.flags.zf)
    {
        goto L_0x004aef98;
    }
    // 004aeea7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aeea8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aeea9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004aeeab  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004aeeae  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aeeb3  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aeeb5  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 004aeeba  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004aeebe  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aeec0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aeec2  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004aeec4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aeec6  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004aeec9  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004aeecc  8b3485600e5700         -mov esi, dword ptr [eax*4 + 0x570e60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.eax * 4);
    // 004aeed3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aeed9  8b3c85600e5700         -mov edi, dword ptr [eax*4 + 0x570e60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.eax * 4);
    // 004aeee0  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004aeee4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aeee6  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004aeee9  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004aeeec  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aeef2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aeef8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aeefa  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004aeefe  8b1c85600e5700         -mov ebx, dword ptr [eax*4 + 0x570e60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705312) /* 0x570e60 */ + cpu.eax * 4);
    // 004aef05  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aef07  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aef0d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aef0f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aef12  c1e810                 +shr eax, 0x10
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
    // 004aef15  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aef17  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aef1b  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004aef1e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aef20  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aef26  3dff000000             +cmp eax, 0xff
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
    // 004aef2b  0f86b3000000           -jbe 0x4aefe4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aefe4;
    }
    // 004aef31  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004aef36:
    // 004aef36  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aef38  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aef3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aef3c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aef3e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aef41  c1e810                 +shr eax, 0x10
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
    // 004aef44  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aef46  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004aef4a  3dff000000             +cmp eax, 0xff
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
    // 004aef4f  0f86a8000000           -jbe 0x4aeffd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aeffd;
    }
    // 004aef55  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004aef5a:
    // 004aef5a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004aef5e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aef60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aef62  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aef64  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aef67  c1e810                 +shr eax, 0x10
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
    // 004aef6a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aef6c  03442410               -add eax, dword ptr [esp + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004aef70  3dff000000             +cmp eax, 0xff
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
    // 004aef75  0f869b000000           -jbe 0x4af016
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004af016;
    }
    // 004aef7b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004aef80:
    // 004aef80  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aef82  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aef86  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004aef89  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004aef8c  81cb000000ff           -or ebx, 0xff000000
    cpu.ebx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004aef92  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aef94  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aef96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aef98:
    // 004aef98  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aef9a  8b0d60ac4d00           -mov ecx, dword ptr [0x4dac60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090400) /* 0x4dac60 */);
    // 004aefa0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004aefa2  7427                   -je 0x4aefcb
    if (cpu.flags.zf)
    {
        goto L_0x004aefcb;
    }
    // 004aefa4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aefa6  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004aefac  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004aefaf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aefb1  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aefb4  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004aefba  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004aefbd  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004aefc0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aefc2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aefc4  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004aefc6  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 004aefc9  eb0f                   -jmp 0x4aefda
    goto L_0x004aefda;
L_0x004aefcb:
    // 004aefcb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aefcd  8d05600e5700           -lea eax, [0x570e60]
    cpu.eax = x86::reg32(x86::reg32(5705312) /* 0x570e60 */);
    // 004aefd3  e8f835fdff             -call 0x4825d0
    cpu.esp -= 4;
    sub_4825d0(app, cpu);
    if (cpu.terminate) return;
    // 004aefd8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004aefda:
    // 004aefda  885d00                 -mov byte ptr [ebp], bl
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.bl;
    // 004aefdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aefde:
    // 004aefde  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aefe1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aefe2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aefe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aefe4:
    // 004aefe4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aefe6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aefe8  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aefec  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aefee  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aeff1  c1e810                 +shr eax, 0x10
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
    // 004aeff4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aeff6  01f0                   +add eax, esi
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
    // 004aeff8  e939ffffff             -jmp 0x4aef36
    goto L_0x004aef36;
L_0x004aeffd:
    // 004aeffd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aefff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af001  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af005  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004af007  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af00a  c1e810                 +shr eax, 0x10
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
    // 004af00d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004af00f  01d8                   +add eax, ebx
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
    // 004af011  e944ffffff             -jmp 0x4aef5a
    goto L_0x004aef5a;
L_0x004af016:
    // 004af016  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004af018  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004af01a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af01e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004af020  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af023  c1e810                 +shr eax, 0x10
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
    // 004af026  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004af028  01c8                   +add eax, ecx
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
    // 004af02a  e951ffffff             -jmp 0x4aef80
    goto L_0x004aef80;
}

/* align: skip 0x90 */
void Application::sub_4af030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af030  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af031  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af032  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af033  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af036  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004af039  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004af03b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004af03d  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004af041  837c243c00             +cmp dword ptr [esp + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af046  7f09                   -jg 0x4af051
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004af051;
    }
    // 004af048  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af04b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af04c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af04d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af04e  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af051:
    // 004af051  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af055  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004af059  0fb6355cb24d00         -movzx esi, byte ptr [0x4db25c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */));
    // 004af060  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004af066  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004af069  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004af06f  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004af072  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004af078  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004af07c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004af07f  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004af082  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af085  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004af088  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004af08c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004af08f  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004af092  83fe10                 +cmp esi, 0x10
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
    // 004af095  0f85e9000000           -jne 0x4af184
    if (!cpu.flags.zf)
    {
        goto L_0x004af184;
    }
    // 004af09b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004af09f:
    // 004af09f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af0a3  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af0a7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004af0a9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004af0ab  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004af0ae  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af0b1  8b1cb550785b00         -mov ebx, dword ptr [esi*4 + 0x5b7850]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.esi * 4);
    // 004af0b8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004af0bb  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004af0be  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004af0c0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af0c2  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af0c4  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af0c7  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af0cd  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af0d0  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af0d3  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af0d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af0d7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af0d9  ff149544074e00         -call dword ptr [edx*4 + 0x4e0744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113668) /* 0x4e0744 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af0e0  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af0e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af0e6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af0ec  726b                   -jb 0x4af159
    if (cpu.flags.cf)
    {
        goto L_0x004af159;
    }
    // 004af0ee  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af0f4  7340                   -jae 0x4af136
    if (!cpu.flags.cf)
    {
        goto L_0x004af136;
    }
    // 004af0f6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004af0f9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004af0fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af0fd  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004af100  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004af103  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004af105  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004af10b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004af10e  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004af113  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004af116  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af118  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004af11a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af11d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af11f  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004af122  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af124  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004af127  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af12d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004af132  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af134  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004af136:
    // 004af136  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af138  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004af13e  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004af141  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af143  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004af146  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004af14c  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004af14f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004af152  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af154  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af156  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004af159:
    // 004af159  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004af15c  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af160  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af164  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004af168  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af16c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af16e  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004af170  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af171  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004af175  0f8524ffffff           -jne 0x4af09f
    if (!cpu.flags.zf)
    {
        goto L_0x004af09f;
    }
    // 004af17b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af17e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af17f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af180  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af181  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af184:
    // 004af184  83fe0f                 +cmp esi, 0xf
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
    // 004af187  0f85f1000000           -jne 0x4af27e
    if (!cpu.flags.zf)
    {
        goto L_0x004af27e;
    }
    // 004af18d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004af191:
    // 004af191  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af195  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af199  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004af19b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004af19d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004af1a0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af1a3  8b1cb550785b00         -mov ebx, dword ptr [esi*4 + 0x5b7850]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.esi * 4);
    // 004af1aa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004af1ad  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004af1b0  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004af1b2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af1b4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af1b6  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af1b9  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af1bf  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af1c2  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af1c5  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af1c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af1c9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af1cb  ff149544074e00         -call dword ptr [edx*4 + 0x4e0744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113668) /* 0x4e0744 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af1d2  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af1d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af1d8  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af1de  7273                   -jb 0x4af253
    if (cpu.flags.cf)
    {
        goto L_0x004af253;
    }
    // 004af1e0  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af1e6  7348                   -jae 0x4af230
    if (!cpu.flags.cf)
    {
        goto L_0x004af230;
    }
    // 004af1e8  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004af1eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af1ed  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004af1f2  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004af1f5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004af1f7  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004af1fd  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004af200  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af202  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004af205  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af207  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004af209  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004af20c  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af212  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004af214  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af217  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af219  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af21b  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004af21e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af224  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af226  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004af229  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004af22e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004af230:
    // 004af230  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af232  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004af238  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004af23b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af23d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004af240  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004af246  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004af249  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004af24c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af24e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af250  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004af253:
    // 004af253  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004af256  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af25a  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af25e  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004af262  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af266  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af268  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004af26a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af26b  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004af26f  0f851cffffff           -jne 0x4af191
    if (!cpu.flags.zf)
    {
        goto L_0x004af191;
    }
    // 004af275  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af278  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af279  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af27a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af27b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af27e:
    // 004af27e  83fe08                 +cmp esi, 8
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
    // 004af281  7579                   -jne 0x4af2fc
    if (!cpu.flags.zf)
    {
        goto L_0x004af2fc;
    }
    // 004af283  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004af287:
    // 004af287  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af28b  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004af28d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004af28f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004af291  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af294  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004af297  8b0c8550785b00         -mov ecx, dword ptr [eax*4 + 0x5b7850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.eax * 4);
    // 004af29e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004af2a1  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 004af2a4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af2a8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af2aa  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af2ac  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af2af  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af2b5  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af2b8  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af2bb  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af2bd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af2bf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af2c1  ff149544074e00         -call dword ptr [edx*4 + 0x4e0744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113668) /* 0x4e0744 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af2c8  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af2cc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af2ce  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af2d2  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af2d6  e8a5fbffff             -call 0x4aee80
    cpu.esp -= 4;
    sub_4aee80(app, cpu);
    if (cpu.terminate) return;
    // 004af2db  43                     -inc ebx
    (cpu.ebx)++;
    // 004af2dc  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af2de  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af2e2  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af2e6  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004af2ea  01c7                   +add edi, eax
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
    // 004af2ec  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af2ed  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004af2f1  7594                   -jne 0x4af287
    if (!cpu.flags.zf)
    {
        goto L_0x004af287;
    }
    // 004af2f3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af2f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2f9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af2fc:
    // 004af2fc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004af300:
    // 004af300  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af304  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004af306  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004af308  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004af30a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af30d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004af310  8b0c8550785b00         -mov ecx, dword ptr [eax*4 + 0x5b7850]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.eax * 4);
    // 004af317  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004af31e  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af320  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af324  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af326  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af328  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af32b  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af331  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af334  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af337  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af339  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af33b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af33d  ff149544074e00         -call dword ptr [edx*4 + 0x4e0744]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113668) /* 0x4e0744 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af344  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af348  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af34c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af34e  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004af352  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af356  e8854b0000             -call 0x4b3ee0
    cpu.esp -= 4;
    sub_4b3ee0(app, cpu);
    if (cpu.terminate) return;
    // 004af35b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004af35e  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004af362  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af366  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af36a  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004af36e  43                     -inc ebx
    (cpu.ebx)++;
    // 004af36f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af371  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004af373  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004af377  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af378  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004af37c  7582                   -jne 0x4af300
    if (!cpu.flags.zf)
    {
        goto L_0x004af300;
    }
    // 004af37e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af381  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af382  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af383  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af384  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4af388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af388  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af389  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af38a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af38b  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af38e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004af392  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004af394  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004af398  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004af39c  837c243c00             +cmp dword ptr [esp + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af3a1  7f09                   -jg 0x4af3ac
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004af3ac;
    }
    // 004af3a3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af3a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af3a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af3a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af3a9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af3ac:
    // 004af3ac  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af3b0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004af3b2  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004af3b6  8a0d5cb24d00           -mov cl, byte ptr [0x4db25c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004af3bc  8b1570b24d00           -mov edx, dword ptr [0x4db270]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004af3c2  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004af3c5  8b156cb24d00           -mov edx, dword ptr [0x4db26c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004af3cb  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004af3ce  030560b24d00           -add eax, dword ptr [0x4db260]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */)));
    // 004af3d4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004af3d8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af3dc  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004af3df  83f908                 +cmp ecx, 8
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
    // 004af3e2  0f8598000000           -jne 0x4af480
    if (!cpu.flags.zf)
    {
        goto L_0x004af480;
    }
    // 004af3e8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004af3eb:
    // 004af3eb  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af3ef  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af3f3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af3f6  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004af3f9  8b3c8550785b00         -mov edi, dword ptr [eax*4 + 0x5b7850]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.eax * 4);
    // 004af400  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af404  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004af407  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af409  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004af40b  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004af40e  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004af411  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004af414  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af416  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af419  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af41f  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af422  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af425  8b3d6cf04d00           -mov edi, dword ptr [0x4df06c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
    // 004af42b  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af42d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af42f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af431  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af436  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004af439  ff149544084e00         -call dword ptr [edx*4 + 0x4e0844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113924) /* 0x4e0844 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af440  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af444  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004af447  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af44b  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004af44f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af451  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af453  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af457  e824faffff             -call 0x4aee80
    cpu.esp -= 4;
    sub_4aee80(app, cpu);
    if (cpu.terminate) return;
    // 004af45c  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af460  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af464  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af466  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004af468  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004af46c  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af46d  8974243c               -mov dword ptr [esp + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 004af471  0f8574ffffff           -jne 0x4af3eb
    if (!cpu.flags.zf)
    {
        goto L_0x004af3eb;
    }
    // 004af477  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af47a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af47b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af47c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af47d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af480:
    // 004af480  83f910                 +cmp ecx, 0x10
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
    // 004af483  0f8505010000           -jne 0x4af58e
    if (!cpu.flags.zf)
    {
        goto L_0x004af58e;
    }
    // 004af489  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004af48d:
    // 004af48d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af491  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af495  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af499  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af49d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af49f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af4a2  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004af4a5  8b3c8550785b00         -mov edi, dword ptr [eax*4 + 0x5b7850]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.eax * 4);
    // 004af4ac  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004af4ae  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004af4b0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af4b3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004af4b6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af4b8  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af4bb  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af4c1  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af4c4  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af4c7  8b3d6cf04d00           -mov edi, dword ptr [0x4df06c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
    // 004af4cd  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af4cf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af4d1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af4d3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af4d8  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004af4db  ff149544084e00         -call dword ptr [edx*4 + 0x4e0844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113924) /* 0x4e0844 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af4e2  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af4e6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af4e8  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af4ee  726b                   -jb 0x4af55b
    if (cpu.flags.cf)
    {
        goto L_0x004af55b;
    }
    // 004af4f0  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af4f6  7340                   -jae 0x4af538
    if (!cpu.flags.cf)
    {
        goto L_0x004af538;
    }
    // 004af4f8  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004af4fb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004af4fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af4ff  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004af502  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004af505  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004af507  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004af50d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004af510  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004af515  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004af518  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af51a  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004af51c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af51f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af521  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004af524  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af526  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004af529  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af52f  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004af534  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af536  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004af538:
    // 004af538  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af53a  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004af540  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004af543  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af545  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004af548  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004af54e  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004af551  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004af554  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af556  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af558  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004af55b:
    // 004af55b  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004af55e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af562  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af566  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af568  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af56c  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af570  01c2                   +add edx, eax
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
    // 004af572  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004af576  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004af57a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af57b  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004af57f  0f8508ffffff           -jne 0x4af48d
    if (!cpu.flags.zf)
    {
        goto L_0x004af48d;
    }
    // 004af585  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af588  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af589  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af58a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af58b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af58e:
    // 004af58e  83f90f                 +cmp ecx, 0xf
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
    // 004af591  0f850d010000           -jne 0x4af6a4
    if (!cpu.flags.zf)
    {
        goto L_0x004af6a4;
    }
    // 004af597  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004af59b:
    // 004af59b  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af59f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af5a3  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af5a7  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af5ab  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af5ad  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af5b0  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004af5b3  8b3c8550785b00         -mov edi, dword ptr [eax*4 + 0x5b7850]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.eax * 4);
    // 004af5ba  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004af5bc  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004af5be  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af5c1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004af5c4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af5c6  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af5c9  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af5cf  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af5d2  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af5d5  8b3d6cf04d00           -mov edi, dword ptr [0x4df06c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
    // 004af5db  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af5dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af5df  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af5e1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af5e6  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004af5e9  ff149544084e00         -call dword ptr [edx*4 + 0x4e0844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113924) /* 0x4e0844 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af5f0  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af5f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af5f6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af5fc  7273                   -jb 0x4af671
    if (cpu.flags.cf)
    {
        goto L_0x004af671;
    }
    // 004af5fe  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af604  7348                   -jae 0x4af64e
    if (!cpu.flags.cf)
    {
        goto L_0x004af64e;
    }
    // 004af606  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004af609  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af60b  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004af610  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004af613  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004af615  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004af61b  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004af61e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af620  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004af623  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af625  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004af627  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004af62a  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af630  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004af632  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af635  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af637  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af639  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004af63c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af642  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af644  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004af647  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004af64c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004af64e:
    // 004af64e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af650  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004af656  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004af659  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af65b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004af65e  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004af664  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004af667  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004af66a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af66c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af66e  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004af671:
    // 004af671  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004af674  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af678  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af67c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af67e  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af682  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af686  01c2                   +add edx, eax
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
    // 004af688  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004af68c  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004af690  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af691  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004af695  0f8500ffffff           -jne 0x4af59b
    if (!cpu.flags.zf)
    {
        goto L_0x004af59b;
    }
    // 004af69b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af69e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af69f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af6a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af6a1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004af6a4:
    // 004af6a4  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004af6a8:
    // 004af6a8  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af6ac  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004af6b0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af6b3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af6b7  8b1c8550785b00         -mov ebx, dword ptr [eax*4 + 0x5b7850]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5994576) /* 0x5b7850 */ + cpu.eax * 4);
    // 004af6be  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af6c0  8d041e                 -lea eax, [esi + ebx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004af6c3  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004af6c6  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004af6c8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004af6cb  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004af6ce  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af6d2  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004af6d4  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004af6d7  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004af6dd  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004af6e0  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004af6e3  8b3d6cf04d00           -mov edi, dword ptr [0x4df06c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5107820) /* 0x4df06c */);
    // 004af6e9  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af6eb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af6ed  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af6ef  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af6f4  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004af6f7  ff149544084e00         -call dword ptr [edx*4 + 0x4e0844]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5113924) /* 0x4e0844 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af6fe  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af702  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004af706  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af70a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af70c  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004af710  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004af714  e8c7470000             -call 0x4b3ee0
    cpu.esp -= 4;
    sub_4b3ee0(app, cpu);
    if (cpu.terminate) return;
    // 004af719  46                     -inc esi
    (cpu.esi)++;
    // 004af71a  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004af71e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af722  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004af724  01c2                   +add edx, eax
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
    // 004af726  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 004af72a  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004af72e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004af72f  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004af733  0f856fffffff           -jne 0x4af6a8
    if (!cpu.flags.zf)
    {
        goto L_0x004af6a8;
    }
    // 004af739  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004af73c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af73d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af73e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af73f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4af744(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af744  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af745  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af746  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af747  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004af74a  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004af74e  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004af752  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004af754  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004af758  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004af75a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af75c  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004af75f  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 004af765  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004af769  83f820                 +cmp eax, 0x20
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
    // 004af76c  0f85af010000           -jne 0x4af921
    if (!cpu.flags.zf)
    {
        goto L_0x004af921;
    }
L_0x004af772:
    // 004af772  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af776  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004af779  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af77c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004af780  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af784  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004af788  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004af78b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af78e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004af791  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af795  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004af798  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af79a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004af79d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004af79f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af7a1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af7a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af7a5  0f8c91010000           -jl 0x4af93c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004af93c;
    }
L_0x004af7ab:
    // 004af7ab  837c242402             +cmp dword ptr [esp + 0x24], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af7b0  7d08                   -jge 0x4af7ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004af7ba;
    }
    // 004af7b2  c744242402000000       -mov dword ptr [esp + 0x24], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 2 /*0x2*/;
L_0x004af7ba:
    // 004af7ba  837c243802             +cmp dword ptr [esp + 0x38], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af7bf  7d08                   -jge 0x4af7c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004af7c9;
    }
    // 004af7c1  c744243802000000       -mov dword ptr [esp + 0x38], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 2 /*0x2*/;
L_0x004af7c9:
    // 004af7c9  81fb8f020000           +cmp ebx, 0x28f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655 /*0x28f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af7cf  0f8e3b010000           -jle 0x4af910
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af910;
    }
    // 004af7d5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af7d9  e812f6ffff             -call 0x4aedf0
    cpu.esp -= 4;
    sub_4aedf0(app, cpu);
    if (cpu.terminate) return;
    // 004af7de  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004af7e3  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004af7e8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004af7ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af7ec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004af7ef  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af7f1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004af7f3  8db00080ffff           -lea esi, [eax - 0x8000]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-32768) /* -0x8000 */);
    // 004af7f9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004af7fb  0f8c42010000           -jl 0x4af943
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004af943;
    }
L_0x004af801:
    // 004af801  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af805  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004af808  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004af80a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004af80c  48                     -dec eax
    (cpu.eax)--;
    // 004af80d  4a                     -dec edx
    (cpu.edx)--;
    // 004af80e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004af811  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004af814  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004af816  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004af818  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004af81c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004af81e  0f8c26010000           -jl 0x4af94a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004af94a;
    }
L_0x004af824:
    // 004af824  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004af828  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004af82a  4e                     -dec esi
    (cpu.esi)--;
    // 004af82b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af82d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004af830  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004af832  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af836  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af83a  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004af83e  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af840  4e                     -dec esi
    (cpu.esi)--;
    // 004af841  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af843  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004af846  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004af848  8b154cb24d00           -mov edx, dword ptr [0x4db24c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004af84e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004af850  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af854  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004af858  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af85a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004af85e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af860  7e1e                   -jle 0x4af880
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af880;
    }
    // 004af862  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af866  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004af869  8d2c13                 -lea ebp, [ebx + edx]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004af86c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af86e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004af872  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 004af876  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af878  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004af87c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004af880:
    // 004af880  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004af884  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004af888  8b0d54b24d00           -mov ecx, dword ptr [0x4db254]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004af88e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af890  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004af892  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af894  7e08                   -jle 0x4af89e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af89e;
    }
    // 004af896  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004af898  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004af89a  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x004af89e:
    // 004af89e  8b1550b24d00           -mov edx, dword ptr [0x4db250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004af8a4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004af8a6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af8a8  7e15                   -jle 0x4af8bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af8bf;
    }
    // 004af8aa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af8ae  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004af8b1  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af8b5  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af8b7  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af8b9  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 004af8bd  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004af8bf:
    // 004af8bf  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af8c3  8b1558b24d00           -mov edx, dword ptr [0x4db258]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004af8c9  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004af8cb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af8cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af8cf  7e04                   -jle 0x4af8d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af8d5;
    }
    // 004af8d1  29442438               -sub dword ptr [esp + 0x38], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004af8d5:
    // 004af8d5  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af8d9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004af8db  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004af8dd  7e31                   -jle 0x4af910
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af910;
    }
L_0x004af8df:
    // 004af8df  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004af8e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004af8e4  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af8e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af8e9  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af8ed  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004af8ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af8f0  45                     -inc ebp
    (cpu.ebp)++;
    // 004af8f1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004af8f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004af8f7  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004af8fb  47                     -inc edi
    (cpu.edi)++;
    // 004af8fc  e82ff7ffff             -call 0x4af030
    cpu.esp -= 4;
    sub_4af030(app, cpu);
    if (cpu.terminate) return;
    // 004af901  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af905  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004af909  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af90b  39dd                   +cmp ebp, ebx
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
    // 004af90d  7cd0                   -jl 0x4af8df
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004af8df;
    }
    // 004af90f  90                     -nop 
    ;
L_0x004af910:
    // 004af910  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af914  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004af916  7541                   -jne 0x4af959
    if (!cpu.flags.zf)
    {
        goto L_0x004af959;
    }
    // 004af918  83c428                 +add esp, 0x28
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
    // 004af91b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af91c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af91d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af91e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004af921:
    // 004af921  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004af926  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af92a  e84dabfeff             -call 0x49a47c
    cpu.esp -= 4;
    sub_49a47c(app, cpu);
    if (cpu.terminate) return;
    // 004af92f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004af933  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004af937  e936feffff             -jmp 0x4af772
    goto L_0x004af772;
L_0x004af93c:
    // 004af93c  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004af93e  e968feffff             -jmp 0x4af7ab
    goto L_0x004af7ab;
L_0x004af943:
    // 004af943  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004af945  e9b7feffff             -jmp 0x4af801
    goto L_0x004af801;
L_0x004af94a:
    // 004af94a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004af94c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af94e  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004af952  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004af954  e9cbfeffff             -jmp 0x4af824
    goto L_0x004af824;
L_0x004af959:
    // 004af959  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004af95b  e89c4ffdff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004af960  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004af963  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af964  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af965  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af966  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4af970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af972  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af973  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004af976  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004af978  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004af97c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004af97e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004af980  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004af982  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004af984  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004af986  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af98a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af98c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004af98e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004af98f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004af991  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af993  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af995  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004af999  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004af99c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004af99e  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004af9a1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af9a3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af9a7  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004af9aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af9ac  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004af9af  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004af9b2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af9b4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004af9b7  e884b10000             -call 0x4bab40
    cpu.esp -= 4;
    sub_4bab40(app, cpu);
    if (cpu.terminate) return;
    // 004af9bc  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af9c0  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004af9c3  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af9c7  3b07                   +cmp eax, dword ptr [edi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af9c9  750a                   -jne 0x4af9d5
    if (!cpu.flags.zf)
    {
        goto L_0x004af9d5;
    }
    // 004af9cb  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004af9ce  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004af9d1  39d0                   +cmp eax, edx
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
    // 004af9d3  744a                   -je 0x4afa1f
    if (cpu.flags.zf)
    {
        goto L_0x004afa1f;
    }
L_0x004af9d5:
    // 004af9d5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004af9d9  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004af9dd  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004af9df  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004af9e1  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004af9e4  39d8                   +cmp eax, ebx
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
    // 004af9e6  743b                   -je 0x4afa23
    if (cpu.flags.zf)
    {
        goto L_0x004afa23;
    }
    // 004af9e8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004af9ea  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004af9ec  e84fb10000             -call 0x4bab40
    cpu.esp -= 4;
    sub_4bab40(app, cpu);
    if (cpu.terminate) return;
    // 004af9f1  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004af9f5:
    // 004af9f5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004af9f7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004af9fa  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004af9fd  39f8                   +cmp eax, edi
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
    // 004af9ff  742a                   -je 0x4afa2b
    if (cpu.flags.zf)
    {
        goto L_0x004afa2b;
    }
    // 004afa01  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004afa03  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004afa05  e836b10000             -call 0x4bab40
    cpu.esp -= 4;
    sub_4bab40(app, cpu);
    if (cpu.terminate) return;
    // 004afa0a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afa0e  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afa11  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004afa16:
    // 004afa16  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afa19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa1c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004afa1f:
    // 004afa1f  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004afa21  ebf3                   -jmp 0x4afa16
    goto L_0x004afa16;
L_0x004afa23:
    // 004afa23  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afa27  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004afa29  ebca                   -jmp 0x4af9f5
    goto L_0x004af9f5;
L_0x004afa2b:
    // 004afa2b  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afa2f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004afa32  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afa35  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004afa3a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afa3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa40  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4afa44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afa44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afa45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004afa46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afa47  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afa4a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004afa4c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004afa50  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afa52  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004afa54  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004afa57  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004afa5a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004afa5d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004afa61  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004afa63  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004afa65  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004afa66  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004afa68  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004afa6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afa6c  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004afa70  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004afa73  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004afa75  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004afa78  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004afa7a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004afa7e  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004afa80  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004afa82  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004afa85  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004afa87  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004afa89  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004afa8c  e8afb00000             -call 0x4bab40
    cpu.esp -= 4;
    sub_4bab40(app, cpu);
    if (cpu.terminate) return;
    // 004afa91  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afa95  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004afa97  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004afa9b  3b4704                 +cmp eax, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afa9e  7508                   -jne 0x4afaa8
    if (!cpu.flags.zf)
    {
        goto L_0x004afaa8;
    }
    // 004afaa0  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004afaa2  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004afaa4  39d0                   +cmp eax, edx
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
    // 004afaa6  744b                   -je 0x4afaf3
    if (cpu.flags.zf)
    {
        goto L_0x004afaf3;
    }
L_0x004afaa8:
    // 004afaa8  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afaac  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004afab0  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afab3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004afab5  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004afab8  39d8                   +cmp eax, ebx
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
    // 004afaba  743b                   -je 0x4afaf7
    if (cpu.flags.zf)
    {
        goto L_0x004afaf7;
    }
    // 004afabc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004afabe  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004afac0  e87bb00000             -call 0x4bab40
    cpu.esp -= 4;
    sub_4bab40(app, cpu);
    if (cpu.terminate) return;
    // 004afac5  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004afac9:
    // 004afac9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004afacb  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aface  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004afad1  39f8                   +cmp eax, edi
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
    // 004afad3  742a                   -je 0x4afaff
    if (cpu.flags.zf)
    {
        goto L_0x004afaff;
    }
    // 004afad5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004afad7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004afad9  e862b00000             -call 0x4bab40
    cpu.esp -= 4;
    sub_4bab40(app, cpu);
    if (cpu.terminate) return;
    // 004afade  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afae2  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afae5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004afaea:
    // 004afaea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afaed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afaee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afaef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afaf0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004afaf3:
    // 004afaf3  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004afaf5  ebf3                   -jmp 0x4afaea
    goto L_0x004afaea;
L_0x004afaf7:
    // 004afaf7  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afafb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004afafd  ebca                   -jmp 0x4afac9
    goto L_0x004afac9;
L_0x004afaff:
    // 004afaff  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afb03  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004afb06  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afb09  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004afb0e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afb11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb14  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4afb18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afb18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afb19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afb1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004afb1b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afb1c  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004afb1f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004afb23  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afb25  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004afb27  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004afb29  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004afb2d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afb31  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afb34  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004afb38  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afb3a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004afb3d  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afb40  c70230885b00           -mov dword ptr [edx], 0x5b8830
    app->getMemory<x86::reg32>(cpu.edx) = 5998640 /*0x5b8830*/;
    // 004afb46  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004afb4a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004afb4c  c70130905b00           -mov dword ptr [ecx], 0x5b9030
    app->getMemory<x86::reg32>(cpu.ecx) = 6000688 /*0x5b9030*/;
    // 004afb52  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afb54  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004afb58:
    // 004afb58  8b354cb24d00           -mov esi, dword ptr [0x4db24c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004afb5e  3b30                   +cmp esi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb60  0f8e70000000           -jle 0x4afbd6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afbd6;
    }
    // 004afb66  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afb6a  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb6c  7e33                   -jle 0x4afba1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afba1;
    }
L_0x004afb6e:
    // 004afb6e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004afb72  4e                     -dec esi
    (cpu.esi)--;
    // 004afb73  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004afb77  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afb79  0f8ef5000000           -jle 0x4afc74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afc74;
    }
    // 004afb7f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afb83  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004afb87  83fe01                 +cmp esi, 1
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
    // 004afb8a  0f85d1000000           -jne 0x4afc61
    if (!cpu.flags.zf)
    {
        goto L_0x004afc61;
    }
    // 004afb90  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004afb94  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004afb98  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004afb9b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004afb9f  ebb7                   -jmp 0x4afb58
    goto L_0x004afb58;
L_0x004afba1:
    // 004afba1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afba2  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afba6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afba7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afba9  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afbad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afbae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004afbb0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afbb4  e8b7fdffff             -call 0x4af970
    cpu.esp -= 4;
    sub_4af970(app, cpu);
    if (cpu.terminate) return;
    // 004afbb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afbbb  74b1                   -je 0x4afb6e
    if (cpu.flags.zf)
    {
        goto L_0x004afb6e;
    }
    // 004afbbd  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afbc1  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afbc5  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afbc8  41                     -inc ecx
    (cpu.ecx)++;
    // 004afbc9  83c308                 +add ebx, 8
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
    // 004afbcc  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004afbd0  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004afbd4  eb98                   -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afbd6:
    // 004afbd6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afbda  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afbdc  7f2a                   -jg 0x4afc08
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004afc08;
    }
    // 004afbde  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afbe2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afbe4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afbe6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afbea  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afbed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afbee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afbef  42                     -inc edx
    (cpu.edx)++;
    // 004afbf0  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afbf4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afbf6  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004afbf9  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004afbfd  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004afc01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc03  e966ffffff             -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afc08:
    // 004afc08  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afc0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afc0c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc0d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc0e  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc12  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afc14  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc15  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc16  8b0d4cb24d00           -mov ecx, dword ptr [0x4db24c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004afc1c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afc21  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afc24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afc25  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afc28  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc2c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afc2d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc31  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004afc35  e836fdffff             -call 0x4af970
    cpu.esp -= 4;
    sub_4af970(app, cpu);
    if (cpu.terminate) return;
    // 004afc3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afc3c  741a                   -je 0x4afc58
    if (cpu.flags.zf)
    {
        goto L_0x004afc58;
    }
    // 004afc3e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afc42  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afc45  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004afc48  83c202                 +add edx, 2
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
    // 004afc4b  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004afc4f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004afc53  e916ffffff             -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afc58:
    // 004afc58  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004afc5c  e90dffffff             -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afc61:
    // 004afc61  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afc64  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afc67  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004afc6b  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004afc6f  e9e4feffff             -jmp 0x4afb58
    goto L_0x004afb58;
L_0x004afc74:
    // 004afc74  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afc78  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004afc7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afc74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004afc74;
    // 004afb18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afb19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afb1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004afb1b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afb1c  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004afb1f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004afb23  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afb25  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004afb27  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004afb29  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004afb2d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afb31  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afb34  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004afb38  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afb3a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004afb3d  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afb40  c70230885b00           -mov dword ptr [edx], 0x5b8830
    app->getMemory<x86::reg32>(cpu.edx) = 5998640 /*0x5b8830*/;
    // 004afb46  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004afb4a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004afb4c  c70130905b00           -mov dword ptr [ecx], 0x5b9030
    app->getMemory<x86::reg32>(cpu.ecx) = 6000688 /*0x5b9030*/;
    // 004afb52  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afb54  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004afb58:
    // 004afb58  8b354cb24d00           -mov esi, dword ptr [0x4db24c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004afb5e  3b30                   +cmp esi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb60  0f8e70000000           -jle 0x4afbd6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afbd6;
    }
    // 004afb66  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afb6a  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb6c  7e33                   -jle 0x4afba1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afba1;
    }
L_0x004afb6e:
    // 004afb6e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004afb72  4e                     -dec esi
    (cpu.esi)--;
    // 004afb73  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004afb77  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afb79  0f8ef5000000           -jle 0x4afc74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afc74;
    }
    // 004afb7f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afb83  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004afb87  83fe01                 +cmp esi, 1
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
    // 004afb8a  0f85d1000000           -jne 0x4afc61
    if (!cpu.flags.zf)
    {
        goto L_0x004afc61;
    }
    // 004afb90  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004afb94  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004afb98  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004afb9b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004afb9f  ebb7                   -jmp 0x4afb58
    goto L_0x004afb58;
L_0x004afba1:
    // 004afba1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afba2  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afba6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afba7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afba9  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afbad  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afbae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004afbb0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afbb4  e8b7fdffff             -call 0x4af970
    cpu.esp -= 4;
    sub_4af970(app, cpu);
    if (cpu.terminate) return;
    // 004afbb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afbbb  74b1                   -je 0x4afb6e
    if (cpu.flags.zf)
    {
        goto L_0x004afb6e;
    }
    // 004afbbd  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afbc1  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afbc5  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afbc8  41                     -inc ecx
    (cpu.ecx)++;
    // 004afbc9  83c308                 +add ebx, 8
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
    // 004afbcc  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004afbd0  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004afbd4  eb98                   -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afbd6:
    // 004afbd6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afbda  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afbdc  7f2a                   -jg 0x4afc08
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004afc08;
    }
    // 004afbde  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afbe2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afbe4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afbe6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afbea  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afbed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afbee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afbef  42                     -inc edx
    (cpu.edx)++;
    // 004afbf0  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afbf4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afbf6  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004afbf9  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004afbfd  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004afc01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc03  e966ffffff             -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afc08:
    // 004afc08  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afc0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afc0c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc0d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc0e  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc12  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afc14  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc15  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afc16  8b0d4cb24d00           -mov ecx, dword ptr [0x4db24c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004afc1c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afc21  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afc24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afc25  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afc28  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc2c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afc2d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afc31  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004afc35  e836fdffff             -call 0x4af970
    cpu.esp -= 4;
    sub_4af970(app, cpu);
    if (cpu.terminate) return;
    // 004afc3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afc3c  741a                   -je 0x4afc58
    if (cpu.flags.zf)
    {
        goto L_0x004afc58;
    }
    // 004afc3e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afc42  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afc45  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004afc48  83c202                 +add edx, 2
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
    // 004afc4b  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004afc4f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004afc53  e916ffffff             -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afc58:
    // 004afc58  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004afc5c  e90dffffff             -jmp 0x4afb6e
    goto L_0x004afb6e;
L_0x004afc61:
    // 004afc61  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afc64  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afc67  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004afc6b  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004afc6f  e9e4feffff             -jmp 0x4afb58
    goto L_0x004afb58;
L_0x004afc74:
L_entry_0x004afc74:
    // 004afc74  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afc78  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004afc7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afc7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afc80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afc81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afc82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004afc83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afc84  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004afc87  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004afc8b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afc8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004afc8f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004afc91  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004afc95  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afc99  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afc9c  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004afca0  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afca2  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004afca5  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afca8  c702308a5b00           -mov dword ptr [edx], 0x5b8a30
    app->getMemory<x86::reg32>(cpu.edx) = 5999152 /*0x5b8a30*/;
    // 004afcae  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004afcb2  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004afcb4  c701308c5b00           -mov dword ptr [ecx], 0x5b8c30
    app->getMemory<x86::reg32>(cpu.ecx) = 5999664 /*0x5b8c30*/;
    // 004afcba  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afcbc  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004afcc0:
    // 004afcc0  8b3554b24d00           -mov esi, dword ptr [0x4db254]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004afcc6  3b30                   +cmp esi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afcc8  0f8f6c000000           -jg 0x4afd3a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004afd3a;
    }
    // 004afcce  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afcd2  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afcd4  7f2f                   -jg 0x4afd05
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004afd05;
    }
L_0x004afcd6:
    // 004afcd6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004afcda  4e                     -dec esi
    (cpu.esi)--;
    // 004afcdb  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004afcdf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afce1  7e91                   -jle 0x4afc74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4afc74(app, cpu);
    }
    // 004afce3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afce7  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004afceb  83fe01                 +cmp esi, 1
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
    // 004afcee  0f85d1000000           -jne 0x4afdc5
    if (!cpu.flags.zf)
    {
        goto L_0x004afdc5;
    }
    // 004afcf4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004afcf8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004afcfc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004afcff  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004afd03  ebbb                   -jmp 0x4afcc0
    goto L_0x004afcc0;
L_0x004afd05:
    // 004afd05  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afd06  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afd0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afd0b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afd0d  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afd11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afd12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004afd14  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afd18  e853fcffff             -call 0x4af970
    cpu.esp -= 4;
    sub_4af970(app, cpu);
    if (cpu.terminate) return;
    // 004afd1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afd1f  74b5                   -je 0x4afcd6
    if (cpu.flags.zf)
    {
        goto L_0x004afcd6;
    }
    // 004afd21  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afd25  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd29  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afd2c  41                     -inc ecx
    (cpu.ecx)++;
    // 004afd2d  83c308                 +add ebx, 8
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
    // 004afd30  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004afd34  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004afd38  eb9c                   -jmp 0x4afcd6
    goto L_0x004afcd6;
L_0x004afd3a:
    // 004afd3a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afd3e  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afd40  7e2a                   -jle 0x4afd6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afd6c;
    }
    // 004afd42  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afd46  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afd48  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afd4a  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd4e  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afd51  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd52  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd53  42                     -inc edx
    (cpu.edx)++;
    // 004afd54  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd58  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afd5a  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004afd5d  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004afd61  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004afd65  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd66  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd67  e96affffff             -jmp 0x4afcd6
    goto L_0x004afcd6;
L_0x004afd6c:
    // 004afd6c  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afd6e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afd70  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd71  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd72  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd76  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afd78  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd79  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afd7a  8b0d54b24d00           -mov ecx, dword ptr [0x4db254]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004afd80  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afd85  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afd88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afd89  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afd8c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afd91  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afd95  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004afd99  e8d2fbffff             -call 0x4af970
    cpu.esp -= 4;
    sub_4af970(app, cpu);
    if (cpu.terminate) return;
    // 004afd9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afda0  741a                   -je 0x4afdbc
    if (cpu.flags.zf)
    {
        goto L_0x004afdbc;
    }
    // 004afda2  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afda6  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afda9  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004afdac  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004afdaf  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004afdb3  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004afdb7  e91affffff             -jmp 0x4afcd6
    goto L_0x004afcd6;
L_0x004afdbc:
    // 004afdbc  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004afdc0  e911ffffff             -jmp 0x4afcd6
    goto L_0x004afcd6;
L_0x004afdc5:
    // 004afdc5  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afdc8  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afdcb  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004afdcf  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004afdd3  e9e8feffff             -jmp 0x4afcc0
    goto L_0x004afcc0;
}

/* align: skip  */
void Application::sub_4afdd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afdd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afdd9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afdda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004afddb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afddc  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004afddf  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004afde3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afde5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004afde7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004afde9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004afded  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004afdf1  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004afdf4  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004afdf8  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afdfa  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004afdfd  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004afe00  c702308e5b00           -mov dword ptr [edx], 0x5b8e30
    app->getMemory<x86::reg32>(cpu.edx) = 6000176 /*0x5b8e30*/;
    // 004afe06  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004afe0a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004afe0c  c70130845b00           -mov dword ptr [ecx], 0x5b8430
    app->getMemory<x86::reg32>(cpu.ecx) = 5997616 /*0x5b8430*/;
    // 004afe12  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004afe14  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004afe18:
    // 004afe18  8b3550b24d00           -mov esi, dword ptr [0x4db250]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004afe1e  3b7004                 +cmp esi, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afe21  0f8e71000000           -jle 0x4afe98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afe98;
    }
    // 004afe27  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afe2b  3b7204                 +cmp esi, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afe2e  7e33                   -jle 0x4afe63
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afe63;
    }
L_0x004afe30:
    // 004afe30  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004afe34  4e                     -dec esi
    (cpu.esi)--;
    // 004afe35  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004afe39  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afe3b  0f8e33feffff           -jle 0x4afc74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4afc74(app, cpu);
    }
    // 004afe41  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afe45  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004afe49  83fe01                 +cmp esi, 1
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
    // 004afe4c  0f85d2000000           -jne 0x4aff24
    if (!cpu.flags.zf)
    {
        goto L_0x004aff24;
    }
    // 004afe52  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004afe56  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004afe5a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004afe5d  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004afe61  ebb5                   -jmp 0x4afe18
    goto L_0x004afe18;
L_0x004afe63:
    // 004afe63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afe64  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afe68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afe69  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004afe6b  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afe6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afe70  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004afe72  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004afe76  e8c9fbffff             -call 0x4afa44
    cpu.esp -= 4;
    sub_4afa44(app, cpu);
    if (cpu.terminate) return;
    // 004afe7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afe7d  74b1                   -je 0x4afe30
    if (cpu.flags.zf)
    {
        goto L_0x004afe30;
    }
    // 004afe7f  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afe83  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afe87  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afe8a  83c108                 +add ecx, 8
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
    // 004afe8d  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004afe8e  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004afe92  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004afe96  eb98                   -jmp 0x4afe30
    goto L_0x004afe30;
L_0x004afe98:
    // 004afe98  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afe9c  3b7204                 +cmp esi, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afe9f  7f2a                   -jg 0x4afecb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004afecb;
    }
    // 004afea1  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afea5  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afea7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afea9  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afead  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afeb0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afeb1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afeb2  42                     -inc edx
    (cpu.edx)++;
    // 004afeb3  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afeb7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afeb9  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004afebc  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004afec0  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004afec4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afec5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afec6  e965ffffff             -jmp 0x4afe30
    goto L_0x004afe30;
L_0x004afecb:
    // 004afecb  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004afecd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afecf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afed0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afed1  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afed5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004afed7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afed8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afed9  8b0d50b24d00           -mov ecx, dword ptr [0x4db250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004afedf  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afee3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afee4  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afee7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afee8  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afeeb  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afeef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afef0  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004afef4  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004afef8  e847fbffff             -call 0x4afa44
    cpu.esp -= 4;
    sub_4afa44(app, cpu);
    if (cpu.terminate) return;
    // 004afefd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afeff  741a                   -je 0x4aff1b
    if (cpu.flags.zf)
    {
        goto L_0x004aff1b;
    }
    // 004aff01  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aff05  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aff08  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004aff0b  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aff0e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004aff12  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004aff16  e915ffffff             -jmp 0x4afe30
    goto L_0x004afe30;
L_0x004aff1b:
    // 004aff1b  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aff1f  e90cffffff             -jmp 0x4afe30
    goto L_0x004afe30;
L_0x004aff24:
    // 004aff24  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aff27  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aff2a  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004aff2e  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004aff32  e9e1feffff             -jmp 0x4afe18
    goto L_0x004afe18;
}

/* align: skip 0x90 */
void Application::sub_4aff38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aff38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aff39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aff3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aff3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aff3c  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004aff3f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004aff43  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004aff45  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aff47  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aff49  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004aff4d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aff51  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aff54  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004aff58  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004aff5a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004aff5d  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aff60  c70230925b00           -mov dword ptr [edx], 0x5b9230
    app->getMemory<x86::reg32>(cpu.edx) = 6001200 /*0x5b9230*/;
    // 004aff66  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004aff6a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004aff6c  c70130865b00           -mov dword ptr [ecx], 0x5b8630
    app->getMemory<x86::reg32>(cpu.ecx) = 5998128 /*0x5b8630*/;
    // 004aff72  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004aff74  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004aff78:
    // 004aff78  8b3558b24d00           -mov esi, dword ptr [0x4db258]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004aff7e  3b7004                 +cmp esi, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aff81  0f8f71000000           -jg 0x4afff8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004afff8;
    }
    // 004aff87  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aff8b  3b7204                 +cmp esi, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aff8e  7f33                   -jg 0x4affc3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004affc3;
    }
L_0x004aff90:
    // 004aff90  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aff94  4e                     -dec esi
    (cpu.esi)--;
    // 004aff95  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004aff99  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aff9b  0f8ed3fcffff           -jle 0x4afc74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4afc74(app, cpu);
    }
    // 004affa1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004affa5  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004affa9  83fe01                 +cmp esi, 1
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
    // 004affac  0f85d2000000           -jne 0x4b0084
    if (!cpu.flags.zf)
    {
        goto L_0x004b0084;
    }
    // 004affb2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004affb6  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004affba  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004affbd  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004affc1  ebb5                   -jmp 0x4aff78
    goto L_0x004aff78;
L_0x004affc3:
    // 004affc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004affc4  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004affc8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004affc9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004affcb  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004affcf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004affd0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004affd2  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004affd6  e869faffff             -call 0x4afa44
    cpu.esp -= 4;
    sub_4afa44(app, cpu);
    if (cpu.terminate) return;
    // 004affdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004affdd  74b1                   -je 0x4aff90
    if (cpu.flags.zf)
    {
        goto L_0x004aff90;
    }
    // 004affdf  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004affe3  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004affe7  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004affea  83c108                 +add ecx, 8
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
    // 004affed  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004affee  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004afff2  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004afff6  eb98                   -jmp 0x4aff90
    goto L_0x004aff90;
L_0x004afff8:
    // 004afff8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afffc  3b7204                 +cmp esi, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004affff  7e2a                   -jle 0x4b002b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b002b;
    }
    // 004b0001  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b0005  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b0007  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0009  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b000d  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0010  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0011  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0012  42                     -inc edx
    (cpu.edx)++;
    // 004b0013  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0017  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b0019  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b001c  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b0020  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b0024  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0025  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0026  e965ffffff             -jmp 0x4aff90
    goto L_0x004aff90;
L_0x004b002b:
    // 004b002b  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b002d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b002f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0030  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0031  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0035  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b0037  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0038  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b0039  8b0d58b24d00           -mov ecx, dword ptr [0x4db258]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004b003f  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0043  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0044  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0047  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0048  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b004b  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b004f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0050  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b0054  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004b0058  e8e7f9ffff             -call 0x4afa44
    cpu.esp -= 4;
    sub_4afa44(app, cpu);
    if (cpu.terminate) return;
    // 004b005d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b005f  741a                   -je 0x4b007b
    if (cpu.flags.zf)
    {
        goto L_0x004b007b;
    }
    // 004b0061  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b0065  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b0068  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b006b  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b006e  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b0072  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004b0076  e915ffffff             -jmp 0x4aff90
    goto L_0x004aff90;
L_0x004b007b:
    // 004b007b  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b007f  e90cffffff             -jmp 0x4aff90
    goto L_0x004aff90;
L_0x004b0084:
    // 004b0084  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0087  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b008a  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004b008e  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004b0092  e9e1feffff             -jmp 0x4aff78
    goto L_0x004aff78;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b00a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b00a0  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b00a3  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004b00a6  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004b00a9  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004b00ab  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b00ad  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b00b0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b00b2  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004b00b5  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b00b8  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b00ba  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004b00bd  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b00c0  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004b00c2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b00c4  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b00c6  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b00c8  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b00ca  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b00cd  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b00cf  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b00d2  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b00d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b00d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b00d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b00d9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b00dc  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b00de  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b00e0  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b00e3  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004b00e6  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004b00e9  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004b00eb  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b00ed  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b00f0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b00f2  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004b00f5  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b00f8  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b00fa  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004b00fd  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b0100  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004b0102  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b0104  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0106  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0108  deeb                   -fsubp st(3)
    cpu.fpu.st(3) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b010a  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b010d  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b010f  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0112  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0115  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b0117  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b0119  e806000000             -call 0x4b0124
    cpu.esp -= 4;
    sub_4b0124(app, cpu);
    if (cpu.terminate) return;
    // 004b011e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0121  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0122  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0124(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0124  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0125  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0128  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b012a  e835c1feff             -call 0x49c264
    cpu.esp -= 4;
    sub_49c264(app, cpu);
    if (cpu.terminate) return;
    // 004b012f  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b0131  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b0133  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004b0135  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b0137  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0139  d94104                 -fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b013c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b013e  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0141  d84908                 -fmul dword ptr [ecx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */));
    // 004b0144  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0147  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b014a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b014b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b014c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b014c  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b014e  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004b0150  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b0153  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b0156  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004b0159  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004b015c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b015e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0160  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0162  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0164  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0165  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0166  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0168  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b016a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b016c  7e26                   -jle 0x4b0194
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b0194;
    }
L_0x004b016e:
    // 004b016e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b0170  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0172  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0175  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b0177  d80a                   -fmul dword ptr [edx]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx));
    // 004b0179  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b017c  d84a04                 -fmul dword ptr [edx + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b017f  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004b0182  d84a08                 -fmul dword ptr [edx + 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004b0185  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b0187  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0189  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b018b  d959fc                 -fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b018e  83c60c                 +add esi, 0xc
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
    // 004b0191  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b0192  75da                   -jne 0x4b016e
    if (!cpu.flags.zf)
    {
        goto L_0x004b016e;
    }
L_0x004b0194:
    // 004b0194  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0195  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0196  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b0198(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0198  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b0199  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b019c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b019e  e881ffffff             -call 0x4b0124
    cpu.esp -= 4;
    sub_4b0124(app, cpu);
    if (cpu.terminate) return;
    // 004b01a3  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b01a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b01a8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b01ad  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b01b1  ff742418               -push dword ptr [esp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b01b5  e816aa0000             -call 0x4babd0
    cpu.esp -= 4;
    sub_4babd0(app, cpu);
    if (cpu.terminate) return;
    // 004b01ba  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b01bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b01be  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b01c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b01c2  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 004b01c4  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b01c6  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004b01c8  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004b01ca  dee1                   +fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b01cc  d9e4                   +ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 004b01ce  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004b01d0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004b01d1  750f                   -jne 0x4b01e2
    if (!cpu.flags.zf)
    {
        goto L_0x004b01e2;
    }
    // 004b01d3  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004b01d5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004b01d7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004b01d8  7704                   -ja 0x4b01de
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b01de;
    }
    // 004b01da  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004b01dc  eb02                   -jmp 0x4b01e0
    goto L_0x004b01e0;
L_0x004b01de:
    // 004b01de  d9eb                   +fldpi 
    cpu.fpu.push(3.1415926535897932);
L_0x004b01e0:
    // 004b01e0  eb1a                   -jmp 0x4b01fc
    goto L_0x004b01fc;
L_0x004b01e2:
    // 004b01e2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004b01e4  e877aa0000             -call 0x4bac60
    cpu.esp -= 4;
    sub_4bac60(app, cpu);
    if (cpu.terminate) return;
    // 004b01e9  3c00                   +cmp al, 0
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
    // 004b01eb  750f                   -jne 0x4b01fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b01fc;
    }
    // 004b01ed  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b01ef  e847fffeff             -call 0x4a013b
    cpu.esp -= 4;
    sub_4a013b(app, cpu);
    if (cpu.terminate) return;
    // 004b01f4  db2d70f04d00           -fld xword ptr [0x4df070]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5107824) /* 0x4df070 */)));
    // 004b01fa  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
L_0x004b01fc:
    // 004b01fc  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b01fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b01ff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b01ff  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004b0203  e8baffffff             -call 0x4b01c2
    cpu.esp -= 4;
    sub_4b01c2(app, cpu);
    if (cpu.terminate) return;
    // 004b0208  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4b020b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b020b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b020c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b020d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b020e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b0210  e89e9affff             -call 0x4a9cb3
    cpu.esp -= 4;
    sub_4a9cb3(app, cpu);
    if (cpu.terminate) return;
    // 004b0215  837a1400               +cmp dword ptr [edx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0219  7526                   -jne 0x4b0241
    if (!cpu.flags.zf)
    {
        goto L_0x004b0241;
    }
    // 004b021b  8a620d                 -mov ah, byte ptr [edx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004b021e  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b0221  7409                   -je 0x4b022c
    if (cpu.flags.zf)
    {
        goto L_0x004b022c;
    }
    // 004b0223  c7421486000000         -mov dword ptr [edx + 0x14], 0x86
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 134 /*0x86*/;
    // 004b022a  eb15                   -jmp 0x4b0241
    goto L_0x004b0241;
L_0x004b022c:
    // 004b022c  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b022f  7409                   -je 0x4b023a
    if (cpu.flags.zf)
    {
        goto L_0x004b023a;
    }
    // 004b0231  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004b0238  eb07                   -jmp 0x4b0241
    goto L_0x004b0241;
L_0x004b023a:
    // 004b023a  c7421400100000         -mov dword ptr [edx + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x004b0241:
    // 004b0241  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004b0244  e87a63ffff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004b0249  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b024c  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b024f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b0252  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004b0256  7523                   -jne 0x4b027b
    if (!cpu.flags.zf)
    {
        goto L_0x004b027b;
    }
    // 004b0258  8a4a0d                 -mov cl, byte ptr [edx + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004b025b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b025e  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 004b0261  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004b0263  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b0266  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004b0269  8d5a18                 -lea ebx, [edx + 0x18]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004b026c  886a0d                 -mov byte ptr [edx + 0xd], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 004b026f  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b0272  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004b0279  eb04                   -jmp 0x4b027f
    goto L_0x004b027f;
L_0x004b027b:
    // 004b027b  804a0c08               -or byte ptr [edx + 0xc], 8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004b027f:
    // 004b027f  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b0282  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b0285  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b028c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b028e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b028f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0291  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0292(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0292  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0293  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0294  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0297  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0299  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b029b  7c08                   -jl 0x4b02a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b02a5;
    }
    // 004b029d  3b05bc064e00           +cmp eax, dword ptr [0x4e06bc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113532) /* 0x4e06bc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b02a3  7611                   -jbe 0x4b02b6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b02b6;
    }
L_0x004b02a5:
    // 004b02a5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b02aa  e80164ffff             -call 0x4a66b0
    cpu.esp -= 4;
    sub_4a66b0(app, cpu);
    if (cpu.terminate) return;
    // 004b02af  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b02b4  eb68                   -jmp 0x4b031e
    goto L_0x004b031e;
L_0x004b02b6:
    // 004b02b6  ff155ced4d00           -call dword ptr [0x4ded5c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107036) /* 0x4ded5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b02bc  833dcced4d0000         +cmp dword ptr [0x4dedcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107148) /* 0x4dedcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b02c3  7420                   -je 0x4b02e5
    if (cpu.flags.zf)
    {
        goto L_0x004b02e5;
    }
    // 004b02c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b02c7  ff15a4ed4d00           -call dword ptr [0x4deda4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107108) /* 0x4deda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b02cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b02cf  7414                   -je 0x4b02e5
    if (cpu.flags.zf)
    {
        goto L_0x004b02e5;
    }
    // 004b02d1  ff15cced4d00           -call dword ptr [0x4dedcc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107148) /* 0x4dedcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b02d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b02d9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b02db  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b02e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b02e3  eb39                   -jmp 0x4b031e
    goto L_0x004b031e;
L_0x004b02e5:
    // 004b02e5  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004b02ea  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b02ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b02ee  8b0488                 -mov eax, dword ptr [eax + ecx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 004b02f1  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b02f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b02f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b02f7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b02f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b02f9  2eff1560654c00         -call dword ptr cs:[0x4c6560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006688) /* 0x4c6560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b0300  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b0302  750f                   -jne 0x4b0313
    if (!cpu.flags.zf)
    {
        goto L_0x004b0313;
    }
    // 004b0304  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0306  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b030c  e8a162ffff             -call 0x4a65b2
    cpu.esp -= 4;
    sub_4a65b2(app, cpu);
    if (cpu.terminate) return;
    // 004b0311  eb0b                   -jmp 0x4b031e
    goto L_0x004b031e;
L_0x004b0313:
    // 004b0313  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b0315  ff1560ed4d00           -call dword ptr [0x4ded60]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107040) /* 0x4ded60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b031b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x004b031e:
    // 004b031e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b0321  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0322  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0323  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b0324(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0324  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b0325  833800                 +cmp dword ptr [eax], 0
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
    // 004b0328  7404                   -je 0x4b032e
    if (cpu.flags.zf)
    {
        goto L_0x004b032e;
    }
    // 004b032a  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004b032b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b032c  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b032e:
    // 004b032e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b032f  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
